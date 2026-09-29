/*
 * Q_CHAR.C  Q's animation scripts and sprite part tables
 *
 * The animation scripts Q's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 q_nmca_000[], q_nmca_001[], q_nmca_002[], q_nmca_003[], q_nmca_004[], q_nmca_005[], q_nmca_006[], q_nmca_007[], q_nmca_008[], q_nmca_011[], q_nmca_012[], q_nmca_013[], q_nmca_014[], q_nmca_015[], q_nmca_016[], q_nmca_017[], q_nmca_020[], q_nmca_021[], q_nmca_022[], q_nmca_023[], q_nmca_024[], q_nmca_026[], q_nmca_027[], q_nmca_029[], q_nmca_030[], q_nmca_031[], q_nmca_032[], q_nmca_033[], q_nmca_038[], q_nmca_040[], q_nmca_041[], q_nmca_043[], q_nmca_044[], q_nmca_045[], q_nmca_046[], q_nmca_047[], q_nmca_048[], q_nmca_049[], q_nmca_050[];
extern const u16 q_nmca_000_head[];
extern const u16 q_nmca_001_head[];
extern const u16 q_nmca_002_head[];
extern const u16 q_nmca_003_head[];
extern const u16 q_nmca_004_head[];
extern const u16 q_nmca_005_head[];
extern const u16 q_nmca_006_head[];
extern const u16 q_nmca_007_head[];
extern const u16 q_nmca_008_head[];
extern const u16 q_nmca_011_head[];
extern const u16 q_nmca_012_head[];
extern const u16 q_nmca_013_head[];
extern const u16 q_nmca_014_head[];
extern const u16 q_nmca_015_head[];
extern const u16 q_nmca_016_head[];
extern const u16 q_nmca_017_head[];
extern const u16 q_nmca_020_head[];
extern const u16 q_nmca_021_head[];
extern const u16 q_nmca_022_head[];
extern const u16 q_nmca_023_head[];
extern const u16 q_nmca_024_head[];
extern const u16 q_nmca_026_head[];
extern const u16 q_nmca_027_head[];
extern const u16 q_nmca_029_head[];
extern const u16 q_nmca_030_head[];
extern const u16 q_nmca_031_head[];
extern const u16 q_nmca_032_head[];
extern const u16 q_nmca_033_head[];
extern const u16 q_nmca_038_head[];
extern const u16 q_nmca_040_head[];
extern const u16 q_nmca_041_head[];
extern const u16 q_nmca_043_head[];
extern const u16 q_nmca_044_head[];
extern const u16 q_nmca_045_head[];
extern const u16 q_nmca_046_head[];
extern const u16 q_nmca_047_head[];
extern const u16 q_nmca_048_head[];
extern const u16 q_nmca_049_head[];
extern const u16 q_nmca_050_head[];
extern const u16 q_dmca_000[], q_dmca_001[], q_dmca_002[], q_dmca_003[], q_dmca_004[], q_dmca_006[], q_dmca_008[], q_dmca_009[], q_dmca_010[], q_dmca_014[], q_dmca_015[], q_dmca_018[], q_dmca_019[], q_dmca_022[], q_dmca_025[], q_dmca_026[], q_dmca_024[], q_dmca_029[], q_dmca_030[], q_dmca_034[], q_dmca_036[], q_dmca_048[], q_dmca_049[], q_dmca_050[], q_dmca_052[], q_dmca_060[], q_dmca_064[], q_dmca_065[], q_dmca_066[], q_dmca_067[], q_dmca_068[], q_dmca_070[], q_dmca_071[], q_dmca_072[], q_dmca_073[], q_dmca_074[], q_dmca_075[], q_dmca_076[], q_dmca_078[], q_dmca_079[], q_dmca_080[], q_dmca_082[], q_dmca_083[], q_dmca_084[], q_dmca_090[], q_dmca_091[], q_dmca_096[], q_dmca_097[];
extern const u16 q_dmca_000_head[];
extern const u16 q_dmca_001_head[];
extern const u16 q_dmca_002_head[];
extern const u16 q_dmca_003_head[];
extern const u16 q_dmca_004_head[];
extern const u16 q_dmca_006_head[];
extern const u16 q_dmca_008_head[];
extern const u16 q_dmca_009_head[];
extern const u16 q_dmca_010_head[];
extern const u16 q_dmca_014_head[];
extern const u16 q_dmca_015_head[];
extern const u16 q_dmca_018_head[];
extern const u16 q_dmca_019_head[];
extern const u16 q_dmca_022_head[];
extern const u16 q_dmca_025_head[];
extern const u16 q_dmca_026_head[];
extern const u16 q_dmca_024_head[];
extern const u16 q_dmca_029_head[];
extern const u16 q_dmca_030_head[];
extern const u16 q_dmca_034_head[];
extern const u16 q_dmca_036_head[];
extern const u16 q_dmca_048_head[];
extern const u16 q_dmca_049_head[];
extern const u16 q_dmca_050_head[];
extern const u16 q_dmca_052_head[];
extern const u16 q_dmca_060_head[];
extern const u16 q_dmca_064_head[];
extern const u16 q_dmca_065_head[];
extern const u16 q_dmca_066_head[];
extern const u16 q_dmca_067_head[];
extern const u16 q_dmca_068_head[];
extern const u16 q_dmca_070_head[];
extern const u16 q_dmca_071_head[];
extern const u16 q_dmca_072_head[];
extern const u16 q_dmca_073_head[];
extern const u16 q_dmca_074_head[];
extern const u16 q_dmca_075_head[];
extern const u16 q_dmca_076_head[];
extern const u16 q_dmca_078_head[];
extern const u16 q_dmca_079_head[];
extern const u16 q_dmca_080_head[];
extern const u16 q_dmca_082_head[];
extern const u16 q_dmca_083_head[];
extern const u16 q_dmca_084_head[];
extern const u16 q_dmca_090_head[];
extern const u16 q_dmca_091_head[];
extern const u16 q_dmca_096_head[];
extern const u16 q_dmca_097_head[];
extern const u16 q_btca_000[], q_btca_001[], q_btca_002[], q_btca_003[], q_btca_004[], q_btca_005[], q_btca_006[], q_btca_007[], q_btca_008[], q_btca_009[], q_btca_010[], q_btca_011[], q_btca_012[], q_btca_013[], q_btca_014[], q_btca_015[], q_btca_016[], q_btca_017[], q_btca_018[], q_btca_019[], q_btca_020[], q_btca_021[], q_btca_022[], q_btca_023[], q_btca_024[], q_btca_025[], q_btca_026[], q_btca_027[], q_btca_028[], q_btca_029[], q_btca_030[], q_btca_031[], q_btca_032[], q_btca_033[], q_btca_034[];
extern const u16 q_btca_000_head[];
extern const u16 q_btca_001_head[];
extern const u16 q_btca_002_head[];
extern const u16 q_btca_003_head[];
extern const u16 q_btca_004_head[];
extern const u16 q_btca_005_head[];
extern const u16 q_btca_006_head[];
extern const u16 q_btca_007_head[];
extern const u16 q_btca_008_head[];
extern const u16 q_btca_009_head[];
extern const u16 q_btca_010_head[];
extern const u16 q_btca_011_head[];
extern const u16 q_btca_012_head[];
extern const u16 q_btca_013_head[];
extern const u16 q_btca_014_head[];
extern const u16 q_btca_015_head[];
extern const u16 q_btca_016_head[];
extern const u16 q_btca_017_head[];
extern const u16 q_btca_018_head[];
extern const u16 q_btca_019_head[];
extern const u16 q_btca_020_head[];
extern const u16 q_btca_021_head[];
extern const u16 q_btca_022_head[];
extern const u16 q_btca_023_head[];
extern const u16 q_btca_024_head[];
extern const u16 q_btca_025_head[];
extern const u16 q_btca_026_head[];
extern const u16 q_btca_027_head[];
extern const u16 q_btca_028_head[];
extern const u16 q_btca_029_head[];
extern const u16 q_btca_030_head[];
extern const u16 q_btca_031_head[];
extern const u16 q_btca_032_head[];
extern const u16 q_btca_033_head[];
extern const u16 q_btca_034_head[];
extern const u16 q_caca_000[], q_caca_001[], q_caca_004[], q_caca_005[], q_caca_008[], q_caca_009[], q_caca_012[], q_caca_013[], q_caca_014[], q_caca_016[];
extern const u16 q_caca_000_head[];
extern const u16 q_caca_001_head[];
extern const u16 q_caca_004_head[];
extern const u16 q_caca_005_head[];
extern const u16 q_caca_008_head[];
extern const u16 q_caca_009_head[];
extern const u16 q_caca_012_head[];
extern const u16 q_caca_013_head[];
extern const u16 q_caca_014_head[];
extern const u16 q_caca_016_head[];
extern const u16 q_cuca_000[], q_cuca_001[], q_cuca_002[], q_cuca_003[], q_cuca_004[], q_cuca_005[], q_cuca_006[], q_cuca_007[], q_cuca_008[], q_cuca_009[], q_cuca_010[], q_cuca_011[], q_cuca_012[], q_cuca_013[], q_cuca_014[], q_cuca_015[], q_cuca_016[], q_cuca_017[], q_cuca_018[], q_cuca_019[], q_cuca_020[], q_cuca_021[], q_cuca_022[], q_cuca_023[], q_cuca_024[], q_cuca_025[], q_cuca_026[], q_cuca_027[], q_cuca_028[], q_cuca_029[], q_cuca_030[], q_cuca_031[], q_cuca_032[], q_cuca_033[], q_cuca_034[], q_cuca_035[], q_cuca_036[], q_cuca_037[], q_cuca_038[], q_cuca_039[], q_cuca_040[], q_cuca_041[], q_cuca_042[], q_cuca_043[], q_cuca_044[], q_cuca_045[], q_cuca_046[], q_cuca_047[], q_cuca_048[], q_cuca_049[], q_cuca_050[], q_cuca_051[], q_cuca_052[], q_cuca_053[], q_cuca_054[], q_cuca_055[], q_cuca_056[], q_cuca_057[], q_cuca_058[], q_cuca_059[], q_cuca_060[], q_cuca_061[], q_cuca_062[], q_cuca_063[], q_cuca_064[], q_cuca_065[], q_cuca_066[], q_cuca_067[];
extern const u16 q_cuca_000_head[];
extern const u16 q_cuca_001_head[];
extern const u16 q_cuca_002_head[];
extern const u16 q_cuca_003_head[];
extern const u16 q_cuca_004_head[];
extern const u16 q_cuca_005_head[];
extern const u16 q_cuca_006_head[];
extern const u16 q_cuca_007_head[];
extern const u16 q_cuca_008_head[];
extern const u16 q_cuca_009_head[];
extern const u16 q_cuca_010_head[];
extern const u16 q_cuca_011_head[];
extern const u16 q_cuca_012_head[];
extern const u16 q_cuca_013_head[];
extern const u16 q_cuca_014_head[];
extern const u16 q_cuca_015_head[];
extern const u16 q_cuca_016_head[];
extern const u16 q_cuca_017_head[];
extern const u16 q_cuca_018_head[];
extern const u16 q_cuca_019_head[];
extern const u16 q_cuca_020_head[];
extern const u16 q_cuca_021_head[];
extern const u16 q_cuca_022_head[];
extern const u16 q_cuca_023_head[];
extern const u16 q_cuca_024_head[];
extern const u16 q_cuca_025_head[];
extern const u16 q_cuca_026_head[];
extern const u16 q_cuca_027_head[];
extern const u16 q_cuca_028_head[];
extern const u16 q_cuca_029_head[];
extern const u16 q_cuca_030_head[];
extern const u16 q_cuca_031_head[];
extern const u16 q_cuca_032_head[];
extern const u16 q_cuca_033_head[];
extern const u16 q_cuca_034_head[];
extern const u16 q_cuca_035_head[];
extern const u16 q_cuca_036_head[];
extern const u16 q_cuca_037_head[];
extern const u16 q_cuca_038_head[];
extern const u16 q_cuca_039_head[];
extern const u16 q_cuca_040_head[];
extern const u16 q_cuca_041_head[];
extern const u16 q_cuca_042_head[];
extern const u16 q_cuca_043_head[];
extern const u16 q_cuca_044_head[];
extern const u16 q_cuca_045_head[];
extern const u16 q_cuca_046_head[];
extern const u16 q_cuca_047_head[];
extern const u16 q_cuca_048_head[];
extern const u16 q_cuca_049_head[];
extern const u16 q_cuca_050_head[];
extern const u16 q_cuca_051_head[];
extern const u16 q_cuca_052_head[];
extern const u16 q_cuca_053_head[];
extern const u16 q_cuca_054_head[];
extern const u16 q_cuca_055_head[];
extern const u16 q_cuca_056_head[];
extern const u16 q_cuca_057_head[];
extern const u16 q_cuca_058_head[];
extern const u16 q_cuca_059_head[];
extern const u16 q_cuca_060_head[];
extern const u16 q_cuca_061_head[];
extern const u16 q_cuca_062_head[];
extern const u16 q_cuca_063_head[];
extern const u16 q_cuca_064_head[];
extern const u16 q_cuca_065_head[];
extern const u16 q_cuca_066_head[];
extern const u16 q_cuca_067_head[];
extern const u16 q_atca_000[], q_atca_001[], q_atca_003[], q_atca_005[], q_atca_006[], q_atca_008[], q_atca_009[], q_atca_012[], q_atca_013[], q_atca_015[], q_atca_017[], q_atca_018[], q_atca_021[], q_atca_024[], q_atca_027[], q_atca_030[], q_atca_033[], q_atca_036[], q_atca_038[], q_atca_040[], q_atca_042[], q_atca_044[], q_atca_046[], q_atca_048[], q_atca_050[], q_atca_052[], q_atca_054[], q_atca_056[], q_atca_058[], q_atca_060[], q_atca_062[], q_atca_064[], q_atca_066[], q_atca_068[], q_atca_070[], q_atca_072[], q_atca_074[], q_atca_076[], q_atca_078[], q_atca_080[], q_atca_082[], q_atca_084[], q_atca_086[], q_atca_088[], q_atca_090[], q_atca_092[], q_atca_094[], q_atca_096[], q_atca_098[], q_atca_100[], q_atca_102[], q_atca_104[], q_atca_106[], q_atca_108[], q_atca_144[], q_atca_145[], q_atca_146[];
extern const u16 q_atca_000_head[];
extern const u16 q_atca_001_head[];
extern const u16 q_atca_003_head[];
extern const u16 q_atca_005_head[];
extern const u16 q_atca_006_head[];
extern const u16 q_atca_008_head[];
extern const u16 q_atca_009_head[];
extern const u16 q_atca_012_head[];
extern const u16 q_atca_013_head[];
extern const u16 q_atca_015_head[];
extern const u16 q_atca_017_head[];
extern const u16 q_atca_018_head[];
extern const u16 q_atca_021_head[];
extern const u16 q_atca_024_head[];
extern const u16 q_atca_027_head[];
extern const u16 q_atca_030_head[];
extern const u16 q_atca_033_head[];
extern const u16 q_atca_036_head[];
extern const u16 q_atca_038_head[];
extern const u16 q_atca_040_head[];
extern const u16 q_atca_042_head[];
extern const u16 q_atca_044_head[];
extern const u16 q_atca_046_head[];
extern const u16 q_atca_048_head[];
extern const u16 q_atca_050_head[];
extern const u16 q_atca_052_head[];
extern const u16 q_atca_054_head[];
extern const u16 q_atca_056_head[];
extern const u16 q_atca_058_head[];
extern const u16 q_atca_060_head[];
extern const u16 q_atca_062_head[];
extern const u16 q_atca_064_head[];
extern const u16 q_atca_066_head[];
extern const u16 q_atca_068_head[];
extern const u16 q_atca_070_head[];
extern const u16 q_atca_072_head[];
extern const u16 q_atca_074_head[];
extern const u16 q_atca_076_head[];
extern const u16 q_atca_078_head[];
extern const u16 q_atca_080_head[];
extern const u16 q_atca_082_head[];
extern const u16 q_atca_084_head[];
extern const u16 q_atca_086_head[];
extern const u16 q_atca_088_head[];
extern const u16 q_atca_090_head[];
extern const u16 q_atca_092_head[];
extern const u16 q_atca_094_head[];
extern const u16 q_atca_096_head[];
extern const u16 q_atca_098_head[];
extern const u16 q_atca_100_head[];
extern const u16 q_atca_102_head[];
extern const u16 q_atca_104_head[];
extern const u16 q_atca_106_head[];
extern const u16 q_atca_108_head[];
extern const u16 q_atca_144_head[];
extern const u16 q_atca_145_head[];
extern const u16 q_atca_146_head[];
extern const u16 q_exca_000[], q_exca_001[], q_exca_003[], q_exca_004[], q_exca_005[], q_exca_006[], q_exca_007[], q_exca_008[], q_exca_009[], q_exca_010[], q_exca_011[], q_exca_013[], q_exca_014[], q_exca_015[], q_exca_016[], q_exca_018[], q_exca_019[], q_exca_020[], q_exca_021[], q_exca_022[], q_exca_023[], q_exca_024[], q_exca_025[], q_exca_029[], q_exca_030[], q_exca_032[], q_exca_033[], q_exca_034[], q_exca_037[], q_exca_038[], q_exca_039[], q_exca_040[], q_exca_041[], q_exca_042[], q_exca_043[], q_exca_044[], q_exca_045[], q_exca_046[], q_exca_047[], q_exca_048[], q_exca_049[], q_exca_017[], q_exca_055[];
extern const u16 q_exca_000_head[];
extern const u16 q_exca_001_head[];
extern const u16 q_exca_003_head[];
extern const u16 q_exca_004_head[];
extern const u16 q_exca_005_head[];
extern const u16 q_exca_006_head[];
extern const u16 q_exca_007_head[];
extern const u16 q_exca_008_head[];
extern const u16 q_exca_009_head[];
extern const u16 q_exca_010_head[];
extern const u16 q_exca_011_head[];
extern const u16 q_exca_013_head[];
extern const u16 q_exca_014_head[];
extern const u16 q_exca_015_head[];
extern const u16 q_exca_016_head[];
extern const u16 q_exca_018_head[];
extern const u16 q_exca_019_head[];
extern const u16 q_exca_020_head[];
extern const u16 q_exca_021_head[];
extern const u16 q_exca_022_head[];
extern const u16 q_exca_023_head[];
extern const u16 q_exca_024_head[];
extern const u16 q_exca_025_head[];
extern const u16 q_exca_029_head[];
extern const u16 q_exca_030_head[];
extern const u16 q_exca_032_head[];
extern const u16 q_exca_033_head[];
extern const u16 q_exca_034_head[];
extern const u16 q_exca_037_head[];
extern const u16 q_exca_038_head[];
extern const u16 q_exca_039_head[];
extern const u16 q_exca_040_head[];
extern const u16 q_exca_041_head[];
extern const u16 q_exca_042_head[];
extern const u16 q_exca_043_head[];
extern const u16 q_exca_044_head[];
extern const u16 q_exca_045_head[];
extern const u16 q_exca_046_head[];
extern const u16 q_exca_047_head[];
extern const u16 q_exca_048_head[];
extern const u16 q_exca_049_head[];
extern const u16 q_exca_017_head[];
extern const u16 q_exca_055_head[];
extern const u16 q_saca_000[], q_saca_001[], q_saca_002[], q_saca_024[], q_saca_025[], q_saca_026[], q_saca_027[], q_saca_028[], q_saca_029[], q_saca_030[], q_saca_031[], q_saca_032[], q_saca_033[], q_saca_034[], q_saca_036[], q_saca_037[], q_saca_038[], q_saca_039[], q_saca_040[], q_saca_041[], q_saca_042[], q_saca_044[], q_saca_046[], q_saca_047[], q_saca_048[], q_saca_052[], q_saca_053[], q_saca_054[], q_saca_060[], q_saca_064[], q_saca_067[];
extern const u16 q_saca_000_head[];
extern const u16 q_saca_001_head[];
extern const u16 q_saca_002_head[];
extern const u16 q_saca_024_head[];
extern const u16 q_saca_025_head[];
extern const u16 q_saca_026_head[];
extern const u16 q_saca_027_head[];
extern const u16 q_saca_028_head[];
extern const u16 q_saca_029_head[];
extern const u16 q_saca_030_head[];
extern const u16 q_saca_031_head[];
extern const u16 q_saca_032_head[];
extern const u16 q_saca_033_head[];
extern const u16 q_saca_034_head[];
extern const u16 q_saca_036_head[];
extern const u16 q_saca_037_head[];
extern const u16 q_saca_038_head[];
extern const u16 q_saca_039_head[];
extern const u16 q_saca_040_head[];
extern const u16 q_saca_041_head[];
extern const u16 q_saca_042_head[];
extern const u16 q_saca_044_head[];
extern const u16 q_saca_046_head[];
extern const u16 q_saca_047_head[];
extern const u16 q_saca_048_head[];
extern const u16 q_saca_052_head[];
extern const u16 q_saca_053_head[];
extern const u16 q_saca_054_head[];
extern const u16 q_saca_060_head[];
extern const u16 q_saca_064_head[];
extern const u16 q_saca_067_head[];
extern const u16 q_cbca_000[], q_cbca_001[], q_cbca_002[], q_cbca_003[], q_cbca_004[], q_cbca_005[], q_cbca_006[], q_cbca_007[], q_cbca_008[], q_cbca_009[], q_cbca_010[], q_cbca_012[], q_cbca_013[], q_cbca_014[], q_cbca_015[], q_cbca_016[], q_cbca_017[], q_cbca_018[], q_cbca_019[], q_cbca_020[], q_cbca_021[], q_cbca_022[], q_cbca_023[], q_cbca_024[], q_cbca_037[], q_cbca_038[], q_cbca_039[], q_cbca_040[], q_cbca_041[], q_cbca_042[], q_cbca_043[], q_cbca_044[];
extern const u16 q_cbca_000_head[];
extern const u16 q_cbca_001_head[];
extern const u16 q_cbca_002_head[];
extern const u16 q_cbca_003_head[];
extern const u16 q_cbca_004_head[];
extern const u16 q_cbca_005_head[];
extern const u16 q_cbca_006_head[];
extern const u16 q_cbca_007_head[];
extern const u16 q_cbca_008_head[];
extern const u16 q_cbca_009_head[];
extern const u16 q_cbca_010_head[];
extern const u16 q_cbca_012_head[];
extern const u16 q_cbca_013_head[];
extern const u16 q_cbca_014_head[];
extern const u16 q_cbca_015_head[];
extern const u16 q_cbca_016_head[];
extern const u16 q_cbca_017_head[];
extern const u16 q_cbca_018_head[];
extern const u16 q_cbca_019_head[];
extern const u16 q_cbca_020_head[];
extern const u16 q_cbca_021_head[];
extern const u16 q_cbca_022_head[];
extern const u16 q_cbca_023_head[];
extern const u16 q_cbca_024_head[];
extern const u16 q_cbca_037_head[];
extern const u16 q_cbca_038_head[];
extern const u16 q_cbca_039_head[];
extern const u16 q_cbca_040_head[];
extern const u16 q_cbca_041_head[];
extern const u16 q_cbca_042_head[];
extern const u16 q_cbca_043_head[];
extern const u16 q_cbca_044_head[];

/* normal scripts: 51 entries */
const u16* const q_nmca[52] = {
    q_nmca_000,  /* 0 KAMAE */
    q_nmca_001,  /* 1 HURIMUKI */
    q_nmca_002,  /* 2 FRONT WALK */
    q_nmca_003,  /* 3 BACK WALK */
    q_nmca_004,  /* 4 DASH HUMIKOMI */
    q_nmca_005,  /* 5 DASH TOBINOKI */
    q_nmca_006,  /* 6 KAGAMU */
    q_nmca_007,  /* 7 KAGAMI KAMAE */
    q_nmca_008,  /* 8 KAGAMI TURN */
    q_nmca_008,  /* 9 KAGAMI F WALK */
    q_nmca_008,  /* 10 KAGAMI B WALK */
    q_nmca_011,  /* 11 STAND UP */
    q_nmca_012,  /* 12 JUMP JUNBI */
    q_nmca_013,  /* 13 SP JUMP JUNBI */
    q_nmca_014,  /* 14 JUMP FRONT */
    q_nmca_015,  /* 15 JUMP VERTICAL */
    q_nmca_016,  /* 16 JUMP BACK */
    q_nmca_017,  /* 17 S JUMP FRONT */
    q_nmca_017,  /* 18 S JUMP V */
    q_nmca_017,  /* 19 S JUMP BACK */
    q_nmca_020,  /* 20 SP JUMP FRONT */
    q_nmca_021,  /* 21 SP JUMP V */
    q_nmca_022,  /* 22 SP JUMP BACK */
    q_nmca_023,  /* 23 WALK END */
    q_nmca_024,  /* 24 PARING HEAD */
    q_nmca_024,  /* 25 PARING UP */
    q_nmca_026,  /* 26 PARING DOWN */
    q_nmca_027,  /* 27 PARING AIR F */
    q_nmca_027,  /* 28 PARING AIR B */
    q_nmca_029,  /* 29 GUARD HEAD */
    q_nmca_030,  /* 30 GUARD UP */
    q_nmca_031,  /* 31 GUARD DOWN */
    q_nmca_032,  /* 32 GUARD AIR */
    q_nmca_033,  /* 33 no name */
    q_nmca_033,  /* 34 no name */
    q_nmca_033,  /* 35 no name */
    q_nmca_033,  /* 36 no name */
    q_nmca_033,  /* 37 no name */
    q_nmca_038,  /* 38 P BREAK ZUJOU */
    q_nmca_038,  /* 39 P BREAK UP */
    q_nmca_040,  /* 40 P BREAK DOWN */
    q_nmca_041,  /* 41 P BREAK AIR F */
    q_nmca_041,  /* 42 P BREAK AIR R */
    q_nmca_043,  /* 43 TUKAMIHAZUSI */
    q_nmca_044,  /* 44 TUKAMIHAZUSARE */
    q_nmca_045,  /* 45 TUKAMIHAZUSI */
    q_nmca_046,  /* 46 TUKAMIHAZUSARE */
    q_nmca_047,  /* 47 no name */
    q_nmca_048,  /* 48 no name */
    q_nmca_049,  /* 49 no name */
    q_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 q_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_000[364] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6601, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6910, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6911, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6912, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6913, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6914, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6915, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6916, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6917, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6918, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6919, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691A, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691B, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691C, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691D, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691E, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691F, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6920, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6921, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6922, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6923, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6924, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 781, 0, 0, 0, 0, 0x6601, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6910, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6911, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6912, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6913, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6914, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6915, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6916, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6917, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6918, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6919, 0, 445, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691A, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691B, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691C, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691D, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691E, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x691F, 0, 444, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6920, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6921, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6922, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6923, 0, 446, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6924, 0, 444, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 q_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_001[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6650, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6651, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6652, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6652, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6653, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6654, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6655, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6656, 0, 447, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 q_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 q_nmca_002[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C7, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C8, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C9, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CA, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CB, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CC, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CD, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CE, 0, 459, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66CF, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D0, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D1, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D2, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D3, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66D4, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66B2, 0, 460, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66B3, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B4, 0, 460, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B5, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B6, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B7, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B8, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66B9, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BA, 0, 461, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BB, 0, 462, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BC, 0, 462, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BD, 0, 462, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BE, 0, 463, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66BF, 0, 463, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C0, 0, 463, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C1, 0, 463, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C2, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66C3, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66C4, 0, 463, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66C5, 0, 463, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66C6, 0, 463, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 q_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 q_nmca_003[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F0, 0, 464, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F1, 0, 464, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F2, 0, 464, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F3, 0, 464, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66F4, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66F5, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66F6, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66F7, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66D4, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66D6, 0, 465, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66D7, 0, 465, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D8, 0, 465, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66D9, 0, 465, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DA, 0, 465, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DB, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DC, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DD, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DE, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66DF, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66E0, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66E1, 0, 466, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66E2, 0, 466, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E3, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E4, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E5, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E6, 0, 467, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E7, 0, 467, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66E8, 0, 467, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66E9, 0, 467, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66EA, 0, 467, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66EB, 0, 468, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66EC, 0, 468, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66ED, 0, 468, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66EE, 0, 469, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66EF, 0, 469, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 q_nmca_004_head[4] = { HEAD(6, 10, 0, 0, 0, 0, 0) };
const u16 q_nmca_004[148] = {
    CMD(CM_RJA, 0, 4, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 277, 0, 0, 0, 0, 0x669F, 0, 470, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x66A0, 0, 471, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x66AE, 0, 471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x66AF, 0, 471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x66A1, 0, 472, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 273, 0, 0, 0, 0, 0x66A2, 0, 473, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x66A3, 0, 474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x662F, 0, 475, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6630, 0, 475, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 q_nmca_005_head[4] = { HEAD(6, 12, 0, 0, 0, 0, 0) };
const u16 q_nmca_005[172] = {
    CMD(CM_RJA, 0, 5, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 277, 0, 0, 0, 0, 0x66A4, 0, 477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x66A5, 0, 478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x66A6, 0, 478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x66A7, 0, 479, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x66A8, 0, 479, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x66A9, 0, 480, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x66AA, 0, 481, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x66AB, 0, 482, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x66AC, 0, 482, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x66AD, 0, 483, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 483, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 q_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_nmca_006[68] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x660B, 0, 444, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660C, 0, 451, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660D, 0, 449, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660E, 0, 449, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x660F, 0, 449, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6610, 0, 449, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 q_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_nmca_007[252] = {
    L4(7, 0, 0, 0, 0, 0, 0, 0x6926, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6927, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6928, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6929, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692A, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692B, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692C, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692D, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692E, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6611, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6930, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6931, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6932, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6933, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6934, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 781, 0, 0, 0, 0, 0x6926, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6927, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6928, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6929, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692A, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692B, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692C, 0, 448, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692D, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x692E, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6611, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6930, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6931, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6932, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6933, 0, 449, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6934, 0, 449, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 q_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_nmca_008[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6658, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6659, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665A, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665B, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665C, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665D, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665E, 0, 450, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 q_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_nmca_011[124] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6611, 0, 448, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6612, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6613, 0, 452, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660B, 0, 453, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660A, 0, 453, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6602, 0, 453, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6603, 0, 453, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6604, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6605, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6606, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6607, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6608, 0, 445, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6609, 0, 445, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 q_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x660B, 0, 277, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x660B, 0, 277, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x660B, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 q_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_013[28] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x660B, 0, 454, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x660C, 0, 278, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x660C, 0, 278, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 q_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_nmca_014[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x6632, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6633, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6634, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6635, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6636, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6637, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6638, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6639, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x663A, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x663B, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x663C, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663D, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 q_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 q_nmca_015[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x6620, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6621, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6622, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6623, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6624, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6625, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6626, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6627, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6628, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6629, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662A, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662B, 0, 458, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 q_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_nmca_016[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(3, 0, 281, 0, 0, 0, 0, 0x663E, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663F, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6640, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6641, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6642, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6643, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6644, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6645, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6646, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6647, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6648, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6649, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 q_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 q_nmca_017[12] = {
    CMD(CM_JSR, 8, 37, 1),
    CMD(CM_JPSS, 0, 15, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 q_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 q_nmca_020[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 0, 0x6632, 0, 455, 0, 0, 0, 18, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6633, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6634, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6635, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6636, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6637, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6638, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6639, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x663A, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x663B, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x663C, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663D, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 q_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 q_nmca_021[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(1, 0, 281, 0, 0, 0, 0, 0x6620, 0, 455, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6621, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6622, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6623, 0, 455, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x6624, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6625, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6626, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6627, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6628, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6629, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662A, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662B, 0, 458, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 q_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 q_nmca_022[132] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 0, 281, 0, 0, 0, 0, 0x663E, 0, 455, 0, 0, 0, 18, 2),
    L4(4, 0, 0, 0, 0, 0, 0, 0x663F, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6640, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6641, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6642, 0, 455, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6643, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6644, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6645, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6646, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6647, 0, 457, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6648, 0, 457, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6649, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 q_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 q_nmca_023[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 q_nmca_024_head[4] = { HEAD(6, 2, 0, 0, 0, 0, 0) };
const u16 q_nmca_024[256] = {
    L6(1, 132, 0, 0, 0, 0, 0, 0x6690, 0, 1, 0, 0, 0, 18, 6, 0, 0, 0, 0, 0),
    L6(2, 0, 774, 0, 0, 0, 0, 0x6691, 0, 1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x6692, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6693, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x6694, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6695, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6696, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6697, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6698, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6699, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x669A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6695, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6696, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6697, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6698, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6699, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x669B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x669C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 q_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 q_nmca_026[68] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x667C, 0, 2, 0, 0, 0, 18, 6),
    L4(1, 0, 774, 0, 0, 0, 0, 0x667D, 0, 2, 0, 0, 0, 6, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x667E, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x667F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6683, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6684, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6685, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6685, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 q_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_nmca_027[196] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x669D, 0, 11, 0, 0, 0, 18, 6),
    L4(250, 0, 774, 0, 0, 0, 0, 0x669E, 0, 11, 0, 0, 0, 6, 2),
    L4(2, 64, 0, 0, 0, 0, 0, 0x669E, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6626, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6627, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6628, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6629, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662A, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662B, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x669D, 0, 11, 0, 0, 0, 18, 6),
    L4(3, 0, 774, 0, 0, 0, 0, 0x669E, 0, 11, 0, 0, 0, 6, 2),
    L4(17, 0, 0, 0, 0, 0, 0, 0x669E, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6626, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6627, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6628, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6629, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662A, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662B, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x664A, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 q_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 q_nmca_029[116] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6660, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6661, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6662, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6663, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6664, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6667, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6668, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 q_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 q_nmca_030[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x666F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6670, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6671, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6672, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6673, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6676, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6677, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6678, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6679, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x667A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 q_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 q_nmca_031[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x667B, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x667C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x667D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x667E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x667F, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x6680, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6683, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6684, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6685, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6686, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x667B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x667B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 q_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 q_nmca_032[36] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6668, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 26217), 0x0000, 0x2000, 0x0000, 0x0000,
    L4(2, 3, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 q_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_033[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP */
const u16 q_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_038[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x6660, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6661, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6680, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6681, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6682, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 P BREAK DOWN */
const u16 q_nmca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_nmca_040[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x6665, 0, 1, 0, 0, 0, 18, 8),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6666, 0, 1, 0, 0, 0, 25, 1),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6680, 0, 1, 0, 0, 0, 22, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6681, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6682, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 P BREAK AIR F, 42 P BREAK AIR R */
const u16 q_nmca_041_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_nmca_041[44] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x6668, 0, 11, 0, 0, 0, 18, 8),
    L4(250, 0, 774, 0, 0, 0, 0, 0x6669, 0, 11, 0, 0, 0, 25, 2),
    CMD(CM_JPSS, 0, 45, 4), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 q_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_043[76] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x6670, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6671, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4608, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6687, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6688, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6689, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x668A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 q_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_044[68] = {
    L4(4, 131, 0, 0, 0, 0, 0, 0x68DF, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x68F1, 0, 1, 0, 0, 0, 0, 0),
    L4(10, 1, 0, 0, 0, 0, 0, 0x68F2, 0, 1, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x68F3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x68F4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68F5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 q_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_nmca_045[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x669E, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 774, 0, 0, 0, 0, 0x669D, 0, 11, 0, 0, 0, 25, 2),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6627, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6628, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6629, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662A, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662B, 0, 11, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x664A, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 q_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_nmca_046[84] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x6626, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6627, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6628, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6629, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662A, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662B, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 q_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_047[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 q_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 q_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6601, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 q_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_nmca_050[68] = {
    CMD(CM_JSR, 8, 42, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6660, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6661, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6680, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6681, 0, 1, 0, 0, 0, 22, 24),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6682, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const q_dmca[99] = {
    q_dmca_000,  /* 0 GUARD HEAD */
    q_dmca_001,  /* 1 GUARD UP */
    q_dmca_002,  /* 2 GUARD DOWN */
    q_dmca_003,  /* 3 GUARD AIR */
    q_dmca_004,  /* 4 HUSHIN HEAD */
    q_dmca_004,  /* 5 HUSHIN UP */
    q_dmca_006,  /* 6 HUSHIN DOWN */
    q_dmca_006,  /* 7 HUSHIN AIR */
    q_dmca_008,  /* 8 FACE S */
    q_dmca_009,  /* 9 FACE M */
    q_dmca_010,  /* 10 FACE L */
    q_dmca_010,  /* 11 FACE SP */
    q_dmca_008,  /* 12 FOOK OKU S */
    q_dmca_009,  /* 13 FOOK OKU M */
    q_dmca_014,  /* 14 FOOK OKU L */
    q_dmca_015,  /* 15 FOOK OKU SP */
    q_dmca_008,  /* 16 FOOK TEMAE S */
    q_dmca_009,  /* 17 FOOK TEMAE M */
    q_dmca_018,  /* 18 FOOK TEMAE L */
    q_dmca_019,  /* 19 FOOK TEMAE SP */
    q_dmca_008,  /* 20 UPPER S */
    q_dmca_009,  /* 21 UPPER M */
    q_dmca_022,  /* 22 UPPER L */
    q_dmca_022,  /* 23 UPPER SP */
    q_dmca_024,  /* 24 NOUTEN S */
    q_dmca_025,  /* 25 NOUTEN M */
    q_dmca_026,  /* 26 NOUTEN L */
    q_dmca_026,  /* 27 NOUTEN SP */
    q_dmca_024,  /* 28 BODY BROW S */
    q_dmca_029,  /* 29 BODY BROW M */
    q_dmca_030,  /* 30 BODY BROW L */
    q_dmca_030,  /* 31 BODY BROW SP */
    q_dmca_024,  /* 32 BODY UPPER S */
    q_dmca_029,  /* 33 BODY UPPER M */
    q_dmca_034,  /* 34 BODY UPPER L */
    q_dmca_034,  /* 35 BODY UPPER SP */
    q_dmca_036,  /* 36 TATAKI S */
    q_dmca_036,  /* 37 TATAKI M */
    q_dmca_036,  /* 38 TATAKI L */
    q_dmca_036,  /* 39 TATAKI SP */
    q_dmca_036,  /* 40 TATAKI V. S */
    q_dmca_036,  /* 41 TATAKI V. M */
    q_dmca_036,  /* 42 TATAKI V. L */
    q_dmca_036,  /* 43 TATAKI V. SP */
    q_dmca_008,  /* 44 NOBASITA TE S */
    q_dmca_009,  /* 45 NOBASITA TE M */
    q_dmca_010,  /* 46 NOBASITA TE L */
    q_dmca_010,  /* 47 NOBASITA TE SP */
    q_dmca_048,  /* 48 KAGAMI S */
    q_dmca_049,  /* 49 KAGAMI M */
    q_dmca_050,  /* 50 KAGAMI L */
    q_dmca_050,  /* 51 KAGAMI SP */
    q_dmca_052,  /* 52 KGM TATAKI S */
    q_dmca_052,  /* 53 KGM TATAKI M */
    q_dmca_052,  /* 54 KGM TATAKI L */
    q_dmca_052,  /* 55 KGM TATAKI SP */
    q_dmca_052,  /* 56 KGM TTKI V.S */
    q_dmca_052,  /* 57 KGM TTKI V.M */
    q_dmca_052,  /* 58 KGM TTKI V.L */
    q_dmca_052,  /* 59 KGM TTKI V.SP */
    q_dmca_060,  /* 60 NEKOROBI S */
    q_dmca_060,  /* 61 NEKOROBI M */
    q_dmca_060,  /* 62 NEKOROBI L */
    q_dmca_060,  /* 63 NEKOROBI SP */
    q_dmca_064,  /* 64 OKIAGARI */
    q_dmca_065,  /* 65 OKIAGARI F */
    q_dmca_066,  /* 66 OKIAGARI B */
    q_dmca_067,  /* 67 LOSE NO STAND */
    q_dmca_068,  /* 68 LOSE SONABA */
    q_dmca_068,  /* 69 LOSE KAGAMI */
    q_dmca_070,  /* 70 PIYO */
    q_dmca_071,  /* 71 UKEMI MOVE F */
    q_dmca_072,  /* 72 UKEMI MOVE R */
    q_dmca_073,  /* 73 SHIMEOTASARE */
    q_dmca_074,  /* 74 TATI TOUKETU S */
    q_dmca_075,  /* 75 TATI TOUKETU M */
    q_dmca_076,  /* 76 TATI TOUKETU L */
    q_dmca_076,  /* 77 TATI TOUKETU P */
    q_dmca_078,  /* 78 KGM TOUKETU S */
    q_dmca_079,  /* 79 KGM TOUKETU M */
    q_dmca_080,  /* 80 KGM TOUKETU L */
    q_dmca_080,  /* 81 KGM TOUKETU P */
    q_dmca_082,  /* 82 TATI DENGEKI S */
    q_dmca_083,  /* 83 TATI DENGEKI M */
    q_dmca_084,  /* 84 TATI DENGEKI L */
    q_dmca_084,  /* 85 TATI DENGEKI P */
    q_dmca_082,  /* 86 KGM DENGEKI S */
    q_dmca_083,  /* 87 KGM DENGEKI M */
    q_dmca_084,  /* 88 KGM DENGEKI L */
    q_dmca_084,  /* 89 KGM DENGEKI P */
    q_dmca_090,  /* 90 OKIAGARI FRONT */
    q_dmca_091,  /* 91 OKIAGARI REAR */
    q_dmca_008,  /* 92 TATI MOE S */
    q_dmca_009,  /* 93 TATI MOE M */
    q_dmca_010,  /* 94 TATI MOE L */
    q_dmca_010,  /* 95 TATI MOE SP */
    q_dmca_096,  /* 96 no name */
    q_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 q_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_000[100] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x6664, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6665, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x6666, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6667, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6668, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666B, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 q_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_001[92] = {
    L4(2, 131, 0, 0, 0, 0, 0, 0x6673, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6674, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x6675, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6676, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6677, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6678, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6679, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x667A, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 q_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_002[76] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6680, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6681, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 133, 0, 0, 0, 0, 0, 0x6682, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6683, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6684, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6685, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6686, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x667B, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x667B, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR */
const u16 q_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_003[92] = {
    L4(4, 131, 266, 0, 0, 0, 0, 0x6668, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6669, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 1, 3, 6), 0, 0, 0, 0,
    L4(250, 138, 0, 0, 0, 0, 0, 0x6669, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    L4(250, 135, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6669, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 16, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 HUSHIN HEAD, 5 HUSHIN UP */
const u16 q_dmca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_004[92] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6670, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6671, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6674, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6687, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6688, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6689, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x668C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 HUSHIN DOWN, 7 HUSHIN AIR */
const u16 q_dmca_006_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_006[84] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x6680, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6681, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6687, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6688, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6689, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x668C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x668C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 12 FOOK OKU S, 16 FOOK TEMAE S, 20 UPPER S ... */
const u16 q_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_008[76] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6700, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6701, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 135, 770, 0, 0, 0, 0, 0x6701, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6701, 0, 239, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6702, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 13 FOOK OKU M, 17 FOOK TEMAE M, 21 UPPER M ... */
const u16 q_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_009[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6705, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 136, 770, 0, 0, 0, 0, 0x6706, 0, 239, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6707, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6708, 0, 240, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6709, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x670A, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x670B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 q_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_010[140] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6705, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x670C, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 143, 771, 0, 0, 0, 0, 0x670D, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x670E, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 22, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x670F, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6710, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6711, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6712, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6713, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6714, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6715, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6716, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x670B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 q_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_014[140] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6784, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 141, 771, 0, 0, 0, 0, 0x6785, 0, 241, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x677D, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x677E, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x677F, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6780, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6781, 0, 240, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6782, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6653, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6656, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 q_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_015[148] = {
    L4(1, 132, 0, 0, 0, 0, 0, 0x6705, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6784, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 142, 771, 0, 0, 0, 0, 0x6785, 0, 241, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x677D, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x677E, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x677F, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6780, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6781, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x6782, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6653, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6656, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 q_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_018[132] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x677B, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 140, 771, 0, 0, 0, 0, 0x677C, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x677D, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x677E, 0, 240, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x677F, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6780, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 10, 0, 0, 0, 0, 0, 0x6781, 0, 241, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6782, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6653, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6656, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 q_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_019[140] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x677A, 0, 239, 0, 0, 0, 0, 0),
    L4(1, 141, 771, 0, 0, 0, 0, 0x677B, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x677C, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x677D, 0, 241, 0, 0, 0, 0, 0),
    L4(4, 10, 0, 0, 0, 0, 0, 0x677E, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x677F, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6780, 0, 242, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6781, 0, 242, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 10, 0, 0, 0, 0, 0, 0x6782, 0, 240, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6653, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6656, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 q_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_022[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6770, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 139, 771, 0, 0, 0, 0, 0x6771, 0, 235, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6772, 0, 235, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 15, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6773, 0, 236, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6774, 0, 237, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662C, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662D, 0, 238, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M */
const u16 q_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_025[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6758, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 135, 770, 0, 0, 0, 0, 0x676C, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x676D, 0, 248, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x676E, 0, 248, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 3, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x676F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6602, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6603, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6605, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6606, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6607, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6608, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 NOUTEN L, 27 NOUTEN SP */
const u16 q_dmca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_026[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x676C, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 134, 770, 0, 0, 0, 0, 0x676D, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x676E, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x676F, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6602, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6603, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6605, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6606, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6607, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6608, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 q_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_024[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6717, 0, 243, 0, 0, 0, 0, 0),
    L4(250, 0, 770, 0, 0, 0, 0, 0x6718, 0, 243, 0, 0, 0, 0, 0),
    L4(4, 133, 0, 0, 0, 0, 0, 0x6719, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 q_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_029[84] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6717, 0, 243, 0, 0, 0, 0, 0),
    L4(250, 0, 770, 0, 0, 0, 0, 0x671A, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 136, 0, 0, 0, 0, 0, 0x671B, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 8, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x671C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x671D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x671E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 q_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_030[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x671A, 0, 243, 0, 0, 0, 0, 0),
    L4(3, 137, 771, 0, 0, 0, 0, 0x671F, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6720, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 10, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6721, 0, 246, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6722, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6723, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6724, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6725, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x671E, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 q_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_034[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6775, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 138, 771, 0, 0, 0, 0, 0x6776, 0, 244, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6777, 0, 245, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6778, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6722, 0, 245, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6723, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6724, 0, 245, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6725, 0, 244, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x671E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 q_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6758, 0, 246, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6759, 0, 246, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S */
const u16 q_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_048[60] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x6726, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 0, 770, 0, 0, 0, 0, 0x6727, 0, 247, 0, 0, 0, 0, 0),
    L4(3, 134, 0, 0, 0, 0, 0, 0x6728, 0, 247, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6729, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 KAGAMI M */
const u16 q_dmca_049_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_049[76] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x672B, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 135, 770, 0, 0, 0, 0, 0x672C, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x672D, 0, 248, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x672E, 0, 247, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 2, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6729, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 q_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_050[76] = {
    L4(1, 131, 0, 0, 0, 0, 0, 0x672B, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 0, 770, 0, 0, 0, 0, 0x672C, 0, 248, 0, 0, 0, 0, 0),
    L4(5, 136, 0, 0, 0, 0, 0, 0x672D, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x672E, 0, 247, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 5, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6729, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x672A, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 q_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_052[36] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(1, 132, 0, 0, 0, 0, 0, 0x672B, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 0, 771, 0, 0, 0, 0, 0x672C, 0, 248, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 q_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_060[148] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6786, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 2, 771, 0, 0, 0, 0, 0x6787, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6788, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6742, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6743, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6744, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6745, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6746, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6747, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6748, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6787, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x6787, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI */
const u16 q_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 q_dmca_064[220] = {
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0,
    L4(12, 9, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 11, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A5, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A6, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A7, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A8, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x67A9, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_SMHF, 1, 0, 0), 0, 0, 0, 0,
    L4(3, 12, 0, 0, 0, 0, 0, 0x67AA, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x67AB, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67AC, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x67AC, 0, 0, 0, 0, 0, 22, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x67AD, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B1, 0, 1, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B3, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B4, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B7, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 OKIAGARI F */
const u16 q_dmca_065_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 q_dmca_065[148] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6890, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6750, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6751, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6752, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6753, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6748, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6749, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 OKIAGARI B */
const u16 q_dmca_066_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 q_dmca_066[156] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x66EE, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66ED, 0, 282, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6740, 0, 282, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x6741, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6752, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6751, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6750, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 12, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x6748, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6749, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 q_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x674A, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 q_dmca_068_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_068[292] = {
    L6(250, 130, 0, 0, 0, 0, 0, 0x6789, 0, 486, 0, 0, 0, 0, 0, 0, 0, 142, 0, 0),
    L6(250, 131, 0, 0, 0, 0, 0, 0x678A, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x6789, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x678A, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x678B, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x678C, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x678D, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x678E, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x678D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x678E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x678F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 288, 0, 0, 0, 0, 0x6794, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6795, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6796, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x6797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 q_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_070[76] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x6765, 0, 484, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6766, 0, 484, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6767, 0, 484, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6768, 0, 484, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6769, 0, 485, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x676A, 0, 485, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x676B, 0, 485, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 q_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_071[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A5, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 776, 0, 0, 0, 0, 0x67A6, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x67A7, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x689A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6899, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6898, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6897, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6896, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6895, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x67A8, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67A9, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67AA, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67AB, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67AC, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x67AC, 0, 0, 0, 0, 0, 22, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x67AD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x67AE, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67AF, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B1, 0, 1, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67B2, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B3, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B4, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B5, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67B7, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67B7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 q_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_072[92] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x67A5, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 776, 0, 0, 0, 0, 0x67A6, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x67A7, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x6895, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6896, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6897, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6898, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6899, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x689A, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 71, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 q_dmca_073_head[4] = { HEAD(6, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_073[292] = {
    L6(3, 0, 771, 0, 0, 0, 0, 0x6789, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x678A, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x6789, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x678A, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x678B, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x678C, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x678D, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 289, 0, 0, 0, 0, 0x678E, 0, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x678D, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 289, 0, 0, 0, 0, 0x678E, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x678F, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6793, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 288, 0, 0, 0, 0, 0x6794, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 1, 0, 0, 0, 0, 0, 0x6795, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6796, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 1, 0, 0, 0, 0, 0, 0x6797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6797, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 q_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6701, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6701, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6702, 0, 239, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 q_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_075[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6709, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6709, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x670A, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x670B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6703, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 q_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_076[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6784, 0, 239, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6784, 0, 240, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6783, 0, 239, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6653, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 q_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_078[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6727, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6727, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6728, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6729, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6729, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 q_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_079[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x672D, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x672D, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x672E, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 q_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x672C, 0, 247, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x672C, 0, 249, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x672D, 0, 248, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x672E, 0, 247, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x672F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 q_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_082[52] = {
    L4(1, 133, 0, 0, 0, 0, 0, 0x6730, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6730, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6731, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6732, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 q_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_083[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x6730, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6731, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6732, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 q_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_dmca_084[44] = {
    L4(3, 133, 0, 0, 0, 0, 0, 0x6730, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6731, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6732, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT */
const u16 q_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 18, 0) };
const u16 q_dmca_090[148] = {
    CMD(CM_MXYT, 16, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6890, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x674B, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674C, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6750, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6751, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6752, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6753, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6749, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 91 OKIAGARI REAR */
const u16 q_dmca_091_head[4] = { HEAD(4, 38, 0, 0, 0, 21, 0) };
const u16 q_dmca_091[156] = {
    CMD(CM_MXYT, 15, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x66EE, 0, 282, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66ED, 0, 282, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6740, 0, 282, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x6741, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6752, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6751, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6750, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x674C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x674B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6748, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6749, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 q_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_096[44] = {
    L4(3, 2, 771, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 q_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_dmca_097[44] = {
    L4(3, 2, 771, 0, 0, 0, 0, 0x674A, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x674A, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x674A, 0, 283, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x674A, 0, 283, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x674A, 0, 283, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const q_btca[37] = {
    q_btca_000,  /* 0 AIR NORMAL */
    q_btca_001,  /* 1 ASIBARAI SIRI */
    q_btca_002,  /* 2 ASIB TUNNOMERI */
    q_btca_003,  /* 3 NOKEZORI */
    q_btca_004,  /* 4 KUNOJI */
    q_btca_005,  /* 5 KIRIMOMI */
    q_btca_006,  /* 6 UPPER */
    q_btca_007,  /* 7 BODY UPPER */
    q_btca_008,  /* 8 HARAYARARE */
    q_btca_009,  /* 9 TATAKI AIR */
    q_btca_010,  /* 10 TTKI V. AIR */
    q_btca_011,  /* 11 HUMI ASIB */
    q_btca_012,  /* 12 FACE */
    q_btca_013,  /* 13 ASIB SIRI LOSE */
    q_btca_014,  /* 14 ASIB TUN LOSE */
    q_btca_015,  /* 15 DENKI */
    q_btca_016,  /* 16 KUNOJI NOKE */
    q_btca_017,  /* 17 BODY UPPER SP */
    q_btca_018,  /* 18 HANEAGARI */
    q_btca_019,  /* 19 TOUKETSU A */
    q_btca_020,  /* 20 BODY SLAM */
    q_btca_021,  /* 21 IPPONZEOI */
    q_btca_022,  /* 22 TOMOE RYU */
    q_btca_023,  /* 23 MONKEY FLIP */
    q_btca_024,  /* 24 TOMOE ORO */
    q_btca_025,  /* 25 SNAKE FANG */
    q_btca_026,  /* 26 FLANKEN.S */
    q_btca_027,  /* 27 KISHINRIKI */
    q_btca_028,  /* 28 SPLASH.M */
    q_btca_029,  /* 29 HARAIGOSHI */
    q_btca_030,  /* 30 ALEX B.D */
    q_btca_031,  /* 31 GILL */
    q_btca_032,  /* 32 HANEKAERI HARA */
    q_btca_033,  /* 33 S HANEAGARI */
    q_btca_034,  /* 34 TATUMAKIZANKU */
    q_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 q_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_000[68] = {
    CMD(CM_JSR, 8, 41, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x671A, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 770, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x671A, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x6AD2, 0, 393, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 q_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_001[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6754, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6755, 0, 395, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6756, 0, 396, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6757, 0, 397, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 q_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_btca_002[44] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6763, 0, 398, 0, 0, 0, 0, 0),
    L4(3, 0, 770, 0, 0, 0, 0, 0x6764, 0, 399, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6764, 0, 399, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI */
const u16 q_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_003[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6734, 0, 401, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 q_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_004[76] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x671A, 0, 279, 0, 0, 0, 0, 0),
    L4(5, 0, 770, 0, 0, 0, 6, 0x671F, 0, 408, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6720, 0, 408, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x674B, 0, 409, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 5, 0x674C, 0, 410, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x674D, 0, 411, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x674D, 0, 411, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 q_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_005[164] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6798, 0, 412, 0, 0, 0, 0, 0),
    L4(3, 0, 771, 0, 0, 0, 0, 0x6799, 0, 413, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x679A, 0, 413, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x679B, 0, 413, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 8, 0x679C, 0, 414, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x679D, 0, 415, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x679E, 0, 416, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x679F, 0, 417, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x67A0, 0, 417, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x67A1, 0, 418, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 10, 0x67A2, 0, 419, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 11, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 q_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_006[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6770, 0, 420, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6771, 0, 421, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6772, 0, 422, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6779, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 q_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_007[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6718, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6775, 0, 425, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6776, 0, 426, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6777, 0, 427, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6778, 0, 428, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6779, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 q_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_008[92] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x671A, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6734, 0, 401, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 TATAKI AIR */
const u16 q_btca_009_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_009[84] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6734, 0, 401, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 q_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_010[44] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6758, 0, 429, 0, 0, 0, 0, 0),
    L4(5, 0, 771, 0, 0, 0, 0, 0x6759, 0, 430, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6759, 0, 430, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 q_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 q_btca_011[52] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6754, 0, 394, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6755, 0, 395, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6756, 0, 396, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6757, 0, 397, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 q_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_012[84] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6702, 0, 431, 0, 0, 0, 0, 0),
    L4(4, 0, 770, 0, 0, 0, 0, 0x6779, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 q_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 q_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_014[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 q_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_015[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x6730, 0, 432, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6730, 0, 432, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6731, 0, 432, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6732, 0, 432, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSE, 771, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 q_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_016[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x671A, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 770, 0, 0, 0, 0, 0x671F, 0, 408, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6720, 0, 408, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6734, 0, 401, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 q_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_017[124] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 770, 0, 0, 0, 0, 0x6734, 0, 401, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 q_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_018[148] = {
    CMD(CM_RJA, 6, 18, 8), 0, 0, 0, 0,
    L4(3, 0, 770, 0, 0, 0, 0, 0x674E, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x674F, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x6750, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 10, 0x6751, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 12, 0x6752, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x6753, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 2, 285, 0, 0, 0, 0, 0x6742, 0, 281, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6743, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6744, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6745, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6746, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6747, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6748, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 q_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    L4(250, 0, 770, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 q_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_020[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x674E, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x674D, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 q_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_021[60] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x674D, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ASXY, 116, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 7, 6, 2), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x6752, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 q_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_022[44] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x6756, 0, 279, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6757, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6757, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 q_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_btca_023[44] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6755, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6756, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6757, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 q_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_btca_024[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x675B, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x675C, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x675D, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x675E, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x675E, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 q_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_025[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 9, 0x6735, 0, 279, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 12, 0x6736, 0, 279, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6737, 0, 279, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6738, 0, 279, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 14, 0x6739, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 9, 0x673A, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 q_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_026[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6755, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6756, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6757, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 q_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_027[76] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 15, 0x6735, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6736, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x6737, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6738, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x6739, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 15, 0x673A, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 15, 0x673A, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 q_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_028[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x674F, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6750, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6751, 0, 281, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6752, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6753, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 q_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_029[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x673B, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673B, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 q_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_030[20] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x674D, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x674E, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 q_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_031[36] = {
    CMD(CM_DUMMY, 0, 0, 26467), 0x0022, 0xE000, 0x0000, 0x0000,
    L4(3, 0, 770, 0, 0, 0, 0, 0x6764, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6764, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 q_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_032[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x6718, 0, 424, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6733, 0, 400, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 q_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_033[168] = {
    L4(250, 130, 0, 0, 0, 0, 12, 0x6787, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(2, 0, 770, 0, 0, 0, 12, 0x6752, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 14, 0x6753, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 2, 285, 0, 0, 0, 0, 0x6742, 0, 281, 0, 0, 0, 22, 38),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6743, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6744, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6745, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6746, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6747, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6748, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 6, 33, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6752, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 12, 0x6752, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 4), 0, 0, 0, 0,
};

/* script: 34 TATUMAKIZANKU */
const u16 q_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_btca_034[100] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6770, 0, 420, 0, 0, 0, 0, 0),
    L4(2, 0, 771, 0, 0, 0, 0, 0x6771, 0, 421, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6772, 0, 422, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6779, 0, 423, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6735, 0, 402, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6736, 0, 403, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6737, 0, 404, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6738, 0, 405, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6739, 0, 406, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x673A, 0, 407, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 17 entries */
const u16* const q_caca[18] = {
    q_caca_000,  /* 0 CATCH 1 */
    q_caca_001,  /* 1 CATCH 2 */
    q_caca_001,  /* 2 CATCH 3 */
    q_caca_001,  /* 3 CATCH 4 */
    q_caca_004,  /* 4 CATCH 5 */
    q_caca_005,  /* 5 CATCH 6 */
    q_caca_005,  /* 6 CATCH 7 */
    q_caca_005,  /* 7 CATCH 8 */
    q_caca_008,  /* 8 CATCH 9 */
    q_caca_009,  /* 9 CATCH 10 */
    q_caca_009,  /* 10 CATCH 11 */
    q_caca_009,  /* 11 CATCH 12 */
    q_caca_012,  /* 12 CATCH 13 */
    q_caca_013,  /* 13 CATCH 14 */
    q_caca_014,  /* 14 CATCH 15 */
    q_caca_014,  /* 15 CATCH 16 */
    q_caca_016,  /* 16 CATCH 17 */
    0
};

/* script: 0 CATCH 1 */
const u16 q_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 q_caca_000[364] = {
    CMD(CM_NGDA, 1542, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 256, 24, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E1, 0, 0, 0, 0, 0, 0, 0, 256, 48, 58, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E2, 0, 0, 0, 0, 0, 0, 0, 256, 72, 60, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E3, 0, 0, 0, 0, 0, 0, 0, 256, 96, 62, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E4, 0, 0, 0, 0, 0, 0, 0, 256, 120, 64, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68E5, 0, 0, 0, 0, 0, 0, 0, 256, 144, 66, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x68E6, 0, 0, 0, 0, 0, 0, 0, 256, 168, 68, 0, 0),
    L6(3, 0, 775, 0, 0, 0, 0, 0x68E7, 0, 0, 0, 0, 0, 0, 0, 256, 192, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E8, 0, 0, 0, 0, 0, 0, 0, 256, 216, 72, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x68E9, 0, 0, 0, 0, 0, 0, 0, 256, 240, 74, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x68EA, -42, 0, 0, 0, 0, 0, 0, 256, 264, 76, 0, 0),
    L6(11, 3, 0, 0, 0, 0, 0, 0x68EB, 0, 0, 0, 0, 0, 0, 0, 256, 288, 78, 0, 0),
    L6(5, 9, 0, 0, 0, 0, 0, 0x68EC, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68ED, 0, 1, 0, 0, 0, 0, 0, 256, 0, 80, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68EE, 0, 1, 0, 0, 0, 0, 0, 256, 0, 82, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68EF, 0, 1, 0, 0, 0, 0, 0, 256, 0, 84, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F0, 0, 1, 0, 0, 0, 0, 0, 256, 0, 86, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6613, 0, 1, 0, 0, 0, 0, 0, 256, 0, 88, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x660B, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6602, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6603, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6605, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6606, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6607, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6608, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2, 2 CATCH 3, 3 CATCH 4 */
const u16 q_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 q_caca_001[364] = {
    CMD(CM_NGDA, 1542, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 256, 24, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E1, 0, 0, 0, 0, 0, 0, 0, 256, 48, 58, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E2, 0, 0, 0, 0, 0, 0, 0, 256, 72, 60, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E3, 0, 0, 0, 0, 0, 0, 0, 256, 96, 62, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E4, 0, 0, 0, 0, 0, 0, 0, 256, 120, 64, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68E5, 0, 0, 0, 0, 0, 0, 0, 256, 144, 66, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x68E6, 0, 0, 0, 0, 0, 0, 0, 256, 168, 68, 0, 0),
    L6(4, 0, 775, 0, 0, 0, 0, 0x68E7, 0, 0, 0, 0, 0, 0, 0, 256, 192, 70, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E8, 0, 0, 0, 0, 0, 0, 0, 256, 216, 72, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E9, 0, 0, 0, 0, 0, 0, 0, 256, 240, 74, 0, 0),
    L6(3, 2, 0, 0, 0, 0, 0, 0x68EA, -42, 0, 0, 0, 0, 0, 0, 256, 264, 76, 0, 0),
    L6(12, 3, 0, 0, 0, 0, 0, 0x68EB, 0, 0, 0, 0, 0, 0, 0, 256, 288, 78, 0, 0),
    L6(5, 9, 0, 0, 0, 0, 0, 0x68EC, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68ED, 0, 1, 0, 0, 0, 0, 0, 256, 0, 80, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68EE, 0, 1, 0, 0, 0, 0, 0, 256, 0, 82, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68EF, 0, 1, 0, 0, 0, 0, 0, 256, 0, 84, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F0, 0, 1, 0, 0, 0, 0, 0, 256, 0, 86, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6613, 0, 1, 0, 0, 0, 0, 0, 256, 0, 88, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x660B, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6602, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6603, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6605, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6606, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6607, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6608, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6609, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 CATCH 5 */
const u16 q_caca_004_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 q_caca_004[400] = {
    CMD(CM_NGDA, 1542, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F6, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F7, 0, 0, 0, 0, 0, 0, 0, 256, 384, 90, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F8, 0, 0, 0, 0, 0, 0, 0, 256, 408, 92, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68F9, 0, 0, 0, 0, 0, 0, 0, 256, 432, 94, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68FA, 0, 0, 0, 0, 0, 0, 0, 256, 456, 96, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68FB, 0, 0, 0, 0, 0, 0, 0, 256, 480, 98, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68FC, 0, 0, 0, 0, 0, 0, 0, 256, 504, 100, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68FD, 0, 0, 0, 0, 0, 0, 0, 256, 528, 102, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68FE, 0, 0, 0, 0, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x68FF, 0, 1, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    L6(2, 0, 775, 0, 0, 0, 0, 0x6900, 0, 1, 0, 0, 0, 0, 0, 256, 600, 0, 0, 0),
    L6(1, 2, 0, 0, 0, 0, 0, 0x6901, -44, 1, 0, 0, 0, 0, 0, 256, 624, 104, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 3, 0, 1, 0, 1, 0, 0x6902, 0, 1, 0, 0, 0, 0, 0, 256, 648, 0, 0, 0),
    L6(3, 9, 0, 1, 0, 2, 0, 0x6903, 0, 1, 0, 0, 0, 0, 0, 256, 672, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 3, 0, 0x6904, 0, 1, 0, 0, 0, 0, 0, 256, 696, 106, 0, 0),
    L6(3, 0, 0, 1, 0, 4, 0, 0x6905, 0, 1, 0, 0, 0, 0, 0, 256, 720, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x6906, 0, 1, 0, 0, 0, 0, 0, 256, 744, 0, 0, 0),
    L6(5, 0, 0, 1, 0, 0, 0, 0x6907, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x6908, 0, 1, 0, 0, 0, 0, 0, 256, 0, 108, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x6909, 0, 1, 0, 0, 0, 0, 0, 256, 0, 110, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x690A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 112, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AB, 0, 1, 0, 0, 0, 0, 0, 256, 0, 114, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AC, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AD, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AE, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 CATCH 6, 6 CATCH 7, 7 CATCH 8 */
const u16 q_caca_005_head[4] = { HEAD(6, 0, 21, 0, 0, 0, 0) };
const u16 q_caca_005[400] = {
    CMD(CM_NGDA, 1542, 50, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F6, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F7, 0, 0, 0, 0, 0, 0, 0, 256, 384, 90, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F8, 0, 0, 0, 0, 0, 0, 0, 256, 408, 92, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F9, 0, 0, 0, 0, 0, 0, 0, 256, 432, 94, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68FA, 0, 0, 0, 0, 0, 0, 0, 256, 456, 96, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68FB, 0, 0, 0, 0, 0, 0, 0, 256, 480, 98, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68FC, 0, 0, 0, 0, 0, 0, 0, 256, 504, 100, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68FD, 0, 0, 0, 0, 0, 0, 0, 256, 528, 102, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x68FE, 0, 0, 0, 0, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x68FF, 0, 1, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    L6(3, 0, 775, 0, 0, 0, 0, 0x6900, 0, 1, 0, 0, 0, 0, 0, 256, 600, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x6901, -44, 1, 0, 0, 0, 0, 0, 256, 624, 104, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 3, 0, 0, 0, 1, 0, 0x6902, 0, 1, 0, 0, 0, 0, 0, 256, 648, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 2, 0, 0x6903, 0, 1, 0, 0, 0, 0, 0, 256, 672, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 3, 0, 0x6904, 0, 1, 0, 0, 0, 0, 0, 256, 696, 106, 0, 0),
    L6(3, 0, 0, 0, 0, 4, 0, 0x6905, 0, 1, 0, 0, 0, 0, 0, 256, 720, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6906, 0, 1, 0, 0, 0, 0, 0, 256, 744, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6907, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6908, 0, 1, 0, 0, 0, 0, 0, 256, 0, 108, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6909, 0, 1, 0, 0, 0, 0, 0, 256, 0, 110, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x690A, 0, 1, 0, 0, 0, 0, 0, 256, 0, 112, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AB, 0, 1, 0, 0, 0, 0, 0, 256, 0, 114, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AC, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AD, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67AE, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 CATCH 9 */
const u16 q_caca_008_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 q_caca_008[76] = {
    CMD(CM_NGDA, 1542, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E1, 0, 0, 0, 0, 0, 0, 0, 0, 48, 58, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E2, 0, 0, 0, 0, 0, 0, 0, 0, 72, 60, 0, 0),
    L6(3, 6, 0, 0, 0, 0, 0, 0x68E3, 0, 0, 0, 0, 0, 0, 0, 256, 96, 62, 0, 0),
    CMD(CM_JMP, 2, 0, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 CATCH 10, 10 CATCH 11, 11 CATCH 12 */
const u16 q_caca_009_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 q_caca_009[76] = {
    CMD(CM_NGDA, 1542, 49, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 56, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E1, 0, 0, 0, 0, 0, 0, 0, 0, 48, 58, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68E2, 0, 0, 0, 0, 0, 0, 0, 0, 72, 60, 0, 0),
    L6(3, 6, 0, 0, 0, 0, 0, 0x68E3, 0, 0, 0, 0, 0, 0, 0, 256, 96, 62, 0, 0),
    CMD(CM_JMP, 2, 1, 6), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 CATCH 13 */
const u16 q_caca_012_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 q_caca_012[292] = {
    CMD(CM_NGDA, 0, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x6968, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 0, 777, 0, 0, 0, 0, 0x6969, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x696A, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x696B, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x696C, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x696D, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x696E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x696F, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 2, 775, 0, 0, 0, 0, 0x6970, -2, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x6971, 0, 0, 0, 0, 0, 0, 0, 0, 984, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x6972, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6973, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6974, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6975, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6976, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6977, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6978, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x666A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 CATCH 14 */
const u16 q_caca_013_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 q_caca_013[136] = {
    CMD(CM_NGDA, 0, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x6968, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 0, 777, 0, 0, 0, 0, 0x6969, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x696A, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x696B, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x696C, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x696D, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x696E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x696F, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 2, 775, 0, 0, 0, 0, 0x6970, -5, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_JMP, 2, 12, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 CATCH 15, 15 CATCH 16 */
const u16 q_caca_014_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 q_caca_014[136] = {
    CMD(CM_NGDA, 0, 57, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0x6968, 0, 0, 0, 0, 0, 0, 0, 0, 768, 0, 0, 0),
    L6(2, 0, 777, 0, 0, 0, 0, 0x6969, 0, 0, 0, 0, 0, 0, 0, 0, 792, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x696A, 0, 0, 0, 0, 0, 0, 0, 0, 816, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x696B, 0, 0, 0, 0, 0, 0, 0, 0, 840, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x696C, 0, 0, 0, 0, 0, 0, 0, 0, 864, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x696D, 0, 0, 0, 0, 0, 0, 0, 0, 888, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x696E, 0, 0, 0, 0, 0, 0, 0, 0, 912, 0, 0, 0),
    L6(14, 0, 0, 0, 0, 0, 0, 0x696F, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 2, 775, 0, 0, 0, 0, 0x6970, -11, 0, 0, 0, 0, 0, 0, 0, 960, 0, 0, 0),
    CMD(CM_JMP, 2, 12, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 CATCH 17 */
const u16 q_caca_016_head[4] = { HEAD(6, 0, 56, 0, 0, 0, 0) };
const u16 q_caca_016[196] = {
    CMD(CM_NGDA, 0, 64, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_PS_Y, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 264, 0, 0, 0, 0, 0x68E0, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A54, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 484, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A55, 0, 0, 0, 0, 0, 0, 0, 8721, 1104, 486, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A56, 0, 0, 0, 0, 0, 0, 0, 8721, 1128, 488, 0, 0),
    L6(8, 0, 775, 0, 0, 15, 0, 0x6A57, 0, 0, 0, 0, 0, 0, 0, 8721, 1152, 490, 0, 0),
    L6(12, 2, 0, 0, 0, 16, 0, 0x6A58, -68, 0, 0, 0, 0, 0, 0, 8721, 1176, 0, 0, 0),
    CMD(CM_EXEC, 1, 146, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 48, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 3, 0, 0, 0, 17, 0, 0x6A59, 0, 0, 0, 0, 0, 42, 6, 8721, 1200, 0, 0, 0),
    L6(17, 0, 0, 0, 0, 0, 0, 0x6A5A, 0, 0, 0, 0, 0, 42, 4, 8721, 1224, 0, 0, 0),
    L6(1, 9, 0, 0, 0, 0, 0, 0x6A5A, 0, 0, 0, 0, 0, 0, 0, 8721, 1248, 0, 0, 0),
    L6(3, 50, 0, 0, 0, 0, 0, 0x6A5A, 0, 0, 0, 0, 0, 0, 0, 8721, 0, 0, 0, 0),
    L6(2, 50, 0, 0, 0, 0, 0, 0x6A5A, 0, 0, 0, 0, 0, 0, 0, 8721, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6A5A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const q_cuca[69] = {
    q_cuca_000,  /* 0 ALEX ZUTUKI */
    q_cuca_001,  /* 1 ALEX BODY S */
    q_cuca_002,  /* 2 ALEX BACK D */
    q_cuca_003,  /* 3 ALEX POWER B */
    q_cuca_004,  /* 4 ALEX SLEEPER */
    q_cuca_005,  /* 5 RYU SEOINAGE */
    q_cuca_006,  /* 6 IBUKI */
    q_cuca_007,  /* 7 DADLEY L B */
    q_cuca_008,  /* 8 IBUKI KUBIORI */
    q_cuca_009,  /* 9 NECRO S T */
    q_cuca_010,  /* 10 RYU TOMOENAGE */
    q_cuca_011,  /* 11 YUN HIZAGERI */
    q_cuca_012,  /* 12 ORO KUBISIME */
    q_cuca_013,  /* 13 NECRO G S */
    q_cuca_014,  /* 14 DUDDLEY D S */
    q_cuca_015,  /* 15 YUN MONKEY F */
    q_cuca_016,  /* 16 ORO TOMOENAGE */
    q_cuca_017,  /* 17 ORO NIOURIKI */
    q_cuca_018,  /* 18 ORO GIGOKU G */
    q_cuca_019,  /* 19 YUN */
    q_cuca_020,  /* 20 NECRO SNAKE F */
    q_cuca_021,  /* 21 NECRO F S */
    q_cuca_022,  /* 22 IBUKI HARAIG */
    q_cuca_023,  /* 23 GILL SPLASH M */
    q_cuca_024,  /* 24 KEN HIZAGERI */
    q_cuca_025,  /* 25 ORO KISINRIKI */
    q_cuca_026,  /* 26 SEAN TACKLE */
    q_cuca_027,  /* 27 ALEX HYPER B */
    q_cuca_028,  /* 28 NECRO SLAM D */
    q_cuca_029,  /* 29 ELENA ASINAGE */
    q_cuca_030,  /* 30 GILL IMPACT C */
    q_cuca_031,  /* 31 ALEX S H B */
    q_cuca_032,  /* 32 ALEX F N D */
    q_cuca_033,  /* 33 no name */
    q_cuca_034,  /* 34 IBUKI */
    q_cuca_035,  /* 35 IBUKI YOROI D */
    q_cuca_036,  /* 36 no name */
    q_cuca_037,  /* 37 MAWARIKOMI M F */
    q_cuca_038,  /* 38 HUGO BODY S */
    q_cuca_039,  /* 39 HUGO N G T */
    q_cuca_040,  /* 40 HUGO M S P */
    q_cuca_041,  /* 41 HUGO S D B B */
    q_cuca_042,  /* 42 no name */
    q_cuca_043,  /* 43 no name */
    q_cuca_044,  /* 44 no name */
    q_cuca_045,  /* 45 no name */
    q_cuca_046,  /* 46 no name */
    q_cuca_047,  /* 47 no name */
    q_cuca_048,  /* 48 no name */
    q_cuca_049,  /* 49 no name */
    q_cuca_050,  /* 50 no name */
    q_cuca_051,  /* 51 no name */
    q_cuca_052,  /* 52 no name */
    q_cuca_053,  /* 53 no name */
    q_cuca_054,  /* 54 no name */
    q_cuca_055,  /* 55 no name */
    q_cuca_056,  /* 56 no name */
    q_cuca_057,  /* 57 no name */
    q_cuca_058,  /* 58 no name */
    q_cuca_059,  /* 59 no name */
    q_cuca_060,  /* 60 no name */
    q_cuca_061,  /* 61 no name */
    q_cuca_062,  /* 62 no name */
    q_cuca_063,  /* 63 no name */
    q_cuca_064,  /* 64 no name */
    q_cuca_065,  /* 65 no name */
    q_cuca_066,  /* 66 no name */
    q_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 q_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x676C),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 q_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_001[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6785),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6752),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6752),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6778),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x674E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 3, 1, 15),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_ASXY, 116, 0, 0),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 q_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_002[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    CMD(CM_RMJA, 3, 2, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x673C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 q_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_003[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6723),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6723),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    CMD(CM_RMJA, 3, 3, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6750),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 q_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 1, 0, 0, 0x676E),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x676E),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 q_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6783),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6784),
    L2(250, 0, 0, 0, 1, 0, 0, 0x67AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 3, 0, 0, 0x679E),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 1, 0, 0, 0x674D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 6, 21, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 q_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 q_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 q_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662F),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6702),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 10, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 q_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6702),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 q_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6725),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6756),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 q_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6774),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6702),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 q_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_012[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6650),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6651),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6652),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6652),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6652),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6783),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6724),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6725),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x671E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 q_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6631),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6630),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6631),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6751),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6753),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x675A),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 q_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6725),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6724),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6720),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 q_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6763),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6764),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x675C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 q_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6764),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6740),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x675B),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 q_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_017[108] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 1, 0, 0, 0x670F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x670C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6738),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6736),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 2, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673D),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x673D),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 q_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6759),
    L2(250, 3, 0, 0, 0, 0, 0, 0x675A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675D),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x675D),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 q_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6630),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6710),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 q_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x666E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x666F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6670),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6671),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6672),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6673),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6674),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6707),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6738),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6737),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6736),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 q_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6661),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6661),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6662),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6663),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6664),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6665),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6666),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6667),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6668),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6669),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6763),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 q_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6707),
    L2(250, 0, 0, 0, 1, 0, 0, 0x670F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6737),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6738),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6739),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673A),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x673B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 q_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_023[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6774),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6737),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6736),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x671F),
    CMD(CM_RMJA, 3, 23, 22),
    L2(250, 9, 0, 0, 0, 0, 0, 0x674E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 q_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_024[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    CMD(CM_RMJA, 3, 24, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6734),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 3, 24, 14),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 7, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 q_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_025[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 1, 0, 0, 0x670F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x670C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6738),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6736),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 2, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 q_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_026[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6738),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 3, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6740),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6745),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6746),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6747),
    L2(250, 3, 0, 0, 1, 0, 0, 0x6787),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6787),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 q_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6750),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 q_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6631),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6630),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6631),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6688),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6751),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6734),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 q_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6602),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6603),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674D),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6755),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 q_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6774),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6780),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6773),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6772),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6772),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6771),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6771),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 q_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x676C),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 q_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_032[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6741),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6787),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6787),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 15),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 q_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_033[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    CMD(CM_RMJA, 3, 33, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x674D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 3, 33, 17),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_ASXY, 116, 0, 0),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 q_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6778),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 q_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_035[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 no name */
const u16 q_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_036[168] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6717),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6719),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6707),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6709),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 2, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6740),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6741),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6742),
    L2(250, 2, 0, 0, 1, 0, 0, 0x6787),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6788),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6743),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6745),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6746),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 1, 60, 9),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 q_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_037[132] = {
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
const u16 q_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_038[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x683E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6840),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 1, 0, 0, 0x675A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x675F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6760),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x673C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 q_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6734),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 q_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_040[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6784),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6782),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 1, 0, 0, 0x67D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 2, 0, 0, 0x67A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6740),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6741),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6760),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6761),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6762),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6749),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6749),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 1, 0, 0, 0x674A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 17),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 q_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6743),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6745),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6764),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 q_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6713),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x671F),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 q_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674A),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x674A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 q_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_044[216] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6784),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6782),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67D7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 1, 0, 0, 0x67D6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 2, 0, 0, 0x67A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6740),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6741),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6760),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6761),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6762),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6749),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6749),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6742),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6743),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6745),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6764),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674E),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x66F6),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 17),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 q_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x676E),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 q_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6750),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 1, 0, 0, 0x67A0),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 2, 0, 0, 0x67A0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6740),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6741),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6752),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 q_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_047[120] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6775),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6776),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6759),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    CMD(CM_RMJA, 3, 47, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x673C),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 q_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x676C),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 q_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 1, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6764),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6750),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 q_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_050[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6774),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6756),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675D),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x675E),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 3, 50, 23),
    CMD(CM_JMP, 6, 1, 5),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 q_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6781),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x67AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6718),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 29, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 q_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6601),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6725),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6752),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6755),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6756),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 q_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_053[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6719),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6717),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6715),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6713),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 3, 0, 0, 0x675C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6720),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x674D),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 q_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6717),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6715),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6772),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6771),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6770),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 q_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6719),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6717),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6716),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6715),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6713),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 3, 0, 0, 0x675C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6753),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 q_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_056[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6704),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 2, 0, 0, 0, 0, 0, 0x671A),
    CMD(CM_RMJA, 3, 56, 11),
    L2(250, 9, 0, 0, 0, 0, 6, 0x671F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 q_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x662E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x674B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 q_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_058[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6777),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6770),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6778),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6733),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 q_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x666D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x666E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x666F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6670),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6671),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6672),
    L2(250, 0, 0, 0, 0, 0, 0, 0x670A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6711),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6712),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 q_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_060[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6703),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6704),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    CMD(CM_RMJA, 3, 60, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x671B),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 q_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x668A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6689),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6688),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6687),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6754),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6710),
    L2(250, 0, 0, 0, 0, 0, 0, 0x674C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6734),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 q_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_062[168] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677A),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677B),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677C),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677E),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677F),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6782),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x676F),
    CMD(CM_PA_X, 0, 3072, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x674B),
    CMD(CM_PA_X, 0, -5120, 0),
    CMD(CM_PS_Y, 0, 0, 88),
    L2(250, 0, 0, 0, 2, 0, 0, 0x674D),
    CMD(CM_PA_X, 0, -6656, 0),
    CMD(CM_PS_Y, 0, 0, -4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x673C),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 1, 0, 0, 0x673D),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 7, 6, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 q_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x671B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6700),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6718),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 770, 0, 0, 0, 0, 0x671F),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 q_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x671A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6714),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6722),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6721),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x671A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 q_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6705),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6783),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6784),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6785),
    L2(250, 0, 0, 0, 0, 0, 0, 0x677D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x677F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6764),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6764),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x675C),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 q_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6701),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6702),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6773),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6733),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6757),
    L2(250, 0, 0, 0, 0, 0, 0, 0x675C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6760),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6760),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 q_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6758),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x676F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6706),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6707),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6708),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6735),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 156 entries */
const u16* const q_atca[157] = {
    q_atca_000,  /* 0 S PUNCH A */
    q_atca_001,  /* 1 S PUNCH B */
    q_atca_001,  /* 2 S PUNCH C */
    q_atca_003,  /* 3 M PUNCH A */
    q_atca_003,  /* 4 M PUNCH B */
    q_atca_005,  /* 5 M PUNCH C */
    q_atca_006,  /* 6 L PUNCH A */
    q_atca_006,  /* 7 L PUNCH B */
    q_atca_008,  /* 8 L PUNCH C */
    q_atca_009,  /* 9 S KICK A */
    q_atca_009,  /* 10 S KICK B */
    q_atca_009,  /* 11 S KICK C */
    q_atca_012,  /* 12 M KICK A */
    q_atca_013,  /* 13 M KICK B */
    q_atca_013,  /* 14 M KICK C */
    q_atca_015,  /* 15 L KICK A */
    q_atca_015,  /* 16 L KICK B */
    q_atca_017,  /* 17 L KICK C */
    q_atca_018,  /* 18 KAGAMI P A */
    q_atca_018,  /* 19 KAGAMI P B */
    q_atca_018,  /* 20 KAGAMI P C */
    q_atca_021,  /* 21 KAGAMI P A */
    q_atca_021,  /* 22 KAGAMI P B */
    q_atca_021,  /* 23 KAGAMI P C */
    q_atca_024,  /* 24 KAGAMI P A */
    q_atca_024,  /* 25 KAGAMI P B */
    q_atca_024,  /* 26 KAGAMI P C */
    q_atca_027,  /* 27 KAGAMI K A */
    q_atca_027,  /* 28 KAGAMI K B */
    q_atca_027,  /* 29 KAGAMI K C */
    q_atca_030,  /* 30 KAGAMI K A */
    q_atca_030,  /* 31 KAGAMI K B */
    q_atca_030,  /* 32 KAGAMI K C */
    q_atca_033,  /* 33 KAGAMI K A */
    q_atca_033,  /* 34 KAGAMI K B */
    q_atca_033,  /* 35 KAGAMI K C */
    q_atca_036,  /* 36 V JUMP P S A */
    q_atca_036,  /* 37 V JUMP P S B */
    q_atca_038,  /* 38 V JUMP P M A */
    q_atca_038,  /* 39 V JUMP P M B */
    q_atca_040,  /* 40 V JUMP P L A */
    q_atca_040,  /* 41 V JUMP P L B */
    q_atca_042,  /* 42 V JUMP K S A */
    q_atca_042,  /* 43 V JUMP K S B */
    q_atca_044,  /* 44 V JUMP K M A */
    q_atca_044,  /* 45 V JUMP K M B */
    q_atca_046,  /* 46 V JUMP K L A */
    q_atca_046,  /* 47 V JUMP K L B */
    q_atca_048,  /* 48 F JUMP P S A */
    q_atca_048,  /* 49 F JUMP P S B */
    q_atca_050,  /* 50 F JUMP P M A */
    q_atca_050,  /* 51 F JUMP P M B */
    q_atca_052,  /* 52 F JUMP P L A */
    q_atca_052,  /* 53 F JUMP P L B */
    q_atca_054,  /* 54 F JUMP K S A */
    q_atca_054,  /* 55 F JUMP K S B */
    q_atca_056,  /* 56 F JUMP K M A */
    q_atca_056,  /* 57 F JUMP K M B */
    q_atca_058,  /* 58 F JUMP K L A */
    q_atca_058,  /* 59 F JUMP K L B */
    q_atca_060,  /* 60 B JUMP P S A */
    q_atca_060,  /* 61 B JUMP P S B */
    q_atca_062,  /* 62 B JUMP P M A */
    q_atca_062,  /* 63 B JUMP P M B */
    q_atca_064,  /* 64 B JUMP P L A */
    q_atca_064,  /* 65 B JUMP P L B */
    q_atca_066,  /* 66 B JUMP K S A */
    q_atca_066,  /* 67 B JUMP K S B */
    q_atca_068,  /* 68 B JUMP K M A */
    q_atca_068,  /* 69 B JUMP K M B */
    q_atca_070,  /* 70 B JUMP K L A */
    q_atca_070,  /* 71 B JUMP K L B */
    q_atca_072,  /* 72 SP V JP S P A */
    q_atca_072,  /* 73 SP V JP S P B */
    q_atca_074,  /* 74 SP V JP M P A */
    q_atca_074,  /* 75 SP V JP M P B */
    q_atca_076,  /* 76 SP V JP L P A */
    q_atca_076,  /* 77 SP V JP L P B */
    q_atca_078,  /* 78 SP V JP S K A */
    q_atca_078,  /* 79 SP V JP S K B */
    q_atca_080,  /* 80 SP V JP M K A */
    q_atca_080,  /* 81 SP V JP M K B */
    q_atca_082,  /* 82 SP V JP L K A */
    q_atca_082,  /* 83 SP V JP L K B */
    q_atca_084,  /* 84 SP F JP S P A */
    q_atca_084,  /* 85 SP F JP S P B */
    q_atca_086,  /* 86 SP F JP M P A */
    q_atca_086,  /* 87 SP F JP M P B */
    q_atca_088,  /* 88 SP F JP L P A */
    q_atca_088,  /* 89 SP F JP L P B */
    q_atca_090,  /* 90 SP F JP S K A */
    q_atca_090,  /* 91 SP F JP S K B */
    q_atca_092,  /* 92 SP F JP M K A */
    q_atca_092,  /* 93 SP F JP M K B */
    q_atca_094,  /* 94 SP F JP L K A */
    q_atca_094,  /* 95 SP F JP L K B */
    q_atca_096,  /* 96 SP B JP S P A */
    q_atca_096,  /* 97 SP B JP S P B */
    q_atca_098,  /* 98 SP B JP M P A */
    q_atca_098,  /* 99 SP B JP M P B */
    q_atca_100,  /* 100 SP B JP L P A */
    q_atca_100,  /* 101 SP B JP L P B */
    q_atca_102,  /* 102 SP B JP S K A */
    q_atca_102,  /* 103 SP B JP S K B */
    q_atca_104,  /* 104 SP B JP M K A */
    q_atca_104,  /* 105 SP B JP M K B */
    q_atca_106,  /* 106 SP B JP L K A */
    q_atca_106,  /* 107 SP B JP L K B */
    q_atca_108,  /* 108 S V JP S P A */
    q_atca_108,  /* 109 S V JP S P B */
    q_atca_108,  /* 110 S V JP M P A */
    q_atca_108,  /* 111 S V JP M P B */
    q_atca_108,  /* 112 S V JP L P A */
    q_atca_108,  /* 113 S V JP L P B */
    q_atca_108,  /* 114 S V JP S K A */
    q_atca_108,  /* 115 S V JP S K B */
    q_atca_108,  /* 116 S V JP M K A */
    q_atca_108,  /* 117 S V JP M K B */
    q_atca_108,  /* 118 S V JP L K A */
    q_atca_108,  /* 119 S V JP L K B */
    q_atca_108,  /* 120 S F JP S P A */
    q_atca_108,  /* 121 S F JP S P B */
    q_atca_108,  /* 122 S F JP M P A */
    q_atca_108,  /* 123 S F JP M P B */
    q_atca_108,  /* 124 S F JP L P A */
    q_atca_108,  /* 125 S F JP L P B */
    q_atca_108,  /* 126 S F JP S K A */
    q_atca_108,  /* 127 S F JP S K B */
    q_atca_108,  /* 128 S F JP M K A */
    q_atca_108,  /* 129 S F JP M K B */
    q_atca_108,  /* 130 S F JP L K A */
    q_atca_108,  /* 131 S F JP L K B */
    q_atca_108,  /* 132 S B JP S P A */
    q_atca_108,  /* 133 S B JP S P B */
    q_atca_108,  /* 134 S B JP M P A */
    q_atca_108,  /* 135 S B JP M P B */
    q_atca_108,  /* 136 S B JP L P A */
    q_atca_108,  /* 137 S B JP L P B */
    q_atca_108,  /* 138 S B JP S K A */
    q_atca_108,  /* 139 S B JP S K B */
    q_atca_108,  /* 140 S B JP M K A */
    q_atca_108,  /* 141 S B JP M K B */
    q_atca_108,  /* 142 S B JP L K A */
    q_atca_108,  /* 143 S B JP L K B */
    q_atca_144,  /* 144 TUKAMIKAKARI A */
    q_atca_145,  /* 145 TUKAMIKAKARI B */
    q_atca_146,  /* 146 TUKAMIKAKARI C */
    q_atca_144,  /* 147 TUKAMIKAKARI D */
    q_atca_145,  /* 148 TUKAMIKAKARI E */
    q_atca_146,  /* 149 TUKAMIKAKARI F */
    q_atca_144,  /* 150 TUKAMI AIR A */
    q_atca_048,  /* 151 TUKAMI AIR B */
    q_atca_048,  /* 152 TUKAMI AIR C */
    q_atca_144,  /* 153 TUKAMI AIR D */
    q_atca_048,  /* 154 TUKAMI AIR E */
    q_atca_048,  /* 155 TUKAMI AIR F */
    0
};

/* script: 0 S PUNCH A */
const u16 q_atca_000_head[4] = { HEAD(4, 0, 0, 9, 0, 1, 0) };
const u16 q_atca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x67B9, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x67BA, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67BB, -3, 3, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67BC, 0, 4, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67BD, 0, 5, 0, 0, 96, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67BE, 0, 1, 0, 0, 16, 0, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67BF, 0, 1, 0, 0, 16, 0, 1),
    L4(2, 64, 0, 0, 0, 0, 0, 0x67C0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67C1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67F0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67F1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67F2, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 S PUNCH B, 2 S PUNCH C */
const u16 q_atca_001_head[4] = { HEAD(6, 0, 0, 11, 0, 1, 0) };
const u16 q_atca_001[184] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x67C2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 368, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67C3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67C4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x67C5, -4, 6, 0, 128, 0, 0, 0, 0, 0, 370, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67C6, 0, 7, 0, 0, 16, 0, 2, 0, 0, 372, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67C7, 0, 8, 0, 0, 16, 21, 2, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67C8, 0, 1, 0, 0, 16, 0, 2, 0, 0, 374, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x67C9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67CA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67CB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 q_atca_003_head[4] = { HEAD(6, 0, 2, 14, 0, 1, 0) };
const u16 q_atca_003[268] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x67CC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67CD, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67CE, 0, 20, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0),
    L6(2, 0, 772, 0, 0, 0, 0, 0x67CE, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x67CF, 0, 20, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67D0, -6, 21, 0, 128, 0, 0, 0, 0, 0, 16, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D1, 0, 22, 0, 0, 0, 0, 0, 0, 0, 18, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D2, 0, 23, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D3, 0, 24, 0, 0, 0, 21, 0, 0, 0, 22, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67D4, 0, 25, 0, 0, 0, 0, 0, 0, 0, 352, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67D5, 0, 25, 0, 0, 0, 0, 0, 0, 0, 354, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67D6, 0, 25, 0, 0, 0, 0, 0, 0, 0, 356, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D7, 0, 20, 0, 0, 0, 0, 0, 0, 0, 358, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 360, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67D9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 362, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 364, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x67EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 q_atca_005_head[4] = { HEAD(6, 0, 2, 9, 0, 1, 0) };
const u16 q_atca_005[256] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ADE, 0, 322, 0, 0, 0, 0, 0, 0, 0, 418, 0, 0),
    L6(3, 0, 772, 0, 0, 0, 0, 0x6ADF, 0, 323, 0, 0, 0, 0, 0, 0, 0, 420, 0, 0),
    L6(2, 0, 269, 0, 0, 0, 0, 0x6AE0, 0, 324, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AE1, -15, 325, 0, 0, 0, 0, 0, 0, 0, 422, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AE2, 0, 326, 0, 128, 0, 0, 0, 0, 0, 424, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AE3, 0, 327, 0, 0, 0, 21, 0, 0, 0, 426, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AE4, 0, 328, 0, 0, 0, 0, 0, 0, 0, 428, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AE5, 0, 329, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AE6, 0, 330, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AE7, 0, 331, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 332, 0, 0, 0, 0, 0, 0, 0, 430, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 333, 0, 0, 0, 0, 0, 0, 0, 432, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 334, 0, 0, 0, 0, 0, 0, 0, 434, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x662E, 0, 335, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662F, 0, 336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B */
const u16 q_atca_006_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 q_atca_006[376] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DB, 0, 26, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x67DC, 0, 26, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67DD, 0, 26, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DE, 0, 26, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(1, 0, 775, 0, 0, 0, 0, 0x67DF, 0, 27, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x67E1, 0, 28, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67E2, -72, 29, 0, 0, 0, 0, 0, 0, 0, 366, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x67E2, 73, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 285, 0, 0, 0, 0, 0x67E3, 9, 29, 0, 0, 0, 30, 110, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67E4, 0, 30, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67E4, 0, 30, 0, 0, 0, 30, 111, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x67E5, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x67E6, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67E8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x67EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 q_atca_008_head[4] = { HEAD(6, 0, 4, 12, 0, 1, 0) };
const u16 q_atca_008[376] = {
    CMD(CM_JSR, 8, 23, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x67DA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DB, 0, 26, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DC, 0, 26, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DD, 0, 26, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67DE, 0, 26, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0),
    L6(1, 0, 775, 0, 0, 0, 0, 0x67DF, 0, 27, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67E0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0),
    L6(2, 1, 0, 0, 0, 0, 0, 0x67E1, 0, 28, 0, 0, 0, 0, 0, 0, 0, 124, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x67E2, -7, 29, 0, 0, 0, 0, 0, 0, 0, 366, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x67E2, 8, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 285, 0, 0, 0, 0, 0x67E3, 9, 29, 0, 0, 0, 30, 110, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E4, 0, 30, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E4, 0, 30, 0, 0, 0, 30, 111, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E5, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E6, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E8, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x67E9, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x67EA, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EB, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EC, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67ED, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EE, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67EF, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x67F3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B, 11 S KICK C */
const u16 q_atca_009_head[4] = { HEAD(4, 0, 1, 11, 0, 1, 0) };
const u16 q_atca_009[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6844, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x6844, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6845, -10, 31, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6846, 0, 32, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6847, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6848, 0, 1, 0, 0, 16, 0, 1),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6849, 0, 1, 0, 0, 16, 0, 1),
    L4(2, 64, 0, 0, 0, 0, 0, 0x684A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A */
const u16 q_atca_012_head[4] = { HEAD(4, 0, 3, 10, 0, 1, 0) };
const u16 q_atca_012[140] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x684F, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 776, 0, 0, 0, 0, 0x6870, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6870, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6871, -12, 34, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6872, 0, 35, 0, 0, 96, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6873, 0, 35, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6874, 0, 35, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6875, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6876, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6877, 0, 36, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6878, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6879, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x687A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x687B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 M KICK B, 14 M KICK C */
const u16 q_atca_013_head[4] = { HEAD(4, 0, 3, 14, 0, 1, 0) };
const u16 q_atca_013[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x684F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 776, 0, 0, 0, 0, 0x6850, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6850, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6851, -13, 37, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6852, 0, 38, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6853, 0, 39, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6854, 0, 39, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6856, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6857, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6858, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6859, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 q_atca_015_head[4] = { HEAD(6, 0, 5, 19, 0, 1, 0) };
const u16 q_atca_015[232] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x685A, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x685B, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x685C, 0, 52, 0, 0, 0, 0, 0, 0, 0, 30, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x685D, 0, 53, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0),
    L6(4, 0, 775, 0, 0, 0, 0, 0x685E, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 270, 0, 0, 0, 0, 0x685E, 0, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 1, 0, 0, 0, 0, 0, 0x685F, -18, 54, 0, 128, 0, 30, 109, 0, 0, 34, 0, 0),
    L6(4, 0, 279, 0, 0, 0, 0, 0x6860, 0, 55, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6861, 0, 56, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6862, 0, 57, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6863, 0, 58, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6864, 0, 59, 0, 0, 0, 0, 0, 0, 0, 42, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6865, 0, 59, 0, 0, 0, 0, 0, 0, 0, 44, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6866, 0, 443, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6867, 0, 443, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 q_atca_017_head[4] = { HEAD(4, 0, 5, 11, 0, 1, 0) };
const u16 q_atca_017[252] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x687C, 0, 40, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x687D, 0, 41, 0, 0, 0, 0, 0),
    L4(4, 0, 778, 0, 0, 0, 0, 0x687E, 0, 42, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x687F, 0, 43, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6880, -64, 44, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6881, 17, 45, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6882, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6883, 0, 47, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6884, 0, 47, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6885, 0, 48, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6886, 0, 49, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 74, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 75, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x6887, 0, 49, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6888, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6889, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x688A, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x688B, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x688C, 0, 50, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x688D, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x688E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x688F, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6890, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6891, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6892, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6654, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6655, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6656, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6657, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 q_atca_018_head[4] = { HEAD(4, 32, 0, 14, 0, 1, 0) };
const u16 q_atca_018[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x67F8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67F9, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x67FA, -19, 60, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67FB, 0, 61, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67FC, 0, 62, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67FD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x67FE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67FF, 0, 2, 272, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6800, 0, 2, 272, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x665E, 0, 2, 272, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x665F, 0, 2, 272, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 q_atca_021_head[4] = { HEAD(6, 32, 2, 12, 0, 1, 0) };
const u16 q_atca_021[220] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x6801, 0, 2, 0, 0, 0, 0, 0, 0, 0, 46, 0, 0),
    L6(4, 0, 774, 0, 0, 0, 0, 0x6802, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0x6803, 0, 64, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6804, -20, 65, 0, 128, 0, 0, 0, 0, 0, 50, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6805, 0, 66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6806, 0, 67, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6807, 0, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6808, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6809, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x680A, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x680B, 0, 63, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x680C, 0, 2, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x680D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 q_atca_024_head[4] = { HEAD(4, 32, 4, 15, 0, 1, 0) };
const u16 q_atca_024[172] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x680E, 0, 69, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x680F, 0, 70, 0, 0, 0, 0, 0),
    L4(2, 0, 778, 0, 0, 0, 0, 0x6810, 0, 71, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x6811, 0, 72, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6812, -21, 73, 0, 128, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 140, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 141, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 142, 0), 0, 0, 0, 0,
    L4(3, 0, 286, 0, 0, 0, 0, 0x6813, 0, 74, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6814, 0, 74, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6815, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6816, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6817, 0, 75, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6818, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6819, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x681A, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x681B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665E, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 q_atca_027_head[4] = { HEAD(4, 32, 1, 14, 0, 1, 0) };
const u16 q_atca_027[100] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x681C, 0, 76, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 0, 0x681D, 0, 77, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x681E, -23, 78, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x681F, 0, 79, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6820, 0, 77, 0, 0, 16, 21, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6821, 0, 76, 0, 0, 16, 0, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6822, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6823, 0, 2, 0, 0, 16, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 q_atca_030_head[4] = { HEAD(6, 32, 3, 15, 0, 1, 0) };
const u16 q_atca_030[172] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0x6824, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 776, 0, 0, 0, 0, 0x6825, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 269, 0, 0, 0, 0, 0x6826, 0, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6827, -24, 82, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6828, 0, 83, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6829, 0, 84, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x682A, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x682B, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x682C, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x682D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 q_atca_033_head[4] = { HEAD(4, 32, 5, 14, 0, 1, 0) };
const u16 q_atca_033[244] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x682E, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x682F, 0, 88, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6830, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 775, 0, 0, 0, 0, 0x6831, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6832, 0, 91, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6833, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6834, -25, 93, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6835, 0, 94, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6836, 0, 94, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6837, 0, 95, 0, 0, 0, 21, 0),
    CMD(CM_EXEC, 1, 74, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 75, 0), 0, 0, 0, 0,
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x6838, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6839, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x683A, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x683B, 0, 97, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x683C, 0, 98, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x683D, 0, 99, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x683E, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x683F, 0, 101, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6840, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6841, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6842, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6843, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 q_atca_036_head[4] = { HEAD(4, 22, 0, 13, 0, 1, 0) };
const u16 q_atca_036[76] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 5, 0x68C0, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x68C6, -26, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C7, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C8, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C9, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68CA, 0, 104, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 q_atca_038_head[4] = { HEAD(4, 22, 2, 13, 0, 1, 0) };
const u16 q_atca_038[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CB, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 772, 0, 0, 0, 6, 0x68CC, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 6, 0x68CD, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CE, -27, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CF, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68D0, 0, 109, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D1, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D2, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D3, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662A, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662B, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 q_atca_040_head[4] = { HEAD(4, 22, 4, 14, 0, 1, 0) };
const u16 q_atca_040[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D4, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x68D5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 778, 0, 0, 0, 5, 0x68D6, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 5, 0x68D7, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x68D8, -28, 117, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D9, 0, 118, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68DA, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68DB, 0, 120, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68DC, 0, 121, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662A, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x662B, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 q_atca_042_head[4] = { HEAD(4, 22, 1, 10, 0, 1, 0) };
const u16 q_atca_042[116] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x68A0, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x68A1, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x68A2, -29, 124, 0, 137, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68A3, 0, 125, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68A4, 0, 125, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68A5, 0, 125, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x68A3, 0, 125, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68A4, 0, 125, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68A5, 0, 125, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68A6, 0, 126, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68A7, 0, 127, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 15, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 q_atca_044_head[4] = { HEAD(4, 22, 3, 17, 0, 1, 0) };
const u16 q_atca_044[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x68A8, 0, 129, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68A9, 0, 130, 0, 0, 0, 0, 0),
    L4(2, 0, 774, 0, 0, 0, 6, 0x68AA, 0, 131, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 6, 0x68AB, 0, 131, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68AC, -30, 132, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68AD, 0, 133, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68AE, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 6, 0x68AF, 0, 135, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 6, 0x68B0, 0, 136, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6627, 0, 128, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 6, 0x6627, 0, 128, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 q_atca_046_head[4] = { HEAD(4, 22, 5, 15, 0, 1, 0) };
const u16 q_atca_046[140] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B1, 0, 137, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x68B2, 0, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B3, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B4, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68B5, 0, 141, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68B6, 0, 142, 0, 0, 0, 0, 0),
    L4(3, 0, 775, 0, 0, 0, 6, 0x68B7, 0, 143, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 6, 0x68B8, -31, 144, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B9, 32, 145, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68BA, 0, 146, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68BB, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68BC, 0, 148, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68BD, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68BE, 0, 150, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x68BE, 0, 150, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B, 151 TUKAMI AIR B, 152 TUKAMI AIR C ... */
const u16 q_atca_048_head[4] = { HEAD(4, 20, 0, 13, 0, 1, 0) };
const u16 q_atca_048[76] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 268, 0, 0, 0, 5, 0x68C0, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x68C1, -26, 151, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C2, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C3, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C4, 0, 152, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68C5, 0, 152, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 q_atca_050_head[4] = { HEAD(4, 20, 2, 13, 0, 2, 0) };
const u16 q_atca_050[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CB, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 772, 0, 0, 0, 6, 0x68CC, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 6, 0x68CD, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CE, -27, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CF, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68D0, 0, 109, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D1, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D2, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D3, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663C, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663D, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 q_atca_052_head[4] = { HEAD(4, 20, 4, 14, 0, 1, 0) };
const u16 q_atca_052[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D4, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x68D5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 778, 0, 0, 0, 5, 0x68D6, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 5, 0x68D7, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x68D8, -28, 117, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D9, 0, 118, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68DA, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68DB, 0, 120, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68DC, 0, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x663C, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x663D, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 q_atca_054_head[4] = { HEAD(2, 24, 1, 11, 0, 1, 0) };
const u16 q_atca_054[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 q_atca_056_head[4] = { HEAD(2, 24, 3, 17, 0, 1, 0) };
const u16 q_atca_056[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 q_atca_058_head[4] = { HEAD(2, 24, 5, 16, 0, 1, 0) };
const u16 q_atca_058[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 q_atca_060_head[4] = { HEAD(2, 24, 0, 13, 0, 1, 0) };
const u16 q_atca_060[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 q_atca_062_head[4] = { HEAD(4, 24, 2, 13, 0, 2, 0) };
const u16 q_atca_062[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CB, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 772, 0, 0, 0, 6, 0x68CC, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 6, 0x68CD, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CE, -27, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68CF, 0, 108, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68D0, 0, 109, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D1, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D2, 0, 110, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68D3, 0, 111, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6648, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6649, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 q_atca_064_head[4] = { HEAD(4, 24, 4, 14, 0, 1, 0) };
const u16 q_atca_064[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D4, 0, 113, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x68D5, 0, 114, 0, 0, 0, 0, 0),
    L4(2, 0, 778, 0, 0, 0, 5, 0x68D6, 0, 115, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 5, 0x68D7, 0, 116, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x68D8, -28, 117, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68D9, 0, 118, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x68DA, 0, 119, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68DB, 0, 120, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68DC, 0, 121, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6648, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6649, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x664A, 0, 112, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 q_atca_066_head[4] = { HEAD(2, 24, 1, 11, 0, 1, 0) };
const u16 q_atca_066[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 q_atca_068_head[4] = { HEAD(2, 24, 3, 17, 0, 1, 0) };
const u16 q_atca_068[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 q_atca_070_head[4] = { HEAD(2, 24, 5, 16, 0, 1, 0) };
const u16 q_atca_070[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 q_atca_072_head[4] = { HEAD(2, 28, 0, 14, 0, 1, 0) };
const u16 q_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 q_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 q_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 q_atca_076_head[4] = { HEAD(2, 28, 4, 13, 0, 1, 0) };
const u16 q_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 q_atca_078_head[4] = { HEAD(2, 28, 1, 11, 0, 1, 0) };
const u16 q_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 q_atca_080_head[4] = { HEAD(2, 28, 3, 17, 0, 1, 0) };
const u16 q_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 q_atca_082_head[4] = { HEAD(2, 28, 5, 16, 0, 1, 0) };
const u16 q_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 q_atca_084_head[4] = { HEAD(2, 26, 0, 13, 0, 1, 0) };
const u16 q_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 q_atca_086_head[4] = { HEAD(2, 26, 2, 13, 0, 2, 0) };
const u16 q_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 q_atca_088_head[4] = { HEAD(2, 26, 4, 13, 0, 1, 0) };
const u16 q_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 q_atca_090_head[4] = { HEAD(2, 26, 1, 11, 0, 1, 0) };
const u16 q_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 q_atca_092_head[4] = { HEAD(2, 26, 3, 17, 0, 1, 0) };
const u16 q_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 q_atca_094_head[4] = { HEAD(2, 26, 5, 16, 0, 1, 0) };
const u16 q_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 q_atca_096_head[4] = { HEAD(2, 30, 0, 13, 0, 1, 0) };
const u16 q_atca_096[8] = {
    CMD(CM_JPSS, 4, 84, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 q_atca_098_head[4] = { HEAD(2, 30, 2, 13, 0, 2, 0) };
const u16 q_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 q_atca_100_head[4] = { HEAD(2, 30, 4, 13, 0, 1, 0) };
const u16 q_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 q_atca_102_head[4] = { HEAD(2, 30, 1, 11, 0, 1, 0) };
const u16 q_atca_102[8] = {
    CMD(CM_JPSS, 4, 90, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 q_atca_104_head[4] = { HEAD(2, 30, 3, 17, 0, 1, 0) };
const u16 q_atca_104[8] = {
    CMD(CM_JPSS, 4, 92, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 q_atca_106_head[4] = { HEAD(2, 30, 5, 16, 0, 1, 0) };
const u16 q_atca_106[8] = {
    CMD(CM_JPSS, 4, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 110 S V JP M P A, 111 S V JP M P B ... */
const u16 q_atca_108_head[4] = { HEAD(4, 16, 0, 0, 0, 0, 0) };
const u16 q_atca_108[140] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 6, 0x68B1, 0, 137, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 6, 0x68B2, 0, 138, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B3, 0, 139, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B4, 0, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B5, 0, 141, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B6, 0, 142, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B7, 0, 143, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x68B8, -31, 144, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68B9, 32, 145, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x68BA, 0, 146, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 5, 0x68BB, 0, 147, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68BC, 0, 148, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x68BD, 0, 149, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68BE, 0, 150, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x68BE, 0, 150, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D, 150 TUKAMI AIR A, 153 TUKAMI AIR D */
const u16 q_atca_144_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_atca_144[160] = {
    CMD(CM_CAFR, 2, 2, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x68DD, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x68DD, -43, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x68DE, 0, 351, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68DF, 0, 352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F1, 0, 353, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x68F2, 0, 354, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68F3, 0, 355, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F4, 0, 356, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x68F5, 0, 351, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B, 148 TUKAMIKAKARI E */
const u16 q_atca_145_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_atca_145[160] = {
    CMD(CM_CAFR, 2, 2, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x68DD, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x68DD, -43, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x68DE, 0, 351, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68DF, 0, 352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F1, 0, 353, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x68F2, 0, 354, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68F3, 0, 355, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F4, 0, 356, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x68F5, 0, 351, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C, 149 TUKAMIKAKARI F */
const u16 q_atca_146_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_atca_146[160] = {
    CMD(CM_CAFR, 2, 2, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 2, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x68DD, 0, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x68DD, -43, 171, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x68DE, 0, 351, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68DF, 0, 352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F1, 0, 353, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x68F2, 0, 354, 0, 0, 0, 0, 0, 0, 0, 146, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x68F3, 0, 355, 0, 0, 0, 0, 0, 0, 0, 148, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68F4, 0, 356, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x68F5, 0, 351, 0, 0, 0, 0, 0, 0, 0, 152, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 154, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX q_olc_ix_table[18] = {
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
};

const OVERLAP_PARTS q_overlap_char_tbl[18] = {
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 26891 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 26892 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 26893 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 26894 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 27371 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 6, 27372 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 7, 27373 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 8, 27374 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 9, 27375 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 10, 27376 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 11, 27377 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 12, 27378 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 13, 27379 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 14, 27380 },
    { -23, 68, 0, 0, 1, 0, 255, 0, 0, 15, 27227 },
    { -27, 58, 0, 0, 1, 0, 255, 0, 0, 16, 27227 },
    { -26, 61, 0, 0, 1, 0, 255, 0, 0, 17, 27227 },
};

const CatchTable q_rival_catch_tbl[1248] = {
    { -69, -1, 1, 1, 1 },
    { -93, 1, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -75, 18, 1, 1, 1 },
    { -90, -1, 1, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -82, 0, 1, 1, 1 },
    { -64, 3, 1, 1, 1 },
    { -39, 2, 2, 1, 1 },
    { -77, -1, 1, 1, 1 },
    { -75, 18, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -69, -1, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -91, 0, 1, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -39, -2, 1, 1, 2 },
    { -93, 3, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -66, 11, 1, 1, 2 },
    { -56, -2, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -71, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -51, 0, 1, 1, 2 },
    { -63, 13, 1, 1, 2 },
    { -66, 11, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -39, -2, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -45, 0, 1, 1, 2 },
    { -73, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -44, 0, 1, 1, 2 },
    { -26, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 32, 0, 1, 1, 3 },
    { -29, 0, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { -29, 25, 1, 1, 3 },
    { 6, 0, 1, 1, 3 },
    { -10, 0, 1, 1, 3 },
    { -20, 0, 1, 1, 3 },
    { -23, 17, 1, 1, 3 },
    { -18, 6, 1, 1, 3 },
    { -33, 9, 1, 1, 3 },
    { -29, 25, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { 32, 0, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { -41, 0, 1, 1, 3 },
    { -22, 3, 1, 1, 3 },
    { -43, 0, 1, 1, 3 },
    { -18, 0, 1, 1, 3 },
    { -4, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 13, -9, 1, 1, 4 },
    { 14, 0, 1, 1, 4 },
    { -7, 2, 1, 1, 4 },
    { 3, 12, 1, 1, 4 },
    { 31, 0, 1, 1, 4 },
    { 36, 1, 1, 1, 4 },
    { 9, 0, 1, 1, 4 },
    { 20, 4, 1, 1, 4 },
    { 20, 0, 1, 1, 4 },
    { -14, 127, 1, 1, 4 },
    { 3, 12, 1, 1, 4 },
    { -7, 2, 1, 1, 4 },
    { -7, 2, 1, 1, 4 },
    { 13, -9, 1, 1, 4 },
    { -7, 2, 1, 1, 4 },
    { -7, 2, 1, 1, 4 },
    { -34, 0, 1, 1, 4 },
    { 8, 3, 1, 1, 4 },
    { 60, 0, 1, 1, 4 },
    { 31, 0, 1, 1, 4 },
    { 6, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 58, -4, 1, 1, 5 },
    { 54, -14, 1, 1, 5 },
    { 37, -3, 1, 1, 5 },
    { 123, 91, 1, 1, 5 },
    { 59, -4, 1, 1, 5 },
    { 79, -3, 1, 1, 5 },
    { 87, -4, 1, 1, 5 },
    { 58, -5, 1, 1, 5 },
    { 49, 8, 1, 1, 5 },
    { 68, 159, 1, 1, 5 },
    { 123, 91, 1, 1, 5 },
    { 37, -3, 1, 1, 5 },
    { 37, -3, 1, 1, 5 },
    { 58, -4, 1, 1, 5 },
    { 37, -3, 1, 1, 5 },
    { 37, -3, 1, 1, 5 },
    { 88, 0, 1, 1, 5 },
    { 46, -1, 1, 1, 5 },
    { 91, 0, 1, 1, 5 },
    { 77, 0, 1, 1, 5 },
    { 42, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 104, -23, 1, 1, 6 },
    { 99, -2, 1, 1, 6 },
    { 92, -8, 1, 1, 6 },
    { 129, 116, 1, 1, 6 },
    { 39, -2, 1, 1, 6 },
    { 99, -5, 1, 1, 6 },
    { 83, -7, 1, 1, 6 },
    { 106, -4, 1, 1, 6 },
    { 86, -4, 1, 1, 6 },
    { 108, 63, 1, 1, 6 },
    { 129, 116, 1, 1, 6 },
    { 92, -8, 1, 1, 6 },
    { 92, -8, 1, 1, 6 },
    { 104, -23, 1, 1, 6 },
    { 92, -8, 1, 1, 6 },
    { 92, -8, 1, 1, 6 },
    { 80, -1, 1, 1, 6 },
    { 88, -5, 1, 1, 6 },
    { 84, 0, 1, 1, 6 },
    { 79, 0, 1, 1, 6 },
    { 86, 2, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 104, -23, 1, 1, 7 },
    { 89, -7, 1, 1, 7 },
    { 97, -7, 1, 1, 7 },
    { 126, 126, 1, 1, 7 },
    { 103, -1, 1, 1, 7 },
    { 102, -5, 1, 1, 7 },
    { 86, -7, 1, 1, 7 },
    { 87, -1, 1, 1, 7 },
    { 88, 5, 1, 1, 7 },
    { 127, 13, 1, 1, 7 },
    { 126, 126, 1, 1, 7 },
    { 97, -7, 1, 1, 7 },
    { 97, -7, 1, 1, 7 },
    { 104, -23, 1, 1, 7 },
    { 97, -7, 1, 1, 7 },
    { 97, -7, 1, 1, 7 },
    { 84, -4, 1, 1, 7 },
    { 112, -1, 1, 1, 7 },
    { 84, 0, 1, 1, 7 },
    { 79, -1, 1, 1, 7 },
    { 82, -4, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 43, -5, 1, 1, 8 },
    { 58, -1, 1, 1, 8 },
    { 91, 132, 1, 1, 8 },
    { 114, 143, 1, 1, 8 },
    { 102, 132, 2, 1, 8 },
    { 73, 12, 1, 1, 8 },
    { 76, 12, 1, 1, 8 },
    { 79, 39, 1, 1, 8 },
    { 65, 33, 1, 1, 8 },
    { 74, 13, 1, 1, 8 },
    { 114, 143, 1, 1, 8 },
    { 91, 132, 1, 1, 8 },
    { 91, 132, 1, 1, 8 },
    { 43, -5, 1, 1, 8 },
    { 91, 132, 1, 1, 8 },
    { 91, 132, 1, 1, 8 },
    { 68, 12, 1, 1, 8 },
    { 90, 46, 1, 1, 8 },
    { 82, 3, 1, 1, 8 },
    { 71, 11, 1, 1, 8 },
    { 84, 44, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -7, 145, 1, 1, 9 },
    { -7, 79, 1, 1, 9 },
    { -34, 211, 1, 1, 9 },
    { -18, 205, 1, 1, 9 },
    { -47, 224, 1, 1, 9 },
    { -2, 151, 1, 1, 9 },
    { -9, 39, 1, 1, 9 },
    { -30, 206, 1, 1, 9 },
    { -20, 180, 1, 1, 9 },
    { -49, 214, 1, 1, 9 },
    { -18, 205, 1, 1, 9 },
    { -34, 211, 1, 1, 9 },
    { -34, 211, 1, 1, 9 },
    { -7, 145, 1, 1, 9 },
    { -34, 211, 1, 1, 9 },
    { -34, 211, 1, 1, 9 },
    { -2, 71, 1, 1, 9 },
    { -27, 70, 1, 1, 9 },
    { -14, 104, 1, 1, 9 },
    { 1, 142, 1, 1, 9 },
    { -48, 156, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -88, -12, 2, 1, 10 },
    { -103, -10, 2, 1, 10 },
    { -63, 80, 1, 1, 10 },
    { -83, 56, 1, 1, 10 },
    { -84, -10, 2, 1, 10 },
    { -86, -5, 2, 1, 10 },
    { -17, -2, 1, 1, 10 },
    { -81, -4, 2, 1, 10 },
    { -88, -11, 1, 1, 10 },
    { -76, -5, 2, 1, 10 },
    { -83, 56, 1, 1, 10 },
    { -63, 80, 1, 1, 10 },
    { -63, 80, 1, 1, 10 },
    { -88, -12, 2, 1, 10 },
    { -63, 80, 1, 1, 10 },
    { -63, 80, 1, 1, 10 },
    { -76, -7, 2, 1, 10 },
    { -33, -1, 2, 1, 10 },
    { -53, -7, 2, 1, 10 },
    { -99, -3, 2, 1, 10 },
    { -76, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -84, -11, 2, 0, 11 },
    { -101, -8, 1, 0, 11 },
    { -64, 62, 1, 0, 11 },
    { -104, -13, 1, 0, 11 },
    { -97, -10, 2, 0, 11 },
    { -77, -5, 2, 0, 11 },
    { -17, -2, 1, 0, 11 },
    { -84, -4, 2, 0, 11 },
    { -87, -11, 1, 0, 11 },
    { -76, -5, 2, 0, 11 },
    { -104, -13, 1, 0, 11 },
    { -64, 62, 1, 0, 11 },
    { -64, 62, 1, 0, 11 },
    { -84, -11, 2, 0, 11 },
    { -64, 62, 1, 0, 11 },
    { -64, 62, 1, 0, 11 },
    { -71, -9, 2, 0, 11 },
    { -33, -1, 2, 0, 11 },
    { -49, -10, 2, 0, 11 },
    { -99, -3, 2, 0, 11 },
    { -76, 0, 2, 0, 11 },
    { 0, 0, 2, 0, 11 },
    { 0, 0, 2, 0, 11 },
    { 0, 0, 2, 0, 11 },
    { -84, -11, 2, 0, 12 },
    { -101, -8, 1, 0, 12 },
    { -35, 32, 2, 0, 12 },
    { -90, -8, 1, 0, 12 },
    { -94, -12, 1, 0, 12 },
    { -77, -5, 2, 0, 12 },
    { -17, -2, 1, 0, 12 },
    { -84, -4, 2, 0, 12 },
    { -88, -11, 1, 0, 12 },
    { -76, -5, 2, 0, 12 },
    { -90, -8, 1, 0, 12 },
    { -35, 32, 2, 0, 12 },
    { -35, 32, 2, 0, 12 },
    { -84, -11, 2, 0, 12 },
    { -35, 32, 2, 0, 12 },
    { -35, 32, 2, 0, 12 },
    { -68, -9, 2, 0, 12 },
    { -33, -1, 2, 0, 12 },
    { -45, -10, 2, 0, 12 },
    { -99, -3, 2, 0, 12 },
    { -72, 0, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { 0, 0, 2, 0, 12 },
    { -102, 6, 2, 0, 13 },
    { -116, -2, 1, 0, 13 },
    { -56, 44, 2, 0, 13 },
    { -122, 4, 1, 0, 13 },
    { -114, 1, 1, 0, 13 },
    { -94, 4, 2, 0, 13 },
    { -28, 4, 1, 0, 13 },
    { -94, 3, 2, 0, 13 },
    { -112, 2, 1, 0, 13 },
    { -90, 4, 2, 0, 13 },
    { -122, 4, 1, 0, 13 },
    { -56, 44, 2, 0, 13 },
    { -56, 44, 2, 0, 13 },
    { -102, 6, 2, 0, 13 },
    { -56, 44, 2, 0, 13 },
    { -56, 44, 2, 0, 13 },
    { -68, 1, 2, 0, 13 },
    { -50, 5, 2, 0, 13 },
    { -50, 2, 2, 0, 13 },
    { -102, 2, 2, 0, 13 },
    { -72, 0, 2, 0, 13 },
    { 0, 0, 2, 0, 13 },
    { 0, 0, 2, 0, 13 },
    { 0, 0, 2, 0, 13 },
    { -69, -1, 1, 1, 1 },
    { -95, 1, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -69, -5, 1, 1, 1 },
    { -82, 0, 1, 1, 1 },
    { -91, 0, 1, 1, 1 },
    { -125, -16, 1, 1, 1 },
    { -77, 3, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -88, 6, 1, 1, 1 },
    { -69, 5, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -74, 0, 1, 1, 1 },
    { -73, -1, 1, 1, 1 },
    { -76, 0, 1, 1, 1 },
    { -76, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -87, 2, 1, 1, 1 },
    { -110, -1, 1, 1, 1 },
    { -71, 0, 1, 1, 1 },
    { -64, -2, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -83, 0, 1, 1, 2 },
    { -74, 8, 1, 1, 2 },
    { -67, -1, 1, 1, 2 },
    { -74, 10, 1, 1, 2 },
    { -83, 0, 1, 1, 2 },
    { -69, 4, 1, 1, 2 },
    { -106, -3, 1, 1, 2 },
    { -76, 14, 1, 1, 2 },
    { -94, 10, 1, 1, 2 },
    { -75, 20, 1, 1, 2 },
    { -74, 10, 1, 1, 2 },
    { -67, -1, 1, 1, 2 },
    { -67, -1, 1, 1, 2 },
    { -82, 0, 1, 1, 2 },
    { -69, -2, 1, 1, 2 },
    { -69, -2, 1, 1, 2 },
    { -88, 6, 1, 1, 2 },
    { -93, 12, 1, 1, 2 },
    { -78, -1, 1, 1, 2 },
    { -70, 4, 1, 1, 2 },
    { -54, 4, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -57, 5, 1, 1, 3 },
    { -119, 26, 1, 1, 3 },
    { -59, 14, 1, 1, 3 },
    { -62, 24, 1, 1, 3 },
    { -59, 15, 1, 1, 3 },
    { -79, -3, 1, 1, 3 },
    { -115, -2, 1, 1, 3 },
    { -71, 28, 1, 1, 3 },
    { -96, 29, 1, 1, 3 },
    { -92, 50, 1, 1, 3 },
    { -62, 24, 1, 1, 3 },
    { -55, 7, 1, 1, 3 },
    { -55, 6, 1, 1, 3 },
    { -57, 5, 1, 1, 3 },
    { -59, 13, 1, 1, 3 },
    { -59, 13, 1, 1, 3 },
    { -87, 27, 1, 1, 3 },
    { -74, 144, 1, 1, 3 },
    { -62, 12, 1, 1, 3 },
    { -85, 20, 1, 1, 3 },
    { -85, 17, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -52, 20, 2, 1, 4 },
    { -66, 28, 2, 1, 4 },
    { -54, 29, 2, 1, 4 },
    { -70, 139, 2, 1, 4 },
    { -47, 30, 2, 1, 4 },
    { -68, 11, 2, 1, 4 },
    { -93, 11, 2, 1, 4 },
    { -58, 44, 2, 1, 4 },
    { -35, 43, 2, 1, 4 },
    { -84, 67, 2, 1, 4 },
    { -70, 139, 2, 1, 4 },
    { -45, 24, 2, 1, 4 },
    { -47, 23, 2, 1, 4 },
    { -46, 21, 2, 1, 4 },
    { -50, 29, 2, 1, 4 },
    { -50, 29, 2, 1, 4 },
    { -81, 47, 2, 1, 4 },
    { -57, 157, 2, 1, 4 },
    { -75, 19, 2, 1, 4 },
    { -91, 172, 2, 1, 4 },
    { -77, 36, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -36, 25, 2, 1, 5 },
    { -30, 16, 2, 1, 5 },
    { -87, 153, 2, 1, 5 },
    { -102, 158, 2, 1, 5 },
    { -39, 30, 2, 1, 5 },
    { -90, 141, 2, 1, 5 },
    { -79, 24, 2, 1, 5 },
    { -82, 73, 2, 1, 5 },
    { -48, 78, 2, 1, 5 },
    { -67, 68, 2, 1, 5 },
    { -102, 158, 2, 1, 5 },
    { -87, 153, 2, 1, 5 },
    { -85, 148, 2, 1, 5 },
    { -32, 28, 2, 1, 5 },
    { -90, 155, 2, 1, 5 },
    { -90, 155, 2, 1, 5 },
    { -56, 73, 2, 1, 5 },
    { -46, 160, 2, 1, 5 },
    { -70, 30, 2, 1, 5 },
    { -63, 47, 2, 1, 5 },
    { -68, 150, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -51, 23, 2, 1, 6 },
    { -6, 40, 2, 1, 6 },
    { -48, 47, 2, 1, 6 },
    { -90, 178, 2, 1, 6 },
    { -25, 38, 2, 1, 6 },
    { -83, 159, 2, 1, 6 },
    { -75, 32, 2, 1, 6 },
    { -50, 91, 2, 1, 6 },
    { -70, 93, 2, 1, 6 },
    { -57, 71, 2, 1, 6 },
    { -90, 178, 2, 1, 6 },
    { -48, 48, 2, 1, 6 },
    { -48, 48, 2, 1, 6 },
    { -46, 27, 2, 1, 6 },
    { -47, 47, 2, 1, 6 },
    { -47, 47, 2, 1, 6 },
    { -49, 86, 2, 1, 6 },
    { -31, 164, 2, 1, 6 },
    { -64, 44, 2, 1, 6 },
    { -88, 146, 2, 1, 6 },
    { -68, 153, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -45, 32, 2, 1, 7 },
    { -11, 50, 2, 1, 7 },
    { -30, 50, 2, 1, 7 },
    { -55, 84, 2, 1, 7 },
    { -30, 58, 2, 1, 7 },
    { -50, 181, 2, 1, 7 },
    { -45, 37, 2, 1, 7 },
    { -39, 87, 2, 1, 7 },
    { -63, 210, 2, 1, 7 },
    { -47, 161, 2, 1, 7 },
    { -55, 84, 2, 1, 7 },
    { -29, 51, 2, 1, 7 },
    { -29, 51, 2, 1, 7 },
    { -42, 31, 2, 1, 7 },
    { -29, 50, 2, 1, 7 },
    { -29, 50, 2, 1, 7 },
    { -21, 75, 2, 1, 7 },
    { -13, 164, 2, 1, 7 },
    { -47, 46, 2, 1, 7 },
    { -73, 155, 2, 1, 7 },
    { -51, 155, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { 0, 0, 2, 1, 7 },
    { -55, 195, 2, 1, 8 },
    { -64, 159, 2, 1, 8 },
    { -38, 65, 2, 1, 8 },
    { -54, 94, 2, 1, 8 },
    { -49, 159, 2, 1, 8 },
    { -32, 65, 2, 1, 8 },
    { -26, 22, 2, 1, 8 },
    { -24, 69, 2, 1, 8 },
    { -65, 199, 2, 1, 8 },
    { -61, 191, 2, 1, 8 },
    { -54, 94, 2, 1, 8 },
    { -30, 63, 2, 1, 8 },
    { -29, 62, 2, 1, 8 },
    { -53, 51, 2, 1, 8 },
    { -38, 63, 2, 1, 8 },
    { -38, 63, 2, 1, 8 },
    { -25, 60, 2, 1, 8 },
    { -13, 166, 2, 1, 8 },
    { -28, 40, 2, 1, 8 },
    { -74, 156, 2, 1, 8 },
    { -49, 154, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -66, 151, 2, 1, 9 },
    { -81, 154, 2, 1, 9 },
    { -53, 166, 2, 1, 9 },
    { -69, 215, 2, 1, 9 },
    { -46, 161, 2, 1, 9 },
    { -11, 78, 2, 1, 9 },
    { -25, 24, 2, 1, 9 },
    { -46, 84, 2, 1, 9 },
    { -55, 187, 2, 1, 9 },
    { -58, 212, 2, 1, 9 },
    { -69, 215, 2, 1, 9 },
    { -50, 159, 2, 1, 9 },
    { -52, 159, 2, 1, 9 },
    { -65, 159, 2, 1, 9 },
    { -60, 166, 2, 1, 9 },
    { -60, 166, 2, 1, 9 },
    { -17, 64, 2, 1, 9 },
    { -8, 169, 2, 1, 9 },
    { -36, 39, 2, 1, 9 },
    { -74, 153, 2, 1, 9 },
    { -48, 157, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -68, 151, 2, 1, 10 },
    { -64, 148, 2, 1, 10 },
    { -52, 163, 2, 1, 10 },
    { -66, 221, 2, 1, 10 },
    { -55, 158, 2, 1, 10 },
    { -54, 149, 2, 1, 10 },
    { -15, 18, 2, 1, 10 },
    { -12, 63, 2, 1, 10 },
    { -55, 175, 2, 1, 10 },
    { -50, 235, 2, 1, 10 },
    { -66, 221, 2, 1, 10 },
    { -49, 156, 2, 1, 10 },
    { -53, 157, 2, 1, 10 },
    { -68, 155, 2, 1, 10 },
    { -59, 163, 2, 1, 10 },
    { -59, 163, 2, 1, 10 },
    { -14, 152, 2, 1, 10 },
    { -7, 176, 2, 1, 10 },
    { -33, 37, 2, 1, 10 },
    { -51, 199, 2, 1, 10 },
    { -24, 163, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -68, 151, 2, 1, 11 },
    { -78, 147, 2, 1, 11 },
    { -36, 60, 2, 1, 11 },
    { -62, 227, 2, 1, 11 },
    { -53, 156, 2, 1, 11 },
    { -61, 157, 2, 1, 11 },
    { -42, 28, 2, 1, 11 },
    { -43, 91, 2, 1, 11 },
    { -59, 166, 2, 1, 11 },
    { -54, 220, 2, 1, 11 },
    { -62, 227, 2, 1, 11 },
    { -28, 60, 2, 1, 11 },
    { -29, 61, 2, 1, 11 },
    { -66, 150, 2, 1, 11 },
    { -36, 61, 2, 1, 11 },
    { -36, 61, 2, 1, 11 },
    { -25, 154, 2, 1, 11 },
    { -20, 176, 2, 1, 11 },
    { -45, 43, 2, 1, 11 },
    { -66, 211, 2, 1, 11 },
    { -48, 193, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { -66, 151, 2, 1, 12 },
    { -72, 140, 2, 1, 12 },
    { -46, 177, 2, 1, 12 },
    { -31, 194, 2, 1, 12 },
    { -43, 171, 2, 1, 12 },
    { -64, 150, 2, 1, 12 },
    { -54, 39, 2, 1, 12 },
    { -23, 123, 2, 1, 12 },
    { -54, 160, 2, 1, 12 },
    { -45, 226, 2, 1, 12 },
    { -31, 194, 2, 1, 12 },
    { -52, 191, 2, 1, 12 },
    { -53, 191, 2, 1, 12 },
    { -61, 150, 2, 1, 12 },
    { -47, 177, 2, 1, 12 },
    { -47, 177, 2, 1, 12 },
    { -30, 172, 2, 1, 12 },
    { -35, 80, 2, 1, 12 },
    { -37, 38, 2, 1, 12 },
    { -66, 221, 2, 1, 12 },
    { -52, 200, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { -53, 135, 2, 1, 13 },
    { -68, 138, 2, 1, 13 },
    { -47, 184, 2, 1, 13 },
    { -35, 217, 2, 1, 13 },
    { -52, 208, 2, 1, 13 },
    { -58, 209, 2, 1, 13 },
    { -51, 9, 2, 1, 13 },
    { -6, 108, 2, 1, 13 },
    { -44, 65, 2, 1, 13 },
    { -18, 115, 2, 1, 13 },
    { -35, 217, 2, 1, 13 },
    { -56, 190, 2, 1, 13 },
    { -55, 192, 2, 1, 13 },
    { -53, 135, 2, 1, 13 },
    { -49, 185, 2, 1, 13 },
    { -49, 185, 2, 1, 13 },
    { -33, 187, 2, 1, 13 },
    { -33, 112, 2, 1, 13 },
    { -43, 37, 2, 1, 13 },
    { -61, 198, 2, 1, 13 },
    { -54, 195, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { -19, 153, 2, 1, 14 },
    { -34, 129, 2, 1, 14 },
    { -35, 123, 2, 1, 14 },
    { 24, 116, 2, 1, 14 },
    { -34, 142, 2, 1, 14 },
    { -53, 100, 2, 1, 14 },
    { -69, 38, 2, 1, 14 },
    { -14, 32, 2, 1, 14 },
    { -37, 111, 2, 1, 14 },
    { -23, 114, 2, 1, 14 },
    { -24, 116, 2, 1, 14 },
    { -35, 123, 2, 1, 14 },
    { -35, 123, 2, 1, 14 },
    { -19, 153, 2, 1, 14 },
    { -35, 123, 2, 1, 14 },
    { -35, 123, 2, 1, 14 },
    { -11, 125, 2, 1, 14 },
    { -27, 30, 2, 1, 14 },
    { -59, 35, 2, 1, 14 },
    { -41, 143, 2, 1, 14 },
    { -41, 143, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 10, 138, 2, 1, 15 },
    { -58, 123, 2, 1, 15 },
    { -36, 71, 2, 1, 15 },
    { -18, 131, 2, 1, 15 },
    { -50, 132, 2, 1, 15 },
    { -19, 96, 2, 1, 15 },
    { -73, 43, 2, 1, 15 },
    { -9, 10, 2, 1, 15 },
    { -50, 98, 2, 1, 15 },
    { -40, 98, 2, 1, 15 },
    { -18, 131, 2, 1, 15 },
    { -36, 71, 2, 1, 15 },
    { -36, 71, 2, 1, 15 },
    { 10, 138, 2, 1, 15 },
    { -36, 71, 2, 1, 15 },
    { -36, 71, 2, 1, 15 },
    { -24, 125, 2, 1, 15 },
    { -26, 42, 2, 1, 15 },
    { -46, 33, 2, 1, 15 },
    { -20, 107, 2, 1, 15 },
    { -3, 82, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { -39, 151, 2, 1, 16 },
    { -19, 75, 2, 1, 16 },
    { -47, 110, 2, 1, 16 },
    { -30, 130, 2, 1, 16 },
    { -52, 119, 2, 1, 16 },
    { -39, 118, 2, 1, 16 },
    { -74, 34, 2, 1, 16 },
    { 0, 23, 2, 1, 16 },
    { -34, 85, 2, 1, 16 },
    { -37, 88, 2, 1, 16 },
    { -30, 130, 2, 1, 16 },
    { -47, 110, 2, 1, 16 },
    { -47, 110, 2, 1, 16 },
    { -39, 151, 2, 1, 16 },
    { -47, 110, 2, 1, 16 },
    { -47, 110, 2, 1, 16 },
    { -21, 84, 2, 1, 16 },
    { -36, 29, 2, 1, 16 },
    { -43, 15, 2, 1, 16 },
    { -51, 126, 2, 1, 16 },
    { -14, 120, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { -51, 140, 2, 1, 17 },
    { -47, 69, 2, 1, 17 },
    { -49, 60, 2, 1, 17 },
    { -22, 16, 2, 1, 17 },
    { -50, 113, 2, 1, 17 },
    { -31, 126, 2, 1, 17 },
    { -72, 30, 2, 1, 17 },
    { -26, -14, 2, 1, 17 },
    { -48, 63, 2, 1, 17 },
    { -40, 80, 2, 1, 17 },
    { -22, 16, 2, 1, 17 },
    { -49, 60, 2, 1, 17 },
    { -49, 60, 2, 1, 17 },
    { -51, 140, 2, 1, 17 },
    { -49, 60, 2, 1, 17 },
    { -49, 60, 2, 1, 17 },
    { -21, 68, 2, 1, 17 },
    { -35, 32, 2, 1, 17 },
    { -46, 14, 2, 1, 17 },
    { -57, 61, 2, 1, 17 },
    { -59, 104, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { -72, -1, 2, 1, 18 },
    { -73, -5, 2, 1, 18 },
    { -80, -3, 2, 1, 18 },
    { -79, -10, 2, 1, 18 },
    { -52, -5, 2, 1, 18 },
    { -79, -4, 2, 1, 18 },
    { -89, -1, 2, 1, 18 },
    { -32, -2, 2, 1, 18 },
    { -68, -2, 2, 1, 18 },
    { -79, -18, 2, 1, 18 },
    { -79, -10, 2, 1, 18 },
    { -80, -3, 2, 1, 18 },
    { -80, -3, 2, 1, 18 },
    { -72, -1, 2, 1, 18 },
    { -80, -3, 2, 1, 18 },
    { -80, -3, 2, 1, 18 },
    { -41, 3, 2, 1, 18 },
    { -50, 21, 2, 1, 18 },
    { -69, 17, 2, 1, 18 },
    { -50, 3, 2, 1, 18 },
    { -62, -10, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { -81, 0, 1, 1, 1 },
    { -44, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -66, 0, 1, 1, 1 },
    { -58, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -89, 1, 1, 1, 1 },
    { -40, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -52, 0, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -83, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 2 },
    { -42, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -38, 0, 1, 1, 2 },
    { -49, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -66, 0, 1, 1, 2 },
    { -58, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -89, 5, 1, 1, 2 },
    { -38, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -61, 0, 1, 1, 2 },
    { -73, 0, 1, 1, 2 },
    { -62, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 2 },
    { -54, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -64, 0, 1, 1, 3 },
    { -42, 0, 1, 1, 3 },
    { -51, 0, 1, 1, 3 },
    { -38, 1, 1, 1, 3 },
    { -49, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -53, 0, 1, 1, 3 },
    { -89, 9, 1, 1, 3 },
    { -38, 1, 1, 1, 3 },
    { -51, 0, 1, 1, 3 },
    { -51, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -51, 0, 1, 1, 3 },
    { -51, 0, 1, 1, 3 },
    { -61, 0, 1, 1, 3 },
    { -73, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -55, 0, 1, 1, 3 },
    { -48, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -36, 3, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { -55, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -86, 16, 1, 1, 4 },
    { -36, 3, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -47, 0, 1, 1, 4 },
    { -56, -2, 1, 1, 4 },
    { -62, 0, 1, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -61, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -29, 3, 1, 1, 5 },
    { -43, 0, 1, 1, 5 },
    { -54, 0, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -52, 0, 1, 1, 5 },
    { -39, 0, 1, 1, 5 },
    { -77, 5, 1, 1, 5 },
    { -29, 3, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -61, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -38, 0, 1, 1, 5 },
    { -60, 0, 1, 1, 5 },
    { -46, 0, 1, 1, 5 },
    { -50, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 6 },
    { -40, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -29, 3, 1, 1, 6 },
    { -23, 0, 1, 1, 6 },
    { -48, 0, 1, 1, 6 },
    { -46, 0, 1, 1, 6 },
    { -39, 0, 1, 1, 6 },
    { -17, 0, 1, 1, 6 },
    { -77, 10, 1, 1, 6 },
    { -29, 3, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -40, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -36, -2, 1, 1, 6 },
    { -36, 0, 1, 1, 6 },
    { -45, 0, 1, 1, 6 },
    { -42, 0, 1, 1, 6 },
    { -42, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -40, 0, 1, 1, 7 },
    { -40, 0, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -25, -5, 1, 1, 7 },
    { -17, 0, 1, 1, 7 },
    { -40, 0, 1, 1, 7 },
    { -44, 0, 1, 1, 7 },
    { -35, 0, 1, 1, 7 },
    { -15, 0, 1, 1, 7 },
    { -47, 0, 1, 1, 7 },
    { -25, -5, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -40, 0, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -34, -2, 1, 1, 7 },
    { -28, 0, 1, 1, 7 },
    { -45, 0, 1, 1, 7 },
    { -39, 0, 1, 1, 7 },
    { -44, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -40, 0, 1, 1, 8 },
    { -40, 0, 1, 1, 8 },
    { -25, 0, 1, 1, 8 },
    { -23, -10, 1, 1, 8 },
    { -16, 1, 1, 1, 8 },
    { -30, 0, 1, 1, 8 },
    { -36, 0, 1, 1, 8 },
    { -35, 0, 1, 1, 8 },
    { -11, 0, 1, 1, 8 },
    { -46, -3, 1, 1, 8 },
    { -23, -10, 1, 1, 8 },
    { -25, 0, 1, 1, 8 },
    { -25, 0, 1, 1, 8 },
    { -40, 0, 1, 1, 8 },
    { -25, 0, 1, 1, 8 },
    { -25, 0, 1, 1, 8 },
    { -28, 2, 1, 1, 8 },
    { -20, 0, 1, 1, 8 },
    { -45, 0, 1, 1, 8 },
    { -38, 0, 1, 1, 8 },
    { -34, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -40, 0, 1, 1, 9 },
    { -30, 0, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -23, -10, 1, 1, 9 },
    { -16, 1, 1, 1, 9 },
    { -24, 0, 1, 1, 9 },
    { -32, 0, 1, 1, 9 },
    { -28, 0, 1, 1, 9 },
    { -9, 0, 1, 1, 9 },
    { -41, 0, 1, 1, 9 },
    { -23, -10, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -40, 0, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -31, 0, 1, 1, 9 },
    { -21, 0, 1, 1, 9 },
    { -20, 0, 1, 1, 9 },
    { -22, 0, 1, 1, 9 },
    { -38, 0, 1, 1, 9 },
    { -38, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { -24, 0, 1, 1, 10 },
    { -38, 0, 1, 1, 10 },
    { -13, 16, 1, 1, 10 },
    { -13, 24, 1, 1, 10 },
    { -31, 7, 1, 1, 10 },
    { -14, 10, 1, 1, 10 },
    { -46, 7, 1, 1, 10 },
    { -41, 12, 1, 1, 10 },
    { -26, 19, 1, 1, 10 },
    { -12, 23, 1, 1, 10 },
    { -13, 24, 1, 1, 10 },
    { -13, 16, 1, 1, 10 },
    { -13, 16, 1, 1, 10 },
    { -24, 0, 1, 1, 10 },
    { -13, 16, 1, 1, 10 },
    { -13, 16, 1, 1, 10 },
    { -28, 15, 1, 1, 10 },
    { -55, 27, 1, 1, 10 },
    { -27, 7, 1, 1, 10 },
    { -11, 15, 1, 1, 10 },
    { -44, 4, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { -23, 58, 1, 1, 11 },
    { -74, 66, 1, 1, 11 },
    { -28, 81, 1, 1, 11 },
    { -34, 95, 1, 1, 11 },
    { -36, 73, 1, 1, 11 },
    { -28, 64, 1, 1, 11 },
    { -34, 68, 1, 1, 11 },
    { -41, 76, 1, 1, 11 },
    { -28, 84, 1, 1, 11 },
    { -33, 78, 1, 1, 11 },
    { -34, 95, 1, 1, 11 },
    { -28, 81, 1, 1, 11 },
    { -28, 81, 1, 1, 11 },
    { -23, 58, 1, 1, 11 },
    { -28, 81, 1, 1, 11 },
    { -28, 81, 1, 1, 11 },
    { -36, 77, 1, 1, 11 },
    { -57, 82, 1, 1, 11 },
    { -28, 60, 1, 1, 11 },
    { -12, 70, 1, 1, 11 },
    { -40, 72, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { -42, 70, 1, 1, 12 },
    { -74, 72, 1, 1, 12 },
    { -31, 89, 1, 1, 12 },
    { -36, 72, 1, 1, 12 },
    { -39, 79, 1, 1, 12 },
    { -28, 82, 1, 1, 12 },
    { -37, 74, 1, 1, 12 },
    { -41, 90, 1, 1, 12 },
    { -30, 98, 1, 1, 12 },
    { -37, 88, 1, 1, 12 },
    { -36, 72, 1, 1, 12 },
    { -31, 89, 1, 1, 12 },
    { -31, 89, 1, 1, 12 },
    { -42, 70, 1, 1, 12 },
    { -31, 89, 1, 1, 12 },
    { -31, 89, 1, 1, 12 },
    { -39, 90, 1, 1, 12 },
    { -59, 96, 1, 1, 12 },
    { -50, 74, 1, 1, 12 },
    { -36, 71, 1, 1, 12 },
    { -62, 78, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { -69, -1, 1, 1, 1 },
    { -93, 1, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -75, 18, 1, 1, 1 },
    { -89, -1, 1, 1, 1 },
    { -90, 0, 1, 1, 1 },
    { -82, 0, 1, 1, 1 },
    { -64, 3, 1, 1, 1 },
    { -39, 2, 2, 1, 1 },
    { -73, -1, 1, 1, 1 },
    { -75, 18, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -69, -1, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { -67, 4, 1, 1, 1 },
    { -91, 0, 1, 1, 1 },
    { -70, 0, 1, 1, 1 },
    { -73, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -39, -2, 1, 1, 2 },
    { -93, 3, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -71, 11, 1, 1, 2 },
    { -62, -3, 1, 1, 2 },
    { -46, 0, 1, 1, 2 },
    { -71, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 2 },
    { -56, 0, 1, 1, 2 },
    { -69, 13, 1, 1, 2 },
    { -71, 11, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -39, -2, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -43, 0, 1, 1, 2 },
    { -49, 0, 1, 1, 2 },
    { -80, 5, 1, 1, 2 },
    { -55, 0, 1, 1, 2 },
    { -49, 0, 1, 1, 2 },
    { -47, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -35, 0, 1, 1, 3 },
    { -46, 0, 1, 1, 3 },
    { -42, 4, 1, 1, 3 },
    { -47, 9, 1, 1, 3 },
    { -32, -2, 1, 1, 3 },
    { -34, 4, 1, 1, 3 },
    { -37, 0, 1, 1, 3 },
    { -78, 126, 1, 1, 3 },
    { -52, 2, 1, 1, 3 },
    { -59, 0, 1, 1, 3 },
    { -47, 9, 1, 1, 3 },
    { -42, 4, 1, 1, 3 },
    { -42, 4, 1, 1, 3 },
    { -35, 0, 1, 1, 3 },
    { -42, 4, 1, 1, 3 },
    { -42, 4, 1, 1, 3 },
    { -53, 2, 1, 1, 3 },
    { -52, 12, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -49, 2, 1, 1, 3 },
    { -38, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -37, 0, 1, 1, 4 },
    { -31, 0, 1, 1, 4 },
    { -27, 2, 1, 1, 4 },
    { -51, 9, 1, 1, 4 },
    { -27, 0, 1, 1, 4 },
    { -34, 4, 1, 1, 4 },
    { -41, 0, 1, 1, 4 },
    { -33, 2, 1, 1, 4 },
    { -40, 3, 1, 1, 4 },
    { -43, 20, 1, 1, 4 },
    { -51, 9, 1, 1, 4 },
    { -27, 2, 1, 1, 4 },
    { -27, 2, 1, 1, 4 },
    { -37, 0, 1, 1, 4 },
    { -27, 2, 1, 1, 4 },
    { -27, 2, 1, 1, 4 },
    { -42, 1, 1, 1, 4 },
    { -45, 5, 1, 1, 4 },
    { -55, 1, 1, 1, 4 },
    { -42, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -28, 0, 1, 1, 5 },
    { -43, 0, 1, 1, 5 },
    { -23, 2, 1, 1, 5 },
    { -22, 9, 1, 1, 5 },
    { -37, 0, 1, 1, 5 },
    { -31, 1, 1, 1, 5 },
    { -47, 0, 1, 1, 5 },
    { -24, 4, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -36, 1, 1, 1, 5 },
    { -22, 9, 1, 1, 5 },
    { -23, 2, 1, 1, 5 },
    { -23, 2, 1, 1, 5 },
    { -28, 0, 1, 1, 5 },
    { -23, 2, 1, 1, 5 },
    { -23, 2, 1, 1, 5 },
    { -48, 0, 1, 1, 5 },
    { -38, 3, 1, 1, 5 },
    { -58, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -39, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -21, 3, 1, 1, 6 },
    { -43, 0, 1, 1, 6 },
    { -26, 2, 1, 1, 6 },
    { -25, 0, 1, 1, 6 },
    { -5, 0, 1, 1, 6 },
    { -47, 0, 1, 1, 6 },
    { -34, 0, 1, 1, 6 },
    { -63, 3, 1, 1, 6 },
    { -37, 0, 1, 1, 6 },
    { -36, 0, 1, 1, 6 },
    { -25, 0, 1, 1, 6 },
    { -26, 2, 1, 1, 6 },
    { -26, 2, 1, 1, 6 },
    { -21, 3, 1, 1, 6 },
    { -26, 2, 1, 1, 6 },
    { -26, 2, 1, 1, 6 },
    { -32, -2, 1, 1, 6 },
    { -44, 0, 1, 1, 6 },
    { -49, 0, 1, 1, 6 },
    { -29, 0, 1, 1, 6 },
    { -49, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { -31, 0, 1, 1, 7 },
    { -38, 0, 1, 1, 7 },
    { -30, 2, 1, 1, 7 },
    { -29, 0, 1, 1, 7 },
    { -51, 0, 1, 1, 7 },
    { -31, 1, 1, 1, 7 },
    { -34, 0, 1, 1, 7 },
    { -42, 7, 1, 1, 7 },
    { -53, 0, 1, 1, 7 },
    { -41, 0, 1, 1, 7 },
    { -29, 0, 1, 1, 7 },
    { -30, 2, 1, 1, 7 },
    { -30, 2, 1, 1, 7 },
    { -31, 0, 1, 1, 7 },
    { -30, 2, 1, 1, 7 },
    { -30, 2, 1, 1, 7 },
    { -34, 1, 1, 1, 7 },
    { -34, 0, 1, 1, 7 },
    { -49, 0, 1, 1, 7 },
    { -27, 0, 1, 1, 7 },
    { -59, 3, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -28, 0, 1, 1, 8 },
    { -38, 0, 1, 1, 8 },
    { -18, 2, 1, 1, 8 },
    { -37, 3, 1, 1, 8 },
    { -43, -1, 1, 1, 8 },
    { -33, 1, 1, 1, 8 },
    { -35, 1, 1, 1, 8 },
    { -52, 6, 1, 1, 8 },
    { -40, 1, 1, 1, 8 },
    { -29, 0, 1, 1, 8 },
    { -37, 3, 1, 1, 8 },
    { -18, 2, 1, 1, 8 },
    { -18, 2, 1, 1, 8 },
    { -28, 0, 1, 1, 8 },
    { -18, 2, 1, 1, 8 },
    { -18, 2, 1, 1, 8 },
    { -38, 0, 1, 1, 8 },
    { -35, 1, 1, 1, 8 },
    { -61, -1, 1, 1, 8 },
    { -26, 0, 1, 1, 8 },
    { -57, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -73, 2, 1, 1, 9 },
    { -38, 2, 1, 1, 9 },
    { -43, 15, 1, 1, 9 },
    { -44, 5, 1, 1, 9 },
    { -47, 2, 1, 1, 9 },
    { -34, 6, 1, 1, 9 },
    { -51, 3, 1, 1, 9 },
    { -57, 12, 1, 1, 9 },
    { -47, 3, 1, 1, 9 },
    { -49, 11, 1, 1, 9 },
    { -44, 5, 1, 1, 9 },
    { -43, 15, 1, 1, 9 },
    { -43, 15, 1, 1, 9 },
    { -73, 2, 1, 1, 9 },
    { -43, 15, 1, 1, 9 },
    { -43, 15, 1, 1, 9 },
    { -47, 7, 1, 1, 9 },
    { -58, 13, 1, 1, 9 },
    { -46, 3, 1, 1, 9 },
    { -53, 4, 1, 1, 9 },
    { -60, 2, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
};

/* extra scripts: 56 entries */
const u16* const q_exca[57] = {
    q_exca_000,  /* 0 follow-up of AIR NORMAL */
    q_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    q_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    q_exca_003,  /* 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI +1 */
    q_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    q_exca_005,  /* 5 follow-up of UPPER, HARAYARARE +19 */
    q_exca_006,  /* 6 follow-up of NOKEZORI, BODY UPPER +10 */
    q_exca_007,  /* 7 no name */
    q_exca_008,  /* 8 follow-up of KGM TATAKI S, KUNOJI +4 */
    q_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +1 */
    q_exca_010,  /* 10 follow-up of KIRIMOMI, IBUKI KUBIORI */
    q_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    q_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    q_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    q_exca_014,  /* 14 no name */
    q_exca_015,  /* 15 no name */
    q_exca_016,  /* 16 no name */
    q_exca_017,  /* 17 follow-up of APPEAR JUNBI 1 */
    q_exca_018,  /* 18 no name */
    q_exca_019,  /* 19 no name */
    q_exca_020,  /* 20 no name */
    q_exca_021,  /* 21 no name */
    q_exca_022,  /* 22 no name */
    q_exca_023,  /* 23 follow-up of HARAIGOSHI */
    q_exca_024,  /* 24 follow-up of SP APPEAR 2, SP APPEAR 4 */
    q_exca_025,  /* 25 follow-up of SP APPEAR 2, SP APPEAR 4 */
    q_exca_017,  /* 26 no name */
    q_exca_017,  /* 27 no name */
    q_exca_017,  /* 28 no name */
    q_exca_029,  /* 29 no name */
    q_exca_030,  /* 30 follow-up of APPEAR 1 */
    q_exca_030,  /* 31 follow-up of APPEAR 1 */
    q_exca_032,  /* 32 no name */
    q_exca_033,  /* 33 follow-up of APPEAR 5 */
    q_exca_034,  /* 34 follow-up of APPEAR 5 */
    q_exca_017,  /* 35 no name */
    q_exca_017,  /* 36 no name */
    q_exca_037,  /* 37 follow-up of WIN 6 */
    q_exca_038,  /* 38 follow-up of WIN 6 */
    q_exca_039,  /* 39 follow-up of WIN 7 */
    q_exca_040,  /* 40 follow-up of WIN 7 */
    q_exca_041,  /* 41 follow-up of GILL IMPACT C */
    q_exca_042,  /* 42 follow-up of GILL IMPACT C */
    q_exca_043,  /* 43 follow-up of WIN 8 */
    q_exca_044,  /* 44 follow-up of WIN 8 */
    q_exca_045,  /* 45 follow-up of SP WIN 1 */
    q_exca_046,  /* 46 follow-up of SP WIN 1 */
    q_exca_047,  /* 47 follow-up of SP WIN 2 */
    q_exca_048,  /* 48 follow-up of SP WIN 2 */
    q_exca_049,  /* 49 follow-up of SP WIN 3 */
    q_exca_017,  /* 50 follow-up of SP WIN 3 */
    q_exca_049,  /* 51 follow-up of SP WIN 4 */
    q_exca_017,  /* 52 follow-up of SP WIN 4 */
    q_exca_049,  /* 53 follow-up of SP WIN 5 */
    q_exca_017,  /* 54 follow-up of SP WIN 5 */
    q_exca_055,  /* 55 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 q_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_000[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD1, 0, 280, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD0, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACF, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACE, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACD, 0, 280, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6AD3, 0, 280, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD4, 0, 280, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD5, 0, 280, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD6, 0, 280, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD7, 0, 280, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD8, 0, 280, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD9, 0, 280, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6ADA, 0, 280, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 q_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_001[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x662D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI, ASIB TUNNOMERI +1 */
const u16 q_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_003[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 q_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_004[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x662D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of UPPER, HARAYARARE +19 */
const u16 q_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_005[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, BODY UPPER +10 */
const u16 q_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_006[148] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x673B, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x673C, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x673D, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x673E, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x673F, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6740, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6741, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6742, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6743, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6744, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6745, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 no name */
const u16 q_exca_007_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_007[124] = {
    CMD(CM_PA_X, 0, 10240, 0), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x66EC, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x66ED, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x66EE, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x66EF, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x66F0, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x66F1, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x66F2, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x66F3, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x66F4, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F5, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F6, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F7, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x66F8, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x66F8, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KGM TATAKI S, KUNOJI +4 */
const u16 q_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_008[140] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x674E, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x674F, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6750, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6751, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6752, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6753, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6742, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6743, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6744, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6745, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +1 */
const u16 q_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_009[116] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 follow-up of KIRIMOMI, IBUKI KUBIORI */
const u16 q_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_010[140] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x673B, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x673C, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x673D, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x673E, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x673F, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6740, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6741, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6742, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6743, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6744, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6745, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6746, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6747, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 q_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_011[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x660B, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x660C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 q_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_013[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x660B, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x660C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 no name */
const u16 q_exca_014_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_014[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x66FA, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 no name */
const u16 q_exca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_015[20] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x66EE, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 no name */
const u16 q_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_016[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x6702, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x6701, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 3, 0, 0, 0x66FF, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66E9, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66E9, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name */
const u16 q_exca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_018[36] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x66E5, 0, 279, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x66E6, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66E7, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 no name */
const u16 q_exca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_019[60] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 2, 0, 0, 0x6702, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x6701, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x66FF, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x66E9, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x66E9, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 no name */
const u16 q_exca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_020[84] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 3, 0, 0, 0x66E0, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x6725, 0, 279, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 2, 0, 0, 0x6727, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x6728, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x6729, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 2, 0, 0, 0x672A, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 2, 0, 0, 0x672C, 0, 279, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66FA, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66FA, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 no name */
const u16 q_exca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_021[68] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 3, 0, 0, 0x6706, 0, 279, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x6700, 0, 279, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x66FF, 0, 279, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 3, 0, 0, 0x6913, 0, 279, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x66FB, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66FB, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 q_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_022[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x673B, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x673B, 0, 279, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI */
const u16 q_exca_023_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_023[116] = {
    L4(1, 2, 0, 0, 1, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 1, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 1, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 1, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 1, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 follow-up of SP APPEAR 2, SP APPEAR 4 */
const u16 q_exca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_024[60] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x6AC6, 0, 298, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AC7, 0, 299, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of SP APPEAR 2, SP APPEAR 4 */
const u16 q_exca_025_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_025[60] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x665A, 0, 2, 0, 0, 0, 32, 98),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6819, 0, 2, 0, 0, 0, 32, 99),
    L4(4, 0, 0, 0, 0, 0, 0, 0x681A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x681B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x665E, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x665F, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 q_exca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_029[44] = {
    CMD(CM_RJA, 7, 10, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x66EC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66ED, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66EE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 follow-up of APPEAR 1, 31 follow-up of APPEAR 1 */
const u16 q_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_030[60] = {
    CMD(CM_PA_X, 0, 2048, 0), 0, 0, 0, 0,
    L4(5, 64, 0, 0, 0, 0, 0, 0x668D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 no name */
const u16 q_exca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_032[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(6, 0, 0, 0, 0, 0, 0, 0x66E3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x66E4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66E5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x66E6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x66E7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 follow-up of APPEAR 5 */
const u16 q_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_033[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6684, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6685, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6686, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6687, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x660D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 follow-up of APPEAR 5 */
const u16 q_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_034[44] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x6629, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 follow-up of WIN 6 */
const u16 q_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_037[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x662A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x662A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x664B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 follow-up of WIN 6 */
const u16 q_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_038[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6629, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x662A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 follow-up of WIN 7 */
const u16 q_exca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_039[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x662A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x662A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x664B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 follow-up of WIN 7 */
const u16 q_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_040[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6629, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x662A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of GILL IMPACT C */
const u16 q_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_041[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 q_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 q_exca_042[116] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x675A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x675B, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x675C, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x675D, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675E, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x675F, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6760, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6761, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6762, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6748, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x6749, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x674A, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 9, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x67A3, 0, 282, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 follow-up of WIN 8 */
const u16 q_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_043[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x68BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67E6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x67E6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x67E7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6693, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6693, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 follow-up of WIN 8 */
const u16 q_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_044[76] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(4, 0, 273, 0, 0, 0, 0, 0x68BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6628, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6629, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 32), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x662A, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x662B, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x662C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 follow-up of SP WIN 1 */
const u16 q_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_045[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x662C, 0, 234, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x662D, 0, 234, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 follow-up of SP WIN 1 */
const u16 q_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_046[68] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x660B, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x660C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of SP WIN 2 */
const u16 q_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_047[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x662C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662D, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of SP WIN 2 */
const u16 q_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_048[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x660C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 follow-up of SP WIN 3, 51 follow-up of SP WIN 4, 53 follow-up of SP WIN 5 */
const u16 q_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_exca_049[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x668B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x668C, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x662E, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x662F, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of APPEAR JUNBI 1, 26 no name, 27 no name, 28 no name ... */
const u16 q_exca_017_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 q_exca_017[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x660C, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x660D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x660E, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x660F, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6610, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6611, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 q_exca_055_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 q_exca_055[124] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD1, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD0, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACF, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACE, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6ACD, 0, 456, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6AD3, 0, 456, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD4, 0, 456, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD5, 0, 456, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD6, 0, 457, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD7, 0, 457, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6AD8, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6AD9, 0, 458, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6ADA, 0, 458, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 68 entries */
const u16* const q_saca[69] = {
    q_saca_000,  /* 0 UP P GUARD P S */
    q_saca_001,  /* 1 UP P GUARD P M */
    q_saca_002,  /* 2 UP P GUARD P L */
    q_saca_002,  /* 3 UP P GUARD K S */
    q_saca_002,  /* 4 UP P GUARD K M */
    q_saca_002,  /* 5 UP P GUARD K L */
    q_saca_000,  /* 6 D P GUARD P S */
    q_saca_001,  /* 7 D P GUARD P M */
    q_saca_002,  /* 8 D P GUARD P L */
    q_saca_002,  /* 9 D P GUARD K S */
    q_saca_002,  /* 10 D P GUARD K M */
    q_saca_002,  /* 11 D P GUARD K L */
    q_saca_002,  /* 12 FUSHIN P S */
    q_saca_002,  /* 13 FUSHIN P M */
    q_saca_002,  /* 14 FUSHIN P L */
    q_saca_002,  /* 15 FUSHIN K S */
    q_saca_002,  /* 16 FUSHIN K M */
    q_saca_002,  /* 17 FUSHIN K L */
    q_saca_002,  /* 18 OKIAGARI P S */
    q_saca_002,  /* 19 OKIAGARI P M */
    q_saca_002,  /* 20 OKIAGARI P L */
    q_saca_002,  /* 21 OKIAGARI K S */
    q_saca_002,  /* 22 OKIAGARI K M */
    q_saca_002,  /* 23 OKIAGARI K L */
    q_saca_024,  /* 24 ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP) */
    q_saca_025,  /* 25 ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP) */
    q_saca_026,  /* 26 ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) */
    q_saca_027,  /* 27 ATTACK 1 SP: EX [4]6+PP (routine Att_SLIDE_and_JUMP) */
    q_saca_028,  /* 28 ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) */
    q_saca_029,  /* 29 ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
    q_saca_030,  /* 30 ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
    q_saca_031,  /* 31 ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
    q_saca_032,  /* 32 ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    q_saca_033,  /* 33 ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    q_saca_034,  /* 34 ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    q_saca_034,  /* 35 ATTACK 3 SP: after [4]6+P (routine Att_SLIDE_and_JUMP) */
    q_saca_036,  /* 36 ATTACK 4 S: 214+P light (plain script) */
    q_saca_037,  /* 37 ATTACK 4 M: 214+P medium (plain script) */
    q_saca_038,  /* 38 ATTACK 4 L: 214+P heavy (plain script) */
    q_saca_039,  /* 39 ATTACK 4 SP: EX 214+PP (plain script) */
    q_saca_040,  /* 40 ATTACK 5 S: 3214+K light (plain script) */
    q_saca_041,  /* 41 ATTACK 5 M: 3214+K medium (plain script) */
    q_saca_042,  /* 42 ATTACK 5 L: 3214+K heavy/EX (plain script) */
    q_saca_042,  /* 43 ATTACK 5 SP: 3214+K heavy/EX (plain script) */
    q_saca_044,  /* 44 ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    q_saca_044,  /* 45 ATTACK 6 M: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    q_saca_046,  /* 46 ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    q_saca_047,  /* 47 ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
    q_saca_048,  /* 48 ATTACK 7 S: SA II 23623+P (plain script) */
    q_saca_048,  /* 49 ATTACK 7 M: SA II 23623+P (plain script) */
    q_saca_048,  /* 50 ATTACK 7 L: SA II 23623+P (plain script) */
    q_saca_048,  /* 51 ATTACK 7 SP: SA II 23623+P (plain script) */
    q_saca_052,  /* 52 ATTACK 8 S: SA III 23623+P (plain script) */
    q_saca_053,  /* 53 ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
    q_saca_054,  /* 54 ATTACK 8 L: 236+K (plain script) */
    q_saca_054,  /* 55 ATTACK 8 SP: 236+K (plain script) */
    q_saca_054,  /* 56 ATTACK 9 S: 236+K (plain script) */
    q_saca_054,  /* 57 ATTACK 9 M: 236+K (plain script) */
    q_saca_054,  /* 58 ATTACK 9 L: 236+K (plain script) */
    q_saca_054,  /* 59 ATTACK 9 SP: 236+K (plain script) */
    q_saca_060,  /* 60 ATTACK 10 S: not started by a command */
    q_saca_060,  /* 61 ATTACK 10 M: not started by a command */
    q_saca_060,  /* 62 ATTACK 10 L: not started by a command */
    q_saca_060,  /* 63 ATTACK 10 SP: not started by a command */
    q_saca_064,  /* 64 ATTACK 11 S: not started by a command */
    q_saca_064,  /* 65 ATTACK 11 M: not started by a command */
    q_saca_064,  /* 66 ATTACK 11 L: not started by a command */
    q_saca_067,  /* 67 ATTACK 11 SP: not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 q_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 q_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x712B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7130, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7131, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7132, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7133, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7134, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x7135, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -3328, 6400), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 15, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 q_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 q_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x7135, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x7134, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x7134, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7133, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7132, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7131, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7130, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712F, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712E, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712D, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712C, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x712B, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 q_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 q_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6601),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: [4]6+P light (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_024_head[4] = { HEAD(6, 0, 8, 13, 0, 1, 84) };
const u16 q_saca_024[364] = {
    CMD(CM_IMGS, 0, 20, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 32, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 778, 0, 0, 0, 0, 0x6938, 0, 251, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693A, 0, 252, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x693D, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693F, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6940, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 16, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6944, 0, 261, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -45, 264, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 45, 265, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6949, 45, 266, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ATTACK 1 M: [4]6+P medium (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_025_head[4] = { HEAD(6, 0, 10, 13, 0, 1, 84) };
const u16 q_saca_025[388] = {
    CMD(CM_IMGS, 0, 21, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 33, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 778, 0, 0, 0, 0, 0x6937, 0, 274, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6938, 0, 251, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6939, 0, 275, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693A, 0, 252, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 174, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x693D, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693F, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6940, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 32, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6944, 0, 261, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -46, 264, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 46, 265, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6949, 46, 266, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 ATTACK 1 L: [4]6+P heavy (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_026_head[4] = { HEAD(6, 0, 12, 13, 0, 1, 84) };
const u16 q_saca_026[412] = {
    CMD(CM_IMGS, 0, 22, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA, 5, 34, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 778, 0, 0, 0, 0, 0x6936, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6937, 0, 274, 0, 0, 0, 0, 0, 0, 0, 162, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6938, 0, 251, 0, 0, 0, 0, 0, 0, 0, 164, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6939, 0, 275, 0, 0, 0, 0, 0, 0, 0, 166, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693A, 0, 252, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693B, 0, 252, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 172, 0, 0),
    L6(2, 30, 279, 0, 0, 0, 0, 0x693D, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693F, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6940, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 64, 8194, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6944, 0, 261, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6947, -47, 264, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 47, 265, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x6949, 47, 266, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ATTACK 1 SP: EX [4]6+PP (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_027_head[4] = { HEAD(6, 0, 14, 13, 0, 1, 84) };
const u16 q_saca_027[448] = {
    CMD(CM_JSR, 8, 16, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 778, 0, 0, 0, 0, 0x6938, 0, 251, 0, 0, 0, 0, 0, 0, 0, 156, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693A, 0, 252, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(2, 30, 279, 0, 0, 0, 0, 0x693D, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x693F, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6940, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6944, 0, 261, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -48, 264, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 48, 265, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6949, 48, 266, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16393, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(12, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 8), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: [4]6+K light (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_028_head[4] = { HEAD(6, 3, 8, 12, 0, 1, 84) };
const u16 q_saca_028[352] = {
    CMD(CM_IMGS, 0, 23, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB2, 0, 274, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB3, 0, 251, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB4, 0, 275, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(3, 0, 775, 0, 0, 0, 0, 0x6AB5, 0, 252, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB7, 0, 253, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x6AB8, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB9, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABA, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABB, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABC, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6ABD, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6ABE, 0, 290, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABF, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, 0, 487, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, -49, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC1, 49, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: [4]6+K medium (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_029_head[4] = { HEAD(6, 3, 10, 12, 0, 1, 84) };
const u16 q_saca_029[364] = {
    CMD(CM_IMGS, 0, 24, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB1, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB2, 0, 274, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB3, 0, 251, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB4, 0, 275, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(4, 0, 775, 0, 0, 0, 0, 0x6AB5, 0, 252, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB7, 0, 253, 0, 0, 0, 0, 0, 0, 0, 194, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x6AB8, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB9, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABA, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABB, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABC, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABD, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6ABE, 0, 290, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABF, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, 0, 487, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, -50, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC1, 50, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: [4]6+K heavy (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_030_head[4] = { HEAD(6, 3, 12, 12, 0, 1, 84) };
const u16 q_saca_030[376] = {
    CMD(CM_IMGS, 0, 25, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB1, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB2, 0, 274, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB3, 0, 251, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB4, 0, 275, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(4, 0, 775, 0, 0, 0, 0, 0x6AB5, 0, 252, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB6, 0, 252, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB7, 0, 253, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x6AB8, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB9, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABA, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABB, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6ABC, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABD, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6ABE, 0, 290, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABF, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, 0, 487, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, -51, 292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC1, 51, 293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX [4]6+KK (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_031_head[4] = { HEAD(6, 3, 14, 12, 0, 1, 84) };
const u16 q_saca_031[340] = {
    CMD(CM_JSR, 8, 17, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB1, 0, 276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB2, 0, 274, 0, 0, 0, 0, 0, 0, 0, 182, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB3, 0, 251, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AB4, 0, 275, 0, 0, 0, 0, 0, 0, 0, 186, 0, 0),
    L6(3, 0, 775, 0, 0, 0, 0, 0x6AB5, 0, 252, 0, 0, 0, 0, 0, 0, 0, 188, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AB6, 0, 252, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB7, 0, 253, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x6AB8, 0, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AB9, 0, 255, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABA, 0, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABB, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6ABC, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6ABD, 0, 289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6ABE, 0, 290, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6ABF, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, 0, 487, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, -52, 292, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC1, 52, 293, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AC3, -53, 297, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(6, 0, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(14, 21, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_L, 2, 8196, 8195), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: after [4]6+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_032_head[4] = { HEAD(6, 0, 8, 11, 0, 1, 84) };
const u16 q_saca_032[304] = {
    L6(6, 0, 0, 0, 0, 0, 0, 0x695A, 0, 433, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x695B, 0, 434, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 778, 0, 0, 0, 0, 0x695C, 0, 435, 0, 0, 0, 30, 139, 0, 0, 500, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695D, 0, 436, 0, 0, 0, 0, 0, 0, 0, 502, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, 0, 488, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, -74, 437, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695F, 0, 438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: after [4]6+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_033_head[4] = { HEAD(6, 0, 10, 11, 0, 1, 84) };
const u16 q_saca_033[304] = {
    L6(6, 0, 0, 0, 0, 0, 0, 0x695A, 0, 433, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 0, 0, 0x695B, 0, 434, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 778, 0, 0, 0, 0, 0x695C, 0, 435, 0, 0, 0, 30, 139, 0, 0, 500, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695D, 0, 436, 0, 0, 0, 0, 0, 0, 0, 502, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, 0, 488, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, -75, 437, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695F, 0, 438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: after [4]6+P (routine Att_SLIDE_and_JUMP), 35 ATTACK 3 SP: after [4]6+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_034_head[4] = { HEAD(6, 0, 12, 11, 0, 1, 84) };
const u16 q_saca_034[304] = {
    L6(6, 0, 0, 0, 0, 0, 0, 0x695A, 0, 433, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 0, 0, 0x695B, 0, 434, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 778, 0, 0, 0, 0, 0x695C, 0, 435, 0, 0, 0, 30, 139, 0, 0, 500, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695D, 0, 436, 0, 0, 0, 0, 0, 0, 0, 502, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, 0, 488, 0, 0, 0, 0, 0, 0, 0, 504, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x695E, -76, 437, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x695F, 0, 438, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 7), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6960, 0, 439, 0, 0, 0, 21, 0, 0, 0, 506, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6961, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6962, 0, 440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6963, 0, 441, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6954, 0, 442, 0, 0, 0, 0, 0, 0, 0, 508, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 214+P light (plain script) */
const u16 q_saca_036_head[4] = { HEAD(6, 0, 8, 13, 0, 3, 87) };
const u16 q_saca_036[544] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6985, 0, 172, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x699B, 0, 189, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF4, 0, 190, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AF5, 0, 175, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6AF6, 0, 191, 0, 0, 0, 30, 211, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AF7, -69, 345, 0, 0, 0, 30, 212, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AF8, 0, 346, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF9, 0, 347, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AFA, 0, 194, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AFB, 0, 195, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6AFC, 0, 348, 0, 0, 0, 30, 213, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AFD, -70, 349, 0, 0, 0, 0, 0, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AFE, 0, 350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6AFF, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6B00, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6B01, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6B02, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AF6, 0, 191, 0, 0, 0, 30, 211, 0, 0, 468, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AF7, -71, 345, 0, 0, 0, 30, 212, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16395, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF8, 0, 346, 0, 0, 0, 21, 0, 0, 0, 260, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF9, 0, 347, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF8, 0, 346, 0, 0, 0, 21, 0, 0, 0, 260, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6AF9, 0, 347, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 214+P medium (plain script) */
const u16 q_saca_037_head[4] = { HEAD(6, 0, 10, 13, 0, 3, 87) };
const u16 q_saca_037[532] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6985, 0, 172, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6986, 0, 173, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6987, 0, 174, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6988, 0, 175, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6989, 0, 175, 0, 0, 0, 30, 214, 0, 0, 208, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x698A, -33, 176, 0, 0, 0, 30, 215, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x698B, 0, 177, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x698C, 0, 177, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x698D, 0, 178, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x698E, 0, 179, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x698F, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6990, -34, 181, 0, 0, 0, 30, 216, 0, 0, 218, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6991, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6992, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6993, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6994, 0, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6995, 0, 183, 0, 0, 0, 0, 0, 0, 0, 220, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6988, 0, 175, 0, 0, 0, 0, 0, 0, 0, 222, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6989, 0, 175, 0, 0, 0, 30, 214, 0, 0, 224, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x698A, -35, 176, 0, 0, 0, 30, 215, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16394, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x698B, 0, 177, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x698B, 0, 177, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 226, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 232, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 234, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 214+P heavy (plain script) */
const u16 q_saca_038_head[4] = { HEAD(6, 0, 12, 12, 0, 3, 87) };
const u16 q_saca_038[520] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6985, 0, 172, 0, 0, 0, 0, 0, 0, 0, 236, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x699B, 0, 189, 0, 0, 0, 0, 0, 0, 0, 238, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x699C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x699D, 0, 175, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x699E, 0, 191, 0, 0, 0, 30, 217, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699F, -36, 192, 0, 0, 0, 30, 218, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69A1, 0, 193, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A2, 0, 194, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A3, 0, 195, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x69A4, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A5, -37, 197, 0, 0, 0, 30, 219, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A6, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A7, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69A8, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A9, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x699D, 0, 175, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699E, 0, 191, 0, 0, 0, 30, 217, 0, 0, 258, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699F, -38, 192, 0, 0, 0, 30, 218, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16394, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x69A0, 0, 193, 0, 0, 0, 21, 0, 0, 0, 260, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 9), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x69A0, 0, 193, 0, 0, 0, 21, 0, 0, 0, 260, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 262, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 264, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 266, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 268, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 270, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 214+PP (plain script) */
const u16 q_saca_039_head[4] = { HEAD(6, 0, 14, 13, 0, 7, 87) };
const u16 q_saca_039[820] = {
    CMD(CM_JSR, 8, 18, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6985, 0, 172, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6986, 0, 173, 0, 0, 0, 0, 0, 0, 0, 202, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6987, 0, 174, 0, 0, 0, 0, 0, 0, 0, 204, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6988, 0, 175, 0, 0, 0, 0, 0, 0, 0, 206, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x6989, 0, 175, 0, 0, 0, 30, 214, 0, 0, 208, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x698A, -54, 378, 0, 0, 0, 30, 215, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x698B, 0, 177, 0, 0, 0, 0, 0, 0, 0, 210, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x698C, 0, 177, 0, 0, 0, 0, 0, 0, 0, 212, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x698D, 0, 178, 0, 0, 0, 0, 0, 0, 0, 214, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x698E, 0, 179, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x698F, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6990, -55, 379, 0, 0, 0, 30, 216, 0, 0, 218, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6991, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6992, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6993, 0, 182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6994, 0, 183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699C, 0, 190, 0, 0, 0, 0, 0, 0, 0, 310, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699D, 0, 175, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x699E, 0, 191, 0, 0, 0, 30, 217, 0, 0, 244, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699F, -56, 380, 0, 0, 0, 30, 218, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 246, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A1, 0, 193, 0, 0, 0, 0, 0, 0, 0, 248, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A2, 0, 194, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A3, 0, 195, 0, 0, 0, 0, 0, 0, 0, 252, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x69A4, 0, 196, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A5, -57, 381, 0, 0, 0, 30, 219, 0, 0, 254, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A6, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A7, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69A8, 0, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69A9, 0, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x699D, 0, 175, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x69B2, 0, 205, 0, 0, 0, 30, 220, 0, 0, 312, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69B3, -58, 382, 0, 0, 0, 30, 221, 0, 0, 278, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69B4, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69B5, 0, 208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69B6, 0, 209, 0, 0, 0, 0, 0, 0, 0, 280, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69B7, 0, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69B8, 0, 211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69B9, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69BA, 0, 213, 0, 0, 0, 0, 0, 0, 0, 282, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x69BB, 0, 214, 0, 0, 0, 30, 222, 0, 0, 284, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69BC, -59, 383, 0, 0, 0, 30, 223, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69BD, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69BE, 0, 217, 0, 0, 0, 0, 0, 0, 0, 286, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69BF, 0, 218, 0, 0, 0, 0, 0, 0, 0, 288, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69C6, 0, 384, 0, 0, 0, 0, 0, 0, 0, 314, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69C7, 0, 385, 0, 0, 0, 0, 0, 0, 0, 316, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69C8, 0, 386, 0, 0, 0, 0, 0, 0, 0, 318, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0x69C9, 0, 387, 0, 0, 0, 30, 224, 0, 0, 320, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x69CA, -60, 388, 0, 0, 0, 30, 225, 0, 0, 322, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x69CB, 60, 389, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69CC, 0, 390, 0, 0, 0, 21, 0, 0, 0, 324, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x69CD, 0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69CE, 0, 392, 0, 0, 0, 0, 0, 0, 0, 326, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x69CF, 0, 184, 0, 0, 0, 0, 0, 0, 0, 328, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D0, 0, 185, 0, 0, 0, 0, 0, 0, 0, 330, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D1, 0, 186, 0, 0, 0, 0, 0, 0, 0, 332, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D2, 0, 187, 0, 0, 0, 0, 0, 0, 0, 334, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x69D3, 0, 188, 0, 0, 0, 0, 0, 0, 0, 336, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662E, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x662F, 0, 201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6630, 0, 202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6631, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: 3214+K light (plain script) */
const u16 q_saca_040_head[4] = { HEAD(6, 0, 24, 10, 0, 1, 88) };
const u16 q_saca_040[280] = {
    CMD(CM_CAFR, 2, 1, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6964, 0, 220, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6965, 0, 221, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    CMD(CM_EXEC, 30, 226, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 227, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 228, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 268, 0, 0, 0, 0, 0x6966, 0, 222, 0, 0, 0, 30, 229, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6967, -1, 223, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6979, 0, 224, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x697A, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697B, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697C, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(13, 0, 0, 0, 0, 0, 0, 0x697D, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x697E, 0, 225, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x697F, 0, 226, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6848, 0, 226, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6849, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x684B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: 3214+K medium (plain script) */
const u16 q_saca_041_head[4] = { HEAD(6, 0, 26, 10, 0, 1, 88) };
const u16 q_saca_041[280] = {
    CMD(CM_CAFR, 2, 1, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 13), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6964, 0, 220, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6965, 0, 221, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    CMD(CM_EXEC, 30, 226, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 227, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 228, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 268, 0, 0, 0, 0, 0x6966, 0, 222, 0, 0, 0, 30, 229, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6967, -1, 227, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6979, 0, 224, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x697A, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697B, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697C, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(15, 0, 0, 0, 0, 0, 0, 0x697D, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x697E, 0, 225, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x697F, 0, 226, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6848, 0, 226, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6849, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x684B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: 3214+K heavy/EX (plain script), 43 ATTACK 5 SP: 3214+K heavy/EX (plain script) */
const u16 q_saca_042_head[4] = { HEAD(6, 0, 28, 10, 0, 1, 88) };
const u16 q_saca_042[280] = {
    CMD(CM_CAFR, 2, 1, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 14), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6964, 0, 220, 0, 0, 0, 0, 0, 0, 0, 126, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6965, 0, 221, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0),
    CMD(CM_EXEC, 30, 226, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 227, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 228, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(5, 0, 268, 0, 0, 0, 0, 0x6966, 0, 222, 0, 0, 0, 30, 229, 0, 0, 130, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6967, -1, 228, 0, 0, 0, 0, 0, 0, 0, 132, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6979, 0, 224, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x697A, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697B, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x697C, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(17, 0, 0, 0, 0, 0, 0, 0x697D, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x697E, 0, 225, 0, 0, 0, 0, 0, 0, 0, 134, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x697F, 0, 226, 0, 0, 0, 0, 0, 0, 0, 136, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6848, 0, 226, 0, 0, 0, 0, 0, 0, 0, 138, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6849, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x684A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 140, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x684B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA I 23623+P (routine Att_SLIDE_and_JUMP), 45 ATTACK 6 M: SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_044_head[4] = { HEAD(6, 0, 48, 13, 0, 5, 89) };
const u16 q_saca_044[496] = {
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(50, 0, 0, 0, 0, 0, 0, 0x693C, 0, 300, 0, 0, 0, 13, 57, 776, 0, 160, 0, 0),
    L6(1, 0, 279, 0, 0, 0, 0, 0x693E, 0, 300, 0, 0, 0, 30, 137, 0, 0, 0, 0, 0),
    L6(2, 30, 0, 0, 0, 0, 0, 0x6942, 0, 300, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 778, 0, 0, 0, 0, 0x6945, 0, 300, 0, 0, 0, 30, 78, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -61, 337, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 61, 338, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6949, 61, 339, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 46, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 47, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 137, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6940, 0, 257, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 778, 0, 0, 0, 0, 0x6944, 0, 261, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -63, 340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 18, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 63, 341, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6949, 63, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x694D, 0, 270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x694E, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x694F, 0, 272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6950, 0, 273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6952, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6953, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_046_head[4] = { HEAD(6, 0, 48, 13, 0, 5, 89) };
const u16 q_saca_046[172] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x693C, 0, 253, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0),
    L6(1, 30, 279, 0, 0, 0, 0, 0x693E, 0, 255, 0, 0, 0, 30, 137, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6941, 0, 258, 0, 0, 0, 30, 138, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6942, 0, 259, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6943, 0, 260, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 778, 0, 0, 0, 0, 0x6945, 0, 262, 0, 0, 0, 30, 78, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6946, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6947, -61, 340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6948, 61, 341, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6949, 61, 342, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x694A, 0, 267, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x694B, 0, 268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x694C, 0, 269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: after SA I 23623+P (routine Att_SLIDE_and_JUMP) */
const u16 q_saca_047_head[4] = { HEAD(6, 0, 48, 13, 0, 5, 89) };
const u16 q_saca_047[172] = {
    L6(1, 30, 279, 0, 0, 0, 0, 0x6AB9, 0, 255, 0, 0, 0, 30, 76, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABA, 0, 256, 0, 0, 0, 30, 77, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABB, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABC, 0, 288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABD, 0, 289, 0, 0, 0, 30, 139, 0, 0, 0, 0, 0),
    L6(1, 0, 775, 0, 0, 0, 0, 0x6ABE, 0, 290, 0, 0, 0, 30, 137, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6ABF, 0, 291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC0, -62, 343, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC1, 62, 344, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC2, 0, 294, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC3, 0, 295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x6AC4, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6AC5, 0, 296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: SA II 23623+P (plain script), 49 ATTACK 7 M: SA II 23623+P (plain script), 50 ATTACK 7 L: SA II 23623+P (plain script), 51 ATTACK 7 SP: SA II 23623+P (plain script) */
const u16 q_saca_048_head[4] = { HEAD(6, 0, 48, 10, 0, 2, 90) };
const u16 q_saca_048[676] = {
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A0B, 0, 300, 0, 0, 0, 13, 58, 783, 0, 376, 0, 0),
    L6(5, 30, 0, 0, 0, 0, 0, 0x6A0C, 0, 300, 0, 0, 0, 0, 0, 783, 0, 378, 0, 0),
    L6(35, 0, 0, 0, 0, 0, 0, 0x6A0D, 0, 300, 0, 0, 0, 0, 0, 783, 0, 380, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A0E, 0, 300, 0, 0, 0, 0, 0, 15, 0, 382, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A0F, 0, 300, 0, 0, 0, 0, 0, 15, 0, 384, 0, 0),
    CMD(CM_EXEC, 30, 156, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 157, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 158, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 159, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 164, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 165, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 166, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A10, 0, 300, 0, 0, 0, 0, 0, 0, 0, 386, 0, 0),
    L6(1, 0, 293, 0, 0, 0, 0, 0x6A11, -65, 301, 0, 128, 0, 39, 20, 0, 0, 388, 0, 0),
    CMD(CM_HJMP, 16386, 8197, 16386), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_UJA5, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A12, 0, 302, 0, 0, 0, 0, 0, 0, 0, 390, 0, 0),
    L6(5, 0, 778, 0, 0, 0, 0, 0x6A13, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A14, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A15, 0, 303, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A16, 0, 304, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A17, 0, 305, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A18, 0, 306, 0, 0, 0, 0, 0, 0, 0, 398, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A19, 0, 307, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A1A, 0, 308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A1B, 0, 309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A1C, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A1D, 0, 311, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A1E, 0, 312, 0, 0, 0, 0, 0, 0, 0, 402, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A1F, 0, 313, 0, 0, 0, 0, 0, 0, 0, 404, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A20, 0, 314, 0, 0, 0, 0, 0, 0, 0, 406, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A21, 0, 315, 0, 0, 0, 0, 0, 0, 0, 408, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A22, 0, 316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 271, 0, 0, 0, 0, 0x6A23, -66, 317, 0, 0, 0, 39, 26, 0, 0, 410, 0, 0),
    CMD(CM_EXEC, 30, 160, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 161, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 162, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 163, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 167, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 168, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A24, 0, 318, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A25, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A26, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A27, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A28, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A29, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A2A, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A2B, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A2C, 0, 319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A2D, 0, 320, 0, 0, 0, 0, 0, 0, 0, 412, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A2E, 0, 321, 0, 0, 0, 0, 0, 0, 0, 414, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6678, 0, 1, 0, 0, 0, 0, 0, 0, 0, 416, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x6679, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x667A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x667A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: SA III 23623+P (plain script) */
const u16 q_saca_052_head[4] = { HEAD(6, 0, 48, 12, 0, 1, 91) };
const u16 q_saca_052[304] = {
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A3C, 0, 300, 0, 0, 0, 13, 59, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A3D, 0, 300, 0, 0, 0, 0, 0, 783, 0, 436, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A3E, 0, 300, 0, 0, 0, 0, 0, 783, 0, 438, 0, 0),
    L6(3, 0, 777, 0, 0, 0, 0, 0x6A3F, 0, 300, 0, 0, 0, 0, 0, 783, 0, 440, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A40, 0, 300, 0, 0, 0, 0, 0, 783, 0, 442, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A41, 0, 300, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A42, 0, 300, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A43, 0, 300, 0, 0, 0, 0, 0, 783, 0, 444, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A44, 0, 300, 0, 0, 0, 0, 0, 783, 0, 446, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A45, 0, 300, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A46, 0, 300, 0, 0, 0, 0, 0, 783, 0, 448, 0, 0),
    L6(12, 0, 0, 0, 0, 0, 0, 0x6A47, 0, 300, 0, 0, 0, 0, 0, 783, 0, 450, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A48, 0, 300, 0, 0, 0, 16, 8, 783, 0, 452, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A49, 0, 300, 0, 0, 0, 0, 0, 0, 0, 454, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A4A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A4C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 456, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A4D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 458, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x666A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x666B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x666C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x666D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x666E, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 ATTACK 8 M: 236+P (routine Att_PL18_NINGENBAKUDAN) */
const u16 q_saca_053_head[4] = { HEAD(6, 0, 48, 12, 0, 1, 91) };
const u16 q_saca_053[232] = {
    CMD(CM_RJA7, 5, 53, 17), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 778, 0, 0, 0, 0, 0x6A3F, 0, 369, 0, 0, 0, 0, 0, 0, 0, 460, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A40, 0, 370, 0, 0, 0, 0, 0, 0, 0, 462, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A4E, 0, 371, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6A4F, -67, 372, 0, 128, 0, 0, 0, 0, 0, 464, 0, 0),
    CMD(CM_HJMP, 8200, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A50, 0, 373, 0, 0, 0, 21, 0, 0, 0, 466, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B0B, 0, 373, 0, 0, 0, 0, 0, 0, 0, 492, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6B0C, 0, 374, 0, 0, 0, 0, 0, 0, 0, 494, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6B0D, 0, 375, 0, 0, 0, 0, 0, 0, 0, 496, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6B0E, 0, 375, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6B0F, 0, 376, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B10, 0, 377, 0, 0, 0, 0, 0, 0, 0, 498, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x68F5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6704, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(10, 0, 0, 0, 0, 0, 0, 0x6A51, 0, 300, 0, 0, 0, 42, 3, 8716, 0, 0, 0, 0),
    L6(3, 50, 0, 0, 0, 0, 0, 0x6A51, 0, 300, 0, 0, 0, 0, 0, 8716, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6A51, 0, 1, 0, 0, 0, 0, 0, 8716, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: 236+K (plain script), 55 ATTACK 8 SP: 236+K (plain script), 56 ATTACK 9 S: 236+K (plain script), 57 ATTACK 9 M: 236+K (plain script) ... */
const u16 q_saca_054_head[4] = { HEAD(6, 0, 56, 12, 0, 1, 91) };
const u16 q_saca_054[316] = {
    CMD(CM_CAFR, 2, 8, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_CARE, 2, 8, 16), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 772, 0, 0, 0, 0, 0x68DD, 0, 351, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 798, 0, 0, 0, 0, 0x68DE, 0, 351, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x68DE, 0, 351, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x68DF, -43, 357, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x68E0, 0, 358, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6A54, 0, 359, 0, 0, 0, 0, 0, 0, 0, 470, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A55, 0, 360, 0, 0, 0, 0, 0, 0, 0, 472, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A56, 0, 361, 0, 0, 0, 0, 0, 0, 0, 474, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A57, 0, 362, 0, 0, 0, 0, 0, 0, 0, 476, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6B03, 0, 363, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6B04, 0, 364, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B05, 0, 364, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B06, 0, 364, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B07, 0, 365, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6B08, 0, 366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6B09, 0, 367, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6B0A, 0, 368, 0, 0, 0, 0, 0, 0, 0, 478, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x697F, 0, 226, 0, 0, 0, 0, 0, 0, 0, 480, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6849, 0, 1, 0, 0, 0, 0, 0, 0, 0, 482, 0, 0),
    L6(4, 64, 0, 0, 0, 0, 0, 0x684A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x684B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x684C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x684D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 ATTACK 10 S: not started by a command, 61 ATTACK 10 M: not started by a command, 62 ATTACK 10 L: not started by a command, 63 ATTACK 10 SP: not started by a command */
const u16 q_saca_060_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 q_saca_060[116] = {
    CMD(CM_JSR, 8, 40, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x660C, 0, 229, 0, 0, 0, 0, 0),
    L4(7, 20, 0, 0, 0, 0, 0, 0x68A0, 0, 230, 0, 0, 0, 22, 20),
    L4(5, 0, 0, 0, 0, 0, 0, 0x68A1, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 269, 0, 0, 0, 0, 0x68A2, -14, 232, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x68A3, 0, 232, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x68A4, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68A5, 0, 232, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x68A3, 0, 232, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x68A6, 0, 126, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x68A7, 0, 127, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6627, 0, 128, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6627, 0, 128, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 ATTACK 11 S: not started by a command, 65 ATTACK 11 M: not started by a command, 66 ATTACK 11 L: not started by a command */
const u16 q_saca_064_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_saca_064[256] = {
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A31, 0, 9, 0, 0, 0, 21, 0, 0, 0, 338, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A32, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6A33, 0, 14, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0),
    L6(2, 0, 778, 0, 0, 0, 0, 0x6A34, 0, 15, 0, 0, 0, 0, 0, 0, 0, 342, 0, 0),
    CMD(CM_EXEC, 1, 143, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 144, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_QUAY, 28, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 40, 285, 0, 0, 0, 0, 0x6A35, 0, 16, 0, 0, 0, 0, 0, 0, 0, 344, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A36, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A37, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6A38, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A39, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A3A, 0, 18, 0, 0, 0, 0, 0, 0, 0, 346, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A3B, 0, 19, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6A3C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x660B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x660A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6602, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6603, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6604, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: not started by a command */
const u16 q_saca_067_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 q_saca_067[160] = {
    L6(50, 0, 0, 0, 0, 0, 0, 0x6A12, 0, 302, 0, 0, 0, 21, 0, 0, 0, 390, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6A12, 0, 302, 0, 0, 0, 21, 0, 0, 0, 390, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0x6A13, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6A14, 0, 302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6A15, 0, 303, 0, 0, 0, 0, 0, 0, 0, 392, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6A16, 0, 304, 0, 0, 0, 0, 0, 0, 0, 394, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6A17, 0, 305, 0, 0, 0, 0, 0, 0, 0, 396, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x6A18, 0, 306, 0, 0, 0, 0, 0, 0, 0, 398, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x6A19, 0, 307, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6A1A, 0, 308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x6950, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6951, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 45 entries */
const u16* const q_cbca[46] = {
    q_cbca_000,  /* 0 APPEAR JUNBI 1 */
    q_cbca_001,  /* 1 APPEAR JUNBI 2 */
    q_cbca_002,  /* 2 APPEAR JUNBI 3 */
    q_cbca_003,  /* 3 APPEAR JUNBI 4 */
    q_cbca_004,  /* 4 APPEAR JUNBI 5 */
    q_cbca_005,  /* 5 APPEAR JUNBI 6 */
    q_cbca_006,  /* 6 APPEAR JUNBI 7 */
    q_cbca_007,  /* 7 APPEAR JUNBI 8 */
    q_cbca_008,  /* 8 APPEAR 1 */
    q_cbca_009,  /* 9 APPEAR 2 */
    q_cbca_010,  /* 10 APPEAR 3 */
    q_cbca_010,  /* 11 APPEAR 4 */
    q_cbca_012,  /* 12 APPEAR 5 */
    q_cbca_013,  /* 13 APPEAR 6 */
    q_cbca_014,  /* 14 APPEAR 7 */
    q_cbca_015,  /* 15 APPEAR 8 */
    q_cbca_016,  /* 16 SP APPEAR 1 */
    q_cbca_017,  /* 17 SP APPEAR 2 */
    q_cbca_018,  /* 18 SP APPEAR 3 */
    q_cbca_019,  /* 19 SP APPEAR 4 */
    q_cbca_020,  /* 20 SP APPEAR 5 */
    q_cbca_021,  /* 21 SP APPEAR 6 */
    q_cbca_022,  /* 22 SP APPEAR 7 */
    q_cbca_023,  /* 23 SP APPEAR 8 */
    q_cbca_024,  /* 24 ZANNEN 1 */
    q_cbca_024,  /* 25 ZANNEN 2 */
    q_cbca_024,  /* 26 ZANNEN 3 */
    q_cbca_024,  /* 27 ZANNEN 4 */
    q_cbca_024,  /* 28 ZANNEN 5 */
    q_cbca_024,  /* 29 ZANNEN 6 */
    q_cbca_024,  /* 30 ZANNEN 7 */
    q_cbca_024,  /* 31 ZANNEN 8 */
    q_cbca_024,  /* 32 WIN 1 */
    q_cbca_024,  /* 33 WIN 2 */
    q_cbca_024,  /* 34 WIN 3 */
    q_cbca_024,  /* 35 WIN 4 */
    q_cbca_024,  /* 36 WIN 5 */
    q_cbca_037,  /* 37 WIN 6 */
    q_cbca_038,  /* 38 WIN 7 */
    q_cbca_039,  /* 39 WIN 8 */
    q_cbca_040,  /* 40 SP WIN 1 */
    q_cbca_041,  /* 41 SP WIN 2 */
    q_cbca_042,  /* 42 SP WIN 3 */
    q_cbca_043,  /* 43 SP WIN 4 */
    q_cbca_044,  /* 44 SP WIN 5 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 q_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 17, 1),
    CMD(CM_RJA3, 7, 17, 7),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 q_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_001[16] = {
    CMD(CM_RJA, 1, 64, 6),
    CMD(CM_RJA2, 1, 65, 1),
    CMD(CM_RJA3, 1, 66, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 q_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 q_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 q_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 q_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 q_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 4, 6, 12),
    CMD(CM_RJA3, 4, 6, 12),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 q_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_007[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 4, 33, 12),
    CMD(CM_RJA3, 4, 33, 12),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 q_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_008[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 30, 1),
    CMD(CM_RJA3, 7, 31, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 q_cbca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_009[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 0),
    CMD(CM_CARE, 2, 2, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 10),
    CMD(CM_CARE, 2, 2, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3, 11 APPEAR 4 */
const u16 q_cbca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_010[28] = {
    CMD(CM_DJMP, 8200, 8192, 16388),
    CMD(CM_CAFR, 2, 2, 14),
    CMD(CM_CARE, 2, 2, 14),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_CAFR, 2, 2, 4),
    CMD(CM_CARE, 2, 2, 4),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 q_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_012[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 33, 1),
    CMD(CM_RJA3, 7, 34, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 13 APPEAR 6 */
const u16 q_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_013[12] = {
    CMD(CM_RJA4, 5, 36, 5),
    CMD(CM_WSET, 16384, 0, 10),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 14 APPEAR 7 */
const u16 q_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_014[12] = {
    CMD(CM_RJA4, 5, 37, 5),
    CMD(CM_WSET, 16384, 0, 8),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 15 APPEAR 8 */
const u16 q_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_015[12] = {
    CMD(CM_RJA4, 5, 38, 4),
    CMD(CM_WSET, 16384, 0, 6),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 16 SP APPEAR 1 */
const u16 q_cbca_016_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 q_cbca_016[16] = {
    CMD(CM_EXEC, 49, 59, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 17 SP APPEAR 2 */
const u16 q_cbca_017_head[4] = { HEAD(2, 0, 31, 0, 0, 0, 0) };
const u16 q_cbca_017[24] = {
    CMD(CM_EXEC, 49, 60, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 18 SP APPEAR 3 */
const u16 q_cbca_018_head[4] = { HEAD(2, 0, 31, 0, 0, 0, 0) };
const u16 q_cbca_018[16] = {
    CMD(CM_EXEC, 49, 61, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 19 SP APPEAR 4 */
const u16 q_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_019[12] = {
    CMD(CM_RJA2, 7, 24, 1),
    CMD(CM_RJA3, 7, 25, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 20 SP APPEAR 5 */
const u16 q_cbca_020_head[4] = { HEAD(2, 0, 32, 0, 0, 0, 0) };
const u16 q_cbca_020[16] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 29, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 21 SP APPEAR 6 */
const u16 q_cbca_021_head[4] = { HEAD(2, 0, 32, 0, 0, 0, 0) };
const u16 q_cbca_021[24] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 31, 0),
    CMD(CM_RJA4, 5, 67, 1),
    CMD(CM_RJA5, 5, 67, 2),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 22 SP APPEAR 7 */
const u16 q_cbca_022_head[4] = { HEAD(2, 0, 32, 0, 0, 0, 0) };
const u16 q_cbca_022[16] = {
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_IMGS, 0, 32, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 23 SP APPEAR 8 */
const u16 q_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_023[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 4, 8, 12),
    CMD(CM_RJA3, 4, 8, 12),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 24 ZANNEN 1, 25 ZANNEN 2, 26 ZANNEN 3, 27 ZANNEN 4 ... */
const u16 q_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_024[4] = {
    CMD(CM_RET, 0, 0, 0),
};

/* script: 37 WIN 6 */
const u16 q_cbca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_037[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 37, 1),
    CMD(CM_RJA3, 7, 38, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 38 WIN 7 */
const u16 q_cbca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_038[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 39, 1),
    CMD(CM_RJA3, 7, 40, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 39 WIN 8 */
const u16 q_cbca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_039[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 43, 1),
    CMD(CM_RJA3, 7, 44, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 40 SP WIN 1 */
const u16 q_cbca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_040[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 45, 1),
    CMD(CM_RJA3, 7, 46, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 41 SP WIN 2 */
const u16 q_cbca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_041[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 42 SP WIN 3 */
const u16 q_cbca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_042[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 49, 1),
    CMD(CM_RJA3, 7, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 43 SP WIN 4 */
const u16 q_cbca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_043[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 51, 1),
    CMD(CM_RJA3, 7, 52, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 44 SP WIN 5 */
const u16 q_cbca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 q_cbca_044[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 53, 1),
    CMD(CM_RJA3, 7, 54, 1),
    CMD(CM_RET, 0, 0, 0),
};

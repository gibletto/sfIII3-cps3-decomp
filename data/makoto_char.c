/*
 * MAKOTO_CHAR.C  Makoto's animation scripts and sprite part tables
 *
 * The animation scripts Makoto's moves run, one table per kind of script (nmca, dmca, btca, caca, cuca, atca, exca, saca, cbca),
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

extern const u16 makoto_nmca_000[], makoto_nmca_001[], makoto_nmca_002[], makoto_nmca_003[], makoto_nmca_004[], makoto_nmca_005[], makoto_nmca_006[], makoto_nmca_007[], makoto_nmca_008[], makoto_nmca_011[], makoto_nmca_012[], makoto_nmca_013[], makoto_nmca_014[], makoto_nmca_015[], makoto_nmca_016[], makoto_nmca_017[], makoto_nmca_020[], makoto_nmca_021[], makoto_nmca_022[], makoto_nmca_023[], makoto_nmca_024[], makoto_nmca_026[], makoto_nmca_027[], makoto_nmca_029[], makoto_nmca_030[], makoto_nmca_031[], makoto_nmca_032[], makoto_nmca_033[], makoto_nmca_038[], makoto_nmca_043[], makoto_nmca_044[], makoto_nmca_045[], makoto_nmca_046[], makoto_nmca_047[], makoto_nmca_048[], makoto_nmca_049[], makoto_nmca_050[];
extern const u16 makoto_nmca_000_head[];
extern const u16 makoto_nmca_001_head[];
extern const u16 makoto_nmca_002_head[];
extern const u16 makoto_nmca_003_head[];
extern const u16 makoto_nmca_004_head[];
extern const u16 makoto_nmca_005_head[];
extern const u16 makoto_nmca_006_head[];
extern const u16 makoto_nmca_007_head[];
extern const u16 makoto_nmca_008_head[];
extern const u16 makoto_nmca_011_head[];
extern const u16 makoto_nmca_012_head[];
extern const u16 makoto_nmca_013_head[];
extern const u16 makoto_nmca_014_head[];
extern const u16 makoto_nmca_015_head[];
extern const u16 makoto_nmca_016_head[];
extern const u16 makoto_nmca_017_head[];
extern const u16 makoto_nmca_020_head[];
extern const u16 makoto_nmca_021_head[];
extern const u16 makoto_nmca_022_head[];
extern const u16 makoto_nmca_023_head[];
extern const u16 makoto_nmca_024_head[];
extern const u16 makoto_nmca_026_head[];
extern const u16 makoto_nmca_027_head[];
extern const u16 makoto_nmca_029_head[];
extern const u16 makoto_nmca_030_head[];
extern const u16 makoto_nmca_031_head[];
extern const u16 makoto_nmca_032_head[];
extern const u16 makoto_nmca_033_head[];
extern const u16 makoto_nmca_038_head[];
extern const u16 makoto_nmca_043_head[];
extern const u16 makoto_nmca_044_head[];
extern const u16 makoto_nmca_045_head[];
extern const u16 makoto_nmca_046_head[];
extern const u16 makoto_nmca_047_head[];
extern const u16 makoto_nmca_048_head[];
extern const u16 makoto_nmca_049_head[];
extern const u16 makoto_nmca_050_head[];
extern const u16 makoto_dmca_000[], makoto_dmca_001[], makoto_dmca_002[], makoto_dmca_003[], makoto_dmca_008[], makoto_dmca_009[], makoto_dmca_010[], makoto_dmca_012[], makoto_dmca_013[], makoto_dmca_014[], makoto_dmca_015[], makoto_dmca_016[], makoto_dmca_018[], makoto_dmca_019[], makoto_dmca_022[], makoto_dmca_025[], makoto_dmca_024[], makoto_dmca_029[], makoto_dmca_030[], makoto_dmca_034[], makoto_dmca_036[], makoto_dmca_048[], makoto_dmca_050[], makoto_dmca_052[], makoto_dmca_060[], makoto_dmca_064[], makoto_dmca_067[], makoto_dmca_068[], makoto_dmca_070[], makoto_dmca_071[], makoto_dmca_072[], makoto_dmca_073[], makoto_dmca_074[], makoto_dmca_075[], makoto_dmca_076[], makoto_dmca_078[], makoto_dmca_079[], makoto_dmca_080[], makoto_dmca_082[], makoto_dmca_083[], makoto_dmca_084[], makoto_dmca_090[], makoto_dmca_096[], makoto_dmca_097[];
extern const u16 makoto_dmca_000_head[];
extern const u16 makoto_dmca_001_head[];
extern const u16 makoto_dmca_002_head[];
extern const u16 makoto_dmca_003_head[];
extern const u16 makoto_dmca_008_head[];
extern const u16 makoto_dmca_009_head[];
extern const u16 makoto_dmca_010_head[];
extern const u16 makoto_dmca_012_head[];
extern const u16 makoto_dmca_013_head[];
extern const u16 makoto_dmca_014_head[];
extern const u16 makoto_dmca_015_head[];
extern const u16 makoto_dmca_016_head[];
extern const u16 makoto_dmca_018_head[];
extern const u16 makoto_dmca_019_head[];
extern const u16 makoto_dmca_022_head[];
extern const u16 makoto_dmca_025_head[];
extern const u16 makoto_dmca_024_head[];
extern const u16 makoto_dmca_029_head[];
extern const u16 makoto_dmca_030_head[];
extern const u16 makoto_dmca_034_head[];
extern const u16 makoto_dmca_036_head[];
extern const u16 makoto_dmca_048_head[];
extern const u16 makoto_dmca_050_head[];
extern const u16 makoto_dmca_052_head[];
extern const u16 makoto_dmca_060_head[];
extern const u16 makoto_dmca_064_head[];
extern const u16 makoto_dmca_067_head[];
extern const u16 makoto_dmca_068_head[];
extern const u16 makoto_dmca_070_head[];
extern const u16 makoto_dmca_071_head[];
extern const u16 makoto_dmca_072_head[];
extern const u16 makoto_dmca_073_head[];
extern const u16 makoto_dmca_074_head[];
extern const u16 makoto_dmca_075_head[];
extern const u16 makoto_dmca_076_head[];
extern const u16 makoto_dmca_078_head[];
extern const u16 makoto_dmca_079_head[];
extern const u16 makoto_dmca_080_head[];
extern const u16 makoto_dmca_082_head[];
extern const u16 makoto_dmca_083_head[];
extern const u16 makoto_dmca_084_head[];
extern const u16 makoto_dmca_090_head[];
extern const u16 makoto_dmca_096_head[];
extern const u16 makoto_dmca_097_head[];
extern const u16 makoto_btca_000[], makoto_btca_001[], makoto_btca_002[], makoto_btca_003[], makoto_btca_004[], makoto_btca_005[], makoto_btca_006[], makoto_btca_007[], makoto_btca_008[], makoto_btca_010[], makoto_btca_011[], makoto_btca_012[], makoto_btca_013[], makoto_btca_014[], makoto_btca_015[], makoto_btca_016[], makoto_btca_017[], makoto_btca_018[], makoto_btca_019[], makoto_btca_020[], makoto_btca_021[], makoto_btca_022[], makoto_btca_023[], makoto_btca_024[], makoto_btca_025[], makoto_btca_026[], makoto_btca_027[], makoto_btca_028[], makoto_btca_029[], makoto_btca_030[], makoto_btca_031[], makoto_btca_032[], makoto_btca_033[], makoto_btca_034[];
extern const u16 makoto_btca_000_head[];
extern const u16 makoto_btca_001_head[];
extern const u16 makoto_btca_002_head[];
extern const u16 makoto_btca_003_head[];
extern const u16 makoto_btca_004_head[];
extern const u16 makoto_btca_005_head[];
extern const u16 makoto_btca_006_head[];
extern const u16 makoto_btca_007_head[];
extern const u16 makoto_btca_008_head[];
extern const u16 makoto_btca_010_head[];
extern const u16 makoto_btca_011_head[];
extern const u16 makoto_btca_012_head[];
extern const u16 makoto_btca_013_head[];
extern const u16 makoto_btca_014_head[];
extern const u16 makoto_btca_015_head[];
extern const u16 makoto_btca_016_head[];
extern const u16 makoto_btca_017_head[];
extern const u16 makoto_btca_018_head[];
extern const u16 makoto_btca_019_head[];
extern const u16 makoto_btca_020_head[];
extern const u16 makoto_btca_021_head[];
extern const u16 makoto_btca_022_head[];
extern const u16 makoto_btca_023_head[];
extern const u16 makoto_btca_024_head[];
extern const u16 makoto_btca_025_head[];
extern const u16 makoto_btca_026_head[];
extern const u16 makoto_btca_027_head[];
extern const u16 makoto_btca_028_head[];
extern const u16 makoto_btca_029_head[];
extern const u16 makoto_btca_030_head[];
extern const u16 makoto_btca_031_head[];
extern const u16 makoto_btca_032_head[];
extern const u16 makoto_btca_033_head[];
extern const u16 makoto_btca_034_head[];
extern const u16 makoto_caca_000[], makoto_caca_001[], makoto_caca_002[], makoto_caca_003[];
extern const u16 makoto_caca_000_head[];
extern const u16 makoto_caca_001_head[];
extern const u16 makoto_caca_002_head[];
extern const u16 makoto_caca_003_head[];
extern const u16 makoto_cuca_000[], makoto_cuca_001[], makoto_cuca_002[], makoto_cuca_003[], makoto_cuca_004[], makoto_cuca_005[], makoto_cuca_006[], makoto_cuca_007[], makoto_cuca_008[], makoto_cuca_009[], makoto_cuca_010[], makoto_cuca_011[], makoto_cuca_012[], makoto_cuca_013[], makoto_cuca_014[], makoto_cuca_015[], makoto_cuca_016[], makoto_cuca_017[], makoto_cuca_018[], makoto_cuca_019[], makoto_cuca_020[], makoto_cuca_021[], makoto_cuca_022[], makoto_cuca_023[], makoto_cuca_024[], makoto_cuca_025[], makoto_cuca_026[], makoto_cuca_027[], makoto_cuca_028[], makoto_cuca_029[], makoto_cuca_030[], makoto_cuca_031[], makoto_cuca_032[], makoto_cuca_033[], makoto_cuca_034[], makoto_cuca_035[], makoto_cuca_036[], makoto_cuca_037[], makoto_cuca_038[], makoto_cuca_039[], makoto_cuca_040[], makoto_cuca_041[], makoto_cuca_042[], makoto_cuca_043[], makoto_cuca_044[], makoto_cuca_045[], makoto_cuca_046[], makoto_cuca_047[], makoto_cuca_048[], makoto_cuca_049[], makoto_cuca_050[], makoto_cuca_051[], makoto_cuca_052[], makoto_cuca_053[], makoto_cuca_054[], makoto_cuca_055[], makoto_cuca_056[], makoto_cuca_057[], makoto_cuca_058[], makoto_cuca_059[], makoto_cuca_060[], makoto_cuca_061[], makoto_cuca_062[], makoto_cuca_063[], makoto_cuca_064[], makoto_cuca_065[], makoto_cuca_066[], makoto_cuca_067[];
extern const u16 makoto_cuca_000_head[];
extern const u16 makoto_cuca_001_head[];
extern const u16 makoto_cuca_002_head[];
extern const u16 makoto_cuca_003_head[];
extern const u16 makoto_cuca_004_head[];
extern const u16 makoto_cuca_005_head[];
extern const u16 makoto_cuca_006_head[];
extern const u16 makoto_cuca_007_head[];
extern const u16 makoto_cuca_008_head[];
extern const u16 makoto_cuca_009_head[];
extern const u16 makoto_cuca_010_head[];
extern const u16 makoto_cuca_011_head[];
extern const u16 makoto_cuca_012_head[];
extern const u16 makoto_cuca_013_head[];
extern const u16 makoto_cuca_014_head[];
extern const u16 makoto_cuca_015_head[];
extern const u16 makoto_cuca_016_head[];
extern const u16 makoto_cuca_017_head[];
extern const u16 makoto_cuca_018_head[];
extern const u16 makoto_cuca_019_head[];
extern const u16 makoto_cuca_020_head[];
extern const u16 makoto_cuca_021_head[];
extern const u16 makoto_cuca_022_head[];
extern const u16 makoto_cuca_023_head[];
extern const u16 makoto_cuca_024_head[];
extern const u16 makoto_cuca_025_head[];
extern const u16 makoto_cuca_026_head[];
extern const u16 makoto_cuca_027_head[];
extern const u16 makoto_cuca_028_head[];
extern const u16 makoto_cuca_029_head[];
extern const u16 makoto_cuca_030_head[];
extern const u16 makoto_cuca_031_head[];
extern const u16 makoto_cuca_032_head[];
extern const u16 makoto_cuca_033_head[];
extern const u16 makoto_cuca_034_head[];
extern const u16 makoto_cuca_035_head[];
extern const u16 makoto_cuca_036_head[];
extern const u16 makoto_cuca_037_head[];
extern const u16 makoto_cuca_038_head[];
extern const u16 makoto_cuca_039_head[];
extern const u16 makoto_cuca_040_head[];
extern const u16 makoto_cuca_041_head[];
extern const u16 makoto_cuca_042_head[];
extern const u16 makoto_cuca_043_head[];
extern const u16 makoto_cuca_044_head[];
extern const u16 makoto_cuca_045_head[];
extern const u16 makoto_cuca_046_head[];
extern const u16 makoto_cuca_047_head[];
extern const u16 makoto_cuca_048_head[];
extern const u16 makoto_cuca_049_head[];
extern const u16 makoto_cuca_050_head[];
extern const u16 makoto_cuca_051_head[];
extern const u16 makoto_cuca_052_head[];
extern const u16 makoto_cuca_053_head[];
extern const u16 makoto_cuca_054_head[];
extern const u16 makoto_cuca_055_head[];
extern const u16 makoto_cuca_056_head[];
extern const u16 makoto_cuca_057_head[];
extern const u16 makoto_cuca_058_head[];
extern const u16 makoto_cuca_059_head[];
extern const u16 makoto_cuca_060_head[];
extern const u16 makoto_cuca_061_head[];
extern const u16 makoto_cuca_062_head[];
extern const u16 makoto_cuca_063_head[];
extern const u16 makoto_cuca_064_head[];
extern const u16 makoto_cuca_065_head[];
extern const u16 makoto_cuca_066_head[];
extern const u16 makoto_cuca_067_head[];
extern const u16 makoto_atca_000[], makoto_atca_002[], makoto_atca_003[], makoto_atca_005[], makoto_atca_006[], makoto_atca_008[], makoto_atca_009[], makoto_atca_011[], makoto_atca_012[], makoto_atca_014[], makoto_atca_015[], makoto_atca_017[], makoto_atca_018[], makoto_atca_021[], makoto_atca_024[], makoto_atca_027[], makoto_atca_030[], makoto_atca_033[], makoto_atca_036[], makoto_atca_038[], makoto_atca_040[], makoto_atca_042[], makoto_atca_044[], makoto_atca_046[], makoto_atca_048[], makoto_atca_050[], makoto_atca_052[], makoto_atca_054[], makoto_atca_056[], makoto_atca_058[], makoto_atca_060[], makoto_atca_062[], makoto_atca_064[], makoto_atca_066[], makoto_atca_068[], makoto_atca_070[], makoto_atca_072[], makoto_atca_074[], makoto_atca_076[], makoto_atca_078[], makoto_atca_080[], makoto_atca_082[], makoto_atca_084[], makoto_atca_086[], makoto_atca_088[], makoto_atca_090[], makoto_atca_092[], makoto_atca_094[], makoto_atca_096[], makoto_atca_098[], makoto_atca_100[], makoto_atca_102[], makoto_atca_104[], makoto_atca_106[], makoto_atca_108[], makoto_atca_144[], makoto_atca_145[], makoto_atca_146[], makoto_atca_156[], makoto_atca_157[], makoto_atca_158[], makoto_atca_159[];
extern const u16 makoto_atca_000_head[];
extern const u16 makoto_atca_002_head[];
extern const u16 makoto_atca_003_head[];
extern const u16 makoto_atca_005_head[];
extern const u16 makoto_atca_006_head[];
extern const u16 makoto_atca_008_head[];
extern const u16 makoto_atca_009_head[];
extern const u16 makoto_atca_011_head[];
extern const u16 makoto_atca_012_head[];
extern const u16 makoto_atca_014_head[];
extern const u16 makoto_atca_015_head[];
extern const u16 makoto_atca_017_head[];
extern const u16 makoto_atca_018_head[];
extern const u16 makoto_atca_021_head[];
extern const u16 makoto_atca_024_head[];
extern const u16 makoto_atca_027_head[];
extern const u16 makoto_atca_030_head[];
extern const u16 makoto_atca_033_head[];
extern const u16 makoto_atca_036_head[];
extern const u16 makoto_atca_038_head[];
extern const u16 makoto_atca_040_head[];
extern const u16 makoto_atca_042_head[];
extern const u16 makoto_atca_044_head[];
extern const u16 makoto_atca_046_head[];
extern const u16 makoto_atca_048_head[];
extern const u16 makoto_atca_050_head[];
extern const u16 makoto_atca_052_head[];
extern const u16 makoto_atca_054_head[];
extern const u16 makoto_atca_056_head[];
extern const u16 makoto_atca_058_head[];
extern const u16 makoto_atca_060_head[];
extern const u16 makoto_atca_062_head[];
extern const u16 makoto_atca_064_head[];
extern const u16 makoto_atca_066_head[];
extern const u16 makoto_atca_068_head[];
extern const u16 makoto_atca_070_head[];
extern const u16 makoto_atca_072_head[];
extern const u16 makoto_atca_074_head[];
extern const u16 makoto_atca_076_head[];
extern const u16 makoto_atca_078_head[];
extern const u16 makoto_atca_080_head[];
extern const u16 makoto_atca_082_head[];
extern const u16 makoto_atca_084_head[];
extern const u16 makoto_atca_086_head[];
extern const u16 makoto_atca_088_head[];
extern const u16 makoto_atca_090_head[];
extern const u16 makoto_atca_092_head[];
extern const u16 makoto_atca_094_head[];
extern const u16 makoto_atca_096_head[];
extern const u16 makoto_atca_098_head[];
extern const u16 makoto_atca_100_head[];
extern const u16 makoto_atca_102_head[];
extern const u16 makoto_atca_104_head[];
extern const u16 makoto_atca_106_head[];
extern const u16 makoto_atca_108_head[];
extern const u16 makoto_atca_144_head[];
extern const u16 makoto_atca_145_head[];
extern const u16 makoto_atca_146_head[];
extern const u16 makoto_atca_156_head[];
extern const u16 makoto_atca_157_head[];
extern const u16 makoto_atca_158_head[];
extern const u16 makoto_atca_159_head[];
extern const u16 makoto_exca_000[], makoto_exca_001[], makoto_exca_003[], makoto_exca_004[], makoto_exca_005[], makoto_exca_006[], makoto_exca_007[], makoto_exca_008[], makoto_exca_009[], makoto_exca_010[], makoto_exca_011[], makoto_exca_013[], makoto_exca_014[], makoto_exca_015[], makoto_exca_016[], makoto_exca_017[], makoto_exca_018[], makoto_exca_022[], makoto_exca_023[], makoto_exca_025[], makoto_exca_026[], makoto_exca_027[], makoto_exca_028[], makoto_exca_029[], makoto_exca_030[], makoto_exca_032[], makoto_exca_033[], makoto_exca_034[], makoto_exca_035[], makoto_exca_037[], makoto_exca_038[], makoto_exca_039[], makoto_exca_040[], makoto_exca_041[], makoto_exca_042[], makoto_exca_043[], makoto_exca_044[], makoto_exca_045[], makoto_exca_046[], makoto_exca_047[], makoto_exca_048[], makoto_exca_049[], makoto_exca_050[], makoto_exca_053[], makoto_exca_054[], makoto_exca_055[], makoto_exca_056[], makoto_exca_057[], makoto_exca_058[], makoto_exca_059[], makoto_exca_060[], makoto_exca_061[], makoto_exca_062[], makoto_exca_063[], makoto_exca_064[], makoto_exca_065[], makoto_exca_066[], makoto_exca_067[], makoto_exca_068[], makoto_exca_069[], makoto_exca_070[], makoto_exca_071[], makoto_exca_072[], makoto_exca_073[], makoto_exca_074[], makoto_exca_075[], makoto_exca_076[], makoto_exca_077[], makoto_exca_078[], makoto_exca_079[];
extern const u16 makoto_exca_000_head[];
extern const u16 makoto_exca_001_head[];
extern const u16 makoto_exca_003_head[];
extern const u16 makoto_exca_004_head[];
extern const u16 makoto_exca_005_head[];
extern const u16 makoto_exca_006_head[];
extern const u16 makoto_exca_007_head[];
extern const u16 makoto_exca_008_head[];
extern const u16 makoto_exca_009_head[];
extern const u16 makoto_exca_010_head[];
extern const u16 makoto_exca_011_head[];
extern const u16 makoto_exca_013_head[];
extern const u16 makoto_exca_014_head[];
extern const u16 makoto_exca_015_head[];
extern const u16 makoto_exca_016_head[];
extern const u16 makoto_exca_017_head[];
extern const u16 makoto_exca_018_head[];
extern const u16 makoto_exca_022_head[];
extern const u16 makoto_exca_023_head[];
extern const u16 makoto_exca_025_head[];
extern const u16 makoto_exca_026_head[];
extern const u16 makoto_exca_027_head[];
extern const u16 makoto_exca_028_head[];
extern const u16 makoto_exca_029_head[];
extern const u16 makoto_exca_030_head[];
extern const u16 makoto_exca_032_head[];
extern const u16 makoto_exca_033_head[];
extern const u16 makoto_exca_034_head[];
extern const u16 makoto_exca_035_head[];
extern const u16 makoto_exca_037_head[];
extern const u16 makoto_exca_038_head[];
extern const u16 makoto_exca_039_head[];
extern const u16 makoto_exca_040_head[];
extern const u16 makoto_exca_041_head[];
extern const u16 makoto_exca_042_head[];
extern const u16 makoto_exca_043_head[];
extern const u16 makoto_exca_044_head[];
extern const u16 makoto_exca_045_head[];
extern const u16 makoto_exca_046_head[];
extern const u16 makoto_exca_047_head[];
extern const u16 makoto_exca_048_head[];
extern const u16 makoto_exca_049_head[];
extern const u16 makoto_exca_050_head[];
extern const u16 makoto_exca_053_head[];
extern const u16 makoto_exca_054_head[];
extern const u16 makoto_exca_055_head[];
extern const u16 makoto_exca_056_head[];
extern const u16 makoto_exca_057_head[];
extern const u16 makoto_exca_058_head[];
extern const u16 makoto_exca_059_head[];
extern const u16 makoto_exca_060_head[];
extern const u16 makoto_exca_061_head[];
extern const u16 makoto_exca_062_head[];
extern const u16 makoto_exca_063_head[];
extern const u16 makoto_exca_064_head[];
extern const u16 makoto_exca_065_head[];
extern const u16 makoto_exca_066_head[];
extern const u16 makoto_exca_067_head[];
extern const u16 makoto_exca_068_head[];
extern const u16 makoto_exca_069_head[];
extern const u16 makoto_exca_070_head[];
extern const u16 makoto_exca_071_head[];
extern const u16 makoto_exca_072_head[];
extern const u16 makoto_exca_073_head[];
extern const u16 makoto_exca_074_head[];
extern const u16 makoto_exca_075_head[];
extern const u16 makoto_exca_076_head[];
extern const u16 makoto_exca_077_head[];
extern const u16 makoto_exca_078_head[];
extern const u16 makoto_exca_079_head[];
extern const u16 makoto_saca_000[], makoto_saca_001[], makoto_saca_002[], makoto_saca_024[], makoto_saca_028[], makoto_saca_029[], makoto_saca_030[], makoto_saca_031[], makoto_saca_049[], makoto_saca_079[], makoto_saca_062[], makoto_saca_063[], makoto_saca_064[], makoto_saca_065[], makoto_saca_066[], makoto_saca_068[], makoto_saca_069[], makoto_saca_070[], makoto_saca_071[], makoto_saca_078[], makoto_saca_032[], makoto_saca_033[], makoto_saca_034[], makoto_saca_035[], makoto_saca_036[], makoto_saca_037[], makoto_saca_038[], makoto_saca_039[], makoto_saca_040[], makoto_saca_041[], makoto_saca_042[], makoto_saca_043[], makoto_saca_044[], makoto_saca_045[], makoto_saca_046[], makoto_saca_047[], makoto_saca_048[], makoto_saca_050[], makoto_saca_051[], makoto_saca_052[], makoto_saca_054[], makoto_saca_055[], makoto_saca_056[], makoto_saca_057[], makoto_saca_058[], makoto_saca_067[], makoto_saca_072[], makoto_saca_073[], makoto_saca_074[], makoto_saca_075[], makoto_saca_076[], makoto_saca_077[];
extern const u16 makoto_saca_000_head[];
extern const u16 makoto_saca_001_head[];
extern const u16 makoto_saca_002_head[];
extern const u16 makoto_saca_024_head[];
extern const u16 makoto_saca_028_head[];
extern const u16 makoto_saca_029_head[];
extern const u16 makoto_saca_030_head[];
extern const u16 makoto_saca_031_head[];
extern const u16 makoto_saca_049_head[];
extern const u16 makoto_saca_079_head[];
extern const u16 makoto_saca_062_head[];
extern const u16 makoto_saca_063_head[];
extern const u16 makoto_saca_064_head[];
extern const u16 makoto_saca_065_head[];
extern const u16 makoto_saca_066_head[];
extern const u16 makoto_saca_068_head[];
extern const u16 makoto_saca_069_head[];
extern const u16 makoto_saca_070_head[];
extern const u16 makoto_saca_071_head[];
extern const u16 makoto_saca_078_head[];
extern const u16 makoto_saca_032_head[];
extern const u16 makoto_saca_033_head[];
extern const u16 makoto_saca_034_head[];
extern const u16 makoto_saca_035_head[];
extern const u16 makoto_saca_036_head[];
extern const u16 makoto_saca_037_head[];
extern const u16 makoto_saca_038_head[];
extern const u16 makoto_saca_039_head[];
extern const u16 makoto_saca_040_head[];
extern const u16 makoto_saca_041_head[];
extern const u16 makoto_saca_042_head[];
extern const u16 makoto_saca_043_head[];
extern const u16 makoto_saca_044_head[];
extern const u16 makoto_saca_045_head[];
extern const u16 makoto_saca_046_head[];
extern const u16 makoto_saca_047_head[];
extern const u16 makoto_saca_048_head[];
extern const u16 makoto_saca_050_head[];
extern const u16 makoto_saca_051_head[];
extern const u16 makoto_saca_052_head[];
extern const u16 makoto_saca_054_head[];
extern const u16 makoto_saca_055_head[];
extern const u16 makoto_saca_056_head[];
extern const u16 makoto_saca_057_head[];
extern const u16 makoto_saca_058_head[];
extern const u16 makoto_saca_067_head[];
extern const u16 makoto_saca_072_head[];
extern const u16 makoto_saca_073_head[];
extern const u16 makoto_saca_074_head[];
extern const u16 makoto_saca_075_head[];
extern const u16 makoto_saca_076_head[];
extern const u16 makoto_saca_077_head[];
extern const u16 makoto_cbca_000[], makoto_cbca_001[], makoto_cbca_002[], makoto_cbca_003[], makoto_cbca_004[], makoto_cbca_005[], makoto_cbca_006[], makoto_cbca_007[], makoto_cbca_008[], makoto_cbca_009[], makoto_cbca_010[], makoto_cbca_011[], makoto_cbca_012[], makoto_cbca_013[], makoto_cbca_014[], makoto_cbca_015[], makoto_cbca_016[], makoto_cbca_017[], makoto_cbca_018[], makoto_cbca_019[], makoto_cbca_020[], makoto_cbca_021[], makoto_cbca_022[], makoto_cbca_023[], makoto_cbca_024[], makoto_cbca_025[], makoto_cbca_026[], makoto_cbca_027[], makoto_cbca_028[], makoto_cbca_029[];
extern const u16 makoto_cbca_000_head[];
extern const u16 makoto_cbca_001_head[];
extern const u16 makoto_cbca_002_head[];
extern const u16 makoto_cbca_003_head[];
extern const u16 makoto_cbca_004_head[];
extern const u16 makoto_cbca_005_head[];
extern const u16 makoto_cbca_006_head[];
extern const u16 makoto_cbca_007_head[];
extern const u16 makoto_cbca_008_head[];
extern const u16 makoto_cbca_009_head[];
extern const u16 makoto_cbca_010_head[];
extern const u16 makoto_cbca_011_head[];
extern const u16 makoto_cbca_012_head[];
extern const u16 makoto_cbca_013_head[];
extern const u16 makoto_cbca_014_head[];
extern const u16 makoto_cbca_015_head[];
extern const u16 makoto_cbca_016_head[];
extern const u16 makoto_cbca_017_head[];
extern const u16 makoto_cbca_018_head[];
extern const u16 makoto_cbca_019_head[];
extern const u16 makoto_cbca_020_head[];
extern const u16 makoto_cbca_021_head[];
extern const u16 makoto_cbca_022_head[];
extern const u16 makoto_cbca_023_head[];
extern const u16 makoto_cbca_024_head[];
extern const u16 makoto_cbca_025_head[];
extern const u16 makoto_cbca_026_head[];
extern const u16 makoto_cbca_027_head[];
extern const u16 makoto_cbca_028_head[];
extern const u16 makoto_cbca_029_head[];

/* normal scripts: 51 entries */
const u16* const makoto_nmca[52] = {
    makoto_nmca_000,  /* 0 KAMAE */
    makoto_nmca_001,  /* 1 HURIMUKI */
    makoto_nmca_002,  /* 2 FRONT WALK */
    makoto_nmca_003,  /* 3 BACK WALK */
    makoto_nmca_004,  /* 4 DASH HUMIKOMI */
    makoto_nmca_005,  /* 5 DASH TOBINOKI */
    makoto_nmca_006,  /* 6 KAGAMU */
    makoto_nmca_007,  /* 7 KAGAMI KAMAE */
    makoto_nmca_008,  /* 8 KAGAMI TURN */
    makoto_nmca_008,  /* 9 KAGAMI F WALK */
    makoto_nmca_008,  /* 10 KAGAMI B WALK */
    makoto_nmca_011,  /* 11 STAND UP */
    makoto_nmca_012,  /* 12 JUMP JUNBI */
    makoto_nmca_013,  /* 13 SP JUMP JUNBI */
    makoto_nmca_014,  /* 14 JUMP FRONT */
    makoto_nmca_015,  /* 15 JUMP VERTICAL */
    makoto_nmca_016,  /* 16 JUMP BACK */
    makoto_nmca_017,  /* 17 S JUMP FRONT */
    makoto_nmca_017,  /* 18 S JUMP V */
    makoto_nmca_017,  /* 19 S JUMP BACK */
    makoto_nmca_020,  /* 20 SP JUMP FRONT */
    makoto_nmca_021,  /* 21 SP JUMP V */
    makoto_nmca_022,  /* 22 SP JUMP BACK */
    makoto_nmca_023,  /* 23 WALK END */
    makoto_nmca_024,  /* 24 PARING HEAD */
    makoto_nmca_024,  /* 25 PARING UP */
    makoto_nmca_026,  /* 26 PARING DOWN */
    makoto_nmca_027,  /* 27 PARING AIR F */
    makoto_nmca_027,  /* 28 PARING AIR B */
    makoto_nmca_029,  /* 29 GUARD HEAD */
    makoto_nmca_030,  /* 30 GUARD UP */
    makoto_nmca_031,  /* 31 GUARD DOWN */
    makoto_nmca_032,  /* 32 GUARD AIR */
    makoto_nmca_033,  /* 33 no name */
    makoto_nmca_033,  /* 34 no name */
    makoto_nmca_033,  /* 35 no name */
    makoto_nmca_033,  /* 36 no name */
    makoto_nmca_033,  /* 37 no name */
    makoto_nmca_038,  /* 38 P BREAK ZUJOU */
    makoto_nmca_038,  /* 39 P BREAK UP */
    makoto_nmca_038,  /* 40 P BREAK DOWN */
    makoto_nmca_038,  /* 41 P BREAK AIR F */
    makoto_nmca_038,  /* 42 P BREAK AIR R */
    makoto_nmca_043,  /* 43 TUKAMIHAZUSI */
    makoto_nmca_044,  /* 44 TUKAMIHAZUSARE */
    makoto_nmca_045,  /* 45 TUKAMIHAZUSI */
    makoto_nmca_046,  /* 46 TUKAMIHAZUSARE */
    makoto_nmca_047,  /* 47 no name */
    makoto_nmca_048,  /* 48 no name */
    makoto_nmca_049,  /* 49 no name */
    makoto_nmca_050,  /* 50 no name */
    0
};

/* script: 0 KAMAE */
const u16 makoto_nmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_000[396] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 12, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 13, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 14, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 15, 1), 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 6), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x60D8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60D9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DD, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60DF, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60E7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60E8, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60E9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60EA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60EB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60EC, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60ED, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60EE, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 HURIMUKI */
const u16 makoto_nmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_001[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6020, 0, 167, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6021, 0, 167, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6022, 0, 167, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6023, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6024, 0, 168, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6025, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 FRONT WALK */
const u16 makoto_nmca_002_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_002[324] = {
    L4(4, 0, 0, 0, 0, 6, 0, 0x6030, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 7, 0, 0x6031, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 8, 0, 0x6032, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 9, 0, 0x6033, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 10, 0, 0x6034, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 11, 0, 0x6035, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 12, 0, 0x6036, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 13, 0, 0x6037, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 14, 0, 0x6038, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 15, 0, 0x6039, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 16, 0, 0x603A, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 17, 0, 0x603B, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 18, 0, 0x603C, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 19, 0, 0x603D, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 20, 0, 0x603E, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 21, 0, 0x603F, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 22, 0, 0x6040, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 23, 0, 0x6041, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 24, 0, 0x6042, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 25, 0, 0x6043, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 26, 0, 0x6030, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 27, 0, 0x6044, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 28, 0, 0x6045, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 29, 0, 0x6046, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 30, 0, 0x6047, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 31, 0, 0x6048, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 32, 0, 0x6049, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 33, 0, 0x604A, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 34, 0, 0x604B, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 35, 0, 0x604C, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 36, 0, 0x604D, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 37, 0, 0x604E, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 38, 0, 0x604F, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 39, 0, 0x6050, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 40, 0, 0x6051, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 41, 0, 0x6052, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 42, 0, 0x6040, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 43, 0, 0x6041, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 44, 0, 0x6042, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 45, 0, 0x6043, 0, 173, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 BACK WALK */
const u16 makoto_nmca_003_head[4] = { HEAD(4, 8, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_003[324] = {
    L4(4, 0, 0, 0, 0, 46, 0, 0x6030, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 85, 0, 0x6043, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 84, 0, 0x6042, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 83, 0, 0x6041, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 82, 0, 0x6040, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 81, 0, 0x6052, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 80, 0, 0x6051, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 79, 0, 0x6050, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 78, 0, 0x604F, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 77, 0, 0x604E, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 76, 0, 0x604D, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 75, 0, 0x604C, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 74, 0, 0x604B, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 73, 0, 0x604A, 0, 176, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 72, 0, 0x6049, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 71, 0, 0x6048, 0, 175, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 70, 0, 0x6047, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 69, 0, 0x6046, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 68, 0, 0x6045, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 67, 0, 0x6044, 0, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 66, 0, 0x6030, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 65, 0, 0x6043, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 64, 0, 0x6042, 0, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 63, 0, 0x6041, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 62, 0, 0x6040, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 61, 0, 0x603F, 0, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 60, 0, 0x603E, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 59, 0, 0x603D, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 58, 0, 0x603C, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 57, 0, 0x603B, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 56, 0, 0x603A, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 55, 0, 0x6039, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 54, 0, 0x6038, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 53, 0, 0x6037, 0, 172, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 52, 0, 0x6036, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 51, 0, 0x6035, 0, 171, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 50, 0, 0x6034, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 49, 0, 0x6033, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 48, 0, 0x6032, 0, 170, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 47, 0, 0x6031, 0, 170, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 DASH HUMIKOMI */
const u16 makoto_nmca_004_head[4] = { HEAD(4, 10, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_004[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6120, 0, 177, 0, 0, 0, 0, 0),
    L4(6, 1, 277, 0, 0, 0, 0, 0x6121, 0, 178, 0, 0, 0, 32, 1),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6122, 0, 179, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x6123, 0, 180, 0, 0, 1, 32, 2),
    L4(4, 2, 0, 0, 0, 0, 0, 0x6124, 0, 180, 0, 0, 1, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x6125, 0, 180, 0, 0, 1, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x6126, 0, 180, 0, 0, 1, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x6127, 0, 1, 0, 0, 1, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6128, 0, 1, 0, 0, 1, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6129, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6129, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 DASH TOBINOKI */
const u16 makoto_nmca_005_head[4] = { HEAD(4, 12, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_005[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x612A, 0, 181, 0, 0, 0, 32, 3),
    L4(2, 1, 277, 0, 0, 0, 0, 0x612B, 0, 182, 0, 0, 0, 32, 3),
    L4(3, 1, 0, 0, 0, 0, 0, 0x612C, 0, 183, 0, 0, 0, 32, 4),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6126, 0, 183, 0, 0, 0, 32, 5),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6127, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6128, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6129, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6129, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 KAGAMU */
const u16 makoto_nmca_006_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_006[76] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6060, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6061, 0, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6062, 0, 184, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 KAGAMI KAMAE */
const u16 makoto_nmca_007_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_007[140] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 19, 1), 0, 0, 0, 0,
    L4(90, 0, 0, 0, 0, 0, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 20, 1), 0, 0, 0, 0,
    L4(60, 0, 0, 0, 0, 0, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 21, 1), 0, 0, 0, 0,
    L4(60, 0, 0, 0, 0, 0, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 8, 22, 1), 0, 0, 0, 0,
    CMD(CM_IXBW, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 KAGAMI TURN, 9 KAGAMI F WALK, 10 KAGAMI B WALK */
const u16 makoto_nmca_008_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_008[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6090, 0, 185, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6091, 0, 185, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6092, 0, 186, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6093, 0, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6094, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 STAND UP */
const u16 makoto_nmca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_011[76] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6070, 0, 187, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 JUMP JUNBI */
const u16 makoto_nmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_012[28] = {
    L4(2, 1, 0, 0, 0, 0, 0, 0x6061, 0, 7, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6061, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6061, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 SP JUMP JUNBI */
const u16 makoto_nmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_013[20] = {
    L4(5, 0, 0, 0, 0, 0, 0, 0x6061, 0, 7, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6061, 0, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 JUMP FRONT */
const u16 makoto_nmca_014_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_014[172] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60B2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60B3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60B4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60B9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60BA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60BB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60BC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60BD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 JUMP VERTICAL */
const u16 makoto_nmca_015_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_015[172] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60A2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60A3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60A4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60A9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60AA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60AB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60AC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60AD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 JUMP BACK */
const u16 makoto_nmca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_016[172] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 281, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60C2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60C3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60C4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60C9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60CA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60CB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60CC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60CD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 S JUMP FRONT, 18 S JUMP V, 19 S JUMP BACK */
const u16 makoto_nmca_017_head[4] = { HEAD(2, 16, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_017[12] = {
    CMD(CM_JSR, 8, 3, 1),
    CMD(CM_JPSS, 0, 15, 8),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 SP JUMP FRONT */
const u16 makoto_nmca_020_head[4] = { HEAD(4, 26, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_020[188] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60B0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60B2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60B3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60B4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60B8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60B9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60BA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60BB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60BC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60BD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 SP JUMP V */
const u16 makoto_nmca_021_head[4] = { HEAD(4, 28, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_021[188] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60A0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60A2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60A3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60A4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60A8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60A9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60AA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60AB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60AC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60AD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 SP JUMP BACK */
const u16 makoto_nmca_022_head[4] = { HEAD(4, 30, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_022[188] = {
    CMD(CM_JSR, 8, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 282, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 18, 2),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C1, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C0, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 7, 0x60C2, 0, 188, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 10, 0x60C3, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60C4, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C5, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C6, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C7, 0, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 15, 0x60C8, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 14, 0x60C9, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 13, 0x60CA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 12, 0x60CB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 8, 0x60CC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x60CD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 WALK END */
const u16 makoto_nmca_023_head[4] = { HEAD(4, 6, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_023[36] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 191, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6075, 0, 191, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 PARING HEAD, 25 PARING UP */
const u16 makoto_nmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_024[92] = {
    L4(1, 134, 0, 0, 0, 0, 0, 0x6100, 0, 1, 0, 0, 0, 18, 6),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6101, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 456, 0, 0, 0, 0, 0x6102, 0, 1, 0, 0, 0, 6, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6103, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6104, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6105, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6106, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6107, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 PARING DOWN */
const u16 makoto_nmca_026_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_026[100] = {
    L4(1, 134, 0, 0, 0, 0, 0, 0x60F9, 0, 2, 0, 0, 0, 18, 6),
    L4(2, 0, 456, 0, 0, 0, 0, 0x60FA, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60FB, 0, 2, 0, 0, 0, 6, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60FC, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x60FD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60FE, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 PARING AIR F, 28 PARING AIR B */
const u16 makoto_nmca_027_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_027[260] = {
    L4(2, 135, 0, 2, 0, 0, 0, 0x6110, 0, 8, 0, 0, 0, 18, 6),
    L4(1, 0, 0, 2, 0, 0, 0, 0x6111, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 456, 2, 0, 0, 0, 0x6112, 0, 8, 0, 0, 0, 6, 2),
    L4(2, 0, 0, 2, 0, 0, 0, 0x6113, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 2, 0, 0, 0, 0x6114, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 2, 0, 0, 0, 0x6115, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 2, 0, 0, 0, 0x60AD, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 2, 0, 0, 0, 0x60AE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 2, 0, 0, 0, 0x60AF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x1800, 0x0000, 0x0000,
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 2, 0, 0, 0, 0x6110, 0, 8, 0, 0, 0, 18, 6),
    L4(2, 0, 0, 2, 0, 0, 0, 0x6111, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 456, 2, 0, 0, 0, 0x6112, 0, 8, 0, 0, 0, 6, 2),
    L4(1, 0, 0, 2, 0, 0, 0, 0x6113, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 2, 0, 0, 0, 0x6114, 0, 8, 0, 0, 0, 0, 0),
    L4(17, 0, 0, 2, 0, 0, 0, 0x6115, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 2, 0, 0, 0, 0x6114, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_AXJMP, 8192, 16389, 16393), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x60BD, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x60AD, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60AE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60AF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x60CD, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 GUARD HEAD */
const u16 makoto_nmca_029_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_029[92] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60D0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60D1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x60D2, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x60D3, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x60D4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60D1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GUARD UP */
const u16 makoto_nmca_030_head[4] = { HEAD(4, 2, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_030[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60D0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60E0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x60E1, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x60E2, 0, 1, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60E0, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 29, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GUARD DOWN */
const u16 makoto_nmca_031_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_031[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60F0, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60F1, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x60F2, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x60F3, 0, 2, 0, 0, 0, 0, 0),
    L4(12, 2, 0, 0, 0, 0, 0, 0x60F4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60F7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 GUARD AIR */
const u16 makoto_nmca_032_head[4] = { HEAD(4, 33, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_032[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name, 34 no name, 35 no name, 36 no name ... */
const u16 makoto_nmca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_033[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 P BREAK ZUJOU, 39 P BREAK UP, 40 P BREAK DOWN, 41 P BREAK AIR F ... */
const u16 makoto_nmca_038_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_038[12] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 TUKAMIHAZUSI */
const u16 makoto_nmca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_043[84] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(2, 132, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6130, 0, 1, 0, 0, 0, 25, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6131, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6132, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6133, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6134, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6135, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 TUKAMIHAZUSARE */
const u16 makoto_nmca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_044[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0xABF9, 0, 326, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0xABFA, 0, 327, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xABFB, 0, 327, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0xABFC, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0xABFD, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0xABFE, 0, 327, 0, 0, 0, 0, 0),
    L4(9, 64, 0, 0, 0, 0, 0, 0xABFE, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 TUKAMIHAZUSI */
const u16 makoto_nmca_045_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_045[100] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(2, 136, 0, 0, 0, 0, 0, 0x6110, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6111, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 0, 456, 0, 0, 0, 0, 0x6112, 0, 8, 0, 0, 0, 25, 2),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6113, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6114, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6115, 0, 8, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x60CD, 0, 190, 0, 0, 0, 0, 0),
    L4(1, 64, 0, 0, 0, 0, 0, 0x60CD, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 TUKAMIHAZUSARE */
const u16 makoto_nmca_046_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_046[92] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0,
    L4(4, 132, 0, 0, 0, 0, 0, 0x0C44, 0, 8, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0C45, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x0C46, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C47, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C48, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C49, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C4A, 0, 8, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C6B, 0, 8, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 makoto_nmca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_047[148] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x624A, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x624B, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x624C, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x624D, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x624E, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x624F, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6250, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6251, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6252, 0, 6, 0, 0, 0, 0, 0),
    L4(6, 0, 466, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 makoto_nmca_048_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_048[28] = {
    L4(4, 8, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 makoto_nmca_049_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_049[28] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6001, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 makoto_nmca_050_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_nmca_050[84] = {
    CMD(CM_JSR, 8, 11, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6130, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -4096, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6131, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6132, 0, 1, 0, 0, 0, 22, 24),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6133, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6134, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6135, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* damage scripts: 98 entries */
const u16* const makoto_dmca[99] = {
    makoto_dmca_000,  /* 0 GUARD HEAD */
    makoto_dmca_001,  /* 1 GUARD UP */
    makoto_dmca_002,  /* 2 GUARD DOWN */
    makoto_dmca_003,  /* 3 GUARD AIR */
    makoto_dmca_003,  /* 4 HUSHIN HEAD */
    makoto_dmca_003,  /* 5 HUSHIN UP */
    makoto_dmca_003,  /* 6 HUSHIN DOWN */
    makoto_dmca_003,  /* 7 HUSHIN AIR */
    makoto_dmca_008,  /* 8 FACE S */
    makoto_dmca_009,  /* 9 FACE M */
    makoto_dmca_010,  /* 10 FACE L */
    makoto_dmca_010,  /* 11 FACE SP */
    makoto_dmca_012,  /* 12 FOOK OKU S */
    makoto_dmca_013,  /* 13 FOOK OKU M */
    makoto_dmca_014,  /* 14 FOOK OKU L */
    makoto_dmca_015,  /* 15 FOOK OKU SP */
    makoto_dmca_016,  /* 16 FOOK TEMAE S */
    makoto_dmca_009,  /* 17 FOOK TEMAE M */
    makoto_dmca_018,  /* 18 FOOK TEMAE L */
    makoto_dmca_019,  /* 19 FOOK TEMAE SP */
    makoto_dmca_008,  /* 20 UPPER S */
    makoto_dmca_009,  /* 21 UPPER M */
    makoto_dmca_022,  /* 22 UPPER L */
    makoto_dmca_022,  /* 23 UPPER SP */
    makoto_dmca_024,  /* 24 NOUTEN S */
    makoto_dmca_025,  /* 25 NOUTEN M */
    makoto_dmca_025,  /* 26 NOUTEN L */
    makoto_dmca_025,  /* 27 NOUTEN SP */
    makoto_dmca_024,  /* 28 BODY BROW S */
    makoto_dmca_029,  /* 29 BODY BROW M */
    makoto_dmca_030,  /* 30 BODY BROW L */
    makoto_dmca_030,  /* 31 BODY BROW SP */
    makoto_dmca_024,  /* 32 BODY UPPER S */
    makoto_dmca_029,  /* 33 BODY UPPER M */
    makoto_dmca_034,  /* 34 BODY UPPER L */
    makoto_dmca_034,  /* 35 BODY UPPER SP */
    makoto_dmca_036,  /* 36 TATAKI S */
    makoto_dmca_036,  /* 37 TATAKI M */
    makoto_dmca_036,  /* 38 TATAKI L */
    makoto_dmca_036,  /* 39 TATAKI SP */
    makoto_dmca_036,  /* 40 TATAKI V. S */
    makoto_dmca_036,  /* 41 TATAKI V. M */
    makoto_dmca_036,  /* 42 TATAKI V. L */
    makoto_dmca_036,  /* 43 TATAKI V. SP */
    makoto_dmca_008,  /* 44 NOBASITA TE S */
    makoto_dmca_009,  /* 45 NOBASITA TE M */
    makoto_dmca_010,  /* 46 NOBASITA TE L */
    makoto_dmca_010,  /* 47 NOBASITA TE SP */
    makoto_dmca_048,  /* 48 KAGAMI S */
    makoto_dmca_048,  /* 49 KAGAMI M */
    makoto_dmca_050,  /* 50 KAGAMI L */
    makoto_dmca_050,  /* 51 KAGAMI SP */
    makoto_dmca_052,  /* 52 KGM TATAKI S */
    makoto_dmca_052,  /* 53 KGM TATAKI M */
    makoto_dmca_052,  /* 54 KGM TATAKI L */
    makoto_dmca_052,  /* 55 KGM TATAKI SP */
    makoto_dmca_052,  /* 56 KGM TTKI V.S */
    makoto_dmca_052,  /* 57 KGM TTKI V.M */
    makoto_dmca_052,  /* 58 KGM TTKI V.L */
    makoto_dmca_052,  /* 59 KGM TTKI V.SP */
    makoto_dmca_060,  /* 60 NEKOROBI S */
    makoto_dmca_060,  /* 61 NEKOROBI M */
    makoto_dmca_060,  /* 62 NEKOROBI L */
    makoto_dmca_060,  /* 63 NEKOROBI SP */
    makoto_dmca_064,  /* 64 OKIAGARI */
    makoto_dmca_064,  /* 65 OKIAGARI F */
    makoto_dmca_064,  /* 66 OKIAGARI B */
    makoto_dmca_067,  /* 67 LOSE NO STAND */
    makoto_dmca_068,  /* 68 LOSE SONABA */
    makoto_dmca_068,  /* 69 LOSE KAGAMI */
    makoto_dmca_070,  /* 70 PIYO */
    makoto_dmca_071,  /* 71 UKEMI MOVE F */
    makoto_dmca_072,  /* 72 UKEMI MOVE R */
    makoto_dmca_073,  /* 73 SHIMEOTASARE */
    makoto_dmca_074,  /* 74 TATI TOUKETU S */
    makoto_dmca_075,  /* 75 TATI TOUKETU M */
    makoto_dmca_076,  /* 76 TATI TOUKETU L */
    makoto_dmca_076,  /* 77 TATI TOUKETU P */
    makoto_dmca_078,  /* 78 KGM TOUKETU S */
    makoto_dmca_079,  /* 79 KGM TOUKETU M */
    makoto_dmca_080,  /* 80 KGM TOUKETU L */
    makoto_dmca_080,  /* 81 KGM TOUKETU P */
    makoto_dmca_082,  /* 82 TATI DENGEKI S */
    makoto_dmca_083,  /* 83 TATI DENGEKI M */
    makoto_dmca_084,  /* 84 TATI DENGEKI L */
    makoto_dmca_084,  /* 85 TATI DENGEKI P */
    makoto_dmca_082,  /* 86 KGM DENGEKI S */
    makoto_dmca_083,  /* 87 KGM DENGEKI M */
    makoto_dmca_084,  /* 88 KGM DENGEKI L */
    makoto_dmca_084,  /* 89 KGM DENGEKI P */
    makoto_dmca_090,  /* 90 OKIAGARI FRONT */
    makoto_dmca_090,  /* 91 OKIAGARI REAR */
    makoto_dmca_008,  /* 92 TATI MOE S */
    makoto_dmca_009,  /* 93 TATI MOE M */
    makoto_dmca_010,  /* 94 TATI MOE L */
    makoto_dmca_010,  /* 95 TATI MOE SP */
    makoto_dmca_096,  /* 96 no name */
    makoto_dmca_097,  /* 97 no name */
    0
};

/* script: 0 GUARD HEAD */
const u16 makoto_dmca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_000[92] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x60D4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60D5, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60D6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x60D4, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 134, 0, 0, 0, 0, 0, 0x60D4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60D1, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 GUARD UP */
const u16 makoto_dmca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_001[92] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60E4, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60E5, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 134, 0, 0, 0, 0, 0, 0x60E3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60E0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 GUARD DOWN */
const u16 makoto_dmca_002_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_002[100] = {
    L4(2, 133, 0, 0, 0, 0, 0, 0x60F4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60F5, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60F6, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x60F4, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 134, 0, 0, 0, 0, 0, 0x60F4, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x60F7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 GUARD AIR, 4 HUSHIN HEAD, 5 HUSHIN UP, 6 HUSHIN DOWN ... */
const u16 makoto_dmca_003_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_003[12] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 FACE S, 20 UPPER S, 44 NOBASITA TE S, 92 TATI MOE S */
const u16 makoto_dmca_008_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_008[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6140, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 135, 450, 0, 0, 0, 0, 0x6141, 0, 220, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6142, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6143, 0, 220, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6144, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6145, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6146, 0, 220, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 FACE M, 17 FOOK TEMAE M, 21 UPPER M, 45 NOBASITA TE M ... */
const u16 makoto_dmca_009_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_009[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6150, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 137, 450, 0, 0, 0, 0, 0x6151, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6152, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6153, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6154, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6155, 0, 221, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6156, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6145, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6146, 0, 220, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 FACE L, 11 FACE SP, 46 NOBASITA TE L, 47 NOBASITA TE SP ... */
const u16 makoto_dmca_010_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_010[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6160, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 139, 451, 0, 0, 0, 0, 0x6161, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6162, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6163, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6164, 0, 220, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6165, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6166, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6167, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6168, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6169, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x616A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FOOK OKU S */
const u16 makoto_dmca_012_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_012[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6160, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 133, 450, 0, 0, 0, 0, 0x6160, 0, 220, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6140, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 FOOK OKU M */
const u16 makoto_dmca_013_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_013[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6160, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 135, 450, 0, 0, 0, 0, 0x6160, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6161, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 4, -32767), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6143, 0, 220, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6140, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 FOOK OKU L */
const u16 makoto_dmca_014_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_014[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6160, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 136, 450, 0, 0, 0, 0, 0x6161, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6162, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6180, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6181, 0, 222, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6182, 0, 221, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6179, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 FOOK OKU SP */
const u16 makoto_dmca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_015[172] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6160, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 142, 450, 0, 0, 0, 0, 0x6161, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6162, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6180, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6181, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6182, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6183, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6184, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6185, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6186, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6187, 0, 222, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6188, 0, 222, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6179, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 FOOK TEMAE S */
const u16 makoto_dmca_016_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_016[28] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6150, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 133, 450, 0, 0, 0, 0, 0x6150, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 1, 12, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 FOOK TEMAE L */
const u16 makoto_dmca_018_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_018[68] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6150, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 136, 450, 0, 0, 0, 0, 0x6151, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6170, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6172, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6173, 0, 221, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6175, 0, 220, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    CMD(CM_JPSS, 1, 14, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 FOOK TEMAE SP */
const u16 makoto_dmca_019_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_019[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6150, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 141, 450, 0, 0, 0, 0, 0x6151, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6170, 0, 220, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6171, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6172, 0, 221, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6173, 0, 222, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6174, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6175, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6176, 0, 223, 0, 0, 0, 0, 0),
    L4(3, 10, 0, 0, 0, 0, 0, 0x6177, 0, 223, 0, 0, 0, 0, 0),
    L4(1, 10, 0, 0, 0, 0, 0, 0x6178, 0, 223, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    CMD(CM_JPSS, 1, 15, 14), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 UPPER L, 23 UPPER SP */
const u16 makoto_dmca_022_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_022[92] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x619B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 135, 451, 0, 0, 0, 0, 0x619C, 0, 216, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x619D, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 6, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6144, 0, 216, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6145, 0, 216, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6146, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 NOUTEN M, 26 NOUTEN L, 27 NOUTEN SP */
const u16 makoto_dmca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_025[108] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6190, 0, 224, 0, 0, 0, 0, 0),
    L4(2, 137, 450, 0, 0, 0, 0, 0x6191, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6192, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6193, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6194, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6195, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6196, 0, 226, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32766), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x6197, 0, 225, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6198, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6199, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x619A, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x619A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 NOUTEN S, 28 BODY BROW S, 32 BODY UPPER S */
const u16 makoto_dmca_024_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_024[84] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61B0, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 134, 450, 0, 0, 0, 0, 0x61B1, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61B2, 0, 224, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x61B3, 0, 224, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(2, 64, 0, 0, 0, 0, 0, 0x6146, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 BODY BROW M, 33 BODY UPPER M */
const u16 makoto_dmca_029_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_029[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61C0, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 136, 450, 0, 0, 0, 0, 0x61C1, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61C2, 0, 225, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x61C3, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61C4, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61C5, 0, 226, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x61C6, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6145, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6146, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x619A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 BODY BROW L, 31 BODY BROW SP */
const u16 makoto_dmca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_030[156] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61D0, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 139, 451, 0, 0, 0, 0, 0x61D1, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D2, 0, 225, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D3, 0, 226, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 13, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D4, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D5, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D6, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61D7, 0, 227, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x61D8, 0, 227, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x61D9, 0, 224, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 BODY UPPER L, 35 BODY UPPER SP */
const u16 makoto_dmca_034_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_034[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61A0, 0, 224, 0, 0, 0, 0, 0),
    L4(8, 135, 451, 0, 0, 0, 0, 0x61A6, 0, 224, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x619C, 0, 217, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 9, -32767), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x619D, 0, 218, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6144, 0, 217, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6145, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6146, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 TATAKI S, 37 TATAKI M, 38 TATAKI L, 39 TATAKI SP ... */
const u16 makoto_dmca_036_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_036[36] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6190, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 451, 0, 0, 0, 0, 0x6232, 0, 227, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 KAGAMI S, 49 KAGAMI M */
const u16 makoto_dmca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_048[100] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61E0, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 134, 450, 0, 0, 0, 0, 0x61E1, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61E2, 0, 229, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x61E3, 0, 230, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x61E4, 0, 229, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61E5, 0, 229, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 KAGAMI L, 51 KAGAMI SP */
const u16 makoto_dmca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_050[116] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61E6, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 135, 451, 0, 0, 0, 0, 0x61E7, 0, 229, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61E8, 0, 230, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61E9, 0, 231, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x61EA, 0, 229, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16398, 0, -32767), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x61EB, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61EC, 0, 228, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61E5, 0, 228, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 KGM TATAKI S, 53 KGM TATAKI M, 54 KGM TATAKI L, 55 KGM TATAKI SP ... */
const u16 makoto_dmca_052_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_052[36] = {
    CMD(CM_RJA, 7, 24, 1), 0, 0, 0, 0,
    L4(1, 132, 0, 0, 0, 0, 0, 0x61E6, 0, 228, 0, 0, 0, 0, 0),
    L4(250, 0, 451, 0, 0, 0, 0, 0x61E7, 0, 229, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 NEKOROBI S, 61 NEKOROBI M, 62 NEKOROBI L, 63 NEKOROBI SP */
const u16 makoto_dmca_060_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_060[124] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6214, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 2, 451, 0, 0, 0, 0, 0x6215, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6216, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x620C, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x620D, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x620E, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620F, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6210, 0, 10, 0, 0, 0, 0, 0),
    L4(4, 5, 0, 0, 0, 0, 0, 0x6211, 0, 10, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6212, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    L4(1, 0, 451, 0, 0, 0, 0, 0x6215, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(2, 2, 0, 0, 0, 0, 0, 0x6215, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 OKIAGARI, 65 OKIAGARI F, 66 OKIAGARI B */
const u16 makoto_dmca_064_head[4] = { HEAD(4, 38, 0, 0, 0, 12, 0) };
const u16 makoto_dmca_064[148] = {
    L4(12, 9, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 11, 0, 0, 0, 0, 0, 0x6280, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6281, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6282, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6283, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6284, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6285, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6286, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6287, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6288, 0, 4, 0, 0, 0, 31, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6071, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6072, 0, 0, 0, 0, 0, 22, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 96, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 LOSE NO STAND */
const u16 makoto_dmca_067_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_067[20] = {
    L4(8, 0, 0, 0, 0, 0, 0, 0x6213, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 LOSE SONABA, 69 LOSE KAGAMI */
const u16 makoto_dmca_068_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_068[236] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6140, 0, 328, 0, 0, 0, 32, 187),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6140, 0, 328, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6260, 0, 328, 0, 0, 0, 32, 188),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6261, 0, 328, 0, 0, 0, 32, 188),
    L4(6, 1, 0, 0, 0, 0, 0, 0x6262, 0, 328, 0, 0, 0, 32, 188),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6263, 0, 328, 0, 0, 0, 32, 189),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6264, 0, 328, 0, 0, 0, 32, 190),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6265, 0, 328, 0, 0, 0, 32, 191),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6266, 0, 328, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6267, 0, 328, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6268, 0, 328, 0, 0, 0, 32, 192),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6269, 0, 328, 0, 0, 0, 32, 193),
    L4(6, 0, 0, 0, 0, 0, 0, 0x626A, 0, 328, 0, 0, 0, 32, 194),
    L4(5, 0, 0, 0, 0, 0, 0, 0x626B, 0, 328, 0, 0, 0, 32, 194),
    L4(4, 0, 0, 0, 0, 0, 0, 0x626C, 0, 328, 0, 0, 0, 32, 194),
    L4(4, 0, 288, 0, 0, 0, 0, 0x6206, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6207, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6208, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6209, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620D, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6210, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6211, 0, 0, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6212, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 PIYO */
const u16 makoto_dmca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_070[196] = {
    CMD(CM_EXEC, 5, 0, 0), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x6240, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6241, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6242, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6243, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6244, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6248, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6249, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6243, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6244, 0, 6, 0, 0, 0, 0, 0),
    L4(11, 0, 0, 0, 0, 0, 0, 0x6245, 0, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6246, 0, 6, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6247, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_PJMP, 28, 16393, 8192), 0, 0, 0, 0,
    CMD(CM_PJMP, 16, -32760, 8192), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x6248, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6249, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6243, 0, 6, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6244, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 0, 0x6247, 0, 6, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 UKEMI MOVE F */
const u16 makoto_dmca_071_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_071[188] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6280, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6286, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, 5120, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 19, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 452, 0, 0, 0, 0, 0x6292, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6293, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6294, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6295, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6296, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6297, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6290, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6291, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6287, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6288, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 UKEMI MOVE R */
const u16 makoto_dmca_072_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_072[180] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6280, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6289, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_PA_X, 0, -11264, 0), 0, 0, 0, 0,
    CMD(CM_MXYT, 20, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 452, 0, 0, 0, 0, 0x6290, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6297, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6296, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6295, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6294, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6293, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6292, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 12, 0, 0, 0, 0, 0, 0x6291, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6287, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6288, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 0, 0, 0, 0, 22, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 SHIMEOTASARE */
const u16 makoto_dmca_073_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_073[188] = {
    L4(2, 0, 451, 0, 0, 0, 0, 0x619B, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6264, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6265, 0, 328, 0, 0, 0, 32, 191),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6266, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6267, 0, 328, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6268, 0, 328, 0, 0, 0, 32, 192),
    L4(12, 0, 0, 0, 0, 0, 0, 0x6269, 0, 328, 0, 0, 0, 32, 193),
    L4(3, 0, 0, 0, 0, 0, 0, 0x626A, 0, 328, 0, 0, 0, 32, 194),
    L4(3, 0, 0, 0, 0, 0, 0, 0x626B, 0, 0, 0, 0, 0, 32, 194),
    L4(3, 0, 0, 0, 0, 0, 0, 0x626C, 0, 0, 0, 0, 0, 32, 194),
    L4(3, 0, 289, 0, 0, 0, 0, 0x6234, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6216, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x620A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x620B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x620C, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x620D, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x620E, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620F, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 1, 0, 0, 0, 0, 0, 0x6210, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6211, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6212, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x6213, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 TATI TOUKETU S */
const u16 makoto_dmca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_074[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6140, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6140, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6075, 0, 220, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 TATI TOUKETU M */
const u16 makoto_dmca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_075[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6143, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6143, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 TATI TOUKETU L, 77 TATI TOUKETU P */
const u16 makoto_dmca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_076[44] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6161, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x6161, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 KGM TOUKETU S */
const u16 makoto_dmca_078_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_078[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61E0, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x61E0, 0, 220, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 KGM TOUKETU M */
const u16 makoto_dmca_079_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_079[36] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61E3, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x61E3, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 KGM TOUKETU L, 81 KGM TOUKETU P */
const u16 makoto_dmca_080_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_080[52] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x61EB, 0, 220, 0, 0, 0, 0, 0),
    L4(250, 131, 0, 0, 0, 0, 0, 0x61EB, 0, 221, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x60F8, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6095, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 TATI DENGEKI S, 86 KGM DENGEKI S */
const u16 makoto_dmca_082_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_082[60] = {
    L4(1, 135, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6299, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x629A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 8, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 83 TATI DENGEKI M, 87 KGM DENGEKI M */
const u16 makoto_dmca_083_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_083[60] = {
    L4(1, 135, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6299, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x629A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 9, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 TATI DENGEKI L, 85 TATI DENGEKI P, 88 KGM DENGEKI L, 89 KGM DENGEKI P */
const u16 makoto_dmca_084_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_084[60] = {
    L4(1, 135, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6299, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x629A, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 OKIAGARI FRONT, 91 OKIAGARI REAR */
const u16 makoto_dmca_090_head[4] = { HEAD(4, 38, 0, 0, 0, 1, 0) };
const u16 makoto_dmca_090[12] = {
    L4(250, 255, 0, 0, 0, 0, 0, 0x6001, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 no name */
const u16 makoto_dmca_096_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_096[44] = {
    L4(3, 2, 451, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 97 no name */
const u16 makoto_dmca_097_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_dmca_097[44] = {
    L4(3, 2, 451, 0, 0, 0, 0, 0x6213, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6213, 0, 11, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6213, 0, 11, 0, 0, 0, 0, 0),
    L4(40, 0, 0, 0, 0, 0, 0, 0x6213, 0, 11, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* knock-down scripts: 36 entries */
const u16* const makoto_btca[37] = {
    makoto_btca_000,  /* 0 AIR NORMAL */
    makoto_btca_001,  /* 1 ASIBARAI SIRI */
    makoto_btca_002,  /* 2 ASIB TUNNOMERI */
    makoto_btca_003,  /* 3 NOKEZORI */
    makoto_btca_004,  /* 4 KUNOJI */
    makoto_btca_005,  /* 5 KIRIMOMI */
    makoto_btca_006,  /* 6 UPPER */
    makoto_btca_007,  /* 7 BODY UPPER */
    makoto_btca_008,  /* 8 HARAYARARE */
    makoto_btca_003,  /* 9 TATAKI AIR */
    makoto_btca_010,  /* 10 TTKI V. AIR */
    makoto_btca_011,  /* 11 HUMI ASIB */
    makoto_btca_012,  /* 12 FACE */
    makoto_btca_013,  /* 13 ASIB SIRI LOSE */
    makoto_btca_014,  /* 14 ASIB TUN LOSE */
    makoto_btca_015,  /* 15 DENKI */
    makoto_btca_016,  /* 16 KUNOJI NOKE */
    makoto_btca_017,  /* 17 BODY UPPER SP */
    makoto_btca_018,  /* 18 HANEAGARI */
    makoto_btca_019,  /* 19 TOUKETSU A */
    makoto_btca_020,  /* 20 BODY SLAM */
    makoto_btca_021,  /* 21 IPPONZEOI */
    makoto_btca_022,  /* 22 TOMOE RYU */
    makoto_btca_023,  /* 23 MONKEY FLIP */
    makoto_btca_024,  /* 24 TOMOE ORO */
    makoto_btca_025,  /* 25 SNAKE FANG */
    makoto_btca_026,  /* 26 FLANKEN.S */
    makoto_btca_027,  /* 27 KISHINRIKI */
    makoto_btca_028,  /* 28 SPLASH.M */
    makoto_btca_029,  /* 29 HARAIGOSHI */
    makoto_btca_030,  /* 30 ALEX B.D */
    makoto_btca_031,  /* 31 GILL */
    makoto_btca_032,  /* 32 HANEKAERI HARA */
    makoto_btca_033,  /* 33 S HANEAGARI */
    makoto_btca_034,  /* 34 TATUMAKIZANKU */
    makoto_btca_027,  /* 35 no name */
    0
};

/* script: 0 AIR NORMAL */
const u16 makoto_btca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_000[68] = {
    CMD(CM_JSR, 8, 0, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x61A6, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_SSE, 450, 0, 0), 0, 0, 0, 0,
    CMD(CM_WCLT, 16398, 5, 16387), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x61A6, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 136, 0, 0, 0, 0, 0, 0x61D3, 0, 277, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 7, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ASIBARAI SIRI */
const u16 makoto_btca_001_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_001[44] = {
    CMD(CM_RJA, 7, 3, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6229, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 0, 0, 0x622A, 0, 279, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x622B, 0, 280, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ASIB TUNNOMERI */
const u16 makoto_btca_002_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_btca_002[36] = {
    CMD(CM_RJA, 7, 7, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6230, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6231, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 NOKEZORI, 9 TATAKI AIR */
const u16 makoto_btca_003_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_003[100] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 451, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 KUNOJI */
const u16 makoto_btca_004_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_004[60] = {
    CMD(CM_RJA, 7, 8, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6220, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 450, 0, 0, 0, 0, 0x6221, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6222, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6223, 0, 293, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6224, 0, 294, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 KIRIMOMI */
const u16 makoto_btca_005_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_005[92] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6270, 0, 295, 0, 0, 0, 0, 0),
    L4(2, 0, 451, 0, 0, 0, 0, 0x6271, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6272, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6273, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6274, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6275, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6276, 0, 296, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 6, 3, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 UPPER */
const u16 makoto_btca_006_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_006[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x619B, 0, 297, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 0, 0, 0x619C, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x619D, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 BODY UPPER */
const u16 makoto_btca_007_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_007[108] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x61A0, 0, 300, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 1, 0, 0x61A6, 0, 277, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 2, 0, 0x61A7, 0, 301, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 3, 0, 0x61A8, 0, 302, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 4, 0, 0x61A9, 0, 303, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 5, 0, 0x61AA, 0, 304, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61AB, 0, 305, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61AC, 0, 306, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61AD, 0, 307, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61AE, 0, 308, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61AF, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 HARAYARARE */
const u16 makoto_btca_008_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_008[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x61B1, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 451, 0, 0, 0, 0, 0x619D, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 TTKI V. AIR */
const u16 makoto_btca_010_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_010[52] = {
    CMD(CM_RJA, 7, 9, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6190, 0, 311, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 0, 0, 0x6191, 0, 312, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61AF, 0, 309, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6232, 0, 313, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 HUMI ASIB */
const u16 makoto_btca_011_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_btca_011[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6230, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6231, 0, 281, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 FACE */
const u16 makoto_btca_012_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_012[116] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6141, 0, 314, 0, 0, 0, 0, 0),
    L4(2, 0, 451, 0, 0, 0, 0, 0x619D, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 ASIB SIRI LOSE */
const u16 makoto_btca_013_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_013[12] = {
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 1, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 ASIB TUN LOSE */
const u16 makoto_btca_014_head[4] = { HEAD(2, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_014[12] = {
    CMD(CM_RJA, 7, 17, 1),
    CMD(CM_JMP, 6, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 DENKI */
const u16 makoto_btca_015_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_015[68] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(1, 136, 0, 0, 0, 0, 0, 0x6298, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6299, 0, 315, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6298, 0, 315, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x629A, 0, 315, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 8, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 KUNOJI NOKE */
const u16 makoto_btca_016_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_016[132] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6220, 0, 292, 0, 0, 0, 0, 0),
    L4(3, 0, 450, 0, 0, 0, 0, 0x6221, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6222, 0, 293, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6223, 0, 293, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 BODY UPPER SP */
const u16 makoto_btca_017_head[4] = { HEAD(6, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_017[148] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 131, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 451, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0, 12288, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 HANEAGARI */
const u16 makoto_btca_018_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_018[196] = {
    CMD(CM_RJA, 6, 18, 9), 0, 0, 0, 0,
    L4(2, 0, 450, 0, 0, 0, 0, 0x6228, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 4, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 4, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_SPS, 0, 0, 38), 0, 0, 0, 0,
    L4(3, 2, 285, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 TOUKETSU A */
const u16 makoto_btca_019_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_019[28] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x6140, 0, 316, 0, 0, 0, 0, 0),
    L4(250, 0, 450, 0, 0, 0, 0, 0x6140, 0, 316, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 BODY SLAM */
const u16 makoto_btca_020_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_020[20] = {
    L4(3, 0, 0, 0, 0, 0, 12, 0x622B, 0, 280, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6232, 0, 313, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 IPPONZEOI */
const u16 makoto_btca_021_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_021[52] = {
    L4(250, 0, 0, 0, 1, 0, 3, 0x6234, 0, 317, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 1, 60, 2), 0, 0, 0, 0,
    L4(250, 0, 0, 0, 0, 0, 3, 0x6205, 0, 318, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 TOMOE RYU */
const u16 makoto_btca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_022[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x619E, 0, 319, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x619F, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6232, 0, 313, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 MONKEY FLIP */
const u16 makoto_btca_023_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_btca_023[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x619E, 0, 319, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x619F, 0, 320, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6232, 0, 313, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 TOMOE ORO */
const u16 makoto_btca_024_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_btca_024[52] = {
    CMD(CM_RJA, 7, 5, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 8, 0x61AD, 0, 307, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x61AE, 0, 308, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x61AF, 0, 309, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x61AF, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 SNAKE FANG */
const u16 makoto_btca_025_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_025[52] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 10, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 10, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 10, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 FLANKEN.S */
const u16 makoto_btca_026_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_026[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6230, 0, 281, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6231, 0, 281, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6232, 0, 313, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KISHINRIKI, 35 no name */
const u16 makoto_btca_027_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_027[60] = {
    CMD(CM_RJA, 6, 27, 5), 0, 0, 0, 0,
    L4(10, 0, 0, 0, 1, 0, 15, 0x622A, 0, 322, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 15, 0x622B, 0, 323, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 15, 0x622B, 0, 323, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_FLIP, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 7, 78, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 SPLASH.M */
const u16 makoto_btca_028_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_028[68] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 HARAIGOSHI */
const u16 makoto_btca_029_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_029[60] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x61FA, 0, 321, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 6, 29, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ALEX B.D */
const u16 makoto_btca_030_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_030[60] = {
    L4(3, 0, 0, 0, 0, 0, 10, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 8, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 8, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 GILL */
const u16 makoto_btca_031_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_031[44] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6229, 0, 278, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 0, 8, 0x622A, 0, 279, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 8, 0x61AE, 0, 308, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61AF, 0, 309, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 HANEKAERI HARA */
const u16 makoto_btca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_032[36] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 285, 0, 0, 0, 0, 0x61B1, 0, 310, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x619D, 0, 299, 0, 0, 0, 24, 0),
    CMD(CM_JMP, 6, 8, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 S HANEAGARI */
const u16 makoto_btca_033_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_033[184] = {
    L4(250, 130, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 6, 33, 7), 0, 0, 0, 0,
    L4(2, 0, 450, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 2, 285, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 22, 38),
    L4(3, 1, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 6, 33, 7), 0, 0, 0, 0,
    L4(1, 0, 450, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 4), 0, 0, 0, 0,
};

/* script: 34 TATUMAKIZANKU */
const u16 makoto_btca_034_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_btca_034[124] = {
    CMD(CM_RJA, 7, 6, 1), 0, 0, 0, 0,
    L4(250, 131, 0, 0, 0, 0, 0, 0x619B, 0, 297, 0, 0, 0, 0, 0),
    L4(3, 0, 451, 0, 0, 0, 0, 0x619C, 0, 298, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x619D, 0, 299, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F0, 0, 282, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F1, 0, 283, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F2, 0, 284, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F3, 0, 285, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F4, 0, 286, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F5, 0, 287, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F6, 0, 288, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F7, 0, 289, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x61F8, 0, 290, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x61F9, 0, 291, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* catch scripts: 4 entries */
const u16* const makoto_caca[5] = {
    makoto_caca_000,  /* 0 CATCH 1 */
    makoto_caca_001,  /* 1 CATCH 2 */
    makoto_caca_002,  /* 2 CATCH 3 */
    makoto_caca_003,  /* 3 CATCH 4 */
    0
};

/* script: 0 CATCH 1 */
const u16 makoto_caca_000_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 makoto_caca_000[304] = {
    CMD(CM_NGDA, 1542, 48, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 264, 0, 0, 0, 0, 0xABF8, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xABF9, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6571, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6572, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6560, 0, 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6561, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6562, 0, 0, 0, 0, 0, 0, 0, 0, 168, 0, 0, 0),
    L6(3, 2, 451, 0, 0, 0, 0, 0x6563, -41, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0),
    L6(1, 3, 0, 0, 0, 0, 0, 0x6564, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 0, 0, 0x6565, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x6565, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6566, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6567, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6568, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x656A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6569, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 64, 0, 0, 0, 0, 0, 0x6072, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 CATCH 2 */
const u16 makoto_caca_001_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 makoto_caca_001[64] = {
    CMD(CM_NGDA, 1542, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0xABF8, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xABF9, 0, 0, 0, 0, 0, 0, 0, 0, 960, 338, 0, 0),
    L6(2, 6, 0, 0, 0, 93, 0, 0x65D5, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 350, 0, 0),
    CMD(CM_JMP, 2, 2, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 CATCH 3 */
const u16 makoto_caca_002_head[4] = { HEAD(6, 0, 20, 0, 0, 0, 0) };
const u16 makoto_caca_002[544] = {
    CMD(CM_NGDA, 1542, 36, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 264, 0, 0, 0, 0, 0xABF8, 0, 0, 0, 0, 0, 0, 0, 0, 936, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xABF9, 0, 0, 0, 0, 0, 0, 0, 0, 960, 338, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65D0, 0, 0, 0, 0, 0, 0, 0, 0, 984, 340, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x65D1, 0, 0, 0, 0, 0, 0, 0, 0, 1008, 342, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65D2, 0, 0, 0, 0, 0, 0, 0, 0, 1032, 344, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65D3, 0, 0, 0, 0, 0, 0, 0, 0, 1056, 346, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65D4, 0, 0, 0, 0, 0, 0, 0, 0, 1080, 348, 0, 0),
    L6(2, 0, 0, 0, 0, 93, 0, 0x65D5, 0, 0, 0, 0, 0, 0, 0, 0, 1104, 350, 0, 0),
    L6(4, 0, 0, 0, 0, 94, 0, 0x65D6, 0, 0, 0, 0, 0, 0, 0, 0, 1128, 352, 0, 0),
    L6(4, 0, 0, 0, 0, 95, 0, 0x65D7, 0, 0, 0, 0, 0, 0, 0, 0, 1152, 354, 0, 0),
    L6(2, 2, 453, 0, 0, 96, 0, 0x65D8, -53, 0, 0, 0, 0, 0, 0, 0, 1176, 356, 0, 0),
    L6(5, 3, 0, 0, 0, 97, 0, 0x65D9, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 358, 0, 0),
    L6(3, 0, 0, 0, 0, 98, 0, 0x65DA, 0, 0, 0, 0, 0, 0, 0, 0, 1224, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 99, 0, 0x65DB, 0, 0, 0, 0, 0, 0, 0, 0, 1248, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 100, 0, 0x65DC, 0, 0, 0, 0, 0, 0, 0, 0, 1272, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65DD, 0, 0, 0, 0, 0, 0, 0, 0, 1296, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65DE, 0, 0, 0, 0, 0, 0, 0, 0, 1320, 360, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65DF, 0, 0, 0, 0, 0, 0, 0, 0, 1344, 362, 0, 0),
    L6(3, 2, 471, 0, 0, 0, 0, 0x65E0, -54, 0, 0, 0, 0, 0, 0, 0, 1368, 364, 0, 0),
    L6(4, 3, 0, 0, 0, 0, 0, 0x65E1, 0, 0, 0, 0, 0, 0, 0, 0, 1392, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65E2, 0, 0, 0, 0, 0, 0, 0, 0, 1416, 0, 0, 0),
    L6(3, 0, 275, 0, 0, 0, 0, 0x65E3, 0, 0, 0, 0, 0, 1, 141, 0, 1440, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65E4, 0, 0, 0, 0, 0, 0, 0, 0, 1464, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65E5, 0, 0, 0, 0, 0, 0, 0, 0, 1488, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65E6, 0, 0, 0, 0, 0, 0, 0, 0, 1512, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65E7, 0, 0, 0, 0, 0, 0, 0, 0, 1536, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x65E8, 0, 0, 0, 0, 0, 0, 0, 0, 1560, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x65E9, 0, 0, 0, 0, 0, 0, 0, 0, 1584, 0, 0, 0),
    L6(2, 0, 474, 0, 0, 0, 0, 0x65EA, 0, 0, 0, 0, 0, 0, 0, 0, 1608, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x65EB, -55, 0, 0, 0, 0, 0, 0, 0, 1632, 0, 0, 0),
    L6(11, 3, 0, 0, 0, 0, 0, 0x65EC, 0, 0, 0, 0, 0, 30, 131, 0, 1656, 366, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x65ED, 0, 0, 0, 0, 0, 30, 132, 0, 1680, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x65EE, 0, 0, 0, 0, 0, 30, 133, 0, 1704, 0, 0, 0),
    L6(3, 0, 0, 1, 0, 0, 0, 0x65EF, 0, 0, 0, 0, 0, 0, 0, 0, 1728, 0, 0, 0),
    L6(7, 0, 0, 1, 0, 0, 0, 0x65F0, 0, 0, 0, 0, 0, 0, 0, 0, 1752, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x6288, 0, 0, 0, 0, 0, 0, 0, 0, 1776, 0, 0, 0),
    L6(2, 9, 0, 1, 0, 0, 0, 0x612A, 0, 0, 0, 0, 0, 0, 0, 0, 1800, 368, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x612B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 370, 0, 0),
    L6(4, 0, 0, 1, 0, 0, 0, 0x612C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x6126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 372, 0, 0),
    L6(2, 64, 0, 1, 0, 0, 0, 0x6127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x6128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 1, 0, 0, 0, 0x6129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 1, 0, 0, 0, 0x6129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 CATCH 4 */
const u16 makoto_caca_003_head[4] = { HEAD(6, 0, 24, 0, 0, 0, 0) };
const u16 makoto_caca_003[412] = {
    CMD(CM_NGDA, 0, 51, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x6571, 0, 0, 0, 0, 0, 0, 0, 256, 288, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6572, 0, 0, 0, 0, 0, 0, 0, 256, 312, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6573, 0, 0, 0, 0, 0, 0, 0, 256, 336, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6574, 0, 0, 0, 0, 0, 0, 0, 256, 360, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6575, 0, 0, 0, 0, 0, 0, 0, 256, 384, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6576, 0, 0, 0, 0, 0, 0, 0, 256, 408, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6577, 0, 0, 0, 0, 0, 0, 0, 256, 432, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6578, 0, 0, 0, 0, 0, 0, 0, 256, 456, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x6579, 0, 0, 0, 0, 0, 0, 0, 256, 480, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x657A, 0, 0, 0, 0, 0, 0, 0, 256, 504, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x657B, 0, 0, 0, 0, 0, 0, 0, 256, 528, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x657C, 0, 0, 0, 0, 0, 0, 0, 256, 552, 0, 0, 0),
    L6(15, 2, 0, 0, 0, 0, 0, 0x657D, -47, 0, 0, 0, 0, 0, 0, 256, 576, 0, 0, 0),
    L6(17, 3, 0, 0, 0, 0, 0, 0x657E, 0, 0, 0, 0, 0, 1, 138, 256, 600, 0, 0, 0),
    L6(11, 0, 0, 0, 0, 0, 0, 0x657F, 0, 0, 0, 0, 0, 0, 0, 256, 624, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6580, 0, 0, 0, 0, 0, 0, 0, 256, 648, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6581, 0, 0, 0, 0, 0, 0, 0, 256, 672, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6582, 0, 0, 0, 0, 0, 0, 0, 256, 696, 0, 0, 0),
    L6(5, 0, 452, 0, 0, 0, 0, 0x6583, 0, 0, 0, 0, 0, 0, 0, 256, 720, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6584, 0, 0, 0, 0, 0, 0, 0, 256, 744, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0x6585, 0, 0, 0, 0, 0, 0, 0, 256, 744, 0, 0, 0),
    L6(3, 9, 0, 0, 0, 0, 0, 0x6586, 0, 0, 0, 0, 0, 0, 0, 256, 768, 308, 0, 0),
    L6(2, 64, 0, 0, 0, 0, 0, 0x6586, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6504, 0, 0, 0, 0, 0, 0, 0, 256, 0, 286, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6078, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6079, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607A, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x607B, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607C, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607D, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 0, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* caught scripts: 68 entries */
const u16* const makoto_cuca[69] = {
    makoto_cuca_000,  /* 0 ALEX ZUTUKI */
    makoto_cuca_001,  /* 1 ALEX BODY S */
    makoto_cuca_002,  /* 2 ALEX BACK D */
    makoto_cuca_003,  /* 3 ALEX POWER B */
    makoto_cuca_004,  /* 4 ALEX SLEEPER */
    makoto_cuca_005,  /* 5 RYU SEOINAGE */
    makoto_cuca_006,  /* 6 IBUKI */
    makoto_cuca_007,  /* 7 DADLEY L B */
    makoto_cuca_008,  /* 8 IBUKI KUBIORI */
    makoto_cuca_009,  /* 9 NECRO S T */
    makoto_cuca_010,  /* 10 RYU TOMOENAGE */
    makoto_cuca_011,  /* 11 YUN HIZAGERI */
    makoto_cuca_012,  /* 12 ORO KUBISIME */
    makoto_cuca_013,  /* 13 NECRO G S */
    makoto_cuca_014,  /* 14 DUDDLEY D S */
    makoto_cuca_015,  /* 15 YUN MONKEY F */
    makoto_cuca_016,  /* 16 ORO TOMOENAGE */
    makoto_cuca_017,  /* 17 ORO NIOURIKI */
    makoto_cuca_018,  /* 18 ORO GIGOKU G */
    makoto_cuca_019,  /* 19 YUN */
    makoto_cuca_020,  /* 20 NECRO SNAKE F */
    makoto_cuca_021,  /* 21 NECRO F S */
    makoto_cuca_022,  /* 22 IBUKI HARAIG */
    makoto_cuca_023,  /* 23 GILL SPLASH M */
    makoto_cuca_024,  /* 24 KEN HIZAGERI */
    makoto_cuca_025,  /* 25 ORO KISINRIKI */
    makoto_cuca_026,  /* 26 SEAN TACKLE */
    makoto_cuca_027,  /* 27 ALEX HYPER B */
    makoto_cuca_028,  /* 28 NECRO SLAM D */
    makoto_cuca_029,  /* 29 ELENA ASINAGE */
    makoto_cuca_030,  /* 30 GILL IMPACT C */
    makoto_cuca_031,  /* 31 ALEX S H B */
    makoto_cuca_032,  /* 32 ALEX F N D */
    makoto_cuca_033,  /* 33 no name */
    makoto_cuca_034,  /* 34 IBUKI */
    makoto_cuca_035,  /* 35 IBUKI YOROI D */
    makoto_cuca_036,  /* 36 no name */
    makoto_cuca_037,  /* 37 MAWARIKOMI M F */
    makoto_cuca_038,  /* 38 HUGO BODY S */
    makoto_cuca_039,  /* 39 HUGO N G T */
    makoto_cuca_040,  /* 40 HUGO M S P */
    makoto_cuca_041,  /* 41 HUGO S D B B */
    makoto_cuca_042,  /* 42 no name */
    makoto_cuca_043,  /* 43 no name */
    makoto_cuca_044,  /* 44 no name */
    makoto_cuca_045,  /* 45 no name */
    makoto_cuca_046,  /* 46 no name */
    makoto_cuca_047,  /* 47 no name */
    makoto_cuca_048,  /* 48 no name */
    makoto_cuca_049,  /* 49 no name */
    makoto_cuca_050,  /* 50 no name */
    makoto_cuca_051,  /* 51 no name */
    makoto_cuca_052,  /* 52 no name */
    makoto_cuca_053,  /* 53 no name */
    makoto_cuca_054,  /* 54 no name */
    makoto_cuca_055,  /* 55 no name */
    makoto_cuca_056,  /* 56 no name */
    makoto_cuca_057,  /* 57 no name */
    makoto_cuca_058,  /* 58 no name */
    makoto_cuca_059,  /* 59 no name */
    makoto_cuca_060,  /* 60 no name */
    makoto_cuca_061,  /* 61 no name */
    makoto_cuca_062,  /* 62 no name */
    makoto_cuca_063,  /* 63 no name */
    makoto_cuca_064,  /* 64 no name */
    makoto_cuca_065,  /* 65 no name */
    makoto_cuca_066,  /* 66 no name */
    makoto_cuca_067,  /* 67 no name */
    0
};

/* script: 0 ALEX ZUTUKI */
const u16 makoto_cuca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_000[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    CMD(CM_RMJA, 3, 0, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6190),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_DUMMY, 0, 0, 0),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 ALEX BODY S */
const u16 makoto_cuca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_001[60] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6206),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 3, 0, 0, 0x619C),
    CMD(CM_RMJA, 3, 1, 12),
    L2(250, 9, 0, 0, 0, 0, 12, 0x622B),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 9, 1),
    CMD(CM_JMP, 6, 20, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 ALEX BACK D */
const u16 makoto_cuca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_002[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6226),
    CMD(CM_RMJA, 3, 2, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6228),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 ALEX POWER B */
const u16 makoto_cuca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_003[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x612C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6228),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61D3),
    CMD(CM_RMJA, 3, 3, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6228),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 ALEX SLEEPER */
const u16 makoto_cuca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_004[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61A0),
    CMD(CM_RMJA, 3, 4, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x619B),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 RYU SEOINAGE */
const u16 makoto_cuca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_005[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6277),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6268),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F8),
    CMD(CM_RMJA, 3, 5, 13),
    L2(250, 9, 0, 0, 0, 0, 3, 0x6234),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 6, 21, 2),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 IBUKI */
const u16 makoto_cuca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_006[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6000),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    CMD(CM_RMJA, 3, 6, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61D1),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 DADLEY L B */
const u16 makoto_cuca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_007[44] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    CMD(CM_RMJA, 3, 7, 8),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61A6),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 IBUKI KUBIORI */
const u16 makoto_cuca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_008[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6164),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    CMD(CM_RMJA, 3, 8, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 5, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 NECRO S T */
const u16 makoto_cuca_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_009[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6154),
    CMD(CM_RMJA, 3, 9, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6141),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 RYU TOMOENAGE */
const u16 makoto_cuca_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_010[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6268),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AB),
    CMD(CM_RMJA, 3, 10, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x619E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 YUN HIZAGERI */
const u16 makoto_cuca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_011[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    CMD(CM_RMJA, 3, 11, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6160),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 ORO KUBISIME */
const u16 makoto_cuca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_012[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6076),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6197),
    CMD(CM_RMJA, 3, 12, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x61D0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 12, 3),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 NECRO G S */
const u16 makoto_cuca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_013[104] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6205),
    CMD(CM_RMJA, 3, 13, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6206),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 DUDDLEY D S */
const u16 makoto_cuca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_014[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6171),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    CMD(CM_RMJA, 3, 14, 9),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6224),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 YUN MONKEY F */
const u16 makoto_cuca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_015[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AA),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6189),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 ORO TOMOENAGE */
const u16 makoto_cuca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_016[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AC),
    CMD(CM_RMJA, 3, 16, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61AD),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 ORO NIOURIKI */
const u16 makoto_cuca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_017[108] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6200),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FA),
    L2(250, 2, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    CMD(CM_RMJA, 3, 17, 24),
    L2(250, 9, 0, 0, 1, 0, 0, 0x61FC),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_RJA, 7, 5, 12),
    CMD(CM_JMP, 7, 5, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 ORO GIGOKU G */
const u16 makoto_cuca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_018[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6293),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 3, 0, 0, 0, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6215),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6216),
    CMD(CM_RMJA, 3, 18, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x620E),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 19 YUN */
const u16 makoto_cuca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_019[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6155),
    CMD(CM_RMJA, 3, 19, 23),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6155),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 10, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 20 NECRO SNAKE F */
const u16 makoto_cuca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_020[68] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x60DF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60E0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60E1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60E3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60E4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60E5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6151),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F3),
    CMD(CM_RMJA, 3, 20, 15),
    L2(250, 9, 0, 0, 1, 0, 0, 0x61F4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 NECRO F S */
const u16 makoto_cuca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_021[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    CMD(CM_RMJA, 3, 21, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6230),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 26, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 IBUKI HARAIG */
const u16 makoto_cuca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_022[56] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x6145),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6144),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F7),
    CMD(CM_RMJA, 3, 22, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x61FA),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 GILL SPLASH M */
const u16 makoto_cuca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_023[80] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x612C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6173),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6173),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(4, 0, 0, 0, 3, 0, 0, 0x6215),
    L2(4, 0, 0, 0, 3, 0, 0, 0x6216),
    CMD(CM_IXBW, 0, 0, 2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FC),
    CMD(CM_RMJA, 3, 23, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61FF),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KEN HIZAGERI */
const u16 makoto_cuca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_024[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    CMD(CM_RMJA, 3, 24, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61F1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 24, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 ORO KISINRIKI */
const u16 makoto_cuca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_025[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6200),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FA),
    L2(250, 2, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6230),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_RMJA, 3, 25, 26),
    L2(250, 9, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 SEAN TACKLE */
const u16 makoto_cuca_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_026[76] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6230),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6231),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6232),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6206),
    L2(250, 3, 0, 0, 1, 0, 0, 0x620A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620F),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6210),
    L2(250, 3, 0, 0, 1, 0, 0, 0x6216),
    CMD(CM_RMJA, 3, 26, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6215),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 ALEX HYPER B */
const u16 makoto_cuca_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_027[148] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6188),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6187),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6188),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6187),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6228),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6228),
    CMD(CM_RMJA, 3, 27, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6228),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 NECRO SLAM D */
const u16 makoto_cuca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_028[128] = {
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F5),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FF),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619E),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6189),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61AB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61AA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6230),
    CMD(CM_RMJA, 3, 28, 29),
    L2(250, 9, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 27, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ELENA ASINAGE */
const u16 makoto_cuca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_029[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6025),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6026),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6027),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6028),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6220),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6224),
    CMD(CM_RMJA, 3, 29, 11),
    L2(250, 9, 0, 0, 3, 0, 0, 0x619F),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 GILL IMPACT C */
const u16 makoto_cuca_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_030[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x612C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6270),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619C),
    L2(250, 0, 0, 2, 1, 0, 0, 0x6229),
    L2(250, 0, 0, 2, 1, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619C),
    CMD(CM_RMJA, 3, 30, 19),
    L2(250, 9, 0, 0, 1, 0, 0, 0x619C),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ALEX S H B */
const u16 makoto_cuca_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_031[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    CMD(CM_RMJA, 3, 31, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6140),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ALEX F N D */
const u16 makoto_cuca_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_032[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6232),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6215),
    CMD(CM_RMJA, 3, 32, 11),
    L2(250, 9, 0, 0, 1, 0, 0, 0x6215),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 1, 60, 12),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 makoto_cuca_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_033[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6227),
    CMD(CM_RMJA, 3, 33, 14),
    L2(250, 9, 0, 0, 0, 0, 10, 0x61F4),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 30, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 IBUKI */
const u16 makoto_cuca_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_034[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    CMD(CM_RMJA, 3, 34, 12),
    L2(250, 9, 0, 0, 0, 0, 0, 0x619D),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 IBUKI YOROI D */
const u16 makoto_cuca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_035[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    CMD(CM_RMJA, 3, 35, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61D1),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
};

/* script: 36 no name */
const u16 makoto_cuca_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_036[168] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x619A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6199),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6155),
    L2(250, 2, 0, 0, 0, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6180),
    L2(250, 2, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6206),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6209),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620B),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620D),
    L2(250, 2, 0, 0, 1, 0, 0, 0x6215),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620D),
    L2(250, 0, 0, 0, 1, 0, 0, 0x620E),
    CMD(CM_RMJA, 3, 36, 38),
    L2(250, 9, 0, 0, 1, 0, 0, 0x620C),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 1, 60, 6),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 MAWARIKOMI M F */
const u16 makoto_cuca_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_037[132] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6001),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6097),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6098),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6094),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60BD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60BC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60BB),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6102),
    L2(250, 0, 0, 0, 2, 0, 0, 0x60BE),
    L2(250, 0, 0, 0, 2, 0, 0, 0x60BF),
    CMD(CM_RMJA, 3, 15, 14),
    L2(250, 9, 0, 0, 3, 0, 0, 0x60C0),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 HUGO BODY S */
const u16 makoto_cuca_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_038[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x607C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6179),
    L2(250, 0, 0, 0, 1, 0, 0, 0x60C3),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6232),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6389),
    L2(250, 0, 0, 0, 3, 0, 0, 0x622B),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6215),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6215),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6215),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    CMD(CM_RMJA, 3, 38, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61AE),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 29, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 HUGO N G T */
const u16 makoto_cuca_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_039[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6200),
    CMD(CM_RMJA, 3, 39, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61F2),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 HUGO M S P */
const u16 makoto_cuca_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_040[152] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6130),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6131),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6133),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6134),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6155),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6172),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6135),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6132),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x626A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6278),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6203),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6234),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6234),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6206),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6209),
    CMD(CM_RMJA, 3, 40, 35),
    L2(250, 9, 0, 0, 0, 0, 0, 0x620A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 19),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 HUGO S D B B */
const u16 makoto_cuca_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_041[88] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x619E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AC),
    CMD(CM_RMJA, 3, 41, 19),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61F2),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 1, 60, 2),
    CMD(CM_JMP, 6, 3, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 no name */
const u16 makoto_cuca_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_042[48] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6165),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D1),
    CMD(CM_RMJA, 3, 42, 9),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6221),
    CMD(CM_MDAT, 1, 30, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 makoto_cuca_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_043[32] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6213),
    CMD(CM_RMJA, 3, 43, 5),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6213),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 96, 1),
    CMD(CM_JMP, 6, 21, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 makoto_cuca_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_044[216] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6130),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6131),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6133),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6134),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6155),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6154),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6172),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6135),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6132),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x626A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6278),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6203),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6234),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61AE),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6234),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6206),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6209),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620D),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620C),
    L2(250, 0, 0, 0, 3, 0, 0, 0x620A),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AE),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AD),
    L2(250, 0, 0, 0, 3, 0, 0, 0x619E),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61AC),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6227),
    CMD(CM_RMJA, 3, 44, 51),
    L2(250, 9, 0, 0, 0, 0, 0, 0x620A),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_FLIP, 0, 0, 0),
    CMD(CM_JMP, 6, 33, 19),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 no name */
const u16 makoto_cuca_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_045[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6194),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6197),
    CMD(CM_RMJA, 3, 45, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6197),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 26, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 makoto_cuca_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_046[84] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6170),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F3),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6203),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6136),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6203),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6136),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60E6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60EF),
    CMD(CM_RMJA, 3, 46, 18),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6205),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 1, 97, 1),
    CMD(CM_JMP, 6, 21, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 no name */
const u16 makoto_cuca_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_047[112] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6178),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6221),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6188),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6187),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6208),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6188),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6187),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 2, 0, 0, 0x6226),
    CMD(CM_RMJA, 3, 47, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6228),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 no name */
const u16 makoto_cuca_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_048[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6144),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6141),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D4),
    CMD(CM_RMJA, 3, 48, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6191),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 25, 1),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 73, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name */
const u16 makoto_cuca_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_049[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 1, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61AC),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FC),
    CMD(CM_RMJA, 3, 49, 15),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61FD),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name */
const u16 makoto_cuca_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_050[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6202),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6203),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6202),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F9),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F8),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6230),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6232),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6233),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6234),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6207),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6208),
    CMD(CM_RMJA, 3, 50, 20),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6209),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 3, 50, 23),
    CMD(CM_JMP, 6, 7, 11),
    CMD(CM_SCHX, 0, -1, 1),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 no name */
const u16 makoto_cuca_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_051[104] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6181),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6183),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 2, 0, 0, 0, 0, 0, 0x61C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6265),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6263),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A0),
    CMD(CM_RMJA, 3, 51, 24),
    L2(250, 9, 0, 0, 0, 0, 0, 0x619B),
    CMD(CM_MDAT, 1, 12, 1),
    CMD(CM_JMP, 1, 24, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 no name */
const u16 makoto_cuca_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_052[72] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6142),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6572),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6232),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6228),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6226),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6222),
    L2(250, 0, 0, 0, 3, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AB),
    CMD(CM_RMJA, 3, 52, 16),
    L2(250, 9, 0, 0, 0, 0, 0, 0x619E),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 22, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 makoto_cuca_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_053[116] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6165),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6164),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6202),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619E),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61FF),
    CMD(CM_RMJA, 3, 53, 26),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61FF),
    CMD(CM_MDAT, 1, 28, 1),
    CMD(CM_RJA, 7, 5, 8),
    CMD(CM_JMP, 6, 18, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 makoto_cuca_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_054[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6270),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6271),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6272),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6273),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6274),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6275),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6276),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    CMD(CM_RMJA, 3, 54, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61C1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 41, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 42, 1),
    CMD(CM_JMP, 6, 31, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 makoto_cuca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_055[92] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6169),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6167),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6166),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6165),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6164),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F5),
    L2(250, 0, 0, 0, 3, 0, 0, 0x61F7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6216),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    CMD(CM_RMJA, 3, 55, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61F4),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 25, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 no name */
const u16 makoto_cuca_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_056[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B0),
    L2(250, 2, 0, 0, 0, 0, 0, 0x6220),
    CMD(CM_RMJA, 3, 56, 10),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6223),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 5),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 no name */
const u16 makoto_cuca_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_057[68] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D2),
    CMD(CM_RMJA, 3, 57, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61D3),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 6, 1),
    CMD(CM_JMP, 6, 6, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 no name */
const u16 makoto_cuca_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_058[96] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6143),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x60C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6223),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61D2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6200),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6227),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6224),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    CMD(CM_RMJA, 3, 58, 21),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61F0),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 3, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 no name */
const u16 makoto_cuca_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_059[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6077),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6076),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6075),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6074),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6073),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6072),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6101),
    L2(250, 0, 0, 0, 0, 0, 0, 0x636B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6230),
    CMD(CM_RMJA, 3, 59, 14),
    L2(250, 9, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 no name */
const u16 makoto_cuca_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_060[36] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x616A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    CMD(CM_RMJA, 3, 60, 7),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6220),
    CMD(CM_MDAT, 1, 24, 2),
    CMD(CM_JMP, 1, 28, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 no name */
const u16 makoto_cuca_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_061[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6472),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6471),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6470),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6470),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6163),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6230),
    CMD(CM_RMJA, 3, 61, 12),
    L2(250, 9, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_MDAT, 1, 20, 2),
    CMD(CM_JMP, 6, 27, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 no name */
const u16 makoto_cuca_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_062[160] = {
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6151),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6170),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6171),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6174),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6175),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B1),
    CMD(CM_PA_X, 0, 0, 0),
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61B2),
    CMD(CM_PA_X, 0, 2048, 0),
    CMD(CM_PS_Y, 0, 0, 6),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61D1),
    CMD(CM_PA_X, 0, -2304, 0),
    CMD(CM_PS_Y, 0, 0, -8),
    L2(250, 0, 0, 0, 1, 0, 0, 0x622A),
    CMD(CM_PA_X, 0, -4352, 0),
    CMD(CM_PS_Y, 0, 0, 21),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FA),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FB),
    L2(250, 0, 0, 0, 1, 0, 0, 0x61FC),
    CMD(CM_RMJA, 3, 62, 38),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61FD),
    CMD(CM_MDAT, 1, 14, 2),
    CMD(CM_JMP, 7, 6, 7),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 no name */
const u16 makoto_cuca_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_063[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6140),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619B),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6220),
    CMD(CM_RMJA, 3, 63, 10),
    L2(250, 9, 450, 0, 0, 0, 0, 0x6221),
    CMD(CM_MDAT, 1, 19, 2),
    CMD(CM_RJA, 7, 8, 1),
    CMD(CM_JMP, 6, 4, 4),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 no name */
const u16 makoto_cuca_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_064[56] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6156),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6229),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61B2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6145),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6197),
    CMD(CM_RMJA, 3, 64, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x61D3),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_RJA, 7, 5, 1),
    CMD(CM_JMP, 6, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 no name */
const u16 makoto_cuca_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_065[64] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6160),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6162),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6180),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6181),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6182),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6182),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6182),
    L2(250, 0, 0, 0, 1, 0, 0, 0x6183),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61A6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61AA),
    CMD(CM_RMJA, 3, 65, 14),
    L2(250, 9, 0, 0, 0, 0, 0, 0x6189),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 23, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 no name */
const u16 makoto_cuca_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_066[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x6150),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6161),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619C),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61C2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6205),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6206),
    L2(250, 0, 0, 0, 0, 0, 0, 0x620A),
    CMD(CM_RMJA, 3, 66, 11),
    L2(250, 9, 0, 0, 0, 0, 0, 0x620A),
    CMD(CM_MDAT, 1, 27, 2),
    CMD(CM_JMP, 1, 60, 2),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 no name */
const u16 makoto_cuca_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cuca_067[60] = {
    CMD(CM_PS_Y, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6190),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6191),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6192),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6193),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6194),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6197),
    L2(250, 0, 0, 0, 0, 0, 0, 0x6151),
    L2(250, 0, 0, 0, 0, 0, 0, 0x619D),
    L2(250, 0, 0, 0, 0, 0, 0, 0x61F1),
    CMD(CM_RMJA, 3, 67, 13),
    L2(250, 9, 0, 0, 0, 0, 0, 0x622A),
    CMD(CM_MDAT, 1, 18, 2),
    CMD(CM_JMP, 6, 35, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* attack scripts: 160 entries */
const u16* const makoto_atca[161] = {
    makoto_atca_000,  /* 0 S PUNCH A */
    makoto_atca_000,  /* 1 S PUNCH B */
    makoto_atca_002,  /* 2 S PUNCH C */
    makoto_atca_003,  /* 3 M PUNCH A */
    makoto_atca_003,  /* 4 M PUNCH B */
    makoto_atca_005,  /* 5 M PUNCH C */
    makoto_atca_006,  /* 6 L PUNCH A */
    makoto_atca_006,  /* 7 L PUNCH B */
    makoto_atca_008,  /* 8 L PUNCH C */
    makoto_atca_009,  /* 9 S KICK A */
    makoto_atca_009,  /* 10 S KICK B */
    makoto_atca_011,  /* 11 S KICK C */
    makoto_atca_012,  /* 12 M KICK A */
    makoto_atca_012,  /* 13 M KICK B */
    makoto_atca_014,  /* 14 M KICK C */
    makoto_atca_015,  /* 15 L KICK A */
    makoto_atca_015,  /* 16 L KICK B */
    makoto_atca_017,  /* 17 L KICK C */
    makoto_atca_018,  /* 18 KAGAMI P A */
    makoto_atca_018,  /* 19 KAGAMI P B */
    makoto_atca_018,  /* 20 KAGAMI P C */
    makoto_atca_021,  /* 21 KAGAMI P A */
    makoto_atca_021,  /* 22 KAGAMI P B */
    makoto_atca_021,  /* 23 KAGAMI P C */
    makoto_atca_024,  /* 24 KAGAMI P A */
    makoto_atca_024,  /* 25 KAGAMI P B */
    makoto_atca_024,  /* 26 KAGAMI P C */
    makoto_atca_027,  /* 27 KAGAMI K A */
    makoto_atca_027,  /* 28 KAGAMI K B */
    makoto_atca_027,  /* 29 KAGAMI K C */
    makoto_atca_030,  /* 30 KAGAMI K A */
    makoto_atca_030,  /* 31 KAGAMI K B */
    makoto_atca_030,  /* 32 KAGAMI K C */
    makoto_atca_033,  /* 33 KAGAMI K A */
    makoto_atca_033,  /* 34 KAGAMI K B */
    makoto_atca_033,  /* 35 KAGAMI K C */
    makoto_atca_036,  /* 36 V JUMP P S A */
    makoto_atca_036,  /* 37 V JUMP P S B */
    makoto_atca_038,  /* 38 V JUMP P M A */
    makoto_atca_038,  /* 39 V JUMP P M B */
    makoto_atca_040,  /* 40 V JUMP P L A */
    makoto_atca_040,  /* 41 V JUMP P L B */
    makoto_atca_042,  /* 42 V JUMP K S A */
    makoto_atca_042,  /* 43 V JUMP K S B */
    makoto_atca_044,  /* 44 V JUMP K M A */
    makoto_atca_044,  /* 45 V JUMP K M B */
    makoto_atca_046,  /* 46 V JUMP K L A */
    makoto_atca_046,  /* 47 V JUMP K L B */
    makoto_atca_048,  /* 48 F JUMP P S A */
    makoto_atca_048,  /* 49 F JUMP P S B */
    makoto_atca_050,  /* 50 F JUMP P M A */
    makoto_atca_050,  /* 51 F JUMP P M B */
    makoto_atca_052,  /* 52 F JUMP P L A */
    makoto_atca_052,  /* 53 F JUMP P L B */
    makoto_atca_054,  /* 54 F JUMP K S A */
    makoto_atca_054,  /* 55 F JUMP K S B */
    makoto_atca_056,  /* 56 F JUMP K M A */
    makoto_atca_056,  /* 57 F JUMP K M B */
    makoto_atca_058,  /* 58 F JUMP K L A */
    makoto_atca_058,  /* 59 F JUMP K L B */
    makoto_atca_060,  /* 60 B JUMP P S A */
    makoto_atca_060,  /* 61 B JUMP P S B */
    makoto_atca_062,  /* 62 B JUMP P M A */
    makoto_atca_062,  /* 63 B JUMP P M B */
    makoto_atca_064,  /* 64 B JUMP P L A */
    makoto_atca_064,  /* 65 B JUMP P L B */
    makoto_atca_066,  /* 66 B JUMP K S A */
    makoto_atca_066,  /* 67 B JUMP K S B */
    makoto_atca_068,  /* 68 B JUMP K M A */
    makoto_atca_068,  /* 69 B JUMP K M B */
    makoto_atca_070,  /* 70 B JUMP K L A */
    makoto_atca_070,  /* 71 B JUMP K L B */
    makoto_atca_072,  /* 72 SP V JP S P A */
    makoto_atca_072,  /* 73 SP V JP S P B */
    makoto_atca_074,  /* 74 SP V JP M P A */
    makoto_atca_074,  /* 75 SP V JP M P B */
    makoto_atca_076,  /* 76 SP V JP L P A */
    makoto_atca_076,  /* 77 SP V JP L P B */
    makoto_atca_078,  /* 78 SP V JP S K A */
    makoto_atca_078,  /* 79 SP V JP S K B */
    makoto_atca_080,  /* 80 SP V JP M K A */
    makoto_atca_080,  /* 81 SP V JP M K B */
    makoto_atca_082,  /* 82 SP V JP L K A */
    makoto_atca_082,  /* 83 SP V JP L K B */
    makoto_atca_084,  /* 84 SP F JP S P A */
    makoto_atca_084,  /* 85 SP F JP S P B */
    makoto_atca_086,  /* 86 SP F JP M P A */
    makoto_atca_086,  /* 87 SP F JP M P B */
    makoto_atca_088,  /* 88 SP F JP L P A */
    makoto_atca_088,  /* 89 SP F JP L P B */
    makoto_atca_090,  /* 90 SP F JP S K A */
    makoto_atca_090,  /* 91 SP F JP S K B */
    makoto_atca_092,  /* 92 SP F JP M K A */
    makoto_atca_092,  /* 93 SP F JP M K B */
    makoto_atca_094,  /* 94 SP F JP L K A */
    makoto_atca_094,  /* 95 SP F JP L K B */
    makoto_atca_096,  /* 96 SP B JP S P A */
    makoto_atca_096,  /* 97 SP B JP S P B */
    makoto_atca_098,  /* 98 SP B JP M P A */
    makoto_atca_098,  /* 99 SP B JP M P B */
    makoto_atca_100,  /* 100 SP B JP L P A */
    makoto_atca_100,  /* 101 SP B JP L P B */
    makoto_atca_102,  /* 102 SP B JP S K A */
    makoto_atca_102,  /* 103 SP B JP S K B */
    makoto_atca_104,  /* 104 SP B JP M K A */
    makoto_atca_104,  /* 105 SP B JP M K B */
    makoto_atca_106,  /* 106 SP B JP L K A */
    makoto_atca_106,  /* 107 SP B JP L K B */
    makoto_atca_108,  /* 108 S V JP S P A */
    makoto_atca_108,  /* 109 S V JP S P B */
    makoto_atca_108,  /* 110 S V JP M P A */
    makoto_atca_108,  /* 111 S V JP M P B */
    makoto_atca_108,  /* 112 S V JP L P A */
    makoto_atca_108,  /* 113 S V JP L P B */
    makoto_atca_108,  /* 114 S V JP S K A */
    makoto_atca_108,  /* 115 S V JP S K B */
    makoto_atca_108,  /* 116 S V JP M K A */
    makoto_atca_108,  /* 117 S V JP M K B */
    makoto_atca_108,  /* 118 S V JP L K A */
    makoto_atca_108,  /* 119 S V JP L K B */
    makoto_atca_108,  /* 120 S F JP S P A */
    makoto_atca_108,  /* 121 S F JP S P B */
    makoto_atca_108,  /* 122 S F JP M P A */
    makoto_atca_108,  /* 123 S F JP M P B */
    makoto_atca_108,  /* 124 S F JP L P A */
    makoto_atca_108,  /* 125 S F JP L P B */
    makoto_atca_108,  /* 126 S F JP S K A */
    makoto_atca_108,  /* 127 S F JP S K B */
    makoto_atca_108,  /* 128 S F JP M K A */
    makoto_atca_108,  /* 129 S F JP M K B */
    makoto_atca_108,  /* 130 S F JP L K A */
    makoto_atca_108,  /* 131 S F JP L K B */
    makoto_atca_108,  /* 132 S B JP S P A */
    makoto_atca_108,  /* 133 S B JP S P B */
    makoto_atca_108,  /* 134 S B JP M P A */
    makoto_atca_108,  /* 135 S B JP M P B */
    makoto_atca_108,  /* 136 S B JP L P A */
    makoto_atca_108,  /* 137 S B JP L P B */
    makoto_atca_108,  /* 138 S B JP S K A */
    makoto_atca_108,  /* 139 S B JP S K B */
    makoto_atca_108,  /* 140 S B JP M K A */
    makoto_atca_108,  /* 141 S B JP M K B */
    makoto_atca_108,  /* 142 S B JP L K A */
    makoto_atca_108,  /* 143 S B JP L K B */
    makoto_atca_144,  /* 144 TUKAMIKAKARI A */
    makoto_atca_145,  /* 145 TUKAMIKAKARI B */
    makoto_atca_146,  /* 146 TUKAMIKAKARI C */
    makoto_atca_144,  /* 147 TUKAMIKAKARI D */
    makoto_atca_145,  /* 148 TUKAMIKAKARI E */
    makoto_atca_146,  /* 149 TUKAMIKAKARI F */
    makoto_atca_048,  /* 150 TUKAMI AIR A */
    makoto_atca_048,  /* 151 TUKAMI AIR B */
    makoto_atca_048,  /* 152 TUKAMI AIR C */
    makoto_atca_048,  /* 153 TUKAMI AIR D */
    makoto_atca_048,  /* 154 TUKAMI AIR E */
    makoto_atca_048,  /* 155 TUKAMI AIR F */
    makoto_atca_156,  /* 156 follow-up of L PUNCH C */
    makoto_atca_157,  /* 157 follow-up of L KICK C */
    makoto_atca_158,  /* 158 follow-up of S KICK A */
    makoto_atca_159,  /* 159 follow-up of M KICK C */
    0
};

/* script: 0 S PUNCH A, 1 S PUNCH B */
const u16 makoto_atca_000_head[4] = { HEAD(4, 0, 0, 8, 0, 1, 0) };
const u16 makoto_atca_000[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6340, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x6341, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6342, -1, 19, 0, 133, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6343, 0, 20, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6344, 0, 20, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6345, 0, 21, 405, 0, 24, 21, 1),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62A7, 0, 1, 405, 0, 8, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x62A8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 S PUNCH C */
const u16 makoto_atca_002_head[4] = { HEAD(4, 0, 0, 11, 0, 1, 0) };
const u16 makoto_atca_002[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A0, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x62A1, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A2, -2, 22, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A3, 0, 23, 0, 0, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A4, 0, 24, 404, 0, 24, 21, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A5, 0, 25, 404, 0, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62A6, 0, 25, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x62A7, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62A8, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62A9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 M PUNCH A, 4 M PUNCH B */
const u16 makoto_atca_003_head[4] = { HEAD(4, 0, 2, 11, 0, 1, 0) };
const u16 makoto_atca_003[124] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6350, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6351, 0, 112, 0, 0, 0, 0, 0),
    L4(3, 0, 472, 0, 0, 0, 0, 0x6352, 0, 112, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6353, 0, 113, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6354, -3, 114, 0, 136, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6355, 0, 115, 0, 136, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6356, 0, 115, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6357, 0, 115, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6358, 0, 116, 0, 0, 0, 21, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6359, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 M PUNCH C */
const u16 makoto_atca_005_head[4] = { HEAD(4, 0, 2, 8, 0, 1, 0) };
const u16 makoto_atca_005[156] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x62B0, 0, 1, 0, 0, 0, 32, 9),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62B1, 0, 1, 0, 0, 0, 32, 10),
    L4(4, 0, 0, 0, 0, 0, 0, 0x62B2, 0, 1, 0, 0, 0, 32, 11),
    L4(1, 1, 473, 0, 0, 0, 0, 0x62B3, 0, 1, 0, 0, 0, 32, 12),
    CMD(CM_EXEC, 30, 113, 0), 0, 0, 0, 0,
    L4(1, 0, 269, 0, 0, 0, 0, 0x62B3, 0, 1, 0, 0, 0, 30, 114),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62B4, -4, 26, 0, 137, 0, 32, 13),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62B5, 0, 27, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62B6, 0, 27, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 28, 0, 0), 0, 0, 0, 0,
    L4(2, 1, 0, 0, 0, 0, 0, 0x62B7, 0, 28, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62B8, 0, 1, 0, 0, 0, 32, 15),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62B9, 0, 1, 0, 0, 0, 32, 27),
    L4(2, 64, 0, 0, 0, 0, 0, 0x62BC, 0, 1, 0, 0, 0, 32, 28),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62BD, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62BE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 L PUNCH A, 7 L PUNCH B */
const u16 makoto_atca_006_head[4] = { HEAD(4, 0, 4, 11, 0, 1, 0) };
const u16 makoto_atca_006[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6360, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6361, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6362, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6363, 0, 29, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x6364, 0, 29, 0, 0, 0, 0, 0),
    L4(2, 0, 453, 0, 0, 0, 0, 0x6365, -5, 30, 0, 64, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6366, 0, 29, 0, 0, 96, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6367, 0, 1, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6368, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6369, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x636A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x636B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 L PUNCH C */
const u16 makoto_atca_008_head[4] = { HEAD(4, 0, 4, 12, 0, 3, 0) };
const u16 makoto_atca_008[212] = {
    CMD(CM_RMJA, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C0, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C1, 0, 32, 0, 0, 0, 32, 16),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62C2, 0, 33, 0, 0, 0, 32, 17),
    L4(4, 0, 0, 0, 0, 0, 0, 0x62C3, 0, 33, 0, 0, 0, 32, 18),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62C4, 0, 33, 0, 0, 0, 32, 19),
    L4(2, 0, 270, 0, 0, 0, 0, 0x62C5, 0, 33, 0, 0, 0, 32, 20),
    L4(2, 0, 473, 0, 0, 0, 0, 0x62C6, -6, 34, 2245, 141, 8, 32, 21),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C7, 0, 35, 2245, 141, 8, 0, 0),
    CMD(CM_RAPP2, 4, 156, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C8, 0, 35, 2245, 141, 8, 0, 0),
    CMD(CM_RAPP2, 4, 156, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x62C9, 0, 35, 2245, 64, 8, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62D5, 0, 35, 2245, 64, 8, 0, 0),
    CMD(CM_RAPP, 4, 156, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x62CA, 0, 36, 0, 0, 0, 0, 0),
    CMD(CM_ASXY, 44, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x62D1, 0, 1, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62D2, 0, 1, 0, 0, 0, 32, 23),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62D3, 0, 1, 0, 0, 0, 32, 24),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62D4, 0, 1, 0, 0, 0, 32, 25),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6126, 0, 1, 0, 0, 0, 32, 26),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6127, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6128, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6129, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6199, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 S KICK A, 10 S KICK B */
const u16 makoto_atca_009_head[4] = { HEAD(4, 0, 1, 8, 0, 1, 0) };
const u16 makoto_atca_009[132] = {
    CMD(CM_RMJA, 4, 158, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B0, 0, 37, 0, 0, 0, 32, 81),
    L4(2, 0, 268, 0, 0, 0, 0, 0x63D0, 0, 37, 0, 0, 0, 32, 82),
    L4(1, 0, 0, 0, 0, 0, 0, 0x63D1, -9, 38, 2693, 135, 104, 32, 83),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63D2, 0, 38, 2693, 135, 104, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63D3, 0, 40, 2693, 128, 104, 31, 1),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63D4, 0, 41, 2693, 0, 104, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63D5, 0, 41, 2693, 0, 8, 32, 84),
    CMD(CM_RMJA, 4, 158, 2), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x63D6, 0, 42, 2693, 0, 8, 32, 85),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63D7, 0, 37, 0, 0, 0, 32, 86),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6106, 0, 1, 0, 0, 0, 32, 87),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6107, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 S KICK C */
const u16 makoto_atca_011_head[4] = { HEAD(4, 0, 1, 14, 0, 1, 0) };
const u16 makoto_atca_011[132] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x63A0, 0, 1, 0, 0, 0, 32, 201),
    L4(3, 0, 268, 0, 0, 0, 0, 0x63A1, 0, 71, 0, 0, 0, 32, 202),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63A2, -21, 72, 0, 133, 0, 32, 203),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63A3, 0, 73, 0, 128, 0, 32, 203),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63A4, 0, 73, 0, 0, 0, 32, 203),
    CMD(CM_ASXY, 408, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x63A5, 0, 71, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63A6, 0, 71, 0, 0, 0, 32, 203),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63A7, 0, 71, 0, 0, 0, 32, 205),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63A8, 0, 1, 0, 0, 0, 32, 206),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63A9, 0, 1, 0, 0, 0, 32, 207),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63AA, 0, 1, 0, 0, 0, 32, 208),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63AB, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 12 M KICK A, 13 M KICK B */
const u16 makoto_atca_012_head[4] = { HEAD(4, 0, 3, 13, 0, 1, 0) };
const u16 makoto_atca_012[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x63B0, 0, 37, 0, 0, 0, 32, 88),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B1, 0, 37, 0, 0, 0, 32, 89),
    L4(2, 0, 269, 0, 0, 0, 0, 0x63B2, 0, 43, 0, 0, 0, 32, 90),
    L4(1, 0, 472, 0, 0, 0, 0, 0x63B3, -11, 44, 0, 134, 0, 32, 91),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B4, 0, 45, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B5, 0, 45, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B6, 0, 46, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B7, 0, 46, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63B8, 0, 43, 0, 0, 0, 32, 92),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63B9, 0, 42, 0, 0, 0, 32, 93),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63BA, 0, 37, 0, 0, 0, 32, 94),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63BB, 0, 1, 0, 0, 0, 32, 95),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63BC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6106, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6107, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 M KICK C */
const u16 makoto_atca_014_head[4] = { HEAD(4, 0, 3, 12, 0, 1, 0) };
const u16 makoto_atca_014[204] = {
    CMD(CM_RMJA, 4, 159, 1), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C0, 0, 1, 0, 0, 0, 32, 40),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63CE, 0, 1, 0, 0, 0, 32, 53),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C1, 0, 1, 0, 0, 0, 32, 41),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C2, 0, 1, 0, 0, 0, 32, 42),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C3, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C4, 0, 47, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C5, 0, 47, 0, 0, 0, 33, 0),
    L4(2, 0, 455, 0, 0, 0, 0, 0x63C6, 0, 47, 0, 0, 0, 32, 43),
    L4(1, 0, 269, 0, 0, 0, 0, 0x63C7, 0, 48, 0, 0, 0, 32, 44),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63C8, -12, 49, 3205, 128, 8, 32, 45),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63C9, 0, 50, 3205, 0, 8, 0, 0),
    CMD(CM_ASXY, 92, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 0, 0x63CA, 0, 51, 0, 0, 0, 21, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x63CB, 0, 51, 0, 0, 0, 32, 47),
    L4(4, 0, 0, 0, 0, 0, 0, 0x63CC, 0, 51, 0, 0, 0, 32, 48),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63CD, 0, 51, 0, 0, 0, 32, 49),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63EB, 0, 51, 0, 0, 0, 32, 50),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63EC, 0, 1, 0, 0, 0, 32, 51),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63ED, 0, 1, 0, 0, 0, 32, 52),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62BE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 L KICK A, 16 L KICK B */
const u16 makoto_atca_015_head[4] = { HEAD(4, 0, 5, 13, 0, 1, 0) };
const u16 makoto_atca_015[172] = {
    CMD(CM_RMJA, 4, 15, 1), 0, 0, 0, 0,
    CMD(CM_MDAT, 4, 4, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x63E0, 0, 12, 0, 0, 0, 32, 29),
    L4(2, 0, 452, 0, 0, 0, 0, 0x63E1, 0, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63E2, 14, 13, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 1, 0, 0, 0, 0x63E3, 0, 13, 0, 0, 0, 32, 30),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E4, 0, 13, 0, 0, 0, 32, 31),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E5, -13, 14, 0, 138, 0, 32, 32),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E6, 0, 15, 0, 128, 0, 32, 33),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E7, 0, 16, 0, 0, 0, 32, 34),
    CMD(CM_ASXY, 70, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E8, 0, 17, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 1, 0, 0, 0, 0x63E9, 0, 17, 0, 0, 0, 32, 36),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63EA, 0, 17, 0, 0, 0, 32, 37),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63EB, 0, 18, 0, 0, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63EC, 0, 1, 0, 0, 0, 32, 39),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63ED, 0, 1, 0, 0, 0, 32, 8),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62BE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 L KICK C */
const u16 makoto_atca_017_head[4] = { HEAD(4, 0, 5, 13, 0, 1, 0) };
const u16 makoto_atca_017[220] = {
    CMD(CM_RJA, 4, 157, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6490, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6491, 0, 74, 0, 0, 0, 32, 54),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6492, 0, 74, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6493, 0, 74, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6494, 0, 1, 0, 0, 0, 32, 55),
    L4(2, 20, 0, 0, 0, 0, 0, 0x6495, 0, 75, 0, 0, 0, 32, 56),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6496, 0, 75, 0, 0, 0, 32, 57),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6497, 0, 76, 0, 0, 0, 32, 58),
    CMD(CM_IFS2, 1024, 8194, 8192), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6498, 0, 76, 0, 0, 0, 32, 59),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6499, 0, 76, 0, 0, 0, 32, 60),
    L4(1, 0, 471, 0, 0, 0, 0, 0x649A, -22, 77, 0, 128, 0, 32, 61),
    L4(2, 0, 0, 1, 0, 0, 0, 0x649B, 0, 77, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x649C, 0, 78, 0, 0, 0, 32, 62),
    CMD(CM_ASXY, 126, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 1, 0, 0, 0, 0x649D, 0, 74, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x649E, 0, 74, 0, 0, 0, 32, 64),
    L4(3, 0, 0, 1, 0, 0, 0, 0x649F, 0, 1, 0, 0, 0, 32, 65),
    L4(3, 0, 0, 1, 0, 0, 0, 0x64A0, 0, 1, 0, 0, 0, 32, 66),
    L4(1, 0, 0, 1, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 32, 67),
    L4(2, 0, 0, 1, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 KAGAMI P A, 19 KAGAMI P B, 20 KAGAMI P C */
const u16 makoto_atca_018_head[4] = { HEAD(4, 32, 0, 11, 0, 1, 0) };
const u16 makoto_atca_018[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6440, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6441, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6441, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x6442, -16, 53, 0, 128, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6443, 0, 53, 18, 0, 104, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6444, 0, 54, 18, 0, 24, 21, 4),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6445, 0, 54, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6446, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6447, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 21 KAGAMI P A, 22 KAGAMI P B, 23 KAGAMI P C */
const u16 makoto_atca_021_head[4] = { HEAD(4, 32, 2, 12, 0, 1, 0) };
const u16 makoto_atca_021[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x6450, 0, 55, 0, 0, 0, 32, 110),
    L4(2, 0, 269, 0, 0, 0, 0, 0x6451, 0, 55, 0, 0, 0, 32, 111),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6452, 0, 55, 0, 0, 0, 32, 112),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6453, 0, 55, 0, 0, 0, 32, 113),
    L4(1, 0, 456, 0, 0, 0, 0, 0x6454, -17, 56, 0, 135, 96, 32, 114),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6455, 0, 56, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6456, 0, 56, 0, 0, 96, 0, 0),
    CMD(CM_ASXY, 230, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6457, 0, 55, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6458, 0, 55, 0, 0, 0, 32, 116),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6459, 0, 2, 0, 0, 0, 32, 117),
    L4(3, 0, 0, 0, 0, 0, 0, 0x645A, 0, 2, 0, 0, 0, 32, 118),
    L4(3, 64, 0, 0, 0, 0, 0, 0x645B, 0, 2, 0, 0, 0, 32, 119),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 KAGAMI P A, 25 KAGAMI P B, 26 KAGAMI P C */
const u16 makoto_atca_024_head[4] = { HEAD(4, 32, 4, 15, 0, 1, 0) };
const u16 makoto_atca_024[148] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6460, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 453, 0, 0, 0, 0, 0x6461, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6462, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6463, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6464, 0, 57, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6465, -18, 58, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6466, 0, 59, 0, 0, 0, 21, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6467, 0, 60, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6468, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6469, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x646A, 0, 61, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x646B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x646C, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x646D, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 KAGAMI K A, 28 KAGAMI K B, 29 KAGAMI K C */
const u16 makoto_atca_027_head[4] = { HEAD(4, 32, 1, 11, 0, 1, 0) };
const u16 makoto_atca_027[100] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x63F0, 0, 62, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 0, 0x63F1, 0, 62, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x63F2, -19, 63, 0, 133, 96, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63F3, 0, 63, 0, 128, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63F4, 0, 63, 0, 0, 96, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63F5, 0, 64, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63F6, 0, 64, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63F7, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63F8, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 KAGAMI K A, 31 KAGAMI K B, 32 KAGAMI K C */
const u16 makoto_atca_030_head[4] = { HEAD(4, 32, 3, 12, 0, 1, 0) };
const u16 makoto_atca_030[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6400, 0, 65, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6401, 0, 66, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 0, 0x6402, 0, 66, 0, 0, 0, 0, 0),
    L4(2, 0, 472, 0, 0, 0, 0, 0x6403, -20, 67, 0, 134, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6404, 0, 68, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6405, 0, 68, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6406, 0, 69, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6407, 0, 70, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6408, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 KAGAMI K A, 34 KAGAMI K B, 35 KAGAMI K C */
const u16 makoto_atca_033_head[4] = { HEAD(4, 32, 5, 10, 0, 1, 0) };
const u16 makoto_atca_033[140] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6410, 0, 79, 0, 0, 0, 32, 96),
    L4(3, 0, 452, 0, 0, 0, 0, 0x6411, 0, 80, 0, 0, 0, 32, 97),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6412, 0, 81, 0, 0, 0, 32, 98),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6413, 0, 82, 0, 0, 0, 32, 99),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6414, -23, 83, 0, 128, 0, 32, 100),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6415, 0, 119, 0, 0, 0, 32, 101),
    CMD(CM_ASXY, 204, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6416, 0, 84, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6417, 0, 85, 0, 0, 0, 32, 103),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6418, 0, 86, 0, 0, 0, 32, 104),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6419, 0, 79, 0, 0, 0, 32, 105),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 32, 106),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6066, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 V JUMP P S A, 37 V JUMP P S B */
const u16 makoto_atca_036_head[4] = { HEAD(4, 22, 0, 12, 0, 1, 0) };
const u16 makoto_atca_036[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 7, 0x6470, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x6471, 0, 87, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 7, 0x6472, 0, 87, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x6473, -24, 88, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 7, 0x6474, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 92, 7, 0x6475, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 7, 0x6476, 0, 88, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 7, 0x6477, 0, 88, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x6478, 0, 87, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 56, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 V JUMP P M A, 39 V JUMP P M B */
const u16 makoto_atca_038_head[4] = { HEAD(4, 22, 2, 12, 0, 1, 0) };
const u16 makoto_atca_038[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 7, 0x6470, 0, 89, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 7, 0x6471, 0, 89, 0, 0, 0, 0, 0),
    L4(4, 0, 269, 0, 0, 0, 7, 0x6472, 0, 89, 0, 0, 0, 0, 0),
    L4(2, 0, 456, 0, 0, 0, 7, 0x6473, -25, 90, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 7, 0x6474, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 7, 0x6475, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 7, 0x6476, 0, 90, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 92, 7, 0x6477, 0, 90, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6478, 0, 89, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 56, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 V JUMP P L A, 41 V JUMP P L B */
const u16 makoto_atca_040_head[4] = { HEAD(4, 22, 4, 12, 0, 1, 0) };
const u16 makoto_atca_040[108] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 6, 0x6480, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6481, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6482, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6483, 0, 91, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x6484, 0, 92, 0, 0, 0, 0, 0),
    L4(2, 0, 473, 0, 0, 0, 6, 0x6485, -26, 93, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6486, 0, 91, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x6487, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6488, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6489, 0, 91, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x648A, 0, 91, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 56, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 V JUMP K S A, 43 V JUMP K S B */
const u16 makoto_atca_042_head[4] = { HEAD(4, 22, 1, 7, 0, 1, 0) };
const u16 makoto_atca_042[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6370, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x6371, -27, 95, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x60AA, 0, 8, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 56, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 V JUMP K M A, 45 V JUMP K M B */
const u16 makoto_atca_044_head[4] = { HEAD(4, 22, 3, 13, 0, 1, 0) };
const u16 makoto_atca_044[116] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6390, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6391, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6392, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 472, 0, 0, 0, 5, 0x6393, -28, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6394, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 88, 5, 0x6395, 0, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 88, 5, 0x6396, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 88, 5, 0x6395, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6397, 0, 96, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6398, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 56, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 V JUMP K L A, 47 V JUMP K L B */
const u16 makoto_atca_046_head[4] = { HEAD(4, 22, 5, 14, 0, 1, 0) };
const u16 makoto_atca_046[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6380, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6381, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x6382, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 470, 0, 0, 0, 6, 0x6383, -29, 99, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6384, 0, 100, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6385, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6386, 0, 101, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6387, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6388, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6389, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AE, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AF, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 F JUMP P S A, 49 F JUMP P S B, 150 TUKAMI AIR A, 151 TUKAMI AIR B ... */
const u16 makoto_atca_048_head[4] = { HEAD(4, 20, 0, 10, 0, 1, 0) };
const u16 makoto_atca_048[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 6, 0x6423, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 6, 0x6424, -30, 104, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6425, 0, 104, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6426, 0, 104, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6427, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6428, 0, 104, 0, 138, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6426, 0, 104, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 6, 0x6427, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x60AB, 0, 103, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 57, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 F JUMP P M A, 51 F JUMP P M B */
const u16 makoto_atca_050_head[4] = { HEAD(4, 20, 2, 10, 0, 1, 0) };
const u16 makoto_atca_050[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6420, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6421, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6422, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 5, 0x6423, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 456, 0, 0, 0, 5, 0x6424, -31, 107, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6425, 0, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6426, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6427, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6428, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6426, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6427, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 90, 5, 0x6428, 0, 107, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x60AB, 0, 106, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 57, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 F JUMP P L A, 53 F JUMP P L B */
const u16 makoto_atca_052_head[4] = { HEAD(4, 20, 4, 11, 0, 1, 0) };
const u16 makoto_atca_052[180] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6430, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6431, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6432, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 5, 0x6433, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6434, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 455, 0, 0, 0, 5, 0x6435, -32, 109, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6436, 33, 110, 0, 149, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6437, 0, 111, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6438, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6439, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643A, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643B, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643C, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643D, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643E, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643F, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x642F, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 57, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x642D, 0, 111, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x642E, 0, 111, 0, 64, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 F JUMP K S A, 55 F JUMP K S B */
const u16 makoto_atca_054_head[4] = { HEAD(4, 20, 1, 7, 0, 1, 0) };
const u16 makoto_atca_054[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6370, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x6371, -27, 95, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 86, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x60BA, 0, 8, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 57, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 F JUMP K M A, 57 F JUMP K M B */
const u16 makoto_atca_056_head[4] = { HEAD(4, 20, 3, 14, 0, 1, 0) };
const u16 makoto_atca_056[116] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6390, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6391, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6392, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 472, 0, 0, 0, 5, 0x6393, -28, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6394, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 88, 5, 0x6395, 0, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 88, 5, 0x6396, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 88, 5, 0x6395, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6397, 0, 96, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6398, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 57, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 F JUMP K L A, 59 F JUMP K L B */
const u16 makoto_atca_058_head[4] = { HEAD(4, 20, 5, 15, 0, 1, 0) };
const u16 makoto_atca_058[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6380, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6381, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x6382, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 470, 0, 0, 0, 6, 0x6383, -29, 99, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6384, 0, 100, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6385, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6386, 0, 101, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6387, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6388, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6389, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 B JUMP P S A, 61 B JUMP P S B */
const u16 makoto_atca_060_head[4] = { HEAD(4, 24, 0, 9, 0, 1, 0) };
const u16 makoto_atca_060[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 6, 0x6423, 0, 103, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 6, 0x6424, -30, 104, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6425, 0, 104, 0, 135, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6426, 0, 104, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6427, 0, 104, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6428, 0, 104, 0, 138, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6426, 0, 104, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 6, 0x6427, 0, 104, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x60AB, 0, 103, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 58, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 B JUMP P M A, 63 B JUMP P M B */
const u16 makoto_atca_062_head[4] = { HEAD(4, 24, 2, 10, 0, 1, 0) };
const u16 makoto_atca_062[124] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(3, 0, 0, 0, 0, 0, 5, 0x6420, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6421, 0, 105, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x6422, 0, 105, 0, 0, 0, 0, 0),
    L4(2, 0, 269, 0, 0, 0, 5, 0x6423, 0, 106, 0, 0, 0, 0, 0),
    L4(3, 0, 456, 0, 0, 0, 5, 0x6424, -31, 107, 0, 136, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6425, 0, 107, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6426, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6427, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6428, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6426, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6427, 0, 107, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 91, 5, 0x6428, 0, 107, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x60AB, 0, 106, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 58, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 B JUMP P L A, 65 B JUMP P L B */
const u16 makoto_atca_064_head[4] = { HEAD(4, 24, 4, 10, 0, 1, 0) };
const u16 makoto_atca_064[180] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6430, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6431, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6432, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6433, 0, 108, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 5, 0x6434, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 455, 0, 0, 0, 5, 0x6435, -32, 109, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x6436, 33, 110, 0, 149, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6437, 0, 111, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6438, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6439, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643A, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643B, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643C, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643D, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643E, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x643F, 0, 111, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x642F, 0, 111, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 58, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 5, 0x642D, 0, 111, 0, 64, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 5, 0x642E, 0, 111, 0, 64, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 B JUMP K S A, 67 B JUMP K S B */
const u16 makoto_atca_066_head[4] = { HEAD(4, 24, 1, 7, 0, 1, 0) };
const u16 makoto_atca_066[92] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6370, 0, 94, 0, 0, 0, 0, 0),
    L4(2, 0, 268, 0, 0, 0, 6, 0x6371, -27, 95, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6372, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6373, 0, 95, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 87, 6, 0x6374, 0, 95, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x60CA, 0, 8, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 58, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 B JUMP K M A, 69 B JUMP K M B */
const u16 makoto_atca_068_head[4] = { HEAD(4, 24, 3, 13, 0, 1, 0) };
const u16 makoto_atca_068[116] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 5, 0x6390, 0, 96, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6391, 0, 96, 0, 0, 0, 0, 0),
    L4(3, 0, 269, 0, 0, 0, 5, 0x6392, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 472, 0, 0, 0, 5, 0x6393, -28, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6394, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 89, 5, 0x6395, 0, 97, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 89, 5, 0x6396, 0, 97, 0, 139, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 89, 5, 0x6395, 0, 97, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6399, 0, 96, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x639A, 0, 96, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 58, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 B JUMP K L A, 71 B JUMP K L B */
const u16 makoto_atca_070_head[4] = { HEAD(4, 24, 5, 14, 0, 1, 0) };
const u16 makoto_atca_070[132] = {
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 6, 0x6380, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 6, 0x6381, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6382, 0, 98, 0, 0, 0, 0, 0),
    L4(2, 0, 470, 0, 0, 0, 6, 0x6383, -29, 99, 0, 135, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6384, 0, 100, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6385, 0, 100, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6386, 0, 101, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6387, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x6388, 0, 102, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x6389, 0, 8, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638A, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x638B, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 9, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 9, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 SP V JP S P A, 73 SP V JP S P B */
const u16 makoto_atca_072_head[4] = { HEAD(2, 28, 0, 13, 0, 1, 0) };
const u16 makoto_atca_072[8] = {
    CMD(CM_JPSS, 4, 36, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 SP V JP M P A, 75 SP V JP M P B */
const u16 makoto_atca_074_head[4] = { HEAD(2, 28, 2, 13, 0, 1, 0) };
const u16 makoto_atca_074[8] = {
    CMD(CM_JPSS, 4, 38, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 SP V JP L P A, 77 SP V JP L P B */
const u16 makoto_atca_076_head[4] = { HEAD(2, 28, 4, 12, 0, 1, 0) };
const u16 makoto_atca_076[8] = {
    CMD(CM_JPSS, 4, 40, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 SP V JP S K A, 79 SP V JP S K B */
const u16 makoto_atca_078_head[4] = { HEAD(2, 28, 1, 7, 0, 1, 0) };
const u16 makoto_atca_078[8] = {
    CMD(CM_JPSS, 4, 42, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 80 SP V JP M K A, 81 SP V JP M K B */
const u16 makoto_atca_080_head[4] = { HEAD(2, 28, 3, 13, 0, 1, 0) };
const u16 makoto_atca_080[8] = {
    CMD(CM_JPSS, 4, 44, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 82 SP V JP L K A, 83 SP V JP L K B */
const u16 makoto_atca_082_head[4] = { HEAD(2, 28, 5, 15, 0, 1, 0) };
const u16 makoto_atca_082[8] = {
    CMD(CM_JPSS, 4, 46, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 84 SP F JP S P A, 85 SP F JP S P B */
const u16 makoto_atca_084_head[4] = { HEAD(2, 26, 0, 10, 0, 1, 0) };
const u16 makoto_atca_084[8] = {
    CMD(CM_JPSS, 4, 48, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 86 SP F JP M P A, 87 SP F JP M P B */
const u16 makoto_atca_086_head[4] = { HEAD(2, 26, 2, 10, 0, 2, 0) };
const u16 makoto_atca_086[8] = {
    CMD(CM_JPSS, 4, 50, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 88 SP F JP L P A, 89 SP F JP L P B */
const u16 makoto_atca_088_head[4] = { HEAD(2, 26, 4, 11, 0, 1, 0) };
const u16 makoto_atca_088[8] = {
    CMD(CM_JPSS, 4, 52, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 90 SP F JP S K A, 91 SP F JP S K B */
const u16 makoto_atca_090_head[4] = { HEAD(2, 26, 1, 7, 0, 1, 0) };
const u16 makoto_atca_090[8] = {
    CMD(CM_JPSS, 4, 54, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 92 SP F JP M K A, 93 SP F JP M K B */
const u16 makoto_atca_092_head[4] = { HEAD(2, 26, 3, 13, 0, 1, 0) };
const u16 makoto_atca_092[8] = {
    CMD(CM_JPSS, 4, 56, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 94 SP F JP L K A, 95 SP F JP L K B */
const u16 makoto_atca_094_head[4] = { HEAD(2, 26, 5, 15, 0, 1, 0) };
const u16 makoto_atca_094[8] = {
    CMD(CM_JPSS, 4, 58, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 96 SP B JP S P A, 97 SP B JP S P B */
const u16 makoto_atca_096_head[4] = { HEAD(2, 30, 0, 10, 0, 1, 0) };
const u16 makoto_atca_096[8] = {
    CMD(CM_JPSS, 4, 60, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 98 SP B JP M P A, 99 SP B JP M P B */
const u16 makoto_atca_098_head[4] = { HEAD(2, 30, 2, 10, 0, 2, 0) };
const u16 makoto_atca_098[8] = {
    CMD(CM_JPSS, 4, 62, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 100 SP B JP L P A, 101 SP B JP L P B */
const u16 makoto_atca_100_head[4] = { HEAD(2, 30, 4, 11, 0, 1, 0) };
const u16 makoto_atca_100[8] = {
    CMD(CM_JPSS, 4, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 102 SP B JP S K A, 103 SP B JP S K B */
const u16 makoto_atca_102_head[4] = { HEAD(2, 30, 1, 7, 0, 1, 0) };
const u16 makoto_atca_102[8] = {
    CMD(CM_JPSS, 4, 66, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 104 SP B JP M K A, 105 SP B JP M K B */
const u16 makoto_atca_104_head[4] = { HEAD(2, 30, 3, 13, 0, 1, 0) };
const u16 makoto_atca_104[8] = {
    CMD(CM_JPSS, 4, 68, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 106 SP B JP L K A, 107 SP B JP L K B */
const u16 makoto_atca_106_head[4] = { HEAD(2, 30, 5, 15, 0, 1, 0) };
const u16 makoto_atca_106[8] = {
    CMD(CM_JPSS, 4, 70, 1),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 108 S V JP S P A, 109 S V JP S P B, 110 S V JP M P A, 111 S V JP M P B ... */
const u16 makoto_atca_108_head[4] = { HEAD(6, 16, 0, 0, 0, 0, 0) };
const u16 makoto_atca_108[304] = {
    CMD(CM_JSR, 8, 38, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0x0E65, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0x0E66, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E67, -37, 145, 0, 135, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E68, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E69, 0, 145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E6A, 0, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E6B, 0, 11, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x0E6C, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0C56, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x0C57, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0),
    L6(250, 0, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
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

/* script: 144 TUKAMIKAKARI A, 147 TUKAMIKAKARI D */
const u16 makoto_atca_144_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_atca_144[156] = {
    CMD(CM_CAFR, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 0), 0, 0, 0, 0,
    CMD(CM_CCFL, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6350, 0, 266, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6350, -40, 135, 0, 0, 0, 0, 0),
    L4(3, 0, 268, 0, 0, 0, 0, 0xABF8, 0, 325, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xABF9, 0, 326, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0xABFA, 0, 327, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xABFB, 0, 327, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0xABFC, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0xABFC, 0, 327, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 145 TUKAMIKAKARI B, 148 TUKAMIKAKARI E */
const u16 makoto_atca_145_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_atca_145[16] = {
    CMD(CM_CAFR, 2, 1, 2),
    CMD(CM_CARE, 2, 1, 2),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 146 TUKAMIKAKARI C, 149 TUKAMIKAKARI F */
const u16 makoto_atca_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_atca_146[16] = {
    CMD(CM_CAFR, 2, 1, 1),
    CMD(CM_CARE, 2, 1, 1),
    CMD(CM_JPSS, 4, 144, 3),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 156 follow-up of L PUNCH C */
const u16 makoto_atca_156_head[4] = { HEAD(4, 0, 4, 13, 0, 1, 0) };
const u16 makoto_atca_156[164] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x62CA, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x62CB, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62CC, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62CD, -7, 34, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62CE, 0, 35, 0, 64, 0, 0, 0),
    L4(3, 0, 270, 0, 0, 0, 0, 0x62CF, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 474, 0, 0, 0, 0, 0x62D0, 0, 52, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C6, -8, 34, 0, 139, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x62C7, 0, 35, 0, 139, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62C8, 0, 35, 0, 128, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x62C9, 0, 35, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x62D5, 0, 35, 0, 64, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62CA, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63BB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63BC, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6106, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6107, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 157 follow-up of L KICK C */
const u16 makoto_atca_157_head[4] = { HEAD(4, 0, 5, 7, 0, 1, 0) };
const u16 makoto_atca_157[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6499, 0, 76, 0, 0, 0, 32, 68),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64A1, 0, 76, 0, 0, 0, 32, 69),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64A2, 0, 1, 0, 0, 0, 32, 70),
    L4(3, 2, 0, 0, 0, 0, 0, 0x64A3, 0, 1, 0, 0, 0, 32, 71),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 17, 24), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 158 follow-up of S KICK A */
const u16 makoto_atca_158_head[4] = { HEAD(4, 0, 3, 13, 0, 1, 0) };
const u16 makoto_atca_158[60] = {
    CMD(CM_ASXY, 214, 0, 0), 0, 0, 0, 0,
    L4(5, 0, 0, 0, 0, 0, 0, 0x63D6, 0, 42, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x63D5, 0, 41, 0, 0, 0, 32, 108),
    L4(1, 0, 472, 0, 0, 0, 0, 0x63B3, -35, 44, 0, 134, 0, 32, 109),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63B4, 0, 45, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63B5, 0, 45, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 4, 12, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 159 follow-up of M KICK C */
const u16 makoto_atca_159_head[4] = { HEAD(4, 0, 5, 13, 0, 1, 0) };
const u16 makoto_atca_159[172] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x63CA, 0, 51, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x63CB, 0, 51, 0, 0, 0, 32, 47),
    L4(4, 0, 0, 0, 0, 0, 0, 0x63CC, 0, 51, 0, 0, 0, 32, 48),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63CD, 0, 51, 0, 0, 0, 32, 49),
    L4(2, 0, 0, 0, 0, 0, 0, 0x63E2, 0, 13, 0, 0, 0, 32, 200),
    L4(2, 0, 270, 1, 0, 0, 0, 0x63E3, 0, 13, 0, 0, 0, 32, 30),
    L4(3, 0, 470, 1, 0, 0, 0, 0x63E4, 0, 13, 0, 0, 0, 32, 31),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E5, -77, 14, 0, 138, 0, 32, 32),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E6, 0, 15, 0, 128, 0, 32, 33),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E7, 0, 16, 0, 0, 0, 32, 34),
    CMD(CM_ASXY, 70, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E8, 0, 17, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 1, 0, 0, 0, 0x63E9, 0, 17, 0, 0, 0, 32, 36),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63EA, 0, 17, 0, 0, 0, 32, 37),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63EB, 0, 18, 0, 0, 0, 32, 38),
    L4(3, 0, 0, 0, 0, 0, 0, 0x63EC, 0, 1, 0, 0, 0, 32, 39),
    L4(3, 64, 0, 0, 0, 0, 0, 0x63ED, 0, 1, 0, 0, 0, 32, 8),
    L4(3, 0, 0, 0, 0, 0, 0, 0x62BE, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const OLC_IX makoto_olc_ix_table[139] = {
    { { 0, 0, 0, 0 } },
    { { 0, 0, 0, 1 } },
    { { 0, 0, 0, 2 } },
    { { 0, 0, 0, 3 } },
    { { 0, 0, 0, 4 } },
    { { 0, 0, 0, 5 } },
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
    { { 75, 0, 0, 0 } },
    { { 76, 0, 0, 0 } },
    { { 77, 0, 0, 0 } },
    { { 78, 0, 0, 0 } },
    { { 79, 0, 0, 0 } },
    { { 80, 0, 0, 0 } },
    { { 81, 0, 0, 0 } },
    { { 82, 0, 0, 0 } },
    { { 83, 0, 0, 0 } },
    { { 84, 0, 0, 0 } },
    { { 85, 0, 0, 0 } },
    { { 86, 0, 0, 0 } },
    { { 92, 0, 0, 0 } },
    { { 98, 0, 0, 0 } },
    { { 104, 0, 0, 0 } },
    { { 110, 0, 0, 0 } },
    { { 116, 0, 0, 0 } },
    { { 122, 0, 0, 0 } },
    { { 128, 0, 0, 0 } },
    { { 129, 0, 0, 0 } },
    { { 130, 0, 0, 0 } },
    { { 131, 0, 0, 0 } },
    { { 132, 0, 0, 0 } },
    { { 133, 0, 0, 0 } },
    { { 134, 0, 0, 0 } },
    { { 135, 0, 0, 0 } },
    { { 136, 0, 0, 0 } },
    { { 146, 0, 0, 0 } },
    { { 151, 0, 0, 0 } },
    { { 159, 0, 0, 0 } },
    { { 161, 0, 0, 0 } },
    { { 163, 185, 0, 0 } },
    { { 168, 0, 0, 0 } },
    { { 174, 0, 0, 0 } },
    { { 179, 0, 0, 0 } },
    { { 183, 0, 0, 0 } },
    { { 199, 0, 0, 0 } },
    { { 207, 0, 0, 0 } },
    { { 213, 0, 0, 0 } },
    { { 218, 0, 0, 0 } },
    { { 222, 0, 0, 0 } },
    { { 226, 0, 0, 0 } },
    { { 230, 0, 0, 0 } },
    { { 231, 0, 0, 0 } },
    { { 232, 0, 0, 0 } },
    { { 233, 0, 0, 0 } },
    { { 234, 0, 0, 0 } },
    { { 235, 0, 0, 0 } },
    { { 236, 0, 0, 0 } },
    { { 237, 0, 0, 0 } },
    { { 238, 0, 0, 0 } },
    { { 239, 0, 0, 0 } },
    { { 240, 0, 0, 0 } },
    { { 241, 0, 0, 0 } },
    { { 242, 0, 0, 0 } },
    { { 243, 0, 0, 0 } },
    { { 244, 0, 0, 0 } },
    { { 245, 0, 0, 0 } },
    { { 246, 0, 0, 0 } },
    { { 247, 0, 0, 0 } },
    { { 248, 0, 0, 0 } },
    { { 249, 0, 0, 0 } },
    { { 250, 0, 0, 0 } },
    { { 251, 0, 0, 0 } },
};

const OVERLAP_PARTS makoto_overlap_char_tbl[252] = {
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 1, 24993 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 2, 24994 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 3, 24995 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 4, 24996 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 5, 24997 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 6, 25312 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 7, 25313 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 8, 25314 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 9, 25315 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 10, 25316 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 11, 25317 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 12, 25318 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 13, 25319 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 14, 25320 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 15, 25321 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 16, 25322 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 17, 25323 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 18, 25324 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 19, 25325 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 20, 25326 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 21, 25327 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 22, 25328 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 23, 25329 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 24, 25330 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 25, 25331 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 26, 25332 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 27, 25333 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 28, 25334 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 29, 25335 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 30, 25336 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 31, 25337 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 32, 25338 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 33, 25339 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 34, 25340 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 35, 25341 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 36, 25342 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 37, 25343 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 38, 25344 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 39, 25345 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 40, 25346 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 41, 25347 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 42, 25348 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 43, 25349 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 44, 25350 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 45, 25351 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 46, 25360 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 47, 25361 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 48, 25362 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 49, 25363 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 50, 25364 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 51, 25365 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 52, 25366 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 53, 25367 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 54, 25368 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 55, 25369 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 56, 25370 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 57, 25371 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 58, 25372 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 59, 25373 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 60, 25374 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 61, 25375 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 62, 25376 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 63, 25377 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 64, 25378 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 65, 25379 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 66, 25380 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 67, 25381 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 68, 25382 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 69, 25383 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 70, 25384 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 71, 25385 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 72, 25386 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 73, 25387 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 74, 25388 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 75, 25389 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 76, 25390 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 77, 25391 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 78, 25392 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 79, 25393 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 80, 25394 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 81, 25395 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 82, 25396 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 83, 25397 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 84, 25398 },
    { 0, 0, 0, 0, 1, 0, 255, 0, 0, 85, 25399 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 0, 25461 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 0, 25462 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 0, 25463 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 0, 25464 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 0, 25465 },
    { 3, 104, 0, 0, 1, 0, 2, 0, 0, 86, 25466 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 0, 25461 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 0, 25462 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 0, 25463 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 0, 25464 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 0, 25465 },
    { 3, 104, 0, 0, 1, 1, 2, 0, 0, 92, 25466 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 0, 25461 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 0, 25462 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 0, 25463 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 0, 25464 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 0, 25465 },
    { 11, 102, 0, 0, 1, 0, 2, 0, 0, 98, 25466 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 0, 25461 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 0, 25462 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 0, 25463 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 0, 25464 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 0, 25465 },
    { 11, 102, 0, 0, 1, 1, 2, 0, 0, 104, 25466 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 0, 25461 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 0, 25462 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 0, 25463 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 0, 25464 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 0, 25465 },
    { -25, 97, 0, 0, 1, 0, 2, 0, 0, 110, 25466 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 0, 25461 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 0, 25462 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 0, 25463 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 0, 25464 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 0, 25465 },
    { -25, 97, 0, 0, 1, 1, 2, 0, 0, 116, 25466 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 0, 25461 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 0, 25462 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 0, 25463 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 0, 25464 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 0, 25465 },
    { -18, 99, 0, 0, 1, 0, 2, 0, 0, 122, 25466 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 128, 26099 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 129, 26100 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 130, 26101 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 131, 26102 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 132, 26103 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 133, 26104 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 134, 26105 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 135, 26106 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25897 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 25898 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 25899 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 25900 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 25901 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 25902 },
    { 0, 0, 0, 0, 1, 0, 6, 0, 0, 137, 25903 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25898 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25899 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25900 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25901 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 25902 },
    { 0, 0, 0, 0, 1, 0, 4, 0, 0, 143, 25903 },
    { 0, 0, 0, 0, 1, 0, 3, 0, 0, 0, 25898 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 25899 },
    { 0, 0, 0, 0, 1, 0, 3, 0, 0, 0, 25900 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 25901 },
    { 0, 0, 0, 0, 1, 0, 3, 0, 0, 0, 25902 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 149, 25903 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 25898 },
    { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 25899 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 25900 },
    { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 25901 },
    { 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 25902 },
    { 0, 0, 0, 0, 1, 0, 1, 0, 0, 155, 25903 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 24713 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 161, 24714 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44136 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44137 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44138 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44139 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 163, 44140 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44141 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44142 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44143 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44144 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44145 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 173, 0 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44146 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44147 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44148 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44149 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 174, 44150 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44151 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44152 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44153 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 182, 0 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 24686 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 183, 24685 },
    { 0, 0, 0, 0, 2, 0, 42, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 0, 44100 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44101 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44102 },
    { 0, 0, 0, 0, 2, 0, 6, 0, 0, 0, 44103 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 44101 },
    { 0, 0, 0, 0, 2, 0, 6, 0, 0, 0, 44102 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44100 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44102 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44100 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44102 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44103 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 44100 },
    { 0, 0, 0, 0, 2, 0, 250, 0, 0, 198, 44102 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25932 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25933 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25934 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 205, 25938 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25932 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25933 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25934 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 212, 25938 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25933 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 217, 25938 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 5, 0, 0, 221, 25938 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 225, 25938 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25935 },
    { 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 25936 },
    { 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 25937 },
    { 0, 0, 0, 0, 2, 0, 4, 0, 0, 229, 25938 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 230, 44292 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 231, 44293 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 232, 44294 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 233, 44295 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 234, 44296 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 235, 44297 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 236, 44298 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 237, 44299 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 238, 44300 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 239, 44322 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 240, 44323 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 241, 44324 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 242, 44325 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 243, 44326 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 244, 44327 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 245, 44328 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 246, 44329 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 247, 44330 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 248, 44331 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 249, 44332 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 250, 44333 },
    { 0, 0, 0, 0, 2, 0, 255, 0, 0, 242, 44334 },
};

const CatchTable makoto_rival_catch_tbl[1800] = {
    { -66, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -60, 0, 2, 1, 1 },
    { -60, 0, 2, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -66, 0, 2, 1, 1 },
    { -70, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -60, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -64, 0, 2, 1, 1 },
    { -72, 0, 2, 1, 1 },
    { -76, 0, 2, 1, 1 },
    { -68, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -66, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -88, 0, 2, 1, 2 },
    { -66, 0, 2, 1, 2 },
    { -62, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -60, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -75, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -76, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -64, 0, 2, 1, 2 },
    { -72, 0, 2, 1, 2 },
    { -76, 0, 1, 1, 2 },
    { -68, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { 0, 0, 2, 1, 2 },
    { -64, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -46, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -88, 0, 2, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -60, 0, 1, 1, 3 },
    { -58, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -70, 0, 1, 1, 3 },
    { -62, 0, 1, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -54, 0, 1, 1, 4 },
    { -40, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -48, 0, 1, 1, 4 },
    { -36, 0, 1, 1, 4 },
    { -66, 0, 1, 1, 4 },
    { -82, 0, 2, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { -48, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -54, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -60, 0, 1, 1, 4 },
    { -68, 0, 1, 1, 4 },
    { -80, 0, 1, 1, 4 },
    { -72, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -14, 0, 1, 1, 5 },
    { -8, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -10, 0, 1, 1, 5 },
    { -12, 0, 1, 1, 5 },
    { -30, 0, 1, 1, 5 },
    { -56, 0, 2, 1, 5 },
    { -12, 0, 1, 1, 5 },
    { -12, 0, 1, 1, 5 },
    { -40, 0, 1, 1, 5 },
    { -10, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -14, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -14, 0, 1, 1, 5 },
    { -24, 0, 1, 1, 5 },
    { -58, 0, 1, 1, 5 },
    { -32, 0, 1, 1, 5 },
    { -24, 0, 1, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { 0, 0, 2, 1, 5 },
    { -14, 0, 1, 1, 6 },
    { -8, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -2, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -30, 0, 1, 1, 6 },
    { -48, 0, 2, 1, 6 },
    { -10, 0, 1, 1, 6 },
    { -8, 0, 1, 1, 6 },
    { -22, 0, 1, 1, 6 },
    { -2, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { -12, 0, 1, 1, 6 },
    { -24, 0, 1, 1, 6 },
    { -32, 0, 1, 1, 6 },
    { -32, 0, 1, 1, 6 },
    { -18, 0, 1, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { -18, 0, 1, 1, 7 },
    { -8, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -20, 0, 1, 1, 7 },
    { -6, 0, 1, 1, 7 },
    { -26, 0, 1, 1, 7 },
    { -44, 0, 2, 1, 7 },
    { -12, 0, 1, 1, 7 },
    { -20, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -20, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -18, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { -20, 0, 1, 1, 7 },
    { -20, 0, 1, 1, 7 },
    { -34, 0, 1, 1, 7 },
    { -18, 0, 1, 1, 7 },
    { -14, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { -30, 0, 1, 1, 8 },
    { -4, 0, 1, 1, 8 },
    { -14, 0, 1, 1, 8 },
    { -30, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { -26, 0, 1, 1, 8 },
    { -36, 0, 2, 1, 8 },
    { -24, 0, 1, 1, 8 },
    { -12, 0, 1, 1, 8 },
    { -16, 0, 1, 1, 8 },
    { -30, 0, 1, 1, 8 },
    { -14, 0, 1, 1, 8 },
    { -14, 0, 1, 1, 8 },
    { -30, 0, 1, 1, 8 },
    { -14, 0, 1, 1, 8 },
    { -14, 0, 1, 1, 8 },
    { -26, 0, 1, 1, 8 },
    { -20, 0, 1, 1, 8 },
    { -36, 0, 1, 1, 8 },
    { -16, 0, 1, 1, 8 },
    { -18, 0, 1, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { -48, 0, 1, 1, 9 },
    { -68, 0, 1, 1, 9 },
    { -72, 0, 1, 1, 9 },
    { -54, 0, 1, 1, 9 },
    { -104, 0, 1, 1, 9 },
    { -80, 0, 1, 1, 9 },
    { -102, 0, 2, 1, 9 },
    { -62, 0, 1, 1, 9 },
    { -70, 0, 1, 1, 9 },
    { -76, 0, 2, 1, 9 },
    { -54, 0, 1, 1, 9 },
    { -68, 0, 1, 1, 9 },
    { -68, 0, 1, 1, 9 },
    { -48, 0, 1, 1, 9 },
    { -68, 0, 1, 1, 9 },
    { -68, 0, 1, 1, 9 },
    { -48, 0, 1, 1, 9 },
    { -72, 0, 1, 1, 9 },
    { -72, 0, 1, 1, 9 },
    { -72, 0, 1, 1, 9 },
    { -84, 0, 1, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { -52, 0, 1, 1, 10 },
    { -78, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -54, 0, 1, 1, 10 },
    { -104, 0, 1, 1, 10 },
    { -80, 0, 1, 1, 10 },
    { -94, 0, 2, 1, 10 },
    { -62, 0, 1, 1, 10 },
    { -70, 0, 1, 1, 10 },
    { -76, 0, 2, 1, 10 },
    { -54, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -52, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -48, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -72, 0, 1, 1, 10 },
    { -84, 0, 1, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { -60, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -54, 0, 1, 1, 1 },
    { -46, 0, 1, 1, 1 },
    { -64, 0, 1, 1, 1 },
    { -53, 0, 1, 1, 1 },
    { -61, 0, 1, 1, 1 },
    { -62, 0, 1, 1, 1 },
    { -57, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -49, 0, 1, 1, 1 },
    { -59, 0, 1, 1, 1 },
    { -63, 0, 1, 1, 1 },
    { -68, 0, 1, 1, 1 },
    { -53, 0, 1, 1, 1 },
    { -60, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -55, -4, 1, 1, 2 },
    { -113, 0, 2, 1, 2 },
    { -114, 2, 1, 1, 2 },
    { -61, 5, 1, 1, 2 },
    { -73, -1, 1, 1, 2 },
    { -57, 0, 1, 1, 2 },
    { -77, 0, 1, 1, 2 },
    { -69, -3, 1, 1, 2 },
    { -84, 0, 1, 1, 2 },
    { -53, 0, 1, 1, 2 },
    { -61, 5, 1, 1, 2 },
    { -114, 2, 1, 1, 2 },
    { -114, 2, 1, 1, 2 },
    { -55, -4, 1, 1, 2 },
    { -114, 2, 1, 1, 2 },
    { -114, 2, 1, 1, 2 },
    { -72, -2, 1, 1, 2 },
    { -77, -3, 1, 1, 2 },
    { -77, -4, 2, 1, 2 },
    { -56, 3, 1, 1, 2 },
    { -73, 1, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -56, 6, 1, 1, 3 },
    { -114, -1, 2, 1, 3 },
    { -114, 0, 2, 1, 3 },
    { -58, 1, 1, 1, 3 },
    { -76, 3, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -72, -7, 1, 1, 3 },
    { -76, -4, 1, 1, 3 },
    { -73, -6, 1, 1, 3 },
    { -77, -2, 1, 1, 3 },
    { -58, 1, 1, 1, 3 },
    { -114, 0, 2, 1, 3 },
    { -114, 0, 2, 1, 3 },
    { -56, 6, 1, 1, 3 },
    { -114, 0, 2, 1, 3 },
    { -114, 0, 2, 1, 3 },
    { -76, -5, 1, 1, 3 },
    { -76, -3, 1, 1, 3 },
    { -82, -4, 1, 1, 3 },
    { -54, 2, 1, 1, 3 },
    { -81, 2, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { 0, 0, 2, 1, 3 },
    { -32, 6, 1, 1, 4 },
    { -109, -2, 2, 1, 4 },
    { -78, -5, 2, 1, 4 },
    { -83, 2, 2, 1, 4 },
    { -92, 0, 2, 1, 4 },
    { -85, 3, 1, 1, 4 },
    { -84, 0, 2, 1, 4 },
    { -83, -4, 1, 1, 4 },
    { -70, -2, 1, 1, 4 },
    { -71, 0, 1, 1, 4 },
    { -83, 2, 2, 1, 4 },
    { -78, -5, 2, 1, 4 },
    { -78, -5, 2, 1, 4 },
    { -32, 6, 1, 1, 4 },
    { -78, -5, 2, 1, 4 },
    { -78, -5, 2, 1, 4 },
    { -92, 1, 2, 1, 4 },
    { -71, -6, 1, 1, 4 },
    { -79, 0, 1, 1, 4 },
    { -91, 3, 2, 1, 4 },
    { -85, -3, 1, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { 0, 0, 2, 1, 4 },
    { -23, 8, 1, 1, 5 },
    { -81, -5, 2, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -84, 1, 1, 1, 5 },
    { -70, 1, 2, 1, 5 },
    { -55, 0, 1, 1, 5 },
    { -75, 0, 2, 1, 5 },
    { -49, -3, 1, 1, 5 },
    { -51, 2, 1, 1, 5 },
    { -47, 0, 1, 1, 5 },
    { -84, 1, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -23, 8, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -91, 0, 1, 1, 5 },
    { -62, -6, 1, 1, 5 },
    { -61, 4, 1, 1, 5 },
    { -49, -4, 2, 1, 5 },
    { -66, 0, 2, 1, 5 },
    { -58, -4, 2, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 1, 7, 1, 1, 6 },
    { 2, -9, 1, 1, 6 },
    { -52, 0, 2, 1, 6 },
    { -52, 3, 1, 1, 6 },
    { -49, -3, 2, 1, 6 },
    { -27, 0, 2, 1, 6 },
    { -14, -2, 1, 1, 6 },
    { -35, 6, 1, 1, 6 },
    { -6, -1, 1, 1, 6 },
    { -18, 2, 1, 1, 6 },
    { -52, 3, 1, 1, 6 },
    { -52, 0, 2, 1, 6 },
    { -52, 0, 2, 1, 6 },
    { 1, 7, 1, 1, 6 },
    { -52, 0, 2, 1, 6 },
    { -52, 0, 2, 1, 6 },
    { -35, -10, 2, 1, 6 },
    { -33, 5, 2, 1, 6 },
    { -16, -4, 2, 1, 6 },
    { -46, -1, 1, 1, 6 },
    { -26, -2, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 0, 0, 2, 1, 6 },
    { 23, 9, 1, 1, 7 },
    { 6, -8, 1, 1, 7 },
    { 5, 0, 1, 1, 7 },
    { -1, 7, 1, 1, 7 },
    { -11, -3, 1, 1, 7 },
    { -4, 0, 1, 1, 7 },
    { -14, -6, 1, 1, 7 },
    { -14, -4, 1, 1, 7 },
    { -15, -4, 1, 1, 7 },
    { -16, 1, 1, 1, 7 },
    { -1, 7, 1, 1, 7 },
    { 5, 0, 1, 1, 7 },
    { 5, 0, 1, 1, 7 },
    { 23, 9, 1, 1, 7 },
    { 5, 0, 1, 1, 7 },
    { 5, 0, 1, 1, 7 },
    { -39, 2, 2, 1, 7 },
    { -19, -4, 1, 1, 7 },
    { -20, 4, 1, 1, 7 },
    { -2, 2, 1, 1, 7 },
    { -26, -2, 2, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 25, 9, 1, 1, 8 },
    { 5, -7, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { 0, 7, 1, 1, 8 },
    { -9, -4, 1, 1, 8 },
    { -5, 1, 1, 1, 8 },
    { -17, 0, 1, 1, 8 },
    { -13, -3, 1, 1, 8 },
    { -14, -4, 1, 1, 8 },
    { -15, 1, 1, 1, 8 },
    { 0, 7, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { 25, 9, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { 7, 0, 1, 1, 8 },
    { -12, -1, 1, 1, 8 },
    { -16, -4, 1, 1, 8 },
    { -13, 1, 1, 1, 8 },
    { -2, 3, 1, 1, 8 },
    { -28, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 0, 0, 1, 1, 8 },
    { 14, 10, 1, 1, 9 },
    { -14, -10, 1, 1, 9 },
    { 15, 2, 1, 1, 9 },
    { 9, 11, 1, 1, 9 },
    { 2, -7, 1, 1, 9 },
    { -4, -1, 1, 1, 9 },
    { -20, 4, 1, 1, 9 },
    { 3, 5, 1, 1, 9 },
    { -4, -3, 1, 1, 9 },
    { -7, 7, 1, 1, 9 },
    { 9, 11, 1, 1, 9 },
    { 15, 2, 1, 1, 9 },
    { 15, 2, 1, 1, 9 },
    { 14, 10, 1, 1, 9 },
    { 15, 2, 1, 1, 9 },
    { 15, 2, 1, 1, 9 },
    { 7, -1, 1, 1, 9 },
    { -6, -1, 1, 1, 9 },
    { -4, 4, 1, 1, 9 },
    { 7, 6, 1, 1, 9 },
    { -8, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 0, 0, 1, 1, 9 },
    { 18, 11, 1, 1, 10 },
    { -9, -9, 1, 1, 10 },
    { 16, 2, 1, 1, 10 },
    { 14, 0, 1, 1, 10 },
    { 5, -5, 1, 1, 10 },
    { -3, -2, 1, 1, 10 },
    { -13, -7, 1, 1, 10 },
    { 7, 7, 1, 1, 10 },
    { -1, -1, 1, 1, 10 },
    { 14, 6, 1, 1, 10 },
    { 14, 0, 1, 1, 10 },
    { 16, 2, 1, 1, 10 },
    { 16, 2, 1, 1, 10 },
    { 18, 11, 1, 1, 10 },
    { 16, 2, 1, 1, 10 },
    { 16, 2, 1, 1, 10 },
    { 15, 0, 1, 1, 10 },
    { -2, 2, 1, 1, 10 },
    { -3, 9, 1, 1, 10 },
    { 4, -1, 1, 1, 10 },
    { -6, 3, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 0, 0, 1, 1, 10 },
    { 19, 1, 1, 1, 11 },
    { -4, -9, 1, 1, 11 },
    { 14, 7, 1, 1, 11 },
    { 12, 2, 1, 1, 11 },
    { 9, -5, 1, 1, 11 },
    { -17, 4, 1, 1, 11 },
    { -21, -8, 1, 1, 11 },
    { -1, 1, 1, 1, 11 },
    { -5, 7, 1, 1, 11 },
    { 16, 9, 1, 1, 11 },
    { 12, 2, 1, 1, 11 },
    { 14, 7, 1, 1, 11 },
    { 14, 7, 1, 1, 11 },
    { 19, 1, 1, 1, 11 },
    { 14, 7, 1, 1, 11 },
    { 14, 7, 1, 1, 11 },
    { 12, 1, 1, 1, 11 },
    { 6, 4, 1, 1, 11 },
    { 1, 9, 1, 1, 11 },
    { 3, 2, 1, 1, 11 },
    { 2, 2, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 0, 0, 1, 1, 11 },
    { 20, 1, 1, 1, 12 },
    { 4, 6, 1, 1, 12 },
    { 15, 22, 1, 1, 12 },
    { 17, 14, 1, 1, 12 },
    { 27, 9, 1, 1, 12 },
    { 2, -2, 1, 1, 12 },
    { -10, -8, 1, 1, 12 },
    { 0, 14, 1, 1, 12 },
    { -3, 5, 1, 1, 12 },
    { 2, 21, 1, 1, 12 },
    { 17, 14, 1, 1, 12 },
    { 15, 22, 1, 1, 12 },
    { 15, 22, 1, 1, 12 },
    { 20, 1, 1, 1, 12 },
    { 15, 22, 1, 1, 12 },
    { 15, 22, 1, 1, 12 },
    { 7, 12, 1, 1, 12 },
    { 9, 18, 1, 1, 12 },
    { -21, -5, 1, 1, 12 },
    { -5, 3, 1, 1, 12 },
    { 9, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 0, 0, 1, 1, 12 },
    { 7, 8, 1, 1, 13 },
    { 7, 5, 1, 1, 13 },
    { 15, 40, 1, 1, 13 },
    { 22, 28, 1, 1, 13 },
    { 8, 20, 1, 1, 13 },
    { 4, 13, 1, 1, 13 },
    { -17, 2, 1, 1, 13 },
    { 12, 26, 1, 1, 13 },
    { -3, 20, 1, 1, 13 },
    { 4, 37, 1, 1, 13 },
    { 22, 28, 1, 1, 13 },
    { 15, 40, 1, 1, 13 },
    { 15, 40, 1, 1, 13 },
    { 7, 8, 1, 1, 13 },
    { 15, 40, 1, 1, 13 },
    { 15, 40, 1, 1, 13 },
    { 9, 27, 1, 1, 13 },
    { 0, 29, 1, 1, 13 },
    { 8, 11, 1, 1, 13 },
    { -5, 19, 1, 1, 13 },
    { 13, 15, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 0, 0, 1, 1, 13 },
    { 20, 11, 1, 1, 14 },
    { 6, 9, 1, 1, 14 },
    { 10, 38, 1, 1, 14 },
    { 14, 35, 1, 1, 14 },
    { 8, 23, 1, 1, 14 },
    { -6, 23, 1, 1, 14 },
    { -16, 4, 1, 1, 14 },
    { 12, 28, 1, 1, 14 },
    { 7, 27, 1, 1, 14 },
    { 5, 39, 1, 1, 14 },
    { 14, 35, 1, 1, 14 },
    { 10, 38, 1, 1, 14 },
    { 10, 38, 1, 1, 14 },
    { 20, 11, 1, 1, 14 },
    { 10, 38, 1, 1, 14 },
    { 10, 38, 1, 1, 14 },
    { 9, 29, 1, 1, 14 },
    { -8, 31, 1, 1, 14 },
    { 8, 14, 1, 1, 14 },
    { -2, 22, 1, 1, 14 },
    { 7, 16, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 0, 0, 1, 1, 14 },
    { 28, 4, 1, 1, 15 },
    { 0, 25, 1, 1, 15 },
    { 13, 35, 1, 1, 15 },
    { 15, 27, 1, 1, 15 },
    { 18, 25, 1, 1, 15 },
    { 6, 26, 1, 1, 15 },
    { -4, 11, 1, 1, 15 },
    { 1, 34, 1, 1, 15 },
    { 7, 25, 1, 1, 15 },
    { 21, 37, 1, 1, 15 },
    { 15, 27, 1, 1, 15 },
    { 13, 35, 1, 1, 15 },
    { 13, 35, 1, 1, 15 },
    { 28, 4, 1, 1, 15 },
    { 13, 35, 1, 1, 15 },
    { 13, 35, 1, 1, 15 },
    { 1, 26, 1, 1, 15 },
    { -7, 27, 1, 1, 15 },
    { -16, 7, 1, 1, 15 },
    { -10, 25, 1, 1, 15 },
    { -1, 21, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 0, 0, 1, 1, 15 },
    { 14, 8, 1, 1, 16 },
    { 3, 6, 1, 1, 16 },
    { 16, 41, 1, 1, 16 },
    { 9, 32, 1, 1, 16 },
    { 8, 23, 1, 1, 16 },
    { 1, 13, 1, 1, 16 },
    { -20, 1, 1, 1, 16 },
    { -1, 32, 1, 1, 16 },
    { -7, 20, 1, 1, 16 },
    { -9, 43, 1, 1, 16 },
    { 9, 32, 1, 1, 16 },
    { 16, 41, 1, 1, 16 },
    { 16, 41, 1, 1, 16 },
    { 14, 8, 1, 1, 16 },
    { 16, 41, 1, 1, 16 },
    { 16, 41, 1, 1, 16 },
    { 0, 21, 1, 1, 16 },
    { -13, 27, 1, 1, 16 },
    { -9, 3, 1, 1, 16 },
    { -7, 18, 1, 1, 16 },
    { 2, 14, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { 0, 0, 1, 1, 16 },
    { -3, 4, 1, 1, 17 },
    { 16, 11, 1, 1, 17 },
    { 15, 46, 1, 1, 17 },
    { 8, 28, 1, 1, 17 },
    { 18, 22, 1, 1, 17 },
    { 4, 34, 1, 1, 17 },
    { -21, 4, 1, 1, 17 },
    { -11, 37, 1, 1, 17 },
    { -14, 18, 1, 1, 17 },
    { -13, 47, 1, 1, 17 },
    { 8, 28, 1, 1, 17 },
    { 15, 46, 1, 1, 17 },
    { 15, 46, 1, 1, 17 },
    { -3, 4, 1, 1, 17 },
    { 15, 46, 1, 1, 17 },
    { 15, 46, 1, 1, 17 },
    { 8, 29, 1, 1, 17 },
    { -13, 29, 1, 1, 17 },
    { -14, 1, 1, 1, 17 },
    { 0, 11, 1, 1, 17 },
    { -14, 26, 1, 1, 17 },
    { 0, 0, 1, 1, 17 },
    { 0, 0, 1, 1, 17 },
    { 0, 0, 1, 1, 17 },
    { -22, 9, 1, 1, 18 },
    { -24, 24, 1, 1, 18 },
    { -32, 33, 1, 1, 18 },
    { -12, 31, 1, 1, 18 },
    { -12, 19, 1, 1, 18 },
    { -32, 22, 1, 1, 18 },
    { -29, 22, 1, 1, 18 },
    { -31, 38, 1, 1, 18 },
    { -14, 29, 1, 1, 18 },
    { -23, 38, 1, 1, 18 },
    { -12, 31, 1, 1, 18 },
    { -32, 33, 1, 1, 18 },
    { -32, 33, 1, 1, 18 },
    { -22, 9, 1, 1, 18 },
    { -32, 33, 1, 1, 18 },
    { -32, 33, 1, 1, 18 },
    { -26, 19, 2, 1, 18 },
    { -28, 29, 1, 1, 18 },
    { -30, 2, 1, 1, 18 },
    { -33, 18, 1, 1, 18 },
    { -30, 28, 1, 1, 18 },
    { 0, 0, 1, 1, 18 },
    { 0, 0, 1, 1, 18 },
    { 0, 0, 1, 1, 18 },
    { -20, 0, 1, 1, 19 },
    { -35, 0, 1, 1, 19 },
    { -19, 12, 1, 1, 19 },
    { -22, 6, 1, 1, 19 },
    { -26, 4, 1, 1, 19 },
    { -25, 2, 1, 1, 19 },
    { -43, 0, 1, 1, 19 },
    { -25, 9, 1, 1, 19 },
    { -38, 14, 1, 1, 19 },
    { -19, 4, 1, 1, 19 },
    { -22, 6, 1, 1, 19 },
    { -19, 12, 1, 1, 19 },
    { -19, 12, 1, 1, 19 },
    { -20, 0, 1, 1, 19 },
    { -19, 12, 1, 1, 19 },
    { -19, 12, 1, 1, 19 },
    { -24, 11, 2, 1, 19 },
    { -34, 7, 2, 1, 19 },
    { -31, -4, 1, 1, 19 },
    { -27, 0, 1, 1, 19 },
    { -28, -5, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { 0, 0, 1, 1, 19 },
    { -28, 0, 1, 1, 20 },
    { -41, 0, 1, 1, 20 },
    { -91, 0, 1, 1, 20 },
    { -27, 4, 1, 1, 20 },
    { -18, 2, 1, 1, 20 },
    { -60, 0, 1, 1, 20 },
    { -49, -1, 1, 1, 20 },
    { -57, 5, 1, 1, 20 },
    { -38, 5, 1, 1, 20 },
    { -46, 0, 1, 1, 20 },
    { -27, 4, 1, 1, 20 },
    { -91, 0, 1, 1, 20 },
    { -91, 0, 1, 1, 20 },
    { -28, 0, 1, 1, 20 },
    { -91, 0, 1, 1, 20 },
    { -91, 0, 1, 1, 20 },
    { -39, -3, 1, 1, 20 },
    { -38, -3, 1, 1, 20 },
    { -50, 0, 2, 1, 20 },
    { -31, 0, 1, 1, 20 },
    { -41, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { 0, 0, 1, 1, 20 },
    { -28, 0, 1, 1, 21 },
    { -39, 0, 1, 1, 21 },
    { -80, 0, 1, 1, 21 },
    { -29, 0, 1, 1, 21 },
    { -39, 0, 1, 1, 21 },
    { -50, 0, 1, 1, 21 },
    { -43, 0, 1, 1, 21 },
    { -43, 0, 1, 1, 21 },
    { -58, 0, 1, 1, 21 },
    { -40, 0, 1, 1, 21 },
    { -29, 0, 1, 1, 21 },
    { -80, 0, 1, 1, 21 },
    { -80, 0, 1, 1, 21 },
    { -28, 0, 1, 1, 21 },
    { -80, 0, 1, 1, 21 },
    { -80, 0, 1, 1, 21 },
    { -34, -3, 2, 1, 21 },
    { -46, -2, 1, 1, 21 },
    { -41, 0, 1, 1, 21 },
    { -43, 0, 1, 1, 21 },
    { -35, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { 0, 0, 1, 1, 21 },
    { -27, 0, 1, 1, 22 },
    { -31, 0, 1, 1, 22 },
    { -44, 0, 1, 1, 22 },
    { -18, 0, 1, 1, 22 },
    { -23, 0, 1, 1, 22 },
    { -28, 0, 1, 1, 22 },
    { -36, 0, 1, 1, 22 },
    { -39, 0, 1, 1, 22 },
    { -41, 0, 1, 1, 22 },
    { -37, 0, 1, 1, 22 },
    { -18, 0, 1, 1, 22 },
    { -44, 0, 1, 1, 22 },
    { -44, 0, 1, 1, 22 },
    { -27, 0, 1, 1, 22 },
    { -44, 0, 1, 1, 22 },
    { -44, 0, 1, 1, 22 },
    { -30, -3, 2, 1, 22 },
    { -45, 0, 1, 1, 22 },
    { -37, 0, 1, 1, 22 },
    { -36, 0, 1, 1, 22 },
    { -34, 0, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { 0, 0, 1, 1, 22 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 2, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -42, -4, 1, 1, 18 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -42, -4, 1, 1, 19 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -81, 0, 1, 1, 20 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -75, 0, 1, 1, 21 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -76, 0, 1, 1, 22 },
    { -91, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -78, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -96, 0, 1, 1, 1 },
    { -92, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -56, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -88, 0, 2, 1, 1 },
    { -76, 0, 1, 1, 23 },
    { -76, 0, 1, 1, 1 },
    { -80, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { -91, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -89, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { 0, 0, 2, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -77, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -83, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 1 },
    { -77, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -77, 0, 1, 1, 1 },
    { -79, 0, 1, 1, 1 },
    { -87, 0, 1, 1, 1 },
    { -80, 0, 1, 1, 1 },
    { -72, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -81, 0, 1, 1, 2 },
    { -76, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { -82, 0, 1, 1, 2 },
    { -84, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 2 },
    { -86, 0, 1, 1, 2 },
    { -78, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 2 },
    { -80, 0, 1, 1, 2 },
    { -88, 0, 1, 1, 2 },
    { -81, 0, 1, 1, 2 },
    { -72, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { 0, 0, 1, 1, 2 },
    { -50, 0, 1, 1, 3 },
    { -49, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -55, 0, 1, 1, 3 },
    { -72, 0, 1, 1, 3 },
    { -82, 0, 1, 1, 3 },
    { -74, 0, 1, 1, 3 },
    { -90, 0, 1, 1, 3 },
    { -57, 0, 1, 1, 3 },
    { -56, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -50, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { -59, 0, 1, 1, 3 },
    { -66, 0, 1, 1, 3 },
    { -59, 0, 1, 1, 3 },
    { -77, 0, 1, 1, 3 },
    { -64, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { 0, 0, 1, 1, 3 },
    { -52, 0, 1, 1, 4 },
    { -62, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -45, 0, 1, 1, 4 },
    { -38, 0, 1, 1, 4 },
    { -61, 0, 1, 1, 4 },
    { -76, 0, 1, 1, 4 },
    { -64, 0, 1, 1, 4 },
    { -77, 0, 1, 1, 4 },
    { -50, 0, 1, 1, 4 },
    { -45, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -52, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -46, 0, 1, 1, 4 },
    { -49, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { -55, 0, 1, 1, 4 },
    { -62, 0, 1, 1, 4 },
    { -56, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { 0, 0, 1, 1, 4 },
    { -7, 0, 1, 1, 5 },
    { -17, 0, 1, 1, 5 },
    { -1, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -7, 0, 1, 1, 5 },
    { -16, 0, 1, 1, 5 },
    { -31, 0, 1, 1, 5 },
    { -19, 0, 1, 1, 5 },
    { -32, 0, 1, 1, 5 },
    { -5, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { -1, 0, 1, 1, 5 },
    { -1, 0, 1, 1, 5 },
    { -7, 0, 1, 1, 5 },
    { -1, 0, 1, 1, 5 },
    { -1, 0, 1, 1, 5 },
    { -4, 0, 1, 1, 5 },
    { -11, 0, 1, 1, 5 },
    { -10, 0, 1, 1, 5 },
    { -17, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 0, 0, 1, 1, 5 },
    { 18, 0, 1, 1, 6 },
    { 1, 0, 1, 1, 6 },
    { 17, 0, 1, 1, 6 },
    { 18, 0, 1, 1, 6 },
    { 25, 0, 1, 1, 6 },
    { 2, 0, 1, 1, 6 },
    { -13, 0, 1, 1, 6 },
    { 4, 0, 1, 1, 6 },
    { -14, 0, 1, 1, 6 },
    { 13, 0, 1, 1, 6 },
    { 18, 0, 1, 1, 6 },
    { 17, 0, 1, 1, 6 },
    { 17, 0, 1, 1, 6 },
    { 18, 0, 1, 1, 6 },
    { 17, 0, 1, 1, 6 },
    { 17, 0, 1, 1, 6 },
    { 14, 0, 1, 1, 6 },
    { 11, 0, 1, 1, 6 },
    { 8, 0, 1, 1, 6 },
    { 5, 0, 1, 1, 6 },
    { 16, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 0, 0, 1, 1, 6 },
    { 33, 0, 1, 1, 7 },
    { 36, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 33, 0, 1, 1, 7 },
    { 40, 0, 1, 1, 7 },
    { 22, 0, 1, 1, 7 },
    { 2, 0, 1, 1, 7 },
    { 21, 0, 1, 1, 7 },
    { 18, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 33, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 33, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 32, 0, 1, 1, 7 },
    { 38, 0, 1, 1, 7 },
    { 26, 0, 1, 1, 7 },
    { 23, 0, 1, 1, 7 },
    { 20, 0, 1, 1, 7 },
    { 40, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 0, 0, 1, 1, 7 },
    { 50, 0, 2, 1, 8 },
    { 53, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 50, 0, 2, 1, 8 },
    { 57, 0, 2, 1, 8 },
    { 39, 0, 2, 1, 8 },
    { 19, 0, 2, 1, 8 },
    { 44, 0, 2, 1, 8 },
    { 36, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 50, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 50, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 49, 0, 2, 1, 8 },
    { 55, 0, 2, 1, 8 },
    { 43, 0, 2, 1, 8 },
    { 40, 0, 2, 1, 8 },
    { 37, 0, 2, 1, 8 },
    { 64, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 0, 0, 2, 1, 8 },
    { 80, 0, 2, 1, 9 },
    { 75, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 80, 0, 2, 1, 9 },
    { 87, 0, 2, 1, 9 },
    { 60, -1, 2, 1, 9 },
    { 49, 0, 2, 1, 9 },
    { 80, 0, 2, 1, 9 },
    { 61, 0, 2, 1, 9 },
    { 84, 0, 2, 1, 9 },
    { 80, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 80, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 79, 0, 2, 1, 9 },
    { 74, 0, 2, 1, 9 },
    { 70, 0, 2, 1, 9 },
    { 57, 0, 2, 1, 9 },
    { 72, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 0, 0, 2, 1, 9 },
    { 69, 0, 2, 1, 10 },
    { 73, 2, 2, 1, 10 },
    { 80, 5, 2, 1, 10 },
    { 83, 0, 2, 1, 10 },
    { 95, 0, 2, 1, 10 },
    { 62, -1, 2, 1, 10 },
    { 54, 0, 2, 1, 10 },
    { 83, 4, 2, 1, 10 },
    { 83, 0, 2, 1, 10 },
    { 83, 0, 2, 1, 10 },
    { 83, 0, 2, 1, 10 },
    { 80, 5, 2, 1, 10 },
    { 80, 5, 2, 1, 10 },
    { 69, 0, 2, 1, 10 },
    { 80, 5, 2, 1, 10 },
    { 80, 5, 2, 1, 10 },
    { 83, 0, 2, 1, 10 },
    { 67, -1, 2, 1, 10 },
    { 60, 0, 2, 1, 10 },
    { 56, 0, 2, 1, 10 },
    { 56, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 0, 0, 2, 1, 10 },
    { 64, 0, 2, 1, 11 },
    { 71, 6, 2, 1, 11 },
    { 77, 0, 2, 1, 11 },
    { 89, 6, 2, 1, 11 },
    { 95, 0, 2, 1, 11 },
    { 71, -1, 2, 1, 11 },
    { 57, 0, 2, 1, 11 },
    { 63, 1, 2, 1, 11 },
    { 86, 0, 2, 1, 11 },
    { 83, 0, 2, 1, 11 },
    { 89, 6, 2, 1, 11 },
    { 77, 0, 2, 1, 11 },
    { 77, 0, 2, 1, 11 },
    { 64, 0, 2, 1, 11 },
    { 77, 0, 2, 1, 11 },
    { 77, 0, 2, 1, 11 },
    { 55, 0, 2, 1, 11 },
    { 68, 0, 2, 1, 11 },
    { 62, 0, 2, 1, 11 },
    { 53, 0, 2, 1, 11 },
    { 64, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 0, 0, 2, 1, 11 },
    { 6, 1, 2, 1, 12 },
    { 13, 6, 2, 1, 12 },
    { 16, 13, 2, 1, 12 },
    { 20, 14, 2, 1, 12 },
    { 21, 9, 2, 1, 12 },
    { 11, 12, 2, 1, 12 },
    { 1, 8, 2, 1, 12 },
    { 10, 14, 2, 1, 12 },
    { 18, 30, 2, 1, 12 },
    { 27, 17, 2, 1, 12 },
    { 20, 14, 2, 1, 12 },
    { 16, 16, 2, 1, 12 },
    { 16, 16, 2, 1, 12 },
    { 6, 1, 2, 1, 12 },
    { 16, 13, 2, 1, 12 },
    { 16, 13, 2, 1, 12 },
    { 20, 11, 2, 1, 12 },
    { 16, 20, 2, 1, 12 },
    { 22, -6, 2, 1, 12 },
    { 21, 2, 2, 1, 12 },
    { 26, 11, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 0, 0, 2, 1, 12 },
    { 7, 3, 2, 1, 13 },
    { 1, 28, 2, 1, 13 },
    { 28, 14, 2, 1, 13 },
    { 31, 24, 2, 1, 13 },
    { 22, 15, 2, 1, 13 },
    { 17, 17, 2, 1, 13 },
    { 26, 8, 2, 1, 13 },
    { 19, 20, 2, 1, 13 },
    { 26, 34, 2, 1, 13 },
    { 27, 19, 2, 1, 13 },
    { 31, 24, 2, 1, 13 },
    { 28, 17, 2, 1, 13 },
    { 28, 17, 2, 1, 13 },
    { 7, 3, 2, 1, 13 },
    { 28, 14, 2, 1, 13 },
    { 28, 14, 2, 1, 13 },
    { 33, 18, 2, 1, 13 },
    { 24, 27, 2, 1, 13 },
    { 24, -2, 2, 1, 13 },
    { 27, 7, 2, 1, 13 },
    { 25, 19, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 0, 0, 2, 1, 13 },
    { 8, 2, 2, 1, 14 },
    { 29, 4, 2, 1, 14 },
    { 24, 15, 2, 1, 14 },
    { 35, 11, 2, 1, 14 },
    { 26, -1, 2, 1, 14 },
    { 36, 17, 2, 1, 14 },
    { 30, 3, 2, 1, 14 },
    { 18, 20, 2, 1, 14 },
    { 48, 24, 2, 1, 14 },
    { 23, 15, 2, 1, 14 },
    { 35, 11, 2, 1, 14 },
    { 24, 15, 2, 1, 14 },
    { 24, 15, 2, 1, 14 },
    { 8, 2, 2, 1, 14 },
    { 24, 15, 2, 1, 14 },
    { 24, 15, 2, 1, 14 },
    { 30, 16, 2, 1, 14 },
    { 37, 24, 2, 1, 14 },
    { 14, 0, 2, 1, 14 },
    { 36, 2, 2, 1, 14 },
    { 37, 16, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 0, 0, 2, 1, 14 },
    { 28, 7, 2, 1, 15 },
    { 36, 10, 2, 1, 15 },
    { 35, 16, 2, 1, 15 },
    { 44, 15, 2, 1, 15 },
    { 54, 7, 2, 1, 15 },
    { 45, 17, 2, 1, 15 },
    { 23, 11, 2, 1, 15 },
    { 29, 19, 2, 1, 15 },
    { 46, 24, 2, 1, 15 },
    { 27, 23, 2, 1, 15 },
    { 44, 15, 2, 1, 15 },
    { 35, 16, 2, 1, 15 },
    { 35, 16, 2, 1, 15 },
    { 28, 7, 2, 1, 15 },
    { 35, 16, 2, 1, 15 },
    { 35, 16, 2, 1, 15 },
    { 18, 12, 2, 1, 15 },
    { 30, 29, 2, 1, 15 },
    { 21, 0, 2, 1, 15 },
    { 34, 0, 2, 1, 15 },
    { 41, 7, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 0, 0, 2, 1, 15 },
    { 26, -2, 2, 1, 16 },
    { 41, 9, 2, 1, 16 },
    { 35, 13, 2, 1, 16 },
    { 45, 17, 2, 1, 16 },
    { 53, 5, 2, 1, 16 },
    { 48, 16, 2, 1, 16 },
    { 27, 7, 2, 1, 16 },
    { 42, 23, 2, 1, 16 },
    { 32, 24, 2, 1, 16 },
    { 36, 19, 2, 1, 16 },
    { 45, 17, 2, 1, 16 },
    { 35, 13, 2, 1, 16 },
    { 35, 13, 2, 1, 16 },
    { 26, -2, 2, 1, 16 },
    { 35, 13, 2, 1, 16 },
    { 35, 13, 2, 1, 16 },
    { 18, 10, 2, 1, 16 },
    { 31, 26, 2, 1, 16 },
    { 26, 0, 2, 1, 16 },
    { 33, 0, 2, 1, 16 },
    { 27, 9, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 0, 0, 2, 1, 16 },
    { 42, 15, 2, 1, 17 },
    { 33, 5, 2, 1, 17 },
    { 35, 15, 2, 1, 17 },
    { 54, 28, 2, 1, 17 },
    { 48, 4, 2, 1, 17 },
    { 33, 15, 2, 1, 17 },
    { 33, 5, 2, 1, 17 },
    { 29, 12, 2, 1, 17 },
    { 36, 22, 2, 1, 17 },
    { 41, 27, 2, 1, 17 },
    { 54, 28, 2, 1, 17 },
    { 35, 15, 2, 1, 17 },
    { 35, 15, 2, 1, 17 },
    { 42, 15, 2, 1, 17 },
    { 35, 15, 2, 1, 17 },
    { 35, 15, 2, 1, 17 },
    { 38, 10, 2, 1, 17 },
    { 31, 23, 2, 1, 17 },
    { 32, 0, 2, 1, 17 },
    { 39, 0, 2, 1, 17 },
    { 27, 7, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 0, 0, 2, 1, 17 },
    { 42, 15, 2, 1, 18 },
    { 24, 1, 2, 1, 18 },
    { 34, 13, 2, 1, 18 },
    { 53, 26, 2, 1, 18 },
    { 47, 3, 2, 1, 18 },
    { 42, 20, 2, 1, 18 },
    { 36, 2, 2, 1, 18 },
    { 24, 19, 2, 1, 18 },
    { 39, 14, 2, 1, 18 },
    { 41, 26, 2, 1, 18 },
    { 53, 26, 2, 1, 18 },
    { 34, 13, 2, 1, 18 },
    { 34, 13, 2, 1, 18 },
    { 42, 15, 2, 1, 18 },
    { 34, 13, 2, 1, 18 },
    { 34, 13, 2, 1, 18 },
    { 38, 8, 2, 1, 18 },
    { 29, 27, 2, 1, 18 },
    { 35, 0, 2, 1, 18 },
    { 38, 0, 2, 1, 18 },
    { 38, -1, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 0, 0, 2, 1, 18 },
    { 23, 7, 2, 1, 19 },
    { 32, 13, 2, 1, 19 },
    { 24, 5, 2, 1, 19 },
    { 43, 23, 2, 1, 19 },
    { 53, 3, 2, 1, 19 },
    { 43, 7, 2, 1, 19 },
    { 37, 0, 2, 1, 19 },
    { 26, 17, 2, 1, 19 },
    { 35, 20, 2, 1, 19 },
    { 46, 25, 2, 1, 19 },
    { 43, 23, 2, 1, 19 },
    { 24, 5, 2, 1, 19 },
    { 24, 5, 2, 1, 19 },
    { 23, 7, 2, 1, 19 },
    { 24, 5, 2, 1, 19 },
    { 24, 5, 2, 1, 19 },
    { 40, 3, 2, 1, 19 },
    { 33, 25, 2, 1, 19 },
    { 41, 0, 2, 1, 19 },
    { 37, 0, 2, 1, 19 },
    { 25, 3, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 0, 0, 2, 1, 19 },
    { 12, 0, 2, 1, 20 },
    { 28, 59, 2, 1, 20 },
    { 28, 14, 2, 1, 20 },
    { 67, 26, 2, 1, 20 },
    { 27, -15, 2, 1, 20 },
    { 38, 30, 2, 1, 20 },
    { 32, -8, 2, 1, 20 },
    { 40, 29, 2, 1, 20 },
    { 40, 27, 2, 1, 20 },
    { 14, 28, 2, 1, 20 },
    { 67, 26, 2, 1, 20 },
    { 32, 5, 2, 1, 20 },
    { 32, 5, 2, 1, 20 },
    { 12, 0, 2, 1, 20 },
    { 28, 14, 2, 1, 20 },
    { 28, 14, 2, 1, 20 },
    { 28, 5, 2, 1, 20 },
    { 22, 15, 2, 1, 20 },
    { 10, 8, 2, 1, 20 },
    { 47, 6, 2, 1, 20 },
    { 28, 7, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { 0, 0, 2, 1, 20 },
    { 9, -28, 2, 1, 21 },
    { 10, 7, 2, 1, 21 },
    { 6, -15, 2, 1, 21 },
    { 24, 5, 2, 1, 21 },
    { 4, -15, 2, 1, 21 },
    { 2, -4, 2, 1, 21 },
    { 17, -26, 2, 1, 21 },
    { 10, -18, 2, 1, 21 },
    { 17, 13, 2, 1, 21 },
    { -2, 5, 2, 1, 21 },
    { 24, 5, 2, 1, 21 },
    { 2, -29, 2, 1, 21 },
    { 2, -29, 2, 1, 21 },
    { 9, -28, 2, 1, 21 },
    { 6, -15, 2, 1, 21 },
    { 6, -15, 2, 1, 21 },
    { -6, -12, 2, 1, 21 },
    { 1, -18, 2, 1, 21 },
    { -15, 9, 2, 1, 21 },
    { 24, -28, 2, 1, 21 },
    { 5, -14, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { 0, 0, 2, 1, 21 },
    { -8, -3, 2, 1, 22 },
    { 4, 0, 2, 1, 22 },
    { -1, -11, 2, 1, 22 },
    { 4, -1, 2, 1, 22 },
    { -12, -4, 2, 1, 22 },
    { -9, -4, 2, 1, 22 },
    { 13, -2, 2, 1, 22 },
    { -8, -3, 2, 1, 22 },
    { 1, 0, 2, 1, 22 },
    { -13, 0, 2, 1, 22 },
    { 4, -1, 2, 1, 22 },
    { 2, -3, 2, 1, 22 },
    { 2, -3, 2, 1, 22 },
    { -8, -3, 2, 1, 22 },
    { -1, -11, 2, 1, 22 },
    { -1, -11, 2, 1, 22 },
    { -11, -2, 2, 1, 22 },
    { -11, -1, 2, 1, 22 },
    { -26, -2, 2, 1, 22 },
    { 17, 0, 2, 1, 22 },
    { -13, -4, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { 0, 0, 2, 1, 22 },
    { -8, -3, 2, 1, 23 },
    { 4, 0, 2, 1, 23 },
    { 3, -3, 2, 1, 23 },
    { 4, -1, 2, 1, 23 },
    { -1, -4, 2, 1, 23 },
    { -9, -4, 2, 1, 23 },
    { 17, -2, 2, 1, 23 },
    { -2, -3, 2, 1, 23 },
    { 2, 0, 2, 1, 23 },
    { -6, 0, 2, 1, 23 },
    { 4, -1, 2, 1, 23 },
    { 3, -3, 2, 1, 23 },
    { 3, -3, 2, 1, 23 },
    { -8, -3, 2, 1, 23 },
    { 3, -3, 2, 1, 23 },
    { 3, -3, 2, 1, 23 },
    { -11, -2, 2, 1, 23 },
    { -1, -2, 2, 1, 23 },
    { 16, -2, 2, 1, 23 },
    { 24, 0, 2, 1, 23 },
    { -12, -4, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { 0, 0, 2, 1, 23 },
    { -8, -3, 2, 1, 24 },
    { 4, 0, 2, 1, 24 },
    { 3, -3, 2, 1, 24 },
    { 4, -1, 2, 1, 24 },
    { 1, -4, 2, 1, 24 },
    { -9, -4, 2, 1, 24 },
    { 17, -2, 2, 1, 24 },
    { -1, -3, 2, 1, 24 },
    { 12, 0, 2, 1, 24 },
    { -7, 0, 2, 1, 24 },
    { 4, -1, 2, 1, 24 },
    { 3, -3, 2, 1, 24 },
    { 3, -3, 2, 1, 24 },
    { -8, -3, 2, 1, 24 },
    { 3, -3, 2, 1, 24 },
    { 3, -3, 2, 1, 24 },
    { -11, -2, 2, 1, 24 },
    { 6, -2, 2, 1, 24 },
    { 8, -2, 2, 1, 24 },
    { 24, 0, 2, 1, 24 },
    { -12, -4, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { 0, 0, 2, 1, 24 },
    { -8, -2, 2, 1, 25 },
    { 4, 0, 2, 1, 25 },
    { 3, -3, 2, 1, 25 },
    { 4, 0, 2, 1, 25 },
    { 1, -4, 2, 1, 25 },
    { -9, -3, 2, 1, 25 },
    { 17, -2, 2, 1, 25 },
    { -1, -3, 2, 1, 25 },
    { 13, 0, 2, 1, 25 },
    { -5, 0, 2, 1, 25 },
    { 4, 0, 2, 1, 25 },
    { 3, -3, 2, 1, 25 },
    { 3, -3, 2, 1, 25 },
    { -8, -2, 2, 1, 25 },
    { 3, -3, 2, 1, 25 },
    { 3, -3, 2, 1, 25 },
    { -11, -2, 2, 1, 25 },
    { -1, -1, 2, 1, 25 },
    { 8, -2, 2, 1, 25 },
    { 24, 0, 2, 1, 25 },
    { -12, -4, 2, 1, 25 },
    { 0, 0, 2, 1, 25 },
    { 0, 0, 2, 1, 25 },
    { 0, 0, 2, 1, 25 },
    { -8, -1, 2, 1, 26 },
    { 4, 0, 2, 1, 26 },
    { 3, -3, 2, 1, 26 },
    { 4, 0, 2, 1, 26 },
    { 2, -3, 2, 1, 26 },
    { -8, -2, 2, 1, 26 },
    { 17, -1, 2, 1, 26 },
    { -1, -2, 2, 1, 26 },
    { 14, 0, 2, 1, 26 },
    { -9, 0, 2, 1, 26 },
    { 4, 0, 2, 1, 26 },
    { 3, -3, 2, 1, 26 },
    { 3, -3, 2, 1, 26 },
    { -8, -1, 2, 1, 26 },
    { 3, -3, 2, 1, 26 },
    { 3, -3, 2, 1, 26 },
    { 9, -1, 2, 1, 26 },
    { 9, 0, 2, 1, 26 },
    { 11, -2, 2, 1, 26 },
    { 24, 0, 2, 1, 26 },
    { -11, -4, 2, 1, 26 },
    { 0, 0, 2, 1, 26 },
    { 0, 0, 2, 1, 26 },
    { 0, 0, 2, 1, 26 },
    { -8, 0, 2, 1, 27 },
    { 4, 0, 2, 1, 27 },
    { 3, -3, 2, 1, 27 },
    { 4, 0, 2, 1, 27 },
    { 3, -2, 2, 1, 27 },
    { -5, -1, 2, 1, 27 },
    { 17, 0, 2, 1, 27 },
    { -1, -1, 2, 1, 27 },
    { 15, 0, 2, 1, 27 },
    { -5, 0, 2, 1, 27 },
    { 4, 0, 2, 1, 27 },
    { 3, -3, 2, 1, 27 },
    { 3, -3, 2, 1, 27 },
    { -8, 0, 2, 1, 27 },
    { 3, -3, 2, 1, 27 },
    { 3, -3, 2, 1, 27 },
    { 9, 0, 2, 1, 27 },
    { 13, 0, 2, 1, 27 },
    { 12, -2, 2, 1, 27 },
    { 24, 0, 2, 1, 27 },
    { -10, -4, 2, 1, 27 },
    { 0, 0, 2, 1, 27 },
    { 0, 0, 2, 1, 27 },
    { 0, 0, 2, 1, 27 },
    { -8, 0, 2, 1, 28 },
    { 4, 0, 2, 1, 28 },
    { 3, -3, 2, 1, 28 },
    { 4, 0, 2, 1, 28 },
    { 4, -1, 2, 1, 28 },
    { -4, 0, 2, 1, 28 },
    { 17, 0, 2, 1, 28 },
    { -1, 0, 2, 1, 28 },
    { 16, 0, 2, 1, 28 },
    { -3, 0, 2, 1, 28 },
    { 4, 0, 2, 1, 28 },
    { 3, -3, 2, 1, 28 },
    { 3, -3, 2, 1, 28 },
    { -8, 0, 2, 1, 28 },
    { 3, -3, 2, 1, 28 },
    { 3, -3, 2, 1, 28 },
    { 8, 0, 2, 1, 28 },
    { 15, 0, 2, 1, 28 },
    { 15, -2, 2, 1, 28 },
    { 24, 0, 2, 1, 28 },
    { -4, -4, 2, 1, 28 },
    { 0, 0, 2, 1, 28 },
    { 0, 0, 2, 1, 28 },
    { 0, 0, 2, 1, 28 },
    { -8, 0, 2, 1, 29 },
    { 4, 0, 2, 1, 29 },
    { 3, -3, 2, 1, 29 },
    { 4, 0, 2, 1, 29 },
    { 5, 0, 2, 1, 29 },
    { 5, 0, 2, 1, 29 },
    { 17, -14, 2, 1, 29 },
    { -3, 0, 2, 1, 29 },
    { 16, 0, 2, 1, 29 },
    { 2, 0, 2, 1, 29 },
    { 4, 0, 2, 1, 29 },
    { 3, -3, 2, 1, 29 },
    { 3, -3, 2, 1, 29 },
    { -8, 0, 2, 1, 29 },
    { 3, -3, 2, 1, 29 },
    { 3, -3, 2, 1, 29 },
    { 8, -14, 2, 1, 29 },
    { 17, 0, 2, 1, 29 },
    { 17, -2, 2, 1, 29 },
    { 21, -4, 2, 1, 29 },
    { 2, -4, 2, 1, 29 },
    { 0, 0, 2, 1, 29 },
    { 0, 0, 2, 1, 29 },
    { 0, 0, 2, 1, 29 },
    { -8, 0, 2, 1, 30 },
    { 4, 0, 2, 1, 30 },
    { 3, -3, 2, 1, 30 },
    { 4, 0, 2, 1, 30 },
    { 6, 0, 2, 1, 30 },
    { 5, 2, 2, 1, 30 },
    { 17, -17, 2, 1, 30 },
    { -3, 0, 2, 1, 30 },
    { 16, 0, 2, 1, 30 },
    { 17, 0, 2, 1, 30 },
    { 4, 0, 2, 1, 30 },
    { 3, -3, 2, 1, 30 },
    { 3, -3, 2, 1, 30 },
    { -8, 0, 2, 1, 30 },
    { 3, -3, 2, 1, 30 },
    { 3, -3, 2, 1, 30 },
    { 5, -11, 2, 1, 30 },
    { 20, 0, 2, 1, 30 },
    { 17, -2, 2, 1, 30 },
    { 21, -9, 2, 1, 30 },
    { 0, -4, 2, 1, 30 },
    { 0, 0, 2, 1, 30 },
    { 0, 0, 2, 1, 30 },
    { 0, 0, 2, 1, 30 },
    { 20, -8, 2, 1, 31 },
    { 20, -31, 2, 1, 31 },
    { 4, -7, 2, 1, 31 },
    { 39, -32, 2, 1, 31 },
    { 16, -5, 2, 1, 31 },
    { 13, -20, 2, 1, 31 },
    { 9, -72, 2, 1, 31 },
    { 12, -6, 2, 1, 31 },
    { 16, -4, 2, 1, 31 },
    { 16, -10, 2, 1, 31 },
    { 39, -32, 2, 1, 31 },
    { 4, -7, 2, 1, 31 },
    { 4, -7, 2, 1, 31 },
    { 20, -8, 2, 1, 31 },
    { 4, -7, 2, 1, 31 },
    { 4, -7, 2, 1, 31 },
    { 11, -9, 2, 1, 31 },
    { 11, -4, 2, 1, 31 },
    { 9, -11, 2, 1, 31 },
    { 12, -4, 2, 1, 31 },
    { 3, -8, 2, 1, 31 },
    { 0, 0, 2, 1, 31 },
    { 0, 0, 2, 1, 31 },
    { 0, 0, 2, 1, 31 },
    { 18, -7, 2, 1, 32 },
    { 18, -40, 2, 1, 32 },
    { 4, -6, 2, 1, 32 },
    { 11, -5, 2, 1, 32 },
    { 16, -5, 2, 1, 32 },
    { 12, -5, 2, 1, 32 },
    { 8, -4, 2, 1, 32 },
    { 12, -6, 2, 1, 32 },
    { 16, -4, 2, 1, 32 },
    { 16, -10, 2, 1, 32 },
    { 11, -5, 2, 1, 32 },
    { 4, -6, 2, 1, 32 },
    { 4, -6, 2, 1, 32 },
    { 18, -7, 2, 1, 32 },
    { 4, -6, 2, 1, 32 },
    { 4, -6, 2, 1, 32 },
    { 11, -9, 2, 1, 32 },
    { 11, -4, 2, 1, 32 },
    { 9, -10, 2, 1, 32 },
    { 13, -30, 2, 1, 32 },
    { 3, -18, 2, 1, 32 },
    { 0, 0, 2, 1, 32 },
    { 0, 0, 2, 1, 32 },
    { 0, 0, 2, 1, 32 },
    { -5, -5, 2, 1, 33 },
    { 18, -6, 2, 1, 33 },
    { 4, -5, 2, 1, 33 },
    { 8, -6, 2, 1, 33 },
    { 16, -5, 2, 1, 33 },
    { 12, -5, 2, 1, 33 },
    { 8, -4, 2, 1, 33 },
    { 8, -6, 2, 1, 33 },
    { 16, -4, 2, 1, 33 },
    { 11, -6, 2, 1, 33 },
    { 8, -6, 2, 1, 33 },
    { 4, -5, 2, 1, 33 },
    { 4, -5, 2, 1, 33 },
    { -5, -5, 2, 1, 33 },
    { 4, -5, 2, 1, 33 },
    { 4, -5, 2, 1, 33 },
    { 11, -9, 2, 1, 33 },
    { 10, -5, 2, 1, 33 },
    { 9, -10, 2, 1, 33 },
    { 13, -29, 2, 1, 33 },
    { 1, -8, 2, 1, 33 },
    { 0, 0, 2, 1, 33 },
    { 0, 0, 2, 1, 33 },
    { 0, 0, 2, 1, 33 },
    { -3, -12, 2, 1, 34 },
    { 16, -5, 2, 1, 34 },
    { 4, -4, 2, 1, 34 },
    { 8, -6, 2, 1, 34 },
    { 16, -5, 2, 1, 34 },
    { 11, -4, 2, 1, 34 },
    { 8, -4, 2, 1, 34 },
    { 9, -4, 2, 1, 34 },
    { 21, -6, 2, 1, 34 },
    { 11, -6, 2, 1, 34 },
    { 8, -6, 2, 1, 34 },
    { 4, -4, 2, 1, 34 },
    { 4, -4, 2, 1, 34 },
    { -3, -12, 2, 1, 34 },
    { 4, -4, 2, 1, 34 },
    { 4, -4, 2, 1, 34 },
    { 8, -13, 2, 1, 34 },
    { 11, -5, 2, 1, 34 },
    { 13, -11, 2, 1, 34 },
    { 11, -23, 2, 1, 34 },
    { 0, -8, 2, 1, 34 },
    { 0, 0, 2, 1, 34 },
    { 0, 0, 2, 1, 34 },
    { 0, 0, 2, 1, 34 },
    { 4, -7, 2, 1, 35 },
    { 16, -4, 2, 1, 35 },
    { 4, -5, 2, 1, 35 },
    { 6, -6, 2, 1, 35 },
    { 16, -5, 2, 1, 35 },
    { 11, -7, 2, 1, 35 },
    { 8, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 24, -6, 2, 1, 35 },
    { 11, -5, 2, 1, 35 },
    { 6, -6, 2, 1, 35 },
    { 4, -5, 2, 1, 35 },
    { 4, -5, 2, 1, 35 },
    { 4, -7, 2, 1, 35 },
    { 4, -5, 2, 1, 35 },
    { 4, -5, 2, 1, 35 },
    { 10, -11, 2, 1, 35 },
    { 8, -7, 2, 1, 35 },
    { 10, -11, 2, 1, 35 },
    { 12, -4, 2, 1, 35 },
    { 0, -13, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { 3, -4, 2, 1, 35 },
    { 16, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 4, -4, 2, 1, 35 },
    { 14, -4, 2, 1, 35 },
    { 9, -6, 2, 1, 35 },
    { 6, -4, 2, 1, 35 },
    { 1, -4, 2, 1, 35 },
    { 19, -4, 2, 1, 35 },
    { 8, -4, 2, 1, 35 },
    { 4, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 3, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 2, -4, 2, 1, 35 },
    { 6, -11, 2, 1, 35 },
    { 8, -7, 2, 1, 35 },
    { 10, -5, 2, 1, 35 },
    { 11, -4, 2, 1, 35 },
    { 0, -8, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { 0, 0, 2, 1, 35 },
    { -24, 0, 2, 1, 36 },
    { -9, 0, 2, 1, 36 },
    { -25, 0, 2, 1, 36 },
    { -23, 0, 2, 1, 36 },
    { -13, 0, 2, 1, 36 },
    { -18, 0, 2, 1, 36 },
    { -21, 0, 2, 1, 36 },
    { -26, 0, 2, 1, 36 },
    { -8, 0, 2, 1, 36 },
    { -19, 0, 2, 1, 36 },
    { -23, 0, 2, 1, 36 },
    { -25, 0, 2, 1, 36 },
    { -25, 0, 2, 1, 36 },
    { -24, 0, 2, 1, 36 },
    { -25, 0, 2, 1, 36 },
    { -25, 0, 2, 1, 36 },
    { -21, 0, 2, 1, 36 },
    { -24, 0, 2, 1, 36 },
    { -18, 0, 2, 1, 36 },
    { -16, 0, 2, 1, 36 },
    { -29, 0, 2, 1, 36 },
    { 0, 0, 2, 1, 36 },
    { 0, 0, 2, 1, 36 },
    { 0, 0, 2, 1, 36 },
};

/* extra scripts: 80 entries */
const u16* const makoto_exca[81] = {
    makoto_exca_000,  /* 0 follow-up of AIR NORMAL */
    makoto_exca_001,  /* 1 follow-up of APPEAR JUNBI 4 */
    makoto_exca_001,  /* 2 follow-up of APPEAR JUNBI 5 */
    makoto_exca_003,  /* 3 follow-up of ASIBARAI SIRI */
    makoto_exca_004,  /* 4 follow-up of APPEAR JUNBI 6 */
    makoto_exca_005,  /* 5 follow-up of BODY UPPER, TOMOE RYU +11 */
    makoto_exca_006,  /* 6 follow-up of NOKEZORI, KIRIMOMI +17 */
    makoto_exca_007,  /* 7 follow-up of ASIB TUNNOMERI */
    makoto_exca_008,  /* 8 follow-up of KUNOJI, IBUKI +2 */
    makoto_exca_009,  /* 9 follow-up of TATAKI S, TTKI V. AIR +1 */
    makoto_exca_010,  /* 10 no name */
    makoto_exca_011,  /* 11 follow-up of APPEAR JUNBI 4 */
    makoto_exca_011,  /* 12 follow-up of APPEAR JUNBI 5 */
    makoto_exca_013,  /* 13 follow-up of APPEAR JUNBI 6 */
    makoto_exca_014,  /* 14 follow-up of ATTACK 5 SP, ATTACK 6 S +1 */
    makoto_exca_015,  /* 15 follow-up of ZANNEN 5 */
    makoto_exca_016,  /* 16 follow-up of ZANNEN 5 */
    makoto_exca_017,  /* 17 follow-up of ASIB TUN LOSE */
    makoto_exca_018,  /* 18 no name */
    makoto_exca_018,  /* 19 no name */
    makoto_exca_018,  /* 20 no name */
    makoto_exca_018,  /* 21 no name */
    makoto_exca_022,  /* 22 no name */
    makoto_exca_023,  /* 23 follow-up of HARAIGOSHI */
    makoto_exca_009,  /* 24 follow-up of KGM TATAKI S, KEN HIZAGERI */
    makoto_exca_025,  /* 25 follow-up of APPEAR 4 */
    makoto_exca_026,  /* 26 follow-up of APPEAR 4 */
    makoto_exca_027,  /* 27 follow-up of APPEAR JUNBI 7 */
    makoto_exca_028,  /* 28 follow-up of APPEAR JUNBI 7 */
    makoto_exca_029,  /* 29 no name */
    makoto_exca_030,  /* 30 no name */
    makoto_exca_030,  /* 31 no name */
    makoto_exca_032,  /* 32 no name */
    makoto_exca_033,  /* 33 no name */
    makoto_exca_034,  /* 34 no name */
    makoto_exca_035,  /* 35 no name */
    makoto_exca_035,  /* 36 no name */
    makoto_exca_037,  /* 37 no name */
    makoto_exca_038,  /* 38 no name */
    makoto_exca_039,  /* 39 no name */
    makoto_exca_040,  /* 40 no name */
    makoto_exca_041,  /* 41 follow-up of GILL IMPACT C */
    makoto_exca_042,  /* 42 follow-up of GILL IMPACT C */
    makoto_exca_043,  /* 43 no name */
    makoto_exca_044,  /* 44 no name */
    makoto_exca_045,  /* 45 no name */
    makoto_exca_046,  /* 46 no name */
    makoto_exca_047,  /* 47 follow-up of APPEAR JUNBI 1 */
    makoto_exca_048,  /* 48 follow-up of APPEAR JUNBI 1 */
    makoto_exca_049,  /* 49 no name */
    makoto_exca_050,  /* 50 no name */
    makoto_exca_049,  /* 51 no name */
    makoto_exca_050,  /* 52 no name */
    makoto_exca_053,  /* 53 no name */
    makoto_exca_054,  /* 54 no name */
    makoto_exca_055,  /* 55 no name */
    makoto_exca_056,  /* 56 follow-up of V JUMP P S A, V JUMP P M A +3 */
    makoto_exca_057,  /* 57 follow-up of F JUMP P S A, F JUMP P M A +4 */
    makoto_exca_058,  /* 58 follow-up of B JUMP P S A, B JUMP P M A +3 */
    makoto_exca_059,  /* 59 follow-up of SP APPEAR 1 */
    makoto_exca_060,  /* 60 follow-up of SP APPEAR 1 */
    makoto_exca_061,  /* 61 follow-up of SP APPEAR 1 */
    makoto_exca_062,  /* 62 follow-up of SP APPEAR 2 */
    makoto_exca_063,  /* 63 follow-up of SP APPEAR 3 */
    makoto_exca_064,  /* 64 follow-up of SP APPEAR 3 */
    makoto_exca_065,  /* 65 follow-up of SP APPEAR 3 */
    makoto_exca_066,  /* 66 follow-up of SP APPEAR 3 */
    makoto_exca_067,  /* 67 follow-up of SP APPEAR 3 */
    makoto_exca_068,  /* 68 follow-up of SP APPEAR 3 */
    makoto_exca_069,  /* 69 follow-up of SP APPEAR 8 */
    makoto_exca_070,  /* 70 follow-up of SP APPEAR 8 */
    makoto_exca_071,  /* 71 follow-up of ZANNEN 1 */
    makoto_exca_072,  /* 72 follow-up of ZANNEN 2 */
    makoto_exca_073,  /* 73 follow-up of ZANNEN 2 */
    makoto_exca_074,  /* 74 follow-up of ZANNEN 2 */
    makoto_exca_075,  /* 75 follow-up of ZANNEN 2 */
    makoto_exca_076,  /* 76 follow-up of ZANNEN 2 */
    makoto_exca_077,  /* 77 follow-up of ZANNEN 2 */
    makoto_exca_078,  /* 78 follow-up of KISHINRIKI */
    makoto_exca_079,  /* 79 no name */
    0
};

/* script: 0 follow-up of AIR NORMAL */
const u16 makoto_exca_000_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_exca_000[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x65B7, 0, 134, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x65B6, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65B5, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x65B4, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C3, 0, 134, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CC, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60CD, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 134, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 134, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 follow-up of APPEAR JUNBI 4, 2 follow-up of APPEAR JUNBI 5 */
const u16 makoto_exca_001_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_001[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6060, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6061, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x6062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 3 follow-up of ASIBARAI SIRI */
const u16 makoto_exca_003_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_003[132] = {
    L4(1, 2, 0, 0, 0, 0, 0, 0x61FF, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x61FB, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FC, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x61FD, 0, 4, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x61FE, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x61FF, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6280, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 1, 64, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 4 follow-up of APPEAR JUNBI 6 */
const u16 makoto_exca_004_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_004[60] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6060, 0, 1, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6061, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x6062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 5 follow-up of BODY UPPER, TOMOE RYU +11 */
const u16 makoto_exca_005_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_005[116] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 6 follow-up of NOKEZORI, KIRIMOMI +17 */
const u16 makoto_exca_006_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_006[212] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FA, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FB, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FC, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FD, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FE, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x61FF, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 7 follow-up of ASIB TUNNOMERI */
const u16 makoto_exca_007_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_007[52] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FF, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x61FB, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 2, 0, 0, 0, 0, 0, 0x61FC, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x61FD, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x61FE, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 3, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 8 follow-up of KUNOJI, IBUKI +2 */
const u16 makoto_exca_008_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_008[196] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6225, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6226, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6227, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6228, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 9 follow-up of TATAKI S, TTKI V. AIR +1, 24 follow-up of KGM TATAKI S, KEN HIZAGERI */
const u16 makoto_exca_009_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_009[132] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6233, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6234, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 10 no name */
const u16 makoto_exca_010_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_010[252] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6277, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6278, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6279, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x627A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x627B, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x627C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x627D, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6264, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6265, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6266, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6267, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6268, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6269, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x626A, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x626B, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x626C, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 11 follow-up of APPEAR JUNBI 4, 12 follow-up of APPEAR JUNBI 5 */
const u16 makoto_exca_011_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_011[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 13 follow-up of APPEAR JUNBI 6 */
const u16 makoto_exca_013_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_013[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 14 follow-up of ATTACK 5 SP, ATTACK 6 S +1 */
const u16 makoto_exca_014_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_014[148] = {
    CMD(CM_EXEC, 30, 193, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 194, 0), 0, 0, 0, 0,
    L4(2, 30, 274, 0, 0, 0, 0, 0x65B9, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BA, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BB, 0, 2, 0, 0, 0, 0, 0),
    L4(8, 21, 0, 0, 0, 0, 0, 0x65CD, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65CE, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65CF, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6502, 0, 2, 0, 0, 0, 22, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6503, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6504, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6072, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6073, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6076, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6077, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 15 follow-up of ZANNEN 5 */
const u16 makoto_exca_015_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_015[60] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6060, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6061, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 16 follow-up of ZANNEN 5 */
const u16 makoto_exca_016_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_016[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 17 follow-up of ASIB TUN LOSE */
const u16 makoto_exca_017_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_017[52] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x61FF, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x61FB, 0, 4, 0, 0, 0, 0, 0),
    L4(6, 2, 0, 0, 0, 0, 0, 0x61FC, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 2, 0, 0, 0, 0, 0, 0x61FD, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x61FE, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 7, 6, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 18 no name, 19 no name, 20 no name, 21 no name */
const u16 makoto_exca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_018[8] = {
    L2(250, 0, 0, 0, 3, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 22 no name */
const u16 makoto_exca_022_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_exca_022[36] = {
    CMD(CM_RJA, 7, 23, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 1, 0, 0, 0x61FA, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 1, 0, 0, 0x61FA, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 23 follow-up of HARAIGOSHI */
const u16 makoto_exca_023_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_023[292] = {
    L4(3, 2, 0, 0, 1, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 1, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 1, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 1, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x2600, 0x0000, 0x0000,
    L4(2, 2, 0, 0, 0, 0, 0, 0x6228, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6200, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6201, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x6202, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6203, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 5, 0, 0, 0, 0, 0, 0x6204, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6205, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 25 follow-up of APPEAR 4 */
const u16 makoto_exca_025_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_025[92] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6136, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6137, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 26 follow-up of APPEAR 4 */
const u16 makoto_exca_026_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_026[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x6136, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6137, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x6064, 0, 1, 0, 0, 0, 22, 32),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6066, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6067, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6067, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 27 follow-up of APPEAR JUNBI 7 */
const u16 makoto_exca_027_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_027[60] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x6060, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6061, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x6062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 3, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 follow-up of APPEAR JUNBI 7 */
const u16 makoto_exca_028_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_028[44] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 no name */
const u16 makoto_exca_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_029[8] = {
    L2(250, 0, 0, 0, 3, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 no name, 31 no name */
const u16 makoto_exca_030_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_030[68] = {
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
const u16 makoto_exca_032_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_exca_032[60] = {
    CMD(CM_RJA, 7, 5, 1), 0, 0, 0, 0,
    L4(8, 0, 0, 0, 0, 0, 0, 0x0CE3, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0CE4, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE5, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0CE6, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x0CE7, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_UJA, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 no name */
const u16 makoto_exca_033_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_033[52] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 no name */
const u16 makoto_exca_034_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_034[44] = {
    L4(2, 64, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 no name, 36 no name */
const u16 makoto_exca_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_035[8] = {
    L2(250, 0, 0, 0, 3, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 no name */
const u16 makoto_exca_037_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_037[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 no name */
const u16 makoto_exca_038_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_038[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 no name */
const u16 makoto_exca_039_head[4] = { HEAD(6, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_039[64] = {
    L6(2, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 no name */
const u16 makoto_exca_040_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_040[44] = {
    L4(2, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 2, 0, 0, 0, 0, 0),
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 follow-up of GILL IMPACT C */
const u16 makoto_exca_041_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_041[124] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 1, 64, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 follow-up of GILL IMPACT C */
const u16 makoto_exca_042_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_042[116] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 no name */
const u16 makoto_exca_043_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_043[60] = {
    CMD(CM_PA_X, 0, 1024, 0), 0, 0, 0, 0,
    L4(3, 0, 273, 0, 0, 0, 0, 0x0EBB, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0DE6, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0DE7, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C93, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 no name */
const u16 makoto_exca_044_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_044[76] = {
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

/* script: 45 no name */
const u16 makoto_exca_045_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_045[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C2A, 0, 180, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C2A, 0, 180, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C4B, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2F, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 no name */
const u16 makoto_exca_046_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_046[52] = {
    L4(1, 0, 273, 0, 0, 0, 0, 0x0C29, 0, 181, 0, 0, 0, 21, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 181, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2A, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x0C2B, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 follow-up of APPEAR JUNBI 1 */
const u16 makoto_exca_047_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_047[60] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x6060, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6061, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 3, 0, 0, 0, 0, 0, 0x6062, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 64, 0, 0, 0, 0, 0, 0x6070, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 follow-up of APPEAR JUNBI 1 */
const u16 makoto_exca_048_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_048[44] = {
    L4(2, 3, 273, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6063, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 3, 0, 0, 0, 0, 0, 0x6064, 0, 2, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6065, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 no name, 51 no name */
const u16 makoto_exca_049_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_049[60] = {
    L4(2, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 2, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 no name, 52 no name */
const u16 makoto_exca_050_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_050[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C88, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 53 no name */
const u16 makoto_exca_053_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_053[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0C8C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C84, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x0C85, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x0C86, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C87, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C0D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 no name */
const u16 makoto_exca_054_head[4] = { HEAD(4, 32, 0, 0, 0, 0, 0) };
const u16 makoto_exca_054[60] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C83, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 2, 0, 0, 0, 0, 0, 0x0C88, 0, 1, 0, 0, 0, 0, 0),
    L4(1, 2, 0, 0, 0, 0, 0, 0x0C29, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x0C2A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0C2C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 no name */
const u16 makoto_exca_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_055[8] = {
    L2(250, 0, 0, 0, 3, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 follow-up of V JUMP P S A, V JUMP P M A +3 */
const u16 makoto_exca_056_head[4] = { HEAD(4, 22, 0, 0, 0, 0, 0) };
const u16 makoto_exca_056[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60AB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60AC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60AD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60AF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 follow-up of F JUMP P S A, F JUMP P M A +4 */
const u16 makoto_exca_057_head[4] = { HEAD(4, 20, 0, 0, 0, 0, 0) };
const u16 makoto_exca_057[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60BB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60BC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60BD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 follow-up of B JUMP P S A, B JUMP P M A +3 */
const u16 makoto_exca_058_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_exca_058[60] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CA, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60CB, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60CC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60CD, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 59 follow-up of SP APPEAR 1 */
const u16 makoto_exca_059_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_059[500] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6018, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6019, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6054, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6055, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6056, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6057, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6058, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6059, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6069, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 28), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 60 follow-up of SP APPEAR 1 */
const u16 makoto_exca_060_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_060[180] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 28), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 61 follow-up of SP APPEAR 1 */
const u16 makoto_exca_061_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_061[276] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 28), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 follow-up of SP APPEAR 2 */
const u16 makoto_exca_062_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_062[36] = {
    L4(4, 0, 0, 0, 0, 110, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 26), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 63 follow-up of SP APPEAR 3 */
const u16 makoto_exca_063_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_063[500] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6018, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6019, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6054, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6055, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6056, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6057, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6058, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6059, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6069, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x606A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x606B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 64 follow-up of SP APPEAR 3 */
const u16 makoto_exca_064_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_064[180] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 65 follow-up of SP APPEAR 3 */
const u16 makoto_exca_065_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_065[276] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 66 follow-up of SP APPEAR 3 */
const u16 makoto_exca_066_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_066[500] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6018, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6019, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x601A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x601F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6054, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6055, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6056, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6057, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6058, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6059, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605C, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x601D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x605F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6069, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x606C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 follow-up of SP APPEAR 3 */
const u16 makoto_exca_067_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_067[180] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 follow-up of SP APPEAR 3 */
const u16 makoto_exca_068_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_068[276] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x6016, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6017, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6003, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6004, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6005, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6006, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6007, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6008, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6009, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600A, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600B, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600C, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600D, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6002, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600E, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x600F, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6010, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6011, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6012, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6013, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 110, 0, 0x6015, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6014, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 0, 30), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 69 follow-up of SP APPEAR 8 */
const u16 makoto_exca_069_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_069[76] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 follow-up of SP APPEAR 8 */
const u16 makoto_exca_070_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_070[116] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 105, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 follow-up of ZANNEN 1 */
const u16 makoto_exca_071_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_071[36] = {
    L4(4, 0, 0, 0, 0, 105, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 105, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 105, 0, 0x6088, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 11), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 follow-up of ZANNEN 2 */
const u16 makoto_exca_072_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_072[76] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 105, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 follow-up of ZANNEN 2 */
const u16 makoto_exca_073_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_073[76] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 105, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 follow-up of ZANNEN 2 */
const u16 makoto_exca_074_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_074[76] = {
    L4(6, 0, 0, 0, 0, 105, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 follow-up of ZANNEN 2 */
const u16 makoto_exca_075_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_075[116] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 105, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 follow-up of ZANNEN 2 */
const u16 makoto_exca_076_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_076[116] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 105, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 follow-up of ZANNEN 2 */
const u16 makoto_exca_077_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_exca_077[116] = {
    L4(6, 0, 0, 0, 0, 0, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6080, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6081, 0, 2, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 105, 0, 0x6082, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6083, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6084, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6085, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6086, 0, 2, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x6087, 0, 2, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 7, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 follow-up of KISHINRIKI */
const u16 makoto_exca_078_head[4] = { HEAD(4, 38, 0, 0, 0, 0, 0) };
const u16 makoto_exca_078[116] = {
    L4(3, 2, 0, 0, 0, 0, 0, 0x6206, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6207, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6208, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 1, 0, 0, 0, 0, 0, 0x6209, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620A, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 5, 0, 0, 0, 0, 0, 0x620B, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x620C, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620D, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620E, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x620F, 0, 4, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6210, 0, 4, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6211, 0, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6212, 0, 4, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6213, 0, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 no name */
const u16 makoto_exca_079_head[4] = { HEAD(4, 24, 0, 0, 0, 0, 0) };
const u16 makoto_exca_079[84] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x65B7, 0, 189, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x65B6, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65B5, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x65B4, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60C3, 0, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60CC, 0, 189, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x60CD, 0, 189, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60CE, 0, 190, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x60CF, 0, 190, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* super art scripts: 80 entries */
const u16* const makoto_saca[81] = {
    makoto_saca_000,  /* 0 UP P GUARD P S */
    makoto_saca_001,  /* 1 UP P GUARD P M */
    makoto_saca_002,  /* 2 UP P GUARD P L */
    makoto_saca_002,  /* 3 UP P GUARD K S */
    makoto_saca_002,  /* 4 UP P GUARD K M */
    makoto_saca_002,  /* 5 UP P GUARD K L */
    makoto_saca_000,  /* 6 D P GUARD P S */
    makoto_saca_001,  /* 7 D P GUARD P M */
    makoto_saca_002,  /* 8 D P GUARD P L */
    makoto_saca_002,  /* 9 D P GUARD K S */
    makoto_saca_002,  /* 10 D P GUARD K M */
    makoto_saca_002,  /* 11 D P GUARD K L */
    makoto_saca_002,  /* 12 FUSHIN P S */
    makoto_saca_002,  /* 13 FUSHIN P M */
    makoto_saca_002,  /* 14 FUSHIN P L */
    makoto_saca_002,  /* 15 FUSHIN K S */
    makoto_saca_002,  /* 16 FUSHIN K M */
    makoto_saca_002,  /* 17 FUSHIN K L */
    makoto_saca_002,  /* 18 OKIAGARI P S */
    makoto_saca_002,  /* 19 OKIAGARI P M */
    makoto_saca_002,  /* 20 OKIAGARI P L */
    makoto_saca_002,  /* 21 OKIAGARI K S */
    makoto_saca_002,  /* 22 OKIAGARI K M */
    makoto_saca_002,  /* 23 OKIAGARI K L */
    makoto_saca_024,  /* 24 ATTACK 1 S: not started by a command */
    makoto_saca_024,  /* 25 ATTACK 1 M: not started by a command */
    makoto_saca_024,  /* 26 ATTACK 1 L: not started by a command */
    makoto_saca_024,  /* 27 ATTACK 1 SP: not started by a command */
    makoto_saca_028,  /* 28 ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_029,  /* 29 ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_030,  /* 30 ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_031,  /* 31 ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_032,  /* 32 ATTACK 3 S: 214+P light (plain script) */
    makoto_saca_033,  /* 33 ATTACK 3 M: 214+P medium (plain script) */
    makoto_saca_034,  /* 34 ATTACK 3 L: 214+P heavy (plain script) */
    makoto_saca_035,  /* 35 ATTACK 3 SP: EX 214+PP (plain script) */
    makoto_saca_036,  /* 36 ATTACK 4 S: 623+P light (plain script) */
    makoto_saca_037,  /* 37 ATTACK 4 M: 623+P medium (plain script) */
    makoto_saca_038,  /* 38 ATTACK 4 L: 623+P heavy (plain script) */
    makoto_saca_039,  /* 39 ATTACK 4 SP: EX 623+PP (plain script) */
    makoto_saca_040,  /* 40 ATTACK 5 S: not started by a command */
    makoto_saca_041,  /* 41 ATTACK 5 M: not started by a command */
    makoto_saca_042,  /* 42 ATTACK 5 L: not started by a command */
    makoto_saca_043,  /* 43 ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1) */
    makoto_saca_044,  /* 44 ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1) */
    makoto_saca_045,  /* 45 ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
    makoto_saca_046,  /* 46 ATTACK 6 L: after SA II 23623+K (routine Att_PL17_AT1) */
    makoto_saca_047,  /* 47 ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
    makoto_saca_048,  /* 48 ATTACK 7 S: not started by a command */
    makoto_saca_049,  /* 49 ATTACK 7 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_050,  /* 50 ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_051,  /* 51 ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_052,  /* 52 ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_052,  /* 53 ATTACK 8 M: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_054,  /* 54 ATTACK 8 L: SA III 23623+P light (routine Att_PL17_AT2) */
    makoto_saca_055,  /* 55 ATTACK 8 SP: SA III 23623+P medium (routine Att_PL17_AT2) */
    makoto_saca_056,  /* 56 ATTACK 9 S: SA III 23623+P heavy (routine Att_PL17_AT2) */
    makoto_saca_057,  /* 57 ATTACK 9 M: SA III EX 23623+PP (routine Att_PL17_AT2) */
    makoto_saca_058,  /* 58 ATTACK 9 L: SA I 23623+P (plain script) */
    makoto_saca_058,  /* 59 ATTACK 9 SP: SA I 23623+P (plain script) */
    makoto_saca_058,  /* 60 ATTACK 10 S: SA I 23623+P (plain script) */
    makoto_saca_058,  /* 61 ATTACK 10 M: SA I 23623+P (plain script) */
    makoto_saca_062,  /* 62 ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_063,  /* 63 ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_064,  /* 64 ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_065,  /* 65 ATTACK 11 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_066,  /* 66 ATTACK 11 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_067,  /* 67 ATTACK 11 SP: after SA I 23623+P (plain script) */
    makoto_saca_068,  /* 68 ATTACK 12 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_069,  /* 69 ATTACK 12 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_070,  /* 70 ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_071,  /* 71 ATTACK 12 SP: after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_072,  /* 72 ATTACK 13 S: after SA II 23623+K (routine Att_PL17_AT1) */
    makoto_saca_073,  /* 73 ATTACK 13 M: not started by a command */
    makoto_saca_074,  /* 74 ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
    makoto_saca_075,  /* 75 ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) */
    makoto_saca_076,  /* 76 air 214+K heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
    makoto_saca_077,  /* 77 air EX 214+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
    makoto_saca_078,  /* 78 after 236+P (routine Att_CHOUCHUURENGEKI) */
    makoto_saca_079,  /* 79 not started by a command */
    0
};

/* script: 0 UP P GUARD P S, 6 D P GUARD P S */
const u16 makoto_saca_000_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_saca_000[116] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7120, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7121, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7122, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7123, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7124, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7125, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7126, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7127, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7128, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7129, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 30, 0, 0, 0, 0, 0, 0x712A, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_PAXY, 0, -1536, 5632), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 5, 1), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 14, 18), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 1 UP P GUARD P M, 7 D P GUARD P M */
const u16 makoto_saca_001_head[4] = { HEAD(4, 21, 0, 0, 0, 0, 0) };
const u16 makoto_saca_001[108] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x712A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x7129, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 31, 0, 0, 0, 0, 0, 0x7129, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7128, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7127, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7126, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7125, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7124, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7123, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7122, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7121, 0, 452, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7120, 0, 452, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 5, 53, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 2 UP P GUARD P L, 3 UP P GUARD K S, 4 UP P GUARD K M, 5 UP P GUARD K L ... */
const u16 makoto_saca_002_head[4] = { HEAD(2, 0, 0, 15, 0, 7, 0) };
const u16 makoto_saca_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x6001),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 24 ATTACK 1 S: not started by a command, 25 ATTACK 1 M: not started by a command, 26 ATTACK 1 L: not started by a command, 27 ATTACK 1 SP: not started by a command */
const u16 makoto_saca_024_head[4] = { HEAD(4, 0, 0, 12, 0, 1, 33) };
const u16 makoto_saca_024[108] = {
    CMD(CM_JSR, 8, 6, 1), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 324, 0, 0, 0, 0, 0),
    L4(5, 20, 0, 0, 0, 0, 0, 0x6420, 0, 117, 0, 0, 0, 22, 20),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6421, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 472, 0, 0, 0, 0, 0x6422, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x6423, 0, 117, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6424, -34, 118, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 90, 0, 0x6425, 0, 118, 0, 137, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 90, 0, 0x6426, 0, 118, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 90, 0, 0x6427, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 90, 0, 0x6428, 0, 118, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BB, 0, 9, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 7, 57, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 28 ATTACK 2 S: 236+P light (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_028_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_028[76] = {
    CMD(CM_WSET, 16384, 0, 16), 0, 0, 0, 0,
    CMD(CM_RJA6, 5, 28, 6), 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 28, 5), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 49, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 134, 0), 0, 0, 0, 0,
    L4(1, 0, 474, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 33, 0),
    L4(1, 0, 638, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155),
    CMD(CM_EXEC, 1, 135, 0), 0, 0, 0, 0,
    CMD(CM_UJA5, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 29 ATTACK 2 M: 236+P medium (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_029_head[4] = { HEAD(4, 0, 10, 9, 0, 1, 92) };
const u16 makoto_saca_029[100] = {
    CMD(CM_WSET, 16384, 0, 32), 0, 0, 0, 0,
    CMD(CM_RJA6, 5, 29, 6), 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 29, 5), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 49, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 134, 0), 0, 0, 0, 0,
    L4(1, 0, 474, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 33, 0),
    L4(2, 0, 638, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155),
    CMD(CM_EXEC, 1, 135, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x6544, 0, 161, 0, 0, 0, 32, 156),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0,
    CMD(CM_UJA5, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 30 ATTACK 2 L: 236+P heavy (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_030_head[4] = { HEAD(4, 0, 12, 9, 0, 1, 92) };
const u16 makoto_saca_030[100] = {
    CMD(CM_WSET, 16384, 0, 64), 0, 0, 0, 0,
    CMD(CM_RJA6, 5, 30, 6), 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 30, 5), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 49, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 134, 0), 0, 0, 0, 0,
    L4(2, 0, 474, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 33, 0),
    L4(2, 0, 638, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155),
    CMD(CM_EXEC, 1, 135, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6544, 0, 161, 0, 0, 0, 32, 156),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0,
    CMD(CM_UJA5, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 31 ATTACK 2 SP: EX 236+PP (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_031_head[4] = { HEAD(4, 0, 14, 9, 0, 1, 92) };
const u16 makoto_saca_031[108] = {
    CMD(CM_JSR, 8, 9, 1), 0, 0, 0, 0,
    L4(3, 0, 475, 0, 0, 0, 0, 0x6100, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6101, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6529, 0, 159, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 134, 0), 0, 0, 0, 0,
    L4(2, 0, 474, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155),
    L4(1, 0, 638, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 135, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 22, 3, 0), 0, 0, 0, 0,
    L4(4, 20, 0, 0, 0, 0, 0, 0x6544, 0, 161, 0, 0, 0, 32, 156),
    CMD(CM_EXEC, 22, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 68, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 49 ATTACK 7 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_049_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_049[276] = {
    CMD(CM_RJA5, 5, 62, 1), 0, 0, 0, 0,
    L4(2, 0, 475, 0, 0, 0, 0, 0x6100, 0, 1, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6101, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_IFS2, 16384, 8192, 8199), 0, 0, 0, 0,
    CMD(CM_RJA5, 5, 63, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 20), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 101, 0, 0x655E, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 49, 26), 0, 0, 0, 0,
    CMD(CM_IFS2, 16384, 8203, 8200), 0, 0, 0, 0,
    CMD(CM_RJA5, 5, 64, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 20), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 102, 0, 0x655E, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 49, 26), 0, 0, 0, 0,
    CMD(CM_IFS2, 16384, 8203, 8200), 0, 0, 0, 0,
    CMD(CM_RJA5, 5, 65, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 20), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 103, 0, 0x655E, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 49, 26), 0, 0, 0, 0,
    CMD(CM_IFS2, 16384, 8203, 8200), 0, 0, 0, 0,
    CMD(CM_RJA5, 5, 66, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 60), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 104, 0, 0x655E, 0, 159, 0, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 49, 26), 0, 0, 0, 0,
    CMD(CM_IFS2, 16384, 8203, 8200), 0, 0, 0, 0,
    CMD(CM_UJA7, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_SCHG2, 256, 16388, 8192), 0, 0, 0, 0,
    CMD(CM_SCHG2, 512, 16387, 8192), 0, 0, 0, 0,
    CMD(CM_SCHG2, 1024, 16386, 8192), 0, 0, 0, 0,
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 79 not started by a command */
const u16 makoto_saca_079_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_079[196] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6100, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 464, 0, 0, 0, 0, 0x6101, 0, 1, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6544, 0, 161, 0, 0, 0, 32, 156),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6000, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x654B, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x654C, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x654D, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x654E, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x654F, 0, 166, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6550, 0, 166, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6551, 0, 166, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x6552, 0, 166, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 62 ATTACK 10 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_062_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_062[144] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -48, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_HJMP, 8194, 16386, 16386), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 78, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654B, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 19), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 111, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
};

/* script: 63 ATTACK 10 SP: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_063_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_063[144] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -49, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_HJMP, 8194, 16386, 16386), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 78, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x654B, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 17), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 112, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
};

/* script: 64 ATTACK 11 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_064_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_064[136] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -50, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_HJMP, 8194, 16386, 16386), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 78, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 15), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 113, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
};

/* script: 65 ATTACK 11 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_065_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_065[136] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -51, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_HJMP, 8194, 16386, 16386), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 78, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 114, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
};

/* script: 66 ATTACK 11 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_066_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_066[132] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -52, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_HJMP, 8194, 16386, 16386), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 78, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 11), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 115, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 68 ATTACK 12 S: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_068_head[4] = { HEAD(4, 0, 14, 9, 0, 1, 92) };
const u16 makoto_saca_068[72] = {
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 71, 1), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x6545, -67, 162, 0, 135, 0, 32, 157),
    L4(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0),
    L4(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0),
    L4(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0),
    CMD(CM_JPSS, 5, 66, 9), 0, 0, 0, 0,
};

/* script: 69 ATTACK 12 M: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_069_head[4] = { HEAD(4, 0, 8, 9, 0, 0, 92) };
const u16 makoto_saca_069[68] = {
    L4(3, 64, 0, 0, 0, 0, 0, 0x6071, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 70 ATTACK 12 L: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_070_head[4] = { HEAD(4, 0, 8, 9, 0, 0, 92) };
const u16 makoto_saca_070[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x6553, 0, 272, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6554, 0, 273, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6555, 0, 274, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6556, 0, 274, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6557, 0, 275, 0, 0, 0, 0, 0),
    L4(3, 0, 458, 0, 0, 0, 0, 0x6558, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6559, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x655A, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x655B, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x655C, 0, 276, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x655D, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 71 ATTACK 12 SP: after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_071_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_071[52] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 11), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 116, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 78 after 236+P (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_078_head[4] = { HEAD(4, 0, 8, 9, 0, 1, 92) };
const u16 makoto_saca_078[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x654B, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 11), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 116, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 32 ATTACK 3 S: 214+P light (plain script) */
const u16 makoto_saca_032_head[4] = { HEAD(4, 0, 8, 11, 0, 1, 93) };
const u16 makoto_saca_032[236] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F0, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 452, 0, 0, 0, 0, 0x64F1, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F2, 0, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F3, 0, 122, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F4, 0, 123, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64F5, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64F6, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F7, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x64F8, 0, 126, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F9, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64FA, -37, 259, 0, 128, 64, 0, 0),
    CMD(CM_QUAY, 8, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x64FB, 0, 260, 0, 0, 64, 30, 115),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64FC, 0, 261, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64FD, 0, 262, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64FE, 0, 262, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64FF, 0, 262, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6500, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6501, 0, 263, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6502, 0, 264, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6503, 0, 265, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6504, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 33 ATTACK 3 M: 214+P medium (plain script) */
const u16 makoto_saca_033_head[4] = { HEAD(4, 0, 10, 11, 0, 1, 93) };
const u16 makoto_saca_033[124] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F0, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 452, 0, 0, 0, 0, 0x64F1, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F2, 0, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F3, 0, 122, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64F4, 0, 123, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64F5, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64F6, 0, 124, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64F7, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x64F8, 0, 126, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F9, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64FA, -64, 259, 0, 128, 64, 0, 0),
    CMD(CM_QUAY, 12, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x64FB, 0, 260, 0, 0, 64, 30, 115),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64FC, 0, 261, 0, 0, 64, 0, 0),
    CMD(CM_JPSS, 5, 32, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 34 ATTACK 3 L: 214+P heavy (plain script) */
const u16 makoto_saca_034_head[4] = { HEAD(4, 0, 12, 11, 0, 1, 93) };
const u16 makoto_saca_034[124] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F0, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 452, 0, 0, 0, 0, 0x64F1, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F2, 0, 121, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F3, 0, 122, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64F4, 0, 123, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x64F5, 0, 124, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64F6, 0, 124, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64F7, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x64F8, 0, 126, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F9, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64FA, -65, 259, 0, 128, 64, 0, 0),
    CMD(CM_QUAY, 16, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x64FB, 0, 260, 0, 0, 64, 30, 115),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64FC, 0, 261, 0, 0, 64, 0, 0),
    CMD(CM_JPSS, 5, 32, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 35 ATTACK 3 SP: EX 214+PP (plain script) */
const u16 makoto_saca_035_head[4] = { HEAD(4, 0, 14, 11, 0, 1, 93) };
const u16 makoto_saca_035[132] = {
    CMD(CM_JSR, 8, 26, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F0, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 452, 0, 0, 0, 0, 0x64F1, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F2, 0, 121, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F3, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F4, 0, 123, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F5, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F6, 0, 124, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64F7, 0, 125, 0, 0, 0, 0, 0),
    L4(2, 0, 270, 0, 0, 0, 0, 0x64F8, 0, 126, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64F9, 0, 127, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x64FA, -66, 259, 0, 128, 64, 0, 0),
    CMD(CM_QUAY, 22, 0, 0), 0, 0, 0, 0,
    L4(3, 0, 285, 0, 0, 0, 0, 0x64FB, 0, 260, 0, 0, 64, 30, 115),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64FC, 0, 261, 0, 0, 64, 0, 0),
    CMD(CM_JPSS, 5, 32, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 36 ATTACK 4 S: 623+P light (plain script) */
const u16 makoto_saca_036_head[4] = { HEAD(6, 0, 8, 2, 0, 1, 94) };
const u16 makoto_saca_036[412] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6510, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6511, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6512, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6513, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 464, 0, 0, 0, 0, 0x6514, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x6515, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6516, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6517, -38, 129, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6518, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6519, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x651A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x651B, 0, 131, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x651C, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x651D, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x651E, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x651F, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6520, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6521, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6522, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6523, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 0, 0, 0x6524, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6525, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6526, 0, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 0, 0, 0x6527, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6078, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6079, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x607A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x607B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 37 ATTACK 4 M: 623+P medium (plain script) */
const u16 makoto_saca_037_head[4] = { HEAD(6, 0, 10, 2, 0, 1, 94) };
const u16 makoto_saca_037[148] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6510, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6511, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6512, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6513, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 464, 0, 0, 0, 0, 0x6514, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 270, 0, 0, 0, 0, 0x6515, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6516, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6517, -61, 129, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6518, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6519, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x651A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 38 ATTACK 4 L: 623+P heavy (plain script) */
const u16 makoto_saca_038_head[4] = { HEAD(6, 0, 12, 2, 0, 1, 94) };
const u16 makoto_saca_038[148] = {
    L6(1, 0, 0, 0, 0, 0, 0, 0x6510, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6511, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6512, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6513, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 464, 0, 0, 0, 0, 0x6514, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 270, 0, 0, 0, 0, 0x6515, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6516, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6517, -62, 129, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6518, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6519, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x651A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 39 ATTACK 4 SP: EX 623+PP (plain script) */
const u16 makoto_saca_039_head[4] = { HEAD(6, 0, 14, 2, 0, 1, 94) };
const u16 makoto_saca_039[172] = {
    CMD(CM_JSR, 8, 10, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6120, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6121, 0, 257, 0, 0, 0, 32, 197, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6122, 0, 257, 0, 0, 0, 32, 198, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6512, 0, 257, 0, 0, 0, 32, 199, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6513, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 464, 0, 0, 0, 0, 0x6514, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 270, 0, 0, 0, 0, 0x6515, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6516, 0, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6517, -63, 258, 0, 128, 64, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6518, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6519, 0, 130, 0, 0, 65, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x651A, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 36, 12), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 40 ATTACK 5 S: not started by a command */
const u16 makoto_saca_040_head[4] = { HEAD(4, 0, 0, 0, 0, 1, 0) };
const u16 makoto_saca_040[708] = {
    CMD(CM_RJA, 5, 41, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 240, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B0, 0, 329, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B1, 0, 329, 0, 0, 0, 32, 121),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B2, 0, 330, 0, 0, 0, 32, 122),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B3, 0, 330, 0, 0, 0, 32, 123),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B4, 0, 330, 0, 0, 0, 32, 124),
    L4(2, 0, 459, 0, 0, 0, 0, 0x64B5, 0, 331, 0, 0, 0, 32, 125),
    L4(2, 40, 0, 0, 0, 0, 0, 0x64B6, 0, 331, 0, 0, 0, 32, 126),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B7, 0, 332, 0, 0, 0, 32, 127),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64B8, 0, 332, 0, 0, 0, 32, 128),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64B9, 0, 332, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64BA, 0, 333, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64BB, 0, 333, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64BC, 0, 334, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64BD, 0, 334, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64BE, 0, 334, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64BF, 0, 334, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64C0, 0, 335, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64C1, 0, 335, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64C2, 0, 336, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x64C3, 0, 336, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x64C4, 0, 336, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x64C5, 0, 336, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x64C6, 0, 336, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64C7, -39, 337, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64C8, 0, 338, 0, 0, 64, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 8194), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 42, 1), 0, 0, 0, 0,
    L4(2, 10, 0, 0, 0, 0, 0, 0x64C9, 0, 339, 0, 0, 64, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64CA, 0, 340, 0, 0, 0, 0, 0),
    L4(3, 0, 459, 0, 0, 0, 0, 0x64CB, 0, 340, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64CC, 0, 340, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64CD, 0, 333, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64CE, 0, 333, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64CF, 0, 333, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64D0, 0, 341, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64D1, 0, 341, 0, 0, 0, 0, 0),
    L4(3, 40, 0, 0, 0, 0, 0, 0x64D2, 0, 341, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64D3, 0, 342, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x64D4, 0, 342, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x64D5, 0, 342, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x64D6, 0, 342, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x64D7, 0, 342, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x64D8, 0, 343, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64D9, 0, 343, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64DA, 0, 344, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8192, 8194), 0, 0, 0, 0,
    L4(3, 20, 0, 0, 0, 0, 0, 0x64DB, 0, 345, 0, 0, 0, 32, 129),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64DC, 0, 345, 0, 0, 0, 32, 130),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64DD, 0, 346, 0, 0, 0, 32, 131),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64DE, 0, 346, 0, 0, 0, 32, 132),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64DF, 0, 346, 0, 0, 0, 32, 133),
    L4(2, 0, 459, 0, 0, 0, 0, 0x64E0, 0, 347, 0, 0, 0, 32, 134),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64E1, 0, 347, 0, 0, 0, 32, 135),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64E2, 0, 347, 0, 0, 0, 32, 136),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64E3, 0, 348, 0, 0, 0, 32, 137),
    L4(2, 0, 0, 0, 0, 0, 0, 0x64E4, 0, 348, 0, 0, 0, 32, 138),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64E5, 0, 349, 0, 0, 0, 32, 139),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64E6, 0, 349, 0, 0, 0, 32, 140),
    L4(2, 0, 0, 0, 1, 0, 0, 0x64B8, 0, 349, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64B9, 0, 350, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x64BA, 0, 350, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x64BB, 0, 350, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x64BC, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64BD, 0, 351, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x64BE, 0, 351, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x64BF, 0, 351, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64C0, 0, 352, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x64C1, 0, 352, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x64C2, 0, 352, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x64C3, 0, 353, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x64C4, 0, 353, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 1, 0, 0, 0x64C5, 0, 353, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 1, 0, 0, 0x64C6, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64C7, 0, 353, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64C8, 0, 354, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64E7, 0, 355, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x64E8, 0, 356, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6021, 0, 357, 0, 0, 0, 0, 0),
    L4(4, 40, 0, 0, 0, 0, 0, 0x6022, 0, 358, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6023, 0, 358, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6024, 0, 359, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6025, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6026, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 30, 0, 0, 0, 0, 0, 0x6027, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6028, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 41 ATTACK 5 M: not started by a command */
const u16 makoto_saca_041_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_saca_041[20] = {
    L4(3, 10, 0, 0, 0, 0, 0, 0x64C8, 0, 1, 0, 0, 64, 0, 0),
    CMD(CM_JPSS, 5, 42, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 42 ATTACK 5 L: not started by a command */
const u16 makoto_saca_042_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 makoto_saca_042[60] = {
    L4(3, 20, 0, 0, 0, 0, 0, 0x64DA, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x64E8, 0, 1, 0, 0, 0, 32, 141),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64E9, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64EA, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x64EB, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 64, 0, 0, 0, 0, 0, 0x64EC, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x64EC, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 43 ATTACK 5 SP: SA II 23623+K light (routine Att_PL17_AT1) */
const u16 makoto_saca_043_head[4] = { HEAD(4, 0, 33, 9, 0, 4, 96) };
const u16 makoto_saca_043[108] = {
    CMD(CM_RJA5, 5, 43, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 46, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 43, 9), 0, 0, 0, 0,
    L4(1, 20, 458, 0, 0, 0, 6, 0x65AD, -42, 138, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 6, 0x65AE, 0, 138, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x65AF, 0, 138, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 6, 0x65B0, 0, 138, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    CMD(CM_ASXY, 290, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 14, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 296, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 47, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 44 ATTACK 6 S: SA II 23623+K medium (routine Att_PL17_AT1) */
const u16 makoto_saca_044_head[4] = { HEAD(4, 0, 35, 12, 0, 4, 96) };
const u16 makoto_saca_044[108] = {
    CMD(CM_RJA5, 5, 44, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 46, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 44, 9), 0, 0, 0, 0,
    L4(1, 20, 458, 0, 0, 0, 5, 0x65A9, -42, 139, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 5, 0x65AA, 0, 139, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x65AB, 0, 139, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 5, 0x65AC, 0, 139, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    CMD(CM_ASXY, 292, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 14, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 298, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 47, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 45 ATTACK 6 M: SA II 23623+K heavy/EX (routine Att_PL17_AT1) */
const u16 makoto_saca_045_head[4] = { HEAD(4, 0, 37, 14, 0, 4, 96) };
const u16 makoto_saca_045[108] = {
    CMD(CM_RJA5, 5, 45, 3), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 46, 1), 0, 0, 0, 0,
    CMD(CM_RJA, 5, 45, 9), 0, 0, 0, 0,
    L4(1, 20, 458, 0, 0, 0, 9, 0x65A5, -42, 140, 0, 134, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 9, 0x65A6, 0, 140, 0, 128, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x65A7, 0, 140, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 9, 0x65A8, 0, 140, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_HJMP, 16387, 16387, 16387), 0, 0, 0, 0,
    CMD(CM_ASXY, 294, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 7, 14, 1), 0, 0, 0, 0,
    CMD(CM_ASXY, 300, 0, 0), 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 47, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 46 ATTACK 6 L: after SA II 23623+K (routine Att_PL17_AT1) */
const u16 makoto_saca_046_head[4] = { HEAD(6, 0, 33, 11, 0, 4, 96) };
const u16 makoto_saca_046[256] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA4, 5, 46, 15), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x63ED, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 10, 0, 0, 0, 0, 0, 0x60A3, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x60C5, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 25, 0, 0, 0, 0, 0, 0x65B1, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 268, 0, 0, 0, 0, 0x65B8, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B7, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B6, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B5, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 30, 268, 0, 0, 0, 0, 0x65B4, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B3, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B2, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65B1, 0, 8, 0, 0, 0, 0, 0, 256, 0, 0, 7, 0),
    CMD(CM_JSR, 8, 1, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 2048, 0, 0, 0, 11, 0x65A0, 0, 133, 0, 0, 0, 13, 49, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 14, 0x65A1, 0, 133, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 15, 0x65A2, 0, 133, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65A3, 0, 133, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(41, 0, 0, 0, 0, 0, 0, 0x65A4, 0, 133, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_UJA5, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 47 ATTACK 6 SP: after SA II 23623+K (routine Att_PL17_AT1) */
const u16 makoto_saca_047_head[4] = { HEAD(6, 0, 33, 10, 0, 3, 96) };
const u16 makoto_saca_047[808] = {
    L6(1, 30, 274, 0, 0, 0, 0, 0x6060, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6061, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6062, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 21, 0, 0, 0, 0, 0, 0x6070, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x63B0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 456, 0, 0, 0, 0, 0x63D0, 0, 141, 0, 0, 0, 32, 82, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x63D1, -43, 142, 0, 138, 0, 32, 83, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x63D2, 0, 143, 0, 138, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x63D3, 0, 143, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x63D4, 0, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x63D5, 0, 144, 0, 0, 0, 32, 84, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x63D6, 0, 145, 0, 128, 0, 32, 85, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x63D7, 0, 141, 0, 0, 0, 32, 86, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x6124, 0, 2, 0, 0, 0, 32, 152, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6410, 0, 146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6411, 0, 147, 0, 0, 0, 32, 97, 0, 0, 0, 0, 0),
    L6(1, 0, 472, 0, 0, 0, 0, 0x6412, 0, 148, 0, 0, 0, 32, 98, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6413, 0, 149, 0, 0, 0, 32, 99, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6414, -44, 150, 0, 128, 0, 32, 100, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6415, 0, 151, 0, 0, 0, 32, 101, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6416, 0, 152, 0, 0, 0, 32, 102, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x6417, 0, 153, 0, 0, 0, 32, 103, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6418, 0, 154, 0, 0, 0, 32, 104, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6419, 0, 146, 0, 0, 0, 32, 105, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6120, 0, 177, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6121, 0, 178, 0, 0, 0, 32, 195, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6122, 0, 179, 0, 0, 0, 32, 196, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x6512, 0, 155, 0, 0, 0, 32, 153, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x6513, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 1, 0, 0, 0x6514, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 1, 0, 0, 0x6515, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 474, 0, 1, 0, 0, 0x6516, 0, 155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HCLR, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 1, 0, 0, 0x6517, -45, 156, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16392, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 1, 0, 0, 0x6518, 0, 157, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16390, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 1, 0, 0, 0x6519, 0, 157, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16389, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 1, 0, 0, 0x651A, 0, 157, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 16388, 8192, 8192), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 72, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 1, 0, 0, 0x6518, 0, 157, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x6519, 0, 157, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 1, 0, 0, 0x651A, 0, 157, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x651B, 0, 158, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x651C, 0, 158, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x651D, 0, 158, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x651E, 0, 158, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 1, 0, 0, 0x651F, 0, 158, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 64, 0, 0, 1, 0, 0, 0x6520, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x6521, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x6522, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x6523, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x6524, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x6525, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 1, 0, 0, 0x6526, 0, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 1, 0, 0, 0x6527, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6078, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6079, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x607A, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x607B, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607C, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 48 ATTACK 7 S: not started by a command */
const u16 makoto_saca_048_head[4] = { HEAD(6, 0, 33, 11, 0, 4, 96) };
const u16 makoto_saca_048[400] = {
    CMD(CM_JSR, 8, 3, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 49, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x63B0, 0, 232, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x63B1, 0, 232, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x6370, 0, 233, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6371, -69, 234, 0, 128, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6374, 0, 235, 0, 64, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 20, 0, 0, 0, 0, 0, 0x6382, 0, 236, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6383, -70, 237, 0, 128, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x6384, 0, 238, 0, 64, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6385, 0, 238, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 20, 0, 0, 0, 0, 0, 0x6386, 0, 239, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6387, 0, 240, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6388, 0, 241, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6389, 0, 242, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x65C0, 0, 243, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x65C1, 0, 244, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65C2, 0, 244, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65C3, 0, 245, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x65C4, 0, 246, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x65C5, 0, 246, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65C6, 0, 247, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0x65C7, -71, 248, 0, 128, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(1, 20, 0, 0, 0, 0, 0, 0x65C8, 0, 249, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65C9, 0, 250, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65CA, 0, 251, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x65CB, 0, 251, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x65CC, 0, 252, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x60BC, 0, 252, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x60BD, 0, 253, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 253, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 253, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 50 ATTACK 7 L: 3214+K light (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_050_head[4] = { HEAD(4, 0, 25, 9, 0, 1, 95) };
const u16 makoto_saca_050[188] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6350, 0, 266, 0, 0, 0, 0, 0),
    L4(2, 0, 456, 0, 0, 0, 0, 0x6351, 0, 267, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6352, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6570, 0, 268, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6571, -40, 254, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6572, 0, 269, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6573, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6590, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6591, 0, 271, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x6592, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6593, 0, 271, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6594, 0, 271, 0, 0, 0, 0, 0),
    L4(4, 64, 0, 0, 0, 0, 0, 0x6594, 0, 271, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6504, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6074, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6075, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 51 ATTACK 7 SP: 3214+K medium (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_051_head[4] = { HEAD(4, 0, 27, 9, 0, 1, 95) };
const u16 makoto_saca_051[100] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6350, 0, 266, 0, 0, 0, 0, 0),
    L4(3, 0, 456, 0, 0, 0, 0, 0x6351, 0, 267, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6352, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6570, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6571, -40, 255, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6572, 0, 269, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6573, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6590, 0, 271, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6591, 0, 271, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 50, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 52 ATTACK 8 S: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI), 53 ATTACK 8 M: 3214+K heavy/EX (routine Att_CHOUCHUURENGEKI) */
const u16 makoto_saca_052_head[4] = { HEAD(4, 0, 29, 10, 0, 1, 95) };
const u16 makoto_saca_052[100] = {
    CMD(CM_CAFR, 2, 1, 3), 0, 0, 0, 0,
    CMD(CM_CARE, 2, 1, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x6350, 0, 266, 0, 0, 0, 0, 0),
    L4(4, 0, 456, 0, 0, 0, 0, 0x6351, 0, 267, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6352, 0, 267, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6570, 0, 268, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6571, -40, 256, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6572, 0, 269, 0, 0, 0, 21, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6573, 0, 270, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6590, 0, 271, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x6591, 0, 271, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 50, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 54 ATTACK 8 L: SA III 23623+P light (routine Att_PL17_AT2) */
const u16 makoto_saca_054_head[4] = { HEAD(6, 0, 48, 0, 0, 0, 97) };
const u16 makoto_saca_054[460] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 54, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 10, 466, 0, 0, 109, 0, 0x6078, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 64, 0, 0, 0, 109, 0, 0x6079, 0, 3, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 109, 0, 0x607A, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x607B, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x607C, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x607D, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 459, 0, 0, 0, 0, 0x6071, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC48, 0, 3, 0, 0, 0, 0, 0, 771, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC49, 0, 3, 0, 0, 0, 0, 0, 776, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC4A, 0, 3, 0, 0, 0, 13, 50, 779, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC4B, 0, 3, 0, 0, 0, 1, 136, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC4C, 0, 3, 0, 0, 0, 0, 0, 783, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC4D, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC4E, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC4F, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC50, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC51, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC52, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC53, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC54, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC55, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC56, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 108, 0, 0xAC57, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC58, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC59, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC5A, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC5B, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC5C, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 108, 0, 0xAC5D, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 109, 0, 0x6071, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 109, 0, 0x6072, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 109, 0, 0x6073, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 55 ATTACK 8 SP: SA III 23623+P medium (routine Att_PL17_AT2) */
const u16 makoto_saca_055_head[4] = { HEAD(6, 0, 50, 0, 0, 0, 97) };
const u16 makoto_saca_055[52] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 54, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 10, 463, 0, 0, 109, 0, 0x6078, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 54, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 56 ATTACK 9 S: SA III 23623+P heavy (routine Att_PL17_AT2) */
const u16 makoto_saca_056_head[4] = { HEAD(6, 0, 52, 0, 0, 0, 97) };
const u16 makoto_saca_056[52] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JSR, 5, 54, 10), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 10, 462, 0, 0, 109, 0, 0x6078, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 54, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 57 ATTACK 9 M: SA III EX 23623+PP (routine Att_PL17_AT2) */
const u16 makoto_saca_057_head[4] = { HEAD(6, 0, 54, 0, 0, 0, 97) };
const u16 makoto_saca_057[64] = {
    CMD(CM_JSR, 8, 7, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 476, 0, 0, 0, 0, 0x6071, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_JSR, 5, 54, 11), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 10, 0, 0, 0, 109, 0, 0x6078, 0, 3, 0, 0, 0, 0, 0, 785, 0, 0, 0, 0),
    CMD(CM_JPSS, 5, 54, 4), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 58 ATTACK 9 L: SA I 23623+P (plain script), 59 ATTACK 9 SP: SA I 23623+P (plain script), 60 ATTACK 10 S: SA I 23623+P (plain script), 61 ATTACK 10 M: SA I 23623+P (plain script) */
const u16 makoto_saca_058_head[4] = { HEAD(6, 0, 48, 11, 0, 1, 3) };
const u16 makoto_saca_058[556] = {
    CMD(CM_JSR, 8, 8, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC08, 0, 3, 0, 0, 0, 13, 55, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC09, 0, 3, 0, 0, 0, 0, 0, 770, 0, 316, 0, 0),
    L6(2, 0, 460, 0, 0, 0, 0, 0xAC0A, 0, 3, 0, 0, 0, 0, 0, 770, 0, 318, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC0B, 0, 3, 0, 0, 0, 0, 0, 770, 0, 320, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC0C, 0, 3, 0, 0, 0, 0, 0, 770, 0, 322, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC0D, 0, 3, 0, 0, 0, 0, 0, 770, 0, 324, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC0E, 0, 3, 0, 0, 0, 0, 0, 770, 0, 326, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC0F, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC10, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC11, 0, 3, 0, 0, 0, 39, 10, 770, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC12, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC13, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC14, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC15, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC16, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC17, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC18, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC19, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(4, 0, 474, 0, 0, 0, 0, 0xAC1A, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(1, 0, 269, 0, 0, 0, 0, 0xAC1B, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC1B, 0, 3, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_RJA7, 5, 67, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC1C, -56, 193, 0, 128, 0, 0, 0, 770, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 16390, 16390), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RJA7, 5, 67, 2), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC1D, 0, 194, 0, 128, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_HJMP, 8200, 16387, 16387), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC1E, 0, 195, 0, 0, 0, 21, 0, 770, 0, 0, 0, 0),
    CMD(CM_IXFW, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_RHSJA, 5, 58, 33), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(250, 0, 0, 0, 0, 0, 0, 0xAC1C, 0, 195, 0, 0, 0, 0, 0, 770, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC1D, 0, 195, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC1E, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC1F, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC20, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0xAC21, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0xAC22, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(7, 0, 0, 0, 0, 0, 0, 0x6071, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6072, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6073, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6074, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6075, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 64, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(8, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 67 ATTACK 11 SP: after SA I 23623+P (plain script) */
const u16 makoto_saca_067_head[4] = { HEAD(6, 0, 48, 11, 0, 4, 3) };
const u16 makoto_saca_067[664] = {
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC1C, 0, 193, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC1D, 0, 194, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC1E, 0, 195, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC1F, 0, 195, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0xAC20, 0, 195, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC21, 0, 195, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC22, 0, 195, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC23, 0, 196, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC24, 0, 197, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC25, 0, 198, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC26, 0, 198, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(5, 0, 456, 0, 0, 0, 0, 0xAC27, 0, 198, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0xAC28, 0, 199, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC29, -57, 200, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC2A, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 456, 0, 0, 0, 0, 0xAC2B, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0xAC2C, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC2D, -58, 202, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC2E, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 456, 0, 0, 0, 0, 0xAC2F, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 268, 0, 0, 0, 0, 0xAC30, 0, 201, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(1, 0, 0, 0, 0, 0, 0, 0xAC31, -59, 203, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC32, 0, 204, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0xAC33, 0, 205, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC34, 0, 206, 0, 0, 0, 0, 0, 780, 0, 328, 0, 0),
    L6(6, 0, 0, 0, 0, 0, 0, 0xAC35, 0, 207, 0, 0, 0, 0, 0, 780, 0, 330, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0xAC36, 0, 208, 0, 0, 0, 0, 0, 780, 0, 332, 0, 0),
    L6(4, 0, 270, 0, 0, 0, 0, 0xAC37, 0, 209, 0, 0, 0, 0, 0, 780, 0, 334, 0, 0),
    L6(3, 0, 0, 0, 0, 106, 0, 0xAC38, -60, 210, 0, 64, 0, 1, 137, 780, 0, 336, 0, 0),
    L6(4, 0, 469, 0, 0, 106, 0, 0xAC39, 0, 211, 0, 0, 0, 0, 0, 780, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 5), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3A, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3B, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3C, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3D, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3E, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 106, 0, 0xAC3F, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 0, 0, 0, 0, 107, 0, 0xAC3A, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 107, 0, 0xAC3B, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 107, 0, 0xAC3C, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 107, 0, 0xAC3D, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 107, 0, 0xAC3E, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 107, 0, 0xAC3F, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 107, 0, 0xAC40, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(6, 0, 0, 0, 0, 107, 0, 0xAC41, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(9, 0, 0, 0, 0, 0, 0, 0xAC42, 0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0xAC43, 0, 213, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6072, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6073, 0, 214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6074, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6075, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(4, 0, 0, 0, 0, 0, 0, 0x6076, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(5, 0, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(250, 255, 0, 0, 0, 0, 0, 0x6077, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 72 ATTACK 13 S: after SA II 23623+K (routine Att_PL17_AT1) */
const u16 makoto_saca_072_head[4] = { HEAD(4, 0, 33, 11, 0, 0, 96) };
const u16 makoto_saca_072[180] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0x651B, 0, 158, 0, 0, 0, 21, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x651C, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x651D, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x651E, 0, 158, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 1, 0, 0, 0x651F, 0, 158, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 1, 0, 0, 0x6520, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x6521, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x6522, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x6523, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x6524, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x6525, 0, 158, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 1, 0, 0, 0x6526, 0, 158, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x6527, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 64, 0, 0, 0, 0, 0, 0x6072, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x6073, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6078, 0, 1, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x6079, 0, 1, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x607A, 0, 1, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x607B, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x607C, 0, 1, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x607D, 0, 1, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 73 ATTACK 13 M: not started by a command */
const u16 makoto_saca_073_head[4] = { HEAD(6, 0, 33, 11, 0, 0, 96) };
const u16 makoto_saca_073[292] = {
    CMD(CM_MVIX, 48, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 0, 0, 0, 0, 0, 0x6100, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6101, 0, 1, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6529, 0, 159, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x652A, 0, 159, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 134, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 0, 474, 0, 0, 0, 0, 0x6543, 0, 160, 0, 0, 0, 32, 155, 256, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 135, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(2, 30, 0, 0, 0, 0, 0, 0x6544, 0, 161, 0, 0, 0, 32, 156, 256, 0, 0, 0, 0),
    CMD(CM_EXEC, 30, 177, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_EXEC, 30, 178, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_MVIX, 47, 0, 0), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(3, 30, 0, 0, 0, 0, 0, 0x6545, -68, 162, 0, 143, 0, 32, 157, 256, 0, 0, 0, 0),
    L6(3, 21, 0, 0, 0, 0, 0, 0x6546, 0, 163, 0, 128, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(4, 21, 0, 0, 0, 0, 0, 0x6547, 0, 164, 0, 0, 0, 0, 0, 256, 0, 0, 0, 0),
    L6(2, 21, 0, 0, 0, 0, 0, 0x6548, 0, 165, 0, 0, 0, 21, 0, 256, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x6549, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(2, 0, 0, 0, 0, 0, 0, 0x654A, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    L6(3, 0, 0, 0, 0, 0, 0, 0x654B, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_RJA, 5, 70, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_FOR, 0, 0, 31), 0, 0, 0, 0, 0, 0, 0, 0,
    L6(1, 0, 0, 0, 0, 111, 0, 0x655E, 0, 166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_IF_S, 1088, 8194, 8203), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_JPSS, 5, 69, 1), 0, 0, 0, 0, 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 74 ATTACK 13 L: air 214+K light (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 makoto_saca_074_head[4] = { HEAD(4, 22, 9, 12, 0, 1, 113) };
const u16 makoto_saca_074[188] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BC, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BD, 0, 236, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BE, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x65BF, 0, 242, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C0, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C1, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C2, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 455, 0, 0, 0, 0, 0x65C3, 0, 245, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x65C4, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x65C6, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C7, -72, 248, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C8, 0, 249, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C9, 0, 250, 0, 0, 0, 21, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65CA, 0, 251, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x65CB, 0, 251, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65CC, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BC, 0, 252, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BD, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BE, 0, 253, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x60BF, 0, 253, 0, 0, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 75 ATTACK 13 SP: air 214+K medium (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 makoto_saca_075_head[4] = { HEAD(4, 22, 11, 12, 0, 1, 113) };
const u16 makoto_saca_075[124] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BC, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BD, 0, 236, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BE, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BF, 0, 242, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C0, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C1, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x65C2, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 455, 0, 0, 0, 0, 0x65C3, 0, 245, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x65C4, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x65C6, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C7, -73, 248, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C8, 0, 249, 0, 64, 0, 0, 0),
    CMD(CM_JPSS, 5, 74, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 76 air 214+K heavy (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 makoto_saca_076_head[4] = { HEAD(4, 22, 13, 12, 0, 1, 113) };
const u16 makoto_saca_076[124] = {
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BC, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BD, 0, 236, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BE, 0, 241, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65BF, 0, 242, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C0, 0, 243, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C1, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 1, 0, 0, 0, 0, 0, 0x65C2, 0, 244, 0, 0, 0, 0, 0),
    L4(2, 0, 455, 0, 0, 0, 0, 0x65C3, 0, 245, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x65C4, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 20, 0, 0, 0, 0, 0, 0x65C6, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C7, -74, 248, 0, 128, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C8, 0, 249, 0, 64, 0, 0, 0),
    CMD(CM_JPSS, 5, 74, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* script: 77 air EX 214+KK (routine Att_KUUCHUUJINNCHUUWATARI) */
const u16 makoto_saca_077_head[4] = { HEAD(4, 22, 15, 12, 0, 2, 113) };
const u16 makoto_saca_077[132] = {
    CMD(CM_JSR, 8, 29, 1), 0, 0, 0, 0,
    CMD(CM_JSR, 8, 28, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BC, 0, 233, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BD, 0, 236, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BE, 0, 241, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65BF, 0, 242, 0, 0, 0, 0, 0),
    L4(1, 1, 0, 0, 0, 0, 0, 0x65C0, 0, 243, 0, 0, 0, 0, 0),
    L4(1, 30, 0, 0, 0, 0, 0, 0x65C1, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C2, 0, 244, 0, 0, 0, 0, 0),
    L4(1, 0, 455, 0, 0, 0, 0, 0x65C3, 0, 245, 0, 0, 0, 0, 0),
    L4(1, 0, 270, 0, 0, 0, 0, 0x65C4, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C5, 0, 246, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x65C6, 0, 247, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C7, -75, 248, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x65C8, -76, 249, 0, 64, 0, 0, 0),
    CMD(CM_JPSS, 5, 74, 15), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

/* combination scripts: 30 entries */
const u16* const makoto_cbca[31] = {
    makoto_cbca_000,  /* 0 APPEAR JUNBI 1 */
    makoto_cbca_001,  /* 1 APPEAR JUNBI 2 */
    makoto_cbca_002,  /* 2 APPEAR JUNBI 3 */
    makoto_cbca_003,  /* 3 APPEAR JUNBI 4 */
    makoto_cbca_004,  /* 4 APPEAR JUNBI 5 */
    makoto_cbca_005,  /* 5 APPEAR JUNBI 6 */
    makoto_cbca_006,  /* 6 APPEAR JUNBI 7 */
    makoto_cbca_007,  /* 7 APPEAR JUNBI 8 */
    makoto_cbca_008,  /* 8 APPEAR 1 */
    makoto_cbca_009,  /* 9 APPEAR 2 */
    makoto_cbca_010,  /* 10 APPEAR 3 */
    makoto_cbca_011,  /* 11 APPEAR 4 */
    makoto_cbca_012,  /* 12 APPEAR 5 */
    makoto_cbca_013,  /* 13 APPEAR 6 */
    makoto_cbca_014,  /* 14 APPEAR 7 */
    makoto_cbca_015,  /* 15 APPEAR 8 */
    makoto_cbca_016,  /* 16 SP APPEAR 1 */
    makoto_cbca_017,  /* 17 SP APPEAR 2 */
    makoto_cbca_018,  /* 18 SP APPEAR 3 */
    makoto_cbca_019,  /* 19 SP APPEAR 4 */
    makoto_cbca_020,  /* 20 SP APPEAR 5 */
    makoto_cbca_021,  /* 21 SP APPEAR 6 */
    makoto_cbca_022,  /* 22 SP APPEAR 7 */
    makoto_cbca_023,  /* 23 SP APPEAR 8 */
    makoto_cbca_024,  /* 24 ZANNEN 1 */
    makoto_cbca_025,  /* 25 ZANNEN 2 */
    makoto_cbca_026,  /* 26 ZANNEN 3 */
    makoto_cbca_027,  /* 27 ZANNEN 4 */
    makoto_cbca_028,  /* 28 ZANNEN 5 */
    makoto_cbca_029,  /* 29 ZANNEN 6 */
    0
};

/* script: 0 APPEAR JUNBI 1 */
const u16 makoto_cbca_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_000[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 47, 1),
    CMD(CM_RJA3, 7, 48, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 1 APPEAR JUNBI 2 */
const u16 makoto_cbca_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_001[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -1, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 2 APPEAR JUNBI 3 */
const u16 makoto_cbca_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_002[4] = {
    CMD(CM_IF_L, 2, 8196, 8195),
};

/* script: 3 APPEAR JUNBI 4 */
const u16 makoto_cbca_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_003[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 1, 1),
    CMD(CM_RJA3, 7, 11, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 4 APPEAR JUNBI 5 */
const u16 makoto_cbca_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_004[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 2, 1),
    CMD(CM_RJA3, 7, 12, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 5 APPEAR JUNBI 6 */
const u16 makoto_cbca_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_005[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 4, 1),
    CMD(CM_RJA3, 7, 13, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 6 APPEAR JUNBI 7 */
const u16 makoto_cbca_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_006[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 27, 1),
    CMD(CM_RJA3, 7, 28, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 7 APPEAR JUNBI 8 */
const u16 makoto_cbca_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_007[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 80, 0),
    CMD(CM_STOP, -80, 85, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 8 APPEAR 1 */
const u16 makoto_cbca_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_008[16] = {
    CMD(CM_IMGS, 0, 18, 0),
    CMD(CM_EXEC, 51, 50, 0),
    CMD(CM_STOP, -50, 50, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 9 APPEAR 2 */
const u16 makoto_cbca_009_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 makoto_cbca_009[16] = {
    CMD(CM_EXEC, 49, 49, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 10 APPEAR 3 */
const u16 makoto_cbca_010_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 makoto_cbca_010[16] = {
    CMD(CM_EXEC, 49, 50, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 11 APPEAR 4 */
const u16 makoto_cbca_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_011[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 25, 1),
    CMD(CM_RJA3, 7, 26, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 12 APPEAR 5 */
const u16 makoto_cbca_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_012[16] = {
    CMD(CM_RJA, 0, 0, 28),
    CMD(CM_RJA2, 0, 0, 30),
    CMD(CM_PJMP, 11, 8194, 8192),
    CMD(CM_PJMP, 16, 8195, 8193),
};

/* script: 13 APPEAR 6 */
const u16 makoto_cbca_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_013[16] = {
    CMD(CM_RJA, 8, 16, 1),
    CMD(CM_RJA2, 8, 18, 1),
    CMD(CM_PJMP, 16, 8194, 8192),
    CMD(CM_PJMP, 18, 8195, 8193),
};

/* script: 14 APPEAR 7 */
const u16 makoto_cbca_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_014[16] = {
    CMD(CM_RJA, 8, 16, 1),
    CMD(CM_RJA2, 8, 17, 1),
    CMD(CM_PJMP, 16, 8194, 8192),
    CMD(CM_PJMP, 10, 8195, 8193),
};

/* script: 15 APPEAR 8 */
const u16 makoto_cbca_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_015[16] = {
    CMD(CM_RJA, 8, 17, 1),
    CMD(CM_RJA2, 8, 18, 1),
    CMD(CM_PJMP, 10, 8194, 8192),
    CMD(CM_PJMP, 18, 8195, 8193),
};

/* script: 16 SP APPEAR 1 */
const u16 makoto_cbca_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_016[20] = {
    CMD(CM_RJA, 7, 59, 1),
    CMD(CM_RJA2, 7, 60, 1),
    CMD(CM_RJA3, 7, 61, 1),
    CMD(CM_PJMP, 12, 8194, 8192),
    CMD(CM_PJMP, 16, 8195, 8196),
};

/* script: 17 SP APPEAR 2 */
const u16 makoto_cbca_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_017[12] = {
    CMD(CM_RJA, 7, 62, 1),
    CMD(CM_RJA2, 7, 62, 3),
    CMD(CM_PJMP, 6, 8194, 8195),
};

/* script: 18 SP APPEAR 3 */
const u16 makoto_cbca_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_018[44] = {
    CMD(CM_RJA, 7, 63, 1),
    CMD(CM_RJA2, 7, 64, 1),
    CMD(CM_RJA3, 7, 65, 1),
    CMD(CM_RJA4, 7, 66, 1),
    CMD(CM_RJA5, 7, 67, 1),
    CMD(CM_RJA6, 7, 68, 1),
    CMD(CM_PJMP, 11, 8192, 16386),
    CMD(CM_PJMP, 14, 8194, 8195),
    CMD(CM_PJMP, 10, 8192, 16386),
    CMD(CM_PJMP, 16, 8196, 8197),
    CMD(CM_PJMP, 16, 8198, 8199),
};

/* script: 19 SP APPEAR 4 */
const u16 makoto_cbca_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_019[16] = {
    CMD(CM_RJA, 0, 7, 13),
    CMD(CM_RJA2, 0, 7, 15),
    CMD(CM_PJMP, 11, 8194, 8192),
    CMD(CM_PJMP, 16, 8195, 8193),
};

/* script: 20 SP APPEAR 5 */
const u16 makoto_cbca_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_020[16] = {
    CMD(CM_RJA, 8, 23, 1),
    CMD(CM_RJA2, 8, 25, 1),
    CMD(CM_PJMP, 8, 8194, 8192),
    CMD(CM_PJMP, 8, 8195, 8193),
};

/* script: 21 SP APPEAR 6 */
const u16 makoto_cbca_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_021[16] = {
    CMD(CM_RJA, 8, 23, 1),
    CMD(CM_RJA2, 8, 24, 1),
    CMD(CM_PJMP, 6, 8194, 8192),
    CMD(CM_PJMP, 16, 8195, 8193),
};

/* script: 22 SP APPEAR 7 */
const u16 makoto_cbca_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_022[16] = {
    CMD(CM_RJA, 8, 24, 1),
    CMD(CM_RJA2, 8, 25, 1),
    CMD(CM_PJMP, 10, 8194, 8192),
    CMD(CM_PJMP, 6, 8195, 8193),
};

/* script: 23 SP APPEAR 8 */
const u16 makoto_cbca_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_023[12] = {
    CMD(CM_RJA, 7, 69, 1),
    CMD(CM_RJA2, 7, 70, 1),
    CMD(CM_PJMP, 24, 8194, 8195),
};

/* script: 24 ZANNEN 1 */
const u16 makoto_cbca_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_024[12] = {
    CMD(CM_RJA, 7, 71, 1),
    CMD(CM_RJA2, 7, 71, 3),
    CMD(CM_PJMP, 6, 8194, 8195),
};

/* script: 25 ZANNEN 2 */
const u16 makoto_cbca_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_025[44] = {
    CMD(CM_RJA, 7, 72, 1),
    CMD(CM_RJA2, 7, 73, 1),
    CMD(CM_RJA3, 7, 74, 1),
    CMD(CM_RJA4, 7, 75, 1),
    CMD(CM_RJA5, 7, 76, 1),
    CMD(CM_RJA6, 7, 77, 1),
    CMD(CM_PJMP, 24, 8192, 16386),
    CMD(CM_PJMP, 16, 8194, 8195),
    CMD(CM_PJMP, 24, 8192, 16386),
    CMD(CM_PJMP, 24, 8196, 8197),
    CMD(CM_PJMP, 16, 8198, 8199),
};

/* script: 26 ZANNEN 3 */
const u16 makoto_cbca_026_head[4] = { HEAD(2, 0, 14, 0, 0, 0, 0) };
const u16 makoto_cbca_026[16] = {
    CMD(CM_EXEC, 49, 51, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 27 ZANNEN 4 */
const u16 makoto_cbca_027_head[4] = { HEAD(2, 0, 33, 0, 0, 0, 96) };
const u16 makoto_cbca_027[32] = {
    CMD(CM_CHKWF, 30, 8192, 8206),
    CMD(CM_S_CHG, 32, 16389, 8192),
    CMD(CM_S_CHG, 64, 16388, 8192),
    CMD(CM_S_CHG, 256, 16388, 8192),
    CMD(CM_S_CHG, 512, 16387, 8192),
    CMD(CM_S_CHG, 1024, 16386, 8192),
    CMD(CM_JPSS, 5, 73, 1),
    CMD(CM_JPSS, 5, 48, 1),
};

/* script: 28 ZANNEN 5 */
const u16 makoto_cbca_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 makoto_cbca_028[16] = {
    CMD(CM_RJA, 8, 2, 1),
    CMD(CM_RJA2, 7, 15, 1),
    CMD(CM_RJA3, 7, 16, 1),
    CMD(CM_RET, 0, 0, 0),
};

/* script: 29 ZANNEN 6 */
const u16 makoto_cbca_029_head[4] = { HEAD(2, 0, 15, 0, 0, 0, 0) };
const u16 makoto_cbca_029[16] = {
    CMD(CM_EXEC, 49, 66, 0),
    CMD(CM_IMGS, 0, 12, 0),
    CMD(CM_EXEC, 16, 5, 0),
    CMD(CM_RET, 0, 0, 0),
};

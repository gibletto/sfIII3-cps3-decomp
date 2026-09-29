/*
 * EFFECT_CHAR.C  Effect character scripts
 *
 * Scripts for effects drawn with character data: player effects (plef), ef01, the ef13 effect, the rival face panels (ag_face_panel_table) and effD4.
 * Each *_char_table is an index of animation scripts ending in 0 followed by the scripts, in the
 * format of the fighters' tables: an effect's work takes the table as its char_table and
 * set_char_move_init starts its scripts. See charscr.h for the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 plef_char_table_000[], plef_char_table_001[], plef_char_table_002[], plef_char_table_003[], plef_char_table_004[], plef_char_table_005[], plef_char_table_006[], plef_char_table_007[], plef_char_table_008[], plef_char_table_009[], plef_char_table_010[], plef_char_table_011[], plef_char_table_012[], plef_char_table_013[], plef_char_table_014[], plef_char_table_015[], plef_char_table_016[], plef_char_table_017[], plef_char_table_018[], plef_char_table_019[], plef_char_table_020[], plef_char_table_021[], plef_char_table_022[], plef_char_table_023[], plef_char_table_024[], plef_char_table_025[], plef_char_table_026[], plef_char_table_027[], plef_char_table_028[], plef_char_table_029[], plef_char_table_030[], plef_char_table_031[], plef_char_table_032[], plef_char_table_033[], plef_char_table_034[], plef_char_table_035[], plef_char_table_036[], plef_char_table_037[], plef_char_table_038[], plef_char_table_039[], plef_char_table_040[], plef_char_table_041[], plef_char_table_042[], plef_char_table_043[], plef_char_table_044[], plef_char_table_045[], plef_char_table_046[], plef_char_table_047[], plef_char_table_048[], plef_char_table_049[], plef_char_table_050[], plef_char_table_051[], plef_char_table_052[], plef_char_table_053[], plef_char_table_054[], plef_char_table_055[], plef_char_table_056[], plef_char_table_057[], plef_char_table_058[], plef_char_table_059[], plef_char_table_060[], plef_char_table_061[], plef_char_table_062[], plef_char_table_063[], plef_char_table_064[], plef_char_table_065[], plef_char_table_066[], plef_char_table_067[], plef_char_table_068[], plef_char_table_069[], plef_char_table_070[], plef_char_table_071[], plef_char_table_072[], plef_char_table_073[], plef_char_table_074[], plef_char_table_075[], plef_char_table_076[], plef_char_table_077[], plef_char_table_078[], plef_char_table_079[], plef_char_table_080[], plef_char_table_081[], plef_char_table_082[], plef_char_table_083[], plef_char_table_084[], plef_char_table_085[], plef_char_table_086[], plef_char_table_087[], plef_char_table_090[], plef_char_table_091[], plef_char_table_092[], plef_char_table_093[], plef_char_table_094[], plef_char_table_095[], plef_char_table_096[], plef_char_table_097[], plef_char_table_098[], plef_char_table_099[], plef_char_table_100[], plef_char_table_101[], plef_char_table_102[], plef_char_table_103[], plef_char_table_104[], plef_char_table_105[], plef_char_table_106[], plef_char_table_107[], plef_char_table_108[], plef_char_table_109[], plef_char_table_110[], plef_char_table_111[], plef_char_table_112[], plef_char_table_113[], plef_char_table_114[], plef_char_table_115[], plef_char_table_116[], plef_char_table_117[], plef_char_table_118[], plef_char_table_119[], plef_char_table_120[], plef_char_table_121[], plef_char_table_122[], plef_char_table_123[], plef_char_table_124[], plef_char_table_125[], plef_char_table_126[], plef_char_table_127[], plef_char_table_128[], plef_char_table_129[], plef_char_table_130[], plef_char_table_131[], plef_char_table_132[], plef_char_table_133[], plef_char_table_134[], plef_char_table_135[], plef_char_table_136[], plef_char_table_137[], plef_char_table_138[], plef_char_table_139[], plef_char_table_140[], plef_char_table_141[], plef_char_table_142[], plef_char_table_143[], plef_char_table_144[], plef_char_table_145[], plef_char_table_146[], plef_char_table_147[], plef_char_table_148[], plef_char_table_149[], plef_char_table_150[], plef_char_table_151[], plef_char_table_152[], plef_char_table_153[], plef_char_table_155[], plef_char_table_156[], plef_char_table_157[], plef_char_table_158[], plef_char_table_159[], plef_char_table_160[], plef_char_table_161[], plef_char_table_163[], plef_char_table_164[], plef_char_table_165[], plef_char_table_166[], plef_char_table_167[], plef_char_table_168[], plef_char_table_169[], plef_char_table_170[], plef_char_table_171[], plef_char_table_172[], plef_char_table_173[], plef_char_table_174[];
extern const u16 plef_char_table_000_head[];
extern const u16 plef_char_table_001_head[];
extern const u16 plef_char_table_002_head[];
extern const u16 plef_char_table_003_head[];
extern const u16 plef_char_table_004_head[];
extern const u16 plef_char_table_005_head[];
extern const u16 plef_char_table_006_head[];
extern const u16 plef_char_table_007_head[];
extern const u16 plef_char_table_008_head[];
extern const u16 plef_char_table_009_head[];
extern const u16 plef_char_table_010_head[];
extern const u16 plef_char_table_011_head[];
extern const u16 plef_char_table_012_head[];
extern const u16 plef_char_table_013_head[];
extern const u16 plef_char_table_014_head[];
extern const u16 plef_char_table_015_head[];
extern const u16 plef_char_table_016_head[];
extern const u16 plef_char_table_017_head[];
extern const u16 plef_char_table_018_head[];
extern const u16 plef_char_table_019_head[];
extern const u16 plef_char_table_020_head[];
extern const u16 plef_char_table_021_head[];
extern const u16 plef_char_table_022_head[];
extern const u16 plef_char_table_023_head[];
extern const u16 plef_char_table_024_head[];
extern const u16 plef_char_table_025_head[];
extern const u16 plef_char_table_026_head[];
extern const u16 plef_char_table_027_head[];
extern const u16 plef_char_table_028_head[];
extern const u16 plef_char_table_029_head[];
extern const u16 plef_char_table_030_head[];
extern const u16 plef_char_table_031_head[];
extern const u16 plef_char_table_032_head[];
extern const u16 plef_char_table_033_head[];
extern const u16 plef_char_table_034_head[];
extern const u16 plef_char_table_035_head[];
extern const u16 plef_char_table_036_head[];
extern const u16 plef_char_table_037_head[];
extern const u16 plef_char_table_038_head[];
extern const u16 plef_char_table_039_head[];
extern const u16 plef_char_table_040_head[];
extern const u16 plef_char_table_041_head[];
extern const u16 plef_char_table_042_head[];
extern const u16 plef_char_table_043_head[];
extern const u16 plef_char_table_044_head[];
extern const u16 plef_char_table_045_head[];
extern const u16 plef_char_table_046_head[];
extern const u16 plef_char_table_047_head[];
extern const u16 plef_char_table_048_head[];
extern const u16 plef_char_table_049_head[];
extern const u16 plef_char_table_050_head[];
extern const u16 plef_char_table_051_head[];
extern const u16 plef_char_table_052_head[];
extern const u16 plef_char_table_053_head[];
extern const u16 plef_char_table_054_head[];
extern const u16 plef_char_table_055_head[];
extern const u16 plef_char_table_056_head[];
extern const u16 plef_char_table_057_head[];
extern const u16 plef_char_table_058_head[];
extern const u16 plef_char_table_059_head[];
extern const u16 plef_char_table_060_head[];
extern const u16 plef_char_table_061_head[];
extern const u16 plef_char_table_062_head[];
extern const u16 plef_char_table_063_head[];
extern const u16 plef_char_table_064_head[];
extern const u16 plef_char_table_065_head[];
extern const u16 plef_char_table_066_head[];
extern const u16 plef_char_table_067_head[];
extern const u16 plef_char_table_068_head[];
extern const u16 plef_char_table_069_head[];
extern const u16 plef_char_table_070_head[];
extern const u16 plef_char_table_071_head[];
extern const u16 plef_char_table_072_head[];
extern const u16 plef_char_table_073_head[];
extern const u16 plef_char_table_074_head[];
extern const u16 plef_char_table_075_head[];
extern const u16 plef_char_table_076_head[];
extern const u16 plef_char_table_077_head[];
extern const u16 plef_char_table_078_head[];
extern const u16 plef_char_table_079_head[];
extern const u16 plef_char_table_080_head[];
extern const u16 plef_char_table_081_head[];
extern const u16 plef_char_table_082_head[];
extern const u16 plef_char_table_083_head[];
extern const u16 plef_char_table_084_head[];
extern const u16 plef_char_table_085_head[];
extern const u16 plef_char_table_086_head[];
extern const u16 plef_char_table_087_head[];
extern const u16 plef_char_table_090_head[];
extern const u16 plef_char_table_091_head[];
extern const u16 plef_char_table_092_head[];
extern const u16 plef_char_table_093_head[];
extern const u16 plef_char_table_094_head[];
extern const u16 plef_char_table_095_head[];
extern const u16 plef_char_table_096_head[];
extern const u16 plef_char_table_097_head[];
extern const u16 plef_char_table_098_head[];
extern const u16 plef_char_table_099_head[];
extern const u16 plef_char_table_100_head[];
extern const u16 plef_char_table_101_head[];
extern const u16 plef_char_table_102_head[];
extern const u16 plef_char_table_103_head[];
extern const u16 plef_char_table_104_head[];
extern const u16 plef_char_table_105_head[];
extern const u16 plef_char_table_106_head[];
extern const u16 plef_char_table_107_head[];
extern const u16 plef_char_table_108_head[];
extern const u16 plef_char_table_109_head[];
extern const u16 plef_char_table_110_head[];
extern const u16 plef_char_table_111_head[];
extern const u16 plef_char_table_112_head[];
extern const u16 plef_char_table_113_head[];
extern const u16 plef_char_table_114_head[];
extern const u16 plef_char_table_115_head[];
extern const u16 plef_char_table_116_head[];
extern const u16 plef_char_table_117_head[];
extern const u16 plef_char_table_118_head[];
extern const u16 plef_char_table_119_head[];
extern const u16 plef_char_table_120_head[];
extern const u16 plef_char_table_121_head[];
extern const u16 plef_char_table_122_head[];
extern const u16 plef_char_table_123_head[];
extern const u16 plef_char_table_124_head[];
extern const u16 plef_char_table_125_head[];
extern const u16 plef_char_table_126_head[];
extern const u16 plef_char_table_127_head[];
extern const u16 plef_char_table_128_head[];
extern const u16 plef_char_table_129_head[];
extern const u16 plef_char_table_130_head[];
extern const u16 plef_char_table_131_head[];
extern const u16 plef_char_table_132_head[];
extern const u16 plef_char_table_133_head[];
extern const u16 plef_char_table_134_head[];
extern const u16 plef_char_table_135_head[];
extern const u16 plef_char_table_136_head[];
extern const u16 plef_char_table_137_head[];
extern const u16 plef_char_table_138_head[];
extern const u16 plef_char_table_139_head[];
extern const u16 plef_char_table_140_head[];
extern const u16 plef_char_table_141_head[];
extern const u16 plef_char_table_142_head[];
extern const u16 plef_char_table_143_head[];
extern const u16 plef_char_table_144_head[];
extern const u16 plef_char_table_145_head[];
extern const u16 plef_char_table_146_head[];
extern const u16 plef_char_table_147_head[];
extern const u16 plef_char_table_148_head[];
extern const u16 plef_char_table_149_head[];
extern const u16 plef_char_table_150_head[];
extern const u16 plef_char_table_151_head[];
extern const u16 plef_char_table_152_head[];
extern const u16 plef_char_table_153_head[];
extern const u16 plef_char_table_155_head[];
extern const u16 plef_char_table_156_head[];
extern const u16 plef_char_table_157_head[];
extern const u16 plef_char_table_158_head[];
extern const u16 plef_char_table_159_head[];
extern const u16 plef_char_table_160_head[];
extern const u16 plef_char_table_161_head[];
extern const u16 plef_char_table_163_head[];
extern const u16 plef_char_table_164_head[];
extern const u16 plef_char_table_165_head[];
extern const u16 plef_char_table_166_head[];
extern const u16 plef_char_table_167_head[];
extern const u16 plef_char_table_168_head[];
extern const u16 plef_char_table_169_head[];
extern const u16 plef_char_table_170_head[];
extern const u16 plef_char_table_171_head[];
extern const u16 plef_char_table_172_head[];
extern const u16 plef_char_table_173_head[];
extern const u16 plef_char_table_174_head[];
extern const u16 ef01_char_table_000[], ef01_char_table_001[], ef01_char_table_002[], ef01_char_table_003[], ef01_char_table_004[], ef01_char_table_005[], ef01_char_table_006[], ef01_char_table_008[], ef01_char_table_009[], ef01_char_table_010[], ef01_char_table_011[], ef01_char_table_012[], ef01_char_table_013[], ef01_char_table_014[], ef01_char_table_015[], ef01_char_table_016[], ef01_char_table_017[], ef01_char_table_018[], ef01_char_table_019[], ef01_char_table_020[], ef01_char_table_021[], ef01_char_table_022[], ef01_char_table_023[], ef01_char_table_024[], ef01_char_table_025[], ef01_char_table_026[], ef01_char_table_027[], ef01_char_table_028[], ef01_char_table_029[], ef01_char_table_031[], ef01_char_table_032[], ef01_char_table_033[], ef01_char_table_034[], ef01_char_table_035[], ef01_char_table_036[], ef01_char_table_038[], ef01_char_table_047[], ef01_char_table_048[], ef01_char_table_049[], ef01_char_table_050[], ef01_char_table_051[], ef01_char_table_052[], ef01_char_table_053[], ef01_char_table_054[], ef01_char_table_055[], ef01_char_table_056[], ef01_char_table_057[], ef01_char_table_058[], ef01_char_table_059[], ef01_char_table_060[], ef01_char_table_061[], ef01_char_table_062[], ef01_char_table_063[], ef01_char_table_064[], ef01_char_table_065[], ef01_char_table_066[], ef01_char_table_067[], ef01_char_table_068[], ef01_char_table_069[], ef01_char_table_070[], ef01_char_table_071[], ef01_char_table_072[], ef01_char_table_073[], ef01_char_table_074[], ef01_char_table_075[], ef01_char_table_076[], ef01_char_table_077[];
extern const u16 ef01_char_table_000_head[];
extern const u16 ef01_char_table_001_head[];
extern const u16 ef01_char_table_002_head[];
extern const u16 ef01_char_table_003_head[];
extern const u16 ef01_char_table_004_head[];
extern const u16 ef01_char_table_005_head[];
extern const u16 ef01_char_table_006_head[];
extern const u16 ef01_char_table_008_head[];
extern const u16 ef01_char_table_009_head[];
extern const u16 ef01_char_table_010_head[];
extern const u16 ef01_char_table_011_head[];
extern const u16 ef01_char_table_012_head[];
extern const u16 ef01_char_table_013_head[];
extern const u16 ef01_char_table_014_head[];
extern const u16 ef01_char_table_015_head[];
extern const u16 ef01_char_table_016_head[];
extern const u16 ef01_char_table_017_head[];
extern const u16 ef01_char_table_018_head[];
extern const u16 ef01_char_table_019_head[];
extern const u16 ef01_char_table_020_head[];
extern const u16 ef01_char_table_021_head[];
extern const u16 ef01_char_table_022_head[];
extern const u16 ef01_char_table_023_head[];
extern const u16 ef01_char_table_024_head[];
extern const u16 ef01_char_table_025_head[];
extern const u16 ef01_char_table_026_head[];
extern const u16 ef01_char_table_027_head[];
extern const u16 ef01_char_table_028_head[];
extern const u16 ef01_char_table_029_head[];
extern const u16 ef01_char_table_031_head[];
extern const u16 ef01_char_table_032_head[];
extern const u16 ef01_char_table_033_head[];
extern const u16 ef01_char_table_034_head[];
extern const u16 ef01_char_table_035_head[];
extern const u16 ef01_char_table_036_head[];
extern const u16 ef01_char_table_038_head[];
extern const u16 ef01_char_table_047_head[];
extern const u16 ef01_char_table_048_head[];
extern const u16 ef01_char_table_049_head[];
extern const u16 ef01_char_table_050_head[];
extern const u16 ef01_char_table_051_head[];
extern const u16 ef01_char_table_052_head[];
extern const u16 ef01_char_table_053_head[];
extern const u16 ef01_char_table_054_head[];
extern const u16 ef01_char_table_055_head[];
extern const u16 ef01_char_table_056_head[];
extern const u16 ef01_char_table_057_head[];
extern const u16 ef01_char_table_058_head[];
extern const u16 ef01_char_table_059_head[];
extern const u16 ef01_char_table_060_head[];
extern const u16 ef01_char_table_061_head[];
extern const u16 ef01_char_table_062_head[];
extern const u16 ef01_char_table_063_head[];
extern const u16 ef01_char_table_064_head[];
extern const u16 ef01_char_table_065_head[];
extern const u16 ef01_char_table_066_head[];
extern const u16 ef01_char_table_067_head[];
extern const u16 ef01_char_table_068_head[];
extern const u16 ef01_char_table_069_head[];
extern const u16 ef01_char_table_070_head[];
extern const u16 ef01_char_table_071_head[];
extern const u16 ef01_char_table_072_head[];
extern const u16 ef01_char_table_073_head[];
extern const u16 ef01_char_table_074_head[];
extern const u16 ef01_char_table_075_head[];
extern const u16 ef01_char_table_076_head[];
extern const u16 ef01_char_table_077_head[];
extern const u16 ef13_char_table_000[], ef13_char_table_001[], ef13_char_table_002[], ef13_char_table_003[], ef13_char_table_004[], ef13_char_table_005[], ef13_char_table_006[], ef13_char_table_007[], ef13_char_table_008[], ef13_char_table_010[], ef13_char_table_011[], ef13_char_table_013[], ef13_char_table_014[], ef13_char_table_015[], ef13_char_table_016[], ef13_char_table_017[], ef13_char_table_018[], ef13_char_table_019[], ef13_char_table_020[], ef13_char_table_021[], ef13_char_table_022[], ef13_char_table_023[], ef13_char_table_024[], ef13_char_table_025[], ef13_char_table_026[], ef13_char_table_027[], ef13_char_table_028[], ef13_char_table_029[], ef13_char_table_030[], ef13_char_table_031[], ef13_char_table_032[], ef13_char_table_033[], ef13_char_table_034[], ef13_char_table_035[], ef13_char_table_036[], ef13_char_table_037[], ef13_char_table_038[], ef13_char_table_039[], ef13_char_table_040[], ef13_char_table_041[], ef13_char_table_042[], ef13_char_table_043[], ef13_char_table_044[], ef13_char_table_045[], ef13_char_table_046[], ef13_char_table_047[], ef13_char_table_048[], ef13_char_table_049[], ef13_char_table_050[], ef13_char_table_051[], ef13_char_table_052[], ef13_char_table_053[], ef13_char_table_056[], ef13_char_table_057[], ef13_char_table_058[], ef13_char_table_059[], ef13_char_table_060[], ef13_char_table_061[], ef13_char_table_062[], ef13_char_table_063[], ef13_char_table_064[], ef13_char_table_065[], ef13_char_table_066[], ef13_char_table_067[], ef13_char_table_068[], ef13_char_table_069[], ef13_char_table_070[], ef13_char_table_071[], ef13_char_table_072[], ef13_char_table_073[], ef13_char_table_074[], ef13_char_table_075[], ef13_char_table_076[], ef13_char_table_077[], ef13_char_table_078[], ef13_char_table_079[], ef13_char_table_080[], ef13_char_table_081[], ef13_char_table_082[], ef13_char_table_083[], ef13_char_table_084[], ef13_char_table_085[], ef13_char_table_086[], ef13_char_table_087[], ef13_char_table_088[], ef13_char_table_089[], ef13_char_table_090[], ef13_char_table_091[], ef13_char_table_092[], ef13_char_table_093[], ef13_char_table_094[], ef13_char_table_095[], ef13_char_table_096[], ef13_char_table_097[], ef13_char_table_098[], ef13_char_table_099[], ef13_char_table_100[], ef13_char_table_101[], ef13_char_table_102[], ef13_char_table_103[], ef13_char_table_104[], ef13_char_table_105[], ef13_char_table_106[], ef13_char_table_107[], ef13_char_table_108[], ef13_char_table_109[], ef13_char_table_110[], ef13_char_table_111[], ef13_char_table_112[], ef13_char_table_113[], ef13_char_table_114[], ef13_char_table_115[], ef13_char_table_116[], ef13_char_table_117[], ef13_char_table_118[], ef13_char_table_119[], ef13_char_table_120[], ef13_char_table_121[], ef13_char_table_122[], ef13_char_table_123[], ef13_char_table_124[], ef13_char_table_125[], ef13_char_table_126[], ef13_char_table_127[], ef13_char_table_128[], ef13_char_table_129[], ef13_char_table_130[], ef13_char_table_131[], ef13_char_table_132[], ef13_char_table_133[], ef13_char_table_134[], ef13_char_table_135[], ef13_char_table_136[], ef13_char_table_137[], ef13_char_table_138[], ef13_char_table_139[], ef13_char_table_140[], ef13_char_table_141[], ef13_char_table_142[], ef13_char_table_143[], ef13_char_table_144[], ef13_char_table_145[], ef13_char_table_146[], ef13_char_table_147[], ef13_char_table_148[], ef13_char_table_149[], ef13_char_table_150[], ef13_char_table_151[], ef13_char_table_152[], ef13_char_table_153[], ef13_char_table_154[], ef13_char_table_155[], ef13_char_table_156[], ef13_char_table_157[], ef13_char_table_158[], ef13_char_table_159[], ef13_char_table_160[], ef13_char_table_161[], ef13_char_table_162[], ef13_char_table_163[], ef13_char_table_164[], ef13_char_table_165[], ef13_char_table_166[], ef13_char_table_167[], ef13_char_table_168[], ef13_char_table_169[], ef13_char_table_170[], ef13_char_table_171[], ef13_char_table_172[], ef13_char_table_173[], ef13_char_table_174[], ef13_char_table_175[], ef13_char_table_176[], ef13_char_table_177[], ef13_char_table_178[], ef13_char_table_179[], ef13_char_table_184[], ef13_char_table_180[], ef13_char_table_181[], ef13_char_table_182[], ef13_char_table_183[], ef13_char_table_189[], ef13_char_table_190[], ef13_char_table_191[], ef13_char_table_192[], ef13_char_table_193[], ef13_char_table_194[], ef13_char_table_195[], ef13_char_table_196[], ef13_char_table_197[], ef13_char_table_198[], ef13_char_table_199[], ef13_char_table_200[], ef13_char_table_201[], ef13_char_table_202[], ef13_char_table_203[], ef13_char_table_204[], ef13_char_table_205[], ef13_char_table_206[], ef13_char_table_207[], ef13_char_table_208[], ef13_char_table_209[], ef13_char_table_210[], ef13_char_table_211[], ef13_char_table_212[], ef13_char_table_213[], ef13_char_table_214[], ef13_char_table_215[], ef13_char_table_216[], ef13_char_table_217[], ef13_char_table_218[], ef13_char_table_219[], ef13_char_table_220[], ef13_char_table_221[], ef13_char_table_222[], ef13_char_table_223[], ef13_char_table_224[], ef13_char_table_225[];
extern const u16 ef13_char_table_000_head[];
extern const u16 ef13_char_table_001_head[];
extern const u16 ef13_char_table_002_head[];
extern const u16 ef13_char_table_003_head[];
extern const u16 ef13_char_table_004_head[];
extern const u16 ef13_char_table_005_head[];
extern const u16 ef13_char_table_006_head[];
extern const u16 ef13_char_table_007_head[];
extern const u16 ef13_char_table_008_head[];
extern const u16 ef13_char_table_010_head[];
extern const u16 ef13_char_table_011_head[];
extern const u16 ef13_char_table_013_head[];
extern const u16 ef13_char_table_014_head[];
extern const u16 ef13_char_table_015_head[];
extern const u16 ef13_char_table_016_head[];
extern const u16 ef13_char_table_017_head[];
extern const u16 ef13_char_table_018_head[];
extern const u16 ef13_char_table_019_head[];
extern const u16 ef13_char_table_020_head[];
extern const u16 ef13_char_table_021_head[];
extern const u16 ef13_char_table_022_head[];
extern const u16 ef13_char_table_023_head[];
extern const u16 ef13_char_table_024_head[];
extern const u16 ef13_char_table_025_head[];
extern const u16 ef13_char_table_026_head[];
extern const u16 ef13_char_table_027_head[];
extern const u16 ef13_char_table_028_head[];
extern const u16 ef13_char_table_029_head[];
extern const u16 ef13_char_table_030_head[];
extern const u16 ef13_char_table_031_head[];
extern const u16 ef13_char_table_032_head[];
extern const u16 ef13_char_table_033_head[];
extern const u16 ef13_char_table_034_head[];
extern const u16 ef13_char_table_035_head[];
extern const u16 ef13_char_table_036_head[];
extern const u16 ef13_char_table_037_head[];
extern const u16 ef13_char_table_038_head[];
extern const u16 ef13_char_table_039_head[];
extern const u16 ef13_char_table_040_head[];
extern const u16 ef13_char_table_041_head[];
extern const u16 ef13_char_table_042_head[];
extern const u16 ef13_char_table_043_head[];
extern const u16 ef13_char_table_044_head[];
extern const u16 ef13_char_table_045_head[];
extern const u16 ef13_char_table_046_head[];
extern const u16 ef13_char_table_047_head[];
extern const u16 ef13_char_table_048_head[];
extern const u16 ef13_char_table_049_head[];
extern const u16 ef13_char_table_050_head[];
extern const u16 ef13_char_table_051_head[];
extern const u16 ef13_char_table_052_head[];
extern const u16 ef13_char_table_053_head[];
extern const u16 ef13_char_table_056_head[];
extern const u16 ef13_char_table_057_head[];
extern const u16 ef13_char_table_058_head[];
extern const u16 ef13_char_table_059_head[];
extern const u16 ef13_char_table_060_head[];
extern const u16 ef13_char_table_061_head[];
extern const u16 ef13_char_table_062_head[];
extern const u16 ef13_char_table_063_head[];
extern const u16 ef13_char_table_064_head[];
extern const u16 ef13_char_table_065_head[];
extern const u16 ef13_char_table_066_head[];
extern const u16 ef13_char_table_067_head[];
extern const u16 ef13_char_table_068_head[];
extern const u16 ef13_char_table_069_head[];
extern const u16 ef13_char_table_070_head[];
extern const u16 ef13_char_table_071_head[];
extern const u16 ef13_char_table_072_head[];
extern const u16 ef13_char_table_073_head[];
extern const u16 ef13_char_table_074_head[];
extern const u16 ef13_char_table_075_head[];
extern const u16 ef13_char_table_076_head[];
extern const u16 ef13_char_table_077_head[];
extern const u16 ef13_char_table_078_head[];
extern const u16 ef13_char_table_079_head[];
extern const u16 ef13_char_table_080_head[];
extern const u16 ef13_char_table_081_head[];
extern const u16 ef13_char_table_082_head[];
extern const u16 ef13_char_table_083_head[];
extern const u16 ef13_char_table_084_head[];
extern const u16 ef13_char_table_085_head[];
extern const u16 ef13_char_table_086_head[];
extern const u16 ef13_char_table_087_head[];
extern const u16 ef13_char_table_088_head[];
extern const u16 ef13_char_table_089_head[];
extern const u16 ef13_char_table_090_head[];
extern const u16 ef13_char_table_091_head[];
extern const u16 ef13_char_table_092_head[];
extern const u16 ef13_char_table_093_head[];
extern const u16 ef13_char_table_094_head[];
extern const u16 ef13_char_table_095_head[];
extern const u16 ef13_char_table_096_head[];
extern const u16 ef13_char_table_097_head[];
extern const u16 ef13_char_table_098_head[];
extern const u16 ef13_char_table_099_head[];
extern const u16 ef13_char_table_100_head[];
extern const u16 ef13_char_table_101_head[];
extern const u16 ef13_char_table_102_head[];
extern const u16 ef13_char_table_103_head[];
extern const u16 ef13_char_table_104_head[];
extern const u16 ef13_char_table_105_head[];
extern const u16 ef13_char_table_106_head[];
extern const u16 ef13_char_table_107_head[];
extern const u16 ef13_char_table_108_head[];
extern const u16 ef13_char_table_109_head[];
extern const u16 ef13_char_table_110_head[];
extern const u16 ef13_char_table_111_head[];
extern const u16 ef13_char_table_112_head[];
extern const u16 ef13_char_table_113_head[];
extern const u16 ef13_char_table_114_head[];
extern const u16 ef13_char_table_115_head[];
extern const u16 ef13_char_table_116_head[];
extern const u16 ef13_char_table_117_head[];
extern const u16 ef13_char_table_118_head[];
extern const u16 ef13_char_table_119_head[];
extern const u16 ef13_char_table_120_head[];
extern const u16 ef13_char_table_121_head[];
extern const u16 ef13_char_table_122_head[];
extern const u16 ef13_char_table_123_head[];
extern const u16 ef13_char_table_124_head[];
extern const u16 ef13_char_table_125_head[];
extern const u16 ef13_char_table_126_head[];
extern const u16 ef13_char_table_127_head[];
extern const u16 ef13_char_table_128_head[];
extern const u16 ef13_char_table_129_head[];
extern const u16 ef13_char_table_130_head[];
extern const u16 ef13_char_table_131_head[];
extern const u16 ef13_char_table_132_head[];
extern const u16 ef13_char_table_133_head[];
extern const u16 ef13_char_table_134_head[];
extern const u16 ef13_char_table_135_head[];
extern const u16 ef13_char_table_136_head[];
extern const u16 ef13_char_table_137_head[];
extern const u16 ef13_char_table_138_head[];
extern const u16 ef13_char_table_139_head[];
extern const u16 ef13_char_table_140_head[];
extern const u16 ef13_char_table_141_head[];
extern const u16 ef13_char_table_142_head[];
extern const u16 ef13_char_table_143_head[];
extern const u16 ef13_char_table_144_head[];
extern const u16 ef13_char_table_145_head[];
extern const u16 ef13_char_table_146_head[];
extern const u16 ef13_char_table_147_head[];
extern const u16 ef13_char_table_148_head[];
extern const u16 ef13_char_table_149_head[];
extern const u16 ef13_char_table_150_head[];
extern const u16 ef13_char_table_151_head[];
extern const u16 ef13_char_table_152_head[];
extern const u16 ef13_char_table_153_head[];
extern const u16 ef13_char_table_154_head[];
extern const u16 ef13_char_table_155_head[];
extern const u16 ef13_char_table_156_head[];
extern const u16 ef13_char_table_157_head[];
extern const u16 ef13_char_table_158_head[];
extern const u16 ef13_char_table_159_head[];
extern const u16 ef13_char_table_160_head[];
extern const u16 ef13_char_table_161_head[];
extern const u16 ef13_char_table_162_head[];
extern const u16 ef13_char_table_163_head[];
extern const u16 ef13_char_table_164_head[];
extern const u16 ef13_char_table_165_head[];
extern const u16 ef13_char_table_166_head[];
extern const u16 ef13_char_table_167_head[];
extern const u16 ef13_char_table_168_head[];
extern const u16 ef13_char_table_169_head[];
extern const u16 ef13_char_table_170_head[];
extern const u16 ef13_char_table_171_head[];
extern const u16 ef13_char_table_172_head[];
extern const u16 ef13_char_table_173_head[];
extern const u16 ef13_char_table_174_head[];
extern const u16 ef13_char_table_175_head[];
extern const u16 ef13_char_table_176_head[];
extern const u16 ef13_char_table_177_head[];
extern const u16 ef13_char_table_178_head[];
extern const u16 ef13_char_table_179_head[];
extern const u16 ef13_char_table_184_head[];
extern const u16 ef13_char_table_180_head[];
extern const u16 ef13_char_table_181_head[];
extern const u16 ef13_char_table_182_head[];
extern const u16 ef13_char_table_183_head[];
extern const u16 ef13_char_table_189_head[];
extern const u16 ef13_char_table_190_head[];
extern const u16 ef13_char_table_191_head[];
extern const u16 ef13_char_table_192_head[];
extern const u16 ef13_char_table_193_head[];
extern const u16 ef13_char_table_194_head[];
extern const u16 ef13_char_table_195_head[];
extern const u16 ef13_char_table_196_head[];
extern const u16 ef13_char_table_197_head[];
extern const u16 ef13_char_table_198_head[];
extern const u16 ef13_char_table_199_head[];
extern const u16 ef13_char_table_200_head[];
extern const u16 ef13_char_table_201_head[];
extern const u16 ef13_char_table_202_head[];
extern const u16 ef13_char_table_203_head[];
extern const u16 ef13_char_table_204_head[];
extern const u16 ef13_char_table_205_head[];
extern const u16 ef13_char_table_206_head[];
extern const u16 ef13_char_table_207_head[];
extern const u16 ef13_char_table_208_head[];
extern const u16 ef13_char_table_209_head[];
extern const u16 ef13_char_table_210_head[];
extern const u16 ef13_char_table_211_head[];
extern const u16 ef13_char_table_212_head[];
extern const u16 ef13_char_table_213_head[];
extern const u16 ef13_char_table_214_head[];
extern const u16 ef13_char_table_215_head[];
extern const u16 ef13_char_table_216_head[];
extern const u16 ef13_char_table_217_head[];
extern const u16 ef13_char_table_218_head[];
extern const u16 ef13_char_table_219_head[];
extern const u16 ef13_char_table_220_head[];
extern const u16 ef13_char_table_221_head[];
extern const u16 ef13_char_table_222_head[];
extern const u16 ef13_char_table_223_head[];
extern const u16 ef13_char_table_224_head[];
extern const u16 ef13_char_table_225_head[];
extern const u16 ag_face_panel_table_unused[], ag_face_panel_table_000[];
extern const u16 ag_face_panel_table_unused_head[];
extern const u16 ag_face_panel_table_000_head[];
extern const u16 effD4_char_table_000[], effD4_char_table_001[];
extern const u16 effD4_char_table_000_head[];
extern const u16 effD4_char_table_001_head[];

/* plef_char_table scripts: 175 entries */
const u16* const plef_char_table[176] = {
    plef_char_table_000, plef_char_table_001, plef_char_table_002, plef_char_table_003, plef_char_table_004, plef_char_table_005,
    plef_char_table_006, plef_char_table_007, plef_char_table_008, plef_char_table_009, plef_char_table_010, plef_char_table_011,
    plef_char_table_012, plef_char_table_013, plef_char_table_014, plef_char_table_015, plef_char_table_016, plef_char_table_017,
    plef_char_table_018, plef_char_table_019, plef_char_table_020, plef_char_table_021, plef_char_table_022, plef_char_table_023,
    plef_char_table_024, plef_char_table_025, plef_char_table_026, plef_char_table_027, plef_char_table_028, plef_char_table_029,
    plef_char_table_030, plef_char_table_031, plef_char_table_032, plef_char_table_033, plef_char_table_034, plef_char_table_035,
    plef_char_table_036, plef_char_table_037, plef_char_table_038, plef_char_table_039, plef_char_table_040, plef_char_table_041,
    plef_char_table_042, plef_char_table_043, plef_char_table_044, plef_char_table_045, plef_char_table_046, plef_char_table_047,
    plef_char_table_048, plef_char_table_049, plef_char_table_050, plef_char_table_051, plef_char_table_052, plef_char_table_053,
    plef_char_table_054, plef_char_table_055, plef_char_table_056, plef_char_table_057, plef_char_table_058, plef_char_table_059,
    plef_char_table_060, plef_char_table_061, plef_char_table_062, plef_char_table_063, plef_char_table_064, plef_char_table_065,
    plef_char_table_066, plef_char_table_067, plef_char_table_068, plef_char_table_069, plef_char_table_070, plef_char_table_071,
    plef_char_table_072, plef_char_table_073, plef_char_table_074, plef_char_table_075, plef_char_table_076, plef_char_table_077,
    plef_char_table_078, plef_char_table_079, plef_char_table_080, plef_char_table_081, plef_char_table_082, plef_char_table_083,
    plef_char_table_084, plef_char_table_085, plef_char_table_086, plef_char_table_087, plef_char_table_080, plef_char_table_080,
    plef_char_table_090, plef_char_table_091, plef_char_table_092, plef_char_table_093, plef_char_table_094, plef_char_table_095,
    plef_char_table_096, plef_char_table_097, plef_char_table_098, plef_char_table_099, plef_char_table_100, plef_char_table_101,
    plef_char_table_102, plef_char_table_103, plef_char_table_104, plef_char_table_105, plef_char_table_106, plef_char_table_107,
    plef_char_table_108, plef_char_table_109, plef_char_table_110, plef_char_table_111, plef_char_table_112, plef_char_table_113,
    plef_char_table_114, plef_char_table_115, plef_char_table_116, plef_char_table_117, plef_char_table_118, plef_char_table_119,
    plef_char_table_120, plef_char_table_121, plef_char_table_122, plef_char_table_123, plef_char_table_124, plef_char_table_125,
    plef_char_table_126, plef_char_table_127, plef_char_table_128, plef_char_table_129, plef_char_table_130, plef_char_table_131,
    plef_char_table_132, plef_char_table_133, plef_char_table_134, plef_char_table_135, plef_char_table_136, plef_char_table_137,
    plef_char_table_138, plef_char_table_139, plef_char_table_140, plef_char_table_141, plef_char_table_142, plef_char_table_143,
    plef_char_table_144, plef_char_table_145, plef_char_table_146, plef_char_table_147, plef_char_table_148, plef_char_table_149,
    plef_char_table_150, plef_char_table_151, plef_char_table_152, plef_char_table_153, plef_char_table_153, plef_char_table_155,
    plef_char_table_156, plef_char_table_157, plef_char_table_158, plef_char_table_159, plef_char_table_160, plef_char_table_161,
    plef_char_table_161, plef_char_table_163, plef_char_table_164, plef_char_table_165, plef_char_table_166, plef_char_table_167,
    plef_char_table_168, plef_char_table_169, plef_char_table_170, plef_char_table_171, plef_char_table_172, plef_char_table_173,
    plef_char_table_174,
    0
};

const u16 plef_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_000[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2AC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2AC5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2AC6),
    L2(3, 1, 0, 0, 0, 0, 0, 0x2AC6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2AC6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_001[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B0D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B0F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B10),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B11),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B15),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B15),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_002[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9832),
    L2(4, 0, 303, 0, 0, 0, 0, 0x9833),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9834),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9835),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9836),
    L2(4, 0, 303, 0, 0, 0, 0, 0x9837),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9838),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9839),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_003[28] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x983A),
    L2(5, 0, 303, 0, 0, 0, 0, 0x983B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x983C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x983D),
    L2(5, 0, 303, 0, 0, 0, 0, 0x983E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x983F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_004[24] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9840),
    L2(5, 0, 316, 0, 0, 0, 0, 0x9841),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9842),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9843),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9844),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_005[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9846),
    L2(4, 0, 315, 0, 0, 0, 0, 0x9847),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9848),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9849),
    L2(4, 0, 0, 0, 0, 0, 0, 0x984A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x984B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x984C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x984D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_006[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9873),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9874),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9875),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9876),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9877),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9878),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9879),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9879),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_007[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x987A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x987B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x987C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x987D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x987E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x987F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9880),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9880),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_008[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F77),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F78),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F79),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F7C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_009[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F7F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F80),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F81),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F82),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F82),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_010[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97B9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x97B9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_011[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97BF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x97C0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_012[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x97C7),
    L2(250, 255, 0, 0, 0, 0, 0, 0x97C7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_013[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0x9F0F),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F10),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F11),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F15),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F16),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F17),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F18),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F19),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F19),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_014[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0x9F1A),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F22),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F24),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_015[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0x9F25),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F26),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F27),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F28),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F29),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F2F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_016[56] = {
    L2(250, 131, 0, 0, 0, 0, 0, 0x9F30),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F31),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F32),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F33),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F34),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F35),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F36),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F37),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F38),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F39),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F3A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F3A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_017[100] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 147, 0, 0, 0, 0, 0, 0x9F40),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F41),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F42),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F43),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F44),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F45),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F46),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F47),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F48),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F49),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4F),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0x9F50),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F52),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F53),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F54),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F54),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_018[92] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 144, 0, 0, 0, 0, 0, 0x9FBC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FBD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FBE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FBF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC8),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0x9FC9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FCA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FCB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FCE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_019[28] = {
    L2(2, 1, 0, 0, 0, 0, 0, 0x9F50),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F52),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F53),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F54),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F54),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_020[32] = {
    L2(3, 1, 0, 0, 0, 0, 0, 0x9FC9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FCE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_021[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F73),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F74),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F75),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F76),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F76),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_022[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F65),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F66),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F67),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F68),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F69),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F6D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F6D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_023[60] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F58),
    L2(4, 0, 283, 0, 0, 0, 0, 0x9F59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F5B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F5C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F5D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F5E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F5F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F60),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F63),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F64),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F64),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_024[84] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x981E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x981F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9820),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9821),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9822),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9823),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9824),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9825),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9826),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9827),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9828),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9829),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x982F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9830),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9830),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_025[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D0B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D0C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D0F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D0F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_026[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2160),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2161),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2162),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2163),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2164),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2165),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2166),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2167),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2168),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2169),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_027[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x216C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x216F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2170),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2171),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2172),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2173),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2174),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2175),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2176),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2177),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_028[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9EF3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9EF4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9EF5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9EF6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_029[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9EF9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9EFA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9EFB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9EFC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EFC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_030[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F06),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F07),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F08),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F09),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F0A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F0B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F0D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F0E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F0E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_031[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EFD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EFE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EFF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F00),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F01),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F02),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F03),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F04),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F05),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F05),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_032[60] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9881),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9882),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9883),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9884),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9885),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9886),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9887),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9888),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9889),
    L2(2, 0, 0, 0, 0, 0, 0, 0x988A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x988B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x988C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x988D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x988D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_033[88] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7D),
    CMD(CM_PAXY, 0, 320, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7E),
    CMD(CM_PAXY, 0, 384, 288),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7F),
    CMD(CM_PAXY, 0, 448, 320),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D80),
    CMD(CM_PAXY, 0, 512, 352),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D81),
    CMD(CM_PAXY, 0, 576, 384),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D82),
    CMD(CM_PAXY, 0, 640, 416),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D83),
    CMD(CM_PAXY, 0, 704, 448),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D84),
    CMD(CM_PAXY, 0, 768, 480),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D85),
    CMD(CM_PAXY, 0, 832, 512),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_PAXY, 0, 896, 544),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_034[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D8F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D90),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D91),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D92),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D94),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D96),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D96),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_035[32] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D87),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D88),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D8B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x2D8C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_036[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D28),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D29),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D2F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D30),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D31),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D32),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D33),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9D34),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D35),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D36),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D37),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_037[36] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D88),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D89),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D8F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_038[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D38),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D39),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D3F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D40),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D41),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D42),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D43),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9D44),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D45),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D46),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_039[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D68),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D69),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D6F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D70),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D71),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D72),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_040[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D48),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D49),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D4F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D50),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D51),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D52),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D53),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9D54),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D55),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D56),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D57),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_041[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D78),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D79),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D7F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D80),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D81),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D82),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_042[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D58),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D59),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5A),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5E),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D5F),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D60),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D61),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D62),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D63),
    L2(8, 1, 0, 0, 0, 0, 0, 0x9D64),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D65),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D66),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9D67),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_043[48] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D98),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D99),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9D),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9E),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D9F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA1),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_044[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(3, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x219A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_045[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x21AC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_046[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x21AA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_047[60] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0x9881),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9882),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9883),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9884),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9885),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9886),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9887),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9888),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9889),
    L2(4, 0, 0, 0, 1, 0, 0, 0x988A),
    L2(4, 0, 0, 0, 1, 0, 0, 0x988B),
    L2(5, 0, 0, 0, 1, 0, 0, 0x988C),
    L2(5, 0, 0, 0, 1, 0, 0, 0x988D),
    L2(250, 255, 0, 0, 1, 0, 0, 0x988D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_048[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C7E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9C80),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9C81),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9C82),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9C83),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9C84),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9C85),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9C86),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9C87),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C87),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_049[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98AB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98AC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_050[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98AD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98AE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_051[32] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98AF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98B0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_052[28] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98F2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98F5),
    L2(250, 255, 0, 0, 0, 0, 0, 0x98F5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_053[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0x9F0F),
    L2(1, 0, 323, 0, 0, 0, 0, 0x9F0F),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9F0F),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F10),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F11),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F12),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F13),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F14),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F15),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F16),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F17),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F18),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F19),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F19),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_054[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0x9F1A),
    L2(1, 0, 323, 0, 0, 0, 0, 0x9F1A),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9F1A),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F1F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F20),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F21),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F22),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F23),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F24),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_055[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0x9F25),
    L2(1, 0, 323, 0, 0, 0, 0, 0x9F25),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9F25),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F26),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F27),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F28),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F29),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F2F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F2F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_056[64] = {
    L2(4, 133, 0, 0, 0, 0, 0, 0x9F30),
    L2(1, 0, 323, 0, 0, 0, 0, 0x9F30),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9F30),
    CMD(CM_IXBW, 0, 0, 1),
    L2(3, 1, 0, 0, 0, 0, 0, 0x9F31),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F32),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F33),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F34),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F35),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F36),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F37),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F38),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F39),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F3A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F3A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_057[100] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 147, 0, 0, 0, 0, 0, 0x9F40),
    L2(2, 0, 314, 0, 0, 0, 0, 0x9F41),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F42),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F43),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F44),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F45),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F46),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F47),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F48),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F49),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F4F),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0x9F50),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F52),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F53),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F54),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F54),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_058[92] = {
    CMD(CM_FOR, 0, 0, 1),
    L2(2, 144, 0, 0, 0, 0, 0, 0x9FBC),
    L2(2, 0, 314, 0, 0, 0, 0, 0x9FBD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FBE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FBF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FC8),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 1, 0, 0, 0, 0, 0, 0x9FC9),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FCA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FCB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9FCE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FCE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_059[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2B71),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2B83),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C01),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C4C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2C4D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2C4E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_060[72] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0x9CFC),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9CFD),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9CFE),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9CFF),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D00),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D01),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D02),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D03),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D04),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D05),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D06),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D07),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D08),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9D09),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9D0A),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9D0B),
    L2(250, 255, 0, 0, 1, 0, 0, 0x9D0B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_061[56] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9906),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9907),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9908),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9909),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9910),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9911),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9911),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_062[72] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_063[72] = {
    L2(3, 0, 0, 0, 1, 0, 0, 0x98F6),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98F7),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98F8),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98F9),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FA),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FB),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FC),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FD),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x98FF),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9900),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9901),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9902),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9903),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9904),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 1, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_064[72] = {
    L2(2, 0, 0, 0, 2, 0, 0, 0x9CFC),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9CFD),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9CFE),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9CFF),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D00),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D01),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D02),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D03),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D04),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D05),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D06),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D07),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D08),
    L2(2, 0, 0, 0, 2, 0, 0, 0x9D09),
    L2(1, 0, 0, 0, 2, 0, 0, 0x9D0A),
    L2(1, 0, 0, 0, 2, 0, 0, 0x9D0B),
    L2(250, 255, 0, 0, 2, 0, 0, 0x9D0B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_065[12] = {
    L2(16, 0, 0, 0, 0, 0, 0, 0x2DDD),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_066[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_067[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_068[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_069[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F9),
    CMD(CM_FOR, 0, 0, 4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FF),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9906),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9907),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9908),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9909),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x990E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x990F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9910),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9911),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9911),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_070[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98D6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98D7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98D8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98D9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98DB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x98DC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x98DC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_071[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_PA_X, 0, 768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_072[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_PA_X, 0, -768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x15F0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_073[72] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9CFC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9CFD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9CFE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9CFF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D00),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D01),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D02),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D03),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D04),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D05),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D06),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D07),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D08),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9D09),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9D0A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9D0B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9D0B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_074[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D28),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D29),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D2F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D30),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D31),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D32),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D33),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D34),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D35),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D36),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D37),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_075[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D38),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D39),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D3F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D40),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D41),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D43),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D44),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D45),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D46),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_076_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_076[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D48),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D49),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D4F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D50),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D51),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D52),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D53),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D54),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D55),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D56),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D57),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_077[68] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D58),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D5F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D60),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D61),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D62),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D63),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D64),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D65),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D66),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D67),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_078_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_078[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x3434),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3435),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3436),
    L2(2, 0, 0, 0, 0, 0, 0, 0x3437),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3438),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3439),
    L2(4, 0, 0, 0, 0, 0, 0, 0x343A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x343B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x343B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_079_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_079[44] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x343C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x343D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x343E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x343F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3440),
    L2(3, 0, 0, 0, 0, 0, 0, 0x3441),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3442),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3443),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3444),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3444),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_080_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_080[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x342A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x342B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x342C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x342D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x342E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x342F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3430),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3431),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3432),
    L2(4, 0, 0, 0, 0, 0, 0, 0x3433),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3433),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_081_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_081[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D8A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2D8B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2D8C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_082_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_082[60] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x9881),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9882),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9883),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9884),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9885),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9886),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9887),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9888),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9889),
    L2(3, 0, 0, 0, 0, 0, 0, 0x988A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x988B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x988C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x988D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x988D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_083_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_083[60] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0x9881),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9882),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9883),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9884),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9885),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9886),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9887),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9888),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9889),
    L2(3, 0, 0, 0, 1, 0, 0, 0x988A),
    L2(3, 0, 0, 0, 1, 0, 0, 0x988B),
    L2(3, 0, 0, 0, 1, 0, 0, 0x988C),
    L2(3, 0, 0, 0, 1, 0, 0, 0x988D),
    L2(250, 255, 0, 0, 1, 0, 0, 0x988D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_084_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_084[20] = {
    L2(3, 0, 0, 2, 0, 0, 0, 0x1A94),
    L2(3, 0, 0, 2, 0, 0, 0, 0x1A95),
    L2(3, 0, 0, 2, 0, 0, 0, 0x1ABD),
    L2(250, 255, 0, 2, 0, 0, 0, 0x1ABD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_085_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_085[40] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0x9F9F),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA0),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA1),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA2),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA3),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA4),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA5),
    L2(250, 255, 0, 2, 0, 0, 0, 0x9FA5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_086_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_086[44] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0x9FA6),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA7),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA8),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FA9),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FAA),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FAB),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FAC),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FAD),
    L2(250, 255, 0, 2, 0, 0, 0, 0x9FAD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_087[60] = {
    L2(3, 133, 0, 2, 0, 0, 0, 0x9FAE),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FAF),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB0),
    CMD(CM_IXBW, 0, 0, 3),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB1),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB2),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB3),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB4),
    L2(3, 0, 0, 2, 0, 0, 0, 0x9FB5),
    L2(250, 255, 0, 2, 0, 0, 0, 0x9FB5),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0001),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_090[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_PA_X, 0, 768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_091_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_091[24] = {
    CMD(CM_FOR, 0, 0, 28),
    L2(1, 0, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_PA_X, 0, -768, 0),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x3F46),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_092_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_092[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0366),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0367),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0368),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0369),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0369),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_093_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_093[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x036D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x036E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x036F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x036F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_094_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_094[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0377),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0378),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0379),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0379),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_095_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_095[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x037D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x037E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x037F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x037F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_096_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_096[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_097_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_097[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0388),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0388),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_098_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_098[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x039A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x039E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x039E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_099_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_099[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0394),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0395),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0396),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0397),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0397),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_100_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_100[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03A8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03A8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_101_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_101[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03AE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03AE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_102_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_102[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03BE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03BE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_103_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_103[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x03B8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03B8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_104_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_104[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x038C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x038E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x038E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_105_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_105[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0385),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0386),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0387),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0388),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0388),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_106_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_106[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0460),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0461),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0462),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0463),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0464),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0465),
    L2(5, 0, 0, 0, 0, 0, 0, 0x0466),
    L2(6, 0, 0, 0, 0, 0, 0, 0x0467),
    L2(7, 0, 0, 0, 0, 0, 0, 0x0468),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0468),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_107_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_107[36] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x0437),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0438),
    L2(3, 0, 0, 0, 0, 0, 0, 0x0439),
    L2(4, 0, 0, 0, 0, 0, 0, 0x043A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x043B),
    L2(6, 0, 0, 0, 0, 0, 0, 0x043C),
    L2(7, 0, 0, 0, 0, 0, 0, 0x043D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x043D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_108_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_108[40] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0469),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x046F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0470),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0470),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_109_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_109[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x043E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x043F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0440),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0441),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0442),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0443),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0444),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0445),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0446),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0447),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0447),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_110_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_110[36] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0471),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0472),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0473),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0474),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0475),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0476),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0477),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0477),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_111_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_111[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0448),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0449),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x044F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x0450),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0450),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_112_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_112[64] = {
    L2(6, 0, 893, 0, 0, 0, 0, 0x02E0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(6, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_113_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_113[68] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x0451),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0452),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0453),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0454),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0455),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0456),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0457),
    L2(10, 0, 0, 0, 0, 0, 0, 0x0458),
    L2(7, 0, 892, 0, 0, 0, 0, 0x0459),
    L2(7, 0, 0, 0, 0, 0, 0, 0x045A),
    L2(7, 0, 0, 0, 0, 0, 0, 0x045B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x045C),
    L2(9, 0, 0, 0, 0, 0, 0, 0x045D),
    L2(10, 0, 0, 0, 0, 0, 0, 0x045E),
    L2(11, 0, 0, 0, 0, 0, 0, 0x045F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x045F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_114_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_114[52] = {
    CMD(CM_EXEC, 29, 1, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FD9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDD),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FDF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FE1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FE2),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_115_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_115[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FE9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FEA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FEB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FEC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FEC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_116_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_116[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_QUAY, 10, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EF0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_117_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_117[68] = {
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 42, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 42, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_118_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_118[84] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, -55, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 41, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 41, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_119_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_119[36] = {
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADB),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADC),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADD),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADE),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4ADF),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE1),
    L2(3, 0, 0, 0, 1, 0, 0, 0x4AE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_120_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_120[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x226B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x226F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2270),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2271),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2272),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2273),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2274),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2275),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2276),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2276),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_121_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_121[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x9825),
    L2(1, 0, 349, 0, 0, 0, 0, 0x9828),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9829),
    L2(1, 0, 0, 0, 0, 0, 0, 0x982A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x982B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x982C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x982E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x982E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_122_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_122[88] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7D),
    CMD(CM_PAXY, 0, 384, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7E),
    CMD(CM_PAXY, 0, 464, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D7F),
    CMD(CM_PAXY, 0, 544, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D80),
    CMD(CM_PAXY, 0, 624, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D81),
    CMD(CM_PAXY, 0, 704, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D82),
    CMD(CM_PAXY, 0, 784, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D83),
    CMD(CM_PAXY, 0, 864, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D84),
    CMD(CM_PAXY, 0, 944, 128),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D85),
    CMD(CM_PAXY, 0, 1024, 128),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_PAXY, 0, 1120, 128),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_123_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_123[44] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AE6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1AE7),
    L2(6, 0, 0, 0, 0, 0, 0, 0x1AE8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AE9),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEA),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEB),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEC),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AED),
    L2(5, 0, 0, 0, 0, 0, 0, 0x1AEE),
    L2(5, 1, 0, 0, 0, 0, 0, 0x1AEE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_124_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_124[180] = {
    CMD(CM_RJA, 0, 124, 9), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x1AEF, -54, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AF0, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AF1, 0, 36, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF2, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF3, 0, 35, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x1AF4, 0, 35, 0, 0, 0, 0, 0),
    L4(250, 0, 0, 0, 0, 0, 0, 0x1AF5, 0, 35, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF6, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF7, 0, 36, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x1AF8, 0, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AF9, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AFA, 0, 36, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x1AFB, 0, 36, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x1AFC, 0, 36, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AFD, 0, 0, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x1AFE, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1AFF, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1B00, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x1B01, 0, 0, 0, 0, 0, 0, 0),
    L4(24, 0, 0, 0, 0, 0, 0, 0x1B02, 0, 0, 0, 0, 0, 47, 2),
    L4(250, 255, 0, 0, 0, 0, 0, 0x1B02, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_125_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_125[32] = {
    CMD(CM_RJA, 0, 126, 1),
    CMD(CM_JSR, 0, 127, 3),
    CMD(CM_JSR, 0, 128, 3),
    CMD(CM_JSR, 0, 129, 3),
    CMD(CM_JSR, 0, 130, 3),
    CMD(CM_JSR, 0, 131, 3),
    CMD(CM_IXBW, 0, 0, 5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_126_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_126[28] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_DSPF, 2, 0, 0),
    L2(16, 0, 0, 0, 0, 0, 0, 0x1B0A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_127_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_127[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 8192),
    CMD(CM_PJMP, 18, 16393, 8192),
    CMD(CM_PJMP, 16, 16397, 8192),
    CMD(CM_PJMP, 14, 16401, 8192),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B03),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_128_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_128[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 8192),
    CMD(CM_PJMP, 18, 16393, 8192),
    CMD(CM_PJMP, 16, 16397, 8192),
    CMD(CM_PJMP, 14, 16401, 8192),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B04),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_129_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_129[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 8192),
    CMD(CM_PJMP, 18, 16393, 8192),
    CMD(CM_PJMP, 16, 16397, 8192),
    CMD(CM_PJMP, 14, 16401, 8192),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B05),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_130_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_130[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 8192),
    CMD(CM_PJMP, 18, 16393, 8192),
    CMD(CM_PJMP, 16, 16397, 8192),
    CMD(CM_PJMP, 14, 16401, 8192),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B06),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_131_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_131[108] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 12, 16389, 8192),
    CMD(CM_PJMP, 18, 16393, 8192),
    CMD(CM_PJMP, 16, 16397, 8192),
    CMD(CM_PJMP, 14, 16401, 8192),
    CMD(CM_JMP, 0, 132, 3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 256, -256),
    CMD(CM_RET, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, -256, -256),
    L2(2, 0, 0, 0, 0, 0, 0, 0x1B07),
    CMD(CM_PAXY, 0, 0, -256),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_132_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_132[52] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x1B08),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_PJMP, 16, 16390, 8192),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B0A),
    CMD(CM_PAXY, 0, 256, -512),
    CMD(CM_RET, 0, 0, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B08),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B09),
    L2(4, 0, 0, 0, 1, 0, 0, 0x1B0A),
    CMD(CM_PAXY, 0, -256, -512),
    CMD(CM_RET, 0, 0, 0),
};

const u16 plef_char_table_133_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_133[284] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B7F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B80),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B81),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B82),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B83),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B84),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B85),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B86),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B87),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B88),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B90),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B91),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B92),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B93),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B94),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B95),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B96),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B97),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B98),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B99),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1B9F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BA9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BAF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB1),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB2),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BB9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BBF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x1BC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_134_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_134[208] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B83),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B84),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B85),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B86),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B89),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B8F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B90),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B91),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B92),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B93),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B94),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B95),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B96),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B97),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B98),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B99),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9E),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1B9F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BA9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BAF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB4),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1BB4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_135_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_135[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1BC1),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1BC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_136_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_136[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AE9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x1AEE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x1AEE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_137_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_137[84] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, -55, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 51, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 51, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_138_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_138[68] = {
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 52, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_139_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_139[68] = {
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADB, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADC, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADD, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADE, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4ADF, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE0, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE1, 0, 52, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 1, 0, 0, 0x4AE2, 0, 52, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_140_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_140[56] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xB3F8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB3F9),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB3FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB3FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB3FC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB3FD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB3FE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB3FF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB400),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB401),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB402),
    L2(4, 0, 0, 0, 0, 0, 0, 0xB403),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB403),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_141_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_141[36] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xB404),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB405),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB406),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB407),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB408),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB409),
    L2(3, 0, 0, 0, 0, 0, 0, 0xB40A),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB40A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_142_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_142[100] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x6530),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6531),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6532),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6533),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6534),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6535),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6536),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6537),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6538),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6539),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x653F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6540),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6541),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6542),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6542),
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(1, 0, 0, 0, 0, 0, 0, 0x6542),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_143_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_143[48] = {
    CMD(CM_FOR, 0, 0, 30),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB478),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB479),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB47F),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB478),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_144_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_144[56] = {
    CMD(CM_FOR, 0, 0, 5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB518),
    L2(2, 0, 0, 0, 0, 0, 0, 0xB519),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB51F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB520),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB521),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB521),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_145_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_145[52] = {
    CMD(CM_EXEC, 29, 2, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA3E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA3F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA40),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA41),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA42),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA43),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA44),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA45),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA46),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA47),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_146_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_146[24] = {
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_147_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_147[48] = {
    L2(1, 0, 272, 0, 1, 0, 0, 0xAA7A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA7F),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA80),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA81),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA82),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA83),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA83),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_148_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_148[40] = {
    L2(2, 0, 265, 0, 0, 0, 0, 0x7600),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7601),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7602),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7603),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7604),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7605),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7606),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7607),
    L2(250, 255, 0, 0, 0, 0, 0, 0x7607),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_149_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_149[96] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x586E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x586F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5870),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5871),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5872),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5873),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5874),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5875),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5876),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5877),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5878),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5879),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x587F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5880),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5881),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5882),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5883),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5883),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_150_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_150[72] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x738D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x738E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x738F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7543),
    L2(1, 0, 0, 0, 0, 0, 0, 0x7544),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7545),
    L2(2, 0, 0, 0, 0, 0, 0, 0x7546),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7547),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7548),
    L2(3, 0, 0, 0, 0, 0, 0, 0x7549),
    L2(3, 0, 0, 0, 0, 0, 0, 0x754A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x754B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x754C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x754D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x754E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x754F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x754F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_151_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_151[44] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0xAB10),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB11),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB12),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB13),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB14),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB15),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB16),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB17),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB18),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB19),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAB19),
};

const u16 plef_char_table_152_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_152[24] = {
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_153_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_153[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x0001),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0001),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_155_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_155[72] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98F9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x98FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FD),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_156_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_156[224] = {
    CMD(CM_CCCH, 0, 8252, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B8),
    L2(1, 0, 317, 0, 0, 0, 0, 0xB4B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D0),
    L2(1, 4, 0, 0, 0, 0, 0, 0xB4D1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D7),
    L2(1, 2, 0, 0, 0, 0, 0, 0xB4D8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E2),
    L2(1, 1, 0, 0, 0, 0, 0, 0xB4E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB4ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_157_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_157[140] = {
    CMD(CM_CCCH, 0, 8252, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB4D7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_158_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_158[192] = {
    CMD(CM_CCCH, 0, 8252, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B8),
    L2(1, 0, 317, 0, 0, 0, 0, 0xB4B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D6),
    L2(1, 1, 0, 0, 0, 0, 0, 0xB4D7),
    CMD(CM_CCCH, 0, 8224, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F92),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F96),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F97),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F98),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F9E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_159_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_159[140] = {
    CMD(CM_CCCH, 0, 8252, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B8),
    L2(1, 0, 317, 0, 0, 0, 0, 0xB4B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4BF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4C9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D5),
    L2(1, 1, 0, 0, 0, 0, 0, 0xB4D6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4D7),
    L2(250, 255, 0, 0, 0, 0, 0, 0xB4D7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_160_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_160[16] = {
    CMD(CM_CCCH, 0, 8252, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xB4B9),
    CMD(CM_JMP, 0, 159, 4),
};

const u16 plef_char_table_161_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_161[224] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D90),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D91),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D92),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D93),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D94),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D95),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D96),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D97),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9D97),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D6D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D6E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D6F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D70),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D71),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D72),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D73),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D74),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D75),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D76),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D77),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9D77),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D78),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D79),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D7A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D7B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D7C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D7D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D7E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D7F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D80),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D81),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D82),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D83),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D84),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D85),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D86),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9D87),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9D87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D98),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D99),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9D9B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D9E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9D9F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA1),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA2),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA3),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA5),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9DA7),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9DA7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_163_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_163[128] = {
    L2(60, 0, 0, 0, 1, 0, 0, 0x03C0),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C1),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C2),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C3),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03C4),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03C5),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03C6),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03C7),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03C8),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03C9),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03CA),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03CB),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03CC),
    L2(6, 0, 0, 0, 1, 0, 0, 0x03CD),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CE),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03CF),
    L2(4, 0, 0, 0, 1, 0, 0, 0x03D0),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D1),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D2),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D3),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D4),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D5),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D6),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D7),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D8),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03D9),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DA),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DB),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DC),
    L2(3, 0, 0, 0, 1, 0, 0, 0x03DD),
    L2(250, 255, 0, 0, 1, 0, 0, 0x03DD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_164_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_164[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_165_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_165[52] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F0),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02FA),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02FA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_166_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_166[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x98D6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98D7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98D8),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98D9),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98DA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98DB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98DC),
    L2(250, 255, 0, 0, 0, 0, 0, 0x98DC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_167_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_167[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x406F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4070),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4071),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4072),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4073),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4074),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4075),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4076),
    L2(4, 0, 0, 0, 0, 0, 0, 0x4077),
    L2(250, 255, 0, 0, 0, 0, 0, 0x4077),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_168_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_168[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9760),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_169_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_169[20] = {
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B61),
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B62),
    L2(3, 0, 0, 2, 1, 0, 0, 0x1B63),
    L2(250, 255, 0, 2, 1, 0, 0, 0x1B63),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_170_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_170[40] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x40B9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BB),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BD),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40BF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x40C0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x40C1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_171_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_171[472] = {
    L2(1, 0, 799, 0, 0, 0, 0, 0xBCAA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCED),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD00),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD01),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD02),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD03),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD04),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD05),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD06),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD07),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD08),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD09),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD0A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD10),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD11),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD12),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD13),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD14),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD15),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD16),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD17),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD18),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD19),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1D),
    L2(250, 255, 0, 0, 0, 0, 0, 0xBD1D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_172_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_172[72] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x98F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x98F7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98F9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x98FB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98FC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98FD),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98FE),
    L2(4, 0, 0, 0, 0, 0, 0, 0x98FF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9900),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9901),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9902),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9903),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9904),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9905),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9905),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_173_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_173[16] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9A11),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9A12),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A12),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 plef_char_table_174_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 plef_char_table_174[52] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9A11),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9A12),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A13),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A14),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A15),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9A16),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9A17),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9A18),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9A19),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9A1A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9A1B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A1B),
    CMD(CM_ROA, 0, 0, 0),
};

/* ef01_char_table scripts: 78 entries */
const u16* const ef01_char_table[79] = {
    ef01_char_table_000, ef01_char_table_001, ef01_char_table_002, ef01_char_table_003, ef01_char_table_004, ef01_char_table_005,
    ef01_char_table_006, ef01_char_table_006, ef01_char_table_008, ef01_char_table_009, ef01_char_table_010, ef01_char_table_011,
    ef01_char_table_012, ef01_char_table_013, ef01_char_table_014, ef01_char_table_015, ef01_char_table_016, ef01_char_table_017,
    ef01_char_table_018, ef01_char_table_019, ef01_char_table_020, ef01_char_table_021, ef01_char_table_022, ef01_char_table_023,
    ef01_char_table_024, ef01_char_table_025, ef01_char_table_026, ef01_char_table_027, ef01_char_table_028, ef01_char_table_029,
    ef01_char_table_029, ef01_char_table_031, ef01_char_table_032, ef01_char_table_033, ef01_char_table_034, ef01_char_table_035,
    ef01_char_table_036, ef01_char_table_036, ef01_char_table_038, ef01_char_table_038, ef01_char_table_038, ef01_char_table_038,
    ef01_char_table_038, ef01_char_table_038, ef01_char_table_038, ef01_char_table_038, ef01_char_table_038, ef01_char_table_047,
    ef01_char_table_048, ef01_char_table_049, ef01_char_table_050, ef01_char_table_051, ef01_char_table_052, ef01_char_table_053,
    ef01_char_table_054, ef01_char_table_055, ef01_char_table_056, ef01_char_table_057, ef01_char_table_058, ef01_char_table_059,
    ef01_char_table_060, ef01_char_table_061, ef01_char_table_062, ef01_char_table_063, ef01_char_table_064, ef01_char_table_065,
    ef01_char_table_066, ef01_char_table_067, ef01_char_table_068, ef01_char_table_069, ef01_char_table_070, ef01_char_table_071,
    ef01_char_table_072, ef01_char_table_073, ef01_char_table_074, ef01_char_table_075, ef01_char_table_076, ef01_char_table_077,
    0
};

const u16 ef01_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_000[44] = {
    L2(2, 0, 265, 0, 0, 0, 0, 0x9ECF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9ED0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9ED1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9ED2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9ED3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9ED4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9ED5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9ED6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9ED7),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9ED7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_001[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB10),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB11),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB12),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB13),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB14),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB15),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB16),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB17),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB18),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB19),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAB19),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_002[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB1A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB1B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB1C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB1D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB1E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xAB1F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB20),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB21),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB22),
    L2(2, 0, 0, 0, 0, 0, 0, 0xAB23),
    L2(250, 255, 0, 0, 0, 0, 0, 0xAB23),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_003[40] = {
    L2(3, 0, 265, 0, 0, 0, 0, 0x9771),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9772),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9773),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9774),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9775),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9776),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9777),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9778),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9778),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_004[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA20),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA21),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA22),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA23),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA24),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA25),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA26),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA27),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA28),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA29),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA29),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_005[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA20),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA21),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA22),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA23),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA24),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA25),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA26),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA27),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA28),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA29),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA29),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_006[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA80),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA81),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA82),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA83),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA83),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_008[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 0, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_009[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 1, 5, 0),
    CMD(CM_EXEC, 41, 1, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_010[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 2, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EF0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_011[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 3, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_012[40] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x988E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x988F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9890),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9891),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9892),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9893),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9894),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9895),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9895),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_013[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9ECF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F92),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F94),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F96),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F97),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F98),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F9E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_014[24] = {
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_015[24] = {
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 41, 1, 0),
    CMD(CM_EXEC, 1, 5, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_016[24] = {
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 2, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_017[24] = {
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 3, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_018[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 41, 2, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_019[28] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0x9916),
    L2(1, 0, 0, 0, 1, 0, 0, 0x9912),
    L2(2, 0, 0, 0, 1, 0, 0, 0x9913),
    L2(3, 0, 0, 0, 1, 0, 0, 0x9914),
    L2(4, 0, 0, 0, 1, 0, 0, 0x9915),
    L2(250, 255, 0, 0, 1, 0, 0, 0x9915),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_020[76] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x03E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E7),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x03ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x03ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_021[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9ECF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F92),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F94),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F96),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F97),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F98),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F9A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9F9E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F9E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_022[64] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F92),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F93),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F94),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F95),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F96),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F97),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9F98),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F99),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F9A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9F9B),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9C),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9D),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9F9E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9F9E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_023[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 2, 0),
    CMD(CM_EXEC, 1, 3, 0),
    CMD(CM_EXEC, 41, 4, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_024[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 4, 0),
    CMD(CM_EXEC, 1, 5, 0),
    CMD(CM_EXEC, 41, 5, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_025[52] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 6, 0),
    CMD(CM_EXEC, 1, 7, 0),
    CMD(CM_EXEC, 41, 6, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEC),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEF),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EF0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_026[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    CMD(CM_EXEC, 1, 8, 0),
    CMD(CM_EXEC, 1, 9, 0),
    CMD(CM_EXEC, 41, 7, 0),
    CMD(CM_JMP, 0, 10, 7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_027[16] = {
    CMD(CM_EXEC, 29, 1, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_028[12] = {
    CMD(CM_EXEC, 29, 2, 0),
    CMD(CM_JMP, 0, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_029[12] = {
    CMD(CM_EXEC, 29, 3, 0),
    CMD(CM_JMP, 0, 27, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_031[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FED),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FEE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FEF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FF5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FF6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FF6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_032[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FED),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FEE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FEF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF0),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9FF4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FF5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9FF6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9FF6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_033[40] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9EEB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EEC),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9EED),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEE),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9EEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9EF0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9EF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_034[8] = {
    CMD(CM_JMP, 0, 4, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_035[8] = {
    CMD(CM_JMP, 0, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_036[8] = {
    CMD(CM_JMP, 0, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_038[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9F8),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9F9),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9FA),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9FB),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9FC),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9FD),
    L2(1, 0, 0, 0, 1, 0, 0, 0xA9FE),
    L2(2, 0, 0, 0, 1, 0, 0, 0xA9FF),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA00),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA01),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA01),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_047[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA02),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA03),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA04),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA05),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA06),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA07),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA08),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA09),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA0A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA0B),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA0B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_048[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA0C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA0D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA0E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA0F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA10),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA11),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA12),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA13),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA14),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA15),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA15),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_049[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA16),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA17),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA18),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA19),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA1A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA1B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA1C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA1D),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA1E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA1F),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA1F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_050[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA20),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA21),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA22),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA23),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA24),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA25),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA26),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA27),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA28),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA29),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA29),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_051[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA2F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA30),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA31),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA32),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA33),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA33),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_052[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA34),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA35),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA36),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA37),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA38),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA39),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA3A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA3B),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA3C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA3D),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA3D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_053[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA3E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA3F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA40),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA41),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA42),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA43),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA44),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA45),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA46),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA47),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_054[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA48),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA49),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA4A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA4B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA4C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA4D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA4E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA4F),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA50),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA51),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA51),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_055[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA52),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA53),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA54),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA55),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA56),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA57),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA58),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA59),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA5A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA5B),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA5B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_056[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA5C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA5D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA5E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA5F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA60),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA61),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA62),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA63),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA64),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA65),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA65),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_057[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA66),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA67),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA68),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA69),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA6A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA6B),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA6C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA6D),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA6E),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA6F),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA6F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_058_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_058[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA70),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA71),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA72),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA73),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA74),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA75),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA76),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA77),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA78),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA79),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA79),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_059_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_059[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7C),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7D),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA7E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA7F),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA80),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA81),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA82),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA83),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA83),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_060[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA84),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA85),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA86),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA87),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA88),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA89),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA8A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA8B),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA8C),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA8D),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA8D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_061_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_061[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA8E),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA8F),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA90),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA91),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA92),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA93),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA94),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA95),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA96),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAA97),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAA97),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_062_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_062[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA98),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA99),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA9A),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA9B),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAA9C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA9D),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA9E),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAA9F),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAA0),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAA1),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAA1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_063[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAA2),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAA3),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAA4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAA5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAA6),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAA7),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAA8),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAA9),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAAA),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAAB),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAAB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_064[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAAC),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAAD),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAAE),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAAF),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAB0),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAB1),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAB2),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAB3),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAB4),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAB5),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAB5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_065[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAB6),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAB7),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAB8),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAB9),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAABA),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAABB),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAABC),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAABD),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAABE),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAABF),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAABF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_066[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAC0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAC1),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAC2),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAC3),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAC4),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAC5),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAC6),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAC7),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAC8),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAC9),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAC9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_067[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAACA),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAACB),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAACC),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAACD),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAACE),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAACF),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAD0),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAD1),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAD2),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAD3),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAD3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_068[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAD4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAD5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAD6),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAD7),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAD8),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAD9),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAADA),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAADB),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAADC),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAADD),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAADD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_069[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAADE),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAADF),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAE0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAE1),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAE2),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAE3),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAE4),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAE5),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAE6),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAE7),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAE7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_070[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAE8),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAE9),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAEA),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAEB),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAEC),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAED),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAEE),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAEF),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAF0),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAF1),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAF1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_071_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_071[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAF2),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAF3),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAF4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAF5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAF6),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAF7),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAF8),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAAF9),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAFA),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAAFB),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAAFB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_072_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_072[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAFC),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAFD),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAFE),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAAFF),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB00),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB01),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB02),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB03),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAB04),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAB05),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAB05),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_073_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_073[48] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB06),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB07),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB08),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB09),
    L2(1, 0, 0, 0, 1, 0, 0, 0xAB0A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB0B),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB0C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xAB0D),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAB0E),
    L2(3, 0, 0, 0, 1, 0, 0, 0xAB0F),
    L2(250, 255, 0, 0, 1, 0, 0, 0xAB0F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_074_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_074[48] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F84),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F85),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F86),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F87),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F88),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F89),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F8A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F8B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F8C),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2F8D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F8D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_075_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_075[472] = {
    L2(1, 0, 799, 0, 0, 0, 0, 0xBCAA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCAF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCB9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCBF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCC9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCCF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCD9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCDF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCE9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCED),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCEF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCF9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBCFF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD00),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD01),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD02),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD03),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD04),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD05),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD06),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD07),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD08),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD09),
    L2(1, 0, 0, 0, 0, 0, 0, 0xBD0A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD0F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD10),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD11),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD12),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD13),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD14),
    L2(2, 0, 0, 0, 0, 0, 0, 0xBD15),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD16),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD17),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD18),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD19),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xBD1D),
    L2(250, 255, 0, 0, 0, 0, 0, 0xBD1D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_076_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_076[184] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x9020),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9021),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9022),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9023),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9024),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9025),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9026),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9027),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9028),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9029),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x902F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9030),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9031),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9032),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9033),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9034),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9035),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9036),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9037),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9038),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9039),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x903F),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9040),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9041),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9042),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9043),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9044),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9045),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9046),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9047),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9048),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9049),
    L2(4, 0, 0, 0, 0, 0, 0, 0x904A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x904B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x904C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef01_char_table_077_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef01_char_table_077[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0x904D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x904E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x904F),
    CMD(CM_ROA, 0, 0, 0),
};

/* ef13_char_table scripts: 226 entries */
const u16* const ef13_char_table[227] = {
    ef13_char_table_000, ef13_char_table_001, ef13_char_table_002, ef13_char_table_003, ef13_char_table_004, ef13_char_table_005,
    ef13_char_table_006, ef13_char_table_007, ef13_char_table_008, ef13_char_table_008, ef13_char_table_010, ef13_char_table_011,
    ef13_char_table_011, ef13_char_table_013, ef13_char_table_014, ef13_char_table_015, ef13_char_table_016, ef13_char_table_017,
    ef13_char_table_018, ef13_char_table_019, ef13_char_table_020, ef13_char_table_021, ef13_char_table_022, ef13_char_table_023,
    ef13_char_table_024, ef13_char_table_025, ef13_char_table_026, ef13_char_table_027, ef13_char_table_028, ef13_char_table_029,
    ef13_char_table_030, ef13_char_table_031, ef13_char_table_032, ef13_char_table_033, ef13_char_table_034, ef13_char_table_035,
    ef13_char_table_036, ef13_char_table_037, ef13_char_table_038, ef13_char_table_039, ef13_char_table_040, ef13_char_table_041,
    ef13_char_table_042, ef13_char_table_043, ef13_char_table_044, ef13_char_table_045, ef13_char_table_046, ef13_char_table_047,
    ef13_char_table_048, ef13_char_table_049, ef13_char_table_050, ef13_char_table_051, ef13_char_table_052, ef13_char_table_053,
    ef13_char_table_053, ef13_char_table_053, ef13_char_table_056, ef13_char_table_057, ef13_char_table_058, ef13_char_table_059,
    ef13_char_table_060, ef13_char_table_061, ef13_char_table_062, ef13_char_table_063, ef13_char_table_064, ef13_char_table_065,
    ef13_char_table_066, ef13_char_table_067, ef13_char_table_068, ef13_char_table_069, ef13_char_table_070, ef13_char_table_071,
    ef13_char_table_072, ef13_char_table_073, ef13_char_table_074, ef13_char_table_075, ef13_char_table_076, ef13_char_table_077,
    ef13_char_table_078, ef13_char_table_079, ef13_char_table_080, ef13_char_table_081, ef13_char_table_082, ef13_char_table_083,
    ef13_char_table_084, ef13_char_table_085, ef13_char_table_086, ef13_char_table_087, ef13_char_table_088, ef13_char_table_089,
    ef13_char_table_090, ef13_char_table_091, ef13_char_table_092, ef13_char_table_093, ef13_char_table_094, ef13_char_table_095,
    ef13_char_table_096, ef13_char_table_097, ef13_char_table_098, ef13_char_table_099, ef13_char_table_100, ef13_char_table_101,
    ef13_char_table_102, ef13_char_table_103, ef13_char_table_104, ef13_char_table_105, ef13_char_table_106, ef13_char_table_107,
    ef13_char_table_108, ef13_char_table_109, ef13_char_table_110, ef13_char_table_111, ef13_char_table_112, ef13_char_table_113,
    ef13_char_table_114, ef13_char_table_115, ef13_char_table_116, ef13_char_table_117, ef13_char_table_118, ef13_char_table_119,
    ef13_char_table_120, ef13_char_table_121, ef13_char_table_122, ef13_char_table_123, ef13_char_table_124, ef13_char_table_125,
    ef13_char_table_126, ef13_char_table_127, ef13_char_table_128, ef13_char_table_129, ef13_char_table_130, ef13_char_table_131,
    ef13_char_table_132, ef13_char_table_133, ef13_char_table_134, ef13_char_table_135, ef13_char_table_136, ef13_char_table_137,
    ef13_char_table_138, ef13_char_table_139, ef13_char_table_140, ef13_char_table_141, ef13_char_table_142, ef13_char_table_143,
    ef13_char_table_144, ef13_char_table_145, ef13_char_table_146, ef13_char_table_147, ef13_char_table_148, ef13_char_table_149,
    ef13_char_table_150, ef13_char_table_151, ef13_char_table_152, ef13_char_table_153, ef13_char_table_154, ef13_char_table_155,
    ef13_char_table_156, ef13_char_table_157, ef13_char_table_158, ef13_char_table_159, ef13_char_table_160, ef13_char_table_161,
    ef13_char_table_162, ef13_char_table_163, ef13_char_table_164, ef13_char_table_165, ef13_char_table_166, ef13_char_table_167,
    ef13_char_table_168, ef13_char_table_169, ef13_char_table_170, ef13_char_table_171, ef13_char_table_172, ef13_char_table_173,
    ef13_char_table_174, ef13_char_table_175, ef13_char_table_176, ef13_char_table_177, ef13_char_table_178, ef13_char_table_179,
    ef13_char_table_180, ef13_char_table_181, ef13_char_table_182, ef13_char_table_183, ef13_char_table_184, ef13_char_table_180,
    ef13_char_table_181, ef13_char_table_182, ef13_char_table_183, ef13_char_table_189, ef13_char_table_190, ef13_char_table_191,
    ef13_char_table_192, ef13_char_table_193, ef13_char_table_194, ef13_char_table_195, ef13_char_table_196, ef13_char_table_197,
    ef13_char_table_198, ef13_char_table_199, ef13_char_table_200, ef13_char_table_201, ef13_char_table_202, ef13_char_table_203,
    ef13_char_table_204, ef13_char_table_205, ef13_char_table_206, ef13_char_table_207, ef13_char_table_208, ef13_char_table_209,
    ef13_char_table_210, ef13_char_table_211, ef13_char_table_212, ef13_char_table_213, ef13_char_table_214, ef13_char_table_215,
    ef13_char_table_216, ef13_char_table_217, ef13_char_table_218, ef13_char_table_219, ef13_char_table_220, ef13_char_table_221,
    ef13_char_table_222, ef13_char_table_223, ef13_char_table_224, ef13_char_table_225,
    0
};

const u16 ef13_char_table_000_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_000[204] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x9968, -1, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, -1, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_001[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_002[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9922),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9923),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9924),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9925),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9926),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9927),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9927),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_003[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9922),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_004[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9922),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_005_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_005[388] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9968, -2, 1, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9998, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9999, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999C, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999D, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999E, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999F, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9998, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9999, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999C, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999D, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999E, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999F, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9998, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9999, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999A, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 47, 0, 171, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x999B, 0, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x999E, 2, 47, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, -2, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 33), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, -3, 47, 0, 171, 0, 0, 0),
    CMD(CM_END, 0, 0, 33), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_006_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 5) };
const u16 ef13_char_table_006[148] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x99A0, -4, 1, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A1, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A2, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A3, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A4, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A5, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A6, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A7, 0, 167, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A0, 0, 167, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A3, 0, 167, 0, 0, 0, 0, 0),
    CMD(CM_WSET, 16384, 0, 1), 0, 0, 0, 0,
    CMD(CM_WSWK, 16384, 1, 16392), 0, 0, 0, 0,
    CMD(CM_WCEQ, 16384, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A4, -4, 167, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99A4, -5, 167, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_007_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_007[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9968, -25, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, -25, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_008_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_008[140] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x99AF, -26, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B0, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B1, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B2, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B3, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B4, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B5, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B6, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B7, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B8, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B9, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99BA, 0, 166, 0, 143, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99AF, 0, 166, 0, 143, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B0, 0, 166, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99B1, -26, 166, 0, 143, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_010_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_010[148] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2193, -6, 22, 0, 0, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2194, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2194, 0, 22, 0, 0, 0, 1, 33),
    CMD(CM_PA_X, 0, 28672, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x219B, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x219C, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219D, 0, 25, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219E, 0, 22, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x219F, 0, 22, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x219F, 0, 22, 0, 0, 0, 1, 33),
    CMD(CM_PA_X, 0, 28672, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x2190, 0, 23, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2191, 0, 24, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2192, 0, 25, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2193, 0, 22, 0, 0, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_JMP, 0, 11, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_011_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_011[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(3, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x219A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_013_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_013[12] = {
    L2(3, 0, 267, 0, 0, 0, 0, 0x2195),
    CMD(CM_JMP, 0, 11, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_014_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_014[12] = {
    L2(3, 0, 266, 0, 0, 0, 0, 0x2195),
    CMD(CM_JMP, 0, 11, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_015_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_015[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B20, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B21, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B22, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B23, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B24, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B25, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B26, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B27, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B28, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B29, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2A, 7, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2B, 7, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_016_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_016[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2C, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2D, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2E, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2F, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B30, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B31, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B32, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B33, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B34, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B35, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B36, 8, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B37, 8, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_017_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_017[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B44, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B45, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B46, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B47, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B48, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B49, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4A, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4B, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4C, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4D, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4E, 9, 6, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B4F, 9, 6, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_018_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_018[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B50, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B51, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B52, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B53, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B54, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B55, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B56, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B57, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B58, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B59, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5A, 10, 7, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5B, 10, 7, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_019_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_019[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5C, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5D, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5E, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5F, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B60, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B61, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B62, 11, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B63, 11, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_020_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_020[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B64, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B65, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B66, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B67, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B68, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B69, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6A, 12, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6B, 12, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_021_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_021[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6C, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6D, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6E, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6F, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B70, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B71, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B72, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B73, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B74, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B75, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B76, 13, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B77, 13, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_022_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_022[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B20, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B21, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B22, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B23, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B24, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B25, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B26, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B27, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B28, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B29, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2A, 14, 3, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2B, 14, 3, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_023_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_023[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2C, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2D, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2E, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B2F, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B30, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B31, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B32, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B33, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B34, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B35, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B36, 15, 4, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B37, 15, 4, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_024_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_024[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5C, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5D, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5E, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B5F, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B60, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B61, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B62, 16, 9, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B63, 16, 9, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_025_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_025[68] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B64, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B65, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B66, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B67, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B68, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B69, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6A, 17, 10, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6B, 17, 10, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_026_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_026[100] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6C, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6D, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6E, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B6F, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B70, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B71, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B72, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B73, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B74, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B75, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B76, 18, 11, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x9B77, 18, 11, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_027_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_027[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, -20, 27, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A61, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A64, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A65, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A66, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A67, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A68, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A69, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6A, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6B, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6C, 0, 20, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6D, 0, 20, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 20, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, -20, 20, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_028_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_028[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A73),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A74),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A75),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A76),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A77),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A78),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A79),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A7B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_029_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_029[64] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A73),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A74),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A75),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A76),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A77),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A78),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A79),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A7B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_030_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_030[64] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9A6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A73),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A74),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A75),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A76),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A77),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A78),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A79),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A7B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_031_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_031[64] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9A6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A6F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A70),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A71),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A72),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A73),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A74),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A75),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A76),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A77),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A78),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A79),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9A7B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A7B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_032_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_032[140] = {
    CMD(CM_IXFW, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 1, 0x9AA3, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A98, -19, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 335, 0, 0, 0, 1, 0x9A99, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9A, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9B, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9C, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9D, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9E, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A9F, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9AA0, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9AA1, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9AA2, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9AA3, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A98, 0, 17, 0, 66, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 1, 0x9A99, 0, 17, 0, 66, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_033_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_033[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9AA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9AA8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_034_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_034[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9AA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9AA8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_035_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_035[28] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9AA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9AA8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_036_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_036[28] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9AA4),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA5),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA6),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA7),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9AA8),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9AA8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_037_head[4] = { HEAD(4, 0, 10, 10, 0, 6, 0) };
const u16 ef13_char_table_037[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, -21, 28, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A61, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A64, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A65, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A66, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A67, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A68, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A69, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6A, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6B, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6C, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6D, 0, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, -21, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_038_head[4] = { HEAD(4, 0, 12, 10, 0, 6, 0) };
const u16 ef13_char_table_038[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, -22, 29, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A61, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A64, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A65, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A66, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A67, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A68, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A69, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6A, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6B, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6C, 0, 30, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6D, 0, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 30, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, -22, 30, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_039_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_039[172] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, -23, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A61, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A64, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A65, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A66, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A67, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A68, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A69, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6A, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6B, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6C, 0, 50, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A6D, 0, 50, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A62, 0, 50, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A63, -23, 50, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_040_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_040[20] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9A60, -24, 16, 0, 0, 0, 0, 0),
    CMD(CM_JMP, 0, 37, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_041_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_041[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C13, -28, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C13, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C14, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C15, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C16, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C17, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C18, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C19, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C1A, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_042_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_042[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0B, -28, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0B, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0C, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0D, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0E, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0F, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C10, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C11, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C12, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_043_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_043[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C03, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C03, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C04, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C05, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C06, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C07, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C08, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C09, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0A, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_044_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_044[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFB, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFB, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFC, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFD, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFE, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFF, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C00, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C01, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C02, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_045_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_045[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF3, -28, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF3, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF4, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF5, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF6, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF7, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF8, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BF9, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BFA, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_046[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9C16),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C16),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_047[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9C0E),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C0E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_048[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9C06),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C06),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_049[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BFE),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9BFE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_050[12] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0x9BF6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9BF6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_051[104] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x9C1C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1D),
    L2(1, 0, 340, 0, 0, 0, 0, 0x9C1E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C20),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C21),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C22),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C23),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C20),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C21),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C22),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C23),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C20),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C21),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C22),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C23),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C23),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_052[40] = {
    L2(1, 0, 340, 0, 0, 0, 0, 0x9C1C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9C1D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C1E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C1F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C20),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C21),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C22),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9C23),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9C23),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_053[52] = {
    L2(1, 0, 341, 0, 0, 0, 0, 0x2C99),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2C9D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2C9E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2C9F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2CA0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2CA1),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2CA2),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D10),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D11),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D11),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_056_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_056[52] = {
    L2(1, 0, 341, 0, 0, 0, 0, 0x2D12),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D13),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D14),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2D15),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D16),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D17),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D18),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2D19),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D1A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2D1B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2D1C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2D1C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_057_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_057[52] = {
    L2(1, 0, 331, 0, 0, 0, 0, 0x2DD1),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD2),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD3),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2DD4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2DD8),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2DD9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2DDA),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2DDB),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDB),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_058_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 4) };
const u16 ef13_char_table_058[52] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0x9BD3, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x9BCE, -29, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BCF, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BD0, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BD1, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_059_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 4) };
const u16 ef13_char_table_059[52] = {
    L4(1, 0, 0, 0, 1, 0, 0, 0x9BD3, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 268, 0, 0, 0, 0, 0x9BCE, -30, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BCF, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BD0, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9BD1, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_060_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_060[12] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0x2DDD),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2DDD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_061_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_061[276] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 872, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 3, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_062_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_062[276] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 873, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_063_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_063[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_064_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_064[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02F9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_065_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_065[8] = {
    CMD(CM_JMP, 0, 63, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_066_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_066[8] = {
    CMD(CM_JMP, 0, 64, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_067_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_067[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 63, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_068_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_068[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 64, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_069_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_069[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 63, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_070_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_070[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 64, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_071_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 5) };
const u16 ef13_char_table_071[20] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x2193, -34, 22, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 10, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_072_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_072[284] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 872, 0, 0, 0, 0, 0x0321, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, -32, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, -32, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, -32, 21, 0, 64, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_073_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_073[284] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 873, 0, 0, 0, 0, 0x0341, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, -33, 26, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, -33, 21, 0, 64, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, -33, 21, 0, 64, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_074_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_074[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -35, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 46, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 46, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 46, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -36, 46, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_075_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_075[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_076_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_076[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9992),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9993),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9994),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9995),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9996),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9997),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9997),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_077_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_077[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 76, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_078_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_078[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 76, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_079_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_079[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9968, -53, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, -58, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_080_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_080[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_081_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_081[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9992),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9993),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9994),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9995),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9996),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9997),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9997),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_082_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_082[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 81, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_083_head[4] = { HEAD(2, 0, 48, 10, 0, 10, 4) };
const u16 ef13_char_table_083[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 81, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_084_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_084[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0B, -37, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0B, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0C, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0D, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0E, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0F, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C10, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C11, 0, 18, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C12, 0, 18, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_085_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_085[84] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C03, -37, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C03, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C04, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C05, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C06, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C07, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C08, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C09, 0, 19, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9C0A, 0, 19, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_086_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_086[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -38, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 31, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 31, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 31, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -38, 31, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_087_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_087[28] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x539A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5398),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5399),
    L2(3, 0, 0, 0, 0, 0, 0, 0x539A),
    L2(3, 0, 0, 0, 0, 0, 0, 0x539B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x539C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_088_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_088[8] = {
    CMD(CM_JMP, 0, 87, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_089_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_089[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x539A),
    CMD(CM_JMP, 0, 87, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_090_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_090[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x539A),
    CMD(CM_JMP, 0, 87, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_091_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_091[292] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -38, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 32, 0, 162, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 32, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 32, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -38, 32, 0, 162, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_092_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_092[300] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0320, -39, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0321, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0322, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0323, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0324, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0325, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0326, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0327, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0328, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0329, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x032F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0330, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0331, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0332, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0333, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0334, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0335, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0336, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0337, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0338, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0339, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x033F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0320, 0, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0327, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0328, -39, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_093_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_093[300] = {
    L4(2, 0, 322, 0, 0, 0, 0, 0x0340, -40, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0341, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0342, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0343, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0344, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0345, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0346, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0347, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0348, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0349, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x034F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0350, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0351, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0352, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0353, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0354, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0355, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0356, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0357, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0358, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0359, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035A, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035B, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035C, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035D, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035E, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x035F, 0, 26, 0, 163, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x0340, 0, 21, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x0344, 0, 26, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0345, -40, 26, 0, 163, 0, 0, 0),
    CMD(CM_END, 0, 0, 7), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_094_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_094[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02E9),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EA),
    L2(3, 0, 0, 0, 0, 0, 0, 0x02EB),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02EC),
    L2(4, 0, 0, 0, 0, 0, 0, 0x02ED),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02ED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_095_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_095[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F7),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F8),
    L2(2, 0, 0, 0, 0, 0, 0, 0x02F9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x02F9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_096_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_096[8] = {
    CMD(CM_JMP, 0, 94, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_097_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_097[8] = {
    CMD(CM_JMP, 0, 95, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_098_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_098[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 94, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_099_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_099[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 95, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_100_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_100[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02E8),
    CMD(CM_JMP, 0, 94, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_101_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_101[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x02F1),
    CMD(CM_JMP, 0, 95, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_102_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_102[572] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x535E, -56, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x535F, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5360, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5361, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5362, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5363, 0, 37, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5364, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5365, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5366, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5367, 0, 38, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5368, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5369, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536A, 0, 39, 0, 144, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536B, 0, 39, 0, 144, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x536C, 0, 39, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536D, -56, 39, 0, 128, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x536E, 0, 39, 0, 128, 0, 0, 0),
    CMD(CM_WCGT, 16399, 3, 16386), 0, 0, 0, 0,
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_SSTX, 0, 3, 256), 0, 0, 0, 0,
    CMD(CM_IXFW, 0, 0, 3), 0, 0, 0, 0,
    CMD(CM_SSTX, 0, 0, 1248), 0, 0, 0, 0,
    CMD(CM_ABBAK, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x536E, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x536F, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5370, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5371, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5372, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5373, 41, 39, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 512), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5374, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5375, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5376, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5377, 41, 39, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5378, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5379, 41, 39, 0, 0, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 768), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x537A, -41, 39, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537B, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537C, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537D, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537E, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x537F, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5380, -41, 38, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5381, 41, 38, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5382, -41, 38, 0, 87, 0, 0, 0),
    CMD(CM_SSTX, 0, 3, 768), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5383, 41, 37, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5384, -41, 37, 0, 87, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5385, 41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5386, -41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5387, 41, 37, 0, 87, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5388, -41, 37, 0, 87, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x5389, 41, 37, 0, 87, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x538A, -41, 37, 0, 87, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538B, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538C, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538D, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538E, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x538F, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5390, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5391, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5392, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5393, 0, 40, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5394, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5395, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5396, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5397, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_103_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_103[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_104_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_104[8] = {
    CMD(CM_JMP, 0, 103, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_105_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_105[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 103, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_106_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_106[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 103, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_107_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 0) };
const u16 ef13_char_table_107[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x575E, -42, 45, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575E, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5760, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5761, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5762, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5763, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5765, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5766, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5767, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5768, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5769, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576A, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576B, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576C, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576D, 0, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 42, 49, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, -42, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, -43, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_108_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_108[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_109_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_109[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x576E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x576F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5770),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5771),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5772),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5773),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5773),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_110_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_110[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x576A),
    CMD(CM_JMP, 0, 109, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_111_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_111[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x576A),
    CMD(CM_JMP, 0, 109, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_112_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_112[196] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(4, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_MVIX, 111, 0, 0), 0, 0, 0, 0,
    L4(2, 20, 0, 0, 0, 0, 0, 0x5245, -44, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5246, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5247, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5248, -45, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5249, -45, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524A, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524B, 0, 33, 0, 150, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524C, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524D, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524E, 0, 33, 0, 147, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, 0, 33, 0, 147, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 10), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 11), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_113_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_113[32] = {
    L2(4, 0, 323, 0, 0, 0, 0, 0x524F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5250),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5251),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5252),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5253),
    L2(3, 0, 0, 0, 0, 0, 0, 0x5254),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5254),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_114_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_114[24] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5247),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5245),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5245),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_115_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_115[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5246),
    CMD(CM_JMP, 0, 114, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_116_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_116[12] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x524F),
    CMD(CM_JMP, 0, 113, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_117_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_117[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -51, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_118_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_118[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_119_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_119[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9992),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9993),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9994),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9995),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9996),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9997),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9997),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_120_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_120[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 119, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_121_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_121[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9992),
    CMD(CM_JMP, 0, 119, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_122_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_122[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5750, -47, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5751, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5752, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5755, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5756, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5757, 0, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, -47, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_123_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_123[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5758),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5759),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x575D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_124_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_124[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x5758),
    L2(2, 0, 0, 0, 0, 0, 0, 0x5759),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x575B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x575D),
    L2(250, 255, 0, 0, 0, 0, 0, 0x575D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_125_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_125[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x5755),
    CMD(CM_JMP, 0, 124, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_126_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_126[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x5755),
    CMD(CM_JMP, 0, 124, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_127_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_127[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -48, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5778, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5779, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 0, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 48, 43, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 4, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -48, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -52, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_128_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_128[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x577B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x577F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5780),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5780),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_129_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_129[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x577B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x577E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x577F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x5780),
    L2(250, 255, 0, 0, 0, 0, 0, 0x5780),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_130_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_130[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x577A),
    CMD(CM_JMP, 0, 129, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_131_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_131[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x577A),
    CMD(CM_JMP, 0, 129, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_132_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_132[20] = {
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, 49, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_133_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_133[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_134_head[4] = { HEAD(4, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_134[20] = {
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, 49, 8, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_135_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_135[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_136_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_136[220] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9968, -57, 1, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 50, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, -50, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_137_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_137[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_138_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_138[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9941),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9942),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9943),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9944),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9945),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9946),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9946),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_139_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_139[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9941),
    CMD(CM_JMP, 0, 138, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_140_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_140[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9941),
    CMD(CM_JMP, 0, 138, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_141_head[4] = { HEAD(4, 0, 34, 10, 0, 6, 0) };
const u16 ef13_char_table_141[52] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(7, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 112, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_142_head[4] = { HEAD(4, 0, 36, 10, 0, 6, 0) };
const u16 ef13_char_table_142[52] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(9, 0, 0, 0, 0, 0, 0, 0x5241, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5242, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5243, 0, 0, 0, 0, 0, 0, 0),
    L4(9, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_JPSS, 0, 112, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_143_head[4] = { HEAD(4, 0, 38, 10, 0, 6, 0) };
const u16 ef13_char_table_143[172] = {
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5244, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5245, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, -44, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5246, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5247, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5248, -45, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5249, -45, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524A, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524B, 0, 33, 0, 148, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524C, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524D, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524E, 0, 33, 0, 145, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5245, 0, 33, 0, 145, 0, 0, 0),
    CMD(CM_IXBW, 0, 0, 10), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5250, 0, 33, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x524F, 0, 33, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 8), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_144_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_144[324] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, -105, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5342, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5343, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5344, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5345, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5346, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5347, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5348, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534B, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534C, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534D, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534E, 0, 48, 0, 166, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x534F, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5350, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5351, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5352, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5353, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5354, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5355, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5356, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5357, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5358, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5359, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535A, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535B, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535C, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x535D, 0, 48, 0, 166, 0, 0, 0),
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    CMD(CM_DUMMY, 0, 0, 0), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5340, 0, 48, 0, 166, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5341, 0, 48, 0, 166, 0, 0, 0),
    CMD(CM_END, 0, 0, 3), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x5349, 0, 48, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x534A, -105, 48, 0, 166, 0, 0, 0),
    CMD(CM_END, 0, 0, 12), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_145_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_145[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -46, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 46, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 0, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -51, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_146_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_146[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -46, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 46, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -46, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -51, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_147_head[4] = { HEAD(4, 0, 48, 10, 0, 10, 0) };
const u16 ef13_char_table_147[196] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x575E, -59, 45, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575E, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5760, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5761, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5762, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5763, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5765, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5766, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5767, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5768, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5769, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576A, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576B, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576C, 0, 49, 0, 147, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x576D, 0, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x575F, 59, 49, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 5, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, -59, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5764, -60, 49, 0, 147, 0, 0, 0),
    CMD(CM_END, 0, 0, 5), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_148_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_148[100] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5750, -62, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5751, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5752, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5755, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5756, 0, 44, 0, 138, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5757, 0, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5753, 0, 44, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5754, -62, 44, 0, 138, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_149_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_149[92] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -63, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5778, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x5779, 0, 43, 0, 134, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 0, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x577A, 63, 43, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 5, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -63, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x5777, -66, 43, 0, 134, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_150_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_150[220] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x9968, -67, 1, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 64, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996B, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996C, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996D, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996E, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996F, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9970, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9971, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9974, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9975, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9976, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9977, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9978, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9979, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997A, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997B, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997C, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9969, 0, 2, 0, 153, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x996A, 0, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 4), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9972, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9973, -64, 2, 0, 153, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_151_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_151[204] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -65, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_152_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_152[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -61, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 61, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 0, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -65, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_153_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_153[228] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x997D, -61, 1, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x997F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9980, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9981, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9982, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9983, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9984, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9985, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9986, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9989, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998A, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998B, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998C, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998D, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998E, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x998F, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9990, 0, 2, 0, 151, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9991, 0, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9987, 61, 2, 0, 0, 0, 0, 0),
    CMD(CM_WCGT, 16399, 1, 16387), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -61, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9988, -65, 2, 0, 151, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_154_head[4] = { HEAD(4, 0, 64, 0, 0, 0, 0) };
const u16 ef13_char_table_154[108] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x0000, -68, 173, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0000, -68, 174, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0000, -68, 175, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0000, -68, 176, 0, 0, 0, 0, 0),
    L4(5, 0, 0, 0, 0, 0, 0, 0x0000, -68, 177, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0000, -68, 178, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0000, -68, 179, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0000, -68, 180, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0000, -70, 181, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0000, -70, 170, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0000, -70, 171, 0, 0, 0, 0, 0),
    L4(7, 0, 0, 0, 0, 0, 0, 0x0000, -70, 172, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_155_head[4] = { HEAD(4, 0, 64, 0, 0, 0, 0) };
const u16 ef13_char_table_155[84] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x0000, -69, 169, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x0000, -69, 170, 0, 0, 0, 0, 0),
    L4(6, 0, 0, 0, 0, 0, 0, 0x0000, -69, 171, 0, 0, 0, 0, 0),
    L4(8, 0, 0, 0, 0, 0, 0, 0x0000, -69, 172, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, -69, 173, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, -69, 174, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, -69, 175, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, -71, 176, 0, 0, 0, 0, 0),
    L4(10, 0, 0, 0, 0, 0, 0, 0x0000, -71, 177, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_156_head[4] = { HEAD(4, 0, 64, 10, 0, 10, 4) };
const u16 ef13_char_table_156[196] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAD, -72, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAE, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAF, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 335, 0, 0, 0, 0, 0x9AB0, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB1, 72, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB2, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB3, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB4, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB5, -73, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB6, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB7, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB8, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAD, 73, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAE, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AAF, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB0, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB1, -72, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB2, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB3, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB4, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB5, 72, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB6, 0, 68, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB7, 0, 67, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB8, 0, 68, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_157_head[4] = { HEAD(4, 0, 64, 10, 0, 10, 4) };
const u16 ef13_char_table_157[660] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AB9, -72, 69, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABA, 0, 105, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABB, 0, 70, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABC, 0, 106, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABD, 72, 71, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABE, 0, 107, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ABF, 0, 72, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC0, 0, 108, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC1, -73, 73, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC2, 0, 109, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC3, 0, 74, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC4, 0, 110, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC5, 73, 75, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC6, 0, 111, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC7, 0, 76, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC8, 0, 112, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AC9, -72, 77, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACA, 0, 113, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACB, 0, 78, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACC, 0, 114, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACD, 72, 79, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACE, 0, 115, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ACF, 0, 80, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD0, 0, 116, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD1, -73, 81, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD2, 0, 117, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD3, 0, 82, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD4, 0, 118, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD5, 73, 83, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD6, 0, 119, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD7, 0, 84, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD8, 0, 120, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AD9, -72, 85, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADA, 0, 121, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADB, 0, 86, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADC, 0, 122, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADD, 72, 87, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADE, 0, 123, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9ADF, 0, 88, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE0, 0, 124, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE1, -73, 89, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE2, 0, 125, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE3, 0, 90, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE4, 0, 126, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE5, 73, 91, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE6, 0, 127, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE7, 0, 92, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE8, 0, 128, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AE9, -72, 93, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AEA, 0, 129, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AEB, 0, 94, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AEC, 0, 130, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AED, 72, 95, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AEE, 0, 131, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AEF, 0, 96, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF0, 0, 132, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF1, -73, 97, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF2, 0, 133, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF3, 0, 98, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF4, 0, 134, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF5, 73, 99, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF6, 0, 135, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF7, 0, 100, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF8, 0, 136, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AF9, -72, 101, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFA, 0, 137, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFB, 0, 102, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFC, 0, 138, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFD, 72, 103, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFE, 0, 139, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9AFF, 0, 104, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B00, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B01, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_EXEC, 1, 151, 0), 0, 0, 0, 0,
    CMD(CM_EXEC, 1, 152, 0), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B02, 0, 0, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B03, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B04, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B05, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B06, 0, 0, 0, 0, 0, 39, 3),
    L4(1, 0, 0, 0, 0, 0, 0, 0x9B07, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x9B07, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_158_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_158[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -81, 155, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -81, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_159_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_159[32] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9761),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9762),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9763),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9764),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9765),
    L2(3, 0, 0, 0, 0, 0, 0, 0x9766),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9766),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_160_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_160[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x73C6),
    L2(250, 255, 0, 0, 0, 0, 0, 0x73C6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_161_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_161[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x73C1),
    CMD(CM_JMP, 0, 160, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_162_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_162[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x73C1),
    CMD(CM_JMP, 0, 160, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_163_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_163[196] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -90, 155, 0, 150, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 150, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 10, 0, 0, 0, 0, 0, 0x75A7, 86, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 150, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -86, 156, 0, 150, 0, 0, 0),
    CMD(CM_END, 0, 0, 13), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_164_head[4] = { HEAD(4, 0, 9, 10, 0, 6, 0) };
const u16 ef13_char_table_164[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -87, 155, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -87, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_165_head[4] = { HEAD(4, 0, 15, 10, 0, 6, 0) };
const u16 ef13_char_table_165[196] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -91, 155, 0, 150, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 150, 0, 0, 0),
    CMD(CM_NEX, 0, 0, 0), 0, 0, 0, 0,
    L4(1, 10, 0, 0, 0, 0, 0, 0x75A7, 88, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 150, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 150, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -88, 156, 0, 150, 0, 0, 0),
    CMD(CM_END, 0, 0, 9), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_166_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 102) };
const u16 ef13_char_table_166[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -74, 155, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -74, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_167_head[4] = { HEAD(4, 0, 14, 10, 0, 6, 0) };
const u16 ef13_char_table_167[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -90, 155, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -90, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_168_head[4] = { HEAD(4, 0, 15, 10, 0, 6, 0) };
const u16 ef13_char_table_168[108] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x75A6, -91, 155, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A0, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A1, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A2, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A3, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A4, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A5, 0, 156, 0, 139, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A6, -91, 156, 0, 139, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_169_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 0) };
const u16 ef13_char_table_169[44] = {
    L4(250, 0, 0, 0, 0, 0, 0, 0x75A7, -75, 156, 0, 131, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, 0, 156, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x75A7, -75, 156, 0, 131, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_170_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_170[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FBC, -76, 140, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FBD, 0, 141, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FBE, 0, 142, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FBF, 0, 142, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC0, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC1, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6FC3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_171_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_171[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_172_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_172[8] = {
    CMD(CM_JMP, 0, 171, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_173_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_173[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 171, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_174_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_174[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 171, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_175_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_175[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FC4, -77, 143, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FC5, 0, 144, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FC6, 0, 145, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC7, 0, 145, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC8, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FC9, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FCA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6FCB, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_176_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_176[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FCC, -78, 146, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FCD, 0, 147, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FCE, 0, 148, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FCF, 0, 148, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD0, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD1, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6FD3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_177_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_177[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FD4, -79, 149, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FD5, 0, 150, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FD6, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD7, 0, 151, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD8, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FD9, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FDA, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6FDB, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_178_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_178[68] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FDC, -80, 152, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FDD, 0, 153, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6FDE, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FDF, 0, 154, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FE0, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FE1, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6FE2, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6FE3, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_179_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 78) };
const u16 ef13_char_table_179[180] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x99E8, -82, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99E9, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EA, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EB, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EC, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99ED, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EE, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EF, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F0, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F1, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F2, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F3, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F4, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F5, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F6, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F7, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F8, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F9, 0, 157, 0, 148, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F0, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F1, -82, 157, 0, 148, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_184_head[4] = { HEAD(4, 0, 8, 10, 0, 6, 78) };
const u16 ef13_char_table_184[180] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x99E8, -85, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99E9, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EA, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EB, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EC, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99ED, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EE, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99EF, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F0, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F1, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F2, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F3, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F4, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F5, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F6, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F7, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F8, 0, 157, 0, 148, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F9, 0, 157, 0, 148, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F0, 0, 157, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x99F1, -85, 157, 0, 148, 0, 0, 0),
    CMD(CM_END, 0, 0, 10), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_180_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_180[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x99FA),
    L2(2, 0, 0, 0, 0, 0, 0, 0x99FB),
    L2(2, 0, 0, 0, 0, 0, 0, 0x99FC),
    L2(1, 0, 0, 0, 0, 0, 0, 0x99FD),
    L2(1, 0, 0, 0, 0, 0, 0, 0x99FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0x99FF),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9A00),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9A01),
    L2(1, 0, 0, 0, 0, 0, 0, 0x9A02),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9A02),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_181_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_181[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9922),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9923),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9924),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9925),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9926),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9927),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9927),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_182_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_182[12] = {
    L2(2, 0, 267, 0, 0, 0, 0, 0x9922),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_183_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_183[12] = {
    L2(2, 0, 266, 0, 0, 0, 0, 0x9922),
    CMD(CM_JMP, 0, 2, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_189_head[4] = { HEAD(4, 0, 14, 10, 0, 10, 0) };
const u16 ef13_char_table_189[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D01, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D02, 0, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D03, 0, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D04, -89, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D05, 0, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D06, 0, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D07, 0, 202, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D08, 0, 203, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D09, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0A, -102, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0B, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0C, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0D, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0E, 0, 204, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D10, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D11, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D12, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_190_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_190[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_191_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_191[8] = {
    CMD(CM_JMP, 0, 190, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_192_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_192[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 190, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_193_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_193[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 190, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_194_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_194[204] = {
    CMD(CM_RJA, 0, 195, 1), 0, 0, 0, 0,
    CMD(CM_RJA2, 0, 196, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F31, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 341, 0, 0, 0, 0, 0x2F32, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F33, -92, 168, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8194, 8195, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F34, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F35, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F36, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F37, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F38, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F39, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F3F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F40, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F41, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F42, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F43, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F44, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F45, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2F45, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_195_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_195[100] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F34),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F35),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F36),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F37),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F38),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F39),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3F),
    CMD(CM_FOR, 0, 0, 5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F3D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F3E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F3F),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F40),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F41),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F43),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F44),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F45),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F45),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_196_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_196[80] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x2F34),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F35),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F36),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F37),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F38),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F39),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F3F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F40),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F41),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F42),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F43),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F44),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F45),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F45),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_197_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_197[204] = {
    CMD(CM_RJA, 0, 198, 1), 0, 0, 0, 0,
    CMD(CM_RJA2, 0, 199, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F48, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 341, 0, 0, 0, 0, 0x2F49, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4A, -92, 168, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8194, 8195, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4D, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4E, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F4F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F50, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F51, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F52, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F53, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F54, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F55, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F56, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F57, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F58, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F59, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F5A, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F5B, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F5C, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2F5C, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_198_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_198[100] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F50),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F51),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F52),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F53),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F54),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F55),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F56),
    CMD(CM_FOR, 0, 0, 5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F54),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F55),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F56),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F57),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F58),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F5A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F5B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F5C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F5C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_199_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_199[80] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x2F4B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4D),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4E),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F4F),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F50),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F51),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F52),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F53),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F54),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F55),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F56),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F57),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F58),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F59),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F5A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F5B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F5C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F5C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_200_head[4] = { HEAD(4, 0, 32, 10, 0, 6, 0) };
const u16 ef13_char_table_200[204] = {
    CMD(CM_RJA, 0, 201, 1), 0, 0, 0, 0,
    CMD(CM_RJA2, 0, 202, 1), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F5F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 341, 0, 0, 0, 0, 0x2F60, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F61, -92, 168, 0, 0, 0, 0, 0),
    CMD(CM_HJMP, 8194, 8195, 8192), 0, 0, 0, 0,
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F62, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F63, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F64, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F65, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F66, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F67, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F68, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F69, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F6A, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F6B, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F6C, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x2F6D, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F6E, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x2F6F, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F70, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x2F71, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F72, 0, 0, 0, 0, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x2F73, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x2F73, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_201_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_201[100] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F62),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F63),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F64),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F65),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F66),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F67),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F68),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F69),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6D),
    CMD(CM_FOR, 0, 0, 5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6D),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F70),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F71),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F72),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F73),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F73),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_202_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_202[80] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x2F62),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F63),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F64),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F65),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F66),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F67),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F68),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F69),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6A),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6B),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6C),
    L2(1, 0, 0, 0, 0, 0, 0, 0x2F6D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2F6F),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F70),
    L2(3, 0, 0, 0, 0, 0, 0, 0x2F71),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F72),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2F73),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2F73),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_203_head[4] = { HEAD(4, 0, 32, 10, 0, 9, 0) };
const u16 ef13_char_table_203[188] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x5858, -93, 182, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5859, -93, 183, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585A, -94, 184, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585B, -93, 185, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585C, -94, 186, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585D, -94, 187, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585E, -94, 188, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x585F, -94, 189, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5860, -94, 190, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5861, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5862, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5863, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5864, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5865, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5866, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5867, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5868, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x5869, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x586A, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x586B, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x586C, 0, 0, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x586D, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x586D, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_204_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_204[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D01, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D02, 0, 211, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D03, 0, 211, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D04, -103, 211, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D05, 0, 212, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D06, 0, 212, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D07, 0, 212, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D08, 0, 213, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D09, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0A, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0B, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0C, 0, 214, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0D, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0E, 0, 215, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D10, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D11, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D12, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_205_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_205[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_206_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_206[8] = {
    CMD(CM_JMP, 0, 205, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_207_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_207[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 205, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_208_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_208[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 205, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_209_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_209[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D01, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D02, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D03, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D04, -103, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D05, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D06, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D07, 0, 205, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D08, 0, 206, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D09, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0A, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0B, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0C, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0D, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0E, 0, 207, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D10, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D11, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D12, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_210_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_210[172] = {
    L4(1, 0, 0, 0, 0, 0, 0, 0x0000, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D01, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D02, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D03, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D04, -103, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D05, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D06, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D07, 0, 208, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D08, 0, 209, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D09, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0A, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0B, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0C, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0D, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0E, 0, 210, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D0F, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D10, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D11, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D12, 0, 0, 0, 0, 0, 0, 0),
    L4(1, 0, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_211_head[4] = { HEAD(4, 0, 8, 10, 0, 10, 0) };
const u16 ef13_char_table_211[164] = {
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D01, -76, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D02, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D03, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D04, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D05, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D06, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D07, 0, 202, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D08, 0, 203, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D09, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0A, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0B, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0C, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0D, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0E, 0, 204, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D0F, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D10, 0, 0, 0, 0, 0, 2, 226),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D11, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D12, 0, 0, 0, 0, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    L4(250, 255, 0, 0, 0, 0, 0, 0x6D13, 0, 0, 0, 0, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_212_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_212[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704A, -95, 191, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704A, 0, 191, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_213_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_213[12] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0x0000),
    L2(250, 255, 0, 0, 0, 0, 0, 0x0000),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_214_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_214[8] = {
    CMD(CM_JMP, 0, 213, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_215_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_215[12] = {
    L2(1, 0, 267, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 213, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_216_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ef13_char_table_216[12] = {
    L2(1, 0, 266, 0, 0, 0, 0, 0x0000),
    CMD(CM_JMP, 0, 213, 2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_217_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_217[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704B, -96, 192, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704B, 0, 192, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_218_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_218[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704C, -97, 193, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704C, 0, 193, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_219_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_219[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704D, -98, 194, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704D, 0, 194, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_220_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_220[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704E, -99, 195, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704E, 0, 195, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_221_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_221[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704F, -100, 196, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704F, 0, 196, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_222_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_222[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x7050, -101, 197, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x7050, 0, 197, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_223_head[4] = { HEAD(4, 0, 32, 10, 0, 10, 0) };
const u16 ef13_char_table_223[28] = {
    L4(3, 0, 0, 0, 0, 0, 0, 0x704C, 0, 193, 0, 0, 0, 0, 0),
    L4(3, 0, 0, 0, 0, 0, 0, 0x704C, 0, 193, 0, 0, 0, 0, 0),
    CMD(CM_END, 0, 0, 2), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_224_head[4] = { HEAD(4, 0, 4, 10, 0, 6, 0) };
const u16 ef13_char_table_224[236] = {
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADB, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADC, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADD, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADE, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4ADF, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE0, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE1, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE2, 0, 26, 0, 64, 0, 0, 0),
    L4(4, 0, 0, 0, 0, 0, 0, 0x4AE3, 0, 26, 0, 64, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0020, 0x0A00, 0x0A05,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9978, -4, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9974, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9979, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9975, 0, 1, 0, 69, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9960, -5, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9964, 0, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9960, 0, 2, 0, 65, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0), 0x0004, 0x0020, 0x0A00, 0x0A05,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9978, -4, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9974, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9979, 0, 1, 0, 69, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9975, 0, 1, 0, 69, 0, 0, 0),
    CMD(CM_END, 0, 0, 1), 0, 0, 0, 0,
    L4(2, 0, 0, 0, 0, 0, 0, 0x9960, -5, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9964, 0, 2, 0, 65, 0, 0, 0),
    L4(2, 0, 0, 0, 0, 0, 0, 0x9960, 0, 2, 0, 65, 0, 0, 0),
    CMD(CM_END, 0, 0, 6), 0, 0, 0, 0,
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ef13_char_table_225_head[4] = { HEAD(2, 0, 8, 0, 0, 0, 0) };
const u16 ef13_char_table_225[180] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F4),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F5),
    L2(2, 0, 0, 0, 0, 0, 0, 0x20F6),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2195),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2196),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2197),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2198),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2199),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2190),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2191),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2192),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2193),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2194),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x219F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A0),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A3),
    L2(2, 0, 0, 0, 0, 0, 0, 0x21A4),
    CMD(CM_ROA, 0, 0, 0),
    L2(6, 53, 4069, 0, 0, 99, 5, 0xFE68),
    L2(6, 53, 4073, 2, 0, 0, 0, 0x0000),
    L2(6, 53, 4078, 2, 0, 99, 5, 0xFF00),
    L2(6, 53, 4086, 2, 0, 0, 0, 0x0000),
    L2(6, 54, 0, 0, 0, 99, 6, 0x0018),
    L2(6, 54, 6, 0, 0, 0, 0, 0x0000),
    L2(6, 54, 11, 0, 0, 99, 6, 0x00C8),
    L2(6, 54, 17, 0, 0, 0, 0, 0x0000),
    L2(6, 54, 22, 0, 0, 99, 6, 0x0178),
    L2(6, 54, 28, 0, 0, 0, 0, 0x0000),
    L2(6, 54, 33, 0, 0, 99, 6, 0x0228),
    L2(6, 54, 43, 2, 0, 0, 0, 0x0000),
    L2(6, 54, 48, 2, 0, 99, 6, 0x0320),
    L2(6, 54, 56, 2, 0, 0, 0, 0x0000),
    L2(6, 54, 65, 2, 0, 99, 6, 0x0488),
    L2(6, 54, 76, 2, 0, 0, 0, 0x0000),
    L2(6, 54, 65, 2, 0, 99, 6, 0x0488),
    L2(6, 54, 76, 2, 0, 0, 0, 0x0000),
};

/* ag_face_panel_table scripts: 1 entries */
const u16* const ag_face_panel_table[2] = {
    ag_face_panel_table_000,
    0
};

const u16 ag_face_panel_table_unused_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ag_face_panel_table_unused[876] = {
    L2(250, 255, 0, 0, 0, 0, 0, 0x96E0),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96E1),
    L2(6, 0, 0, 0, 0, 0, 0, 0x96E2),
    L2(90, 0, 0, 0, 0, 0, 0, 0x96E3),
    L2(250, 255, 0, 0, 0, 0, 0, 0x96E3),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96E4),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96E5),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96E6),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96E7),
    L2(3, 1, 0, 0, 0, 0, 0, 0x96E8),
    L2(30, 2, 0, 0, 0, 0, 0, 0x96E9),
    L2(250, 255, 0, 0, 0, 0, 0, 0x96E9),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x96EA),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96EB),
    L2(7, 0, 0, 0, 0, 0, 0, 0x96EC),
    L2(32, 0, 0, 0, 0, 0, 0, 0x96ED),
    CMD(CM_FOR, 0, 0, 3),
    L2(3, 0, 0, 0, 0, 0, 0, 0x96EE),
    L2(16, 0, 0, 0, 0, 0, 0, 0x96EF),
    L2(10, 0, 0, 0, 0, 0, 0, 0x96F0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x96EE),
    L2(6, 0, 0, 0, 0, 0, 0, 0x96ED),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x96ED),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x96F1),
    L2(8, 0, 0, 0, 0, 0, 0, 0x96F2),
    L2(32, 0, 0, 0, 0, 0, 0, 0x96F3),
    L2(4, 0, 0, 0, 0, 0, 0, 0x96F4),
    L2(4, 0, 0, 0, 0, 0, 0, 0x96F5),
    L2(4, 0, 0, 0, 0, 0, 0, 0x96F6),
    L2(4, 0, 0, 0, 0, 0, 0, 0x96F7),
    L2(4, 0, 0, 0, 0, 0, 0, 0x96F8),
    L2(5, 0, 0, 0, 0, 0, 0, 0x96F9),
    L2(6, 0, 0, 0, 0, 0, 0, 0x96FA),
    L2(7, 0, 0, 0, 0, 0, 0, 0x96FB),
    L2(4, 1, 0, 0, 0, 0, 0, 0x96FC),
    L2(6, 2, 0, 0, 0, 0, 0, 0x96FD),
    L2(6, 2, 0, 0, 0, 0, 0, 0x96FE),
    L2(20, 2, 0, 0, 0, 0, 0, 0x96FF),
    L2(250, 255, 0, 0, 0, 0, 0, 0x96FF),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9704),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9702),
    L2(58, 0, 0, 0, 0, 0, 0, 0x9703),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9702),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9701),
    L2(58, 0, 0, 0, 0, 0, 0, 0x9700),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9701),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9701),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9705),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9706),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9707),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9708),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9709),
    L2(20, 1, 0, 0, 0, 0, 0, 0x970A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x970A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x970F),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x970D),
    L2(58, 0, 0, 0, 0, 0, 0, 0x970E),
    L2(7, 0, 0, 0, 0, 0, 0, 0x970D),
    L2(8, 0, 0, 0, 0, 0, 0, 0x970C),
    L2(58, 0, 0, 0, 0, 0, 0, 0x970B),
    L2(5, 0, 0, 0, 0, 0, 0, 0x970C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x970C),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9710),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9711),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9712),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9713),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9714),
    L2(20, 1, 0, 0, 0, 0, 0, 0x9715),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9715),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x971A),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9718),
    L2(58, 0, 0, 0, 0, 0, 0, 0x9719),
    L2(7, 0, 0, 0, 0, 0, 0, 0x9718),
    L2(8, 0, 0, 0, 0, 0, 0, 0x9717),
    L2(58, 0, 0, 0, 0, 0, 0, 0x9716),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9717),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9717),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0x971B),
    L2(8, 0, 0, 0, 0, 0, 0, 0x971C),
    L2(8, 0, 0, 0, 0, 0, 0, 0x971D),
    L2(7, 0, 0, 0, 0, 0, 0, 0x971E),
    L2(6, 0, 0, 0, 0, 0, 0, 0x971F),
    L2(20, 1, 0, 0, 0, 0, 0, 0x9720),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9720),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9721),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9722),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9723),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9724),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9725),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9726),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9727),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9728),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9729),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9722),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9723),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9724),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9725),
    L2(6, 0, 0, 0, 0, 0, 0, 0x9723),
    L2(7, 0, 0, 0, 0, 0, 0, 0x972A),
    L2(32, 0, 0, 0, 0, 0, 0, 0x972B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x972B),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0x972C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x972D),
    L2(4, 1, 0, 0, 0, 0, 0, 0x972E),
    L2(4, 2, 0, 0, 0, 0, 0, 0x972F),
    L2(4, 2, 0, 0, 0, 0, 0, 0x9730),
    L2(20, 2, 0, 0, 0, 0, 0, 0x9731),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9731),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9732),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9733),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9734),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9735),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9736),
    L2(32, 0, 0, 0, 0, 0, 0, 0x9737),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9738),
    L2(4, 0, 0, 0, 0, 0, 0, 0x9739),
    L2(5, 0, 0, 0, 0, 0, 0, 0x973A),
    L2(5, 0, 0, 0, 0, 0, 0, 0x973B),
    L2(32, 0, 0, 0, 0, 0, 0, 0x973C),
    L2(250, 255, 0, 0, 0, 0, 0, 0x973C),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x973D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x973E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x973F),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9740),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9741),
    L2(5, 0, 0, 0, 0, 0, 0, 0x9742),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9743),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9744),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9745),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9746),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9747),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9748),
    L2(5, 1, 0, 0, 0, 0, 0, 0x9749),
    L2(5, 1, 0, 0, 0, 0, 0, 0x974A),
    L2(250, 255, 0, 0, 0, 0, 0, 0x974A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x2245),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2246),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2247),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2248),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2249),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224A),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224B),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224C),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224D),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224E),
    L2(4, 0, 0, 0, 0, 0, 0, 0x224F),
    L2(250, 255, 0, 0, 0, 0, 0, 0x224F),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(56, 0, 0, 0, 0, 0, 0, 0x2250),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2251),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2252),
    L2(2, 0, 0, 0, 0, 0, 0, 0x2251),
    L2(16, 0, 0, 0, 0, 0, 0, 0x2252),
    L2(250, 255, 0, 0, 0, 0, 0, 0x2252),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_END, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2253),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2254),
    L2(4, 0, 0, 0, 0, 0, 0, 0x2255),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2256),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2257),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2258),
    L2(5, 0, 0, 0, 0, 0, 0, 0x2259),
    L2(5, 1, 0, 0, 0, 0, 0, 0x225A),
    L2(5, 1, 0, 0, 0, 0, 0, 0x225B),
    L2(250, 255, 0, 0, 0, 0, 0, 0x225B),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 ag_face_panel_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 ag_face_panel_table_000[100] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DA8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DA9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DAF),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB0),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB1),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB2),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB3),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB4),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB5),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB6),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB7),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB8),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DB9),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBA),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBB),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBC),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBD),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBE),
    L2(250, 0, 0, 0, 0, 0, 0, 0x9DBF),
    CMD(CM_ROA, 0, 0, 0),
};

/* effD4_char_table scripts: 2 entries */
const u16* const effD4_char_table[3] = {
    effD4_char_table_000, effD4_char_table_001,
    0
};

const u16 effD4_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effD4_char_table_000[12] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0x9906),
    L2(3, 255, 0, 0, 0, 0, 0, 0x9907),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 effD4_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 effD4_char_table_001[48] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0x9908),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9909),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990A),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990B),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990C),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990D),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990E),
    L2(2, 0, 0, 0, 0, 0, 0, 0x990F),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9910),
    L2(2, 0, 0, 0, 0, 0, 0, 0x9911),
    L2(250, 255, 0, 0, 0, 0, 0, 0x9911),
    CMD(CM_ROA, 0, 0, 0),
};

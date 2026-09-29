/*
 * STAGE_CHAR.C  Stage background character scripts
 *
 * Scripts for the characters in the stage backgrounds, one table per stage (usa, rca, afc, hkg, grm, brz, orm, eng, jp3, chn, fnl, j11, frc, bns, j10).
 * Each *_char_table is an index of animation scripts ending in 0 followed by the scripts, in the
 * format of the fighters' tables: an effect's work takes the table as its char_table and
 * set_char_move_init starts its scripts. See charscr.h for the line layouts.
 */

#include "types.h"
#include "structs.h"
#include "charscr.h"

#pragma section TBL

extern const u16 usa_char_table_000[], usa_char_table_001[], usa_char_table_002[], usa_char_table_003[], usa_char_table_004[], usa_char_table_005[], usa_char_table_006[], usa_char_table_007[], usa_char_table_008[], usa_char_table_009[], usa_char_table_010[], usa_char_table_011[], usa_char_table_012[], usa_char_table_013[], usa_char_table_014[], usa_char_table_015[], usa_char_table_016[], usa_char_table_017[], usa_char_table_018[], usa_char_table_019[], usa_char_table_020[], usa_char_table_021[], usa_char_table_022[];
extern const u16 usa_char_table_000_head[];
extern const u16 usa_char_table_001_head[];
extern const u16 usa_char_table_002_head[];
extern const u16 usa_char_table_003_head[];
extern const u16 usa_char_table_004_head[];
extern const u16 usa_char_table_005_head[];
extern const u16 usa_char_table_006_head[];
extern const u16 usa_char_table_007_head[];
extern const u16 usa_char_table_008_head[];
extern const u16 usa_char_table_009_head[];
extern const u16 usa_char_table_010_head[];
extern const u16 usa_char_table_011_head[];
extern const u16 usa_char_table_012_head[];
extern const u16 usa_char_table_013_head[];
extern const u16 usa_char_table_014_head[];
extern const u16 usa_char_table_015_head[];
extern const u16 usa_char_table_016_head[];
extern const u16 usa_char_table_017_head[];
extern const u16 usa_char_table_018_head[];
extern const u16 usa_char_table_019_head[];
extern const u16 usa_char_table_020_head[];
extern const u16 usa_char_table_021_head[];
extern const u16 usa_char_table_022_head[];
extern const u16 rca_char_table_000[], rca_char_table_001[], rca_char_table_002[], rca_char_table_003[], rca_char_table_004[], rca_char_table_005[], rca_char_table_006[], rca_char_table_007[], rca_char_table_008[], rca_char_table_009[], rca_char_table_010[], rca_char_table_011[], rca_char_table_012[], rca_char_table_013[], rca_char_table_014[], rca_char_table_015[], rca_char_table_016[], rca_char_table_017[], rca_char_table_018[], rca_char_table_019[], rca_char_table_020[], rca_char_table_021[], rca_char_table_022[], rca_char_table_023[];
extern const u16 rca_char_table_000_head[];
extern const u16 rca_char_table_001_head[];
extern const u16 rca_char_table_002_head[];
extern const u16 rca_char_table_003_head[];
extern const u16 rca_char_table_004_head[];
extern const u16 rca_char_table_005_head[];
extern const u16 rca_char_table_006_head[];
extern const u16 rca_char_table_007_head[];
extern const u16 rca_char_table_008_head[];
extern const u16 rca_char_table_009_head[];
extern const u16 rca_char_table_010_head[];
extern const u16 rca_char_table_011_head[];
extern const u16 rca_char_table_012_head[];
extern const u16 rca_char_table_013_head[];
extern const u16 rca_char_table_014_head[];
extern const u16 rca_char_table_015_head[];
extern const u16 rca_char_table_016_head[];
extern const u16 rca_char_table_017_head[];
extern const u16 rca_char_table_018_head[];
extern const u16 rca_char_table_019_head[];
extern const u16 rca_char_table_020_head[];
extern const u16 rca_char_table_021_head[];
extern const u16 rca_char_table_022_head[];
extern const u16 rca_char_table_023_head[];
extern const u16 afc_char_table_000[], afc_char_table_001[], afc_char_table_002[], afc_char_table_003[], afc_char_table_004[], afc_char_table_005[], afc_char_table_006[], afc_char_table_007[], afc_char_table_008[], afc_char_table_009[], afc_char_table_010[], afc_char_table_011[], afc_char_table_012[], afc_char_table_013[], afc_char_table_014[], afc_char_table_015[], afc_char_table_016[], afc_char_table_017[], afc_char_table_018[], afc_char_table_019[];
extern const u16 afc_char_table_000_head[];
extern const u16 afc_char_table_001_head[];
extern const u16 afc_char_table_002_head[];
extern const u16 afc_char_table_003_head[];
extern const u16 afc_char_table_004_head[];
extern const u16 afc_char_table_005_head[];
extern const u16 afc_char_table_006_head[];
extern const u16 afc_char_table_007_head[];
extern const u16 afc_char_table_008_head[];
extern const u16 afc_char_table_009_head[];
extern const u16 afc_char_table_010_head[];
extern const u16 afc_char_table_011_head[];
extern const u16 afc_char_table_012_head[];
extern const u16 afc_char_table_013_head[];
extern const u16 afc_char_table_014_head[];
extern const u16 afc_char_table_015_head[];
extern const u16 afc_char_table_016_head[];
extern const u16 afc_char_table_017_head[];
extern const u16 afc_char_table_018_head[];
extern const u16 afc_char_table_019_head[];
extern const u16 hkg_char_table_000[], hkg_char_table_001[], hkg_char_table_002[], hkg_char_table_003[], hkg_char_table_004[], hkg_char_table_005[], hkg_char_table_006[], hkg_char_table_007[], hkg_char_table_008[], hkg_char_table_009[];
extern const u16 hkg_char_table_000_head[];
extern const u16 hkg_char_table_001_head[];
extern const u16 hkg_char_table_002_head[];
extern const u16 hkg_char_table_003_head[];
extern const u16 hkg_char_table_004_head[];
extern const u16 hkg_char_table_005_head[];
extern const u16 hkg_char_table_006_head[];
extern const u16 hkg_char_table_007_head[];
extern const u16 hkg_char_table_008_head[];
extern const u16 hkg_char_table_009_head[];
extern const u16 grm_char_table_000[], grm_char_table_001[], grm_char_table_002[], grm_char_table_003[], grm_char_table_004[], grm_char_table_005[], grm_char_table_006[], grm_char_table_007[], grm_char_table_008[], grm_char_table_009[], grm_char_table_010[], grm_char_table_011[], grm_char_table_012[], grm_char_table_013[], grm_char_table_014[];
extern const u16 grm_char_table_000_head[];
extern const u16 grm_char_table_001_head[];
extern const u16 grm_char_table_002_head[];
extern const u16 grm_char_table_003_head[];
extern const u16 grm_char_table_004_head[];
extern const u16 grm_char_table_005_head[];
extern const u16 grm_char_table_006_head[];
extern const u16 grm_char_table_007_head[];
extern const u16 grm_char_table_008_head[];
extern const u16 grm_char_table_009_head[];
extern const u16 grm_char_table_010_head[];
extern const u16 grm_char_table_011_head[];
extern const u16 grm_char_table_012_head[];
extern const u16 grm_char_table_013_head[];
extern const u16 grm_char_table_014_head[];
extern const u16 brz_char_table_000[], brz_char_table_001[], brz_char_table_002[], brz_char_table_003[], brz_char_table_004[], brz_char_table_005[], brz_char_table_006[], brz_char_table_007[], brz_char_table_008[], brz_char_table_009[], brz_char_table_010[], brz_char_table_011[];
extern const u16 brz_char_table_000_head[];
extern const u16 brz_char_table_001_head[];
extern const u16 brz_char_table_002_head[];
extern const u16 brz_char_table_003_head[];
extern const u16 brz_char_table_004_head[];
extern const u16 brz_char_table_005_head[];
extern const u16 brz_char_table_006_head[];
extern const u16 brz_char_table_007_head[];
extern const u16 brz_char_table_008_head[];
extern const u16 brz_char_table_009_head[];
extern const u16 brz_char_table_010_head[];
extern const u16 brz_char_table_011_head[];
extern const u16 orm_char_table_000[];
extern const u16 orm_char_table_000_head[];
extern const u16 eng_char_table_000[], eng_char_table_001[], eng_char_table_002[], eng_char_table_003[], eng_char_table_004[], eng_char_table_005[], eng_char_table_006[], eng_char_table_007[], eng_char_table_008[], eng_char_table_009[], eng_char_table_010[], eng_char_table_011[], eng_char_table_012[], eng_char_table_013[], eng_char_table_014[], eng_char_table_015[], eng_char_table_016[];
extern const u16 eng_char_table_000_head[];
extern const u16 eng_char_table_001_head[];
extern const u16 eng_char_table_002_head[];
extern const u16 eng_char_table_003_head[];
extern const u16 eng_char_table_004_head[];
extern const u16 eng_char_table_005_head[];
extern const u16 eng_char_table_006_head[];
extern const u16 eng_char_table_007_head[];
extern const u16 eng_char_table_008_head[];
extern const u16 eng_char_table_009_head[];
extern const u16 eng_char_table_010_head[];
extern const u16 eng_char_table_011_head[];
extern const u16 eng_char_table_012_head[];
extern const u16 eng_char_table_013_head[];
extern const u16 eng_char_table_014_head[];
extern const u16 eng_char_table_015_head[];
extern const u16 eng_char_table_016_head[];
extern const u16 jp3_char_table_000[], jp3_char_table_001[], jp3_char_table_002[], jp3_char_table_003[], jp3_char_table_004[], jp3_char_table_005[], jp3_char_table_006[], jp3_char_table_007[], jp3_char_table_008[], jp3_char_table_009[], jp3_char_table_010[];
extern const u16 jp3_char_table_000_head[];
extern const u16 jp3_char_table_001_head[];
extern const u16 jp3_char_table_002_head[];
extern const u16 jp3_char_table_003_head[];
extern const u16 jp3_char_table_004_head[];
extern const u16 jp3_char_table_005_head[];
extern const u16 jp3_char_table_006_head[];
extern const u16 jp3_char_table_007_head[];
extern const u16 jp3_char_table_008_head[];
extern const u16 jp3_char_table_009_head[];
extern const u16 jp3_char_table_010_head[];
extern const u16 chn_char_table_000[], chn_char_table_001[], chn_char_table_002[], chn_char_table_003[], chn_char_table_004[], chn_char_table_005[], chn_char_table_006[], chn_char_table_007[], chn_char_table_008[], chn_char_table_009[], chn_char_table_010[], chn_char_table_011[], chn_char_table_012[], chn_char_table_016[], chn_char_table_017[], chn_char_table_018[], chn_char_table_019[], chn_char_table_020[], chn_char_table_021[], chn_char_table_022[], chn_char_table_023[], chn_char_table_024[], chn_char_table_025[], chn_char_table_026[], chn_char_table_027[], chn_char_table_028[], chn_char_table_029[], chn_char_table_030[], chn_char_table_031[], chn_char_table_032[], chn_char_table_033[], chn_char_table_034[], chn_char_table_035[], chn_char_table_036[], chn_char_table_037[], chn_char_table_038[], chn_char_table_039[], chn_char_table_040[], chn_char_table_041[], chn_char_table_042[], chn_char_table_043[], chn_char_table_044[], chn_char_table_045[], chn_char_table_046[], chn_char_table_047[], chn_char_table_048[], chn_char_table_049[], chn_char_table_050[], chn_char_table_051[], chn_char_table_052[], chn_char_table_053[], chn_char_table_054[], chn_char_table_055[];
extern const u16 chn_char_table_000_head[];
extern const u16 chn_char_table_001_head[];
extern const u16 chn_char_table_002_head[];
extern const u16 chn_char_table_003_head[];
extern const u16 chn_char_table_004_head[];
extern const u16 chn_char_table_005_head[];
extern const u16 chn_char_table_006_head[];
extern const u16 chn_char_table_007_head[];
extern const u16 chn_char_table_008_head[];
extern const u16 chn_char_table_009_head[];
extern const u16 chn_char_table_010_head[];
extern const u16 chn_char_table_011_head[];
extern const u16 chn_char_table_012_head[];
extern const u16 chn_char_table_016_head[];
extern const u16 chn_char_table_017_head[];
extern const u16 chn_char_table_018_head[];
extern const u16 chn_char_table_019_head[];
extern const u16 chn_char_table_020_head[];
extern const u16 chn_char_table_021_head[];
extern const u16 chn_char_table_022_head[];
extern const u16 chn_char_table_023_head[];
extern const u16 chn_char_table_024_head[];
extern const u16 chn_char_table_025_head[];
extern const u16 chn_char_table_026_head[];
extern const u16 chn_char_table_027_head[];
extern const u16 chn_char_table_028_head[];
extern const u16 chn_char_table_029_head[];
extern const u16 chn_char_table_030_head[];
extern const u16 chn_char_table_031_head[];
extern const u16 chn_char_table_032_head[];
extern const u16 chn_char_table_033_head[];
extern const u16 chn_char_table_034_head[];
extern const u16 chn_char_table_035_head[];
extern const u16 chn_char_table_036_head[];
extern const u16 chn_char_table_037_head[];
extern const u16 chn_char_table_038_head[];
extern const u16 chn_char_table_039_head[];
extern const u16 chn_char_table_040_head[];
extern const u16 chn_char_table_041_head[];
extern const u16 chn_char_table_042_head[];
extern const u16 chn_char_table_043_head[];
extern const u16 chn_char_table_044_head[];
extern const u16 chn_char_table_045_head[];
extern const u16 chn_char_table_046_head[];
extern const u16 chn_char_table_047_head[];
extern const u16 chn_char_table_048_head[];
extern const u16 chn_char_table_049_head[];
extern const u16 chn_char_table_050_head[];
extern const u16 chn_char_table_051_head[];
extern const u16 chn_char_table_052_head[];
extern const u16 chn_char_table_053_head[];
extern const u16 chn_char_table_054_head[];
extern const u16 chn_char_table_055_head[];
extern const u16 fnl_char_table_000[], fnl_char_table_001[], fnl_char_table_002[], fnl_char_table_003[], fnl_char_table_004[], fnl_char_table_005[], fnl_char_table_006[], fnl_char_table_007[];
extern const u16 fnl_char_table_000_head[];
extern const u16 fnl_char_table_001_head[];
extern const u16 fnl_char_table_002_head[];
extern const u16 fnl_char_table_003_head[];
extern const u16 fnl_char_table_004_head[];
extern const u16 fnl_char_table_005_head[];
extern const u16 fnl_char_table_006_head[];
extern const u16 fnl_char_table_007_head[];
extern const u16 j11_char_table_000[], j11_char_table_001[], j11_char_table_002[], j11_char_table_003[], j11_char_table_004[], j11_char_table_005[], j11_char_table_006[];
extern const u16 j11_char_table_000_head[];
extern const u16 j11_char_table_001_head[];
extern const u16 j11_char_table_002_head[];
extern const u16 j11_char_table_003_head[];
extern const u16 j11_char_table_004_head[];
extern const u16 j11_char_table_005_head[];
extern const u16 j11_char_table_006_head[];
extern const u16 frc_char_table_000[], frc_char_table_001[], frc_char_table_002[], frc_char_table_003[], frc_char_table_004[], frc_char_table_005[], frc_char_table_006[], frc_char_table_007[], frc_char_table_008[], frc_char_table_009[], frc_char_table_010[], frc_char_table_011[], frc_char_table_012[], frc_char_table_013[], frc_char_table_014[], frc_char_table_015[], frc_char_table_016[], frc_char_table_017[], frc_char_table_018[], frc_char_table_019[], frc_char_table_020[], frc_char_table_021[], frc_char_table_022[], frc_char_table_023[], frc_char_table_024[];
extern const u16 frc_char_table_000_head[];
extern const u16 frc_char_table_001_head[];
extern const u16 frc_char_table_002_head[];
extern const u16 frc_char_table_003_head[];
extern const u16 frc_char_table_004_head[];
extern const u16 frc_char_table_005_head[];
extern const u16 frc_char_table_006_head[];
extern const u16 frc_char_table_007_head[];
extern const u16 frc_char_table_008_head[];
extern const u16 frc_char_table_009_head[];
extern const u16 frc_char_table_010_head[];
extern const u16 frc_char_table_011_head[];
extern const u16 frc_char_table_012_head[];
extern const u16 frc_char_table_013_head[];
extern const u16 frc_char_table_014_head[];
extern const u16 frc_char_table_015_head[];
extern const u16 frc_char_table_016_head[];
extern const u16 frc_char_table_017_head[];
extern const u16 frc_char_table_018_head[];
extern const u16 frc_char_table_019_head[];
extern const u16 frc_char_table_020_head[];
extern const u16 frc_char_table_021_head[];
extern const u16 frc_char_table_022_head[];
extern const u16 frc_char_table_023_head[];
extern const u16 frc_char_table_024_head[];
extern const u16 bns_char_table_000[], bns_char_table_001[], bns_char_table_002[], bns_char_table_003[], bns_char_table_004[], bns_char_table_005[], bns_char_table_006[], bns_char_table_007[], bns_char_table_008[], bns_char_table_009[], bns_char_table_010[], bns_char_table_011[], bns_char_table_012[];
extern const u16 bns_char_table_000_head[];
extern const u16 bns_char_table_001_head[];
extern const u16 bns_char_table_002_head[];
extern const u16 bns_char_table_003_head[];
extern const u16 bns_char_table_004_head[];
extern const u16 bns_char_table_005_head[];
extern const u16 bns_char_table_006_head[];
extern const u16 bns_char_table_007_head[];
extern const u16 bns_char_table_008_head[];
extern const u16 bns_char_table_009_head[];
extern const u16 bns_char_table_010_head[];
extern const u16 bns_char_table_011_head[];
extern const u16 bns_char_table_012_head[];
extern const u16 j10_char_table_000[], j10_char_table_001[], j10_char_table_002[], j10_char_table_003[], j10_char_table_004[], j10_char_table_005[], j10_char_table_006[], j10_char_table_007[], j10_char_table_008[], j10_char_table_009[], j10_char_table_010[], j10_char_table_011[], j10_char_table_012[], j10_char_table_013[], j10_char_table_014[], j10_char_table_015[], j10_char_table_016[], j10_char_table_017[], j10_char_table_018[], j10_char_table_019[], j10_char_table_020[], j10_char_table_021[], j10_char_table_022[], j10_char_table_023[];
extern const u16 j10_char_table_000_head[];
extern const u16 j10_char_table_001_head[];
extern const u16 j10_char_table_002_head[];
extern const u16 j10_char_table_003_head[];
extern const u16 j10_char_table_004_head[];
extern const u16 j10_char_table_005_head[];
extern const u16 j10_char_table_006_head[];
extern const u16 j10_char_table_007_head[];
extern const u16 j10_char_table_008_head[];
extern const u16 j10_char_table_009_head[];
extern const u16 j10_char_table_010_head[];
extern const u16 j10_char_table_011_head[];
extern const u16 j10_char_table_012_head[];
extern const u16 j10_char_table_013_head[];
extern const u16 j10_char_table_014_head[];
extern const u16 j10_char_table_015_head[];
extern const u16 j10_char_table_016_head[];
extern const u16 j10_char_table_017_head[];
extern const u16 j10_char_table_018_head[];
extern const u16 j10_char_table_019_head[];
extern const u16 j10_char_table_020_head[];
extern const u16 j10_char_table_021_head[];
extern const u16 j10_char_table_022_head[];
extern const u16 j10_char_table_023_head[];

/* usa_char_table scripts: 23 entries */
const u16* const usa_char_table[24] = {
    usa_char_table_000, usa_char_table_001, usa_char_table_002, usa_char_table_003, usa_char_table_004, usa_char_table_005,
    usa_char_table_006, usa_char_table_007, usa_char_table_008, usa_char_table_009, usa_char_table_010, usa_char_table_011,
    usa_char_table_012, usa_char_table_013, usa_char_table_014, usa_char_table_015, usa_char_table_016, usa_char_table_017,
    usa_char_table_018, usa_char_table_019, usa_char_table_020, usa_char_table_021, usa_char_table_022,
    0
};

const u16 usa_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8D0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8D1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8D2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8D3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_004[348] = {
    L2(50, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F2),
    CMD(CM_FOR, 0, 0, 10),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD900),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD902),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD904),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD906),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD908),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90E),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD910),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD912),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD914),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD916),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD918),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91C),
    L2(250, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD91E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F2),
    CMD(CM_FOR, 0, 0, 15),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD900),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD902),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD904),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD906),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD908),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90E),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD910),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD912),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD914),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD916),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD918),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91C),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91E),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD91E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_005[348] = {
    L2(50, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8ED),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F3),
    CMD(CM_FOR, 0, 0, 10),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD901),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD903),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD905),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD907),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD909),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90F),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD911),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD913),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD915),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD917),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD919),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91D),
    L2(250, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD91F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8D9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8DF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8E9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8ED),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8EF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F3),
    CMD(CM_FOR, 0, 0, 15),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8F9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD8FF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD901),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD903),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD905),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD907),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD909),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD90F),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD911),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD913),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD915),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD917),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD919),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD91D),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD91F),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD91F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_006[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD926),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_007[80] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD926),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD92C),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_008[56] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_009[52] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD92B),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_010[272] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD926),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_011[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD929),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD928),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD927),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD926),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD920),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD921),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD922),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD923),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD924),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD925),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD926),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_012[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD934),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_013[80] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD934),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD93A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_014[56] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92E),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_015[56] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(250, 1, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD93A),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_016[200] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93A),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD934),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_017[104] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD939),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD938),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD937),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD936),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD935),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD934),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD930),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD931),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD932),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD933),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD934),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_018[8] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_019[8] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_020[8] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_021[8] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD93E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 usa_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 usa_char_table_022[8] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD92D),
    CMD(CM_ROA, 0, 0, 0),
};

/* rca_char_table scripts: 24 entries */
const u16* const rca_char_table[25] = {
    rca_char_table_000, rca_char_table_001, rca_char_table_002, rca_char_table_003, rca_char_table_004, rca_char_table_005,
    rca_char_table_006, rca_char_table_007, rca_char_table_008, rca_char_table_009, rca_char_table_010, rca_char_table_011,
    rca_char_table_012, rca_char_table_013, rca_char_table_014, rca_char_table_015, rca_char_table_016, rca_char_table_017,
    rca_char_table_018, rca_char_table_019, rca_char_table_020, rca_char_table_021, rca_char_table_022, rca_char_table_023,
    0
};

const u16 rca_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD800),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD801),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD802),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD803),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD804),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_005[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD805),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_006[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xD806),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_007[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD807),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_008[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD808),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_009[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD809),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_010[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD80A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_011[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD80B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_012[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD80C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_013[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD80D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_014[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD80E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_015[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD80F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_016[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD810),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_017[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD811),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_018[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xD812),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_019[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD813),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_020[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD814),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_021[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD815),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_022[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xD816),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 rca_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 rca_char_table_023[318] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD817),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD818),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD819),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD81A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD81B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD81A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD819),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD818),
    CMD(CM_ROA, 0, 0, 0),
    L2(6, 70, 3927, 1, 0, 100, 6, 0xF58C),
    L2(6, 70, 3930, 1, 0, 100, 6, 0xF5BC),
    L2(6, 70, 3933, 1, 0, 100, 6, 0xF5EC),
    L2(6, 70, 3936, 1, 0, 100, 6, 0xF61C),
    L2(6, 70, 3939, 1, 0, 100, 6, 0xF764),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 2304, 0),
    CMD(CM_DUMMY, -9680, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 2304, 0),
    CMD(CM_DUMMY, -9679, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 2304, 0),
    CMD(CM_DUMMY, -9678, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 1024, 0),
    CMD(CM_DUMMY, -9677, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 1024, 0),
    CMD(CM_DUMMY, -9676, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 1024, 0),
    CMD(CM_DUMMY, -9675, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 11264, 0),
    CMD(CM_DUMMY, -9674, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 11264, 0),
    CMD(CM_DUMMY, -9673, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 12, 0),
    CMD(CM_DUMMY, 10, -19456, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 13, 0),
    CMD(CM_DUMMY, 0, 2560, 0),
    CMD(CM_DUMMY, -9672, 2560, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9670, 20480, 0),
    CMD(CM_DUMMY, -9669, 2560, 0),
    CMD(CM_DUMMY, -9670, 2560, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9668, 20480, 0),
    CMD(CM_DUMMY, -9667, 2560, 0),
    CMD(CM_DUMMY, -9668, 12, 0),
    CMD(CM_DUMMY, 4, -19456, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 13, 0),
    CMD(CM_DUMMY, 0, 2560, 0),
    CMD(CM_DUMMY, -9672, 2560, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9670, 20480, 0),
    CMD(CM_DUMMY, -9669, 2560, 0),
    CMD(CM_DUMMY, -9670, 2560, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9668, 20480, 0),
    CMD(CM_DUMMY, -9667, 2560, 0),
    CMD(CM_DUMMY, -9668, 12, 0),
    CMD(CM_DUMMY, 2, -19456, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 2560, 0),
    CMD(CM_DUMMY, -9672, 1536, 0),
    CMD(CM_DUMMY, -9671, 13, 0),
    CMD(CM_DUMMY, 0, 1, 0),
    CMD(CM_DUMMY, 0, 2, 0),
    CMD(CM_DUMMY, 0, 2304, 0),
    CMD(CM_DUMMY, -9664, 1, 0),
    0x0000, 0x0000,
};

/* afc_char_table scripts: 20 entries */
const u16* const afc_char_table[21] = {
    afc_char_table_000, afc_char_table_001, afc_char_table_002, afc_char_table_003, afc_char_table_004, afc_char_table_005,
    afc_char_table_006, afc_char_table_007, afc_char_table_008, afc_char_table_009, afc_char_table_010, afc_char_table_011,
    afc_char_table_012, afc_char_table_013, afc_char_table_014, afc_char_table_015, afc_char_table_016, afc_char_table_017,
    afc_char_table_018, afc_char_table_019,
    0
};

const u16 afc_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD880),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD881),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD882),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD883),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD884),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_005[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD885),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_006[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD886),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_007[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD887),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_008[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD888),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_009[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD889),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_010[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD88A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_011[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD88B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_012[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD88C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_013[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD88D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_014[28] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0xD88E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xD88F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xD890),
    L2(10, 0, 0, 0, 0, 0, 0, 0xD891),
    L2(10, 0, 0, 0, 0, 0, 0, 0xD890),
    L2(10, 0, 0, 0, 0, 0, 0, 0xD88F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_015[28] = {
    L2(200, 0, 0, 0, 0, 0, 0, 0xD895),
    L2(16, 0, 0, 0, 0, 0, 0, 0xD896),
    L2(16, 0, 0, 0, 0, 0, 0, 0xD897),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD898),
    L2(16, 0, 0, 0, 0, 0, 0, 0xD897),
    L2(16, 0, 0, 0, 0, 0, 0, 0xD896),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_016[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD89F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_017[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8A0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_018[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8A1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 afc_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 afc_char_table_019[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD8A2),
    CMD(CM_ROA, 0, 0, 0),
};

/* hkg_char_table scripts: 10 entries */
const u16* const hkg_char_table[11] = {
    hkg_char_table_000, hkg_char_table_001, hkg_char_table_002, hkg_char_table_003, hkg_char_table_004, hkg_char_table_005,
    hkg_char_table_006, hkg_char_table_007, hkg_char_table_008, hkg_char_table_009,
    0
};

const u16 hkg_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_000[120] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0xD990),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD991),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD992),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD993),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD994),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD995),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD996),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD997),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD998),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD999),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD99A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD99B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD99C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD99D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD990),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD99E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD99F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9A0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9A1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9A2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9A3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD9A4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD9A5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xD9A6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9A7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9A8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9A9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AA),
    L2(4, 255, 0, 0, 0, 0, 0, 0xD9AA),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_001[52] = {
    L2(50, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    L2(50, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    L2(100, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    L2(40, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    L2(250, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_JSR, 0, 5, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_002[20] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_003[44] = {
    L2(40, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_JSR, 0, 6, 1),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_JSR, 0, 6, 1),
    L2(20, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_JSR, 0, 6, 1),
    L2(100, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_JSR, 0, 6, 1),
    L2(60, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_JSR, 0, 6, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_004[52] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    L2(200, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    L2(90, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    L2(120, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    L2(50, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    L2(100, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_JSR, 0, 7, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_005[96] = {
    CMD(CM_EXEC, 52, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9AF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9B0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9B1),
    L2(84, 0, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B4),
    CMD(CM_NEX, 0, 0, 0),
    L2(32, 0, 0, 0, 0, 0, 0, 0xD9B2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B4),
    L2(16, 0, 0, 0, 0, 0, 0, 0xD9B2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9B3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xD9B4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9B2),
    L2(2, 255, 0, 0, 0, 0, 0, 0xD9B2),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_006[56] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_FOR, 0, 0, 3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C1),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C3),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9C8),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD9C8),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_007[92] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_FOR, 0, 0, 2),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BE),
    CMD(CM_NEX, 0, 0, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9B9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BF),
    L2(43, 0, 0, 0, 0, 0, 0, 0xD9C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BC),
    L2(15, 0, 0, 0, 0, 0, 0, 0xD9C0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9BF),
    L2(15, 0, 0, 0, 0, 0, 0, 0xD9C0),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD9C0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_008[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CC),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CA),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9C9),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CA),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CB),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CC),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD9CC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 hkg_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 hkg_char_table_009[36] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9D0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CE),
    L2(2, 0, 0, 0, 0, 0, 0, 0xD9CD),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CE),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9CF),
    L2(1, 0, 0, 0, 0, 0, 0, 0xD9D0),
    L2(1, 255, 0, 0, 0, 0, 0, 0xD9D0),
    CMD(CM_ROA, 0, 0, 0),
};

/* grm_char_table scripts: 15 entries */
const u16* const grm_char_table[16] = {
    grm_char_table_000, grm_char_table_001, grm_char_table_002, grm_char_table_003, grm_char_table_004, grm_char_table_005,
    grm_char_table_006, grm_char_table_007, grm_char_table_008, grm_char_table_009, grm_char_table_010, grm_char_table_011,
    grm_char_table_012, grm_char_table_013, grm_char_table_014,
    0
};

const u16 grm_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_000[176] = {
    L2(15, 0, 0, 0, 0, 0, 0, 0xDA70),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDA70),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDA74),
    L2(25, 0, 0, 0, 0, 0, 0, 0xDA75),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA76),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA77),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA78),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA79),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA7A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA7B),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA79),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA7A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA79),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDA7B),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA7A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA7B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA79),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA78),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA77),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDA70),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA71),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA72),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA73),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA74),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDA75),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDA76),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA7C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA7D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA7E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA7F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_005[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA80),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_006[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA81),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_007[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA82),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_008[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA83),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_009[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA84),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_010[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA85),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_011[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA86),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_012[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDA85),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_013[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA85),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA87),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA88),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA89),
    L2(3, 255, 0, 0, 0, 0, 0, 0xDA89),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 grm_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 grm_char_table_014[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA85),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA89),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA88),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDA87),
    L2(3, 255, 0, 0, 0, 0, 0, 0xDA87),
    CMD(CM_ROA, 0, 0, 0),
};

/* brz_char_table scripts: 12 entries */
const u16* const brz_char_table[13] = {
    brz_char_table_000, brz_char_table_001, brz_char_table_002, brz_char_table_003, brz_char_table_004, brz_char_table_005,
    brz_char_table_006, brz_char_table_007, brz_char_table_008, brz_char_table_009, brz_char_table_010, brz_char_table_011,
    0
};

const u16 brz_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDAC0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDAC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_002[68] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAC9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACC),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACD),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACE),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDACF),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDAD2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_004[236] = {
    CMD(CM_FOR, 0, 0, 20),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADC),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADD),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADE),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADF),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE1),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEC),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAED),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAD9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADC),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADD),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADE),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDADF),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE1),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE4),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE5),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE8),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAE9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEA),
    L2(70, 0, 0, 0, 0, 0, 0, 0xDAEB),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAEC),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDAED),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_005[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDAEE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_006[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDEE0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_007[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDEE1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_008[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDEE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_009[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE5),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDEE2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_010[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDEE7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 brz_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 brz_char_table_011[40] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEE7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEEB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEEA),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDEE7),
    CMD(CM_ROA, 0, 0, 0),
};

/* orm_char_table scripts: 1 entries */
const u16* const orm_char_table[2] = {
    orm_char_table_000,
    0
};

const u16 orm_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 orm_char_table_000[8] = {
    L2(11, 0, 0, 0, 0, 0, 0, 0xDB00),
    CMD(CM_ROA, 0, 0, 0),
};

/* eng_char_table scripts: 17 entries */
const u16* const eng_char_table[18] = {
    eng_char_table_000, eng_char_table_001, eng_char_table_002, eng_char_table_003, eng_char_table_004, eng_char_table_005,
    eng_char_table_006, eng_char_table_007, eng_char_table_008, eng_char_table_009, eng_char_table_010, eng_char_table_011,
    eng_char_table_012, eng_char_table_013, eng_char_table_014, eng_char_table_015, eng_char_table_016,
    0
};

const u16 eng_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB40),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB41),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_002[124] = {
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 16, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 14, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 16, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 15, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 14, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 15, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 14, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 16, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_JSR, 0, 15, 3),
    CMD(CM_JSR, 0, 13, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_003[88] = {
    L2(180, 0, 0, 0, 0, 0, 0, 0xDB42),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB43),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB44),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB45),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB44),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB43),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB43),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB44),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB45),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB46),
    CMD(CM_FOR, 0, 0, 10),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB47),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB77),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB48),
    CMD(CM_NEX, 0, 0, 0),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB47),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB46),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB45),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB44),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB43),
    L2(124, 0, 0, 0, 0, 0, 0, 0xDB42),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_004[84] = {
    L2(180, 0, 0, 0, 0, 0, 0, 0xDB49),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB4D),
    CMD(CM_FOR, 0, 0, 10),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4E),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB78),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4F),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4E),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4D),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4C),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4B),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDB4A),
    L2(95, 0, 0, 0, 0, 0, 0, 0xDB49),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_005[84] = {
    L2(184, 0, 0, 0, 0, 0, 0, 0xDB50),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB51),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB52),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB53),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB52),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB51),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB52),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB53),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB54),
    CMD(CM_FOR, 0, 0, 10),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB55),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB79),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB56),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB55),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB54),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB53),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB52),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB51),
    L2(48, 0, 0, 0, 0, 0, 0, 0xDB50),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_006[84] = {
    L2(188, 0, 0, 0, 0, 0, 0, 0xDB57),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB58),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB59),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5A),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB59),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB58),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5B),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5C),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB7A),
    CMD(CM_FOR, 0, 0, 10),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5D),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5C),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB7A),
    CMD(CM_NEX, 0, 0, 0),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5D),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5C),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5B),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB5A),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB59),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB58),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_007[52] = {
    CMD(CM_FOR, 0, 0, 6),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB5E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_NEX, 0, 0, 0),
    L2(200, 0, 0, 0, 0, 0, 0, 0xDB76),
    L2(104, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_FOR, 0, 0, 6),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB5E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_NEX, 0, 0, 0),
    L2(240, 0, 0, 0, 0, 0, 0, 0xDB76),
    L2(240, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_008[52] = {
    CMD(CM_FOR, 0, 0, 6),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB5F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_NEX, 0, 0, 0),
    L2(200, 0, 0, 0, 0, 0, 0, 0xDB76),
    L2(104, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_FOR, 0, 0, 6),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB5F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_NEX, 0, 0, 0),
    L2(240, 0, 0, 0, 0, 0, 0, 0xDB76),
    L2(240, 0, 0, 0, 0, 0, 0, 0xDB76),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_009[108] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB60),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB61),
    CMD(CM_NEX, 0, 0, 0),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDB62),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB63),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB62),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB63),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB62),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB63),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB60),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB61),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB60),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB61),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB62),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB63),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB62),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB63),
    L2(66, 0, 0, 0, 0, 0, 0, 0xDB64),
    L2(36, 0, 0, 0, 0, 0, 0, 0xDB65),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDB64),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB65),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB64),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB65),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB64),
    L2(30, 0, 0, 0, 0, 0, 0, 0xDB65),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_010[44] = {
    L2(132, 0, 0, 0, 0, 0, 0, 0xDB66),
    L2(92, 0, 0, 0, 0, 0, 0, 0xDB67),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB68),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB69),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB6A),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB69),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDB6A),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB69),
    L2(44, 0, 0, 0, 0, 0, 0, 0xDB6A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDB68),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_011[68] = {
    L2(122, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB72),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB72),
    L2(28, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB73),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB74),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB73),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB74),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB73),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDB71),
    L2(112, 0, 0, 0, 0, 0, 0, 0xDB74),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_012[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDB75),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_013[88] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDB6B),
    CMD(CM_ROA, 0, 0, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB6B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB6C),
    L2(25, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB6E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB70),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB6C),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6F),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDB70),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB6F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6E),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDB6C),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_014[120] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDB6B),
    CMD(CM_ROA, 0, 0, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB6C),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB6D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7B),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB6B),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7C),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7C),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB7F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB7F),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7E),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7D),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB7C),
    L2(30, 0, 0, 0, 0, 0, 0, 0xDB6B),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_015[76] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDB80),
    CMD(CM_ROA, 0, 0, 0),
    L2(36, 0, 0, 0, 0, 0, 0, 0xDB80),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB81),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB82),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB81),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB81),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB81),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB83),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDB80),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB81),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB82),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDB83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDB81),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 eng_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 eng_char_table_016[100] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDB84),
    CMD(CM_ROA, 0, 0, 0),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB84),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB85),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB86),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB87),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB88),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB89),
    L2(15, 0, 0, 0, 0, 0, 0, 0xDB8A),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8C),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8D),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8F),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB90),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8C),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDB8B),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB8A),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB89),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB88),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB87),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB86),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDB85),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* jp3_char_table scripts: 11 entries */
const u16* const jp3_char_table[12] = {
    jp3_char_table_000, jp3_char_table_001, jp3_char_table_002, jp3_char_table_003, jp3_char_table_004, jp3_char_table_005,
    jp3_char_table_006, jp3_char_table_007, jp3_char_table_008, jp3_char_table_009, jp3_char_table_010,
    0
};

const u16 jp3_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_000[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_001[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_002[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_003[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_004[8] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_005[24] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF5),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF6),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF7),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF8),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBF9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_006[28] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDC00),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC01),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC02),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC03),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC04),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDC04),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_007[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDC1F),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_008[24] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBFA),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBFB),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBFC),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBFD),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDBFE),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_009[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDC05),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 jp3_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 jp3_char_table_010[108] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC06),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC07),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC08),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC09),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC0A),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC0B),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC0C),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC0D),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC0E),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC0F),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC10),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC11),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC12),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC13),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC14),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC15),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC16),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC17),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC18),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC19),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC1A),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC1B),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC1C),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC1D),
    L2(3, 9, 0, 0, 0, 0, 0, 0xDC1E),
    L2(3, 255, 0, 0, 0, 0, 0, 0xDC1E),
    CMD(CM_ROA, 0, 0, 0),
};

/* chn_char_table scripts: 56 entries */
const u16* const chn_char_table[57] = {
    chn_char_table_000, chn_char_table_001, chn_char_table_002, chn_char_table_003, chn_char_table_004, chn_char_table_005,
    chn_char_table_006, chn_char_table_007, chn_char_table_008, chn_char_table_009, chn_char_table_010, chn_char_table_011,
    chn_char_table_012, chn_char_table_010, chn_char_table_011, chn_char_table_012, chn_char_table_016, chn_char_table_017,
    chn_char_table_018, chn_char_table_019, chn_char_table_020, chn_char_table_021, chn_char_table_022, chn_char_table_023,
    chn_char_table_024, chn_char_table_025, chn_char_table_026, chn_char_table_027, chn_char_table_028, chn_char_table_029,
    chn_char_table_030, chn_char_table_031, chn_char_table_032, chn_char_table_033, chn_char_table_034, chn_char_table_035,
    chn_char_table_036, chn_char_table_037, chn_char_table_038, chn_char_table_039, chn_char_table_040, chn_char_table_041,
    chn_char_table_042, chn_char_table_043, chn_char_table_044, chn_char_table_045, chn_char_table_046, chn_char_table_047,
    chn_char_table_048, chn_char_table_049, chn_char_table_050, chn_char_table_051, chn_char_table_052, chn_char_table_053,
    chn_char_table_054, chn_char_table_055,
    0
};

const u16 chn_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE10),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE11),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE12),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE13),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE14),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_005[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE15),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_006[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDE16),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_007[180] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE17),
    CMD(CM_PAXY, 0, 1024, 768),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE18),
    CMD(CM_PAXY, 0, -1024, 512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE19),
    CMD(CM_PAXY, 0, -5376, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1A),
    CMD(CM_PAXY, 0, -2048, -768),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1B),
    CMD(CM_PAXY, 0, -1792, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1C),
    CMD(CM_PAXY, 0, -2816, 6912),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1D),
    CMD(CM_PAXY, 0, -1792, 1536),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1E),
    CMD(CM_PAXY, 0, -3328, 2560),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE1F),
    CMD(CM_PAXY, 0, -1792, -4352),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE20),
    CMD(CM_PAXY, 0, -1792, -2816),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDE21),
    CMD(CM_PAXY, 0, -1792, -2560),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE22),
    CMD(CM_PAXY, 0, -2048, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE23),
    CMD(CM_PAXY, 0, -1280, -768),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE24),
    CMD(CM_PAXY, 0, 512, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE25),
    CMD(CM_PAXY, 0, 512, 512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE26),
    CMD(CM_PAXY, 0, -1280, -256),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE27),
    CMD(CM_PAXY, 0, -1792, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE28),
    CMD(CM_PAXY, 0, -2816, 256),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDE29),
    CMD(CM_PAXY, 0, -1536, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2A),
    CMD(CM_PAXY, 0, -1280, -1024),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2B),
    CMD(CM_PAXY, 0, -768, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2C),
    L2(250, 1, 0, 0, 0, 0, 0, 0xDE2C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_008[244] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2D),
    CMD(CM_PAXY, 0, -512, 2048),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2E),
    CMD(CM_PA_Y, 0, 0, 3072),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2F),
    CMD(CM_PA_Y, 0, 0, 2560),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE30),
    CMD(CM_PA_Y, 0, 0, 2304),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDE31),
    CMD(CM_PA_Y, 0, 0, 768),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE32),
    CMD(CM_PAXY, 0, -512, 2304),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE38),
    CMD(CM_PA_Y, 0, 0, 1792),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE31),
    CMD(CM_PA_Y, 0, 0, 512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE32),
    CMD(CM_PAXY, 0, -1536, 2304),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE33),
    CMD(CM_PAXY, 0, -1536, 256),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDE35),
    CMD(CM_PAXY, 0, -512, -768),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE38),
    CMD(CM_PAXY, 0, -512, -3328),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE2F),
    CMD(CM_PAXY, 0, -1024, -2560),
    L2(2, 2, 0, 0, 0, 0, 0, 0xDE30),
    CMD(CM_PA_Y, 0, 0, -1280),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE31),
    CMD(CM_PA_Y, 0, 0, -1536),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE32),
    CMD(CM_PAXY, 0, -512, -1536),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE34),
    CMD(CM_PA_Y, 0, 0, -2304),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE35),
    CMD(CM_PA_Y, 0, 0, -3328),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE38),
    CMD(CM_PA_Y, 0, 0, -3328),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE2E),
    CMD(CM_PA_Y, 0, 0, -2304),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE2F),
    CMD(CM_PAXY, 0, -512, -1280),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE30),
    CMD(CM_PAXY, 0, -512, -768),
    L2(2, 2, 0, 0, 0, 0, 0, 0xDE31),
    CMD(CM_PAXY, 0, 2048, 1792),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE32),
    CMD(CM_PAXY, 0, 2048, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE38),
    CMD(CM_PAXY, 0, 1792, -1024),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2E),
    CMD(CM_PAXY, 0, 1280, -256),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE2F),
    CMD(CM_PAXY, 0, 1024, -768),
    L2(2, 2, 0, 0, 0, 0, 0, 0xDE31),
    CMD(CM_PAXY, 0, 1536, -3072),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE32),
    CMD(CM_PA_Y, 0, 0, -2304),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDE39),
    L2(250, 1, 0, 0, 0, 0, 0, 0xDE39),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_009[52] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3A),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3B),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3C),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3D),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE3F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE40),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE41),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE42),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE43),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDE44),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDE44),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_010[12] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4A),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDE4A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_011[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE49),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE48),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE47),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE46),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE45),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDE45),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_012[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE4F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE50),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE51),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE52),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE53),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE54),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE55),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE56),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE57),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE58),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE59),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDE59),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_016[108] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A8),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0A9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AA),
    CMD(CM_FOR, 0, 0, 4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AD),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B0),
    CMD(CM_FOR, 0, 0, 5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B3),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0AF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_017[136] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0xE0B4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B8),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BF),
    L2(24, 0, 0, 0, 0, 0, 0, 0xE0C0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BF),
    L2(50, 0, 0, 0, 0, 0, 0, 0xE0C0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0BF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C4),
    CMD(CM_FOR, 0, 0, 3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C7),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C8),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0C9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B8),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0B5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_018[112] = {
    L2(24, 0, 0, 0, 0, 0, 0, 0xE0CB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CC),
    CMD(CM_FOR, 0, 0, 9),
    L2(24, 0, 0, 0, 0, 0, 0, 0xE0CB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CC),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CF),
    L2(14, 0, 0, 0, 0, 0, 0, 0xE0D0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D3),
    L2(14, 0, 0, 0, 0, 0, 0, 0xE0D4),
    L2(35, 0, 0, 0, 0, 0, 0, 0xE0D5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D1),
    L2(14, 0, 0, 0, 0, 0, 0, 0xE0D0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0CF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_019[184] = {
    L2(120, 0, 0, 0, 0, 0, 0, 0xE0D8),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E5),
    L2(70, 0, 0, 0, 0, 0, 0, 0xE0E6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E8),
    CMD(CM_FOR2, 0, 0, 2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E8),
    L2(14, 0, 0, 0, 0, 0, 0, 0xE0E6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E8),
    CMD(CM_FOR, 0, 0, 2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E7),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E8),
    CMD(CM_NEX, 0, 0, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xE0E8),
    CMD(CM_NEX2, 0, 0, 0),
    L2(28, 0, 0, 0, 0, 0, 0, 0xE0E6),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E2),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DD),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0DA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0D9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_020[140] = {
    CMD(CM_FOR, 0, 0, 9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EA),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0ED),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EE),
    L2(70, 0, 0, 0, 0, 0, 0, 0xE0EF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F2),
    CMD(CM_FOR, 0, 0, 9),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F4),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F5),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F4),
    CMD(CM_NEX, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F3),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F1),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0F0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EF),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EE),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0ED),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EC),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EB),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0EA),
    L2(7, 0, 0, 0, 0, 0, 0, 0xE0E9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_021[124] = {
    L2(18, 0, 0, 0, 0, 0, 0, 0xE0F6),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F7),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F8),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F9),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FA),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FB),
    L2(24, 0, 0, 0, 0, 0, 0, 0xE0FC),
    L2(24, 0, 0, 0, 0, 0, 0, 0xE0FD),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FE),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FF),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FE),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FF),
    L2(54, 0, 0, 0, 0, 0, 0, 0xE0FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE100),
    L2(96, 0, 0, 0, 0, 0, 0, 0xE101),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE100),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FC),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE102),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE103),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE104),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE105),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE106),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE107),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE108),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE109),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0FA),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F9),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F8),
    L2(6, 0, 0, 0, 0, 0, 0, 0xE0F7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_022[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE5A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_023[8] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE66),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_024[68] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE6C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE6D),
    L2(4, 9, 0, 0, 0, 0, 0, 0xDE6E),
    L2(4, 9, 0, 0, 0, 0, 0, 0xDE6F),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE70),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE71),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE72),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE73),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE74),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE75),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE76),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE77),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE78),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE79),
    L2(6, 9, 0, 0, 0, 0, 0, 0xDE7A),
    L2(6, 255, 0, 0, 0, 0, 0, 0xDE7A),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_025_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_025[48] = {
    CMD(CM_EXEC, 3, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE84),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE85),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE86),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE87),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE88),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE89),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8C),
    L2(6, 255, 0, 0, 0, 0, 0, 0xDE8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_026_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_026[84] = {
    CMD(CM_EXEC, 3, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE7B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE7C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE7D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE7E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE7F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE80),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE81),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE82),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE83),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE84),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE85),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE86),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE87),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE88),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE89),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDE8C),
    L2(6, 255, 0, 0, 0, 0, 0, 0xDE8C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_027_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_027[72] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE8D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE8E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE8F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE90),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE91),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE92),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE93),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE94),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE95),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE96),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE97),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE98),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE99),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9C),
    L2(6, 255, 0, 0, 0, 0, 0, 0xDE9C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_028_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_028[28] = {
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 36, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    L2(30, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_029_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_029[180] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 37, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 38, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 36, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 41, 3),
    CMD(CM_JSR, 0, 43, 3),
    CMD(CM_JSR, 0, 42, 3),
    CMD(CM_JSR, 0, 43, 3),
    CMD(CM_JSR, 0, 43, 3),
    CMD(CM_JSR, 0, 40, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 36, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 38, 3),
    CMD(CM_JSR, 0, 37, 3),
    CMD(CM_JSR, 0, 37, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 36, 3),
    CMD(CM_JSR, 0, 41, 3),
    L2(3, 255, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_030_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_030[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDEBC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_031_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_031[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_032_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_032[16] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(4, 255, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_033_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_033[20] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBC),
    L2(4, 255, 0, 0, 1, 0, 0, 0xDEBC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_034_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_034[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_035_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_035[36] = {
    L2(40, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 42, 3),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(5, 255, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_036_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_036[36] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEB8),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_037_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_037[40] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDEB9),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEBA),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_038_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_038[48] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBB),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBC),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBE),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_039_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_039[48] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBC),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBE),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_040_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_040[44] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBC),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBE),
    CMD(CM_PA_X, 0, 512, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_041_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_041[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBB),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBB),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBC),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBE),
    CMD(CM_PA_X, 0, -512, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_042_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_042[36] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEB7),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEB8),
    CMD(CM_NEX, 0, 0, 0),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_043_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_043[40] = {
    L2(6, 0, 0, 0, 1, 0, 0, 0xDEB9),
    CMD(CM_ROA, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3),
    L2(6, 0, 0, 0, 1, 0, 0, 0xDEB9),
    L2(6, 0, 0, 0, 1, 0, 0, 0xDEBA),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEB9),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEBA),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_044_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_044[72] = {
    CMD(CM_JSR, 0, 36, 3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEBB),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEBC),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEBB),
    CMD(CM_JSR, 0, 42, 3),
    L2(40, 0, 0, 0, 1, 0, 0, 0xDEB7),
    CMD(CM_JSR, 0, 42, 3),
    L2(8, 0, 0, 0, 1, 0, 0, 0xDEBB),
    CMD(CM_PA_Y, 0, 0, -256),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEBC),
    CMD(CM_PA_Y, 0, 0, 256),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(40, 255, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_045_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_045[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC1),
    CMD(CM_END, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_046_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_046[32] = {
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEB7),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBB),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDEC1),
    CMD(CM_END, 0, 0, 4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_047_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_047[28] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECC),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDECC),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_048_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_048[56] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDECF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDED8),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDED8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_049_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_049[164] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9D),
    CMD(CM_PAXY, 0, 4352, 1792),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9E),
    CMD(CM_PAXY, 0, 4352, 2816),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9F),
    CMD(CM_PAXY, 0, 4096, 2560),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA0),
    CMD(CM_PAXY, 0, 2816, 768),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA1),
    CMD(CM_PAXY, 0, 5376, -7680),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA3),
    CMD(CM_PAXY, 0, 5120, -8192),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA3),
    CMD(CM_PAXY, 0, 2048, -9216),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA3),
    CMD(CM_PAXY, 0, -2048, -10752),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA2),
    CMD(CM_PAXY, 0, 1536, -5632),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDEA0),
    CMD(CM_PAXY, 0, -768, 1024),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDE9F),
    CMD(CM_PAXY, 0, 2304, -2560),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA0),
    CMD(CM_PA_Y, 0, 0, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA2),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_Y, 0, 0, -2816),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA1),
    CMD(CM_PA_Y, 0, 0, 2304),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA0),
    CMD(CM_PA_Y, 0, 0, -3328),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA1),
    CMD(CM_PA_Y, 0, 0, 2816),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA2),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_PA_Y, 0, 0, -4352),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEA1),
    L2(250, 1, 0, 0, 0, 0, 0, 0xDEA1),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDEA1),
    CMD(CM_IXBW, 0, 0, 1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_050_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_050[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA6),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA8),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDEA9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_051_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_051[20] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEAA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEAB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEAC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEAD),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_052_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_052[24] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE5B),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE5C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE5D),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE5E),
    L2(3, 255, 0, 0, 0, 0, 0, 0xDE5E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_053_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_053[48] = {
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE67),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE68),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE69),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE6A),
    CMD(CM_PA_X, 0, -256, 0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDE6B),
    L2(3, 255, 0, 0, 0, 0, 0, 0xDE6B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_054_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_054[384] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBF),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBA),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB9),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBB),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB8),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBC),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBD),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC7),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC6),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC5),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC4),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC3),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEC0),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEBE),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB7),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 chn_char_table_055_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 chn_char_table_055[16] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB1),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDEB3),
    CMD(CM_ROA, 0, 0, 0),
};

/* fnl_char_table scripts: 8 entries */
const u16* const fnl_char_table[9] = {
    fnl_char_table_000, fnl_char_table_001, fnl_char_table_002, fnl_char_table_003, fnl_char_table_004, fnl_char_table_005,
    fnl_char_table_006, fnl_char_table_007,
    0
};

const u16 fnl_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDC40),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_001[44] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC41),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC42),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC43),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC44),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC45),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC46),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC45),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC44),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC43),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDC42),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_002[8] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDC47),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_003[12] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC48),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDC49),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_004[32] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4C),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC4F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC50),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_005[36] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC57),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC58),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC59),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC5A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC5B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC5C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC5D),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC5E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_006[184] = {
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC5F),
    CMD(CM_PA_X, 0, 768, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC60),
    CMD(CM_PA_X, 0, 512, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC61),
    CMD(CM_PA_X, 0, 1280, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC62),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC63),
    CMD(CM_PA_X, 0, 1024, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC64),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC65),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC66),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC67),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC68),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC69),
    CMD(CM_PA_X, 0, -1280, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6A),
    CMD(CM_PA_X, 0, -1280, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6B),
    CMD(CM_PA_X, 0, -1536, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6C),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6D),
    CMD(CM_PA_X, 0, -512, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6E),
    CMD(CM_PA_X, 0, -1792, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC6F),
    CMD(CM_PA_X, 0, -1280, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC70),
    CMD(CM_PA_X, 0, -1280, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC71),
    CMD(CM_PA_X, 0, -256, 0),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC72),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC73),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC74),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDC75),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC76),
    CMD(CM_PA_X, 0, 768, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC77),
    CMD(CM_PA_X, 0, 768, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC78),
    CMD(CM_PA_X, 0, 1792, 0),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDC79),
    CMD(CM_PA_X, 0, 2304, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 fnl_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 fnl_char_table_007[60] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC7A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC7B),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC7C),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC7D),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC7E),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC7F),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC80),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDC81),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC82),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC83),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC84),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC85),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC86),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDC87),
    CMD(CM_ROA, 0, 0, 0),
};

/* j11_char_table scripts: 7 entries */
const u16* const j11_char_table[8] = {
    j11_char_table_000, j11_char_table_001, j11_char_table_002, j11_char_table_003, j11_char_table_004, j11_char_table_005,
    j11_char_table_006,
    0
};

const u16 j11_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDCA0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDCA1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDCB1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_003[116] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xDCB1),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDCB6),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDCB7),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDCB8),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDCB9),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDCB2),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDCB3),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDCB4),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDCB5),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA8),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA9),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAA),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAB),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAC),
    CMD(CM_PA_X, 0, 2560, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAD),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAE),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCAF),
    CMD(CM_PA_X, 0, 1536, 0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCB0),
    CMD(CM_IXBW, 0, 0, 18),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_004[20] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_005[476] = {
    CMD(CM_FOR, 0, 0, 12),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    CMD(CM_PAXY, 0, 512, 512),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    CMD(CM_PAXY, 0, 512, 512),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 10),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 12),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 10),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA4),
    CMD(CM_PAXY, 0, 512, -256),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, 512, 0),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA5),
    CMD(CM_PAXY, 0, 512, -256),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 12),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 6),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    CMD(CM_PAXY, 0, -512, -512),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, -512, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    CMD(CM_PAXY, 0, -512, -512),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 8),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    CMD(CM_PAXY, 0, -1024, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    CMD(CM_PA_X, 0, -1024, 0),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    CMD(CM_PAXY, 0, -1024, 256),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j11_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j11_char_table_006[20] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA4),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA7),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA5),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDCA6),
    CMD(CM_ROA, 0, 0, 0),
};

/* frc_char_table scripts: 25 entries */
const u16* const frc_char_table[26] = {
    frc_char_table_000, frc_char_table_001, frc_char_table_002, frc_char_table_003, frc_char_table_004, frc_char_table_005,
    frc_char_table_006, frc_char_table_007, frc_char_table_008, frc_char_table_009, frc_char_table_010, frc_char_table_011,
    frc_char_table_012, frc_char_table_013, frc_char_table_014, frc_char_table_015, frc_char_table_016, frc_char_table_017,
    frc_char_table_018, frc_char_table_019, frc_char_table_020, frc_char_table_021, frc_char_table_022, frc_char_table_023,
    frc_char_table_024,
    0
};

const u16 frc_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDD60),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDD61),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_002[20] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDD62),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDDA6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDDA7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDDA6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDD63),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDD64),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_005[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDD65),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_006[100] = {
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD66),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD67),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD68),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD69),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6C),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6D),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6E),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD6F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD70),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD71),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD72),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD73),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD74),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD75),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD76),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD77),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD78),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD79),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD7A),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD7B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD7C),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDD7D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_007[84] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD7E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD7F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD80),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDD81),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD82),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD83),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD84),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD85),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD86),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD87),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD88),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD89),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD8F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDD90),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDD91),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_008[84] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD92),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD93),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD94),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDD95),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD96),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD97),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDD98),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD99),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9E),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDD9F),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDA0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDA1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDA2),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDA3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDDA4),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDDA5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_009[156] = {
    CMD(CM_FOR, 0, 0, 2),
    L2(180, 0, 0, 0, 0, 0, 0, 0xDDA8),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(50, 1, 0, 0, 0, 0, 0, 0xDDAC),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(60, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAC),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDDA8),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(70, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(80, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    CMD(CM_NEX, 0, 0, 0),
    L2(240, 0, 0, 0, 0, 0, 0, 0xDDA8),
    CMD(CM_FOR, 0, 0, 3),
    L2(180, 0, 0, 0, 0, 0, 0, 0xDDA8),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(50, 1, 0, 0, 0, 0, 0, 0xDDAC),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(60, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDAC),
    L2(10, 0, 0, 0, 0, 0, 0, 0xDDA8),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    L2(70, 1, 0, 0, 0, 0, 0, 0xDDAA),
    L2(80, 1, 0, 0, 0, 0, 0, 0xDDAB),
    L2(10, 1, 0, 0, 0, 0, 0, 0xDDA9),
    CMD(CM_NEX, 0, 0, 0),
    L2(120, 0, 0, 0, 0, 0, 0, 0xDDA8),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_010[84] = {
    L2(60, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_JSR, 0, 17, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_JSR, 0, 15, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(120, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_JSR, 0, 16, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_JSR, 0, 16, 3),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_JSR, 0, 17, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(180, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_JSR, 0, 15, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(100, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_JSR, 0, 16, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_011[88] = {
    CMD(CM_FOR, 0, 0, 10),
    CMD(CM_JSR, 0, 18, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_JSR, 0, 19, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_JSR, 0, 20, 3),
    L2(120, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_FOR, 0, 0, 8),
    CMD(CM_JSR, 0, 18, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_JSR, 0, 20, 3),
    L2(120, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_FOR, 0, 0, 5),
    CMD(CM_JSR, 0, 18, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_JSR, 0, 19, 3),
    CMD(CM_FOR, 0, 0, 5),
    CMD(CM_JSR, 0, 18, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_012[52] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_JSR, 0, 21, 3),
    L2(120, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_FOR, 0, 0, 3),
    CMD(CM_JSR, 0, 22, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(180, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_FOR, 0, 0, 4),
    CMD(CM_JSR, 0, 22, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_JSR, 0, 21, 3),
    L2(140, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_013[40] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDC8),
    CMD(CM_FOR, 0, 0, 4),
    CMD(CM_JSR, 0, 23, 3),
    CMD(CM_NEX, 0, 0, 0),
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDC8),
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDC8),
    CMD(CM_FOR, 0, 0, 2),
    CMD(CM_JSR, 0, 23, 3),
    CMD(CM_NEX, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_014[28] = {
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDD0),
    CMD(CM_JSR, 0, 24, 3),
    L2(250, 0, 0, 0, 0, 0, 0, 0xDDD0),
    CMD(CM_JSR, 0, 24, 3),
    L2(60, 0, 0, 0, 0, 0, 0, 0xDDD0),
    CMD(CM_JSR, 0, 24, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_015[192] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_ROA, 0, 0, 0),
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_016[36] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_ROA, 0, 0, 0),
    L2(14, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDAF),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(14, 1, 0, 0, 0, 0, 0, 0xDDB1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_017[80] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDAD),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDB2),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDB3),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDB2),
    L2(12, 1, 0, 0, 0, 0, 0, 0xDDB3),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDDAD),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDAE),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB0),
    L2(2, 1, 0, 0, 0, 0, 0, 0xDDB1),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_018[28] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_ROA, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDB4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB6),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_019[100] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_ROA, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDB4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDB4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB6),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDB4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB8),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB9),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDBA),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB8),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDB9),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDBA),
    L2(12, 1, 0, 0, 0, 0, 0, 0xDDBB),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDBC),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_020[32] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDB4),
    CMD(CM_ROA, 0, 0, 0),
    L2(128, 1, 0, 0, 0, 0, 0, 0xDDBD),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDBE),
    L2(128, 1, 0, 0, 0, 0, 0, 0xDDBF),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDBE),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_021[36] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_ROA, 0, 0, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDDC0),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(12, 1, 0, 0, 0, 0, 0, 0xDDC2),
    L2(4, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(68, 1, 0, 0, 0, 0, 0, 0xDDC2),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_022[136] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDC0),
    CMD(CM_ROA, 0, 0, 0),
    L2(144, 0, 0, 0, 0, 0, 0, 0xDDC0),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC3),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC6),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC7),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC5),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC4),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC3),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDC0),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(16, 1, 0, 0, 0, 0, 0, 0xDDC2),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(40, 1, 0, 0, 0, 0, 0, 0xDDC2),
    L2(8, 0, 0, 0, 0, 0, 0, 0xDDC0),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(24, 1, 0, 0, 0, 0, 0, 0xDDC2),
    L2(8, 1, 0, 0, 0, 0, 0, 0xDDC1),
    L2(32, 1, 0, 0, 0, 0, 0, 0xDDC2),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_023[120] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDC8),
    CMD(CM_ROA, 0, 0, 0),
    L2(105, 0, 0, 0, 0, 0, 0, 0xDDC8),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDC9),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDC9),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCA),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCB),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCC),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCD),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCC),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCD),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCC),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCD),
    L2(7, 1, 0, 0, 0, 0, 0, 0xDDCC),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 frc_char_table_024_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 frc_char_table_024[48] = {
    L2(168, 0, 0, 0, 0, 0, 0, 0xDDD0),
    CMD(CM_ROA, 0, 0, 0),
    L2(126, 1, 0, 0, 0, 0, 0, 0xDDCE),
    L2(12, 1, 0, 0, 0, 0, 0, 0xDDCF),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDDD0),
    L2(18, 1, 0, 0, 0, 0, 0, 0xDDD1),
    L2(42, 1, 0, 0, 0, 0, 0, 0xDDD2),
    L2(18, 1, 0, 0, 0, 0, 0, 0xDDD1),
    L2(12, 0, 0, 0, 0, 0, 0, 0xDDD0),
    L2(6, 1, 0, 0, 0, 0, 0, 0xDDCF),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

/* bns_char_table scripts: 13 entries */
const u16* const bns_char_table[14] = {
    bns_char_table_000, bns_char_table_001, bns_char_table_002, bns_char_table_003, bns_char_table_004, bns_char_table_005,
    bns_char_table_006, bns_char_table_007, bns_char_table_008, bns_char_table_009, bns_char_table_010, bns_char_table_011,
    bns_char_table_012,
    0
};

const u16 bns_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDCE0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_001[20] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA0),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA6),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA4),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA5),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA1),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_004[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDFA2),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_005[184] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFAF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFB9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFBF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFC9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFCF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFD6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_006[8] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFDF),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_007[44] = {
    L2(4, 9, 0, 0, 0, 0, 0, 0xDFE0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE2),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFE7),
    L2(4, 9, 0, 0, 0, 0, 0, 0xDFE8),
    L2(4, 9, 0, 0, 0, 0, 0, 0xDFE9),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_008[152] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xDFE0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFEA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFEB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFEC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFED),
    CMD(CM_EXEC, 3, 1, 0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFEE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFEF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF0),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF1),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF2),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDFF3),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDFF3),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF4),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF5),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF6),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF7),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF8),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFF9),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFA),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFB),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFC),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFD),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFE),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDFFF),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE000),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE001),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE002),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE003),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE004),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE005),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE006),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE007),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE008),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE009),
    L2(5, 0, 0, 0, 0, 0, 0, 0xE00A),
    CMD(CM_IXBW, 0, 0, 6),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_009[92] = {
    CMD(CM_FOR, 0, 0, 3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE015),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE016),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE018),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE016),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE015),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE016),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE018),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE016),
    CMD(CM_NEX, 0, 0, 0),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE015),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(12, 0, 0, 0, 0, 0, 0, 0xE018),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE017),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE016),
    L2(4, 0, 0, 0, 0, 0, 0, 0xE015),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE013),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE014),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_010[164] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xE020),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE022),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE023),
    CMD(CM_FOR, 0, 0, 3),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE020),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE022),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE020),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE022),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE023),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE024),
    CMD(CM_NEX, 0, 0, 0),
    L2(22, 0, 0, 0, 0, 0, 0, 0xE024),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE025),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE026),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE027),
    L2(28, 0, 0, 0, 0, 0, 0, 0xE028),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE027),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE026),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE025),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE024),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE020),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE022),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE020),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE021),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE022),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE023),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE024),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE025),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE026),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE027),
    L2(22, 0, 0, 0, 0, 0, 0, 0xE028),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE029),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE02A),
    L2(8, 0, 0, 0, 0, 0, 0, 0xE02B),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_011[8] = {
    L2(8, 0, 0, 0, 0, 0, 0, 0xE02C),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 bns_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 bns_char_table_012[32] = {
    L2(255, 0, 0, 0, 0, 0, 0, 0xB30B),
    L2(255, 0, 0, 0, 0, 0, 0, 0xB30C),
    L2(255, 0, 0, 0, 0, 0, 0, 0xB338),
    L2(255, 0, 0, 0, 0, 0, 0, 0xB339),
    L2(255, 0, 0, 0, 0, 0, 0, 0xB30D),
    L2(255, 0, 159, 0, 0, 0, 0, 0xB309),
    L2(255, 0, 156, 0, 0, 0, 0, 0xB30A),
    CMD(CM_ROA, 0, 0, 0),
};

/* j10_char_table scripts: 24 entries */
const u16* const j10_char_table[25] = {
    j10_char_table_000, j10_char_table_001, j10_char_table_002, j10_char_table_003, j10_char_table_004, j10_char_table_005,
    j10_char_table_006, j10_char_table_007, j10_char_table_008, j10_char_table_009, j10_char_table_010, j10_char_table_011,
    j10_char_table_012, j10_char_table_013, j10_char_table_014, j10_char_table_015, j10_char_table_016, j10_char_table_017,
    j10_char_table_018, j10_char_table_019, j10_char_table_020, j10_char_table_021, j10_char_table_022, j10_char_table_023,
    0
};

const u16 j10_char_table_000_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_000[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF20),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_001_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_001[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF21),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_002_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_002[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF22),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_003_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_003[8] = {
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF23),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_004_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_004[28] = {
    CMD(CM_JSR, 0, 5, 3),
    CMD(CM_JSR, 0, 6, 3),
    CMD(CM_PA_X, 0, -512, 0),
    CMD(CM_JSR, 0, 5, 3),
    CMD(CM_PA_X, 0, 512, 0),
    CMD(CM_JSR, 0, 7, 3),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_005_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_005[168] = {
    L2(28, 0, 0, 0, 0, 0, 0, 0xDF24),
    CMD(CM_ROA, 0, 0, 0),
    L2(28, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF25),
    L2(43, 0, 0, 0, 0, 0, 0, 0xDF26),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF27),
    L2(42, 0, 0, 0, 0, 0, 0, 0xDF28),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF27),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDF26),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF29),
    L2(21, 0, 0, 0, 0, 0, 0, 0xDF2A),
    L2(31, 0, 0, 0, 0, 0, 0, 0xDF2B),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF2A),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2C),
    L2(39, 0, 0, 0, 0, 0, 0, 0xDF2D),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2C),
    L2(19, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF2C),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDF2D),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2C),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2E),
    L2(39, 0, 0, 0, 0, 0, 0, 0xDF2F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2E),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2E),
    L2(20, 0, 0, 0, 0, 0, 0, 0xDF2F),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF2E),
    L2(18, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF30),
    L2(28, 0, 0, 0, 0, 0, 0, 0xDF32),
    L2(9, 0, 0, 0, 0, 0, 0, 0xDF34),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF34),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF35),
    L2(42, 0, 0, 0, 0, 0, 0, 0xDF36),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF35),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF34),
    L2(16, 0, 0, 0, 0, 0, 0, 0xDF24),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_006_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_006[56] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF37),
    CMD(CM_ROA, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF37),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF38),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF39),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3A),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3B),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3C),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3D),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3F),
    L2(5, 255, 0, 0, 0, 0, 0, 0xDF3F),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_007_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_007[56] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3F),
    CMD(CM_ROA, 0, 0, 0),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF40),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF41),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF42),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF43),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF44),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF45),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF46),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF47),
    L2(5, 255, 0, 0, 0, 0, 0, 0xDF47),
    CMD(CM_RET, 0, 0, 0),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_008_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_008[32] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF48),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF49),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF4A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF4B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF4C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF4D),
    L2(2, 255, 0, 0, 0, 0, 0, 0xDF4D),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_009_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_009[44] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF4E),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF4F),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF50),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF51),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF52),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF53),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF54),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF55),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF56),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF57),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_010_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_010[48] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF4E),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDF4F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF50),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF51),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF52),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF53),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF54),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF55),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF56),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF57),
    L2(1, 255, 0, 0, 0, 0, 0, 0xDF57),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_011_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_011[44] = {
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF4F),
    L2(5, 2, 0, 0, 0, 0, 0, 0xDF4F),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF51),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF52),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF53),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF54),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF55),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF56),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF57),
    L2(1, 255, 0, 0, 0, 0, 0, 0xDF57),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_012_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_012[36] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF5A),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF5B),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF5C),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF5D),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF5E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF5F),
    L2(25, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(2, 255, 0, 0, 0, 0, 0, 0xDF24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_013_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_013[28] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF60),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF61),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF62),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF63),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF64),
    L2(2, 255, 0, 0, 0, 0, 0, 0xDF64),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_014_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_014[44] = {
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF65),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF66),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF67),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF68),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF69),
    L2(1, 0, 0, 0, 0, 0, 0, 0xDF6A),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF6B),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF6C),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF6D),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_015_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_015[64] = {
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF65),
    L2(3, 2, 0, 0, 0, 0, 0, 0xDF66),
    CMD(CM_PA_Y, 0, 0, 512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF67),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF68),
    CMD(CM_PA_Y, 0, 0, 512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF69),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF6A),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF6B),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF6C),
    CMD(CM_PA_Y, 0, 0, -512),
    L2(4, 0, 0, 0, 0, 0, 0, 0xDF6D),
    CMD(CM_PA_Y, 0, 0, -512),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF6E),
    L2(1, 255, 0, 0, 0, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_016_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_016[32] = {
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF66),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF67),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF68),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF6B),
    L2(6, 0, 0, 0, 0, 0, 0, 0xDF6D),
    L2(5, 2, 0, 0, 0, 0, 0, 0xDF6E),
    L2(250, 255, 0, 0, 0, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_017_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_017[44] = {
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF70),
    L2(2, 0, 0, 0, 0, 0, 0, 0xDF71),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF72),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF73),
    L2(3, 0, 0, 0, 0, 0, 0, 0xDF74),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF75),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF76),
    L2(25, 0, 0, 0, 0, 0, 0, 0xDF25),
    L2(25, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(2, 255, 0, 0, 0, 0, 0, 0xDF24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_018_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_018[28] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF60),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF61),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF62),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF63),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF64),
    L2(2, 255, 0, 0, 1, 0, 0, 0xDF64),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_019_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_019[44] = {
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF65),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF66),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF67),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF68),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF69),
    L2(1, 0, 0, 0, 1, 0, 0, 0xDF6A),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF6B),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF6C),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF6D),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_020_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_020[64] = {
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF65),
    L2(3, 2, 0, 0, 1, 0, 0, 0xDF66),
    CMD(CM_PA_Y, 0, 0, 512),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF67),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF68),
    CMD(CM_PA_Y, 0, 0, 512),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF69),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF6A),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDF6B),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDF6C),
    CMD(CM_PA_Y, 0, 0, -512),
    L2(4, 0, 0, 0, 1, 0, 0, 0xDF6D),
    CMD(CM_PA_Y, 0, 0, -512),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF6E),
    L2(1, 255, 0, 0, 1, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_021_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_021[32] = {
    L2(6, 0, 0, 0, 1, 0, 0, 0xDF66),
    L2(6, 0, 0, 0, 1, 0, 0, 0xDF67),
    L2(5, 0, 0, 0, 1, 0, 0, 0xDF68),
    L2(6, 0, 0, 0, 1, 0, 0, 0xDF6B),
    L2(6, 0, 0, 0, 1, 0, 0, 0xDF6D),
    L2(5, 2, 0, 0, 1, 0, 0, 0xDF6E),
    L2(250, 255, 0, 0, 1, 0, 0, 0xDF6E),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_022_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_022[44] = {
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF70),
    L2(2, 0, 0, 0, 1, 0, 0, 0xDF71),
    L2(7, 0, 0, 0, 1, 0, 0, 0xDF72),
    L2(7, 0, 0, 0, 1, 0, 0, 0xDF73),
    L2(3, 0, 0, 0, 1, 0, 0, 0xDF74),
    L2(5, 0, 0, 0, 1, 0, 0, 0xDF75),
    L2(5, 0, 0, 0, 1, 0, 0, 0xDF76),
    L2(25, 0, 0, 0, 1, 0, 0, 0xDF25),
    L2(25, 0, 0, 0, 1, 0, 0, 0xDF24),
    L2(2, 255, 0, 0, 1, 0, 0, 0xDF24),
    CMD(CM_ROA, 0, 0, 0),
};

const u16 j10_char_table_023_head[4] = { HEAD(2, 0, 0, 0, 0, 0, 0) };
const u16 j10_char_table_023[88] = {
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF37),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF38),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF39),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3A),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3B),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3C),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3D),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3E),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF24),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF3F),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF40),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF41),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF42),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF43),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF44),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF45),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF46),
    L2(5, 0, 0, 0, 0, 0, 0, 0xDF47),
    L2(7, 0, 0, 0, 0, 0, 0, 0xDF24),
    CMD(CM_ROA, 0, 0, 0),
};

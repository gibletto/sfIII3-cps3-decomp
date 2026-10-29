/*
 * PLPAT_TBL.C  player attack dispatch tables
 *
 * plpat_lv_00 is the common attack routines Attack_00000 - Attack_15000, indexed by attack
 * routine number. plxx_extra_attack_table starts with each character's extra attack dispatcher
 * (pl00_extra_attack - pl20_extra_attack, by player number). cjdr_frame_tbl holds rows of
 * jump-attack recovery frame counts, one per kind of jump attack, reached through
 * cjdr_karaburi_table and its companions for get_cjdR. Read by PLPAT.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Attack_00000();
extern void Attack_01000();
extern void Attack_02000();
extern void Attack_03000();
extern void Attack_04000();
extern void Attack_05000();
extern void Attack_06000();
extern void Attack_07000();
extern void Attack_08000();
extern void Attack_09000();
extern void Attack_10000();
extern void Attack_14000();
extern void Attack_15000();
extern void pl00_extra_attack();
extern void pl01_extra_attack();
extern void pl02_extra_attack();
extern void pl03_extra_attack();
extern void pl04_extra_attack();
extern void pl05_extra_attack();
extern void pl06_extra_attack();
extern void pl07_extra_attack();
extern void pl08_extra_attack();
extern void pl09_extra_attack();
extern void pl10_extra_attack();
extern void pl11_extra_attack();
extern void pl12_extra_attack();
extern void pl13_extra_attack();
extern void pl14_extra_attack();
extern void pl16_extra_attack();
extern void pl17_extra_attack();
extern void pl18_extra_attack();
extern void pl19_extra_attack();
extern void pl20_extra_attack();

void (*const plpat_lv_00[16])() = {
    Attack_00000,  Attack_01000,  Attack_02000,  Attack_03000,  /* 0 */
    Attack_04000,  Attack_05000,  Attack_06000,  Attack_07000,  /* 4 */
    Attack_08000,  Attack_09000,  Attack_10000,  Attack_00000,  /* 8 */
    Attack_00000,  Attack_00000,  Attack_14000,  Attack_15000,  /* 12 */
};

void (*const plxx_extra_attack_table[24])() = {
    pl00_extra_attack,
    pl01_extra_attack,
    pl02_extra_attack,
    pl03_extra_attack,
    pl04_extra_attack,
    pl05_extra_attack,
    pl06_extra_attack,
    pl07_extra_attack,
    pl08_extra_attack,
    pl09_extra_attack,
    pl10_extra_attack,
    pl11_extra_attack,
    pl12_extra_attack,
    pl13_extra_attack,
    pl14_extra_attack,
    pl14_extra_attack,
    pl16_extra_attack,
    pl17_extra_attack,
    pl18_extra_attack,
    pl19_extra_attack,
    pl20_extra_attack,
    0,
    0,
    0,
};

/* provisional name */
const u8 cjdr_frame_tbl[15][8] = {
    { 10, 10, 14, 14, 18, 18, 18, 18 },  /* [0] */
    { 11, 11, 16, 16, 21, 21, 21, 21 },  /* [1] */
    { 14, 14, 18, 18, 22, 22, 22, 22 },  /* [2] */
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  /* [3] */
    { 22, 10, 23, 11, 24, 12, 24, 12 },  /* [4] */
    { 24, 12, 25, 13, 26, 14, 26, 14 },  /* [5] */
    { 26, 14, 27, 15, 28, 16, 28, 16 },  /* [6] */
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  /* [7] */
    { 16, 7, 18, 9, 20, 11, 20, 11 },  /* [8] */
    { 17, 8, 19, 10, 21, 12, 21, 12 },  /* [9] */
    { 18, 9, 20, 11, 22, 13, 22, 13 },  /* [10] */
    { 20, 20, 23, 23, 26, 26, 26, 26 },  /* [11] */
    { 22, 22, 24, 24, 26, 26, 26, 26 },  /* [12] */
    { 23, 23, 25, 25, 26, 26, 26, 26 },  /* [13] */
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  /* [14] */
};

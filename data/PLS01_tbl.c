/*
 * PLS01_TBL.C  player guard and state check tables
 *
 * sel_hd_fg_hos is each character's offset of the point from which the direction to the
 * opponent's attack is measured; dir32_rl_conv mirrors that 32-way direction and dir32_sel_tbl
 * turns it into high or low. chcgp_hos marks, per character, whether guarding makes that
 * check. about_rno is a class code per routine class. Read by PLS01.C (check_attbox_dir,
 * check_defense_kind).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u8 about_rno[6] = {
    0, 1, 2, 1, 2, 0,
};

const s16 sel_hd_fg_hos[24][2] = {
    { 0, 92 },  /* Gill */
    { 24, 76 },  /* Alex */
    { 8, 76 },  /* Ryu */
    { 20, 64 },  /* Yun */
    { 0, 84 },  /* Dudley */
    { 4, 80 },  /* Necro */
    { 8, 88 },  /* Hugo */
    { 4, 68 },  /* Ibuki */
    { 0, 72 },  /* Elena */
    { -16, 64 },  /* Oro */
    { 20, 64 },  /* Yang */
    { 8, 76 },  /* Ken */
    { 8, 76 },  /* Sean */
    { 0, 92 },  /* Urien */
    { 8, 76 },  /* Gouki */
    { 8, 76 },  /* Shin Gouki */
    { 0, 76 },  /* Chun-Li */
    { 14, 58 },  /* Makoto */
    { 0, 104 },  /* Q */
    { 4, 80 },  /* Twelve */
    { 4, 87 },  /* Remy */
    { 0, 0 },  /* 21 */
    { 0, 0 },  /* 22 */
    { 0, 0 },  /* 23 */
};

const s16 dir32_rl_conv[32] = {
    0, 31, 30, 29, 28, 27, 26, 25,
    24, 23, 22, 21, 20, 19, 18, 17,
    16, 15, 14, 13, 12, 11, 10, 9,
    8, 7, 6, 5, 4, 3, 2, 1,
};

const s16 dir32_sel_tbl[2][32] = {
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
};

const s16 chcgp_hos[25] = {
    0, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1,
    1, 0, 0, 0, 0,
};


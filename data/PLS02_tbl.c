/*
 * PLS02_TBL.C  player movement, gauge and CPU random tables
 *
 * random_tbl_32_com, random_tbl_16_com and their _ex companions are the CPU random number
 * tables; satse is each character's body half-width for the screen-edge checks (also read by
 * BG_SUB_2.C for the scroll limits), sel_hosei_tbl_ix each character's correction box index
 * for the car bonus stage, and dir16_rl_conv mirrors a 16-way direction; these are read by
 * PLS02.C. The super art gauge rates by game level (asagh_zuru, asagh_zuru2) and by character
 * (apagt_table, ukemi_apagt_table, nagenuke_apagt_table), konjyou_tbl (per-character damage
 * scaling), the hit routine choice by direction (dir16_hddm, dir16_trdm, dir32_skydm,
 * dir32_grddm), dead_voice_table (KO voices per character) and gauge_rank_table are read by
 * PLSGAUGE.C; jump_pat_status_data, the jump posture by lever direction, by PLS03ATT.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 asagh_zuru[8] = {
    -2, -1, 0, 0, 1, 2, 3, 4,
};

const s16 asagh_zuru2[8] = {
    1, 2, 3, 4, 5, 6, 7, 8,
};

const s16 sel_hosei_tbl_ix[24] = {
    29, 45, 1, 5, 49, 13, 9, 21,
    17, 25, 5, 1, 1, 29, 1, 1,
    33, 37, 41, 57,
    53, 0, 0, 0,
};

const s16 satse[24] = {
    32, 32, 28, 24, 32, 36, 40, 24,
    28, 28, 24, 28, 28, 32, 30, 30,
    28, 28, 24, 36,
    24, 32, 32, 32,
};

const s16 random_tbl_32_com[128] = {
    27, 4, 17, 6, 31, 10, 29, 2,
    25, 19, 11, 22, 5, 15, 6, 20,
    24, 18, 4, 26, 19, 11, 30, 0,
    21, 7, 10, 27, 1, 24, 16, 6,
    15, 5, 29, 17, 1, 23, 18, 2,
    13, 22, 31, 16, 13, 3, 21, 30,
    17, 22, 0, 26, 3, 19, 10, 23,
    14, 30, 19, 29, 13, 8, 2, 9,
    9, 25, 4, 12, 28, 20, 2, 14,
    27, 9, 7, 18, 27, 1, 31, 14,
    4, 8, 29, 8, 24, 28, 7, 16,
    3, 11, 15, 6, 20, 28, 25, 12,
    13, 23, 25, 10, 22, 8, 18, 21,
    12, 1, 24, 31, 0, 3, 26, 7,
    20, 5, 5, 15, 14, 0, 11, 28,
    16, 26, 9, 17, 21, 30, 12, 23,
};

const s16 random_tbl_16_com[64] = {
    3, 8, 6, 9, 14, 13, 9, 5,
    10, 14, 1, 7, 4, 15, 2, 0,
    12, 15, 5, 13, 6, 3, 11, 8,
    0, 3, 11, 10, 1, 7, 11, 4,
    5, 4, 13, 2, 11, 9, 7, 10,
    1, 6, 12, 9, 14, 0, 15, 2,
    13, 1, 15, 8, 0, 6, 14, 3,
    12, 8, 4, 5, 10, 2, 7, 12,
};

const s16 random_tbl_32_ex[32] = {
    16, 24, 5, 22, 10, 27, 14, 1,
    20, 8, 29, 3, 26, 11, 18, 0,
    31, 15, 28, 7, 12, 23, 4, 30,
    9, 19, 2, 25, 13, 17, 21, 6,
};

const s16 random_tbl_16_ex_com[16] = {
    9, 0, 5, 12, 3, 14, 7, 10,
    1, 15, 6, 11, 2, 8, 13, 4,
};

const s16 dir16_rl_conv[16] = {
    0, 15, 14, 13, 12, 11, 10, 9,
    8, 7, 6, 5, 4, 3, 2, 1,
};

const s16 dir16_hddm[16] = {
    35, 35, 35, 32, 32, 32, 36, 36,
    36, 36, 36, 32, 32, 32, 35, 35,
};

const s16 dir16_trdm[16] = {
    38, 38, 38, 37, 37, 37, 36, 36,
    36, 36, 36, 37, 37, 37, 38, 38,
};

const s16 konjyou_tbl[24][6] = {
    { 26, 28, 30, 32, 32, 32 },  /* Gill */
    { 26, 28, 30, 32, 32, 32 },  /* Alex */
    { 26, 28, 30, 32, 32, 32 },  /* Ryu */
    { 26, 28, 30, 32, 32, 32 },  /* Yun */
    { 26, 28, 30, 32, 32, 32 },  /* Dudley */
    { 26, 28, 30, 32, 32, 32 },  /* Necro */
    { 26, 28, 30, 32, 32, 32 },  /* Hugo */
    { 26, 28, 30, 32, 32, 32 },  /* Ibuki */
    { 26, 28, 30, 32, 32, 32 },  /* Elena */
    { 26, 28, 30, 32, 32, 32 },  /* Oro */
    { 26, 28, 30, 32, 32, 32 },  /* Yang */
    { 26, 28, 30, 32, 32, 32 },  /* Ken */
    { 26, 28, 30, 32, 32, 32 },  /* Sean */
    { 26, 28, 30, 32, 32, 32 },  /* Urien */
    { 26, 28, 30, 32, 32, 32 },  /* Gouki */
    { 26, 28, 30, 32, 32, 32 },  /* Shin Gouki */
    { 26, 28, 30, 32, 32, 32 },  /* Chun-Li */
    { 26, 28, 30, 32, 32, 32 },  /* Makoto */
    { 26, 28, 30, 32, 32, 32 },  /* Q */
    { 26, 28, 30, 32, 32, 32 },  /* Twelve */
    { 26, 28, 30, 32, 32, 32 },  /* Remy */
    { 26, 28, 30, 32, 32, 32 },  /* 21 */
    { 26, 28, 30, 32, 32, 32 },  /* 22 */
    { 26, 28, 30, 32, 32, 32 },  /* 23 */
};

const s16 apagt_table[24] = {
    5, 4, 4, 4, 4, 4, 5, 4,
    5, 3, 4, 4, 4, 4, 4, 5,
    4, 5, 3, 2, 4, 0, 0, 0,
};

const s16 ukemi_apagt_table[24] = {
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3,
};

const s16 nagenuke_apagt_table[24] = {
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
};

const s16 dir32_skydm[32] = {
    88, 88, 88, 88, 88, 88, 88, 88,
    88, 88, 88, 97, 97, 97, 97, 98,
    98, 98, 97, 97, 97, 97, 88, 88,
    88, 88, 88, 88, 88, 88, 88, 88,
};

const s16 dir32_grddm[32] = {
    91, 91, 91, 91, 91, 91, 91, 91,
    91, 91, 91, 39, 39, 39, 39, 40,
    40, 40, 39, 39, 39, 39, 91, 91,
    91, 91, 91, 91, 91, 91, 91, 91,
};

const u8 convert_saishin_lvdir[2][16] = {
    { 0, 0, 0, 0, 1, 1, 1, 0, 2, 2, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 2, 2, 2, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
};

const s16 dead_voice_table[24][2] = {
    { 864, 865 },  /* Gill */
    { 928, 929 },  /* Alex */
    { 512, 513 },  /* Ryu */
    { 608, 609 },  /* Yun */
    { 896, 897 },  /* Dudley */
    { 800, 801 },  /* Necro */
    { 832, 833 },  /* Hugo */
    { 352, 353 },  /* Ibuki */
    { 672, 673 },  /* Elena */
    { 576, 577 },  /* Oro */
    { 640, 641 },  /* Yang */
    { 384, 385 },  /* Ken */
    { 480, 481 },  /* Sean */
    { 736, 737 },  /* Urien */
    { 704, 705 },  /* Gouki */
    { 704, 705 },  /* Shin Gouki */
    { 416, 417 },  /* Chun-Li */
    { 448, 449 },  /* Makoto */
    { 768, 769 },  /* Q */
    { 960, 961 },  /* Twelve */
    { 544, 545 },  /* Remy */
    { 864, 865 },  /* 21 */
    { 864, 865 },  /* 22 */
    { 864, 865 },  /* 23 */
};

/* Limit, value: gauge_rank_value returns the value of the first row whose limit it reaches. */
const s16 gauge_rank_table[6][2] = {
    { 90, 1000 },
    { 80, 600 },
    { 60, 400 },
    { 40, 300 },
    { 20, 200 },
    { 0, 100 },
};

const u8 jump_pat_status_data[2][4] = {
    { 22, 20, 24, 0 },
    { 22, 24, 20, 0 },
};

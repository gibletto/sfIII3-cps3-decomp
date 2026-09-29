/*
 * SPGAUGE_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 fade_adrs_tbl_0[];
extern const u16 fade_adrs_tbl_1[];
extern const u16 fade_adrs_tbl_10[];
extern const u16 fade_adrs_tbl_11[];
extern const u16 fade_adrs_tbl_12[];
extern const u16 fade_adrs_tbl_13[];
extern const u16 fade_adrs_tbl_14[];
extern const u16 fade_adrs_tbl_15[];
extern const u16 fade_adrs_tbl_16[];
extern const u16 fade_adrs_tbl_17[];
extern const u16 fade_adrs_tbl_18[];
extern const u16 fade_adrs_tbl_19[];
extern const u16 fade_adrs_tbl_2[];
extern const u16 fade_adrs_tbl_20[];
extern const u16 fade_adrs_tbl_21[];
extern const u16 fade_adrs_tbl_22[];
extern const u16 fade_adrs_tbl_23[];
extern const u16 fade_adrs_tbl_25[];
extern const u16 fade_adrs_tbl_26[];
extern const u16 fade_adrs_tbl_27[];
extern const u16 fade_adrs_tbl_28[];
extern const u16 fade_adrs_tbl_29[];
extern const u16 fade_adrs_tbl_3[];
extern const u16 fade_adrs_tbl_30[];
extern const u16 fade_adrs_tbl_31[];
extern const u16 fade_adrs_tbl_32[];
extern const u16 fade_adrs_tbl_33[];
extern const u16 fade_adrs_tbl_34[];
extern const u16 fade_adrs_tbl_35[];
extern const u16 fade_adrs_tbl_4[];
extern const u16 fade_adrs_tbl_5[];
extern const u16 fade_adrs_tbl_6[];
extern const u16 fade_adrs_tbl_7[];
extern const u16 fade_adrs_tbl_8[];
extern const u16 fade_adrs_tbl_9[];


const u16 sa_time_data_tbl[6][2] = {
    { 0x800, 0x820 },
    { 0x808, 0x828 },
    { 0x810, 0x830 },
    { 0x818, 0x838 },
    { 0x810, 0x830 },
    { 0x808, 0x828 },
};

const u16 sa_color_data2_tbl[3][2] = {
    { 0x1A, 0x9A },
    { 0x18, 0x98 },
    { 0x1A, 0x9A },
};

const u16 sagauge_colchg_tbl[4][2] = {
    { 0x22, 0xA2 },
    { 0x24, 0xA4 },
    { 0x26, 0xA6 },
    { 0x24, 0xA4 },
};

const u16 fade_adrs_tbl_17[2] = {
    0, 5,
};

const u16 fade_adrs_tbl_18[4] = {
    0, 4, 0, 2,
};

const u16 fade_adrs_tbl_19[2] = {
    0, 4,
};

const u16 fade_adrs_tbl_20[2] = {
    0, 2,
};

const u16 fade_adrs_tbl_21[2] = {
    0, 0xA,
};

const u16 fade_adrs_tbl_13[2] = {
    0, 0x28,
};

const u16 fade_adrs_tbl_22[2] = {
    0, 0x82,
};

const u16 fade_adrs_tbl_25[2] = {
    0, 0x27,
};

const u16 fade_adrs_tbl_34[2] = {
    0, 0x30,
};

const u16 fade_adrs_tbl_14[2] = {
    0, 0x29,
};

const u16 fade_adrs_tbl_16[2] = {
    0, 0x2F,
};

const u16 fade_adrs_tbl_10[2] = {
    0, 0x22,
};

const u16 fade_adrs_tbl_26[2] = {
    0, 0x13,
};

const u16 fade_adrs_tbl_2[2] = {
    0, 0x18,
};

const u16 fade_adrs_tbl_9[2] = {
    0, 0x1F,
};

const u16 fade_adrs_tbl_6[2] = {
    0, 0x1C,
};

const u16 fade_adrs_tbl_1[2] = {
    0, 0x15,
};

const u16 fade_adrs_tbl_7[2] = {
    0, 0x1D,
};

const u16 fade_adrs_tbl_11[2] = {
    0, 0x23,
};

const u16 fade_adrs_tbl_4[2] = {
    0, 0x1A,
};

const u16 fade_adrs_tbl_3[2] = {
    0, 0x19,
};

const u16 fade_adrs_tbl_0[2] = {
    0, 0x14,
};

const u16 fade_adrs_tbl_8[2] = {
    0, 0x1E,
};

const u16 fade_adrs_tbl_28[2] = {
    0, 0x12,
};

const u16 fade_adrs_tbl_12[2] = {
    0, 0x24,
};

const u16 fade_adrs_tbl_15[2] = {
    0, 0x2B,
};

const u16 fade_adrs_tbl_5[2] = {
    0, 0x1B,
};

const u16 fade_adrs_tbl_29[2] = {
    0, 0x84,
};

const u16 fade_adrs_tbl_27[2] = {
    0, 0x91,
};

const u16 fade_adrs_tbl_23[2] = {
    0, 0x86,
};

const u16 fade_adrs_tbl_30[2] = {
    0, 0xB4,
};

const u16 fade_adrs_tbl_31[6] = {
    0, 5, 0, 0x59, 0, 0x86,
};

const u16 fade_adrs_tbl_32[4] = {
    0, 0x2A, 0, 0x81,
};

const u16 fade_adrs_tbl_33[4] = {
    0, 5, 0, 0x59,
};

const u16 fade_adrs_tbl_35[86] = {
    0, 0x93, 0, 0x7B, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
};

const s16 fade_param_tbl[42][6] = {
    { 2, 31, 15, 0, 2, -1 },
    { 3, 31, 15, 0, 2, -1 },
    { 1, 31, 0, 2, 1, -32 },
    { 2, 31, 0, 0, 2, -1 },
    { 2, 0, 31, 1, 2, 1 },
    { 1, 31, 15, 0, 2, -1 },
    { 1, 31, 0, 0, 2, -1 },
    { 1, 0, 31, 1, 2, 1 },
    { 1, 0, 31, 3, 1, 10 },
    { 1, 31, 0, 0, 1, -4 },
    { 1, 31, 0, 2, 3, -1 },
    { 1, 0, 31, 3, 1, 2 },
    { 1, 31, 0, 2, 1, -8 },
    { 1, 20, 31, 3, 1, 6 },
    { 1, 0, 31, 3, 1, 32 },
    { 1, 31, 0, 2, 1, -16 },
    { 1, 31, 0, 2, 1, -1 },
    { 1, 0, 31, 3, 1, 2 },
    { 1, 31, 0, 2, 1, -2 },
    { 1, 0, 31, 3, 2, 1 },
    { 1, 0, 31, 1, 1, 2 },
    { 1, 31, 0, 0, 1, -2 },
    { 1, 31, 0, 2, 1, -1 },
    { 1, 0, 31, 3, 1, 1 },
    { 1, 0, 31, 1, 2, 1 },
    { 1, 31, 0, 0, 1, -32 },
    { 1, 0, 31, 1, 4, 1 },
    { 1, 31, 0, 0, 1, -2 },
    { 1, 22, 31, 1, 4, 1 },
    { 1, 0, 31, 1, 1, 32 },
    { 1, 31, 0, 0, 1, -8 },
    { 1, 0, 31, 3, 2, 1 },
    { 1, 31, 0, 0, 1, -16 },
    { 1, 31, 0, 2, 2, -1 },
    { 2, 31, 19, 0, 2, -1 },
    { 3, 31, 19, 0, 2, -1 },
    { 3, 31, 17, 0, 2, -1 },
    { 3, 31, 0, 0, 1, -1 },
    { 3, 0, 31, 1, 1, 1 },
    { 2, 31, 0, 0, 1, -1 },
    { 2, 31, 0, 0, 1, -1 },
    { 2, 31, 0, 0, 1, -32 },
};

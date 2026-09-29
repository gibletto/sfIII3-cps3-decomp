/*
 * EFFD9_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 coltbl_000_1P[];
extern const s16 coltbl_000_2P[86];
extern const s16 coltbl_007_1P[];
extern const s16 coltbl_007_2P[];
extern const s16 coltbl_008_1P[];
extern const s16 coltbl_008_2P[];

const s16 coltbl_000_1P[10] = {
    1, 8192, 2, 8193, 1, 8195, 2, 8193,
    0, 0,
};

const s16 coltbl_000_2P[86] = {
    1, 8208, 2, 8209, 1, 8211, 2, 8209,
    0, 0, 2, 8192, 2, 8194, 0, 0,
    2, 8208, 2, 8210, 0, 0, 999, 8195,
    0, 0, 999, 8211, 0, 0, 2, 8192,
    2, 8193, 0, 0, 2, 8208, 2, 8209,
    0, 0, 2, 8192, 2, 8196, 0, 0,
    2, 8208, 2, 8212, 0, 0, 1, 8280,
    2, 8192, 0, 0, 1, 8281, 2, 8208,
    0, 0, 2, 8192, 2, 8259, 2, 8192,
    2, 8262, 0, 0, 2, 8208, 2, 8267,
    2, 8208, 2, 8270, 0, 0,
};

const s16 coltbl_007_1P[10] = {
    1, 8195, 2, 8192, 1, 8195, 2, 8192,
    0, 0,
};

const s16 coltbl_007_2P[10] = {
    1, 8211, 2, 8208, 1, 8211, 2, 8208,
    0, 0,
};

const s16 coltbl_008_1P[8] = {
    2, 8192, 2, 8193, 2, 8193, 0, 0,
};

const s16 coltbl_008_2P[8] = {
    2, 8208, 2, 8209, 2, 8209, 0, 0,
};

const ColorTableIndex color_table_index[9] = {
    { 8, 0, (void*)coltbl_000_1P, (void*)coltbl_000_2P },
    { 7, 24, (void*)&coltbl_000_2P[30], (void*)&coltbl_000_2P[36] },
    { 7, 30, (void*)&coltbl_000_2P[10], (void*)&coltbl_000_2P[16] },
    { 5, 0, (void*)&coltbl_000_2P[22], (void*)&coltbl_000_2P[26] },
    { 7, 18, (void*)&coltbl_000_2P[42], (void*)&coltbl_000_2P[48] },
    { 18, 24, (void*)&coltbl_000_2P[54], (void*)&coltbl_000_2P[60] },
    { 17, 24, (void*)&coltbl_000_2P[66], (void*)&coltbl_000_2P[76] },
    { 2, 10, (void*)coltbl_007_1P, (void*)coltbl_007_2P },
    { 8, 0, (void*)coltbl_008_1P, (void*)coltbl_008_2P },
};

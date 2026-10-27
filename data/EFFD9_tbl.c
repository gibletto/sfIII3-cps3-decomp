/*
 * EFFD9_TBL.C  palette change tables for effect D9
 *
 * color_table_index has nine entries { end-condition flags, timer, 1P table, 2P table }; the
 * entry number is given when effect D9 is started. The coltbl_* tables (and slices of
 * coltbl_000_2P) are the colour steps, { frames, colour } pairs ending with 0, that the effect
 * cycles through the player's extra colour. Read by EFFD9.C, the palette change controller.
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
    { 8, 0, coltbl_000_1P, coltbl_000_2P },
    { 7, 24, &coltbl_000_2P[30], &coltbl_000_2P[36] },
    { 7, 30, &coltbl_000_2P[10], &coltbl_000_2P[16] },
    { 5, 0, &coltbl_000_2P[22], &coltbl_000_2P[26] },
    { 7, 18, &coltbl_000_2P[42], &coltbl_000_2P[48] },
    { 18, 24, &coltbl_000_2P[54], &coltbl_000_2P[60] },
    { 17, 24, &coltbl_000_2P[66], &coltbl_000_2P[76] },
    { 2, 10, coltbl_007_1P, coltbl_007_2P },
    { 8, 0, coltbl_008_1P, coltbl_008_2P },
};

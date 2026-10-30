/*
 * EFFD9_TBL.C  palette change tables for effect D9
 *
 * color_table_index has nine entries { end-condition flags, timer, 1P table, 2P table }; the
 * entry number is given when effect D9 is started. The coltbl_NNN_1P and coltbl_NNN_2P tables
 * are the colour steps, { frames, colour } pairs ending with 0, that the effect cycles through
 * the player's extra colour. Read by EFFD9.C, the palette change controller.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 coltbl_000_1P[];
extern const s16 coltbl_000_2P[];
extern const s16 coltbl_001_1P[];
extern const s16 coltbl_001_2P[];
extern const s16 coltbl_002_1P[];
extern const s16 coltbl_002_2P[];
extern const s16 coltbl_003_1P[];
extern const s16 coltbl_003_2P[];
extern const s16 coltbl_004_1P[];
extern const s16 coltbl_004_2P[];
extern const s16 coltbl_005_1P[];
extern const s16 coltbl_005_2P[];
extern const s16 coltbl_006_1P[];
extern const s16 coltbl_006_2P[];
extern const s16 coltbl_007_1P[];
extern const s16 coltbl_007_2P[];
extern const s16 coltbl_008_1P[];

const s16 coltbl_000_1P[10] = {
    1, 8192, 2, 8193, 1, 8195, 2, 8193,
    0, 0,
};

const s16 coltbl_000_2P[10] = {
    1, 8208, 2, 8209, 1, 8211, 2, 8209,
    0, 0,
};

const s16 coltbl_001_1P[6] = {
    2, 8192, 2, 8194, 0, 0,
};

const s16 coltbl_001_2P[6] = {
    2, 8208, 2, 8210, 0, 0,
};

const s16 coltbl_002_1P[4] = {
    999, 8195, 0, 0,
};

const s16 coltbl_002_2P[4] = {
    999, 8211, 0, 0,
};

const s16 coltbl_003_1P[6] = {
    2, 8192, 2, 8193, 0, 0,
};

const s16 coltbl_003_2P[6] = {
    2, 8208, 2, 8209, 0, 0,
};

const s16 coltbl_004_1P[6] = {
    2, 8192, 2, 8196, 0, 0,
};

const s16 coltbl_004_2P[6] = {
    2, 8208, 2, 8212, 0, 0,
};

const s16 coltbl_005_1P[6] = {
    1, 8280, 2, 8192, 0, 0,
};

const s16 coltbl_005_2P[6] = {
    1, 8281, 2, 8208, 0, 0,
};

const s16 coltbl_006_1P[10] = {
    2, 8192, 2, 8259, 2, 8192, 2, 8262,
    0, 0,
};

const s16 coltbl_006_2P[10] = {
    2, 8208, 2, 8267, 2, 8208, 2, 8270,
    0, 0,
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
    { 7, 24, coltbl_003_1P, coltbl_003_2P },
    { 7, 30, coltbl_001_1P, coltbl_001_2P },
    { 5, 0, coltbl_002_1P, coltbl_002_2P },
    { 7, 18, coltbl_004_1P, coltbl_004_2P },
    { 18, 24, coltbl_005_1P, coltbl_005_2P },
    { 17, 24, coltbl_006_1P, coltbl_006_2P },
    { 2, 10, coltbl_007_1P, coltbl_007_2P },
    { 8, 0, coltbl_008_1P, coltbl_008_2P },
};

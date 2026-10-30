/*
 * EFF74_TBL.C  bg130 background cell animation tables
 *
 * eff74_cell_tbl lists the animation cells loaded into the spare character blocks.
 * eff74_anim_tbl gives, for each of the four random patterns, its frame and cell lists
 * (eff74_anim_tbl_0 .. eff74_anim_tbl_7) and their length. Read by EFF74.C, the bg130
 * background cell animation with random patterns.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const EFF74_FRAME eff74_anim_tbl_0[];
extern const s16 eff74_anim_tbl_1[];
extern const EFF74_FRAME eff74_anim_tbl_2[];
extern const s16 eff74_anim_tbl_3[];
extern const EFF74_FRAME eff74_anim_tbl_4[];
extern const s16 eff74_anim_tbl_7[];

extern const CELL_REQ eff74_cell_tbl[][16];

const CELL_REQ eff74_cell_tbl[3][16] = {
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 0xF }, { 0x10C0, 0x10 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 1 }, { 0x30C0, 2 } },
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 3 }, { 0x10C0, 4 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 5 }, { 0x30C0, 6 } },
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 7 }, { 0x10C0, 8 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 7 }, { 0x30C0, 8 } },
};

const EFF74_FRAME eff74_anim_tbl_0[5] = {
    { 0, 0x200, 2 },
    { 0, 0, 2 },
    { 1, 0x200, 2 },
    { 1, 0, 2 },
    { 2, 0x200, 2 },
};

const EFF74_FRAME eff74_anim_tbl_2[2] = {
    { 0, 0x200, 1 },
    { 1, 0x200, 1 },
};

const EFF74_FRAME eff74_anim_tbl_4[2] = {
    { 1, 0, 1 },
    { 2, 0x200, 1 },
};

/* a cell index list like eff74_anim_tbl_1; nothing in the program refers to it (provisional name) */
const s16 eff74_anim_unref_0[4] = {
    0, 1, 2, 0,
};

const s16 eff74_anim_tbl_1[4] = {
    8, 10, 12, 11,
};

const s16 eff74_anim_tbl_3[4] = {
    3, 2, 1, 4,
};

const s16 eff74_anim_tbl_7[5] = {
    1, 2, 2, 1, 0,
};

const EFF74_ANIM eff74_anim_tbl[4] = {
    { eff74_anim_tbl_0, eff74_anim_tbl_1, 5 },
    { eff74_anim_tbl_2, eff74_anim_tbl_3, 2 },
    { eff74_anim_tbl_4, eff74_anim_tbl_3, 2 },
    { eff74_anim_tbl_0, eff74_anim_tbl_7, 5 },
};

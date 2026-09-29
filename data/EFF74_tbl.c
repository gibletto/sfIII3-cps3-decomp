/*
 * EFF74_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 eff74_anim_tbl_0[];
extern const u8 eff74_anim_tbl_1[];
extern const u8 eff74_anim_tbl_2[];
extern const u8 eff74_anim_tbl_3[];
extern const u8 eff74_anim_tbl_4[];
extern const u8 eff74_anim_tbl_7[];

extern const CELL_REQ eff74_cell_tbl[][16];

const CELL_REQ eff74_cell_tbl[3][16] = {
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 0xF }, { 0x10C0, 0x10 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 1 }, { 0x30C0, 2 } },
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 3 }, { 0x10C0, 4 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 5 }, { 0x30C0, 6 } },
    { { 0, 9 }, { 0x40, 0xA }, { 0x80, 0xB }, { 0xC0, 0xC }, { 0x1000, 0xD }, { 0x1040, 0xE }, { 0x1080, 7 }, { 0x10C0, 8 }, { 0x2000, 9 }, { 0x2040, 0xA }, { 0x2080, 0xB }, { 0x20C0, 0xC }, { 0x3000, 0xD }, { 0x3040, 0xE }, { 0x3080, 7 }, { 0x30C0, 8 } },
};

const u8 eff74_anim_tbl_0[30] = {
    0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 1, 2, 0,
    2, 0, 0, 1, 0, 0, 2, 0, 0, 2, 2, 0, 2, 0,
};

const u8 eff74_anim_tbl_2[12] = {
    0, 0, 2, 0, 1, 0, 0, 1, 2, 0, 1, 0,
};

const u8 eff74_anim_tbl_4[20] = {
    0, 1, 0, 0, 1, 0, 0, 2, 2, 0, 1, 0, 0, 0, 0, 1,
    0, 2, 0, 0,
};

const u8 eff74_anim_tbl_1[8] = {
    0, 8, 0, 10, 0, 12, 0, 11,
};

const u8 eff74_anim_tbl_3[8] = {
    0, 3, 0, 2, 0, 1, 0, 4,
};

const u8 eff74_anim_tbl_7[10] = {
    0, 1, 0, 2, 0, 2, 0, 1, 0, 0,
};

const EFF74_ANIM eff74_anim_tbl[4] = {
    { (void*)((const u8*)eff74_anim_tbl_0), (void*)((const u8*)eff74_anim_tbl_1), 5 },
    { (void*)((const u8*)eff74_anim_tbl_2), (void*)((const u8*)eff74_anim_tbl_3), 2 },
    { (void*)((const u8*)eff74_anim_tbl_4), (void*)((const u8*)eff74_anim_tbl_3), 2 },
    { (void*)((const u8*)eff74_anim_tbl_0), (void*)((const u8*)eff74_anim_tbl_7), 5 },
};

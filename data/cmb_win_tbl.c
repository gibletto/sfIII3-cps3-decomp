/*
 * CMB_WIN_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 combo_mpos_tbl[7][2] = {
    { 3, 12 }, { 3, 8 }, { 3, 4 }, { 0, 5 }, { 0, 9 }, { 0, 11 }, { 0, 9 },
};

const s16 combo_mclr_pos_tbl[7][2] = {
    { 11, 8 }, { 15, 4 }, { 19, 0 }, { 15, 4 }, { 11, 8 }, { 9, 10 }, { 11, 8 },
};

const s16 combo_hitpos_tbl[3][2] = {
    { 0, 9 }, { 0, 5 }, { 0, 1 },
};

const u16 combo_erase_pos_tbl[2][8][2] = {
    { { 0x24, 1 }, { 0x1F, 1 }, { 0x1C, 1 }, { 0x20, 1 }, { 0x24, 1 }, { 0x26, 1 }, { 0x24, 1 }, { 0x24, 1 } },
    { { 0x32, 1 }, { 0x2D, 1 }, { 0x2A, 1 }, { 0x2E, 1 }, { 0x32, 1 }, { 0x34, 1 }, { 0x32, 1 }, { 0x30, 1 } },
};

const u16 combo_erase_len_tbl[11] = {
    0xB, 0x10, 0x13, 0xF, 0xB, 9, 0xB, 0xB,
    0x22, 0x22, 0x24,
};

const s16 sa_color_data_tbl[3] = {
    26, 24, 26,
};

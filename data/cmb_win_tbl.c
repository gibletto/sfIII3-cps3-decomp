/*
 * CMB_WIN_TBL.C  combo display and super art colour tables
 *
 * combo_mpos_tbl, combo_mclr_pos_tbl, combo_hitpos_tbl, combo_erase_pos_tbl and
 * combo_erase_len_tbl are the text-layer positions and erase lengths of the combo hit message;
 * sa_color_data_tbl gives the colour of the super art gauge cells. Read by SC_TRANS.C.
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
    { { 36, 1 }, { 31, 1 }, { 28, 1 }, { 32, 1 }, { 36, 1 }, { 38, 1 }, { 36, 1 }, { 36, 1 } },
    { { 50, 1 }, { 45, 1 }, { 42, 1 }, { 46, 1 }, { 50, 1 }, { 52, 1 }, { 50, 1 }, { 48, 1 } },
};

const u16 combo_erase_len_tbl[11] = {
    11, 16, 19, 15, 11, 9, 11, 11,
    34, 34, 36,
};

const u16 sa_color_data_tbl[3] = {
    26, 24, 26,
};

/*
 * SC_TRANS_TBL2.C  text layer HUD and picture tables
 *
 * sc_celllist_scr_tbl gives each cell list its screen column base, tone_down_tbl the
 * tone-down character transfers, picture_chr_tbl / picture_set_tbl / picture_attr_tbl the
 * text layer pictures, nwdata_tbl the winner name plates by character, vmark_tbl the win mark
 * positions, smark_pos_tbl and smark_kind_tbl the stun mark position and size by character,
 * and combo_mtbl the combo message frames. Read by SC_TRANS.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s8 sc_celllist_scr_tbl[18] = {
    0, 3, 3, 3, 13, 12, 3, 3,
    3, 3, 3, 3, 3, 6, 0, 3,
    3, 0,
};

const TONE_ENTRY tone_down_tbl[20] = {
    { 0x80, 0x600, 0 },
    { 4, 0x1B0, 0xBA },
    { 4, 0x1C0, 0xCA },
    { 0x30, 0x12A0, 0x130 },
    { 0x20, 0x13A0, 0x1E0 },
    { 0xC8, 0x1000, 0x130 },
    { 0x10, 0x12D0, 0x160 },
    { 0x10, 0x12E0, 0x170 },
    { 0x70, 0x1000, 0x130 },
    { 0x30, 0x10A0, 0x1D0 },
    { 0x20, 0x1000, 0x130 },
    { 0x20, 0x1020, 0x150 },
    { 0x20, 0x1040, 0x170 },
    { 0x20, 0x1060, 0x190 },
    { 0x20, 0x1080, 0x1B0 },
    { 0x28, 0x10A0, 0x1D0 },
    { 0x1B, 0x6C0, 0x40 },
    { 0x10, 0x680, 0 },
    { 0x1B, 0x640, 0x40 },
    { 0x10, 0x600, 0 },
};

const u16 picture_chr_tbl[8] = {
    0xD80, 0xC80, 0xF00, 0xE80, 0xC00, 0xD00, 0xF80, 0x780,
};

const s16 picture_set_tbl[8] = {
    19, 26, 26, 18, 26, 18, 18, 28,
};

const u16 picture_attr_tbl[8] = {
    0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
};

const NAME_PLATE nwdata_tbl[22] = {
    { 0x1100, 10, 4, 13, 9, 24, 9 },
    { 0x1128, 13, 4, 11, 9, 25, 9 },
    { 0x115C, 10, 4, 13, 9, 24, 9 },
    { 0x1184, 10, 4, 13, 9, 24, 9 },
    { 0x11AC, 16, 4, 10, 9, 27, 9 },
    { 0x11F4, 16, 4, 10, 9, 27, 9 },
    { 0x1234, 14, 4, 11, 9, 26, 9 },
    { 0x126C, 14, 4, 11, 9, 26, 9 },
    { 0x12A4, 15, 4, 10, 9, 26, 9 },
    { 0x12E0, 10, 4, 13, 9, 24, 9 },
    { 0x1308, 13, 4, 11, 9, 25, 9 },
    { 0x133C, 10, 4, 13, 9, 24, 9 },
    { 0x1364, 13, 4, 11, 9, 25, 9 },
    { 0x1398, 15, 4, 10, 9, 26, 9 },
    { 0x13D4, 15, 4, 10, 9, 26, 9 },
    { 0x1410, 15, 4, 10, 9, 26, 9 },
    { 0x144C, 16, 4, 10, 9, 27, 9 },
    { 0x148C, 16, 4, 10, 9, 27, 9 },
    { 0x14CC, 4, 4, 16, 9, 21, 9 },
    { 0x14DC, 16, 4, 10, 9, 27, 9 },
    { 0x151C, 13, 4, 11, 9, 25, 9 },
    { 0x1550, 14, 4, 11, 9, 26, 9 },
};

const s16 vmark_tbl[48] = {
    19, 4, 16, 20, 4, 17, 17, 4,
    18, 18, 4, 19, 15, 4, 20, 16,
    4, 21, 13, 4, 22, 14, 4, 23,
    27, 4, 24, 28, 4, 25, 29, 4,
    26, 30, 4, 27, 31, 4, 28, 32,
    4, 29, 33, 4, 30, 34, 4, 31,
};

const s16 smark_pos_tbl[24][2] = {
    { 14, 29 },  /* Gill */
    { 14, 29 },  /* Alex */
    { 15, 29 },  /* Ryu */
    { 15, 29 },  /* Yun */
    { 14, 29 },  /* Dudley */
    { 15, 29 },  /* Necro */
    { 14, 29 },  /* Hugo */
    { 15, 29 },  /* Ibuki */
    { 15, 29 },  /* Elena */
    { 14, 29 },  /* Oro */
    { 15, 29 },  /* Yang */
    { 15, 29 },  /* Ken */
    { 15, 29 },  /* Sean */
    { 15, 29 },  /* Urien */
    { 15, 28 },  /* Gouki */
    { 15, 28 },  /* Shin Gouki */
    { 15, 29 },  /* Chun-Li */
    { 15, 29 },  /* Makoto */
    { 14, 29 },  /* Q */
    { 15, 29 },  /* Twelve */
    { 15, 28 },  /* Remy */
    { 15, 29 },  /* 21 */
    { 15, 29 },  /* 22 */
    { 15, 29 },  /* 23 */
};

const u16 smark_kind_tbl[24] = {
    1, 1, 0, 0, 1, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 1, 0, 1, 0, 0, 0,
};

const CMB_FRAME combo_mtbl[7] = {
    { 0xB06, 8, 2 },
    { 0xB20, 12, 2 },
    { 0xB40, 16, 2 },
    { 0xB60, 15, 2 },
    { 0xB80, 11, 2 },
    { 0xBA0, 9, 2 },
    { 0xBC0, 11, 2 },
};

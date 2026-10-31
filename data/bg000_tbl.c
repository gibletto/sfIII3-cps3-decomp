/*
 * BG000_TBL.C  stage background set-up tables
 *
 * Per stage background (bg_index), and for the special screens drawn by bg_etc_write (the etc_
 * tables, by screen type): the scroll graphics number (use_scr), graphics source and size
 * (bg_gfx_tbl), layer scroll speeds (msp), layer priorities (bg_prio_tbl), cell
 * attributes, cell counts and cell sources (bg_attr_tbl, bg_cell_cnt_tbl, bg_cg_src_tbl), the
 * cell set per stage (bg_cell_set_tbl) and the layer scroll limits (limit_tbl3).
 * bg_rewrite_cells0 - 9 are the cell lists (map offset, cell number) bg_scr_write puts into each
 * background layer, and bg_etc_cells0 - 12 those bg_etc_scr_write puts on the special screens;
 * both are reached through bg_rewrite_cell_tbl and bg_etc_cell_tbl in BG000.C. Also the
 * layer layout records that bg_map_tbl and bg_map_tbl2 in BG000.C name per stage and layer:
 * bg_scr_record_NN_n (stage NN, layer n) and etc_bg_scr_record_N_n (special screen N), each
 * named after the first entry that uses it, bg_scr_record_data (layer 0 of stage 0 and most
 * special screens), ake_scr_record_data (the finish screen's layer 3) and the unreferenced
 * bg_scr_record_unref_N. Read by BG000.C; bg_gfx_tbl and bg_scr_record_data also by the debug
 * fight setups in CMD_MAIN.C.
 *
 * A layer layout record (sprite_list_setup) is a run of groups, each the layer and priority followed by
 * (code, position, attribute) entries and -1, ended by -1; the comment before each record says which
 * stages' layers use it.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 debug_scene_scrn_data[17][16][32];
extern const u16 eff08_scrn_data[29][16][32];
extern const u16 eff23_scrn_data[49][16][32];
extern const u16 eff45_scrn_data[29][16][32];
extern const u16 eff74_scrn_data[17][16][32];
extern const u16 effJ5_scrn_data[29][16][32];
extern const u16 end_2000_scrn_data[5][16][32];
extern const u16 russia2_scrn_data[4][16][32];
extern const u16 bg_scrn_data_00[17][16][32];
extern const u16 bg_scrn_data_02[25][16][32];
extern const u16 bg_scrn_data_04[17][16][32];
extern const u16 bg_scrn_data_05[17][16][32];
extern const u16 bg_scrn_data_06[17][16][32];
extern const u16 bg_scrn_data_09[17][16][32];
extern const u16 bg_scrn_data_12[17][16][32];
extern const u16 bg_scrn_data_13[17][16][32];
extern const u16 bg_scrn_data_14[19][16][32];
extern const u16 bg_scrn_data_16[17][16][32];
extern const u16 bg_scrn_data_17[18][16][32];
extern const u16 bg_scrn_data_18[17][16][32];
extern const u16 bg_scrn_data_21[17][16][32];
extern const u16 bg_scrn_data_22[17][16][32];
extern const u16 etc_bg_scrn_data_0[12][16][32];
extern const u16 etc_bg_scrn_data_3[95][16][32];
extern const u16 etc_bg_scrn_data_7[3][16][32];

const s16 use_scr[23] = {
    2, 2, 3, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2,
};

const s16 use_scr2[12] = {
    1, 1, 1, 1, 2, 1, 1, 1,
    1, 1, 1, 1,
};

/* layer 0 of stage 0; layer 0 of special screens 1, 2, 3, 4, 5, 7, 11 */
const s16 bg_scr_record_data[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stages 0, 1, 3, 4, 5, 6, 7, 10, 13, 14, 15, 16, 17, 19; layer 1 of special screens 0, 4; provisional name */
const s16 bg_scr_record_00_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 2 of stage 0; provisional name */
const s16 bg_scr_record_00_2[16] = {
    3, 104,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_0[16] = {
    4, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_1[28] = {
    0, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 3 of the finish screen (akebono_initialize) */
/* provisional name */
const s16 ake_scr_record_data[28] = {
    4, 69,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stages 1, 4, 6, 11, 20; provisional name */
const s16 bg_scr_record_01_0[7] = {
    1, 94,  0x1FF, 0x100, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_2[7] = {
    2, 84,  0x1FF, 0x100, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_3[7] = {
    3, 104,  0x1FF, 0x100, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_4[7] = {
    4, 94,  0x1FF, 0x100, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_5[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_6[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_7[16] = {
    3, 104,  0x7F, 0x7F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  -1,
    -1,
};

/* layer 1 of stage 11; provisional name */
const s16 bg_scr_record_11_1[16] = {
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1F0, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 2; provisional name */
const s16 bg_scr_record_02_0[16] = {
    1, 94,  0x7F, 0x4F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 2; provisional name */
const s16 bg_scr_record_02_1[7] = {
    2, 84,  0x4A, 0x4A00, 12,  -1,
    -1,
};

/* layer 2 of stage 2; provisional name */
const s16 bg_scr_record_02_2[16] = {
    3, 104,  0x7F, 0x1000, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 3; provisional name */
const s16 bg_scr_record_03_0[16] = {
    1, 94,  0x7F, 0x5800, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 10; provisional name */
const s16 bg_scr_record_10_0[16] = {
    1, 20,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stages 5, 19; provisional name */
const s16 bg_scr_record_05_0[16] = {
    1, 94,  0x7F, 0x5100, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_8[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_9[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 7; provisional name */
const s16 bg_scr_record_07_0[16] = {
    1, 104,  0x7F, 0x5400, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_10[7] = {
    2, 84,  0x4F, 0x4F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_11[16] = {
    3, 94,  0x7F, 0x1000, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 8; provisional name */
const s16 bg_scr_record_08_0[16] = {
    1, 104,  0x7F, 0x3C00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 8; provisional name */
const s16 bg_scr_record_08_1[7] = {
    2, 84,  0x3F, 0x3F00, 12,  -1,
    -1,
};

/* layer 2 of stage 8; provisional name */
const s16 bg_scr_record_08_2[7] = {
    3, 94,  0x70, 0x2000, 12,  -1,
    -1,
};

/* layer 0 of stage 9; provisional name */
const s16 bg_scr_record_09_0[16] = {
    1, 94,  0x7F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 9; provisional name */
const s16 bg_scr_record_09_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 12; provisional name */
const s16 bg_scr_record_12_0[16] = {
    1, 94,  0x7F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 12; provisional name */
const s16 bg_scr_record_12_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 13; provisional name */
const s16 bg_scr_record_13_0[16] = {
    1, 94,  0x7F, 0x4F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stages 14, 15; provisional name */
const s16 bg_scr_record_14_0[16] = {
    1, 94,  0x7F, 0x4F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_12[16] = {
    2, 84,  0x3F, 0x3F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 16; provisional name */
const s16 bg_scr_record_16_0[13] = {
    1, 94,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 17; provisional name */
const s16 bg_scr_record_17_0[10] = {
    1, 94,  0x17F, 0x6000, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 18; provisional name */
const s16 bg_scr_record_18_0[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 18; provisional name */
const s16 bg_scr_record_18_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_13[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_14[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_15[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 20; provisional name */
const s16 bg_scr_record_20_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 21; provisional name */
const s16 bg_scr_record_21_0[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 21; provisional name */
const s16 bg_scr_record_21_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of stage 22; provisional name */
const s16 bg_scr_record_22_0[16] = {
    1, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 1 of stage 22; provisional name */
const s16 bg_scr_record_22_1[16] = {
    2, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* layer 0 of special screens 0, 6, 8, 9, 10; provisional name */
const s16 etc_bg_scr_record_0_0[28] = {
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_16[16] = {
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_17[16] = {
    2, 94,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

/* not referred to; provisional name */
const s16 bg_scr_record_unref_18[16] = {
    3, 104,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  -1,
    -1,
};

const s32 msp[23][3][2] = {
    { { 0xE000, 0xA000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0xA000, 0x10000 } },
    { { 0xD000, 0xD000 }, { 0x10000, 0x10000 }, { 0x8000, 0xD000 } },
    { { 0xC000, 0xC000 }, { 0x10000, 0x10000 }, { 0xA000, 0x10000 } },
    { { 0xA000, 0xC000 }, { 0x10000, 0x10000 }, { 0xA000, 0x10000 } },
    { { 0x8000, 0xF000 }, { 0x10000, 0x10000 }, { 0x8000, 0xB000 } },
    { { 0xF000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x9000, 0xE000 }, { 0x10000, 0x10000 }, { 0xD000, 0xF800 } },
    { { 0x1000, 0xE800 }, { 0x10000, 0x10000 }, { 0x3000, 0xE000 } },
    { { 0x8000, 0x10000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x8000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x8000, 0xF000 }, { 0x10000, 0x10000 }, { 0x8000, 0xB000 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0xC000, 0xF000 }, { 0x10000, 0x10000 }, { 0x8000, 0xB000 } },
    { { 0xF000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x8000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
    { { 0x8000, 0xE000 }, { 0x10000, 0x10000 }, { 0, 0 } },
};

/* Layer scroll speeds of the first eight special screen types. bg_etc_write reads it with types 8-11 too,
   past the end, into etc_bg_zuubun_tbl: those screens' layers get the speed 0 found there. */
const s32 msp2[8][3][2] = {
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xF800, 0xF000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
    { { 0x10000, 0x10000 }, { 0x10000, 0x10000 }, { 0xE000, 0xE000 } },
};

/* provisional name */
const s32 etc_bg_zuubun_tbl[12][3] = {
    { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
    { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
};

/* provisional name */
const BG_GFX bg_gfx_tbl[23] = {
    { 0x1FFB800, 30623, 0x1FFB880, 1 },
    { 0x1E7D800, 21023, 0x1E7D880, 1 },
    { 0x1F0E800, 22511, 0x1F0E880, 1 },
    { 0x1EAB800, 21167, 0x1EAB880, 1 },
    { 0x1FAD800, 26191, 0x1FAD880, 1 },
    { 0x1E92800, 24127, 0x1E92880, 1 },
    { 0x1FD7000, 28559, 0x1FD7080, 1 },
    { 0x1F24800, 32431, 0x1F24880, 1 },
    { 0x1E68000, 24799, 0x1E68080, 1 },
    { 0x1FA2000, 12479, 0x1FA2080, 1 },
    { 0x1EBE000, 74639, 0x1EBE080, 1 },
    { 0x1E7D800, 21023, 0x1E7D880, 1 },
    { 0x1EFD000, 17071, 0x1EFD080, 1 },
    { 0x1E00000, 34623, 0x1E00080, 1 },
    { 0x1E2B800, 23903, 0x1E2B880, 1 },
    { 0x1E2B800, 23903, 0x1E2B880, 1 },
    { 0x1F49000, 35407, 0x1F49080, 1 },
    { 0x1E42000, 26015, 0x1E42080, 1 },
    { 0x1E92800, 24127, 0x1E92880, 1 },
    { 0x1EED000, 18367, 0x1EED080, 1 },
    { 0x2042000, 23359, 0x2042080, 1 },
    { 0x1F7C000, 16335, 0x1F7C080, 1 },
    { 0x1F8B800, 13055, 0x1F8B880, 1 },
};

/* provisional name */
const BG_GFX etc_bg_gfx_tbl[23] = {
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x208E000, 4383, 0x208E080, 1 },
    { 0x208E000, 4383, 0x208E080, 1 },
    { 0x2082000, 47583, 0x2082080, 1 },
    { 0x2082000, 47583, 0x2082080, 1 },
    { 0x207A000, 5407, 0x207A080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0x2082000, 36879, 0x2082080, 1 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};

const s16 bg_prio_tbl[23][3] = {
    { 24, 24, 24 },
    { 0, 24, 0 },
    { 24, 24, 24 },
    { 24, 24, 0 },
    { 0, 24, 0 },
    { 24, 24, 0 },
    { 0, 24, 0 },
    { 24, 24, 24 },
    { 24, 24, 24 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 0, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 24, 24, 0 },
    { 0, 24, 0 },
    { 24, 24, 24 },
    { 0, 24, 0 },
};

/* provisional name */
const s16 bg_attr_tbl[23] = {
    512, 512, 512, 512, 512, 512, 512, 512,
    512, 512, 512, 512, 512, 512, 512, 512,
    512, 512, 512, 512, 512, 512, 512,
};

/* provisional name */
const s16 etc_bg_attr_tbl[13] = {
    512, 512, 512, 512, 512, 512, 512, 512,
    512, 512, 512, 512, 512,
};

/* provisional name */
const s16 bg_cell_cnt_tbl[23][3] = {
    { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 },
    { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 },
    { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 }, { 8, 8, 8 },
};

/* provisional name */
const s16 etc_bg_cell_cnt_tbl[12][3] = {
    { 4, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 2, 0 }, { 2, 0, 0 }, { 4, 0, 0 }, { 2, 0, 0 },
    { 4, 0, 0 }, { 4, 0, 0 }, { 4, 0, 0 }, { 2, 0, 0 },
};

/* provisional name */
const u32 bg_cg_src_tbl[23] = {
    (u32)bg_scrn_data_00,
    (u32)debug_scene_scrn_data,
    (u32)bg_scrn_data_02,
    (u32)eff08_scrn_data,
    (u32)bg_scrn_data_04,
    (u32)bg_scrn_data_05,
    (u32)bg_scrn_data_06,
    (u32)effJ5_scrn_data,
    (u32)eff45_scrn_data,
    (u32)bg_scrn_data_09,
    (u32)eff23_scrn_data,
    (u32)debug_scene_scrn_data,
    (u32)bg_scrn_data_12,
    (u32)bg_scrn_data_13,
    (u32)bg_scrn_data_14,
    (u32)bg_scrn_data_14,
    (u32)bg_scrn_data_16,
    (u32)bg_scrn_data_17,
    (u32)bg_scrn_data_18,
    (u32)bg_scrn_data_18,
    (u32)eff74_scrn_data,
    (u32)bg_scrn_data_21,
    (u32)bg_scrn_data_22,
};

const u32 etc_bg_cg_src_tbl[12] = {
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_3,
    (u32)etc_bg_scrn_data_3,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_7,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
    (u32)etc_bg_scrn_data_0,
};

/* provisional name */
const HUD_CELL bg_rewrite_cells0[8] = {
    { 0x2000, 1 }, { 0x2040, 2 }, { 0x2080, 3 }, { 0x20C0, 4 },
    { 0x3000, 5 }, { 0x3040, 6 }, { 0x3080, 7 }, { 0x30C0, 8 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells1[8] = {
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
    { 0x3000, 13 }, { 0x3040, 14 }, { 0x3080, 15 }, { 0x30C0, 16 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells2[8] = {
    { 0x2000, 17 }, { 0x2040, 18 }, { 0x2080, 19 }, { 0x20C0, 20 },
    { 0x3000, 21 }, { 0x3040, 22 }, { 0x3080, 23 }, { 0x30C0, 24 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells3[8] = {
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
    { 0x3000, 13 }, { 0x3040, 14 }, { 0x3080, 17 }, { 0x30C0, 18 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells4[8] = {
    { 0x2000, 1 }, { 0x2040, 2 }, { 0x2080, 3 }, { 0x20C0, 4 },
    { 0x3000, 17 }, { 0x3040, 18 }, { 0x3080, 7 }, { 0x30C0, 8 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells5[8] = {
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
    { 0x3000, 13 }, { 0x3040, 14 }, { 0x3080, 17 }, { 0x30C0, 16 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells6[8] = {
    { 0x2000, 9 }, { 0x2040, 10 }, { 0x2080, 11 }, { 0x20C0, 12 },
    { 0x3000, 13 }, { 0x3040, 14 }, { 0x3080, 15 }, { 0x30C0, 16 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells7[8] = {
    { 0x2000, 17 }, { 0x2040, 18 }, { 0x2080, 19 }, { 0x20C0, 20 },
    { 0x3000, 21 }, { 0x3040, 22 }, { 0x3080, 23 }, { 0x30C0, 24 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells8[12] = {
    { 0x2000, 0 }, { 0x2040, 1 }, { 0x2080, 2 }, { 0x20C0, 0 },
    { 0x3000, 0 }, { 0x3040, 5 }, { 0x3080, 6 }, { 0x30C0, 0 },
    { 0, 0 }, { 0x40, 8 }, { 0x80, 9 }, { 0xC0, 0 },
};

/* provisional name */
const HUD_CELL bg_rewrite_cells9[18] = {
    { 0x3000, 0 }, { 0x3040, 1 }, { 0x3080, 2 }, { 0x30C0, 0 },
    { 0x2000, 0 }, { 0x2040, 1 }, { 0x2000, 0 }, { 0x2040, 1 },
    { 0x2000, 0 }, { 0x2040, 1 }, { 0x1000, 0 }, { 0x1040, 0 },
    { 0x1080, 1 }, { 0x10C0, 1 }, { 0x3000, 2 }, { 0x3040, 2 },
    { 0x3080, 3 }, { 0x30C0, 3 },
};

const s16 bg_cell_set_tbl[24] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1,
    0, 5, 0, 0, 0, 0, 0, 0,
};

/* provisional name */
const TILEREQ bg_etc_cells0[4] = {
    { 64, 0x1040, 3 }, { 64, 0x1080, 4 }, { 64, 0x3040, 5 }, { 64, 0x3080, 6 },
};

/* provisional name */
const TILEREQ bg_etc_cells1[4] = {
    { 64, 0x1040, 3 }, { 64, 0x1080, 4 }, { 97, 0x3040, 5 }, { 97, 0x3080, 6 },
};

/* provisional name */
const TILEREQ bg_etc_cells2[4] = {
    { 64, 0x1040, 3 }, { 64, 0x1080, 4 }, { 99, 0x3040, 5 }, { 99, 0x3080, 6 },
};

/* provisional name */
const TILEREQ bg_etc_cells3[4] = {
    { 64, 0x1040, 3 }, { 64, 0x1080, 4 }, { 101, 0x3040, 5 }, { 101, 0x3080, 6 },
};

/* provisional name */
const TILEREQ bg_etc_cells4[2] = {
    { 64, 0x3040, 5 }, { 64, 0x3080, 6 },
};

/* provisional name */
const TILEREQ bg_etc_cells5[2] = {
    { 107, 0x3040, 1 }, { 107, 0x3080, 2 },
};

/* provisional name */
const TILEREQ bg_etc_cells6[2] = {
    { 108, 0x3040, 1 }, { 108, 0x3080, 2 },
};

/* provisional name */
const TILEREQ bg_etc_cells7[2] = {
    { 64, 0x3040, 1 }, { 64, 0x3080, 2 },
};

/* provisional name */
const TILEREQ bg_etc_cells8[2] = {
    { 64, 0x3040, 1 }, { 64, 0x3080, 2 },
};

/* provisional name */
const TILEREQ bg_etc_cells9[2] = {
    { 64, 0x3040, 3 }, { 64, 0x3080, 4 },
};

/* provisional name */
const TILEREQ bg_etc_cells10[2] = {
    { 64, 0x2040, 3 }, { 64, 0x2080, 4 },
};

/* provisional name */
const TILEREQ bg_etc_cells11[4] = {
    { 64, 0x1040, 3 }, { 64, 0x1080, 4 }, { 64, 0x3040, 1 }, { 64, 0x3080, 2 },
};

/* provisional name */
const TILEREQ bg_etc_cells12[2] = {
    { 32, 0x3040, 1 }, { 32, 0x3080, 2 },
};

const s16 limit_tbl3[23][3][6] = {
    { { 272, 692, 360, 636, 240, 240 }, { 272, 752, 328, 696, 240, 240 }, { 209, 756, 265, 700, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 764, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 748, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 760, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 752, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 272, 752, 328, 696, 240, 240 }, { 272, 752, 324, 696, 240, 240 }, { 272, 752, 328, 696, 240, 240 } },
    { { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 } },
    { { 335, 704, 389, 639, 192, 192 }, { 271, 752, 314, 708, 192, 192 }, { 399, 640, 449, 578, 192, 192 } },
    { { 268, 744, 324, 688, 240, 240 }, { 268, 744, 324, 652, 240, 240 }, { 268, 744, 324, 688, 240, 240 } },
    { { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 760, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 764, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 } },
    { { 360, 687, 384, 631, 227, 227 }, { 268, 760, 322, 700, 227, 227 }, { 419, 628, 443, 572, 227, 227 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 752, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 333, 695, 389, 639, 240, 240 }, { 272, 752, 314, 708, 240, 240 }, { 393, 634, 449, 578, 240, 240 } },
    { { 270, 760, 326, 704, 240, 240 }, { 262, 760, 270, 704, 240, 240 }, { 270, 760, 326, 704, 240, 240 } },
    { { 333, 695, 389, 639, 232, 232 }, { 276, 754, 338, 688, 232, 232 }, { 393, 634, 449, 578, 232, 232 } },
    { { 272, 752, 328, 696, 240, 240 }, { 272, 752, 324, 696, 240, 240 }, { 272, 752, 328, 696, 240, 240 } },
    { { 272, 752, 328, 696, 240, 240 }, { 272, 752, 272, 696, 240, 240 }, { 272, 752, 328, 696, 240, 240 } },
    { { 268, 754, 324, 698, 240, 240 }, { 274, 752, 324, 698, 240, 240 }, { 268, 754, 324, 698, 240, 240 } },
    { { 452, 572, 508, 516, 184, 184 }, { 452, 572, 508, 516, 184, 184 }, { 452, 572, 508, 516, 184, 184 } },
    { { 452, 572, 508, 516, 184, 184 }, { 452, 572, 508, 516, 184, 184 }, { 452, 572, 508, 516, 184, 184 } },
};

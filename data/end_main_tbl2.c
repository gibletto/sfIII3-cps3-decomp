/*
 * END_MAIN_TBL2.C  opening and ending control tables
 *
 * op_bg0_0015_tbl is the six-step pattern list passed to oh_opening_demo by an opening BG0
 * scene. The rest are indexed by the ending's character number: end_bg_index_tbl picks the
 * ending's entry in end_bg_gfx_tbl (scroll graphics source, size and preparation data),
 * end_use_scr gives its number of BG layers, end_color_tbl its colour load, staff_fade_tbl
 * the fade that closes the ending scenes and end_fade_tbl the fade from its closing picture
 * into the staff roll. end_cg_src_tbl holds the screen data of each character's closing
 * picture, and end_map_data_0 .. 3 are the layout records of the four ending BG layers,
 * reached through end_map_tbl. All read by END_MAIN.C; end_stage_no_tbl is not read.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 end_1000_scrn_data[9][16][32];
extern const u16 end_100_scrn_data[12][16][32];
extern const u16 end_1100_scrn_data[19][16][32];
extern const u16 end_1600_scrn_data[14][16][32];
extern const u16 end_1800_scrn_data[11][16][32];
extern const u16 end_1900_scrn_data[10][16][32];
extern const u16 end_2000_scrn_data[5][16][32];
extern const u16 end_200_scrn_data[9][16][32];
extern const u16 end_300_scrn_data[14][16][32];
extern const u16 end_400_scrn_data[22][16][32];
extern const u16 end_500_scrn_data[18][16][32];
extern const u16 end_600_scrn_data[15][16][32];
extern const u16 end_700_scrn_data[15][16][32];
extern const u16 end_800_scrn_data[12][16][32];
extern const u16 end_900_scrn_data[9][16][32];
extern const u16 end_ake_scrn_data[21][16][32];
extern const u16 end_b00_scrn_data[16][16][32];
extern const u16 end_c00_scrn_data[19][16][32];
extern const u16 end_d00_scrn_data[9][16][32];
extern const u16 end_e00_scrn_data[16][16][32];

const s16 op_bg0_0015_tbl[6] = {
    45, 46, 45, 46, 47, 41,
};

/* provisional name */
/* A per-player number like end_use_scr (player 15 shares 14, players 21-23 and 0 give 5), stored after
   op_bg0_0015_tbl. Nothing in the program refers to it. */
const s16 end_stage_no_tbl[24] = {
    5, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 14,
    16, 17, 18, 19, 20, 5, 5, 5,
};

const s16 end_use_scr[24] = {
    0, 1, 3, 2, 3, 2, 2, 2,
    1, 1, 3, 2, 2, 2, 3, 3,
    1, 3, 2, 2, 2, 2, 2, 2,
};

const s16 end_bg_index_tbl[24] = {
    0, 1, 2, 21, 16, 4, 7, 15,
    13, 5, 8, 17, 6, 9, 10, 10,
    14, 11, 18, 19, 12, 1, 1, 1,
};

const END_BG_GFX end_bg_gfx_tbl[24] = {
    { 0, 0, 0 }, { 0x1CDD000, 16175, 0x1CDD080 }, { 0x1C65000, 16175, 0x1C65080 }, { 0x208F800, 10287, 0x208F880 }, { 0x1A95000, 29199, 0x1A95080 }, { 0x1A76800, 12191, 0x1A76880 }, { 0x1AC2000, 27103, 0x1AC2080 }, { 0x1AE3000, 22927, 0x1AE3080 },
    { 0x1B84000, 15663, 0x1B84080 }, { 0x1B07000, 15247, 0x1B07080 }, { 0x1A1E000, 19263, 0x1A1E080 }, { 0x1A0F000, 16031, 0x1A0F080 }, { 0x1B3F000, 11775, 0x1B3F080 }, { 0x1A80800, 16095, 0x1A80880 }, { 0x1B98000, 17487, 0x1B98080 }, { 0x1A5A800, 19311, 0x1A5A880 },
    { 0x1BC8000, 32991, 0x1BC8080 }, { 0x1C16000, 16687, 0x1C16080 }, { 0x1C3D000, 10703, 0x1C3D080 }, { 0x1C8D000, 15071, 0x1C8D080 }, { 0x1C8D000, 15071, 0x1C8D080 }, { 0x1CB5000, 18255, 0x1CB5080 }, { 0, 0, 0 }, { 0, 0, 0 },
};

const u32 end_cg_src_tbl[24] = {
    (u32)end_100_scrn_data,
    (u32)end_100_scrn_data,
    (u32)end_200_scrn_data,
    (u32)end_ake_scrn_data,
    (u32)end_500_scrn_data,
    (u32)end_900_scrn_data,
    (u32)end_c00_scrn_data,
    (u32)end_600_scrn_data,
    (u32)end_1000_scrn_data,
    (u32)end_d00_scrn_data,
    (u32)end_e00_scrn_data,
    (u32)end_1100_scrn_data,
    (u32)end_2000_scrn_data,
    (u32)end_800_scrn_data,
    (u32)end_1600_scrn_data,
    (u32)end_700_scrn_data,
    (u32)end_400_scrn_data,
    (u32)end_b00_scrn_data,
    (u32)end_1800_scrn_data,
    (u32)end_1900_scrn_data,
    (u32)end_300_scrn_data,
    0,
    0,
    0,
};

/* provisional name */
const s16 end_map_data_0[28] = {
    /* [0] */
    1, 84,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_1[28] = {
    /* [0] */
    2, 94,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  0x27F, 0x7F00, 28,
           0x2FF, 0x7F00, 28,  0x37F, 0x7F00, 28,  0x3FF, 0x7F00, 28,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_2[28] = {
    /* [0] */
    3, 104,  0x7F, 0x7F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  0x27F, 0x7F00, 44,
           0x2FF, 0x7F00, 44,  0x37F, 0x7F00, 44,  0x3FF, 0x7F00, 44,  -1,
    -1,
};

/* provisional name */
const s16 end_map_data_3[28] = {
    /* [0] */
    4, 114,  0x7F, 0x7F00, 60,  0xFF, 0x7F00, 60,  0x17F, 0x7F00, 60,  0x1FF, 0x7F00, 60,  0x27F, 0x7F00, 60,
           0x2FF, 0x7F00, 60,  0x37F, 0x7F00, 60,  0x3FF, 0x7F00, 60,  -1,
    -1,
};

const s8 end_color_tbl[24] = {
    18, 48, 41, 47, 34, 19, 24, 31,
    28, 21, 29, 35, 26, 25, 20, 20,
    30, 18, 36, 43, 27, 18, 18, 18,
};

const u16 staff_fade_tbl[24] = {
    0x38, 0x71, 0x5F, 0x67, 0x55, 0x10, 0x36, 0x52,
    0x47, 0x33, 0x4A, 0x58, 0x3C, 0x39, 0x1B, 0x1B,
    0x4D, 0x12, 0x5B, 0x64, 0x43, 0x3A, 0x3A, 0x3A,
};

const u16 end_fade_tbl[48] = {
    0x3C, 0x70, 0x5E, 0x66, 0x54, 0x1A, 0x35, 0x51,
    0x46, 0x32, 0x49, 0x57, 0x3B, 0x38, 0x1C, 0x1C,
    0x4C, 0x19, 0x5A, 0x63, 0x42, 0x45, 0x45, 0x45,
    0x3C, 0x72, 0x60, 0x68, 0x56, 0x17, 0x37, 0x53,
    0x48, 0x34, 0x4B, 0x59, 0x3D, 0x3A, 0x18, 0x18,
    0x4E, 0x14, 0x5C, 0x65, 0x44, 0x45, 0x45, 0x45,
};

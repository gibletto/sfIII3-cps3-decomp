/*
 * END_MAIN_TBL2.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 end_1000_scrn_data[];
extern const u8 end_100_scrn_data[];
extern const u8 end_1100_scrn_data[];
extern const u8 end_1600_scrn_data[];
extern const u8 end_1800_scrn_data[];
extern const u8 end_1900_scrn_data[];
extern const u8 end_2000_scrn_data[];
extern const u8 end_200_scrn_data[];
extern const u8 end_300_scrn_data[];
extern const u8 end_400_scrn_data[];
extern const u8 end_500_scrn_data[];
extern const u8 end_600_scrn_data[];
extern const u8 end_700_scrn_data[];
extern const u8 end_800_scrn_data[];
extern const u8 end_900_scrn_data[];
extern const u8 end_ake_scrn_data[];
extern const u8 end_b00_scrn_data[];
extern const u8 end_c00_scrn_data[];
extern const u8 end_d00_scrn_data[];
extern const u8 end_e00_scrn_data[];

const s16 op_bg0_0015_tbl[6] = {
    45, 46, 45, 46, 47, 41,
};

/* Stored after op_bg0_0015_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of op_bg0_0015_tbl. */
const s16 op_bg0_0015_tbl_tail[24] = {
    5, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 14,
    16, 17, 18, 19, 20, 5, 5, 5,
};

const s16 end_scno_tbl[24] = {
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

const u32 end_cg_src_tbl[80] = {
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
    0x10054,
    0x7F7F00,
    0xC00FF,
    0x7F00000C,
    0x17F7F00,
    0xC01FF,
    0x7F00000C,
    0x27F7F00,
    0xC02FF,
    0x7F00000C,
    0x37F7F00,
    0xC03FF,
    0x7F00000C,
    0xFFFFFFFF,
    0x2005E,
    0x7F7F00,
    0x1C00FF,
    0x7F00001C,
    0x17F7F00,
    0x1C01FF,
    0x7F00001C,
    0x27F7F00,
    0x1C02FF,
    0x7F00001C,
    0x37F7F00,
    0x1C03FF,
    0x7F00001C,
    0xFFFFFFFF,
    0x30068,
    0x7F7F00,
    0x2C00FF,
    0x7F00002C,
    0x17F7F00,
    0x2C01FF,
    0x7F00002C,
    0x27F7F00,
    0x2C02FF,
    0x7F00002C,
    0x37F7F00,
    0x2C03FF,
    0x7F00002C,
    0xFFFFFFFF,
    0x40072,
    0x7F7F00,
    0x3C00FF,
    0x7F00003C,
    0x17F7F00,
    0x3C01FF,
    0x7F00003C,
    0x27F7F00,
    0x3C02FF,
    0x7F00003C,
    0x37F7F00,
    0x3C03FF,
    0x7F00003C,
    0xFFFFFFFF,
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

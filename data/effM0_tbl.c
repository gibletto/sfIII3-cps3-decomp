/*
 * EFFM0_TBL.C  player 17 super art palette data
 *
 * effM0_tbl_top holds the colour data of the super art palette effect; its step entries from
 * index 4 on point at effM0_tbl_top_0. EFFL8.C reaches it through effL8_data_tbl.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effM0_tbl_top_0[];

void (*const effM0_tbl_top[8])() = {
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x00040000,
    (void (*)())((const u8*)effM0_tbl_top_0),
    (void (*)())0x00040001,
    (void (*)())((const u8*)effM0_tbl_top_0),
};

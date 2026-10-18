/*
 * EFFM0_TBL.C  game tables
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

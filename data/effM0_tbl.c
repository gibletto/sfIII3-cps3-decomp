/*
 * EFFM0_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 effM0_tbl_top_0[];

extern void animal_0000();
extern void animal_0001();
extern void animal_0002();
extern void animal_0004();
extern void animal_0005();
extern const u8 effl7_data_tbl[];

void (*const effM0_tbl_top[15])() = {
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x03E003E0,
    (void (*)())0x00040000,
    (void (*)())((const u8*)effM0_tbl_top_0),
    (void (*)())0x00040001,
    (void (*)())((const u8*)effM0_tbl_top_0),
    animal_0000,
    animal_0001,
    animal_0002,
    animal_0001,
    animal_0004,
    animal_0005,
    animal_0000,
};

const s16 animal_0005_tbl[16] = {
    40, 50, 160, 70, 80, 100, 30, 200,
    340, 10, 110, 18, 40, 60, 30, 150,
};

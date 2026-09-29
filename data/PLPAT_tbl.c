/*
 * PLPAT_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Attack_00000();
extern void Attack_01000();
extern void Attack_02000();
extern void Attack_03000();
extern void Attack_04000();
extern void Attack_05000();
extern void Attack_06000();
extern void Attack_07000();
extern void Attack_08000();
extern void Attack_09000();
extern void Attack_10000();
extern void Attack_14000();
extern void Attack_15000();
extern void pl00_extra_attack();
extern void pl01_extra_attack();
extern void pl02_extra_attack();
extern void pl03_extra_attack();
extern void pl04_extra_attack();
extern void pl05_extra_attack();
extern void pl06_extra_attack();
extern void pl07_extra_attack();
extern void pl08_extra_attack();
extern void pl09_extra_attack();
extern void pl10_extra_attack();
extern void pl11_extra_attack();
extern void pl12_extra_attack();
extern void pl13_extra_attack();
extern void pl14_extra_attack();
extern void pl16_extra_attack();
extern void pl17_extra_attack();
extern void pl18_extra_attack();
extern void pl19_extra_attack();
extern void pl20_extra_attack();

void (*const plpat_lv_00[16])() = {
    Attack_00000,  Attack_01000,  Attack_02000,  Attack_03000,  /* 0 */
    Attack_04000,  Attack_05000,  Attack_06000,  Attack_07000,  /* 4 */
    Attack_08000,  Attack_09000,  Attack_10000,  Attack_00000,  /* 8 */
    Attack_00000,  Attack_00000,  Attack_14000,  Attack_15000,  /* 12 */
};

void (*const plxx_extra_attack_table[54])() = {
    pl00_extra_attack,
    pl01_extra_attack,
    pl02_extra_attack,
    pl03_extra_attack,
    pl04_extra_attack,
    pl05_extra_attack,
    pl06_extra_attack,
    pl07_extra_attack,
    pl08_extra_attack,
    pl09_extra_attack,
    pl10_extra_attack,
    pl11_extra_attack,
    pl12_extra_attack,
    pl13_extra_attack,
    pl14_extra_attack,
    pl14_extra_attack,
    pl16_extra_attack,
    pl17_extra_attack,
    pl18_extra_attack,
    pl19_extra_attack,
    pl20_extra_attack,
    0,
    0,
    0,
    (void (*)())0x0A0A0E0E,
    (void (*)())0x12121212,
    (void (*)())0x0B0B1010,
    (void (*)())0x15151515,
    (void (*)())0x0E0E1212,
    (void (*)())0x16161616,
    (void (*)())0xFFFFFFFF,
    (void (*)())0xFFFFFFFF,
    (void (*)())0x160A170B,
    (void (*)())0x180C180C,
    (void (*)())0x180C190D,
    (void (*)())0x1A0E1A0E,
    (void (*)())0x1A0E1B0F,
    (void (*)())0x1C101C10,
    (void (*)())0xFFFFFFFF,
    (void (*)())0xFFFFFFFF,
    (void (*)())0x10071209,
    (void (*)())0x140B140B,
    (void (*)())0x1108130A,
    (void (*)())0x150C150C,
    (void (*)())0x1209140B,
    (void (*)())0x160D160D,
    (void (*)())0x14141717,
    (void (*)())0x1A1A1A1A,
    (void (*)())0x16161818,
    (void (*)())0x1A1A1A1A,
    (void (*)())0x17171919,
    (void (*)())0x1A1A1A1A,
    (void (*)())0xFFFFFFFF,
    (void (*)())0xFFFFFFFF,
};

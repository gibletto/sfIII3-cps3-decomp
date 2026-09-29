/*
 * PLPAT09_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_JINNCHUUWATARI();
extern void Att_JINNCHUUWATARI_EX();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL09_EX_KISHINRIKI();
extern void Att_PL09_EX_TENGUIWA();
extern void Att_PL09_TOKUSHUKOUDOU();
extern void Att_SHOURYUUKEN();
extern void Att_SP_YAGYOUDAMA();

const u8 tenguiwa_stage_data[23][2] = {
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
    { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, 1 },
};

const u8 tenguiwa_stand_by[8][8] = {
    { 24, 25, 26, 27, 28, 29, 30, 30 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
    { 31, 32, 33, 34, 35, 34, 33, 31 },
};

const s16 tenguiwa_pos_hosei[4][6] = {
    { 8, 112, 2, 4, 64, 48 },
    { 48, 104, -2, 40, 52, 96 },
    { -48, 100, 2, -40, 56, 144 },
    { -8, 96, -2, 0, 24, 192 },
};

const s16 tenguiwa_pos_hosei2[8][6] = {
    { 72, 100, 2, 68, 80, 48 },
    { 32, 132, -2, 32, 56, 96 },
    { 8, 112, 2, 4, 76, 144 },
    { -32, 130, -2, -32, 52, 192 },
    { -64, 100, 2, -64, 78, 48 },
    { 16, 144, -2, 16, 96, 96 },
    { -8, 144, 2, -8, 96, 144 },
    { 0, 160, -2, 0, 104, 192 },
};

const s16 pl09_tk_table[14] = {
    0, 500, 600, 700, 800, 900, 1000, 1100,
    1200, 1300, 1400, 1500, 1600, 1700,
};

const s16 homing_hos[2][24][2] = {
    { { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 128 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 24, 86 }, { 28, 68 }, { 16, 62 }, { 16, 52 }, { 20, 72 }, { 20, 58 }, { 18, 82 }, { 18, 52 }, { 28, 45 }, { 25, 42 }, { 16, 52 }, { 16, 62 }, { 16, 62 }, { 24, 86 }, { 16, 62 }, { 16, 62 }, { 16, 62 }, { 16, 62 }, { 24, 86 }, { 20, 58 }, { 20, 72 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};

const s16 homing_kop[2][4] = {
    { 1, 14, 0, 2 },
    { 0, 14, 0, 2 },
};

void (*const pl09_exatt_table[18])() = {
    Att_HADOUKEN,               Att_SHOURYUUKEN,            Att_KUUCHUUNICHIRINSHOU,    Att_HADOUKEN,  /* 0 */
    Att_HADOUKEN,               Att_HADOUKEN,               Att_HADOUKEN,               Att_KUUCHUUJINNCHUUWATARI,  /* 4 */
    Att_JINNCHUUWATARI,         Att_JINNCHUUWATARI_EX,      Att_SP_YAGYOUDAMA,          Att_PL09_EX_TENGUIWA,  /* 8 */
    Att_PL09_EX_KISHINRIKI,     Att_DUMMY,                  Att_PL09_TOKUSHUKOUDOU,     Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,           Att_METAMOR_REBIRTH,  /* 16 */
};

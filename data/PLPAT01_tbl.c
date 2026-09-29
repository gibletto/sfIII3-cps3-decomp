/*
 * PLPAT01_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_HOMING_JUMP();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_NM_OKIAGARI();
extern void Att_PL01_DDT();
extern void Att_PL01_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SENPUUKYAKU2();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

const s16 pl01_ddt_dat[24][2] = {
    { 46, 11 }, { 32, 12 }, { 28, 13 }, { 16, 14 }, { 36, 15 }, { 16, 16 }, { 60, 17 }, { 20, 18 },
    { 24, 19 }, { 12, 20 }, { 16, 14 }, { 28, 13 }, { 28, 13 }, { 46, 11 }, { 28, 13 }, { 28, 0 },
    { 24, 21 }, { 18, 22 }, { 52, 23 }, { 18, 16 },
    { 38, 24 },
    { 16, 0 },
    { 16, 0 },
    { 16, 0 },
};

void (*const pl01_exatt_table[18])() = {
    Att_CHOUCHUURENGEKI,     Att_SHOURYUUKEN,         Att_HADOUKEN,            Att_HADOUKEN2,  /* 0 */
    Att_CHOUCHUURENGEKI,     Att_SENPUUKYAKU2,        Att_SENPUUKYAKU,         Att_NM_OKIAGARI,  /* 4 */
    Att_PL01_DDT,            Att_HOMING_JUMP,         Att_SLIDE_and_JUMP,      Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL01_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

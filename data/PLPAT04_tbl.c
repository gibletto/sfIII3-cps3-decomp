/*
 * PLPAT04_TBL.C  game tables
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
extern void Att_PL04_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl04_exatt_table[18])() = {
    Att_SENPUUKYAKU,         Att_SENPUUKYAKU,         Att_HADOUKEN,            Att_SHOURYUUREPPA,  /* 0 */
    Att_HADOUKEN2,           Att_CHOUCHUURENGEKI,     Att_CHOUCHUURENGEKI,     Att_SLIDE_and_JUMP,  /* 4 */
    Att_SLIDE_and_JUMP,      Att_HADOUKEN,            Att_NM_OKIAGARI,         Att_DUMMY,  /* 8 */
    Att_HOMING_JUMP,         Att_DUMMY,               Att_PL04_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

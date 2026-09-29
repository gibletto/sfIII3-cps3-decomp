/*
 * PLPAT11_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_KUUCHUUNICHIRINSHOU();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL11_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SHOURYUUKEN();
extern void Att_SHOURYUUREPPA();
extern void Att_SLIDE_and_JUMP();

void (*const pl11_exatt_table[18])() = {
    Att_HADOUKEN,             Att_SHOURYUUKEN,          Att_SENPUUKYAKU,          Att_SHOURYUUREPPA,  /* 0 */
    Att_SHOURYUUREPPA,        Att_SLIDE_and_JUMP,       Att_KUUCHUUNICHIRINSHOU,  Att_CHOUCHUURENGEKI,  /* 4 */
    Att_DUMMY,                Att_DUMMY,                Att_DUMMY,                Att_DUMMY,  /* 8 */
    Att_DUMMY,                Att_DUMMY,                Att_PL11_TOKUSHUKOUDOU,   Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,         Att_METAMOR_REBIRTH,  /* 16 */
};

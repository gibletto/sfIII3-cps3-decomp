/*
 * PLPAT17_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN2();
extern void Att_KUUCHUUJINNCHUUWATARI();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL17_AT1();
extern void Att_PL17_AT2();
extern void Att_PL17_TOKUSHUKOUDOU();

void (*const pl17_exatt_table[18])() = {
    Att_CHOUCHUURENGEKI,        Att_PL17_AT1,               Att_HADOUKEN2,              Att_PL17_AT2,  /* 0 */
    Att_KUUCHUUJINNCHUUWATARI,  Att_DUMMY,                  Att_DUMMY,                  Att_DUMMY,  /* 4 */
    Att_DUMMY,                  Att_DUMMY,                  Att_DUMMY,                  Att_DUMMY,  /* 8 */
    Att_DUMMY,                  Att_DUMMY,                  Att_PL17_TOKUSHUKOUDOU,     Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,           Att_METAMOR_REBIRTH,  /* 16 */
};

/*
 * PLPAT16_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL16_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

void (*const pl16_exatt_table[18])() = {
    Att_SENPUUKYAKU,         Att_HADOUKEN2,           Att_HADOUKEN,            Att_HADOUKEN,  /* 0 */
    Att_SLIDE_and_JUMP,      Att_SLIDE_and_JUMP,      Att_SLIDE_and_JUMP,      Att_DUMMY,  /* 4 */
    Att_DUMMY,               Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL16_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

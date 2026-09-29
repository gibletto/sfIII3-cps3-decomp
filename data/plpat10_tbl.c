/*
 * PLPAT10_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL10_MACH_SLIDE2();
extern void Att_PL10_TOKUSHUKOUDOU();
extern void Att_SLIDE_and_JUMP();
extern void Att_TENSHINSENKYUUTAI();

void (*const pl10_exatt_table[18])() = {
    Att_HADOUKEN,            Att_TENSHINSENKYUUTAI,   Att_SLIDE_and_JUMP,      Att_HADOUKEN,  /* 0 */
    Att_SLIDE_and_JUMP,      Att_TENSHINSENKYUUTAI,   Att_HADOUKEN,            Att_PL10_MACH_SLIDE2,  /* 4 */
    Att_DUMMY,               Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL10_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

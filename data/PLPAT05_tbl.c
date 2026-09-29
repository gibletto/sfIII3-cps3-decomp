/*
 * PLPAT05_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_JINNCHUUWATARI();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL05_TOKUSHUKOUDOU();
extern void Att_SENPUUKYAKU();
extern void Att_SLIDE_and_JUMP();

void (*const pl05_exatt_table[18])() = {
    Att_CHOUCHUURENGEKI,     Att_HADOUKEN,            Att_HADOUKEN,            Att_HADOUKEN,  /* 0 */
    Att_HADOUKEN,            Att_SENPUUKYAKU,         Att_HADOUKEN,            Att_HADOUKEN,  /* 4 */
    Att_HADOUKEN,            Att_JINNCHUUWATARI,      Att_SLIDE_and_JUMP,      Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL05_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

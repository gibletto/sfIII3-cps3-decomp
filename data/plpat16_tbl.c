/*
 * PLPAT16_TBL.C  Chun-Li's special attack table
 *
 * pl16_exatt_table lists the routines of attack numbers 16 and up of character 16 (Chun-Li).
 * Read by pl16_extra_attack in PLPAT16.C.
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

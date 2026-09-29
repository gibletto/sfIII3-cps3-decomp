/*
 * PLPAT06_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HADOUKEN2();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL06_HASHIRI_NAGE();
extern void Att_PL06_TOKUSHUKOUDOU();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

void (*const pl06_exatt_table[18])() = {
    Att_HADOUKEN2,           Att_HADOUKEN2,           Att_CHOUCHUURENGEKI,     Att_HADOUKEN2,  /* 0 */
    Att_SHOURYUUKEN,         Att_SLIDE_and_JUMP,      Att_HADOUKEN2,           Att_SHOURYUUKEN,  /* 4 */
    Att_PL06_HASHIRI_NAGE,   Att_PL06_HASHIRI_NAGE,   Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL06_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

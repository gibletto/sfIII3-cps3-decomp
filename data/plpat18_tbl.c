/*
 * PLPAT18_TBL.C  Q's special attack table
 *
 * pl18_exatt_table lists the routines of attack numbers 16 and up of character 18 (Q). Read
 * by pl18_extra_attack in PLPAT18.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HADOUKEN2();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL18_NINGENBAKUDAN();
extern void Att_PL18_TOKUSHUKOUDOU();
extern void Att_SLIDE_and_JUMP();

void (*const pl18_exatt_table[18])() = {
    Att_SLIDE_and_JUMP,      Att_SLIDE_and_JUMP,      Att_HADOUKEN2,           Att_HADOUKEN2,  /* 0 */
    Att_SLIDE_and_JUMP,      Att_HADOUKEN2,           Att_HADOUKEN,            Att_PL18_NINGENBAKUDAN,  /* 4 */
    Att_HADOUKEN,            Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL18_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

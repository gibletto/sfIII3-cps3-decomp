/*
 * PLPAT20_TBL.C  Remy's special attack table
 *
 * pl20_exatt_table lists the routines of attack numbers 16 and up of character 20 (Remy).
 * Read by pl20_extra_attack in PLPAT20.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_DUMMY();
extern void Att_HADOUKEN();
extern void Att_HOMING_JUMP();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL20_AT1();
extern void Att_PL20_AT2();
extern void Att_PL20_AT3();
extern void Att_PL20_TOKUSHUKOUDOU();

void (*const pl20_exatt_table[18])() = {
    Att_HADOUKEN,            Att_PL20_AT1,            Att_PL20_AT2,            Att_HOMING_JUMP,  /* 0 */
    Att_HADOUKEN,            Att_PL20_AT3,            Att_DUMMY,               Att_DUMMY,  /* 4 */
    Att_DUMMY,               Att_DUMMY,               Att_DUMMY,               Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL20_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

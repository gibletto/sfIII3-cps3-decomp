/*
 * PLPAT07_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Att_CHOUCHUURENGEKI();
extern void Att_DUMMY();
extern void Att_HOMING_JUMP();
extern void Att_METAMOR_REBIRTH();
extern void Att_METAMOR_WAIT();
extern void Att_PL07_AT1();
extern void Att_PL07_AT2();
extern void Att_PL07_AT3();
extern void Att_PL07_SA2();
extern void Att_PL07_SA3();
extern void Att_PL07_TOKUSHUKOUDOU();
extern void Att_SHOURYUUKEN();
extern void Att_SLIDE_and_JUMP();

void (*const pl07_exatt_table[18])() = {
    Att_SHOURYUUKEN,         Att_PL07_AT1,            Att_CHOUCHUURENGEKI,     Att_SLIDE_and_JUMP,  /* 0 */
    Att_CHOUCHUURENGEKI,     Att_PL07_SA2,            Att_PL07_AT2,            Att_PL07_AT3,  /* 4 */
    Att_PL07_SA3,            Att_SLIDE_and_JUMP,      Att_HOMING_JUMP,         Att_DUMMY,  /* 8 */
    Att_DUMMY,               Att_DUMMY,               Att_PL07_TOKUSHUKOUDOU,  Att_DUMMY,  /* 12 */
    Att_METAMOR_WAIT,        Att_METAMOR_REBIRTH,  /* 16 */
};

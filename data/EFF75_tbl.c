/*
 * EFF75_TBL.C  order-driven select object states
 *
 * EFF75_Jmp_Tbl is the jump table of the object's order states: wait, slide in, change
 * animation, appear and die. Read by EFF75_ORDER.C, the effect 75 move routine and order
 * states.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF75_CHAR_CHANGE();
extern void EFF75_DIE();
extern void EFF75_SLIDE_IN();
extern void EFF75_SUDDENLY();
extern void EFF75_WAIT();

void (*const EFF75_Jmp_Tbl[5])() = {
    EFF75_WAIT,
    EFF75_SLIDE_IN,
    EFF75_CHAR_CHANGE,
    EFF75_SUDDENLY,
    EFF75_DIE,
};

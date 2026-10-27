/*
 * EFF42_TBL.C  order-driven select object states
 *
 * EFF42_Jmp_Tbl is the jump table of the object's order states: appear, slide in, slide out,
 * kill and move. Read by EFF42.C, the order-driven select object.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF42_KILL();
extern void EFF42_MOVE();
extern void EFF42_SLIDE_IN();
extern void EFF42_SLIDE_OUT();
extern void EFF42_SUDDENLY();

void (*const EFF42_Jmp_Tbl[5])() = {
    EFF42_SUDDENLY,
    EFF42_SLIDE_IN,
    EFF42_SLIDE_OUT,
    EFF42_MOVE,
    EFF42_KILL,
};

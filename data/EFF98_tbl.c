/*
 * EFF98_TBL.C  super-art plate states
 *
 * EFF98_Jmp_Tbl is the jump table of the plate's order states: wait, slide in, slide out,
 * appear and kill. Read by EFF98.C, the super-art plate on the player select screens.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF98_KILL();
extern void EFF98_SLIDE_IN();
extern void EFF98_SLIDE_OUT();
extern void EFF98_SUDDENLY();
extern void EFF98_WAIT();

void (*const EFF98_Jmp_Tbl[5])() = {
    EFF98_WAIT,
    EFF98_SLIDE_IN,
    EFF98_SLIDE_OUT,
    EFF98_SUDDENLY,
    EFF98_KILL,
};

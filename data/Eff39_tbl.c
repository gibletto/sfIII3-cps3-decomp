/*
 * EFF39_TBL.C  state routines of effect 39
 *
 * EFF39_Jmp_Tbl is the six state routines (wait, slide in, slide out, appear at once, move,
 * kill) of the character name object on the select screens. Read by EFF39.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF39_KILL();
extern void EFF39_MOVE();
extern void EFF39_SLIDE_IN();
extern void EFF39_SLIDE_OUT();
extern void EFF39_SUDDENLY();
extern void EFF39_WAIT();

void (*const EFF39_Jmp_Tbl[6])() = {
    EFF39_WAIT,
    EFF39_SLIDE_IN,
    EFF39_SLIDE_OUT,
    EFF39_SUDDENLY,
    EFF39_MOVE,
    EFF39_KILL,
};


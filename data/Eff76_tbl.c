/*
 * EFF76_TBL.C  state routines of effect 76
 *
 * EFF76_Jmp_Tbl is the state routines of the screen objects of the select, versus, win and
 * ranking screens (wait, wait for break-in, slide in, appear at once, before, shift, die).
 * Read by EFF76.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF76_BEFORE();
extern void EFF76_DIE();
extern void EFF76_SHIFT();
extern void EFF76_SLIDE_IN();
extern void EFF76_SLIDE_OUT();
extern void EFF76_SUDDENLY();
extern void EFF76_WAIT();
extern void EFF76_WAIT_BREAK_INTO();

void (*const EFF76_Jmp_Tbl[8])() = {
    EFF76_WAIT,
    EFF76_SLIDE_IN,
    EFF76_SLIDE_OUT,
    EFF76_SUDDENLY,
    EFF76_DIE,
    EFF76_SHIFT,
    EFF76_WAIT_BREAK_INTO,
    EFF76_BEFORE,
};


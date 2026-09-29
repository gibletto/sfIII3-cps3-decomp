/*
 * EFF76_TBL.C  game tables
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


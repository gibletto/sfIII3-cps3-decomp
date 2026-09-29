/*
 * EFF98_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF98_DIE();
extern void EFF98_SLIDE_IN();
extern void EFF98_SLIDE_OUT();
extern void EFF98_SUDDENLY();
extern void EFF98_WAIT();

void (*const EFF98_Jmp_Tbl[5])() = {
    EFF98_WAIT,
    EFF98_SLIDE_IN,
    EFF98_SLIDE_OUT,
    EFF98_SUDDENLY,
    EFF98_DIE,
};

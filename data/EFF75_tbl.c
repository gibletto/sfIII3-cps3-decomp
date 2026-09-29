/*
 * EFF75_TBL.C  game tables
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

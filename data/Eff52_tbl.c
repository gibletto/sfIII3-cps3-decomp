/*
 * EFF52_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF52_KILL();
extern void EFF52_SLIDE_IN();
extern void EFF52_SLIDE_OUT();
extern void EFF52_SUDDENLY();
extern void EFF52_WAIT();

void (*const EFF52_Jmp_Tbl[5])() = {
    EFF52_WAIT,
    EFF52_SLIDE_IN,
    EFF52_SLIDE_OUT,
    EFF52_SUDDENLY,
    EFF52_KILL,
};

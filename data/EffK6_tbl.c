/*
 * EFFK6_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFFK6_KILL();
extern void EFFK6_MOVE();
extern void EFFK6_SLIDE_IN();
extern void EFFK6_SLIDE_OUT();
extern void EFFK6_SUDDENLY();
extern void EFFK6_WAIT();

void (*const EFFK6_Jmp_Tbl[6])() = {
    EFFK6_WAIT,
    EFFK6_SLIDE_IN,
    EFFK6_SLIDE_OUT,
    EFFK6_SUDDENLY,
    EFFK6_MOVE,
    EFFK6_KILL,
};


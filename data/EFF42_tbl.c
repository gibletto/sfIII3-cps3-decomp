/*
 * EFF42_TBL.C  game tables
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

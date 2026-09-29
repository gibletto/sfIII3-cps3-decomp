/*
 * EFF69_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF69_KILL();
extern void EFF69_SLIDE_IN();
extern void EFF69_SLIDE_OUT();
extern void EFF69_SUDDENLY();
extern void EFF69_WAIT();

void (*const EFF69_Jmp_Tbl[5])() = {
    EFF69_WAIT,
    EFF69_SLIDE_IN,
    EFF69_SLIDE_OUT,
    EFF69_SUDDENLY,
    EFF69_KILL,
};

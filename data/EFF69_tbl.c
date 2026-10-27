/*
 * EFF69_TBL.C  sliding select object states
 *
 * EFF69_Jmp_Tbl is the jump table of the object's order states: wait, slide in, slide out,
 * appear and kill. Read by EFF69.C, the select-screen object sliding in from the right.
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

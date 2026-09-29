/*
 * EFF38_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void EFF38_KILL();
extern void EFF38_MOVE();
extern void EFF38_SHIFT();
extern void EFF38_SLIDE_IN();
extern void EFF38_SLIDE_OUT();
extern void EFF38_SUDDENLY();
extern void EFF38_WAIT();

const s16 EFF38_Base_XY[2][2][2] = {
    { { -64, 16 }, { -128, 32 } },
    { { 64, 16 }, { 128, -32 } },
};

void (*const EFF38_Jmp_Tbl[7])() = {
    EFF38_WAIT,
    EFF38_SLIDE_IN,
    EFF38_SLIDE_OUT,
    EFF38_SUDDENLY,
    EFF38_SHIFT,
    EFF38_MOVE,
    EFF38_KILL,
};


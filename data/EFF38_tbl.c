/*
 * EFF38_TBL.C  order-driven select object tables
 *
 * EFF38_Base_XY gives the base x, y of the object by player and play type, to which
 * EFF38_Correct_Data (SEL_DATA.C) is added. EFF38_Jmp_Tbl is the jump table of its order
 * states (wait, appear, slide in and out, kill, shift, move). Read by EFF38.C, the
 * order-driven select and VS screen object.
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

/* Indexed by player and play type: base x, y of effect 38, to which EFF38_Correct_Data is added. */
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


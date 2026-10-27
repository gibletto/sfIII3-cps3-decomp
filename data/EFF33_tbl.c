/*
 * EFF33_TBL.C  appearance companion result animations
 *
 * WinLoseID gives, by master and winner, whether the companion plays its win or lose
 * animation. Read by EFF33.C, the appearance companion that reacts to the result.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 WinLoseID[2][2] = {
    { 1, 0 }, { 0, 1 },
};

/*
 * DEMO_TBL_B.C  demonstration play characters
 *
 * Demo_PL_Play_Data gives the two characters of each demonstration fight. Read by
 * DEMO02_CODE.C, the attract-mode demonstration play.
 */

#include "types.h"
#include "structs.h"
#include "fighter.h"

#pragma section TBL

const s8 Demo_PL_Play_Data[4][2] = {
    { PL_CHUN, PL_BIKEI }, { PL_KEN, PL_NO12 }, { PL_RYU, PL_KARATE }, { PL_SEAN, PL_ELENA },
};

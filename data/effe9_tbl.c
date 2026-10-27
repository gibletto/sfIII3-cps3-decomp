/*
 * EFFE9_TBL.C  opening frame bar table (effect E9)
 *
 * effE9_data rows hold the x, y, animation number and priority of the frame bar sprites of
 * the opening demo. Read by effect_E9_init in EFFE9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effE9_data[4][4] = {
    { 512, 0, 0, 21 },
    { 512, 208, 1, 19 },
    { 292, 136, 2, 21 },
    { 728, 136, 2, 21 },
};


/*
 * EFFH0_TBL.C  bonus-stage level display sprites
 *
 * bbbs_nando_small is the two-sprite connected display (level digit and label) for each facing
 * of the player, as CONN { x, y, colour, character } entries. Read by EFFH0.C, created by
 * BBBSCOM.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const CONN bbbs_nando_small[2][2] = {
    { { 176, -16, 0, 0xB332 }, { 132, -16, 0, 0xB331 } },
    { { -104, -16, 0, 0xB332 }, { -148, -16, 0, 0xB331 } },
};

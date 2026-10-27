/*
 * EFFJ2.C  bonus-stage level plate sprites
 *
 * bbbs_nando_large is the two-part connected sprite of the level plate, as CONN { x, y,
 * colour, character } entries. Read by EFFJ2_CODE.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const CONN bbbs_nando_large[2] = {
    { 92, 78, 0, 0xB30F },
    { -20, 78, 0, 0xB30E },
};

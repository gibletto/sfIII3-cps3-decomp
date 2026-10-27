/*
 * EFFJ9_TBL.C  shake offsets of the object beside the bonus-stage car
 *
 * c2quake_table gives the x shake offset for each frame of the car's shake. Read by EFFJ9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL



const s16 c2quake_table[19] = {
    0, 3, 3, 2, 2, 1, 1, 1,
    0, 0, 0, -1, -1, -1, -2, -2,
    -3, -3, 0,
};

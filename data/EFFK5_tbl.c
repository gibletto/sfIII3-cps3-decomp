/*
 * EFFK5_TBL.C  damage box interpolation tables for effect K5
 *
 * lookup_index picks, for each of the eight joints, whether it follows the body (0) or hand
 * (1) box table; k5_exc_check tells, per cg script command, how the look-ahead treats it (2
 * stop, 1 step over, 0 follow it). Read by EFFK5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 lookup_index[10] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    -1, -1,
};

const s8 k5_exc_check[125] = {
    1, 2, 0, 2, 2, 2, 2, 1,
    1, 1, 2, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 2, 1, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 2, 1, 2, 2,
    1, 0, 0, 1, 1, 2, 2, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 1, 1, 1, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 2, 2, 2,
    2, 2, 1, 1, 1, 1, 1, 1,
    2, 2, 1, 1, 1, 2, 2, 1,
    1, 1, 1, 1, 1, 2, 2, 2,
    1, 2, 2, 2, 1, 2, 2, 2,
    2, 2, 2, 2, 2,
};


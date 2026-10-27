/*
 * EFFC8_TBL.C  entrance prop throw speeds
 *
 * effc8_data_tbl gives the speeds and accelerations with which the prop is thrown clear at the
 * end of the entrance. Read by EFFC8.C, the entrance prop that follows the player's animation.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 effc8_data_tbl[4] = {
    196608, 512, 0, -6144,
};

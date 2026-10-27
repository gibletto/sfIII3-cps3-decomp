/*
 * EFFD7_TBL.C  thrown ball catch boxes
 *
 * effD7_hit_box holds the ball's box and the player's catch box tested when the player catches
 * the ball. Read by EFFD7.C, the ball thrown by a player.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effD7_hit_box[2][4] = {
    { -9, 17, -6, 12 },
    { -4, 10, 114, 9 },
};

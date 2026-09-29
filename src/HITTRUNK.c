/*
 * HITTRUNK.C  Body-hit damage routine by attack direction
 *
 * get_kind_of_trunk_dm returns the body-hit damage routine for an attack direction, mirroring the
 * direction first when the defender faces the other way. Used by HITCHECK.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "HITTRUNK.h"
/* provisional name */
s32 get_kind_of_trunk_dm(s16 dir, char rl)
{
    if (rl == 0) {
        dir = dir16_rl_conv[dir];
    }
    return dir16_trdm[dir];
}

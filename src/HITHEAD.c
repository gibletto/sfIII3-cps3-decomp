/*
 * HITHEAD.C  Head-hit damage routine by attack direction
 *
 * get_kind_of_head_dm returns the head-hit damage routine for an attack direction, mirroring the
 * direction first when the defender faces the other way. Used by HITCHECK.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "HITHEAD.h"
s32 get_kind_of_head_dm(s16 dir, char rl)
{
    if (rl == 0) {
        dir = dir16_rl_conv[dir];
    }
    return dir16_hddm[dir];
}

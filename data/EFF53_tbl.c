/*
 * EFF53_TBL.C  bg040 blinking object timing
 *
 * eff53_vanish_time holds the random times the object stays hidden before it blinks. Read by
 * EFF53.C, the bg040 blinking stage object.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff53_vanish_time[8] = {
    480, 600, 900, 1440, 480, 1080, 1500, 600,
};

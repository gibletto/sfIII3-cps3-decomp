/*
 * EFF29_TBL.C  static stage objects and the bg100 object's timing
 *
 * scr_obj_num28 starts with the number of effect 28 objects, followed by their settings
 * (position, priority, animation, family, colour, sync), reached through scr_obj_data28; read
 * by EFF28.C, the static stage objects. eff29_vanish_time holds the random hidden times of the
 * bg100 object, read by EFF29.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num28[10] = {
    1, 0, 1, 128, 448, 72, 92, 9,
    0, 1,
};

const s16 eff29_vanish_time[8] = {
    480, 600, 300, 240, 200, 340, 500, 360,
};

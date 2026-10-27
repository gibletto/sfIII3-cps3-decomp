/*
 * EFF18_TBL.C  reacting stage object placement
 *
 * scr_obj_num18 gives the number of effect 18 objects for each stage setting, and
 * scr_obj_data18_0 their settings, reached through scr_obj_data18. Read by EFF18.C, which
 * holds effects 17 and 18.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num18[1][4] = {
    { 1, 1, 1, 1 },
};

const s16 scr_obj_data18_0[2] = {
    0, 0,
};


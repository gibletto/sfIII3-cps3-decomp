/*
 * EFF54_TBL.C  blinking object part placement
 *
 * eff29_data_tbl gives the position, priority and animation of each of the two parts of the
 * blinking stage object. Read by EFF54.C, the parts of the blinking stage object.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff29_data_tbl[8] = {
    687, 128, 82, 7, 415, 152, 79, 8,
};

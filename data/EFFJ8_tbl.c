/*
 * EFFJ8_TBL.C  dragonfly heights and hover times
 *
 * effj8_y_tbl is the eight random heights a dragonfly enters at, and effj8_timer_tbl the eight
 * random hovering times. Read by EFFJ8.C, the dragonflies of the stage background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 effj8_timer_tbl[8] = {
    60, 120, 180, 90, 150, 30, 220, 160,
};

const s16 effj8_y_tbl[8] = {
    128, 80, 96, 160, 176, 112, 144, 168,
};

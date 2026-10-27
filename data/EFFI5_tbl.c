/*
 * EFFI5_TBL.C  fade-in palette steps for effect I5
 *
 * effI5_fade_tbl is the 16 palette steps the ending object fades in through before its own
 * palette is restored. Read by EFFI5.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 effI5_fade_tbl[16] = {
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30,
    31,
};


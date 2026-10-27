/*
 * EFFM3_TBL.C  zoom values of the grade letter
 *
 * M3_bahn_data gives the zoom speed multiplier and divisor, the delay before the letter
 * appears, the BG quake value set when the first letter lands, and the zoom speed change. Read
 * by EFFM3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 M3_bahn_data[5] = {
    16, 10, 78, 0, -512,
};



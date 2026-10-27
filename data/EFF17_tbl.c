/*
 * EFF17_TBL.C  zoom-in piece placement
 *
 * eff17_data_tbl gives the position, priority and timing of each of the nine effect 17 pieces.
 * Read by EFF18.C, which holds effects 17 and 18.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff17_data_tbl[9][5] = {
    { 396, 144, 28, 1, 0 },
    { 422, 144, 27, 2, 3 },
    { 451, 144, 26, 3, 6 },
    { 478, 144, 25, 4, 9 },
    { 505, 144, 24, 5, 12 },
    { 543, 144, 23, 6, 15 },
    { 569, 144, 22, 7, 18 },
    { 599, 144, 21, 8, 21 },
    { 629, 144, 20, 9, 24 },
};

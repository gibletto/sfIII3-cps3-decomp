/*
 * END_4_TBL.C  Dudley's ending scene tables (ending 4)
 *
 * timer_4_tbl is the length in frames of each of the five scenes of the ending and end_4_pos
 * the BG x and y of each scene. Read by END_4.C; the cell sets are in END_3_TBL_B.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 timer_4_tbl[5] = {
    960, 1140, 1800, 600, 780,
};

const s16 end_4_pos[5][2] = {
    { 576, 768 },
    { 512, 256 },
    { 512, 768 },
    { 512, 512 },
    { 512, 256 },
};


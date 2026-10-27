/*
 * EFF58_TBL.C  palette step tables
 *
 * eff56_color_tbl gives the eight palette numbers of each cycle and eff56_timer_tbl the time
 * of each step. Read by EFF56.C, the palette steps.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u8 eff56_color_tbl[2][8] = {
    { 160, 161, 162, 163, 164, 163, 162, 161 },
    { 165, 166, 167, 168, 169, 168, 167, 166 },
};

const u8 eff56_timer_tbl[2][8] = {
    { 4, 3, 2, 3, 4, 3, 2, 3 },
    { 2, 1, 1, 1, 2, 1, 1, 1 },
};

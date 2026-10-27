/*
 * BG_SUB_TBL.C  background test stage list
 *
 * bg_test_stage_tbl is the stage and area of each entry the debug background test steps
 * through. Read by TATE00.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s8 bg_test_stage_tbl[14][2] = {
    { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 }, { 6, 0 }, { 7, 0 },
    { 8, 0 }, { 9, 9 }, { 13, 0 }, { 20, 0 }, { 21, 0 }, { 0, 0 },
};

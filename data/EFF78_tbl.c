/*
 * EFF78_TBL.C  bg000 crow tables
 *
 * eff78_data_tbl gives the perch position of each of the two crows, and crow_char_tbl the
 * take-off pattern and the x, y distance to fly for each take-off direction. Read by EFF78.C,
 * the crows.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff78_data_tbl[2][2] = {
    { 416, 71 }, { 912, 64 },
};

/*
 * One row per take-off direction: take-off pattern (the flight pattern is the next one),
 * and the x and y distance to fly.
 */
const s16 crow_char_tbl[3][3] = {
    { 8, 0, 64 },
    { 18, -16, 64 },
    { 13, 16, 64 },
};


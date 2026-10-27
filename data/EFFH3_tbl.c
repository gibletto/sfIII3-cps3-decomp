/*
 * EFFH3_TBL.C  ending picture placement
 *
 * effH3_data_tbl gives the five still pictures { x, y, pattern }. Read by EFFH3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 effH3_data_tbl[5][3] = {
    { 512, 0, 0 },
    { 256, 136, 2 },
    { 768, 136, 2 },
    { 256, 280, 2 },
    { 768, 280, 2 },
};


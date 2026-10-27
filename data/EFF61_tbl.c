/*
 * EFF61_TBL.C  alternate background part patterns
 *
 * eff61_data_tbl has a row per part type of the alternate background; the pattern number in
 * its last column is set when the part slides. Read by EFF62.C, which holds effects 61 and 62.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff61_data_tbl[9][4] = {
    { 0, 0, 0, 0 },
    { 48, 0, 24, 0 },
    { 15, 0, 6, 0 },
    { 48, 0, 24, 0 },
    { 15, 0, 9, 0 },
    { 9, 0, 20, 0 },
    { 13, 0, 10, 0 },
    { 8, 0, 11, 0 },
    { 12, 0, 18, 0 },
};

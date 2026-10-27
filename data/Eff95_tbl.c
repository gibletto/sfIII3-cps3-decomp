/*
 * EFF95_TBL.C  continue screen character poses
 *
 * eff95_data_tbl gives, for each continue count, four poses the character picks from at
 * random. Read by EFF95.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff95_data_tbl[10][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 1, 1 },
    { 2, 2, 3, 3 },
    { 4, 4, 5, 5 },
    { 6, 6, 6, 7 },
    { 7, 7, 8, 8 },
    { 8, 9, 9, 9 },
    { 9, 9, 9, 9 },
    { 9, 9, 9, 9 },
    { 9, 9, 9, 9 },
};

/*
 * POW_DATA.C  score award table
 *
 * Score_Data is the list of score amounts a player can be awarded (0, 100, 200, ... per
 * entry), indexed by score kind. Read by POW_POW.C, which adds them to the players' scores.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s32 Score_Data[21] = {
    0, 100, 200, 300, 400, 500, 1000, 1500,
    2000, 2500, 3000, 4000, 5000, 6000, 7000, 8000,
    9000, 10000, 3500, 12000, 14000,
};

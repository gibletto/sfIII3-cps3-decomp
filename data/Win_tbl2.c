/*
 * WIN_TBL2.C  per-character win screen and stage tables
 *
 * PL_Color_Data is the win screen background type and Victory_Color_Data the win screen
 * colour, both per character, read by WIN_2.C and EFF76.C; Random_Stage_Data is the list of
 * stages Setup_Battle_Country picks from at random, read by SEL_PL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u8 PL_Color_Data[21] = {
    0, 10, 0, 0, 10, 8, 0, 9,
    9, 10, 0, 10, 0, 0, 0, 0,
    9, 9, 0, 8, 0,
};

const u8 Victory_Color_Data[21] = {
    0, 53, 0, 0, 53, 49, 0, 51,
    51, 53, 0, 53, 0, 0, 0, 0,
    51, 51, 0, 49, 0,
};

const u8 Random_Stage_Data[18] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 16, 17,
    19, 20,
};

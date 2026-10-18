/*
 * DEMO02.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const u8 Arts_Rnd_Demo_Data[8] = {
    0, 0, 0, 1, 1, 1, 2, 2,
};

const s8 Demo_Stage_Play_Data[4][2] = {
    { 16, 20 }, { 11, 19 }, { 2, 17 }, { 12, 8 },
};

const s8 Demo_PL_Data[4] = {
    0, 1, 0, 1,
};

/* Stored after Demo_PL_Data. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Demo_PL_Data. */

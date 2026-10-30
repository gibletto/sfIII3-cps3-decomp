/*
 * DEMO02.C  demonstration play settings
 *
 * Arts_Rnd_Demo_Data gives the super art picked at random for each demo player,
 * Demo_Stage_Play_Data the two stages of each demo, and Demo_PL_Data which side is driven by
 * the demo input in each select-screen demo. Read by DEMO02_CODE.C, the attract-mode
 * demonstration play.
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

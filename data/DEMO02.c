/*
 * DEMO02.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Ranking_00();
extern void Ranking_00_1st();
extern void Ranking_00_2nd();
extern void Ranking_00_3rd();
extern void Ranking_00_4th();
extern void Ranking_00_5th();
extern void Ranking_00_Last();
extern void Ranking_01();
extern void Ranking_01_1st();
extern void Ranking_01_2nd();
extern void Ranking_01_4th();
extern void Ranking_01_5th();

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

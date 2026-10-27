/*
 * EFF92.C  win mark redraw sequence
 *
 * Rewrite_Mark_Data is the sequence of mark kinds and times drawn when a win mark is earned:
 * 0x8000 stands for the mark earned, and a time of -1 ends the sequence. Read by EFF92_CODE.C,
 * the win marks.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 Rewrite_Mark_Data[26] = {
    0x8000, 2, 8, 2, 0x8000, 2, 8, 2,
    0x8000, 2, 8, 2, 0x8000, 2, 8, 2,
    0x8000, 2, 8, 2, 0x8000, 2, 8, 3,
    0x8000, -1,
};

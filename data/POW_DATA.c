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
    0, 0x64, 0xC8, 0x12C, 0x190, 0x1F4, 0x3E8, 0x5DC,
    0x7D0, 0x9C4, 0xBB8, 0xFA0, 0x1388, 0x1770, 0x1B58, 0x1F40,
    0x2328, 0x2710, 0xDAC, 0x2EE0, 0x36B0,
};

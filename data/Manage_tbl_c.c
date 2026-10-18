/*
 * MANAGE_TBL_C.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const u32 Ball_Perfect_PTS[2][5] = {
    { 0x4E20, 0x7530, 0xC350, 0x13880, 0x1D4C0 },
    { 0x2710, 0x4E20, 0x9C40, 0x13880, 0x27100 },
};

const s8 Game_Manage_7_2_sub0_table[4] = "WIN";

const s8 Wins_msg[8] = "WINS";

const s8 Win_Record_Erase_msg[12] = "         ";

const s8 Loser_Erase_msg[7] = "      ";

const u8 Break_Into_Level_Data[9] = {
    3, 5, 7, 9, 1, 1, 1, 1,
    0,
};

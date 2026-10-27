/*
 * MANAGE_TBL_C.C  round and match management tables
 *
 * Ball_Perfect_PTS is the bonus for the two perfect results of the ball bonus stage by
 * Bonus_Stage_Level; Break_Into_Level_Data the super art finishes needed by round count for a
 * CPU break-in; Game_Manage_7_2_sub0_table, Wins_msg, Win_Record_Erase_msg and Loser_Erase_msg
 * are the WIN / WINS texts and the blanks that erase them. Read by MANAGE_2.C.
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

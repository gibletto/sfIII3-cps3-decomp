/*
 * MANAGE_TBL_C.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Continue_1st();
extern void Continue_2nd();
extern void Continue_3rd();
extern void Continue_4th();
extern void Continue_5th();
extern void FBI_Warning_1st();
extern void FBI_Warning_2nd();
extern void GameOver_1st();
extern void GameOver_2nd();
extern void GameOver_3rd();
extern void Game_Manage_10th();
extern void Game_Manage_11th();
extern void Game_Manage_12_0();
extern void Game_Manage_12_1();
extern void Game_Manage_12_2();
extern void Game_Manage_12_3();
extern void Game_Manage_12_4();
extern void Game_Manage_12_5();
extern void Game_Manage_12_7();
extern void Game_Manage_12_8();
extern void Game_Manage_12th();
extern void Game_Manage_1st();
extern void Game_Manage_2_0();
extern void Game_Manage_2_1();
extern void Game_Manage_2_2();
extern void Game_Manage_2_3();
extern void Game_Manage_2_4();
extern void Game_Manage_2nd();
extern void Game_Manage_3rd();
extern void Game_Manage_4th();
extern void Game_Manage_5_0();
extern void Game_Manage_5_1();
extern void Game_Manage_5_2();
extern void Game_Manage_5_3();
extern void Game_Manage_5_4();
extern void Game_Manage_5_5();
extern void Game_Manage_5_6();
extern void Game_Manage_5_7();
extern void Game_Manage_5th();
extern void Game_Manage_6th();
extern void Game_Manage_7_0();
extern void Game_Manage_7_1();
extern void Game_Manage_7_2();
extern void Game_Manage_7_3();
extern void Game_Manage_7_4();
extern void Game_Manage_7_5();
extern void Game_Manage_7_6();
extern void Game_Manage_7_7();
extern void Game_Manage_7_8();
extern void Game_Manage_7_9();
extern void Game_Manage_7th();
extern void Game_Manage_81_0();
extern void Game_Manage_81_1();
extern void Game_Manage_81_2();
extern void Game_Manage_81_3();
extern void Game_Manage_8_0();
extern void Game_Manage_8_1();
extern void Game_Manage_8_2();
extern void Game_Manage_8_3();
extern void Game_Manage_8th();
extern void Game_Manage_9th();
extern void Lose_2nd();
extern void Lose_3rd();
extern void Lose_4th();
extern void Lose_5th();
extern void Lose_6th();
extern void Win_1st();
extern void Win_2nd();
extern void Win_3rd();
extern void Win_4th();
extern void Win_5th();
extern void Win_6th();
extern void Lose_1st();

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

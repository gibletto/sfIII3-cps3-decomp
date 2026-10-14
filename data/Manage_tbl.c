/*
 * MANAGE_TBL.C  game tables
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

const RANK_DATA Rank_Default_Data[20] = {
    { { 28, 13, 22 }, 0x10, 0x186A0, 10, 0, 0xA, 0, 1 },
    { { 22, 24, 24 }, 0x11, 0x15F90, 9, 0, 9, 1, 0 },
    { { 23, 14, 24 }, 0x12, 0x13880, 8, 0, 8, 2, 1 },
    { { 24, 23, 30 }, 0x13, 0x11170, 7, 0, 7, 3, 0 },
    { { 34, 24, 20 }, 0x14, 0xEA60, 6, 0, 6, 4, 0 },
    { { 20, 10, 18 }, 0x10, 0x186A0, 10, 10, 0xA, 0, 1 },
    { { 21, 29, 1 }, 0x11, 0x15F90, 9, 9, 9, 1, 0 },
    { { 34, 30, 20 }, 0x12, 0x13880, 8, 8, 8, 2, 1 },
    { { 27, 10, 24 }, 0x13, 0x11170, 7, 7, 7, 3, 0 },
    { { 0, 0, 8 }, 0x14, 0xEA60, 6, 6, 6, 4, 0 },
    { { 18, 12, 17 }, 0x10, 0x186A0, 11, 0, 0xA, 0, 1 },
    { { 28, 14, 29 }, 5, 0x15F90, 9, 0, 9, 1, 0 },
    { { 23, 14, 24 }, 4, 0x13880, 8, 0, 8, 2, 1 },
    { { 24, 23, 30 }, 0xA, 0x11170, 7, 0, 7, 3, 0 },
    { { 34, 24, 20 }, 8, 0xEA60, 6, 0, 6, 4, 0 },
    { { 18, 23, 14 }, 0x14, 0x186A0, 11, 11, 0xA, 0, 1 },
    { { 21, 29, 1 }, 1, 0x15F90, 9, 9, 9, 1, 0 },
    { { 34, 30, 20 }, 4, 0x13880, 8, 8, 8, 2, 1 },
    { { 27, 10, 24 }, 0xA, 0x11170, 7, 7, 7, 3, 0 },
    { { 18, 23, 14 }, 8, 0xEA60, 6, 6, 6, 4, 0 },
};

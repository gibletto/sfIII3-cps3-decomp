/*
 * MANAGE_TBL_B.C  game tables
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

const s8 FBI_msg[4] = "FBI";
const s8 str_Q_SOUND[8] = "Q SOUND";
const s8 str_EYE_CATCH_Part1[16] = "EYE CATCH Part1";
const s8 str_EYE_CATCH_Part2[16] = "EYE CATCH Part2";
const s8 str_STREET_FIGHTER_III_2[20] = "STREET FIGHTER III\n";
const s8 str_199X_CAPCOM[12] = "199X CAPCOM";
const s8 str_PLAY_DEMO[16] = "   PLAY DEMO";
const s8 str_RANKING[12] = "   RANKING";
const s8 str_FBI[12] = "     FBI";
const s8 str_SELECT_PLAYER[16] = "SELECT PLAYER";
const s8 str_SELECT_PLAYER_2[16] = "SELECT PLAYER\n";
const s8 str_INSERT_COIN_2[12] = "INSERT COIN";
const s8 str_blank_3[12] = "           ";
const s8 str_PUSH_1_OR_2_START_BUTTON[28] = "PUSH 1 OR 2 START BUTTON";

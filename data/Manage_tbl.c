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

/* Initial values of jmp_tbl (FBI_Warning) in Manage.c. */
const u32 FBI_Warning_jmp_tbl_init[2] = {
    (u32)FBI_Warning_1st, (u32)FBI_Warning_2nd,
};

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

/* Initial values of Management_Jmp_Tbl (Game_Management), SC2_Jmp_Tbl (Game_Manage_2nd), SC5_Jmp_Tbl (Game_Manage_5th), SC7_Jmp_Tbl (Game_Manage_7th), SC8_Jmp_Tbl (Game_Manage_8th), SC81_Jmp_Tbl (Game_Manage_8_1) in Manage.c. */
const u32 Manage_local_init[43] = {
    (u32)Game_Manage_1st,
    (u32)Game_Manage_2nd,
    (u32)Game_Manage_3rd,
    (u32)Game_Manage_4th,
    (u32)Game_Manage_5th,
    (u32)Game_Manage_6th,
    (u32)Game_Manage_7th,
    (u32)Game_Manage_8th,
    (u32)Game_Manage_9th,
    (u32)Game_Manage_10th,
    (u32)Game_Manage_11th,
    (u32)Game_Manage_12th,
    (u32)Game_Manage_2_0,
    (u32)Game_Manage_2_1,
    (u32)Game_Manage_2_2,
    (u32)Game_Manage_2_3,
    (u32)Game_Manage_2_4,
    (u32)Game_Manage_5_0,
    (u32)Game_Manage_5_1,
    (u32)Game_Manage_5_2,
    (u32)Game_Manage_5_3,
    (u32)Game_Manage_5_4,
    (u32)Game_Manage_5_5,
    (u32)Game_Manage_5_6,
    (u32)Game_Manage_5_7,
    (u32)Game_Manage_7_0,
    (u32)Game_Manage_7_1,
    (u32)Game_Manage_7_2,
    (u32)Game_Manage_7_3,
    (u32)Game_Manage_7_4,
    (u32)Game_Manage_7_5,
    (u32)Game_Manage_7_6,
    (u32)Game_Manage_7_7,
    (u32)Game_Manage_7_8,
    (u32)Game_Manage_7_9,
    (u32)Game_Manage_8_0,
    (u32)Game_Manage_8_1,
    (u32)Game_Manage_8_2,
    (u32)Game_Manage_8_3,
    (u32)Game_Manage_81_0,
    (u32)Game_Manage_81_1,
    (u32)Game_Manage_81_2,
    (u32)Game_Manage_81_3,
};

const u32 Comp_Bonus_Data[21] = {
    0x7530, 0x9C40, 0xC350, 0xEA60, 0x11170, 0x13880, 0x15F90, 0x186A0,
    0x1ADB0, 0x1D4C0, 0x1FBD0, (u32)Game_Manage_12_0, (u32)Game_Manage_12_1, (u32)Game_Manage_12_7, (u32)Game_Manage_12_3, (u32)Game_Manage_12_4,
    (u32)Game_Manage_12_5, (u32)Game_Manage_12_1, (u32)Game_Manage_12_2, (u32)Game_Manage_12_8, (u32)Game_Manage_12_5,
};

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

/* Initial values of Scene_Tbl (Winner_Scene), Scene_Tbl (Loser_Scene) in Win.c. */
const u32 Win_local_init[12] = {
    (u32)Win_1st,
    (u32)Win_2nd,
    (u32)Win_3rd,
    (u32)Win_4th,
    (u32)Win_5th,
    (u32)Win_6th,
    (u32)Lose_1st,
    (u32)Lose_2nd,
    (u32)Lose_3rd,
    (u32)Lose_4th,
    (u32)Lose_5th,
    (u32)Lose_6th,
};

const u16 Entry_Msg_X_Data[12][2] = {
    { 6, 0xA }, { 0x1F, 0x28 },
    { 5, 0xA }, { 0x1E, 0x27 },
    { 2, 0xA }, { 0x1B, 0x24 },
    { 2, 9 }, { 27, 40 },
    { 7, 15 }, { 32, 41 },
    { 7, 15 }, { 32, 41 },
};

const s16 Score_X_Pos_Data[4][2] = {
    { 17, 23 }, { 37, 46 },
    { 6, 14 },
    { 31, 40 },
};

const s16 Loser_X_Pos_Data[6][2] = {
    { 5, 5 }, { 42, 55 },
    { 8, 15 },
    { 31, 40 },
    { 7, 15 },
    { 32, 41 },
};

const s16 EFFA3_Area_Data[2][2][4] = {
    { { 0, 9, 48, 10 }, { 8, 9, 62, 10 } },
    { { 0, 15, 48, 16 }, { 8, 15, 62, 16 } },
};

/* Initial values of Scene_Tbl (Game_Over), Scene_Tbl (Continue_Scene) in Win.c. */
const u32 Win_local_init_2[8] = {
    (u32)GameOver_1st,
    (u32)GameOver_2nd,
    (u32)GameOver_3rd,
    (u32)Continue_1st,
    (u32)Continue_2nd,
    (u32)Continue_3rd,
    (u32)Continue_4th,
    (u32)Continue_5th,
};

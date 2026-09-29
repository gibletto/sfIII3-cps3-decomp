/*
 * GAME_MAIN_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Game00();
extern void Game01();
extern void Game02();
extern void Game03();
extern void Game04();
extern void Game05();
extern void Game06();
extern void Game07();
extern void Game08();
extern void Game09();
extern void Game0_0();
extern void Game0_1();
extern void Game0_2();
extern void Game0_3();
extern void Game10();
extern void Game11();
extern void Game2_0();
extern void Game2_1();
extern void Game2_2();
extern void Game2_3();
extern void Game2_4();
extern void Game2_5();

const s8 Insert_Coin_Erase_msg[16] = "              ";

/* The initial values of Game_Jmp_Tbl (game_phase_dispatch) in Game_Main.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Game_Jmp_Tbl_init[12] = {
    (u32)Game00, (u32)Game01, (u32)Game02, (u32)Game03, (u32)Game04, (u32)Game05, (u32)Game06, (u32)Game07,
    (u32)Game08, (u32)Game09, (u32)Game10, (u32)Game11,
};

const GAME00_JMP_TBL Game00_Jmp_Data[1] = {
    { { Game0_0, Game0_1, Game0_2, Game0_3, Game0_2, Game0_3 } },
};

const s8 Game01_Erase_msg[20] = "                   ";

/* The initial values of Game02_Jmp_Tbl (Game02) in Game_Main.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Game02_Jmp_Tbl_init[6] = {
    (u32)Game2_0,
    (u32)Game2_1,
    (u32)Game2_2,
    (u32)Game2_3,
    (u32)Game2_4,
    (u32)Game2_5,
};

/*
 * BG100_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void bg1000_init00();
extern void bg1001_init00();
extern void bg1100_init00();
extern void bg1100_move();
extern void bg1101_init00();
extern void bg1101_move();
extern void bg1201_init00();
extern void bg1202_init00();
extern void bg1300_init00();
extern void bg1301_init00();
extern void bg1400_init00();
extern void bg1401_init00();
extern void bg1501_init00();
extern void bg1502_init00();
extern void bg1601_init00();
extern void bg1602_init00();
extern void bg1901_init00();
extern void bg1902_init00();
extern void bg_base_move_common();
extern void bg_move_common();

const BG_JMP2 bg1000_jmp_tbl[1] = {
    { { bg1000_init00, bg_move_common } },
};

const BG_JMP2 bg1001_jmp_tbl[15] = {
    { { bg1001_init00, bg_base_move_common } },
    { { bg1101_init00, bg1101_move } },
    { { bg1100_init00, bg1100_move } },
    { { bg1201_init00, bg_move_common } },
    { { bg1202_init00, bg_base_move_common } },
    { { bg1301_init00, bg_base_move_common } },
    { { bg1300_init00, bg_move_common } },
    { { bg1401_init00, bg_base_move_common } },
    { { bg1400_init00, bg_move_common } },
    { { bg1501_init00, bg_move_common } },
    { { bg1502_init00, bg_base_move_common } },
    { { bg1601_init00, bg_move_common } },
    { { bg1602_init00, bg_base_move_common } },
    { { bg1901_init00, bg_move_common } },
    { { bg1902_init00, bg_base_move_common } },
};

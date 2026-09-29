/*
 * BG130_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void bns01_init00();
extern void bns01_move();
extern void bns02_init00();
extern void bns02_move();
extern void bns11_init00();
extern void bns11_move();
extern void bns12_init00();
extern void bns12_move();

const BG_JMP2 bonus1_jmp0_tbl[1] = {
    { { bns01_init00, bns01_move } },
};

const BG_JMP2 bonus1_jmp1_tbl[3] = {
    { { bns02_init00, bns02_move } },
    { { bns11_init00, bns11_move } },
    { { bns12_init00, bns12_move } },
};

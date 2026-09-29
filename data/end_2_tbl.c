/*
 * END_2_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_200_0000();
extern void end_200_1000();
extern void end_200_2000();
extern void end_200_3000();
extern void end_201_1000();
extern void end_201_3000();
extern void end_202_1000();
extern void end_202_3000();
extern void end_202_4000();
extern void end_X_com01();

const PANEL end_200_panel0[6] = {
    { 0, 1 }, { 64, 2 }, { 4096, 3 }, { 4160, 4 }, { 8192, 5 }, { 8256, 6 },
};

const PANEL end_200_panel1[2] = {
    { 8192, 7 }, { 8256, 8 },
};

const s16 timer_2_tbl[5] = {
    480, 660, 120, 240, 780,
};

const s16 end_2_pos[5][2] = {
    { 256, 768 },
    { 320, 256 },
    { 512, 0 },
    { 320, 256 },
    { 320, 256 },
};

/* The initial values of end_100_jp (end_200_move) in end_2.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const end_100_jp_init[5])() = {
    end_200_0000,
    end_200_1000,
    end_200_2000,
    end_200_3000,
    end_200_3000,
};

const s16 end_200_1000_anm_tbl[4] = {
    12, 13, 14, 15,
};

/* The initial values of end_202_jp (end_201_move) in end_2.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const end_202_jp_init[5])() = {
    end_X_com01,
    end_201_1000,
    end_X_com01,
    end_201_3000,
    end_201_3000,
};

const s16 end_201_anm_tbl[10] = {
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25,
};

/* The initial values of end_202_jp (end_202_move) in end_2.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const end_202_jp_init_2[5])() = {
    end_X_com01,
    end_202_1000,
    end_X_com01,
    end_202_3000,
    end_202_4000,
};

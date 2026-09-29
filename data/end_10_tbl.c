/*
 * END_10_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_1000_0000();
extern void end_1000_1000();
extern void end_1000_2000();
extern void end_1000_4000();
extern void end_1001_1000();
extern void end_1002_1000();
extern void end_1003_1000();
extern void end_1003_2000();
extern void end_X_com01();

const PANEL end_1000_bg0_cell_tbl[8] = {
    { 0, 5 }, { 64, 6 }, { 4096, 1 }, { 4160, 2 }, { 8192, 3 }, { 8256, 4 }, { 12288, 7 }, { 12352, 8 },
};

const s16 timer_10_tbl[6] = {
    780, 720, 420, 780, 420, 660,
};

const s16 end_10_pos[6][2] = {
    { 256, 768 },
    { 256, 512 },
    { 256, 432 },
    { 256, 432 },
    { 256, 0 },
    { 256, 256 },
};

/* The initial values of end_1000_jp (end_1000_move) in end_10.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const end_1000_jp_init_4[6])() = {
    end_1000_0000,
    end_1000_1000,
    end_1000_2000,
    end_1000_2000,
    end_1000_4000,
    end_1000_2000,
};

const s16 end_1000_0000_anm_tbl[6] = {
    16, 17, 18, 19, 18, 17,
};

const s16 end_1000_4000_anm_tbl[5] = {
    20, 21, 22, 23, 24,
};

/* Stored after end_1000_4000_anm_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_1000_4000_anm_tbl. */
void (*const end_1000_4000_anm_tbl_tail[18])() = {
    end_X_com01,    end_1001_1000,  end_X_com01,    end_X_com01,  /* 0 */
    end_X_com01,    end_X_com01,    end_X_com01,    end_1002_1000,  /* 4 */
    end_X_com01,    end_X_com01,    end_X_com01,    end_X_com01,  /* 8 */
    end_X_com01,    end_1003_1000,  end_1003_2000,  end_X_com01,  /* 12 */
    end_X_com01,    end_X_com01,  /* 16 */
};

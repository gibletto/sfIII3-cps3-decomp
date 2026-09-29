/*
 * END_17_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 end_5_bg1_cell_0[];

extern void end_1100_3();
extern void end_1100_6();
extern void end_1100_common();
extern void end_1101_2();
extern void end_X_com01();

const PANEL end_1100_bg0_cell_tbl[16] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 7 }, { 4288, 8 },
    { 8192, 9 }, { 8256, 10 }, { 8320, 11 }, { 8384, 12 }, { 12288, 13 }, { 12352, 14 }, { 12416, 15 }, { 12480, 16 },
};

const u8 end_5_bg1_cell_0[16] = {
    0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 16, 64, 0, 0, 0, 0,
};

const s16 timer_11_tbl[7] = {
    660, 480, 120, 180, 480, 1260, 420,
};

const s16 end_11_pos[7][2] = {
    { 256, 768 },
    { 768, 768 },
    { 768, 768 },
    { 256, 768 },
    { 768, 512 },
    { 256, 256 },
    { 768, 256 },
};

/* The initial values of end_1102_move_jp (end_1100_move) in end_17.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
void (*const end_1102_move_jp_init[7])() = {
    end_1100_common,
    end_1100_common,
    end_1100_common,
    end_1100_3,
    end_1100_common,
    end_1100_common,
    end_1100_6,
};

const s16 end_11_115_pos[4][3] = {
    { 768, 256, 1 },
    { 256, 0, 2 },
    { 768, 0, 2 },
    { 256, 768, 1 },
};

/* Stored after end_11_115_pos. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_11_115_pos. */
void (*const end_11_115_pos_tail[14])() = {
    end_X_com01,  end_X_com01,  end_1101_2,   end_1101_2,  /* 0 */
    end_X_com01,  end_X_com01,  end_X_com01,  end_X_com01,  /* 4 */
    end_X_com01,  end_1101_2,   end_X_com01,  end_X_com01,  /* 8 */
    end_X_com01,  end_X_com01,  /* 12 */
};

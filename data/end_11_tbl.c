/*
 * END_11_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_X_com01();
extern void end_b00_0000();
extern void end_b00_1000();
extern void end_b00_3000();
extern void end_b01_0000();
extern void end_b01_3000();

const PANEL end_b00_bg0_cell_tbl[8] = {
    { 0, 3 }, { 64, 4 }, { 128, 8 }, { 192, 9 }, { 4096, 12 }, { 4160, 13 }, { 4224, 14 }, { 4288, 15 },
};

const PANEL end_b00_bg1_cell_tbl[16] = {
    { 0, 1 }, { 64, 2 }, { 128, 5 }, { 192, 6 }, { 4096, 1 }, { 4160, 2 }, { 4224, 5 }, { 4288, 6 },
    { 8192, 1 }, { 8256, 2 }, { 8320, 5 }, { 8384, 6 }, { 12288, 1 }, { 12352, 2 }, { 12416, 5 }, { 12480, 6 },
};

const s16 timer_b_tbl[7] = {
    240, 480, 180, 420, 600, 1080, 720,
};

const s16 end_b_pos[7][2] = {
    { 256, 0 }, { 256, 768 }, { 768, 0 }, { 768, 768 }, { 256, 512 }, { 768, 512 }, { 768, 512 },
};

/* Stored after end_b_pos. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_b_pos. */
void (*const end_b_pos_tail[14])() = {
    end_b00_0000,  end_b00_1000,  end_b00_0000,  end_b00_3000,  /* 0 */
    end_b00_0000,  end_b00_0000,  end_b00_0000,  end_b01_0000,  /* 4 */
    end_X_com01,   end_b01_0000,  end_b01_3000,  end_X_com01,  /* 8 */
    end_X_com01,   end_X_com01,  /* 12 */
};

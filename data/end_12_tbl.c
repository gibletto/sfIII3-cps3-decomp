/*
 * END_12_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_C00_0000();
extern void end_C00_1000();
extern void end_C00_2000();
extern void end_C00_3000();
extern void end_C00_4000();
extern void end_C00_5000();
extern void end_C00_6000();
extern void end_C01_0000();
extern void end_X_com01();

const PANEL end_c00_bg0_cell_tbl[12] = {
    { 4096, 3 }, { 4160, 4 }, { 8192, 11 }, { 8256, 12 }, { 12288, 15 }, { 12352, 16 }, { 128, 5 }, { 192, 6 },
    { 4224, 7 }, { 4288, 8 }, { 8320, 13 }, { 8384, 14 },
};

const PANEL end_c00_bg1_cell_tbl[6] = {
    { 4096, 1 }, { 4160, 2 }, { 8192, 9 }, { 8256, 10 }, { 12288, 17 }, { 12352, 18 },
};

const s16 timer_c_tbl[7] = {
    600, 600, 360, 420, 360, 540, 420,
};

const s16 end_c_pos[7][2] = {
    { 256, 32 }, { 768, 768 }, { 768, 768 }, { 768, 512 }, { 768, 768 }, { 768, 256 }, { 768, 256 },
};

/* Stored after end_c_pos. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_c_pos. */
void (*const end_c_pos_tail[14])() = {
    end_C00_0000,  end_C00_1000,  end_C00_2000,  end_C00_3000,  /* 0 */
    end_C00_4000,  end_C00_5000,  end_C00_6000,  end_C01_0000,  /* 4 */
    end_X_com01,   end_X_com01,   end_X_com01,   end_X_com01,  /* 8 */
    end_X_com01,   end_X_com01,  /* 12 */
};

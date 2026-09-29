/*
 * END_14_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_X_com01();
extern void end_e00_0000();
extern void end_e00_1000();
extern void end_e00_2000();
extern void end_e00_3000();
extern void end_e00_4000();
extern void end_e00_5000();
extern void end_e00_6000();
extern void end_e00_7000();
extern void end_e01_0000();
extern void end_e01_7000();
extern void end_e02_0000();
extern void end_e02_1000();
extern void end_e02_2000();
extern void end_e02_3000();
extern void end_e02_4000();
extern void end_e02_7000();

const s16 timer_e_tbl[9] = {
    1320, 240, 900, 1200, 360, 360, 300, 420,
    600,
};

const s16 end_e_pos[10][2] = {
    { 256, 768 },
    { 768, 0 },
    { 768, 768 },
    { 256, 0 },
    { 768, 768 },
    { 768, 768 },
    { 256, 0 },
    { 256, 768 },
    { 256, 256 },
    { 768, 256 },
};

/* Stored after end_e_pos. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_e_pos. */
void (*const end_e_pos_tail[8])() = {
    end_e00_0000,  end_e00_1000,  end_e00_2000,  end_e00_3000,  /* 0 */
    end_e00_4000,  end_e00_5000,  end_e00_6000,  end_e00_7000,  /* 4 */
};

const s16 end_e00_0000_col_tbl[12] = {
    16, 17, 18, 19, 20, 21, 22, 23,
    22, 23, 22, 23,
};

const s16 end_e00_1000_col_tbl[8] = {
    8, 9, 10, 11, 12, 13, 14, 15,
};

const s16 end_e00_2000_col_tbl[8] = {
    15, 14, 13, 12, 11, 10, 9, 8,
};

/* Stored after end_e00_2000_col_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_e00_2000_col_tbl. */
void (*const end_e00_2000_col_tbl_tail[16])() = {
    end_e01_0000,  end_X_com01,   end_X_com01,   end_X_com01,  /* 0 */
    end_X_com01,   end_X_com01,   end_X_com01,   end_e01_7000,  /* 4 */
    end_e02_0000,  end_e02_1000,  end_e02_2000,  end_e02_3000,  /* 8 */
    end_e02_4000,  end_X_com01,   end_X_com01,   end_e02_7000,  /* 12 */
};

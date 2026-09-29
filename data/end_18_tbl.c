/*
 * END_18_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_1800_0001();
extern void end_1800_0005();
extern void end_1800_0006();
extern void end_1800_0008();
extern void end_1800_0009();
extern void end_1800_0010();

const PANEL end_1800_bg0_cell_tbl[16] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 192, 4 }, { 4096, 5 }, { 4160, 6 }, { 4224, 1 }, { 4288, 2 },
    { 8192, 7 }, { 8256, 8 }, { 8320, 9 }, { 8384, 10 },
};

const s16 timer_18_tbl[11] = {
    900, 240, 240, 240, 240, 420, 720, 360,
    480, 240, 300,
};

const s16 end_18_pos[11][2] = {
    { 768, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 256, 768 },
    { 768, 768 },
    { 256, 512 },
    { 256, 768 },
    { 256, 512 },
    { 256, 256 },
    { 768, 512 },
};

/* Stored after end_18_pos. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_18_pos. */
void (*const end_18_pos_tail[11])() = {
    end_1800_0005,  end_1800_0001,  end_1800_0001,  end_1800_0001,  /* 0 */
    end_1800_0001,  end_1800_0005,  end_1800_0006,  end_1800_0001,  /* 4 */
    end_1800_0008,  end_1800_0009,  end_1800_0010,  /* 8 */
};

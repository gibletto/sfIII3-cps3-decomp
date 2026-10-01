/*
 * END_1_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void end_100_0000();
extern void end_100_0001();
extern void end_100_0002();
extern void end_100_0004();

const PANEL end_100_panel[11] = {
    { 0, 1 }, { 64, 2 }, { 128, 3 }, { 4096, 4 }, { 4160, 5 }, { 4224, 6 }, { 4288, 7 }, { 8192, 8 },
    { 8256, 9 }, { 8320, 10 }, { 8384, 11 },
};

const s16 timer_1_tbl[5] = {
    1200, 900, 1260, 240, 360,
};

const s16 end_1_pos[5][2] = {
    { 256, 768 },
    { 256, 512 },
    { 768, 512 },
    { 256, 256 },
    { 768, 240 },
};

/* Initial values of end_200_jp (end_100_move) in end_1.c. */
void (*const end_200_jp_init[5])() = {
    end_100_0000,
    end_100_0001,
    end_100_0002,
    end_100_0002,
    end_100_0004,
};

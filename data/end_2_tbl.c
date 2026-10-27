/*
 * END_2_TBL.C  Ryu's ending tables (ending 2)
 *
 * end_200_panel0 and end_200_panel1 list BG cells (map offset, cell number) written by the
 * ending, timer_2_tbl the length in frames of each of its five scenes and end_2_pos the BG x
 * and y of each scene. Read by END_2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

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

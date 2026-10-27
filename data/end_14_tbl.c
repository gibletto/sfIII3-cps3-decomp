/*
 * END_14_TBL.C  Gouki's ending scene tables (ending 14)
 *
 * timer_e_tbl is the length in frames of each scene of the Gouki and Shin Gouki ending and
 * end_e_pos the BG x and y of each scene. Read by END_14.C; the initial cells are in
 * END_13_TBL_B.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

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

/*
 * END_14_TBL.C  game tables
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

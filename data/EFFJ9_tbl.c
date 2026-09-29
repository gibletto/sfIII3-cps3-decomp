/*
 * EFFJ9_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 c2quake_table_tail[];
extern const s16 hahen_data_0[];


const s16 c2quake_table[19] = {
    0, 3, 3, 2, 2, 1, 1, 1,
    0, 0, 0, -1, -1, -1, -2, -2,
    -3, -3, 0,
};

/* Stored after c2quake_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of c2quake_table. */
const s16 c2quake_table_tail[41] = {
    0, 0, 0, 0, 0, -72, 16, 80,
    16, -8, 16, 80, 16, -104, 32, 24,
    16, -112, 32, 56, 16, -44, 24, 56,
    16, -40, 16, 56, 16, 136, 16, 88,
    16, 48, 32, 24, 16, 48, 32, 40,
    16,
};

const s16 hahen_data_0[12] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0,
};


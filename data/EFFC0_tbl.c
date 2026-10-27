/*
 * EFFC0_TBL.C  damage state 25 effect tables
 *
 * plhos_data gives, for each character, the offset from the player and the pattern of the
 * effect, and hok_table_ef the extra animation steps per frame by how hard the player mashes.
 * Read by EFFC0.C, the animation attached to a player in damage state 25.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 hok_table_ef[8] = {
    1, 1, 2, 2, 3, 3, 3, 3,
};

const s16 plhos_data[24][3] = {
    { 2, 136, 4 },
    { 40, 92, 3 },
    { -4, 104, 2 },
    { 2, 92, 5 },
    { 40, 88, 5 },
    { 8, 94, 2 },
    { 8, 106, 2 },
    { 20, 78, 2 },
    { 30, 96, 2 },
    { 10, 88, 3 },
    { 2, 92, 5 },
    { -4, 104, 2 },
    { -4, 104, 5 },
    { 2, 136, 4 },
    { -4, 104, 2 },
    { -4, 104, 2 },
    { 6, 90, 2 },
    { -4, 104, 2 },
    { -41, 127, 5 },
    { -4, 104, 4 },
    { -4, 104, 4 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};

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
    { 2, 136, 4 },  /* Gill */
    { 40, 92, 3 },  /* Alex */
    { -4, 104, 2 },  /* Ryu */
    { 2, 92, 5 },  /* Yun */
    { 40, 88, 5 },  /* Dudley */
    { 8, 94, 2 },  /* Necro */
    { 8, 106, 2 },  /* Hugo */
    { 20, 78, 2 },  /* Ibuki */
    { 30, 96, 2 },  /* Elena */
    { 10, 88, 3 },  /* Oro */
    { 2, 92, 5 },  /* Yang */
    { -4, 104, 2 },  /* Ken */
    { -4, 104, 5 },  /* Sean */
    { 2, 136, 4 },  /* Urien */
    { -4, 104, 2 },  /* Gouki */
    { -4, 104, 2 },  /* Shin Gouki */
    { 6, 90, 2 },  /* Chun-Li */
    { -4, 104, 2 },  /* Makoto */
    { -41, 127, 5 },  /* Q */
    { -4, 104, 4 },  /* Twelve */
    { -4, 104, 4 },  /* Remy */
    { 0, 0, 0 },  /* 21 */
    { 0, 0, 0 },  /* 22 */
    { 0, 0, 0 },  /* 23 */
};

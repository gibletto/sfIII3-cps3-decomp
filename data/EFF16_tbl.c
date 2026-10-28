/*
 * EFF16_TBL.C  bonus stage score display tables
 *
 * bunkai_table holds the powers of ten used to split the score into digits, bunkai_numobj the
 * character of each digit, and bbbs_score the screen position and character of each digit of
 * the score display of each type. Read by EFF16.C, the bonus-stage score display.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u32 bunkai_table[8] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
};

const u16 bunkai_numobj[10] = {
    0xB322, 0xB323, 0xB324, 0xB325, 0xB326, 0xB327, 0xB328, 0xB329,
    0xB32A, 0xB32B,
};

const CONN bbbs_score[4][8] = {
    { { -64, 164, 0, 0xB322 }, { -80, 164, 0, 0xB322 }, { -96, 164, 0, 0xB322 }, { -112, 164, 0, 0xB322 }, { -128, 164, 0, 0xB322 }, { -144, 164, 0, 0xB322 }, { -160, 164, 0, 0xB322 }, { -176, 164, 0, 0xB322 } },
    { { 176, 164, 0, 0xB322 }, { 160, 164, 0, 0xB322 }, { 144, 164, 0, 0xB322 }, { 128, 164, 0, 0xB322 }, { 112, 164, 0, 0xB322 }, { 96, 164, 0, 0xB322 }, { 80, 164, 0, 0xB322 }, { 64, 164, 0, 0xB322 } },
    { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
};

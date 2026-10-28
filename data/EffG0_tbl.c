/*
 * EFFG0_TBL.C  bonus score line digits
 *
 * suji_table_G0 is the powers of ten used to split the score, suji_numobj_G0 the ten digit
 * characters, and Result_Score the six-digit CONN layout of the line. Read by EFFG0.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u32 suji_table_G0[6] = {
    1, 10, 100, 1000, 10000, 100000,
};

const u16 suji_numobj_G0[10] = {
    0xBD33, 0xBD34, 0xBD35, 0xBD36, 0xBD37, 0xBD38, 0xBD39, 0xBD3A,
    0xBD3B, 0xBD3C,
};

const CONN Result_Score[6] = {
    { 40, 0, 0, 0xBD33 },
    { 32, 0, 0, 0xBD33 },
    { 24, 0, 0, 0xBD33 },
    { 16, 0, 0, 0xBD33 },
    { 8, 0, 0, 0xBD33 },
    { 0, 0, 0, 0xBD33 },
};

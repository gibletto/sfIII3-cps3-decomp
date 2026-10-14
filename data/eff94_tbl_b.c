/*
 * EFF94_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff94_0000();
extern void eff94_1000();
extern void eff94_2000();
extern void eff94_2000_0();
extern void eff94_2000_1();
extern void eff94_2000_2();
extern void eff94_2000_3();
extern void eff94_2000_4();
extern void eff94_3000();
extern void eff94_3000_0();
extern void eff94_3000_4();
extern void eff94_4000();

const s16 eff94_3000_tbl[4][3] = {
    { 328, 304, 0 },
    { 288, 240, 1 },
    { 280, 320, 0 },
    { 352, 264, 1 },
};

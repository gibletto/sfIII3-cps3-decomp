/*
 * EFF94_TBL.C  game tables
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

const s16 eff94_data_tbl[5][10] = {
    { 2, 8320, 392, 64, 12, 22, 52, 0, 0, 1 },
    { 2, 8320, 408, 75, 11, 23, 53, 0, 1, 1 },
    { 2, 8320, 640, 16, 10, 9, 10, 0, 4, 1 },
    { 2, 8320, 352, 272, 10, 2, 2, 0, 2, 1 },
    { 2, 8320, 352, 272, 10, 2, 2, 0, 3, 0 },
};

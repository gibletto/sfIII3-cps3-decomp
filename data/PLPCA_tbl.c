/*
 * PLPCA_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Catch_00000();
extern void Catch_01000();
extern void Catch_02000();
extern void Catch_03000();
extern void Catch_04000();
extern void Catch_05000();
extern void Catch_06000();
extern void Catch_07000();
extern void Catch_08000();

void (*const plpca_lv_00[9])() = {
    Catch_00000,  Catch_01000,  Catch_02000,  Catch_03000,  /* 0 */
    Catch_04000,  Catch_05000,  Catch_06000,  Catch_07000,  /* 4 */
    Catch_08000,  /* 8 */
};

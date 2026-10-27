/*
 * EFF04_TBL.C  nine-piece zoom display colours
 *
 * eff04_col_tbl is the cycle of extra colours stepped through while the nine zoom pieces are
 * in place. Read by EFF04.C, the nine-piece zoom display controller.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff04_col_tbl[6] = {
    128, 129, 130, 131, 130, 129,
};

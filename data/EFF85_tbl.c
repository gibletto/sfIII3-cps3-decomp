/*
 * EFF85_TBL.C  swallow animation numbers
 *
 * eff85_char_index_tbl gives the animation number of each step of the swallow's sequence. Read
 * by EFF85.C, the swallow on the stage background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 eff85_char_index_tbl[9] = {
    0, 30, 0, 32, 29, 33, 0, 0,
    0,
};

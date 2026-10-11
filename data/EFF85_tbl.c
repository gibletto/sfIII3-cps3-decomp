/*
 * EFF85_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void eff85_0000();
extern void eff85_0100();
extern void eff85_0200();
extern void eff85_1000();
extern void eff85_3000();
extern void eff85_5000();
extern void eff85_7000();
extern void eff85_8000();
extern void eff85_9000();
extern void eff85_common();

const s16 eff85_char_index_tbl[9] = {
    0, 30, 0, 32, 29, 33, 0, 0,
    0,
};

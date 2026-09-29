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

/* Stored after eff85_char_index_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of eff85_char_index_tbl. */
void (*const eff85_char_index_tbl_tail[12])() = {
    eff85_0000,    eff85_0100,    eff85_0200,    eff85_1000,  /* 0 */
    eff85_common,  eff85_3000,    eff85_common,  eff85_5000,  /* 4 */
    eff85_common,  eff85_7000,    eff85_8000,    eff85_9000,  /* 8 */
};

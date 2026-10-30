/*
 * BG000_TBL2.C  special screen layer positions
 *
 * etc_bg_pos_tbl gives the starting x, y of each layer of the special screens drawn by
 * bg_etc_write, by screen type. Read by BG000.C. bg_test_menu_scr, the position lines of the
 * background test (strings in BG000_TBL3.C), is not referred to.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 str_BG_1_POS_X[];
extern const s8 str_BG_1_POS_Y[];
extern const s8 str_BG_2_POS_X[];
extern const s8 str_BG_2_POS_Y[];
extern const s8 str_BG_3_POS_X[];
extern const s8 str_BG_3_POS_Y[];
extern const s8 str_BG_4_POS_X[];
extern const s8 str_BG_4_POS_Y[];
extern const s8 str_BG_1[];
extern const s8 str_BG_2[];
extern const s8 str_BG_3[];
extern const s8 str_BG_4[];
extern const s8 str_STAGE[];
extern const s8 str_AREA[];

const s32 etc_bg_pos_tbl[13][3][2] = {
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
};

/* the text lines of the background test's position display; nothing in the program refers to them (provisional name) */
const TM_STRING bg_test_menu_scr[14] = {
    { 30, 20, 0xE, str_BG_1_POS_X },
    { 30, 21, 0xE, str_BG_1_POS_Y },
    { 30, 22, 0xE, str_BG_2_POS_X },
    { 30, 23, 0xE, str_BG_2_POS_Y },
    { 30, 24, 0xE, str_BG_3_POS_X },
    { 30, 25, 0xE, str_BG_3_POS_Y },
    { 30, 26, 0xE, str_BG_4_POS_X },
    { 30, 27, 0xE, str_BG_4_POS_Y },
    { 3, 22, 0xE, str_BG_1 },
    { 3, 23, 0xE, str_BG_2 },
    { 3, 24, 0xE, str_BG_3 },
    { 3, 25, 0xE, str_BG_4 },
    { 3, 19, 0xE, str_STAGE },
    { 3, 20, 0xE, str_AREA },
};

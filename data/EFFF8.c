/*
 * EFFF8.C  second parry mark offsets and the empty ending scene list
 *
 * paring_b_mark_data is indexed by parry type and character and gives the { x, y } offset of
 * the parry mark from the player; read by EFFF8_CODE.C. efff9_no_scene is an empty scene list
 * (0, -1) that starts each character's group in the txt_no_ tables of EFFF9.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 efff9_no_scene[];


const s16 paring_b_mark_data[3][24][2] = {
    { { 28, 100 }, { 12, 88 }, { 10, 84 }, { 8, 76 }, { 14, 88 }, { 16, 86 }, { 24, 104 }, { 8, 70 }, { 20, 82 }, { 28, 70 }, { 8, 76 }, { 10, 84 }, { 10, 84 }, { 28, 100 }, { 10, 84 }, { 10, 84 }, { 10, 72 }, { 27, 64 }, { 28, 93 }, { 28, 71 }, { 24, 80 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 12, 52 }, { 26, 52 }, { 16, 50 }, { 10, 48 }, { 24, 60 }, { 24, 66 }, { 26, 68 }, { 16, 46 }, { 28, 44 }, { 26, 44 }, { 10, 48 }, { 16, 50 }, { 16, 50 }, { 12, 52 }, { 16, 50 }, { 16, 50 }, { 0, 0 }, { 27, 39 }, { 35, 44 }, { 18, 57 }, { 27, 43 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 40, 92 }, { 42, 62 }, { 28, 76 }, { 28, 76 }, { 38, 68 }, { 30, 84 }, { 28, 108 }, { 28, 56 }, { 38, 52 }, { 40, 60 }, { 28, 76 }, { 32, 48 }, { 32, 48 }, { 40, 92 }, { 28, 76 }, { 28, 76 }, { 28, 64 }, { 28, 76 }, { 52, 95 }, { 20, 97 }, { 26, 77 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};

/* provisional name */
const u16 efff9_no_scene[2] = {
    0, 0xFFFF,
};


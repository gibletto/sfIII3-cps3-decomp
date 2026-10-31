/*
 * EFF93_TBL.C  stage background object counts for effects 87 and 88
 *
 * eff87_loop_tbl and eff88_loop_tbl give the number of background objects to spawn by type and
 * compel flag; scr_obj_data87_0 and scr_obj_data88_0 are the empty object lists that the
 * effect 87 and 88 record tables point to. Read by EFF87.C and EFF88.C. eff90_pos_y_tbl holds
 * the y positions of the nine parts of the BG1 display object (effect 90).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 scr_obj_data87_0[];
extern const s16 scr_obj_data88_0[];


const s16 eff87_loop_tbl[1][4] = {
    { 0, 0, 0, 0 },
};

/* provisional name */
const s16 scr_obj_data87_0[2] = {
    0, 0,
};

const s16 eff88_loop_tbl[1][4] = {
    { 0, 0, 0, 0 },
};

/* provisional name */
const s16 scr_obj_data88_0[2] = {
    0, 0,
};

/* y positions of the nine parts of the BG1 display object; nothing refers to it */
const s16 eff90_pos_y_tbl[10] = {
    0, 32, 64, 96, 128, 160, 192, 224,
    256, 0,
};

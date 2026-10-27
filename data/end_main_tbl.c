/*
 * END_MAIN_TBL.C  opening demo BG tables
 *
 * op_quake_y_tbl0 is the 16-step vertical shake applied to an opening BG0 scene, and
 * op_scr_record_data_0 .. op_scr_record_data_3 are the scroll layout records of the four
 * opening BG layers, passed to sprite_list_setup. Read by END_MAIN.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 op_quake_y_tbl0[16] = {
    4, -8, 2, 1, -6, -3, 9, -3,
    8, -2, 6, 3, -4, -9, 3, -1,
};

const u8 op_scr_record_data_0[56] = {
    0, 1, 0, 75, 0, 127, 127, 0, 0, 12, 0, 255, 127, 0, 0, 12, 1, 127, 127, 0, 0, 12, 1, 255, 127, 0, 0, 12, 2, 127, 127, 0, 0, 12, 2, 255, 127, 0, 0, 12, 3, 127, 127, 0, 0, 12, 3, 255, 127, 0, 0, 12, 255, 255, 255, 255
};

const u8 op_scr_record_data_1[56] = {
    0, 2, 0, 80, 0, 127, 127, 0, 0, 28, 0, 255, 127, 0, 0, 28, 1, 127, 127, 0, 0, 28, 1, 255, 127, 0, 0, 28, 2, 127, 127, 0, 0, 28, 2, 255, 127, 0, 0, 28, 3, 127, 127, 0, 0, 28, 3, 255, 127, 0, 0, 28, 255, 255, 255, 255
};

const u8 op_scr_record_data_2[56] = {
    0, 3, 0, 85, 0, 127, 127, 0, 0, 44, 0, 255, 127, 0, 0, 44, 1, 127, 127, 0, 0, 44, 1, 255, 127, 0, 0, 44, 2, 127, 127, 0, 0, 44, 2, 255, 127, 0, 0, 44, 3, 127, 127, 0, 0, 44, 3, 255, 127, 0, 0, 44, 255, 255, 255, 255
};

const u8 op_scr_record_data_3[56] = {
    0, 4, 0, 88, 0, 127, 127, 0, 0, 60, 0, 255, 127, 0, 0, 60, 1, 127, 127, 0, 0, 60, 1, 255, 127, 0, 0, 60, 2, 127, 127, 0, 0, 60, 2, 255, 127, 0, 0, 60, 3, 127, 127, 0, 0, 60, 3, 255, 127, 0, 0, 60, 255, 255, 255, 255
};

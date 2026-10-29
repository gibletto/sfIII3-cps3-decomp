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

const s16 op_scr_record_data_0[28] = {
    /* [0] */
    1, 75,  0x7F, 0x7F00, 12,  0xFF, 0x7F00, 12,  0x17F, 0x7F00, 12,  0x1FF, 0x7F00, 12,  0x27F, 0x7F00, 12,
           0x2FF, 0x7F00, 12,  0x37F, 0x7F00, 12,  0x3FF, 0x7F00, 12,  -1,
    -1,
};

const s16 op_scr_record_data_1[28] = {
    /* [0] */
    2, 80,  0x7F, 0x7F00, 28,  0xFF, 0x7F00, 28,  0x17F, 0x7F00, 28,  0x1FF, 0x7F00, 28,  0x27F, 0x7F00, 28,
           0x2FF, 0x7F00, 28,  0x37F, 0x7F00, 28,  0x3FF, 0x7F00, 28,  -1,
    -1,
};

const s16 op_scr_record_data_2[28] = {
    /* [0] */
    3, 85,  0x7F, 0x7F00, 44,  0xFF, 0x7F00, 44,  0x17F, 0x7F00, 44,  0x1FF, 0x7F00, 44,  0x27F, 0x7F00, 44,
           0x2FF, 0x7F00, 44,  0x37F, 0x7F00, 44,  0x3FF, 0x7F00, 44,  -1,
    -1,
};

const s16 op_scr_record_data_3[28] = {
    /* [0] */
    4, 88,  0x7F, 0x7F00, 60,  0xFF, 0x7F00, 60,  0x17F, 0x7F00, 60,  0x1FF, 0x7F00, 60,  0x27F, 0x7F00, 60,
           0x2FF, 0x7F00, 60,  0x37F, 0x7F00, 60,  0x3FF, 0x7F00, 60,  -1,
    -1,
};

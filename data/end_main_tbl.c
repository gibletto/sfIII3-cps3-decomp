/*
 * END_MAIN_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void op_bg0_0000();
extern void op_bg0_0001();
extern void op_bg0_0002();
extern void op_bg0_0003();
extern void op_bg0_0004();
extern void op_bg0_0005();
extern void op_bg0_0006();
extern void op_bg0_0007();
extern void op_bg0_0008();
extern void op_bg0_0010();
extern void op_bg0_0011();
extern void op_bg0_0012();
extern void op_bg0_0013();
extern void op_bg0_0014();
extern void op_bg0_0015();
extern void op_bg0_0016();
extern void op_bg1_0003_move();
extern void opening_capcom_scene_init();
extern void opening_init2();
extern void opening_move();

const s16 op_bg0_0001_tbl[16] = {
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

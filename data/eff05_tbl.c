/*
 * EFF05_TBL.C  stage scenery object list, set 05
 *
 * scr_obj_num is the number of scenery objects for each stage background (bg_index). The
 * scr_obj_data_N lists that follow hold the object rows (family, colour, position, priority,
 * animation, line-scroll sync) that scr_obj_data in EFF05.C names, each list after the first
 * stage that uses it; a stage with no objects names a list it never reads (scr_obj_data_0,
 * which EFF06.C names for its own empty stages too). Read by EFF05.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num[23] = {
    0, 2, 0, 0, 0, 2, 1, 0,
    3, 1, 0, 1, 1, 1, 1, 1,
    2, 2, 0, 2, 4, 1, 4,
};

/* set 05 stages 0, 2, 3, 4, 18 with no objects; set 06 stages 3, 6, 21, 22 with no objects; not an object row; provisional name */
const s16 scr_obj_data_0[1] = {
    0,
};

/* set 05 stages 1, 11; provisional name */
const s16 scr_obj_data_1[16] = {
    0, 1, 128, 568, 48, 86, 0, 0,
    0, 2, 8320, 528, 47, 68, 19, 0,
};

/* set 05 stage 10 with no objects; provisional name */
const s16 scr_obj_data_10[8] = {
    0, 3, 128, 512, 16, 88, 10, 0,
};

/* set 05 stage 5; provisional name */
const s16 scr_obj_data_5[16] = {
    0, 3, 128, 512, 0, 88, 9, 0,
    0, 3, 8320, 560, 0, 88, 10, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_0[16] = {
    0, 2, 128, 512, 0, 84, 3, 0,
    0, 2, 128, 512, 0, 84, 4, 0,
};

/* set 05 stage 19; provisional name */
const s16 scr_obj_data_19[16] = {
    0, 3, 128, 512, 0, 88, 21, 0,
    0, 3, 8320, 560, 0, 88, 22, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_1[16] = {
    0, 2, 128, 512, 0, 84, 15, 0,
    0, 2, 128, 512, 0, 84, 16, 0,
};

/* set 05 stage 6; provisional name */
const s16 scr_obj_data_6[8] = {
    0, 1, 8320, 511, 96, 88, 11, 0,
};

/* set 05 stage 7 with no objects; provisional name */
const s16 scr_obj_data_7[32] = {
    0, 3, 8320, 504, 48, 94, 4, 0,
    0, 3, 8320, 504, 112, 94, 8, 0,
    0, 2, 8320, 464, 256, 84, 7, 0,
    0, 2, 8320, 512, 352, 84, 8, 0,
};

/* set 05 stage 8; provisional name */
const s16 scr_obj_data_8[24] = {
    0, 2, 8320, 496, 48, 85, 1, 0,
    0, 7, 8320, 512, 43, 88, 12, 0,
    0, 7, 8320, 512, 43, 88, 13, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_2[24] = {
    0, 2, 8320, 624, 120, 86, 7, 0,
    0, 3, 8320, 512, 72, 90, 1, 0,
    0, 3, 8320, 512, 72, 90, 2, 0,
};

/* set 05 stage 9; provisional name */
const s16 scr_obj_data_9[8] = {
    0, 6, 8320, 352, 16, 10, 5, 0,
};

/* set 05 stage 12; provisional name */
const s16 scr_obj_data_12[8] = {
    0, 6, 8320, 352, 16, 10, 5, 0,
};

/* set 05 stage 13; provisional name */
const s16 scr_obj_data_13[8] = {
    0, 3, 128, 512, 32, 88, 0, 0,
};

/* set 05 stages 14, 15; provisional name */
const s16 scr_obj_data_14[8] = {
    0, 3, 128, 512, 88, 98, 7, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_3[16] = {
    0, 2, 128, 576, 64, 84, 5, 0,
    0, 2, 128, 560, 208, 84, 6, 0,
};

/* set 05 stage 16; provisional name */
const s16 scr_obj_data_16[16] = {
    0, 3, 8320, 512, 80, 86, 0, 0,
    0, 2, 8320, 480, 16, 12, 2, 0,
};

/* set 05 stage 17; provisional name */
const s16 scr_obj_data_17[16] = {
    0, 1, 8320, 512, 176, 90, 2, 0,
    0, 1, 8320, 512, 240, 90, 3, 0,
};

/* set 05 stage 20; provisional name */
const s16 scr_obj_data_20[32] = {
    0, 2, 8320, 504, 11, 10, 0, 0,
    0, 1, 8320, 496, 64, 86, 1, 0,
    0, 3, 128, 496, 144, 88, 3, 0,
    0, 3, 128, 512, 320, 83, 5, 0,
};

/* set 05 stage 21; provisional name */
const s16 scr_obj_data_21[8] = {
    0, 2, 128, 445, 48, 10, 0, 0,
};

/* set 05 stage 22; provisional name */
const s16 scr_obj_data_22[32] = {
    0, 2, 128, 624, 0, 10, 2, 0,
    0, 2, 8320, 511, 0, 12, 3, 0,
    0, 2, 128, 511, 0, 80, 4, 0,
    0, 2, 128, 608, 48, 77, 11, 0,
};

/*
 * EFF06_TBL.C  stage scenery object list, set 06
 *
 * scr_obj_num6 is the number of second-set scenery objects for each stage background
 * (bg_index). The scr_obj_data6_N lists that follow hold the object rows that scr_obj_data6 in
 * EFF06.C names, each list after the first stage that uses it. Read by EFF06.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num6[23] = {
    1, 6, 4, 0, 3, 1, 0, 2,
    8, 3, 0, 4, 3, 0, 1, 1,
    1, 4, 0, 1, 1, 0, 0,
};

/* set 06 stage 0; provisional name */
const s16 scr_obj_data6_0[8] = {
    0, 2, 8320, 640, 48, 82, 0, 0,
};

/* set 06 stage 1 and stage 13 with no objects; provisional name */
const s16 scr_obj_data6_1[48] = {
    0, 1, 128, 648, 48, 86, 1, 0,
    0, 1, 128, 728, 48, 86, 2, 0,
    0, 1, 128, 792, 48, 86, 3, 0,
    0, 2, 8320, 648, 16, 10, 18, 0,
    0, 2, 8320, 416, 48, 70, 20, 0,
    0, 2, 8320, 264, 48, 72, 21, 0,
};

/* set 06 stage 11; provisional name */
const s16 scr_obj_data6_11[32] = {
    0, 1, 128, 648, 48, 86, 1, 0,
    0, 1, 128, 728, 48, 86, 2, 0,
    0, 1, 128, 792, 48, 86, 3, 0,
    0, 2, 128, 463, 193, 83, 22, 0,
};

/* set 06 stage 2; provisional name */
const s16 scr_obj_data6_2[32] = {
    0, 6, 8320, 160, 64, 86, 0, 0,
    0, 6, 8320, 224, 64, 86, 1, 0,
    0, 6, 8320, 336, 64, 86, 2, 0,
    0, 6, 8320, 432, 64, 86, 3, 0,
};

/* set 06 stage 10 with no objects; provisional name */
const s16 scr_obj_data6_10[48] = {
    0, 3, 128, 448, 16, 88, 9, 0,
    0, 3, 128, 528, 16, 88, 11, 0,
    0, 3, 128, 608, 16, 88, 12, 0,
    0, 3, 128, 688, 16, 88, 13, 0,
    0, 3, 128, 768, 16, 88, 14, 0,
    0, 3, 128, 848, 16, 88, 15, 0,
};

/* set 06 stage 4; provisional name */
const s16 scr_obj_data6_4[24] = {
    0, 2, 8320, 672, 24, 10, 0, 0,
    0, 2, 128, 416, 72, 82, 1, 0,
    0, 2, 128, 192, 0, 10, 12, 0,
};

/* set 06 stage 5 and stage 18 with no objects; provisional name */
const s16 scr_obj_data6_5[8] = {
    0, 3, 8320, 432, 0, 82, 8, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data6_unref_0[48] = {
    0, 2, 128, 160, 0, 84, 0, 0,
    0, 2, 128, 256, 0, 84, 1, 0,
    0, 2, 128, 352, 0, 84, 2, 0,
    0, 2, 128, 672, 0, 84, 5, 0,
    0, 2, 128, 768, 0, 84, 6, 0,
    0, 2, 128, 864, 0, 84, 7, 0,
};

/* set 06 stage 19; provisional name */
const s16 scr_obj_data6_19[8] = {
    0, 3, 8320, 432, 0, 82, 20, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data6_unref_1[48] = {
    0, 2, 128, 160, 0, 84, 12, 0,
    0, 2, 128, 256, 0, 84, 13, 0,
    0, 2, 128, 352, 0, 84, 14, 0,
    0, 2, 128, 672, 0, 84, 17, 0,
    0, 2, 128, 768, 0, 84, 18, 0,
    0, 2, 128, 864, 0, 84, 19, 0,
};

/* set 06 stage 7; provisional name */
const s16 scr_obj_data6_7[16] = {
    0, 3, 8320, 288, 80, 93, 0, 0,
    0, 3, 8320, 416, 48, 93, 1, 0,
};

/* set 06 stage 8; provisional name */
const s16 scr_obj_data6_8[64] = {
    0, 7, 8320, 256, 43, 88, 10, 0,
    0, 7, 8320, 384, 43, 88, 11, 0,
    0, 7, 8320, 752, 43, 88, 16, 0,
    0, 2, 8320, 192, 48, 86, 0, 0,
    0, 2, 8320, 576, 48, 86, 2, 0,
    0, 2, 8320, 800, 48, 86, 3, 0,
    0, 6, 8320, 640, 128, 85, 6, 0,
    0, 6, 8320, 368, 160, 85, 7, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data6_unref_2[24] = {
    0, 2, 8320, 336, 88, 86, 6, 0,
    0, 6, 8320, 514, 136, 86, 8, 0,
    0, 6, 8320, 722, 56, 86, 9, 0,
};

/* set 06 stage 9; provisional name */
const s16 scr_obj_data6_9[24] = {
    0, 3, 8320, 464, 64, 86, 6, 0,
    0, 7, 8320, 512, 96, 88, 7, 0,
    0, 6, 8320, 832, 16, 10, 5, 0,
};

/* set 06 stage 12; provisional name */
const s16 scr_obj_data6_12[24] = {
    0, 3, 8320, 464, 64, 86, 0, 0,
    0, 7, 8320, 512, 96, 88, 1, 0,
    0, 6, 8320, 832, 16, 10, 5, 0,
};

/* set 06 stages 14, 15; provisional name */
const s16 scr_obj_data6_14[8] = {
    0, 2, 8320, 592, 16, 10, 0, 0,
};

/* not referred to; not an object row; provisional name */
const s16 scr_obj_data6_unref_3[2] = {
    1, 1,
};

/* set 06 stage 16; provisional name */
const s16 scr_obj_data6_16[8] = {
    0, 2, 8320, 448, 16, 14, 1, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data6_unref_4[8] = {
    0, 2, 8320, 928, 32, 72, 3, 0,
};

/* set 06 stage 17; provisional name */
const s16 scr_obj_data6_17[32] = {
    0, 1, 8320, 256, 64, 90, 0, 0,
    0, 1, 8320, 384, 128, 90, 1, 0,
    0, 1, 8320, 624, 128, 90, 4, 0,
    0, 3, 8320, 784, 128, 10, 7, 0,
};

/* set 06 stage 20; provisional name */
const s16 scr_obj_data6_20[8] = {
    0, 3, 128, 496, 64, 88, 4, 0,
};

/* not referred to; not an object row; provisional name */
const s16 scr_obj_data6_unref_5[1] = {
    0,
};

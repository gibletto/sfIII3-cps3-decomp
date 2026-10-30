/*
 * EFF05_TBL.C  stage scenery object list, set 05
 *
 * scr_obj_num is the number of scenery objects for each stage background (bg_index). The
 * stgSS00_data_tbl lists that follow hold the object rows (family, colour, position, priority,
 * animation, line-scroll sync) that scr_obj_data in EFF05.C names, each list after the first
 * stage SS (hexadecimal) that uses it; a stage with no objects names a list it never reads
 * (stg_dum_data_tbl, which EFF06.C names for its own empty stages too); scr_obj_data_unref_N
 * are not referred to. Read by EFF05.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 scr_obj_num[23] = {
    0, 2, 0, 0, 0, 2, 1, 0,
    3, 1, 0, 1, 1, 1, 1, 1,
    2, 2, 0, 2, 4, 1, 4,
};

/* set 05 stages 0, 2, 3, 4, 18 with no objects; set 06 stages 3, 6, 21, 22 with no objects; not an object row */
const s16 stg_dum_data_tbl[1] = {
    0,
};

/* set 05 stages 1, 11 */
const s16 stg0100_data_tbl[16] = {
    0, 1, 128, 568, 48, 86, 0, 0,
    0, 2, 8320, 528, 47, 68, 19, 0,
};

/* set 05 stage 10 with no objects */
const s16 stg0A00_data_tbl[8] = {
    0, 3, 128, 512, 16, 88, 10, 0,
};

/* set 05 stage 5 */
const s16 stg0500_data_tbl[16] = {
    0, 3, 128, 512, 0, 88, 9, 0,
    0, 3, 8320, 560, 0, 88, 10, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_0[16] = {
    0, 2, 128, 512, 0, 84, 3, 0,
    0, 2, 128, 512, 0, 84, 4, 0,
};

/* set 05 stage 19 */
const s16 stg1300_data_tbl[16] = {
    0, 3, 128, 512, 0, 88, 21, 0,
    0, 3, 8320, 560, 0, 88, 22, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_1[16] = {
    0, 2, 128, 512, 0, 84, 15, 0,
    0, 2, 128, 512, 0, 84, 16, 0,
};

/* set 05 stage 6 */
const s16 stg0600_data_tbl[8] = {
    0, 1, 8320, 511, 96, 88, 11, 0,
};

/* set 05 stage 7 with no objects */
const s16 stg0700_data_tbl[32] = {
    0, 3, 8320, 504, 48, 94, 4, 0,
    0, 3, 8320, 504, 112, 94, 8, 0,
    0, 2, 8320, 464, 256, 84, 7, 0,
    0, 2, 8320, 512, 352, 84, 8, 0,
};

/* set 05 stage 8 */
const s16 stg0800_data_tbl[24] = {
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

/* set 05 stage 9 */
const s16 stg0900_data_tbl[8] = {
    0, 6, 8320, 352, 16, 10, 5, 0,
};

/* set 05 stage 12 */
const s16 stg0c00_data_tbl[8] = {
    0, 6, 8320, 352, 16, 10, 5, 0,
};

/* set 05 stage 13 */
const s16 stg0d00_data_tbl[8] = {
    0, 3, 128, 512, 32, 88, 0, 0,
};

/* set 05 stages 14, 15 */
const s16 stg0e00_data_tbl[8] = {
    0, 3, 128, 512, 88, 98, 7, 0,
};

/* not referred to; provisional name */
const s16 scr_obj_data_unref_3[16] = {
    0, 2, 128, 576, 64, 84, 5, 0,
    0, 2, 128, 560, 208, 84, 6, 0,
};

/* set 05 stage 16 */
const s16 stg1000_data_tbl[16] = {
    0, 3, 8320, 512, 80, 86, 0, 0,
    0, 2, 8320, 480, 16, 12, 2, 0,
};

/* set 05 stage 17 */
const s16 stg1100_data_tbl[16] = {
    0, 1, 8320, 512, 176, 90, 2, 0,
    0, 1, 8320, 512, 240, 90, 3, 0,
};

/* set 05 stage 20 */
const s16 stg1400_data_tbl[32] = {
    0, 2, 8320, 504, 11, 10, 0, 0,
    0, 1, 8320, 496, 64, 86, 1, 0,
    0, 3, 128, 496, 144, 88, 3, 0,
    0, 3, 128, 512, 320, 83, 5, 0,
};

/* set 05 stage 21 */
const s16 stg1500_data_tbl[8] = {
    0, 2, 128, 445, 48, 10, 0, 0,
};

/* set 05 stage 22 */
const s16 stg1600_data_tbl[32] = {
    0, 2, 128, 624, 0, 10, 2, 0,
    0, 2, 8320, 511, 0, 12, 3, 0,
    0, 2, 128, 511, 0, 80, 4, 0,
    0, 2, 128, 608, 48, 77, 11, 0,
};

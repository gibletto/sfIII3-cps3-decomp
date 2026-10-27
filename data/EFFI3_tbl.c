/*
 * EFFI3_TBL.C  palette cycle and background stop tables
 *
 * effI2_col_tbl and effI2_timer_tbl are the ten palette numbers and step times that effect I2
 * cycles through; read by EFFI3.C. i3_data has an I3_Data { flags, time source, time } entry
 * per background stop type, giving the duration and end conditions; read by EFFI3_2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const u8 effI2_col_tbl[10] = {
    8, 13, 14, 15, 16, 17, 16, 15,
    14, 13,
};

const u8 effI2_timer_tbl[10] = {
    9, 8, 7, 6, 5, 4, 5, 6,
    7, 8,
};

const I3_Data i3_data[6] = {
    { 3, 2, 0 }, { 1, 1, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 }, { 2, 0, 0 },
};

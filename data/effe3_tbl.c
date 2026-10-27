/*
 * EFFE3_TBL.C  super art flash background table (effect E3)
 *
 * effE3_data has one row per Flash_MT value: the BG3 x and y of the flash picture and the
 * frames it is held. Read by EFFE3.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


/* One row per Flash_MT value: BG3 x and y of the picture and the frames it is held. */
const s16 effE3_data[5][3] = {
    { 0, 0, 1 }, { 256, 256, 1 }, { 768, 256, 1 }, { 768, 0, 1 }, { 768, 256, 1 },
};


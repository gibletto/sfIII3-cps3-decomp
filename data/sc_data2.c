/*
 * SC_DATA2.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s16 spgauge_postbl_0[];
extern const s16 spgauge_postbl_1[];
extern const s16 spgauge_puttbl_0[];
extern const s16 spgauge_puttbl_1[];


const s16 flash_timer_tbl[2] = {
    3, 1,
};

const s16 flash_color_tbl[4] = {
    10, 12, 10, 8,
};

const s16 spgauge_puttbl_0[9] = {
    176, 177, 178, 179, 180, 181, 182, 183,
    184,
};

const s16 spgauge_puttbl_1[9] = {
    352, 353, 354, 355, 356, 357, 358, 359,
    360,
};

const s16 spgauge_postbl_0[16] = {
    21, 20, 19, 18, 17, 16, 15, 14,
    13, 12, 11, 10, 9, 8, 7, 6,
};

const s16 spgauge_postbl_1[16] = {
    26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41,
};


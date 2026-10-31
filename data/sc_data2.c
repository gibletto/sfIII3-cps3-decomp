/*
 * SC_DATA2.C  round timer flash and super art gauge cell tables
 *
 * flash_timer_tbl and flash_color_tbl are the rate and colour cycle of the flashing round
 * timer (COUNT.C). spgauge_puttbl_0/1 are the cell codes of each fill step of the super art
 * gauge and spgauge_postbl_0/1 its cell columns, for the 1P and 2P sides (SPGAUGE.C).
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 spgauge_postbl_0[];
extern const u16 spgauge_postbl_1[];
extern const u16 spgauge_puttbl_0[];
extern const u16 spgauge_puttbl_1[];


const s16 flash_timer_tbl[2] = {
    3, 1,
};

const s16 flash_color_tbl[4] = {
    10, 12, 10, 8,
};

/* provisional name */
const u16 spgauge_puttbl_0[9] = {
    176, 177, 178, 179, 180, 181, 182, 183,
    184,
};

const u16 spgauge_puttbl_1[9] = {
    352, 353, 354, 355, 356, 357, 358, 359,
    360,
};

const u16 spgauge_postbl_0[16] = {
    21, 20, 19, 18, 17, 16, 15, 14,
    13, 12, 11, 10, 9, 8, 7, 6,
};

const u16 spgauge_postbl_1[16] = {
    26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41,
};


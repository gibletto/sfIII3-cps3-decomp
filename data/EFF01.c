/*
 * EFF01.C  overlay parts colours
 *
 * parts_colmd_table and parts_colcd_table give the colour mode and colour code of an overlay
 * part, picked by the indexes in the character's overlap table. Read by EFF01_CODE.C, the
 * overlay parts effect.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 parts_colmd_table[2] = {
    16384, 0,
};

const s16 parts_colcd_table[14] = {
    8192, 0, 6, 8192, 4, 8224, 4, 4,
    0, 6, 5, 4, 8294, 0,
};

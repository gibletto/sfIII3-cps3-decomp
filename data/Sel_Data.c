/*
 * SEL_DATA.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 EFF76_Face_Pos_Data[20][2] = {
    { 32, 16 }, { 80, 16 }, { 88, 16 }, { 80, 16 }, { 80, 16 }, { 152, 16 }, { 80, 16 }, { 80, 16 },
    { 80, 16 }, { 80, 16 }, { 80, 16 }, { 80, 16 }, { 80, 16 }, { 80, 16 }, { 80, 16 }, { 80, 16 },
    { 96, 16 }, { 88, 16 }, { 88, 16 }, { 80, 16 },
};

/* Stored after EFF76_Face_Pos_Data. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of EFF76_Face_Pos_Data. */
const s16 EFF76_Face_Pos_Data_tail[22][2] = {
    96, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    88, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
    80, 16,
};

const s16 Width_Data_76[26] = {
    80, 48, 192, 48, 48, 48, 48, 192,
    192, 96, 96, 192, 112, 192, 80, 128,
    80, 80, 256, 48, 32, 96, 160, 384,
    208, 208,
};

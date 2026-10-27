/*
 * EFF37_TBL.C  face panel position offsets
 *
 * panel_pos_hosei gives the offset of the face panel from the judge it belongs to, for each
 * judge character set and display frame type of the judge. Read by EFF37.C, the face panel
 * shown with a character.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 panel_pos_hosei[8][4][2] = {
    { { 25, 99 }, { 25, 100 }, { 0, 0 }, { 25, 100 } },
    { { 43, 103 }, { 42, 106 }, { 0, 0 }, { 42, 106 } },
    { { 18, 115 }, { 0, 0 }, { 0, 0 }, { 18, 115 } },
    { { 18, 115 }, { 0, 0 }, { 0, 0 }, { 18, 115 } },
    { { 18, 115 }, { 0, 0 }, { 0, 0 }, { 18, 115 } },
    { { 30, 90 }, { 30, 89 }, { 0, 0 }, { 30, 89 } },
    { { -23, 112 }, { 0, 0 }, { 0, 0 }, { -23, 112 } },
    { { -86, 60 }, { 0, 0 }, { 0, 0 }, { -86, 60 } },
};

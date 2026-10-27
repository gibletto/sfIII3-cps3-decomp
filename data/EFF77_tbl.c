/*
 * EFF77_TBL.C  temporary full-screen background settings
 *
 * eff77_data_tbl gives, for each type, the time the background is held and the x, y scroll
 * position of BG layer 3. Read by EFF77.C, the temporary full-screen background.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff77_data_tbl[7][3] = {
    { 64, 256, 256 },
    { 2, 768, 256 },
    { 1, 256, 0 },
    { 32, 256, 0 },
    { 22, 256, 0 },
    { 1, 256, 256 },
    { 1, 256, 256 },
};


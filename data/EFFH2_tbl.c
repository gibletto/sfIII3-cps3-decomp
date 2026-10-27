/*
 * EFFH2_TBL.C  path of the marker on a judge's vote panel
 *
 * panel_guide is the eight { x, y } offsets the H2 marker steps through around the panel, one
 * step every eight frames. Read by EFFH2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 panel_guide[8][2] = {
    { 0, 6 }, { 0, 5 }, { 0, 4 }, { 0, 2 }, { 0, 0 }, { 0, 2 }, { 0, 4 }, { 0, 5 },
};

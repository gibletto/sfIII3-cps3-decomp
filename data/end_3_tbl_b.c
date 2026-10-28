/*
 * END_3_TBL_B.C  Dudley's ending cell tables (ending 4)
 *
 * end_400_panel_tbl_0 and end_400_panel_tbl_1 are two sets of twelve BG cells (map offset,
 * cell number), picked through end_400_panel_tbl in END_4.C; the scene timings are in
 * END_4_TBL.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const PANEL end_400_panel_tbl_0[];
extern const PANEL end_400_panel_tbl_1[];

const PANEL end_400_panel_tbl_0[12] = {
    { 0, 1 }, { 0x40, 2 }, { 0x80, 3 }, { 0xC0, 0 },
    { 0x1000, 16 }, { 0x1040, 17 }, { 0x1080, 18 }, { 0x10C0, 0 },
    { 0x2000, 19 }, { 0x2040, 20 }, { 0x2080, 21 }, { 0x20C0, 0 },
};

const PANEL end_400_panel_tbl_1[12] = {
    { 0, 4 }, { 0x40, 5 }, { 0x80, 6 }, { 0xC0, 7 },
    { 0x1000, 8 }, { 0x1040, 9 }, { 0x1080, 10 }, { 0x10C0, 11 },
    { 0x2000, 12 }, { 0x2040, 13 }, { 0x2080, 14 }, { 0x10C0, 15 },
};


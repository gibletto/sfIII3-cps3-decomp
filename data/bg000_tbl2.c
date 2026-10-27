/*
 * BG000_TBL2.C  special screen layer positions
 *
 * etc_bg_pos_tbl gives the starting x, y of each layer of the special screens drawn by
 * bg_etc_write, by screen type. Read by BG000.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 pos_area_wide_tbl[692];

const s32 etc_bg_pos_tbl[20][3][2] = {
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 33554432, 0 }, { 33554432, 0 }, { 0, 0 } },
    { { 1966100, 917504 }, { (u32)&pos_area_wide_tbl[496], 1966101 }, { 917504, (u32)&pos_area_wide_tbl[512] } },
    { { 1966102, 917504 }, { (u32)&pos_area_wide_tbl[528], 1966103 }, { 917504, (u32)&pos_area_wide_tbl[544] } },
    { { 1966104, 917504 }, { (u32)&pos_area_wide_tbl[560], 1966105 }, { 917504, (u32)&pos_area_wide_tbl[576] } },
    { { 1966106, 917504 }, { (u32)&pos_area_wide_tbl[592], 1966107 }, { 917504, (u32)&pos_area_wide_tbl[608] } },
    { { 196630, 917504 }, { (u32)&pos_area_wide_tbl[624], 196631 }, { 917504, (u32)&pos_area_wide_tbl[636] } },
    { { 196632, 917504 }, { (u32)&pos_area_wide_tbl[648], 196633 }, { 917504, (u32)&pos_area_wide_tbl[660] } },
    { { 196627, 917504 }, { (u32)&pos_area_wide_tbl[668], 196628 }, { 917504, (u32)&pos_area_wide_tbl[680] } },
};

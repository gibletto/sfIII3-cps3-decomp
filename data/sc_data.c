/*
 * SC_DATA.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u16 sc_vram_00_attr[];
extern const u16 sc_vram_00_code[];
extern const u16 sc_vram_00_pos[];
extern const u16 sc_vram_01_attr[];
extern const u16 sc_vram_01_code[];
extern const u16 sc_vram_01_pos[];
extern const u16 sc_vram_02_attr[];
extern const u16 sc_vram_02_code[];
extern const u16 sc_vram_02_pos[];
extern const u16 sc_vram_03_attr[];
extern const u16 sc_vram_03_code[];
extern const u16 sc_vram_03_pos[];
extern const u16 sc_vram_04_attr[];
extern const u16 sc_vram_04_code[];
extern const u16 sc_vram_04_pos[];
extern const u16 sc_vram_05_pos[];
extern const u16 sc_vram_06_attr[];
extern const u16 sc_vram_06_code[];
extern const u16 sc_vram_06_pos[];
extern const u16 sc_vram_07_attr[];
extern const u16 sc_vram_07_pos[];
extern const u16 sc_vram_08_attr[];
extern const u16 sc_vram_09_attr[];
extern const u16 sc_vram_10_attr[];
extern const u16 sc_vram_11_attr[];
extern const u16 sc_vram_12_attr[];
extern const u16 sc_vram_12_code[];
extern const u16 sc_vram_12_pos[];
extern const u16 sc_vram_13_attr[];
extern const u16 sc_vram_14_pos[];
extern const u16 sc_vram_16_code[];
extern const u16 sc_vram_16_pos[];
extern const u16 sc_vram_18_code[];
extern const u16 sc_vram_18_pos[];
extern const u16 sc_vram_19_code[];
extern const u16 sc_vram_19_pos[];
extern const u16 sc_vram_20_attr[];
extern const u16 sc_vram_20_code[];
extern const u16 sc_vram_20_pos[];
extern const u16 sc_vram_21_code[];
extern const u16 sc_vram_22_code[];
extern const u16 sc_vram_23_code[];
extern const u16 sc_vram_24_code[];
extern const u16 sc_vram_24_pos[];
extern const u16 sc_vram_25_code[];
extern const u16 sc_vram_25_pos[];
extern const u16 sc_vram_26_code[];
extern const u16 sc_vram_26_pos[];
extern const u16 sc_vram_27_code[];
extern const u16 sc_vram_28_code[];
extern const u16 sc_vram_28_pos[];
extern const u16 sc_vram_29_attr[];
extern const u16 sc_vram_29_code[];
extern const u16 sc_vram_29_pos[];

extern const u8 sc_celllist_tbl[];

const CELL_SET sc_ram_vram_tbl[30] = {
    { (void*)sc_vram_00_pos, (void*)sc_vram_00_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_01_pos, (void*)sc_vram_01_code, (void*)sc_vram_01_attr },
    { (void*)sc_vram_02_pos, (void*)sc_vram_02_code, (void*)sc_vram_02_attr },
    { (void*)sc_vram_03_pos, (void*)sc_vram_03_code, (void*)sc_vram_03_attr },
    { (void*)sc_vram_04_pos, (void*)sc_vram_04_code, (void*)sc_vram_04_attr },
    { (void*)sc_vram_05_pos, (void*)sc_vram_04_code, (void*)sc_vram_04_attr },
    { (void*)sc_vram_06_pos, (void*)sc_vram_06_code, (void*)sc_vram_06_attr },
    { (void*)sc_vram_07_pos, (void*)sc_vram_06_code, (void*)sc_vram_07_attr },
    { (void*)sc_vram_06_pos, (void*)sc_vram_06_code, (void*)sc_vram_08_attr },
    { (void*)sc_vram_07_pos, (void*)sc_vram_06_code, (void*)sc_vram_09_attr },
    { (void*)sc_vram_06_pos, (void*)sc_vram_06_code, (void*)sc_vram_10_attr },
    { (void*)sc_vram_07_pos, (void*)sc_vram_06_code, (void*)sc_vram_11_attr },
    { (void*)sc_vram_12_pos, (void*)sc_vram_12_code, (void*)sc_vram_12_attr },
    { (void*)sc_vram_12_pos, (void*)sc_vram_12_code, (void*)sc_vram_13_attr },
    { (void*)sc_vram_14_pos, (void*)sc_vram_12_code, (void*)sc_vram_12_attr },
    { (void*)sc_vram_14_pos, (void*)sc_vram_12_code, (void*)sc_vram_13_attr },
    { (void*)sc_vram_16_pos, (void*)sc_vram_16_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_16_pos, (void*)sc_vram_16_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_18_pos, (void*)sc_vram_18_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_19_pos, (void*)sc_vram_19_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_20_pos, (void*)sc_vram_20_code, (void*)sc_vram_20_attr },
    { (void*)sc_vram_20_pos, (void*)sc_vram_21_code, (void*)sc_vram_20_attr },
    { (void*)sc_vram_20_pos, (void*)sc_vram_22_code, (void*)sc_vram_20_attr },
    { (void*)sc_vram_20_pos, (void*)sc_vram_23_code, (void*)sc_vram_20_attr },
    { (void*)sc_vram_24_pos, (void*)sc_vram_24_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_25_pos, (void*)sc_vram_25_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_26_pos, (void*)sc_vram_26_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_20_pos, (void*)sc_vram_27_code, (void*)sc_vram_20_attr },
    { (void*)sc_vram_28_pos, (void*)sc_vram_28_code, (void*)sc_vram_00_attr },
    { (void*)sc_vram_29_pos, (void*)sc_vram_29_code, (void*)sc_vram_29_attr },
};

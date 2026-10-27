/*
 * SC_DATA.C  text layer RAM-to-VRAM transfer table
 *
 * sc_ram_vram_tbl has 30 entries, each pointing at a position list, a character code list
 * and an attribute list in SC_TRANS_TBL.C; sc_ram_to_vram and its variant in SC_TRANS.C use
 * it to put prepared screen parts on the text layer.
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

const CELL_SET sc_ram_vram_tbl[30] = {
    { sc_vram_00_pos, sc_vram_00_code, sc_vram_00_attr },
    { sc_vram_01_pos, sc_vram_01_code, sc_vram_01_attr },
    { sc_vram_02_pos, sc_vram_02_code, sc_vram_02_attr },
    { sc_vram_03_pos, sc_vram_03_code, sc_vram_03_attr },
    { sc_vram_04_pos, sc_vram_04_code, sc_vram_04_attr },
    { sc_vram_05_pos, sc_vram_04_code, sc_vram_04_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_06_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_07_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_08_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_09_attr },
    { sc_vram_06_pos, sc_vram_06_code, sc_vram_10_attr },
    { sc_vram_07_pos, sc_vram_06_code, sc_vram_11_attr },
    { sc_vram_12_pos, sc_vram_12_code, sc_vram_12_attr },
    { sc_vram_12_pos, sc_vram_12_code, sc_vram_13_attr },
    { sc_vram_14_pos, sc_vram_12_code, sc_vram_12_attr },
    { sc_vram_14_pos, sc_vram_12_code, sc_vram_13_attr },
    { sc_vram_16_pos, sc_vram_16_code, sc_vram_00_attr },
    { sc_vram_16_pos, sc_vram_16_code, sc_vram_00_attr },
    { sc_vram_18_pos, sc_vram_18_code, sc_vram_00_attr },
    { sc_vram_19_pos, sc_vram_19_code, sc_vram_00_attr },
    { sc_vram_20_pos, sc_vram_20_code, sc_vram_20_attr },
    { sc_vram_20_pos, sc_vram_21_code, sc_vram_20_attr },
    { sc_vram_20_pos, sc_vram_22_code, sc_vram_20_attr },
    { sc_vram_20_pos, sc_vram_23_code, sc_vram_20_attr },
    { sc_vram_24_pos, sc_vram_24_code, sc_vram_00_attr },
    { sc_vram_25_pos, sc_vram_25_code, sc_vram_00_attr },
    { sc_vram_26_pos, sc_vram_26_code, sc_vram_00_attr },
    { sc_vram_20_pos, sc_vram_27_code, sc_vram_20_attr },
    { sc_vram_28_pos, sc_vram_28_code, sc_vram_00_attr },
    { sc_vram_29_pos, sc_vram_29_code, sc_vram_29_attr },
};

/*
 * PLPNM_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Normal_00000();
extern void Normal_01000();
extern void Normal_02000();
extern void Normal_03000();
extern void Normal_04000();
extern void Normal_05000();
extern void Normal_06000();
extern void Normal_07000();
extern void Normal_08000();
extern void Normal_09000();
extern void Normal_10000();
extern void Normal_11000();
extern void Normal_12000();
extern void Normal_13000();
extern void Normal_16000();
extern void Normal_17000();
extern void Normal_18000();
extern void Normal_27000();
extern void Normal_31000();
extern void Normal_35000();
extern void Normal_36000();
extern void Normal_37000();
extern void Normal_38000();
extern void Normal_39000();
extern void Normal_40000();
extern void Normal_41000();
extern void Normal_42000();
extern void Normal_47000();
extern void Normal_48000();
extern void Normal_50000();
extern void Normal_51000();
extern void Normal_52000();
extern void Normal_53000();
extern void Normal_54000();
extern void Normal_55000();
extern void Normal_56000();
extern void Normal_57000();
extern void Normal_58000();
extern void nm_05_0000();
extern void nm_05_0100();
extern void nm_06_0000();
extern void nm_06_0100();
extern void nm_06_0200();

const s16 nmPB_data[5][3] = {
    { 38, 23, 1 },
    { 39, 23, 1 },
    { 40, 24, 1 },
    { 41, 25, 0 },
    { 42, 25, 0 },
};

const s16 nmCE_data[4][3] = {
    { 43, 26, 1 },
    { 44, 27, 1 },
    { 45, 28, 0 },
    { 46, 29, 0 },
};

void (*const plpnm_lv_00[59])() = {
    Normal_00000,  Normal_01000,  Normal_02000,  Normal_03000,  /* 0 */
    Normal_04000,  Normal_05000,  Normal_06000,  Normal_07000,  /* 4 */
    Normal_08000,  Normal_09000,  Normal_10000,  Normal_11000,  /* 8 */
    Normal_12000,  Normal_13000,  Normal_13000,  Normal_13000,  /* 12 */
    Normal_16000,  Normal_17000,  Normal_18000,  Normal_18000,  /* 16 */
    Normal_18000,  Normal_18000,  Normal_18000,  Normal_18000,  /* 20 */
    Normal_18000,  Normal_18000,  Normal_18000,  Normal_27000,  /* 24 */
    Normal_27000,  Normal_27000,  Normal_27000,  Normal_31000,  /* 28 */
    Normal_31000,  Normal_31000,  Normal_35000,  Normal_35000,  /* 32 */
    Normal_36000,  Normal_37000,  Normal_38000,  Normal_39000,  /* 36 */
    Normal_40000,  Normal_41000,  Normal_42000,  Normal_42000,  /* 40 */
    Normal_42000,  Normal_42000,  Normal_42000,  Normal_47000,  /* 44 */
    Normal_48000,  Normal_47000,  Normal_50000,  Normal_51000,  /* 48 */
    Normal_52000,  Normal_53000,  Normal_54000,  Normal_55000,  /* 52 */
    Normal_56000,  Normal_57000,  Normal_58000,  /* 56 */
};

void (*const normal_05[24])() = {
    nm_05_0000,  nm_05_0000,  nm_05_0100,  nm_05_0000,  /* 0 */
    nm_05_0000,  nm_05_0000,  nm_05_0000,  nm_05_0000,  /* 4 */
    nm_05_0100,  nm_05_0000,  nm_05_0000,  nm_05_0100,  /* 8 */
    nm_05_0100,  nm_05_0000,  nm_05_0100,  nm_05_0100,  /* 12 */
    nm_05_0000,  nm_05_0100,  nm_05_0000,  nm_05_0000,  /* 16 */
    nm_05_0000,  nm_05_0000,  nm_05_0000,  nm_05_0000,  /* 20 */
};

void (*const normal_06[24])() = {
    nm_06_0100,  nm_06_0100,  nm_06_0200,  nm_06_0000,  /* 0 */
    nm_06_0100,  nm_06_0100,  nm_06_0100,  nm_06_0100,  /* 4 */
    nm_06_0000,  nm_06_0100,  nm_06_0000,  nm_06_0200,  /* 8 */
    nm_06_0200,  nm_06_0100,  nm_06_0200,  nm_06_0200,  /* 12 */
    nm_06_0000,  nm_06_0200,  nm_06_0100,  nm_06_0100,  /* 16 */
    nm_06_0100,  nm_06_0000,  nm_06_0000,  nm_06_0000,  /* 20 */
};

const u16 jpdat_tbl[9][2] = {
    { 0x11, 6 }, { 0x12, 7 }, { 0x13, 8 }, { 0xE, 9 }, { 0xF, 0xA }, { 0x10, 0xB }, { 0x14, 0xC }, { 0x15, 0xD },
    { 0x16, 0xE },
};

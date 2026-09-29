/*
 * PLS00_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void dm_00000();
extern void dm_04000();
extern void dm_08000();
extern void dm_17000();
extern void dm_18000();
extern void dm_25000();
extern void nm_00000();
extern void nm_01000();
extern void nm_02000();
extern void nm_03000();
extern void nm_05000();
extern void nm_07000();
extern void nm_08000();
extern void nm_09000();
extern void nm_10000();
extern void nm_11000();
extern void nm_13000();
extern void nm_16000();
extern void nm_17000();
extern void nm_18000();
extern void nm_27000();
extern void nm_29000();
extern void nm_31000();
extern void nm_34000();
extern void nm_36000();
extern void nm_37000();
extern void nm_38000();
extern void nm_39000();
extern void nm_40000();
extern void nm_42000();
extern void nm_45000();
extern void nm_47000();
extern void nm_48000();
extern void nm_49000();
extern void nm_51000();
extern void nm_52000();
extern void nm_55000();
extern void nm_57000();
extern void nm_91000();
extern void nm_95000();
extern void process_attack();
extern void process_catch();
extern void process_caught();
extern void process_damage();
extern void process_normal();

const s8 lvdir_conv[4] = {
    0, 2, 1, 0,
};

void (*const process_ndcca[5])() = {
    process_normal,
    process_damage,
    process_catch,
    process_caught,
    process_attack,
};

void (*const plpnm_xxxxx[59])() = {
    nm_00000,  nm_01000,  nm_02000,  nm_03000,  /* 0 */
    nm_03000,  nm_05000,  nm_05000,  nm_07000,  /* 4 */
    nm_08000,  nm_09000,  nm_10000,  nm_11000,  /* 8 */
    nm_11000,  nm_13000,  nm_13000,  nm_13000,  /* 12 */
    nm_16000,  nm_17000,  nm_18000,  nm_18000,  /* 16 */
    nm_18000,  nm_18000,  nm_18000,  nm_18000,  /* 20 */
    nm_18000,  nm_18000,  nm_18000,  nm_27000,  /* 24 */
    nm_27000,  nm_29000,  nm_27000,  nm_31000,  /* 28 */
    nm_31000,  nm_31000,  nm_34000,  nm_34000,  /* 32 */
    nm_36000,  nm_37000,  nm_38000,  nm_39000,  /* 36 */
    nm_40000,  nm_40000,  nm_42000,  nm_42000,  /* 40 */
    nm_42000,  nm_45000,  nm_45000,  nm_47000,  /* 44 */
    nm_48000,  nm_49000,  nm_49000,  nm_51000,  /* 48 */
    nm_52000,  nm_52000,  nm_51000,  nm_55000,  /* 52 */
    nm_55000,  nm_57000,  nm_55000,  /* 56 */
};

void (*const plpdm_xxxxx[39])() = {
    dm_00000,  dm_04000,  dm_04000,  dm_04000,  /* 0 */
    dm_04000,  dm_04000,  dm_04000,  dm_04000,  /* 4 */
    dm_08000,  dm_08000,  dm_08000,  dm_08000,  /* 8 */
    dm_04000,  dm_04000,  dm_18000,  dm_18000,  /* 12 */
    dm_04000,  dm_17000,  dm_18000,  dm_18000,  /* 16 */
    dm_18000,  dm_18000,  dm_18000,  dm_18000,  /* 20 */
    dm_00000,  dm_25000,  dm_18000,  dm_18000,  /* 24 */
    dm_18000,  dm_18000,  dm_18000,  dm_18000,  /* 28 */
    nm_91000,  nm_91000,  nm_91000,  nm_91000,  /* 32 */
    nm_95000,  nm_95000,  nm_95000,  /* 36 */
};


/*
 * EFFD3_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void effD2_wipe_close();
extern void effD2_wipe_open();

void (*const EFFD3_Jmp_Tbl[2])() = {
    effD2_wipe_close,
    effD2_wipe_open,
};

const s16 ake_timer_tbl[13] = {
    4, 4, 4, 4, 4, 10, 10, 10,
    10, 10, 10, 10, 20,
};

const s16 ake_pos_tbl[13][2] = {
    { 256, 768 },
    { 768, 0 },
    { 256, 768 },
    { 768, 0 },
    { 256, 768 },
    { 768, 0 },
    { 256, 0 },
    { 768, 256 },
    { 256, 256 },
    { 768, 512 },
    { 256, 512 },
    { 768, 768 },
    { 256, 768 },
};


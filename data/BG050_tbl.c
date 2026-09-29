/*
 * BG050_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void bg0802_init00();
extern void bg080_sync_init();
extern void bg080_sync_move();
extern void bg0901_init00();
extern void bg0902_init00();
extern void bg_base_move_common();
extern void bg_move_common();
extern void demo90_base();

const BG_JMP2 bg0802_jmp_tbl[5] = {
    { { bg0802_init00, bg_base_move_common } },
    { { bg080_sync_init, bg080_sync_move } },
    { { bg0901_init00, demo90_base } },
    { { bg_move_common, bg0902_init00 } },
    { { demo90_base, bg_base_move_common } },
};

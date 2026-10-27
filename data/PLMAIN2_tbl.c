/*
 * PLMAIN2_TBL.C  player move routines for the bonus stage
 *
 * plmain_b_lv_00 is the five routine_no[0] steps (player_mvbs_0000 .. 4000) of the bonus-stage
 * player move. Read by PLMAIN2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void player_mvbs_0000();
extern void player_mvbs_1000();
extern void player_mvbs_2000();
extern void player_mvbs_3000();
extern void player_mvbs_4000();

void (*const plmain_b_lv_00[5])() = {
    player_mvbs_0000,
    player_mvbs_1000,
    player_mvbs_2000,
    player_mvbs_3000,
    player_mvbs_4000,
};

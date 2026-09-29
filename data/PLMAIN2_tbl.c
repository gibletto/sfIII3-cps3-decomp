/*
 * PLMAIN2_TBL.C  game tables
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

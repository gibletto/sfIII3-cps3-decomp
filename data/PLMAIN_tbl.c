/*
 * PLMAIN_TBL.C  player move routine tables
 *
 * plmain_lv_00 is the five routine_no[0] steps (player_mv_0000 .. 4000) of the player move;
 * plmain_lv_02 the routine_no[1] states (normal, damage, catch, caught, attack), also used by
 * the bonus stage; sag_jmp_tbl the super art gauge process by gauge type (stock, timed,
 * rebirth). Read by PLMAIN.C and PLMAIN2.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Player_attack();
extern void Player_catch();
extern void Player_caught();
extern void Player_damage();
extern void Player_normal();
extern void player_mv_0000();
extern void player_mv_1000();
extern void player_mv_2000();
extern void player_mv_3000();
extern void player_mv_4000();
extern void sag_normal();
extern void sag_rebirth();
extern void sag_timer();

void (*const plmain_lv_00[5])() = {
    player_mv_0000,
    player_mv_1000,
    player_mv_2000,
    player_mv_3000,
    player_mv_4000,
};

void (*const plmain_lv_02[5])() = {
    Player_normal,
    Player_damage,
    Player_catch,
    Player_caught,
    Player_attack,
};

void (*const sag_jmp_tbl[4])() = {
    sag_normal,
    sag_timer,
    sag_normal,
    sag_rebirth,
};

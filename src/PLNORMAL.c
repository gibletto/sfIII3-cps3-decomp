/*
 * PLNORMAL.C  Player normal-state routines and win-pose moves
 *
 * The Normal_XXXXX routines are the entries of the player normal table: standing, crouching and
 * turning (Normal_02000 - 04000), forward and back dashes, walking, jump starts and jumps
 * (Normal_16000 - 26000), parry (Normal_31000), throw escapes (Normal_47000, Normal_48000), wall
 * jump (Normal_52000), extra jumps and other special movement states.
 * Each sets up its animation and speed data and lands through the jumping process when airborne.
 * The Winner_Pose_xxx routines are the win-pose moves (setup, hold, enter, exit).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "lose_pl.h"
#include "PLS02.h"
#include "PLSGAUGE.h"
#include "CHARMOVE.h"
#include "PLS00.h"
#include "EFFG6.h"
#include "EFFI3.h"
#include "Grade.h"
#include "PLS01.h"
#include "CHARSET.h"
#include "win_pl.h"
#include "PLNORMAL.h"

struct PLW_tag;void Normal_02000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 1);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_03000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 2);
        setup_mvxy_data(&wk->wu, 0);
        wk->wu.mvxy.a[0].sp >>= 1;
        add_mvxy_speed(&wk->wu);
        wk->wu.mvxy.a[0].sp *= 2;
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



void Normal_04000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 3);
        setup_mvxy_data((WORK*)wk, 1);
        add_mvxy_speed((WORK*)wk);
        break;
    case 1:
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        char_move((WORK*)wk);
        break;
    }
}



void Normal_05000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->running_f = 1;
    wk->guard_flag = 3;
    normal_05[wk->player_number](wk);
    jumping_guard_type_check(wk);
}



void nm_05_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 4);
        setup_mvxy_data((WORK*)wk, 2);
    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
        } else {
            char_move((WORK*)wk);
        }
        break;
    case 2:
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void nm_05_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 4);
        setup_mvxy_data((WORK*)wk, 2);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        break;
    case 2:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_06000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->running_f = 2;
    wk->guard_flag = 3;
    normal_06[wk->player_number](wk);
    jumping_guard_type_check(wk);
}



void nm_06_0000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void nm_06_0100(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        setup_mvxy_data((WORK*)wk, 3);
    case 1:
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            break;
        }
        char_move((WORK*)wk);
        break;
    case 2:
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void nm_06_0200(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 5);
        setup_mvxy_data((WORK*)wk, 3);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            add_mvxy_speed((WORK*)wk);
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        break;
    case 2:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        cal_mvxy_speed((WORK*)wk);
        add_mvxy_speed((WORK*)wk);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_07000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 11);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_08000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 6);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_09000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 7);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_10000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init((WORK*)wk, 0, 8);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_11000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + -1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 0x9);
        setup_mvxy_data(&wk->wu, 0x4);
        add_mvxy_speed(&wk->wu);
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



void Normal_12000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 10);
        setup_mvxy_data(&wk->wu, 5);
        add_mvxy_speed(&wk->wu);
        break;
    case 1:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        break;
    }
}



void Normal_13000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 50);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_16000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 0;
        set_char_move_init((WORK*)wk, 0, 12);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_17000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 0;
        set_char_move_init((WORK*)wk, 0, 13);
        break;
    case 1:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_18000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, jpdat_tbl[wk->wu.routine_no[2] - 18][0]);
        setup_mvxy_data(&wk->wu, jpdat_tbl[wk->wu.routine_no[2] - 18][1]);
        add_mvxy_speed(&wk->wu);
        wk->air_jump_ok_time = 4;
        wk->bs2_on_car = 0;
        break;
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
    jumping_guard_type_check(wk);
}



void Normal_18000_init_unit(PLW* wk, u8 ps) {
    ps = (ps - 14) / 2;
    if (ps > 8) {
        ps = 4;
    }
    set_char_move_init(&wk->wu, 0, jpdat_tbl[ps][0]);
    setup_mvxy_data(&wk->wu, jpdat_tbl[ps][1]);
    add_mvxy_speed(&wk->wu);
}



void Normal_27000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, wk->wu.routine_no[2] + 2);
        break;
    case 1:
        char_move(&wk->wu);
        break;
    }
}



void Normal_31000(PLW* wk) {
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        set_char_move_init((WORK*)wk, 0, wk->wu.routine_no[2] - 7);
        set_hit_stop_hit_quake((WORK*)wk);
        add_sp_arts_gauge_paring(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca((WORK*)wk);
        break;
    case 2:
        char_move((WORK*)wk);
        break;
    }
}



/* provisional name */
void Normal_air_paring(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.rl_flag != ((wk->wu.dm_rl + 1) & 1)) {
            wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        setup_air_paring_mvxy((WORK*)wk);
        set_char_move_init((WORK*)wk, 0, 27);
        add_sp_arts_gauge_paring(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init((WORK*)wk);
    case 2:
        if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
            wk->wu.next_z = 32;
        }
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_35000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    wk->guard_chuu = guard_kind[wk->wu.routine_no[2] - 27];
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.rl_flag != ((wk->wu.dm_rl + 1) & 1)) {
            wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
            wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
            wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
        }
        remake_mvxy_PoSB((WORK*)wk);
        set_char_move_init((WORK*)wk, 0, 27);
        add_sp_arts_gauge_paring(wk);
        break;
    case 1:
        wk->wu.routine_no[3]++;
        char_move_wca_init((WORK*)wk);
    case 2:
        if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
            wk->wu.next_z = 32;
        }
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_36000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    char_move((WORK*)wk);
}



void Normal_37000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    char_move((WORK*)wk);
}



void Normal_38000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
    jumping_guard_type_check(wk);
}



void Normal_39000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority - 1;
    }
    if (wk->wu.routine_no[3]) {
        char_move((WORK*)wk);
        return;
    }
    wk->wu.routine_no[3]++;
    set_char_move_init((WORK*)wk, 0, 23);
}



void Normal_40000(PLW* wk) {
    wk->wu.next_z = 38;
    win_player(wk);
}



void Normal_41000(PLW* wk) {
    wk->wu.next_z = 34;
    lose_player(wk);
}



void Normal_42000(PLW* wk) {
    const s16* dadr = nmPB_data[wk->wu.routine_no[2] - 42];
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = (wk->wu.dm_rl + 1) & 1;
        if (dadr[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }
        set_char_move_init((WORK*)wk, 0, dadr[0]);
        setup_mvxy_data((WORK*)wk, dadr[1]);
        Flash_MT[(wk->wu.id)] = 2;
        add_sp_arts_gauge_paring(wk);
        set_hit_stop_hit_quake((WORK*)wk);
        if (wk->wu.hit_stop > 0) {
            wk->wu.hit_stop = -wk->wu.hit_stop;
            break;
        }
        break;
    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca((WORK*)wk);
        } else {
        case 2:
            char_move((WORK*)wk);
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
            add_mvxy_speed((WORK*)wk);
            if (dadr[2]) {
                effect_G6_init((WORK*)wk, wk->wu.weight_level);
            }
        }
        break;
    case 3:
        jumping_union_process((WORK*)wk, 4);
        break;
    case 4:
        char_move((WORK*)wk);
        break;
    }
}



void Normal_47000(PLW* wk) {
    const s16* datix = nmCE_data[wk->wu.routine_no[2] - 47];
    if (((WORK*)wk->wu.target_adrs)->cg_prio != 2) {
        wk->wu.next_z = 32;
    }
    if (wk->wu.dm_work_id & 11) {
        wk->dm_hos_flag = 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        if (datix[2]) {
            wk->wu.xyz[1].disp.pos = 0;
        }
        set_char_move_init(&wk->wu, 0, datix[0]);
        setup_mvxy_data(&wk->wu, datix[1]);
        wk->wu.hit_stop = -18;
        wk->wu.hit_quake = 0;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        add_sp_arts_gauge_nagenuke(wk);
        grade_add_grap_def(wk->wu.id);
        break;
    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
        case 2:
            char_move(&wk->wu);
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
            if (datix[2]) {
                effect_G6_init(&wk->wu, wk->wu.weight_level);
                break;
            }
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Normal_48000(PLW* wk) {
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 0, 44);
        setup_mvxy_data(&wk->wu, 27);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        break;
    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
        case 2:
            char_move(&wk->wu);
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
            add_mvxy_speed(&wk->wu);
            effect_G6_init(&wk->wu, wk->wu.weight_level);
        }
        break;
    case 3:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        break;
    }
}



void Normal_50000(PLW* wk) {
    wk->guard_flag = 3;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        set_char_move_init(&wk->wu, 0, 46);
        setup_mvxy_data(&wk->wu, 29);
        wk->wu.hit_stop = -17;
        wk->wu.hit_quake = 8;
        wk->wu.dm_stop = wk->wu.dm_quake = 0;
        return;
    case 1:
        if (1) {
            wk->wu.routine_no[3]++;
            char_move_wca(&wk->wu);
        } else {
        case 2:
            char_move(&wk->wu);
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Normal_51000(PLW* wk) {
    if (wk->wu.routine_no[3] == 0) {
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 12);
    }
}



void Normal_52000(PLW* wk) {
    wk->guard_flag = 3;
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        remake_sankaku_tobi_mvxy((WORK*)wk, wk->micchaku_flag);
        set_char_move_init((WORK*)wk, 0, 48);
        effect_I3_init((WORK*)wk, 0);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = 21;
            wk->wu.routine_no[3] = 1;
            set_char_move_init((WORK*)wk, 0, 14);
            char_move_z((WORK*)wk);
            add_mvxy_speed((WORK*)wk);
        }
        break;
    }
}



void Normal_53000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        set_char_move_init(&wk->wu, 0, 49);
        break;
    case 1:
        char_move(&wk->wu);
        set_new_jpdir(wk);
        if (wk->wu.cg_type == 0xFF) {
            check_jump_rl_dir(wk);
            switch (wk->jpdir) {
            case 1:
                wk->wu.routine_no[2] = 21;
                break;
            case 2:
                wk->wu.routine_no[2] = 23;
                break;
            default:
                wk->wu.routine_no[2] = 22;
                break;
            }
            wk->wu.routine_no[3] = 1;
            set_char_move_init(&wk->wu, 0, jpdat_tbl[wk->wu.routine_no[2] - 18][0]);
            char_move_z(&wk->wu);
            setup_mvxy_data(&wk->wu, jpdat_tbl[wk->wu.routine_no[2] - 18][1]);
            wk->wu.mvxy.a[0].real.h = (wk->wu.mvxy.a[0].real.h * 6) / 10;
            wk->wu.mvxy.a[1].real.h = (wk->wu.mvxy.a[1].real.h << 3) / 10;
            add_mvxy_speed(&wk->wu);
        }
        break;
    }
}



void Normal_54000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init((WORK*)wk, 0, 12);
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[2] = 18;
            wk->wu.routine_no[3] = 0;
            if (wk->wu.rl_flag != check_work_position((WORK*)wk, (WORK*)wk->wu.target_adrs)) {
                wk->wu.routine_no[2] = 20;
            }
        }
        break;
    }
}



void Normal_55000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->bs2_on_car = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->extra_jump = 1;
        set_char_move_init((WORK*)wk, 0, 18);
        setup_mvxy_data((WORK*)wk, 7);
        make_nm55_init_sp(wk);
        add_mvxy_speed((WORK*)wk);
        break;
    case 1:
        jumping_union_process((WORK*)wk, 2);
        break;
    case 2:
        char_move((WORK*)wk);
        break;
    }
}



void make_nm55_init_sp(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;
    s16 isp;
    wk->wu.mvxy.a[1].sp /= 3;
    isp = (wk->move_power << 2) / 5;
    if (isp < 3) {
        isp = 3;
    }
    wk->wu.mvxy.a[0].real.h = isp;
    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = efw->hosei_adrs[ix].hos_box;
    if (!check_work_position_bonus(&wk->wu, efw->xyz[0].disp.pos + dad[0] + (dad[1] / 2))) {
        if (wk->wu.rl_flag) {
            wk->wu.mvxy.a[0].real.h = -wk->wu.mvxy.a[0].real.h;
        }
        return;
    }
    if (wk->wu.rl_flag == 0) {
        wk->wu.mvxy.a[0].real.h = -wk->wu.mvxy.a[0].real.h;
    }
}



void Normal_56000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    wk->bs2_on_car = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        nm56_char_select(wk);
        add_mvxy_speed(&wk->wu);
        wk->bs2_on_car = 0;
        break;
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
}



void nm56_char_select(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;
    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = efw->hosei_adrs[ix].hos_box;
    setup_mvxy_data(&wk->wu, 17);
    ix = 16;
    if (check_work_position_bonus(&wk->wu, efw->xyz[0].disp.pos + dad[0] + (dad[1] / 2))) {
        if (wk->wu.rl_flag) {
            ix = 14;
        }
    } else if (wk->wu.rl_flag == 0) {
        ix = 14;
    }
    if (ix == 14) {
        wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
    }
    set_char_move_init(&wk->wu, 0, ix);
}



void Normal_57000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        nm57_dir_select(wk);
        wk->wu.xyz[1].disp.pos = 0;
        set_char_move_init(&wk->wu, 0, 50);
        setup_mvxy_data(&wk->wu, 18);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
            add_mvxy_speed(&wk->wu);
            effect_G6_init(&wk->wu, wk->wu.weight_level);
            break;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void nm57_dir_select(PLW* wk) {
    WORK* efw;
    s16* dad;
    s16 ix;
    efw = (WORK*)((WORK*)wk->wu.target_adrs)->my_effadrs;
    ix = get_sel_hosei_tbl_ix(wk->player_number) + 1;
    dad = (s16*)efw->hosei_adrs[ix].hos_box;
    wk->wu.rl_flag = 1;
    if (check_work_position_bonus((WORK*)wk, dad[0] + efw->xyz[0].disp.pos + (dad[1] / 2))) {
        wk->wu.rl_flag = 0;
    }
}



void Normal_58000(PLW* wk) {
    if (wk->the_same_players) {
        wk->wu.next_z = wk->wu.my_priority + 1;
    }
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 0, 18);
        setup_mvxy_data(&wk->wu, 7);
        break;
    case 1:
        jumping_union_process(&wk->wu, 2);
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
}

/*
 * EFFJ7.C  Effect J7: Gill's two-sided palette animation
 *
 * effect_J7_init (from PLCNTDAT.c) creates the effect only for character 0 (Gill) played as
 * himself, and records the player's colour choice. effect_J7_move starts when gill_ccch_go is
 * set or the player reaches his start state, and steps two colour tables from pl00_cctbl (one
 * for each side of the body) through the player's two 48-word palette blocks in palette RAM,
 * swapping them to match the player's facing; get_new_color_data loads each step's colours,
 * timer and end code. When the player's vitality falls below zero it returns to the first step
 * and holds while the player is in move state 4/21.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EFFECT.h"
#include "EFFJ7.h"
#include "cps3.h"
#include "fighter.h"


void effect_J7_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    ewk->wu.rl_flag = mwk->wu.rl_flag;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (mwk->gill_ccch_go == 0 && (mwk->wu.routine_no[1] != 0 || mwk->wu.routine_no[2] != 1)) {
            break;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.hit_adrs = (u32*)pl00_cctbl[ewk->wu.type][0];
        ewk->wu.dmg_adrs = (u32*)pl00_cctbl[ewk->wu.type][1];
        ewk->wu.step_xy_table = (s16*)COLOR_RAM + (ewk->master_id == 1) * 1024;
        ewk->wu.move_xy_table = ewk->wu.step_xy_table + 512;
        ewk->wu.dir_timer = 0;
        ewk->wu.dir_step = 0;
        ewk->wu.dir_old = 1;
        do { if (--(&ewk->wu)->dir_timer < 0) { if ((&ewk->wu)->dir_old) { (&ewk->wu)->dir_step = 1; } else { (&ewk->wu)->dir_step++; } if ((&ewk->wu)->rl_flag) { get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->hit_adrs, (&ewk->wu)->step_xy_table); get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->dmg_adrs, (&ewk->wu)->move_xy_table); } else { get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->dmg_adrs, (&ewk->wu)->move_xy_table); get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->hit_adrs, (&ewk->wu)->step_xy_table); } } } while (0);
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] = 3;
        } else if (mwk->wu.vital_new < 0) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.routine_no[1] = 0;
        } else if (EXE_flag == 0 && Game_pause == 0) {
            do { if (--(&ewk->wu)->dir_timer < 0) { if ((&ewk->wu)->dir_old) { (&ewk->wu)->dir_step = 1; } else { (&ewk->wu)->dir_step++; } if ((&ewk->wu)->rl_flag) { get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->hit_adrs, (&ewk->wu)->step_xy_table); get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->dmg_adrs, (&ewk->wu)->move_xy_table); } else { get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->dmg_adrs, (&ewk->wu)->move_xy_table); get_new_color_data((&ewk->wu), (ColorCode*)(&ewk->wu)->hit_adrs, (&ewk->wu)->step_xy_table); } } } while (0);
        }
        break;
    case 2:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.dir_timer = 0;
            ewk->wu.dir_step = 0;
            ewk->wu.dir_old = 1;
            if (ewk->wu.rl_flag) {
                get_new_color_data(&ewk->wu, (ColorCode*)ewk->wu.hit_adrs, ewk->wu.step_xy_table);
                get_new_color_data(&ewk->wu, (ColorCode*)ewk->wu.dmg_adrs, ewk->wu.move_xy_table);
            } else {
                get_new_color_data(&ewk->wu, (ColorCode*)ewk->wu.dmg_adrs, ewk->wu.move_xy_table);
                get_new_color_data(&ewk->wu, (ColorCode*)ewk->wu.hit_adrs, ewk->wu.step_xy_table);
            }
            break;
        case 1:
            if (mwk->wu.routine_no[1] == 4 && mwk->wu.routine_no[2] == 21) {
                ewk->wu.routine_no[1]++;
            }
            break;
        case 2:
            if (mwk->wu.routine_no[1] != 4 || mwk->wu.routine_no[2] != 21) {
                ewk->wu.routine_no[0] = 1;
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        break;
    default:
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void get_new_color_data(WORK* wk, ColorCode* trom, s16* tram) {
    const s16* data;
    s32 i;
    wk->dir_timer = trom[wk->dir_step].timer;
    wk->dir_old = trom[wk->dir_step].endcode;
    data = trom[wk->dir_step].adrs;
    for (i = 0; i < 48; i++) {
        *tram++ = *data++;
    }
}



s32 effect_J7_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (wk->player_number != PL_GILL) {
        return 0;
    }
    if (My_char[wk->wu.id] != PL_GILL) {
        return 0;
    }
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 197;
    ewk->wu.work_id = 16;
    ewk->wu.type = Player_Color[wk->wu.id];
    ewk->my_master = (u32*)wk;
    ewk->master_id = wk->wu.id;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_player = wk->player_number;
    return 0;
}

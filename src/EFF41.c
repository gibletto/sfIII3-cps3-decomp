/*
 * EFF41.C  Effect 41 (super art sign)
 *
 * effect_41_init creates the super art sign for a player (not in test mode).
 * Effect 41 is the sign shown when a super art or EX move is used: it plays the sa_sign_data
 * animation beside the player, flashes the super-art gauge, and on cue creates effect D9 and
 * consumes the gauge (gauge_minus, which also adds to the super-art grade).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "aboutspr.h"
#include "EFFD9.h"
#include "effect_2.h"
#include "Grade.h"
#include "EFF41.h"
#include "SYS_sub.h"
#include "EFF42.h"

/* routine_no[0] */
#define R0_INIT         0       /* set up and flash the gauge */
#define R0_MOVE         1       /* animate beside the player */
#define R0_END          2       /* leave the player's shell list */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1]: where the sign is placed */
#define R1_BESIDE       0       /* (default) beside the player */
#define R1_LOW          1       /* on the floor under the player */
#define R1_SCREEN       2       /* at the centre of the screen */

/* sa_sign_data columns */
#define SA_SIGN_X       0       /* x offset from the player, mirrored by rl_flag */
#define SA_SIGN_Y       1       /* y offset from the player */
#define SA_SIGN_CHAR    2       /* animation number */
#define SA_SIGN_GAUGE   3       /* gauge used: 1 super art, 2 EX */
#define SA_SIGN_PLACE   4       /* placing routine, eff41_main_process */



void effect_41_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        ewk->wu.routine_no[1] = R1_BESIDE;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.position_z = 24;
        switch (sa_sign_data[ewk->wu.type][SA_SIGN_GAUGE]) {
        case 1:
            sa_gauge_flash[mwk->wu.id] |= 4;
            break;
        case 2:
            sa_gauge_flash[mwk->wu.id] |= 4;
        default:
            break;
        }
        set_char_move_init(&ewk->wu, 0, sa_sign_data[ewk->wu.type][SA_SIGN_CHAR]);
        goto jump;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1 || mwk->wu.routine_no[1] != PLAYER_ATTACK) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.hit_stop) {
                ewk->wu.hit_stop--;
            } else {
                char_move(&ewk->wu);
            }
        }
        if (ewk->wu.cg_type == 4) {
            ewk->wu.cg_type = 0;
            effect_D9_init(mwk, 7);
        }
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[0]++;
            ewk->wu.disp_flag = 0;
            break;
        }
    jump:
        eff41_main_process[sa_sign_data[ewk->wu.type][SA_SIGN_PLACE]](ewk, mwk);
        ewk->wu.cg_type = 0;
        sort_push_request(&ewk->wu);
        break;
    case R0_END:
        erase_my_shell_ix((WORK*)ewk->my_master, ewk->wu.myself);
        ewk->wu.routine_no[0] = R0_KILL;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void eff41_process_00(WORK_Other* ewk, PLW* mwk) {
    if (ewk->wu.cg_type == 1) {
        gauge_minus(ewk, mwk);
    }
    ewk->wu.position_x = mwk->wu.position_x;
    if (mwk->wu.rl_flag) {
        ewk->wu.position_x -= sa_sign_data[ewk->wu.type][SA_SIGN_X];
    } else {
        ewk->wu.position_x += sa_sign_data[ewk->wu.type][SA_SIGN_X];
    }
    ewk->wu.position_y = mwk->wu.position_y + sa_sign_data[ewk->wu.type][SA_SIGN_Y];
}



void eff41_process_01(WORK_Other* ewk, PLW* mwk) {
    const s16 (*t)[5];
    switch (ewk->wu.cg_type) {
    case 1:
        gauge_minus(ewk, mwk);
        ewk->wu.routine_no[1] = R1_LOW;
        break;
    case 2:
        ewk->wu.routine_no[1] = R1_SCREEN;
        break;
    }
    t = sa_sign_data;
    switch (ewk->wu.routine_no[1]) {
    case R1_LOW:
        ewk->wu.position_x = mwk->wu.position_x;
        ewk->wu.position_y = 0;
        break;
    case R1_SCREEN:
        ewk->wu.position_x = bg_w.bgw[1].position_x + bg_w.pos_offset;
        ewk->wu.position_y = mwk->wu.position_y + t[ewk->wu.type][SA_SIGN_Y];
        break;
    default:
        ewk->wu.position_x = mwk->wu.position_x;
        if (mwk->wu.rl_flag) {
            ewk->wu.position_x -= t[ewk->wu.type][SA_SIGN_X];
        } else {
            ewk->wu.position_x += t[ewk->wu.type][SA_SIGN_X];
        }
        ewk->wu.position_y = mwk->wu.position_y + t[ewk->wu.type][SA_SIGN_Y];
        break;
    }
}



void gauge_minus(WORK_Other* ewk, PLW* mwk) {
    switch (sa_sign_data[ewk->wu.type][SA_SIGN_GAUGE]) {
    case 1:
        mwk->sa->saeff_ok = -1;
        grade_add_super_arts(mwk->wu.id, 1);
        break;
    case 2:
        mwk->sa->saeff_mp = -1;
        grade_add_super_arts(mwk->wu.id, 2);
        return;
    }
}



s32 effect_41_init(PLW* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if (!test_flag) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        write_my_shell_ix(&wk->wu, ix);
        ewk->wu.be_flag = 1;
        ewk->wu.type = data;
        ewk->wu.id = 41;
        ewk->wu.work_id = 16;
        ewk->wu.my_family = wk->wu.my_family;
        ewk->wu.cgromtype = 1;
        ewk->my_master = (u32*)wk;
        ewk->master_work_id = wk->wu.work_id;
        ewk->master_id = wk->wu.id;
        *ewk->wu.char_table = plef_char_table;
        return 0;
    }
}




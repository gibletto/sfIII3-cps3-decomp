/*
 * EFFJ9.C  Effect J9: object beside the bonus-stage car
 *
 * effect_J9_init is called by the car effect C2 (EFFC2.C) and places the object at the car's
 * position; it uses the car's character set (0x17) with priority 68. effect_J9_move plays pattern
 * 0x44 and shakes it with the car (get_c2_quake reads c2quake_table by the car's frame); when the
 * car switches to pattern 0x47 it changes to pattern 0x45 and then follows the car's x. Its push
 * box follows the car's state (player_hosei_data). effJ9_trans draws it at x + shake offset.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFC2.h"
#include "CHARID.h"
#include "CHARMOVE.h"
#include "EFFJ9.h"




void effect_J9_move(WORK_Other* ewk) {

    WORK* c2wk = (WORK*)ewk->my_master;
    s32 k;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.charset_id = 0x17;
        set_char_base_data(&ewk->wu);
        ewk->wu.my_col_mode = 0x4400;
        ewk->wu.my_col_code = 0x2022;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.my_priority = 68;
        ewk->wu.next_x = 0;
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            k = 0x44;
            goto bind;
        case 1:
            ewk->wu.next_x = get_c2_quake(c2wk);
            if (c2wk->char_index == 0x47) {
                ewk->wu.next_x = 0;
                k = 0x45;
                ewk->wu.routine_no[1]++;
            bind:
                set_char_move_init(&ewk->wu, 0, k);
            }
            break;
        default:
            ewk->wu.xyz[0].disp.pos = c2wk->xyz[0].disp.pos;
            break;
        }
        player_hosei_data(ewk, c2wk->dir_timer);
        effJ9_trans(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effJ9_trans(WORK* wk) {
    wk->position_x = wk->xyz[0].disp.pos + wk->next_x;
    sort_push_request(wk);
}


s16 get_c2_quake(WORK* c2wk) {
    u16 c2cg;
    if ((c2cg = c2wk->cg_number) > 18) {
        return 0;
    }
    return c2quake_table[c2cg];
}



s32 effect_J9_init(WORK_Other* wk, u8 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 199;
    ewk->wu.work_id = 16;
    ewk->wu.type = data;
    ewk->my_master = (u32*)wk;
    ewk->master_player = wk->master_player;
    ewk->master_id = wk->master_id;
    ewk->master_work_id = wk->master_work_id;
    ewk->wu.xyz[0].disp.pos = wk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = wk->wu.xyz[1].disp.pos;
    return 0;
}

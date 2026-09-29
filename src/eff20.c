/*
 * EFF20.C  Finish-screen overlay sprite (effect 20)
 *
 * A single sprite created by the Shun Goku Satsu finish screen (syungoku_finish in EFFD3).
 * effect_20_init places it at the stage centre facing like the winner, using the etc2
 * character table with animation 49; effect_20_move plays the animation once, keeps it
 * locked to BG1's X position, and clears its parent's old_rno[0] while running and sets it
 * again when the animation ends so the parent can continue.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "eff20.h"



void effect_20_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1]++;
        ewk->wu.disp_flag = 1;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        oya->wu.old_rno[0] = 0;
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos + 8;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        break;
    case 1:
        char_move(&ewk->wu);
        if (ewk->wu.cg_type == 0xFF) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            oya->wu.old_rno[0] = 1;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[1]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_20_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 20;
    ewk->wu.work_id = 16;
    ewk->wu.my_priority = 0x40;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = plw[Winner_id].wu.rl_flag;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 0x39;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = 40;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.my_priority = ewk->wu.position_z = 16;
    ewk->wu.char_index = 49;
    return 0;
}

/*
 * EFFECT_L9_MOVE.C  Finish-screen sprites (effect L9)
 *
 * Two sprites shown by the Shun Goku Satsu finish screen (syungoku_finish in EFFD3).
 * effect_L9_init(oya, type) creates either the large piece (animation 53, offset by the
 * winner's facing) or the small one (animation 48) at the stage centre.
 * effect_L9_move plays the animation locked to BG1's X position and hides and frees the
 * sprite once the parent screen reaches its closing state.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "effect_L9_move.h"



void effect_L9_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[1]) {
    case 0:
        ewk->wu.routine_no[1] += 1;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        break;
    case 1:
        char_move(&ewk->wu);
        if (oya->wu.routine_no[0] >= 3) {
            ewk->wu.routine_no[1] += 1;
            ewk->wu.disp_flag = 0;
        }
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
        ewk->wu.xyz[0].disp.pos += ewk->wu.old_rno[0];
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
        sort_push_request4(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[1] += 1;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_L9_init(WORK_Other* oya, u8 ten_type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->my_master = (u32*)oya;
    ewk->master_id = oya->wu.id;
    ewk->wu.type = ten_type;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 219;
    ewk->wu.work_id = 16;
    ewk->wu.my_priority = 64;
    ewk->wu.cgromtype = 1;
    ewk->wu.rl_flag = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.char_table[0] = etc2_char_table;
    ewk->wu.my_family = 2;
    ewk->wu.my_col_code = 57;
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[1].wxy[0].disp.pos;
    if (ewk->wu.type) {
        ewk->wu.char_index = 53;
        if (plw[Winner_id].wu.rl_flag) {
            ewk->wu.old_rno[0] = -1;
        } else {
            ewk->wu.old_rno[0] = 0;
        }
        ewk->wu.my_priority = ewk->wu.position_z = 9;
        ewk->wu.xyz[1].disp.pos = 40;
    } else {
        ewk->wu.char_index = 48;
        ewk->wu.old_rno[0] = 0;
        ewk->wu.my_priority = ewk->wu.position_z = 17;
        ewk->wu.xyz[1].disp.pos = 24;
    }
    return 0;
}

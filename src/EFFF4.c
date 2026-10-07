/*
 * EFFF4.C  Effects F3 and F4: slide-in select sprite and BG3 flash
 *
 * Effect F3 (effect_F3_init with step, delay, y and entry side) shows sel_pl_char_table pattern
 * 39 after its delay and slides it in from the left or right edge of BG0 (effF3_pos_set) with a
 * decelerating speed until it stops at DE_X[14] + 32 relative to BG0.
 * Effect F4 flashes the screen between the normal scroll layers and BG3: on its first frame it
 * shows only BG3, then toggles the layers every frame for old_rno[0] frames and restores the
 * normal layers, keeping the BG3 sprite slot and position set each frame. akebono_flag cuts the
 * flash short. effect_F4_init is an empty stub.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "EFFF4.h"



void effect_F3_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (--ewk->wu.dir_timer != 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.mvxy.a[0].sp > 0) {
            if (ewk->wu.dir_old <= ewk->wu.xyz[0].disp.pos) {
                ewk->wu.routine_no[0]++;
                ewk->wu.xyz[0].disp.pos = ewk->wu.dir_old;
            }
        } else if (ewk->wu.dir_old >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0]++;
            ewk->wu.xyz[0].disp.pos = ewk->wu.dir_old;
        }
        break;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



s32 effect_F3_init(s16 step, s16 delay, s16 x, s16 y) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 153;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 1;
    ewk->wu.dir_timer = delay;
    ewk->wu.char_table[0] = sel_pl_char_table;
    ewk->wu.char_index = 39;
    ewk->wu.dir_step = step;
    ewk->wu.my_col_code = 0x2043;
    ewk->wu.xyz[1].disp.pos = y;
    ewk->wu.position_z = 80;
    effF3_pos_set(ewk, x);
    return 0;
}



/* provisional name */
void effF3_pos_set(WORK_Other* ewk, s16 x) {
    if (x == 4) {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].xy[0].disp.pos + 576;
        ewk->wu.mvxy.a[0].sp = -0x150000;
        ewk->wu.mvxy.d[0].sp = -0x18000;
    } else {
        ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].xy[0].disp.pos - 384;
        ewk->wu.mvxy.a[0].sp = 0x150000;
        ewk->wu.mvxy.d[0].sp = 0x18000;
    }
    ewk->wu.dir_old = bg_w.bgw[0].xy[0].disp.pos + DE_X[14] + 32;
}



void effect_F4_move(WORK_Other* ewk) {
    s16 i;
    if (akebono_flag) {
        ewk->wu.old_rno[0] = -1;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        for (i = 0; i < bg_w.scno; i++) {
            scroll_layer_mask_disable(1 << i);
        }
        scroll_layer_mask_enable(8);
        ewk->wu.disp_flag = 1;
        scrn_map_set_now(3, (u32)bg_w.bgw[3].bg_address);
        Scrn_Move_Set_R(3, 0x100 - bg_w.pos_offset, 0x200);
        break;
    case 1:
        ewk->wu.old_rno[0]--;
        if (ewk->wu.old_rno[0] > 0) {
            ewk->wu.disp_flag ^= 1;
            if (ewk->wu.disp_flag) {
                for (i = 0; i < bg_w.scno; i++) {
                    scroll_layer_mask_disable(1 << i);
                }
                scroll_layer_mask_enable(8);
            } else {
                for (i = 0; i < bg_w.scno; i++) {
                    scroll_layer_mask_enable(1 << i);
                }
                scroll_layer_mask_disable(8);
            }
        } else {
            ewk->wu.routine_no[0]++;
            for (i = 0; i < bg_w.scno; i++) {
                scroll_layer_mask_enable(1 << i);
            }
            scroll_layer_mask_disable(8);
        }
        scrn_map_set_now(3, (u32)bg_w.bgw[3].bg_address);
        Scrn_Move_Set_R(3, 0x100 - bg_w.pos_offset, 0x200);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



void effect_F4_init(WORK_Other* ewk) {}


/* provisional name */
void effect_F4_dummy(void) {}

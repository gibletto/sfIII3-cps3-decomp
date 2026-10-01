/*
 * EFFE1.C  Effect E1: large centre-screen sprites of the opening
 *
 * effect_E1_init creates one of two etc_char_table sprites (patterns 0x59 and 0x5A) at the screen
 * centre (0x200, 0x90) on BG1, with zoom size 63 and priorities 0x45 / 0x44. end_main.c starts
 * both, together with two F5 effects, when it draws the opening Capcom logo
 * (opening_capcom_logo_draw). effect_E1_move starts the pattern once and then simply draws the
 * sprite every frame.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "EFFE1.h"



void effect_E1_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
    case 1:
        ewk->wu.my_mr.size.x = 63;
        ewk->wu.my_mr.size.y = 63;
    }
    ewk->wu.position_x = (u16)ewk->wu.xyz[0].disp.pos & 0x3FF;
    ewk->wu.position_y = (u16)ewk->wu.xyz[1].disp.pos & 0x3FF;
    sort_push_request4(ewk);
}



s32 effect_E1_init(s16 id, s16 Time, s16 _p2) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x8D;
    ewk->wu.work_id = 0x10;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0xC0;
    ewk->wu.my_family = 1;
    ewk->wu.dir_timer = Time;
    ewk->wu.char_table[0] = etc_char_table;
    ewk->wu.my_mr.size.x = 0x3F;
    ewk->wu.my_mr.size.y = 0x3F;
    switch (id) {
    case 0:
        ewk->wu.char_index = 0x59;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.my_priority = ewk->wu.position_z = 0x45;
        break;
    case 1:
        ewk->wu.my_priority = ewk->wu.position_z = 0x44;
        ewk->wu.xyz[0].disp.pos = 0x200;
        ewk->wu.xyz[1].disp.pos = 0x90;
        ewk->wu.char_index = 0x5A;
        break;
    }
    return 0;
}

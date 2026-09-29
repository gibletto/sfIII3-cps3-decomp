/*
 * EFF22.C  Effect 22: falling snow (bg050)
 *
 * effect_22_init creates twelve snow works. Each starts from snow_pos_tbl, drifts with one
 * of four speed sets from snow_sp and restarts at the top when it falls below the floor.
 * Called from bg050.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "CHARSET.h"
#include "EFF22.h"



void effect_22_move(WORK_Other* ewk) {
    const s32* ptr;
    if (obr_disp_off_check()) {
        return;
    }
    if (compel_dead_check(ewk) != 0) {
        ewk->wu.routine_no[0] = 99;
        ewk->wu.disp_flag = 0;
        return;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.dead_f = 1;
        set_char_move_init(&ewk->wu, 0, 11);
        ewk->wu.disp_flag = 1;
        ewk->wu.old_rno[0] = 0;
    case 1:
        ewk->wu.routine_no[0]++;
        ptr = &snow_sp[ewk->wu.old_rno[0]][ewk->wu.type][0];
        ewk->wu.mvxy.a[0].sp = *ptr++;
        ewk->wu.mvxy.d[0].sp = *ptr++;
        ewk->wu.mvxy.a[1].sp = *ptr++;
        ewk->wu.mvxy.d[1].sp = *ptr++;
        ewk->wu.xyz[0].disp.pos = snow_pos_tbl[ewk->wu.type][0];
        ewk->wu.xyz[1].disp.pos = snow_pos_tbl[ewk->wu.type][1];
        ewk->wu.old_rno[0]++;
        ewk->wu.old_rno[0] &= 3;
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos < 0x18) {
                ewk->wu.routine_no[0] = 1;
            }
        }
        disp_pos_trans_entry_r(ewk);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_22_init(void) {
    s16 ix;
    s16 i;
    WORK_Other* ewk;
    for (i = 0; i < 12; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.be_flag = 1;
        ewk->wu.id = 22;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.type = i;
        ewk->wu.my_family = 2;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 128;
        ewk->wu.char_table[0] = rca_char_table;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
    }
    return 0;
}

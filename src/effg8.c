/*
 * EFFG8.C  Finish-screen sparkles (effect G8)
 *
 * Sixteen sparkles started by akebono_finish (EFFD3) once its picture sequence ends.
 * effect_G8_init creates them; effect_G8_move waits a random delay, grows each sparkle
 * from zoom 0 while it drifts with speeds from effg8_speed_tbl, and frees it when it leaves
 * the box tested by effg8_range_check or when the finish screen (akebono_flag) ends.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "CHARMOVE.h"
#include "effg8.h"



void effect_G8_move(WORK_Other* ewk) {
    if (!akebono_flag) {
        ewk->wu.routine_no[0] = 99;
    }
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.my_mr_flag = 1;
        ewk->wu.my_mr.size.x = 0;
        ewk->wu.my_mr.size.y = 0;
        set_char_move_init(&ewk->wu, 0, 17);
        ewk->wu.old_rno[3] = random_16_com();
        ewk->wu.old_rno[0] = 512;
        ewk->wu.old_rno[1] = 112;
        ewk->wu.xyz[0].disp.pos = ewk->wu.old_rno[0];
        ewk->wu.xyz[1].disp.pos = ewk->wu.old_rno[1];
        ewk->wu.mvxy.a[0].sp = effg8_speed_tbl[ewk->wu.old_rno[2]][0];
        ewk->wu.mvxy.d[0].sp = effg8_speed_tbl[ewk->wu.old_rno[2]][1];
        ewk->wu.mvxy.a[1].sp = effg8_speed_tbl[ewk->wu.old_rno[2]][2];
        ewk->wu.mvxy.d[1].sp = effg8_speed_tbl[ewk->wu.old_rno[2]][3];
        break;
    case 1:
        ewk->wu.old_rno[3] -= 1;
        if (ewk->wu.old_rno[3] > 0) {
            break;
        }
        ewk->wu.routine_no[0] += 1;
        ewk->wu.disp_flag = 1;
    case 2:
        ewk->wu.my_mr.size.x += 2;
        ewk->wu.my_mr.size.y += 2;
        if (ewk->wu.my_mr.size.x >= 63) {
            ewk->wu.routine_no[0] += 1;
        }
    case 3:
        add_x_sub(ewk);
        add_y_sub(ewk);
        if (effg8_range_check(ewk)) {
            ewk->wu.routine_no[0] = 99;
            break;
        }
        ewk->wu.position_x = (ewk->wu.xyz[0].disp.pos & 0x3FF);
        ewk->wu.position_y = (ewk->wu.xyz[1].disp.pos & 0x3FF);
        sort_push_request4(ewk);
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    }
}



s16 effg8_range_check(WORK_Other* ewk) {
    if (ewk->wu.xyz[0].disp.pos < 408) {
        return 1;
    }
    if (ewk->wu.xyz[0].disp.pos > 616) {
        return 1;
    }
    if (ewk->wu.xyz[1].disp.pos < 48) {
        return 1;
    }
    if (ewk->wu.xyz[1].disp.pos > 192) {
        return 1;
    }
    return 0;
}



s32 effect_G8_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    for (i = 0; i < 16; i++) {
        if ((ix = pull_effect_work(4)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->wu.id = 168;
        ewk->wu.be_flag = 1;
        ewk->wu.type = i;
        ewk->wu.work_id = 16;
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 448;
        ewk->wu.char_table[0] = etc2_char_table;
        ewk->wu.my_family = 4;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.old_rno[2] = i;
    }
    return 0;
}

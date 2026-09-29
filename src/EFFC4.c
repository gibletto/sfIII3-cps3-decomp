/*
 * EFFC4.C  Effect C4: bouncing object (move)
 *
 * effect_C4_move starts the object's pattern and runs it through three flight phases whose speeds
 * come from effC4_sp_tbl: each time it falls below the floor the next phase starts (a bounce),
 * with a landing sound requested on the first landing. After the last bounce it slides left,
 * still animating, and is hidden and freed once it passes x 128. It shows a shadow and uses
 * direct_03_char_table; the init, effect_C4_init, is in EFFC5.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "SE.h"
#include "EFFC4.h"



void effect_C4_move(WORK_Other* ewk) {
    const s32* spd;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, ewk->wu.char_index);
        spd = effC4_sp_tbl[ewk->wu.routine_no[0]];
        ewk->wu.mvxy.a[0].sp = *spd++;
        ewk->wu.mvxy.a[1].sp = *spd++;
        ewk->wu.mvxy.d[0].sp = *spd++;
        ewk->wu.mvxy.d[1].sp = *spd;
        break;
    case 1:
    case 2:
    case 3:
        if (EXE_flag == 0 && Game_pause == 0) {
            if (ewk->wu.cg_type != 2) {
                char_move(&ewk->wu);
            }
            add_x_sub(ewk);
            add_y_sub(ewk);
            if (ewk->wu.xyz[1].disp.pos < 0) {
                if (ewk->wu.routine_no[0] == 1) {
                    Sound_SE(ewk->master_id * 0x300 + 0x264);
                }
                ewk->wu.routine_no[0]++;
                spd = effC4_sp_tbl[ewk->wu.routine_no[0]];
                ewk->wu.mvxy.a[0].sp = *spd++;
                ewk->wu.mvxy.a[1].sp = *spd++;
                ewk->wu.mvxy.d[0].sp = *spd++;
                ewk->wu.mvxy.d[1].sp = *spd;
                char_move_z(&ewk->wu);
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(ewk);
        break;
    case 4:
        if (EXE_flag == 0 && Game_pause == 0) {
            add_x_sub(ewk);
            char_move(&ewk->wu);
            if (ewk->wu.xyz[0].disp.pos < 128) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(ewk);
        break;
    case 5:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}

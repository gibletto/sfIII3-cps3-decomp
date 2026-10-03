/*
 * EFFM6.C  Entrance vehicle companion part (effect M6)
 *
 * The second sprite of the entrance vehicle created by effect_M5_init. effect_M6_move
 * locks its X position to the parent vehicle, plays its running pattern, switches to its
 * closing pattern once the vehicle has stopped, and hides and frees itself when that ends.
 * effect_M6_init (id 226, from effM5), at the end of the file, creates an object behind a parent
 * effect, copying its position, facing and colour, with char 105 of etc_char_table.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "CHARMOVE.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "CHARSET.h"
#include "bg_sub.h"
#include "effM6.h"
#include "PLCNTSET.h"
#include "PLCNTDAT.h"
#include "ta_sub.h"
#include "PLS02.h"
#include "HITCHECK.h"
#include "spgauge.h"
#include "sc_sub.h"
#include "EFFM7.h"



void effect_M6_move(WORK_Other* ewk) {
    WORK_Other* oya = (WORK_Other*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init(&ewk->wu, 0, 0x69);
        break;
    case 1:
        if (!EXE_flag && !Game_pause) {
            if (oya->wu.routine_no[0] >= 2) {
                ewk->wu.routine_no[0]++;
                set_char_move_init(&ewk->wu, 0, 0x6A);
            } else {
                char_move(&ewk->wu);
            }
        }
        ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 2:
        if (!EXE_flag && !Game_pause) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 1) {
                ewk->wu.routine_no[0]++;
                ewk->wu.disp_flag = 0;
            }
        }
        ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
        suzi_sync_pos_set(ewk);
        sort_push_request(&ewk->wu);
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_M6_init(WORK_Other* oya) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 226;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 0;
    ewk->my_master = (u32*)oya;
    ewk->wu.my_family = 2;
    ewk->wu.char_index = 105;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_priority = ewk->wu.position_z = oya->wu.my_priority - 1;
    ewk->wu.xyz[0].cal = oya->wu.xyz[0].cal;
    ewk->wu.xyz[1].cal = oya->wu.xyz[1].cal;
    ewk->wu.rl_flag = oya->wu.rl_flag;
    *ewk->wu.char_table = etc_char_table;
    ewk->wu.my_col_code = oya->wu.my_col_code;
    suzi_offset_set(ewk);
}




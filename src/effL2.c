/*
 * EFFL2.C  Onlooker that follows a fighter (effect L2)
 *
 * A background character on stage BG030 that turns to face the fighter it belongs to.
 * effect_L2_init only creates it when one side is player number 3 (and neither is 10),
 * placing it on that player's side with a shadow. effl2_dir_check picks its facing from
 * effl2_dir_tbl by the fighter's X position. When the match ends in a complete victory it
 * plays a win or lose reaction depending on Winner_id, and it resets after the next
 * screen wipe. Started from bg0301_init.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "effL2.h"
#include "fighter.h"



void effect_L2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        effl2_dir_check(ewk);
        {
            s32 z = 0;
            set_char_move_init2(&ewk->wu, z, z, 1, z);
        }
        return;
    case 1:
        if (!Allow_a_battle_f && Conclusion_Flag == 1 && C_No0 >= 2) {
            if (!(!Complete_Victory)) {
                if (Conclusion_Flag != 0) {
                    ewk->wu.routine_no[0]++;
                    ewk->wu.old_rno[0] = 0;
                    if (Winner_id != ewk->master_id) {
                        set_char_move_init(&ewk->wu, 0, 2);
                    } else {
                        set_char_move_init(&ewk->wu, 0, 1);
                    }
                }
            }
        } else if (!EXE_flag && !Game_pause) {
            effl2_dir_check(ewk);
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        return;
    case 2:
        if (Exec_Wipe != 0) {
            ewk->wu.old_rno[0] = 1;
        }
        if (ewk->wu.old_rno[0] != 0 && !Exec_Wipe) {
            ewk->wu.routine_no[0] = 0;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        sort_push_request(&ewk->wu);
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
}



void effl2_dir_check(WORK_Other* ewk) {
    s16 work;
    s32 z;

    work = plw[ewk->master_id].wu.xyz[0].disp.pos >> 6;
    work &= 15;
    if (effl2_dir_tbl[ewk->master_id][work] != ewk->wu.direction) {
        ewk->wu.direction = effl2_dir_tbl[ewk->master_id][work];
        z = 0;
        set_char_move_init2(&ewk->wu, z, z, ewk->wu.direction + 1, z);
    }
}



s32 effect_L2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    s16 oya_id;
    if (plw[0].player_number == PL_YANG || plw[1].player_number == PL_YANG) {
        return;
    }
    if (plw[0].player_number == PL_YUN && plw[1].player_number == PL_YUN) {
        return;
    }
    if (plw[0].player_number == PL_YUN) {
        oya_id = 0;
    } else if (plw[1].player_number == PL_YUN) {
        oya_id = 1;
    } else {
        return;
    }
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 212;
    ewk->wu.work_id = 16;
    ewk->master_id = oya_id;
    ewk->wu.cgromtype = 1;
    ewk->wu.disp_flag = 1;
    ewk->wu.my_family = 2;
    ewk->my_master = (u32*)&plw[oya_id];
    ewk->wu.my_col_mode = 0x4200;
    if (oya_id) {
        ewk->wu.my_col_code = 0x2016;
    } else {
        ewk->wu.my_col_code = 0x2006;
    }
    ewk->wu.my_priority = ewk->wu.position_z = 70;
    if (oya_id) {
        ewk->wu.xyz[0].cal = 0x3000000;
    } else {
        ewk->wu.xyz[0].cal = 0xF00000;
    }
    ewk->wu.xyz[1].cal = 0xA0000;
    ewk->wu.char_table[0] = direct_03_char_table;
    ewk->wu.kage_flag = 1;
    ewk->wu.kage_hx = 0;
    ewk->wu.kage_hy = 11;
    ewk->wu.kage_char = 10;
    ewk->wu.kage_prio = ewk->wu.position_z + 1;
    ewk->wu.dir_old = 0;
    ewk->wu.direction = 0;
}

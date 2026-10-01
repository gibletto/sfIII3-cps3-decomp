/*
 * PLCNTAPP.C  Player control start-of-round (appear) phase
 *
 * init_app_10000 sets up both players at the start of a match (pli_0000 clears the works, loads
 * the combo demo players if needed and calls setup_base_and_other_data), stores the parry
 * counters and waits until both players are ready (pli_1000) before starting the fight.
 * init_app_20000 and init_app_30000 are the lighter resets used by the other appear types.
 * pli_3000 queues the per-character extra graphics transfers.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "EM_Cand.h"
#include "end_sub.h"
#include "EFFC9.h"
#include "effM5.h"
#include "PLCNTSET.h"
#include "PLCNTDAT.h"
#include "EFF33.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "PLCNTAPP.h"
#include "fighter.h"
void init_app_10000(void) {
    switch (pcon_rno[1]) {
    case 0:
        pli_0000();
        pcon_rno[1] = 2;
        pcon_dp_flag = 0;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;
        break;
    case 1:
        pli_1000();
        break;
    case 2:
        pcon_rno[1] = 3;
        if (plw[0].wu.operator) {
            paring_ctr_vs[0][0] = paring_ctr_ori[0];
        } else {
            paring_ctr_vs[0][0] = 0;
        }
        if (plw[1].wu.operator) {
            paring_ctr_vs[0][1] = paring_ctr_ori[1];
            return;
        }
        paring_ctr_vs[0][1] = 0;
        break;
    case 3:
        pcon_rno[1] = 1;
        pli_3000();
        break;
    }
}



void init_app_20000(void) {
    s16 i;
    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        pcon_dp_flag = 0;
        another_bg[0] = another_bg[1] = 0;
        reset_char_disp_work(&plw[0].wu);
        reset_char_disp_work(&plw[1].wu);
        for (i = 0; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }
        setup_any_data();
        plw[0].do_not_move = plw[1].do_not_move = 0;
        plw[0].scr_pos_set_flag = plw[1].scr_pos_set_flag = 1;
        break;
    case 1:
        pli_1000();
        break;
    }
}



void init_app_30000(void) {
    s16 i;
    switch (pcon_rno[1]) {
    case 0:
        pcon_rno[1]++;
        round_slow_flag = 0;
        dead_voice_flag = 0;
        for (i = 1; i < 8; i++) {
            plw[0].wu.routine_no[i] = plw[1].wu.routine_no[i] = 0;
        }
        plw[0].wu.routine_no[0] = plw[1].wu.routine_no[0] = 1;
        another_bg[0] = another_bg[1] = 0;
        plw[0].do_not_move = plw[1].do_not_move = 0;
        break;
    case 1:
        if (plw[0].wu.routine_no[0] != 3 || plw[1].wu.routine_no[0] != 3) {
            break;
        }
        pcon_rno[0] = 2;
        pcon_rno[1] = 3;
        pcon_rno[2] = 1;
        setup_EJG_index();
        effect_C9_init(plw, 0);
        effect_C9_init(plw, 1);
        effect_C9_init(plw, 2);
        load_any_color(0x88);
        load_player_sub_color();
        load_char_gfx(0x9DA8, 1);
        if (bg_w.stage != 8 || Round_num != 0) {
            if (plw[0].player_number == PL_HUGO) {
                effect_33_init(&plw[0].wu, 0);
            }
            if (plw[1].player_number == PL_HUGO) {
                effect_33_init(&plw[1].wu, 0);
            }
        }
        break;
    }
}



void pli_0000(void) {
    pcon_rno[1]++;
    round_slow_flag = 0;
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    if (Combo_Demo_Flag) {
        Setup_Combo_Demo_PL();
    }
    setup_base_and_other_data();
}



void pli_1000(void) {
    if ((plw[0].wu.routine_no[0] == 3) && (plw[1].wu.routine_no[0] == 3)) {
        if (Allow_a_battle_f) {
            pcon_rno[0] = 1;
            pcon_rno[1] = 0;
            plw[0].wu.routine_no[0] = 4;
            plw[1].wu.routine_no[0] = 4;
            ca_check_flag = 1;
        }
    }
}



/* provisional name */
void pli_3000(void) {
    if (plw[0].player_number == PL_GOUKI1 || plw[1].player_number == PL_GOUKI1) {
        load_any_color(0x99);
    }
    if (plw[0].player_number == PL_ORO || plw[1].player_number == PL_ORO) {
        effect_M4_init(5);
    }
    if (plw[0].player_number == PL_Q || plw[1].player_number == PL_Q) {
        effect_M4_init(bg_w.stage ? 2 : 4);
    }
    if (plw[0].player_number == PL_ELENA || plw[1].player_number == PL_ELENA) {
        effect_M4_init(6);
    }
    if (plw[0].player_number == PL_URIEN || plw[1].player_number == PL_URIEN) {
        effect_M4_init(7);
    }
    if (plw[0].player_number == 0 || plw[1].player_number == 0) {
        effect_M4_init(0);
    }
    effect_M4_init(3);
}

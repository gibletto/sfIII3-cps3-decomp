/*
 * EFFA7.C  Effects A7, A8 and A9: hit marks, a fade controller and result-screen objects
 *
 * Effect A7 is the hit mark. effect_A7_init is called by the player damage code (PLPDM.c,
 * PLPCU.c) with the attacker's work and records the hit-mark number (hm_dm_side). On its first
 * frame effect_A7_move reads the hmdt entry: it requests the hit sound, sets the mark's colour
 * (hcct or the target's palette), offsets it by the explem / explem2 tables, jitters it at random,
 * chooses a directional pattern from hit_mark_dir_table and arms a screen quake (gqdt).
 * The mark then animates in the list-8 sort queue and stops while Pause_Hit_Marks is set.
 * Effect A8 puts screen picture 7, requests fade 69 and runs the fade with skipping forbidden.
 * Effect A9 places sel_pl_char_table objects on BG3 from Position_Data_A9 for the win screen
 * (Win.c) and next-opponent screen (next_cpu.c); Setup_A9 sets per-object options and can
 * add an effect 59 companion.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "aboutspr.h"
#include "sc_trans.h"
#include "textsound.h"
#include "CHARMOVE.h"
#include "Eff59.h"
#include "EFFECT.h"
#include "sc_sub.h"
#include "PLS02.h"
#include "CHARSET.h"
#include "EFFA7.h"



void effect_A7_move(WORK_Other* ewk) {
    const HMDT* tad;
    const EXPLEM* edt;
    s32 index;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        *ewk->wu.char_table = ef01_char_table;
        tad = &hmdt[ewk->wu.kohm];
        if (tad->hits == 0) {
            if (tad->se) {
                sound_effect_request[tad->se](ewk, tad->se);
                Last_Called_SE = tad->se;
            } else {
                Last_Called_SE = 0;
            }
            push_effect_work(&ewk->wu);
            return;
        }
        if (tad->status & 8) {
            ewk->wu.disp_flag = 2;
        } else {
            ewk->wu.disp_flag = 1;
        }
        if (tad->status & 0x40) {
            if (((WORK*)ewk->wu.target_adrs)->work_id == 1) {
                ewk->wu.dir_timer = ((PLW*)ewk->wu.target_adrs)->player_number;
            } else {
                ewk->wu.dir_timer = ((WORK_Other*)ewk->wu.target_adrs)->master_player;
            }
        }
        if (tad->col) {
            ewk->wu.my_col_code = hcct[tad->col];
        } else if (tad->status & 0x80) {
            ewk->wu.my_col_code = ((WORK*)ewk->wu.target_adrs)->my_col_code + 7;
        }
        if (tad->se) {
            sound_effect_request[tad->se](ewk, tad->se);
            Last_Called_SE = tad->se;
        } else {
            Last_Called_SE = 0;
        }
        if (tad->status & 0x10) {
            if (tad->status & 0x20) {
                edt = &explem2[tad->emhix][ewk->wu.dir_timer];
            } else {
                edt = &explem[tad->myhix];
            }
            if (ewk->wu.rl_flag) {
                ewk->wu.xyz[0].disp.pos -= *(s16*)&edt->hx;
            } else {
                ewk->wu.xyz[0].disp.pos += *(s16*)&edt->hx;
            }
            ewk->wu.xyz[1].disp.pos += *(s16*)&edt->hy;
        }
        if (tad->status & 2) {
            ewk->wu.xyz[0].disp.pos += random_16_com() - 7;
            ewk->wu.xyz[1].disp.pos += (random_16_com() & 7) - 3;
        }
        ewk->wu.scr_mv_x = gqdt[tad->quake][0];
        ewk->wu.scr_mv_y = gqdt[tad->quake][1];
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
        ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
        if (tad->status & 0x10) {
            index = edt->chix;
        } else {
            ewk->wu.dir_old = 0;
            if (tad->dir) {
                ewk->wu.dir_old = hit_mark_dir_table[ewk->wu.direction];
                if (ewk->wu.dir_old < 0) {
                    ewk->wu.rl_flag = 1;
                    ewk->wu.dir_old = -ewk->wu.dir_old;
                }
            }
            index = tad->hits + ewk->wu.dir_old;
        }
        set_char_move_init(&ewk->wu, 0, index);
        if (Pause_Hit_Marks) {
            return;
        }
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        if (Pause_Hit_Marks) {
            return;
        }
        if (EXE_flag == 0 && Game_pause == 0) {
            char_move(&ewk->wu);
            if (ewk->wu.cg_type == 0xFF) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[0]++;
                return;
            }
            if (ewk->wu.scr_mv_x && --ewk->wu.scr_mv_x == 0) {
                bg_w.quake_y_index = ewk->wu.scr_mv_y;
            }
        }
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    sort_push_request8(&ewk->wu);
}



s32 effect_A7_init(PLW* wk) {
    WORK_Other* ewk;
    PLW* twk;
    s16 ix;
    if (Combo_Demo_Flag & 0x80) {
        return 0;
    }
    if (wk->wu.work_id != 1) {
        return -1;
    }
    if ((ix = pull_effect_work(2)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    twk = (PLW*)wk->wu.target_adrs;
    ewk->wu.be_flag = 1;
    ewk->wu.id = 107;
    ewk->wu.work_id = 64;
    ewk->wu.rl_flag = wk->wu.rl_flag;
    ewk->wu.kohm = wk->wu.hm_dm_side;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_family = 2;
    ewk->wu.my_mr_flag = 0;
    ewk->wu.xyz[0].disp.pos = ewk->wu.position_x = wk->wu.xyz[0].disp.pos;
    ewk->wu.xyz[1].disp.pos = ewk->wu.position_y = wk->wu.xyz[1].disp.pos;
    ewk->wu.xyz[2].disp.pos = 26;
    ewk->my_master = (u32*)wk->wu.target_adrs;
    ewk->master_id = twk->wu.id;
    ewk->master_work_id = twk->wu.work_id;
    ewk->wu.target_adrs = (u32*)wk;
    ewk->wu.my_col_code = twk->wu.my_col_code + 7;
    ewk->master_player = ewk->wu.dir_timer = twk->player_number;
    ewk->wu.blink_timing = ewk->master_id;
    return 0;
}



void effect_A8_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        sc_picture_put(7, 0, 0);
        Request_Fade(69, 0);
        end_no_cut = 1;
        break;
    case 1:
        if (Fade_Flag) {
            fade_cont_main();
        } else {
            ewk->wu.routine_no[0]++;
            end_no_cut = 0;
        }
        break;
    default:
        all_cgps_put_back(ewk);
        push_effect_work((WORK*)ewk);
        break;
    case 2:
        break;
    }
}

u32 effect_A8_init(void)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 108;
    ewk->wu.work_id = 16;
    return 0;
}



void effect_A9_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;
    case 1:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new)) {
            return;
        }
        ewk->wu.disp_flag = 1;
        ewk->wu.routine_no[0]++;
        break;
    case 2:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        if (ewk->wu.char_index == 55) {
            if (E_07_Flag[LOSER]) {
                ewk->wu.routine_no[0]++;
                ewk->wu.dir_timer = 20;
                sound_request(0x68);
            }
            break;
        }
        if (ewk->wu.char_index == 57) {
            char_move(&ewk->wu);
        }
        break;
    case 3:
        char_move(&ewk->wu);
        if (--ewk->wu.dir_timer == 0) {
            if (ewk->wu.cg_type == 1) {
                ewk->wu.dir_timer = 1;
            } else {
                ewk->wu.routine_no[0] = 4;
            }
        }
        break;
    case 4:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.vital_new) || Suicide[3] != 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 99;
            return;
        }
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;
    ewk->wu.position_z = ewk->wu.xyz[2].disp.pos;
    sort_push_request4(&ewk->wu);
}



s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 109;
    ewk->wu.work_id = 16;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2040;
    ewk->wu.my_family = 4;
    *ewk->wu.char_table = sel_pl_char_table;
    ewk->wu.char_index = Char_Index;
    ewk->wu.xyz[0].disp.pos = Offset_BG_X[3] + bg_w.bgw[3].wxy[0].disp.pos + Position_Data_A9[Pos_Index][0];
    ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Position_Data_A9[Pos_Index][1];
    ewk->wu.xyz[2].disp.pos = Position_Data_A9[Pos_Index][2];
    ewk->wu.vital_new = Position_Data_A9[Pos_Index][3];
    Setup_A9(ewk, Char_Index, Option, Option2);
    return 0;
}



/* provisional name */
void Setup_A9(WORK_Other* ewk, s16 Char_Index, s16 Option, s16 Option2) {
    switch (Char_Index) {
    case 32:
        if (Option2) {
            effect_59_init(ewk, ewk->wu.my_family, 4, 1);
        }
    case 33:
    case 34:
    case 81:
    case 12:
    case 16:
    case 79:
    case 6:
    case 80:
    case 58:
    case 60:
    case 59:
        ewk->wu.dir_step = Option;
        break;
    }
}

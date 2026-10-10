#include "EFFA6.h"

/*
 * EFFA6.C  Effect A6: pre-fight dialogue text on the VS screen (move)
 *
 * Effect A6 is the dialogue line shown beside a character portrait on the VS screen; it is the
 * child of an effect 76 plate (orders 0x43 / 0x44) created by next_cpu.c. effect_A6_move reads a
 * per-character script from effA6_pl2_data_tbl (message number + display time pairs) and for
 * each line picks the message table by Country and Language (effA6_mes_jp / _en / _es / _pt),
 * loads the line's graphics and builds its connected sprites. The line slides in from the side of
 * its portrait and follows the parent's depth. Switch bit 0x1000 of that player skips to the end
 * (Next_Step); Auto_Cut_Sub cuts the current wait short. Freed on Suicide[3].
 * effect_A6_init is called by the effect 76 plate for orders 0x43 / 0x44: it creates the work,
 * records the speaking character (My_char of Player_id) and the parent plate, starts a 60-frame
 * delay and chooses which half of the character's script (routine_no[5] = 0 or 32) and which x
 * position to use from the plate side and Player_id.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "next_cpu.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"

#pragma inline(check2_A6_shortcut)

s32 check2_A6_shortcut(void) {
    u16 sw_w;
    if (Player_id) {
        sw_w = p2sw_0;
    } else {
        sw_w = p1sw_0;
    }
    if (sw_w & 0x1000) {
        return 1;
    }
    return 0;
}



void effect_A6_move(WORK_Other_CONN* ewk) {
    WORK_Other* mwk;
    const EFFA6_MESSAGE* mes;
    const CONN* conn_data;
    const u16* chr_data;
    s32 variant;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (check2_A6_shortcut() != 0) {
            Next_Step |= ~0x7F;
        }
        if (Auto_Cut_Sub() != 0) {
            if (ewk->wu.routine_no[6] <= 210) {
                ewk->wu.routine_no[6] = 1;
            } else if (ewk->wu.routine_no[6] <= 420) {
                ewk->wu.routine_no[6] = 210;
            } else if (ewk->wu.routine_no[6] <= 630) {
                ewk->wu.routine_no[6] = 420;
            } else if (ewk->wu.routine_no[6] <= 840) {
                ewk->wu.routine_no[6] = 630;
            } else {
                ewk->wu.routine_no[6] = 840;
            }
        }
        ewk->wu.routine_no[6] = ewk->wu.routine_no[6] - 1;
        if (ewk->wu.routine_no[6] <= 0) {
            ewk->wu.routine_no[6] = effA6_pl2_data_tbl[ewk->master_player][ewk->wu.routine_no[5] + 1];
            if (ewk->wu.routine_no[6] < 0) {
                Next_Step |= ~0x7F;
                ewk->wu.routine_no[6] = -1;
            } else if (!(mmes_already = effA6_pl2_data_tbl[ewk->master_player][ewk->wu.routine_no[5]])) {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[5] = ewk->wu.routine_no[5] + 2;
            } else {
                ewk->wu.routine_no[5] = ewk->wu.routine_no[5] + 2;
                switch (Country) {
                case 1:
                    mes = &effA6_mes_jp[ewk->master_player][mmes_already];
                    break;
                case 4:
                    mes = &effA6_mes_en[ewk->master_player][mmes_already];
                    break;
                default:
                    mes = &effA6_mes_jp[ewk->master_player][mmes_already];
                    break;
                }
                conn_data = mes->conn;
                chr_data = mes->chr;
                variant = Language;
                switch (Country) {
                case 1:
                    conn_data = effA6_mes_jp[ewk->master_player][mmes_already].conn;
                    chr_data = effA6_mes_jp[ewk->master_player][mmes_already].chr;
                    break;
                case 3:
                    switch (variant) {
                    case 0:
                        conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
                        break;
                    case 1:
                        conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
                        break;
                    case 2:
                        conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
                        break;
                    }
                    break;
                case 5:
                    conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
                    chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
                    break;
                case 6:
                    conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
                    chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
                    break;
                case 7:
                    switch (variant) {
                    case 0:
                        conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
                        break;
                    case 1:
                        conn_data = effA6_mes_es[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_es[ewk->master_player][mmes_already].chr;
                        break;
                    case 2:
                        conn_data = effA6_mes_pt[ewk->master_player][mmes_already].conn;
                        chr_data = effA6_mes_pt[ewk->master_player][mmes_already].chr;
                        break;
                    }
                    break;
                case 2:
                case 4:
                default:
                    conn_data = effA6_mes_en[ewk->master_player][mmes_already].conn;
                    chr_data = effA6_mes_en[ewk->master_player][mmes_already].chr;
                    break;
                }
                for (i = 0; i < chr_data[0]; i++) {
                    load_char_gfx(chr_data[i + 1], 1);
                }
                ewk->num_of_conn = chr_data[i + 1];
                ewk->wu.disp_flag = 1;
                ewk->wu.cg_number = 0;
                ewk->wu.old_cgnum = 0;
                for (i = 0; i < ewk->num_of_conn; i++) {
                    ewk->conn[i].nx = conn_data[i].nx;
                    ewk->conn[i].ny = conn_data[i].ny;
                    ewk->conn[i].col = conn_data[i].col;
                    ewk->conn[i].chr = conn_data[i].chr;
                }
                ewk->wu.vitality = 0xF0;
                ewk->wu.routine_no[1] = 0;
            }
        }
        if (Suicide[3]) {
            ewk->wu.routine_no[0] = 1;
            break;
        }
        if (!ewk->wu.disp_flag) {
            break;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            switch (ewk->wu.dir_old) {
            case 0x43:
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 72;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].xy[1].disp.pos + 186;
                break;
            default:
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 664;
                ewk->wu.position_y = ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].xy[1].disp.pos + 26;
                break;
            }
        case 1:
            switch (ewk->wu.dir_old) {
            case 0x43:
                ewk->wu.xyz[0].disp.pos += 10;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
                if (ewk->wu.position_x >= 320) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 320;
                }
                break;
            default:
                ewk->wu.xyz[0].disp.pos -= 10;
                ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
                if (ewk->wu.position_x <= 392) {
                    ewk->wu.routine_no[1]++;
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 392;
                }
                break;
            }
            break;
        case 2:
            break;
        }
        mwk = (WORK_Other*)ewk->my_master;
        switch (ewk->wu.dir_old) {
        case 0x43:
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
            effa6_pos_x_1p = mwk->wu.position_x;
            effa6_pos_y_1p = mwk->wu.position_y;
            effa6_pos_z_1p = mwk->wu.position_z;
            break;
        default:
            ewk->wu.position_z = ewk->wu.xyz[2].disp.pos = mwk->wu.position_z - 1;
            effa6_pos_x_2p = mwk->wu.position_x;
            effa6_pos_y_2p = mwk->wu.position_y;
            effa6_pos_y_2p = mwk->wu.position_y;
            break;
        }
        ewk->wu.cg_number = ewk->wu.cg_number + 1;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 1:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


s32 effect_A6_init(WORK_Other* mwk) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    effA6_work_set(ewk);
    ewk->master_player = My_char[Player_id];
    ewk->my_master = (u32*)mwk;
    ewk->wu.dir_old = mwk->wu.dir_old;
    ewk->wu.routine_no[6] = 60;
    switch (ewk->wu.dir_old) {
    case 0x43:
        if (!Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }
        ewk->wu.position_x = 504;
        break;
    default:
        if (Player_id) {
            ewk->wu.routine_no[5] = 0;
        } else {
            ewk->wu.routine_no[5] = 32;
        }
        ewk->wu.position_x = 632;
        break;
    }
    return 0;
}

/*
 * effA6_work_set fills the fixed fields of an effect A6 dialogue work (id 106, palette 0x160,
 * family 1, priority 35) for effect_A6_init.
 */

/* provisional name */
void effA6_work_set(WORK* wk) {
    wk->be_flag = 1;
    wk->id = 106;
    wk->work_id = 16;
    wk->rl_flag = 0;
    wk->cgromtype = 1;
    wk->sync_suzi = 0;
    wk->my_col_mode = 0x4200;
    wk->my_col_code = 0x160;
    wk->my_family = 1;
    wk->my_priority = 35;
    wk->position_x = 0x238;
    wk->position_y = 24;
    wk->position_z = 35;
}

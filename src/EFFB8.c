/*
 * EFFB8.C  Effect B7 init and effect B8: the winner's message banner
 *
 * effect_B7_init creates the two rank-in number works (B7) for a player's name entry, left and
 * right of centre, showing np->rank_in (called from n_input.c).
 * Effect B8 is the win message shown after a match. effect_B8_init (called from Win.c) takes
 * the winner and a delay and chooses the message: sometimes a line for the defeated character,
 * otherwise one of eight general lines picked by b8_sel_1_by_8 without repeating the last two.
 * effect_B8_move waits the delay, picks effB8_mes_jp / _en / _es / _pt by Country and Language,
 * loads the line's graphics and connected sprites, slides the banner in from the right and
 * holds it until Suicide[2]; on death it purges the line's graphics. With extra switch 2 bit 2
 * on, player 1's buttons cycle characters and messages through effB8_mes_change_init.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "PLS02.h"
#include "EFFB8.h"

#pragma inline(b8_sel_1_by_8)

void effect_B8_move(WORK_Other_CONN* ewk) {
    const EFFB8_MESSAGE* mes;
    const CONN* conn_data;
    const u16* chr_data;
    s32 variant;
    s32 sw;
    s16 num;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        mes_timer--;
        if (mes_timer > 0) {
            return;
        }
        ewk->wu.routine_no[0]++;
        switch (Country) {
        case 1:
            mes = &effB8_mes_jp[ewk->master_player][mes_already];
            break;
        case 4:
            mes = &effB8_mes_en[ewk->master_player][mes_already];
            break;
        default:
            mes = &effB8_mes_jp[ewk->master_player][mes_already];
        }
        conn_data = mes->conn;
        chr_data = mes->chr;
        variant = Language;
        switch (Country) {
        case 1:
            conn_data = effB8_mes_jp[ewk->master_player][mes_already].conn;
            chr_data = effB8_mes_jp[ewk->master_player][mes_already].chr;
            break;
        case 3:
            switch (variant) {
            case 0:
                conn_data = effB8_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effB8_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effB8_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 5:
            conn_data = effB8_mes_es[ewk->master_player][mes_already].conn;
            chr_data = effB8_mes_es[ewk->master_player][mes_already].chr;
            break;
        case 6:
            conn_data = effB8_mes_pt[ewk->master_player][mes_already].conn;
            chr_data = effB8_mes_pt[ewk->master_player][mes_already].chr;
            break;
        case 7:
            switch (variant) {
            case 0:
                conn_data = effB8_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effB8_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effB8_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effB8_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 2:
        case 4:
        default:
            conn_data = effB8_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effB8_mes_en[ewk->master_player][mes_already].chr;
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
        ewk->wu.vitality = 240;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        mes_timer = 55;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        ewk->wu.hit_quake = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos - 152;
        ewk->wu.mvxy.a[0].sp = -0x100000;
        ewk->wu.mvxy.d[0].sp = 0;
        break;
    case 1:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 3;
            break;
        }
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 2:
        if (Suicide[2] == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            break;
        }
        if (exsw_2 & 4) {
            sw = p1sw_0 & ~p1sw_1;
            if (sw & 0x380) {
                ewk->wu.routine_no[0]++;
                test_in = 1;
                if (sw & 0x80) {
                    test_pl_no++;
                    if (test_pl_no > 20) {
                        test_pl_no = 0;
                        if (Country == 1) {
                            test_mes_no = 0;
                        } else {
                            test_mes_no = 20;
                        }
                    }
                }
                if (sw & 0x100) {
                    test_mes_no++;
                    if (test_mes_no > 27) {
                        if (Country == 1) {
                            test_mes_no = 0;
                        } else {
                            test_mes_no = 20;
                        }
                    }
                }
                if (sw & 0x200) {
                    test_mes_no--;
                    if (test_mes_no < 0) {
                        test_mes_no = 27;
                    }
                }
                effB8_mes_change_init(test_pl_no, test_mes_no);
            }
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case 3:
        ewk->wu.routine_no[0]++;
        break;
    default:
        if (test_in == 0) {
            switch (Country) {
            case 1:
                chr_data = effB8_mes_jp[ewk->master_player][mes_already].chr;
                break;
            case 4:
                chr_data = effB8_mes_en[ewk->master_player][mes_already].chr;
                break;
            default:
                chr_data = effB8_mes_jp[ewk->master_player][mes_already].chr;
                break;
            }
            num = chr_data[0];
            for (i = 0; i < num; i++) {
                purge_char_gfx(chr_data[i + 1]);
            }
        }
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* provisional name */
static u16 b8_sel_1_by_8(void) {
    u16 mes_no;
    mes_no = (random_16_com() >> 1) & 7;
    old_mes_no2 = old_mes_no2 & 7;
    old_mes_no3 = old_mes_no3 & 7;
    if (old_mes_no2 == mes_no) {
        mes_no = (mes_no + 1) & 7;
    }
    if (old_mes_no3 == mes_no) {
        mes_no = (mes_no + 1) & 7;
        if (old_mes_no2 == mes_no) {
            mes_no = (mes_no + 1) & 7;
        }
    }
    old_mes_no3 = old_mes_no2;
    old_mes_no2 = mes_no;
    mes_no = mes_no + 20;
    return mes_no;
}



s32 effect_B8_init(s8 WIN_PL_NO, s16 timer) {
    PLW* wk;
    WORK_Other_CONN* ewk;
    s16 ix;
    u16 mes_no;
    test_in = 0;
    wk = &plw[WIN_PL_NO];
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    wk_set(ewk);
    mes_timer = timer;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->wu.work_id;
    ewk->master_id = wk->wu.id;
    ewk->master_player = My_char[wk->wu.id];
    test_pl_no = My_char[wk->wu.id];
    if (((random_16_com() >> 3) & 1) == 0) {
        if (Country == 1) {
            mes_no = My_char[wk->wu.id ^ 1];
            if (mes_no >= 15) {
                mes_no--;
            }
            if (old_mes_no_pl == mes_no) {
                mes_no = b8_sel_1_by_8();
            } else {
            }
            old_mes_no_pl = mes_no;
        } else {
            mes_no = b8_sel_1_by_8();
        }
        mes_already = mes_no;
    } else {
        mes_no = b8_sel_1_by_8();
        mes_already = mes_no;
    }
    test_mes_no = mes_no;
    return 0;
}


void wk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 118;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x160;
    ewk->wu.my_family = 1;
    ewk->wu.my_priority = 35;
    ewk->wu.position_x = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 168;
    ewk->wu.position_y = bg_w.bgw[ewk->wu.my_family - 1].wxy[1].disp.pos + 15;
    ewk->wu.xyz[0].disp.pos = bg_w.bgw[ewk->wu.my_family - 1].wxy[0].disp.pos + 168;
    ewk->wu.position_z = 35;
}



/* provisional name */
s32 effB8_mes_change_init(s16 pl, s16 mes_no) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.routine_no[0] = 0;
    wk_set(ewk);
    ewk->master_player = pl;
    mes_already = mes_no;
    return 0;
}

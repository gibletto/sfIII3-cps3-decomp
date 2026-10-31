/*
 * EFFA6.C  Effect A6: pre-fight dialogue text on the VS screen
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

#include "EFFA6.h"

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "next_cpu.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"

/* routine_no[0] */
#define R0_MOVE         0       /* run the dialogue script */
#define R0_HIDE         1       /* hide the line */
#define R0_END          2       /* one more frame */
#define R0_KILL         3       /* (default) put the work back */

/* routine_no[1]: slide of the current line */
#define R1_INIT         0       /* place the line at its start */
#define R1_SLIDE        1       /* slide in 10 dots a frame */
#define R1_STAY         2       /* in place */

extern const EFFA6_MESSAGE effA6_mes_en_0[];
extern const EFFA6_MESSAGE effA6_mes_en_10[];
extern const EFFA6_MESSAGE effA6_mes_en_11[];
extern const EFFA6_MESSAGE effA6_mes_en_12[];
extern const EFFA6_MESSAGE effA6_mes_en_13[];
extern const EFFA6_MESSAGE effA6_mes_en_16[];
extern const EFFA6_MESSAGE effA6_mes_en_17[];
extern const EFFA6_MESSAGE effA6_mes_en_19[];
extern const EFFA6_MESSAGE effA6_mes_en_2[];
extern const EFFA6_MESSAGE effA6_mes_en_20[];
extern const EFFA6_MESSAGE effA6_mes_en_3[];
extern const EFFA6_MESSAGE effA6_mes_en_4[];
extern const EFFA6_MESSAGE effA6_mes_en_5[];
extern const EFFA6_MESSAGE effA6_mes_en_6[];
extern const EFFA6_MESSAGE effA6_mes_en_7[];
extern const EFFA6_MESSAGE effA6_mes_en_8[];
extern const EFFA6_MESSAGE effA6_mes_en_9[];
extern const EFFA6_MESSAGE effA6_mes_jp_0[];
extern const EFFA6_MESSAGE effA6_mes_jp_10[];
extern const EFFA6_MESSAGE effA6_mes_jp_11[];
extern const EFFA6_MESSAGE effA6_mes_jp_12[];
extern const EFFA6_MESSAGE effA6_mes_jp_13[];
extern const EFFA6_MESSAGE effA6_mes_jp_16[];
extern const EFFA6_MESSAGE effA6_mes_jp_17[];
extern const EFFA6_MESSAGE effA6_mes_jp_19[];
extern const EFFA6_MESSAGE effA6_mes_jp_2[];
extern const EFFA6_MESSAGE effA6_mes_jp_20[];
extern const EFFA6_MESSAGE effA6_mes_jp_3[];
extern const EFFA6_MESSAGE effA6_mes_jp_4[];
extern const EFFA6_MESSAGE effA6_mes_jp_5[];
extern const EFFA6_MESSAGE effA6_mes_jp_6[];
extern const EFFA6_MESSAGE effA6_mes_jp_7[];
extern const EFFA6_MESSAGE effA6_mes_jp_8[];
extern const EFFA6_MESSAGE effA6_mes_jp_9[];

s16 effa6_pos_x_1p;  /* 02068C14 */
s16 effa6_pos_y_1p;  /* 02068C16 */
s16 effa6_pos_z_1p;  /* 02068C18 */
s16 effa6_pos_x_2p;  /* 02068C1A */
s16 effa6_pos_y_2p;  /* 02068C1C */
s16 effa6_pos_z_2p;  /* the 2P z position beside x_1p..y_2p; nothing in the program uses it (provisional name) */
s16 mmes_already;  /* 02068C20 */


/* 02006DAC */
const EFFA6_MESSAGE* effA6_mes_jp[21] = {
    effA6_mes_jp_0,
    effA6_mes_jp_0,
    effA6_mes_jp_2,
    effA6_mes_jp_3,
    effA6_mes_jp_4,
    effA6_mes_jp_5,
    effA6_mes_jp_6,
    effA6_mes_jp_7,
    effA6_mes_jp_8,
    effA6_mes_jp_9,
    effA6_mes_jp_10,
    effA6_mes_jp_11,
    effA6_mes_jp_12,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_16,
    effA6_mes_jp_17,
    effA6_mes_jp_17,
    effA6_mes_jp_19,
    effA6_mes_jp_20,
};
/* 02006E00 */
const EFFA6_MESSAGE* effA6_mes_en[21] = {
    effA6_mes_en_0,
    effA6_mes_en_0,
    effA6_mes_en_2,
    effA6_mes_en_3,
    effA6_mes_en_4,
    effA6_mes_en_5,
    effA6_mes_en_6,
    effA6_mes_en_7,
    effA6_mes_en_8,
    effA6_mes_en_9,
    effA6_mes_en_10,
    effA6_mes_en_11,
    effA6_mes_en_12,
    effA6_mes_en_13,
    effA6_mes_en_13,
    effA6_mes_en_13,
    effA6_mes_en_16,
    effA6_mes_en_17,
    effA6_mes_en_17,
    effA6_mes_en_19,
    effA6_mes_en_20,
};
/* 02006E54 */
const EFFA6_MESSAGE* effA6_mes_es[21] = {
    effA6_mes_jp_0,
    effA6_mes_jp_0,
    effA6_mes_jp_2,
    effA6_mes_jp_3,
    effA6_mes_jp_4,
    effA6_mes_jp_5,
    effA6_mes_jp_6,
    effA6_mes_jp_7,
    effA6_mes_jp_8,
    effA6_mes_jp_9,
    effA6_mes_jp_10,
    effA6_mes_jp_11,
    effA6_mes_jp_12,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_16,
    effA6_mes_jp_17,
    effA6_mes_jp_17,
    effA6_mes_jp_19,
    effA6_mes_jp_20,
};
/* 02006EA8 */
const EFFA6_MESSAGE* effA6_mes_pt[21] = {
    effA6_mes_jp_0,
    effA6_mes_jp_0,
    effA6_mes_jp_2,
    effA6_mes_jp_3,
    effA6_mes_jp_4,
    effA6_mes_jp_5,
    effA6_mes_jp_6,
    effA6_mes_jp_7,
    effA6_mes_jp_8,
    effA6_mes_jp_9,
    effA6_mes_jp_10,
    effA6_mes_jp_11,
    effA6_mes_jp_12,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_13,
    effA6_mes_jp_16,
    effA6_mes_jp_17,
    effA6_mes_jp_17,
    effA6_mes_jp_19,
    effA6_mes_jp_20,
};


#pragma inline(check2_A6_shortcut)

/* provisional name */
s32 effA5_shot_pressed(void) {
    u16 sw;
    if (Player_id) {
        sw = p2sw_0;
    } else {
        sw = p1sw_0;
    }
    if (sw & BUTTON_SHOTS) {
        return 1;
    }
    return 0;
}



s32 check2_A6_shortcut(void) {
    u16 sw;
    if (Player_id) {
        sw = p2sw_0;
    } else {
        sw = p1sw_0;
    }
    if (sw & BUTTON_START) {
        return 1;
    }
    return 0;
}



#define DIALOGUE_THIRD_SKIP_TIME 630

void effect_A6_move(WORK_Other_CONN* ewk) {
    WORK_Other* mwk;
    const EFFA6_MESSAGE* mes;
    const CONN* conn_data;
    const u16* chr_data;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case R0_MOVE:
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
                ewk->wu.routine_no[6] = DIALOGUE_THIRD_SKIP_TIME;
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
                    mes = effA6_mes_jp[ewk->master_player];
                    mes += mmes_already;
                    conn_data = mes->conn;
                    chr_data = mes->chr;
                    break;
                case 4:
                    mes = effA6_mes_en[ewk->master_player];
                    mes += mmes_already;
                    conn_data = mes->conn;
                    chr_data = mes->chr;
                    break;
                default:
                    mes = effA6_mes_jp[ewk->master_player];
                    mes += mmes_already;
                    conn_data = mes->conn;
                    chr_data = mes->chr;
                    break;
                }
                switch (Country) {
                case 1:
                    conn_data = effA6_mes_jp[ewk->master_player][mmes_already].conn;
                    chr_data = effA6_mes_jp[ewk->master_player][mmes_already].chr;
                    break;
                case 3:
                    switch (Language) {
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
                    switch (Language) {
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
                ewk->wu.routine_no[1] = R1_INIT;
            }
        }
        if (Suicide[3]) {
            ewk->wu.routine_no[0] = R0_HIDE;
            break;
        } else if (ewk->wu.disp_flag) {
            switch (ewk->wu.routine_no[1]) {
            case R1_INIT:
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
                /* fall through */
            case R1_SLIDE:
                switch (ewk->wu.dir_old) {
                case 0x43:
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos + 10;
                    if (ewk->wu.position_x >= 320) {
                        ewk->wu.routine_no[1]++;
                        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 320;
                    }
                    break;
                default:
                    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = ewk->wu.xyz[0].disp.pos - 10;
                    if (ewk->wu.position_x <= 392) {
                        ewk->wu.routine_no[1]++;
                        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = 392;
                    }
                    break;
                }
                break;
            case R1_STAY:
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
            ewk->wu.cg_number++;
            ewk->wu.cg_number &= 0x7FFF;
            sort_push_request3(&ewk->wu);
        }
        break;
    case R0_HIDE:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        break;
    case R0_END:
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
    ewk->wu.routine_no[0] = R0_MOVE;
    wwwk_set(&ewk->wu);
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
 * wwwk_set fills the fixed fields of an effect A6 dialogue work (id 106, palette 0x160,
 * family 1, priority 35) for effect_A6_init.
 */

void wwwk_set(WORK* wk) {
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

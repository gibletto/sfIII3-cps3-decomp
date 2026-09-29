/*
 * PLPATUNI.C  Shared special-move routines for all characters
 *
 * Special attack routines used by several characters' attack tables (the "universal" set).
 * They cover the fireball family (Att_HADOUKEN, Att_HADOUKEN2), rising uppercuts
 * (Att_SHOURYUUKEN, Att_SHOURYUUREPPA, Att_SHINSHOURYUUKEN), spinning and hopping kicks
 * (Att_SENPUUKYAKU, Att_ABISEGERI, Att_TENSHINSENKYUUTAI), air specials (Att_KUUCHUU...),
 * leaping and homing jumps (Att_JINNCHUUWATARI, Att_HOMING_JUMP, Att_SLIDE_and_JUMP) and
 * Att_CHOUCHUURENGEKI. Each steps its animation and mvxy movement data by cg_type marks.
 * Att_METAMOR_WAIT/Att_METAMOR_REBIRTH handle a metamorphosed player waiting and being restored
 * (offsets from metareb_pos); Att_NM_OKIAGARI is a get-up; Att_DUMMY fills unused slots.
 * att_ahj_table_reader reads the target-relative jump data used by the leaping moves.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLS02.h"
#include "CALDIR.h"
#include "CHARMOVE.h"
#include "PLPAT.h"
#include "PLS01.h"
#include "CHARSET.h"
#include "PLPATUNI.h"



void Att_DUMMY(PLW* wk) {}



void Att_METAMOR_WAIT(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 30) {
            wk->wu.routine_no[3] = 2;
        }
        break;
    case 2:
        char_move(&wk->wu);
        if (wk->wu.cg_type != 30) {
            wk->wu.routine_no[3] = 3;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.d[1].sp = -0x8000;
            wk->wu.mvxy.kop[0] = wk->wu.mvxy.kop[1] = 0;
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Att_METAMOR_REBIRTH(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3] = 1;
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data((WORK*)wk);
        if (wk->wu.xyz[1].disp.pos < 3) {
            wk->wu.xyz[1].disp.pos = -8;
        } else {
            wk->wu.xyz[1].disp.pos -= metareb_pos[wk->player_number][1];
            if (wk->wu.rl_flag) {
                wk->wu.xyz[0].disp.pos += metareb_pos[wk->player_number][0];
            } else {
                wk->wu.xyz[0].disp.pos -= metareb_pos[wk->player_number][0];
            }
        }
        set_char_move_init((WORK*)wk, 5, 1);
        wk->metamor_over = 0;
        break;
    case 1:
        char_move((WORK*)wk);
        if (wk->wu.cg_type == 31) {
            wk->wu.cg_type = 0;
            wk->caution_flag = 0;
            wk->wu.cg_ja = wk->wu.hit_ix_table[wk->wu.cg_hit_ix];
            set_jugde_area((WORK*)wk);
            break;
        }
        if (wk->wu.cg_type == 40) {
            wk->wu.routine_no[3] = 2;
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.d[1].sp = -0x8000;
            wk->wu.mvxy.kop[0] = wk->wu.mvxy.kop[1] = 0;
            wk->scr_pos_set_flag = 1;
        }
        break;
    case 2:
        wk->scr_pos_set_flag = 1;
        jumping_union_process((WORK*)wk, 3);
        break;
    case 3:
        wk->scr_pos_set_flag = 1;
        char_move((WORK*)wk);
        break;
    }
}


void Att_HADOUKEN(PLW* wk) {
    wk->scr_pos_set_flag = 0;
    Att_HADOUKEN2(wk);
}



void Att_HADOUKEN2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        break;
    }
}



void Att_NM_OKIAGARI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        break;
    }
}



void Att_SHOURYUUKEN(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 25:
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 30:
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Att_SENPUUKYAKU(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] != 3 && wk->wu.cg_type == 20) {
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void Att_SENPUUKYAKU2(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->data_ix);
        cal_initial_speed_y(&wk->wu, wk->as->r_no, 0);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void Att_ABISEGERI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        setup_mvxy_data(&wk->wu, wk->as->r_no);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] == 3) {
            if (wk->wu.mvxy.kop[0] == 2) {
                wk->wu.mvxy.kop[0] = 1;
            }
            wk->wu.mvxy.d[1].sp = 0;
            wk->wu.mvxy.a[1].sp = 0;
        }
        break;
    case 3:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        if (wk->wu.cg_type == 64 || wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.a[0].sp = 0;
        }
        break;
    default:
        char_move(&wk->wu);
        break;
    }
}



void Att_SHOURYUUREPPA(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 40 && (wk->cp->sw_new & 0x770) == 0x70) {
            wk->wu.routine_no[1] = 0;
            wk->wu.routine_no[2] = 6;
            wk->wu.routine_no[3] = 0;
            wk->wu.cg_type = 0;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 1);
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        jumping_union_process(&wk->wu, 4);
        break;
    case 4:
        char_move(&wk->wu);
        break;
    }
}



void Att_SHINSHOURYUUKEN(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 1);
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_KUUCHUUNICHIRINSHOU(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
    case 1:
        jumping_union_process(&wk->wu, 2);
        if (wk->wu.routine_no[3] != 2) {
            if (wk->wu.cg_type == 20) {
                add_to_mvxy_data(&wk->wu, wk->as->data_ix);
                wk->wu.cg_type = 0;
            }
            if (wk->wu.cg_type == 30) {
                add_to_mvxy_data(&wk->wu, wk->as->r_no);
                wk->wu.cg_type = 0;
            }
        }
        break;
    case 2:
        char_move(&wk->wu);
        break;
    }
}



void Att_KUUCHUUJINNCHUUWATARI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.routine_no[3]++;
        }
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] == 3) {
            break;
        }
        if (wk->wu.cg_type == 20) {
            add_to_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->as->data_ix);
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



/* provisional name */
void Att_TENSHINSENKYUUTAI_OLD(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 40:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        case 30:
            wk->wu.mvxy.index = wk->as->data_ix;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            break;
        }
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] != 3 && wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    }
}



void Att_TENSHINSENKYUUTAI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        break;
    case 1:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 40:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        case 50:
            wk->wu.routine_no[3] = 4;
            wk->wu.cg_type = 0;
            break;
        case 30:
            wk->wu.mvxy.index = wk->as->data_ix;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        if (wk->wu.routine_no[3] != 4 && wk->hos_fi_flag | wk->hos_em_flag) {
            char_move_cmj4(&wk->wu);
            wk->wu.routine_no[3] = 4;
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 3);
        if (wk->wu.routine_no[3] != 3 && wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        break;
    case 4:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 40:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        case 30:
            wk->wu.mvxy.index = wk->as->data_ix;
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
            break;
        }
        add_mvxy_speed(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        break;
    }
}



void Att_CHOUCHUURENGEKI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    default:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        switch (wk->wu.cg_type) {
        case 20:
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
            break;
        case 21:
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            break;
        }
    }
}



void Att_SLIDE_and_JUMP(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        hoken_muriyari_chakuchi(wk);
        wk->wu.rl_flag = wk->wu.rl_waza;
        reset_mvxy_data(&wk->wu);
        wk->wu.mvxy.index = wk->as->r_no;
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 3;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.routine_no[3] != 1) {
            add_mvxy_speed(&wk->wu);
        }
        break;
    case 2:
        jumping_union_process(&wk->wu, 1);
        if ((wk->wu.routine_no[3] != 1) && (wk->wu.cg_type == 20)) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    case 3:
        char_move(&wk->wu);
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.index++;
            wk->wu.routine_no[3] = 2;
            wk->wu.cg_type = 0;
        }
        if (wk->wu.cg_type == 21) {
            reset_mvxy_data(&wk->wu);
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 1;
        }
        if (wk->wu.cg_type == 30) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.mvxy.a[1].sp = wk->wu.mvxy.d[1].sp = wk->wu.mvxy.kop[1] = 0;
            wk->wu.mvxy.index++;
            wk->wu.cg_type = 0;
        }
        break;
    }
}



void Att_JINNCHUUWATARI(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move(&wk->wu);
        att_ahj_table_reader(wk);
        break;
    case 2:
        if (wk->wu.cg_type == 20) {
            setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
            wk->wu.cg_type = 0;
            wk->wu.mvxy.index++;
        }
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 3;
            break;
        }
        jumping_union_process(&wk->wu, 3);
        break;
    case 3:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 1) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3] = 2;
        }
        break;
    }
}



void Att_HOMING_JUMP(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case 0:
        wk->wu.routine_no[3]++;
        wk->wu.rl_flag = wk->wu.rl_waza;
        hoken_muriyari_chakuchi(wk);
        set_char_move_init(&wk->wu, 5, wk->as->char_ix);
        wk->wu.mvxy.index = wk->as->data_ix;
        break;
    case 1:
        char_move(&wk->wu);
        att_ahj_table_reader(wk);
        break;
    case 3:
        wk->wu.routine_no[3] = 2;
    case 2:
        jumping_union_process(&wk->wu, 1);
        if (wk->wu.routine_no[3] != 1) {
            att_ahj_table_reader(wk);
        }
        break;
    }
}



void att_ahj_table_reader(PLW* wk) {
    PLW* twk = (PLW*)wk->wu.target_adrs;
    const s16* curr_kop = ahj_kop[wk->as->r_no];
    s16 ex;
    s16 ey;
    if (wk->wu.cg_type == 30) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        switch (curr_kop[0]) {
        case 0:
            if (wk->wu.rl_flag) {
                ex = twk->wu.position_x - *ahj_empos_hos[wk->as->r_no][twk->player_number];
            } else {
                ex = twk->wu.position_x + *ahj_empos_hos[wk->as->r_no][twk->player_number];
            }
            ey = ahj_empos_hos[wk->as->r_no][twk->player_number][1];
            wk->wu.mvxy.a[0].sp = 0;
            cal_delta_speed(&wk->wu, curr_kop[1], ex, ey, curr_kop[2], curr_kop[3]);
        default:
            if (wk->wu.rl_flag == 0) {
                wk->wu.mvxy.a[0].sp = -wk->wu.mvxy.a[0].sp;
                wk->wu.mvxy.d[0].sp = -wk->wu.mvxy.d[0].sp;
            }
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
            add_mvxy_speed(&wk->wu);
        }
    }
    if (wk->wu.cg_type == 20) {
        setup_mvxy_data(&wk->wu, wk->wu.mvxy.index);
        wk->wu.mvxy.index++;
        wk->wu.routine_no[3]++;
        wk->wu.cg_type = 0;
        add_mvxy_speed(&wk->wu);
    }
}

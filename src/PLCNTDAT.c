/*
 * PLCNTDAT.C  Player base data, stun and super-art setup, round resets
 *
 * setup_base_and_other_data sets both players' base data (set_base_data), super-art and stun work
 * pointers and other data, and creates their J7 and E5 effects; set_base_data_metamor reloads it
 * after a metamorphosis, set_player_shadow sets the shadow.
 * set_kizetsu_status loads a character's stun limit and recovery; clear_kizetsu_point and
 * clear_super_arts_point reset the stun and super-art values.
 * reset_piyori_and_fight, reset_fight_status, reset_round_and_screen and erase_extra_plef_work reset
 * the round; debug_player_change lets the debug buttons change character, art and colour.
 * check_combo_end is used by the combo counter (cmb_cont).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "VITAL.h"
#include "spgauge.h"
#include "EFF02.h"
#include "EFF00.h"
#include "EFFK5.h"
#include "effM5.h"
#include "CMD_MAIN.h"
#include "EFFE5.h"
#include "EFFJ7.h"
#include "EFFECT.h"
#include "bg_sub.h"
#include "CHARID.h"
#include "PLCNTDAT.h"
#include "fighter.h"



/* provisional name */
s16 debug_player_change(void) {
    s16 chg = 0;
    if (exsw_1 & 0x80) {
        if (plw[0].cp->sw_now & 0x10) {
            My_char[0]++;
            if (My_char[0] > 20) {
                My_char[0] = 0;
            }
            chg = 1;
        }
        if (plw[0].cp->sw_now & 0x20) {
            Super_Arts[0]++;
            if (Super_Arts[0] > 2) {
                Super_Arts[0] = 0;
            }
            chg = 2;
        }
        if (plw[0].cp->sw_now & 0x40) {
            Player_Color[0]++;
            if (Player_Color[0] > 6) {
                Player_Color[0] = 0;
            }
            chg = 1;
        }
        if (plw[1].cp->sw_now & 0x10) {
            My_char[1]++;
            if (My_char[1] > 20) {
                My_char[1] = 0;
            }
            chg = 1;
        }
        if (plw[1].cp->sw_now & 0x20) {
            Super_Arts[1]++;
            if (Super_Arts[1] > 2) {
                Super_Arts[1] = 0;
            }
            chg = 2;
        }
        if (plw[1].cp->sw_now & 0x40) {
            Player_Color[1]++;
            if (Player_Color[1] > 6) {
                Player_Color[1] = 0;
            }
            chg = 1;
        }
    }
    if (My_char[0] == PL_GILL && Player_Color[0] != 0 && plw[0].wu.operator == 1) {
        chg = 1;
        Player_Color[0] = 0;
    }
    if (My_char[1] == PL_GILL && Player_Color[1] != 0 && plw[1].wu.operator == 1) {
        chg = 1;
        Player_Color[1] = 0;
    }
    if (chg) {
        if (chg == 1) {
            set_kizetsu_status(0);
            set_kizetsu_status(1);
        }
        reset_fight_status();
        erase_extra_plef_work();
    }
    return chg;
}



/* provisional name */
void reset_piyori_and_fight(void)
{
  set_kizetsu_status(0);
  set_kizetsu_status(1);
  reset_fight_status();
  return;
}



/* provisional name */
void reset_fight_status(void) {
    s16 rno = 0;
    appear_type = pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = rno;
    count_cont_reset();
    set_super_arts_status(0);
    set_super_arts_status(1);
    Sa_frame_Clear();
    spgauge_cont_init();
}



/* provisional name */
void reset_round_and_screen(void) {
    System_all_clear_Wait();
    scfont_page0_fill(0, 32);
    load_any_color(2);
    count_cont_reset();
    Round_num = G_No2 = appear_type = pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
}



/* provisional name */
void erase_extra_plef_work(void) {
    effect_work_list_release(0, 0);
    effect_work_list_release(1, 1);
    effect_work_list_release(3, 0x91);
    effect_work_list_release(4, 0x81);
    effect_work_list_release(4, 0x25);
    effect_work_list_release(4, 0xAC);
}



void setup_base_and_other_data(void) {
    set_base_data(&plw[0], 0);
    set_base_data(&plw[1], 1);
    plw[0].sa = &super_arts[0];
    plw[1].sa = &super_arts[1];
    plw[0].py = &piyori_type[0];
    plw[1].py = &piyori_type[1];
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_work_list_release(3, 0xC5);
    plw[0].gill_ccch_go = plw[1].gill_ccch_go = 0;
    effect_J7_init(&plw[0]);
    effect_J7_init(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);
    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }
}



void setup_any_data(void) {
    set_base_data_tiny(&plw[0]);
    set_base_data_tiny(&plw[1]);
    setup_other_data(&plw[0]);
    setup_other_data(&plw[1]);
    effect_work_list_release(3, 0xC5);
    plw[0].gill_ccch_go = plw[1].gill_ccch_go = 0;
    effect_J7_init(&plw[0]);
    effect_J7_init(&plw[1]);
    effect_E5_init(&plw[0]);
    effect_E5_init(&plw[1]);
    if (plw[0].wu.my_priority == plw[1].wu.my_priority) {
        plw[0].the_same_players = plw[1].the_same_players = 1;
    }
}



void set_base_data(PLW* wk, s16 ix) {
    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wu.blink_timing = ix;
    wk->wu.id = ix;
    wk->wu.work_id = 1;
    wk->wu.operator = Operator_Status[ix];
    wk->wu.charset_id = plid_data[My_char[ix]];
    wk->wkey_flag = wk->dead_flag = 0;
    set_char_base_data(&wk->wu);
    wk->wu.target_adrs = (u32*)&plw[(ix + 1) & 1];
    wk->player_number = My_char[ix];
    cmd_init(wk);
    wk->cb = &combo_type[ix];
    wk->rp = &remake_power[ix];
    if (ix) {
        wk->wu.my_col_code |= 0x10;
    }
    wk->spmv_ng_flag = spmv_ng_table[wk->player_number];
    wk->wu.weight_level = weight_lv_table[wk->player_number];
    set_player_shadow(wk);
}



/* provisional name */
void set_base_data_metamor(PLW* wk) {
    set_char_base_data(&wk->wu);
    if (wk->wu.id) {
        wk->wu.my_col_code |= 0x10;
    }
    cmd_init(wk);
    wk->spmv_ng_flag = spmv_ng_table[wk->player_number];
    set_player_shadow(wk);
}



void set_base_data_tiny(PLW* wk) {
    wk->wu.charset_id = plid_data[My_char[wk->wu.id]];
    wk->player_number = My_char[wk->wu.id];
    set_char_base_data(&wk->wu);
    if (wk->wu.id) {
        wk->wu.my_col_code |= 0x10;
    }
    wk->wu.be_flag = 1;
    wk->wu.disp_flag = 0;
    wk->wkey_flag = wk->dead_flag = 0;
    cmd_init(wk);
    wk->spmv_ng_flag = spmv_ng_table[wk->player_number];
    wk->wu.weight_level = weight_lv_table[wk->player_number];
    set_player_shadow(wk);
}



void set_player_shadow(PLW* wk) {
    wk->wu.kage_flag = 1;
    wk->wu.kage_prio = 68;
    wk->wu.kage_hx = kage_base[wk->player_number][0];
    wk->wu.kage_char = kage_base[wk->player_number][1];
}



void setup_other_data(PLW* wk) {
    load_player_color(wk->player_number, wk->wu.id, Player_Color[wk->wu.id]);
    if (wk->player_number == PL_GILL && !(Introduce_Boss[wk->wu.id][1] & 0x80)) {
        effect_M4_init(1);
    }
    effect_01_init((WORK*)wk, 0);
    effect_01_init((WORK*)wk, 1);
    effect_01_init((WORK*)wk, 2);
    effect_01_init((WORK*)wk, 3);
    effect_K5_init(wk);
}



/* provisional name */
void set_kizetsu_status(ix)
s16 ix;
{
    s16 plnum = My_char[ix];
    piyori_type[ix].flag = 0;
    piyori_type[ix].time = 0;
    piyori_type[ix].now.timer = 0;
    piyori_type[ix].store = 0;
    piyori_type[ix].genkai = pl_piyo_tbl[plnum];
    piyori_type[ix].recover = pl_nr_piyo_tbl[plnum];
}



void clear_kizetsu_point(PLW* wk) {
    wk->py->flag = 0;
    wk->py->time = 0;
    wk->py->now.timer = 0;
    wk->py->store = 0;
    wk->py->recover = pl_nr_piyo_tbl[wk->player_number];
}

void set_super_arts_status(s16 pl)
{
    SA_WORK *sa;
    u8 *data;

    data = super_arts_data[My_char[pl]][Super_Arts[pl]];
    sa = &super_arts[pl];
    sa->kind_of_arts = Super_Arts[pl];
    sa->nmsa_g_ix = data[0];
    sa->exsa_g_ix = data[1];
    sa->exs2_g_ix = data[2];
    sa->nmsa_a_ix = data[3];
    sa->exsa_a_ix = data[4];
    sa->exs2_a_ix = data[5];
    sa->gauge_type = data[7];
    sa->gauge_len = *(s16 *)&data[8];
    sa->store_max = *(s16 *)&data[10];
    sa->dtm = *(s32 *)&data[12];
    sa->dtm_mul = 1;
    sa->store = 0;
    sa->gauge.s.h = 0;
    sa->gauge.s.l = -1;
    sa->sa_rno = 0;
    sa->ok = 0;
}



void clear_super_arts_point(PLW* wk) {
    wk->sa->gauge.s.h = 0;
    wk->sa->gauge.s.l = -1;
    wk->sa->mp_rno = 0;
    wk->sa->sa_rno = 0;
    wk->sa->ex_rno = 0;
    wk->sa->mp = 0;
    wk->sa->ok = 0;
    wk->sa->ex = 0;
}



s16 check_combo_end(s16 ix) {
    s16 rnum;
    if (plw[ix].py->flag) {
        return 1;
    }
    if (plw[ix].tsukamare_f) {
        return 1;
    }
    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 0;
    }
    if (plw[ix].wu.cg_ja.boix == 0 && plw[ix].wu.cg_ja.cuix == 0 && plw[ix].wu.pat_status == 38) {
        return 0;
    }
    if (plw[ix].zuru_flag) {
        return 0;
    }
    if (plw[ix].wu.routine_no[1] != 1 && plw[ix].wu.routine_no[1] != 3) {
        return 0;
    }
    if (plw[ix].old_gdflag != plw[ix].guard_flag) {
        if (plw[ix].guard_flag == 0) {
            rnum = 0;
        } else {
            rnum = 1;
        }
    } else if (plw[ix].guard_flag == 0) {
        rnum = 0;
    } else {
        rnum = 1;
    }
    return rnum;
}

void set_scrrrl(void)
{
    s16 center;
    center = get_center_position();
    scrr = center + 192;
    scrl = center - 192;
}

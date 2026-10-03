/*
 * end_sub.c  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads
 *
 * Card dispenser bookkeeping for the regions that give out cards: card_win_check counts wins per
 * player and requests a card when the required wins are reached; card_msg_disp blinks the
 * "card won" and "no cards" messages. cd_keep_spinning_tick keeps the CD drive spinning and
 * cd_error_fatal_hang shows the no-drive / no-disc message and stops the machine.
 * staff_roll_main scrolls the staff credits after an ending, with a button skip check.
 * debug_play07..13 are debug-menu fight setups that initialise a match with fixed characters and
 * stage and run the battle loop. The colour transfer routines (load_any_color, load_bg_color,
 * load_player_color, fade variants, side/effect/option colours) send palette blocks from ROM
 * tables to colour RAM through the transfer queue.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "EFFECT.h"
#include "EFFH3.h"
#include "PLCNTDAT.h"
#include "sys_test.h"
#include "sys_config.h"
#include "Manage.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "meta_col.h"
#include "textsound.h"
#include "fifo.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "cps3.h"

#pragma inline(card_pl_work_clear)



/* provisional name */
void card_pl_work_clear(s16 pl) {
    memset(&card_pl_w[pl], 0, 12);
}

/* provisional name */
u32 card_work_clear(void)
{
    memset((u8 *)&card_pl_w[0], 0, sizeof(SELPL));
    return (u32)memset((u8 *)&card_pl_w[1], 0, sizeof(SELPL));
}

/* provisional name */
u32 card_win_check(s16 vs_mode)
{
    SELPL *win;
    s8 need;
    s32 ret;

    if (!Card_Dispenser) {
        return 0;
    }
    ret = Country;
    if (ret != 6 && ret != 5) {
        return (u32)ret;
    }
    if (!Play_Type) {
        win = (SELPL *)((u8 *)card_pl_w + (s8)(Winner_id * sizeof(SELPL)));
        if (!vs_mode) {
            need = Win_Point_Com - Continue_Coin[Winner_id];
            if (need < 0) {
                need = 1;
            }
            win->wins += 1;
            if (!win->cleared && need <= win->wins) {
                win->cleared += 1;
                card_out_req += 1;
                win->flag = 1;
            }
        } else {
            win->cleared += 1;
            card_out_req += 1;
            win->flag = 1;
        }
        return (u32)memset((u8 *)card_pl_w + (s8)(Loser_id * sizeof(SELPL)), 0, sizeof(SELPL));
    }
    memset((u8 *)card_pl_w + (s8)(Loser_id * sizeof(SELPL)), 0, sizeof(SELPL));
    win = (SELPL *)((u8 *)card_pl_w + (s8)(Winner_id * sizeof(SELPL)));
    win->vs_wins += 1;
    ret = win->cleared;
    if (!ret && (ret = win->vs_wins) >= Win_Point_Human) {
        win->cleared += 1;
        card_out_req += 1;
        win->flag = 1;
        ret = 1;
    }
    return (u32)ret;
}


/* provisional name */
void card_msg_disp(void) {
    SELPL* rec;
    if (!Card_Dispenser) {
        return;
    }
    if (Country != 6 && Country != 5) {
        return;
    }
    rec = &card_pl_w[Winner_id];
    switch (rec->card_state) {
    case 0:
        if (card_out_busy != 0 || card_empty_flag != -1) {
            break;
        }
        rec->card_state++;
        card_pl_w[Winner_id].blink = 0;
    case 1:
        switch (card_pl_w[Winner_id].blink & 31) {
        case 0:
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_mes);
            break;
        case 15:
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_clr_mes);
            break;
        }
        if (card_out_busy == 0 && card_empty_flag != -1) {
            card_pl_w[Winner_id].msg_state = 0;
            card_pl_w[Winner_id].card_state = 0;
            tilemap_print_string_attr(21, Text_Page_Y + 6, 18, no_card_clr_mes);
            return;
        }
        card_pl_w[Winner_id].blink++;
        return;
    }
    switch (rec->msg_state) {
    case 0:
        if (rec->flag == 0) {
            break;
        }
        rec->msg_state++;
        card_pl_w[Winner_id].msg_timer = -32;
        card_msg_cnt = -1;
    case 1:
        card_msg_cnt++;
        if (--card_pl_w[Winner_id].msg_timer == 0) {
            card_msg_cnt = 0;
            card_pl_w[Winner_id].msg_state = 0;
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_clr_mes);
            card_pl_w[Winner_id].flag = 0;
            break;
        }
        switch (card_msg_cnt & 63) {
        case 0:
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_mes);
            break;
        case 31:
            tilemap_print_string_attr(18, Text_Page_Y + 6, 18, win_card_clr_mes);
            break;
        }
        break;
    }
}



/* provisional name */
void cd_keep_spinning_tick(void) {
    if (cd_ready_flag) {
        if (!cd_spin_timer) {
            scsi_start_stop_unit(1, 1);
            cd_spin_timer = 0x258;
        }
        cd_spin_timer--;
    }
}



/* provisional name */
void cd_selftest_periodic(void) {
    if (cd_ready_flag) {
        _builtin_set_imask(15);
        if (cd_check_drive_inquiry() != 0) {
            cd_error_fatal_hang(0);
        }
        if (cd_check_disc_id() != 0) {
            cd_error_fatal_hang(1);
        }
        _builtin_set_imask(1);
    }
}



/* provisional name */
void cd_error_fatal_hang(s32 kind) {
    coin_lock_set(-1);
    set_screen_mode(3);
    screen_flip_offsets_set();
    Scr_all_clear_Wait();
    coin_work_init();
    Cd_Error_Flag = 1;
    palette_bank_set(0);
    palette_write(0, sys_palette, 0x100);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)sys_font_cg, 0x8C);
    clear_scroll_layer_state_and_mask();
    sound_driver_init();
    kill_tasks_by_priority(3, 1);
    switch (kind) {
    case 0:
        tilemap_print_string_attr(18, 16, 18, no_cd_drive_mes);
        break;
    case 1:
        tilemap_print_string_attr(21, 16, 18, no_cd_rom_mes);
        break;
    }
    while (1) {
    }
}



/* provisional name */
s32 staff_roll_skip_check(void) {
    u16 v;
    if (!end_no_cut) {
        if (WINNER) {
            v = p2sw_0;
        } else {
            v = p1sw_0;
        }
        if (v & 0x3f0) {
            return 1;
        }
    }
    return 0;
}



/* provisional name */
void staff_roll_put(id, x, y, a, b)
s32 id;
s32 x;
s32 y;
s32 a;
s32 b;
{
    effect_H6_init(id, b, x + (bg_w.bgw[5].xy[0].disp.pos - 192), y + bg_w.bgw[5].position_y, a, -1);
}



/* provisional name */
s32 staff_roll_main(void) {
    const STAFF_LINE* line;
    s16 x;
    s16 y;
    s16 attr;
    switch (staff_r_no) {
    case 0:
        staff_r_no++;
        staffroll_end = 0;
        bg_w.bgw[5].xy[0].cal = 0x1000000;
        bg_w.bgw[5].wxy[0].cal = 0x1000000;
        bg_w.bgw[5].xy[1].cal = 0;
        bg_w.bgw[5].position_x = 0x100 - bg_w.pos_offset;
        bg_w.bgw[5].position_y = 0;
        Family_Set_R(6, -bg_w.bgw[5].position_x & 0x3FF, (0x300 - (bg_w.bgw[5].position_y & 0x3FF)) & 0x3FF);
        roll_rate2 = 1;
        roll_stop = 0;
        staff_name_ptr = 0;
        end_w.timer = 0;
        name_timer = 0;
        staff_roll_timer = 0x1E96;
        break;
    case 1:
        if (staff_roll_skip_check()) {
            staff_r_no = 4;
            end_w.timer = 0;
        } else {
            roll_rate_t2 = 1;
        }
        if (end_w.timer >= 0) {
            end_w.timer -= roll_rate_t2;
            staff_roll_timer -= roll_rate_t2;
        } else {
            if (staff_roll_tbl[staff_name_ptr].str == 0) {
                staff_r_no = 3;
                end_w.timer = staff_roll_tbl[staff_name_ptr].wait;
                break;
            }
            name_timer = 0x7FFF;
            line = &staff_roll_tbl[staff_name_ptr];
            x = line->x;
            y = line->y;
            attr = line->attr;
            staff_roll_put(240, x, y, attr, line->str);
            end_w.timer = staff_roll_tbl[staff_name_ptr].wait;
            staff_name_ptr++;
            if (end_w.timer <= 0) {
                line = &staff_roll_tbl[staff_name_ptr];
                x = line->x;
                y = line->y;
                attr = line->attr;
                staff_roll_put(240, x, y, attr, line->str);
                end_w.timer = staff_roll_tbl[staff_name_ptr].wait;
                staff_name_ptr++;
                if (end_w.timer <= 0) {
                    line = &staff_roll_tbl[staff_name_ptr];
                    x = line->x;
                    y = line->y;
                    attr = line->attr;
                    staff_roll_put(240, x, y, attr, line->str);
                    end_w.timer = 240;
                    staff_name_ptr++;
                }
            }
        }
        if (name_timer >= 0) {
            name_timer -= roll_rate_t2;
            break;
        }
        line = &staff_roll_tbl[staff_name_ptr];
        name_timer = line->wait;
        x = line->x;
        y = line->y;
        attr = line->attr;
        staff_roll_put(20, x, y, attr, line->str);
        staff_name_ptr++;
        line = &staff_roll_tbl[staff_name_ptr];
        x = line->x;
        y = line->y;
        attr = line->attr;
        staff_roll_put(20, x, y, attr, line->str);
        staff_name_ptr++;
        if (staff_roll_tbl[staff_name_ptr].wait == 0) {
            line = &staff_roll_tbl[staff_name_ptr];
            x = line->x;
            y = line->y;
            attr = line->attr;
            staff_roll_put(20, x, y, attr, line->str);
            staff_name_ptr++;
            line = &staff_roll_tbl[staff_name_ptr];
            x = line->x;
            y = line->y;
            attr = line->attr;
            staff_roll_put(20, x, y, attr, line->str);
            staff_name_ptr++;
            if (staff_roll_tbl[staff_name_ptr].wait == 0) {
                line = &staff_roll_tbl[staff_name_ptr];
                x = line->x;
                y = line->y;
                attr = line->attr;
                staff_roll_put(20, x, y, attr, line->str);
                staff_name_ptr++;
                line = &staff_roll_tbl[staff_name_ptr];
                x = line->x;
                y = line->y;
                attr = line->attr;
                staff_roll_put(20, x, y, attr, line->str);
                staff_name_ptr++;
                if (staff_roll_tbl[staff_name_ptr].wait == 0) {
                    line = &staff_roll_tbl[staff_name_ptr];
                    x = line->x;
                    y = line->y;
                    attr = line->attr;
                    staff_roll_put(20, x, y, attr, line->str);
                    staff_name_ptr++;
                    line = &staff_roll_tbl[staff_name_ptr];
                    x = line->x;
                    y = line->y;
                    attr = line->attr;
                    staff_roll_put(20, x, y, attr, line->str);
                    staff_name_ptr++;
                    if (staff_roll_tbl[staff_name_ptr].wait == 0) {
                        line = &staff_roll_tbl[staff_name_ptr];
                        x = line->x;
                        y = line->y;
                        attr = line->attr;
                        staff_roll_put(20, x, y, attr, line->str);
                        staff_name_ptr++;
                        line = &staff_roll_tbl[staff_name_ptr];
                        x = line->x;
                        y = line->y;
                        attr = line->attr;
                        staff_roll_put(20, x, y, attr, line->str);
                        staff_name_ptr++;
                    }
                }
            }
        }
        break;
    case 2:
    case 3:
        if (end_w.timer >= 0) {
            end_w.timer -= roll_rate_t2;
        } else {
            staff_r_no++;
        }
        if (staff_roll_skip_check()) {
            staff_r_no = 4;
            end_w.timer = 0;
        }
        break;
    default:
        staffroll_end = 1;
        break;
    }
    return staffroll_end;
}



/* provisional name */
void debug_play07(void) {
    void (*jmp_tbl[2])() = { debug_play07_init, debug_play07_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play07_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play07_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}



/* provisional name */
void debug_play08(void) {
    void (*jmp_tbl[2])() = { debug_play08_init, debug_play08_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play08_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play08_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}



/* provisional name */
void debug_play09(void) {
    void (*jmp_tbl[2])() = { debug_play09_init, debug_play09_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play09_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play09_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}



/* provisional name */
void debug_play10(void) {
    void (*jmp_tbl[2])() = { debug_play10_init, debug_play10_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play10_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play10_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}



/* provisional name */
void debug_play11(void) {
    void (*jmp_tbl[2])() = { debug_play11_init, debug_play11_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play11_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play11_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}



/* provisional name */
void debug_play12(void) {
    void (*jmp_tbl[2])() = { debug_play12_init, debug_play12_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play12_init(void) {
    G_No2++;
    dbg_play12_w[0] = dbg_play12_w[1] = dbg_play12_w[2] = dbg_play12_w[3] = 0;
    effect_work_quick_init();
    bg_work_clear();
}



/* provisional name */
void debug_play12_move(void) { hit_check_main_process(); }


/* provisional name */
void debug_play12_dummy(void) {}



/* provisional name */
void debug_play13(void) {
    void (*jmp_tbl[2])() = { debug_play13_init, debug_play13_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play13_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play13_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}

void init_color_trans_req(void)
{
    /* colour transfer request work: 256-byte request table and its three counters */
    col_trans_req_cnt0 = 0;
    col_trans_req_cnt1 = 0;
    col_trans_req_cnt2 = 0;
    memset(col_trans_req_tbl, 0, 256);
}



void load_any_color(ix)
u8 ix;
{
    const XFER* p = &any_color_tbl[ix];
    s32 zero = 0;
    polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
}



/* provisional name */
void load_bg_color(ix)
u8 ix;
{
    const XFER* p = &bg_color_tbl[ix];
    s32 zero = 0;
    polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
}

/* provisional name */
void load_bg_color_fade(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &bg_color_tbl[col_no & 0xFF];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r + 0x40, g + 0x40, b + 0x40);
}

/* provisional name */
void load_any_color_fade(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &any_color_tbl[col_no & 0xFF];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r + 0x40, g + 0x40, b + 0x40);
}

/* provisional name */
void load_any_color_attr(u16 col_no, u8 r, u8 g, u8 b)
{
    const XFER *xfer = &any_color_tbl[col_no & 0xFF];

    polygon2d_submit_quad(xfer->src, xfer->dst, xfer->size, r, g, b);
}

/* provisional name */
void load_any_color_req(col_no, r, g, b)
u16 col_no;
u8 r;
u8 g;
u8 b;
{
    const XFER *xfer = &any_color_tbl[col_no & 0xFF];

    polygon2d_queue_quad(xfer->src, xfer->dst, xfer->size, r, g, b);
}



/* provisional name */
void color_trans_dummy(void)
{
  return;
}



/* provisional name */
void load_player_color(a, b, c)
    u16 a;
    s16 b;
    s16 c;
{
    s32 zero = 0;
    const XFER* p = player_color_tbl[a][b][c];
    s8 i;
    for (i = 0; i < 14; i++, p++) {
        if (p->size) {
            col_trans_result = polygon2d_submit_quad(p->src, p->dst, p->size, zero, zero, zero);
        }
    }
}



void metamor_color_restore(u16 wkid) {
    s16 zero = 0;
    const u32* p = metamor_color_tbl[wkid][Player_Color[wkid]][0];
    col_trans_result = polygon2d_submit_quad(p[0], p[1], p[2], zero, zero, zero);
    col_trans_result = polygon2d_submit_quad(p[0], p[1] + 0x400, p[2], zero, zero, zero);
}



/* provisional name */
void load_player_color_fade(u16 a, s16 b, s16 c, u8 d, u8 e, u8 f) {
    const XFER* p = player_color_tbl[a][b][c];
    s8 i;
    for (i = 0; i < 13; i++, p++) {
        col_trans_result = polygon2d_submit_quad(p->src, p->dst, p->size, d + 64, e + 64, f + 64);
    }
}



/* provisional name */
void load_char_eff_color(ix, slot)
u16 ix;
u16 slot;
{
    col_trans_result = polygon2d_submit_quad(char_eff_color_tbl[ix], slot * 0x400 + 0x2000, 0x400, 0, 0, 0);
}



/* provisional name */
void load_side_color(u8 side, u16 ix) {
    s16 zero = 0;
    if (side) {
        polygon2d_submit_quad(side_color_2p_tbl[ix].src, 0xF000, side_color_2p_tbl[ix].size, zero, zero, zero);
    } else {
        polygon2d_submit_quad(side_color_1p_tbl[ix].src, 0xE000, side_color_1p_tbl[ix].size, zero, zero, zero);
    }
}

/* provisional name */
void load_player_sub_color(void)
{
    polygon2d_submit_quad(Player_Color[0] * 0x300 + 0x03389900, 0x2E00, 0x300, 0, 0, 0);
    polygon2d_submit_quad(Player_Color[1] * 0x300 + 0x03389900, 0x3100, 0x300, 0, 0, 0);
}



/* provisional name */
void load_opt_color(u16 ix) {
    const u32* p = &opt_color_tbl[ix];
    if (*p != 0) {
        polygon2d_submit_quad(*p, 0x2980, 0x80, 0, 0, 0);
    }
}

/*
 * END_SUB_2.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads (part 2)
 *
 * Routines: cd_keep_spinning_tick, cd_selftest_periodic, cd_error_fatal_hang, staff_roll_skip_check,
 * staff_roll_put, staff_roll_main.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Manage.h"
#include "manage_2.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "entry_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "cps3.h"

#pragma inline(card_pl_work_clear)



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
        bg_w.bgw[5].wxy[0].cal = bg_w.bgw[5].xy[0].cal = 0x1000000;
        bg_w.bgw[5].xy[1].cal = 0;
        bg_w.bgw[5].position_x = 0x100 - bg_w.pos_offset;
        bg_w.bgw[5].position_y = 0;
        Family_Set_R(6, -bg_w.bgw[5].position_x & 0x3FF, (0x300 - (bg_w.bgw[5].position_y & 0x3FF)) & 0x3FF);
        roll_rate2 = 1;
        roll_stop = staff_name_ptr = 0;
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
            staff_roll_timer = staff_roll_timer - roll_rate_t2;
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
            name_timer = name_timer - roll_rate_t2;
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

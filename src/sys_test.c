/*
 * sys_test.c  System library: scroll registers, test mode pages, CD/SCSI, coin chutes
 *
 * Scroll control: Bg_On_W / Bg_Off_W and the layer masks, Scrn_Move_Set and Scrn_Pos_Init set plane
 * positions, Irl_Family and scroll_layers_finalize_frame write the scroll and family registers each
 * frame, and the sprite slot setters point planes at their tilemaps. Operator test menu pages:
 * input and output tests, sound test, colour bars, screen cross hatch, backup RAM (game data)
 * display and clear, and the memory test with its RAM, SIMM and SRAM checks. The boot self-test
 * routines test cell, work, video, palette and sprite RAM and check the CD drive and disc ID; the
 * rewrite menu handles the CD-ROM setup screen. SCSI commands (test unit ready, mode sense, read
 * capacity, request sense, start/stop unit, medium lock, read(10)) drive the CD drive. The last
 * part runs the coin chutes, the service coin and the lockout coils each frame (the chute, credit
 * and switch routines they call are in coin_sw.c).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "meta_col.h"
#include "eeprom.h"
#include "sys_config.h"
#include "textsound.h"
#include "sys_test.h"
#include "cps3.h"



void Irl_Family(void) {
    volatile u16* reg;
    s32 i;
    u16 v;
    reg = (volatile u16*)VIDEO_REG;
    for (i = 0; i < 8; i++) {
        v = fm_pos[i].cur_x.disp.pos - zoom_adj_x + flip_obj_ofs_x;
        *reg = v & 0x3FF;
        reg++;
        v = fm_pos[i].cur_y.disp.pos + zoom_adj_y + flip_obj_ofs_y + 0xFFFEU;
        *reg = v & 0x3FF;
        reg++;
        fm_pos[i].cur_x.cal = fm_pos[i].set_x.cal;
        fm_pos[i].cur_y.cal = fm_pos[i].set_y.cal;
    }
}



/* provisional name: unreferenced; toggles a scroll layer's flip bits and applies them */
void scrn_flip_set(u16 n, u16 flip) {
    s32 unused;
    switch (flip) {
    case 0:
        scrn_mode_prm[n][0] ^= 0x800;
        scrn_mode_prm[n][1] = scrn_mode_prm[n][0];
        break;
    case 1:
        scrn_mode_prm[n][0] ^= 0x400;
        scrn_mode_prm[n][1] = scrn_mode_prm[n][0];
        break;
    case 2:
        scrn_mode_prm[n][0] ^= 0xC00;
        scrn_mode_prm[n][1] = scrn_mode_prm[n][0];
        break;
    }
}



/* provisional name: unreferenced; toggles a scroll layer's flip bits */
void scrn_flip_toggle(u16 n, u16 flip) {
    s32 unused;
    switch (flip) {
    case 0:
        scrn_mode_prm[n][0] ^= 0x800;
        break;
    case 1:
        scrn_mode_prm[n][0] ^= 0x400;
        break;
    case 2:
        scrn_mode_prm[n][0] ^= 0xC00;
        break;
    }
}



/* provisional name */
void clear_scroll_layer_state_and_mask(void) {
    s32 i;
    scroll_layer_mask_disable(0xFFF);
    for (i = 0; i < 4; i++) {
        scrn_reg_w[i].pos_x = 0;
        scrn_reg_w[i].pos_y = 0;
        scrn_reg_w[i].attr = 0;
        scrn_reg_w[i].ctrl = 0;
        scrn_reg_w[i].map_adrs = 0;
        scrn_mode_prm[i][0] = 0;
        scrn_mode_prm[i][1] = 0;
    }
}



/* provisional name */
void scroll_layer_mask_enable(mask)
u16 mask;
{
    Screen_Switch |= mask;
    Screen_Switch_Buffer = Screen_Switch &= 0xFFF;
    scroll_layer_commit();
}



void Bg_On_W(u16 mask) {
    Screen_Switch |= mask;
    Screen_Switch &= 0xFFF;
    Screen_Switch_Req = 1;
    scroll_layer_commit();
}



/* provisional name */
void scroll_layer_mask_disable(mask)
u16 mask;
{
    mask = ~mask;
    Screen_Switch &= mask;
    Screen_Switch_Buffer = Screen_Switch &= 0xFFF;
    scroll_layer_commit();
}



void Bg_Off_W(mask)
u16 mask;
{
    mask = ~mask;
    Screen_Switch &= mask;
    Screen_Switch &= 0xFFF;
    Screen_Switch_Req = 1;
    scroll_layer_commit();
}



/* provisional name */
void scroll_layer_commit(void) {
    s32 j;
    s32 i;
    u16 bit;
    u16 m;
    for (i = 0; i < 3; i++) {
        bit = scroll_enable_bit_tbl[i][0];
        for (j = 0; j < 4; j++) {
            m = Screen_Switch_Buffer;
            m &= bit;
            if (m == bit) {
                scrn_reg_w[j].ctrl |= scroll_enable_bit_tbl[i][1];
            } else {
                scrn_reg_w[j].ctrl &= ~scroll_enable_bit_tbl[i][1];
            }
            bit <<= 1;
        }
    }
    Screen_Switch_Buffer = Screen_Switch;
}



/* provisional name: unreferenced */
void scrn_line_set_now(n, v)
u16 n;
s16 v;
{
    scrn_line_prm[n][0] = v & 0x3FF;
    scrn_line_prm[n][1] = v & 0x3FF;
}



/* provisional name: unreferenced */
void scrn_line_set(u16 n, s16 v) {
    scrn_line_prm[n][0] = v & 0x3FF;
}



/* provisional name */
u32 simmram_large_page_addr(void) {
    u32 addr;
    u16 slot;
    slot = simmram_big_page_alloc_40(1);
    if (slot == 0) {
        return 0;
    }
    return simmram_slot_addr(slot);
}



/* provisional name */
u32 simmram_small_page_addr(void) {
    u32 addr;
    u16 slot;
    slot = simmram_small_page_alloc_40(1);
    if (slot == 0) {
        return 0;
    }
    return simmram_slot_addr(slot);
}



/* provisional name */
void scrn_map_set_now(n, p)
u16 n;
void* p;
{
    scrn_map_ptr[n].ptr0 = p;
    scrn_map_ptr[n].ptr2 = p;
}



/* provisional name */
void scrn_map_set(n, p)
u16 n;
void* p;
{
    scrn_map_ptr[n].ptr0 = p;
}



/* provisional name */
void scrn_linescroll_set_now(u16 n, void* p) {
    scrn_map_ptr[n].ptr1 = p;
    scrn_map_ptr[n].ptr3 = p;
}



/* provisional name: unreferenced */
void scrn_linescroll_set(n, p)
u16 n;
void* p;
{
    scrn_map_ptr[n].ptr1 = p;
}



/* provisional name */
void scrn_attr_set(n, attr, bits)
s16 n;
u16 attr;
u16 bits;
{
    scrn_reg_w[n].attr = attr << 6;
    scrn_reg_w[n].attr |= bits;
}



void Scrn_Pos_Init(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        scrn_pos[i].set_x.cal = 0;
        scrn_pos[i].cur_x.cal = 0;
        scrn_pos[i].set_y.cal = 0;
        scrn_pos[i].cur_y.cal = 0;
    }
}



/* provisional name */
void Scrn_Move_Set_R(s32 n, s16 x, s16 y) {
    scrn_pos[n].set_x.disp.pos = x;
    scrn_pos[n].cur_x.disp.pos = x;
    scrn_pos[n].set_y.disp.pos = y;
    scrn_pos[n].cur_y.disp.pos = y;
}



/* provisional name: unreferenced */
void Scrn_X_Set_R(ix, x)
    s32 ix;
    s16 x;
{
    scrn_pos[ix].set_x.disp.pos = x;
    scrn_pos[ix].cur_x.disp.pos = x;
}

/* provisional name */
void Scrn_Y_Set_R(ix, y)
    s32 ix;
    s16 y;
{
    scrn_pos[ix].set_y.disp.pos = y;
    scrn_pos[ix].cur_y.disp.pos = y;
}



void Scrn_Move_Set(n, x, y)
s32 n;
s16 x;
s16 y;
{
    scrn_pos[n].set_x.disp.pos = x;
    scrn_pos[n].set_y.disp.pos = y;
}



/* provisional name: unreferenced */
void Scrn_X_Set_W(s32 ix, s16 x)
{
    scrn_pos[ix].set_x.disp.pos = x;
}

/* provisional name */
void Scrn_Y_Set_W(s32 ix, s16 y)
{
    scrn_pos[ix].set_y.disp.pos = y;
}



/* provisional name: unreferenced */
void Scrn_Move_Add(s32 n, s32 dx, s32 dy) {
    scrn_pos[n].set_x.cal += dx;
    scrn_pos[n].set_y.cal += dy;
    if (n == 4) {
        scrn_pos[n].set_x.disp.pos &= 0x1FF;
        scrn_pos[n].set_y.disp.pos &= 0x1FF;
    } else {
        scrn_pos[n].set_x.disp.pos &= 0x3FF;
        scrn_pos[n].set_y.disp.pos &= 0x3FF;
    }
}



/* provisional name */
void scroll_layers_finalize_frame(void) {
    s32 i;
    s32 unused1;
    s32 addr;
    volatile u16* reg;
    s32 unused2;
    s16 w;
    reg = ((volatile u16*)(VIDEO_REG + 0x20));
    for (i = 0; i < 4; i++) {
        scrn_reg_w[i].pos_x = zoom_adj_x + scrn_pos[i].cur_x.disp.pos + flip_scr_ofs_x;
        scrn_reg_w[i].pos_x &= 0x3FF;
        *reg = scrn_reg_w[i].pos_x;
        reg++;
        if (((u8)Monitor_Flip) == 0) {
            scrn_reg_w[i].pos_y = -scrn_pos[i].cur_y.disp.pos + zoom_adj_y + flip_scr_ofs_y + 0xFEFC;
        } else {
            scrn_reg_w[i].pos_y = -scrn_pos[i].cur_y.disp.pos + zoom_adj_y + 4;
        }
        scrn_reg_w[i].pos_y &= 0x3FF;
        *reg = scrn_reg_w[i].pos_y;
        reg++;
        *reg = scrn_reg_w[i].attr;
        reg++;
        if (Screen_Switch_Req) {
            Screen_Switch_Req = 0;
            scroll_layer_commit();
        }
        w = scrn_reg_w[i].ctrl & ~0x3FF;
        w |= scrn_line_prm[i][1] & 0x3FF;
        scrn_reg_w[i].ctrl = w;
        scrn_reg_w[i].ctrl &= 0xF3FF;
        scrn_reg_w[i].ctrl |= scrn_mode_prm[i][1] & 0xC00;
        *reg = scrn_reg_w[i].ctrl;
        reg++;
        if (scrn_map_ptr[i].ptr2) {
            addr = (s32)scrn_map_ptr[i].ptr2;
            addr = (addr - SPRITE_RAM) >> 12;
            scrn_reg_w[i].map_adrs = addr;
            scrn_reg_w[i].map_adrs &= 0x7F;
        }
        if (scrn_map_ptr[i].ptr3) {
            addr = (s32)scrn_map_ptr[i].ptr3;
            addr = (addr - SPRITE_RAM) >> 4;
            w = addr;
            w &= 0x7F00;
            scrn_reg_w[i].map_adrs |= w;
        }
        *reg = scrn_reg_w[i].map_adrs;
        reg += 4;
        scrn_pos[i].cur_x.cal = scrn_pos[i].set_x.cal;
        scrn_pos[i].cur_y.cal = scrn_pos[i].set_y.cal;
        scrn_map_ptr[i].ptr2 = scrn_map_ptr[i].ptr0;
        scrn_map_ptr[i].ptr3 = scrn_map_ptr[i].ptr1;
        scrn_line_prm[i][1] = scrn_line_prm[i][0];
        scrn_mode_prm[i][1] = scrn_mode_prm[i][0];
    }
    (*(volatile u16*)(SS_REG + (0x0E))) = w = scrn_pos[4].cur_x.disp.pos + screen_base_x + flip_crt_ofs_x;
    (*(volatile u16*)(SS_REG + (0x10))) = w = w >> 8;
    (*(volatile u16*)(SS_REG + (0x20))) = w = -scrn_pos[4].cur_y.disp.pos + screen_base_y + flip_crt_ofs_y;
    (*(volatile u16*)(SS_REG + (0x22))) = w = w >> 8;
    scrn_pos[4].cur_x = scrn_pos[4].set_x;
    scrn_pos[4].cur_y = scrn_pos[4].set_y;
}



/* provisional name */
void iotest_draw_sw_grid(void) {
    register s16 i;
    register s16 j;
    register s32 x;
    register s16 diag1;
    register s16 diag2;
    i = j = 0;
    diag1 = diag2 = 0;
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    for (; i < 4; i++, j += 2) {
        if ((iotest_diag_bit_tbl[i] & p1sw_0) == iotest_diag_bit_tbl[i]) {
            tilemap_print_string_attr(iotest_1p_diag_x[j] + x, iotest_1p_diag_y[j], 8, iotest_on_str);
            diag1 = 1;
        } else {
            tilemap_print_string_attr(iotest_1p_diag_x[j] + x, iotest_1p_diag_y[j], 2, iotest_off_str);
        }
        if ((iotest_diag_bit_tbl[i] & p2sw_0) == iotest_diag_bit_tbl[i]) {
            tilemap_print_string_attr(iotest_2p_diag_x[j] + x, iotest_2p_diag_y[j], 8, iotest_on_str);
            diag2 = 1;
        } else {
            tilemap_print_string_attr(iotest_2p_diag_x[j] + x, iotest_2p_diag_y[j], 2, iotest_off_str);
        }
    }
    i = j = 0;
    for (; j < 12; i += 2, j++) {
        if (iotest_sw_bit_tbl[j] & p1sw_0) {
            if (j < 4) {
                if (diag1) {
                    tilemap_print_string_attr(iotest_1p_sw_x[i] + x, iotest_1p_sw_y[i], 2, iotest_off_str);
                } else {
                    tilemap_print_string_attr(iotest_1p_sw_x[i] + x, iotest_1p_sw_y[i], 8, iotest_on_str);
                }
            } else {
                tilemap_print_string_attr(iotest_1p_sw_x[i] + x, iotest_1p_sw_y[i], 8, iotest_on_str);
            }
        } else {
            tilemap_print_string_attr(iotest_1p_sw_x[i] + x, iotest_1p_sw_y[i], 2, iotest_off_str);
        }
        if (iotest_sw_bit_tbl[j] & p2sw_0) {
            if (j < 4) {
                if (diag2) {
                    tilemap_print_string_attr(iotest_2p_sw_x[i] + x, iotest_2p_sw_y[i], 2, iotest_off_str);
                } else {
                    tilemap_print_string_attr(iotest_2p_sw_x[i] + x, iotest_2p_sw_y[i], 8, iotest_on_str);
                }
            } else {
                tilemap_print_string_attr(iotest_2p_sw_x[i] + x, iotest_2p_sw_y[i], 8, iotest_on_str);
            }
        } else {
            tilemap_print_string_attr(iotest_2p_sw_x[i] + x, iotest_2p_sw_y[i], 2, iotest_off_str);
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != 1) {
            if (iotest_sys_bit_tbl[i] & syssw_0) {
                tilemap_print_string_attr(iotest_sys_sw_x[i * 2] + x, iotest_sys_sw_y[i * 2], 8, iotest_on_str);
            } else {
                tilemap_print_string_attr(iotest_sys_sw_x[i * 2] + x, iotest_sys_sw_y[i * 2], 2, iotest_off_str);
            }
        }
    }
}



/* provisional name */
s32 iotest_input_page(void) {
    register s32 rc;
    register s32 x;
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    switch (iotest_in_no) {
    case 0:
        tilemap_fill_all(0, 32);
        tilemap_print_string(x, 0, 0xFFFF, iotest_input_scr);
        iotest_in_no++;
        break;
    case 1:
        iotest_draw_sw_grid();
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        iotest_in_no = 0;
        return rc;
    }
    rc = 0;
    return rc;
}



/* provisional name */
void iotest_output_toggle(void) {
    register u16 trig1;
    register u16 trig2;
    register s32 unused;
    trig1 = ~p1sw_1 & p1sw_0;
    trig2 = ~p2sw_1 & p2sw_0;
    if (trig1 & 0x10) {
        if (iotest_out1_flag != 0) {
            iotest_out1_flag = 0;
        } else {
            iotest_out1_flag = 1;
        }
        if (iotest_out1_flag != 0) {
            coin_out_latch |= 1;
        } else {
            coin_out_latch &= ~1;
        }
    }
    if (trig2 & 0x10) {
        if (iotest_out2_flag != 0) {
            iotest_out2_flag = 0;
        } else {
            iotest_out2_flag = 1;
        }
        if (iotest_out2_flag != 0) {
            coin_out_latch |= 2;
        } else {
            coin_out_latch &= ~2;
        }
    }
    if ((p1sw_0 & 0x20) == 0x20 && (p1sw_1 & 0x20) != 0x20) {
        iotest_hold_flag = 1;
        coin_out_latch |= 0x10;
        coin_out_latch |= 0x20;
    } else if ((p1sw_0 & 0x20) != 0x20 && (p1sw_1 & 0x20) == 0x20) {
        iotest_hold_flag = 0;
        coin_out_latch &= ~0x10;
        coin_out_latch &= ~0x20;
    } else if ((p2sw_0 & 0x20) != 0x20 && (p2sw_1 & 0x20) == 0x20) {
        if (Card_Dispenser != 0) {
            card_out_req++;
        }
    }
}



/* provisional name */
s32 iotest_output_page(void) {
    register s32 rc;
    register s32 x;
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    switch (iotest_out_no) {
    case 0:
        tilemap_fill_all(0, 32);
        tilemap_print_string(x, 0, 0xFFFF, iotest_output_scr);
        if (Card_Dispenser != 0) {
            tilemap_print_string(x, 0, 0xFFFF, iotest_dispenser_str);
        }
        iotest_hold_flag = 0;
        iotest_out1_flag = iotest_out2_flag = 0;
        iotest_save_flip = (s8)Monitor_Flip;
        iotest_out_no++;
        break;
    case 1:
        iotest_output_toggle();
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        iotest_out_no = 0;
        Monitor_Flip = iotest_save_flip_low;
        coin_out_latch &= ~1;
        coin_out_latch &= ~2;
        coin_out_latch &= ~0x10;
        coin_out_latch &= ~0x20;
        if (iotest_hold_flag != 0) {
            coin_out_latch &= ~0x10;
            coin_out_latch &= ~0x20;
        }
        return rc;
    }
    rc = 0;
    return rc;
}



/* provisional name */
void soundtest_draw_title(void) {
    tilemap_fill_all(0, 32);
    if (screen_mode == 7) {
        tilemap_print_string(4, 0, 0xFFFF, soundtest_menu_scr);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, soundtest_menu_scr);
    }
    soundtest_no++;
}



/* provisional name */
void soundtest_code_select(void) {
    register u16 trig;
    register u8 sys;
    register s32 unused;
    register s32 x;
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    sys = ~syssw_1 & syssw_0;
    if (p1sw_0 == p1sw_1) {
        if (soundtest_rep_timer == 0) {
            trig = p1sw_0;
        } else {
            soundtest_rep_timer--;
            trig = ~p1sw_1 & p1sw_0;
        }
    } else {
        soundtest_rep_timer = 30;
        trig = ~p1sw_1 & p1sw_0;
    }
    if (trig & 8) {
        soundtest_code += 16;
    } else if (trig & 4) {
        soundtest_code -= 16;
    } else if (trig & 1) {
        soundtest_code += 1;
    } else if (trig & 2) {
        soundtest_code -= 1;
    }
    trig = ~p1sw_1 & p1sw_0;
    if (trig & 0x10) {
        sound_request(soundtest_code);
    } else if (trig & 0x20) {
        bgm_stop();
    }
    tilemap_print_hex_block(x + 30, 7, 2, soundtest_code, 4, 0);
}



/* provisional name */
s32 soundtest_page(void) {
    register s32 rc;
    switch (soundtest_no) {
    case 0:
        soundtest_draw_title();
        break;
    case 1:
        soundtest_code_select();
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        soundtest_no = 0;
        soundtest_code = 0;
        soundtest_rep_timer = 30;
        sound_driver_init();
        return rc;
    }
    rc = 0;
    return rc;
}

/* provisional name */
void soundtest_monitor_task(void) {
    s32 i;
    s16 status;
    u16 on;
    u16 bit;
    u16 req;
    s32 level;
    u16 pan;
    u16 level_l;
    u16 level_r;
    volatile SNDVOICEREG* voice;
    s32 unused1;
    s32 unused2;
    req = 0;
    tilemap_fill_all(0, 32);
    tilemap_print_string(0, 0, 0xFFFF, soundtest_monitor_scr);
    tilemap_print_hex(30, 3, 2, req, 4, 0);
    status = sound_driver_version();
    tilemap_print_hex(10, 3, 2, status, 4, 0);
    task_sleep(1);
    for (;;) {
        if ((p1sw_0 & 0x1010) != 0x1010) {
            break;
        }
        task_sleep(1);
    }
    for (;;) {
        if ((p1sw_0 & 0x1010) == 0x1010) {
            break;
        }
        if ((p1sw_0 & 4) == 4 && (p1sw_1 & 4) != 4) {
            req--;
            tilemap_print_hex(30, 3, 2, req, 4, 0);
        } else if ((p1sw_0 & 8) == 8 && (p1sw_1 & 8) != 8) {
            req++;
            tilemap_print_hex(30, 3, 2, req, 4, 0);
        } else if ((p1sw_0 & 1) == 1 && (p1sw_1 & 1) != 1) {
            req += 16;
            tilemap_print_hex(30, 3, 2, req, 4, 0);
        } else if ((p1sw_0 & 2) == 2 && (p1sw_1 & 2) != 2) {
            req -= 16;
            tilemap_print_hex(30, 3, 2, req, 4, 0);
        } else if ((p1sw_0 & 0x10) == 0x10 && (p1sw_1 & 0x10) != 0x10) {
            sound_request(req);
        } else if ((p1sw_0 & 0x20) == 0x20 && (p1sw_1 & 0x20) != 0x20) {
            sound_driver_init();
        }
        status = sound_status_read();
        if (status & 1) {
            tilemap_print_string_attr(10, 5, 2, snd_stat_stop_str);
        }
        if (status & 2) {
            tilemap_print_string_attr(10, 5, 2, snd_stat_play_str);
        }
        if (status & 4) {
            tilemap_print_string_attr(10, 5, 2, snd_stat_pause_str);
        }
        tilemap_print_string_attr(10, 9, 2, snd_stat_blank_str);
        if (status & 8) {
            tilemap_print_string_attr(10, 6, 2, snd_stat_fadein_str);
        }
        if (status & 0x10) {
            tilemap_print_string_attr(10, 6, 2, snd_stat_fadeout_str);
        }
        on = snd_key_on_reg;
        bit = 1;
        voice = (volatile SNDVOICEREG*)SOUND_REG;
        for (i = 0; i < 16; i++) {
            pan = voice->pan;
            if ((on & bit) == 0) {
                soundtest_print_pan_bar(4, i + 9, -1);
            } else {
                soundtest_print_pan_bar(4, i + 9, ((pan & 0xFFF) + 1) / 256);
            }
            level_l = voice->level_l;
            level_r = voice->level_r;
            tilemap_print_hex(21, i + 9, 2, pan, 4, 0);
            level = ((level_l & 0x7FFF) + (level_r & 0x7FFF)) / 2 + 1;
            soundtest_print_level_bar(40, i + 9, (u32)level >> 12);
            soundtest_print_lr_balance(30, i + 9, level_l, level_r);
            bit <<= 1;
            voice++;
        }
        task_sleep(1);
    }
    sound_driver_init();
    task_sleep(1);
}



/* provisional name */
void soundtest_print_pan_bar(s32 x, s32 y, s32 pan) {
    tilemap_print_string_attr(x, y, 2, pan_bar_str);
    if (pan != -1) {
        tilemap_put_char(x + (pan & 15), y, 2, 35);
    }
}



/* provisional name */
void soundtest_print_lr_balance(s32 x, s32 y, s32 now, s32 old) {
    if (now == old) {
        tilemap_print_string_attr(x, y, 2, delta_same_str);
    } else if (now > old) {
        tilemap_print_string_attr(x, y, 2, delta_up_str);
    } else {
        tilemap_print_string_attr(x, y, 2, delta_down_str);
    }
}



/* provisional name */
void soundtest_print_level_bar(s32 x, s32 y, s32 level) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (i < level) {
            tilemap_put_char(i + x, y, 2, 17);
        } else {
            tilemap_put_char(i + x, y, 2, 45);
        }
    }
}



/* provisional name */
void colortest_draw_title(void) {
    tilemap_fill_all(0, 32);
    if (screen_mode == 7) {
        tilemap_print_string(4, 0, 0xFFFF, colortest_scr);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, colortest_scr);
    }
    palette_write(0, colortest_palette, 0x85);
    colortest_no++;
}



/* provisional name */
void colortest_draw_palette_grid(void) {
    register s16 i;
    register s16 j;
    register s16 k;
    register s32 x;
    register s32 y;
    register s16 bank;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    x = 10;
    y = 5;
    bank = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 16; k++) {
                tilemap_put_block(x + col, y, (i * 2 + bank) * 2, k + 16);
                x++;
            }
            switch (i) {
            case 0:
                tilemap_put_block(x + col, y, 16, 17);
                break;
            case 1:
                tilemap_put_block(x + col, y, 16, 18);
                break;
            case 2:
                tilemap_put_block(x + col, y, 16, 19);
                break;
            case 3:
                tilemap_put_block(x + col, y, 16, 20);
            }
            x++;
            for (k = 0; k < 15; k++) {
                tilemap_put_block(x + col, y, (i * 2 + bank + 1) * 2, k + 17);
                x++;
            }
            x = 10;
            y++;
        }
        y++;
    }
    colortest_no++;
}



/* provisional name */
s32 colortest_page(void) {
    register s32 rc;
    switch (colortest_no) {
    case 0:
        colortest_draw_title();
        break;
    case 1:
        colortest_draw_palette_grid();
        break;
    case 2:
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        colortest_no = 0;
        return rc;
    }
    rc = 0;
    return rc;
}



/* provisional name */
void screentest_draw_crosshatch(void) {
    register s16 x;
    register s16 y;
    register s16 attr;
    register s16 ofs;
    register s16 cols;
    register s16 rows;
    register u16* p;
    switch (screen_mode) {
    case 3:
        cols = 24;
        ofs = 0;
        break;
    case 7:
        cols = 31;
        ofs = 4;
    }
    rows = 14;
    tilemap_fill_all(0, 32);
    p = (u16*)SS_RAM_CACHED;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            if (y == 0 || x == 0 || x == cols - 1 || y == rows - 1) {
                attr = 8;
            } else {
                attr = 2;
            }
            p[0] = 127;
            p[1] = attr;
            p[2] = 127;
            p[3] = attr | 0x80;
            p[0x80] = 127;
            p[0x81] = attr | 0x40;
            p[0x82] = 127;
            p[0x83] = attr | 0xC0;
            p += 4;
        }
        p += 0x100 - cols * 4;
    }
    tilemap_print_string(ofs, 0, 0xFFFF, crosshatch_scr);
    screentest_no++;
}



/* provisional name */
s32 screentest_page(void) {
    register s32 rc;
    switch (screentest_no) {
    case 0:
        screentest_draw_crosshatch();
        break;
    case 1:
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        screentest_no = 0;
        return rc;
    }
    rc = 0;
    return rc;
}



/* provisional name */
void gamedata_print_counters(void) {
    s32 unused;
    s32 x;
    u32 val[4];
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    eeprom_read(8, (volatile u16*)(EEP_ROM + 0x160), (u16*)val);
    tilemap_print_hex_block(x + 30, 7, 2, hex_to_bcd(val[0]), 6, 0);
    tilemap_print_hex_block(x + 30, 9, 2, hex_to_bcd(val[1]), 6, 0);
    if (Free_Play_Enable != 0) {
        tilemap_print_hex_block(x + 30, 11, 2, hex_to_bcd(val[2]), 6, 0);
        if (Area_Type == 3 || Area_Type == 4) {
            tilemap_print_hex_block(x + 30, 13, 2, hex_to_bcd(val[3]), 6, 0);
        }
    } else {
        if (Area_Type == 3 || Area_Type == 4) {
            tilemap_print_hex_block(x + 30, 11, 2, hex_to_bcd(val[3]), 6, 0);
        }
    }
}



/* provisional name */
void gamedata_draw_title(void) {
    s32 x;
    if (screen_mode == 7) {
        x = 4;
    } else {
        x = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(x, 0, 0xFFFF, gamedata_scr);
    if (Free_Play_Enable != 0) {
        tilemap_print_string(x, 0, 0xFFFF, gamedata_freeplay_str);
        if (Area_Type == 3 || Area_Type == 4) {
            tilemap_print_string(x, 2, 0xFFFF, gamedata_card_str);
        }
    } else {
        if (Area_Type == 3 || Area_Type == 4) {
            tilemap_print_string(x, 0, 0xFFFF, gamedata_card_str);
        }
    }
    backup_test_no++;
}



/* provisional name */
void gamedata_show_counters(void) {
    gamedata_print_counters();
    backup_test_no++;
}



/* provisional name */
void gamedata_clear_card_counter(void) {
    if ((p1sw_0 & 0x100) && (p1sw_0 & 0x200) && (p1sw_0 & 0x400)) {
        book_coin_count[3] = 0;
        if (eeprom_write(2, (volatile u16*)(EEP_ROM + 0x170), (u16*)&book_coin_count[3])) {
            eeprom_error_halt();
        }
        backup_test_no--;
    }
}



/* provisional name */
s32 gamedata_page(void) {
    register s32 rc;
    switch (backup_test_no) {
    case 0:
        gamedata_draw_title();
        break;
    case 1:
        gamedata_show_counters();
        break;
    case 2:
        gamedata_clear_card_counter();
        break;
    }
    if ((p1sw_0 & 0x1000) && (p1sw_0 & 0x10)) {
        rc = -1;
        backup_test_no = 0;
        return rc;
    }
    rc = 0;
    return rc;
}



/* provisional name */
s16 config_menu_page(void) {
    register s16 rc;
    switch (config_menu_no) {
    case 0:
        Config_No_0 = 0;
        rc = 0;
        config_menu_no++;
        break;
    case 1:
        rc = config_menu_run();
        break;
    }
    if (rc != 0) {
        config_menu_no = 0;
    }
    return rc;
}



/* provisional name */
u32 memtest_pattern_word(volatile u16* addr, u32 size) {
    register u16 got;
    register u16 save;
    register u32 i;
    register volatile u16* p;
    for (p = addr, i = 0; i < size; i += 2) {
        save = *p;
        *p = 0xFFFF;
        got = *p;
        *p = save;
        if (got != 0xFFFF) {
            return (u32)p;
        }
        *p = 0xAAAA;
        got = *p;
        *p = save;
        if (got != 0xAAAA) {
            return (u32)p;
        }
        *p = 0x5555;
        got = *p;
        *p = save;
        if (got != 0x5555) {
            return (u32)p;
        }
        *p = 0;
        got = *p;
        *p = save;
        if (got != 0) {
            return (u32)p;
        }
        p++;
    }
    return 0;
}

/* provisional name */
u16 * memtest_pattern_byte_lane(u16 *start, u32 size)
{
    volatile u16 *addr;
    u16 save;
    u16 read;
    u32 i;
    addr = start;
    i = 0;
    do {
        save = *addr;
        *addr = 0xFFFF;
        read = *addr;
        *addr = save;
        if ((read & 0xFF) != 0xFF) {
            return (u16 *)addr;
        }
        *addr = 0xAAAA;
        read = *addr;
        *addr = save;
        if ((read & 0xFF) != 0xAA && read != 0xAAAA) {
            return (u16 *)addr;
        }
        *addr = 0x5555;
        read = *addr;
        *addr = save;
        if ((read & 0xFF) != 0x55) {
            return (u16 *)addr;
        }
        *addr = 0;
        read = *addr;
        *addr = save;
        if ((read & 0xFF) != 0) {
            return (u16 *)addr;
        }
        i++;
        addr++;
    } while (i < (size >> 1));
    return (u16 *)0;
}



/* provisional name */
u32 memtest_pattern_masked_word(volatile u16* addr, u32 size) {
    register u16 got;
    register u16 save;
    register u32 i;
    register volatile u16* p;
    i = 0;
    p = addr;
    while (1) {
        save = *p;
        *p = 0xFFFF;
        got = *p;
        *p = save;
        if ((got & 0x7FFF) != 0x7FFF) {
            return (u32)p;
        }
        *p = 0xAAAA;
        got = *p;
        *p = save;
        if ((got & 0x7FFF) != 0x2AAA && got != 0xAAAA) {
            return (u32)p;
        }
        *p = 0x5555;
        got = *p;
        *p = save;
        if ((got & 0x7FFF) != 0x5555) {
            return (u32)p;
        }
        *p = 0;
        got = *p;
        *p = save;
        if (got & 0x7FFF) {
            return (u32)p;
        }
        i++;
        p++;
        if (i >= size >> 1) {
            break;
        }
    }
    return 0;
}



/* provisional name */
u32 memtest_pattern_stride_8(volatile u16* addr, u32 size) {
    register u16 got;
    register u16 save;
    register u32 i;
    register volatile u16* p;
    for (p = addr, i = 0; i < size; i += 8) {
        save = *p;
        *p = 0xFFFF;
        got = *p;
        *p = save;
        if (got != 0xFFFF) {
            return (u32)p;
        }
        *p = 0xAAAA;
        got = *p;
        *p = save;
        if (got != 0xAAAA) {
            return (u32)p;
        }
        *p = 0x5555;
        got = *p;
        *p = save;
        if (got != 0x5555) {
            return (u32)p;
        }
        *p = 0;
        got = *p;
        *p = save;
        if (got != 0) {
            return (u32)p;
        }
        p++;
    }
    return 0;
}



/* provisional name */
void memtest_work_ram(void) {
    register s32 err;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 3, 2, memtest_checking_str);
    _builtin_set_imask(15);
    err = memtest_pattern_word((volatile u16*)WORK_RAM, 0x80000);
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 3, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 3, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 3, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_sprite_ram(void) {
    register s32 err;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 5, 2, memtest_checking_str);
    _builtin_set_imask(15);
    err = memtest_pattern_word((volatile u16*)SPRITE_RAM, 0x7E000);
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 5, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 5, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 5, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_color_ram(void) {
    register s32 err;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 7, 2, memtest_checking_str);
    _builtin_set_imask(15);
    err = memtest_pattern_masked_word((volatile u16*)COLOR_RAM, 0x40000);
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 7, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 7, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 7, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_character_ram(void) {
    register s32 err;
    register u32 bank;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 9, 2, memtest_checking_str);
    _builtin_set_imask(15);
    for (bank = 0; bank < 8; bank++) {
        *(volatile u16*)(VIDEO_REG + 0x86) = bank;
        err = memtest_pattern_stride_8((volatile u16*)CHARACTER_RAM, 0x100000);
        if (err) {
            break;
        }
    }
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 9, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 9, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 9, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_ss_ram(void) {
    register s32 err;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 11, 2, memtest_checking_str);
    _builtin_set_imask(15);
    err = ((u32(*)(volatile u16* addr, u32 size))memtest_pattern_byte_lane)((volatile u16*)SS_RAM, 0xC800);
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 11, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 11, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 11, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_eeprom(void) {
    register s32 err;
    register s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 13, 2, memtest_checking_str);
    _builtin_set_imask(15);
    err = eeprom_test((u16*)eeprom_w);
    _builtin_set_imask(1);
    if (err) {
        tilemap_print_string_attr(col + 30, 13, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 13, 2, err, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 13, 2, memtest_ok_str);
    }
}



/* provisional name */
void memtest_sram(void) {
    u8 got;
    u8 save;
    s32 i;
    s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_print_string_attr(col + 30, 15, 2, memtest_checking_str);
    _builtin_set_imask(15);
    for (i = 0; i < 0x200; i++) {
        save = sram_read_byte(i);
        sram_write_byte(i, 0xFF);
        got = sram_read_byte(i);
        sram_write_byte(i, save);
        if (got != 0xFF) {
            break;
        }
        sram_write_byte(i, 0xAA);
        got = sram_read_byte(i);
        sram_write_byte(i, save);
        if (got != 0xAA) {
            break;
        }
        sram_write_byte(i, 0x55);
        got = sram_read_byte(i);
        sram_write_byte(i, save);
        if (got != 0x55) {
            break;
        }
        sram_write_byte(i, 0);
        got = sram_read_byte(i);
        sram_write_byte(i, save);
        if (got != 0) {
            break;
        }
    }
    _builtin_set_imask(1);
    if (i < 0x200) {
        tilemap_print_string_attr(col + 30, 15, 8, memtest_ng_str);
        tilemap_print_hex_block(col + 33, 15, 2, i * 2 + SRAM, 8, 0);
        memtest_error = 1;
    } else {
        tilemap_print_string_attr(col + 30, 15, 2, memtest_ok_str);
    }
}



/* provisional name */
s32 cd_check_drive_inquiry(void) {
    s32 rc;
    if (no_cd_flag) {
        return 0;
    }
    while (1) {
        rc = scsi_test_unit_ready(1);
        if ((rc = scsi_decode_sense_key(rc)) == -1) {
            return -1;
        }
        if (rc == 0) {
            break;
        }
    }
    while (1) {
        rc = scsi_inquiry(36, 1, scsi_mode_buf);
        if ((rc = scsi_decode_sense_key(rc)) == -1) {
            return -1;
        }
        if (rc == 0) {
            break;
        }
    }
    if (scsi_mode_buf[0] != 5) {
        return -1;
    }
    return 0;
}



/* provisional name */
s32 cd_check_disc_id(void) {
    s32 rc;
    u32 blen;
    s32 last;
    if (no_cd_flag) {
        return 0;
    }
    while (1) {
        rc = scsi_test_unit_ready(1);
        if ((rc = scsi_decode_sense_key(rc)) == -1) {
            return -1;
        }
        if (rc == 0) {
            break;
        }
    }
    while (1) {
        rc = scsi_read_capacity(8, scsi_capacity_buf);
        if ((rc = scsi_decode_sense_key(rc)) == -1) {
            return -1;
        }
        if (rc == 0) {
            break;
        }
    }
    blen = scsi_capacity_buf[1];
    last = (blen >> 8) - 1;
    while (1) {
        scsi_send_cdb_bytes(10, cdb_read_toc);
        rc = scsi_send_cdb_and_read(12, scsi_toc_buf);
        if ((rc = scsi_decode_sense_key(rc)) == -1) {
            return -1;
        }
        if (rc == 0) {
            break;
        }
    }
    if ((scsi_toc_buf[5] & 0xF) == 4) {
        while (1) {
            rc = scsi_read_10(16, 1, last, 1, cd_sector_buf);
            rc = scsi_decode_sense_key(rc);
            if (rc == -1) {
                return -1;
            }
            if (rc == 0) {
                break;
            }
        }
        if (cd_sector_buf[1] == 'C' && cd_sector_buf[2] == 'D' && cd_sector_buf[3] == '0' &&
            cd_sector_buf[4] == '0' && cd_sector_buf[5] == '1') {
            if (cd_sector_buf[0x28] == game_volume_id[0] && cd_sector_buf[0x29] == game_volume_id[1] &&
                cd_sector_buf[0x2a] == game_volume_id[2] && cd_sector_buf[0x2b] == game_volume_id[3] &&
                cd_sector_buf[0x2c] == game_volume_id[4] && cd_sector_buf[0x2d] == game_volume_id[5] &&
                cd_sector_buf[0x2e] == game_volume_id[6] && cd_sector_buf[0x2f] == game_volume_id[7] &&
                cd_sector_buf[0x30] == game_volume_id[8] && cd_sector_buf[0x31] == game_volume_id[9] &&
                cd_sector_buf[0x32] == game_volume_id[10]) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}



/* provisional name */
void memtest_cdrom(void) {
    s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    if (!no_cd_flag) {
        tilemap_print_string_attr(col + 30, 15, 2, memtest_checking_str);
        if (cd_check_drive_inquiry() == 0) {
            tilemap_print_string_attr(col + 30, 15, 2, memtest_ok_str);
        } else {
            tilemap_print_string_attr(col + 30, 15, 8, memtest_ng_str);
            memtest_error = 1;
        }
    } else {
        tilemap_print_string_attr(col + 30, 15, 2, memtest_skip_str);
    }
}



/* provisional name */
void memtest_simm_quick(void) {
    s32 slot;
    s32 j;
    u32 sum;
    s32 col;
    u8* p = ((u8*)0x1FED4);
    u8* q;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    for (slot = 1; slot < 8; slot++) {
        if (p[0] != 0) {
            tilemap_print_string_attr(col + 30, slot + 16, 2, memtest_checking_str);
            _builtin_set_imask(15);
            if (p[0] == 1) {
                sum = simm_quick_checksum(slot, 0);
            } else {
                sum = simm_quick_checksum(slot, 1);
            }
            if (sum % 256 != p[2]) {
                memtest_error = 1;
                q = ((u8*)0x1FED4);
                for (j = 1; j < 8; j++) {
                    if (q[0] != 0 && sum % 256 == q[2]) {
                        break;
                    }
                    q += 4;
                }
                if (j == 8) {
                    tilemap_print_string_attr(col + 30, slot + 16, 8, memtest_ng_str);
                } else {
                    tilemap_print_string_attr(col + 30, slot + 16, 8, simm_name_tbl[j]);
                }
            } else {
                tilemap_print_string_attr(col + 30, slot + 16, 2, memtest_ok_str);
            }
        } else {
            tilemap_print_string_attr(col + 30, slot + 16, 2, memtest_skip_str);
        }
        p += 4;
    }
}



/* provisional name */
void memtest_memory_check(void) {
    s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, memtest_ram_scr);
    memtest_work_ram();
    memtest_sprite_ram();
    memtest_color_ram();
    memtest_character_ram();
    memtest_ss_ram();
    memtest_eeprom();
    memtest_cdrom();
    memtest_simm_quick();
}



/* provisional name */
void simm_check_run(void) {
    s32 slot;
    u32 sum;
    s32 col;
    u8* p = ((u8*)0x1FED4);
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, memtest_simm_scr);
    for (slot = 1; slot < 8; slot++) {
        if (p[0] != 0) {
            tilemap_print_string_attr(col + 30, slot * 2 + 3, 2, memtest_checking_str);
            _builtin_set_imask(15);
            if (p[0] == 1) {
                sum = simm_full_checksum(slot, 0);
            } else {
                sum = simm_full_checksum(slot, 1);
            }
            if (sum % 256 != p[1]) {
                memtest_error = 1;
                tilemap_print_string_attr(col + 30, slot * 2 + 3, 8, memtest_ng_str);
            } else {
                tilemap_print_string_attr(col + 30, slot * 2 + 3, 2, memtest_ok_str);
            }
        } else {
            tilemap_print_string_attr(col + 30, slot * 2 + 3, 2, memtest_skip_str);
        }
        p += 4;
    }
}



/* provisional name */
void memtest_menu_init(void) {
    s32 col;
    memtest_cursor = 0;
    memtest_error = 0;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, memtest_menu_scr);
    tilemap_put_block(col + 15, 9, 2, 62);
    memtest_no++;
}



/* provisional name */
void memtest_menu_select(void) {
    s32 col;
    s32 unused;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    if ((p1sw_0 & 1) == 1 && (p1sw_1 & 1) != 1) {
        tilemap_put_block(col + 15, memtest_cursor * 2 + 9, 2, 32);
        if (--memtest_cursor < 0) {
            memtest_cursor = 2;
        }
        tilemap_put_block(col + 15, memtest_cursor * 2 + 9, 2, 62);
    } else if ((p1sw_0 & 2) == 2 && (p1sw_1 & 2) != 2) {
        tilemap_put_block(col + 15, memtest_cursor * 2 + 9, 2, 32);
        if (++memtest_cursor > 2) {
            memtest_cursor = 0;
        }
        tilemap_put_block(col + 15, memtest_cursor * 2 + 9, 2, 62);
    }
    if ((p1sw_0 & 0x10) == 0x10 && (p1sw_1 & 0x10) != 0x10) {
        switch (memtest_cursor) {
        case 0:
            memtest_memory_check();
            memtest_no++;
            break;
        case 1:
            simm_check_run();
            memtest_no++;
            break;
        default:
            memtest_no = 4;
            break;
        }
    }
}



/* provisional name */
s32 memtest_page(void) {
    register s32 rc;
    rc = 0;
    switch (memtest_no) {
    case 0:
        memtest_menu_init();
        break;
    case 1:
        memtest_menu_select();
        break;
    case 2:
        if (memtest_error == 0) {
            memtest_no++;
            memtest_wait = 60;
        }
        break;
    case 3:
        if (memtest_wait == 0) {
            memtest_no++;
        } else {
            memtest_wait--;
        }
        break;
    default:
        rc = -1;
        memtest_no = 0;
        break;
    }
    return rc;
}



/* provisional name */
u8 sram_read_byte(u32 addr) {
    volatile u8* p;
    u8 v;
    if (addr >= 0x200) {
        p = (volatile u8*)(SRAM + 0x3FE);
    } else {
        p = (volatile u8*)(addr * 2 + SRAM);
    }
    sram_bus_slow();
    v = p[1];
    delay_cycles(2);
    sram_bus_normal();
    return v;
}



/* provisional name */
void sram_write_byte(u32 addr, u8 v) {
    volatile u16* p;
    if (addr >= 0x200) {
        p = (volatile u16*)(SRAM + 0x3FE);
    } else {
        p = (volatile u16*)(addr * 2 + SRAM);
    }
    sram_bus_slow();
    *p = v;
    delay_cycles(2);
    sram_bus_normal();
}



/* provisional name */
void sram_bus_slow(void) {
    *(volatile u8*)SH2_CCR = 0x10;
    *(volatile u32*)SH2_BCR1 = 0xA55A00E0;
    *(volatile u32*)SH2_WCR = 0xA55AAA5F;
    *(volatile u8*)SH2_CCR = 0x11;
}



/* provisional name */
void sram_bus_normal(void) {
    *(volatile u8*)SH2_CCR = 0x10;
    *(volatile u32*)SH2_BCR1 = 0xA55A0020;
    *(volatile u32*)SH2_WCR = 0xA55AAA57;
    *(volatile u8*)SH2_CCR = 0x11;
}



/* provisional name */
u32 simm_full_checksum(s32 rom, s32 wide) {
    s32 mode;
    s32 bank;
    u32 port;
    s32 addr;
    s32 count;
    s32 chip;
    u32 sum;
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8* p;
    if (rom == 0) {
        chip = 0;
        mode = 0;
    } else if (rom > 2) {
        chip = rom - 2;
        mode = 0;
    } else {
        chip = rom - 1;
        mode = 1;
    }
    if (mode == 0) {
        if (chip == 0 || wide != 0) {
            count = 0x400000;
        } else {
            count = 0x1000000;
        }
        sum = 0;
        for (addr = 0; count > 0; addr++, count--) {
            bank = (chip - 1) * 8 + ((addr >> 21) & 0x3F) + 2;
            port = (addr & 0x1FFFFF) + SIMM_WINDOW;
            *(volatile u16*)(VIDEO_REG + 0x88) = bank;
            while (1) {
                a = *(volatile u8*)port;
                b = *(volatile u8*)port;
                c = *(volatile u8*)port;
                d = *(volatile u8*)port;
                if (a == b && c == d) {
                    break;
                }
            }
            sum += a;
        }
    } else {
        count = 0x800000;
        sum = 0;
        addr = (chip << 23) + 0x26000000;
        p = (u8*)((u32)&a + 0x20000000);
        for (; count > 0; addr++, count--) {
            dma0_transfer_wait(addr, (u32)p, 1, 0);
            sum += *p;
        }
    }
    return sum;
}



/* provisional name: unreferenced; sums one byte of each half of the given graphics SIMM banks */
s32 simm_bank_checksum(s32 slot, s32 count) {
    volatile u8* p;
    s32 i;
    s32 start;
    u32 sum;
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    if (slot == 0) {
        start = 0;
    } else if (slot > 2) {
        start = (slot - 3) * 8 + 2;
    } else {
        return -1;
    }
    sum = 0;
    for (i = start; i < start + count; i++) {
        *(volatile u16*)(VIDEO_REG + 0x88) = i;
        p = (volatile u8*)SIMM_WINDOW;
        while (1) {
            a = *p;
            b = *p;
            c = *p;
            d = *p;
            if (a == b && c == d) {
                break;
            }
        }
        sum += a;
        p = (volatile u8*)(SIMM_WINDOW + 0x100000);
        while (1) {
            a = *p;
            b = *p;
            c = *p;
            d = *p;
            if (a == b && c == d) {
                break;
            }
        }
        sum += a;
    }
    return sum % 256;
}



/* provisional name */
s32 simm_quick_checksum(s32 slot, s32 mode) {
    s32 i;
    s32 flash;
    s32 bank;
    s32 start;
    s32 count;
    u32 base;
    s32 sum;
    u8 b;
    u8* p;
    if (slot == 0) {
        bank = 0;
        flash = 0;
    } else if (slot > 2) {
        bank = slot - 2;
        flash = 0;
    } else {
        bank = slot - 1;
        flash = 1;
    }
    if (flash == 0) {
        if (slot == 0) {
            start = 0;
        } else {
            start = (slot - 3) * 8 + 2;
        }
        if (bank == 0 || mode != 0) {
            count = 2;
        } else {
            count = 8;
        }
        sum = 0;
        for (i = start; i < start + count; i++) {
            *(volatile u16*)(VIDEO_REG + 0x88) = i;
            sum += *(u8*)(simm_sum_offset_tbl[0] + SIMM_WINDOW);
            sum += *(u8*)(simm_sum_offset_tbl[1] + SIMM_WINDOW);
            sum += *(u8*)(simm_sum_offset_tbl[2] + SIMM_WINDOW);
            sum += *(u8*)(simm_sum_offset_tbl[3] + SIMM_WINDOW);
        }
    } else {
        base = bank * 0x800000 + 0x26000000;
        sum = 0;
        p = (u8*)((u32)&b + 0x20000000);
        for (i = 0; i < 16; i++) {
            dma0_transfer_wait(simm_sum_offset_tbl[i] + base, (u32)p, 1, 0);
            sum += *p;
        }
    }
    return sum;
}



/* provisional name */
s32 scsi_test_unit_ready(s32 lun) {
    scsi_send_cdb_bytes(6, cdb_test_unit_ready);
    return scsi_send_cdb_and_read(0, 0);
}



/* provisional name */
s32 scsi_inquiry(s32 len, s32 lun, u8* buf) {
    scsi_send_cdb_bytes(6, cdb_inquiry);
    return scsi_send_cdb_and_read(len, buf);
}



/* provisional name */
s32 scsi_read_capacity(s32 len, void* buf) {
    scsi_send_cdb_bytes(10, cdb_read_capacity);
    return scsi_send_cdb_and_read(len, buf);
}



/* provisional name */
s32 scsi_request_sense(s32 len, s32 lun, u8* buf) {
    scsi_send_cdb_bytes(6, cdb_request_sense);
    return scsi_send_cdb_and_read(len, buf);
}



/* provisional name */
s32 scsi_start_stop_unit(s32 op, s32 lun) {
    s8 cdb[12];
    if (no_cd_flag) {
        return 0;
    }
    cdb[0] = 0x1B;
    cdb[1] = 0;
    cdb[2] = 0;
    cdb[3] = 0;
    cdb[4] = op & 3;
    cdb[5] = 0;
    scsi_send_cdb_bytes(6, cdb);
    return scsi_send_cdb_and_read(0, 0);
}



/* provisional name */
s32 scsi_prevent_allow_medium_removal(s32 prevent, s32 lun) {
    s8 cdb[12];
    cdb[0] = 0x1E;
    cdb[1] = 0;
    cdb[2] = 0;
    cdb[3] = 0;
    cdb[4] = prevent & 1;
    cdb[5] = 0;
    scsi_send_cdb_bytes(6, cdb);
    return scsi_send_cdb_and_read(0, 0);
}



/* provisional name */
s32 scsi_read_10(s32 lba, s32 count, s32 blk, s32 unused, void* buf) {
    s8 cdb[10];
    cdb[0] = 0x28;
    cdb[1] = 0;
    cdb[2] = (lba & 0xFF000000) >> 24;
    cdb[3] = (lba & 0xFF0000) >> 16;
    cdb[4] = (lba & 0xFF00) >> 8;
    cdb[5] = lba;
    cdb[6] = 0;
    cdb[7] = (count & 0xFF00) >> 8;
    cdb[8] = count;
    cdb[9] = 0;
    scsi_send_cdb_bytes(10, cdb);
    return scsi_send_cdb_and_read((blk + 1) * count << 8, buf);
}



/* provisional name */
s32 scsi_send_cdb_bytes(s32 n, s8* cdb) {
    s32 i;
    s8* p;
    p = cdb;
    scsi_cdb_len = n;
    *(volatile u16*)CD_REG = 3;
    delay_cycles(17);
    for (i = 0; i < n; i++, p++) {
        *(volatile u16*)(CD_REG + 0x2) = *p;
        delay_cycles(17);
    }
    return 0;
}



/* provisional name */
s32 scsi_send_cdb_and_read(s32 lba, u8* buf) {
    s32 count;
    u8* dst;
    u8 cmd;
    u16 phase;
    u16 w14;
    u16 msg;
    u32 addr;
    s32 tries;
    u16 result;
    dst = buf;
    cmd = 33;
    tries = 0;
    scsi_error = 0;
    (*(volatile u16*)CD_REG) = 0;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = scsi_cdb_len;
    delay_cycles(17);
    cmd |= 64;
    (*(volatile u16*)CD_REG) = 15;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = 0;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = 0;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = 32;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = (s16)((lba & 0xFF0000) >> 16);
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = (lba & 0xFF00) >> 8;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = lba & 0xFF;
    delay_cycles(17);
    (*(volatile u16*)CD_REG) = 21;
    delay_cycles(17);
    (*(volatile u16*)(CD_REG + 0x2)) = cmd;
    delay_cycles(17);
    while (1) {
        tries++;
        for (count = 255; count > 0; count--) {
            if (((*(volatile u16*)CD_REG) & 0x30) == 0) {
                break;
            }
        }
        if (count == 0) {
            scsi_error = 2;
            return -1;
        }
        while (1) {
            if (((*(volatile u16*)CD_REG) & 0x80) == 0) {
                break;
            }
            (*(volatile u16*)CD_REG) = 23;
            delay_cycles(17);
            w14 = (*(volatile u16*)(CD_REG + 0x2));
        }
        (*(volatile u16*)CD_REG) = 24;
        delay_cycles(17);
        (*(volatile u16*)(CD_REG + 0x2)) = 8;
        delay_cycles(17);
        count = 0;
        while (1) {
            if ((*(volatile u16*)CD_REG) & 1) {
                count = 0;
                (*(volatile u16*)CD_REG) = 25;
                delay_cycles(17);
                *dst = (*(volatile u16*)(CD_REG + 0x2));
                dst++;
            } else {
                count++;
            }
            if ((*(volatile u16*)CD_REG) & 0x80) {
                break;
            }
            if (count == 0xFFFF0) {
                scsi_error = 2;
                return -1;
            }
        }
        (*(volatile u16*)CD_REG) = 23;
        delay_cycles(17);
        phase = (*(volatile u16*)(CD_REG + 0x2)) & 0xFF;
        if (phase == 22) {
            break;
        }
        (*(volatile u16*)CD_REG) = 19;
        delay_cycles(17);
        addr = ((*(volatile u16*)(CD_REG + 0x2)) & 0xFF) << 16;
        addr |= ((*(volatile u16*)(CD_REG + 0x2)) & 0xFF) << 8;
        addr |= (*(volatile u16*)(CD_REG + 0x2)) & 0xFF;
        (*(volatile u16*)CD_REG) = 16;
        delay_cycles(17);
        msg = (*(volatile u16*)(CD_REG + 0x2)) & 0xFF;
        switch (phase) {
        case 75:
            (*(volatile u16*)CD_REG) = 16;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = 70;
            delay_cycles(17);
            (*(volatile u16*)CD_REG) = 18;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = 0;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = 0;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = 0;
            delay_cycles(17);
            break;
        case 133:
            if (msg != 67) {
                scsi_error = 1;
                return -1;
            }
            while (((*(volatile u16*)CD_REG) & 0x80) == 0) {
            }
            phase = (*(volatile u16*)(CD_REG + 0x2)) & 0xFF;
            if (phase == 128) {
                (*(volatile u16*)CD_REG) = 16;
                delay_cycles(17);
                (*(volatile u16*)(CD_REG + 0x2)) = 68;
                delay_cycles(17);
            } else if (phase == 129) {
                (*(volatile u16*)CD_REG) = 25;
                delay_cycles(17);
                w14 = (*(volatile u16*)(CD_REG + 0x2));
                (*(volatile u16*)CD_REG) = 16;
                delay_cycles(17);
                (*(volatile u16*)(CD_REG + 0x2)) = 69;
                delay_cycles(17);
            } else {
                scsi_error = 1;
                return -1;
            }
            (*(volatile u16*)CD_REG) = 17;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = 32;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = (addr & 0xFF0000) >> 16;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = (addr & 0xFF00) >> 8;
            delay_cycles(17);
            (*(volatile u16*)(CD_REG + 0x2)) = addr & 0xFF;
            delay_cycles(17);
            break;
        default:
            scsi_error = 1;
            return -1;
        }
    }
    (*(volatile u16*)CD_REG) = 1;
    delay_cycles(17);
    w14 = (*(volatile u16*)(CD_REG + 0x2));
    if ((w14 & 8) == 0) {
        while (1) {
            if ((*(volatile u16*)CD_REG) & 0x80) {
                break;
            }
        }
        (*(volatile u16*)CD_REG) = 23;
        delay_cycles(17);
        phase = (*(volatile u16*)(CD_REG + 0x2)) & 0xFF;
        if (phase != 133) {
            (*(volatile u16*)CD_REG) = 15;
            delay_cycles(17);
            result = (*(volatile u16*)(CD_REG + 0x2)) & 0x1F;
            scsi_error = 1;
            return -1;
        }
    }
    (*(volatile u16*)CD_REG) = 15;
    delay_cycles(17);
    result = (*(volatile u16*)(CD_REG + 0x2)) & 0x1F;
    return result;
}



/* provisional name */
s32 scsi_decode_sense_key(s32 status) {
    switch (status) {
    case -1:
        if (scsi_error == 2) {
            return -1;
        }
        return 1;
        break;
    case 0:
        return 0;
    case 8:
        return 1;
    case 24:
        return -1;
    case 2:
    default:
        if (scsi_request_sense(22, 1, (u8*)scsi_sense_buf)) {
            return -1;
        }
        break;
    }
    scsi_sense_key = scsi_sense_buf[2];
    scsi_sense_asc = scsi_sense_buf[12];
    switch (scsi_sense_key) {
    case 0:
    case 1:
        scsi_error = 0;
        return 0;
    case 2:
        switch (scsi_sense_asc) {
        case 4:
            return 1;
        case 58:
        default:
            return -1;
        }
    case 5:
        return -1;
    case 7:
        return -1;
    case 3:
    case 4:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    default:
        return 1;
    }
}



/* provisional name */
void rewrite_menu_init(void) {
    s32 col;
    rewrite_cursor = 0;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    while (scsi_prevent_allow_medium_removal(0, 1)) {
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_menu_scr);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
    tilemap_put_block(col + 15, 9, 2, 62);
    rewrite_no++;
}



/* provisional name */
void rewrite_menu_select(void) {
    s32 col;
    s32 unused;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    if ((p1sw_0 & 1) == 1 && (p1sw_1 & 1) != 1) {
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 32);
        if (--rewrite_cursor < 0) {
            rewrite_cursor = 2;
        }
        if (rewrite_cursor == 2) {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_exit_guide_scr);
        } else {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
        }
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 62);
    } else if ((p1sw_0 & 2) == 2 && (p1sw_1 & 2) != 2) {
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 32);
        if (++rewrite_cursor > 2) {
            rewrite_cursor = 0;
        }
        if (rewrite_cursor == 2) {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_exit_guide_scr);
        } else {
            tilemap_print_string(col, 0, 0xFFFF, rewrite_guide_scr);
        }
        tilemap_put_block(col + 15, rewrite_cursor * 2 + 9, 2, 62);
    }
    if ((p1sw_0 & 0x10) == 0x10 && (p1sw_1 & 0x10) != 0x10) {
        if (rewrite_cursor == 2) {
            rewrite_no++;
        }
    } else if ((p1sw_0 & 0x1000) == 0x1000 && (p1sw_0 & 0x10) == 0x10) {
        tilemap_fill_all(0, 32);
        task_sleep(1);
        if (rewrite_cursor == 0) {
            bios_vector_restart(0x200, 0);
        } else {
            bios_vector_restart(0x208, 0);
        }
    }
}



/* provisional name */
void rewrite_cd_not_ready(void) {
    s32 col;
    if (screen_mode == 7) {
        col = 4;
    } else {
        col = 0;
    }
    tilemap_fill_all(0, 32);
    tilemap_print_string(col, 0, 0xFFFF, rewrite_not_ready_str);
    task_sleep(180);
    rewrite_no = 0;
}



/* provisional name */
s32 rewrite_page(void) {
    register s32 rc;
    if (no_cd_flag) {
        return -1;
    }
    rc = 0;
    switch (rewrite_no) {
    case 0:
        rewrite_menu_init();
        break;
    case 1:
        rewrite_menu_select();
        break;
    case 2:
        if (cd_check_drive_inquiry() == 0) {
            if (cd_check_disc_id() == 0) {
                while (scsi_prevent_allow_medium_removal(1, 1)) {
                }
                rc = -1;
                rewrite_no = 0;
            } else {
                rewrite_no++;
            }
        } else {
            rewrite_no++;
        }
        break;
    case 3:
        rewrite_cd_not_ready();
        break;
    }
    return rc;
}



/* provisional name */
void coin_chutes_update(s32 keep) {
    switch (Chute_Mode) {
    case 0:
    case 3:
    case 7:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 1:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 2:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        coin_counter_drive(0);
        break;
    case 4:
    case 8:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 5:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 6:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        coin_counter_drive(0);
        break;
    case 9:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        coin_counter_drive(0);
        break;
    case 10:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(3, keep)) {
            coin_credit_add(0, 0);
        }
        coin_counter_drive(0);
        break;
    case 11:
        if (coin_chute_check(0, keep)) {
            coin_credit_add(0, 0);
        }
        if (coin_chute_check(1, keep)) {
            coin_credit_add(1, 0);
        }
        if (coin_chute_check(2, keep)) {
            coin_credit_add(2, 0);
        }
        if (coin_chute_check(3, keep)) {
            coin_credit_add(3, 0);
        }
        coin_counter_drive(0);
        break;
    }
}



/* provisional name */
void service_coin_check(void) {
    if ((syssw_0 & 1) && !(syssw_1 & 1)) {
        bookkeep_service_count();
        coin_in_flag = 1;
        switch (Chute_Mode) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 10:
            credit_1p++;
            (*(s8*)&(coin_chute1_w[6])) = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            break;
        case 2:
        case 9:
            credit_1p++;
            (*(s8*)&(coin_chute1_w[6])) = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w[6] = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            break;
        case 6:
            credit_1p++;
            (*(s8*)&(coin_chute1_w[6])) = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w[6] = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            credit_3p++;
            coin3_in_flag = 1;
            if (credit_3p > 9) {
                credit_3p = 9;
            }
            break;
        case 11:
            credit_1p++;
            (*(s8*)&(coin_chute1_w[6])) = 1;
            if (credit_1p > 9) {
                credit_1p = 9;
            }
            credit_2p++;
            coin_chute2_w[6] = 1;
            if (credit_2p > 9) {
                credit_2p = 9;
            }
            credit_3p++;
            coin3_in_flag = 1;
            if (credit_3p > 9) {
                credit_3p = 9;
            }
            credit_4p++;
            coin4_in_flag = 1;
            if (credit_4p > 9) {
                credit_4p = 9;
            }
            break;
        }
    }
}



/* provisional name */
void coin_lockout_update(void) {
    if (Free_Play != 0) {
        coin_lock_set(-1);
    } else {
        switch (Chute_Mode) {
        case 0:
        case 3:
        case 7:
            coin_lock_check(0, 0);
            coin_lock_set(1);
            break;
        case 1:
            coin_lock_check(0, 0);
            coin_lock_check(0, 1);
            break;
        case 2:
            coin_lock_check(0, 0);
            coin_lock_check(1, 1);
            break;
        case 4:
        case 8:
            coin_lock_check(0, 0);
            coin_lock_check(0, 2);
            break;
        case 5:
            coin_lock_check(0, 0);
            coin_lock_check(0, 1);
            coin_lock_check(0, 2);
            break;
        case 6:
            coin_lock_check(0, 0);
            coin_lock_check(1, 1);
            coin_lock_check(2, 2);
            break;
        case 9:
            coin_lock_check(0, 0);
            coin_lock_check(2, 2);
            break;
        case 10:
            coin_lock_check(0, 0);
            coin_lock_check(0, 1);
            coin_lock_check(0, 2);
            coin_lock_check(0, 3);
            break;
        case 11:
            coin_lock_check(0, 0);
            coin_lock_check(1, 1);
            coin_lock_check(2, 2);
            coin_lock_check(3, 3);
            break;
        }
    }
}



/* provisional name */
void coin_work_init(void) {
    register s32 unused;
    register u32 j;
    register s32 i;
    s8* p;
    for (i = 0; i < 4; i++) {
        p = (s8*)coin_chute_tbl[i];
        for (j = 0; j < 8; j++) {
            *p++ = 0;
        }
        p = credit_ptr_tbl[i];
        *p = 0;
    }
}

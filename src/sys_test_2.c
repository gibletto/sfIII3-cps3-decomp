/*
 * SYS_TEST_2.C  Test mode: input/output, sound and colour test pages
 *
 * iotest_draw_sw_grid, iotest_input_page, iotest_output_toggle and iotest_output_page are the switch
 * and output test pages; soundtest_* the sound test (title, code select, monitor task, pan, balance
 * and level bars); colortest_* the palette grid test.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "eeprom.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "sys_test_2.h"
#include "cps3.h"



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
        Monitor_Flip = iotest_save_flip;
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
            tilemap_put_char(x + i, y, 2, 17);
        } else {
            tilemap_put_char(x + i, y, 2, 45);
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

/*
 * COM_PL.C  Test-mode main task, screen setup and computer player control
 *
 * System part: region_setup splits the BIOS region byte into country and version; display_mode_setup
 * and set_screen_mode choose normal or wide screen; screen_window_regs_update and zoom_regs_update
 * write the window and zoom registers in vblank; Zoomf_Init_X/Y, Frame_Up/Down and Frame_Adgjust
 * handle screen zoom. test_mode_task is the test-mode task: it enters test mode from the test
 * switch, draws the menu, runs the I/O, sound, colour, screen, backup RAM, configuration, memory
 * and CD pages, and restarts the game task on exit.
 * Computer player part: CPU_Sub is called by PLMAIN for each CPU player and returns its lever data.
 * Main_Program measures distance and area and runs the CPU state from Com_Jmp_Tbl (Com_Initialize,
 * Com_Free, Com_Active, Com_Follow, Com_Passive, Com_Guard, Com_VS_Shell, Com_Damage, Com_Float,
 * Com_Flip, Com_Caught, Com_Catch, Com_Wait_Lie), which run the per-character patterns.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Ck_Pass.h"
#include "Com_Sub.h"
#include "ACTIVE00.h"
#include "active01.h"
#include "active02.h"
#include "active03.h"
#include "active04.h"
#include "active05.h"
#include "active06.h"
#include "active07.h"
#include "active08.h"
#include "active09.h"
#include "active10.h"
#include "active11.h"
#include "active12.h"
#include "active13.h"
#include "active14.h"
#include "active16.h"
#include "active17.h"
#include "active18.h"
#include "active19.h"
#include "FOLLOW02.h"
#include "fifo.h"
#include "sys_test.h"
#include "textsound.h"
#include "pass00.h"
#include "PASS01.h"
#include "PASS02.h"
#include "PASS03.h"
#include "PASS04.h"
#include "PASS05.h"
#include "PASS06.h"
#include "PASS07.h"
#include "PASS08.h"
#include "PASS09.h"
#include "pass10.h"
#include "PASS11.h"
#include "PASS12.h"
#include "pass13.h"
#include "pass14.h"
#include "pass15.h"
#include "pass16.h"
#include "pass17.h"
#include "pass18.h"
#include "pass19.h"
#include "Passive20.h"
#include "SHELL00.h"
#include "SHELL01.h"
#include "SHELL03.h"
#include "SHELL04.h"
#include "SHELL05.h"
#include "SHELL07.h"
#include "SHELL11.h"
#include "SHELL12.h"
#include "SHELL13.h"
#include "SHELL14.h"
#include "Entry.h"
#include "CMD_MAIN.h"
#include "sys_config.h"
#include "PLS02.h"
#include "SE.h"
#include "EFFECT.h"
#include "aboutspr.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "Manage.h"
#include "bg0001.h"
#include "Com_Pl.h"
#include "cps3.h"
#include "fighter.h"

#pragma noregsave(boot_task)
#pragma noregsave(test_mode_task)

static s32 Check_Hamari(PLW* wk);



/* First task of the system.  Set up the task request queue and start
   mode_init_task in task slot 0, retrying until a slot is free.  From then on
   serve the queue: whenever task slot 6 is free and a request is waiting, start
   the requested routine there at priority 4; otherwise give up the frame. */
/* provisional name */
void boot_task(void) {
    TASK_REQ* req;

    task_sleep(3);
    fifo_init((u32*)&task_req_queue, (u32)task_req_buff, 200);
    while (create_task((void (*)())mode_init_task, 0, &task_tbl[0], 1, 0) == 0) {
    }
    do {
        if (task_tbl[6].status == 0) {
            req = (TASK_REQ*)fifo_get((FIFO32*)&task_req_queue);
            if (req != 0) {
                create_task(req->func, 2, &task_tbl[6], 4, req->arg);
                continue;
            }
        }
        task_wait();
    } while (1);
}



/* provisional name */
void kill_mode_tasks(void) {
    fifo_init(&task_req_queue, task_req_buff, 200);
    kill_tasks_by_priority(4, 2);
}



/* provisional name */
void text_clear_task_exit(void) {
    tilemap_fill_all(0, 32);
    destroy_current_task();
}



/* Start-up task, created by boot_task (and again by the test menu when it
   returns to the game).  Sets up the region, the video and sound work, the
   coin and switch work and the settings from EEPROM, clears the game state,
   starts test_mode_task, then shows the title with the region name and the
   region's warning screen (each can be cut short with a button), and finally
   starts the per-frame tasks and ends itself. */
/* provisional name */
void mode_init_task(void) {
    s16 wait;
    u8 region;
    s32 color;

    region_setup();
    CC_Type = region_cc_type_tbl[Country - 1];
    region_group_params_set();
    init_render_lists();
    init_color_trans_req();
    init_char_gfx_tables();
    clear_scroll_layer_state_and_mask();
    Scrn_Pos_Init();
    Family_Init();
    coin_work_init();
    palette_bank_set(0x3FC00);
    palette_write(0, sys_palette, 256);
    tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)sys_font_cg, 140);
    switch_work_clear(Cabinet_Type);
    dispenser_init();
    eeprom_config_load();
    task_sleep(60);
    Win_Point_Split = 1;
    tilemap_fill_all(0, 32);
    task_sleep(1);

    test_flag = 0;
    Cd_Error_Flag = 0;
    Break_Into = 0;
    Forbid_Break = 0;
    Extra_Break = 0;
    Fade_Half_Flag = 0;
    Demo_Flag = 0;
    Random_ix16_com = 0;
    Random_ix32_com = 0;
    unused_flag_a = 0;
    judge_disp_all = 0;
    unused_flag_b = 0;
    unused_flag_c = 0;
    test_sw_lock = 0;
    Keep_BGM_Flag = 0;
    No_Death = 0;
    Get_Demo_Index = Request_Break[0] = Request_Break[1] = 0;
    Battle_Round[0] = Game_setting.set4 & 3;
    Battle_Round[1] = (Game_setting.set4 / 16) & 3;
    G_No[0] = G_No[1] = G_No[2] = G_No[3] = 0;
    E_No[0] = E_No[1] = E_No[2] = E_No[3] = 0;
    S_No = S_Sub_No = S_Sub2_No = S_Sub3_No = 0;
    Fade_R_No0 = Fade_R_No1 = 0;
    Fade_Flag = 0;
    if (Free_Play) {
        credit_1p = 9;
        credit_2p = 9;
    }
    effect_work_init();
    task_sleep(1);
    while (create_task(test_mode_task, 0, &task_tbl[4], 2, 0) == 0) {
    }

    /* title and region name, in the region's colour */
    region = bios_region_code & 15;
    if (region >= 8) {
        region = 8;
    } else {
        region &= 7;
    }
    if (region >= 8) {
        color = 2;
    } else if ((color = region & 7) == 0) {
        color = 1;
    }
    cd_ready_flag = 0;
    no_cd_flag = bios_cd_flags & 1;
    display_mode_setup();
    tilemap_print_string((*&DE_X)[3], 0, color * 2, boot_title_str);
    tilemap_print_string((*&DE_X)[3], 0, color * 2, &boot_region_str[region]);
    if (no_cd_flag) {
        tilemap_print_string((*&DE_X)[3], 0, color * 2, boot_no_cd_str);
    }
    task_sleep(6);
    for (wait = 166; --wait > 0; ) {
        if ((p1sw_0 | p2sw_0) & 0x3F0) {
            wait = 0;
        }
        task_sleep(1);
    }

    /* warning screen for this country */
    tilemap_fill_all(0, 32);
    load_char_gfx(0x9000, 1);
    setup_kage_cells();
    tilemap_print_string((*&DE_X)[3], 0, 0xFFFF, warning_mes[Country - 1]);
    task_sleep(16);
    for (wait = 100; --wait > 0; ) {
        if ((p1sw_0 | p2sw_0) & 0x3F0) {
            wait = 0;
        }
        task_sleep(1);
    }

    tilemap_fill_all(0, 32);
    Setup_Com_Max_Range();
    load_any_color(2);
    ToneDown(0);
    Entry_Mes_X[0] = 2;
    Entry_Mes_X[1] = 27;
    Entry_Mes_Wide[0] = 16;
    Entry_Mes_Wide[1] = 3;
    dm17_to_nm23_flag = 0;
    Ranking_Init();
    while (create_task(game_frame_task, 0, &task_tbl[3], 3, 0) == 0) {
    }
    while (create_task(entry_task, 0, &task_tbl[2], 3, 0) == 0) {
    }
    destroy_current_task();
}



/* provisional name */
void region_setup(void) {
    Country = bios_region_code & 15;
    Version_Type = bios_region_code & 0xF0;
    Version_Type >>= 4;
    if (Version_Type >= 9) {
        Version_Type = 8;
    }
    Area_Type = region_type_tbl[Country];
}



/* provisional name */
void region_group_params_set(void) {
    CC_Value[0] = region_param_tbl[CC_Type][0];
    CC_Value[1] = region_param_tbl[CC_Type][1];
}



/* provisional name */
void display_mode_setup(void) {
    if ((*&Game_setting).mode) {
        set_screen_mode(7);
        screen_flip_offsets_set();
        DE_X[0] = 8;
        DE_X[1] = 16;
        DE_X[2] = 6;
        DE_X[3] = 7;
        DE_X[4] = 9;
        DE_X[5] = 112;
        DE_X[6] = 4;
        DE_X[7] = 11;
        DE_X[8] = 2;
        DE_X[9] = 12;
        DE_X[10] = 56;
        DE_X[11] = 0x100;
        DE_X[12] = 13;
        DE_X[13] = 1;
        DE_X[14] = 32;
        DE_X[15] = 16;
        DE_X[16] = 5;
        DE_X[17] = 3;
        DE_X[18] = 14;
        Max_vitality = 0xC0;
    } else {
        set_screen_mode(3);
        screen_flip_offsets_set();
        DE_X[0] = 0;
        DE_X[1] = 0;
        DE_X[2] = 0;
        DE_X[3] = 0;
        DE_X[4] = 0;
        DE_X[5] = 0;
        DE_X[6] = 0;
        DE_X[7] = 0;
        DE_X[8] = 0;
        DE_X[9] = 0;
        DE_X[10] = 0;
        DE_X[11] = 0xC0;
        DE_X[12] = 0;
        DE_X[13] = 0;
        DE_X[14] = 0;
        DE_X[15] = 0;
        DE_X[16] = 0;
        DE_X[17] = 0;
        DE_X[18] = 0;
        Max_vitality = 0xA0;
    }
}

/* provisional name */
void test_mode_task(void) {
    test_rno = test_cursor = 0;
    do {
        switch (test_rno) {
        case 0:
            test_mode_wait();
            break;
        case 1:
            test_menu_init();
            sprite_bank_flip();
            break;
        case 2:
            test_menu_run();
            sprite_bank_flip();
            break;
        case 3:
            test_mode_exit();
            break;
        }
        task_sleep(1);
    } while (1);
}

/* Wait for the test switch; on a press, stop the game and open the test menu. */
/* provisional name */
void test_mode_wait(void)
{
    if ((syssw_0 & 2) && test_sw_lock == 0) {
        test_flag = 1;
        coin_lock_set(-1);
        if (Game_setting.mode) {
            set_screen_mode(7);
        } else {
            set_screen_mode(3);
        }
        screen_flip_offsets_set();
        voice_all_off();
        bg_vbl_trans_flag = 0;
        Demo_Flag = 1;
        Scrn_Pos_Init();
        Family_Init();
        init_render_lists();
        palette_bank_set(0x3FC00);
        tilemap_fill_all(0, 32);
        config_menu_load_settings();
        kill_tasks_by_func((void (*)())mode_init_task);
        kill_tasks_by_priority(3, 1);
        test_rno += 1;
    }
}



/* provisional name */
void test_menu_init(void) {
    test_rno += 1;
    test_menu_no = 0;
    sound_driver_init();
    sound_reg_level_set(0, 0);
    Debug_Menu_No = 0;
    Debug_Select_No = 0;
    Debug_R_No = 0;
    bg_vbl_trans_flag = 0;
    tilemap_fill_all(0, 32);
    palette_write(0, (u16*)((u32)sys_palette), 256);
    if (Country == 1) {
        test_font_type = 1;
        tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)((u32)jp_menu_font_cg), 512);
        tilemap_fill_all(0, 0x1200);
        tilemap_print_script_seq(0, 0, 0xFFFF, (TMSCRIPT*)test_menu_scr_jp);
        test_cursor_on = 0x1204;
        test_cursor_off = 0x1200;
        if (config_differs_from_default()) {
            tilemap_rect_fill(21, 16, 4, 2, 8, 0xFFFF);
        }
    } else {
        test_font_type = 0;
        tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)((u32)sys_font_cg), 140);
        tilemap_fill_all(0, 32);
        tilemap_print_string(0, 0, 0xFFFF, (TM_STRING*)Country == 2 ? test_menu_str_asia : test_menu_str);
        test_cursor_on = 62;
        test_cursor_off = 32;
        if (config_differs_from_default()) {
            tilemap_rect_fill(19, 15, 14, 1, 8, 0xFFFF);
        }
    }
    tilemap_put_block(test_cursor_x_tbl[test_font_type], test_cursor_y_tbl[(s8)test_font_type][test_cursor], 2,
                             test_cursor_on);
    if (Country == 2) {
        test_cursor_max = 8;
    } else {
        test_cursor_max = 9;
    }
    task_sleep(1);
}



/* provisional name */
void test_menu_run(void) {
    s16 done = 0;
    switch (test_menu_no) {
    case 0:
        test_menu_select();
        break;
    case 1:
        done = iotest_input_page();
        break;
    case 2:
        done = iotest_output_page();
        break;
    case 3:
        done = soundtest_page();
        break;
    case 4:
        done = colortest_page();
        break;
    case 5:
        done = screentest_page();
        break;
    case 6:
        done = gamedata_page();
        break;
    case 7:
        done = config_menu_page();
        break;
    case 8:
        done = memtest_page();
        break;
    case 9:
        if (no_cd_flag) {
            test_rno += 1;
            break;
        }
        done = rewrite_page();
        break;
    case 10:
        test_rno += 1;
        break;
    }
    if (done) {
        test_rno = 1;
    }
}



/* provisional name */
void test_menu_select(void) {
    u16 sw = ~p1sw_1 & p1sw_0;
    if (sw & 1) {
        tilemap_put_block(test_cursor_x_tbl[test_font_type], test_cursor_y_tbl[(s8)test_font_type][test_cursor], 2,
                                 test_cursor_off);
        if (--test_cursor < 0) {
            test_cursor = test_cursor_max;
        }
        tilemap_put_block(test_cursor_x_tbl[test_font_type], test_cursor_y_tbl[(s8)test_font_type][test_cursor], 2,
                                 test_cursor_on);
    } else if (sw & 2) {
        tilemap_put_block(test_cursor_x_tbl[test_font_type], test_cursor_y_tbl[(s8)test_font_type][test_cursor], 2,
                                 test_cursor_off);
        if (++test_cursor > test_cursor_max) {
            test_cursor = 0;
        }
        tilemap_put_block(test_cursor_x_tbl[test_font_type], test_cursor_y_tbl[(s8)test_font_type][test_cursor], 2,
                                 test_cursor_on);
    } else if (sw & 16) {
        test_menu_no = test_cursor + 1;
        tilemap_chunk_copy_16b((s16*)(SS_RAM + 0x8000), (char*)((u32)sys_font_cg), 140);
        tilemap_fill_all(0, 32);
    }
}

/* provisional name */
void test_mode_exit(void)
{
    tilemap_fill_all(0, 32);
    test_cursor = 0;
    test_menu_no = 0;
    test_rno = 0;
    coin_lock_set(-1);
    Cd_Error_Flag = 1;
    switch_read(1);
    if (Game_setting.mode == 0) {
        set_screen_mode(3);
    } else {
        set_screen_mode(7);
    }
    screen_flip_offsets_set();
    Scrn_Pos_Init();
    Family_Init();
    coin_work_init();
    init_render_lists();
    palette_bank_set(0x3FC00);
    while (create_task((void (*)())mode_init_task, 0, &task_tbl[0], 0, 0) == 0) {
    }
    destroy_current_task();
}



/* provisional name */
void screen_flip_offsets_set(void) {
    const s16* p;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        p = screen_flip_ofs_tbl[screen_mode];
        flip_obj_ofs_x = p[0];
        flip_obj_ofs_y = p[1];
        flip_crt_ofs_x = p[2];
        flip_crt_ofs_y = p[3];
        flip_scr_ofs_x = p[4];
        flip_scr_ofs_y = p[5];
        flip_zoom_ofs_x = p[6];
        flip_zoom_ofs_y = p[7];
    } else {
        flip_obj_ofs_x = 0;
        flip_obj_ofs_y = 0;
        flip_crt_ofs_x = 0;
        flip_crt_ofs_y = 0;
        flip_scr_ofs_x = 0;
        flip_scr_ofs_y = 0;
        flip_zoom_ofs_x = 0;
        flip_zoom_ofs_y = 0;
    }
}



/* provisional name */
void set_screen_mode(mode)
s32 mode;
{
    const s16* row;
    window_req_flag = 1;
    screen_mode = mode;
    screen_base_x = screen_origin_tbl[mode][0];
    screen_base_y = screen_origin_tbl[mode][1];
    if (screen_mode == 7 && Monitor_Flip) {
        screen_window[0][0] = screen_window_flip_tbl[0];
        screen_window[0][1] = screen_window_flip_tbl[1];
        screen_window[0][2] = screen_window_flip_tbl[2];
        screen_window[0][3] = screen_window_flip_tbl[3];
        screen_window[1][0] = screen_window_flip_tbl[4];
        screen_window[1][1] = screen_window_flip_tbl[5];
        screen_window[1][2] = screen_window_flip_tbl[6];
        screen_window[1][3] = screen_window_flip_tbl[7];
        screen_disp_ctrl = screen_window_flip_tbl[8];
    } else {
        row = (const s16*)((const u8*)screen_window_tbl + (u8)(mode * sizeof(screen_window_tbl[0])));
        screen_window[0][0] = row[0];
        screen_window[0][1] = row[1];
        screen_window[0][2] = row[2];
        screen_window[0][3] = row[3];
        screen_window[1][0] = row[4];
        screen_window[1][1] = row[5];
        screen_window[1][2] = row[6];
        screen_window[1][3] = row[7];
        screen_disp_ctrl = row[8];
    }
}



/* provisional name */
void screen_window_regs_update(void) {
    s16* win;
    s16* win1;
    u16 ctrl;
    u16 t;
    if (Monitor_Flip != Monitor_Flip_Old) {
        Monitor_Flip_Old = Monitor_Flip;
        screen_flip_offsets_set();
    } else {
        if (window_req_flag == 0) {
            return;
        }
        window_req_flag = 0;
    }
    win = screen_window[0];
    *(u16*)(VIDEO_REG + 0x60) = win[0];
    *(u16*)(VIDEO_REG + 0x62) = win[1];
    *(u16*)(VIDEO_REG + 0x64) = win[2];
    *(u16*)(VIDEO_REG + 0x66) = win[3];
    win1 = win + 4;
    *(u16*)(VIDEO_REG + 0x70) = win1[0];
    *(u16*)(VIDEO_REG + 0x72) = win1[1];
    *(u16*)(VIDEO_REG + 0x74) = win1[2];
    *(u16*)(VIDEO_REG + 0x76) = win1[3];
    ctrl = screen_disp_ctrl;
    if (Monitor_Flip) {
        ctrl |= 24;
    }
    *(u16*)(VIDEO_REG + 0x80) = ctrl;
    win = screen_window[0];
    *(u16*)SS_REG = win[0];
    *(u16*)(SS_REG + 0x2) = screen_disp_reg_tbl[screen_mode][0];
    *(u16*)(SS_REG + 0x4) = screen_disp_reg_tbl[screen_mode][1];
    *(u16*)(SS_REG + 0x6) = screen_disp_reg_tbl[screen_mode][2];
    *(u16*)(SS_REG + 0x8) = screen_disp_reg_tbl[screen_mode][3];
    win1 = win + 4;
    t = win[3];
    *(u16*)(SS_REG + 0xA) = t;
    *(u16*)(SS_REG + 0xC) = t >> 8;
    *(u16*)(SS_REG + 0x12) = win1[0];
    t = win1[1];
    *(u16*)(SS_REG + 0x14) = t;
    *(u16*)(SS_REG + 0x16) = t >> 8;
    t = win1[2] + 2;
    *(u16*)(SS_REG + 0x18) = t;
    *(u16*)(SS_REG + 0x1A) = t >> 8;
    t = win1[3];
    *(u16*)(SS_REG + 0x1C) = t;
    *(u16*)(SS_REG + 0x1E) = t >> 8;
    *(u16*)(SS_REG + 0x26) = screen_disp_ctrl & 7;
    *(u16*)(SS_REG + 0x28) = Monitor_Flip ? 3 : 0;
}



/* provisional name */
void Zoomf_Init(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 1023;
    zoom_frame[0].zoom = 64;
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 1023;
    zoom_frame[1].zoom = 64;
    zoom_adj_x = 0;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_X(void) {
    zoom_frame[0].pos = 0;
    zoom_frame[0].size = 0;
    zoom_frame[0].mask = 0x3FF;
    zoom_frame[0].zoom = 64;
    zoom_adj_x = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* provisional name */
void Zoomf_Init_Y(void) {
    zoom_frame[1].pos = 0;
    zoom_frame[1].size = 0;
    zoom_frame[1].mask = 0x3FF;
    zoom_frame[1].zoom = 64;
    zoom_adj_y = 0;
    zoom_req_flag = 1;
    if (Monitor_Flip) {
        screen_flip_offsets_set();
    }
}



/* Zooms the frame in; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Up(u16 x, u16 y, s16 add_x, s16 add_y) {
    s32 adj;
    zoom_frame[0].zoom -= add_x;
    zoom_frame[1].zoom -= add_y;
    adj = Frame_Adgjust(x, y);
    zoom_req_flag = 1;
    return adj;
}



/* Zooms the frame out; returns the vertical offset computed by Frame_Adgjust. */
s32 Frame_Down(u16 x, u16 y, s16 add_x, s16 add_y) {
    s32 adj;
    zoom_frame[0].zoom += add_x;
    zoom_frame[1].zoom += add_y;
    adj = Frame_Adgjust(x, y);
    zoom_req_flag = 1;
    return adj;
}



/* Recomputes the zoom frame offsets; returns the vertical offset as first computed (before -32 is nudged to -31). */
s32 Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;
    s32 adj;
    if (Monitor_Flip) {
        pos_y = 0xD0 - pos_y;
        if (screen_mode != 7) {
            flip_zoom_ofs_x = 0x80;
        }
    }
    if (zoom_frame[0].zoom >= 0x40) {
        buff = zoom_frame[0].zoom;
        buff -= 0x40;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        zoom_adj_x = -buff;
        if (Monitor_Flip && screen_mode != 7) {
            flip_zoom_ofs_x = 0x80 - buff * 2;
        }
    } else {
        buff = 0x40;
        buff -= zoom_frame[0].zoom;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        if (Monitor_Flip) {
            zoom_adj_x = -buff;
        } else {
            zoom_adj_x = buff;
        }
    }
    if (zoom_frame[1].zoom >= 0x40) {
        buff = zoom_frame[1].zoom;
        buff -= 0x40;
        buff *= pos_y + 0x21;
        buff >>= 6;
        buff &= 0x1FF;
        if (!Monitor_Flip) {
            buff = -buff;
        }
        zoom_adj_y = buff;
        if ((adj = zoom_adj_y) == -0x20) {
            zoom_adj_y += 1;
        }
    } else {
        buff = 0x40;
        buff -= zoom_frame[1].zoom;
        buff *= pos_y + 0x21;
        buff >>= 6;
        buff &= 0x1FF;
        if (Monitor_Flip) {
            buff = -buff;
        }
        zoom_adj_y = buff;
        if ((adj = zoom_adj_y) == -0x20) {
            zoom_adj_y += 1;
        }
    }
    return adj;
}



/* provisional name */
void zoom_regs_update(void) {
    SCROLL_WINDOW* win;
    if (zoom_req_flag) {
        zoom_req_flag = 0;
        win = zoom_frame;
        *(s16*)(VIDEO_REG + 0x68) = (win->pos + flip_zoom_ofs_x) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x6A) = win->size;
        *(s16*)(VIDEO_REG + 0x6C) = win->mask;
        *(s16*)(VIDEO_REG + 0x6E) = win->zoom;
        win++;
        *(s16*)(VIDEO_REG + 0x78) = (win->pos + flip_zoom_ofs_y) & 0x3FF;
        *(s16*)(VIDEO_REG + 0x7A) = win->size;
        *(s16*)(VIDEO_REG + 0x7C) = win->mask;
        *(s16*)(VIDEO_REG + 0x7E) = win->zoom;
    }
}



s32 CPU_Sub(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    u16 index;
    if (Allow_a_battle_f == 0 || pcon_dp_flag == 1) {
        return 0;
    }
    Lever_Buff[wk->wu.id] = 0;
    if (em->pat_status == 0x26) {
        Lie_Flag[wk->wu.id] = 1;
    } else {
        Lie_Flag[wk->wu.id] = 0;
    }
    index = Pattern_Index[wk->wu.id];
    Last_Pattern_Index[wk->wu.id] = index;
    Main_Program(wk);
    Check_Store_Lv(wk);
    Shift_Resume_Lv(wk);
    return Lever_Buff[wk->wu.id];
}



void Main_Program(PLW* wk) {
    void (*Com_Jmp_Tbl[16])(PLW*) = { Com_Initialize, Com_Free, Com_Active, Com_Before_Follow, Com_Follow, Com_Before_Passive, Com_Passive, Com_Guard, Com_VS_Shell, Check_No12_Shell_Guard, Com_Damage, Com_Float, Com_Flip, Com_Caught, Com_Wait_Lie, Com_Catch };
    Ck_Distance(wk);
    Area_Number[wk->wu.id] = Ck_Area(wk);
    Attack_Flag[wk->wu.id] = plw[wk->wu.id ^ 1].caution_flag;
    Check_At_Count(wk);
    Disposal_Again[wk->wu.id] = 0;
    Com_Jmp_Tbl[CP_No[wk->wu.id][0]](wk);
    if (Disposal_Again[wk->wu.id]) {
        Com_Jmp_Tbl[CP_No[wk->wu.id][0]](wk);
    }
}



void Com_Initialize(PLW* wk) {
    const s16* xx;
    s16 i;
    CP_No[wk->wu.id][0] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Lever_Squat[wk->wu.id] = 0;
    Lever_Store[wk->wu.id][0] = 0;
    Lever_Store[wk->wu.id][1] = 0;
    Lever_Store[wk->wu.id][2] = 0;
    Attack_Counter[wk->wu.id] = 0;
    Bullet_No[wk->wu.id] = 0;
    Last_Attack_Counter[wk->wu.id] = -1;
    Guard_Counter[wk->wu.id] = -1;
    Turn_Over_Timer[wk->wu.id] = 1;
    Attack_Count_Index[wk->wu.id] = 0;
    Flip_Counter[wk->wu.id] = 0;
    xx = Area_Unit_Data[wk->player_number];
    Separate_Area[wk->wu.id][0] = xx[0];
    Separate_Area[wk->wu.id][1] = xx[1];
    Separate_Area[wk->wu.id][2] = xx[2];
    xx = Shell_Area_Unit_Data[wk->player_number];
    Shell_Separate_Area[wk->wu.id][0] = xx[0];
    Shell_Separate_Area[wk->wu.id][1] = xx[1];
    Shell_Separate_Area[wk->wu.id][2] = xx[2];
    Com_Width_Data[wk->wu.id] = PL_Body_Width_Data[wk->player_number];
    Clear_Com_Flag(wk);
    Standing_Master_Timer[wk->wu.id] = Setup_Next_Stand_Timer(wk);
    Squat_Master_Timer[wk->wu.id] = Setup_Next_Squat_Timer(wk);
    Setup_Bullet_Counter(wk);
    for (i = 0; i < 20; i++) {
        Resume_Lever[wk->wu.id][i] = 0;
    }
    for (i = 0; i < 3; i++) {
        Attack_Count_Buff[wk->wu.id][i] = -1;
    }
}



void Com_Free(PLW* wk) {
    s16 xx;
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    CP_No[wk->wu.id][0] = 2;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    if (Before_Look[wk->wu.id]) {
        xx = Standing_Timer[wk->wu.id];
    } else {
        xx = 0;
    }
    Clear_Com_Flag(wk);
    Standing_Timer[wk->wu.id] = xx;
    for (xx = 0; xx <= 7; xx++) {
        CP_Index[wk->wu.id][xx] = 0;
    }
    Select_Active(wk);
}



void Com_Before_Follow(PLW* wk) {
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Guard(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }
    Decide_Follow_Menu(wk);
    CP_No[wk->wu.id][0] = 4;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    CP_Index[wk->wu.id][0] = 0;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
}



void Com_Before_Passive(PLW* wk) {
    Lever_Buff[wk->wu.id] = Lever_LR[wk->wu.id];
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    if (!Limited_Flag[wk->wu.id] && !Counter_Attack[wk->wu.id]) {
        if (Check_Guard(wk)) {
            return;
        }
    }
    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }
    CP_No[wk->wu.id][0] = 6;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    CP_Index[wk->wu.id][0] = 0;
    CP_Index[wk->wu.id][1] = 0;
    CP_Index[wk->wu.id][2] = 0;
    CP_Index[wk->wu.id][3] = 0;
}



void Com_Guard(PLW* wk) {
    WORK* em;
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    if (wk->wu.routine_no[1] == 1 && PL_Blow_Off_Data[wk->wu.routine_no[2]] == 2) {
        Next_Be_Float(wk);
        return;
    }
    em = (WORK*)wk->wu.target_adrs;
    if (Ck_Exit_Guard(wk, em)) {
        Check_Guard_Type(wk, em);
        return;
    }
    Passive_Flag[wk->wu.id] = 0;
    Passive_Mode = 4;
    if (Ck_Passive_Term(wk)) {
        Select_Passive(wk);
        Counter_Attack[wk->wu.id] |= 2;
        return;
    }
    if (!Check_Counter_Attack(wk)) {
        Next_Be_Free(wk);
        return;
    }
    if (Select_Passive(wk) == -1) {
        Next_Be_Free(wk);
    }
}



static s32 Check_Hamari(PLW* wk) {
    u8 tech;
    s16 Rnd;
    s16 limit;
    s16 xx;
    if (Area_Number[wk->wu.id] >= 2) {
        return 0;
    }
    tech = Attack_Count_Buff[wk->wu.id][0];
    Rnd = random_32_com() & 1;
    limit = Rnd + 3;
    if (((PLW*)wk->wu.target_adrs)->player_number == PL_DUDLEY && tech == 3) {
        limit--;
    } else if (tech != 0 && tech != 1) {
        return 0;
    }
    for (xx = 1; xx < limit; xx++) {
        if (tech != Attack_Count_Buff[wk->wu.id][xx]) {
            return 0;
        }
    }
    return VS_Tech[wk->wu.id] = 32;
}



s32 Check_Counter_Attack(PLW* wk) {
    s16 xx;
    WORK* em;
    if (Area_Number[wk->wu.id] >= 3) {
        return 0;
    }
    em = (WORK*)wk->wu.target_adrs;
    xx = Type_of_Attack[wk->wu.id] & 0xF8;
    if (xx == 8) {
        VS_Tech[wk->wu.id] = 28;
        return;
    }
    if (xx == 24) {
        VS_Tech[wk->wu.id] = 14;
        return;
    }
    if (xx == 32) {
        VS_Tech[wk->wu.id] = 14;
        return;
    }
    if (xx == 48) {
        VS_Tech[wk->wu.id] = 14;
        return;
    }
    return Check_Hamari(wk);
}



void Check_No12_Shell_Guard(PLW* wk) {
    WORK_Other* tmw;
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    tmw = (WORK_Other*)Shell_Address[wk->wu.id];
    Check_Guard_Type(wk, &tmw->wu);
    if (Timer_00[wk->wu.id] == 0) {
        if (wk->player_number != PL_NO12) {
            if (wk->wu.routine_no[1] != 1) {
                Exit_Damage_Sub(wk);
            }
        } else if (Check_No12_Shell_Passed(wk, tmw) != 0) {
            Exit_Damage_Sub(wk);
        }
        if (tmw->wu.routine_no[0] == 2) {
            Exit_Damage_Sub(wk);
        }
        if (tmw->wu.id != 13) {
            Exit_Damage_Sub(wk);
        }
        Timer_00[wk->wu.id] = 1;
        return;
    }
    Timer_00[wk->wu.id]--;
}



/* provisional name */
s32 Check_No12_Shell_Passed(PLW* wk, WORK_Other* tmw) {
    s16 pos_x;
    if (wk->wu.rl_flag) {
        pos_x = wk->wu.xyz[0].disp.pos - 48;
        if (tmw->wu.xyz[0].disp.pos < pos_x) {
            return 1;
        }
    } else {
        pos_x = wk->wu.xyz[0].disp.pos + 48;
        if (tmw->wu.xyz[0].disp.pos > pos_x) {
            return 1;
        }
    }
    return 0;
}



void Check_Guard_Type(PLW* wk, WORK* em) {
    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    switch (Guard_Type[wk->wu.id]) {
    case 0:
        if (em->pat_status >= 0xE && em->pat_status <= 0x1E) {
            break;
        }
        if (em->att.guard & 16 || !(em->att.guard & 8)) {
            break;
        }
        Lever_Buff[wk->wu.id] |= 2;
        break;
    case 1:
        break;
    case 2:
        Lever_Buff[wk->wu.id] |= 2;
        break;
    }
}



s32 Ck_Exit_Guard(PLW* wk, WORK* em) {
    s16 Lv;
    if (--Timer_00[wk->wu.id]) {
        return 1;
    }
    Timer_00[wk->wu.id] = 1;
    if (Ck_Exit_Guard_Sub(wk, em)) {
        if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
            return 1;
        }
        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        Lv = Setup_Lv10(0);
        if (Break_Into_CPU == 2) {
            Lv = 10;
        }
        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 2;
        }
        Lv += CC_Value[0];
        if (EM_Rank != 0) {
            Guard_Type[wk->wu.id] = Guard_Data[18][Lv][random_16_com()];
        } else {
            Guard_Type[wk->wu.id] = Guard_Data[wk->player_number][Lv][random_16_com()];
        }
        return 1;
    }
    return 0;
}



s32 Ck_Exit_Guard_Sub(PLW* wk, WORK* em) {
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    if (wk->wu.routine_no[1] == 1) {
        if (wk->wu.routine_no[3] == 0) {
            return 1;
        }
        if (wk->wu.routine_no[2] >= 4 && wk->wu.routine_no[2] <= 7 && wk->wu.cmwk[0xE] == 0 &&
            Attack_Flag[wk->wu.id] == 0) {
            return 0;
        }
        return 1;
    }
    if (em->routine_no[1] != 4) {
        return 0;
    }
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }
    return 1;
}



void Com_Active(PLW* wk) {
    void (*Char_Jmp_Tbl[21])(PLW*) = { Computer00, Computer01, Computer02, Computer03, Computer04, Computer05, Computer06, Computer07, Computer08, Computer09, Computer10, Computer11, Computer12, Computer13, Computer14, Computer15, Computer16, Computer17, Computer18, Computer19, Computer20 };
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    Pattern_Insurance(wk, 0, 0);
    Char_Jmp_Tbl[wk->player_number](wk);
}



void Com_Follow(PLW* wk) {
    void (*Follow_Jmp_Tbl[21])(PLW*) = { Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02, Follow02 };
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    Pattern_Insurance(wk, 3, 2);
    Follow_Jmp_Tbl[wk->player_number](wk);
}



void Com_Passive(PLW* wk) {
    void (*Passive_Jmp_Tbl[21])(PLW*) = { Passive00, Passive01, Passive02, Passive03, Passive04, Passive05, Passive06, Passive07, Passive08, Passive09, Passive10, Passive11, Passive12, Passive13, Passive14, Passive15, Passive16, Passive17, Passive18, Passive19, Passive20 };
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    Pattern_Insurance(wk, 1, 1);
    Passive_Jmp_Tbl[wk->player_number](wk);
}



void Com_VS_Shell(PLW* wk) {
    void (*VS_Shell_Jmp_Tbl[21])(PLW*) = { Shell00, Shell01, Shell11, Shell03, Shell04, Shell05, Shell03, Shell07, Shell03, Shell03, Shell03, Shell11, Shell12, Shell13, Shell14, Shell14, Shell11, Shell11, Shell11, Shell11, Shell11 };
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    Pattern_Insurance(wk, 2, 0);
    VS_Shell_Jmp_Tbl[wk->player_number](wk);
}



void Com_Damage(PLW* wk) {
    void (*Damage_Jmp_Tbl[10])(PLW*) = { Damage_1st, Damage_2nd, Damage_3rd, Damage_4th, Damage_5th, Damage_6th, Damage_7th, Damage_7th, Damage_7th, Damage_8th };
    if (Check_Caught(wk)) {
        return;
    }
    Damage_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}



void Damage_1st(PLW* wk) {
    u8 Lv;
    u8 Rnd;
    u8 xx;
    WORK* em;
    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_Buff[wk->wu.id] |= 2;
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->py->flag) {
            CP_No[wk->wu.id][1] = 9;
            break;
        }
        if (PL_Blow_Off_Data[wk->wu.routine_no[2]] == 0) {
            CP_No[wk->wu.id][1] = 1;
            break;
        }
        CP_No[wk->wu.id][2]++;
        Lv = Setup_Lv08(0);
        if (Break_Into_CPU == 2) {
            Lv = 8;
        }
        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }
        Rnd = random_32_com();
        xx = Setup_EM_Rank_Index(wk);
        if (Receive_Data[xx][Lv] > Rnd) {
            Receive_Flag[wk->wu.id] = 1;
            break;
        }
        break;
    case 1:
        if (wk->wu.routine_no[3] == 0) {
            CP_No[wk->wu.id][2] = 0;
            break;
        }
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 3;
        }
        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }
        Rnd = random_32_com();
        CP_No[wk->wu.id][1] = Get_Up_Data[wk->player_number][Lv][Rnd] + 1;
        CP_No[wk->wu.id][2] = 0;
        if (Get_Up_Area_Data[wk->player_number][CP_No[wk->wu.id][1] - 1][Area_Number[wk->wu.id]] == 1) {
            CP_No[wk->wu.id][1] = *(((u8*)Get_Up_Area_Data[wk->player_number][CP_No[wk->wu.id][1]]) + 5);
        }
        if (CP_No[wk->wu.id][1] != 0) {
            break;
        }
        Lv = Setup_Lv10(0);
        if (Break_Into_CPU == 2) {
            Lv = 10;
        }
        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 0;
        }
        Rnd = random_16_com();
        Lv += CC_Value[0];
        em = (WORK*)wk->wu.target_adrs;
        if (EM_Rank != 0) {
            Guard_Type[wk->wu.id] = Guard_Data[18][Lv][Rnd];
        } else {
            Guard_Type[wk->wu.id] = Guard_Data[wk->player_number][Lv][Rnd];
        }
        Check_Guard_Type(wk, em);
        break;
    }
}



void Damage_2nd(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    Check_Guard_Type(wk, em);
    if (wk->wu.routine_no[2] == 0x19) {
        CP_No[wk->wu.id][1] = 9;
        CP_No[wk->wu.id][2] = 0;
        return;
    }
    if (Receive_Flag[wk->wu.id] != 0 && plw[wk->wu.id].uot_cd_ok_flag != 0) {
        Lever_Buff[wk->wu.id] = 2;
    }
    if (wk->wu.routine_no[1] != 1) {
        Exit_Damage_Sub(wk);
    }
}



void Damage_3rd(PLW* _p0) {}



void Damage_4th(PLW* _p0) {}



void Damage_5th(PLW* wk) {
    if (wk->wu.routine_no[3] == 0) {
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        return;
    }
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }
        if (wk->wu.cg_type == 9) {
            CP_No[wk->wu.id][2]++;
            CP_Index[wk->wu.id][1] = 0;
        }
        break;
    case 1:
        if (Command_Attack_SP(wk, wk->player_number, 46, 8)) {
            CP_No[wk->wu.id][2]++;
        }
        break;
    default:
        if (wk->wu.routine_no[1] != 4 || wk->wu.cg_type == 64) {
            Exit_Damage_Sub(wk);
        }
        break;
    }
}



void Damage_6th(PLW* wk) {
    u8 Lv;
    u8 Rnd;
    if (wk->wu.routine_no[3] == 0) {
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        return;
    }
    if (wk->wu.routine_no[2] == 0x19) {
        CP_No[wk->wu.id][1] = 9;
        CP_No[wk->wu.id][2] = 0;
        return;
    }
    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
    Lever_Buff[wk->wu.id] |= 2;
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }
        if (wk->wu.cg_type == 12) {
            if (Get_Up_Area_Data[wk->player_number][CP_No[wk->wu.id][1] - 1][Area_Number[wk->wu.id]] == 0x1) {
                CP_No[wk->wu.id][1] = *(((u8*)Get_Up_Area_Data[wk->player_number][CP_No[wk->wu.id][1]]) + 5);
            }
            CP_No[wk->wu.id][2]++;
            CP_Index[wk->wu.id][1] = 0;
            Lv = Setup_Lv04(0);
            if (Break_Into_CPU == 2) {
                Lv = 3;
            }
            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }
            Rnd = random_32_com() & 3;
            Rnd *= 2;
            CP_Index[wk->wu.id][0] = Get_Up_Action_Tech_Data[wk->player_number][Lv][Rnd];
            CP_Index[wk->wu.id][7] = Get_Up_Action_Tech_Data[wk->player_number][Lv][Rnd + 1];
            if (CP_Index[wk->wu.id][0] == 0xFF) {
                CP_Index[wk->wu.id][0] = Get_Up_Action_Tech_Data[wk->player_number][Lv][0];
                CP_Index[wk->wu.id][7] = 8;
                if (plw[wk->wu.id].sa->ok &&
                    Get_Up_SA_Tech_Data[wk->player_number][plw[wk->wu.id].sa->kind_of_arts] != -1) {
                    CP_Index[wk->wu.id][0] = Get_Up_SA_Tech_Data[wk->player_number][plw[wk->wu.id].sa->kind_of_arts];
                }
            }
        }
        break;
    case 1:
        if (Command_Attack_SP(wk, wk->player_number, CP_Index[wk->wu.id][0], CP_Index[wk->wu.id][7])) {
            CP_No[wk->wu.id][2]++;
        }
        break;
    default:
        if (Command_Attack_SP(wk, wk->player_number, CP_Index[wk->wu.id][0], CP_Index[wk->wu.id][7])) {
            Exit_Damage_Sub(wk);
        }
        break;
    }
}



void Damage_7th(PLW* wk) {
    WORK* em;
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[1] != 1) {
            Exit_Damage_Sub(wk);
            break;
        }
        CP_No[wk->wu.id][2]++;
        switch (CP_No[wk->wu.id][1]) {
        case 6:
            Guard_Type[wk->wu.id] = 0;
            break;
        case 7:
            Guard_Type[wk->wu.id] = 1;
            break;
        default:
            Guard_Type[wk->wu.id] = 2;
            break;
        }
        break;
    default:
        em = (WORK*)wk->wu.target_adrs;
        Check_Guard_Type(wk, em);
        if (wk->wu.cg_type != 0x40 && wk->wu.routine_no[1] != 0) {
            break;
        }
        if (Attack_Flag[wk->wu.id] != 0) {
            break;
        }
        if (Attack_Flag[wk->wu.id] == 0) {
            Exit_Damage_Sub(wk);
            break;
        }
        if (wk->tsukamarenai_flag == 0) {
            Exit_Damage_Sub(wk);
        }
        break;
    }
}



void Damage_8th(PLW* wk) {
    s16 Rnd;
    s16 Lv;
    if (wk->wu.routine_no[1] != 1) {
        Exit_Damage_Sub(wk);
    }
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (wk->wu.routine_no[2] == 0x19) {
            CP_No[wk->wu.id][2] += 1;
            Timer_00[wk->wu.id] = 1;
            Lv = Setup_Lv08(0);
            if (Break_Into_CPU == 2) {
                Lv = 8;
            }
            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }
            Timer_01[wk->wu.id] = Faint_Rapid_Data[Lv][(Rnd = random_16_com() & 7)];
        }
        break;
    case 1:
        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0, &CP_No[wk->wu.id][3]);
        break;
    }
}



void Exit_Damage_Sub(PLW* wk) {
    Clear_Com_Flag(wk);
    if (Check_Passive(wk)) {
        return;
    }
    Next_Be_Free(wk);
}



s32 Check_Damage(PLW* wk) {
    if (Counter_Attack[wk->wu.id] & 2) {
        return 0;
    }
    if (wk->wu.routine_no[1] == 1 && CP_No[wk->wu.id][0] != 7 && CP_No[wk->wu.id][0] != 9 &&
        Guard_Flag[wk->wu.id] == 0) {
        CP_No[wk->wu.id][0] = 10;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Receive_Flag[wk->wu.id] = 0;
        Lever_Buff[wk->wu.id] = 2;
        Clear_Com_Flag(wk);
        return 1;
    }
    return 0;
}



void Com_Float(PLW* wk) {
    void (*Float_Jmp_Tbl[4])(PLW*) = { Damage_2nd, Float_2nd, Float_3rd, Float_4th };
    if (Check_Caught(wk)) {
        return;
    }
    if (Check_Flip(wk)) {
        return;
    }
    Float_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}



void Float_2nd(PLW* wk) {
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Lever_Buff[wk->wu.id] = 16;
        break;
    default:
        if (wk->wu.routine_no[1] == 0) {
            Next_Be_Free(wk);
            break;
        }
        Check_Damage(wk);
        break;
    }
}



void Float_3rd(PLW* wk) {
    if (wk->wu.routine_no[1] != 1) {
        Next_Be_Free(wk);
    }
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 4;
        Lever_Pool[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    default:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Timer_00[wk->wu.id] = 3;
        Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
        break;
    }
}



void Float_4th(PLW* wk) {
    if (wk->wu.routine_no[1] != 1) {
        Next_Be_Free(wk);
    }
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 4;
        Lever_Pool[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        {
            u16 lp = Lever_Pool[wk->wu.id];
            Lever_Buff[wk->wu.id] = lp;
        }
        break;
    default:
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Timer_00[wk->wu.id] = 3;
        {
            u16 lp = Lever_Pool[wk->wu.id];
            Lever_Buff[wk->wu.id] = lp;
        }
        break;
    }
}



void Com_Flip(PLW* wk) {
    void (*Flip_Jmp_Tbl[5])(PLW*) = { Flip_Zero, Flip_1st, Flip_2nd, Flip_3rd, Flip_4th };
    if (Check_Damage(wk)) {
        return;
    }
    if (Check_Caught(wk)) {
        return;
    }
    Flip_Jmp_Tbl[CP_No[wk->wu.id][1]](wk);
}



void Flip_Zero(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    switch (CP_No[wk->wu.id][2]) {
    case 0:
        if (em->routine_no[1] != 4) {
            Exit_Damage_Sub(wk);
            break;
        }
        if (!Check_Flip_GO(wk, 0)) {
            break;
        }
        CP_No[wk->wu.id][2]++;
        Timer_00[wk->wu.id] = 9;
        break;
    case 1:
        if (Check_Flip(wk)) {
            break;
        }
        if (--Timer_00[wk->wu.id] != 0) {
            break;
        }
        Exit_Damage_Sub(wk);
        break;
    }
}



s32 Check_Flip_GO(PLW* wk, s16 xx) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (em->att_hit_ok || xx) {
        if (em->pat_status == 0x21 || em->pat_status == 0x20) {
            Lever_Buff[wk->wu.id] = 2;
        } else {
            Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        }
        if (xx == 0 && Resume_Lever[wk->wu.id][0] == Lever_Buff[wk->wu.id]) {
            Next_Be_Guard(wk, em, 0);
            Flip_Counter[wk->wu.id] = 255;
            return 0;
        }
        Flip_Counter[wk->wu.id]++;
        return 1;
    }
    return 0;
}



void Flip_1st(PLW* wk) {
    if (wk->wu.xyz[1].disp.pos <= 0) {
        Exit_Damage_Sub(wk);
    }
}



void Flip_2nd(PLW* wk) {
    PLW* em;
    if (PL_Damage_Data[wk->wu.routine_no[2]] != 0) {
        return;
    }
    em = (PLW*)wk->wu.target_adrs;
    if (wk->player_number == PL_GOUKI2) {
        if (Check_Flip_GO(wk, 0)) {
            if (Check_Flip_Chance(wk)) {
                CP_No[wk->wu.id][1] = 0;
                CP_No[wk->wu.id][2] = 1;
                return;
            }
            if (Check_Flip_Attack(wk) != 0) {
                VS_Tech[wk->wu.id] = 31;
                Flip_Counter[wk->wu.id] = 255;
                if (Select_Passive(wk) == -1) {
                    Exit_Damage_Sub(wk);
                }
            } else {
                Exit_Damage_Sub(wk);
            }
            return;
        }
        if (em->wu.total_att_set > em->total_att_hit_ok && Attack_Flag[wk->wu.id]) {
            return;
        }
        if (Check_Flip_Attack(wk) != 0) {
            VS_Tech[wk->wu.id] = 13;
            if (Select_Passive(wk) == -1) {
                Exit_Damage_Sub(wk);
            }
        } else {
            Exit_Damage_Sub(wk);
        }
        return;
    }
    if (Check_Flip_Attack(wk) != 0) {
        if (Select_Passive(wk) == -1) {
            Exit_Damage_Sub(wk);
        }
    } else {
        Exit_Damage_Sub(wk);
    }
}



void Flip_3rd(PLW* wk) {
    s16 next_disposal;
    if (PL_Damage_Data[wk->wu.routine_no[2]] == 0) {
        return;
    }
    next_disposal = Check_Shell_Flip(wk);
    switch (next_disposal) {
    case 0:
        CP_No[wk->wu.id][1] = 2;
        return;
    case 1:
        CP_No[wk->wu.id][1] = 4;
        Timer_00[wk->wu.id] = 12;
        return;
    default:
        CP_No[wk->wu.id][0] = 9;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Timer_00[wk->wu.id] = 10;
        Flip_Counter[wk->wu.id] = 255;
        dash_flag_clear(wk->wu.id);
        Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);
        break;
    }
}



void Flip_4th(PLW* wk) {
    if (--Timer_00[wk->wu.id] != 0) {
        return;
    }
    Check_Flip_GO(wk, 1);
    Flip_Counter[wk->wu.id]--;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 1;
    Timer_00[wk->wu.id] = 9;
}


s32 Check_Shell_Flip(PLW* wk) {
    WORK* shell;
    u16 Rnd;
    u16 Lv;
    Flip_Counter[wk->wu.id]++;
    if (Timer_01[wk->wu.id] != 8) {
        return 0;
    }
    shell = (WORK*)wk->wu.dmg_adrs;
    if (shell->vital_new < 256) {
        return 0;
    }
    if (Flip_Counter[wk->wu.id] < 3) {
        return 1;
    }
    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    Lv = Setup_Lv08(0);
    if (Rnd >= Shell_Flip_Data[wk->player_number][Lv]) {
        return -1;
    }
    return 1;
}



/* provisional name */
s32 Check_Flip_Chance(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    u16 Rnd;
    u16 Lv;
    if (em->kind_of_waza == 0 || em->kind_of_waza == 1) {
        return Lever_Buff[wk->wu.id] = 0;
    }
    if (Flip_Counter[wk->wu.id] < 3) {
        return 1;
    }
    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    Lv = Setup_Lv08(0);
    if (Rnd >= Flip_Chance_Data[wk->player_number][Lv]) {
        return 0;
    }
    return 1;
}



s32 Check_Flip(PLW* wk) {
    if (Flip_Flag[wk->wu.id]) {
        return 0;
    }
    if (wk->wu.routine_no[1] != 0) {
        return 0;
    }
    if (PL_Damage_Data[wk->wu.routine_no[2]] == 0) {
        return 0;
    }
    if (Flip_Counter[wk->wu.id] == 0xFF) {
        return 0;
    }
    CP_No[wk->wu.id][0] = 12;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 15;
    if (Timer_01[wk->wu.id] == 8) {
        CP_No[wk->wu.id][1] = 3;
    } else {
        CP_No[wk->wu.id][1] = 2;
    }
    if (wk->wu.xyz[1].disp.pos > 0) {
        CP_No[wk->wu.id][1] = 1;
    }
    return 1;
}

s32 Check_Flip_Attack(PLW* wk)
{
    s32 flip;
    s16 lv;
    s16 rnd;
    s16 term;
    s16 rank;

    lv = Setup_Lv08(0);
    if (Break_Into_CPU == 2) {
        lv = 8;
    }
    if (Demo_Flag == 0 && Weak_PL == (u16)wk->wu.id) {
        lv = 0;
    }
    rnd = random_32_com();
    term = Flip_Term_Correct(wk);
    rank = Setup_EM_Rank_Index(wk);
    /* Flip_Attack_Data[CC_Type][rank][lv] (s8, 21 ranks of 8 levels per type) */
    flip = (s16)(rnd - term) < Flip_Attack_Data[CC_Type][rank][lv];
    if (flip) {
        Flip_Flag[wk->wu.id] = 0;
        VS_Tech[wk->wu.id] = 13;
        Counter_Attack[wk->wu.id] = 1;
    }
    return flip;
}



void Com_Caught(PLW* wk) {
    s16 Rnd;
    s16 Lv;
    WORK* em = (WORK*)wk->wu.target_adrs;
    switch (CP_No[wk->wu.id][1]) {
    case 0:
        CP_No[wk->wu.id][1]++;
        CP_No[wk->wu.id][2] = 0;
        if (em->sp_tech_id == 1) {
            Timer_00[wk->wu.id] = 12;
            Lv = Setup_Lv08(0);
            if (Break_Into_CPU == 2) {
                Lv = 8;
            }
            if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
                Lv = 0;
            }
            Timer_01[wk->wu.id] = Caught_Timer_Data[Lv][(Rnd = random_16_com() & 7)];
            break;
        }
        Timer_00[wk->wu.id] = Decide_Exit_Catch(wk);
        Timer_01[wk->wu.id] = 1;
        break;
    case 1:
        if (wk->wu.routine_no[1] != 3) {
            if (wk->wu.routine_no[1] == 0) {
                Next_Be_Free(wk);
                break;
            }
            Check_Damage(wk);
            break;
        }
        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0x3F0, &CP_No[wk->wu.id][2]);
        break;
    }
}



s16 Decide_Exit_Catch(PLW* wk) {
    s16 Rnd;
    s16 xx;
    s16 Lv = Setup_Lv18(Game_setting.level);
    Lv += CC_Value[0];
    if (Break_Into_CPU == 2) {
        Lv = 19;
    }
    Rnd = (u8)random_32_com();
    xx = Setup_EM_Rank_Index(wk);
    if (Rnd >= Exit_Throw_Data[xx][Lv]) {
        return 0;
    }
    return 1;
}



s32 Com_Rapid_Sub(PLW* wk, s16 Shot, s16* dir_step) {
    u16 xx;
    if (--Timer_00[wk->wu.id] == 0) {
        Timer_00[wk->wu.id] = Timer_01[wk->wu.id];
        xx = Rapid_Lever_Data[dir_step[0]];
        xx |= Shot;
        dir_step[0]++;
        dir_step[0] &= 1;
        return xx;
    }
    return 0;
}



s32 Check_Caught(PLW* wk) {
    if (wk->wu.routine_no[1] == 3) {
        CP_No[wk->wu.id][0] = 13;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Clear_Com_Flag(wk);
        return 1;
    }
    return 0;
}



void Com_Catch(PLW* wk) {
    WORK* em;
    s16 Rnd;
    s16 Lv;
    switch (CP_No[wk->wu.id][1]) {
    case 0:
        CP_No[wk->wu.id][1]++;
        CP_No[wk->wu.id][2] = 0;
        Timer_00[wk->wu.id] = 1;
        Lv = Setup_Lv04(0);
        if (Break_Into_CPU == 2) {
            Lv = 0x4;
        }
        Timer_01[wk->wu.id] = Rapid_Hit_Data[Lv][(Rnd = random_16_com() & 7)];
        break;
    case 1:
        em = (WORK*)wk->wu.target_adrs;
        if (wk->wu.routine_no[1] != 2 || em->routine_no[1] != 3) {
            Next_Be_Free(wk);
            break;
        }
        Lever_Buff[wk->wu.id] = Com_Rapid_Sub(wk, 0x3F0, &CP_No[wk->wu.id][2]);
        break;
    }
}



void Be_Catch(PLW* wk) {
    CP_No[wk->wu.id][0] = 15;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
}



void Com_Wait_Lie(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    if (Check_Blow_Off(wk, em, 0)) {
        return;
    }
    Exit_Damage_Sub(wk);
}



s32 Command_Attack_SP(PLW* wk, s8 Pl_Number, s16 Tech_Number, s16 Power_Level) {
    switch (CP_Index[wk->wu.id][1]) {
    case 0:
        CP_Index[wk->wu.id][1]++;
        dash_flag_clear(wk->wu.id);
        Tech_Address[wk->wu.id] = player_cmd[Pl_Number][Tech_Number & 0xFFU];
        Tech_Index[wk->wu.id] = 0xC;
        Check_Rapid(wk, Tech_Number);
        Rapid_Index[wk->wu.id] = 0x90;
        Lever_Pool[wk->wu.id] = 0x90;
        break;
    case 1:
        switch (Tech_Address[wk->wu.id][Tech_Index[wk->wu.id]]) {
        default:
        case 1:
        case 10:
            if (Command_Type_00(wk, Power_Level & 0xF, Tech_Number, -1) == -1) {
                CP_Index[wk->wu.id][1] = 99;
            }
            break;
        case 2:
            if (Command_Type_01(wk, Power_Level & 0xF, -1)) {
                CP_Index[wk->wu.id][1]++;
            }
            break;
        }
        if (CP_Index[wk->wu.id][1] == 2) {
            return 1;
        }
        break;
    case 2:
        if (wk->wu.cg_type == 64) {
            Lever_Buff[wk->wu.id] = Lever_Pool[wk->wu.id];
            CP_Index[wk->wu.id][1]++;
        }
    default:
        Rapid_Sub(wk);
        if (wk->wu.routine_no[1] == 0 && plw[wk->wu.id].caution_flag == 0) {
            return 1;
        }
    }
    return 0;
}



void Next_Be_Free(wk)
PLW* wk;
{
    CP_No[wk->wu.id][0] = 1;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    {
        u16 lr = Lever_LR[wk->wu.id];
        Lever_Buff[wk->wu.id] = lr;
    }
}



void Next_Be_Float(PLW* wk) {
    s16 Rnd;
    s16 Lv;
    CP_No[wk->wu.id][0] = 11;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
    Lv = Setup_Lv04(0);
    Rnd = random_16_com();
    CP_No[wk->wu.id][1] = Be_Float_Data[Lv][Rnd];
}



void Clear_Com_Flag(PLW* wk) {
    Passive_Flag[wk->wu.id] = 0;
    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Guard_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    Shell_Ignore_Timer[wk->wu.id] = 0;
    Pierce_Menu[wk->wu.id] = 0;
    Continue_Menu[wk->wu.id] = 0;
    Standing_Timer[wk->wu.id] = 0;
    Before_Look[wk->wu.id] = 0;
    Attack_Count_No0[wk->wu.id] = 0;
    Turn_Over[wk->wu.id] = 0;
    Jump_Pass_Timer[wk->wu.id][0] = 0;
    Jump_Pass_Timer[wk->wu.id][1] = 0;
    Jump_Pass_Timer[wk->wu.id][2] = 0;
    Jump_Pass_Timer[wk->wu.id][3] = 0;
    Last_Eftype[wk->wu.id] = 0;
}



void Check_At_Count(PLW* wk) {
    WORK* em = (WORK*)wk->wu.target_adrs;
    s16 ix;
    if (Attack_Count_No0[wk->wu.id] == 0) {
        if (Attack_Flag[wk->wu.id]) {
            Attack_Counter[wk->wu.id]++;
            Attack_Count_No0[wk->wu.id] = 1;
            Type_of_Attack[wk->wu.id] = em->kind_of_waza;
            Attack_Count_Buff[wk->wu.id][Attack_Count_Index[wk->wu.id]] = em->kind_of_waza;
            Attack_Count_Index[wk->wu.id]++;
            Attack_Count_Index[wk->wu.id] &= 3;
        }
    } else if (Attack_Flag[wk->wu.id] == 0) {
        Attack_Count_No0[wk->wu.id] = 0;
    }
    if (Attack_Flag[wk->wu.id]) {
        Reset_Timer[wk->wu.id] = 120;
        return;
    }
    if (--Reset_Timer[wk->wu.id] == 0) {
        for (ix = 0; ix < 4; ix++) {
            Attack_Count_Buff[wk->wu.id][ix] = ix;
        }
    }
}



void Shift_Resume_Lv(PLW* wk) {
    s16 xx;
    for (xx = 18; xx >= 0; xx--) {
        Resume_Lever[wk->wu.id][xx + 1] = Resume_Lever[wk->wu.id][xx];
    }
    Resume_Lever[wk->wu.id][0] = Lever_Buff[wk->wu.id];
}



void Check_Store_Lv(PLW* wk) {
    s16 xx = Lever_Buff[wk->wu.id] & 0xF;
    switch (xx) {
    case 2:
        Lever_Store[wk->wu.id][0]++;
        break;
    case 6:
    case 10:
        Store_LR_Sub(wk);
        Lever_Store[wk->wu.id][0]++;
        break;
    case 4:
    case 8:
        Store_LR_Sub(wk);
        break;
    default:
        Lever_Store[wk->wu.id][0] = 0;
        Lever_Store[wk->wu.id][1] = 0;
        Lever_Store[wk->wu.id][2] = 0;
        break;
    }
}



void Store_LR_Sub(PLW* wk) {
    if (wk->wu.rl_waza) {
        if (Lever_Buff[wk->wu.id] & 8) {
            Lever_Store[wk->wu.id][1]++;
            Lever_Store[wk->wu.id][2] = 0;
        }
        if (Lever_Buff[wk->wu.id] & 4) {
            Lever_Store[wk->wu.id][1] = 0;
            Lever_Store[wk->wu.id][2]++;
        }
    } else {
        if (Lever_Buff[wk->wu.id] & 4) {
            Lever_Store[wk->wu.id][1]++;
            Lever_Store[wk->wu.id][2] = 0;
        }
        if (Lever_Buff[wk->wu.id] & 8) {
            Lever_Store[wk->wu.id][1] = 0;
            Lever_Store[wk->wu.id][2]++;
        }
    }
}



void Setup_Bullet_Counter(PLW* wk) {
    Bullet_Counter[wk->wu.id] = 3;
    Bullet_Counter[wk->wu.id] += random_32_com() & 1;
}



void Pattern_Insurance(PLW* wk, s16 Kind_Of_Insurance, s16 Forced_Number) {
    if (Pattern_Insurance_Data[wk->player_number][Kind_Of_Insurance] < (s16)Pattern_Index[wk->wu.id]) {
        Pattern_Index[wk->wu.id] = Forced_Number;
    }
}

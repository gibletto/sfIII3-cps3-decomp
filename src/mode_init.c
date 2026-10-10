/*
 * MODE_INIT.C  Mode initialisation and screen mode setup
 *
 * mode_init_task initialises the game for the selected mode; region_setup splits the BIOS
 * region byte into country and version, region_group_params_set picks the per-region
 * parameters, and display_mode_setup chooses normal or wide screen.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
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
#include "active15.h"
#include "active16.h"
#include "active17.h"
#include "active18.h"
#include "active19.h"
#include "active20.h"
#include "FOLLOW01.h"
#include "FOLLOW02.h"
#include "fifo.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "textsound_2.h"
#include "textsound_3.h"
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
#include "entry_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "PLS02.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "aboutspr.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "Manage.h"
#include "manage_2.h"
#include "bg0001.h"
#include "Com_Pl.h"
#include "cps3.h"
#include "fighter.h"
#include "RANKING.h"




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
    G_No0 = G_No1 = G_No2 = G_No3 = 0;
    E_No0 = E_No1 = E_No2 = E_No3 = 0;
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
    region = (region >= 8) ? 8 : region & 7;
    if (region >= 8) {
        color = 2;
    } else {
        color = (region & 7) ? (region & 7) : 1;
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
void region_cc_type_set(void) {
    CC_Type = region_cc_type_tbl[Country - 1];
}



/* provisional name */
void region_group_params_set(void) {
    CC_Value[0] = region_param_tbl[CC_Type][0];
    CC_Value[1] = region_param_tbl[CC_Type][1];
}



/* provisional name */
void display_mode_setup(void) {
    if (Game_setting.mode) {
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

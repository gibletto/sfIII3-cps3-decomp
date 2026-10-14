/*
 * SYS_CONFIG_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u32 chute_mode_str_tbl_0[];
extern const u32 chute_mode_str_tbl_1[];
extern const u32 chute_mode_str_tbl_10[];
extern const u32 chute_mode_str_tbl_11[];
extern const u32 chute_mode_str_tbl_2[];
extern const u32 chute_mode_str_tbl_3[];
extern const u32 chute_mode_str_tbl_4[];
extern const u32 chute_mode_str_tbl_5[];
extern const u32 chute_mode_str_tbl_6[];
extern const u32 chute_mode_str_tbl_7[];
extern const u32 chute_mode_str_tbl_8[];
extern const u32 chute_mode_str_tbl_9[];
extern const void* const coin_rate_tbl_tail[];
extern const u32 coin_setting_str_tbl_1[];
extern const u32 coin_setting_str_tbl_10[];
extern const u32 coin_setting_str_tbl_11[];
extern const u32 coin_setting_str_tbl_12[];
extern const u32 coin_setting_str_tbl_13[];
extern const u32 coin_setting_str_tbl_14[];
extern const u32 coin_setting_str_tbl_15[];
extern const u32 coin_setting_str_tbl_16[];
extern const u32 coin_setting_str_tbl_17[];
extern const u32 coin_setting_str_tbl_18[];
extern const u32 coin_setting_str_tbl_2[];
extern const u32 coin_setting_str_tbl_3[];
extern const u32 coin_setting_str_tbl_4[];
extern const u32 coin_setting_str_tbl_5[];
extern const u32 coin_setting_str_tbl_6[];
extern const u32 coin_setting_str_tbl_7[];
extern const u32 coin_setting_str_tbl_8[];
extern const u32 coin_setting_str_tbl_9[];
extern const u32 monitor_str_tbl_1[];
extern const u32 on_off_str_tbl_0[];
extern const u32 on_off_str_tbl_1[];
extern const u32 sound_mode_str_tbl_0[];
extern const u32 sound_mode_str_tbl_1[];
extern const u32 sound_mode_str_tbl_2[];
extern const u32 sound_mode_str_tbl_3[];
extern const u32 sound_mode_str_tbl_4[];
extern const u32 sound_mode_str_tbl_5[];

extern const char str_config_menu_title[];
extern const char str_config_1_system[];
extern const char str_sys_2_chute_mode[];
extern const char str_sys_3_continue[];
extern const char str_sys_4_monitor[];
extern const char str_sys_5_demo_sound[];
extern const char str_sys_6_sound_mode[];
extern const char str_sys_7_exit[];
extern const char str_sys_7_language[];
extern const char str_sys_8_exit[];
extern const char str_sys_7_c_dispenser[];
extern const char str_sys_8_win_point[];
extern const char str_config_2_game[];
extern const char str_sys_9_exit[];
extern const char str_sys_7_voice_type[];
extern const char str_sys_8_win_point_com[];
extern const char str_sys_9_win_point_human[];
extern const char str_sys_10_exit[];
extern const char str_guide_select_option[];
extern const char str_guide_modify_setting[];
extern const char str_guide_modify_shot1_shot2[];
extern const char str_guide_return_config_menu[];
extern const char str_guide_return_shot1[];
extern const char str_config_3_default[];
extern const char str_saving_configuration[];
extern const char str_saving_in_eeprom[];
extern const char str_config_4_save_exit[];
extern const char str_guide_select_up_down[];
extern const char str_guide_start_shot1[];
extern const char str_guide_reset_shot1_shot2[];
extern const char str_sysconfig_title[];
extern const char str_sys_1_coin[];
extern const char str_1coin_1credit[];
extern const char str_1coin_2credits[];
extern const char str_3coins_1credit[];
extern const char str_4coins_1credit[];
extern const char str_5coins_1credit[];
extern const char str_6coins_1credit[];
extern const char str_7coins_1credit[];
extern const char str_8coins_1credit[];
extern const char str_9coins_1credit[];
extern const char str_2coins_start_1coin_cont[];
extern const char str_coin_free_play[];
extern const char str_2pl_1chute_single[];
extern const char str_1coin_3credits[];
extern const char str_2pl_2chutes_single[];
extern const char str_2pl_2chutes_multi[];
extern const char str_3pl_1chute_single[];
extern const char str_3pl_2chutes_single[];
extern const char str_3pl_3chutes_single[];
extern const char str_3pl_3chutes_multi[];
extern const char str_4pl_1chute_single[];
extern const char str_4pl_2chutes_single[];
extern const char str_4pl_2chutes_multi[];
extern const char str_4pl_4chutes_single[];
extern const char str_1coin_4credits[];
extern const char str_4pl_4chutes_multi[];
extern const char str_cfg_on[];
extern const char str_cfg_off[];
extern const char str_cfg_external[];
extern const char str_cfg_jamma[];
extern const char str_cfg_english[];
extern const char str_cfg_spanish[];
extern const char str_cfg_portuguese[];
extern const char str_cfg_normal[];
extern const char str_cfg_flip[];
extern const char str_1coin_5credits[];
extern const char str_1coin_6credits[];
extern const char str_1coin_7credits[];
extern const char str_1coin_8credits[];
extern const char str_1coin_9credits[];
extern const char str_2coins_1credit[];

const TM_STRING config_top_menu_scr[5] = {
    { 4, 2, 2, (void*)str_config_menu_title },
    { 0x12, 6, 2, (void*)str_config_1_system },
    { 0x12, 8, 2, (void*)str_config_2_game },
    { 0x12, 0xA, 2, (void*)str_config_3_default },
    { 0x12, 0xC, 2, (void*)str_config_4_save_exit },
};

const TM_STRING config_top_guide_scr[2] = {
    { 0xd, 26, 2, (void*)str_guide_select_up_down },
    { 0xd, 27, 2, (void*)str_guide_start_shot1 },
};

const TM_STRING config_reset_guide_scr[2] = {
    { 0xd, 26, 2, (void*)str_guide_select_up_down },
    { 0xd, 27, 2, (void*)str_guide_reset_shot1_shot2 },
};

const TM_STRING sysconfig_scr[7] = {
    { 0x1, 2, 2, (void*)str_sysconfig_title },
    { 0x3, 5, 2, (void*)str_sys_1_coin },
    { 0x3, 7, 2, (void*)str_sys_2_chute_mode },
    { 0x3, 9, 2, (void*)str_sys_3_continue },
    { 0x3, 11, 2, (void*)str_sys_4_monitor },
    { 0x3, 13, 2, (void*)str_sys_5_demo_sound },
    { 0x3, 15, 2, (void*)str_sys_6_sound_mode },
};

const TM_STRING sysconfig_exit_scr[3] = {
    { 0x3, 17, 2, (void*)str_sys_7_exit },
    { 0x3, 17, 2, (void*)str_sys_7_language },
    { 0x3, 19, 2, (void*)str_sys_8_exit },
};

const TM_STRING sysconfig_dispenser_scr[5] = {
    { 0x3, 17, 2, (void*)str_sys_7_c_dispenser },
    { 0x3, 19, 2, (void*)str_sys_8_win_point },
    { 0x3, 21, 2, (void*)str_sys_9_exit },
    { 0x3, 17, 2, (void*)str_sys_7_voice_type },
    { 0x3, 19, 2, (void*)str_sys_8_exit },
};

const TM_STRING sysconfig_winpoint_scr[4] = {
    { 0x3, 17, 2, (void*)str_sys_7_c_dispenser },
    { 0x3, 19, 2, (void*)str_sys_8_win_point_com },
    { 0x3, 21, 2, (void*)str_sys_9_win_point_human },
    { 0x2, 23, 2, (void*)str_sys_10_exit },
};

const TM_STRING sysconfig_modify_guide[3] = {
    { 0x7, 25, 2, (void*)str_guide_select_option },
    { 0x7, 26, 2, (void*)str_guide_modify_setting },
    { 0x7, 27, 2, (void*)str_guide_modify_shot1_shot2 },
};

const TM_STRING sysconfig_return_guide[3] = {
    { 0x7, 25, 2, (void*)str_guide_select_option },
    { 0x7, 26, 2, (void*)str_guide_return_config_menu },
    { 0x7, 27, 2, (void*)str_guide_return_shot1 },
};

const TM_STRING config_saving_scr[2] = {
    { 5, 0xC, 0xE, (void*)str_saving_configuration },
    { 5, 0xE, 0xE, (void*)str_saving_in_eeprom },
};

/* provisional name */
const char str_config_menu_title[40] = "7. C O N F I G U R A T I O N   M E N U\n";

/* provisional name */
const char str_config_1_system[12] = "1. SYSTEM\n";

/* provisional name */
const char str_config_2_game[12] = "2. GAME\n";

/* provisional name */
const char str_config_3_default[12] = "3. DEFAULT\n";

/* provisional name */
const char str_config_4_save_exit[16] = "4. SAVE & EXIT";

/* provisional name */
const char str_guide_select_up_down[28] = "SELECT = 1P UP or DOWN   \n";

/* provisional name */
const char str_guide_start_shot1[28] = "START  = 1P SHOT1        ";

/* provisional name */
const char str_guide_reset_shot1_shot2[28] = "RESET  = 1P SHOT1 & SHOT2";

/* provisional name */
const char str_sysconfig_title[48] = "7-1. S Y S T E M   C O N F I G U R A T I O N\n";

/* provisional name */
const char str_sys_1_coin[12] = "1. COIN\n";

/* provisional name */
const char str_sys_2_chute_mode[16] = "2. CHUTE MODE\n";

/* provisional name */
const char str_sys_3_continue[16] = "3. CONTINUE\n";

/* provisional name */
const char str_sys_4_monitor[12] = "4. MONITOR\n";

/* provisional name */
const char str_sys_5_demo_sound[16] = "5. DEMO SOUND\n";

/* provisional name */
const char str_sys_6_sound_mode[16] = "6. SOUND MODE";

/* provisional name */
const char str_sys_7_exit[8] = "7. EXIT";

/* provisional name */
const char str_sys_7_language[16] = "7. LANGUAGE\n";

/* provisional name */
const char str_sys_8_exit[8] = "8. EXIT";

/* provisional name */
const char str_sys_7_c_dispenser[16] = "7. C.DISPENSER\n";

/* provisional name */
const char str_sys_8_win_point[16] = "8. WIN POINT\n";

/* provisional name */
const char str_sys_9_exit[8] = "9. EXIT";

/* provisional name */
const char str_sys_7_voice_type[16] = "7. VOICE TYPE\n";

/* provisional name */
const char str_sys_8_win_point_com[20] = "8. WIN POINT COM\n";

/* provisional name */
const char str_sys_9_win_point_human[20] = "9. WIN POINT HUMAN\n";

/* provisional name */
const char str_sys_10_exit[12] = "10. EXIT";

/* provisional name */
const char str_guide_select_option[36] = "SELECT OPTION  = 1P UP or DOWN    \n";

/* provisional name */
const char str_guide_modify_setting[36] = "MODIFY SETTING = 1P LEFT or RIGHT \n";

/* provisional name */
const char str_guide_modify_shot1_shot2[36] = "               = 1P SHOT1 or SHOT2";

/* provisional name */
const char str_guide_return_config_menu[36] = "RETURN TO CONFIGURATION MENU      \n";

/* provisional name */
const char str_guide_return_shot1[36] = "               = 1P SHOT1         ";

/* provisional name */
const char str_saving_configuration[36] = "NOW  SAVING  NEW  CONFIGURATION\n";

/* provisional name */
const char str_saving_in_eeprom[40] = "                         IN  EEPROM...";

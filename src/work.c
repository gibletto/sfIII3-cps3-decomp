/*
 * WORK.C  initialised work RAM
 *
 * The variables that start the game with a value: the boot code copies their image from ROM to work
 * RAM 02000000-02007EEB (D_ROM, D_BGN, D_END in sections.src). The linker's ROM (D,R) option keeps
 * the image in ROM (section D, after the game tables) and gives the variables their addresses in work
 * RAM (section R). The work RAM that starts cleared (from 02007EEC) is in work_b.c. A <name>_tail table
 * holds the initial values of the bytes between <name> and the next named variable: unnamed variables,
 * or more of <name> read through an index past its end.
 */

#include "types.h"
#include "structs.h"
extern s8 coin_chute3_w[];
extern s8 coin_chute4_w[];
extern const char memtest_simm_title_and_names[128];
extern const char str_ONBOARD[];
extern const char str_SIMM1[];
extern const char str_SIMM2[];
extern const char str_SIMM3[];
extern const char str_SIMM4[];
extern const char str_SIMM5[];
extern const char str_SIMM6[];
extern const char str_SIMM7[];
extern const u16 rca_char_table_023[318];
extern const char gcfg_help_shot1_en[132];
extern const char str_NORMAL_2[];
extern const char str_WIDE[];
extern const char str_1_ROUND[];
extern const char str_3_ROUNDS[];
extern const char str_5_ROUNDS[];
extern const char str_7_ROUNDS[];
extern const char str_OFF[];
extern const char str_1_MATCH[];
extern const char str_OFF_2[];
extern const char str_ON[];
extern const char sh_mn_mov_imm_rn[92];
extern const char str_R0[];
extern const char str_R1[];
extern const char str_R2[];
extern const char str_R3[];
extern const char str_R4[];
extern const char str_R5[];
extern const char str_R6[];
extern const char str_R7[];
extern const char str_R8[];
extern const char str_R9[];
extern const char str_R10[];
extern const char str_R11[];
extern const char str_R12[];
extern const char str_R13[];
extern const char str_R14[];
extern const char str_SP[];
extern const u16 ef13_char_table_225[180];

extern const s16 lvr_chk_tbl_0[];
extern const s16 lvr_chk_tbl_1[];
extern const s16 lvr_chk_tbl_2[];
extern const char player_cmd_0[];
extern const char player_cmd_1[];
extern const char player_cmd_11[];
extern const char player_cmd_2[];
extern const char player_cmd_3[];
extern const char player_cmd_4[];
extern const char player_cmd_5[];

extern void* kizetsu_timer_table_0[];
extern void* kizetsu_timer_table_1[];
extern void* kizetsu_timer_table_2[];
extern void* kizetsu_timer_table_3[];
extern void* kizetsu_timer_table_4[];
extern void* kizetsu_timer_table_5[];
extern u32 sys_cfg_sound_scr_jp_tail[];

extern const s16 scr_obj_data27_0[];
extern const s16 scr_obj_data27_1[];

extern const s16 scr_obj_data18_0[];

extern const u16 fade_adrs_tbl_0[];
extern const u16 fade_adrs_tbl_1[];
extern const u16 fade_adrs_tbl_10[];
extern const u16 fade_adrs_tbl_11[];
extern const u16 fade_adrs_tbl_12[];
extern const u16 fade_adrs_tbl_13[];
extern const u16 fade_adrs_tbl_14[];
extern const u16 fade_adrs_tbl_15[];
extern const u16 fade_adrs_tbl_16[];
extern const u16 fade_adrs_tbl_17[];
extern const u16 fade_adrs_tbl_18[];
extern const u16 fade_adrs_tbl_19[];
extern const u16 fade_adrs_tbl_2[];
extern const u16 fade_adrs_tbl_20[];
extern const u16 fade_adrs_tbl_21[];
extern const u16 fade_adrs_tbl_22[];
extern const u16 fade_adrs_tbl_23[];
extern const u16 fade_adrs_tbl_25[];
extern const u16 fade_adrs_tbl_26[];
extern const u16 fade_adrs_tbl_27[];
extern const u16 fade_adrs_tbl_28[];
extern const u16 fade_adrs_tbl_29[];
extern const u16 fade_adrs_tbl_3[];
extern const u16 fade_adrs_tbl_30[];
extern const u16 fade_adrs_tbl_31[];
extern const u16 fade_adrs_tbl_32[];
extern const u16 fade_adrs_tbl_33[];
extern const u16 fade_adrs_tbl_34[];
extern const u16 fade_adrs_tbl_35[];
extern const u16 fade_adrs_tbl_4[];
extern const u16 fade_adrs_tbl_5[];
extern const u16 fade_adrs_tbl_6[];
extern const u16 fade_adrs_tbl_7[];
extern const u16 fade_adrs_tbl_8[];
extern const u16 fade_adrs_tbl_9[];

extern const s16 effF9_mes_pt_0[];

extern const u8 cfg_top_guide_jp_0[];
extern const u8 cfg_top_reset_guide_jp_0[];
extern const u8 config_top_scr_jp_0[];
extern const void* const effA6_mes_en_0[];
extern const void* const effA6_mes_en_10[];
extern const void* const effA6_mes_en_11[];
extern const void* const effA6_mes_en_12[];
extern const void* const effA6_mes_en_13[];
extern const void* const effA6_mes_en_16[];
extern const void* const effA6_mes_en_17[];
extern const void* const effA6_mes_en_19[];
extern const void* const effA6_mes_en_2[];
extern const void* const effA6_mes_en_20[];
extern const void* const effA6_mes_en_3[];
extern const void* const effA6_mes_en_4[];
extern const void* const effA6_mes_en_5[];
extern const void* const effA6_mes_en_6[];
extern const void* const effA6_mes_en_7[];
extern const void* const effA6_mes_en_8[];
extern const void* const effA6_mes_en_9[];
extern const void* const effA6_mes_jp_0[];
extern const void* const effA6_mes_jp_10[];
extern const void* const effA6_mes_jp_11[];
extern const void* const effA6_mes_jp_12[];
extern const void* const effA6_mes_jp_13[];
extern const void* const effA6_mes_jp_16[];
extern const void* const effA6_mes_jp_17[];
extern const void* const effA6_mes_jp_19[];
extern const void* const effA6_mes_jp_2[];
extern const void* const effA6_mes_jp_20[];
extern const void* const effA6_mes_jp_3[];
extern const void* const effA6_mes_jp_4[];
extern const void* const effA6_mes_jp_5[];
extern const void* const effA6_mes_jp_6[];
extern const void* const effA6_mes_jp_7[];
extern const void* const effA6_mes_jp_8[];
extern const void* const effA6_mes_jp_9[];
extern const void* const effB8_mes_en_0[];
extern const void* const effB8_mes_en_1[];
extern const void* const effB8_mes_en_10[];
extern const void* const effB8_mes_en_11[];
extern const void* const effB8_mes_en_12[];
extern const void* const effB8_mes_en_13[];
extern const void* const effB8_mes_en_14[];
extern const void* const effB8_mes_en_16[];
extern const void* const effB8_mes_en_17[];
extern const void* const effB8_mes_en_18[];
extern const void* const effB8_mes_en_19[];
extern const void* const effB8_mes_en_2[];
extern const void* const effB8_mes_en_20[];
extern const void* const effB8_mes_en_3[];
extern const void* const effB8_mes_en_4[];
extern const void* const effB8_mes_en_5[];
extern const void* const effB8_mes_en_6[];
extern const void* const effB8_mes_en_7[];
extern const void* const effB8_mes_en_8[];
extern const void* const effB8_mes_en_9[];
extern const void* const effB8_mes_jp_0[];
extern const void* const effB8_mes_jp_1[];
extern const void* const effB8_mes_jp_10[];
extern const void* const effB8_mes_jp_11[];
extern const void* const effB8_mes_jp_12[];
extern const void* const effB8_mes_jp_13[];
extern const void* const effB8_mes_jp_14[];
extern const void* const effB8_mes_jp_16[];
extern const void* const effB8_mes_jp_17[];
extern const void* const effB8_mes_jp_18[];
extern const void* const effB8_mes_jp_19[];
extern const void* const effB8_mes_jp_2[];
extern const void* const effB8_mes_jp_20[];
extern const void* const effB8_mes_jp_3[];
extern const void* const effB8_mes_jp_4[];
extern const void* const effB8_mes_jp_5[];
extern const void* const effB8_mes_jp_6[];
extern const void* const effB8_mes_jp_7[];
extern const void* const effB8_mes_jp_8[];
extern const void* const effB8_mes_jp_9[];
extern const void* const effF9_mes_en_0[];
extern const void* const effF9_mes_en_10[];
extern const void* const effF9_mes_en_11[];
extern const void* const effF9_mes_en_12[];
extern const void* const effF9_mes_en_13[];
extern const void* const effF9_mes_en_14[];
extern const void* const effF9_mes_en_16[];
extern const void* const effF9_mes_en_17[];
extern const void* const effF9_mes_en_18[];
extern const void* const effF9_mes_en_19[];
extern const void* const effF9_mes_en_2[];
extern const void* const effF9_mes_en_20[];
extern const void* const effF9_mes_en_3[];
extern const void* const effF9_mes_en_4[];
extern const void* const effF9_mes_en_5[];
extern const void* const effF9_mes_en_6[];
extern const void* const effF9_mes_en_7[];
extern const void* const effF9_mes_en_8[];
extern const void* const effF9_mes_en_9[];
extern const void* const effF9_mes_jp_0[];
extern const void* const effF9_mes_jp_10[];
extern const void* const effF9_mes_jp_11[];
extern const void* const effF9_mes_jp_12[];
extern const void* const effF9_mes_jp_13[];
extern const void* const effF9_mes_jp_14[];
extern const void* const effF9_mes_jp_16[];
extern const void* const effF9_mes_jp_17[];
extern const void* const effF9_mes_jp_18[];
extern const void* const effF9_mes_jp_19[];
extern const void* const effF9_mes_jp_2[];
extern const void* const effF9_mes_jp_20[];
extern const void* const effF9_mes_jp_3[];
extern const void* const effF9_mes_jp_4[];
extern const void* const effF9_mes_jp_5[];
extern const void* const effF9_mes_jp_6[];
extern const void* const effF9_mes_jp_7[];
extern const void* const effF9_mes_jp_8[];
extern const void* const effF9_mes_jp_9[];
extern const u32 sys_cfg_exit_guide_jp_0[];
extern const u32 sys_cfg_item_guide_jp_0[];
extern const u8 sys_cfg_page_scr_jp_0[];
extern const u32 sys_cfg_page_scr_jp_1[];
extern const u32 sys_cfg_page_scr_jp_10[];
extern const u32 sys_cfg_page_scr_jp_11[];
extern const u32 sys_cfg_page_scr_jp_12[];
extern const u32 sys_cfg_page_scr_jp_13[];
extern const u32 sys_cfg_page_scr_jp_14[];
extern const u32 sys_cfg_page_scr_jp_15[];
extern const u32 sys_cfg_page_scr_jp_16[];
extern const u32 sys_cfg_page_scr_jp_17[];
extern const u32 sys_cfg_page_scr_jp_18[];
extern const u32 sys_cfg_page_scr_jp_19[];
extern const u32 sys_cfg_page_scr_jp_2[];
extern const u32 sys_cfg_page_scr_jp_20[];
extern const u8 sys_cfg_page_scr_jp_21[];
extern const u8 sys_cfg_page_scr_jp_22[];
extern const u8 sys_cfg_page_scr_jp_23[];
extern const u8 sys_cfg_page_scr_jp_24[];
extern const u8 sys_cfg_page_scr_jp_25[];
extern const u8 sys_cfg_page_scr_jp_26[];
extern const u8 sys_cfg_page_scr_jp_27[];
extern const u8 sys_cfg_page_scr_jp_28[];
extern const u8 sys_cfg_page_scr_jp_29[];
extern const u32 sys_cfg_page_scr_jp_3[];
extern const u8 sys_cfg_page_scr_jp_30[];
extern const u8 sys_cfg_page_scr_jp_31[];
extern const u8 sys_cfg_page_scr_jp_32[];
extern const u8 sys_cfg_page_scr_jp_33[];
extern const u8 sys_cfg_page_scr_jp_34[];
extern const u8 sys_cfg_page_scr_jp_35[];
extern const u8 sys_cfg_page_scr_jp_36[];
extern const u8 sys_cfg_page_scr_jp_37[];
extern const u8 sys_cfg_page_scr_jp_38[];
extern const u8 sys_cfg_page_scr_jp_39[];
extern const u32 sys_cfg_page_scr_jp_4[];
extern const u8 sys_cfg_page_scr_jp_40[];
extern const u32 sys_cfg_page_scr_jp_41[];
extern const u32 sys_cfg_page_scr_jp_42[];
extern const u8 sys_cfg_page_scr_jp_43[];
extern const u8 sys_cfg_page_scr_jp_44[];
extern const u8 sys_cfg_page_scr_jp_45[];
extern const u8 sys_cfg_page_scr_jp_46[];
extern const u8 sys_cfg_page_scr_jp_47[];
extern const u8 sys_cfg_page_scr_jp_48[];
extern const u8 sys_cfg_page_scr_jp_49[];
extern const u32 sys_cfg_page_scr_jp_5[];
extern const u8 sys_cfg_page_scr_jp_50[];
extern const u32 sys_cfg_page_scr_jp_51[];
extern const u32 sys_cfg_page_scr_jp_52[];
extern const u32 sys_cfg_page_scr_jp_53[];
extern const u32 sys_cfg_page_scr_jp_54[];
extern const u32 sys_cfg_page_scr_jp_55[];
extern const u32 sys_cfg_page_scr_jp_56[];
extern const u32 sys_cfg_page_scr_jp_57[];
extern const u32 sys_cfg_page_scr_jp_58[];
extern const u32 sys_cfg_page_scr_jp_59[];
extern const u32 sys_cfg_page_scr_jp_6[];
extern const u8 sys_cfg_page_scr_jp_60[];
extern const u8 sys_cfg_page_scr_jp_61[];
extern const u8 sys_cfg_page_scr_jp_62[];
extern const u8 sys_cfg_page_scr_jp_63[];
extern const u8 sys_cfg_page_scr_jp_64[];
extern const u8 sys_cfg_page_scr_jp_65[];
extern const u8 sys_cfg_page_scr_jp_66[];
extern const u8 sys_cfg_page_scr_jp_67[];
extern const u8 sys_cfg_page_scr_jp_68[];
extern const u8 sys_cfg_page_scr_jp_69[];
extern const u32 sys_cfg_page_scr_jp_7[];
extern const u8 sys_cfg_page_scr_jp_70[];
extern const u8 sys_cfg_page_scr_jp_71[];
extern const u8 sys_cfg_page_scr_jp_72[];
extern const u8 sys_cfg_page_scr_jp_73[];
extern const u8 sys_cfg_page_scr_jp_74[];
extern const u8 sys_cfg_page_scr_jp_75[];
extern const u8 sys_cfg_page_scr_jp_76[];
extern const u8 sys_cfg_page_scr_jp_77[];
extern const u8 sys_cfg_page_scr_jp_78[];
extern const u8 sys_cfg_page_scr_jp_79[];
extern const u32 sys_cfg_page_scr_jp_8[];
extern const u32 sys_cfg_page_scr_jp_80[];
extern const u32 sys_cfg_page_scr_jp_9[];
extern const u32 sys_cfg_sound_scr_jp_0[];
extern const u8 test_menu_scr_jp_0[];
extern const char test_menu_str_0[];
extern const char test_menu_str_1[];
extern const char test_menu_str_10[];
extern const char test_menu_str_11[];
extern const char test_menu_str_12[];
extern const char test_menu_str_2[];
extern const char test_menu_str_3[];
extern const char test_menu_str_4[];
extern const char test_menu_str_5[];
extern const char test_menu_str_6[];
extern const char test_menu_str_7[];
extern const char test_menu_str_8[];
extern const char test_menu_str_9[];
extern const char test_menu_str_asia_9[];

extern const s16 spgauge_postbl_0[];
extern const s16 spgauge_postbl_1[];
extern const s16 spgauge_puttbl_0[];
extern const s16 spgauge_puttbl_1[];

extern const s16 stngauge_postbl_0[];
extern const s16 stngauge_postbl_0_2[];
extern const s16 stngauge_postbl_1[];
extern const s16 stngauge_postbl_1_2[];
extern const s16 stngauge_puttbl_0[];
extern const s16 stngauge_puttbl_1[];

extern const u32 end_400_panel_tbl_0[];
extern const u32 end_400_panel_tbl_1[];

extern const u8 end_5_bg1_cell_0[];

extern const u32 pl00_cctbl_0[];
extern const u32 pl00_cctbl_1[];

extern const s16 scr_obj_data87_0[];

extern const u32 eff21_data_adrs_0[];

extern const s16 scr_obj_data25_0[];

extern u8 coin_count_ptr_tbl_0[];
extern u8 coin_count_ptr_tbl_1[];
extern u8 coin_count_ptr_tbl_2[];
extern u8 coin_count_ptr_tbl_3[];

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

extern const u32 Follow_Menu_1st_Unit_Data_0[];
extern const u32 Follow_Menu_1st_Unit_Data_2[];
extern const u32 Follow_Menu_2nd_Unit_Data_0[];
extern const u32 Follow_Menu_2nd_Unit_Data_2[];

extern const s16 effM4_dir_tbl_0[];
extern const s16 effM4_dir_tbl_1[];
extern const s16 effM4_dir_tbl_2[];
extern const s16 effM4_dir_tbl_3[];
extern const s16 effM4_dir_tbl_4[];
extern const s16 effM4_dir_tbl_5[];
extern const s16 effM4_dir_tbl_6[];
extern const s16 effM4_dir_tbl_7[];

extern const s16 flash_obj_data61_0[];
extern const s16 flash_obj_data61_1[];
extern const s16 flash_obj_data61_2[];

extern const u8 gcfg_bonus_scr_jp_0[];
extern const u8 gcfg_bonus_scr_jp_1[];
extern const u32 gcfg_cursor_clr_scr_jp_0[];
extern const u32 gcfg_cursor_scr_jp_0[];
extern const u8 gcfg_event_scr_jp_0[];
extern const u8 gcfg_event_scr_jp_1[];
extern const u32 gcfg_exit_guide_scr_jp_0[];
extern const u32 gcfg_gauge_clr_scr_jp_0[];
extern const u32 gcfg_gauge_scr_jp_0[];
extern const u32 gcfg_gauge_scr_jp_1[];
extern const u32 gcfg_gauge_scr_jp_2[];
extern const u32 gcfg_gauge_scr_jp_3[];
extern const u32 gcfg_gauge_scr_jp_4[];
extern const u32 gcfg_gauge_scr_jp_5[];
extern const u32 gcfg_gauge_scr_jp_6[];
extern const u32 gcfg_gauge_scr_jp_7[];
extern const u32 gcfg_guide_scr_jp_0[];
extern const u8 gcfg_round_scr_jp_0[];
extern const u8 gcfg_round_scr_jp_1[];
extern const u8 gcfg_round_scr_jp_2[];
extern const u8 gcfg_round_scr_jp_3[];
extern const u8 gcfg_screen_scr_jp_0[];
extern const u8 gcfg_screen_scr_jp_1[];
extern const u32 gcfg_title_scr_jp_0[];

extern const u8 game_cfg_default_tbl_row0[];
extern const u8 game_cfg_default_tbl_row1[];
extern const u8 game_cfg_default_tbl_row2[];
extern const u8 game_cfg_default_tbl_row3[];
extern const u8 game_cfg_default_tbl_row4[];
extern const u8 game_cfg_default_tbl_row5[];
extern const u8 game_cfg_default_tbl_row6[];
extern const u8 game_cfg_default_tbl_row7[];
extern const u8 game_cfg_default_tbl_row8[];
extern const char str_Asian_countries_only[];
extern const char str_Canada_and_the_Federative_Republ[];
extern const char str_Sales_export_or_operation_outsid[];
extern const char str_Sales_export_or_operation_outsid_2[];
extern const char str_This_game_is_for_use_in_japan_on[];
extern const char str_This_game_is_for_use_in_the_Euro[];
extern const char str_This_game_is_for_use_in_the_Fede[];
extern const char str_This_game_is_for_use_in_the_Ocea[];
extern const char str_This_game_is_for_use_in_the_Unit[];
extern const char str_This_game_is_for_use_in_the_West[];
extern const char str_This_game_is_for_use_in_the_sout[];
extern const char str_Violators_are_subject_to_severe_[];
extern const char str_WARNING[];
extern const char str_and_trademark_infringement_and_i[];
extern const char str_and_will_be_prosecuted_to_the_fu[];
extern const char str_blank_2[];
extern const char str_countries_except_the_United_Stat[];
extern const char str_countries_may_be_construed_as_co[];
extern const char str_country_may_be_construed_as_copy[];
extern const char str_country_may_be_construed_as_copy_2[];
extern const char str_of_America_and_Canada_only[];
extern const char str_of_Brazil_only[];
extern const char str_of_the_law[];
extern const char str_only[];
extern const char str_prohibited[];
extern const char str_trademark_infringement_and_is_st[];
extern const u8 sys_cfg_default_0_0[];
extern const u8 sys_cfg_default_0_1[];
extern const u8 sys_cfg_default_1_1[];
extern const u8 sys_cfg_default_1_2[];
extern const u8 sys_cfg_default_1_4[];
extern const u8 sys_cfg_default_1_3[];
extern const u8 sys_cfg_default_1_5[];
extern const u8 sys_cfg_default_1_6[];
extern const u8 sys_cfg_default_1_7[];
extern const u8 sys_cfg_default_1_8[];
extern const u8 sys_cfg_default_2_0[];
extern const u8 sys_cfg_default_2_1[];
extern const u8 sys_cfg_default_0_2[];
extern const u8 sys_cfg_default_2_2[];
extern const u8 sys_cfg_default_2_4[];
extern const u8 sys_cfg_default_2_3[];
extern const u8 sys_cfg_default_2_5[];
extern const u8 sys_cfg_default_2_6[];
extern const u8 sys_cfg_default_2_7[];
extern const u8 sys_cfg_default_2_8[];
extern const u8 sys_cfg_default_0_4[];
extern const u8 sys_cfg_default_0_3[];
extern const u8 sys_cfg_default_0_5[];
extern const u8 sys_cfg_default_0_6[];
extern const u8 sys_cfg_default_0_7[];
extern const u8 sys_cfg_default_0_8[];
extern const u8 sys_cfg_default_1_0[];

extern const char str_1DATA_SH5[];
extern const char str_A[];
extern const char str_ADD_ARTS[];
extern const char str_AFRICA[];
extern const char str_AFRICA_2[];
extern const char str_AFRICA_JUMP[];
extern const char str_AFRICA_LAND[];
extern const char str_AIR_NORMAL[];
extern const char str_ALEX[];
extern const char str_ALEX_BACK_D[];
extern const char str_ALEX_BODY_S[];
extern const char str_ALEX_B_D[];
extern const char str_ALEX_F_N_D[];
extern const char str_ALEX_HYPER_B[];
extern const char str_ALEX_POWER_B[];
extern const char str_ALEX_SLEEPER[];
extern const char str_ALEX_S_H_B[];
extern const char str_ALEX_ZUTUKI[];
extern const char str_ALL_CHARACTER[];
extern const char str_ALL[];
extern const char str_APPEAR_1[];
extern const char str_APPEAR_2[];
extern const char str_APPEAR_3[];
extern const char str_APPEAR_4[];
extern const char str_APPEAR_5[];
extern const char str_APPEAR_6[];
extern const char str_APPEAR_7[];
extern const char str_APPEAR_8[];
extern const char str_APPEAR_JUNBI_1[];
extern const char str_APPEAR_JUNBI_2[];
extern const char str_APPEAR_JUNBI_3[];
extern const char str_APPEAR_JUNBI_4[];
extern const char str_APPEAR_JUNBI_5[];
extern const char str_APPEAR_JUNBI_6[];
extern const char str_APPEAR_JUNBI_7[];
extern const char str_APPEAR_JUNBI_8[];
extern const char str_APPEAR_USE[];
extern const char str_ASIBARAI_SIRI[];
extern const char str_ASIB_SIRI_LOSE[];
extern const char str_ASIB_TUNNOMERI[];
extern const char str_ASIB_TUN_LOSE[];
extern const char str_AT[];
extern const char str_ATTACK[];
extern const char str_ATTACK_10_L[];
extern const char str_ATTACK_10_M[];
extern const char str_ATTACK_10_S[];
extern const char str_ATTACK_10_SP[];
extern const char str_ATTACK_11_L[];
extern const char str_ATTACK_11_M[];
extern const char str_ATTACK_11_S[];
extern const char str_ATTACK_11_SP[];
extern const char str_ATTACK_12_L[];
extern const char str_ATTACK_12_M[];
extern const char str_ATTACK_12_S[];
extern const char str_ATTACK_12_SP[];
extern const char str_ATTACK_13_L[];
extern const char str_ATTACK_13_M[];
extern const char str_ATTACK_13_S[];
extern const char str_ATTACK_13_SP[];
extern const char str_ATTACK_1_L[];
extern const char str_ATTACK_1_M[];
extern const char str_ATTACK_1_S[];
extern const char str_ATTACK_1_SP[];
extern const char str_ATTACK_2_L[];
extern const char str_ATTACK_2_M[];
extern const char str_ATTACK_2_S[];
extern const char str_ATTACK_2_SP[];
extern const char str_ATTACK_3_L[];
extern const char str_ATTACK_3_M[];
extern const char str_ATTACK_3_S[];
extern const char str_ATTACK_3_SP[];
extern const char str_ATTACK_4_L[];
extern const char str_ATTACK_4_M[];
extern const char str_ATTACK_4_S[];
extern const char str_ATTACK_4_SP[];
extern const char str_ATTACK_5_L[];
extern const char str_ATTACK_5_M[];
extern const char str_ATTACK_5_S[];
extern const char str_ATTACK_5_SP[];
extern const char str_ATTACK_6_L[];
extern const char str_ATTACK_6_M[];
extern const char str_ATTACK_6_S[];
extern const char str_ATTACK_6_SP[];
extern const char str_ATTACK_7_L[];
extern const char str_ATTACK_7_M[];
extern const char str_ATTACK_7_S[];
extern const char str_ATTACK_7_SP[];
extern const char str_ATTACK_8_L[];
extern const char str_ATTACK_8_M[];
extern const char str_ATTACK_8_S[];
extern const char str_ATTACK_8_SP[];
extern const char str_ATTACK_9_L[];
extern const char str_ATTACK_9_M[];
extern const char str_ATTACK_9_S[];
extern const char str_ATTACK_9_SP[];
extern const char str_ATT_000[];
extern const char str_ATT_IX[];
extern const char str_ATT[];
extern const char str_ATT_2[];
extern const char str_AT_LEVEL[];
extern const char str_B[];
extern const char str_BACK[];
extern const char str_BACK_WALK[];
extern const char str_BASE[];
extern const char str_BEFORE[];
extern const char str_BG_SELECT[];
extern const char str_BHA_000[];
extern const char str_BIKEI[];
extern const char str_BLANK[];
extern const char str_BODY_BROW_L[];
extern const char str_BODY_BROW_M[];
extern const char str_BODY_BROW_S[];
extern const char str_BODY_BROW_SP[];
extern const char str_BODY_SLAM[];
extern const char str_BODY_UPPER[];
extern const char str_BODY_UPPER_L[];
extern const char str_BODY_UPPER_M[];
extern const char str_BODY_UPPER_S[];
extern const char str_BODY_UPPER_SP[];
extern const char str_BODY_UPPER_SP_2[];
extern const char str_BOD_000[];
extern const char str_BONUS[];
extern const char str_BONUS_1[];
extern const char str_BONUS_2[];
extern const char str_BONUS_CHAR[];
extern const char str_BONUS_WIN_1[];
extern const char str_BONUS_WIN_2[];
extern const char str_BONUS_WIN_3[];
extern const char str_BRAZIL[];
extern const char str_BRAZIL_1[];
extern const char str_BRAZIL_1_2[];
extern const char str_BRAZIL_2[];
extern const char str_BREAST[];
extern const char str_BT[];
extern const char str_BUTTOBI[];
extern const char str_BUTT_PAT[];
extern const char str_BUTT_TYPE[];
extern const char str_B_JUMP_K_L_A[];
extern const char str_B_JUMP_K_L_B[];
extern const char str_B_JUMP_K_M_A[];
extern const char str_B_JUMP_K_M_B[];
extern const char str_B_JUMP_K_S_A[];
extern const char str_B_JUMP_K_S_B[];
extern const char str_B_JUMP_P_L_A[];
extern const char str_B_JUMP_P_L_B[];
extern const char str_B_JUMP_P_M_A[];
extern const char str_B_JUMP_P_M_B[];
extern const char str_B_JUMP_P_S_A[];
extern const char str_B_JUMP_P_S_B[];
extern const char str_C[];
extern const char str_CA[];
extern const char str_CANCEL_SH6[];
extern const char str_CATCH[];
extern const char str_CATCH_1[];
extern const char str_CATCH_10[];
extern const char str_CATCH_11[];
extern const char str_CATCH_12[];
extern const char str_CATCH_13[];
extern const char str_CATCH_14[];
extern const char str_CATCH_15[];
extern const char str_CATCH_16[];
extern const char str_CATCH_17[];
extern const char str_CATCH_18[];
extern const char str_CATCH_19[];
extern const char str_CATCH_2[];
extern const char str_CATCH_20[];
extern const char str_CATCH_21[];
extern const char str_CATCH_22[];
extern const char str_CATCH_23[];
extern const char str_CATCH_24[];
extern const char str_CATCH_25[];
extern const char str_CATCH_26[];
extern const char str_CATCH_27[];
extern const char str_CATCH_28[];
extern const char str_CATCH_29[];
extern const char str_CATCH_3[];
extern const char str_CATCH_30[];
extern const char str_CATCH_31[];
extern const char str_CATCH_32[];
extern const char str_CATCH_33[];
extern const char str_CATCH_34[];
extern const char str_CATCH_35[];
extern const char str_CATCH_36[];
extern const char str_CATCH_37[];
extern const char str_CATCH_38[];
extern const char str_CATCH_39[];
extern const char str_CATCH_4[];
extern const char str_CATCH_40[];
extern const char str_CATCH_5[];
extern const char str_CATCH_6[];
extern const char str_CATCH_7[];
extern const char str_CATCH_8[];
extern const char str_CATCH_9[];
extern const char str_CATCH_n[];
extern const char str_CAT_000[];
extern const char str_CAUGHT[];
extern const char str_CAUGHT_n[];
extern const char str_CAU_000[];
extern const char str_CB[];
extern const char str_CGD1[];
extern const char str_CGD2[];
extern const char str_CGD3[];
extern const char str_CGD_TYPE[];
extern const char str_CG_ADD_XY[];
extern const char str_CG_ATT_IX[];
extern const char str_CG_CANCEL[];
extern const char str_CG_CTR[];
extern const char str_CG_EFFECT[];
extern const char str_CG_EFTYPE[];
extern const char str_CG_EXTDAT[];
extern const char str_CG_FLIP[];
extern const char str_CG_HIT_IX[];
extern const char str_CG_NIX[];
extern const char str_CG_NUMBER[];
extern const char str_CG_OLC_IX[];
extern const char str_CG_RIVAL[];
extern const char str_CG_SE[];
extern const char str_CG_STATUS[];
extern const char str_CG_TYPE[];
extern const char str_CHAINA[];
extern const char str_CHAINA_2[];
extern const char str_CHUN_LI[];
extern const char str_CMCF[];
extern const char str_CMCR[];
extern const char str_CMJ2[];
extern const char str_CMJ3[];
extern const char str_CMJ4[];
extern const char str_CMJA[];
extern const char str_CML2[];
extern const char str_CMLP[];
extern const char str_CMMD[];
extern const char str_CMMS[];
extern const char str_CMOA[];
extern const char str_CMSW[];
extern const char str_CMYD[];
extern const char str_CODE_H[];
extern const char str_CR_1P[];
extern const char str_CU[];
extern const char str_CURRENT[];
extern const char str_CURRENT_n[];
extern const char str_D[];
extern const char str_DADLEY_L_B[];
extern const char str_DAMAGE[];
extern const char str_DASH_HUMIKOMI[];
extern const char str_DASH_TOBINOKI[];
extern const char str_DATA_NOTHING[];
extern const char str_DELETE_ALL_SH4[];
extern const char str_DENKI[];
extern const char str_DIP[];
extern const char str_DIR_ATT[];
extern const char str_DIR[];
extern const char str_DM[];
extern const char str_DUDDLEY_D_S[];
extern const char str_DUDLEY[];
extern const char str_D_P_GUARD_K_L[];
extern const char str_D_P_GUARD_K_M[];
extern const char str_D_P_GUARD_K_S[];
extern const char str_D_P_GUARD_P_L[];
extern const char str_D_P_GUARD_P_M[];
extern const char str_D_P_GUARD_P_S[];
extern const char str_EDIT_INT[];
extern const char str_EDIT_NUM[];
extern const char str_EFF01_CHAR[];
extern const char str_EFF13_CHAR[];
extern const char str_EFFECT[];
extern const char str_ELENA[];
extern const char str_ELENA_ASINAGE[];
extern const char str_ENDING[];
extern const char str_ENGLAND[];
extern const char str_ENGLAND_2[];
extern const char str_ETC[];
extern const char str_ETC_1[];
extern const char str_ETC_2[];
extern const char str_ETC_3[];
extern const char str_EX[];
extern const char str_EXIT_1P_2P_START[];
extern const char str_EXIT_OK[];
extern const char str_EXTRA[];
extern const char str_FACE[];
extern const char str_FACE_L[];
extern const char str_FACE_M[];
extern const char str_FACE_S[];
extern const char str_FACE_SP[];
extern const char str_FLANKEN_S[];
extern const char str_FLASH[];
extern const char str_FLIP_ED[];
extern const char str_FLIP[];
extern const char str_FOOK_OKU_L[];
extern const char str_FOOK_OKU_M[];
extern const char str_FOOK_OKU_S[];
extern const char str_FOOK_OKU_SP[];
extern const char str_FOOK_TEMAE_L[];
extern const char str_FOOK_TEMAE_M[];
extern const char str_FOOK_TEMAE_S[];
extern const char str_FOOK_TEMAE_SP[];
extern const char str_FRANCE[];
extern const char str_FRANCE_2[];
extern const char str_FRONT_WALK[];
extern const char str_FUSHIN_K_L[];
extern const char str_FUSHIN_K_M[];
extern const char str_FUSHIN_K_S[];
extern const char str_FUSHIN_P_L[];
extern const char str_FUSHIN_P_M[];
extern const char str_FUSHIN_P_S[];
extern const char str_F_JUMP_K_L_A[];
extern const char str_F_JUMP_K_L_B[];
extern const char str_F_JUMP_K_M_A[];
extern const char str_F_JUMP_K_M_B[];
extern const char str_F_JUMP_K_S_A[];
extern const char str_F_JUMP_K_S_B[];
extern const char str_F_JUMP_P_L_A[];
extern const char str_F_JUMP_P_L_B[];
extern const char str_F_JUMP_P_M_A[];
extern const char str_F_JUMP_P_M_B[];
extern const char str_F_JUMP_P_S_A[];
extern const char str_F_JUMP_P_S_B[];
extern const char str_GERMANY[];
extern const char str_GERMANY_2[];
extern const char str_GILL[];
extern const char str_GILL_2[];
extern const char str_GILL_3[];
extern const char str_GILL_IMPACT_C[];
extern const char str_GILL_SPLASH_M[];
extern const char str_GILL_STAGE[];
extern const char str_GOUKI_1[];
extern const char str_GOUKI_2[];
extern const char str_GROUP[];
extern const char str_GUARD_AIR[];
extern const char str_GUARD_AIR_2[];
extern const char str_GUARD_DOWN[];
extern const char str_GUARD_DOWN_2[];
extern const char str_GUARD_HEAD[];
extern const char str_GUARD_HEAD_2[];
extern const char str_GUARD_UP[];
extern const char str_GUARD_UP_2[];
extern const char str_GUARD[];
extern const char str_G[];
extern const char str_H[];
extern const char str_HANASARE[];
extern const char str_HAND[];
extern const char str_HANEAGARI[];
extern const char str_HANEKAERI_HARA[];
extern const char str_HAN_000[];
extern const char str_HARAIGOSHI[];
extern const char str_HARAYARARE[];
extern const char str_HEAD[];
extern const char str_HISS[];
extern const char str_HIT_RANGE[];
extern const char str_HIT[];
extern const char str_HONGKONG[];
extern const char str_HONGKONG_0[];
extern const char str_HONGKONG_1[];
extern const char str_HOSEI[];
extern const char str_HOS_000[];
extern const char str_HS_ME[];
extern const char str_HS_YOU[];
extern const char str_HUGO[];
extern const char str_HUGO_BODY_S[];
extern const char str_HUGO_M_S_P[];
extern const char str_HUGO_N_G_T[];
extern const char str_HUGO_S_D_B_B[];
extern const char str_HUMI_ASIB[];
extern const char str_HURIMUKI[];
extern const char str_HUSHIN_AIR[];
extern const char str_HUSHIN_DOWN[];
extern const char str_HUSHIN_HEAD[];
extern const char str_HUSHIN_UP[];
extern const char str_H_n[];
extern const char str_IBUKI[];
extern const char str_IBUKI_2[];
extern const char str_IBUKI_HARAIG[];
extern const char str_IBUKI_KUBIORI[];
extern const char str_IBUKI_YOROI_D[];
extern const char str_IMPACT[];
extern const char str_INE[];
extern const char str_INTERRUT[];
extern const char str_INT_END[];
extern const char str_IPPONZEOI[];
extern const char str_IX_000[];
extern const char str_IX_1[];
extern const char str_IX_2[];
extern const char str_IX_3[];
extern const char str_IX_4[];
extern const char str_JAPAN2[];
extern const char str_JAPAN_0[];
extern const char str_JAPAN_1[];
extern const char str_JAPAN_10[];
extern const char str_JAPAN_11[];
extern const char str_JAPAN_20[];
extern const char str_JAPAN_21[];
extern const char str_JAPAN_3[];
extern const char str_JAPAN_30[];
extern const char str_JUDGEMENT_GAL[];
extern const char str_JUDGMENT_LOSE[];
extern const char str_JUDGMENT_WAIT[];
extern const char str_JUDGMENT_WIN[];
extern const char str_JUMP_BACK[];
extern const char str_JUMP_FRONT[];
extern const char str_JUMP_JUNBI[];
extern const char str_JUMP_VERTICAL[];
extern const char str_KAGAMI_B_WALK[];
extern const char str_KAGAMI_F_WALK[];
extern const char str_KAGAMI_KAMAE[];
extern const char str_KAGAMI_K_A[];
extern const char str_KAGAMI_K_B[];
extern const char str_KAGAMI_K_C[];
extern const char str_KAGAMI_L[];
extern const char str_KAGAMI_M[];
extern const char str_KAGAMI_P_A[];
extern const char str_KAGAMI_P_B[];
extern const char str_KAGAMI_P_C[];
extern const char str_KAGAMI_S[];
extern const char str_KAGAMI_SP[];
extern const char str_KAGAMI_TURN[];
extern const char str_KAGAMU[];
extern const char str_KAMAE[];
extern const char str_KARATE[];
extern const char str_KEN[];
extern const char str_KEN_HIZAGERI[];
extern const char str_KGM_DENGEKI_L[];
extern const char str_KGM_DENGEKI_M[];
extern const char str_KGM_DENGEKI_P[];
extern const char str_KGM_DENGEKI_S[];
extern const char str_KGM_TATAKI_L[];
extern const char str_KGM_TATAKI_M[];
extern const char str_KGM_TATAKI_S[];
extern const char str_KGM_TATAKI_SP[];
extern const char str_KGM_TOUKETU_L[];
extern const char str_KGM_TOUKETU_M[];
extern const char str_KGM_TOUKETU_P[];
extern const char str_KGM_TOUKETU_S[];
extern const char str_KGM_TTKI_V_L[];
extern const char str_KGM_TTKI_V_M[];
extern const char str_KGM_TTKI_V_S[];
extern const char str_KGM_TTKI_V_SP[];
extern const char str_KIND_WAZA[];
extern const char str_KIRIMOMI[];
extern const char str_KISHINRIKI[];
extern const char str_KOC_IX_PT_Nix[];
extern const char str_KOC_IX_PT_Nix_n[];
extern const char str_KUNOJI[];
extern const char str_KUNOJI_NOKE[];
extern const char str_LEG[];
extern const char str_LOSE_KAGAMI[];
extern const char str_LOSE_NO_STAND[];
extern const char str_LOSE_SONABA[];
extern const char str_L_KICK_A[];
extern const char str_L_KICK_B[];
extern const char str_L_KICK_C[];
extern const char str_L_PUNCH_A[];
extern const char str_L_PUNCH_B[];
extern const char str_L_PUNCH_C[];
extern const char str_M[];
extern const char str_MAWARIKOMI_M_F[];
extern const char str_MF[];
extern const char str_MKH_IX[];
extern const char str_MLD[];
extern const char str_MLF[];
extern const char str_MLN[];
extern const char str_MLR[];
extern const char str_MLU[];
extern const char str_MONKEY_FLIP[];
extern const char str_MOTION[];
extern const char str_M_2[];
extern const char str_M_B[];
extern const char str_M_KICK_A[];
extern const char str_M_KICK_B[];
extern const char str_M_KICK_C[];
extern const char str_M_PUNCH_A[];
extern const char str_M_PUNCH_B[];
extern const char str_M_PUNCH_C[];
extern const char str_NAKAI[];
extern const char str_NECRO[];
extern const char str_NECRO_F_S[];
extern const char str_NECRO_G_S[];
extern const char str_NECRO_SLAM_D[];
extern const char str_NECRO_SNAKE_F[];
extern const char str_NECRO_S_T[];
extern const char str_NEKOROBI_L[];
extern const char str_NEKOROBI_M[];
extern const char str_NEKOROBI_S[];
extern const char str_NEKOROBI_SP[];
extern const char str_NG_TYPE[];
extern const char str_NM[];
extern const char str_NOBASITA_TE_L[];
extern const char str_NOBASITA_TE_M[];
extern const char str_NOBASITA_TE_S[];
extern const char str_NOBASITA_TE_SP[];
extern const char str_NOKEZORI[];
extern const char str_NORMAL[];
extern const char str_NOUTEN_L[];
extern const char str_NOUTEN_M[];
extern const char str_NOUTEN_S[];
extern const char str_NOUTEN_SP[];
extern const char str_NO_1P_SHOT6[];
extern const char str_NO_EDIT[];
extern const char str_NUM_END[];
extern const char str_N_Y[];
extern const char str_N_Y_0[];
extern const char str_N_Y_1[];
extern const char str_No_12[];
extern const char str_OBJECT_EDIT_2[];
extern const char str_OBJECT_EDIT[];
extern const char str_OBJECT_LOOK[];
extern const char str_OBJECT_TEST[];
extern const char str_OHYA[];
extern const char str_OKIAGARI[];
extern const char str_OKIAGARI_B[];
extern const char str_OKIAGARI_F[];
extern const char str_OKIAGARI_FRONT[];
extern const char str_OKIAGARI_K_L[];
extern const char str_OKIAGARI_K_M[];
extern const char str_OKIAGARI_K_S[];
extern const char str_OKIAGARI_P_L[];
extern const char str_OKIAGARI_P_M[];
extern const char str_OKIAGARI_P_S[];
extern const char str_OKIAGARI_REAR[];
extern const char str_OLC_IX[];
extern const char str_ORO[];
extern const char str_OROMEKA[];
extern const char str_ORO_GIGOKU_G[];
extern const char str_ORO_KISINRIKI[];
extern const char str_ORO_KUBISIME[];
extern const char str_ORO_NIOURIKI[];
extern const char str_ORO_TOMOENAGE[];
extern const char str_ORUMEKA[];
extern const char str_PA[];
extern const char str_PARING_AIR_B[];
extern const char str_PARING_AIR_F[];
extern const char str_PARING_DOWN[];
extern const char str_PARING_HEAD[];
extern const char str_PARING_UP[];
extern const char str_PARTS_FL[];
extern const char str_PARTS_X_H[];
extern const char str_PARTS_Y_H[];
extern const char str_PARTS[];
extern const char str_PATTERN[];
extern const char str_PAT_ST[];
extern const char str_PB[];
extern const char str_PIYO[];
extern const char str_PIYO_n[];
extern const char str_PLAYER[];
extern const char str_PLEF[];
extern const char str_POS_X_H[];
extern const char str_POS_Y_H[];
extern const char str_POW[];
extern const char str_PRESS_ANY_SHOT[];
extern const char str_P_BREAK_AIR_F[];
extern const char str_P_BREAK_AIR_R[];
extern const char str_P_BREAK_DOWN[];
extern const char str_P_BREAK_UP[];
extern const char str_P_BREAK_ZUJOU[];
extern const char str_Pa[];
extern const char str_Q[];
extern const char str_R[];
extern const char str_RAOH[];
extern const char str_REACTION[];
extern const char str_REL_X_H[];
extern const char str_REL_Y_H[];
extern const char str_REVISE_X_H[];
extern const char str_REVISE_Y_H[];
extern const char str_RUCCIA[];
extern const char str_RUSSIA_0[];
extern const char str_RUSSIA_1[];
extern const char str_RUSSIA_2[];
extern const char str_RYU[];
extern const char str_RYU_SEOINAGE[];
extern const char str_RYU_TOMOENAGE[];
extern const char str_R_n[];
extern const char str_S[];
extern const char str_S1[];
extern const char str_S2[];
extern const char str_S3[];
extern const char str_S4[];
extern const char str_S5[];
extern const char str_S6[];
extern const char str_SA[];
extern const char str_SEAN[];
extern const char str_SEAN_BALL_HIT[];
extern const char str_SEAN_TACKLE[];
extern const char str_SELECT[];
extern const char str_SELECT_UP_DOWN[];
extern const char str_SHIMEOTASARE[];
extern const char str_SIZE_X_H[];
extern const char str_SIZE_Y_H[];
extern const char str_SNAKE_FANG[];
extern const char str_SPLASH_M[];
extern const char str_SP_APPEAR_1[];
extern const char str_SP_APPEAR_2[];
extern const char str_SP_APPEAR_3[];
extern const char str_SP_APPEAR_4[];
extern const char str_SP_APPEAR_5[];
extern const char str_SP_APPEAR_6[];
extern const char str_SP_APPEAR_7[];
extern const char str_SP_APPEAR_8[];
extern const char str_SP_AT[];
extern const char str_SP_B_JP_L_K_A[];
extern const char str_SP_B_JP_L_K_B[];
extern const char str_SP_B_JP_L_P_A[];
extern const char str_SP_B_JP_L_P_B[];
extern const char str_SP_B_JP_M_K_A[];
extern const char str_SP_B_JP_M_K_B[];
extern const char str_SP_B_JP_M_P_A[];
extern const char str_SP_B_JP_M_P_B[];
extern const char str_SP_B_JP_S_K_A[];
extern const char str_SP_B_JP_S_K_B[];
extern const char str_SP_B_JP_S_P_A[];
extern const char str_SP_B_JP_S_P_B[];
extern const char str_SP_F_JP_L_K_A[];
extern const char str_SP_F_JP_L_K_B[];
extern const char str_SP_F_JP_L_P_A[];
extern const char str_SP_F_JP_L_P_B[];
extern const char str_SP_F_JP_M_K_A[];
extern const char str_SP_F_JP_M_K_B[];
extern const char str_SP_F_JP_M_P_A[];
extern const char str_SP_F_JP_M_P_B[];
extern const char str_SP_F_JP_S_K_A[];
extern const char str_SP_F_JP_S_K_B[];
extern const char str_SP_F_JP_S_P_A[];
extern const char str_SP_F_JP_S_P_B[];
extern const char str_SP_JUMP_BACK[];
extern const char str_SP_JUMP_FRONT[];
extern const char str_SP_JUMP_JUNBI[];
extern const char str_SP_JUMP_V[];
extern const char str_SP_TECH[];
extern const char str_SP_V_JP_L_K_A[];
extern const char str_SP_V_JP_L_K_B[];
extern const char str_SP_V_JP_L_P_A[];
extern const char str_SP_V_JP_L_P_B[];
extern const char str_SP_V_JP_M_K_A[];
extern const char str_SP_V_JP_M_K_B[];
extern const char str_SP_V_JP_M_P_A[];
extern const char str_SP_V_JP_M_P_B[];
extern const char str_SP_V_JP_S_K_A[];
extern const char str_SP_V_JP_S_K_B[];
extern const char str_SP_V_JP_S_P_A[];
extern const char str_SP_V_JP_S_P_B[];
extern const char str_SP_WIN_1[];
extern const char str_SP_WIN_2[];
extern const char str_SP_WIN_3[];
extern const char str_SP_WIN_4[];
extern const char str_SP_WIN_5[];
extern const char str_SP_WIN_6[];
extern const char str_SP_WIN_7[];
extern const char str_SP_WIN_8[];
extern const char str_STAND_UP[];
extern const char str_S_B_JP_L_K_A[];
extern const char str_S_B_JP_L_K_B[];
extern const char str_S_B_JP_L_P_A[];
extern const char str_S_B_JP_L_P_B[];
extern const char str_S_B_JP_M_K_A[];
extern const char str_S_B_JP_M_K_B[];
extern const char str_S_B_JP_M_P_A[];
extern const char str_S_B_JP_M_P_B[];
extern const char str_S_B_JP_S_K_A[];
extern const char str_S_B_JP_S_K_B[];
extern const char str_S_B_JP_S_P_A[];
extern const char str_S_B_JP_S_P_B[];
extern const char str_S_F_JP_L_K_A[];
extern const char str_S_F_JP_L_K_B[];
extern const char str_S_F_JP_L_P_A[];
extern const char str_S_F_JP_L_P_B[];
extern const char str_S_F_JP_M_K_A[];
extern const char str_S_F_JP_M_K_B[];
extern const char str_S_F_JP_M_P_A[];
extern const char str_S_F_JP_M_P_B[];
extern const char str_S_F_JP_S_K_A[];
extern const char str_S_F_JP_S_K_B[];
extern const char str_S_F_JP_S_P_A[];
extern const char str_S_F_JP_S_P_B[];
extern const char str_S_HANEAGARI[];
extern const char str_S_JUMP_BACK[];
extern const char str_S_JUMP_FRONT[];
extern const char str_S_JUMP_V[];
extern const char str_S_KICK_A[];
extern const char str_S_KICK_B[];
extern const char str_S_KICK_C[];
extern const char str_S_PUNCH_A[];
extern const char str_S_PUNCH_B[];
extern const char str_S_PUNCH_C[];
extern const char str_S_V_JP_L_K_A[];
extern const char str_S_V_JP_L_K_B[];
extern const char str_S_V_JP_L_P_A[];
extern const char str_S_V_JP_L_P_B[];
extern const char str_S_V_JP_M_K_A[];
extern const char str_S_V_JP_M_K_B[];
extern const char str_S_V_JP_M_P_A[];
extern const char str_S_V_JP_M_P_B[];
extern const char str_S_V_JP_S_K_A[];
extern const char str_S_V_JP_S_K_B[];
extern const char str_S_V_JP_S_P_A[];
extern const char str_S_V_JP_S_P_B[];
extern const char str_TATAKI_AIR[];
extern const char str_TATAKI_L[];
extern const char str_TATAKI_M[];
extern const char str_TATAKI_S[];
extern const char str_TATAKI_SP[];
extern const char str_TATAKI_V_L[];
extern const char str_TATAKI_V_M[];
extern const char str_TATAKI_V_S[];
extern const char str_TATAKI_V_SP[];
extern const char str_TATI_DENGEKI_L[];
extern const char str_TATI_DENGEKI_M[];
extern const char str_TATI_DENGEKI_P[];
extern const char str_TATI_DENGEKI_S[];
extern const char str_TATI_MOE_L[];
extern const char str_TATI_MOE_M[];
extern const char str_TATI_MOE_S[];
extern const char str_TATI_MOE_SP[];
extern const char str_TATI_TOUKETU_L[];
extern const char str_TATI_TOUKETU_M[];
extern const char str_TATI_TOUKETU_P[];
extern const char str_TATI_TOUKETU_S[];
extern const char str_TATUMAKIZANKU[];
extern const char str_TOMOE_ORO[];
extern const char str_TOMOE_RYU[];
extern const char str_TOUKETSU_A[];
extern const char str_TRUNK[];
extern const char str_TTKI_V_AIR[];
extern const char str_TUKAMIHAZUSARE[];
extern const char str_TUKAMIHAZUSI[];
extern const char str_TUKAMIKAKARI_A[];
extern const char str_TUKAMIKAKARI_B[];
extern const char str_TUKAMIKAKARI_C[];
extern const char str_TUKAMIKAKARI_D[];
extern const char str_TUKAMIKAKARI_E[];
extern const char str_TUKAMIKAKARI_F[];
extern const char str_TUKAMI_AIR_A[];
extern const char str_TUKAMI_AIR_B[];
extern const char str_TUKAMI_AIR_C[];
extern const char str_TUKAMI_AIR_D[];
extern const char str_TUKAMI_AIR_E[];
extern const char str_TUKAMI_AIR_F[];
extern const char str_UKEMI_MOVE_F[];
extern const char str_UKEMI_MOVE_R[];
extern const char str_UNION[];
extern const char str_UPPER[];
extern const char str_UPPER_L[];
extern const char str_UPPER_M[];
extern const char str_UPPER_S[];
extern const char str_UPPER_SP[];
extern const char str_UP_P_GUARD_K_L[];
extern const char str_UP_P_GUARD_K_M[];
extern const char str_UP_P_GUARD_K_S[];
extern const char str_UP_P_GUARD_P_L[];
extern const char str_UP_P_GUARD_P_M[];
extern const char str_UP_P_GUARD_P_S[];
extern const char str_URIEN[];
extern const char str_USEMJ[];
extern const char str_VS_ID[];
extern const char str_V_JUMP_K_L_A[];
extern const char str_V_JUMP_K_L_B[];
extern const char str_V_JUMP_K_M_A[];
extern const char str_V_JUMP_K_M_B[];
extern const char str_V_JUMP_K_S_A[];
extern const char str_V_JUMP_K_S_B[];
extern const char str_V_JUMP_P_L_A[];
extern const char str_V_JUMP_P_L_B[];
extern const char str_V_JUMP_P_M_A[];
extern const char str_V_JUMP_P_M_B[];
extern const char str_V_JUMP_P_S_A[];
extern const char str_V_JUMP_P_S_B[];
extern const char str_WAIT[];
extern const char str_WALK_END[];
extern const char str_WCA[];
extern const char str_WCA_IX[];
extern const char str_WIN_1[];
extern const char str_WIN_2[];
extern const char str_WIN_3[];
extern const char str_WIN_4[];
extern const char str_WIN_5[];
extern const char str_WIN_6[];
extern const char str_WIN_7[];
extern const char str_WIN_8[];
extern const char str_WORK_EMPTY[];
extern const char str_YANG[];
extern const char str_YES_2P_SHOT6[];
extern const char str_YOKE_PAT[];
extern const char str_YOKE_TYPE[];
extern const char str_YOKOYAMA[];
extern const char str_YOSHIZUMI[];
extern const char str_YUN[];
extern const char str_YUN_2[];
extern const char str_YUN_HIZAGERI[];
extern const char str_YUN_MONKEY_F[];
extern const char str_YU[];
extern const char str_ZANNEN_1[];
extern const char str_ZANNEN_2[];
extern const char str_ZANNEN_3[];
extern const char str_ZANNEN_4[];
extern const char str_ZANNEN_5[];
extern const char str_ZANNEN_6[];
extern const char str_ZANNEN_7[];
extern const char str_ZANNEN_8[];
extern const char str_ZOKUSEI[];
extern const char str_ZU_FLAG[];
extern const char str_a[];
extern const char str_a_2[];
extern const char str_c[];
extern const char str_c_2[];
extern const char str_d[];
extern const char str_d_2[];
extern const char str_empty[];
extern const char str_empty_10[];
extern const char str_empty_2[];
extern const char str_empty_3[];
extern const char str_empty_4[];
extern const char str_empty_5[];
extern const char str_empty_6[];
extern const char str_empty_7[];
extern const char str_empty_8[];
extern const char str_empty_9[];
extern const char str_h[];
extern const char str_h_2[];
extern const char str_hsA[];
extern const char str_hsC[];
extern const char str_huA[];
extern const char str_m[];
extern const char str_m_2[];
extern const char str_n[];
extern const char str_n_2[];
extern const char str_n_3[];
extern const char str_n_4[];
extern const char str_nmA[];
extern const char str_nmC[];
extern const char str_paA[];
extern const char str_r[];
extern const char str_r_2[];
extern const char str_s[];
extern const char str_s_2[];
extern const char str_saA[];
extern const char str_saC[];
extern const char str_sl_00[];
extern const char str_sl_10[];
extern const char str_sl_12[];
extern const char str_sl_20[];
extern const char str_sl_22[];
extern const char str_sl_30[];
extern const char str_sl_32[];
extern const char str_sl_40[];
extern const char str_sl_42[];
extern const char str_sl_44[];
extern const char str_sl_50[];
extern const char str_sl_52[];
extern const char str_sl_54[];
extern const char str_sl_60[];
extern const char str_sl_62[];
extern const char str_sl_64[];
extern const char str_sl_70[];
extern const char str_sl_80[];
extern const char str_sl_82[];
extern const char str_sl_90[];

extern void BG000(), BG010(), BG020(), BG030(), BG040(), BG050(), BG060(), BG070();
extern void BG080(), BG090(), BG100(), BG120(), BG130(), BG140(), BG150(), BG160();
extern void BG180(), BG190(), Bonus_bg1(), Bonus_bg2(), Name_Finish(), Name_Input_comm(), Name_Input_init(), Name_Input_wait();
extern void Name_Scs_Finish(), Name_Scs_Input_comm(), op_118_move(), check_0(), check_1(), check_10(), check_11(), check_12();
extern void check_13(), check_14(), check_15(), check_16(), check_18(), check_19(), check_2(), check_20();
extern void check_21(), check_22(), check_23(), check_24(), check_25(), check_26(), check_3(), check_4();
extern void check_5(), check_6(), check_7(), check_9(), check_init(), config_menu_dispatch(), config_menu_init(), config_top_default();
extern void config_top_draw(), config_top_game(), config_top_page(), config_top_save_exit(), config_top_select(), config_top_system(), Name_Input_end(), Name_Scs_Input_init();
extern void eff09_0000(), eff09_1000(), eff09_10000(), eff09_11000(), eff09_12000(), eff09_13000(), eff09_14000(), eff09_15000();
extern void eff09_16000(), eff09_17000(), eff09_18000(), eff09_19000(), eff09_2000(), eff09_20000(), eff09_21000(), eff09_22000();
extern void eff09_23000(), eff09_24000(), eff09_25000(), eff09_26000(), eff09_27000(), eff09_3000(), eff09_4000(), eff09_5000();
extern void eff09_6000(), eff09_7000(), eff09_8000(), eff09_9000(), eff18_00(), eff18_01(), eff25_00(), eff25_02();
extern void eff25_04(), eff25_06(), eff25_08(), eff26_00(), eff26_01(), eff26_02(), eff26_03(), eff26_04();
extern void eff26_05(), eff27_00(), eff27_02(), eff27_03(), eff27_04(), eff27_05(), eff27_06(), eff27_07();
extern void eff27_08(), eff27_09(), eff64_00(), eff64_02(), eff64_04(), eff64_08(), eff66_00(), eff66_01();
extern void eff66_02(), eff66_03(), end_00000(), end_02000(), end_03000(), end_04000(), end_05000(), end_06000();
extern void end_07000(), end_08000(), end_09000(), end_10000(), end_11000(), end_12000(), end_13000(), end_14000();
extern void end_17000(), end_19000(), end_20000(), end_400_0000(), end_400_1000(), end_401_0000(), end_401_1000(), end_401_2000();
extern void end_401_3000(), end_401_4000(), end_402_0000(), end_402_1000(), end_X_com01(), end_01000(), end_16000(), end_18000();
extern void gameconfig_page(), Name_Scs_Input_end(), op_100_move(), op_101_move(), op_102_move(), op_103_move(), op_104_move(), op_105_move();
extern void op_106_move(), op_107_move(), op_109_move(), op_110_move(), op_111_move(), op_112_move(), op_113_move(), op_114_move();
extern void op_115_move(), op_116_move(), op_117_move(), op_108_move(), scr_10_20(), scr_10_21(), scr_10_22(), scr_11_20();
extern void scr_11_21(), scr_11_22(), scr_12_20(), scr_12_21(), scr_12_22(), scr_x_dummy(), sysconfig_chute_mode(), sysconfig_coin();
extern void sysconfig_continue(), sysconfig_demo_sound(), sysconfig_dispenser(), sysconfig_draw(), sysconfig_exit(), sysconfig_monitor(), sysconfig_page(), sysconfig_select();
extern void sysconfig_sound_mode(), sysconfig_win_point(), sysconfig_win_point_human();
extern const u8 Arts_Rnd_Data[];
extern const u8 EFF59_Correct_Data[];
extern const s8 FBI_msg[200];
extern const s8 str_Q_SOUND[];
extern const s8 str_EYE_CATCH_Part1[];
extern const s8 str_EYE_CATCH_Part2[];
extern const s8 str_STREET_FIGHTER_III_2[];
extern const s8 str_199X_CAPCOM[];
extern const s8 str_PLAY_DEMO[];
extern const s8 str_RANKING[];
extern const s8 str_FBI[];
extern const s8 str_SELECT_PLAYER[];
extern const s8 str_SELECT_PLAYER_2[];
extern const s8 str_INSERT_COIN_2[];
extern const s8 str_blank_3[];
extern const s8 str_PUSH_1_OR_2_START_BUTTON[];
extern const u8 Game_Config_Jmp_Data[];
extern const u8 M3_bahn_data[];
extern const u8 Pattern20_Tbl[];
extern const u8 afc_char_table[];
extern const u8 ag_face_panel_table[];
extern const u8 ake_scr_record_data[1358];
extern const u8 alex_atca[];
extern const u8 alex_btca[];
extern const u8 alex_caca[];
extern const u8 alex_cuca[];
extern const u8 alex_dmca[];
extern const u8 alex_exca[];
extern const u8 alex_nmca[];
extern const u8 alex_saca[];
extern const u8 alex_yuca[];
extern const u8 bbbs_level_00[];
extern const u8 bbbs_level_01[];
extern const u8 bbbs_level_02[];
extern const u8 bbbs_level_03[];
extern const u8 bbbs_level_04[];
extern const u8 bbbs_level_05[];
extern const u8 bbbs_level_06[];
extern const u8 bbbs_level_07[];
extern const u8 bbbs_level_08[];
extern const s16 bbbs_level_09[9669];
extern const s16 bg_cell_set_tbl[240];
extern const s16 bg_scr_record_data[92];
extern const u8 bns_char_table[];
extern const u8 bonus_char_table[];
extern const u8 brz_char_table[];
extern const u8 chn_char_table[];
extern const u8 chun_atca[];
extern const u8 chun_btca[];
extern const u8 chun_caca[];
extern const u8 chun_cuca[];
extern const u8 chun_dmca[];
extern const u8 chun_exca[];
extern const u8 chun_nmca[];
extern const u8 chun_saca[];
extern const u8 chun_yuca[];
extern const u8 coin_rate_tbl[24][2];
extern const char dbg_wca_str[44];
extern const u8 dog24_x_data[];
extern const u8 dudley_atca[];
extern const u8 dudley_btca[];
extern const u8 dudley_caca[];
extern const u8 dudley_cuca[];
extern const u8 dudley_dmca[];
extern const u8 dudley_exca[];
extern const u8 dudley_nmca[];
extern const u8 dudley_saca[];
extern const u8 dudley_yuca[];
extern const u8 ef01_char_table[];
extern const u8 ef13_char_table[];
extern const u8 eff21_sp_tbl[];
extern const s16 eff26_num[2];
extern const u8 eff48_data_tbl00[];
extern const u8 eff48_data_tbl01[];
extern const u8 eff48_data_tbl02[];
extern const u8 eff48_data_tbl03[];
extern const u8 eff48_data_tbl04[];
extern const u8 eff48_data_tbl05[];
extern const u8 eff48_data_tbl06[];
extern const u8 eff48_data_tbl07[];
extern const u8 eff48_data_tbl08[];
extern const u8 eff48_data_tbl09[];
extern const u8 eff48_data_tbl10[];
extern const u8 eff48_data_tbl11[];
extern const u8 eff48_data_tbl12[];
extern const u8 eff48_data_tbl13[];
extern const u8 eff48_data_tbl14[];
extern const u8 eff48_data_tbl15[];
extern const u8 eff48_data_tbl16[];
extern const u8 eff48_data_tbl17[];
extern const u8 eff48_data_tbl18[];
extern const u8 eff48_data_tbl19[];
extern const u8 eff48_data_tbl20[];
extern const u8 eff48_data_tbl21[];
extern const u8 eff86_data_tbl00[];
extern const u8 eff87_loop_tbl[];
extern const s16 eff88_loop_tbl[4][4];
extern const s16 effH7_bound_tbl[164];
extern const u8 effJ5_frame_tbl[];
extern void (*const effM0_tbl_top[15])();
extern const u8 elena_atca[];
extern const u8 elena_btca[];
extern const u8 elena_caca[];
extern const u8 elena_cuca[];
extern const u8 elena_dmca[];
extern const u8 elena_exca[];
extern const u8 elena_nmca[];
extern const u8 elena_saca[];
extern const u8 elena_yuca[];
extern const u8 end_1100_bg0_cell_tbl[];
extern const u8 end_300_col_tbl[];
extern const u32 end_cg_src_tbl[80];
extern const u8 end_char_table[];
extern const u8 eng_char_table[];
extern const u8 etc2_char_table[];
extern const u8 etc3_char_table[];
extern const u32 etc_bg_cg_src_tbl[200];
extern const u8 etc_char_table[];
extern const u8 fade_data_tbl[];
extern const u8 flash_color_tbl[];
extern const u8 fnl_char_table[];
extern const u8 frc_char_table[];
extern const u8 gill_atca[];
extern const u8 gill_btca[];
extern const u8 gill_caca[];
extern const u8 gill_cuca[];
extern const u8 gill_dmca[];
extern const u8 gill_exca[];
extern const u8 gill_nmca[];
extern const u8 gill_saca[];
extern const u8 gill_yuca[];
extern const u8 gouki1_atca[];
extern const u8 gouki1_btca[];
extern const u8 gouki1_caca[];
extern const u8 gouki1_cuca[];
extern const u8 gouki1_dmca[];
extern const u8 gouki1_exca[];
extern const u8 gouki1_nmca[];
extern const u8 gouki1_saca[];
extern const u8 gouki1_yuca[];
extern const u8 gouki2_atca[];
extern const u8 gouki2_btca[];
extern const u8 gouki2_caca[];
extern const u8 gouki2_cuca[];
extern const u8 gouki2_dmca[];
extern const u8 gouki2_exca[];
extern const u8 gouki2_nmca[];
extern const u8 gouki2_saca[];
extern const u8 gouki2_yuca[];
extern const u8 grm_char_table[];
extern const u8 hissatsu_dageki_00[];
extern const u8 hissatsu_dageki_01[];
extern const u8 hissatsu_dageki_02[];
extern const u8 hit_kind_tbl[];
extern const u8 hkg_char_table[];
extern const u8 hugo_atca[];
extern const u8 hugo_btca[];
extern const u8 hugo_caca[];
extern const u8 hugo_cuca[];
extern const u8 hugo_dmca[];
extern const u8 hugo_exca[];
extern const u8 hugo_nmca[];
extern const u8 hugo_saca[];
extern const u8 hugo_yuca[];
extern const u8 ibuki_atca[];
extern const u8 ibuki_btca[];
extern const u8 ibuki_caca[];
extern const u8 ibuki_cuca[];
extern const u8 ibuki_dmca[];
extern const u8 ibuki_exca[];
extern const u8 ibuki_nmca[];
extern const u8 ibuki_saca[];
extern const u8 ibuki_yuca[];
extern const u8 j10_char_table[];
extern const u8 j11_char_table[];
extern const u8 jp3_char_table[];
extern const u8 jp_menu_cg_5[];
extern const u8 ken_atca[];
extern const u8 ken_btca[];
extern const u8 ken_caca[];
extern const u8 ken_cuca[];
extern const u8 ken_dmca[];
extern const u8 ken_exca[];
extern const u8 ken_nmca[];
extern const u8 ken_saca[];
extern const u8 ken_yuca[];
extern const u8 makoto_atca[];
extern const u8 makoto_btca[];
extern const u8 makoto_caca[];
extern const u8 makoto_cuca[];
extern const u8 makoto_dmca[];
extern const u8 makoto_exca[];
extern const u8 makoto_nmca[];
extern const u8 makoto_saca[];
extern const u8 makoto_yuca[];
extern const u8 memtest_skip_str[];
extern const s8 msg_press_2p_button[204];
extern const s8 str_INSERT_COIN[];
extern const s8 str_INSERT_COINS[];
extern const s8 str_INSERT_COINS_2[];
extern const s8 str_INSERT_COINS_3[];
extern const s8 str_INSERT_COINS_4[];
extern const s8 str_INSERT_COINS_5[];
extern const s8 str_INSERT_COINS_6[];
extern const s8 str_INSERT_COINS_7[];
extern const s8 str_INSERT_COINS_8[];
extern const u8 necro_atca[];
extern const u8 necro_btca[];
extern const u8 necro_caca[];
extern const u8 necro_cuca[];
extern const u8 necro_dmca[];
extern const u8 necro_exca[];
extern const u8 necro_nmca[];
extern const u8 necro_saca[];
extern const u8 necro_yuca[];
extern const u8 no12_atca[];
extern const u8 no12_btca[];
extern const u8 no12_caca[];
extern const u8 no12_cuca[];
extern const u8 no12_dmca[];
extern const u8 no12_exca[];
extern const u8 no12_nmca[];
extern const u8 no12_saca[];
extern const u8 no12_yuca[];
extern const u8 op_char_table[];
extern const u8 orm_char_table[];
extern const u8 oro_atca[];
extern const u8 oro_btca[];
extern const u8 oro_caca[];
extern const u8 oro_cuca[];
extern const u8 oro_dmca[];
extern const u8 oro_exca[];
extern const u8 oro_nmca[];
extern const u8 oro_saca[];
extern const u8 oro_yuca[];
extern const u8 parental_advisory_msg[];
extern const u8 paring_b_mark_data[];
extern const s16 pl01txt1[40];
extern const s16 pl02txt1[20];
extern const u8 pl02txt5[];
extern const u8 pl03txt1[];
extern const s16 pl03txt2[14];
extern const s16 pl03txt4[18];
extern const u8 pl03txt6[];
extern const s16 pl04txt1[24];
extern const u8 pl05txt1[];
extern const s16 pl05txt2[20];
extern const u8 pl05txt5[];
extern const s16 pl05txt6[12];
extern const u8 pl06txt2[];
extern const u8 pl06txt3[];
extern const u8 pl06txt4[];
extern const u8 pl06txt5[];
extern const u8 pl07txt1[];
extern const u8 pl07txt2[];
extern const s16 pl07txt3[20];
extern const u8 pl08txt1[];
extern const u8 pl08txt2[];
extern const s16 pl08txt3[18];
extern const s16 pl09txt2[10];
extern const u8 pl09txt4[];
extern const u8 pl09txt5[];
extern const u8 pl09txt6[];
extern const u8 pl10txt1[];
extern const s16 pl10txt2[16];
extern const s16 pl10txt4[16];
extern const s16 pl10txt6[12];
extern const s16 pl11txt2[40];
extern const s16 pl12txt2[14];
extern const u8 pl12txt4[];
extern const s16 pl12txt5[10];
extern const u8 pl13txt1[];
extern const s16 pl13txt2[22];
extern const u8 pl14txt1[];
extern const s16 pl14txt2[24];
extern const s16 pl15txt1[14];
extern const u8 pl15txt3[];
extern const s16 pl15txt4[12];
extern const u8 pl16txt1[];
extern const u8 pl16txt2[];
extern const s16 pl16txt3[8];
extern const u8 pl16txt5[];
extern const u8 pl16txt6[];
extern const u8 pl16txt7[];
extern const u8 pl17txt1[];
extern const u8 pl17txt2[];
extern const u8 pl17txt3[];
extern const s16 pl17txt5[54];
extern const s16 pl17txt6[14];
extern const u8 pl19txt2[];
extern const u8 pl19txt3[];
extern const s16 pl19txt4[14];
extern const s16 pl19txt6[10];
extern const u8 pl_cmd_num[];
extern const s16 gill_cmd_00[];
extern const s16 gill_cmd_01[];
extern const s16 gill_cmd_02[];
extern const s16 gill_cmd_03[];
extern const s16 gill_cmd_04[];
extern const s16 gill_cmd_05[];
extern const s16 gill_cmd_06[];
extern const s16 gill_cmd_07[];
extern const s16 gill_cmd_08[];
extern const s16 gill_cmd_09[];
extern const s16 gill_cmd_10[];
extern const s16 gill_cmd_11[];
extern const s16 gill_cmd_12[];
extern const s16 gill_cmd_13[];
extern const s16 gill_cmd_14[];
extern const s16 gill_cmd_15[];
extern const s16 gill_cmd_16[];
extern const s16 gill_cmd_20[];
extern const s16 gill_cmd_21[];
extern const s16 gill_cmd_22[];
extern const s16 gill_cmd_24[];
extern const s16 gill_cmd_25[];
extern const s16 gill_cmd_28[];
extern const s16 gill_cmd_29[];
extern const s16 gill_cmd_30[];
extern const s16 gill_cmd_31[];
extern const s16 alex_cmd_20[];
extern const s16 alex_cmd_21[];
extern const s16 alex_cmd_22[];
extern const s16 alex_cmd_28[];
extern const s16 alex_cmd_29[];
extern const s16 alex_cmd_30[];
extern const s16 alex_cmd_31[];
extern const s16 alex_cmd_32[];
extern const s16 alex_cmd_33[];
extern const s16 ryu_cmd_20[];
extern const s16 ryu_cmd_21[];
extern const s16 ryu_cmd_22[];
extern const s16 ryu_cmd_28[];
extern const s16 ryu_cmd_29[];
extern const s16 ryu_cmd_30[];
extern const s16 ryu_cmd_31[];
extern const s16 ryu_cmd_46[];
extern const s16 yun_cmd_20[];
extern const s16 yun_cmd_21[];
extern const s16 yun_cmd_22[];
extern const s16 yun_cmd_28[];
extern const s16 yun_cmd_29[];
extern const s16 yun_cmd_30[];
extern const s16 yun_cmd_31[];
extern const s16 yun_cmd_32[];
extern const s16 dudley_cmd_20[];
extern const s16 dudley_cmd_21[];
extern const s16 dudley_cmd_22[];
extern const s16 dudley_cmd_28[];
extern const s16 dudley_cmd_29[];
extern const s16 dudley_cmd_30[];
extern const s16 dudley_cmd_31[];
extern const s16 dudley_cmd_32[];
extern const s16 dudley_cmd_33[];
extern const s16 necro_cmd_20[];
extern const s16 necro_cmd_21[];
extern const s16 necro_cmd_22[];
extern const s16 necro_cmd_28[];
extern const s16 necro_cmd_29[];
extern const s16 necro_cmd_30[];
extern const s16 necro_cmd_31[];
extern const s16 necro_cmd_32[];
extern const s16 hugo_cmd_20[];
extern const s16 hugo_cmd_21[];
extern const s16 hugo_cmd_22[];
extern const s16 hugo_cmd_28[];
extern const s16 hugo_cmd_29[];
extern const s16 hugo_cmd_30[];
extern const s16 hugo_cmd_31[];
extern const s16 hugo_cmd_32[];
extern const s16 hugo_cmd_33[];
extern const s16 ibuki_cmd_20[];
extern const s16 ibuki_cmd_21[];
extern const s16 ibuki_cmd_38[];
extern const s16 ibuki_cmd_28[];
extern const s16 ibuki_cmd_29[];
extern const s16 ibuki_cmd_30[];
extern const s16 ibuki_cmd_31[];
extern const s16 ibuki_cmd_32[];
extern const s16 ibuki_cmd_33[];
extern const s16 ibuki_cmd_34[];
extern const s16 ibuki_cmd_46[];
extern const s16 elena_cmd_20[];
extern const s16 elena_cmd_21[];
extern const s16 elena_cmd_22[];
extern const s16 elena_cmd_28[];
extern const s16 elena_cmd_29[];
extern const s16 elena_cmd_30[];
extern const s16 elena_cmd_31[];
extern const s16 elena_cmd_32[];
extern const s16 oro_cmd_20[];
extern const s16 oro_cmd_21[];
extern const s16 oro_cmd_22[];
extern const s16 oro_cmd_24[];
extern const s16 oro_cmd_28[];
extern const s16 oro_cmd_29[];
extern const s16 oro_cmd_30[];
extern const s16 oro_cmd_31[];
extern const s16 oro_cmd_46[];
extern const s16 oro_cmd_47[];
extern const s16 yang_cmd_20[];
extern const s16 yang_cmd_21[];
extern const s16 yang_cmd_22[];
extern const s16 yang_cmd_28[];
extern const s16 yang_cmd_29[];
extern const s16 yang_cmd_30[];
extern const s16 yang_cmd_31[];
extern const s16 yang_cmd_32[];
extern const s16 ken_cmd_20[];
extern const s16 ken_cmd_21[];
extern const s16 ken_cmd_22[];
extern const s16 ken_cmd_28[];
extern const s16 ken_cmd_29[];
extern const s16 ken_cmd_30[];
extern const s16 ken_cmd_46[];
extern const s16 sean_cmd_20[];
extern const s16 sean_cmd_21[];
extern const s16 sean_cmd_22[];
extern const s16 sean_cmd_28[];
extern const s16 sean_cmd_29[];
extern const s16 sean_cmd_30[];
extern const s16 sean_cmd_31[];
extern const s16 sean_cmd_32[];
extern const s16 urien_cmd_20[];
extern const s16 urien_cmd_21[];
extern const s16 urien_cmd_22[];
extern const s16 urien_cmd_28[];
extern const s16 urien_cmd_29[];
extern const s16 urien_cmd_30[];
extern const s16 urien_cmd_31[];
extern const s16 gouki1_cmd_20[];
extern const s16 gouki1_cmd_21[];
extern const s16 gouki1_cmd_22[];
extern const s16 gouki1_cmd_24[];
extern const s16 gouki1_cmd_25[];
extern const s16 gouki1_cmd_28[];
extern const s16 gouki1_cmd_29[];
extern const s16 gouki1_cmd_30[];
extern const s16 gouki1_cmd_31[];
extern const s16 gouki1_cmd_32[];
extern const s16 gouki1_cmd_33[];
extern const s16 gouki1_cmd_34[];
extern const s16 gouki1_cmd_35[];
extern const s16 gouki1_cmd_38[];
extern const s16 gouki1_cmd_39[];
extern const s16 gouki1_cmd_46[];
extern const s16 gouki1_cmd_47[];
extern const s16 chun_cmd_20[];
extern const s16 chun_cmd_21[];
extern const s16 chun_cmd_22[];
extern const s16 chun_cmd_28[];
extern const s16 chun_cmd_29[];
extern const s16 chun_cmd_30[];
extern const s16 chun_cmd_31[];
extern const s16 makoto_cmd_20[];
extern const s16 makoto_cmd_21[];
extern const s16 makoto_cmd_22[];
extern const s16 makoto_cmd_28[];
extern const s16 makoto_cmd_29[];
extern const s16 makoto_cmd_30[];
extern const s16 makoto_cmd_31[];
extern const s16 makoto_cmd_46[];
extern const s16 q_cmd_20[];
extern const s16 q_cmd_21[];
extern const s16 q_cmd_22[];
extern const s16 q_cmd_28[];
extern const s16 q_cmd_29[];
extern const s16 q_cmd_30[];
extern const s16 q_cmd_31[];
extern const s16 q_cmd_32[];
extern const s16 q_cmd_33[];
extern const s16 no12_cmd_20[];
extern const s16 no12_cmd_21[];
extern const s16 no12_cmd_38[];
extern const s16 no12_cmd_28[];
extern const s16 no12_cmd_29[];
extern const s16 no12_cmd_30[];
extern const s16 no12_cmd_46[];
extern const s16 no12_cmd_47[];
extern const s16 no12_cmd_48[];
extern const s16 no12_cmd_49[];
extern const s16 remy_cmd_20[];
extern const s16 remy_cmd_21[];
extern const s16 remy_cmd_22[];
extern const s16 remy_cmd_28[];
extern const s16 remy_cmd_29[];
extern const s16 remy_cmd_30[];
extern const s16 remy_cmd_31[];
extern const u8 plef_char_table[];
extern void (*const plxx_extra_attack_table[54])();
extern const u8 q_atca[];
extern const u8 q_btca[];
extern const u8 q_caca[];
extern const u8 q_cuca[];
extern const u8 q_dmca[];
extern const u8 q_exca[];
extern const u8 q_nmca[];
extern const u8 q_saca[];
extern const u8 q_yuca[];
extern const u8 rca_char_table[];
extern const u8 remy_atca[];
extern const u8 remy_btca[];
extern const u8 remy_caca[];
extern const u8 remy_cuca[];
extern const u8 remy_dmca[];
extern const u8 remy_exca[];
extern const u8 remy_nmca[];
extern const u8 remy_saca[];
extern const u8 remy_yuca[];
extern const u8 ryu_atca[];
extern const u8 ryu_btca[];
extern const u8 ryu_caca[];
extern const u8 ryu_cuca[];
extern const u8 ryu_dmca[];
extern const u8 ryu_exca[];
extern const u8 ryu_nmca[];
extern const u8 ryu_saca[];
extern const u8 ryu_yuca[];
extern const u8 sagauge_colchg_tbl[];
extern const s16 scr_obj_num[352];
extern const s16 scr_obj_num10[30];
extern const s16 scr_obj_num12[94];
extern const u8 scr_obj_num18[];
extern const u8 scr_obj_num27[];
extern const s16 scr_obj_num28[10];
extern const s16 scr_obj_num44[242];
extern const s16 scr_obj_num6[546];
extern const u8 sean_atca[];
extern const u8 sean_btca[];
extern const u8 sean_caca[];
extern const u8 sean_cuca[];
extern const u8 sean_dmca[];
extern const u8 sean_exca[];
extern const u8 sean_nmca[];
extern const u8 sean_saca[];
extern const u8 sean_yuca[];
extern const u8 sel_pl_char_table[];
extern const u8 sh_str_undef[];
extern const u8 super_arts_nage_00[];
extern const u8 super_arts_nage_01[];
extern const u8 super_arts_nage_02[];
extern const u8 tsuujyou_dageki_00[];
extern const u8 tsuujyou_dageki_01[];
extern const u8 tsuujyou_dageki_02[];
extern const u8 tsuujyou_nage_00[];
extern const u8 tsuujyou_nage_01[];
extern const s16 tsuujyou_nage_02[112];
extern const u8 ukemi_time_tbl[];
extern const u8 urien_atca[];
extern const u8 urien_btca[];
extern const u8 urien_caca[];
extern const u8 urien_cuca[];
extern const u8 urien_dmca[];
extern const u8 urien_exca[];
extern const u8 urien_nmca[];
extern const u8 urien_saca[];
extern const u8 urien_yuca[];
extern const u8 usa_char_table[];
extern const u16 vital_cell_1p_tbl[131];
extern const u8 yang_atca[];
extern const u8 yang_btca[];
extern const u8 yang_caca[];
extern const u8 yang_cuca[];
extern const u8 yang_dmca[];
extern const u8 yang_exca[];
extern const u8 yang_nmca[];
extern const u8 yang_saca[];
extern const u8 yang_yuca[];
extern const u8 yun_atca[];
extern const u8 yun_btca[];
extern const u8 yun_caca[];
extern const u8 yun_cuca[];
extern const u8 yun_dmca[];
extern const u8 yun_exca[];
extern const u8 yun_nmca[];
extern const u8 yun_saca[];
extern const u8 yun_yuca[];
extern u8 coin3_in_flag[];
extern u8 coin_chute1_w[];
extern s8 coin_chute2_w[8];
extern u8 p1sw_0[];
extern u8 p1sw_1[];
extern u8 p2sw_0[];
extern u8 p2sw_1[];
extern u8 p3sw_0[];
extern u8 p3sw_1[];
extern u8 p4sw_0[];
extern u8 p4sw_1[];
extern u8 task_stack[18][1024];

extern void (*chk_move_jp[])();
extern s8 credit_1p;
extern s8 credit_2p;
extern s8 credit_3p;
extern s8 credit_4p;
extern TM_STRING dbg_act_kind_str[994];
extern void* effF9_mes_pt[141];
extern TMSCRIPT sys_cfg_page_scr_jp[81];
extern void* sys_cfg_sound_scr_jp[];

u32 frt_tick_count = 0;  /* 02000000 */
s8 Coin_Mode = 0;  /* 02000004 */
s8 Monitor_Flip = 0;  /* 02000005 */
s8 Continue_Flag = 0;  /* 02000006 */
s8 Chute_Mode = 0;  /* 02000007 */
s8 Sound_Mode = 0;  /* 02000008 */
s8 Demo_Sound = 0;  /* 02000009 */
/* 0200000A */
/* Stored after Demo_Sound. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Demo_Sound. */
u8 Demo_Sound_tail[1] = {
    0,
};

s8 Language = 0;  /* 0200000B */
s8 Free_Play = 0;  /* 0200000C */
u8 Card_Dispenser = 0;  /* 0200000D */
s8 Win_Point_Com = 0;  /* 0200000E */
s8 Win_Point_Human = 0;  /* 0200000F */
s8 Voice_Type = 0;  /* 02000010 */
s8 Win_Point_Com_Max = 8;  /* 02000011 */
s8 Win_Point_Human_Max = 30;  /* 02000012 */
s8 Win_Point_Com_Min = 2;  /* 02000013 */
s8 Win_Point_Human_Min = 2;  /* 02000014 */
s8 Win_Point_Split = 0;  /* 02000015 */
s8 Cabinet_Type = 0;  /* 02000016 */
s8 Area_Type = 0;  /* 02000017 */
s8 Area_Alt_Flag = 0;  /* 02000018 */
s8 Two_Coin_Start = 0;  /* 02000019 */
s8 Free_Play_Enable = 0;  /* 0200001A */
/* 0200001B */
/* Stored after Free_Play_Enable. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Free_Play_Enable. */
u8 Free_Play_Enable_tail[2] = {
    0, 0,
};

s8 Cd_Error_Flag = 0;  /* 0200001D */
s16 Config_No_0 = 0;  /* 0200001E */
s16 Config_No_1 = 0;  /* 02000020 */
s16 Config_No_2 = 0;  /* 02000022 */
/* 02000024 */
void* reg_name_tbl[16] = {
    (void*)str_R0,
    (void*)str_R1,
    (void*)str_R2,
    (void*)str_R3,
    (void*)str_R4,
    (void*)str_R5,
    (void*)str_R6,
    (void*)str_R7,
    (void*)str_R8,
    (void*)str_R9,
    (void*)str_R10,
    (void*)str_R11,
    (void*)str_R12,
    (void*)str_R13,
    (void*)str_R14,
    (void*)str_SP,
};
/* Stored after reg_name_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of reg_name_tbl. */
u32 reg_name_tbl_tail[3] = {
    1024, 256, 256,
};

s32 task_stack_num = 8;  /* 02000070 */
void* isp_vblank = (void*)&task_stack[9][0];  /* 02000074 */
void* isp_sprite_poly = (void*)&task_stack[10][0];  /* 02000078 */
void* isp_irq_spare = (void*)&task_stack[11][0];  /* 0200007C */
/* 02000080 */
/* stack pointers for two interrupts the game does not take (provisional name) */
void* isp_unused[2] = {
    (void*)&task_stack[12][0],
    (void*)&task_stack[13][0],
};
void* isp_exception = (void*)&task_stack[14][0];  /* 02000088 */
void* isp_frt_compare = (void*)&task_stack[15][0];  /* 0200008C */
void* isp_frt_overflow = (void*)&task_stack[16][0];  /* 02000090 */
u8 test_flag = 0;  /* 02000094 */
/* 02000095 */
/* Stored after test_flag. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of test_flag. */
u8 test_flag_tail[27] = {
    0, 0, 0, 77, 97, 121, 32, 49, 50, 32, 49, 57, 57, 57, 0, 48,
    54, 58, 50, 57, 58, 48, 52, 0, 0, 0, 0,
};

/* 020000B0 */
TM_STRING insert_coin_mes[9] = {
    { 0, 0, 0x12, (void*)str_INSERT_COIN },
    { 0, 0, 0x12, (void*)str_INSERT_COINS },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_2 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_3 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_4 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_5 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_6 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_7 },
    { 0, 0, 0x12, (void*)str_INSERT_COINS_8 },
};
/* 0200011C */
TM_STRING warning_mes[9][11] = {
    { { 0x13, 2, 2, (void*)(str_WARNING) }, { 2, 4, 2, (void*)(str_This_game_is_for_use_in_japan_on) }, { 2, 6, 2, (void*)(str_Sales_export_or_operation_outsid) }, { 2, 8, 2, (void*)(str_country_may_be_construed_as_copy) }, { 2, 0xA, 2, (void*)(str_and_trademark_infringement_and_i) }, { 2, 0xC, 2, (void*)(str_prohibited) }, { 2, 0xE, 2, (void*)(str_Violators_are_subject_to_severe_) }, { 2, 0x10, 2, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 2, 0x12, 2, (void*)(str_of_the_law) }, { 2, 0x14, 2, (void*)(str_blank_2) }, { 2, 0x16, 2, (void*)(str_blank_2) } },
    { { 0x13, 2, 4, (void*)(str_WARNING) }, { 2, 4, 4, (void*)(str_This_game_is_for_use_in_the_sout) }, { 2, 6, 4, (void*)(str_Asian_countries_only) }, { 2, 8, 4, (void*)(str_Sales_export_or_operation_outsid_2) }, { 2, 0xA, 4, (void*)(str_countries_may_be_construed_as_co) }, { 2, 0xC, 4, (void*)(str_trademark_infringement_and_is_st) }, { 2, 0xE, 4, (void*)(str_prohibited) }, { 2, 0x10, 4, (void*)(str_Violators_are_subject_to_severe_) }, { 2, 0x12, 4, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 2, 0x14, 4, (void*)(str_of_the_law) }, { 2, 0x16, 4, (void*)(str_blank_2) } },
    { { 0x13, 2, 6, (void*)(str_WARNING) }, { 1, 4, 6, (void*)(str_This_game_is_for_use_in_the_Euro) }, { 1, 6, 6, (void*)(str_only) }, { 1, 8, 6, (void*)(str_Sales_export_or_operation_outsid_2) }, { 1, 0xA, 6, (void*)(str_countries_may_be_construed_as_co) }, { 1, 0xC, 6, (void*)(str_trademark_infringement_and_is_st) }, { 1, 0xE, 6, (void*)(str_prohibited) }, { 1, 0x10, 6, (void*)(str_Violators_are_subject_to_severe_) }, { 1, 0x12, 6, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 1, 0x14, 6, (void*)(str_of_the_law) }, { 1, 0x16, 6, (void*)(str_blank_2) } },
    { { 0x13, 2, 8, (void*)(str_WARNING) }, { 2, 4, 8, (void*)(str_This_game_is_for_use_in_the_Unit) }, { 2, 6, 8, (void*)(str_of_America_and_Canada_only) }, { 2, 8, 8, (void*)(str_Sales_export_or_operation_outsid_2) }, { 2, 0xA, 8, (void*)(str_countries_may_be_construed_as_co) }, { 2, 0xC, 8, (void*)(str_trademark_infringement_and_is_st) }, { 2, 0xE, 8, (void*)(str_prohibited) }, { 2, 0x10, 8, (void*)(str_Violators_are_subject_to_severe_) }, { 2, 0x12, 8, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 2, 0x14, 8, (void*)(str_of_the_law) }, { 2, 0x16, 8, (void*)(str_blank_2) } },
    { { 0x13, 2, 0xA, (void*)(str_WARNING) }, { 1, 4, 0xA, (void*)(str_This_game_is_for_use_in_the_West) }, { 1, 6, 0xA, (void*)(str_countries_except_the_United_Stat) }, { 1, 8, 0xA, (void*)(str_Canada_and_the_Federative_Republ) }, { 1, 0xA, 0xA, (void*)(str_Sales_export_or_operation_outsid_2) }, { 1, 0xC, 0xA, (void*)(str_countries_may_be_construed_as_co) }, { 1, 0xE, 0xA, (void*)(str_trademark_infringement_and_is_st) }, { 1, 0x10, 0xA, (void*)(str_prohibited) }, { 1, 0x12, 0xA, (void*)(str_Violators_are_subject_to_severe_) }, { 1, 0x14, 0xA, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 1, 0x16, 0xA, (void*)(str_of_the_law) } },
    { { 0x13, 2, 0xC, (void*)(str_WARNING) }, { 1, 4, 0xC, (void*)(str_This_game_is_for_use_in_the_Fede) }, { 1, 6, 0xC, (void*)(str_of_Brazil_only) }, { 1, 8, 0xC, (void*)(str_Sales_export_or_operation_outsid) }, { 1, 0xA, 0xC, (void*)(str_country_may_be_construed_as_copy_2) }, { 1, 0xC, 0xC, (void*)(str_trademark_infringement_and_is_st) }, { 1, 0xE, 0xC, (void*)(str_prohibited) }, { 1, 0x10, 0xC, (void*)(str_Violators_are_subject_to_severe_) }, { 1, 0x12, 0xC, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 1, 0x14, 0xC, (void*)(str_of_the_law) }, { 1, 0x16, 0xC, (void*)(str_blank_2) } },
    { { 0x13, 2, 0xE, (void*)(str_WARNING) }, { 1, 4, 0xE, (void*)(str_This_game_is_for_use_in_the_Ocea) }, { 1, 6, 0xE, (void*)(str_only) }, { 1, 8, 0xE, (void*)(str_Sales_export_or_operation_outsid_2) }, { 1, 0xA, 0xE, (void*)(str_countries_may_be_construed_as_co) }, { 1, 0xC, 0xE, (void*)(str_trademark_infringement_and_is_st) }, { 1, 0xE, 0xE, (void*)(str_prohibited) }, { 1, 0x10, 0xE, (void*)(str_Violators_are_subject_to_severe_) }, { 1, 0x12, 0xE, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 1, 0x14, 0xE, (void*)(str_of_the_law) }, { 1, 0x16, 0xE, (void*)(str_blank_2) } },
    { { 0x13, 2, 4, (void*)(str_WARNING) }, { 2, 4, 4, (void*)(str_This_game_is_for_use_in_the_sout) }, { 2, 6, 4, (void*)(str_Asian_countries_only) }, { 2, 8, 4, (void*)(str_Sales_export_or_operation_outsid_2) }, { 2, 0xA, 4, (void*)(str_countries_may_be_construed_as_co) }, { 2, 0xC, 4, (void*)(str_trademark_infringement_and_is_st) }, { 2, 0xE, 4, (void*)(str_prohibited) }, { 2, 0x10, 4, (void*)(str_Violators_are_subject_to_severe_) }, { 2, 0x12, 4, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 2, 0x14, 4, (void*)(str_of_the_law) }, { 2, 0x16, 4, (void*)(str_blank_2) } },
    { { 0x13, 2, 2, (void*)(str_WARNING) }, { 2, 4, 2, (void*)(str_This_game_is_for_use_in_japan_on) }, { 2, 6, 2, (void*)(str_Sales_export_or_operation_outsid) }, { 2, 8, 2, (void*)(str_country_may_be_construed_as_copy) }, { 2, 10, 2, (void*)(str_and_trademark_infringement_and_i) }, { 2, 12, 2, (void*)(str_prohibited) }, { 2, 14, 2, (void*)(str_Violators_are_subject_to_severe_) }, { 2, 16, 2, (void*)(str_and_will_be_prosecuted_to_the_fu) }, { 2, 18, 2, (void*)(str_of_the_law) }, { 2, 20, 2, (void*)(str_blank_2) }, { 2, 22, 2, (void*)(str_blank_2) } },
};
/* 0200053C */
/* The default settings rows of each cabinet type (sys_cfg_default_tbl), nine per type. */
const u8* sys_cfg_default_list[3][9] = {
    { sys_cfg_default_0_0, sys_cfg_default_0_1, sys_cfg_default_0_2, sys_cfg_default_0_3, sys_cfg_default_0_4, sys_cfg_default_0_5, sys_cfg_default_0_6, sys_cfg_default_0_7, sys_cfg_default_0_8 },
    { sys_cfg_default_1_0, sys_cfg_default_1_1, sys_cfg_default_1_2, sys_cfg_default_1_3, sys_cfg_default_1_4, sys_cfg_default_1_5, sys_cfg_default_1_6, sys_cfg_default_1_7, sys_cfg_default_1_8 },
    { sys_cfg_default_2_0, sys_cfg_default_2_1, sys_cfg_default_2_2, sys_cfg_default_2_3, sys_cfg_default_2_4, sys_cfg_default_2_5, sys_cfg_default_2_6, sys_cfg_default_2_7, sys_cfg_default_2_8 },
};

/* 0200062C */
u32 sys_cfg_default_tbl[3] = {
    (u32)sys_cfg_default_list[0], (u32)sys_cfg_default_list[1], (u32)sys_cfg_default_list[2],
};
/* 02000638 */
void* game_cfg_default_tbl[9] = {
    (void*)(game_cfg_default_tbl_row0),
    (void*)(game_cfg_default_tbl_row1),
    (void*)(game_cfg_default_tbl_row2),
    (void*)(game_cfg_default_tbl_row3),
    (void*)(game_cfg_default_tbl_row4),
    (void*)(game_cfg_default_tbl_row5),
    (void*)(game_cfg_default_tbl_row6),
    (void*)(game_cfg_default_tbl_row7),
    (void*)(game_cfg_default_tbl_row8),
};
/* Stored after game_cfg_default_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of game_cfg_default_tbl. */
u32 game_cfg_default_tbl_tail[1] = {
    65536,
};

s8 Monitor_Flip_Old = 0;  /* 02000660 */
/* 02000664 */
void* Follow_Menu_1st_Unit_Data[13] = {
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_2),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_1st_Unit_Data_0),
};
/* 02000698 */
void* Follow_Menu_2nd_Unit_Data[13] = {
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_2),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
    (void*)((const u8*)Follow_Menu_2nd_Unit_Data_0),
};
/* 020006CC */
/* Stored after Follow_Menu_2nd_Unit_Data. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Follow_Menu_2nd_Unit_Data. */
u32 Follow_Menu_2nd_Unit_Data_tail[72] = {
    0x130008, 0xE0000, (u32)str_Q_SOUND, 0x100008,
    0xE0000, (u32)str_EYE_CATCH_Part1, 0x100008, 0xE0000,
    (u32)str_EYE_CATCH_Part2, 0xE0008, 0xE0000, (u32)str_STREET_FIGHTER_III_2,
    0x120013, 0xE0000, (u32)str_199X_CAPCOM, 0x100008,
    0xE0000, (u32)str_PLAY_DEMO, 0x100008, 0xE0000,
    (u32)str_RANKING, 0x100008, 0xE0000, (u32)str_FBI,
    0x1B0008, 0xE0000, (u32)str_Q_SOUND, 0x180008,
    0xE0000, (u32)str_EYE_CATCH_Part1, 0x180008, 0xE0000,
    (u32)str_EYE_CATCH_Part2, 0x160008, 0xE0000, (u32)str_STREET_FIGHTER_III_2,
    0x180013, 0xE0000, (u32)str_199X_CAPCOM, 0x180008,
    0xE0000, (u32)str_PLAY_DEMO, 0x180008, 0xE0000,
    (u32)str_RANKING, 0x180008, 0xE0000, (u32)str_FBI,
    0x100008, 0xE0000, (u32)str_SELECT_PLAYER, 0x180008,
    0xE0000, (u32)str_SELECT_PLAYER_2, 0x12000D, 0xE0000,
    (u32)str_INSERT_COIN_2, 0x12000D, 0xE0000, (u32)str_blank_3,
    0xB000C, 0xE0000, (u32)str_PUSH_1_OR_2_START_BUTTON, 0x1A000D,
    0xE0000, (u32)str_INSERT_COIN_2, 0x1A000D, 0xE0000,
    (u32)str_blank_3, 0x13000C, 0xE0000, (u32)str_PUSH_1_OR_2_START_BUTTON,
};

/* 020007EC */
TMSCRIPT gcfg_guide_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_guide_scr_jp_0) },
};
/* 020007F4 */
TMSCRIPT gcfg_exit_guide_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_exit_guide_scr_jp_0) },
};
/* 020007FC */
TMSCRIPT gcfg_screen_scr_jp[2] = {
    { 1, 0, (void*)((const u8*)gcfg_screen_scr_jp_0) },
    { 1, 0, (void*)((const u8*)gcfg_screen_scr_jp_1) },
};
/* 0200080C */
TMSCRIPT gcfg_round_scr_jp[4] = {
    { 1, 0, (void*)((const u8*)gcfg_round_scr_jp_0) },
    { 1, 0, (void*)((const u8*)gcfg_round_scr_jp_1) },
    { 1, 0, (void*)((const u8*)gcfg_round_scr_jp_2) },
    { 1, 0, (void*)((const u8*)gcfg_round_scr_jp_3) },
};
/* 0200082C */
TMSCRIPT gcfg_event_scr_jp[2] = {
    { 1, 0, (void*)((const u8*)gcfg_event_scr_jp_0) },
    { 1, 0, (void*)((const u8*)gcfg_event_scr_jp_1) },
};
/* 0200083C */
TMSCRIPT gcfg_bonus_scr_jp[2] = {
    { 1, 0, (void*)((const u8*)gcfg_bonus_scr_jp_0) },
    { 1, 0, (void*)((const u8*)gcfg_bonus_scr_jp_1) },
};
/* 0200084C */
TMSCRIPT gcfg_cursor_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_cursor_scr_jp_0) },
};
/* 02000854 */
TMSCRIPT gcfg_cursor_clr_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_cursor_clr_scr_jp_0) },
};
/* 0200085C */
TMSCRIPT gcfg_gauge_scr_jp[8] = {
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_0) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_1) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_2) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_3) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_4) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_5) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_6) },
    { 1, 0, (void*)((const u8*)gcfg_gauge_scr_jp_7) },
};
/* 0200089C */
TMSCRIPT gcfg_gauge_clr_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_gauge_clr_scr_jp_0) },
};
/* 020008A4 */
TMSCRIPT gcfg_title_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)gcfg_title_scr_jp_0) },
};
/* 020008AC */
TM_STRING gcfg_screen_str_en[2] = {
    { 2, 0, 2, (void*)str_NORMAL_2 },
    { 2, 0, 2, (void*)str_WIDE },
};
/* 020008C4 */
TM_STRING gcfg_round_str_en[4] = {
    { 2, 0, 2, (void*)str_1_ROUND },
    { 2, 0, 2, (void*)str_3_ROUNDS },
    { 2, 0, 2, (void*)str_5_ROUNDS },
    { 2, 0, 2, (void*)str_7_ROUNDS },
};
/* 020008F4 */
TM_STRING gcfg_event_str_en[2] = {
    { 2, 0, 2, (void*)str_OFF },
    { 2, 0, 2, (void*)str_1_MATCH },
};
/* 0200090C */
TM_STRING gcfg_bonus_str_en[2] = {
    { 2, 0, 2, (void*)str_OFF_2 },
    { 2, 0, 2, (void*)str_ON },
};
/* 02000924 */
void* dbg_sign_str[2] = {
    (void*)&dbg_wca_str[4],
    (void*)&dbg_wca_str[8],
};
/* 0200092C */
s16 dbg_rgb_preset_tbl[8][3] = {
    { 0, 0, 0 }, { 127, 0, 0 }, { 127, 127, 127 }, { 127, 127, 0 }, { 127, 0, 127 }, { 0, 127, 0 }, { 0, 0, 127 }, { 112, 112, 112 },
};
/* 0200095C */
TM_STRING dbg_menu_str[15] = {
    { 0xD, 2, 2, (void*)str_OBJECT_TEST },
    { 0xA, 4, 2, (void*)str_BG_SELECT },
    { 0xA, 5, 2, (void*)str_OBJECT_LOOK },
    { 0xA, 6, 2, (void*)str_OBJECT_EDIT },
    { 0xA, 7, 2, (void*)str_OBJECT_EDIT_2 },
    { 0xA, 8, 2, (void*)str_HIT },
    { 0xA, 9, 2, (void*)str_ALL_CHARACTER },
    { 0xA, 0xA, 2, (void*)str_PARTS },
    { 0xA, 0xB, 2, (void*)str_YOKOYAMA },
    { 0xA, 0xC, 2, (void*)str_NAKAI },
    { 0xA, 0xD, 2, (void*)str_YOSHIZUMI },
    { 0xA, 0xE, 2, (void*)str_YU },
    { 0xA, 0xF, 2, (void*)str_RAOH },
    { 0xA, 0x10, 2, (void*)str_INE },
    { 0xA, 0x11, 2, (void*)str_OHYA },
};
/* 02000A10 */
TM_STRING dbg_select_exit_str[2] = {
    { 0x11, 3, 2, (void*)str_SELECT_UP_DOWN },
    { 0x11, 4, 2, (void*)str_EXIT_1P_2P_START },
};
/* 02000A28 */
TM_STRING dbg_obj_info_str[10] = {
    { 1, 3, 2, (void*)str_PLAYER },
    { 1, 4, 2, (void*)str_ALL },
    { 1, 6, 2, (void*)str_MOTION },
    { 1, 8, 2, (void*)str_PATTERN },
    { 1, 9, 2, (void*)str_INTERRUT },
    { 1, 0xA, 2, (void*)str_CODE_H },
    { 1, 0xB, 2, (void*)str_FLIP },
    { 1, 0xC, 2, (void*)str_FLIP_ED },
    { 1, 0xD, 2, (void*)str_POS_X_H },
    { 1, 0xE, 2, (void*)str_POS_Y_H },
};
/* 02000AA0 */
TM_STRING dbg_obj_rel_str[3] = {
    { 1, 0xF, 2, (void*)str_REL_X_H },
    { 1, 0x10, 2, (void*)str_REL_Y_H },
    { 1, 0x11, 2, (void*)str_CURRENT },
};
/* 02000AC4 */
TM_STRING dbg_all_char_str[7] = {
    { 0xF, 1, 2, (void*)str_ALL_CHARACTER },
    { 1, 5, 2, (void*)str_H_n },
    { 1, 7, 2, (void*)str_H_n },
    { 4, 0xB, 2, (void*)str_GROUP },
    { 4, 0xC, 2, (void*)str_R_n },
    { 4, 0xD, 2, (void*)str_G },
    { 4, 0xE, 2, (void*)str_B },
};
/* 02000B18 */
TM_STRING dbg_edit_num_str[4] = {
    { 1, 0x12, 2, (void*)str_EDIT_NUM },
    { 1, 0x13, 2, (void*)str_NUM_END },
    { 1, 0x14, 2, (void*)str_EDIT_INT },
    { 1, 0x15, 2, (void*)str_INT_END },
};
/* 02000B48 */
TM_STRING dbg_parts_info_str[17] = {
    { 1, 3, 2, (void*)str_PLAYER },
    { 1, 4, 2, (void*)str_ALL },
    { 1, 6, 2, (void*)str_MOTION },
    { 1, 8, 2, (void*)str_PATTERN },
    { 1, 9, 2, (void*)str_INTERRUT },
    { 1, 0xA, 2, (void*)str_CODE_H },
    { 1, 0xB, 2, (void*)str_FLIP },
    { 1, 0xC, 2, (void*)str_FLIP_ED },
    { 1, 0xD, 2, (void*)str_CURRENT_n },
    { 1, 0xE, 2, (void*)str_PARTS_X_H },
    { 1, 0xF, 2, (void*)str_PARTS_Y_H },
    { 1, 0x10, 2, (void*)str_PARTS_FL },
    { 1, 0x11, 2, (void*)str_OLC_IX },
    { 1, 0x12, 2, (void*)str_IX_1 },
    { 1, 0x13, 2, (void*)str_IX_2 },
    { 1, 0x14, 2, (void*)str_IX_3 },
    { 1, 0x15, 2, (void*)str_IX_4 },
};
/* 02000C14 */
TM_STRING dbg_rec_menu_str[3] = {
    { 0x1B, 3, 6, (void*)str_DELETE_ALL_SH4 },
    { 0x1B, 4, 6, (void*)str_1DATA_SH5 },
    { 0x1B, 5, 6, (void*)str_CANCEL_SH6 },
};
/* 02000C38 */
TM_STRING dbg_rec_clear_str[3] = {
    { 0x1B, 3, 6, (void*)str_n },
    { 0x1B, 4, 6, (void*)str_n },
    { 0x1B, 5, 6, (void*)str_empty },
};
/* 02000C5C */
TM_STRING dbg_rec_nodata_str[2] = {
    { 0x1B, 3, 6, (void*)str_NO_EDIT },
    { 0x1B, 4, 6, (void*)str_DATA_NOTHING },
};
/* 02000C74 */
TM_STRING dbg_hit_size_str[18] = {
    { 1, 0xF, 2, (void*)str_REVISE_X_H },
    { 1, 0x10, 2, (void*)str_SIZE_X_H },
    { 1, 0x11, 2, (void*)str_REVISE_Y_H },
    { 1, 0x12, 2, (void*)str_SIZE_Y_H },
    { 1, 0x14, 2, (void*)str_IX_000 },
    { 1, 0x15, 2, (void*)str_CR_1P },
    { 1, 0x17, 2, (void*)str_MF },
    { 1, 0x18, 2, (void*)str_M_B },
    { 8, 0x14, 2, (void*)str_BOD_000 },
    { 8, 0x15, 2, (void*)str_BHA_000 },
    { 8, 0x16, 2, (void*)str_HAN_000 },
    { 8, 0x17, 2, (void*)str_CAT_000 },
    { 8, 0x18, 2, (void*)str_CAU_000 },
    { 8, 0x19, 2, (void*)str_ATT_000 },
    { 8, 0x1A, 2, (void*)str_HOS_000 },
    { 0xF, 0x19, 2, (void*)str_KOC_IX_PT_Nix_n },
    { 0xF, 0x1A, 2, (void*)str_KOC_IX_PT_Nix_n },
    { 0xF, 0x1B, 2, (void*)str_KOC_IX_PT_Nix },
};
/* 02000D4C */
TM_STRING dbg_hit_part_str[15] = {
    { 0x28, 0xC, 2, (void*)str_HEAD },
    { 0x28, 0xD, 2, (void*)str_BREAST },
    { 0x28, 0xE, 2, (void*)str_TRUNK },
    { 0x28, 0xF, 2, (void*)str_LEG },
    { 0x28, 0x10, 2, (void*)str_HAND },
    { 0x28, 0x11, 2, (void*)str_HAND },
    { 0x28, 0x12, 2, (void*)str_HAND },
    { 0x28, 0x13, 2, (void*)str_HAND },
    { 0x28, 0x14, 2, (void*)str_CATCH_n },
    { 0x28, 0x15, 2, (void*)str_CAUGHT_n },
    { 0x28, 0x16, 2, (void*)str_ATT },
    { 0x28, 0x17, 2, (void*)str_ATT },
    { 0x28, 0x18, 2, (void*)str_ATT_2 },
    { 0x28, 0x19, 2, (void*)str_ATT_2 },
    { 0x28, 0x1A, 2, (void*)str_HOSEI },
};
/* 02000E00 */
TM_STRING dbg_work_empty_str[2] = {
    { 0xF, 5, 8, (void*)str_WORK_EMPTY },
    { 0xF, 7, 8, (void*)str_PRESS_ANY_SHOT },
};
/* 02000E18 */
TM_STRING dbg_blank4_str[4] = {
    { 0xB, 5, 2, (void*)str_n_2 },
    { 0xB, 6, 2, (void*)str_n_2 },
    { 0xB, 7, 2, (void*)str_n_2 },
    { 0xB, 8, 2, (void*)str_empty_2 },
};
/* 02000E48 */
TM_STRING dbg_exit_ok_str[3] = {
    { 0xE, 5, 2, (void*)str_EXIT_OK },
    { 0xB, 7, 2, (void*)str_YES_2P_SHOT6 },
    { 0xB, 8, 2, (void*)str_NO_1P_SHOT6 },
};
/* 02000E6C */
TM_STRING dbg_cg_head_str[6] = {
    { 0x1B, 3, 2, (void*)str_CG_CTR },
    { 0x1B, 4, 2, (void*)str_CG_TYPE },
    { 0x1B, 5, 2, (void*)str_CG_SE },
    { 0x1B, 6, 2, (void*)str_CG_FLIP },
    { 0x1B, 7, 2, (void*)str_CG_OLC_IX },
    { 0x1B, 8, 2, (void*)str_CG_NUMBER },
};
/* 02000EB4 */
TM_STRING dbg_cg_att_str[6] = {
    { 0x1B, 0xA, 2, (void*)str_CG_ATT_IX },
    { 0x1B, 0xB, 2, (void*)str_CG_HIT_IX },
    { 0x1B, 0xC, 2, (void*)str_CG_EXTDAT },
    { 0x1B, 0xD, 2, (void*)str_CG_CANCEL },
    { 0x1B, 0xE, 2, (void*)str_CG_EFFECT },
    { 0x1B, 0xF, 2, (void*)str_CG_EFTYPE },
};
/* 02000EFC */
TM_STRING dbg_cg_rival_str[4] = {
    { 0x1B, 0x10, 2, (void*)str_CG_RIVAL },
    { 0x1B, 0x11, 2, (void*)str_CG_ADD_XY },
    { 0x1B, 0x12, 2, (void*)str_CG_NIX },
    { 0x1B, 0x13, 2, (void*)str_CG_STATUS },
};
/* 02000F2C */
TM_STRING dbg_cgd_info_str[8] = {
    { 0x1B, 2, 2, (void*)str_CGD_TYPE },
    { 0x1B, 3, 2, (void*)str_PAT_ST },
    { 0x1B, 4, 2, (void*)str_KIND_WAZA },
    { 0x1B, 5, 2, (void*)str_HIT_RANGE },
    { 0x1B, 6, 2, (void*)str_YOKE_TYPE },
    { 0x1B, 7, 2, (void*)str_YOKE_PAT },
    { 0x1B, 8, 2, (void*)str_SP_TECH },
    { 0x1B, 9, 2, (void*)str_WCA_IX },
};
/* 02000F8C */
TM_STRING dbg_att_data_str[21] = {
    { 0x1B, 2, 2, (void*)str_ATT_IX },
    { 0x1B, 3, 2, (void*)str_REACTION },
    { 0x1B, 4, 2, (void*)str_MKH_IX },
    { 0x1B, 5, 2, (void*)str_DIP },
    { 0x1B, 6, 2, (void*)str_HISS },
    { 0x1B, 7, 2, (void*)str_DIR },
    { 0x1B, 8, 2, (void*)str_GUARD },
    { 0x1B, 9, 2, (void*)str_POW },
    { 0x1B, 0xA, 2, (void*)str_IMPACT },
    { 0x1B, 0xB, 2, (void*)str_PIYO_n },
    { 0x1B, 0xC, 2, (void*)str_NG_TYPE },
    { 0x1B, 0xD, 2, (void*)str_HS_ME },
    { 0x1B, 0xE, 2, (void*)str_HS_YOU },
    { 0x1B, 0xF, 2, (void*)str_ZU_FLAG },
    { 0x1B, 0x10, 2, (void*)str_ZOKUSEI },
    { 0x1B, 0x11, 2, (void*)str_AT_LEVEL },
    { 0x1B, 0x12, 2, (void*)str_ADD_ARTS },
    { 0x1B, 0x13, 2, (void*)str_BUTT_TYPE },
    { 0x1B, 0x14, 2, (void*)str_BUTT_PAT },
    { 0x1B, 0x15, 2, (void*)str_DIR_ATT },
    { 0x1B, 0x16, 2, (void*)str_VS_ID },
};
/* 02001088 */
TM_STRING dbg_hud_clr_str[26] = {
    { 0x1B, 2, 2, (void*)str_n_3 },
    { 0x1B, 3, 2, (void*)str_n_3 },
    { 0x1B, 4, 2, (void*)str_n_3 },
    { 0x1B, 5, 2, (void*)str_n_3 },
    { 0x1B, 6, 2, (void*)str_n_3 },
    { 0x1B, 7, 2, (void*)str_n_3 },
    { 0x1B, 8, 2, (void*)str_n_3 },
    { 0x1B, 9, 2, (void*)str_n_3 },
    { 0x1B, 0xA, 2, (void*)str_n_3 },
    { 0x1B, 0xB, 2, (void*)str_n_3 },
    { 0x1B, 0xC, 2, (void*)str_n_3 },
    { 0x1B, 0xD, 2, (void*)str_n_3 },
    { 0x1B, 0xE, 2, (void*)str_n_3 },
    { 0x1B, 0xF, 2, (void*)str_n_3 },
    { 0x1B, 0x10, 2, (void*)str_n_3 },
    { 0x1B, 0x11, 2, (void*)str_n_3 },
    { 0x1B, 0x12, 2, (void*)str_n_3 },
    { 0x1B, 0x13, 2, (void*)str_n_3 },
    { 0x1B, 0x14, 2, (void*)str_n_3 },
    { 0x1B, 0x15, 2, (void*)str_n_3 },
    { 0x1B, 0x16, 2, (void*)str_n_3 },
    { 0x1B, 0x17, 2, (void*)str_n_3 },
    { 0x1B, 0x18, 2, (void*)str_n_3 },
    { 0x1B, 0x19, 2, (void*)str_n_3 },
    { 0x1B, 0x1A, 2, (void*)str_n_3 },
    { 0x1B, 0x1B, 2, (void*)str_empty_3 },
};
/* 020011C0 */
TM_STRING dbg_hud_clr_mid_str[6] = {
    { 0x1B, 0xE, 2, (void*)str_n_3 },
    { 0x1B, 0xF, 2, (void*)str_n_3 },
    { 0x1B, 0x10, 2, (void*)str_n_3 },
    { 0x1B, 0x11, 2, (void*)str_n_3 },
    { 0x1B, 0x12, 2, (void*)str_n_3 },
    { 0x1B, 0x13, 2, (void*)str_n_3 },
};
/* 02001208 */
TM_STRING dbg_hud_clr_low_str[9] = {
    { 0x1B, 0x14, 2, (void*)str_n_3 },
    { 0x1B, 0x15, 2, (void*)str_n_3 },
    { 0x1B, 0x16, 2, (void*)str_n_3 },
    { 0x1B, 0x17, 2, (void*)str_n_3 },
    { 0x1B, 0x18, 2, (void*)str_n_3 },
    { 0x1B, 0x19, 2, (void*)str_n_3 },
    { 0x1B, 0x1A, 2, (void*)str_n_3 },
    { 0x1B, 0x1B, 2, (void*)str_empty_3 },
    { 0x1B, 0x1C, 2, (void*)str_empty_3 },
};
/* 02001274 */
TM_STRING dbg_hud_clr_bottom_str[3] = {
    { 5, 0x19, 2, (void*)str_n_4 },
    { 5, 0x1A, 2, (void*)str_n_4 },
    { 5, 0x1B, 2, (void*)str_empty_4 },
};
/* 02001298 */
TM_STRING dbg_cm_label_str[13] = {
    { 0x1B, 2, 2, (void*)str_CMOA },
    { 0x1B, 3, 2, (void*)str_CMSW },
    { 0x1B, 4, 2, (void*)str_CMLP },
    { 0x1B, 5, 2, (void*)str_CML2 },
    { 0x1B, 6, 2, (void*)str_CMJA },
    { 0x1B, 7, 2, (void*)str_CMJ2 },
    { 0x1B, 8, 2, (void*)str_CMJ3 },
    { 0x1B, 9, 2, (void*)str_CMJ4 },
    { 0x1B, 0xA, 2, (void*)str_CMMS },
    { 0x1B, 0xB, 2, (void*)str_CMMD },
    { 0x1B, 0xC, 2, (void*)str_CMYD },
    { 0x1B, 0xD, 2, (void*)str_CMCF },
    { 0x1B, 0xE, 2, (void*)str_CMCR },
};
/* 02001334 */
TM_STRING dbg_cgd_type_str[5] = {
    { 0x25, 1, 0xA, (void*)str_WCA },
    { 0x25, 2, 0xA, (void*)str_CGD1 },
    { 0x25, 2, 0xA, (void*)str_CGD2 },
    { 0x25, 2, 0xA, (void*)str_CGD3 },
    { 0x25, 2, 0xA, (void*)str_empty_5 },
};
/* 02001370 */
TM_STRING dbg_pat_status_str[23] = {
    { 0x25, 3, 0xA, (void*)str_sl_00 },
    { 0x25, 3, 0xA, (void*)str_sl_10 },
    { 0x25, 3, 0xA, (void*)str_sl_12 },
    { 0x25, 3, 0xA, (void*)str_sl_20 },
    { 0x25, 3, 0xA, (void*)str_sl_22 },
    { 0x25, 3, 0xA, (void*)str_sl_30 },
    { 0x25, 3, 0xA, (void*)str_sl_32 },
    { 0x25, 3, 0xA, (void*)str_sl_40 },
    { 0x25, 3, 0xA, (void*)str_sl_42 },
    { 0x25, 3, 0xA, (void*)str_sl_44 },
    { 0x25, 3, 0xA, (void*)str_sl_50 },
    { 0x25, 3, 0xA, (void*)str_sl_52 },
    { 0x25, 3, 0xA, (void*)str_sl_54 },
    { 0x25, 3, 0xA, (void*)str_sl_60 },
    { 0x25, 3, 0xA, (void*)str_sl_62 },
    { 0x25, 3, 0xA, (void*)str_sl_64 },
    { 0x25, 3, 0xA, (void*)str_sl_70 },
    { 0x25, 3, 0xA, (void*)str_sl_80 },
    { 0x25, 3, 0xA, (void*)str_sl_82 },
    { 0x25, 3, 0xA, (void*)str_sl_90 },
    { 0x25, 3, 0xA, (void*)str_empty_6 },
    { 0x25, 3, 0xA, (void*)str_empty_6 },
    { 0x25, 3, 0xA, (void*)str_empty_6 },
};
/* 02001484 */
TM_STRING dbg_extdat_str[3] = {
    { 0x25, 0xC, 0xA, (void*)str_Pa },
    { 0x25, 0xC, 0xA, (void*)str_PA },
    { 0x25, 0xC, 0xA, (void*)str_PB },
};
/* 020014A8 */
TM_STRING dbg_eftype_names[9] = {
    { 0x25, 0xF, 0xA, (void*)str_MLN },
    { 0x25, 0xF, 0xA, (void*)str_MLU },
    { 0x25, 0xF, 0xA, (void*)str_MLD },
    { 0x25, 0xF, 0xA, (void*)str_MLF },
    { 0x25, 0xF, 0xA, (void*)str_MLF },
    { 0x25, 0xF, 0xA, (void*)str_MLR },
    { 0x25, 0xF, 0xA, (void*)str_MLR },
    { 0x25, 0xF, 0xA, (void*)str_MLR },
    { 0x25, 0xF, 0xA, (void*)str_M },
};
/* 02001514 */
TM_STRING dbg_eftype_s_str[6] = {
    { 0x28, 0xF, 0xA, (void*)str_S1 },
    { 0x28, 0xF, 0xA, (void*)str_S2 },
    { 0x28, 0xF, 0xA, (void*)str_S3 },
    { 0x28, 0xF, 0xA, (void*)str_S4 },
    { 0x28, 0xF, 0xA, (void*)str_S5 },
    { 0x28, 0xF, 0xA, (void*)str_S6 },
};
/* 0200155C */
TM_STRING dbg_eftype_usemj_str[8] = {
    { 0x2A, 0xF, 0xA, (void*)str_empty_7 },
    { 0x2A, 0xF, 0xA, (void*)str_USEMJ },
    { 0x25, 0x18, 0xA, (void*)str_BASE },
    { 0x25, 0x18, 0xA, (void*)str_BEFORE },
    { 0x25, 0x18, 0xA, (void*)str_BACK },
    { 0x25, 0x18, 0xA, (void*)str_empty_7 },
    { 0x25, 0x18, 0xA, (void*)str_empty_7 },
    { 0x25, 0x18, 0xA, (void*)str_empty_7 },
};
/* 020015BC */
TM_STRING dbg_cancel_on_str[8] = {
    { 0x2C, 0xD, 0xA, (void*)str_H },
    { 0x2B, 0xD, 0xA, (void*)str_D },
    { 0x2A, 0xD, 0xA, (void*)str_A },
    { 0x29, 0xD, 0xA, (void*)str_M_2 },
    { 0x28, 0xD, 0xA, (void*)str_R },
    { 0x27, 0xD, 0xA, (void*)str_C },
    { 0x26, 0xD, 0xA, (void*)str_S },
    { 0x25, 0xD, 0xA, (void*)str_S },
};
/* 0200161C */
TM_STRING dbg_cancel_off_str[24] = {
    { 0x2C, 0xD, 0xA, (void*)str_h },
    { 0x2B, 0xD, 0xA, (void*)str_d },
    { 0x2A, 0xD, 0xA, (void*)str_a },
    { 0x29, 0xD, 0xA, (void*)str_m },
    { 0x28, 0xD, 0xA, (void*)str_r },
    { 0x27, 0xD, 0xA, (void*)str_c },
    { 0x26, 0xD, 0xA, (void*)str_s },
    { 0x25, 0xD, 0xA, (void*)str_s },
    { 0x25, 0x11, 0xA, (void*)str_H },
    { 0x26, 0x11, 0xA, (void*)str_D },
    { 0x27, 0x11, 0xA, (void*)str_A },
    { 0x28, 0x11, 0xA, (void*)str_M_2 },
    { 0x29, 0x11, 0xA, (void*)str_R },
    { 0x2A, 0x11, 0xA, (void*)str_C },
    { 0x2B, 0x11, 0xA, (void*)str_S },
    { 0x2C, 0x11, 0xA, (void*)str_S },
    { 0x25, 0x11, 0xA, (void*)str_h_2 },
    { 0x26, 0x11, 0xA, (void*)str_d_2 },
    { 0x27, 0x11, 0xA, (void*)str_a_2 },
    { 0x28, 0x11, 0xA, (void*)str_m_2 },
    { 0x29, 0x11, 0xA, (void*)str_r_2 },
    { 0x2A, 0x11, 0xA, (void*)str_c_2 },
    { 0x2B, 0x11, 0xA, (void*)str_s_2 },
    { 0x2C, 0x11, 0xA, (void*)str_s_2 },
};
/* 0200173C */
TM_STRING dbg_koc_cmlp_str[11] = {
    { 0xC, 0x19, 0xA, (void*)str_NM },
    { 0xC, 0x19, 0xA, (void*)str_DM },
    { 0xC, 0x19, 0xA, (void*)str_CA },
    { 0xC, 0x19, 0xA, (void*)str_CU },
    { 0xC, 0x19, 0xA, (void*)str_AT },
    { 0xC, 0x19, 0xA, (void*)str_BT },
    { 0xC, 0x19, 0xA, (void*)str_EX },
    { 0xC, 0x19, 0xA, (void*)str_SA },
    { 0x20, 0x19, 0xA, (void*)str_CB },
    { 0x20, 0x19, 0xA, (void*)str_empty_8 },
    { 0x20, 0x19, 0xA, (void*)str_empty_8 },
};
/* 020017C0 */
TM_STRING dbg_koc_cml2_str[11] = {
    { 0xC, 0x1A, 0xA, (void*)str_NM },
    { 0xC, 0x1A, 0xA, (void*)str_DM },
    { 0xC, 0x1A, 0xA, (void*)str_CA },
    { 0xC, 0x1A, 0xA, (void*)str_CU },
    { 0xC, 0x1A, 0xA, (void*)str_AT },
    { 0xC, 0x1A, 0xA, (void*)str_BT },
    { 0xC, 0x1A, 0xA, (void*)str_EX },
    { 0xC, 0x1A, 0xA, (void*)str_SA },
    { 0x20, 0x1A, 0xA, (void*)str_CB },
    { 0x20, 0x1A, 0xA, (void*)str_empty_8 },
    { 0x20, 0x1A, 0xA, (void*)str_empty_8 },
};
/* 02001844 */
TM_STRING dbg_koc_cmsw_str[11] = {
    { 0x20, 0x19, 0xA, (void*)str_NM },
    { 0x20, 0x19, 0xA, (void*)str_DM },
    { 0x20, 0x19, 0xA, (void*)str_CA },
    { 0x20, 0x19, 0xA, (void*)str_CU },
    { 0x20, 0x19, 0xA, (void*)str_AT },
    { 0x20, 0x19, 0xA, (void*)str_SA },
    { 0x20, 0x19, 0xA, (void*)str_BT },
    { 0x20, 0x19, 0xA, (void*)str_EX },
    { 0x20, 0x19, 0xA, (void*)str_CB },
    { 0x20, 0x19, 0xA, (void*)str_empty_8 },
    { 0x20, 0x19, 0xA, (void*)str_empty_8 },
};
/* 020018C8 */
TM_STRING dbg_koc_cmja_str[11] = {
    { 0x20, 0x1A, 0xA, (void*)str_NM },
    { 0x20, 0x1A, 0xA, (void*)str_DM },
    { 0x20, 0x1A, 0xA, (void*)str_CA },
    { 0x20, 0x1A, 0xA, (void*)str_CU },
    { 0x20, 0x1A, 0xA, (void*)str_AT },
    { 0x20, 0x1A, 0xA, (void*)str_SA },
    { 0x20, 0x1A, 0xA, (void*)str_BT },
    { 0x20, 0x1A, 0xA, (void*)str_EX },
    { 0x20, 0x1A, 0xA, (void*)str_CB },
    { 0x20, 0x1A, 0xA, (void*)str_empty_8 },
    { 0x20, 0x1A, 0xA, (void*)str_empty_8 },
};
/* 0200194C */
TM_STRING dbg_koc_cmoa_str[18] = {
    { 0x20, 0x1B, 0xA, (void*)str_NM },
    { 0x20, 0x1B, 0xA, (void*)str_DM },
    { 0x20, 0x1B, 0xA, (void*)str_CA },
    { 0x20, 0x1B, 0xA, (void*)str_CU },
    { 0x20, 0x1B, 0xA, (void*)str_AT },
    { 0x20, 0x1B, 0xA, (void*)str_SA },
    { 0x20, 0x1B, 0xA, (void*)str_BT },
    { 0x20, 0x1B, 0xA, (void*)str_EX },
    { 0x20, 0x1B, 0xA, (void*)str_CB },
    { 0x20, 2, 2, (void*)str_NM },
    { 0x20, 2, 2, (void*)str_DM },
    { 0x20, 2, 2, (void*)str_CA },
    { 0x20, 2, 2, (void*)str_CU },
    { 0x20, 2, 2, (void*)str_AT },
    { 0x20, 2, 2, (void*)str_SA },
    { 0x20, 2, 2, (void*)str_BT },
    { 0x20, 2, 2, (void*)str_EX },
    { 0x20, 2, 2, (void*)str_CB },
};
/* 02001A24 */
TM_STRING dbg_waza_kind_str[8] = {
    { 0x25, 4, 0xA, (void*)str_nmA },
    { 0x25, 4, 0xA, (void*)str_hsA },
    { 0x25, 4, 0xA, (void*)str_nmC },
    { 0x25, 4, 0xA, (void*)str_hsC },
    { 0x25, 4, 0xA, (void*)str_saA },
    { 0x25, 4, 0xA, (void*)str_saC },
    { 0x25, 4, 0xA, (void*)str_paA },
    { 0x25, 4, 0xA, (void*)str_huA },
};
/* 02001A84 */
TM_STRING dbg_bg_name_str[25] = {
    { 2, 3, 2, (void*)str_BLANK },
    { 2, 3, 2, (void*)str_FLASH },
    { 2, 3, 2, (void*)str_GILL },
    { 2, 3, 2, (void*)str_N_Y_0 },
    { 2, 3, 2, (void*)str_JAPAN_0 },
    { 2, 3, 2, (void*)str_HONGKONG_0 },
    { 2, 3, 2, (void*)str_ENGLAND },
    { 2, 3, 2, (void*)str_RUSSIA_0 },
    { 2, 3, 2, (void*)str_GERMANY },
    { 2, 3, 2, (void*)str_JAPAN_1 },
    { 2, 3, 2, (void*)str_AFRICA },
    { 2, 3, 2, (void*)str_BRAZIL },
    { 2, 3, 2, (void*)str_HONGKONG_1 },
    { 2, 3, 2, (void*)str_N_Y_1 },
    { 2, 3, 2, (void*)str_BRAZIL_1 },
    { 2, 3, 2, (void*)str_OROMEKA },
    { 2, 3, 2, (void*)str_JAPAN_20 },
    { 2, 3, 2, (void*)str_JAPAN_21 },
    { 2, 3, 2, (void*)str_CHAINA },
    { 2, 3, 2, (void*)str_JAPAN_30 },
    { 2, 3, 2, (void*)str_RUSSIA_1 },
    { 2, 3, 2, (void*)str_RUSSIA_2 },
    { 2, 3, 2, (void*)str_FRANCE },
    { 2, 3, 2, (void*)str_BONUS_1 },
    { 2, 3, 2, (void*)str_BONUS_2 },
};
/* 02001BB0 */
TM_STRING dbg_char_name_str[25] = {
    { 0xB, 3, 2, (void*)str_GILL_2 },
    { 0xB, 3, 2, (void*)str_ALEX },
    { 0xB, 3, 2, (void*)str_RYU },
    { 0xB, 3, 2, (void*)str_YUN },
    { 0xB, 3, 2, (void*)str_DUDLEY },
    { 0xB, 3, 2, (void*)str_NECRO },
    { 0xB, 3, 2, (void*)str_HUGO },
    { 0xB, 3, 2, (void*)str_IBUKI },
    { 0xB, 3, 2, (void*)str_ELENA },
    { 0xB, 3, 2, (void*)str_ORO },
    { 0xB, 3, 2, (void*)str_YANG },
    { 0xB, 3, 2, (void*)str_KEN },
    { 0xB, 3, 2, (void*)str_SEAN },
    { 0xB, 3, 2, (void*)str_URIEN },
    { 0xB, 3, 2, (void*)str_GOUKI_1 },
    { 0xB, 3, 2, (void*)str_GOUKI_2 },
    { 0xB, 3, 2, (void*)str_CHUN_LI },
    { 0xB, 3, 2, (void*)str_KARATE },
    { 0xB, 3, 2, (void*)str_Q },
    { 0xB, 3, 2, (void*)str_No_12 },
    { 0xB, 3, 2, (void*)str_BIKEI },
    { 0xB, 3, 2, (void*)str_empty_9 },
    { 0xB, 3, 2, (void*)str_empty_9 },
    { 0xB, 3, 2, (void*)str_empty_9 },
    { 0xB, 3, 2, (void*)str_ETC },
};
/* 02001CDC */
TM_STRING dbg_act_kind_str[994] = {
    { 3, 5, 4, (void*)str_NORMAL },
    { 3, 5, 4, (void*)str_DAMAGE },
    { 3, 5, 4, (void*)str_CATCH },
    { 3, 5, 4, (void*)str_CAUGHT },
    { 3, 5, 4, (void*)str_ATTACK },
    { 3, 5, 4, (void*)str_SP_AT },
    { 3, 5, 4, (void*)str_BUTTOBI },
    { 3, 5, 4, (void*)str_UNION },
    { 3, 5, 4, (void*)str_ETC },
    { 3, 5, 4, (void*)str_ETC },
    { 3, 5, 4, (void*)str_EFFECT },
    { 3, 5, 4, (void*)str_empty_9 },
    { 3, 7, 4, (void*)str_KAMAE },
    { 3, 7, 4, (void*)str_HURIMUKI },
    { 3, 7, 4, (void*)str_FRONT_WALK },
    { 3, 7, 4, (void*)str_BACK_WALK },
    { 3, 7, 4, (void*)str_DASH_HUMIKOMI },
    { 3, 7, 4, (void*)str_DASH_TOBINOKI },
    { 3, 7, 4, (void*)str_KAGAMU },
    { 3, 7, 4, (void*)str_KAGAMI_KAMAE },
    { 3, 7, 4, (void*)str_KAGAMI_TURN },
    { 3, 7, 4, (void*)str_KAGAMI_F_WALK },
    { 3, 7, 4, (void*)str_KAGAMI_B_WALK },
    { 3, 7, 4, (void*)str_STAND_UP },
    { 3, 7, 4, (void*)str_JUMP_JUNBI },
    { 3, 7, 4, (void*)str_SP_JUMP_JUNBI },
    { 3, 7, 4, (void*)str_JUMP_FRONT },
    { 3, 7, 4, (void*)str_JUMP_VERTICAL },
    { 3, 7, 4, (void*)str_JUMP_BACK },
    { 3, 7, 4, (void*)str_S_JUMP_FRONT },
    { 3, 7, 4, (void*)str_S_JUMP_V },
    { 3, 7, 4, (void*)str_S_JUMP_BACK },
    { 3, 7, 4, (void*)str_SP_JUMP_FRONT },
    { 3, 7, 4, (void*)str_SP_JUMP_V },
    { 3, 7, 4, (void*)str_SP_JUMP_BACK },
    { 3, 7, 4, (void*)str_WALK_END },
    { 3, 7, 4, (void*)str_PARING_HEAD },
    { 3, 7, 4, (void*)str_PARING_UP },
    { 3, 7, 4, (void*)str_PARING_DOWN },
    { 3, 7, 4, (void*)str_PARING_AIR_F },
    { 3, 7, 4, (void*)str_PARING_AIR_B },
    { 3, 7, 4, (void*)str_GUARD_HEAD },
    { 3, 7, 4, (void*)str_GUARD_UP },
    { 3, 7, 4, (void*)str_GUARD_DOWN },
    { 3, 7, 4, (void*)str_GUARD_AIR },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_P_BREAK_ZUJOU },
    { 3, 7, 4, (void*)str_P_BREAK_UP },
    { 3, 7, 4, (void*)str_P_BREAK_DOWN },
    { 3, 7, 4, (void*)str_P_BREAK_AIR_F },
    { 3, 7, 4, (void*)str_P_BREAK_AIR_R },
    { 3, 7, 4, (void*)str_TUKAMIHAZUSI },
    { 3, 7, 4, (void*)str_TUKAMIHAZUSARE },
    { 3, 7, 4, (void*)str_TUKAMIHAZUSI },
    { 3, 7, 4, (void*)str_TUKAMIHAZUSARE },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_GUARD_HEAD_2 },
    { 3, 7, 4, (void*)str_GUARD_UP_2 },
    { 3, 7, 4, (void*)str_GUARD_DOWN_2 },
    { 3, 7, 4, (void*)str_GUARD_AIR_2 },
    { 3, 7, 4, (void*)str_HUSHIN_HEAD },
    { 3, 7, 4, (void*)str_HUSHIN_UP },
    { 3, 7, 4, (void*)str_HUSHIN_DOWN },
    { 3, 7, 4, (void*)str_HUSHIN_AIR },
    { 3, 7, 4, (void*)str_FACE_S },
    { 3, 7, 4, (void*)str_FACE_M },
    { 3, 7, 4, (void*)str_FACE_L },
    { 3, 7, 4, (void*)str_FACE_SP },
    { 3, 7, 4, (void*)str_FOOK_OKU_S },
    { 3, 7, 4, (void*)str_FOOK_OKU_M },
    { 3, 7, 4, (void*)str_FOOK_OKU_L },
    { 3, 7, 4, (void*)str_FOOK_OKU_SP },
    { 3, 7, 4, (void*)str_FOOK_TEMAE_S },
    { 3, 7, 4, (void*)str_FOOK_TEMAE_M },
    { 3, 7, 4, (void*)str_FOOK_TEMAE_L },
    { 3, 7, 4, (void*)str_FOOK_TEMAE_SP },
    { 3, 7, 4, (void*)str_UPPER_S },
    { 3, 7, 4, (void*)str_UPPER_M },
    { 3, 7, 4, (void*)str_UPPER_L },
    { 3, 7, 4, (void*)str_UPPER_SP },
    { 3, 7, 4, (void*)str_NOUTEN_S },
    { 3, 7, 4, (void*)str_NOUTEN_M },
    { 3, 7, 4, (void*)str_NOUTEN_L },
    { 3, 7, 4, (void*)str_NOUTEN_SP },
    { 3, 7, 4, (void*)str_BODY_BROW_S },
    { 3, 7, 4, (void*)str_BODY_BROW_M },
    { 3, 7, 4, (void*)str_BODY_BROW_L },
    { 3, 7, 4, (void*)str_BODY_BROW_SP },
    { 3, 7, 4, (void*)str_BODY_UPPER_S },
    { 3, 7, 4, (void*)str_BODY_UPPER_M },
    { 3, 7, 4, (void*)str_BODY_UPPER_L },
    { 3, 7, 4, (void*)str_BODY_UPPER_SP },
    { 3, 7, 4, (void*)str_TATAKI_S },
    { 3, 7, 4, (void*)str_TATAKI_M },
    { 3, 7, 4, (void*)str_TATAKI_L },
    { 3, 7, 4, (void*)str_TATAKI_SP },
    { 3, 7, 4, (void*)str_TATAKI_V_S },
    { 3, 7, 4, (void*)str_TATAKI_V_M },
    { 3, 7, 4, (void*)str_TATAKI_V_L },
    { 3, 7, 4, (void*)str_TATAKI_V_SP },
    { 3, 7, 4, (void*)str_NOBASITA_TE_S },
    { 3, 7, 4, (void*)str_NOBASITA_TE_M },
    { 3, 7, 4, (void*)str_NOBASITA_TE_L },
    { 3, 7, 4, (void*)str_NOBASITA_TE_SP },
    { 3, 7, 4, (void*)str_KAGAMI_S },
    { 3, 7, 4, (void*)str_KAGAMI_M },
    { 3, 7, 4, (void*)str_KAGAMI_L },
    { 3, 7, 4, (void*)str_KAGAMI_SP },
    { 3, 7, 4, (void*)str_KGM_TATAKI_S },
    { 3, 7, 4, (void*)str_KGM_TATAKI_M },
    { 3, 7, 4, (void*)str_KGM_TATAKI_L },
    { 3, 7, 4, (void*)str_KGM_TATAKI_SP },
    { 3, 7, 4, (void*)str_KGM_TTKI_V_S },
    { 3, 7, 4, (void*)str_KGM_TTKI_V_M },
    { 3, 7, 4, (void*)str_KGM_TTKI_V_L },
    { 3, 7, 4, (void*)str_KGM_TTKI_V_SP },
    { 3, 7, 4, (void*)str_NEKOROBI_S },
    { 3, 7, 4, (void*)str_NEKOROBI_M },
    { 3, 7, 4, (void*)str_NEKOROBI_L },
    { 3, 7, 4, (void*)str_NEKOROBI_SP },
    { 3, 7, 4, (void*)str_OKIAGARI },
    { 3, 7, 4, (void*)str_OKIAGARI_F },
    { 3, 7, 4, (void*)str_OKIAGARI_B },
    { 3, 7, 4, (void*)str_LOSE_NO_STAND },
    { 3, 7, 4, (void*)str_LOSE_SONABA },
    { 3, 7, 4, (void*)str_LOSE_KAGAMI },
    { 3, 7, 4, (void*)str_PIYO },
    { 3, 7, 4, (void*)str_UKEMI_MOVE_F },
    { 3, 7, 4, (void*)str_UKEMI_MOVE_R },
    { 3, 7, 4, (void*)str_SHIMEOTASARE },
    { 3, 7, 4, (void*)str_TATI_TOUKETU_S },
    { 3, 7, 4, (void*)str_TATI_TOUKETU_M },
    { 3, 7, 4, (void*)str_TATI_TOUKETU_L },
    { 3, 7, 4, (void*)str_TATI_TOUKETU_P },
    { 3, 7, 4, (void*)str_KGM_TOUKETU_S },
    { 3, 7, 4, (void*)str_KGM_TOUKETU_M },
    { 3, 7, 4, (void*)str_KGM_TOUKETU_L },
    { 3, 7, 4, (void*)str_KGM_TOUKETU_P },
    { 3, 7, 4, (void*)str_TATI_DENGEKI_S },
    { 3, 7, 4, (void*)str_TATI_DENGEKI_M },
    { 3, 7, 4, (void*)str_TATI_DENGEKI_L },
    { 3, 7, 4, (void*)str_TATI_DENGEKI_P },
    { 3, 7, 4, (void*)str_KGM_DENGEKI_S },
    { 3, 7, 4, (void*)str_KGM_DENGEKI_M },
    { 3, 7, 4, (void*)str_KGM_DENGEKI_L },
    { 3, 7, 4, (void*)str_KGM_DENGEKI_P },
    { 3, 7, 4, (void*)str_OKIAGARI_FRONT },
    { 3, 7, 4, (void*)str_OKIAGARI_REAR },
    { 3, 7, 4, (void*)str_TATI_MOE_S },
    { 3, 7, 4, (void*)str_TATI_MOE_M },
    { 3, 7, 4, (void*)str_TATI_MOE_L },
    { 3, 7, 4, (void*)str_TATI_MOE_SP },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_AIR_NORMAL },
    { 3, 7, 4, (void*)str_ASIBARAI_SIRI },
    { 3, 7, 4, (void*)str_ASIB_TUNNOMERI },
    { 3, 7, 4, (void*)str_NOKEZORI },
    { 3, 7, 4, (void*)str_KUNOJI },
    { 3, 7, 4, (void*)str_KIRIMOMI },
    { 3, 7, 4, (void*)str_UPPER },
    { 3, 7, 4, (void*)str_BODY_UPPER },
    { 3, 7, 4, (void*)str_HARAYARARE },
    { 3, 7, 4, (void*)str_TATAKI_AIR },
    { 3, 7, 4, (void*)str_TTKI_V_AIR },
    { 3, 7, 4, (void*)str_HUMI_ASIB },
    { 3, 7, 4, (void*)str_FACE },
    { 3, 7, 4, (void*)str_ASIB_SIRI_LOSE },
    { 3, 7, 4, (void*)str_ASIB_TUN_LOSE },
    { 3, 7, 4, (void*)str_DENKI },
    { 3, 7, 4, (void*)str_KUNOJI_NOKE },
    { 3, 7, 4, (void*)str_BODY_UPPER_SP_2 },
    { 3, 7, 4, (void*)str_HANEAGARI },
    { 3, 7, 4, (void*)str_TOUKETSU_A },
    { 3, 7, 4, (void*)str_BODY_SLAM },
    { 3, 7, 4, (void*)str_IPPONZEOI },
    { 3, 7, 4, (void*)str_TOMOE_RYU },
    { 3, 7, 4, (void*)str_MONKEY_FLIP },
    { 3, 7, 4, (void*)str_TOMOE_ORO },
    { 3, 7, 4, (void*)str_SNAKE_FANG },
    { 3, 7, 4, (void*)str_FLANKEN_S },
    { 3, 7, 4, (void*)str_KISHINRIKI },
    { 3, 7, 4, (void*)str_SPLASH_M },
    { 3, 7, 4, (void*)str_HARAIGOSHI },
    { 3, 7, 4, (void*)str_ALEX_B_D },
    { 3, 7, 4, (void*)str_GILL_3 },
    { 3, 7, 4, (void*)str_HANEKAERI_HARA },
    { 3, 7, 4, (void*)str_S_HANEAGARI },
    { 3, 7, 4, (void*)str_TATUMAKIZANKU },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_CATCH_1 },
    { 3, 7, 4, (void*)str_CATCH_2 },
    { 3, 7, 4, (void*)str_CATCH_3 },
    { 3, 7, 4, (void*)str_CATCH_4 },
    { 3, 7, 4, (void*)str_CATCH_5 },
    { 3, 7, 4, (void*)str_CATCH_6 },
    { 3, 7, 4, (void*)str_CATCH_7 },
    { 3, 7, 4, (void*)str_CATCH_8 },
    { 3, 7, 4, (void*)str_CATCH_9 },
    { 3, 7, 4, (void*)str_CATCH_10 },
    { 3, 7, 4, (void*)str_CATCH_11 },
    { 3, 7, 4, (void*)str_CATCH_12 },
    { 3, 7, 4, (void*)str_CATCH_13 },
    { 3, 7, 4, (void*)str_CATCH_14 },
    { 3, 7, 4, (void*)str_CATCH_15 },
    { 3, 7, 4, (void*)str_CATCH_16 },
    { 3, 7, 4, (void*)str_CATCH_17 },
    { 3, 7, 4, (void*)str_CATCH_18 },
    { 3, 7, 4, (void*)str_CATCH_19 },
    { 3, 7, 4, (void*)str_CATCH_20 },
    { 3, 7, 4, (void*)str_CATCH_21 },
    { 3, 7, 4, (void*)str_CATCH_22 },
    { 3, 7, 4, (void*)str_CATCH_23 },
    { 3, 7, 4, (void*)str_CATCH_24 },
    { 3, 7, 4, (void*)str_CATCH_25 },
    { 3, 7, 4, (void*)str_CATCH_26 },
    { 3, 7, 4, (void*)str_CATCH_27 },
    { 3, 7, 4, (void*)str_CATCH_28 },
    { 3, 7, 4, (void*)str_CATCH_29 },
    { 3, 7, 4, (void*)str_CATCH_30 },
    { 3, 7, 4, (void*)str_CATCH_31 },
    { 3, 7, 4, (void*)str_CATCH_32 },
    { 3, 7, 4, (void*)str_CATCH_33 },
    { 3, 7, 4, (void*)str_CATCH_34 },
    { 3, 7, 4, (void*)str_CATCH_35 },
    { 3, 7, 4, (void*)str_CATCH_36 },
    { 3, 7, 4, (void*)str_CATCH_37 },
    { 3, 7, 4, (void*)str_CATCH_38 },
    { 3, 7, 4, (void*)str_CATCH_39 },
    { 3, 7, 4, (void*)str_CATCH_40 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_ALEX_ZUTUKI },
    { 3, 7, 4, (void*)str_ALEX_BODY_S },
    { 3, 7, 4, (void*)str_ALEX_BACK_D },
    { 3, 7, 4, (void*)str_ALEX_POWER_B },
    { 3, 7, 4, (void*)str_ALEX_SLEEPER },
    { 3, 7, 4, (void*)str_RYU_SEOINAGE },
    { 3, 7, 4, (void*)str_IBUKI_2 },
    { 3, 7, 4, (void*)str_DADLEY_L_B },
    { 3, 7, 4, (void*)str_IBUKI_KUBIORI },
    { 3, 7, 4, (void*)str_NECRO_S_T },
    { 3, 7, 4, (void*)str_RYU_TOMOENAGE },
    { 3, 7, 4, (void*)str_YUN_HIZAGERI },
    { 3, 7, 4, (void*)str_ORO_KUBISIME },
    { 3, 7, 4, (void*)str_NECRO_G_S },
    { 3, 7, 4, (void*)str_DUDDLEY_D_S },
    { 3, 7, 4, (void*)str_YUN_MONKEY_F },
    { 3, 7, 4, (void*)str_ORO_TOMOENAGE },
    { 3, 7, 4, (void*)str_ORO_NIOURIKI },
    { 3, 7, 4, (void*)str_ORO_GIGOKU_G },
    { 3, 7, 4, (void*)str_YUN_2 },
    { 3, 7, 4, (void*)str_NECRO_SNAKE_F },
    { 3, 7, 4, (void*)str_NECRO_F_S },
    { 3, 7, 4, (void*)str_IBUKI_HARAIG },
    { 3, 7, 4, (void*)str_GILL_SPLASH_M },
    { 3, 7, 4, (void*)str_KEN_HIZAGERI },
    { 3, 7, 4, (void*)str_ORO_KISINRIKI },
    { 3, 7, 4, (void*)str_SEAN_TACKLE },
    { 3, 7, 4, (void*)str_ALEX_HYPER_B },
    { 3, 7, 4, (void*)str_NECRO_SLAM_D },
    { 3, 7, 4, (void*)str_ELENA_ASINAGE },
    { 3, 7, 4, (void*)str_GILL_IMPACT_C },
    { 3, 7, 4, (void*)str_ALEX_S_H_B },
    { 3, 7, 4, (void*)str_ALEX_F_N_D },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_IBUKI_2 },
    { 3, 7, 4, (void*)str_IBUKI_YOROI_D },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_MAWARIKOMI_M_F },
    { 3, 7, 4, (void*)str_HUGO_BODY_S },
    { 3, 7, 4, (void*)str_HUGO_N_G_T },
    { 3, 7, 4, (void*)str_HUGO_M_S_P },
    { 3, 7, 4, (void*)str_HUGO_S_D_B_B },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_S_PUNCH_A },
    { 3, 7, 4, (void*)str_S_PUNCH_B },
    { 3, 7, 4, (void*)str_S_PUNCH_C },
    { 3, 7, 4, (void*)str_M_PUNCH_A },
    { 3, 7, 4, (void*)str_M_PUNCH_B },
    { 3, 7, 4, (void*)str_M_PUNCH_C },
    { 3, 7, 4, (void*)str_L_PUNCH_A },
    { 3, 7, 4, (void*)str_L_PUNCH_B },
    { 3, 7, 4, (void*)str_L_PUNCH_C },
    { 3, 7, 4, (void*)str_S_KICK_A },
    { 3, 7, 4, (void*)str_S_KICK_B },
    { 3, 7, 4, (void*)str_S_KICK_C },
    { 3, 7, 4, (void*)str_M_KICK_A },
    { 3, 7, 4, (void*)str_M_KICK_B },
    { 3, 7, 4, (void*)str_M_KICK_C },
    { 3, 7, 4, (void*)str_L_KICK_A },
    { 3, 7, 4, (void*)str_L_KICK_B },
    { 3, 7, 4, (void*)str_L_KICK_C },
    { 3, 7, 4, (void*)str_KAGAMI_P_A },
    { 3, 7, 4, (void*)str_KAGAMI_P_B },
    { 3, 7, 4, (void*)str_KAGAMI_P_C },
    { 3, 7, 4, (void*)str_KAGAMI_P_A },
    { 3, 7, 4, (void*)str_KAGAMI_P_B },
    { 3, 7, 4, (void*)str_KAGAMI_P_C },
    { 3, 7, 4, (void*)str_KAGAMI_P_A },
    { 3, 7, 4, (void*)str_KAGAMI_P_B },
    { 3, 7, 4, (void*)str_KAGAMI_P_C },
    { 3, 7, 4, (void*)str_KAGAMI_K_A },
    { 3, 7, 4, (void*)str_KAGAMI_K_B },
    { 3, 7, 4, (void*)str_KAGAMI_K_C },
    { 3, 7, 4, (void*)str_KAGAMI_K_A },
    { 3, 7, 4, (void*)str_KAGAMI_K_B },
    { 3, 7, 4, (void*)str_KAGAMI_K_C },
    { 3, 7, 4, (void*)str_KAGAMI_K_A },
    { 3, 7, 4, (void*)str_KAGAMI_K_B },
    { 3, 7, 4, (void*)str_KAGAMI_K_C },
    { 3, 7, 4, (void*)str_V_JUMP_P_S_A },
    { 3, 7, 4, (void*)str_V_JUMP_P_S_B },
    { 3, 7, 4, (void*)str_V_JUMP_P_M_A },
    { 3, 7, 4, (void*)str_V_JUMP_P_M_B },
    { 3, 7, 4, (void*)str_V_JUMP_P_L_A },
    { 3, 7, 4, (void*)str_V_JUMP_P_L_B },
    { 3, 7, 4, (void*)str_V_JUMP_K_S_A },
    { 3, 7, 4, (void*)str_V_JUMP_K_S_B },
    { 3, 7, 4, (void*)str_V_JUMP_K_M_A },
    { 3, 7, 4, (void*)str_V_JUMP_K_M_B },
    { 3, 7, 4, (void*)str_V_JUMP_K_L_A },
    { 3, 7, 4, (void*)str_V_JUMP_K_L_B },
    { 3, 7, 4, (void*)str_F_JUMP_P_S_A },
    { 3, 7, 4, (void*)str_F_JUMP_P_S_B },
    { 3, 7, 4, (void*)str_F_JUMP_P_M_A },
    { 3, 7, 4, (void*)str_F_JUMP_P_M_B },
    { 3, 7, 4, (void*)str_F_JUMP_P_L_A },
    { 3, 7, 4, (void*)str_F_JUMP_P_L_B },
    { 3, 7, 4, (void*)str_F_JUMP_K_S_A },
    { 3, 7, 4, (void*)str_F_JUMP_K_S_B },
    { 3, 7, 4, (void*)str_F_JUMP_K_M_A },
    { 3, 7, 4, (void*)str_F_JUMP_K_M_B },
    { 3, 7, 4, (void*)str_F_JUMP_K_L_A },
    { 3, 7, 4, (void*)str_F_JUMP_K_L_B },
    { 3, 7, 4, (void*)str_B_JUMP_P_S_A },
    { 3, 7, 4, (void*)str_B_JUMP_P_S_B },
    { 3, 7, 4, (void*)str_B_JUMP_P_M_A },
    { 3, 7, 4, (void*)str_B_JUMP_P_M_B },
    { 3, 7, 4, (void*)str_B_JUMP_P_L_A },
    { 3, 7, 4, (void*)str_B_JUMP_P_L_B },
    { 3, 7, 4, (void*)str_B_JUMP_K_S_A },
    { 3, 7, 4, (void*)str_B_JUMP_K_S_B },
    { 3, 7, 4, (void*)str_B_JUMP_K_M_A },
    { 3, 7, 4, (void*)str_B_JUMP_K_M_B },
    { 3, 7, 4, (void*)str_B_JUMP_K_L_A },
    { 3, 7, 4, (void*)str_B_JUMP_K_L_B },
    { 3, 7, 4, (void*)str_SP_V_JP_S_P_A },
    { 3, 7, 4, (void*)str_SP_V_JP_S_P_B },
    { 3, 7, 4, (void*)str_SP_V_JP_M_P_A },
    { 3, 7, 4, (void*)str_SP_V_JP_M_P_B },
    { 3, 7, 4, (void*)str_SP_V_JP_L_P_A },
    { 3, 7, 4, (void*)str_SP_V_JP_L_P_B },
    { 3, 7, 4, (void*)str_SP_V_JP_S_K_A },
    { 3, 7, 4, (void*)str_SP_V_JP_S_K_B },
    { 3, 7, 4, (void*)str_SP_V_JP_M_K_A },
    { 3, 7, 4, (void*)str_SP_V_JP_M_K_B },
    { 3, 7, 4, (void*)str_SP_V_JP_L_K_A },
    { 3, 7, 4, (void*)str_SP_V_JP_L_K_B },
    { 3, 7, 4, (void*)str_SP_F_JP_S_P_A },
    { 3, 7, 4, (void*)str_SP_F_JP_S_P_B },
    { 3, 7, 4, (void*)str_SP_F_JP_M_P_A },
    { 3, 7, 4, (void*)str_SP_F_JP_M_P_B },
    { 3, 7, 4, (void*)str_SP_F_JP_L_P_A },
    { 3, 7, 4, (void*)str_SP_F_JP_L_P_B },
    { 3, 7, 4, (void*)str_SP_F_JP_S_K_A },
    { 3, 7, 4, (void*)str_SP_F_JP_S_K_B },
    { 3, 7, 4, (void*)str_SP_F_JP_M_K_A },
    { 3, 7, 4, (void*)str_SP_F_JP_M_K_B },
    { 3, 7, 4, (void*)str_SP_F_JP_L_K_A },
    { 3, 7, 4, (void*)str_SP_F_JP_L_K_B },
    { 3, 7, 4, (void*)str_SP_B_JP_S_P_A },
    { 3, 7, 4, (void*)str_SP_B_JP_S_P_B },
    { 3, 7, 4, (void*)str_SP_B_JP_M_P_A },
    { 3, 7, 4, (void*)str_SP_B_JP_M_P_B },
    { 3, 7, 4, (void*)str_SP_B_JP_L_P_A },
    { 3, 7, 4, (void*)str_SP_B_JP_L_P_B },
    { 3, 7, 4, (void*)str_SP_B_JP_S_K_A },
    { 3, 7, 4, (void*)str_SP_B_JP_S_K_B },
    { 3, 7, 4, (void*)str_SP_B_JP_M_K_A },
    { 3, 7, 4, (void*)str_SP_B_JP_M_K_B },
    { 3, 7, 4, (void*)str_SP_B_JP_L_K_A },
    { 3, 7, 4, (void*)str_SP_B_JP_L_K_B },
    { 3, 7, 4, (void*)str_S_V_JP_S_P_A },
    { 3, 7, 4, (void*)str_S_V_JP_S_P_B },
    { 3, 7, 4, (void*)str_S_V_JP_M_P_A },
    { 3, 7, 4, (void*)str_S_V_JP_M_P_B },
    { 3, 7, 4, (void*)str_S_V_JP_L_P_A },
    { 3, 7, 4, (void*)str_S_V_JP_L_P_B },
    { 3, 7, 4, (void*)str_S_V_JP_S_K_A },
    { 3, 7, 4, (void*)str_S_V_JP_S_K_B },
    { 3, 7, 4, (void*)str_S_V_JP_M_K_A },
    { 3, 7, 4, (void*)str_S_V_JP_M_K_B },
    { 3, 7, 4, (void*)str_S_V_JP_L_K_A },
    { 3, 7, 4, (void*)str_S_V_JP_L_K_B },
    { 3, 7, 4, (void*)str_S_F_JP_S_P_A },
    { 3, 7, 4, (void*)str_S_F_JP_S_P_B },
    { 3, 7, 4, (void*)str_S_F_JP_M_P_A },
    { 3, 7, 4, (void*)str_S_F_JP_M_P_B },
    { 3, 7, 4, (void*)str_S_F_JP_L_P_A },
    { 3, 7, 4, (void*)str_S_F_JP_L_P_B },
    { 3, 7, 4, (void*)str_S_F_JP_S_K_A },
    { 3, 7, 4, (void*)str_S_F_JP_S_K_B },
    { 3, 7, 4, (void*)str_S_F_JP_M_K_A },
    { 3, 7, 4, (void*)str_S_F_JP_M_K_B },
    { 3, 7, 4, (void*)str_S_F_JP_L_K_A },
    { 3, 7, 4, (void*)str_S_F_JP_L_K_B },
    { 3, 7, 4, (void*)str_S_B_JP_S_P_A },
    { 3, 7, 4, (void*)str_S_B_JP_S_P_B },
    { 3, 7, 4, (void*)str_S_B_JP_M_P_A },
    { 3, 7, 4, (void*)str_S_B_JP_M_P_B },
    { 3, 7, 4, (void*)str_S_B_JP_L_P_A },
    { 3, 7, 4, (void*)str_S_B_JP_L_P_B },
    { 3, 7, 4, (void*)str_S_B_JP_S_K_A },
    { 3, 7, 4, (void*)str_S_B_JP_S_K_B },
    { 3, 7, 4, (void*)str_S_B_JP_M_K_A },
    { 3, 7, 4, (void*)str_S_B_JP_M_K_B },
    { 3, 7, 4, (void*)str_S_B_JP_L_K_A },
    { 3, 7, 4, (void*)str_S_B_JP_L_K_B },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_A },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_B },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_C },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_D },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_E },
    { 3, 7, 4, (void*)str_TUKAMIKAKARI_F },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_A },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_B },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_C },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_D },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_E },
    { 3, 7, 4, (void*)str_TUKAMI_AIR_F },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_UP_P_GUARD_P_S },
    { 3, 7, 4, (void*)str_UP_P_GUARD_P_M },
    { 3, 7, 4, (void*)str_UP_P_GUARD_P_L },
    { 3, 7, 4, (void*)str_UP_P_GUARD_K_S },
    { 3, 7, 4, (void*)str_UP_P_GUARD_K_M },
    { 3, 7, 4, (void*)str_UP_P_GUARD_K_L },
    { 3, 7, 4, (void*)str_D_P_GUARD_P_S },
    { 3, 7, 4, (void*)str_D_P_GUARD_P_M },
    { 3, 7, 4, (void*)str_D_P_GUARD_P_L },
    { 3, 7, 4, (void*)str_D_P_GUARD_K_S },
    { 3, 7, 4, (void*)str_D_P_GUARD_K_M },
    { 3, 7, 4, (void*)str_D_P_GUARD_K_L },
    { 3, 7, 4, (void*)str_FUSHIN_P_S },
    { 3, 7, 4, (void*)str_FUSHIN_P_M },
    { 3, 7, 4, (void*)str_FUSHIN_P_L },
    { 3, 7, 4, (void*)str_FUSHIN_K_S },
    { 3, 7, 4, (void*)str_FUSHIN_K_M },
    { 3, 7, 4, (void*)str_FUSHIN_K_L },
    { 3, 7, 4, (void*)str_OKIAGARI_P_S },
    { 3, 7, 4, (void*)str_OKIAGARI_P_M },
    { 3, 7, 4, (void*)str_OKIAGARI_P_L },
    { 3, 7, 4, (void*)str_OKIAGARI_K_S },
    { 3, 7, 4, (void*)str_OKIAGARI_K_M },
    { 3, 7, 4, (void*)str_OKIAGARI_K_L },
    { 3, 7, 4, (void*)str_ATTACK_1_S },
    { 3, 7, 4, (void*)str_ATTACK_1_M },
    { 3, 7, 4, (void*)str_ATTACK_1_L },
    { 3, 7, 4, (void*)str_ATTACK_1_SP },
    { 3, 7, 4, (void*)str_ATTACK_2_S },
    { 3, 7, 4, (void*)str_ATTACK_2_M },
    { 3, 7, 4, (void*)str_ATTACK_2_L },
    { 3, 7, 4, (void*)str_ATTACK_2_SP },
    { 3, 7, 4, (void*)str_ATTACK_3_S },
    { 3, 7, 4, (void*)str_ATTACK_3_M },
    { 3, 7, 4, (void*)str_ATTACK_3_L },
    { 3, 7, 4, (void*)str_ATTACK_3_SP },
    { 3, 7, 4, (void*)str_ATTACK_4_S },
    { 3, 7, 4, (void*)str_ATTACK_4_M },
    { 3, 7, 4, (void*)str_ATTACK_4_L },
    { 3, 7, 4, (void*)str_ATTACK_4_SP },
    { 3, 7, 4, (void*)str_ATTACK_5_S },
    { 3, 7, 4, (void*)str_ATTACK_5_M },
    { 3, 7, 4, (void*)str_ATTACK_5_L },
    { 3, 7, 4, (void*)str_ATTACK_5_SP },
    { 3, 7, 4, (void*)str_ATTACK_6_S },
    { 3, 7, 4, (void*)str_ATTACK_6_M },
    { 3, 7, 4, (void*)str_ATTACK_6_L },
    { 3, 7, 4, (void*)str_ATTACK_6_SP },
    { 3, 7, 4, (void*)str_ATTACK_7_S },
    { 3, 7, 4, (void*)str_ATTACK_7_M },
    { 3, 7, 4, (void*)str_ATTACK_7_L },
    { 3, 7, 4, (void*)str_ATTACK_7_SP },
    { 3, 7, 4, (void*)str_ATTACK_8_S },
    { 3, 7, 4, (void*)str_ATTACK_8_M },
    { 3, 7, 4, (void*)str_ATTACK_8_L },
    { 3, 7, 4, (void*)str_ATTACK_8_SP },
    { 3, 7, 4, (void*)str_ATTACK_9_S },
    { 3, 7, 4, (void*)str_ATTACK_9_M },
    { 3, 7, 4, (void*)str_ATTACK_9_L },
    { 3, 7, 4, (void*)str_ATTACK_9_SP },
    { 3, 7, 4, (void*)str_ATTACK_10_S },
    { 3, 7, 4, (void*)str_ATTACK_10_M },
    { 3, 7, 4, (void*)str_ATTACK_10_L },
    { 3, 7, 4, (void*)str_ATTACK_10_SP },
    { 3, 7, 4, (void*)str_ATTACK_11_S },
    { 3, 7, 4, (void*)str_ATTACK_11_M },
    { 3, 7, 4, (void*)str_ATTACK_11_L },
    { 3, 7, 4, (void*)str_ATTACK_11_SP },
    { 3, 7, 4, (void*)str_ATTACK_12_S },
    { 3, 7, 4, (void*)str_ATTACK_12_M },
    { 3, 7, 4, (void*)str_ATTACK_12_L },
    { 3, 7, 4, (void*)str_ATTACK_12_SP },
    { 3, 7, 4, (void*)str_ATTACK_13_S },
    { 3, 7, 4, (void*)str_ATTACK_13_M },
    { 3, 7, 4, (void*)str_ATTACK_13_L },
    { 3, 7, 4, (void*)str_ATTACK_13_SP },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_HANASARE },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_EFF01_CHAR },
    { 3, 7, 4, (void*)str_EFF13_CHAR },
    { 3, 7, 4, (void*)str_BONUS_CHAR },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_JUDGEMENT_GAL },
    { 3, 7, 4, (void*)str_EXTRA },
    { 3, 7, 4, (void*)str_PLEF },
    { 3, 7, 4, (void*)str_SELECT },
    { 3, 7, 4, (void*)str_ETC_1 },
    { 3, 7, 4, (void*)str_ETC_2 },
    { 3, 7, 4, (void*)str_ETC_3 },
    { 3, 7, 4, (void*)str_RUCCIA },
    { 3, 7, 4, (void*)str_AFRICA_2 },
    { 3, 7, 4, (void*)str_N_Y },
    { 3, 7, 4, (void*)str_HONGKONG },
    { 3, 7, 4, (void*)str_JAPAN2 },
    { 3, 7, 4, (void*)str_GERMANY_2 },
    { 3, 7, 4, (void*)str_BRAZIL_2 },
    { 3, 7, 4, (void*)str_ORUMEKA },
    { 3, 7, 4, (void*)str_ENGLAND_2 },
    { 3, 7, 4, (void*)str_JAPAN_3 },
    { 3, 7, 4, (void*)str_GILL_STAGE },
    { 3, 7, 4, (void*)str_JAPAN_11 },
    { 3, 7, 4, (void*)str_BONUS },
    { 3, 7, 4, (void*)str_FRANCE_2 },
    { 3, 7, 4, (void*)str_CHAINA_2 },
    { 3, 7, 4, (void*)str_BRAZIL_1_2 },
    { 3, 7, 4, (void*)str_JAPAN_10 },
    { 3, 7, 4, (void*)str_ENDING },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_1 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_2 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_3 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_4 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_5 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_6 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_7 },
    { 3, 7, 4, (void*)str_APPEAR_JUNBI_8 },
    { 3, 7, 4, (void*)str_APPEAR_1 },
    { 3, 7, 4, (void*)str_APPEAR_2 },
    { 3, 7, 4, (void*)str_APPEAR_3 },
    { 3, 7, 4, (void*)str_APPEAR_4 },
    { 3, 7, 4, (void*)str_APPEAR_5 },
    { 3, 7, 4, (void*)str_APPEAR_6 },
    { 3, 7, 4, (void*)str_APPEAR_7 },
    { 3, 7, 4, (void*)str_APPEAR_8 },
    { 3, 7, 4, (void*)str_SP_APPEAR_1 },
    { 3, 7, 4, (void*)str_SP_APPEAR_2 },
    { 3, 7, 4, (void*)str_SP_APPEAR_3 },
    { 3, 7, 4, (void*)str_SP_APPEAR_4 },
    { 3, 7, 4, (void*)str_SP_APPEAR_5 },
    { 3, 7, 4, (void*)str_SP_APPEAR_6 },
    { 3, 7, 4, (void*)str_SP_APPEAR_7 },
    { 3, 7, 4, (void*)str_SP_APPEAR_8 },
    { 3, 7, 4, (void*)str_ZANNEN_1 },
    { 3, 7, 4, (void*)str_ZANNEN_2 },
    { 3, 7, 4, (void*)str_ZANNEN_3 },
    { 3, 7, 4, (void*)str_ZANNEN_4 },
    { 3, 7, 4, (void*)str_ZANNEN_5 },
    { 3, 7, 4, (void*)str_ZANNEN_6 },
    { 3, 7, 4, (void*)str_ZANNEN_7 },
    { 3, 7, 4, (void*)str_ZANNEN_8 },
    { 3, 7, 4, (void*)str_WIN_1 },
    { 3, 7, 4, (void*)str_WIN_2 },
    { 3, 7, 4, (void*)str_WIN_3 },
    { 3, 7, 4, (void*)str_WIN_4 },
    { 3, 7, 4, (void*)str_WIN_5 },
    { 3, 7, 4, (void*)str_WIN_6 },
    { 3, 7, 4, (void*)str_WIN_7 },
    { 3, 7, 4, (void*)str_WIN_8 },
    { 3, 7, 4, (void*)str_SP_WIN_1 },
    { 3, 7, 4, (void*)str_SP_WIN_2 },
    { 3, 7, 4, (void*)str_SP_WIN_3 },
    { 3, 7, 4, (void*)str_SP_WIN_4 },
    { 3, 7, 4, (void*)str_SP_WIN_5 },
    { 3, 7, 4, (void*)str_SP_WIN_6 },
    { 3, 7, 4, (void*)str_SP_WIN_7 },
    { 3, 7, 4, (void*)str_SP_WIN_8 },
    { 3, 7, 4, (void*)str_JUDGMENT_WAIT },
    { 3, 7, 4, (void*)str_JUDGMENT_WAIT },
    { 3, 7, 4, (void*)str_JUDGMENT_WAIT },
    { 3, 7, 4, (void*)str_JUDGMENT_WAIT },
    { 3, 7, 4, (void*)str_JUDGMENT_WIN },
    { 3, 7, 4, (void*)str_JUDGMENT_WIN },
    { 3, 7, 4, (void*)str_JUDGMENT_WIN },
    { 3, 7, 4, (void*)str_JUDGMENT_WIN },
    { 3, 7, 4, (void*)str_JUDGMENT_LOSE },
    { 3, 7, 4, (void*)str_JUDGMENT_LOSE },
    { 3, 7, 4, (void*)str_JUDGMENT_LOSE },
    { 3, 7, 4, (void*)str_JUDGMENT_LOSE },
    { 3, 7, 4, (void*)str_WAIT },
    { 3, 7, 4, (void*)str_AFRICA_JUMP },
    { 3, 7, 4, (void*)str_AFRICA_LAND },
    { 3, 7, 4, (void*)str_SEAN_BALL_HIT },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_BONUS_WIN_1 },
    { 3, 7, 4, (void*)str_BONUS_WIN_2 },
    { 3, 7, 4, (void*)str_BONUS_WIN_3 },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_APPEAR_USE },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
    { 3, 7, 4, (void*)str_empty_10 },
};
/* 02004B74 */
void* dbg_act_name_tbl[11] = {
    (void*)&dbg_act_kind_str[12],
    (void*)&dbg_act_kind_str[77],
    (void*)&dbg_act_kind_str[231],
    (void*)&dbg_act_kind_str[279],
    (void*)&dbg_act_kind_str[329],
    (void*)&dbg_act_kind_str[610],
    (void*)&dbg_act_kind_str[181],
    (void*)&dbg_act_kind_str[722],
    (void*)&dbg_act_kind_str[895],
    (void*)&dbg_act_kind_str[895],
    (void*)&dbg_act_kind_str[853],
};
/* 02004BA0 */
void* dbg_pl_char_tbl[29][9] = {
    { (void*)gill_nmca, (void*)gill_dmca, (void*)gill_caca, (void*)gill_cuca, (void*)gill_atca, (void*)gill_saca, (void*)gill_btca, (void*)gill_exca, (void*)gill_yuca },
    { (void*)alex_nmca, (void*)alex_dmca, (void*)alex_caca, (void*)alex_cuca, (void*)alex_atca, (void*)alex_saca, (void*)alex_btca, (void*)alex_exca, (void*)alex_yuca },
    { (void*)ryu_nmca, (void*)ryu_dmca, (void*)ryu_caca, (void*)ryu_cuca, (void*)ryu_atca, (void*)ryu_saca, (void*)ryu_btca, (void*)ryu_exca, (void*)ryu_yuca },
    { (void*)yun_nmca, (void*)yun_dmca, (void*)yun_caca, (void*)yun_cuca, (void*)yun_atca, (void*)yun_saca, (void*)yun_btca, (void*)yun_exca, (void*)yun_yuca },
    { (void*)dudley_nmca, (void*)dudley_dmca, (void*)dudley_caca, (void*)dudley_cuca, (void*)dudley_atca, (void*)dudley_saca, (void*)dudley_btca, (void*)dudley_exca, (void*)dudley_yuca },
    { (void*)necro_nmca, (void*)necro_dmca, (void*)necro_caca, (void*)necro_cuca, (void*)necro_atca, (void*)necro_saca, (void*)necro_btca, (void*)necro_exca, (void*)necro_yuca },
    { (void*)hugo_nmca, (void*)hugo_dmca, (void*)hugo_caca, (void*)hugo_cuca, (void*)hugo_atca, (void*)hugo_saca, (void*)hugo_btca, (void*)hugo_exca, (void*)hugo_yuca },
    { (void*)ibuki_nmca, (void*)ibuki_dmca, (void*)ibuki_caca, (void*)ibuki_cuca, (void*)ibuki_atca, (void*)ibuki_saca, (void*)ibuki_btca, (void*)ibuki_exca, (void*)ibuki_yuca },
    { (void*)elena_nmca, (void*)elena_dmca, (void*)elena_caca, (void*)elena_cuca, (void*)elena_atca, (void*)elena_saca, (void*)elena_btca, (void*)elena_exca, (void*)elena_yuca },
    { (void*)oro_nmca, (void*)oro_dmca, (void*)oro_caca, (void*)oro_cuca, (void*)oro_atca, (void*)oro_saca, (void*)oro_btca, (void*)oro_exca, (void*)oro_yuca },
    { (void*)yang_nmca, (void*)yang_dmca, (void*)yang_caca, (void*)yang_cuca, (void*)yang_atca, (void*)yang_saca, (void*)yang_btca, (void*)yang_exca, (void*)yang_yuca },
    { (void*)ken_nmca, (void*)ken_dmca, (void*)ken_caca, (void*)ken_cuca, (void*)ken_atca, (void*)ken_saca, (void*)ken_btca, (void*)ken_exca, (void*)ken_yuca },
    { (void*)sean_nmca, (void*)sean_dmca, (void*)sean_caca, (void*)sean_cuca, (void*)sean_atca, (void*)sean_saca, (void*)sean_btca, (void*)sean_exca, (void*)sean_yuca },
    { (void*)urien_nmca, (void*)urien_dmca, (void*)urien_caca, (void*)urien_cuca, (void*)urien_atca, (void*)urien_saca, (void*)urien_btca, (void*)urien_exca, (void*)urien_yuca },
    { (void*)gouki1_nmca, (void*)gouki1_dmca, (void*)gouki1_caca, (void*)gouki1_cuca, (void*)gouki1_atca, (void*)gouki1_saca, (void*)gouki1_btca, (void*)gouki1_exca, (void*)gouki1_yuca },
    { (void*)gouki2_nmca, (void*)gouki2_dmca, (void*)gouki2_caca, (void*)gouki2_cuca, (void*)gouki2_atca, (void*)gouki2_saca, (void*)gouki2_btca, (void*)gouki2_exca, (void*)gouki2_yuca },
    { (void*)chun_nmca, (void*)chun_dmca, (void*)chun_caca, (void*)chun_cuca, (void*)chun_atca, (void*)chun_saca, (void*)chun_btca, (void*)chun_exca, (void*)chun_yuca },
    { (void*)makoto_nmca, (void*)makoto_dmca, (void*)makoto_caca, (void*)makoto_cuca, (void*)makoto_atca, (void*)makoto_saca, (void*)makoto_btca, (void*)makoto_exca, (void*)makoto_yuca },
    { (void*)q_nmca, (void*)q_dmca, (void*)q_caca, (void*)q_cuca, (void*)q_atca, (void*)q_saca, (void*)q_btca, (void*)q_exca, (void*)q_yuca },
    { (void*)no12_nmca, (void*)no12_dmca, (void*)no12_caca, (void*)no12_cuca, (void*)no12_atca, (void*)no12_saca, (void*)no12_btca, (void*)no12_exca, (void*)no12_yuca },
    { (void*)remy_nmca, (void*)remy_dmca, (void*)remy_caca, (void*)remy_cuca, (void*)remy_atca, (void*)remy_saca, (void*)remy_btca, (void*)remy_exca, (void*)remy_yuca },
    { (void*)gill_nmca, (void*)gill_dmca, (void*)gill_caca, (void*)gill_cuca, (void*)gill_atca, (void*)gill_saca, (void*)gill_btca, (void*)gill_exca, (void*)gill_yuca },
    { (void*)gill_nmca, (void*)gill_dmca, (void*)gill_caca, (void*)gill_cuca, (void*)gill_atca, (void*)gill_saca, (void*)gill_btca, (void*)gill_exca, (void*)gill_yuca },
    { (void*)gill_nmca, (void*)gill_dmca, (void*)gill_caca, (void*)gill_cuca, (void*)gill_atca, (void*)gill_saca, (void*)gill_btca, (void*)gill_exca, (void*)gill_yuca },
    { (void*)ef01_char_table, (void*)ef13_char_table, (void*)bonus_char_table, (void*)&ef13_char_table_225[108], (void*)&ef13_char_table_225[116], (void*)&ef13_char_table_225[124], (void*)&ef13_char_table_225[132], (void*)&ef13_char_table_225[140], (void*)&ef13_char_table_225[148] },
    { (void*)&ef13_char_table_225[156], (void*)&ef13_char_table_225[164], (void*)ag_face_panel_table, (void*)plef_char_table, (void*)sel_pl_char_table, (void*)etc_char_table, (void*)etc2_char_table, (void*)etc3_char_table, (void*)rca_char_table },
    { (void*)afc_char_table, (void*)usa_char_table, (void*)hkg_char_table, (void*)&rca_char_table_023[36], (void*)grm_char_table, (void*)brz_char_table, (void*)orm_char_table, (void*)eng_char_table, (void*)jp3_char_table },
    { (void*)fnl_char_table, (void*)j11_char_table, (void*)bns_char_table, (void*)frc_char_table, (void*)chn_char_table, (void*)brz_char_table, (void*)j10_char_table, (void*)end_char_table, (void*)op_char_table },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
/* 02004FB4 */
void (*chk_move_jp[28])() = {
    (void (*)())check_init,
    (void (*)())check_0,
    (void (*)())check_1,
    (void (*)())check_2,
    (void (*)())check_3,
    (void (*)())check_4,
    (void (*)())check_5,
    (void (*)())check_6,
    (void (*)())check_7,
    (void (*)())check_7,
    (void (*)())check_9,
    (void (*)())check_10,
    (void (*)())check_11,
    (void (*)())check_12,
    (void (*)())check_13,
    (void (*)())check_14,
    (void (*)())check_15,
    (void (*)())check_16,
    (void (*)())check_16,
    (void (*)())check_18,
    (void (*)())check_19,
    (void (*)())check_20,
    (void (*)())check_21,
    (void (*)())check_22,
    (void (*)())check_23,
    (void (*)())check_24,
    (void (*)())check_25,
    (void (*)())check_26,
};
/* 02005024 */
const s16* pl_cmd_list[21][56] = {
    { /* gill */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_20, gill_cmd_21, gill_cmd_22, gill_cmd_16,
        gill_cmd_24, gill_cmd_25, gill_cmd_16, gill_cmd_16,
        gill_cmd_28, gill_cmd_29, gill_cmd_30, gill_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* alex */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        alex_cmd_20, alex_cmd_21, alex_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        alex_cmd_28, alex_cmd_29, alex_cmd_30, alex_cmd_31,
        alex_cmd_32, alex_cmd_33, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* ryu */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ryu_cmd_20, ryu_cmd_21, ryu_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ryu_cmd_28, ryu_cmd_29, ryu_cmd_30, ryu_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, ryu_cmd_46, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* yun */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        yun_cmd_20, yun_cmd_21, yun_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        yun_cmd_28, yun_cmd_29, yun_cmd_30, yun_cmd_31,
        yun_cmd_32, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* dudley */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        dudley_cmd_20, dudley_cmd_21, dudley_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        dudley_cmd_28, dudley_cmd_29, dudley_cmd_30, dudley_cmd_31,
        dudley_cmd_32, dudley_cmd_33, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* necro */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        necro_cmd_20, necro_cmd_21, necro_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        necro_cmd_28, necro_cmd_29, necro_cmd_30, necro_cmd_31,
        necro_cmd_32, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* hugo */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        hugo_cmd_20, hugo_cmd_21, hugo_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        hugo_cmd_28, hugo_cmd_29, hugo_cmd_30, hugo_cmd_31,
        hugo_cmd_32, hugo_cmd_33, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* ibuki */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ibuki_cmd_20, ibuki_cmd_21, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ibuki_cmd_28, ibuki_cmd_29, ibuki_cmd_30, ibuki_cmd_31,
        ibuki_cmd_32, ibuki_cmd_33, ibuki_cmd_34, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, ibuki_cmd_38, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, ibuki_cmd_46, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* elena */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        elena_cmd_20, elena_cmd_21, elena_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        elena_cmd_28, elena_cmd_29, elena_cmd_30, elena_cmd_31,
        elena_cmd_32, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* oro */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        oro_cmd_20, oro_cmd_21, oro_cmd_22, gill_cmd_16,
        oro_cmd_24, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        oro_cmd_28, oro_cmd_29, oro_cmd_30, oro_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, oro_cmd_46, oro_cmd_47,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* yang */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        yang_cmd_20, yang_cmd_21, yang_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        yang_cmd_28, yang_cmd_29, yang_cmd_30, yang_cmd_31,
        yang_cmd_32, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* ken */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ken_cmd_20, ken_cmd_21, ken_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        ken_cmd_28, ken_cmd_29, ken_cmd_30, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, ken_cmd_46, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* sean */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        sean_cmd_20, sean_cmd_21, sean_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        sean_cmd_28, sean_cmd_29, sean_cmd_30, sean_cmd_31,
        sean_cmd_32, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* urien */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        urien_cmd_20, urien_cmd_21, urien_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        urien_cmd_28, urien_cmd_29, urien_cmd_30, urien_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* gouki1 */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gouki1_cmd_20, gouki1_cmd_21, gouki1_cmd_22, gill_cmd_16,
        gouki1_cmd_24, gouki1_cmd_25, gill_cmd_16, gill_cmd_16,
        gouki1_cmd_28, gouki1_cmd_29, gouki1_cmd_30, gouki1_cmd_31,
        gouki1_cmd_32, gouki1_cmd_33, gouki1_cmd_34, gouki1_cmd_35,
        gill_cmd_16, gill_cmd_16, gouki1_cmd_38, gouki1_cmd_39,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gouki1_cmd_46, gouki1_cmd_47,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* gouki2 */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gouki1_cmd_20, gouki1_cmd_21, gouki1_cmd_22, gill_cmd_16,
        gouki1_cmd_24, gouki1_cmd_25, gill_cmd_16, gill_cmd_16,
        gouki1_cmd_28, gouki1_cmd_29, gouki1_cmd_30, gouki1_cmd_31,
        gouki1_cmd_32, gouki1_cmd_33, gouki1_cmd_34, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gouki1_cmd_38, gouki1_cmd_39,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gouki1_cmd_46, gouki1_cmd_47,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* chun */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        chun_cmd_20, chun_cmd_21, chun_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        chun_cmd_28, chun_cmd_29, chun_cmd_30, chun_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* makoto */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        makoto_cmd_20, makoto_cmd_21, makoto_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        makoto_cmd_28, makoto_cmd_29, makoto_cmd_30, makoto_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, makoto_cmd_46, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* q */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        q_cmd_20, q_cmd_21, q_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        q_cmd_28, q_cmd_29, q_cmd_30, q_cmd_31,
        q_cmd_32, q_cmd_33, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* no12 */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        no12_cmd_20, no12_cmd_21, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        no12_cmd_28, no12_cmd_29, no12_cmd_30, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, no12_cmd_38, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, no12_cmd_46, no12_cmd_47,
        no12_cmd_48, no12_cmd_49, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
    { /* remy */
        gill_cmd_00, gill_cmd_01, gill_cmd_02, gill_cmd_03,
        gill_cmd_04, gill_cmd_05, gill_cmd_06, gill_cmd_07,
        gill_cmd_08, gill_cmd_09, gill_cmd_10, gill_cmd_11,
        gill_cmd_12, gill_cmd_13, gill_cmd_14, gill_cmd_15,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        remy_cmd_20, remy_cmd_21, remy_cmd_22, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        remy_cmd_28, remy_cmd_29, remy_cmd_30, remy_cmd_31,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
        gill_cmd_16, gill_cmd_16, gill_cmd_16, gill_cmd_16,
    },
};
/* 02006284 */
void* pl_CMD[24] = {
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[1],
    (void*)pl_cmd_list[2],
    (void*)pl_cmd_list[3],
    (void*)pl_cmd_list[4],
    (void*)pl_cmd_list[5],
    (void*)pl_cmd_list[6],
    (void*)pl_cmd_list[7],
    (void*)pl_cmd_list[8],
    (void*)pl_cmd_list[9],
    (void*)pl_cmd_list[10],
    (void*)pl_cmd_list[11],
    (void*)pl_cmd_list[12],
    (void*)pl_cmd_list[13],
    (void*)pl_cmd_list[14],
    (void*)pl_cmd_list[15],
    (void*)pl_cmd_list[16],
    (void*)pl_cmd_list[17],
    (void*)pl_cmd_list[18],
    (void*)pl_cmd_list[19],
    (void*)pl_cmd_list[20],
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[0],
};
/* 020062E4 */
void* player_cmd[24] = {
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[1],
    (void*)pl_cmd_list[2],
    (void*)pl_cmd_list[3],
    (void*)pl_cmd_list[4],
    (void*)pl_cmd_list[5],
    (void*)pl_cmd_list[6],
    (void*)pl_cmd_list[7],
    (void*)pl_cmd_list[8],
    (void*)pl_cmd_list[9],
    (void*)pl_cmd_list[10],
    (void*)pl_cmd_list[11],
    (void*)pl_cmd_list[12],
    (void*)pl_cmd_list[13],
    (void*)pl_cmd_list[14],
    (void*)pl_cmd_list[15],
    (void*)pl_cmd_list[16],
    (void*)pl_cmd_list[17],
    (void*)pl_cmd_list[18],
    (void*)pl_cmd_list[19],
    (void*)pl_cmd_list[20],
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[0],
    (void*)pl_cmd_list[0],
};
/* Stored after player_cmd. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of player_cmd. */
u32 player_cmd_tail[64] = {
    0x0001000C, 0x000E0000, (u32)((const u8*)player_cmd_0), 0x0001000D,
    0x000E0000, (u32)((const u8*)player_cmd_1), 0x0001000E, 0x000E0000,
    (u32)((const u8*)player_cmd_2), 0x0001000F, 0x000E0000, (u32)((const u8*)player_cmd_3),
    0x00010010, 0x000E0000, (u32)((const u8*)player_cmd_4), 0x000C0011,
    0x000E0000, (u32)((const u8*)player_cmd_5), 0x0017000C, 0x000E0000,
    (u32)((const u8*)player_cmd_0), 0x0017000D, 0x000E0000, (u32)((const u8*)player_cmd_1),
    0x0017000E, 0x000E0000, (u32)((const u8*)player_cmd_2), 0x0017000F,
    0x000E0000, (u32)((const u8*)player_cmd_3), 0x00170010, 0x000E0000,
    (u32)((const u8*)player_cmd_4), 0x00220011, 0x000E0000, (u32)((const u8*)player_cmd_11),
    0x000B0003, 0x001A0003, 0x000B0007, 0x001A0007,
    0x000F0003, 0x001E0003, 0x000F0007, 0x001E0007,
    0x000D0003, 0x001C0003, 0x000D0007, 0x001C0007,
    0x000B0005, 0x001A0005, 0x000F0005, 0x001E0005,
    0x000B0009, 0x001A0009, 0x000D0009, 0x001C0009,
    0x000F0009, 0x001E0009, 0x000B000A, 0x001A000A,
    0x000D000A, 0x001C000A, 0x000F000A, 0x001E000A,
};

/* 02006444 */
s16 lvr_chk_tbl[4] = {
    5, 6, 9, 10,
};
/* 0200644C */
/* Stored after lvr_chk_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of lvr_chk_tbl. */
u32 lvr_chk_tbl_tail[20] = {
    0x10002, 0x40008, 0x60013, 0x60000,
    (u32)((const u8*)lvr_chk_tbl_0), 0x60013, 0x60000, (u32)((const u8*)lvr_chk_tbl_1),
    0x60013, 0x60000, (u32)((const u8*)lvr_chk_tbl_2), 0x1D0013,
    0x60000, (u32)((const u8*)lvr_chk_tbl_0), 0x1D0013, 0x60000,
    (u32)((const u8*)lvr_chk_tbl_1), 0x1D0013, 0x60000, (u32)((const u8*)lvr_chk_tbl_2),
};

/* 0200649C */
void (*ta_move_tbl[22])() = {
    (void (*)())BG000,
    (void (*)())BG010,
    (void (*)())BG020,
    (void (*)())BG030,
    (void (*)())BG040,
    (void (*)())BG050,
    (void (*)())BG060,
    (void (*)())BG070,
    (void (*)())BG080,
    (void (*)())BG090,
    (void (*)())BG100,
    (void (*)())BG010,
    (void (*)())BG120,
    (void (*)())BG130,
    (void (*)())BG140,
    (void (*)())BG140,
    (void (*)())BG150,
    (void (*)())BG160,
    (void (*)())BG180,
    (void (*)())BG180,
    (void (*)())BG190,
    (void (*)())Bonus_bg1,
};
/* 020064F4 */
/* Stored after ta_move_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of ta_move_tbl. */
void* ta_move_tbl_tail[1] = {
    (void*)Bonus_bg2,
};
/* 020064F8 */
void (*scr_x_mv_jp[35])() = {
    (void (*)())scr_10_20,
    (void (*)())scr_10_21,
    (void (*)())scr_10_22,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_11_20,
    (void (*)())scr_11_21,
    (void (*)())scr_11_22,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_x_dummy,
    (void (*)())scr_12_20,
    (void (*)())scr_12_21,
    (void (*)())scr_12_22,
};
/* 02006584 */
char ake_attr_tbl[32] = {
    0, 0, 0, 0, 0, 1, 0, 1,
    0, 2, 0, 2, 0, 3, 0, 3,
    0, 4, 0, 4, 0, 5, 0, 5,
    0, 6, 0, 6, 0, 7, 0, 7,
};
/* 020065A4 */
u32 bg_map_tbl[1][3] = {
    { (u32)bg_scr_record_data, (u32)&bg_scr_record_data[16], (u32)&bg_scr_record_data[32] },
};
/* 020065B0 */
void* scene_bg_map[66] = {
    (void*)&ake_scr_record_data[56],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[240],
    (void*)&ake_scr_record_data[272],
    (void*)&ake_scr_record_data[286],
    (void*)&ake_scr_record_data[318],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[56],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[382],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[56],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[478],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[556],
    (void*)&ake_scr_record_data[588],
    (void*)&ake_scr_record_data[602],
    (void*)&ake_scr_record_data[616],
    (void*)&ake_scr_record_data[648],
    0,
    (void*)&ake_scr_record_data[350],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[56],
    (void*)&ake_scr_record_data[208],
    0,
    (void*)&ake_scr_record_data[680],
    (void*)&ake_scr_record_data[712],
    0,
    (void*)&ake_scr_record_data[744],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[776],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[776],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[840],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[866],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[886],
    (void*)&ake_scr_record_data[918],
    0,
    (void*)&ake_scr_record_data[382],
    (void*)&bg_scr_record_data[16],
    0,
    (void*)&ake_scr_record_data[56],
    (void*)&ake_scr_record_data[1046],
    0,
    (void*)&ake_scr_record_data[1078],
    (void*)&ake_scr_record_data[1110],
    0,
    (void*)&ake_scr_record_data[1142],
    (void*)&ake_scr_record_data[1174],
    0,
};
/* 020066B8 */
u32 bg_map_tbl2[12][3] = {
    { (u32)&ake_scr_record_data[1206], (u32)&bg_scr_record_data[16], 0 },
    { (u32)bg_scr_record_data, 0, 0 },
    { (u32)bg_scr_record_data, 0, 0 },
    { (u32)bg_scr_record_data, 0, 0 },
    { (u32)bg_scr_record_data, (u32)&bg_scr_record_data[16], 0 },
    { (u32)bg_scr_record_data, 0, 0 },
    { (u32)&ake_scr_record_data[1206], 0, 0 },
    { (u32)bg_scr_record_data, 0, 0 },
    { (u32)&ake_scr_record_data[1206], 0, 0 },
    { (u32)&ake_scr_record_data[1206], 0, 0 },
    { (u32)&ake_scr_record_data[1206], 0, 0 },
    { (u32)bg_scr_record_data, 0, 0 },
};
/* 02006748 */
void* bg_rewrite_cell_tbl[6][3] = {
    { (void*)&etc_bg_cg_src_tbl[12], (void*)&etc_bg_cg_src_tbl[28], (void*)&etc_bg_cg_src_tbl[44] },
    { (void*)&etc_bg_cg_src_tbl[76], (void*)&etc_bg_cg_src_tbl[28], (void*)&etc_bg_cg_src_tbl[44] },
    { (void*)&etc_bg_cg_src_tbl[164], (void*)&etc_bg_cg_src_tbl[108], (void*)&etc_bg_cg_src_tbl[124] },
    { (void*)&etc_bg_cg_src_tbl[12], (void*)&etc_bg_cg_src_tbl[60], (void*)&etc_bg_cg_src_tbl[44] },
    { (void*)&etc_bg_cg_src_tbl[12], (void*)&etc_bg_cg_src_tbl[28], (void*)&etc_bg_cg_src_tbl[44] },
    { (void*)&etc_bg_cg_src_tbl[12], (void*)&etc_bg_cg_src_tbl[92], (void*)&etc_bg_cg_src_tbl[44] },
};
/* 02006790 */
void* bg_etc_cell_tbl[14][3] = {
    { (void*)&bg_cell_set_tbl[24], 0, 0 },
    { (void*)&bg_cell_set_tbl[120], 0, 0 },
    { (void*)&bg_cell_set_tbl[132], 0, 0 },
    { (void*)&bg_cell_set_tbl[156], 0, 0 },
    { (void*)&bg_cell_set_tbl[168], (void*)&bg_cell_set_tbl[180], 0 },
    { (void*)&bg_cell_set_tbl[192], 0, 0 },
    { (void*)&bg_cell_set_tbl[204], 0, 0 },
    { (void*)&bg_cell_set_tbl[228], 0, 0 },
    { (void*)&bg_cell_set_tbl[48], 0, 0 },
    { (void*)&bg_cell_set_tbl[72], 0, 0 },
    { (void*)&bg_cell_set_tbl[96], 0, 0 },
    { (void*)&bg_cell_set_tbl[144], 0, 0 },
    { (void*)Name_Input_init, (void*)Name_Input_comm, (void*)Name_Input_wait },
    { (void*)Name_Input_comm, (void*)Name_Input_wait, (void*)Name_Input_comm },
};
/* 02006838 */
/* Stored after bg_etc_cell_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of bg_etc_cell_tbl. */
void* bg_etc_cell_tbl_tail[2] = {
    (void*)Name_Input_end,
    (void*)Name_Finish,
};
/* 02006840 */
void (*Name_Jmp_scs[8])() = {
    (void (*)())Name_Scs_Input_init,
    (void (*)())Name_Scs_Input_comm,
    (void (*)())Name_Input_wait,
    (void (*)())Name_Scs_Input_comm,
    (void (*)())Name_Input_wait,
    (void (*)())Name_Scs_Input_comm,
    (void (*)())Name_Scs_Input_end,
    (void (*)())Name_Scs_Finish,
};
/* 02006860 */
void (*opening_move_jp[19])() = {
    (void (*)())op_100_move,
    (void (*)())op_101_move,
    (void (*)())op_102_move,
    (void (*)())op_103_move,
    (void (*)())op_104_move,
    (void (*)())op_105_move,
    (void (*)())op_106_move,
    (void (*)())op_107_move,
    (void (*)())op_108_move,
    (void (*)())op_109_move,
    (void (*)())op_110_move,
    (void (*)())op_111_move,
    (void (*)())op_112_move,
    (void (*)())op_113_move,
    (void (*)())op_114_move,
    (void (*)())op_115_move,
    (void (*)())op_116_move,
    (void (*)())op_117_move,
    (void (*)())op_118_move,
};
/* 020068AC */
s16 op_104_sound[8] = {
    0, 5, 6, 7, 9, 10, 11, 0,
};
/* 020068BC */
void (*end_main_jp[20])() = {
    (void (*)())end_00000,
    (void (*)())end_01000,
    (void (*)())end_02000,
    (void (*)())end_03000,
    (void (*)())end_04000,
    (void (*)())end_05000,
    (void (*)())end_06000,
    (void (*)())end_07000,
    (void (*)())end_08000,
    (void (*)())end_09000,
    (void (*)())end_10000,
    (void (*)())end_11000,
    (void (*)())end_12000,
    (void (*)())end_13000,
    (void (*)())end_14000,
    (void (*)())end_14000,
    (void (*)())end_16000,
    (void (*)())end_17000,
    (void (*)())end_18000,
    (void (*)())end_19000,
};
/* 0200690C */
/* Stored after end_main_jp. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_main_jp. */
void* end_main_jp_tail[4] = {
    (void*)end_20000,
    (void*)end_01000,
    (void*)end_01000,
    (void*)end_01000,
};
/* 0200691C */
u32 end_map_tbl[4] = {
    (u32)&end_cg_src_tbl[24],
    (u32)&end_cg_src_tbl[38],
    (u32)&end_cg_src_tbl[52],
    (u32)&end_cg_src_tbl[66],
};
/* 0200692C */
void* end_400_panel_tbl[2] = {
    (void*)((const u8*)end_400_panel_tbl_0),
    (void*)((const u8*)end_400_panel_tbl_1),
};
/* 02006934 */
void (*end_400_jp[5])() = {
    (void (*)())end_400_0000,
    (void (*)())end_400_1000,
    (void (*)())end_X_com01,
    (void (*)())end_X_com01,
    (void (*)())end_X_com01,
};
/* 02006948 */
void (*end_401_jp[5])() = {
    (void (*)())end_401_0000,
    (void (*)())end_401_1000,
    (void (*)())end_401_2000,
    (void (*)())end_401_3000,
    (void (*)())end_401_4000,
};
/* 0200695C */
void (*end_402_jp[5])() = {
    (void (*)())end_402_0000,
    (void (*)())end_402_1000,
    (void (*)())end_X_com01,
    (void (*)())end_X_com01,
    (void (*)())end_X_com01,
};
/* 02006970 */
s8 end_5_bg1_cell[4] = {
    13, 14, 15, 13,
};
/* 02006974 */
/* Stored after end_5_bg1_cell. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of end_5_bg1_cell. */
u32 end_5_bg1_cell_tail[12] = {
    (u32)end_1100_bg0_cell_tbl, (u32)((const u8*)end_5_bg1_cell_0), 0, 0x10000,
    0x20000, 0x30000, 0x40000, 0x50000,
    0x60000, 0x70000, 0x80000, 0x90000,
};

s16 staff_name_ptr = 0;  /* 020069A4 */
s32 staffroll_end = 0;  /* 020069A8 */
/* 020069AC */
/* Stored after staffroll_end. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of staffroll_end. */
u32 staffroll_end_tail[1] = {
    0,
};

u16 scrfont_view_attr = 0;  /* 020069B0 */
/* 020069B2 */
/* Stored after scrfont_view_attr. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of scrfont_view_attr. */
u16 scrfont_view_attr_tail[1] = {
    19,
};

/* 020069B4 */
void* vital_npos_tbl[2] = {
    (void*)&vital_cell_1p_tbl[81],
    (void*)&vital_cell_1p_tbl[101],
};
/* 020069BC */
void* vital_attr_tbl[3] = {
    (void*)&vital_cell_1p_tbl[121],
    (void*)&vital_cell_1p_tbl[124],
    (void*)&vital_cell_1p_tbl[127],
};
/* 020069C8 */
void* spgauge_puttbl[2] = {
    (void*)((const u8*)spgauge_puttbl_0),
    (void*)((const u8*)spgauge_puttbl_1),
};
/* 020069D0 */
void* spgauge_postbl[2] = {
    (void*)((const u8*)spgauge_postbl_0),
    (void*)((const u8*)spgauge_postbl_1),
};
/* 020069D8 */
u32 fade_adrs_tbl[36] = {
    (u32)((const u8*)fade_adrs_tbl_0),
    (u32)((const u8*)fade_adrs_tbl_1),
    (u32)((const u8*)fade_adrs_tbl_2),
    (u32)((const u8*)fade_adrs_tbl_3),
    (u32)((const u8*)fade_adrs_tbl_4),
    (u32)((const u8*)fade_adrs_tbl_5),
    (u32)((const u8*)fade_adrs_tbl_6),
    (u32)((const u8*)fade_adrs_tbl_7),
    (u32)((const u8*)fade_adrs_tbl_8),
    (u32)((const u8*)fade_adrs_tbl_9),
    (u32)((const u8*)fade_adrs_tbl_10),
    (u32)((const u8*)fade_adrs_tbl_11),
    (u32)((const u8*)fade_adrs_tbl_12),
    (u32)((const u8*)fade_adrs_tbl_13),
    (u32)((const u8*)fade_adrs_tbl_14),
    (u32)((const u8*)fade_adrs_tbl_15),
    (u32)((const u8*)fade_adrs_tbl_16),
    (u32)((const u8*)fade_adrs_tbl_17),
    (u32)((const u8*)fade_adrs_tbl_18),
    (u32)((const u8*)fade_adrs_tbl_19),
    (u32)((const u8*)fade_adrs_tbl_20),
    (u32)((const u8*)fade_adrs_tbl_21),
    (u32)((const u8*)fade_adrs_tbl_22),
    (u32)((const u8*)fade_adrs_tbl_23),
    (u32)((const u8*)fade_adrs_tbl_22),
    (u32)((const u8*)fade_adrs_tbl_25),
    (u32)((const u8*)fade_adrs_tbl_26),
    (u32)((const u8*)fade_adrs_tbl_27),
    (u32)((const u8*)fade_adrs_tbl_28),
    (u32)((const u8*)fade_adrs_tbl_29),
    (u32)((const u8*)fade_adrs_tbl_30),
    (u32)((const u8*)fade_adrs_tbl_31),
    (u32)((const u8*)fade_adrs_tbl_32),
    (u32)((const u8*)fade_adrs_tbl_33),
    (u32)((const u8*)fade_adrs_tbl_34),
    (u32)((const u8*)fade_adrs_tbl_35),
};
/* 02006A68 */
void* stngauge_puttbl[2] = {
    (void*)((const u8*)stngauge_puttbl_0),
    (void*)((const u8*)stngauge_puttbl_1),
};
/* 02006A70 */
void* stngauge_postbl[2] = {
    (void*)((const u8*)stngauge_postbl_0),
    (void*)((const u8*)stngauge_postbl_1),
};
/* 02006A78 */
/* Stored after stngauge_postbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of stngauge_postbl. */
void* stngauge_postbl_tail[2] = {
    (void*)((const u8*)stngauge_postbl_0_2),
    (void*)((const u8*)stngauge_postbl_1_2),
};
/* 02006A80 */
void* char_add[22] = {
    (void*)fnl_char_table,
    (void*)usa_char_table,
    (void*)j10_char_table,
    (void*)hkg_char_table,
    (void*)eng_char_table,
    (void*)rca_char_table,
    (void*)grm_char_table,
    (void*)j11_char_table,
    (void*)afc_char_table,
    (void*)brz_char_table,
    (void*)hkg_char_table,
    (void*)usa_char_table,
    (void*)brz_char_table,
    (void*)orm_char_table,
    (void*)&rca_char_table_023[36],
    (void*)&rca_char_table_023[36],
    (void*)chn_char_table,
    (void*)jp3_char_table,
    (void*)usa_char_table,
    (void*)rca_char_table,
    (void*)frc_char_table,
    (void*)bns_char_table,
};
/* 02006AD8 */
/* Stored after char_add. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of char_add. */
void* char_add_tail[1] = {
    (void*)bns_char_table,
};
/* 02006ADC */
void* scr_obj_data[23] = {
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[24],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[48],
    (void*)&scr_obj_num[112],
    (void*)&scr_obj_num[120],
    (void*)&scr_obj_num[152],
    (void*)&scr_obj_num[200],
    (void*)&scr_obj_num[40],
    (void*)&scr_obj_num[24],
    (void*)&scr_obj_num[208],
    (void*)&scr_obj_num[216],
    (void*)&scr_obj_num[224],
    (void*)&scr_obj_num[224],
    (void*)&scr_obj_num[248],
    (void*)&scr_obj_num[264],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[80],
    (void*)&scr_obj_num[280],
    (void*)&scr_obj_num[312],
    (void*)&scr_obj_num[320],
};
/* 02006B38 */
void* scr_obj_data6[23] = {
    (void*)&scr_obj_num6[23],
    (void*)&scr_obj_num6[31],
    (void*)&scr_obj_num6[111],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num6[191],
    (void*)&scr_obj_num6[215],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num6[327],
    (void*)&scr_obj_num6[343],
    (void*)&scr_obj_num6[431],
    (void*)&scr_obj_num6[143],
    (void*)&scr_obj_num6[79],
    (void*)&scr_obj_num6[455],
    (void*)&scr_obj_num6[31],
    (void*)&scr_obj_num6[479],
    (void*)&scr_obj_num6[479],
    (void*)&scr_obj_num6[489],
    (void*)&scr_obj_num6[505],
    (void*)&scr_obj_num6[215],
    (void*)&scr_obj_num6[271],
    (void*)&scr_obj_num6[537],
    (void*)&scr_obj_num[23],
    (void*)&scr_obj_num[23],
};
/* 02006B94 */
void (*eff09_tbl[28])() = {
    (void (*)())eff09_0000,
    (void (*)())eff09_1000,
    (void (*)())eff09_2000,
    (void (*)())eff09_3000,
    (void (*)())eff09_4000,
    (void (*)())eff09_5000,
    (void (*)())eff09_6000,
    (void (*)())eff09_7000,
    (void (*)())eff09_8000,
    (void (*)())eff09_9000,
    (void (*)())eff09_10000,
    (void (*)())eff09_11000,
    (void (*)())eff09_12000,
    (void (*)())eff09_13000,
    (void (*)())eff09_14000,
    (void (*)())eff09_15000,
    (void (*)())eff09_16000,
    (void (*)())eff09_17000,
    (void (*)())eff09_18000,
    (void (*)())eff09_19000,
    (void (*)())eff09_20000,
    (void (*)())eff09_21000,
    (void (*)())eff09_22000,
    (void (*)())eff09_23000,
    (void (*)())eff09_24000,
    (void (*)())eff09_25000,
    (void (*)())eff09_26000,
    (void (*)())eff09_27000,
};
/* 02006C04 */
void* scr_obj_data10[4] = {
    (void*)&scr_obj_num10[4],
    (void*)&scr_obj_num10[16],
    (void*)&scr_obj_num10[25],
    (void*)&scr_obj_num10[28],
};
/* 02006C14 */
void* scr_obj_data12[6] = {
    (void*)&scr_obj_num12[6],
    (void*)&scr_obj_num12[14],
    (void*)&scr_obj_num12[22],
    (void*)&scr_obj_num12[38],
    (void*)&scr_obj_num12[54],
    (void*)&scr_obj_num12[78],
};
/* 02006C2C */
void* scr_obj_data18[1][4] = {
    { (void*)((const u8*)scr_obj_data18_0), (void*)((const u8*)scr_obj_data18_0), (void*)((const u8*)scr_obj_data18_0), (void*)((const u8*)scr_obj_data18_0) },
};
/* 02006C3C */
void (*eff18_jp_tbl[2])() = {
    (void (*)())eff18_00,
    (void (*)())eff18_01,
};
/* 02006C44 */
void* eff21_data_adrs[1] = {
    (void*)((const u8*)eff21_data_adrs_0),
};
/* 02006C48 */
void* scr_obj_data25[1] = {
    (void*)((const u8*)scr_obj_data25_0),
};
/* 02006C4C */
void (*eff25_jp_tbl[10])() = {
    (void (*)())eff25_00,
    (void (*)())eff25_00,
    (void (*)())eff25_02,
    (void (*)())eff25_02,
    (void (*)())eff25_08,
    (void (*)())eff25_08,
    (void (*)())eff25_06,
    (void (*)())eff25_06,
    (void (*)())eff25_04,
    (void (*)())eff25_04,
};
/* 02006C74 */
void (*eff26_jp_tbl[6])() = {
    (void (*)())eff26_00,
    (void (*)())eff26_01,
    (void (*)())eff26_02,
    (void (*)())eff26_03,
    (void (*)())eff26_04,
    (void (*)())eff26_05,
};
/* 02006C8C */
void* scr_obj_data26[1] = {
    (void*)&eff26_num[1],
};
/* 02006C90 */
void* scr_obj_data27[2] = {
    (void*)((const u8*)scr_obj_data27_0),
    (void*)((const u8*)scr_obj_data27_1),
};
/* 02006C98 */
void (*eff27_jp_tbl[11])() = {
    (void (*)())eff27_00,
    (void (*)())eff27_00,
    (void (*)())eff27_02,
    (void (*)())eff27_03,
    (void (*)())eff27_04,
    (void (*)())eff27_05,
    (void (*)())eff27_06,
    (void (*)())eff27_06,
    (void (*)())eff27_07,
    (void (*)())eff27_08,
    (void (*)())eff27_09,
};
/* 02006CC4 */
void* scr_obj_data28[1] = {
    (void*)&scr_obj_num28[1],
};
/* 02006CC8 */
void* scr_obj_data44[10] = {
    (void*)&scr_obj_num44[10],
    (void*)&scr_obj_num44[26],
    (void*)&scr_obj_num44[34],
    (void*)&scr_obj_num44[50],
    (void*)&scr_obj_num44[106],
    (void*)&scr_obj_num44[114],
    (void*)&scr_obj_num44[138],
    (void*)&scr_obj_num44[154],
    (void*)&scr_obj_num44[194],
    (void*)&scr_obj_num44[226],
};
/* 02006CF0 */
ConstShortArray eff48_adrs_tbl[22] = {
    (void*)eff48_data_tbl00,
    (void*)eff48_data_tbl01,
    (void*)eff48_data_tbl02,
    (void*)eff48_data_tbl03,
    (void*)eff48_data_tbl04,
    (void*)eff48_data_tbl05,
    (void*)eff48_data_tbl06,
    (void*)eff48_data_tbl07,
    (void*)eff48_data_tbl08,
    (void*)eff48_data_tbl09,
    (void*)eff48_data_tbl10,
    (void*)eff48_data_tbl11,
    (void*)eff48_data_tbl12,
    (void*)eff48_data_tbl13,
    (void*)eff48_data_tbl14,
    (void*)eff48_data_tbl15,
    (void*)eff48_data_tbl16,
    (void*)eff48_data_tbl17,
    (void*)eff48_data_tbl18,
    (void*)eff48_data_tbl19,
    (void*)eff48_data_tbl20,
    (void*)eff48_data_tbl21,
};
/* 02006D48 */
void* flash_obj_data61[3] = {
    (void*)((const u8*)flash_obj_data61_0),
    (void*)((const u8*)flash_obj_data61_1),
    (void*)((const u8*)flash_obj_data61_2),
};
/* 02006D54 */
void (*eff64_jp_tbl[9])() = {
    (void (*)())eff64_00,
    (void (*)())eff64_00,
    (void (*)())eff64_02,
    (void (*)())eff64_02,
    (void (*)())eff64_04,
    (void (*)())eff64_04,
    (void (*)())eff64_04,
    (void (*)())eff64_04,
    (void (*)())eff64_08,
};
/* 02006D78 */
void (*eff66_jp_tbl[4])() = {
    (void (*)())eff66_00,
    (void (*)())eff66_01,
    (void (*)())eff66_02,
    (void (*)())eff66_03,
};
/* 02006D88 */
void* eff86_adrs_tbl[1] = {
    (void*)eff86_data_tbl00,
};
/* 02006D8C */
void* scr_obj_data87[1][4] = {
    { (void*)((const u8*)scr_obj_data87_0), (void*)((const u8*)scr_obj_data87_0), (void*)((const u8*)scr_obj_data87_0), (void*)((const u8*)scr_obj_data87_0) },
};
/* 02006D9C */
void* scr_obj_data88[1][4] = {
    { (void*)&eff88_loop_tbl[1][0], (void*)&eff88_loop_tbl[1][0], (void*)&eff88_loop_tbl[1][0], (void*)&eff88_loop_tbl[1][0] },
};
/* 02006DAC */
void* effA6_mes_jp[21] = {
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_2),
    (void*)((const u8*)effA6_mes_jp_3),
    (void*)((const u8*)effA6_mes_jp_4),
    (void*)((const u8*)effA6_mes_jp_5),
    (void*)((const u8*)effA6_mes_jp_6),
    (void*)((const u8*)effA6_mes_jp_7),
    (void*)((const u8*)effA6_mes_jp_8),
    (void*)((const u8*)effA6_mes_jp_9),
    (void*)((const u8*)effA6_mes_jp_10),
    (void*)((const u8*)effA6_mes_jp_11),
    (void*)((const u8*)effA6_mes_jp_12),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_16),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_19),
    (void*)((const u8*)effA6_mes_jp_20),
};
/* 02006E00 */
void* effA6_mes_en[21] = {
    (void*)((const u8*)effA6_mes_en_0),
    (void*)((const u8*)effA6_mes_en_0),
    (void*)((const u8*)effA6_mes_en_2),
    (void*)((const u8*)effA6_mes_en_3),
    (void*)((const u8*)effA6_mes_en_4),
    (void*)((const u8*)effA6_mes_en_5),
    (void*)((const u8*)effA6_mes_en_6),
    (void*)((const u8*)effA6_mes_en_7),
    (void*)((const u8*)effA6_mes_en_8),
    (void*)((const u8*)effA6_mes_en_9),
    (void*)((const u8*)effA6_mes_en_10),
    (void*)((const u8*)effA6_mes_en_11),
    (void*)((const u8*)effA6_mes_en_12),
    (void*)((const u8*)effA6_mes_en_13),
    (void*)((const u8*)effA6_mes_en_13),
    (void*)((const u8*)effA6_mes_en_13),
    (void*)((const u8*)effA6_mes_en_16),
    (void*)((const u8*)effA6_mes_en_17),
    (void*)((const u8*)effA6_mes_en_17),
    (void*)((const u8*)effA6_mes_en_19),
    (void*)((const u8*)effA6_mes_en_20),
};
/* 02006E54 */
void* effA6_mes_es[21] = {
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_2),
    (void*)((const u8*)effA6_mes_jp_3),
    (void*)((const u8*)effA6_mes_jp_4),
    (void*)((const u8*)effA6_mes_jp_5),
    (void*)((const u8*)effA6_mes_jp_6),
    (void*)((const u8*)effA6_mes_jp_7),
    (void*)((const u8*)effA6_mes_jp_8),
    (void*)((const u8*)effA6_mes_jp_9),
    (void*)((const u8*)effA6_mes_jp_10),
    (void*)((const u8*)effA6_mes_jp_11),
    (void*)((const u8*)effA6_mes_jp_12),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_16),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_19),
    (void*)((const u8*)effA6_mes_jp_20),
};
/* 02006EA8 */
void* effA6_mes_pt[21] = {
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_0),
    (void*)((const u8*)effA6_mes_jp_2),
    (void*)((const u8*)effA6_mes_jp_3),
    (void*)((const u8*)effA6_mes_jp_4),
    (void*)((const u8*)effA6_mes_jp_5),
    (void*)((const u8*)effA6_mes_jp_6),
    (void*)((const u8*)effA6_mes_jp_7),
    (void*)((const u8*)effA6_mes_jp_8),
    (void*)((const u8*)effA6_mes_jp_9),
    (void*)((const u8*)effA6_mes_jp_10),
    (void*)((const u8*)effA6_mes_jp_11),
    (void*)((const u8*)effA6_mes_jp_12),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_13),
    (void*)((const u8*)effA6_mes_jp_16),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_17),
    (void*)((const u8*)effA6_mes_jp_19),
    (void*)((const u8*)effA6_mes_jp_20),
};
/* 02006EFC */
void* effB8_mes_jp[21] = {
    (void*)((const u8*)effB8_mes_jp_0),
    (void*)((const u8*)effB8_mes_jp_1),
    (void*)((const u8*)effB8_mes_jp_2),
    (void*)((const u8*)effB8_mes_jp_3),
    (void*)((const u8*)effB8_mes_jp_4),
    (void*)((const u8*)effB8_mes_jp_5),
    (void*)((const u8*)effB8_mes_jp_6),
    (void*)((const u8*)effB8_mes_jp_7),
    (void*)((const u8*)effB8_mes_jp_8),
    (void*)((const u8*)effB8_mes_jp_9),
    (void*)((const u8*)effB8_mes_jp_10),
    (void*)((const u8*)effB8_mes_jp_11),
    (void*)((const u8*)effB8_mes_jp_12),
    (void*)((const u8*)effB8_mes_jp_13),
    (void*)((const u8*)effB8_mes_jp_14),
    (void*)((const u8*)effB8_mes_jp_14),
    (void*)((const u8*)effB8_mes_jp_16),
    (void*)((const u8*)effB8_mes_jp_17),
    (void*)((const u8*)effB8_mes_jp_18),
    (void*)((const u8*)effB8_mes_jp_19),
    (void*)((const u8*)effB8_mes_jp_20),
};
/* 02006F50 */
void* effB8_mes_en[21] = {
    (void*)((const u8*)effB8_mes_en_0),
    (void*)((const u8*)effB8_mes_en_1),
    (void*)((const u8*)effB8_mes_en_2),
    (void*)((const u8*)effB8_mes_en_3),
    (void*)((const u8*)effB8_mes_en_4),
    (void*)((const u8*)effB8_mes_en_5),
    (void*)((const u8*)effB8_mes_en_6),
    (void*)((const u8*)effB8_mes_en_7),
    (void*)((const u8*)effB8_mes_en_8),
    (void*)((const u8*)effB8_mes_en_9),
    (void*)((const u8*)effB8_mes_en_10),
    (void*)((const u8*)effB8_mes_en_11),
    (void*)((const u8*)effB8_mes_en_12),
    (void*)((const u8*)effB8_mes_en_13),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_16),
    (void*)((const u8*)effB8_mes_en_17),
    (void*)((const u8*)effB8_mes_en_18),
    (void*)((const u8*)effB8_mes_en_19),
    (void*)((const u8*)effB8_mes_en_20),
};
/* 02006FA4 */
void* effB8_mes_es[21] = {
    (void*)((const u8*)effB8_mes_en_0),
    (void*)((const u8*)effB8_mes_en_1),
    (void*)((const u8*)effB8_mes_en_2),
    (void*)((const u8*)effB8_mes_en_3),
    (void*)((const u8*)effB8_mes_en_4),
    (void*)((const u8*)effB8_mes_en_5),
    (void*)((const u8*)effB8_mes_en_6),
    (void*)((const u8*)effB8_mes_en_7),
    (void*)((const u8*)effB8_mes_en_8),
    (void*)((const u8*)effB8_mes_en_9),
    (void*)((const u8*)effB8_mes_en_10),
    (void*)((const u8*)effB8_mes_en_11),
    (void*)((const u8*)effB8_mes_en_12),
    (void*)((const u8*)effB8_mes_en_13),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_16),
    (void*)((const u8*)effB8_mes_en_17),
    (void*)((const u8*)effB8_mes_en_18),
    (void*)((const u8*)effB8_mes_en_19),
    (void*)((const u8*)effB8_mes_en_20),
};
/* 02006FF8 */
void* effB8_mes_pt[21] = {
    (void*)((const u8*)effB8_mes_en_0),
    (void*)((const u8*)effB8_mes_en_1),
    (void*)((const u8*)effB8_mes_en_2),
    (void*)((const u8*)effB8_mes_en_3),
    (void*)((const u8*)effB8_mes_en_4),
    (void*)((const u8*)effB8_mes_en_5),
    (void*)((const u8*)effB8_mes_en_6),
    (void*)((const u8*)effB8_mes_en_7),
    (void*)((const u8*)effB8_mes_en_8),
    (void*)((const u8*)effB8_mes_en_9),
    (void*)((const u8*)effB8_mes_en_10),
    (void*)((const u8*)effB8_mes_en_11),
    (void*)((const u8*)effB8_mes_en_12),
    (void*)((const u8*)effB8_mes_en_13),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_14),
    (void*)((const u8*)effB8_mes_en_16),
    (void*)((const u8*)effB8_mes_en_17),
    (void*)((const u8*)effB8_mes_en_18),
    (void*)((const u8*)effB8_mes_en_19),
    (void*)((const u8*)effB8_mes_en_20),
};
/* 0200704C */
void* ag_char_table[8] = {
    (void*)&ef13_char_table_225[108],
    (void*)&ef13_char_table_225[116],
    (void*)&ef13_char_table_225[124],
    (void*)&ef13_char_table_225[132],
    (void*)&ef13_char_table_225[140],
    (void*)&ef13_char_table_225[148],
    (void*)&ef13_char_table_225[156],
    (void*)&ef13_char_table_225[164],
};
/* 0200706C */
void* effF9_mes_jp[28] = {
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_2),
    (void*)((const u8*)effF9_mes_jp_3),
    (void*)((const u8*)effF9_mes_jp_4),
    (void*)((const u8*)effF9_mes_jp_5),
    (void*)((const u8*)effF9_mes_jp_6),
    (void*)((const u8*)effF9_mes_jp_7),
    (void*)((const u8*)effF9_mes_jp_8),
    (void*)((const u8*)effF9_mes_jp_9),
    (void*)((const u8*)effF9_mes_jp_10),
    (void*)((const u8*)effF9_mes_jp_11),
    (void*)((const u8*)effF9_mes_jp_12),
    (void*)((const u8*)effF9_mes_jp_13),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_16),
    (void*)((const u8*)effF9_mes_jp_17),
    (void*)((const u8*)effF9_mes_jp_18),
    (void*)((const u8*)effF9_mes_jp_19),
    (void*)((const u8*)effF9_mes_jp_20),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
};
/* 020070DC */
void* effF9_mes_en[21] = {
    (void*)((const u8*)effF9_mes_en_0),
    (void*)((const u8*)effF9_mes_en_0),
    (void*)((const u8*)effF9_mes_en_2),
    (void*)((const u8*)effF9_mes_en_3),
    (void*)((const u8*)effF9_mes_en_4),
    (void*)((const u8*)effF9_mes_en_5),
    (void*)((const u8*)effF9_mes_en_6),
    (void*)((const u8*)effF9_mes_en_7),
    (void*)((const u8*)effF9_mes_en_8),
    (void*)((const u8*)effF9_mes_en_9),
    (void*)((const u8*)effF9_mes_en_10),
    (void*)((const u8*)effF9_mes_en_11),
    (void*)((const u8*)effF9_mes_en_12),
    (void*)((const u8*)effF9_mes_en_13),
    (void*)((const u8*)effF9_mes_en_14),
    (void*)((const u8*)effF9_mes_en_14),
    (void*)((const u8*)effF9_mes_en_16),
    (void*)((const u8*)effF9_mes_en_17),
    (void*)((const u8*)effF9_mes_en_18),
    (void*)((const u8*)effF9_mes_en_19),
    (void*)((const u8*)effF9_mes_en_20),
};
/* 02007130 */
void* effF9_mes_es[21] = {
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_2),
    (void*)((const u8*)effF9_mes_jp_3),
    (void*)((const u8*)effF9_mes_jp_4),
    (void*)((const u8*)effF9_mes_jp_5),
    (void*)((const u8*)effF9_mes_jp_6),
    (void*)((const u8*)effF9_mes_jp_7),
    (void*)((const u8*)effF9_mes_jp_8),
    (void*)((const u8*)effF9_mes_jp_9),
    (void*)((const u8*)effF9_mes_jp_10),
    (void*)((const u8*)effF9_mes_jp_11),
    (void*)((const u8*)effF9_mes_jp_12),
    (void*)((const u8*)effF9_mes_jp_13),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
};
/* 02007184 */
void* effF9_mes_pt[141] = {
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_0),
    (void*)((const u8*)effF9_mes_jp_2),
    (void*)((const u8*)effF9_mes_jp_3),
    (void*)((const u8*)effF9_mes_jp_4),
    (void*)((const u8*)effF9_mes_jp_5),
    (void*)((const u8*)effF9_mes_jp_6),
    (void*)((const u8*)effF9_mes_jp_7),
    (void*)((const u8*)effF9_mes_jp_8),
    (void*)((const u8*)effF9_mes_jp_9),
    (void*)((const u8*)effF9_mes_jp_10),
    (void*)((const u8*)effF9_mes_jp_11),
    (void*)((const u8*)effF9_mes_jp_12),
    (void*)((const u8*)effF9_mes_jp_13),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_jp_14),
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl01txt1,
    (void*)&pl01txt1[6],
    (void*)&pl01txt1[16],
    (void*)&pl01txt1[30],
    (void*)&pl01txt1[34],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl02txt1,
    (void*)&pl02txt1[6],
    (void*)&pl02txt1[14],
    (void*)&pl02txt1[18],
    (void*)pl02txt5,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl03txt1,
    (void*)pl03txt2,
    (void*)&pl03txt2[6],
    (void*)pl03txt4,
    (void*)&pl03txt4[10],
    (void*)pl03txt6,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl04txt1,
    (void*)&pl04txt1[10],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl05txt1,
    (void*)pl05txt2,
    (void*)&pl05txt2[10],
    (void*)&pl05txt2[16],
    (void*)pl05txt5,
    (void*)pl05txt6,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl05txt6[6],
    (void*)pl06txt2,
    (void*)pl06txt3,
    (void*)pl06txt4,
    (void*)pl06txt5,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl07txt1,
    (void*)pl07txt2,
    (void*)pl07txt3,
    (void*)&pl07txt3[8],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl08txt1,
    (void*)pl08txt2,
    (void*)pl08txt3,
    (void*)&pl08txt3[10],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl08txt3[14],
    (void*)pl09txt2,
    (void*)&pl09txt2[6],
    (void*)pl09txt4,
    (void*)pl09txt5,
    (void*)pl09txt6,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl10txt1,
    (void*)pl10txt2,
    (void*)&pl10txt2[10],
    (void*)pl10txt4,
    (void*)&pl10txt4[10],
    (void*)pl10txt6,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl10txt6[8],
    (void*)pl11txt2,
    (void*)&pl11txt2[6],
    (void*)&pl11txt2[14],
    (void*)&pl11txt2[26],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl11txt2[34],
    (void*)pl12txt2,
    (void*)&pl12txt2[8],
    (void*)pl12txt4,
    (void*)pl12txt5,
    (void*)&pl12txt5[6],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl13txt1,
    (void*)pl13txt2,
    (void*)&pl13txt2[8],
    (void*)&pl13txt2[14],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl14txt1,
    (void*)pl14txt2,
    (void*)&pl14txt2[10],
    (void*)&pl14txt2[16],
    (void*)&pl14txt2[18],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl15txt1,
    (void*)&pl15txt1[10],
    (void*)pl15txt3,
    (void*)pl15txt4,
    (void*)&pl15txt4[8],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl16txt1,
    (void*)pl16txt2,
    (void*)pl16txt3,
    (void*)&pl16txt3[6],
    (void*)pl16txt5,
    (void*)pl16txt6,
    (void*)pl16txt7,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl17txt1,
    (void*)pl17txt2,
    (void*)pl17txt3,
    (void*)&pl17txt6[10],
    (void*)pl17txt5,
    (void*)pl17txt6,
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl17txt5[6],
    (void*)&pl17txt5[12],
    (void*)&pl17txt5[22],
    (void*)&pl17txt5[30],
    (void*)&pl17txt5[40],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)&pl17txt5[48],
    (void*)pl19txt2,
    (void*)pl19txt3,
    (void*)pl19txt4,
    (void*)&pl19txt4[10],
    (void*)pl19txt6,
    (void*)&pl19txt6[8],
    (void*)((const u8*)effF9_mes_pt_0),
    (void*)pl15txt1,
};
/* 020073B8 */
void* txt_no_tbl[20] = {
    (void*)&effF9_mes_pt[21],
    (void*)&effF9_mes_pt[21],
    (void*)&effF9_mes_pt[27],
    (void*)&effF9_mes_pt[33],
    (void*)&effF9_mes_pt[40],
    (void*)&effF9_mes_pt[43],
    (void*)&effF9_mes_pt[50],
    (void*)&effF9_mes_pt[56],
    (void*)&effF9_mes_pt[61],
    (void*)&effF9_mes_pt[66],
    (void*)&effF9_mes_pt[73],
    (void*)&effF9_mes_pt[80],
    (void*)&effF9_mes_pt[86],
    (void*)&effF9_mes_pt[93],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[104],
    (void*)&effF9_mes_pt[110],
    (void*)&effF9_mes_pt[118],
    (void*)&effF9_mes_pt[125],
};
/* 02007408 */
/* Stored after txt_no_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of txt_no_tbl. */
void* txt_no_tbl_tail[8] = {
    (void*)&effF9_mes_pt[131],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[98],
    (void*)&effF9_mes_pt[139],
    (void*)&effF9_mes_pt[139],
};
/* 02007428 */
void* effH7_move_tbl[16] = {
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[57],
    (void*)&effH7_bound_tbl[97],
    (void*)&effH7_bound_tbl[97],
    (void*)&effH7_bound_tbl[73],
    (void*)&effH7_bound_tbl[125],
};
/* 02007468 */
void* pl00_cctbl[7][2] = {
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
    { (void*)((const u8*)pl00_cctbl_0), (void*)((const u8*)pl00_cctbl_1) },
};
/* 020074A0 */
void* effL8_data_tbl[7] = {
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
    (void*)&effM0_tbl_top[4],
};
/* 020074BC */
void* effM4_dir_tbl[8] = {
    (void*)((const u8*)effM4_dir_tbl_0),
    (void*)((const u8*)effM4_dir_tbl_1),
    (void*)((const u8*)effM4_dir_tbl_2),
    (void*)((const u8*)effM4_dir_tbl_3),
    (void*)((const u8*)effM4_dir_tbl_4),
    (void*)((const u8*)effM4_dir_tbl_5),
    (void*)((const u8*)effM4_dir_tbl_6),
    (void*)((const u8*)effM4_dir_tbl_7),
};
/* 020074DC */
TM_STRING test_menu_str[13] = {
    { 0xF, 1, 2, (void*)((const u8*)test_menu_str_0) },
    { 0x10, 3, 2, (void*)((const u8*)test_menu_str_1) },
    { 0x10, 5, 2, (void*)((const u8*)test_menu_str_2) },
    { 0x10, 7, 2, (void*)((const u8*)test_menu_str_3) },
    { 0x10, 9, 2, (void*)((const u8*)test_menu_str_4) },
    { 0x10, 0xB, 2, (void*)((const u8*)test_menu_str_5) },
    { 0x10, 0xD, 2, (void*)((const u8*)test_menu_str_6) },
    { 0x10, 0xF, 2, (void*)((const u8*)test_menu_str_7) },
    { 0x10, 0x11, 2, (void*)((const u8*)test_menu_str_8) },
    { 0x10, 0x13, 2, (void*)((const u8*)test_menu_str_9) },
    { 0x10, 0x15, 2, (void*)((const u8*)test_menu_str_10) },
    { 0xD, 0x1A, 2, (void*)((const u8*)test_menu_str_11) },
    { 0xD, 0x1B, 2, (void*)((const u8*)test_menu_str_12) },
};
/* 02007578 */
TM_STRING test_menu_str_asia[12] = {
    { 0xF, 1, 2, (void*)((const u8*)test_menu_str_0) },
    { 0x10, 3, 2, (void*)((const u8*)test_menu_str_1) },
    { 0x10, 5, 2, (void*)((const u8*)test_menu_str_2) },
    { 0x10, 7, 2, (void*)((const u8*)test_menu_str_3) },
    { 0x10, 9, 2, (void*)((const u8*)test_menu_str_4) },
    { 0x10, 0xB, 2, (void*)((const u8*)test_menu_str_5) },
    { 0x10, 0xD, 2, (void*)((const u8*)test_menu_str_6) },
    { 0x10, 0xF, 2, (void*)((const u8*)test_menu_str_7) },
    { 0x10, 0x11, 2, (void*)((const u8*)test_menu_str_8) },
    { 0x10, 0x13, 2, (void*)((const u8*)test_menu_str_asia_9) },
    { 0xD, 0x1A, 2, (void*)((const u8*)test_menu_str_11) },
    { 0xD, 0x1B, 2, (void*)((const u8*)test_menu_str_12) },
};
/* 02007608 */
TMSCRIPT test_menu_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)test_menu_scr_jp_0) },
};
/* 02007610 */
TMSCRIPT config_top_scr_jp[1] = {
    { 1, 0, (void*)((const u8*)config_top_scr_jp_0) },
};
/* 02007618 */
TMSCRIPT sys_cfg_page_scr_jp[81] = {
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_0) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_1) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_2) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_3) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_4) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_5) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_6) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_7) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_8) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_9) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_10) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_11) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_12) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_13) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_14) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_15) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_16) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_17) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_18) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_19) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_20) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_21) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_22) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_23) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_24) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_25) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_26) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_27) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_28) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_29) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_30) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_31) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_32) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_33) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_34) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_35) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_36) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_37) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_38) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_39) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_40) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_41) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_42) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_43) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_44) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_45) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_46) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_47) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_48) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_49) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_50) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_51) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_52) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_53) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_54) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_55) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_56) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_57) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_58) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_59) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_60) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_61) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_62) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_63) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_64) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_65) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_66) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_67) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_68) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_69) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_70) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_71) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_72) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_73) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_74) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_75) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_76) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_77) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_78) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_79) },
    { 1, 0, (void*)((const u8*)sys_cfg_page_scr_jp_80) },
};
/* 020078A0 */
TMSCRIPT sys_cfg_exit_guide_jp[1] = {
    { 1, 0, (void*)((const u8*)sys_cfg_exit_guide_jp_0) },
};
/* 020078A8 */
TMSCRIPT sys_cfg_item_guide_jp[1] = {
    { 1, 0, (void*)((const u8*)sys_cfg_item_guide_jp_0) },
};
/* 020078B0 */
TMSCRIPT cfg_top_guide_jp[1] = {
    { 1, 0, (void*)((const u8*)cfg_top_guide_jp_0) },
};
/* 020078B8 */
TMSCRIPT cfg_top_reset_guide_jp[1] = {
    { 1, 0, (void*)((const u8*)cfg_top_reset_guide_jp_0) },
};
/* 020078C0 */
void* sys_cfg_coin_scr_jp[19] = {
    (void*)&sys_cfg_page_scr_jp[2],
    (void*)&sys_cfg_page_scr_jp[3],
    (void*)&sys_cfg_page_scr_jp[4],
    (void*)&sys_cfg_page_scr_jp[5],
    (void*)&sys_cfg_page_scr_jp[6],
    (void*)&sys_cfg_page_scr_jp[7],
    (void*)&sys_cfg_page_scr_jp[8],
    (void*)&sys_cfg_page_scr_jp[9],
    (void*)&sys_cfg_page_scr_jp[10],
    (void*)&sys_cfg_page_scr_jp[11],
    (void*)&sys_cfg_page_scr_jp[12],
    (void*)&sys_cfg_page_scr_jp[13],
    (void*)&sys_cfg_page_scr_jp[14],
    (void*)&sys_cfg_page_scr_jp[15],
    (void*)&sys_cfg_page_scr_jp[16],
    (void*)&sys_cfg_page_scr_jp[17],
    (void*)&sys_cfg_page_scr_jp[18],
    (void*)&sys_cfg_page_scr_jp[19],
    (void*)&sys_cfg_page_scr_jp[20],
};
/* 0200790C */
void* sys_cfg_chute_scr_jp[12] = {
    (void*)&sys_cfg_page_scr_jp[21],
    (void*)&sys_cfg_page_scr_jp[22],
    (void*)&sys_cfg_page_scr_jp[23],
    (void*)&sys_cfg_page_scr_jp[24],
    (void*)&sys_cfg_page_scr_jp[25],
    (void*)&sys_cfg_page_scr_jp[26],
    (void*)&sys_cfg_page_scr_jp[27],
    (void*)&sys_cfg_page_scr_jp[28],
    (void*)&sys_cfg_page_scr_jp[29],
    (void*)&sys_cfg_page_scr_jp[30],
    (void*)&sys_cfg_page_scr_jp[31],
    (void*)&sys_cfg_page_scr_jp[32],
};
/* 0200793C */
void* sys_cfg_continue_scr_jp[2] = {
    (void*)&sys_cfg_page_scr_jp[33],
    (void*)&sys_cfg_page_scr_jp[34],
};
/* 02007944 */
void* sys_cfg_monitor_scr_jp[2] = {
    (void*)&sys_cfg_page_scr_jp[35],
    (void*)&sys_cfg_page_scr_jp[36],
};
/* 0200794C */
void* sys_cfg_demo_scr_jp[2] = {
    (void*)&sys_cfg_page_scr_jp[37],
    (void*)&sys_cfg_page_scr_jp[38],
};
/* 02007954 */
void* sys_cfg_sound_scr_jp[42] = {
    (void*)&sys_cfg_page_scr_jp[39],
    (void*)&sys_cfg_page_scr_jp[40],
    (void*)&sys_cfg_page_scr_jp[41],
    (void*)&sys_cfg_page_scr_jp[42],
    (void*)&sys_cfg_page_scr_jp[43],
    (void*)&sys_cfg_page_scr_jp[44],
    (void*)&sys_cfg_page_scr_jp[45],
    (void*)&sys_cfg_page_scr_jp[46],
    (void*)&sys_cfg_page_scr_jp[47],
    (void*)&sys_cfg_page_scr_jp[48],
    (void*)&sys_cfg_page_scr_jp[49],
    (void*)&sys_cfg_page_scr_jp[50],
    (void*)&sys_cfg_page_scr_jp[51],
    (void*)&sys_cfg_page_scr_jp[52],
    (void*)&sys_cfg_page_scr_jp[53],
    (void*)&sys_cfg_page_scr_jp[54],
    (void*)&sys_cfg_page_scr_jp[55],
    (void*)&sys_cfg_page_scr_jp[56],
    (void*)&sys_cfg_page_scr_jp[57],
    (void*)&sys_cfg_page_scr_jp[58],
    (void*)&sys_cfg_page_scr_jp[59],
    (void*)&sys_cfg_page_scr_jp[60],
    (void*)&sys_cfg_page_scr_jp[61],
    (void*)&sys_cfg_page_scr_jp[62],
    (void*)&sys_cfg_page_scr_jp[63],
    (void*)&sys_cfg_page_scr_jp[64],
    (void*)&sys_cfg_page_scr_jp[65],
    (void*)&sys_cfg_page_scr_jp[66],
    (void*)&sys_cfg_page_scr_jp[67],
    (void*)&sys_cfg_page_scr_jp[68],
    (void*)&sys_cfg_page_scr_jp[69],
    (void*)&sys_cfg_page_scr_jp[70],
    (void*)&sys_cfg_page_scr_jp[71],
    (void*)&sys_cfg_page_scr_jp[72],
    (void*)&sys_cfg_page_scr_jp[73],
    (void*)&sys_cfg_page_scr_jp[74],
    (void*)&sys_cfg_page_scr_jp[75],
    (void*)&sys_cfg_page_scr_jp[76],
    (void*)&sys_cfg_page_scr_jp[77],
    (void*)&sys_cfg_page_scr_jp[78],
    (void*)&sys_cfg_page_scr_jp[79],
    (void*)&sys_cfg_page_scr_jp[80],
};
/* Stored after sys_cfg_sound_scr_jp. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of sys_cfg_sound_scr_jp. */
u32 sys_cfg_sound_scr_jp_tail[2] = {
    0x00010000, (u32)((const u8*)sys_cfg_sound_scr_jp_0),
};

void* kizetsu_timer_table_0[4] = {
    tsuujyou_dageki_00, tsuujyou_dageki_01, tsuujyou_dageki_02, tsuujyou_dageki_02,
};

void* kizetsu_timer_table_1[4] = {
    hissatsu_dageki_00, hissatsu_dageki_01, hissatsu_dageki_02, hissatsu_dageki_02,
};

void* kizetsu_timer_table_2[4] = {
    tsuujyou_nage_00, tsuujyou_nage_01, tsuujyou_nage_02, tsuujyou_nage_02,
};

void* kizetsu_timer_table_3[4] = {
    &tsuujyou_nage_02[16], &tsuujyou_nage_02[32], &tsuujyou_nage_02[48], &tsuujyou_nage_02[48],
};

void* kizetsu_timer_table_4[4] = {
    &tsuujyou_nage_02[64], &tsuujyou_nage_02[80], &tsuujyou_nage_02[96], &tsuujyou_nage_02[96],
};

void* kizetsu_timer_table_5[4] = {
    super_arts_nage_00, super_arts_nage_01, super_arts_nage_02, super_arts_nage_02,
};

/* 02007A64 */
void* kizetsu_timer_table[9] = {
    (void*)((const u8*)kizetsu_timer_table_0),
    (void*)((const u8*)kizetsu_timer_table_1),
    (void*)((const u8*)kizetsu_timer_table_2),
    (void*)((const u8*)kizetsu_timer_table_3),
    (void*)((const u8*)kizetsu_timer_table_4),
    (void*)((const u8*)kizetsu_timer_table_5),
    (void*)((const u8*)kizetsu_timer_table_4),
    (void*)((const u8*)kizetsu_timer_table_5),
    (void*)((const u8*)kizetsu_timer_table_4),
};
/* 02007A88 */
void* cjdr_karaburi_table[20] = {
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
};
/* 02007AD8 */
/* Stored after cjdr_karaburi_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of cjdr_karaburi_table. */
void* cjdr_karaburi_table_tail[4] = {
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
    (void*)&plxx_extra_attack_table[30],
};
/* 02007AE8 */
void* cjdr_hits_table[20] = {
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
};
/* 02007B38 */
/* Stored after cjdr_hits_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of cjdr_hits_table. */
void* cjdr_hits_table_tail[4] = {
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
    (void*)&plxx_extra_attack_table[38],
};
/* 02007B48 */
void* cjdr_blocking_table[20] = {
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[44],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[44],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[44],
};
/* 02007B98 */
/* Stored after cjdr_blocking_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of cjdr_blocking_table. */
void* cjdr_blocking_table_tail[4] = {
    (void*)&plxx_extra_attack_table[42],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[40],
    (void*)&plxx_extra_attack_table[40],
};
/* 02007BA8 */
void* cjdr_defense_table[20] = {
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
};
/* 02007BF8 */
/* Stored after cjdr_defense_table. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of cjdr_defense_table. */
void* cjdr_defense_table_tail[4] = {
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
    (void*)&plxx_extra_attack_table[52],
};
/* 02007C08 */
void* bbbs_table[2][5] = {
    { (void*)bbbs_level_00, (void*)bbbs_level_01, (void*)bbbs_level_02, (void*)bbbs_level_03, (void*)bbbs_level_04 },
    { (void*)bbbs_level_05, (void*)bbbs_level_06, (void*)bbbs_level_07, (void*)bbbs_level_08, (void*)bbbs_level_09 },
};
/* 02007C30 */
void* metamor_color_ptr_tbl[24] = {
    (void*)&bbbs_level_09[229],
    (void*)&bbbs_level_09[1125],
    (void*)&bbbs_level_09[1573],
    (void*)&bbbs_level_09[2021],
    (void*)&bbbs_level_09[2469],
    (void*)&bbbs_level_09[2917],
    (void*)&bbbs_level_09[3365],
    (void*)&bbbs_level_09[3813],
    (void*)&bbbs_level_09[4261],
    (void*)&bbbs_level_09[4709],
    (void*)&bbbs_level_09[5157],
    (void*)&bbbs_level_09[5605],
    (void*)&bbbs_level_09[6053],
    (void*)&bbbs_level_09[6501],
    (void*)&bbbs_level_09[6949],
    (void*)&bbbs_level_09[6949],
    (void*)&bbbs_level_09[7397],
    (void*)&bbbs_level_09[7845],
    (void*)&bbbs_level_09[8293],
    (void*)&bbbs_level_09[8741],
    (void*)&bbbs_level_09[9189],
    (void*)&bbbs_level_09[229],
    (void*)&bbbs_level_09[229],
    (void*)&bbbs_level_09[229],
};
s16 iotest_in_no = 0;  /* 02007C90 */
/* 02007C92 */
/* Stored after iotest_in_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of iotest_in_no. */
u16 iotest_in_no_tail[1] = {
    0,
};

s16 iotest_out_no = 0;  /* 02007C94 */
/* 02007C96 */
/* Stored after iotest_out_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of iotest_out_no. */
u16 iotest_out_no_tail[1] = {
    0,
};

s16 soundtest_rep_timer = 30;  /* 02007C98 */
s16 soundtest_code = 0;  /* 02007C9A */
s16 soundtest_no = 0;  /* 02007C9C */
/* 02007C9E */
/* Stored after soundtest_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of soundtest_no. */
u16 soundtest_no_tail[1] = {
    0,
};

s16 colortest_no = 0;  /* 02007CA0 */
/* 02007CA2 */
/* Stored after colortest_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of colortest_no. */
u16 colortest_no_tail[1] = {
    0,
};

s16 screentest_no = 0;  /* 02007CA4 */
/* 02007CA6 */
/* Stored after screentest_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of screentest_no. */
u16 screentest_no_tail[1] = {
    0,
};

s16 backup_test_no = 0;  /* 02007CA8 */
/* 02007CAA */
/* Stored after backup_test_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of backup_test_no. */
u16 backup_test_no_tail[1] = {
    0,
};

s16 config_menu_no = 0;  /* 02007CAC */
/* 02007CB0 */
void* simm_name_tbl[8] = {
    (void*)str_ONBOARD,
    (void*)str_SIMM1,
    (void*)str_SIMM2,
    (void*)str_SIMM3,
    (void*)str_SIMM4,
    (void*)str_SIMM5,
    (void*)str_SIMM6,
    (void*)str_SIMM7,
};
u8 no_cd_flag = 0;  /* 02007CD0 */
s16 memtest_error = 0;  /* 02007CD2 */
s16 memtest_wait = 0;  /* 02007CD4 */
s16 memtest_cursor = 0;  /* 02007CD6 */
s16 memtest_no = 0;  /* 02007CD8 */
/* 02007CDA */
/* Stored after memtest_no. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of memtest_no. */
u16 memtest_no_tail[1] = {
    0,
};

s16 rewrite_no = 0;  /* 02007CDC */
s16 rewrite_cursor = 0;  /* 02007CDE */
s8 credit_1p = 0;  /* 02007CE0 */
s8 credit_2p = 0;  /* 02007CE1 */
s8 credit_3p = 0;  /* 02007CE2 */
s8 credit_4p = 0;  /* 02007CE3 */
/* 02007CE4 */
u8 coin_count_ptr_tbl_0[1] = {
    0,
};

u8 coin_count_ptr_tbl_1[1] = {
    0,
};

u8 coin_count_ptr_tbl_2[1] = {
    0,
};

u8 coin_count_ptr_tbl_3[1] = {
    0,
};

u8 coin_in_flag = 0;  /* 02007CE8 */
u8 coin_out_latch = 0;  /* 02007CE9 */
/* 02007CEC */
void* coin_chute_tbl[4] = {
    (void*)&coin_chute1_w,
    (void*)&coin_chute2_w,
    (void*)&coin_chute3_w,
    (void*)&coin_chute4_w,
};
/* 02007CFC */
void* coin_sw_tbl[4][2] = {
    { (void*)&p1sw_0, (void*)&p1sw_1 },
    { (void*)&p2sw_0, (void*)&p2sw_1 },
    { (void*)&p3sw_0, (void*)&p3sw_1 },
    { (void*)&p4sw_0, (void*)&p4sw_1 },
};
/* 02007D1C */
void* credit_ptr_tbl[4] = {
    (void*)&credit_1p,
    (void*)&credit_2p,
    (void*)&credit_3p,
    (void*)&credit_4p,
};
/* 02007D2C */
void* coin_count_ptr_tbl[4] = {
    (void*)((const u8*)coin_count_ptr_tbl_0),
    (void*)((const u8*)coin_count_ptr_tbl_1),
    (void*)((const u8*)coin_count_ptr_tbl_2),
    (void*)((const u8*)coin_count_ptr_tbl_3),
};
s32 card_empty_flag = 0;  /* 02007D3C */
/* 02007D40 */
u32 bookkeep_add0 = 0;
u32 bookkeep_add1 = 0;
u32 bookkeep_add2 = 0;
u32 bookkeep_add3 = 0;
s8 event_off_flag = 1;  /* 02007D50 */
/* 02007D54 */
void* coin_setting_str_tbl[19] = {
    (void*)&coin_rate_tbl[20][0],
    (void*)((const u8*)coin_setting_str_tbl_1),
    (void*)((const u8*)coin_setting_str_tbl_2),
    (void*)((const u8*)coin_setting_str_tbl_3),
    (void*)((const u8*)coin_setting_str_tbl_4),
    (void*)((const u8*)coin_setting_str_tbl_5),
    (void*)((const u8*)coin_setting_str_tbl_6),
    (void*)((const u8*)coin_setting_str_tbl_7),
    (void*)((const u8*)coin_setting_str_tbl_8),
    (void*)((const u8*)coin_setting_str_tbl_9),
    (void*)((const u8*)coin_setting_str_tbl_10),
    (void*)((const u8*)coin_setting_str_tbl_11),
    (void*)((const u8*)coin_setting_str_tbl_12),
    (void*)((const u8*)coin_setting_str_tbl_13),
    (void*)((const u8*)coin_setting_str_tbl_14),
    (void*)((const u8*)coin_setting_str_tbl_15),
    (void*)((const u8*)coin_setting_str_tbl_16),
    (void*)((const u8*)coin_setting_str_tbl_17),
    (void*)((const u8*)coin_setting_str_tbl_18),
};
/* 02007DA0 */
void* chute_mode_str_tbl[12] = {
    (void*)((const u8*)chute_mode_str_tbl_0),
    (void*)((const u8*)chute_mode_str_tbl_1),
    (void*)((const u8*)chute_mode_str_tbl_2),
    (void*)((const u8*)chute_mode_str_tbl_3),
    (void*)((const u8*)chute_mode_str_tbl_4),
    (void*)((const u8*)chute_mode_str_tbl_5),
    (void*)((const u8*)chute_mode_str_tbl_6),
    (void*)((const u8*)chute_mode_str_tbl_7),
    (void*)((const u8*)chute_mode_str_tbl_8),
    (void*)((const u8*)chute_mode_str_tbl_9),
    (void*)((const u8*)chute_mode_str_tbl_10),
    (void*)((const u8*)chute_mode_str_tbl_11),
};
/* 02007DD0 */
void* on_off_str_tbl[2] = {
    (void*)((const u8*)on_off_str_tbl_0),
    (void*)((const u8*)on_off_str_tbl_1),
};
/* 02007DD8 */
void* sound_mode_str_tbl[7] = {
    (void*)((const u8*)sound_mode_str_tbl_0),
    (void*)((const u8*)sound_mode_str_tbl_1),
    (void*)((const u8*)sound_mode_str_tbl_2),
    (void*)((const u8*)sound_mode_str_tbl_3),
    (void*)((const u8*)sound_mode_str_tbl_4),
    (void*)((const u8*)sound_mode_str_tbl_5),
    (void*)((const u8*)on_off_str_tbl_0),
};
/* 02007DF4 */
void* monitor_str_tbl[2] = {
    (void*)((const u8*)sound_mode_str_tbl_5),
    (void*)((const u8*)monitor_str_tbl_1),
};
/* 02007DFC */
void (*config_menu_tbl[2])() = {
    (void (*)())config_menu_init,
    (void (*)())config_menu_dispatch,
};
/* 02007E04 */
void (*config_page_tbl[3])() = {
    (void (*)())config_top_page,
    (void (*)())sysconfig_page,
    (void (*)())gameconfig_page,
};
/* 02007E10 */
void (*config_top_step_tbl[2])() = {
    (void (*)())config_top_draw,
    (void (*)())config_top_select,
};
/* 02007E18 */
void (*config_top_item_tbl[4])() = {
    (void (*)())config_top_system,
    (void (*)())config_top_game,
    (void (*)())config_top_default,
    (void (*)())config_top_save_exit,
};
/* 02007E28 */
void (*sysconfig_step_tbl[2])() = {
    (void (*)())sysconfig_draw,
    (void (*)())sysconfig_select,
};
/* 02007E30 */
void (*sysconfig_item_tbl[7])() = {
    (void (*)())sysconfig_coin,
    (void (*)())sysconfig_chute_mode,
    (void (*)())sysconfig_continue,
    (void (*)())sysconfig_monitor,
    (void (*)())sysconfig_demo_sound,
    (void (*)())sysconfig_sound_mode,
    (void (*)())sysconfig_exit,
};
/* 02007E4C */
void (*sysconfig_item_tbl_b[7])() = {
    (void (*)())sysconfig_coin,
    (void (*)())sysconfig_chute_mode,
    (void (*)())sysconfig_continue,
    (void (*)())sysconfig_monitor,
    (void (*)())sysconfig_demo_sound,
    (void (*)())sysconfig_sound_mode,
    (void (*)())sysconfig_exit,
};
/* 02007E68 */
void (*sysconfig_item_card_tbl[9])() = {
    (void (*)())sysconfig_coin,
    (void (*)())sysconfig_chute_mode,
    (void (*)())sysconfig_continue,
    (void (*)())sysconfig_monitor,
    (void (*)())sysconfig_demo_sound,
    (void (*)())sysconfig_sound_mode,
    (void (*)())sysconfig_dispenser,
    (void (*)())sysconfig_win_point,
    (void (*)())sysconfig_exit,
};
/* 02007E8C */
void (*sysconfig_item_tbl_c[7])() = {
    (void (*)())sysconfig_coin,
    (void (*)())sysconfig_chute_mode,
    (void (*)())sysconfig_continue,
    (void (*)())sysconfig_monitor,
    (void (*)())sysconfig_demo_sound,
    (void (*)())sysconfig_sound_mode,
    (void (*)())sysconfig_exit,
};
/* 02007EA8 */
void (*sysconfig_item_card_tbl2[10])() = {
    (void (*)())sysconfig_coin,
    (void (*)())sysconfig_chute_mode,
    (void (*)())sysconfig_continue,
    (void (*)())sysconfig_monitor,
    (void (*)())sysconfig_demo_sound,
    (void (*)())sysconfig_sound_mode,
    (void (*)())sysconfig_dispenser,
    (void (*)())sysconfig_win_point,
    (void (*)())sysconfig_win_point_human,
    (void (*)())sysconfig_exit,
};
u16 sprite_dummy_code = 0;  /* 02007ED0 */
/* 02007ED2 */
/* Stored after sprite_dummy_code. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of sprite_dummy_code. */
u16 sprite_dummy_code_tail[1] = {
    0,
};

u16 sprite_head_x = 0;  /* 02007ED4 */
u16 sprite_head_y = 0;  /* 02007ED6 */
u16 sprite_pad_x = 0;  /* 02007ED8 */
u16 sprite_pad_y = 0;  /* 02007EDA */
u32 spr_pool_busy = 0;  /* 02007EDC */
u32 poly_buf_offset = 0;  /* 02007EE0 */
s32 poly_cram_bank = 0;  /* 02007EE4 */
u32 bgm_tempo_add = 0;  /* 02007EE8 */

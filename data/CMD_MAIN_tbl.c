/*
 * CMD_MAIN_TBL.C  English game configuration screen layout
 *
 * config_title_str_tbl places the title and item lines of the English GAME CONFIGURATION page,
 * config_help_modify_str_tbl and config_help_return_str_tbl the help lines at the foot of the
 * page; the text itself is in CMD_MAIN_TBL_B.C. gcfg_gauge_chr_en and gcfg_gauge_clr_chr_en
 * are the characters of the star gauges. Read by GAME_CONFIG_EN.C, the English configuration
 * page.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 gcfg_line_title_en[];
extern const s8 gcfg_line_level_en[];
extern const s8 gcfg_help_modify_en[];
extern const s8 gcfg_help_shots_en[];
extern const s8 gcfg_help_select2_en[];
extern const s8 gcfg_help_return_en[];
extern const s8 gcfg_help_shot1_en[];
extern const s8 gcfg_line_damage_en[];
extern const s8 gcfg_line_timer_en[];
extern const s8 gcfg_line_1p_round_en[];
extern const s8 gcfg_line_2p_round_en[];
extern const s8 gcfg_line_event_en[];
extern const s8 gcfg_line_bonus_en[];
extern const s8 gcfg_line_exit_en[];
extern const s8 gcfg_help_select_en[];

const TM_STRING config_title_str_tbl[10] = {
    { 3, 1, 2, gcfg_line_title_en },
    { 5, 4, 2, gcfg_line_level_en },
    { 0x5, 6, 2, gcfg_line_damage_en },
    { 0x5, 8, 2, gcfg_line_timer_en },
    { 0x5, 10, 2, gcfg_line_1p_round_en },
    { 0x5, 12, 2, gcfg_line_2p_round_en },
    { 0x5, 14, 2, gcfg_line_event_en },
    { 0x5, 16, 2, gcfg_line_bonus_en },
    { 0x5, 18, 2, gcfg_line_exit_en },
    { 0x9, 25, 2, gcfg_help_select_en },
};

const TM_STRING config_help_modify_str_tbl[2] = {
    { 9, 26, 2, gcfg_help_modify_en },
    { 9, 27, 2, gcfg_help_shots_en },
};

const TM_STRING config_help_return_str_tbl[3] = {
    { 9, 25, 2, gcfg_help_select2_en },
    { 9, 26, 2, gcfg_help_return_en },
    { 0x9, 27, 2, gcfg_help_shot1_en },
};

const s16 gcfg_gauge_clr_chr_en = 42;

const s16 gcfg_gauge_chr_en[8] = {
    49, 50, 51, 52, 53, 54, 55, 56,
};

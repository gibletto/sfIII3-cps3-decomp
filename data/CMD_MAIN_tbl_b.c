/*
 * CMD_MAIN_TBL_B.C  English game configuration text and debug character sets
 *
 * gcfg_line_*_en and gcfg_help_*_en are the item and help lines of the English GAME
 * CONFIGURATION page, reached through the tables in CMD_MAIN_TBL.C. str_NORMAL_2 .. str_ON are
 * the setting values printed beside the items, read by GAME_CONFIG_EN.C. debug_charset_tbl
 * gives the charset_id loaded for each character number in the debug menu, read by CMD_MAIN.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const char gcfg_line_title_en[];
extern const char gcfg_line_level_en[];
extern const char gcfg_help_modify_en[];
extern const char gcfg_help_shots_en[];
extern const char gcfg_help_select2_en[];
extern const char gcfg_help_return_en[];
extern const char gcfg_help_shot1_en[];
extern const char gcfg_line_damage_en[];
extern const char gcfg_line_timer_en[];
extern const char gcfg_line_1p_round_en[];
extern const char gcfg_line_2p_round_en[];
extern const char gcfg_line_event_en[];
extern const char gcfg_line_bonus_en[];
extern const char gcfg_line_exit_en[];
extern const char gcfg_help_select_en[];

/* provisional name */
const char gcfg_line_title_en[44] = "7-2. G A M E   C O N F I G U R A T I O N\n";

/* provisional name */
const char gcfg_line_level_en[44] = "1. GAME DIFFICULTY   EASY[********]HARD\n";

/* provisional name */
const char gcfg_line_damage_en[40] = "2. DAMAGE LEVEL      LOW [****] HIGH\n";

/* provisional name */
const char gcfg_line_timer_en[40] = "3. TIMER SPEED       SLOW[****]FAST\n";

/* provisional name */
const char gcfg_line_1p_round_en[32] = "4. 1P MAX ROUND      3 ROUND\n";

/* provisional name */
const char gcfg_line_2p_round_en[32] = "5. 2P MAX ROUND      3 ROUND\n";

/* provisional name */
const char gcfg_line_event_en[28] = "6. EVENT             OFF\n";

/* provisional name */
const char gcfg_line_bonus_en[28] = "7. BONUS GAME        ON \n";

/* provisional name */
const char gcfg_line_exit_en[12] = "8. EXIT\n";

/* provisional name */
const char gcfg_help_select_en[32] = "SELECT OPTION  = 1P UP or DOWN";

/* provisional name */
const char gcfg_help_modify_en[36] = "MODIFY SETTING = 1P LEFT or RIGHT \n";

/* provisional name */
const char gcfg_help_shots_en[36] = "               = 1P SHOT1 or SHOT2";

/* provisional name */
const char gcfg_help_select2_en[36] = "SELECT OPTION  = 1P UP or DOWN    \n";

/* provisional name */
const char gcfg_help_return_en[36] = "RETURN TO CONFIGURATION MENU      \n";

/* provisional name */
const char gcfg_help_shot1_en[36] = "               = 1P SHOT1         ";
const char str_NORMAL_2[12] = "NORMAL  ";
const char str_WIDE[12] = "WIDE    ";
const char str_1_ROUND[12] = "1 ROUND ";
const char str_3_ROUNDS[12] = "3 ROUNDS";
const char str_5_ROUNDS[12] = "5 ROUNDS";
const char str_7_ROUNDS[12] = "7 ROUNDS";
const char str_OFF[8] = "OFF    ";
const char str_1_MATCH[8] = "1 MATCH";
const char str_OFF_2[4] = "OFF";
const char str_ON[4] = "ON ";

const u8 debug_charset_tbl[24] = {
    6, 3, 5, 1, 2, 9, 7, 4,
    10, 8, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 6, 6, 6,
};

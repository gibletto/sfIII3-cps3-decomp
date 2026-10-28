/*
 * COM_PL_TBL.C  region, boot screen, default settings and screen mode tables
 *
 * region_type_tbl, region_cc_type_tbl and region_param_tbl turn the region into the area type
 * and its parameters; boot_title_str, boot_region_str and boot_no_cd_str lay out the boot
 * screen, and the str_* strings are the boot, version and region warning text.
 * sys_cfg_default_* are the default system settings by cabinet type and region and
 * game_cfg_default_tbl_row* the default game settings by region, reached through the lists in
 * MODE_INIT.C. All read by MODE_INIT.C, except parental_advisory_msg (DEMO00.C, the
 * attract-mode logos), test_cursor_x_tbl and test_cursor_y_tbl (TEST_MODE.C, the test-mode
 * cursor) and the screen_* window, origin, display register and flip offset tables of each
 * screen mode (SCRN_CTRL.C). boot_version_str and screen_flip_ofs_tbl_tail are not referred to
 * by name.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const u8 game_cfg_default_tbl_row0[];
extern const u8 game_cfg_default_tbl_row1[];
extern const u8 game_cfg_default_tbl_row2[];
extern const u8 game_cfg_default_tbl_row3[];
extern const u8 game_cfg_default_tbl_row4[];
extern const u8 game_cfg_default_tbl_row5[];
extern const u8 game_cfg_default_tbl_row6[];
extern const u8 game_cfg_default_tbl_row7[];
extern const u8 game_cfg_default_tbl_row8[];
extern const s8 str_3rd_STRIKE[];
extern const s8 str_990512[];
extern const s8 str_ASIA[];
extern const s8 str_Animated_violence_Mild[];
extern const char str_Asian_countries_only[];
extern const s8 str_BENT_STAFF_VERSION[];
extern const s8 str_BRAZIL_3[];
extern const s8 str_BUG_CHECK_VERSION[];
extern const s8 str_CHARACTER_CHECK_VERSION[];
extern const s8 str_CHECK_VERSION[];
extern const char str_Canada_and_the_Federative_Republ[];
extern const s8 str_Contains_scenes_of_violence_invo[];
extern const s8 str_DEVELOPMENT_VERSION[];
extern const s8 str_EURO[];
extern const s8 str_HISPANIC[];
extern const s8 str_JAPAN[];
extern const s8 str_LOCATION_TEST_VERSION[];
extern const s8 str_NO_CD[];
extern const s8 str_OCEANIA[];
extern const s8 str_PRODUCT_VERSION[];
extern const s8 str_PUBLICITY_VERSION[];
extern const s8 str_Parental_Advisory[];
extern const s8 str_SHOW_VERSION[];
extern const s8 str_STREET_FIGHTER_III[];
extern const char str_Sales_export_or_operation_outsid[];
extern const char str_Sales_export_or_operation_outsid_2[];
extern const char str_This_game_is_for_use_in_japan_on[];
extern const char str_This_game_is_for_use_in_the_Euro[];
extern const char str_This_game_is_for_use_in_the_Fede[];
extern const char str_This_game_is_for_use_in_the_Ocea[];
extern const char str_This_game_is_for_use_in_the_Unit[];
extern const char str_This_game_is_for_use_in_the_West[];
extern const char str_This_game_is_for_use_in_the_sout[];
extern const s8 str_USA[];
extern const char str_Violators_are_subject_to_severe_[];
extern const char str_WARNING[];
extern const char str_and_trademark_infringement_and_i[];
extern const char str_and_will_be_prosecuted_to_the_fu[];
extern const s8 str_blank[];
extern const char str_blank_2[];
extern const s8 str_cartoon_like_characters_ina_fant[];
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

const s8 region_type_tbl[9] = {
    0, 0, 2, 5, 1, 3, 4, 7,
    2,
};

const s8 region_cc_type_tbl[8] = {
    0, 2, 1, 1, 1, 1, 1, 2,
};

const s8 region_param_tbl[3][2] = {
    { 0, 0 }, { 1, 2 }, { 2, 4 },
};

const TM_STRING boot_title_str[3] = {
    { 8, 8, 2, str_STREET_FIGHTER_III },
    { 8, 9, 2, str_3rd_STRIKE },
    { 17, 11, 2, str_990512 },
};

const TM_STRING boot_region_str[10] = {
    { 15, 13, 0xE, str_blank },
    { 19, 13, 2, str_JAPAN },
    { 19, 13, 4, str_ASIA },
    { 19, 13, 6, str_EURO },
    { 19, 13, 8, str_USA },
    { 16, 13, 0xA, str_HISPANIC },
    { 18, 13, 0xC, str_BRAZIL_3 },
    { 17, 13, 0xE, str_OCEANIA },
    { 19, 13, 4, str_ASIA },
    { 19, 13, 2, str_NO_CD },
};

const TM_STRING boot_version_str[9] = {
    { 16, 14, 0xE, str_PRODUCT_VERSION },
    { 13, 14, 0xE, str_CHARACTER_CHECK_VERSION },
    { 16, 14, 0xE, str_PUBLICITY_VERSION },
    { 15, 14, 0xE, str_LOCATION_TEST_VERSION },
    { 18, 14, 0xE, str_SHOW_VERSION },
    { 16, 14, 0xE, str_BUG_CHECK_VERSION },
    { 16, 14, 0xE, str_BENT_STAFF_VERSION },
    { 15, 14, 0xE, str_DEVELOPMENT_VERSION },
    { 17, 14, 0xE, str_CHECK_VERSION },
};

const TM_STRING boot_no_cd_str[1] = {
    { 20, 15, 2, str_NO_CD },
};

const TM_STRING parental_advisory_msg[4] = {
    { 6, 22, 0x28, str_Parental_Advisory },
    { 6, 23, 0x28, str_Animated_violence_Mild },
    { 1, 25, 0x28, str_Contains_scenes_of_violence_invo },
    { 1, 26, 0x28, str_cartoon_like_characters_ina_fant },
};

/* the boot and warning screens' text */
const s8 str_STREET_FIGHTER_III[36] = "S T R E E T   F I G H T E R   III\n";
const s8 str_3rd_STRIKE[28] = "       3 r d  S T R I K E\n";
const s8 str_990512[16] = " 9 9 0 5 1 2";
const s8 str_blank[16] = "             ";
const s8 str_JAPAN[12] = "J A P A N";
const s8 str_ASIA[12] = " A S I A";
const s8 str_EURO[12] = " E U R O ";
const s8 str_USA[12] = "  U S A  ";
const s8 str_HISPANIC[16] = "H I S P A N I C";
const s8 str_BRAZIL_3[12] = "B R A Z I L";
const s8 str_OCEANIA[16] = "O C E A N I A";
const s8 str_NO_CD[8] = " NO CD";
const s8 str_PRODUCT_VERSION[16] = "PRODUCT VERSION";
const s8 str_CHARACTER_CHECK_VERSION[24] = "CHARACTER CHECK VERSION";
const s8 str_PUBLICITY_VERSION[20] = "PUBLICITY VERSION";
const s8 str_LOCATION_TEST_VERSION[24] = "LOCATION TEST VERSION";
const s8 str_SHOW_VERSION[16] = "SHOW VERSION";
const s8 str_BUG_CHECK_VERSION[20] = "BUG CHECK VERSION";
const s8 str_BENT_STAFF_VERSION[20] = "BENT STAFF VERSION";
const s8 str_DEVELOPMENT_VERSION[20] = "DEVELOPMENT VERSION";
const s8 str_CHECK_VERSION[16] = "CHECK VERSION";
const char str_WARNING[12] = "WARNING\n";
const char str_This_game_is_for_use_in_japan_on[40] = "This game is for use in japan only.\n";
const char str_Sales_export_or_operation_outsid[44] = "Sales, export or operation outside this\n";
const char str_country_may_be_construed_as_copy[40] = "country may be construed as copyright\n";
const char str_and_trademark_infringement_and_i[44] = "and trademark infringement and is strictly\n";
const char str_prohibited[16] = "prohibited.\n";
const char str_Violators_are_subject_to_severe_[44] = "Violators are subject to severe penalties\n";
const char str_and_will_be_prosecuted_to_the_fu[44] = "and will be prosecuted to the full extent\n";
const char str_of_the_law[12] = "of the law.";
const char str_blank_2[4] = "";
const char str_This_game_is_for_use_in_the_sout[40] = "This game is for use in the south-east\n";
const char str_Asian_countries_only[24] = "Asian countries only.\n";
const char str_Sales_export_or_operation_outsid_2[44] = "Sales, export or operation outside these\n";
const char str_countries_may_be_construed_as_co[48] = "countries may be construed as copyright and\n";
const char str_trademark_infringement_and_is_st[40] = "trademark infringement and is strictly\n";
const char str_This_game_is_for_use_in_the_Euro[48] = "This game is for use in the European countries\n";
const char str_only[8] = "only.\n";
const char str_This_game_is_for_use_in_the_Unit[44] = "This game is for use in the United States\n";
const char str_of_America_and_Canada_only[32] = "of America and Canada only.\n";
const char str_This_game_is_for_use_in_the_West[48] = "This game is for use in the Western Hemisphere\n";
const char str_countries_except_the_United_Stat[48] = "countries except the United States of America,\n";
const char str_Canada_and_the_Federative_Republ[48] = "Canada, and the Federative Republic of Brazil.\n";
const char str_This_game_is_for_use_in_the_Fede[52] = "This game is for use in the Federative Republic\n";
const char str_of_Brazil_only[20] = "of Brazil only.\n";
const char str_country_may_be_construed_as_copy_2[44] = "country may be construed as copyright and\n";
const char str_This_game_is_for_use_in_the_Ocea[48] = "This game is for use in the Oceanian countries\n";
const s8 str_Parental_Advisory[20] = "Parental Advisory\n";
const s8 str_Animated_violence_Mild[28] = "Animated violence - Mild\n";
const s8 str_Contains_scenes_of_violence_invo[40] = "Contains scenes of violence involving\n";
const s8 str_cartoon_like_characters_ina_fant[48] = "cartoon-like characters in a fantasy setting.";
const u8 sys_cfg_default_0_0[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_1[32] = { 0, 9, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_2[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_4[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_3[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_5[32] = { 0, 9, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_6[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_7[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_0_8[32] = { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_0[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_1[32] = { 1, 9, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_2[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_4[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_3[32] = { 1, 0, 1, 5, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_5[32] = { 1, 9, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_6[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_7[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_1_8[32] = { 1, 0, 1, 5, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_0[32] = { 2, 0, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_1[32] = { 2, 9, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_2[32] = { 2, 0, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_4[32] = { 2, 0, 1, 10, 1, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_3[33] = { 2, 0, 1, 10, 1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_5[32] = { 2, 9, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_6[33] = { 2, 0, 1, 10, 1, 1, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_7[32] = { 2, 0, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 sys_cfg_default_2_8[32] = { 2, 0, 1, 10, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const u8 game_cfg_default_tbl_row0[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 0, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row1[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 3, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row2[16] = { 0, 7, 1, 1, 17, 0, 0, 1, 153, 4, 21, 1, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row3[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 4, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row4[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 5, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row5[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 2, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row6[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 6, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row7[16] = { 0, 2, 1, 1, 17, 0, 0, 1, 153, 4, 21, 7, 51, 51, 83, 32 };
const u8 game_cfg_default_tbl_row8[18] = { 0, 7, 1, 1, 17, 0, 0, 1, 153, 4, 21, 8, 51, 51, 83, 32, 0, 0 };

const u32 test_cursor_y_tbl[2][10] = {
    { 3, 5, 7, 9, 0xB, 0xD, 0xF, 0x11, 0x13, 0x15 },
    { 4, 6, 8, 0xA, 0xC, 0xE, 0x10, 0x12, 0x14, 0x16 },
};

const u32 test_cursor_x_tbl[2] = {
    0xE, 0xD,
};

const s16 screen_window_tbl[8][9] = {
    { 38, 80, 379, 454, 3, 21, 245, 262, 96 },
    { 35, 83, 411, 454, 3, 21, 245, 262, 97 },
    { 35, 92, 448, 454, 3, 21, 246, 262, 98 },
    { 42, 111, 495, 454, 3, 21, 245, 262, 99 },
    { 35, 98, 497, 454, 3, 21, 245, 262, 99 },
    { 35, 114, 551, 454, 3, 21, 245, 262, 100 },
    { 42, 143, 618, 454, 3, 21, 245, 262, 101 },
    { 35, 118, 613, 454, 3, 21, 245, 262, 101 },
};

const s16 screen_window_flip_tbl[9] = {
    35, 97, 606, 454, 3, 21, 245, 262,
    101,
};

const s16 screen_origin_tbl[8][2] = {
    { -65, -19 },
    { 0, 0 },
    { -80, -35 },
    { -101, -24 },
    { 0, 0 },
    { -114, -36 },
    { 0, 0 },
    { -107, -24 },
};

const s16 screen_disp_reg_tbl[8][4] = {
    { 46, 0, 152, 1 },
    { 46, 0, 187, 1 },
    { 49, 0, 229, 1 },
    { 62, 0, 22, 2 },
    { 54, 0, 22, 2 },
    { 58, 0, 83, 2 },
    { 74, 0, 159, 2 },
    { 64, 0, 159, 2 },
};

const s16 screen_flip_ofs_tbl[5][8] = {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 262, 128, 288, 0, 265, 128, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
};

/* Stored after screen_flip_ofs_tbl. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of screen_flip_ofs_tbl. */
const s16 screen_flip_ofs_tbl_tail[3] = {
    0, 0, 0,
};


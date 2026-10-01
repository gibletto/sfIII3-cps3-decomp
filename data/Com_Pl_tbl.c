/*
 * COM_PL_TBL.C  game tables
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
extern const char str_3rd_STRIKE[];
extern const char str_990512[];
extern const char str_ASIA[];
extern const char str_Animated_violence_Mild[];
extern const char str_Asian_countries_only[];
extern const char str_BENT_STAFF_VERSION[];
extern const char str_BRAZIL_3[];
extern const char str_BUG_CHECK_VERSION[];
extern const char str_CHARACTER_CHECK_VERSION[];
extern const char str_CHECK_VERSION[];
extern const char str_Canada_and_the_Federative_Republ[];
extern const char str_Contains_scenes_of_violence_invo[];
extern const char str_DEVELOPMENT_VERSION[];
extern const char str_EURO[];
extern const char str_HISPANIC[];
extern const char str_JAPAN[];
extern const char str_LOCATION_TEST_VERSION[];
extern const char str_NO_CD[];
extern const char str_OCEANIA[];
extern const char str_PRODUCT_VERSION[];
extern const char str_PUBLICITY_VERSION[];
extern const char str_Parental_Advisory[];
extern const char str_SHOW_VERSION[];
extern const char str_STREET_FIGHTER_III[];
extern const char str_Sales_export_or_operation_outsid[];
extern const char str_Sales_export_or_operation_outsid_2[];
extern const char str_This_game_is_for_use_in_japan_on[];
extern const char str_This_game_is_for_use_in_the_Euro[];
extern const char str_This_game_is_for_use_in_the_Fede[];
extern const char str_This_game_is_for_use_in_the_Ocea[];
extern const char str_This_game_is_for_use_in_the_Unit[];
extern const char str_This_game_is_for_use_in_the_West[];
extern const char str_This_game_is_for_use_in_the_sout[];
extern const char str_USA[];
extern const char str_Violators_are_subject_to_severe_[];
extern const char str_WARNING[];
extern const char str_and_trademark_infringement_and_i[];
extern const char str_and_will_be_prosecuted_to_the_fu[];
extern const char str_blank[];
extern const char str_blank_2[];
extern const char str_cartoon_like_characters_ina_fant[];
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

extern void Check_No12_Shell_Guard();
extern void Com_Active();
extern void Com_Before_Follow();
extern void Com_Before_Passive();
extern void Com_Catch();
extern void Com_Caught();
extern void Com_Damage();
extern void Com_Flip();
extern void Com_Float();
extern void Com_Follow();
extern void Com_Free();
extern void Com_Guard();
extern void Com_Initialize();
extern void Com_Passive();
extern void Com_VS_Shell();
extern void Com_Wait_Lie();
extern void Computer00();
extern void Computer01();
extern void Computer02();
extern void Computer03();
extern void Computer04();
extern void Computer05();
extern void Computer06();
extern void Computer07();
extern void Computer08();
extern void Computer09();
extern void Computer10();
extern void Computer11();
extern void Computer12();
extern void Computer13();
extern void Computer14();
extern void Computer15();
extern void Computer16();
extern void Computer17();
extern void Computer18();
extern void Computer19();
extern void Computer20();
extern void Damage_1st();
extern void Damage_2nd();
extern void Damage_3rd();
extern void Damage_4th();
extern void Damage_5th();
extern void Damage_6th();
extern void Damage_7th();
extern void Damage_8th();
extern void Flip_1st();
extern void Flip_2nd();
extern void Flip_3rd();
extern void Flip_4th();
extern void Flip_Zero();
extern void Float_2nd();
extern void Float_3rd();
extern void Float_4th();
extern void Follow02();
extern void Passive00();
extern void Passive01();
extern void Passive02();
extern void Passive03();
extern void Passive04();
extern void Passive05();
extern void Passive06();
extern void Passive07();
extern void Passive08();
extern void Passive09();
extern void Passive10();
extern void Passive11();
extern void Passive12();
extern void Passive13();
extern void Passive14();
extern void Passive15();
extern void Passive16();
extern void Passive17();
extern void Passive18();
extern void Passive19();
extern void Passive20();
extern void Shell00();
extern void Shell01();
extern void Shell03();
extern void Shell04();
extern void Shell05();
extern void Shell07();
extern void Shell11();
extern void Shell12();
extern void Shell13();
extern void Shell14();

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
    { 8, 8, 2, (void*)str_STREET_FIGHTER_III },
    { 8, 9, 2, (void*)str_3rd_STRIKE },
    { 0x11, 0xB, 2, (void*)str_990512 },
};

const TM_STRING boot_region_str[10] = {
    { 0xF, 0xD, 0xE, (void*)str_blank },
    { 0x13, 0xD, 2, (void*)str_JAPAN },
    { 0x13, 0xD, 4, (void*)str_ASIA },
    { 0x13, 0xD, 6, (void*)str_EURO },
    { 0x13, 0xD, 8, (void*)str_USA },
    { 0x10, 0xD, 0xA, (void*)str_HISPANIC },
    { 0x12, 0xD, 0xC, (void*)str_BRAZIL_3 },
    { 0x11, 0xD, 0xE, (void*)str_OCEANIA },
    { 0x13, 0xD, 4, (void*)str_ASIA },
    { 0x13, 0xD, 2, (void*)str_NO_CD },
};

/* Stored after boot_region_str. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of boot_region_str. */
const u32 boot_region_str_tail[27] = {
    0x10000E, 0xE0000, (u32)str_PRODUCT_VERSION, 0xD000E,
    0xE0000, (u32)str_CHARACTER_CHECK_VERSION, 0x10000E, 0xE0000,
    (u32)str_PUBLICITY_VERSION, 0xF000E, 0xE0000, (u32)str_LOCATION_TEST_VERSION,
    0x12000E, 0xE0000, (u32)str_SHOW_VERSION, 0x10000E,
    0xE0000, (u32)str_BUG_CHECK_VERSION, 0x10000E, 0xE0000,
    (u32)str_BENT_STAFF_VERSION, 0xF000E, 0xE0000, (u32)str_DEVELOPMENT_VERSION,
    0x11000E, 0xE0000, (u32)str_CHECK_VERSION,
};

const TM_STRING boot_no_cd_str[1] = {
    { 0x14, 0xF, 2, (void*)str_NO_CD },
};

const TM_STRING parental_advisory_msg[4] = {
    { 6, 0x16, 0x28, (void*)str_Parental_Advisory },
    { 6, 0x17, 0x28, (void*)str_Animated_violence_Mild },
    { 1, 0x19, 0x28, (void*)str_Contains_scenes_of_violence_invo },
    { 1, 0x1A, 0x28, (void*)str_cartoon_like_characters_ina_fant },
};

/* the boot and warning screens' text */
const char str_STREET_FIGHTER_III[36] = "S T R E E T   F I G H T E R   III\n";
const char str_3rd_STRIKE[28] = "       3 r d  S T R I K E\n";
const char str_990512[16] = " 9 9 0 5 1 2";
const char str_blank[16] = "             ";
const char str_JAPAN[12] = "J A P A N";
const char str_ASIA[12] = " A S I A";
const char str_EURO[12] = " E U R O ";
const char str_USA[12] = "  U S A  ";
const char str_HISPANIC[16] = "H I S P A N I C";
const char str_BRAZIL_3[12] = "B R A Z I L";
const char str_OCEANIA[16] = "O C E A N I A";
const char str_NO_CD[8] = " NO CD";
const char str_PRODUCT_VERSION[16] = "PRODUCT VERSION";
const char str_CHARACTER_CHECK_VERSION[24] = "CHARACTER CHECK VERSION";
const char str_PUBLICITY_VERSION[20] = "PUBLICITY VERSION";
const char str_LOCATION_TEST_VERSION[24] = "LOCATION TEST VERSION";
const char str_SHOW_VERSION[16] = "SHOW VERSION";
const char str_BUG_CHECK_VERSION[20] = "BUG CHECK VERSION";
const char str_BENT_STAFF_VERSION[20] = "BENT STAFF VERSION";
const char str_DEVELOPMENT_VERSION[20] = "DEVELOPMENT VERSION";
const char str_CHECK_VERSION[16] = "CHECK VERSION";
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
const char str_Parental_Advisory[20] = "Parental Advisory\n";
const char str_Animated_violence_Mild[28] = "Animated violence - Mild\n";
const char str_Contains_scenes_of_violence_invo[40] = "Contains scenes of violence involving\n";
const char str_cartoon_like_characters_ina_fant[48] = "cartoon-like characters in a fantasy setting.";
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

const u16 Correct_Lv_Data[22] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0x106, 0x16,
    288, 0, 265, 0, 0, 0,
};

/* Initial values of Com_Jmp_Tbl (Main_Program), Char_Jmp_Tbl (Com_Active), Follow_Jmp_Tbl (Com_Follow), Passive_Jmp_Tbl (Com_Passive), VS_Shell_Jmp_Tbl (Com_VS_Shell), Damage_Jmp_Tbl (Com_Damage), Float_Jmp_Tbl (Com_Float), Flip_Jmp_Tbl (Com_Flip) in Com_Pl.c. */
const u32 Com_Pl_local_init[119] = {
    (u32)Com_Initialize, (u32)Com_Free, (u32)Com_Active, (u32)Com_Before_Follow,
    (u32)Com_Follow, (u32)Com_Before_Passive, (u32)Com_Passive, (u32)Com_Guard,
    (u32)Com_VS_Shell, (u32)Check_No12_Shell_Guard, (u32)Com_Damage, (u32)Com_Float,
    (u32)Com_Flip, (u32)Com_Caught, (u32)Com_Wait_Lie, (u32)Com_Catch,
    (u32)Computer00, (u32)Computer01, (u32)Computer02, (u32)Computer03,
    (u32)Computer04, (u32)Computer05, (u32)Computer06, (u32)Computer07,
    (u32)Computer08, (u32)Computer09, (u32)Computer10, (u32)Computer11,
    (u32)Computer12, (u32)Computer13, (u32)Computer14, (u32)Computer15,
    (u32)Computer16, (u32)Computer17, (u32)Computer18, (u32)Computer19,
    (u32)Computer20, (u32)Follow02, (u32)Follow02, (u32)Follow02,
    (u32)Follow02, (u32)Follow02, (u32)Follow02, (u32)Follow02,
    (u32)Follow02, (u32)Follow02, (u32)Follow02, (u32)Follow02,
    (u32)Follow02, (u32)Follow02, (u32)Follow02, (u32)Follow02,
    (u32)Follow02, (u32)Follow02, (u32)Follow02, (u32)Follow02,
    (u32)Follow02, (u32)Follow02, (u32)Passive00, (u32)Passive01,
    (u32)Passive02, (u32)Passive03, (u32)Passive04, (u32)Passive05,
    (u32)Passive06, (u32)Passive07, (u32)Passive08, (u32)Passive09,
    (u32)Passive10, (u32)Passive11, (u32)Passive12, (u32)Passive13,
    (u32)Passive14, (u32)Passive15, (u32)Passive16, (u32)Passive17,
    (u32)Passive18, (u32)Passive19, (u32)Passive20, (u32)Shell00,
    (u32)Shell01, (u32)Shell11, (u32)Shell03, (u32)Shell04,
    (u32)Shell05, (u32)Shell03, (u32)Shell07, (u32)Shell03,
    (u32)Shell03, (u32)Shell03, (u32)Shell11, (u32)Shell12,
    (u32)Shell13, (u32)Shell14, (u32)Shell14, (u32)Shell11,
    (u32)Shell11, (u32)Shell11, (u32)Shell11, (u32)Shell11,
    (u32)Damage_1st, (u32)Damage_2nd, (u32)Damage_3rd, (u32)Damage_4th,
    (u32)Damage_5th, (u32)Damage_6th, (u32)Damage_7th, (u32)Damage_7th,
    (u32)Damage_7th, (u32)Damage_8th, (u32)Damage_2nd, (u32)Float_2nd,
    (u32)Float_3rd, (u32)Float_4th, (u32)Flip_Zero, (u32)Flip_1st,
    (u32)Flip_2nd, (u32)Flip_3rd, (u32)Flip_4th,
};

const u16 Rapid_Lever_Data[2] = {
    8, 4,
};

/* Stored after Rapid_Lever_Data. Nothing in the program refers to it by name or address; if it is read,
   it is through an index past the end of Rapid_Lever_Data. */
const u8 Rapid_Lever_Data_tail[17] = {
    0, 0, 0, 0, 9, 9, 37, 9, 9, 9, 9, 9, 9, 9, 9, 9,
    9,
};

const u8 Pattern_Insurance_Data[21][4] = {
    { 67, 157, 10, 3 },
    { 69, 175, 9, 3 },
    { 74, 132, 10, 3 },
    { 71, 135, 10, 3 },
    { 67, 141, 11, 3 },
    { 66, 101, 10, 3 },
    { 63, 146, 10, 3 },
    { 75, 213, 11, 3 },
    { 70, 213, 10, 3 },
    { 100, 131, 10, 3 },
    { 69, 137, 10, 3 },
    { 89, 254, 13, 3 },
    { 85, 230, 10, 3 },
    { 80, 167, 11, 3 },
    { 150, 252, 12, 3 },
    { 148, 248, 12, 3 },
    { 68, 163, 13, 3 },
    { 69, 166, 13, 3 },
    { 82, 181, 13, 3 },
    { 108, 203, 13, 3 },
    { 78, 175, 13, 3 },
};


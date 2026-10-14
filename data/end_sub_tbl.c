/*
 * END_SUB_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void debug_play07_init();
extern void debug_play07_move();
extern void debug_play08_init();
extern void debug_play08_move();
extern void debug_play09_init();
extern void debug_play09_move();
extern void debug_play10_init();
extern void debug_play10_move();
extern void debug_play11_init();
extern void debug_play11_move();
extern void debug_play12_init();
extern void debug_play12_move();
extern void debug_play13_init();
extern void debug_play13_move();
extern const STAFF_LINE staff_roll_tbl[];
extern const char staff_STREET_FIGHTER_3rd_STRIKE[];
extern const char staff_Fight_for_the_Future[];
extern const char staff_STAFF[];
extern const char staff_CHARACTER_DESIGN[];
extern const char staff_WHO[];
extern const char staff_IKUSAN_Z[];
extern const char staff_D_Kurita[];
extern const char staff_Chimorin_SHOGUN[];
extern const char staff_SIBAKI[];
extern const char staff_Chunzenji_Rute[];
extern const char staff_Tsuyoshi[];
extern const char staff_Jun_Ikawa[];
extern const char staff_Toshihiro_Suzuki[];
extern const char staff_NOYA_T[];
extern const char staff_Seiji_Yano[];
extern const u8 staff_blank[];
extern const char staff_TOMO[];
extern const char staff_HIRANO_DAICHI[];
extern const char staff_Izumi_N[];
extern const char staff_AKIMAN[];
extern const char staff_SCROLL_DESIGN[];
extern const char staff_IMAHORI_75[];
extern const char staff_SUGIYAMA_50[];
extern const char staff_YOUKO_FUKUMOTO[];
extern const char staff_YUKI_KYOTANI[];
extern const char staff_SAWATCH[];
extern const char staff_ATUSHI[];
extern const char staff_RYO_UNO[];
extern const char staff_Yusuke_Saiwai[];
extern const char staff_KENICHI_YAMAHASHI[];
extern const char staff_ORIGINAL_ART_WORK[];
extern const char staff_DAIGORO[];
extern const char staff_HARUMARU[];
extern const char staff_TITLE_LOGO_DESIGN[];
extern const char staff_Y_UCHIDA[];
extern const char staff_INSTRACTION_DESIGN[];
extern const char staff_SAKOMIZU[];
extern const char staff_PROGRAMMING[];
extern const char staff_KAZUHITO_NAKAI[];
extern const u8 staff_blank_2[];
extern const char staff_YUKO_KAWAMURA_TATE[];
extern const char staff_HIROSHI_NAKAGAWA_RAOH[];
extern const char staff_Y_M_INADA_INE[];
extern const char staff_MASAHITO_Oh_Ya[];
extern const char staff_AKIHIRO_YOKOYAMA[];
extern const char staff_SOUND_EFFECT_DESIGN[];
extern const char staff_SATOSHI_ISE[];
extern const char staff_Y_SANDOU[];
extern const char staff_MUSIC_COMPOSE[];
extern const char staff_H_OKUGAWA[];
extern const char staff_SOUND_EDITOR[];
extern const char staff_KAZUYA_TAKIMOTO[];
extern const char staff_SOUND_MANAGEMENT_DIRECTER[];
extern const u8 staff_blank_3[];
extern const char staff_Third_Strike_Opening_Theme_S[];
extern const char staff_Let_s_Get_It_On_Event_Theme_[];
extern const char staff_Moving_On_Ending_Song[];
extern const char staff_Song_Written_by_Infinite_hid[];
extern const char staff_Arrengerd_by_hideki[];
extern const char staff_blank_4[];
extern const char staff_Vocals[];
extern const char staff_Courtesy_of_Lock_Down_Entert[];
extern const char staff_RECORDING_ENGINEER[];
extern const char staff_Yutaka_Shimoyama_Victor_St[];
extern const char staff_MIX_ENGINEER[];
extern const char staff_Paul_Shubat[];
extern const char staff_ASSISTANT_ENGINEER[];
extern const char staff_Vladimir_Nikolic[];
extern const char staff_ARTIST_MANAGEMENT[];
extern const char staff_Cain_Lock_Down_Entertainment[];
extern const char staff_VOICE_ACTOR[];
extern const char staff_TOURU_OHKAWA[];
extern const char staff_YUJI_KISHI[];
extern const char staff_MITSUO_IWATA[];
extern const char staff_KENTARO_ITOU[];
extern const char staff_MASAKAZU_SUZUKI[];
extern const char staff_YURI_AMANO[];
extern const char staff_MIE_MIDORI[];
extern const char staff_TAKASHI_MATSUYAMA[];
extern const char staff_TOMOMICHI_NISHIMURA[];
extern const char staff_MAKOTO_TSUMURA[];
extern const char staff_EIJI_SEKIGUCHI[];
extern const char staff_ATSUKO_TANAKA[];
extern const char staff_LAWRENCE_BAYNE[];
extern const char staff_PATRICK_GALLAGAN[];
extern const char staff_FRANCIS_DIAKEWSKY[];
extern const char staff_LEN_CARLSON[];
extern const char staff_PLANNING[];
extern const char staff_Neo_G_H_ISHIZAWA[];
extern const char staff_HARUO_MURATA[];
extern const char staff_NUMACH_T_O[];
extern const char staff_YASUNORI_ICHINOSE[];
extern const char staff_SADA_36[];
extern const char staff_SPECIAL_THANKS[];
extern const char staff_YOUICHI_EGAWA[];
extern const char staff_T_SHIRAIWA[];
extern const char staff_ABU[];
extern const char staff_TOMOAKI_TSUJI[];
extern const char staff_TOBUTO_MAM2_DEZAKI[];
extern const char staff_MITSUAKI_TIM2_ARAKI[];
extern const char staff_TAKEchan[];
extern const char staff_ONI_SUZUKI[];
extern const char staff_BUG_H_SUGIMOTO[];
extern const char staff_K_SHINANO[];
extern const char staff_GON[];
extern const char staff_SYACHI_S_OHOKA[];
extern const char staff_YNG_J_MATSUBARA[];
extern const char staff_MIURA_CUBERICK[];
extern const char staff_TETSUYA_HAZE[];
extern const char staff_YOSHIHIRO_TOMITA[];
extern const char staff_HMX_12_HAMADA[];
extern const char staff_MASAYASU_MUKAI[];
extern const char staff_PUNCH_KUBOZONO[];
extern const char staff_TETSUYA_IIJIMA[];
extern const char staff_LISA_E_JONES[];
extern const char staff_MASAYUKI_FUKUMOTO[];
extern const char staff_LANCE_LUU[];
extern const char staff_NATE_WILLIAMS[];
extern const char staff_MESSAGE_TRANSLATOR[];
extern const char staff_ERIK_SUZUKI[];
extern const char staff_DAN_OKADA[];
extern const char staff_CHRIS_TANG[];
extern const char staff_PRODUCER[];
extern const char staff_NORITAKA_FUNAMIZU[];
extern const char staff_KOUJI_NAKAJIMA[];
extern const char staff_GENERAL_PRODUCER[];
extern const char staff_YOSHIKI_OKAMOTO[];
extern const char staff_AND_CAPCOM_ALL_STAFF[];
extern const char staff_blank_5[];
extern const char staff_THANK_YOU_FOR_PLAYING[];
extern const char staff_PRESENTED_BY[];
extern const char staff_STREET_FIGHTER_2ND_IMPACT[];
extern const char staff_GIANT_ATTACK[];
extern const char staff_STAFF_2[];
extern const char staff_CHARACTER_DESIGN_2[];
extern const char staff_W_O[];
extern const char staff_H[];
extern const char staff_D_K_R_T[];
extern const char staff_U_I_A[];
extern const char staff_C_I_O_I_H_G_N[];
extern const char staff_H_M_R_N_S_O_U[];
extern const char staff_S_I_A_I[];
extern const char staff_H_B_K[];
extern const char staff_C_u[];
extern const char staff_h_n[];
extern const char staff_J_N_I_A_A[];
extern const char staff_U_K_W[];
extern const char staff_S_I_I_Y_N[];
extern const char staff_E_J_A_O[];
extern const char staff_Y_K_S_I_A_A[];
extern const char staff_U_I_I_H_K_W[];
extern const char staff_S_I_N_S_K[];
extern const char staff_H_N_O_U_E_N[];
extern const char staff_SCROLL_DESIGN_2[];
extern const char staff_H_R_S_I_S_G_Y_M[];
extern const char staff_I_O_H_U_I_A_A[];
extern const char staff_Y_K_U_U_O_O[];
extern const char staff_O_O_F_K_M_T[];
extern const char staff_H_R_Y_K_M_H_R[];
extern const char staff_I_O_U_I_I_A_O_I[];
extern const char staff_O_I_I[];
extern const char staff_J_J[];
extern const char staff_N_O_E[];
extern const char staff_A_B_I[];
extern const char staff_A_E_I_K_H_M[];
extern const char staff_K_M_O_A_A[];
extern const char staff_T_M[];
extern const char staff_A_A[];
extern const char staff_Y_M_M_T_O_I[];
extern const char staff_A_A_O_O_K_J[];
extern const char staff_K_U_C_I_T_K_D[];
extern const char staff_O_I_H_A_E_A[];
extern const char staff_ORIGINAL_ART_WORK_2[];
extern const char staff_A_I_A[];
extern const char staff_K_M_N[];
extern const char staff_K_N_I_H_M_R[];
extern const char staff_I_U_N_S_I_U_A[];
extern const char staff_N[];
extern const char staff_K[];
extern const char staff_TITLE_LOGO_DESIGN_2[];
extern const char staff_S_O_I[];
extern const char staff_H_E[];
extern const char staff_INSTRACTION_DESIGN_2[];
extern const char staff_S_K_M_Z[];
extern const char staff_A_O_I_U[];
extern const char staff_PROGRAMMING_2[];
extern const char staff_K_Z_H_T_A_A[];
extern const char staff_A_U_I_O_N_K_I[];
extern const u8 staff_blank_6[];
extern const char staff_O_U_A_L_1_Y_S_I_U_I[];
extern const char staff_Y_K_A_A_U_A_T_T[];
extern const char staff_U_O_K_W_M_R_A_E[];
extern const char staff_H_R_S_I_N_K_G_W[];
extern const char staff_I_O_H_A_A_A_A[];
extern const char staff_Y_S_I_O_U_I_A_A_I_E[];
extern const char staff_O_H_N_B_N_D_N[];
extern const char staff_M_S_H_T_h_Y[];
extern const char staff_A_A_I_O_O_a[];
extern const char staff_A_I_I_O_Y_K_Y_M[];
extern const char staff_K_H_R_O_O_A_A[];
extern const char staff_SOUND_EFFECT_DESIGN_2[];
extern const char staff_S_T_S_I_I_E[];
extern const char staff_A_O_H_S[];
extern const u8 staff_blank_7[];
extern const u8 staff_blank_8[];
extern const char staff_MUSIC_COMPOSE_2[];
extern const char staff_H_D_K_K_G_W[];
extern const char staff_I_E_I_O_U_A_A[];
extern const char staff_Y_K_W_I[];
extern const char staff_U_I_I_A[];
extern const char staff_MUSIC_ARRANGEMENT[];
extern const char staff_PLANNING_2[];
extern const char staff_S_T_A_U_I_O[];
extern const char staff_E_O_Y_S_H_R[];
extern const char staff_N_O_G_S_I_A_A[];
extern const char staff_E_H_I_H_Z_W[];
extern const char staff_N_M_C[];
extern const char staff_U_A_H[];
extern const char staff_VOICE_ACTOR_2[];
extern const char staff_Y_J_E_A[];
extern const char staff_U_I_U_D[];
extern const char staff_W_T_R_A_A_I[];
extern const char staff_A_A_U_T_K_G[];
extern const char staff_T_M_M_C_I_N_S_I_U_A[];
extern const char staff_O_O_I_H_I_H_M_R[];
extern const char staff_K_H_R_U_I_O[];
extern const char staff_A_O_U_F_J_N[];
extern const char staff_Y_R_M_N[];
extern const char staff_U_I_A_A_O[];
extern const char staff_I_S_I_H_B[];
extern const char staff_S_H_N_C_I_A[];
extern const char staff_K_N_T_K_M_R[];
extern const char staff_A_O_U_A_U[];
extern const char staff_K_J_O_E[];
extern const char staff_O_I_T_B[];
extern const char staff_B_U_E_R_B_R_S_N[];
extern const char staff_R_C_O_E_T_O[];
extern const char staff_M_C_A_L_S_M_E_S[];
extern const char staff_I_H_E_O_M_R[];
extern const char staff_MESSAGE_TRANSLATOR_2[];
extern const char staff_E_I_U_U_I[];
extern const char staff_R_K_S_Z_K[];
extern const char staff_D_N_O_A_A[];
extern const char staff_A_K_D[];
extern const char staff_C_R_S_T_N[];
extern const char staff_H_I_A_G[];
extern const char staff_Y_M_K_I_H[];
extern const char staff_U_I_O_N_S_I[];
extern const char staff_K_R_A_O_H_R_E_F_E_T_S[];
extern const char staff_A_L_S_I_O_D_R_I_A[];
extern const char staff_SPECIAL_THANKS_2[];
extern const char staff_T_U_O_H[];
extern const char staff_S_Y_S_I[];
extern const char staff_M_Y_N[];
extern const char staff_A_A_O[];
extern const char staff_O_O[];
extern const char staff_B_B_N[];
extern const char staff_L_O[];
extern const char staff_T_K_F_M_A_A_A[];
extern const char staff_A_A_U_I_S_G_T[];
extern const char staff_M_A_K[];
extern const char staff_O_I[];
extern const char staff_N_A_E[];
extern const char staff_K_I[];
extern const char staff_H_N_K_M_R[];
extern const char staff_A_A_U_A[];
extern const char staff_H_O_I_A[];
extern const char staff_J_M[];
extern const u8 staff_blank_9[];
extern const u8 staff_blank_10[];
extern const char staff_T_K_Y_H_R_I_A[];
extern const char staff_A_U_A_S_I_A_W[];
extern const char staff_R_T_O_O[];
extern const char staff_I_A_R_K_S[];
extern const char staff_R_o_i[];
extern const char staff_y_j[];
extern const char staff_H_R_A_O_L_W[];
extern const char staff_A_D_Y_S_F_L_O[];
extern const char staff_C_U_H_C_E_S[];
extern const char staff_S_B_G_C_E_K_R[];
extern const char staff_K_N_S_I_E_M_T_U_A_A[];
extern const char staff_U_I_H_G_A_S_B_R[];
extern const char staff_M_N_B_A_S_M_T[];
extern const char staff_A_A_U_M_T_U_O_O[];
extern const char staff_T_M_Y_K_O_O_A[];
extern const char staff_O_O_U_I_Y_K_T[];
extern const char staff_T_T_U_A_H_Z[];
extern const char staff_E_S_Y_A_E[];
extern const char staff_K_T_U_U_E_M_U_A[];
extern const char staff_A_S_S_K_I_R[];
extern const char staff_M_S_H_R_A_I_A_I[];
extern const char staff_A_A_I_O_K_J_T_N[];
extern const char staff_T_K_S_I_H_S_I_O_O[];
extern const char staff_A_A_H_A_H_M_T[];
extern const char staff_T_S_I_I_O_K_R_T[];
extern const char staff_O_H_H_K_U_A_A[];
extern const char staff_Y_S_I_I_O_T_M_T[];
extern const char staff_O_H_H_R_O_I_A[];
extern const char staff_D_I_U_E_S_S_K[];
extern const char staff_A_S_K_A_A_I[];
extern const char staff_A_I_O_I_M_R_T[];
extern const char staff_K_N_R_U_A_A[];
extern const char staff_S_I_L_S_I_H_T_S_P_A[];
extern const char staff_K_L_M_T_E_T_L_Y[];
extern const char staff_T_K_K_S[];
extern const char staff_T[];
extern const char staff_H_R_S_I_S_G_M_T_U[];
extern const char staff_I_O_H_U_I_O_O_B_G[];
extern const char staff_G_N[];
extern const char staff_O[];
extern const char staff_K_H_U_E_A_A_K[];
extern const char staff_O_S_K_R_I_T_O[];
extern const char staff_PRODUCER_2[];
extern const char staff_T_M_S_I_S_D_M_T[];
extern const char staff_O_O_H_A_A_O_O[];
extern const char staff_GENERAL_PRODUCER_2[];
extern const char staff_N_R_T_K_U_A_I_U[];
extern const char staff_O_I_A_A_F_N_M_Z[];
extern const char staff_Y_S_I_I_O_A_O_O[];
extern const char staff_O_H_K_K_M_T[];
extern const char staff_blank_11[];

const s8 no_card_mes[8] = "NO CARD";

const s8 no_card_clr_mes[8] = "       ";

const s8 win_card_clr_mes[16] = "            ";

const s8 win_card_mes[16] = "WIN THE CARD";

const char no_cd_drive_mes[16] = "NO CD-ROM DRIVE";

const char no_cd_rom_mes[42] = {
    78, 79, 32, 67, 68, 45, 82, 79,
    77, 0, 0, 0, 1, -5, 0, 0,
    2, -84, 0, 0, 1, -116, 0, 0,
    1, -54, 0, 0, 2, 110, 0, 0,
    2, 23, 0, 0, 0, -54, 0, 120,
    0, -84,
};

const s8 combo_demo_pl_tbl[3][6] = {
    { 2, 1, 0, 13, 0, 0 },
    { 1, 1, 0, 6, 1, 0 },
    { 3, 0, 0, 10, 0, 0 },
};

const STAFF_LINE staff_roll_tbl[340] = {
    { -1, 48, 128, 3, (const u8*)staff_STREET_FIGHTER_3rd_STRIKE },
    { -1, 48, 96, 3, (const u8*)staff_Fight_for_the_Future },
    { -1, 48, 64, 3, (const u8*)staff_STAFF },
    { 30, 96, 160, 8, (const u8*)staff_CHARACTER_DESIGN },
    { 20, 96, 136, 6, (const u8*)staff_WHO },
    { 20, 96, 136, 6, (const u8*)staff_IKUSAN_Z },
    { 20, 96, 136, 6, (const u8*)staff_D_Kurita },
    { 20, 96, 136, 6, (const u8*)staff_Chimorin_SHOGUN },
    { 20, 104, 136, 6, (const u8*)staff_SIBAKI },
    { 20, 96, 136, 6, (const u8*)staff_Chunzenji_Rute },
    { 20, 96, 136, 6, (const u8*)staff_Tsuyoshi },
    { 20, 96, 136, 6, (const u8*)staff_Jun_Ikawa },
    { 20, 96, 136, 6, (const u8*)staff_Toshihiro_Suzuki },
    { 20, 96, 136, 6, (const u8*)staff_NOYA_T },
    { 20, 96, 136, 6, (const u8*)staff_Seiji_Yano },
    { 20, 96, 136, 6, (const u8*)staff_blank },
    { 20, 96, 136, 6, (const u8*)staff_TOMO },
    { 20, 88, 136, 6, (const u8*)staff_HIRANO_DAICHI },
    { 20, 96, 136, 6, (const u8*)staff_Izumi_N },
    { 60, 96, 136, 6, (const u8*)staff_AKIMAN },
    { 30, 96, 160, 8, (const u8*)staff_SCROLL_DESIGN },
    { 20, 96, 136, 6, (const u8*)staff_IMAHORI_75 },
    { 20, 104, 136, 6, (const u8*)staff_SUGIYAMA_50 },
    { 20, 88, 136, 6, (const u8*)staff_YOUKO_FUKUMOTO },
    { 20, 88, 136, 6, (const u8*)staff_YUKI_KYOTANI },
    { 20, 96, 136, 6, (const u8*)staff_SAWATCH },
    { 20, 96, 136, 6, (const u8*)staff_ATUSHI },
    { 20, 96, 136, 6, (const u8*)staff_RYO_UNO },
    { 20, 88, 136, 6, (const u8*)staff_Yusuke_Saiwai },
    { 60, 96, 136, 6, (const u8*)staff_KENICHI_YAMAHASHI },
    { 30, 96, 160, 8, (const u8*)staff_ORIGINAL_ART_WORK },
    { 20, 88, 136, 6, (const u8*)staff_DAIGORO },
    { 60, 88, 136, 6, (const u8*)staff_HARUMARU },
    { 30, 96, 160, 8, (const u8*)staff_TITLE_LOGO_DESIGN },
    { 60, 88, 136, 6, (const u8*)staff_Y_UCHIDA },
    { 30, 96, 160, 8, (const u8*)staff_INSTRACTION_DESIGN },
    { 60, 96, 136, 6, (const u8*)staff_SAKOMIZU },
    { 30, 96, 160, 8, (const u8*)staff_PROGRAMMING },
    { 20, 88, 136, 6, (const u8*)staff_KAZUHITO_NAKAI },
    { 20, 96, 136, 6, (const u8*)staff_blank_2 },
    { 20, 88, 136, 6, (const u8*)staff_YUKO_KAWAMURA_TATE },
    { 20, 88, 136, 6, (const u8*)staff_HIROSHI_NAKAGAWA_RAOH },
    { 20, 96, 136, 6, (const u8*)staff_Y_M_INADA_INE },
    { 40, 88, 136, 6, (const u8*)staff_MASAHITO_Oh_Ya },
    { 60, 88, 136, 6, (const u8*)staff_AKIHIRO_YOKOYAMA },
    { 30, 96, 160, 8, (const u8*)staff_SOUND_EFFECT_DESIGN },
    { 20, 104, 136, 6, (const u8*)staff_SATOSHI_ISE },
    { 60, 96, 136, 6, (const u8*)staff_Y_SANDOU },
    { 30, 96, 160, 8, (const u8*)staff_MUSIC_COMPOSE },
    { 60, 96, 136, 6, (const u8*)staff_H_OKUGAWA },
    { 30, 96, 160, 8, (const u8*)staff_SOUND_EDITOR },
    { 60, 88, 136, 6, (const u8*)staff_KAZUYA_TAKIMOTO },
    { 30, 96, 160, 8, (const u8*)staff_SOUND_MANAGEMENT_DIRECTER },
    { 60, 88, 136, 6, (const u8*)staff_blank_3 },
    { 20, 48, 136, 8, (const u8*)staff_Third_Strike_Opening_Theme_S },
    { 20, 48, 136, 8, (const u8*)staff_Let_s_Get_It_On_Event_Theme_ },
    { 40, 48, 136, 8, (const u8*)staff_Moving_On_Ending_Song },
    { 20, 48, 136, 6, (const u8*)staff_Song_Written_by_Infinite_hid },
    { 40, 48, 136, 6, (const u8*)staff_Arrengerd_by_hideki },
    { 30, 224, 136, 2, (const u8*)staff_blank_4 },
    { 30, 48, 136, 8, (const u8*)staff_Vocals },
    { 20, 4, 136, 6, (const u8*)staff_Courtesy_of_Lock_Down_Entert },
    { 100, 192, 136, 1, (const u8*)staff_blank_4 },
    { 30, 96, 136, 8, (const u8*)staff_RECORDING_ENGINEER },
    { 60, 80, 136, 6, (const u8*)staff_Yutaka_Shimoyama_Victor_St },
    { 30, 96, 136, 8, (const u8*)staff_MIX_ENGINEER },
    { 60, 96, 136, 6, (const u8*)staff_Paul_Shubat },
    { 30, 96, 136, 8, (const u8*)staff_ASSISTANT_ENGINEER },
    { 60, 96, 136, 6, (const u8*)staff_Vladimir_Nikolic },
    { 30, 96, 136, 8, (const u8*)staff_ARTIST_MANAGEMENT },
    { 60, 64, 136, 6, (const u8*)staff_Cain_Lock_Down_Entertainment },
    { 30, 96, 160, 8, (const u8*)staff_VOICE_ACTOR },
    { 20, 96, 136, 6, (const u8*)staff_TOURU_OHKAWA },
    { 20, 96, 136, 6, (const u8*)staff_YUJI_KISHI },
    { 20, 96, 136, 6, (const u8*)staff_MITSUO_IWATA },
    { 20, 96, 136, 6, (const u8*)staff_KENTARO_ITOU },
    { 20, 96, 136, 6, (const u8*)staff_MASAKAZU_SUZUKI },
    { 20, 104, 136, 6, (const u8*)staff_YURI_AMANO },
    { 20, 104, 136, 6, (const u8*)staff_MIE_MIDORI },
    { 20, 96, 136, 6, (const u8*)staff_TAKASHI_MATSUYAMA },
    { 20, 96, 136, 6, (const u8*)staff_TOMOMICHI_NISHIMURA },
    { 20, 88, 136, 6, (const u8*)staff_MAKOTO_TSUMURA },
    { 20, 88, 136, 6, (const u8*)staff_EIJI_SEKIGUCHI },
    { 40, 96, 136, 6, (const u8*)staff_ATSUKO_TANAKA },
    { 20, 96, 136, 6, (const u8*)staff_LAWRENCE_BAYNE },
    { 20, 96, 136, 6, (const u8*)staff_PATRICK_GALLAGAN },
    { 20, 88, 136, 6, (const u8*)staff_FRANCIS_DIAKEWSKY },
    { 60, 96, 136, 6, (const u8*)staff_LEN_CARLSON },
    { 30, 96, 160, 8, (const u8*)staff_PLANNING },
    { 20, 96, 136, 6, (const u8*)staff_Neo_G_H_ISHIZAWA },
    { 20, 96, 136, 6, (const u8*)staff_HARUO_MURATA },
    { 20, 96, 136, 6, (const u8*)staff_NUMACH_T_O },
    { 40, 88, 136, 6, (const u8*)staff_YASUNORI_ICHINOSE },
    { 60, 96, 136, 6, (const u8*)staff_SADA_36 },
    { 30, 88, 160, 8, (const u8*)staff_SPECIAL_THANKS },
    { 40, 96, 136, 6, (const u8*)staff_YOUICHI_EGAWA },
    { 20, 96, 136, 6, (const u8*)staff_T_SHIRAIWA },
    { 40, 96, 136, 6, (const u8*)staff_ABU },
    { 20, 96, 136, 6, (const u8*)staff_TOMOAKI_TSUJI },
    { 20, 96, 136, 6, (const u8*)staff_TOBUTO_MAM2_DEZAKI },
    { 20, 96, 136, 6, (const u8*)staff_MITSUAKI_TIM2_ARAKI },
    { 20, 96, 136, 6, (const u8*)staff_TAKEchan },
    { 40, 96, 136, 6, (const u8*)staff_ONI_SUZUKI },
    { 20, 96, 136, 6, (const u8*)staff_BUG_H_SUGIMOTO },
    { 20, 96, 136, 6, (const u8*)staff_K_SHINANO },
    { 20, 96, 136, 6, (const u8*)staff_GON },
    { 40, 96, 136, 6, (const u8*)staff_SYACHI_S_OHOKA },
    { 20, 96, 136, 6, (const u8*)staff_YNG_J_MATSUBARA },
    { 20, 88, 136, 6, (const u8*)staff_MIURA_CUBERICK },
    { 20, 88, 136, 6, (const u8*)staff_TETSUYA_HAZE },
    { 20, 88, 136, 6, (const u8*)staff_YOSHIHIRO_TOMITA },
    { 20, 88, 136, 6, (const u8*)staff_HMX_12_HAMADA },
    { 40, 88, 136, 6, (const u8*)staff_MASAYASU_MUKAI },
    { 20, 88, 136, 6, (const u8*)staff_PUNCH_KUBOZONO },
    { 20, 88, 136, 6, (const u8*)staff_TETSUYA_IIJIMA },
    { 20, 88, 136, 6, (const u8*)staff_LISA_E_JONES },
    { 20, 88, 136, 6, (const u8*)staff_MASAYUKI_FUKUMOTO },
    { 20, 88, 136, 6, (const u8*)staff_LANCE_LUU },
    { 40, 88, 136, 6, (const u8*)staff_NATE_WILLIAMS },
    { 30, 96, 160, 8, (const u8*)staff_MESSAGE_TRANSLATOR },
    { 20, 96, 136, 6, (const u8*)staff_ERIK_SUZUKI },
    { 20, 96, 136, 6, (const u8*)staff_DAN_OKADA },
    { 60, 104, 136, 6, (const u8*)staff_CHRIS_TANG },
    { 30, 96, 160, 8, (const u8*)staff_PRODUCER },
    { 40, 96, 136, 6, (const u8*)staff_NORITAKA_FUNAMIZU },
    { 60, 88, 136, 6, (const u8*)staff_KOUJI_NAKAJIMA },
    { 30, 96, 160, 8, (const u8*)staff_GENERAL_PRODUCER },
    { 100, 88, 136, 6, (const u8*)staff_YOSHIKI_OKAMOTO },
    { 100, 96, 112, 8, (const u8*)staff_AND_CAPCOM_ALL_STAFF },
    { 128, 48, 144, 5, (const u8*)staff_blank_5 },
    { -1, 48, 144, 5, (const u8*)staff_THANK_YOU_FOR_PLAYING },
    { -1, 48, 96, 5, (const u8*)staff_PRESENTED_BY },
    { 20, 190, 96, 0, (const u8*)staff_blank_4 },
    { 20, 190, 0, 5, (const u8*)staff_blank_5 },
    { 256, 0, 0, 6, 0 },
    { 20, 48, 128, 3, (const u8*)staff_STREET_FIGHTER_2ND_IMPACT },
    { 20, 48, 96, 3, (const u8*)staff_GIANT_ATTACK },
    { 20, 48, 64, 3, (const u8*)staff_STAFF_2 },
    { 540, 96, 160, 1, (const u8*)staff_CHARACTER_DESIGN_2 },
    { 20, 96, 136, 0, (const u8*)staff_W_O },
    { 0, 96, 136, 2, (const u8*)staff_H },
    { 0, 96, 112, 0, (const u8*)staff_D_K_R_T },
    { 0, 96, 112, 2, (const u8*)staff_U_I_A },
    { 0, 96, 88, 0, (const u8*)staff_C_I_O_I_H_G_N },
    { 0, 96, 88, 2, (const u8*)staff_H_M_R_N_S_O_U },
    { 0, 96, 64, 0, (const u8*)staff_S_I_A_I },
    { 0, 96, 64, 2, (const u8*)staff_H_B_K },
    { 0, 96, 40, 0, (const u8*)staff_C_u },
    { 0, 96, 40, 2, (const u8*)staff_h_n },
    { 20, 96, 136, 0, (const u8*)staff_J_N_I_A_A },
    { 0, 96, 136, 2, (const u8*)staff_U_K_W },
    { 0, 96, 112, 0, (const u8*)staff_S_I_I_Y_N },
    { 0, 96, 112, 2, (const u8*)staff_E_J_A_O },
    { 0, 96, 88, 0, (const u8*)staff_Y_K_S_I_A_A },
    { 0, 96, 88, 2, (const u8*)staff_U_I_I_H_K_W },
    { 0, 96, 64, 0, (const u8*)staff_S_I_N_S_K },
    { 0, 96, 64, 2, (const u8*)staff_H_N_O_U_E_N },
    { 540, 96, 160, 1, (const u8*)staff_SCROLL_DESIGN_2 },
    { 20, 96, 136, 0, (const u8*)staff_H_R_S_I_S_G_Y_M },
    { 0, 96, 136, 2, (const u8*)staff_I_O_H_U_I_A_A },
    { 0, 96, 112, 0, (const u8*)staff_Y_K_U_U_O_O },
    { 0, 96, 112, 2, (const u8*)staff_O_O_F_K_M_T },
    { 0, 96, 88, 0, (const u8*)staff_H_R_Y_K_M_H_R },
    { 0, 96, 88, 2, (const u8*)staff_I_O_U_I_I_A_O_I },
    { 0, 96, 64, 0, (const u8*)staff_O_I_I },
    { 0, 96, 64, 2, (const u8*)staff_J_J },
    { 0, 96, 40, 0, (const u8*)staff_N_O_E },
    { 0, 96, 40, 2, (const u8*)staff_A_B_I },
    { 20, 96, 136, 0, (const u8*)staff_A_E_I_K_H_M },
    { 0, 96, 136, 2, (const u8*)staff_K_M_O_A_A },
    { 0, 96, 112, 0, (const u8*)staff_T_M },
    { 0, 96, 112, 2, (const u8*)staff_A_A },
    { 0, 96, 88, 0, (const u8*)staff_Y_M_M_T_O_I },
    { 0, 96, 88, 2, (const u8*)staff_A_A_O_O_K_J },
    { 0, 96, 64, 0, (const u8*)staff_K_U_C_I_T_K_D },
    { 0, 96, 64, 2, (const u8*)staff_O_I_H_A_E_A },
    { 20, 96, 160, 1, (const u8*)staff_ORIGINAL_ART_WORK_2 },
    { 20, 96, 120, 0, (const u8*)staff_A_I_A },
    { 0, 96, 120, 2, (const u8*)staff_K_M_N },
    { 0, 96, 96, 0, (const u8*)staff_K_N_I_H_M_R },
    { 0, 96, 96, 2, (const u8*)staff_I_U_N_S_I_U_A },
    { 0, 96, 72, 0, (const u8*)staff_N },
    { 0, 96, 72, 2, (const u8*)staff_K },
    { 20, 96, 160, 1, (const u8*)staff_TITLE_LOGO_DESIGN_2 },
    { 20, 96, 104, 0, (const u8*)staff_S_O_I },
    { 0, 96, 104, 2, (const u8*)staff_H_E },
    { 20, 96, 160, 1, (const u8*)staff_INSTRACTION_DESIGN_2 },
    { 20, 96, 104, 0, (const u8*)staff_S_K_M_Z },
    { 0, 96, 104, 2, (const u8*)staff_A_O_I_U },
    { 540, 96, 160, 1, (const u8*)staff_PROGRAMMING_2 },
    { 20, 96, 128, 0, (const u8*)staff_K_Z_H_T_A_A },
    { 0, 96, 128, 2, (const u8*)staff_A_U_I_O_N_K_I },
    { 0, 96, 104, 0, (const u8*)staff_blank_6 },
    { 0, 96, 104, 2, (const u8*)staff_O_U_A_L_1_Y_S_I_U_I },
    { 0, 96, 80, 0, (const u8*)staff_Y_K_A_A_U_A_T_T },
    { 0, 96, 80, 2, (const u8*)staff_U_O_K_W_M_R_A_E },
    { 0, 96, 56, 0, (const u8*)staff_H_R_S_I_N_K_G_W },
    { 0, 96, 56, 2, (const u8*)staff_I_O_H_A_A_A_A },
    { 20, 96, 128, 0, (const u8*)staff_Y_S_I_O_U_I_A_A_I_E },
    { 0, 96, 128, 0, (const u8*)staff_O_H_N_B_N_D_N },
    { 0, 96, 104, 0, (const u8*)staff_M_S_H_T_h_Y },
    { 0, 96, 104, 2, (const u8*)staff_A_A_I_O_O_a },
    { 0, 96, 68, 0, (const u8*)staff_A_I_I_O_Y_K_Y_M },
    { 0, 96, 68, 2, (const u8*)staff_K_H_R_O_O_A_A },
    { 20, 96, 160, 1, (const u8*)staff_SOUND_EFFECT_DESIGN_2 },
    { 20, 96, 112, 0, (const u8*)staff_S_T_S_I_I_E },
    { 0, 96, 112, 2, (const u8*)staff_A_O_H_S },
    { 0, 96, 88, 0, (const u8*)staff_blank_7 },
    { 0, 96, 88, 2, (const u8*)staff_blank_8 },
    { 20, 96, 160, 1, (const u8*)staff_MUSIC_COMPOSE_2 },
    { 20, 96, 112, 0, (const u8*)staff_H_D_K_K_G_W },
    { 0, 96, 112, 2, (const u8*)staff_I_E_I_O_U_A_A },
    { 0, 96, 88, 0, (const u8*)staff_Y_K_W_I },
    { 0, 96, 88, 2, (const u8*)staff_U_I_I_A },
    { 20, 96, 160, 1, (const u8*)staff_MUSIC_ARRANGEMENT },
    { 20, 96, 104, 0, (const u8*)staff_H_D_K_K_G_W },
    { 0, 96, 104, 2, (const u8*)staff_I_E_I_O_U_A_A },
    { 20, 96, 160, 1, (const u8*)staff_PLANNING_2 },
    { 20, 96, 112, 0, (const u8*)staff_S_T_A_U_I_O },
    { 0, 96, 112, 2, (const u8*)staff_E_O_Y_S_H_R },
    { 0, 96, 88, 0, (const u8*)staff_N_O_G_S_I_A_A },
    { 0, 96, 88, 2, (const u8*)staff_E_H_I_H_Z_W },
    { 0, 96, 64, 0, (const u8*)staff_N_M_C },
    { 0, 96, 64, 2, (const u8*)staff_U_A_H },
    { 810, 96, 160, 1, (const u8*)staff_VOICE_ACTOR_2 },
    { 20, 96, 128, 0, (const u8*)staff_Y_J_E_A },
    { 0, 96, 128, 2, (const u8*)staff_U_I_U_D },
    { 0, 96, 104, 0, (const u8*)staff_W_T_R_A_A_I },
    { 0, 96, 104, 2, (const u8*)staff_A_A_U_T_K_G },
    { 0, 96, 80, 0, (const u8*)staff_T_M_M_C_I_N_S_I_U_A },
    { 0, 96, 80, 2, (const u8*)staff_O_O_I_H_I_H_M_R },
    { 0, 96, 56, 0, (const u8*)staff_K_H_R_U_I_O },
    { 0, 96, 56, 2, (const u8*)staff_A_O_U_F_J_N },
    { 20, 96, 128, 0, (const u8*)staff_Y_R_M_N },
    { 0, 96, 128, 2, (const u8*)staff_U_I_A_A_O },
    { 0, 96, 104, 0, (const u8*)staff_I_S_I_H_B },
    { 0, 96, 104, 2, (const u8*)staff_S_H_N_C_I_A },
    { 0, 96, 80, 0, (const u8*)staff_K_N_T_K_M_R },
    { 0, 96, 80, 2, (const u8*)staff_A_O_U_A_U },
    { 0, 96, 56, 0, (const u8*)staff_K_J_O_E },
    { 0, 96, 56, 2, (const u8*)staff_O_I_T_B },
    { 20, 96, 128, 0, (const u8*)staff_B_U_E_R_B_R_S_N },
    { 0, 96, 128, 2, (const u8*)staff_R_C_O_E_T_O },
    { 0, 96, 104, 0, (const u8*)staff_M_C_A_L_S_M_E_S },
    { 0, 96, 104, 2, (const u8*)staff_I_H_E_O_M_R },
    { 20, 96, 160, 1, (const u8*)staff_MESSAGE_TRANSLATOR_2 },
    { 20, 96, 136, 0, (const u8*)staff_E_I_U_U_I },
    { 0, 96, 136, 2, (const u8*)staff_R_K_S_Z_K },
    { 0, 96, 112, 0, (const u8*)staff_D_N_O_A_A },
    { 0, 96, 112, 2, (const u8*)staff_A_K_D },
    { 0, 96, 88, 0, (const u8*)staff_C_R_S_T_N },
    { 0, 96, 88, 2, (const u8*)staff_H_I_A_G },
    { 0, 96, 64, 0, (const u8*)staff_Y_M_K_I_H },
    { 0, 96, 64, 2, (const u8*)staff_U_I_O_N_S_I },
    { 0, 96, 40, 0, (const u8*)staff_K_R_A_O_H_R_E_F_E_T_S },
    { 0, 96, 40, 2, (const u8*)staff_A_L_S_I_O_D_R_I_A },
    { 1898, 96, 160, 1, (const u8*)staff_SPECIAL_THANKS_2 },
    { 20, 96, 136, 0, (const u8*)staff_T_U_O_H },
    { 0, 96, 136, 2, (const u8*)staff_S_Y_S_I },
    { 0, 96, 112, 0, (const u8*)staff_M_Y_N },
    { 0, 96, 112, 2, (const u8*)staff_A_A_O },
    { 0, 96, 88, 0, (const u8*)staff_T_M },
    { 0, 96, 88, 2, (const u8*)staff_O_O },
    { 0, 96, 64, 0, (const u8*)staff_B_B_N },
    { 0, 96, 64, 2, (const u8*)staff_L_O },
    { 0, 96, 40, 0, (const u8*)staff_T_K_F_M_A_A_A },
    { 0, 96, 40, 2, (const u8*)staff_A_A_U_I_S_G_T },
    { 20, 96, 136, 0, (const u8*)staff_M_A_K },
    { 0, 96, 136, 2, (const u8*)staff_O_I },
    { 0, 96, 112, 0, (const u8*)staff_N_A_E },
    { 0, 96, 112, 2, (const u8*)staff_K_I },
    { 0, 96, 88, 0, (const u8*)staff_H_N_K_M_R },
    { 0, 96, 88, 2, (const u8*)staff_A_A_U_A },
    { 0, 96, 64, 0, (const u8*)staff_H_O_I_A },
    { 0, 96, 64, 2, (const u8*)staff_J_M },
    { 20, 96, 136, 0, (const u8*)staff_blank_9 },
    { 0, 96, 136, 2, (const u8*)staff_blank_10 },
    { 0, 96, 112, 0, (const u8*)staff_T_K_Y_H_R_I_A },
    { 0, 96, 112, 2, (const u8*)staff_A_U_A_S_I_A_W },
    { 0, 96, 88, 0, (const u8*)staff_R_T_O_O },
    { 0, 96, 88, 2, (const u8*)staff_I_A_R_K_S },
    { 0, 96, 64, 0, (const u8*)staff_R_o_i },
    { 0, 96, 64, 2, (const u8*)staff_y_j },
    { 0, 96, 40, 0, (const u8*)staff_H_R_A_O_L_W },
    { 0, 96, 40, 2, (const u8*)staff_A_D_Y_S_F_L_O },
    { 20, 96, 144, 0, (const u8*)staff_C_U_H_C_E_S },
    { 0, 96, 144, 2, (const u8*)staff_S_B_G_C_E_K_R },
    { 0, 96, 112, 0, (const u8*)staff_K_N_S_I_E_M_T_U_A_A },
    { 0, 96, 112, 2, (const u8*)staff_U_I_H_G_A_S_B_R },
    { 0, 96, 88, 0, (const u8*)staff_M_N_B_A_S_M_T },
    { 0, 96, 88, 2, (const u8*)staff_A_A_U_M_T_U_O_O },
    { 0, 96, 64, 0, (const u8*)staff_T_M_Y_K_O_O_A },
    { 0, 96, 64, 2, (const u8*)staff_O_O_U_I_Y_K_T },
    { 0, 96, 40, 0, (const u8*)staff_T_T_U_A_H_Z },
    { 0, 96, 40, 2, (const u8*)staff_E_S_Y_A_E },
    { 20, 96, 144, 0, (const u8*)staff_C_U_H_C_E_S },
    { 0, 96, 144, 2, (const u8*)staff_S_B_G_C_E_K_R },
    { 0, 96, 112, 0, (const u8*)staff_K_T_U_U_E_M_U_A },
    { 0, 96, 112, 2, (const u8*)staff_A_S_S_K_I_R },
    { 0, 96, 88, 0, (const u8*)staff_M_S_H_R_A_I_A_I },
    { 0, 96, 88, 2, (const u8*)staff_A_A_I_O_K_J_T_N },
    { 0, 96, 64, 0, (const u8*)staff_T_K_S_I_H_S_I_O_O },
    { 0, 96, 64, 2, (const u8*)staff_A_A_H_A_H_M_T },
    { 0, 96, 40, 0, (const u8*)staff_T_S_I_I_O_K_R_T },
    { 0, 96, 40, 2, (const u8*)staff_O_H_H_K_U_A_A },
    { 20, 96, 144, 0, (const u8*)staff_C_U_H_C_E_S },
    { 0, 96, 144, 2, (const u8*)staff_S_B_G_C_E_K_R },
    { 0, 96, 112, 0, (const u8*)staff_Y_S_I_I_O_T_M_T },
    { 0, 96, 112, 2, (const u8*)staff_O_H_H_R_O_I_A },
    { 0, 96, 88, 0, (const u8*)staff_D_I_U_E_S_S_K },
    { 0, 96, 88, 2, (const u8*)staff_A_S_K_A_A_I },
    { 0, 96, 64, 0, (const u8*)staff_A_I_O_I_M_R_T },
    { 0, 96, 64, 2, (const u8*)staff_K_N_R_U_A_A },
    { 20, 96, 144, 0, (const u8*)staff_S_I_L_S_I_H_T_S_P_A },
    { 0, 96, 144, 2, (const u8*)staff_K_L_M_T_E_T_L_Y },
    { 0, 96, 112, 0, (const u8*)staff_T_K_K_S },
    { 0, 96, 112, 2, (const u8*)staff_T },
    { 0, 96, 88, 0, (const u8*)staff_H_R_S_I_S_G_M_T_U },
    { 0, 96, 88, 2, (const u8*)staff_I_O_H_U_I_O_O_B_G },
    { 0, 96, 64, 0, (const u8*)staff_G_N },
    { 0, 96, 64, 2, (const u8*)staff_O },
    { 0, 96, 40, 0, (const u8*)staff_K_H_U_E_A_A_K },
    { 0, 96, 40, 2, (const u8*)staff_O_S_K_R_I_T_O },
    { 20, 96, 160, 1, (const u8*)staff_PRODUCER_2 },
    { 20, 96, 104, 0, (const u8*)staff_T_M_S_I_S_D_M_T },
    { 0, 96, 104, 2, (const u8*)staff_O_O_H_A_A_O_O },
    { 20, 96, 160, 1, (const u8*)staff_GENERAL_PRODUCER_2 },
    { 20, 96, 120, 0, (const u8*)staff_N_R_T_K_U_A_I_U },
    { 0, 96, 120, 2, (const u8*)staff_O_I_A_A_F_N_M_Z },
    { 0, 96, 80, 0, (const u8*)staff_Y_S_I_I_O_A_O_O },
    { 0, 96, 80, 2, (const u8*)staff_O_H_K_K_M_T },
    { 20, 96, 112, 4, (const u8*)staff_AND_CAPCOM_ALL_STAFF },
    { 20, 96, 0, 0, (const u8*)staff_blank_11 },
    { 0, 96, 0, 0, (const u8*)staff_blank_11 },
    { 20, 48, 144, 5, (const u8*)staff_blank_5 },
    { 20, 48, 144, 5, (const u8*)staff_THANK_YOU_FOR_PLAYING },
    { 0, 48, 96, 5, (const u8*)staff_PRESENTED_BY },
    { 0, 190, 96, 0, (const u8*)staff_blank_4 },
    { 0, 190, 0, 0, (const u8*)staff_blank_5 },
    { 512, 0, 0, 0, 0 },
};

/* the staff roll's text, one string per line of the roll */
const char staff_STREET_FIGHTER_3rd_STRIKE[32] = "   STREET FIGHTER { 3rd STRIKE";
const char staff_Fight_for_the_Future[28] = "       Fight for the Future";
const char staff_STAFF[20] = "              STAFF";
const char staff_CHARACTER_DESIGN[20] = "   CHARACTER DESIGN";
const char staff_WHO[16] = "          WHO";
const char staff_IKUSAN_Z[16] = "       IKUSAN Z";
const char staff_D_Kurita[16] = "       D=Kurita";
const char staff_Chimorin_SHOGUN[20] = "   Chimorin SHOGUN";
const char staff_SIBAKI[16] = "       SIBAKI]";
const char staff_Chunzenji_Rute[20] = "    Chunzenji&Rute";
const char staff_Tsuyoshi[16] = "       Tsuyoshi";
const char staff_Jun_Ikawa[16] = "      Jun-Ikawa";
const char staff_Toshihiro_Suzuki[20] = "   Toshihiro Suzuki";
const char staff_NOYA_T[16] = "        NOYA-T";
const char staff_Seiji_Yano[20] = "      Seiji Yano";
const u8 staff_blank[20] = { 32, 32, 78, 97, 111, 105, 34, 72, 69, 76, 76, 34, 82, 121, 111, 115, 117, 107, 101, 0 };
const char staff_TOMO[16] = "         TOMO";
const char staff_HIRANO_DAICHI[20] = "     HIRANO=DAICHI";
const char staff_Izumi_N[16] = "        Izumi.N";
const char staff_AKIMAN[16] = "        AKIMAN";
const char staff_SCROLL_DESIGN[20] = "     SCROLL DESIGN";
const char staff_IMAHORI_75[20] = "      IMAHORI 75%";
const char staff_SUGIYAMA_50[20] = "     SUGIYAMA 50%";
const char staff_YOUKO_FUKUMOTO[24] = "    ]YOUKO FUKUMOTO]";
const char staff_YUKI_KYOTANI[24] = "    [ YUKI KYOTANI [";
const char staff_SAWATCH[16] = "       |SAWATCH";
const char staff_ATUSHI[20] = "      ^ ATUSHI ^";
const char staff_RYO_UNO[16] = "        RYO UNO";
const char staff_Yusuke_Saiwai[20] = "     Yusuke Saiwai*";
const char staff_KENICHI_YAMAHASHI[24] = "   KENICHI YAMAHASHI";
const char staff_ORIGINAL_ART_WORK[24] = "   ORIGINAL ART WORK";
const char staff_DAIGORO[16] = "        DAIGORO";
const char staff_HARUMARU[20] = "        HARUMARU";
const char staff_TITLE_LOGO_DESIGN[24] = "   TITLE LOGO DESIGN";
const char staff_Y_UCHIDA[20] = "        Y.UCHIDA";
const char staff_INSTRACTION_DESIGN[24] = "   INSTRACTION DESIGN";
const char staff_SAKOMIZU[20] = "        SAKOMIZU";
const char staff_PROGRAMMING[20] = "      PROGRAMMING";
const char staff_KAZUHITO_NAKAI[20] = "     KAZUHITO NAKAI";
const u8 staff_blank_2[24] = { 32, 78, 79, 66, 85, 89, 65, 34, 76, 84, 49, 34, 89, 79, 83, 72, 73, 90, 85, 77, 73, 0, 0, 0 };
const char staff_YUKO_KAWAMURA_TATE[24] = "  YUKO KAWAMURA(TATE)";
const char staff_HIROSHI_NAKAGAWA_RAOH[24] = " HIROSHI NAKAGAWA(RAOH)";
const char staff_Y_M_INADA_INE[20] = "    Y&M.INADA(INE)";
const char staff_MASAHITO_Oh_Ya[20] = "    MASAHITO Oh!Ya!";
const char staff_AKIHIRO_YOKOYAMA[24] = "   AKIHIRO | YOKOYAMA";
const char staff_SOUND_EFFECT_DESIGN[24] = "  SOUND EFFECT DESIGN";
const char staff_SATOSHI_ISE[20] = "     SATOSHI ISE";
const char staff_Y_SANDOU[16] = "       Y.SANDOU";
const char staff_MUSIC_COMPOSE[20] = "     MUSIC COMPOSE";
const char staff_H_OKUGAWA[20] = "      H. OKUGAWA";
const char staff_SOUND_EDITOR[20] = "      SOUND EDITOR";
const char staff_KAZUYA_TAKIMOTO[24] = "     KAZUYA TAKIMOTO";
const char staff_SOUND_MANAGEMENT_DIRECTER[28] = "SOUND MANAGEMENT DIRECTER";
const u8 staff_blank_3[20] = { 32, 32, 32, 32, 9, 32, 89, 111, 115, 104, 105, 110, 111, 114, 105, 32, 79, 110, 111, 0 };
const char staff_Third_Strike_Opening_Theme_S[40] = "Third Strike    (Opening Theme Song)";
const char staff_Let_s_Get_It_On_Event_Theme_[36] = "Let's Get It On (Event Theme Song)";
const char staff_Moving_On_Ending_Song[32] = "Moving On       (Ending Song)";
const char staff_Song_Written_by_Infinite_hid[32] = "Song Written by Infinite/hideki";
const char staff_Arrengerd_by_hideki[20] = "Arrengerd by hideki";
const char staff_blank_4[4] = "#";
const char staff_Vocals[12] = "     Vocals";
const char staff_Courtesy_of_Lock_Down_Entert[44] = "(Courtesy of Lock Down Entertainment Inc.)";
const char staff_RECORDING_ENGINEER[24] = "  RECORDING ENGINEER";
const char staff_Yutaka_Shimoyama_Victor_St[32] = "Yutaka Shimoyama(Victor St.)";
const char staff_MIX_ENGINEER[20] = "     MIX ENGINEER";
const char staff_Paul_Shubat[20] = "      Paul Shubat";
const char staff_ASSISTANT_ENGINEER[24] = "  ASSISTANT ENGINEER";
const char staff_Vladimir_Nikolic[20] = "   Vladimir Nikolic";
const char staff_ARTIST_MANAGEMENT[24] = "   ARTIST MANAGEMENT";
const char staff_Cain_Lock_Down_Entertainment[36] = "Cain(Lock Down Entertainment Inc.)";
const char staff_VOICE_ACTOR[20] = "      VOICE ACTOR";
const char staff_TOURU_OHKAWA[20] = "     TOURU OHKAWA";
const char staff_YUJI_KISHI[20] = "      YUJI KISHI";
const char staff_MITSUO_IWATA[20] = "     MITSUO IWATA";
const char staff_KENTARO_ITOU[20] = "     KENTARO ITOU";
const char staff_MASAKAZU_SUZUKI[20] = "    MASAKAZU SUZUKI";
const char staff_YURI_AMANO[20] = "      YURI AMANO";
const char staff_MIE_MIDORI[20] = "      MIE MIDORI";
const char staff_TAKASHI_MATSUYAMA[24] = "   TAKASHI MATSUYAMA";
const char staff_TOMOMICHI_NISHIMURA[24] = "  TOMOMICHI NISHIMURA";
const char staff_MAKOTO_TSUMURA[20] = "     MAKOTO TSUMURA";
const char staff_EIJI_SEKIGUCHI[20] = "     EIJI SEKIGUCHI";
const char staff_ATSUKO_TANAKA[20] = "     ATSUKO TANAKA";
const char staff_LAWRENCE_BAYNE[20] = "    LAWRENCE BAYNE";
const char staff_PATRICK_GALLAGAN[20] = "   PATRICK GALLAGAN";
const char staff_FRANCIS_DIAKEWSKY[24] = "   FRANCIS DIAKEWSKY";
const char staff_LEN_CARLSON[20] = "      LEN CARLSON";
const char staff_PLANNING[16] = "       PLANNING";
const char staff_Neo_G_H_ISHIZAWA[20] = "   Neo_G H.ISHIZAWA";
const char staff_HARUO_MURATA[20] = "     HARUO MURATA";
const char staff_NUMACH_T_O[20] = "     NUMACH (T.O)";
const char staff_YASUNORI_ICHINOSE[24] = "   YASUNORI ICHINOSE";
const char staff_SADA_36[16] = "       SADA 36";
const char staff_SPECIAL_THANKS[20] = "     SPECIAL THANKS";
const char staff_YOUICHI_EGAWA[20] = "     YOUICHI EGAWA";
const char staff_T_SHIRAIWA[20] = "      T.SHIRAIWA";
const char staff_ABU[16] = "          ABU";
const char staff_TOMOAKI_TSUJI[20] = "     TOMOAKI TSUJI";
const char staff_TOBUTO_MAM2_DEZAKI[24] = "  TOBUTO(MAM2)DEZAKI";
const char staff_MITSUAKI_TIM2_ARAKI[24] = "  MITSUAKI(TIM2)ARAKI";
const char staff_TAKEchan[16] = "       TAKEchan";
const char staff_ONI_SUZUKI[20] = "      ONI-SUZUKI";
const char staff_BUG_H_SUGIMOTO[20] = "    BUG(H.SUGIMOTO)";
const char staff_K_SHINANO[16] = "      K.SHINANO";
const char staff_GON[16] = "         GON";
const char staff_SYACHI_S_OHOKA[20] = "    SYACHI(S.OHOKA)";
const char staff_YNG_J_MATSUBARA[20] = "    YNG.J.MATSUBARA";
const char staff_MIURA_CUBERICK[20] = "     MIURA CUBERICK";
const char staff_TETSUYA_HAZE[20] = "      TETSUYA HAZE";
const char staff_YOSHIHIRO_TOMITA[24] = "    YOSHIHIRO TOMITA";
const char staff_HMX_12_HAMADA[20] = "      HMX-12 HAMADA";
const char staff_MASAYASU_MUKAI[20] = "     MASAYASU MUKAI";
const char staff_PUNCH_KUBOZONO[20] = "     PUNCH KUBOZONO";
const char staff_TETSUYA_IIJIMA[20] = "     TETSUYA IIJIMA";
const char staff_LISA_E_JONES[20] = "      LISA E. JONES";
const char staff_MASAYUKI_FUKUMOTO[24] = "    MASAYUKI FUKUMOTO";
const char staff_LANCE_LUU[20] = "        LANCE LUU";
const char staff_NATE_WILLIAMS[20] = "      NATE WILLIAMS";
const char staff_MESSAGE_TRANSLATOR[24] = "  MESSAGE TRANSLATOR";
const char staff_ERIK_SUZUKI[20] = "      ERIK SUZUKI";
const char staff_DAN_OKADA[20] = "       DAN OKADA";
const char staff_CHRIS_TANG[20] = "      CHRIS TANG";
const char staff_PRODUCER[16] = "       PRODUCER";
const char staff_NORITAKA_FUNAMIZU[24] = "   NORITAKA FUNAMIZU";
const char staff_KOUJI_NAKAJIMA[20] = "     KOUJI NAKAJIMA";
const char staff_GENERAL_PRODUCER[20] = "   GENERAL PRODUCER";
const char staff_YOSHIKI_OKAMOTO[24] = "     YOSHIKI OKAMOTO";
const char staff_AND_CAPCOM_ALL_STAFF[24] = "  AND CAPCOM ALL STAFF";
const char staff_blank_5[4] = " ";
const char staff_THANK_YOU_FOR_PLAYING[32] = "      THANK YOU FOR PLAYING!";
const char staff_PRESENTED_BY[24] = "           PRESENTED BY";
const char staff_STREET_FIGHTER_2ND_IMPACT[32] = "   STREET FIGHTER $ 2ND IMPACT";
const char staff_GIANT_ATTACK[24] = "          GIANT ATTACK";
const char staff_STAFF_2[20] = "             STAFF";
const char staff_CHARACTER_DESIGN_2[24] = "  - CHARACTER DESIGN -";
const char staff_W_O[16] = "          W O";
const char staff_H[16] = "           H";
const char staff_D_K_R_T[16] = "        D K R T";
const char staff_U_I_A[20] = "         - U I A";
const char staff_C_I_O_I_H_G_N[20] = "    C I O I   H G N";
const char staff_H_M_R_N_S_O_U[20] = "     H M R N S O U";
const char staff_S_I_A_I[16] = "        S I A I";
const char staff_H_B_K[16] = "         H B K";
const char staff_C_u[16] = "         C u";
const char staff_h_n[16] = "          h n";
const char staff_J_N_I_A_A[20] = "       J N I A A";
const char staff_U_K_W[16] = "        U   K W";
const char staff_S_I_I_Y_N[20] = "       S I I Y N";
const char staff_E_J_A_O[20] = "        E J   A O";
const char staff_Y_K_S_I_A_A[20] = "     Y K   S I A A";
const char staff_U_I_I_H_K_W[20] = "      U I I H K W";
const char staff_S_I_N_S_K[20] = "     S I N S K .";
const char staff_H_N_O_U_E_N[20] = "      H N O U E  N";
const char staff_SCROLL_DESIGN_2[24] = "   - SCROLL DESIGN -";
const char staff_H_R_S_I_S_G_Y_M[20] = "    H R S I S G Y M";
const char staff_I_O_H_U_I_A_A[24] = "     I O H   U I A A";
const char staff_Y_K_U_U_O_O[20] = "     Y K   U U O O";
const char staff_O_O_F_K_M_T[20] = "      O O F K M T";
const char staff_H_R_Y_K_M_H_R[20] = "    H R Y K   M H R";
const char staff_I_O_U_I_I_A_O_I[24] = "     I O U I I A O I";
const char staff_O_I_I[16] = "         O I I";
const char staff_J_J[16] = "          J J";
const char staff_N_O_E[16] = "         N O E";
const char staff_A_B_I[16] = "          A B I";
const char staff_A_E_I_K_H_M[20] = "      A E I K H M";
const char staff_K_M_O_A_A[20] = "       K M   O A A";
const char staff_T_M[16] = "          T M";
const char staff_A_A[16] = "           A A";
const char staff_Y_M_M_T_O_I[20] = "     Y M M T   O I";
const char staff_A_A_O_O_K_J[20] = "      A A O O K J";
const char staff_K_U_C_I_T_K_D[20] = "     K U C I T K D";
const char staff_O_I_H_A_E_A[20] = "      O I H   A E A";
const char staff_ORIGINAL_ART_WORK_2[24] = " - ORIGINAL ART WORK -";
const char staff_A_I_A[16] = "         A I A";
const char staff_K_M_N[16] = "          K M N";
const char staff_K_N_I_H_M_R[20] = "     K N   I H M R";
const char staff_I_U_N_S_I_U_A[20] = "      I U N S I U A";
const char staff_N[16] = "           N";
const char staff_K[16] = "            K";
const char staff_TITLE_LOGO_DESIGN_2[24] = " - TITLE LOGO DESIGN -";
const char staff_S_O_I[16] = "         S O I";
const char staff_H_E[16] = "          H E";
const char staff_INSTRACTION_DESIGN_2[24] = " - INSTRACTION DESIGN -";
const char staff_S_K_M_Z[16] = "        S K M Z";
const char staff_A_O_I_U[20] = "         A O I U";
const char staff_PROGRAMMING_2[20] = "    - PROGRAMMING -";
const char staff_K_Z_H_T_A_A[20] = "     K Z H T   A A";
const char staff_A_U_I_O_N_K_I[20] = "      A U I O N K I";
const u8 staff_blank_6[24] = { 32, 32, 78, 32, 66, 32, 89, 32, 34, 32, 84, 32, 34, 32, 79, 32, 72, 32, 90, 32, 77, 0, 0, 0 };
const char staff_O_U_A_L_1_Y_S_I_U_I[24] = "   O U A L 1 Y S I U I";
const char staff_Y_K_A_A_U_A_T_T[24] = "  Y K   A A U A T T )";
const char staff_U_O_K_W_M_R_A_E[24] = "   U O K W M R ( A E";
const char staff_H_R_S_I_N_K_G_W[20] = "    H R S I N K G W";
const char staff_I_O_H_A_A_A_A[24] = "     I O H   A A A A";
const char staff_Y_S_I_O_U_I_A_A_I_E[24] = "  Y S I O U I A A I E ";
const char staff_O_H_N_B_N_D_N[24] = "   O H N B   N D ( N )";
const char staff_M_S_H_T_h_Y[20] = "    M S H T   h Y !";
const char staff_A_A_I_O_O_a[20] = "     A A I O O ! a";
const char staff_A_I_I_O_Y_K_Y_M[20] = "    A I I O Y K Y M";
const char staff_K_H_R_O_O_A_A[24] = "     K H R   O O A A";
const char staff_SOUND_EFFECT_DESIGN_2[24] = "- SOUND EFFECT DESIGN -";
const char staff_S_T_S_I_I_E[20] = "      S T S I I E";
const char staff_A_O_H_S[20] = "       A O H   S";
const u8 staff_blank_7[24] = { 32, 32, 72, 32, 82, 32, 65, 32, 73, 34, 32, 54, 32, 107, 32, 75, 32, 78, 32, 79, 0, 0, 0, 0 };
const u8 staff_blank_8[20] = { 32, 32, 32, 73, 32, 79, 32, 75, 32, 32, 88, 32, 56, 32, 34, 32, 79, 32, 68, 0 };
const char staff_MUSIC_COMPOSE_2[24] = "   - MUSIC COMPOSE -";
const char staff_H_D_K_K_G_W[20] = "    H D K   K G W";
const char staff_I_E_I_O_U_A_A[20] = "     I E I O U A A";
const char staff_Y_K_W_I[20] = "       Y K   W I";
const char staff_U_I_I_A[16] = "        U I I A";
const char staff_MUSIC_ARRANGEMENT[24] = " - MUSIC ARRANGEMENT -";
const char staff_PLANNING_2[20] = "      - PLANNING -";
const char staff_S_T_A_U_I_O[20] = "      S T   A U I O";
const char staff_E_O_Y_S_H_R[20] = "       E O Y S H R";
const char staff_N_O_G_S_I_A_A[24] = "  N O G     . S I A A -";
const char staff_E_H_I_H_Z_W[24] = "   E .   - H I H Z W";
const char staff_N_M_C[16] = "         N M C";
const char staff_U_A_H[16] = "          U A H";
const char staff_VOICE_ACTOR_2[20] = "    - VOICE ACTOR -";
const char staff_Y_J_E_A[20] = "       Y J   E A";
const char staff_U_I_U_D[16] = "        U I U D";
const char staff_W_T_R_A_A_I[20] = "     W T R   A A I";
const char staff_A_A_U_T_K_G[20] = "      A A U T K G";
const char staff_T_M_M_C_I_N_S_I_U_A[24] = "  T M M C I N S I U A";
const char staff_O_O_I_H_I_H_M_R[24] = "   O O I H   I H M R";
const char staff_K_H_R_U_I_O[20] = "     K H R   U I O";
const char staff_A_O_U_F_J_N[20] = "      A O U F J N";
const char staff_Y_R_M_N[20] = "       Y R   M N";
const char staff_U_I_A_A_O[20] = "        U I A A O";
const char staff_I_S_I_H_B[20] = "      I S I   H B";
const char staff_S_H_N_C_I_A[20] = "       S H N C I A";
const char staff_K_N_T_K_M_R[20] = "      K N T K M R";
const char staff_A_O_U_A_U[20] = "       A   O U A U";
const char staff_K_J_O_E[20] = "       K J   O E";
const char staff_O_I_T_B[16] = "        O I T B";
const char staff_B_U_E_R_B_R_S_N[20] = "    B U E R B R S N";
const char staff_R_C_O_E_T_O[20] = "     R C   O E T O";
const char staff_M_C_A_L_S_M_E_S[20] = "    M C A L S M E S";
const char staff_I_H_E_O_M_R[20] = "     I H E   O M R";
const char staff_MESSAGE_TRANSLATOR_2[24] = " - MESSAGE TRANSLATOR -";
const char staff_E_I_U_U_I[20] = "      E I   U U I";
const char staff_R_K_S_Z_K[20] = "       R K S Z K";
const char staff_D_N_O_A_A[20] = "       D N O A A";
const char staff_A_K_D[16] = "        A   K D";
const char staff_C_R_S_T_N[20] = "       C R S T N";
const char staff_H_I_A_G[20] = "        H I   A G";
const char staff_Y_M_K_I_H[20] = "      Y M K   I H";
const char staff_U_I_O_N_S_I[20] = "       U I O N S I";
const char staff_K_R_A_O_H_R_E_F_E_T_S[28] = " K R A O H R   E F E T S";
const char staff_A_L_S_I_O_D_R_I_A[24] = "  A L   S I O D   R I A";
const char staff_SPECIAL_THANKS_2[24] = "   - SPECIAL THANKS -";
const char staff_T_U_O_H[16] = "        T U O H";
const char staff_S_Y_S_I[20] = "         S Y S I";
const char staff_M_Y_N[16] = "         M Y N";
const char staff_A_A_O[16] = "          A A O";
const char staff_O_O[16] = "           O O";
const char staff_B_B_N[16] = "          B B N";
const char staff_L_O[16] = "           L O";
const char staff_T_K_F_M_A_A_A[24] = "     T K F M   A A A";
const char staff_A_A_U_I_S_G_T[20] = "      A A U I S G T";
const char staff_M_A_K[16] = "         M A K";
const char staff_O_I[16] = "          . O I";
const char staff_N_A_E[16] = "         N A E";
const char staff_K_I[16] = "          . K I";
const char staff_H_N_K_M_R[20] = "       H N K M R";
const char staff_A_A_U_A[20] = "        . A A U A";
const char staff_H_O_I_A[20] = "         H O I A";
const char staff_J_M[16] = "          . J M";
const u8 staff_blank_9[20] = { 32, 32, 32, 32, 89, 32, 74, 32, 34, 32, 54, 32, 107, 32, 77, 32, 75, 32, 77, 0 };
const u8 staff_blank_10[24] = { 32, 32, 32, 32, 32, 79, 32, 73, 32, 88, 32, 56, 32, 34, 32, 73, 32, 65, 32, 73, 0, 0, 0, 0 };
const char staff_T_K_Y_H_R_I_A[24] = "     T K Y   H R I A";
const char staff_A_U_A_S_I_A_W[20] = "      A U A S I A W";
const char staff_R_T_O_O[20] = "       R T   O O";
const char staff_I_A_R_K_S[20] = "        I A R K S";
const char staff_R_o_i[16] = "         R o i";
const char staff_y_j[16] = "          y j";
const char staff_H_R_A_O_L_W[24] = "   H R : A   - O L W";
const char staff_A_D_Y_S_F_L_O[24] = "    A D Y S   F L O -";
const char staff_C_U_H_C_E_S[24] = "   ( C   U   H C E S";
const char staff_S_B_G_C_E_K_R[24] = "      S B G C E K R  )";
const char staff_K_N_S_I_E_M_T_U_A_A[28] = "     K N S I E M T U A A";
const char staff_U_I_H_G_A_S_B_R[24] = "      U I H G   A S B R";
const char staff_M_N_B_A_S_M_T[24] = "     M N B   A S M T";
const char staff_A_A_U_M_T_U_O_O[24] = "      A A U M T U O O";
const char staff_T_M_Y_K_O_O_A[24] = "     T M Y K   O O A";
const char staff_O_O_U_I_Y_K_T[20] = "      O O U I Y K T";
const char staff_T_T_U_A_H_Z[20] = "     T T U A H Z";
const char staff_E_S_Y_A_E[20] = "      E S Y   A E";
const char staff_K_T_U_U_E_M_U_A[24] = "     K T U U E M U A";
const char staff_A_S_S_K_I_R[20] = "      A S S K   I R";
const char staff_M_S_H_R_A_I_A_I[24] = "     M S H R   A I A I";
const char staff_A_A_I_O_K_J_T_N[24] = "      A A I O K J T N";
const char staff_T_K_S_I_H_S_I_O_O[24] = "     T K S I H S I O O";
const char staff_A_A_H_A_H_M_T[24] = "      A A H   A H M T";
const char staff_T_S_I_I_O_K_R_T[24] = "     T S I I O K R T";
const char staff_O_H_H_K_U_A_A[24] = "      O H H K   U A A";
const char staff_Y_S_I_I_O_T_M_T[24] = "     Y S I I O T M T";
const char staff_O_H_H_R_O_I_A[24] = "      O H H R   O I A";
const char staff_D_I_U_E_S_S_K[20] = "     D I U E S S K";
const char staff_A_S_K_A_A_I[20] = "      A S K   A A I";
const char staff_A_I_O_I_M_R_T[20] = "     A I O I M R T";
const char staff_K_N_R_U_A_A[20] = "      K N R   U A A";
const char staff_S_I_L_S_I_H_T_S_P_A[28] = "( S I L S I H - T S  P A";
const char staff_K_L_M_T_E_T_L_Y[28] = "   K L   M T     E T  L Y )";
const char staff_T_K_K_S[16] = "     T K K S";
const char staff_T[12] = "      T - .";
const char staff_H_R_S_I_S_G_M_T_U[28] = "     H R S I S G M T - U";
const char staff_I_O_H_U_I_O_O_B_G[28] = "      I O H . U I O O B G";
const char staff_G_N[12] = "     G N";
const char staff_O[8] = "      O";
const char staff_K_H_U_E_A_A_K[24] = "     K H U E A A ( K )";
const char staff_O_S_K_R_I_T_O[24] = "      O S K - R I T O";
const char staff_PRODUCER_2[20] = "      - PRODUCER -";
const char staff_T_M_S_I_S_D_M_T[20] = "    T M S I S D M T";
const char staff_O_O_H_A_A_O_O[24] = "     O O H   A A O O";
const char staff_GENERAL_PRODUCER_2[24] = "  - GENERAL PRODUCER -";
const char staff_N_R_T_K_U_A_I_U[24] = "    N R T K   U A I U";
const char staff_O_I_A_A_F_N_M_Z[24] = "     O I A A F N M Z";
const char staff_Y_S_I_I_O_A_O_O[24] = "     Y S I I O A O O";
const char staff_O_H_K_K_M_T[20] = "      O H K   K M T";
const char staff_blank_11[4] = "   ";

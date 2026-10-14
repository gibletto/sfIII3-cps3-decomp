/*
 * END_SUB_TBL_C.C  game tables
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

/* Cell lists of the screen transfers (sc_celllist_tbl in sc_trans_tbl.c). */
const u32 sc_celllist_data[1324] = {
    0x10002, 0x2008F, 0x20002, 0x2008F, 0x30002, 0x2008F, 0x40002, 0x2008F,
    0x50002, 0x2008F, 0x60002, 0x2008F, 0x70002, 0x2008F, 0x80002, 0x2008F,
    0x90002, 0x2008F, 0xA0002, 0x2008F, 0xB0002, 0x2008F, 0xC0002, 0x2008F,
    0xD0002, 0x2008F, 0xE0002, 0x2008F, 0xF0002, 0x2008F, 0x100002, 0x2008F,
    0x110002, 0x2008F, 0x120002, 0x2008F, 0x130002, 0x2008F, 0x140002, 0x2008F,
    0x640000, 0, 0x1B0002, 0x2008F, 0x1C0002, 0x2008F, 0x1D0002, 0x2008F,
    0x1E0002, 0x2008F, 0x1F0002, 0x2008F, 0x200002, 0x2008F, 0x210002, 0x2008F,
    0x220002, 0x2008F, 0x230002, 0x2008F, 0x240002, 0x2008F, 0x250002, 0x2008F,
    0x260002, 0x2008F, 0x270002, 0x2008F, 0x280002, 0x2008F, 0x290002, 0x2008F,
    0x2A0002, 0x2008F, 0x2B0002, 0x2008F, 0x2C0002, 0x2008F, 0x2D0002, 0x2008F,
    0x2E0002, 0x2008F, 0x640000, 0, 0x90002, 0x2008F, 0xA0002, 0x2008F,
    0xB0002, 0x2008F, 0xC0002, 0x2008F, 0xD0002, 0x2008F, 0xE0002, 0x2008F,
    0xF0002, 0x2008F, 0x100002, 0x2008F, 0x110002, 0x2008F, 0x120002, 0x2008F,
    0x130002, 0x2008F, 0x140002, 0x2008F, 0x150002, 0x2008F, 0x160002, 0x2008F,
    0x170002, 0x2008F, 0x180002, 0x2008F, 0x190002, 0x2008F, 0x1A0002, 0x2008F,
    0x1B0002, 0x2008F, 0x1C0002, 0x2008F, 0x640000, 0, 0x230002, 0x2008F,
    0x240002, 0x2008F, 0x250002, 0x2008F, 0x260002, 0x2008F, 0x270002, 0x2008F,
    0x280002, 0x2008F, 0x290002, 0x2008F, 0x2A0002, 0x2008F, 0x2B0002, 0x2008F,
    0x2C0002, 0x2008F, 0x2D0002, 0x2008F, 0x2E0002, 0x2008F, 0x2F0002, 0x2008F,
    0x300002, 0x2008F, 0x310002, 0x2008F, 0x320002, 0x2008F, 0x330002, 0x2008F,
    0x340002, 0x2008F, 0x350002, 0x2008F, 0x360002, 0x2008F, 0x640000, 0,
    0x150001, 0x8006F, 0x150002, 0x8007E, 0x150003, 0x8007F, 0x150004, 0x48006F,
    0x160001, 0x800E0, 0x160002, 0x800E2, 0x160003, 0x800E4, 0x160004, 0x800E6,
    0x170001, 0x800E1, 0x170002, 0x800E3, 0x170003, 0x800E5, 0x170004, 0x800E7,
    0x180001, 0x800F0, 0x180002, 0x800F2, 0x180003, 0x800F4, 0x190001, 0x800F1,
    0x190002, 0x800F3, 0x190003, 0x800F5, 0x190004, 0x800F6, 0x190004, 0x800F7,
    0x1A0001, 0x88006F, 0x1A0002, 0x88007E, 0x1A0003, 0x88007F, 0x1A0004, 0xC8006F,
    0x640000, 0x1A0000, 0x2001B, 0x1C0124, 0x3001B, 0x1C0125, 0x4001B, 0x1C0125,
    0x4001A, 0x1C012C, 0x5001B, 0x1C0126, 0x6001B, 0x1C0127, 0x7001B, 0x1C0128,
    0x8001B, 0x1C0129, 0x9001B, 0x1C012A, 0x640000, 0, 0x2D001B, 0x9C0124,
    0x2C001B, 0x9C0125, 0x2B001B, 0x9C0125, 0x2B001A, 0x9C012C, 0x2A001B, 0x9C0126,
    0x29001B, 0x9C0127, 0x28001B, 0x9C0128, 0x27001B, 0x9C0129, 0x26001B, 0x9C012A,
    0x640000, 0, 0xC0009, 0x280180, 0xD0009, 0x280181, 0xE0009, 0x280182,
    0xF0009, 0x280183, 0x100009, 0x280184, 0x110009, 0x280185, 0x120009, 0x280186,
    0x130009, 0x280187, 0x140009, 0x280188, 0x150009, 0x280189, 0x160009, 0x28018A,
    0x170009, 0x28018B, 0x180009, 0x28018C, 0x190009, 0x28018D, 0x1A0009, 0x28018E,
    0x1B0009, 0x28018F, 0x1C0009, 0x2801C0, 0x1D0009, 0x2801C1, 0x1E0009, 0x2801C2,
    0x1F0009, 0x2801C3, 0x200009, 0x2801C4, 0x210009, 0x2801C5, 0x220009, 0x2801C6,
    0x230009, 0x2801C7, 0xC000A, 0x280190, 0xD000A, 0x280191, 0xE000A, 0x280192,
    0xF000A, 0x280193, 0x10000A, 0x280194, 0x11000A, 0x280195, 0x12000A, 0x280196,
    0x13000A, 0x280197, 0x14000A, 0x280198, 0x15000A, 0x280199, 0x16000A, 0x28019A,
    0x17000A, 0x28019B, 0x18000A, 0x28019C, 0x19000A, 0x28019D, 0x1A000A, 0x28019E,
    0x1B000A, 0x28019F, 0x1C000A, 0x2801D0, 0x1D000A, 0x2801D1, 0x1E000A, 0x2801D2,
    0x1F000A, 0x2801D3, 0x20000A, 0x2801D4, 0x21000A, 0x2801D5, 0x22000A, 0x2801D6,
    0x23000A, 0x2801D7, 0xC000B, 0x2801A0, 0xD000B, 0x2801A1, 0xE000B, 0x2801A2,
    0xF000B, 0x2801A3, 0x10000B, 0x2801A4, 0x11000B, 0x2801A5, 0x12000B, 0x2801A6,
    0x13000B, 0x2801A7, 0x14000B, 0x2801A8, 0x15000B, 0x2801A9, 0x16000B, 0x2801AA,
    0x17000B, 0x2801AB, 0x18000B, 0x2801AC, 0x19000B, 0x2801AD, 0x1A000B, 0x2801AE,
    0x1B000B, 0x2801AF, 0x1C000B, 0x2801E0, 0x1D000B, 0x2801E1, 0x1E000B, 0x2801E2,
    0x1F000B, 0x2801E3, 0x20000B, 0x2801E4, 0x21000B, 0x2801E5, 0x22000B, 0x2801E6,
    0x23000B, 0x2801E7, 0xC000C, 0x2801B0, 0xD000C, 0x2801B1, 0xE000C, 0x2801B2,
    0xF000C, 0x2801B3, 0x10000C, 0x2801B4, 0x11000C, 0x2801B5, 0x12000C, 0x2801B6,
    0x13000C, 0x2801B7, 0x14000C, 0x2801B8, 0x15000C, 0x2801B9, 0x16000C, 0x2801BA,
    0x17000C, 0x2801BB, 0x18000C, 0x2801BC, 0x19000C, 0x2801BD, 0x1A000C, 0x2801BE,
    0x1B000C, 0x2801BF, 0x1C000C, 0x2801F0, 0x1D000C, 0x2801F1, 0x1E000C, 0x2801F2,
    0x1F000C, 0x2801F3, 0x20000C, 0x2801F4, 0x21000C, 0x2801F5, 0x22000C, 0x2801F6,
    0x23000C, 0x2801F7, 0x640000, 0, 0x100009, 0x280180, 0x110009, 0x280181,
    0x120009, 0x280182, 0x130009, 0x280183, 0x140009, 0x280184, 0x150009, 0x280185,
    0x160009, 0x280186, 0x170009, 0x280187, 0x180009, 0x280188, 0x190009, 0x280189,
    0x1A0009, 0x28018A, 0x1B0009, 0x28018B, 0x1C0009, 0x28018C, 0x1D0009, 0x28018D,
    0x1E0009, 0x28018E, 0x1F0009, 0x28018F, 0x10000A, 0x280190, 0x11000A, 0x280191,
    0x12000A, 0x280192, 0x13000A, 0x280193, 0x14000A, 0x280194, 0x15000A, 0x280195,
    0x16000A, 0x280196, 0x17000A, 0x280197, 0x18000A, 0x280198, 0x19000A, 0x280199,
    0x1A000A, 0x28019A, 0x1B000A, 0x28019B, 0x1C000A, 0x28019C, 0x1D000A, 0x28019D,
    0x1E000A, 0x28019E, 0x1F000A, 0x28019F, 0x10000B, 0x2801A0, 0x11000B, 0x2801A1,
    0x12000B, 0x2801A2, 0x13000B, 0x2801A3, 0x14000B, 0x2801A4, 0x15000B, 0x2801A5,
    0x16000B, 0x2801A6, 0x17000B, 0x2801A7, 0x18000B, 0x2801A8, 0x19000B, 0x2801A9,
    0x1A000B, 0x2801AA, 0x1B000B, 0x2801AB, 0x1C000B, 0x2801AC, 0x1D000B, 0x2801AD,
    0x1E000B, 0x2801AE, 0x1F000B, 0x2801AF, 0x10000C, 0x2801B0, 0x11000C, 0x2801B1,
    0x12000C, 0x2801B2, 0x13000C, 0x2801B3, 0x14000C, 0x2801B4, 0x15000C, 0x2801B5,
    0x16000C, 0x2801B6, 0x17000C, 0x2801B7, 0x18000C, 0x2801B8, 0x19000C, 0x2801B9,
    0x1A000C, 0x2801BA, 0x1B000C, 0x2801BB, 0x1C000C, 0x2801BC, 0x1D000C, 0x2801BD,
    0x1E000C, 0x2801BE, 0x1F000C, 0x2801BF, 0x10000D, 0x2801C0, 0x11000D, 0x2801C1,
    0x12000D, 0x2801C2, 0x13000D, 0x2801C3, 0x14000D, 0x2801C4, 0x15000D, 0x2801C5,
    0x16000D, 0x2801C6, 0x17000D, 0x2801C7, 0x18000D, 0x2801C8, 0x19000D, 0x2801C9,
    0x1A000D, 0x2801CA, 0x1B000D, 0x2801CB, 0x1C000D, 0x2801CC, 0x1D000D, 0x2801CD,
    0x1E000D, 0x2801CE, 0x1F000D, 0x2801CF, 0x10000E, 0x2801D0, 0x11000E, 0x2801D1,
    0x12000E, 0x2801D2, 0x13000E, 0x2801D3, 0x14000E, 0x2801D4, 0x15000E, 0x2801D5,
    0x16000E, 0x2801D6, 0x17000E, 0x2801D7, 0x18000E, 0x2801D8, 0x19000E, 0x2801D9,
    0x1A000E, 0x2801DA, 0x1B000E, 0x2801DB, 0x1C000E, 0x2801DC, 0x1D000E, 0x2801DD,
    0x1E000E, 0x2801DE, 0x1F000E, 0x2801DF, 0x10000F, 0x2801E0, 0x11000F, 0x2801E1,
    0x12000F, 0x2801E2, 0x13000F, 0x2801E3, 0x14000F, 0x2801E4, 0x15000F, 0x2801E5,
    0x16000F, 0x2801E6, 0x17000F, 0x2801E7, 0x18000F, 0x2801E8, 0x19000F, 0x2801E9,
    0x1A000F, 0x2801EA, 0x1B000F, 0x2801EB, 0x1C000F, 0x2801EC, 0x1D000F, 0x2801ED,
    0x1E000F, 0x2801EE, 0x1F000F, 0x2801EF, 0x100010, 0x2801F0, 0x110010, 0x2801F1,
    0x120010, 0x2801F2, 0x130010, 0x2801F3, 0x140010, 0x2801F4, 0x150010, 0x2801F5,
    0x160010, 0x2801F6, 0x170010, 0x2801F7, 0x180010, 0x2801F8, 0x190010, 0x2801F9,
    0x1A0010, 0x2801FA, 0x1B0010, 0x2801FB, 0x1C0010, 0x2801FC, 0x1D0010, 0x2801FD,
    0x1E0010, 0x2801FE, 0x1F0010, 0x2801FF, 0x640000, 0, 0x4000B, 0x3A0140,
    0x5000B, 0x3A0144, 0x6000B, 0x3A0148, 0x7000B, 0x3A014C, 0x8000B, 0x3A0150,
    0x9000B, 0x3A0154, 0xA000B, 0x3A0158, 0xB000B, 0x3A015C, 0xC000B, 0x3A0160,
    0xD000B, 0x3A0164, 0xE000B, 0x3A0168, 0xF000B, 0x3A016C, 0x10000B, 0x3A0170,
    0x11000B, 0x3A0174, 0x12000B, 0x3A0178, 0x13000B, 0x3A017C, 0x14000B, 0x3A0180,
    0x15000B, 0x3A0184, 0x16000B, 0x3A0188, 0x17000B, 0x3A018C, 0x18000B, 0x3A0190,
    0x19000B, 0x3A0194, 0x1A000B, 0x3A0198, 0x1B000B, 0x3A019C, 0x1C000B, 0x3A01A0,
    0x1D000B, 0x3A01A4, 0x1E000B, 0x3A01A8, 0x1F000B, 0x3A01AC, 0x20000B, 0x3A01B0,
    0x21000B, 0x3A01B4, 0x22000B, 0x3A01B8, 0x23000B, 0x3A01BC, 0x24000B, 0x3A01C0,
    0x25000B, 0x3A01C4, 0x26000B, 0x3A01C8, 0x27000B, 0x3A01CC, 0x28000B, 0x3A01D0,
    0x29000B, 0x3A01D4, 0x2A000B, 0x3A01D8, 0x2B000B, 0x3A01DC, 0x4000C, 0x3A0141,
    0x5000C, 0x3A0145, 0x6000C, 0x3A0149, 0x7000C, 0x3A014D, 0x8000C, 0x3A0151,
    0x9000C, 0x3A0155, 0xA000C, 0x3A0159, 0xB000C, 0x3A015D, 0xC000C, 0x3A0161,
    0xD000C, 0x3A0165, 0xE000C, 0x3A0169, 0xF000C, 0x3A016D, 0x10000C, 0x3A0171,
    0x11000C, 0x3A0175, 0x12000C, 0x3A0179, 0x13000C, 0x3A017D, 0x14000C, 0x3A0181,
    0x15000C, 0x3A0185, 0x16000C, 0x3A0189, 0x17000C, 0x3A018D, 0x18000C, 0x3A0191,
    0x19000C, 0x3A0195, 0x1A000C, 0x3A0199, 0x1B000C, 0x3A019D, 0x1C000C, 0x3A01A1,
    0x1D000C, 0x3A01A5, 0x1E000C, 0x3A01A9, 0x1F000C, 0x3A01AD, 0x20000C, 0x3A01B1,
    0x21000C, 0x3A01B5, 0x22000C, 0x3A01B9, 0x23000C, 0x3A01BD, 0x24000C, 0x3A01C1,
    0x25000C, 0x3A01C5, 0x26000C, 0x3A01C9, 0x27000C, 0x3A01CD, 0x28000C, 0x3A01D1,
    0x29000C, 0x3A01D5, 0x2A000C, 0x3A01D9, 0x2B000C, 0x3A01DD, 0x4000D, 0x3A0142,
    0x5000D, 0x3A0146, 0x6000D, 0x3A014A, 0x7000D, 0x3A014E, 0x8000D, 0x3A0152,
    0x9000D, 0x3A0156, 0xA000D, 0x3A015A, 0xB000D, 0x3A015E, 0xC000D, 0x3A0162,
    0xD000D, 0x3A0166, 0xE000D, 0x3A016A, 0xF000D, 0x3A016E, 0x10000D, 0x3A0172,
    0x11000D, 0x3A0176, 0x12000D, 0x3A017A, 0x13000D, 0x3A017E, 0x14000D, 0x3A0182,
    0x15000D, 0x3A0186, 0x16000D, 0x3A018A, 0x17000D, 0x3A018E, 0x18000D, 0x3A0192,
    0x19000D, 0x3A0196, 0x1A000D, 0x3A019A, 0x1B000D, 0x3A019E, 0x1C000D, 0x3A01A2,
    0x1D000D, 0x3A01A6, 0x1E000D, 0x3A01AA, 0x1F000D, 0x3A01AE, 0x20000D, 0x3A01B2,
    0x21000D, 0x3A01B6, 0x22000D, 0x3A01BA, 0x23000D, 0x3A01BE, 0x24000D, 0x3A01C2,
    0x25000D, 0x3A01C6, 0x26000D, 0x3A01CA, 0x27000D, 0x3A01CE, 0x28000D, 0x3A01D2,
    0x29000D, 0x3A01D6, 0x2A000D, 0x3A01DA, 0x2B000D, 0x3A01DE, 0x4000E, 0x3A0143,
    0x5000E, 0x3A0147, 0x6000E, 0x3A014B, 0x7000E, 0x3A014F, 0x8000E, 0x3A0153,
    0x9000E, 0x3A0157, 0xA000E, 0x3A015B, 0xB000E, 0x3A015F, 0xC000E, 0x3A0163,
    0xD000E, 0x3A0167, 0xE000E, 0x3A016B, 0xF000E, 0x3A016F, 0x10000E, 0x3A0173,
    0x11000E, 0x3A0177, 0x12000E, 0x3A017B, 0x13000E, 0x3A017F, 0x14000E, 0x3A0183,
    0x15000E, 0x3A0187, 0x16000E, 0x3A018B, 0x17000E, 0x3A018F, 0x18000E, 0x3A0193,
    0x19000E, 0x3A0197, 0x1A000E, 0x3A019B, 0x1B000E, 0x3A019F, 0x1C000E, 0x3A01A3,
    0x1D000E, 0x3A01A7, 0x1E000E, 0x3A01AB, 0x1F000E, 0x3A01AF, 0x20000E, 0x3A01B3,
    0x21000E, 0x3A01B7, 0x22000E, 0x3A01BB, 0x23000E, 0x3A01BF, 0x24000E, 0x3A01C3,
    0x25000E, 0x3A01C7, 0x26000E, 0x3A01CB, 0x27000E, 0x3A01CF, 0x28000E, 0x3A01D3,
    0x29000E, 0x3A01D7, 0x2A000E, 0x3A01DB, 0x2B000E, 0x3A01DF, 0x640000, 0,
    0xC000A, 0x2C01A0, 0xD000A, 0x2C01A1, 0xE000A, 0x2C01A2, 0xF000A, 0x2C01A3,
    0x10000A, 0x2C01A4, 0x11000A, 0x2C01A5, 0x12000A, 0x2C01A6, 0x13000A, 0x2C01A7,
    0xC000B, 0x2C01B0, 0xD000B, 0x2C01B1, 0xE000B, 0x2C01B2, 0xF000B, 0x2C01B3,
    0x10000B, 0x2C01B4, 0x11000B, 0x2C01B5, 0x12000B, 0x2C01B6, 0x13000B, 0x2C01B7,
    0xC000C, 0x2C01C0, 0xD000C, 0x2C01C1, 0xE000C, 0x2C01C2, 0xF000C, 0x2C01C3,
    0x10000C, 0x2C01C4, 0x11000C, 0x2C01C5, 0x12000C, 0x2C01C6, 0x13000C, 0x2C01C7,
    0x640000, 0, 0xC000E, 0x2C01A8, 0xD000E, 0x2C01A9, 0xE000E, 0x2C01AA,
    0xF000E, 0x2C01AB, 0x10000E, 0x2C01AC, 0x11000E, 0x2C01AD, 0x12000E, 0x2C01AE,
    0x13000E, 0x2C01AF, 0xC000F, 0x2C01B8, 0xD000F, 0x2C01B9, 0xE000F, 0x2C01BA,
    0xF000F, 0x2C01BB, 0x10000F, 0x2C01BC, 0x11000F, 0x2C01BD, 0x12000F, 0x2C01BE,
    0x13000F, 0x2C01BF, 0xC0010, 0x2C01C8, 0xD0010, 0x2C01C9, 0xE0010, 0x2C01CA,
    0xF0010, 0x2C01CB, 0x100010, 0x2C01CC, 0x110010, 0x2C01CD, 0x120010, 0x2C01CE,
    0x130010, 0x2C01CF, 0x640000, 0, 0xC0012, 0x2C01D0, 0xD0012, 0x2C01D1,
    0xE0012, 0x2C01D2, 0xF0012, 0x2C01D3, 0x100012, 0x2C01D4, 0x110012, 0x2C01D5,
    0x120012, 0x2C01D6, 0x130012, 0x2C01D7, 0x140012, 0x2C01D8, 0x150012, 0x2C01D9,
    0xC0013, 0x2C01E0, 0xD0013, 0x2C01E1, 0xE0013, 0x2C01E2, 0xF0013, 0x2C01E3,
    0x100013, 0x2C01E4, 0x110013, 0x2C01E5, 0x120013, 0x2C01E6, 0x130013, 0x2C01E7,
    0x140013, 0x2C01E8, 0x150013, 0x2C01E9, 0xC0014, 0x2C01F0, 0xD0014, 0x2C01F1,
    0xE0014, 0x2C01F2, 0xF0014, 0x2C01F3, 0x100014, 0x2C01F4, 0x110014, 0x2C01F5,
    0x120014, 0x2C01F6, 0x130014, 0x2C01F7, 0x140014, 0x2C01F8, 0x150014, 0x2C01F9,
    0x640000, 0, 0xA000A, 0x2C01DA, 0xB000A, 0x2C01DB, 0xC000A, 0x2C01DC,
    0xD000A, 0x2C01DD, 0xE000A, 0x2C01DE, 0xF000A, 0x2C01DF, 0x10000A, 0x2C0180,
    0x11000A, 0x2C0181, 0x12000A, 0x2C0182, 0x13000A, 0x2C0183, 0x14000A, 0x2C0184,
    0x15000A, 0x2C0185, 0x16000A, 0x2C0186, 0x17000A, 0x2C0187, 0xA000B, 0x2C01EA,
    0xB000B, 0x2C01EB, 0xC000B, 0x2C01EC, 0xD000B, 0x2C01ED, 0xE000B, 0x2C01EE,
    0xF000B, 0x2C01EF, 0x10000B, 0x2C0190, 0x11000B, 0x2C0191, 0x12000B, 0x2C0192,
    0x13000B, 0x2C0193, 0x14000B, 0x2C0194, 0x15000B, 0x2C0195, 0x16000B, 0x2C0196,
    0x17000B, 0x2C0197, 0xA000C, 0x2C01FA, 0xB000C, 0x2C01FB, 0xC000C, 0x2C01FC,
    0xD000C, 0x2C01FD, 0xE000C, 0x2C01FE, 0xF000C, 0x2C01FF, 0x10000C, 0x2C0188,
    0x11000C, 0x2C0189, 0x12000C, 0x2C018A, 0x13000C, 0x2C018B, 0x14000C, 0x2C018C,
    0x15000C, 0x2C018D, 0x16000C, 0x2C018E, 0x17000C, 0x2C018F, 0x640000, 0,
    0xD0000, 0x1600D6, 0xE0000, 0x1600D7, 0xF0000, 0x1600D8, 0x100000, 0x1600D9,
    0x110000, 0x1600DA, 0x120000, 0x1600DB, 0x130000, 0x1600DC, 0x140000, 0x1600DD,
    0x80000, 0x1600DE, 0x90000, 0x1600DF, 0x640000, 0, 0x240000, 0x1600E6,
    0x250000, 0x1600E7, 0x260000, 0x1600E8, 0x270000, 0x1600E9, 0x280000, 0x1600EA,
    0x290000, 0x1600EB, 0x2A0000, 0x1600EC, 0x2B0000, 0x1600ED, 0x1F0000, 0x1600EE,
    0x200000, 0x1600EF, 0x640000, 0,
};

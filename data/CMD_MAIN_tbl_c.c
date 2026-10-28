/*
 * CMD_MAIN_TBL_C.C  debug menu text and tables
 *
 * The dbg_*_str and str_* strings are the labels of the debug screens: menu titles, cg data
 * and judgement field names, stage and character names, and the names of the normal, damage,
 * catch, caught and attack motions. The tables give the colours of debug objects, the first cg
 * code of each player, effect and background group, colour codes, the stage of each BG select
 * entry, the screen positions of the hit judgement grids and columns, and hit_kind_tbl, the
 * next hit kind when a kind is stepped up or down. Read by CMD_MAIN.C, the debug menu.
 * chk22_tbl lists the eight lever directions marked in a move slot when the command check
 * starts; read by CMD_MAIN_2.C, the command input.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern const s8 str_1DATA_SH5[];
extern const s8 str_A[];
extern const s8 str_ADD_ARTS[];
extern const s8 str_AFRICA[];
extern const s8 str_AFRICA_2[];
extern const s8 str_AFRICA_JUMP[];
extern const s8 str_AFRICA_LAND[];
extern const s8 str_AIR_NORMAL[];
extern const s8 str_ALEX[];
extern const s8 str_ALEX_BACK_D[];
extern const s8 str_ALEX_BODY_S[];
extern const s8 str_ALEX_B_D[];
extern const s8 str_ALEX_F_N_D[];
extern const s8 str_ALEX_HYPER_B[];
extern const s8 str_ALEX_POWER_B[];
extern const s8 str_ALEX_SLEEPER[];
extern const s8 str_ALEX_S_H_B[];
extern const s8 str_ALEX_ZUTUKI[];
extern const s8 str_ALL_CHARACTER[];
extern const s8 str_ALL[];
extern const s8 str_APPEAR_1[];
extern const s8 str_APPEAR_2[];
extern const s8 str_APPEAR_3[];
extern const s8 str_APPEAR_4[];
extern const s8 str_APPEAR_5[];
extern const s8 str_APPEAR_6[];
extern const s8 str_APPEAR_7[];
extern const s8 str_APPEAR_8[];
extern const s8 str_APPEAR_JUNBI_1[];
extern const s8 str_APPEAR_JUNBI_2[];
extern const s8 str_APPEAR_JUNBI_3[];
extern const s8 str_APPEAR_JUNBI_4[];
extern const s8 str_APPEAR_JUNBI_5[];
extern const s8 str_APPEAR_JUNBI_6[];
extern const s8 str_APPEAR_JUNBI_7[];
extern const s8 str_APPEAR_JUNBI_8[];
extern const s8 str_APPEAR_USE[];
extern const s8 str_ASIBARAI_SIRI[];
extern const s8 str_ASIB_SIRI_LOSE[];
extern const s8 str_ASIB_TUNNOMERI[];
extern const s8 str_ASIB_TUN_LOSE[];
extern const s8 str_AT[];
extern const s8 str_ATTACK[];
extern const s8 str_ATTACK_10_L[];
extern const s8 str_ATTACK_10_M[];
extern const s8 str_ATTACK_10_S[];
extern const s8 str_ATTACK_10_SP[];
extern const s8 str_ATTACK_11_L[];
extern const s8 str_ATTACK_11_M[];
extern const s8 str_ATTACK_11_S[];
extern const s8 str_ATTACK_11_SP[];
extern const s8 str_ATTACK_12_L[];
extern const s8 str_ATTACK_12_M[];
extern const s8 str_ATTACK_12_S[];
extern const s8 str_ATTACK_12_SP[];
extern const s8 str_ATTACK_13_L[];
extern const s8 str_ATTACK_13_M[];
extern const s8 str_ATTACK_13_S[];
extern const s8 str_ATTACK_13_SP[];
extern const s8 str_ATTACK_1_L[];
extern const s8 str_ATTACK_1_M[];
extern const s8 str_ATTACK_1_S[];
extern const s8 str_ATTACK_1_SP[];
extern const s8 str_ATTACK_2_L[];
extern const s8 str_ATTACK_2_M[];
extern const s8 str_ATTACK_2_S[];
extern const s8 str_ATTACK_2_SP[];
extern const s8 str_ATTACK_3_L[];
extern const s8 str_ATTACK_3_M[];
extern const s8 str_ATTACK_3_S[];
extern const s8 str_ATTACK_3_SP[];
extern const s8 str_ATTACK_4_L[];
extern const s8 str_ATTACK_4_M[];
extern const s8 str_ATTACK_4_S[];
extern const s8 str_ATTACK_4_SP[];
extern const s8 str_ATTACK_5_L[];
extern const s8 str_ATTACK_5_M[];
extern const s8 str_ATTACK_5_S[];
extern const s8 str_ATTACK_5_SP[];
extern const s8 str_ATTACK_6_L[];
extern const s8 str_ATTACK_6_M[];
extern const s8 str_ATTACK_6_S[];
extern const s8 str_ATTACK_6_SP[];
extern const s8 str_ATTACK_7_L[];
extern const s8 str_ATTACK_7_M[];
extern const s8 str_ATTACK_7_S[];
extern const s8 str_ATTACK_7_SP[];
extern const s8 str_ATTACK_8_L[];
extern const s8 str_ATTACK_8_M[];
extern const s8 str_ATTACK_8_S[];
extern const s8 str_ATTACK_8_SP[];
extern const s8 str_ATTACK_9_L[];
extern const s8 str_ATTACK_9_M[];
extern const s8 str_ATTACK_9_S[];
extern const s8 str_ATTACK_9_SP[];
extern const s8 str_ATT_000[];
extern const s8 str_ATT_IX[];
extern const s8 str_ATT[];
extern const s8 str_ATT_2[];
extern const s8 str_AT_LEVEL[];
extern const s8 str_B[];
extern const s8 str_BACK[];
extern const s8 str_BACK_WALK[];
extern const s8 str_BASE[];
extern const s8 str_BEFORE[];
extern const s8 str_BG_SELECT[];
extern const s8 str_BHA_000[];
extern const s8 str_BIKEI[];
extern const s8 str_BLANK[];
extern const s8 str_BODY_BROW_L[];
extern const s8 str_BODY_BROW_M[];
extern const s8 str_BODY_BROW_S[];
extern const s8 str_BODY_BROW_SP[];
extern const s8 str_BODY_SLAM[];
extern const s8 str_BODY_UPPER[];
extern const s8 str_BODY_UPPER_L[];
extern const s8 str_BODY_UPPER_M[];
extern const s8 str_BODY_UPPER_S[];
extern const s8 str_BODY_UPPER_SP[];
extern const s8 str_BODY_UPPER_SP_2[];
extern const s8 str_BOD_000[];
extern const s8 str_BONUS[];
extern const s8 str_BONUS_1[];
extern const s8 str_BONUS_2[];
extern const s8 str_BONUS_CHAR[];
extern const s8 str_BONUS_WIN_1[];
extern const s8 str_BONUS_WIN_2[];
extern const s8 str_BONUS_WIN_3[];
extern const s8 str_BRAZIL[];
extern const s8 str_BRAZIL_1[];
extern const s8 str_BRAZIL_1_2[];
extern const s8 str_BRAZIL_2[];
extern const s8 str_BREAST[];
extern const s8 str_BT[];
extern const s8 str_BUTTOBI[];
extern const s8 str_BUTT_PAT[];
extern const s8 str_BUTT_TYPE[];
extern const s8 str_B_JUMP_K_L_A[];
extern const s8 str_B_JUMP_K_L_B[];
extern const s8 str_B_JUMP_K_M_A[];
extern const s8 str_B_JUMP_K_M_B[];
extern const s8 str_B_JUMP_K_S_A[];
extern const s8 str_B_JUMP_K_S_B[];
extern const s8 str_B_JUMP_P_L_A[];
extern const s8 str_B_JUMP_P_L_B[];
extern const s8 str_B_JUMP_P_M_A[];
extern const s8 str_B_JUMP_P_M_B[];
extern const s8 str_B_JUMP_P_S_A[];
extern const s8 str_B_JUMP_P_S_B[];
extern const s8 str_C[];
extern const s8 str_CA[];
extern const s8 str_CANCEL_SH6[];
extern const s8 str_CATCH[];
extern const s8 str_CATCH_1[];
extern const s8 str_CATCH_10[];
extern const s8 str_CATCH_11[];
extern const s8 str_CATCH_12[];
extern const s8 str_CATCH_13[];
extern const s8 str_CATCH_14[];
extern const s8 str_CATCH_15[];
extern const s8 str_CATCH_16[];
extern const s8 str_CATCH_17[];
extern const s8 str_CATCH_18[];
extern const s8 str_CATCH_19[];
extern const s8 str_CATCH_2[];
extern const s8 str_CATCH_20[];
extern const s8 str_CATCH_21[];
extern const s8 str_CATCH_22[];
extern const s8 str_CATCH_23[];
extern const s8 str_CATCH_24[];
extern const s8 str_CATCH_25[];
extern const s8 str_CATCH_26[];
extern const s8 str_CATCH_27[];
extern const s8 str_CATCH_28[];
extern const s8 str_CATCH_29[];
extern const s8 str_CATCH_3[];
extern const s8 str_CATCH_30[];
extern const s8 str_CATCH_31[];
extern const s8 str_CATCH_32[];
extern const s8 str_CATCH_33[];
extern const s8 str_CATCH_34[];
extern const s8 str_CATCH_35[];
extern const s8 str_CATCH_36[];
extern const s8 str_CATCH_37[];
extern const s8 str_CATCH_38[];
extern const s8 str_CATCH_39[];
extern const s8 str_CATCH_4[];
extern const s8 str_CATCH_40[];
extern const s8 str_CATCH_5[];
extern const s8 str_CATCH_6[];
extern const s8 str_CATCH_7[];
extern const s8 str_CATCH_8[];
extern const s8 str_CATCH_9[];
extern const s8 str_CATCH_n[];
extern const s8 str_CAT_000[];
extern const s8 str_CAUGHT[];
extern const s8 str_CAUGHT_n[];
extern const s8 str_CAU_000[];
extern const s8 str_CB[];
extern const s8 str_CGD1[];
extern const s8 str_CGD2[];
extern const s8 str_CGD3[];
extern const s8 str_CGD_TYPE[];
extern const s8 str_CG_ADD_XY[];
extern const s8 str_CG_ATT_IX[];
extern const s8 str_CG_CANCEL[];
extern const s8 str_CG_CTR[];
extern const s8 str_CG_EFFECT[];
extern const s8 str_CG_EFTYPE[];
extern const s8 str_CG_EXTDAT[];
extern const s8 str_CG_FLIP[];
extern const s8 str_CG_HIT_IX[];
extern const s8 str_CG_NIX[];
extern const s8 str_CG_NUMBER[];
extern const s8 str_CG_OLC_IX[];
extern const s8 str_CG_RIVAL[];
extern const s8 str_CG_SE[];
extern const s8 str_CG_STATUS[];
extern const s8 str_CG_TYPE[];
extern const s8 str_CHAINA[];
extern const s8 str_CHAINA_2[];
extern const s8 str_CHUN_LI[];
extern const s8 str_CMCF[];
extern const s8 str_CMCR[];
extern const s8 str_CMJ2[];
extern const s8 str_CMJ3[];
extern const s8 str_CMJ4[];
extern const s8 str_CMJA[];
extern const s8 str_CML2[];
extern const s8 str_CMLP[];
extern const s8 str_CMMD[];
extern const s8 str_CMMS[];
extern const s8 str_CMOA[];
extern const s8 str_CMSW[];
extern const s8 str_CMYD[];
extern const s8 str_CODE_H[];
extern const s8 str_CR_1P[];
extern const s8 str_CU[];
extern const s8 str_CURRENT[];
extern const s8 str_CURRENT_n[];
extern const s8 str_D[];
extern const s8 str_DADLEY_L_B[];
extern const s8 str_DAMAGE[];
extern const s8 str_DASH_HUMIKOMI[];
extern const s8 str_DASH_TOBINOKI[];
extern const s8 str_DATA_NOTHING[];
extern const s8 str_DELETE_ALL_SH4[];
extern const s8 str_DENKI[];
extern const s8 str_DIP[];
extern const s8 str_DIR_ATT[];
extern const s8 str_DIR[];
extern const s8 str_DM[];
extern const s8 str_DUDDLEY_D_S[];
extern const s8 str_DUDLEY[];
extern const s8 str_D_P_GUARD_K_L[];
extern const s8 str_D_P_GUARD_K_M[];
extern const s8 str_D_P_GUARD_K_S[];
extern const s8 str_D_P_GUARD_P_L[];
extern const s8 str_D_P_GUARD_P_M[];
extern const s8 str_D_P_GUARD_P_S[];
extern const s8 str_EDIT_INT[];
extern const s8 str_EDIT_NUM[];
extern const s8 str_EFF01_CHAR[];
extern const s8 str_EFF13_CHAR[];
extern const s8 str_EFFECT[];
extern const s8 str_ELENA[];
extern const s8 str_ELENA_ASINAGE[];
extern const s8 str_ENDING[];
extern const s8 str_ENGLAND[];
extern const s8 str_ENGLAND_2[];
extern const s8 str_ETC[];
extern const s8 str_ETC_1[];
extern const s8 str_ETC_2[];
extern const s8 str_ETC_3[];
extern const s8 str_EX[];
extern const s8 str_EXIT_1P_2P_START[];
extern const s8 str_EXIT_OK[];
extern const s8 str_EXTRA[];
extern const s8 str_FACE[];
extern const s8 str_FACE_L[];
extern const s8 str_FACE_M[];
extern const s8 str_FACE_S[];
extern const s8 str_FACE_SP[];
extern const s8 str_FLANKEN_S[];
extern const s8 str_FLASH[];
extern const s8 str_FLIP_ED[];
extern const s8 str_FLIP[];
extern const s8 str_FOOK_OKU_L[];
extern const s8 str_FOOK_OKU_M[];
extern const s8 str_FOOK_OKU_S[];
extern const s8 str_FOOK_OKU_SP[];
extern const s8 str_FOOK_TEMAE_L[];
extern const s8 str_FOOK_TEMAE_M[];
extern const s8 str_FOOK_TEMAE_S[];
extern const s8 str_FOOK_TEMAE_SP[];
extern const s8 str_FRANCE[];
extern const s8 str_FRANCE_2[];
extern const s8 str_FRONT_WALK[];
extern const s8 str_FUSHIN_K_L[];
extern const s8 str_FUSHIN_K_M[];
extern const s8 str_FUSHIN_K_S[];
extern const s8 str_FUSHIN_P_L[];
extern const s8 str_FUSHIN_P_M[];
extern const s8 str_FUSHIN_P_S[];
extern const s8 str_F_JUMP_K_L_A[];
extern const s8 str_F_JUMP_K_L_B[];
extern const s8 str_F_JUMP_K_M_A[];
extern const s8 str_F_JUMP_K_M_B[];
extern const s8 str_F_JUMP_K_S_A[];
extern const s8 str_F_JUMP_K_S_B[];
extern const s8 str_F_JUMP_P_L_A[];
extern const s8 str_F_JUMP_P_L_B[];
extern const s8 str_F_JUMP_P_M_A[];
extern const s8 str_F_JUMP_P_M_B[];
extern const s8 str_F_JUMP_P_S_A[];
extern const s8 str_F_JUMP_P_S_B[];
extern const s8 str_GERMANY[];
extern const s8 str_GERMANY_2[];
extern const s8 str_GILL[];
extern const s8 str_GILL_2[];
extern const s8 str_GILL_3[];
extern const s8 str_GILL_IMPACT_C[];
extern const s8 str_GILL_SPLASH_M[];
extern const s8 str_GILL_STAGE[];
extern const s8 str_GOUKI_1[];
extern const s8 str_GOUKI_2[];
extern const s8 str_GROUP[];
extern const s8 str_GUARD_AIR[];
extern const s8 str_GUARD_AIR_2[];
extern const s8 str_GUARD_DOWN[];
extern const s8 str_GUARD_DOWN_2[];
extern const s8 str_GUARD_HEAD[];
extern const s8 str_GUARD_HEAD_2[];
extern const s8 str_GUARD_UP[];
extern const s8 str_GUARD_UP_2[];
extern const s8 str_GUARD[];
extern const s8 str_G[];
extern const s8 str_H[];
extern const s8 str_HANASARE[];
extern const s8 str_HAND[];
extern const s8 str_HANEAGARI[];
extern const s8 str_HANEKAERI_HARA[];
extern const s8 str_HAN_000[];
extern const s8 str_HARAIGOSHI[];
extern const s8 str_HARAYARARE[];
extern const s8 str_HEAD[];
extern const s8 str_HISS[];
extern const s8 str_HIT_RANGE[];
extern const s8 str_HIT[];
extern const s8 str_HONGKONG[];
extern const s8 str_HONGKONG_0[];
extern const s8 str_HONGKONG_1[];
extern const s8 str_HOSEI[];
extern const s8 str_HOS_000[];
extern const s8 str_HS_ME[];
extern const s8 str_HS_YOU[];
extern const s8 str_HUGO[];
extern const s8 str_HUGO_BODY_S[];
extern const s8 str_HUGO_M_S_P[];
extern const s8 str_HUGO_N_G_T[];
extern const s8 str_HUGO_S_D_B_B[];
extern const s8 str_HUMI_ASIB[];
extern const s8 str_HURIMUKI[];
extern const s8 str_HUSHIN_AIR[];
extern const s8 str_HUSHIN_DOWN[];
extern const s8 str_HUSHIN_HEAD[];
extern const s8 str_HUSHIN_UP[];
extern const s8 str_H_n[];
extern const s8 str_IBUKI[];
extern const s8 str_IBUKI_2[];
extern const s8 str_IBUKI_HARAIG[];
extern const s8 str_IBUKI_KUBIORI[];
extern const s8 str_IBUKI_YOROI_D[];
extern const s8 str_IMPACT[];
extern const s8 str_INE[];
extern const s8 str_INTERRUT[];
extern const s8 str_INT_END[];
extern const s8 str_IPPONZEOI[];
extern const s8 str_IX_000[];
extern const s8 str_IX_1[];
extern const s8 str_IX_2[];
extern const s8 str_IX_3[];
extern const s8 str_IX_4[];
extern const s8 str_JAPAN2[];
extern const s8 str_JAPAN_0[];
extern const s8 str_JAPAN_1[];
extern const s8 str_JAPAN_10[];
extern const s8 str_JAPAN_11[];
extern const s8 str_JAPAN_20[];
extern const s8 str_JAPAN_21[];
extern const s8 str_JAPAN_3[];
extern const s8 str_JAPAN_30[];
extern const s8 str_JUDGEMENT_GAL[];
extern const s8 str_JUDGMENT_LOSE[];
extern const s8 str_JUDGMENT_WAIT[];
extern const s8 str_JUDGMENT_WIN[];
extern const s8 str_JUMP_BACK[];
extern const s8 str_JUMP_FRONT[];
extern const s8 str_JUMP_JUNBI[];
extern const s8 str_JUMP_VERTICAL[];
extern const s8 str_KAGAMI_B_WALK[];
extern const s8 str_KAGAMI_F_WALK[];
extern const s8 str_KAGAMI_KAMAE[];
extern const s8 str_KAGAMI_K_A[];
extern const s8 str_KAGAMI_K_B[];
extern const s8 str_KAGAMI_K_C[];
extern const s8 str_KAGAMI_L[];
extern const s8 str_KAGAMI_M[];
extern const s8 str_KAGAMI_P_A[];
extern const s8 str_KAGAMI_P_B[];
extern const s8 str_KAGAMI_P_C[];
extern const s8 str_KAGAMI_S[];
extern const s8 str_KAGAMI_SP[];
extern const s8 str_KAGAMI_TURN[];
extern const s8 str_KAGAMU[];
extern const s8 str_KAMAE[];
extern const s8 str_KARATE[];
extern const s8 str_KEN[];
extern const s8 str_KEN_HIZAGERI[];
extern const s8 str_KGM_DENGEKI_L[];
extern const s8 str_KGM_DENGEKI_M[];
extern const s8 str_KGM_DENGEKI_P[];
extern const s8 str_KGM_DENGEKI_S[];
extern const s8 str_KGM_TATAKI_L[];
extern const s8 str_KGM_TATAKI_M[];
extern const s8 str_KGM_TATAKI_S[];
extern const s8 str_KGM_TATAKI_SP[];
extern const s8 str_KGM_TOUKETU_L[];
extern const s8 str_KGM_TOUKETU_M[];
extern const s8 str_KGM_TOUKETU_P[];
extern const s8 str_KGM_TOUKETU_S[];
extern const s8 str_KGM_TTKI_V_L[];
extern const s8 str_KGM_TTKI_V_M[];
extern const s8 str_KGM_TTKI_V_S[];
extern const s8 str_KGM_TTKI_V_SP[];
extern const s8 str_KIND_WAZA[];
extern const s8 str_KIRIMOMI[];
extern const s8 str_KISHINRIKI[];
extern const s8 str_KOC_IX_PT_Nix[];
extern const s8 str_KOC_IX_PT_Nix_n[];
extern const s8 str_KUNOJI[];
extern const s8 str_KUNOJI_NOKE[];
extern const s8 str_LEG[];
extern const s8 str_LOSE_KAGAMI[];
extern const s8 str_LOSE_NO_STAND[];
extern const s8 str_LOSE_SONABA[];
extern const s8 str_L_KICK_A[];
extern const s8 str_L_KICK_B[];
extern const s8 str_L_KICK_C[];
extern const s8 str_L_PUNCH_A[];
extern const s8 str_L_PUNCH_B[];
extern const s8 str_L_PUNCH_C[];
extern const s8 str_M[];
extern const s8 str_MAWARIKOMI_M_F[];
extern const s8 str_MF[];
extern const s8 str_MKH_IX[];
extern const s8 str_MLD[];
extern const s8 str_MLF[];
extern const s8 str_MLN[];
extern const s8 str_MLR[];
extern const s8 str_MLU[];
extern const s8 str_MONKEY_FLIP[];
extern const s8 str_MOTION[];
extern const s8 str_M_2[];
extern const s8 str_M_B[];
extern const s8 str_M_KICK_A[];
extern const s8 str_M_KICK_B[];
extern const s8 str_M_KICK_C[];
extern const s8 str_M_PUNCH_A[];
extern const s8 str_M_PUNCH_B[];
extern const s8 str_M_PUNCH_C[];
extern const s8 str_NAKAI[];
extern const s8 str_NECRO[];
extern const s8 str_NECRO_F_S[];
extern const s8 str_NECRO_G_S[];
extern const s8 str_NECRO_SLAM_D[];
extern const s8 str_NECRO_SNAKE_F[];
extern const s8 str_NECRO_S_T[];
extern const s8 str_NEKOROBI_L[];
extern const s8 str_NEKOROBI_M[];
extern const s8 str_NEKOROBI_S[];
extern const s8 str_NEKOROBI_SP[];
extern const s8 str_NG_TYPE[];
extern const s8 str_NM[];
extern const s8 str_NOBASITA_TE_L[];
extern const s8 str_NOBASITA_TE_M[];
extern const s8 str_NOBASITA_TE_S[];
extern const s8 str_NOBASITA_TE_SP[];
extern const s8 str_NOKEZORI[];
extern const s8 str_NORMAL[];
extern const s8 str_NOUTEN_L[];
extern const s8 str_NOUTEN_M[];
extern const s8 str_NOUTEN_S[];
extern const s8 str_NOUTEN_SP[];
extern const s8 str_NO_1P_SHOT6[];
extern const s8 str_NO_EDIT[];
extern const s8 str_NUM_END[];
extern const s8 str_N_Y[];
extern const s8 str_N_Y_0[];
extern const s8 str_N_Y_1[];
extern const s8 str_No_12[];
extern const s8 str_OBJECT_EDIT_2[];
extern const s8 str_OBJECT_EDIT[];
extern const s8 str_OBJECT_LOOK[];
extern const s8 str_OBJECT_TEST[];
extern const s8 str_OHYA[];
extern const s8 str_OKIAGARI[];
extern const s8 str_OKIAGARI_B[];
extern const s8 str_OKIAGARI_F[];
extern const s8 str_OKIAGARI_FRONT[];
extern const s8 str_OKIAGARI_K_L[];
extern const s8 str_OKIAGARI_K_M[];
extern const s8 str_OKIAGARI_K_S[];
extern const s8 str_OKIAGARI_P_L[];
extern const s8 str_OKIAGARI_P_M[];
extern const s8 str_OKIAGARI_P_S[];
extern const s8 str_OKIAGARI_REAR[];
extern const s8 str_OLC_IX[];
extern const s8 str_ORO[];
extern const s8 str_OROMEKA[];
extern const s8 str_ORO_GIGOKU_G[];
extern const s8 str_ORO_KISINRIKI[];
extern const s8 str_ORO_KUBISIME[];
extern const s8 str_ORO_NIOURIKI[];
extern const s8 str_ORO_TOMOENAGE[];
extern const s8 str_ORUMEKA[];
extern const s8 str_PA[];
extern const s8 str_PARING_AIR_B[];
extern const s8 str_PARING_AIR_F[];
extern const s8 str_PARING_DOWN[];
extern const s8 str_PARING_HEAD[];
extern const s8 str_PARING_UP[];
extern const s8 str_PARTS_FL[];
extern const s8 str_PARTS_X_H[];
extern const s8 str_PARTS_Y_H[];
extern const s8 str_PARTS[];
extern const s8 str_PATTERN[];
extern const s8 str_PAT_ST[];
extern const s8 str_PB[];
extern const s8 str_PIYO[];
extern const s8 str_PIYO_n[];
extern const s8 str_PLAYER[];
extern const s8 str_PLEF[];
extern const s8 str_POS_X_H[];
extern const s8 str_POS_Y_H[];
extern const s8 str_POW[];
extern const s8 str_PRESS_ANY_SHOT[];
extern const s8 str_P_BREAK_AIR_F[];
extern const s8 str_P_BREAK_AIR_R[];
extern const s8 str_P_BREAK_DOWN[];
extern const s8 str_P_BREAK_UP[];
extern const s8 str_P_BREAK_ZUJOU[];
extern const s8 str_Pa[];
extern const s8 str_Q[];
extern const s8 str_R[];
extern const s8 str_RAOH[];
extern const s8 str_REACTION[];
extern const s8 str_REL_X_H[];
extern const s8 str_REL_Y_H[];
extern const s8 str_REVISE_X_H[];
extern const s8 str_REVISE_Y_H[];
extern const s8 str_RUCCIA[];
extern const s8 str_RUSSIA_0[];
extern const s8 str_RUSSIA_1[];
extern const s8 str_RUSSIA_2[];
extern const s8 str_RYU[];
extern const s8 str_RYU_SEOINAGE[];
extern const s8 str_RYU_TOMOENAGE[];
extern const s8 str_R_n[];
extern const s8 str_S[];
extern const s8 str_S1[];
extern const s8 str_S2[];
extern const s8 str_S3[];
extern const s8 str_S4[];
extern const s8 str_S5[];
extern const s8 str_S6[];
extern const s8 str_SA[];
extern const s8 str_SEAN[];
extern const s8 str_SEAN_BALL_HIT[];
extern const s8 str_SEAN_TACKLE[];
extern const s8 str_SELECT[];
extern const s8 str_SELECT_UP_DOWN[];
extern const s8 str_SHIMEOTASARE[];
extern const s8 str_SIZE_X_H[];
extern const s8 str_SIZE_Y_H[];
extern const s8 str_SNAKE_FANG[];
extern const s8 str_SPLASH_M[];
extern const s8 str_SP_APPEAR_1[];
extern const s8 str_SP_APPEAR_2[];
extern const s8 str_SP_APPEAR_3[];
extern const s8 str_SP_APPEAR_4[];
extern const s8 str_SP_APPEAR_5[];
extern const s8 str_SP_APPEAR_6[];
extern const s8 str_SP_APPEAR_7[];
extern const s8 str_SP_APPEAR_8[];
extern const s8 str_SP_AT[];
extern const s8 str_SP_B_JP_L_K_A[];
extern const s8 str_SP_B_JP_L_K_B[];
extern const s8 str_SP_B_JP_L_P_A[];
extern const s8 str_SP_B_JP_L_P_B[];
extern const s8 str_SP_B_JP_M_K_A[];
extern const s8 str_SP_B_JP_M_K_B[];
extern const s8 str_SP_B_JP_M_P_A[];
extern const s8 str_SP_B_JP_M_P_B[];
extern const s8 str_SP_B_JP_S_K_A[];
extern const s8 str_SP_B_JP_S_K_B[];
extern const s8 str_SP_B_JP_S_P_A[];
extern const s8 str_SP_B_JP_S_P_B[];
extern const s8 str_SP_F_JP_L_K_A[];
extern const s8 str_SP_F_JP_L_K_B[];
extern const s8 str_SP_F_JP_L_P_A[];
extern const s8 str_SP_F_JP_L_P_B[];
extern const s8 str_SP_F_JP_M_K_A[];
extern const s8 str_SP_F_JP_M_K_B[];
extern const s8 str_SP_F_JP_M_P_A[];
extern const s8 str_SP_F_JP_M_P_B[];
extern const s8 str_SP_F_JP_S_K_A[];
extern const s8 str_SP_F_JP_S_K_B[];
extern const s8 str_SP_F_JP_S_P_A[];
extern const s8 str_SP_F_JP_S_P_B[];
extern const s8 str_SP_JUMP_BACK[];
extern const s8 str_SP_JUMP_FRONT[];
extern const s8 str_SP_JUMP_JUNBI[];
extern const s8 str_SP_JUMP_V[];
extern const s8 str_SP_TECH[];
extern const s8 str_SP_V_JP_L_K_A[];
extern const s8 str_SP_V_JP_L_K_B[];
extern const s8 str_SP_V_JP_L_P_A[];
extern const s8 str_SP_V_JP_L_P_B[];
extern const s8 str_SP_V_JP_M_K_A[];
extern const s8 str_SP_V_JP_M_K_B[];
extern const s8 str_SP_V_JP_M_P_A[];
extern const s8 str_SP_V_JP_M_P_B[];
extern const s8 str_SP_V_JP_S_K_A[];
extern const s8 str_SP_V_JP_S_K_B[];
extern const s8 str_SP_V_JP_S_P_A[];
extern const s8 str_SP_V_JP_S_P_B[];
extern const s8 str_SP_WIN_1[];
extern const s8 str_SP_WIN_2[];
extern const s8 str_SP_WIN_3[];
extern const s8 str_SP_WIN_4[];
extern const s8 str_SP_WIN_5[];
extern const s8 str_SP_WIN_6[];
extern const s8 str_SP_WIN_7[];
extern const s8 str_SP_WIN_8[];
extern const s8 str_STAND_UP[];
extern const s8 str_S_B_JP_L_K_A[];
extern const s8 str_S_B_JP_L_K_B[];
extern const s8 str_S_B_JP_L_P_A[];
extern const s8 str_S_B_JP_L_P_B[];
extern const s8 str_S_B_JP_M_K_A[];
extern const s8 str_S_B_JP_M_K_B[];
extern const s8 str_S_B_JP_M_P_A[];
extern const s8 str_S_B_JP_M_P_B[];
extern const s8 str_S_B_JP_S_K_A[];
extern const s8 str_S_B_JP_S_K_B[];
extern const s8 str_S_B_JP_S_P_A[];
extern const s8 str_S_B_JP_S_P_B[];
extern const s8 str_S_F_JP_L_K_A[];
extern const s8 str_S_F_JP_L_K_B[];
extern const s8 str_S_F_JP_L_P_A[];
extern const s8 str_S_F_JP_L_P_B[];
extern const s8 str_S_F_JP_M_K_A[];
extern const s8 str_S_F_JP_M_K_B[];
extern const s8 str_S_F_JP_M_P_A[];
extern const s8 str_S_F_JP_M_P_B[];
extern const s8 str_S_F_JP_S_K_A[];
extern const s8 str_S_F_JP_S_K_B[];
extern const s8 str_S_F_JP_S_P_A[];
extern const s8 str_S_F_JP_S_P_B[];
extern const s8 str_S_HANEAGARI[];
extern const s8 str_S_JUMP_BACK[];
extern const s8 str_S_JUMP_FRONT[];
extern const s8 str_S_JUMP_V[];
extern const s8 str_S_KICK_A[];
extern const s8 str_S_KICK_B[];
extern const s8 str_S_KICK_C[];
extern const s8 str_S_PUNCH_A[];
extern const s8 str_S_PUNCH_B[];
extern const s8 str_S_PUNCH_C[];
extern const s8 str_S_V_JP_L_K_A[];
extern const s8 str_S_V_JP_L_K_B[];
extern const s8 str_S_V_JP_L_P_A[];
extern const s8 str_S_V_JP_L_P_B[];
extern const s8 str_S_V_JP_M_K_A[];
extern const s8 str_S_V_JP_M_K_B[];
extern const s8 str_S_V_JP_M_P_A[];
extern const s8 str_S_V_JP_M_P_B[];
extern const s8 str_S_V_JP_S_K_A[];
extern const s8 str_S_V_JP_S_K_B[];
extern const s8 str_S_V_JP_S_P_A[];
extern const s8 str_S_V_JP_S_P_B[];
extern const s8 str_TATAKI_AIR[];
extern const s8 str_TATAKI_L[];
extern const s8 str_TATAKI_M[];
extern const s8 str_TATAKI_S[];
extern const s8 str_TATAKI_SP[];
extern const s8 str_TATAKI_V_L[];
extern const s8 str_TATAKI_V_M[];
extern const s8 str_TATAKI_V_S[];
extern const s8 str_TATAKI_V_SP[];
extern const s8 str_TATI_DENGEKI_L[];
extern const s8 str_TATI_DENGEKI_M[];
extern const s8 str_TATI_DENGEKI_P[];
extern const s8 str_TATI_DENGEKI_S[];
extern const s8 str_TATI_MOE_L[];
extern const s8 str_TATI_MOE_M[];
extern const s8 str_TATI_MOE_S[];
extern const s8 str_TATI_MOE_SP[];
extern const s8 str_TATI_TOUKETU_L[];
extern const s8 str_TATI_TOUKETU_M[];
extern const s8 str_TATI_TOUKETU_P[];
extern const s8 str_TATI_TOUKETU_S[];
extern const s8 str_TATUMAKIZANKU[];
extern const s8 str_TOMOE_ORO[];
extern const s8 str_TOMOE_RYU[];
extern const s8 str_TOUKETSU_A[];
extern const s8 str_TRUNK[];
extern const s8 str_TTKI_V_AIR[];
extern const s8 str_TUKAMIHAZUSARE[];
extern const s8 str_TUKAMIHAZUSI[];
extern const s8 str_TUKAMIKAKARI_A[];
extern const s8 str_TUKAMIKAKARI_B[];
extern const s8 str_TUKAMIKAKARI_C[];
extern const s8 str_TUKAMIKAKARI_D[];
extern const s8 str_TUKAMIKAKARI_E[];
extern const s8 str_TUKAMIKAKARI_F[];
extern const s8 str_TUKAMI_AIR_A[];
extern const s8 str_TUKAMI_AIR_B[];
extern const s8 str_TUKAMI_AIR_C[];
extern const s8 str_TUKAMI_AIR_D[];
extern const s8 str_TUKAMI_AIR_E[];
extern const s8 str_TUKAMI_AIR_F[];
extern const s8 str_UKEMI_MOVE_F[];
extern const s8 str_UKEMI_MOVE_R[];
extern const s8 str_UNION[];
extern const s8 str_UPPER[];
extern const s8 str_UPPER_L[];
extern const s8 str_UPPER_M[];
extern const s8 str_UPPER_S[];
extern const s8 str_UPPER_SP[];
extern const s8 str_UP_P_GUARD_K_L[];
extern const s8 str_UP_P_GUARD_K_M[];
extern const s8 str_UP_P_GUARD_K_S[];
extern const s8 str_UP_P_GUARD_P_L[];
extern const s8 str_UP_P_GUARD_P_M[];
extern const s8 str_UP_P_GUARD_P_S[];
extern const s8 str_URIEN[];
extern const s8 str_USEMJ[];
extern const s8 str_VS_ID[];
extern const s8 str_V_JUMP_K_L_A[];
extern const s8 str_V_JUMP_K_L_B[];
extern const s8 str_V_JUMP_K_M_A[];
extern const s8 str_V_JUMP_K_M_B[];
extern const s8 str_V_JUMP_K_S_A[];
extern const s8 str_V_JUMP_K_S_B[];
extern const s8 str_V_JUMP_P_L_A[];
extern const s8 str_V_JUMP_P_L_B[];
extern const s8 str_V_JUMP_P_M_A[];
extern const s8 str_V_JUMP_P_M_B[];
extern const s8 str_V_JUMP_P_S_A[];
extern const s8 str_V_JUMP_P_S_B[];
extern const s8 str_WAIT[];
extern const s8 str_WALK_END[];
extern const s8 str_WCA[];
extern const s8 str_WCA_IX[];
extern const s8 str_WIN_1[];
extern const s8 str_WIN_2[];
extern const s8 str_WIN_3[];
extern const s8 str_WIN_4[];
extern const s8 str_WIN_5[];
extern const s8 str_WIN_6[];
extern const s8 str_WIN_7[];
extern const s8 str_WIN_8[];
extern const s8 str_WORK_EMPTY[];
extern const s8 str_YANG[];
extern const s8 str_YES_2P_SHOT6[];
extern const s8 str_YOKE_PAT[];
extern const s8 str_YOKE_TYPE[];
extern const s8 str_YOKOYAMA[];
extern const s8 str_YOSHIZUMI[];
extern const s8 str_YUN[];
extern const s8 str_YUN_2[];
extern const s8 str_YUN_HIZAGERI[];
extern const s8 str_YUN_MONKEY_F[];
extern const s8 str_YU[];
extern const s8 str_ZANNEN_1[];
extern const s8 str_ZANNEN_2[];
extern const s8 str_ZANNEN_3[];
extern const s8 str_ZANNEN_4[];
extern const s8 str_ZANNEN_5[];
extern const s8 str_ZANNEN_6[];
extern const s8 str_ZANNEN_7[];
extern const s8 str_ZANNEN_8[];
extern const s8 str_ZOKUSEI[];
extern const s8 str_ZU_FLAG[];
extern const s8 str_a[];
extern const s8 str_a_2[];
extern const s8 str_c[];
extern const s8 str_c_2[];
extern const s8 str_d[];
extern const s8 str_d_2[];
extern const s8 str_empty[];
extern const s8 str_empty_10[];
extern const s8 str_empty_2[];
extern const s8 str_empty_3[];
extern const s8 str_empty_4[];
extern const s8 str_empty_5[];
extern const s8 str_empty_6[];
extern const s8 str_empty_7[];
extern const char str_empty_8[];
extern const s8 str_empty_9[];
extern const s8 str_h[];
extern const s8 str_h_2[];
extern const s8 str_hsA[];
extern const s8 str_hsC[];
extern const s8 str_huA[];
extern const s8 str_m[];
extern const s8 str_m_2[];
extern const s8 str_n[];
extern const s8 str_n_2[];
extern const s8 str_n_3[];
extern const s8 str_n_4[];
extern const s8 str_nmA[];
extern const s8 str_nmC[];
extern const s8 str_paA[];
extern const s8 str_r[];
extern const s8 str_r_2[];
extern const s8 str_s[];
extern const s8 str_s_2[];
extern const s8 str_saA[];
extern const s8 str_saC[];
extern const s8 str_sl_00[];
extern const s8 str_sl_10[];
extern const s8 str_sl_12[];
extern const s8 str_sl_20[];
extern const s8 str_sl_22[];
extern const s8 str_sl_30[];
extern const s8 str_sl_32[];
extern const s8 str_sl_40[];
extern const s8 str_sl_42[];
extern const s8 str_sl_44[];
extern const s8 str_sl_50[];
extern const s8 str_sl_52[];
extern const s8 str_sl_54[];
extern const s8 str_sl_60[];
extern const s8 str_sl_62[];
extern const s8 str_sl_64[];
extern const s8 str_sl_70[];
extern const s8 str_sl_80[];
extern const s8 str_sl_82[];
extern const s8 str_sl_90[];

extern const char hit_kind_none_str[];
extern const char hit_kind_dd_str[];
extern const char hit_kind_uu_str[];
extern const char hit_kind_ua_str[];
extern const char hit_kind_ud_str[];
extern const char hit_kind_au_str[];
extern const char hit_kind_aa_str[];
extern const char hit_kind_ad_str[];
extern const char hit_kind_du_str[];
extern const char hit_kind_da_str[];

const char dbg_hex_mark_str[4] = "H";

const char dbg_2p_str[4] = "2P";

const char dbg_1p_str[4] = "1P";

const char dbg_hold_str[8] = "HOLD";

const char dbg_free_str[8] = "FREE";

const char dbg_copy_str[8] = "COPY";

const char dbg_user_str[8] = "USER  ";

const char dbg_define_str[8] = "DEFINE";

const char dbg_lp_str[4] = "LP";

const char dbg_nix_str[4] = "Nix";

const char dbg_l2_str[4] = "L2";

const char dbg_sw_str[4] = "SW";

const char dbg_ja_str[4] = "JA";

const char dbg_j2_str[4] = "J2";

const char dbg_oa_str[4] = "OA";

const char dbg_over_write_str[12] = "OVER WRITE";

const char dbg_insert_str[12] = "INSERT    ";

const char dbg_addition_str[12] = "ADDITION  ";

const char dbg_parts1_str[8] = "PARTS 1";

const char dbg_blank8_str[12] = "        ";

const char dbg_nothing_str[12] = " NOTHING";

const char dbg_parts2_str[8] = "PARTS 2";

const char dbg_parts3_str[8] = "PARTS 3";

const char dbg_parts4_str[8] = "PARTS 4";

const char dbg_no_extdat_str[8] = "pbao";

const char dbg_eftype_str[4] = "Rpd";

const char dbg_waza_k_str[4] = "K";

const char dbg_waza_p_str[4] = "P";

const char dbg_digit0_str[4] = "0";

const char dbg_digit1_str[4] = "1";

const char dbg_digit2_str[4] = "2";

const char dbg_wca_str[44] = {  /* "Wca", then other data */
    87, 99, 97, 0, 45, 45, 0, 0,
    43, 43, 0, 0, 0, 0, 6, 0,
    12, 0, 18, 0, 24, 0, 30, 0,
    36, 0, 42, 0, 48, 0, 54, 0,
    60, 0, 66, 0, 72, 0, 78, 0,
    84, 0, -118, 0,
};

const s16 dbg_obj_color_tbl[126] = {
    1, 1, 13, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 5, 2,
    2, 2, 2, 8, 1, 12, 7, 4,
    9, 11, 10, 34, 0, 36, 13, 40,
    5, 42, 6, 6, 9, 0x9760, 1, 0x9760,
    1, -8992, 1, 0x96E0, 1, 0x96E0, 1, 0x96E0,
    1, 0x96E0, 1, 0x96E0, 1, 0x96E0, 1, 0x96E0,
    1, 0x96E0, 1, 0x96E0, 1, 0x9DA8, 1, 0x9000,
    1, 0x9060, 1, 0x9000, 1, 0x9000, 1, 0x9000,
    1, -10240, 1, -10112, 1, -10032, 1, -9840,
    1, -9680, 1, -9616, 1, -9536, 1, -9472,
    1, -9408, 1, -9232, 1, -9152, 1, -9056,
    1, -8992, 1, -8864, 1, -8688, 1, -8480,
    1, -8416, 1, -7856, 1, -7056, 1, 0,
    256, 257, 512, 513, 768, 769, 1024, 1025,
    1280, 1536, 1792, 2048, 2049, 2304,
};

const u16 bcp_group_top_tbl[26] = {
    0, 0x600, 0xC00, 0x1200, 0x1800, 0x1E00, 0x2400, 0x2A00,
    0x3000, 0x3600, 0x3C00, 0x4200, 0x4800, 0x4E00, 0x5400, 0x5400,
    0x5A00, 0x6000, 0x6600, 0x6C00, 0x7200, 0x7800, 0x7E00, 0x8400,
    0x8A00, 0x9000,
};

const u16 bcp_group_no_tbl[30] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 14,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29,
};

const u16 bce_group_top_tbl[59] = {
    0x9000, 0x9020, 0x9060, 0x9560, 0x9660, 0x96E0, 0x9760, 0x9960,
    0x9A60, 0x9B20, 0x9B2C, 0x9B38, 0x9B44, 0x9B50, 0x9B5C, 0x9B64,
    0x9B6C, 0x9B78, 0x9B84, 0x9B70, 0x9B9C, 0x9BA8, 0x9C88, 0x9D28,
    0x9DA8, 0x9DC8, 0x9EC8, 0xA0C8, 0xA0F8, 0xA7F8, 0xA9F8, 0xABF8,
    0xADF8, 0xB1F8, 0xB2F8, 0xB3F8, 0xB478, 0xB498, 0xB4B8, 0xB518,
    0xB528, 0xB5A8, 0xB628, 0xB6A8, 0xB728, 0xB7A8, 0xB828, 0xB8A8,
    0xB928, 0xB9A8, 0xBA28, 0xBAA8, 0xBB28, 0xBBA8, 0xBC28, 0xBCA8,
    0xBD28, 0xBDA8, 0xBDE8,
};

const u16 bcb_group_top_tbl[48] = {
    0xD800, 0xD880, 0xD8D0, 0xD990, 0xDA30, 0xDA70, 0xDAC0, 0xDB00,
    0xDB40, 0xDBF0, 0xDC30, 0xDC40, 0xDCA0, 0xDCE0, 0xDD60, 0xDE10,
    0xDEE0, 0xDF20, 0xDFA0, 0xE0A0, 0xE150, 0xE170, 0xE1B0, 0xE1F0,
    0xE220, 0xE240, 0xE280, 0xE2A0, 0xE2D0, 0xE2F0, 0xE320, 0xE330,
    0xE360, 0xE390, 0xE3B0, 0xE3D0, 0xE3F0, 0xE450, 0xE470, 0xE520,
    0xE528, 0xE530, 0xE538, 0xE540, 0xE548, 0xE578, 0xE598, 0xE5B8,
};

const s16 dbg_col_code_tbl[27] = {
    128, 128, 128, 128, 128, 128, 128, 128,
    128, 128, 128, 128, 128, 99, 90, 85,
    80, 89, 88, 100, 95, 81, 81, 81,
    87, 96, 88,
};

const s16 dbg_col_no_tbl[60] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 4, 3, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 3, 3, 3, 3, 4, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2,
};

const u8 dbg_bg_select_tbl[25][2] = {
    { 0, 0 }, { 0, 0 }, { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 }, { 5, 0 },
    { 6, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { 11, 0 }, { 12, 0 }, { 13, 0 },
    { 14, 0 }, { 15, 0 }, { 16, 0 }, { 17, 0 }, { 18, 0 }, { 19, 0 }, { 20, 0 }, { 21, 0 },
    { 22, 0 },
};

const GRID_ROW hit_grid5_pos_tbl[9] = {
    { 2, 6, 6, 6 },
    { 2, 8, 6, 8 },
    { 2, 10, 6, 10 },
    { 2, 12, 6, 12 },
    { 2, 14, 6, 14 },
    { 2, 16, 6, 16 },
    { 2, 18, 6, 18 },
    { 2, 20, 6, 20 },
    { 2, 22, 6, 22 },
};

const GRID9_ROW hit_grid9_pos_tbl[7] = {
    { 30, 5, { 34, 5, 38, 5, 41, 5, 44, 5 } },
    { 30, 8, { 34, 8, 38, 8, 41, 8, 44, 8 } },
    { 30, 11, { 34, 11, 38, 11, 41, 11, 44, 11 } },
    { 30, 14, { 34, 14, 38, 14, 41, 14, 44, 14 } },
    { 30, 17, { 34, 17, 38, 17, 41, 17, 44, 17 } },
    { 30, 20, { 34, 20, 38, 20, 41, 20, 44, 20 } },
    { 30, 23, { 34, 23, 38, 23, 41, 23, 44, 23 } },
};

const JUDGE_COLUMN judge_column_tbl[7] = {
    { 3, 15, { 0, 0, 0, 0, 1 } },
    { 6, 15, { 1, 0, 0, 0, 2 } },
    { 32, 15, { 2, 0, 0, 1, 3 } },
    { 35, 15, { 3, 0, 0, 2, 4 } },
    { 39, 15, { 4, 0, 0, 3, 5 } },
    { 42, 15, { 5, 0, 0, 4, 6 } },
    { 45, 15, { 6, 0, 0, 5, 6 } },
};

const HIT_KIND hit_kind_tbl[32] = {
    { 16, 26, 16, 16, hit_kind_none_str },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 17, 0, 20, 17, hit_kind_uu_str },
    { 18, 16, 21, 18, hit_kind_ua_str },
    { 20, 17, 22, 16, hit_kind_ud_str },
    { 0, 0, 0, 0, str_empty_8 },
    { 21, 18, 24, 21, hit_kind_au_str },
    { 22, 20, 25, 22, hit_kind_aa_str },
    { 24, 21, 26, 20, hit_kind_ad_str },
    { 0, 0, 0, 0, str_empty_8 },
    { 25, 22, 16, 25, hit_kind_du_str },
    { 26, 24, 17, 26, hit_kind_da_str },
    { 0, 25, 18, 24, hit_kind_dd_str },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
    { 0, 0, 0, 0, str_empty_8 },
};

/* the debug screens' text: menu lines, move and object names */
const s8 str_OBJECT_TEST[16] = "OBJECT TEST\n";
const s8 str_BG_SELECT[16] = "BG SELECT  \n";
const s8 str_OBJECT_LOOK[16] = "OBJECT LOOK\n";
const s8 str_OBJECT_EDIT[16] = "OBJECT EDIT\n";
const s8 str_OBJECT_EDIT_2[16] = "OBJECT EDIT 2\n";
const s8 str_HIT[8] = "HIT\n";
const s8 str_ALL_CHARACTER[16] = "ALL CHARACTER\n";
const s8 str_PARTS[8] = "PARTS\n";
const s8 str_YOKOYAMA[12] = "YOKOYAMA\n";
const s8 str_NAKAI[8] = "NAKAI\n";
const s8 str_YOSHIZUMI[12] = "YOSHIZUMI\n";
const s8 str_YU[4] = "YU\n";
const s8 str_RAOH[8] = "RAOH\n";
const s8 str_INE[8] = "INE\n";
const s8 str_OHYA[8] = "OHYA";
const s8 str_SELECT_UP_DOWN[20] = "SELECT  UP DOWN\n";
const s8 str_EXIT_1P_2P_START[24] = "EXIT    1P & 2P START";
const s8 str_PLAYER[12] = "PLAYER  :\n";
const s8 str_ALL[16] = "ALL     :   /\n";
const s8 str_MOTION[16] = "MOTION  :   /\n";
const s8 str_PATTERN[16] = "PATTERN :   /\n";
const s8 str_INTERRUT[16] = "INTERRUT:   /\n";
const s8 str_CODE_H[20] = "CODE    :     H\n";
const s8 str_FLIP[12] = "FLIP    :\n";
const s8 str_FLIP_ED[12] = "FLIP ED :\n";
const s8 str_POS_X_H[20] = "POS X   :     H\n";
const s8 str_POS_Y_H[16] = "POS Y   :     H";
const s8 str_REL_X_H[20] = "REL X   :     H\n";
const s8 str_REL_Y_H[20] = "REL Y   :     H\n";
const s8 str_CURRENT[12] = "CURRENT :";
const s8 str_H_n[16] = "             H\n";
const s8 str_GROUP[16] = "GROUP         \n";
const s8 str_R_n[16] = "R             \n";
const s8 str_G[16] = "G             \n";
const s8 str_B[20] = "B               ";
const s8 str_EDIT_NUM[12] = "EDIT NUM:\n";
const s8 str_NUM_END[12] = " NUM END:\n";
const s8 str_EDIT_INT[12] = "EDIT INT:\n";
const s8 str_INT_END[12] = " INT END:";
const s8 str_CURRENT_n[12] = "CURRENT :\n";
const s8 str_PARTS_X_H[20] = "PARTS X :     H\n";
const s8 str_PARTS_Y_H[20] = "PARTS Y :     H\n";
const s8 str_PARTS_FL[12] = "PARTS FL:\n";
const s8 str_OLC_IX[12] = "OLC IX  :\n";
const s8 str_IX_1[12] = "    IX 1:\n";
const s8 str_IX_2[12] = "    IX 2:\n";
const s8 str_IX_3[12] = "    IX 3:\n";
const s8 str_IX_4[12] = "    IX 4:";
const s8 str_DELETE_ALL_SH4[20] = "DELETE ALL    SH4\n";
const s8 str_1DATA_SH5[20] = "       1DATA  SH5\n";
const s8 str_CANCEL_SH6[20] = "       CANCEL SH6";
const s8 str_n[20] = "                  \n";
const s8 str_empty[20] = "                  ";
const s8 str_NO_EDIT[24] = "NO EDIT             \n";
const s8 str_DATA_NOTHING[24] = "   DATA  NOTHING    ";
const s8 str_REVISE_X_H[20] = "REVISE X:     H\n";
const s8 str_SIZE_X_H[20] = "SIZE   X:     H\n";
const s8 str_REVISE_Y_H[20] = "REVISE Y:     H\n";
const s8 str_SIZE_Y_H[20] = "SIZE   Y:     H\n";
const s8 str_IX_000[20] = "IX 000         \n";
const s8 str_CR_1P[20] = "CR  1P         \n";
const s8 str_MF[20] = "MF             \n";
const s8 str_M_B[20] = "M__B__         \n";
const s8 str_BOD_000[12] = "BOD 000\n";
const s8 str_BHA_000[12] = "BHA 000\n";
const s8 str_HAN_000[12] = "HAN 000\n";
const s8 str_CAT_000[12] = "CAT 000\n";
const s8 str_CAU_000[12] = "CAU 000\n";
const s8 str_ATT_000[12] = "ATT 000\n";
const s8 str_HOS_000[8] = "HOS 000";
const s8 str_KOC_IX_PT_Nix_n[32] = "        KOC     IX      PT Nix\n";
const s8 str_KOC_IX_PT_Nix[32] = "        KOC     IX      PT Nix";
const s8 str_HEAD[8] = "HEAD  \n";
const s8 str_BREAST[8] = "BREAST\n";
const s8 str_TRUNK[8] = "TRUNK \n";
const s8 str_LEG[8] = "LEG   \n";
const s8 str_HAND[8] = "HAND  \n";
const s8 str_CATCH_n[8] = "CATCH \n";
const s8 str_CAUGHT_n[8] = "CAUGHT\n";
const s8 str_ATT[8] = "ATT+  \n";
const s8 str_ATT_2[8] = "ATT-  \n";
const s8 str_HOSEI[8] = "HOSEI ";
const s8 str_WORK_EMPTY[16] = "WORK EMPTY !!\n";
const s8 str_PRESS_ANY_SHOT[16] = "PRESS ANY SHOT";
const s8 str_n_2[20] = "                 \n";
const s8 str_empty_2[20] = "                 ";
const s8 str_EXIT_OK[16] = " EXIT OK ? \n";
const s8 str_YES_2P_SHOT6[20] = " YES : 2P-SHOT6 \n";
const s8 str_NO_1P_SHOT6[20] = " NO  : 1P-SHOT6 ";
const s8 str_CG_CTR[24] = "CG CTR        (    )\n";
const s8 str_CG_TYPE[12] = "CG TYPE  \n";
const s8 str_CG_SE[24] = "CG SE         (    )\n";
const s8 str_CG_FLIP[24] = "CG FLIP       (    )\n";
const s8 str_CG_OLC_IX[24] = "CG OLC IX     (    )\n";
const s8 str_CG_NUMBER[12] = "CG NUMBER";
const s8 str_CG_ATT_IX[24] = "CG ATT IX     (    )\n";
const s8 str_CG_HIT_IX[24] = "CG HIT IX     (    )\n";
const s8 str_CG_EXTDAT[12] = "CG EXTDAT\n";
const s8 str_CG_CANCEL[12] = "CG CANCEL\n";
const s8 str_CG_EFFECT[12] = "CG EFFECT\n";
const s8 str_CG_EFTYPE[12] = "CG EFTYPE  ";
const s8 str_CG_RIVAL[24] = "CG RIVAL      (    )\n";
const s8 str_CG_ADD_XY[24] = "CG ADD XY     (    )\n";
const s8 str_CG_NIX[8] = "CG NIX\n";
const s8 str_CG_STATUS[12] = "CG STATUS";
const s8 str_CGD_TYPE[12] = "CGD TYPE \n";
const s8 str_PAT_ST[12] = "PAT ST   \n";
const s8 str_KIND_WAZA[12] = "KIND WAZA\n";
const s8 str_HIT_RANGE[12] = "HIT RANGE\n";
const s8 str_YOKE_TYPE[12] = "YOKE TYPE\n";
const s8 str_YOKE_PAT[12] = "YOKE PAT \n";
const s8 str_SP_TECH[12] = "SP TECH\n";
const s8 str_WCA_IX[8] = "WCA IX";
const s8 str_ATT_IX[8] = "ATT IX\n";
const s8 str_REACTION[24] = "REACTION      (    )\n";
const s8 str_MKH_IX[24] = "MKH IX        (    )\n";
const s8 str_DIP[24] = "DIP           (    )\n";
const s8 str_HISS[24] = "HISS          (    )\n";
const s8 str_DIR[24] = "DIR           (    )\n";
const s8 str_GUARD[24] = "GUARD         (    )\n";
const s8 str_POW[24] = "POW           (    )\n";
const s8 str_IMPACT[24] = "IMPACT        (    )\n";
const s8 str_PIYO_n[24] = "PIYO          (    )\n";
const s8 str_NG_TYPE[24] = "NG TYPE       (    )\n";
const s8 str_HS_ME[24] = "HS ME         (    )\n";
const s8 str_HS_YOU[24] = "HS YOU        (    )\n";
const s8 str_ZU_FLAG[24] = "ZU FLAG       (    )\n";
const s8 str_ZOKUSEI[24] = "ZOKUSEI       (    )\n";
const s8 str_AT_LEVEL[24] = "AT LEVEL      (    )\n";
const s8 str_ADD_ARTS[24] = "ADD ARTS      (    )\n";
const s8 str_BUTT_TYPE[24] = "BUTT TYPE     (    )\n";
const s8 str_BUTT_PAT[24] = "BUTT PAT      (    )\n";
const s8 str_DIR_ATT[24] = "DIR ATT       (    )\n";
const s8 str_VS_ID[24] = "VS ID         (    )";
const s8 str_n_3[32] = "                            \n";
const s8 str_empty_3[32] = "                            ";
const s8 str_n_4[40] = "                                     \n";
const s8 str_empty_4[40] = "                                     ";
const s8 str_CMOA[8] = "CMOA\n";
const s8 str_CMSW[8] = "CMSW\n";
const s8 str_CMLP[8] = "CMLP\n";
const s8 str_CML2[8] = "CML2\n";
const s8 str_CMJA[8] = "CMJA\n";
const s8 str_CMJ2[8] = "CMJ2\n";
const s8 str_CMJ3[8] = "CMJ3\n";
const s8 str_CMJ4[8] = "CMJ4\n";
const s8 str_CMMS[8] = "CMMS\n";
const s8 str_CMMD[8] = "CMMD\n";
const s8 str_CMYD[8] = "CMYD\n";
const s8 str_CMCF[8] = "CMCF\n";
const s8 str_CMCR[8] = "CMCR";
const s8 str_WCA[8] = "WCA ";
const s8 str_CGD1[8] = "CGD1";
const s8 str_CGD2[8] = "CGD2";
const s8 str_CGD3[8] = "CGD3";
const s8 str_empty_5[8] = "    ";
const s8 str_sl_00[8] = "sl_00";
const s8 str_sl_10[8] = "sl_10";
const s8 str_sl_12[8] = "sl_12";
const s8 str_sl_20[8] = "sl_20";
const s8 str_sl_22[8] = "sl_22";
const s8 str_sl_30[8] = "sl_30";
const s8 str_sl_32[8] = "sl_32";
const s8 str_sl_40[8] = "sl_40";
const s8 str_sl_42[8] = "sl_42";
const s8 str_sl_44[8] = "sl_44";
const s8 str_sl_50[8] = "sl_50";
const s8 str_sl_52[8] = "sl_52";
const s8 str_sl_54[8] = "sl_54";
const s8 str_sl_60[8] = "sl_60";
const s8 str_sl_62[8] = "sl_62";
const s8 str_sl_64[8] = "sl_64";
const s8 str_sl_70[8] = "sl_70";
const s8 str_sl_80[8] = "sl_80";
const s8 str_sl_82[8] = "sl_82";
const s8 str_sl_90[8] = "sl_90";
const s8 str_empty_6[8] = "     ";
const s8 str_Pa[4] = "Pa";
const s8 str_PA[4] = "PA";
const s8 str_PB[4] = "PB";
const s8 str_MLN[4] = "MLN";
const s8 str_MLU[4] = "MLU";
const s8 str_MLD[4] = "MLD";
const s8 str_MLF[4] = "MLF";
const s8 str_MLR[4] = "MLR";
const s8 str_M[4] = "M__";
const s8 str_S1[4] = "S1";
const s8 str_S2[4] = "S2";
const s8 str_S3[4] = "S3";
const s8 str_S4[4] = "S4";
const s8 str_S5[4] = "S5";
const s8 str_S6[4] = "S6";
const s8 str_empty_7[8] = "      ";
const s8 str_USEMJ[8] = "+USEMJ";
const s8 str_BASE[8] = "BASE  ";
const s8 str_BEFORE[8] = "BEFORE";
const s8 str_BACK[8] = "BACK  ";
const s8 str_H[4] = "H";
const s8 str_D[4] = "D";
const s8 str_A[4] = "A";
const s8 str_M_2[4] = "M";
const s8 str_R[4] = "R";
const s8 str_C[4] = "C";
const s8 str_S[4] = "S";
const s8 str_h[4] = "h";
const s8 str_d[4] = "d";
const s8 str_a[4] = "a";
const s8 str_m[4] = "m";
const s8 str_r[4] = "r";
const s8 str_c[4] = "c";
const s8 str_s[4] = "s";
const s8 str_h_2[4] = "h ";
const s8 str_d_2[4] = "d ";
const s8 str_a_2[4] = "a ";
const s8 str_m_2[4] = "m ";
const s8 str_r_2[4] = "r ";
const s8 str_c_2[4] = "c ";
const s8 str_s_2[4] = "s ";
const s8 str_NM[4] = "NM";
const s8 str_DM[4] = "DM";
const s8 str_CA[4] = "CA";
const s8 str_CU[4] = "CU";
const s8 str_AT[4] = "AT";
const s8 str_BT[4] = "BT";
const s8 str_EX[4] = "EX";
const s8 str_SA[4] = "SA";
const s8 str_CB[4] = "CB";
const char str_empty_8[4] = "  ";
const s8 str_nmA[4] = "nmA";
const s8 str_hsA[4] = "hsA";
const s8 str_nmC[4] = "nmC";
const s8 str_hsC[4] = "hsC";
const s8 str_saA[4] = "saA";
const s8 str_saC[4] = "saC";
const s8 str_paA[4] = "paA";
const s8 str_huA[4] = "huA";
const s8 str_BLANK[16] = "BLANK        ";
const s8 str_FLASH[16] = "FLASH        ";
const s8 str_GILL[16] = "GILL         ";
const s8 str_N_Y_0[16] = "N.Y 0        ";
const s8 str_JAPAN_0[16] = "JAPAN 0      ";
const s8 str_HONGKONG_0[16] = "HONGKONG 0   ";
const s8 str_ENGLAND[16] = "ENGLAND      ";
const s8 str_RUSSIA_0[16] = "RUSSIA 0     ";
const s8 str_GERMANY[16] = "GERMANY      ";
const s8 str_JAPAN_1[16] = "JAPAN 1      ";
const s8 str_AFRICA[16] = "AFRICA       ";
const s8 str_BRAZIL[16] = "BRAZIL       ";
const s8 str_HONGKONG_1[16] = "HONGKONG 1   ";
const s8 str_N_Y_1[16] = "N.Y 1        ";
const s8 str_BRAZIL_1[16] = "BRAZIL 1     ";
const s8 str_OROMEKA[16] = "OROMEKA      ";
const s8 str_JAPAN_20[16] = "JAPAN 20     ";
const s8 str_JAPAN_21[16] = "JAPAN 21     ";
const s8 str_CHAINA[16] = "CHAINA       ";
const s8 str_JAPAN_30[16] = "JAPAN 30     ";
const s8 str_RUSSIA_1[16] = "RUSSIA 1     ";
const s8 str_RUSSIA_2[16] = "RUSSIA 2     ";
const s8 str_FRANCE[16] = "FRANCE       ";
const s8 str_BONUS_1[16] = "BONUS 1      ";
const s8 str_BONUS_2[16] = "BONUS 2      ";
const s8 str_GILL_2[8] = "GILL   ";
const s8 str_ALEX[8] = "ALEX   ";
const s8 str_RYU[8] = "RYU    ";
const s8 str_YUN[8] = "YUN    ";
const s8 str_DUDLEY[8] = "DUDLEY ";
const s8 str_NECRO[8] = "NECRO  ";
const s8 str_HUGO[8] = "HUGO   ";
const s8 str_IBUKI[8] = "IBUKI  ";
const s8 str_ELENA[8] = "ELENA  ";
const s8 str_ORO[8] = "ORO    ";
const s8 str_YANG[8] = "YANG   ";
const s8 str_KEN[8] = "KEN    ";
const s8 str_SEAN[8] = "SEAN   ";
const s8 str_URIEN[8] = "URIEN  ";
const s8 str_GOUKI_1[8] = "GOUKI 1";
const s8 str_GOUKI_2[8] = "GOUKI 2";
const s8 str_CHUN_LI[8] = "CHUN-LI";
const s8 str_KARATE[8] = "KARATE ";
const s8 str_Q[8] = "Q      ";
const s8 str_No_12[8] = "No.12  ";
const s8 str_BIKEI[8] = "BIKEI  ";
const s8 str_empty_9[8] = "       ";
const s8 str_ETC[8] = "ETC    ";
const s8 str_NORMAL[8] = "NORMAL ";
const s8 str_DAMAGE[8] = "DAMAGE ";
const s8 str_CATCH[8] = "CATCH  ";
const s8 str_CAUGHT[8] = "CAUGHT ";
const s8 str_ATTACK[8] = "ATTACK ";
const s8 str_SP_AT[8] = "SP AT  ";
const s8 str_BUTTOBI[8] = "BUTTOBI";
const s8 str_UNION[8] = "UNION  ";
const s8 str_EFFECT[8] = "EFFECT ";
const s8 str_KAMAE[16] = "KAMAE         ";
const s8 str_HURIMUKI[16] = "HURIMUKI      ";
const s8 str_FRONT_WALK[16] = "FRONT WALK    ";
const s8 str_BACK_WALK[16] = "BACK  WALK    ";
const s8 str_DASH_HUMIKOMI[16] = "DASH  HUMIKOMI";
const s8 str_DASH_TOBINOKI[16] = "DASH  TOBINOKI";
const s8 str_KAGAMU[16] = "KAGAMU        ";
const s8 str_KAGAMI_KAMAE[16] = "KAGAMI KAMAE  ";
const s8 str_KAGAMI_TURN[16] = "KAGAMI TURN   ";
const s8 str_KAGAMI_F_WALK[16] = "KAGAMI F WALK ";
const s8 str_KAGAMI_B_WALK[16] = "KAGAMI B WALK ";
const s8 str_STAND_UP[16] = "STAND UP      ";
const s8 str_JUMP_JUNBI[16] = "JUMP     JUNBI";
const s8 str_SP_JUMP_JUNBI[16] = "SP JUMP  JUNBI";
const s8 str_JUMP_FRONT[16] = "JUMP FRONT    ";
const s8 str_JUMP_VERTICAL[16] = "JUMP VERTICAL ";
const s8 str_JUMP_BACK[16] = "JUMP BACK     ";
const s8 str_S_JUMP_FRONT[16] = "S JUMP FRONT  ";
const s8 str_S_JUMP_V[16] = "S JUMP V      ";
const s8 str_S_JUMP_BACK[16] = "S JUMP BACK   ";
const s8 str_SP_JUMP_FRONT[16] = "SP JUMP FRONT ";
const s8 str_SP_JUMP_V[16] = "SP JUMP V     ";
const s8 str_SP_JUMP_BACK[16] = "SP JUMP BACK  ";
const s8 str_WALK_END[16] = "WALK END      ";
const s8 str_PARING_HEAD[16] = "PARING  HEAD  ";
const s8 str_PARING_UP[16] = "PARING  UP    ";
const s8 str_PARING_DOWN[16] = "PARING  DOWN  ";
const s8 str_PARING_AIR_F[16] = "PARING  AIR F ";
const s8 str_PARING_AIR_B[16] = "PARING  AIR B ";
const s8 str_GUARD_HEAD[16] = "GUARD  HEAD   ";
const s8 str_GUARD_UP[16] = "GUARD  UP     ";
const s8 str_GUARD_DOWN[16] = "GUARD  DOWN   ";
const s8 str_GUARD_AIR[16] = "GUARD  AIR    ";
const s8 str_empty_10[16] = "              ";
const s8 str_P_BREAK_ZUJOU[16] = "P BREAK  ZUJOU";
const s8 str_P_BREAK_UP[16] = "P BREAK  UP   ";
const s8 str_P_BREAK_DOWN[16] = "P BREAK  DOWN ";
const s8 str_P_BREAK_AIR_F[16] = "P BREAK  AIR F";
const s8 str_P_BREAK_AIR_R[16] = "P BREAK  AIR R";
const s8 str_TUKAMIHAZUSI[16] = "TUKAMIHAZUSI  ";
const s8 str_TUKAMIHAZUSARE[16] = "TUKAMIHAZUSARE";
const s8 str_GUARD_HEAD_2[16] = "GUARD HEAD    ";
const s8 str_GUARD_UP_2[16] = "GUARD UP      ";
const s8 str_GUARD_DOWN_2[16] = "GUARD DOWN    ";
const s8 str_GUARD_AIR_2[16] = "GUARD AIR     ";
const s8 str_HUSHIN_HEAD[16] = "HUSHIN  HEAD  ";
const s8 str_HUSHIN_UP[16] = "HUSHIN  UP    ";
const s8 str_HUSHIN_DOWN[16] = "HUSHIN  DOWN  ";
const s8 str_HUSHIN_AIR[16] = "HUSHIN  AIR   ";
const s8 str_FACE_S[16] = "FACE  S       ";
const s8 str_FACE_M[16] = "FACE  M       ";
const s8 str_FACE_L[16] = "FACE  L       ";
const s8 str_FACE_SP[16] = "FACE  SP      ";
const s8 str_FOOK_OKU_S[16] = "FOOK OKU  S   ";
const s8 str_FOOK_OKU_M[16] = "FOOK OKU  M   ";
const s8 str_FOOK_OKU_L[16] = "FOOK OKU  L   ";
const s8 str_FOOK_OKU_SP[16] = "FOOK OKU  SP  ";
const s8 str_FOOK_TEMAE_S[16] = "FOOK TEMAE  S ";
const s8 str_FOOK_TEMAE_M[16] = "FOOK TEMAE  M ";
const s8 str_FOOK_TEMAE_L[16] = "FOOK TEMAE  L ";
const s8 str_FOOK_TEMAE_SP[16] = "FOOK TEMAE  SP";
const s8 str_UPPER_S[16] = "UPPER  S      ";
const s8 str_UPPER_M[16] = "UPPER  M      ";
const s8 str_UPPER_L[16] = "UPPER  L      ";
const s8 str_UPPER_SP[16] = "UPPER  SP     ";
const s8 str_NOUTEN_S[16] = "NOUTEN  S     ";
const s8 str_NOUTEN_M[16] = "NOUTEN  M     ";
const s8 str_NOUTEN_L[16] = "NOUTEN  L     ";
const s8 str_NOUTEN_SP[16] = "NOUTEN  SP    ";
const s8 str_BODY_BROW_S[16] = "BODY BROW   S ";
const s8 str_BODY_BROW_M[16] = "BODY BROW   M ";
const s8 str_BODY_BROW_L[16] = "BODY BROW   L ";
const s8 str_BODY_BROW_SP[16] = "BODY BROW   SP";
const s8 str_BODY_UPPER_S[16] = "BODY UPPER  S ";
const s8 str_BODY_UPPER_M[16] = "BODY UPPER  M ";
const s8 str_BODY_UPPER_L[16] = "BODY UPPER  L ";
const s8 str_BODY_UPPER_SP[16] = "BODY UPPER  SP";
const s8 str_TATAKI_S[16] = "TATAKI  S     ";
const s8 str_TATAKI_M[16] = "TATAKI  M     ";
const s8 str_TATAKI_L[16] = "TATAKI  L     ";
const s8 str_TATAKI_SP[16] = "TATAKI  SP    ";
const s8 str_TATAKI_V_S[16] = "TATAKI V. S   ";
const s8 str_TATAKI_V_M[16] = "TATAKI V. M   ";
const s8 str_TATAKI_V_L[16] = "TATAKI V. L   ";
const s8 str_TATAKI_V_SP[16] = "TATAKI V. SP  ";
const s8 str_NOBASITA_TE_S[16] = "NOBASITA TE  S";
const s8 str_NOBASITA_TE_M[16] = "NOBASITA TE  M";
const s8 str_NOBASITA_TE_L[16] = "NOBASITA TE  L";
const s8 str_NOBASITA_TE_SP[16] = "NOBASITA TE SP";
const s8 str_KAGAMI_S[16] = "KAGAMI  S     ";
const s8 str_KAGAMI_M[16] = "KAGAMI  M     ";
const s8 str_KAGAMI_L[16] = "KAGAMI  L     ";
const s8 str_KAGAMI_SP[16] = "KAGAMI  SP    ";
const s8 str_KGM_TATAKI_S[16] = "KGM TATAKI S  ";
const s8 str_KGM_TATAKI_M[16] = "KGM TATAKI M  ";
const s8 str_KGM_TATAKI_L[16] = "KGM TATAKI L  ";
const s8 str_KGM_TATAKI_SP[16] = "KGM TATAKI SP ";
const s8 str_KGM_TTKI_V_S[16] = "KGM TTKI V.S  ";
const s8 str_KGM_TTKI_V_M[16] = "KGM TTKI V.M  ";
const s8 str_KGM_TTKI_V_L[16] = "KGM TTKI V.L  ";
const s8 str_KGM_TTKI_V_SP[16] = "KGM TTKI V.SP ";
const s8 str_NEKOROBI_S[16] = "NEKOROBI  S   ";
const s8 str_NEKOROBI_M[16] = "NEKOROBI  M   ";
const s8 str_NEKOROBI_L[16] = "NEKOROBI  L   ";
const s8 str_NEKOROBI_SP[16] = "NEKOROBI  SP  ";
const s8 str_OKIAGARI[16] = "OKIAGARI      ";
const s8 str_OKIAGARI_F[16] = "OKIAGARI  F   ";
const s8 str_OKIAGARI_B[16] = "OKIAGARI  B   ";
const s8 str_LOSE_NO_STAND[16] = "LOSE  NO STAND";
const s8 str_LOSE_SONABA[16] = "LOSE  SONABA  ";
const s8 str_LOSE_KAGAMI[16] = "LOSE  KAGAMI  ";
const s8 str_PIYO[16] = "PIYO          ";
const s8 str_UKEMI_MOVE_F[16] = "UKEMI MOVE F  ";
const s8 str_UKEMI_MOVE_R[16] = "UKEMI MOVE R  ";
const s8 str_SHIMEOTASARE[16] = "SHIMEOTASARE  ";
const s8 str_TATI_TOUKETU_S[16] = "TATI TOUKETU S";
const s8 str_TATI_TOUKETU_M[16] = "TATI TOUKETU M";
const s8 str_TATI_TOUKETU_L[16] = "TATI TOUKETU L";
const s8 str_TATI_TOUKETU_P[16] = "TATI TOUKETU P";
const s8 str_KGM_TOUKETU_S[16] = "KGM  TOUKETU S";
const s8 str_KGM_TOUKETU_M[16] = "KGM  TOUKETU M";
const s8 str_KGM_TOUKETU_L[16] = "KGM  TOUKETU L";
const s8 str_KGM_TOUKETU_P[16] = "KGM  TOUKETU P";
const s8 str_TATI_DENGEKI_S[16] = "TATI DENGEKI S";
const s8 str_TATI_DENGEKI_M[16] = "TATI DENGEKI M";
const s8 str_TATI_DENGEKI_L[16] = "TATI DENGEKI L";
const s8 str_TATI_DENGEKI_P[16] = "TATI DENGEKI P";
const s8 str_KGM_DENGEKI_S[16] = "KGM  DENGEKI S";
const s8 str_KGM_DENGEKI_M[16] = "KGM  DENGEKI M";
const s8 str_KGM_DENGEKI_L[16] = "KGM  DENGEKI L";
const s8 str_KGM_DENGEKI_P[16] = "KGM  DENGEKI P";
const s8 str_OKIAGARI_FRONT[16] = "OKIAGARI FRONT";
const s8 str_OKIAGARI_REAR[16] = "OKIAGARI REAR ";
const s8 str_TATI_MOE_S[16] = "TATI MOE  S   ";
const s8 str_TATI_MOE_M[16] = "TATI MOE  M   ";
const s8 str_TATI_MOE_L[16] = "TATI MOE  L   ";
const s8 str_TATI_MOE_SP[16] = "TATI MOE  SP  ";
const s8 str_AIR_NORMAL[16] = "AIR  NORMAL   ";
const s8 str_ASIBARAI_SIRI[16] = "ASIBARAI SIRI ";
const s8 str_ASIB_TUNNOMERI[16] = "ASIB TUNNOMERI";
const s8 str_NOKEZORI[16] = "NOKEZORI      ";
const s8 str_KUNOJI[16] = "KUNOJI        ";
const s8 str_KIRIMOMI[16] = "KIRIMOMI      ";
const s8 str_UPPER[16] = "UPPER         ";
const s8 str_BODY_UPPER[16] = "BODY UPPER    ";
const s8 str_HARAYARARE[16] = "HARAYARARE    ";
const s8 str_TATAKI_AIR[16] = "TATAKI  AIR   ";
const s8 str_TTKI_V_AIR[16] = "TTKI V. AIR   ";
const s8 str_HUMI_ASIB[16] = "HUMI ASIB     ";
const s8 str_FACE[16] = "FACE          ";
const s8 str_ASIB_SIRI_LOSE[16] = "ASIB SIRI LOSE";
const s8 str_ASIB_TUN_LOSE[16] = "ASIB TUN  LOSE";
const s8 str_DENKI[16] = "DENKI         ";
const s8 str_KUNOJI_NOKE[16] = "KUNOJI NOKE   ";
const s8 str_BODY_UPPER_SP_2[16] = "BODY UPPER SP ";
const s8 str_HANEAGARI[16] = "HANEAGARI     ";
const s8 str_TOUKETSU_A[16] = "TOUKETSU  A   ";
const s8 str_BODY_SLAM[16] = "BODY SLAM     ";
const s8 str_IPPONZEOI[16] = "IPPONZEOI     ";
const s8 str_TOMOE_RYU[16] = "TOMOE  RYU    ";
const s8 str_MONKEY_FLIP[16] = "MONKEY FLIP   ";
const s8 str_TOMOE_ORO[16] = "TOMOE ORO     ";
const s8 str_SNAKE_FANG[16] = "SNAKE FANG    ";
const s8 str_FLANKEN_S[16] = "FLANKEN.S     ";
const s8 str_KISHINRIKI[16] = "KISHINRIKI    ";
const s8 str_SPLASH_M[16] = "SPLASH.M      ";
const s8 str_HARAIGOSHI[16] = "HARAIGOSHI    ";
const s8 str_ALEX_B_D[16] = "ALEX B.D      ";
const s8 str_GILL_3[16] = "GILL          ";
const s8 str_HANEKAERI_HARA[16] = "HANEKAERI HARA";
const s8 str_S_HANEAGARI[16] = "S HANEAGARI   ";
const s8 str_TATUMAKIZANKU[16] = "TATUMAKIZANKU ";
const s8 str_CATCH_1[16] = "CATCH  1      ";
const s8 str_CATCH_2[16] = "CATCH  2      ";
const s8 str_CATCH_3[16] = "CATCH  3      ";
const s8 str_CATCH_4[16] = "CATCH  4      ";
const s8 str_CATCH_5[16] = "CATCH  5      ";
const s8 str_CATCH_6[16] = "CATCH  6      ";
const s8 str_CATCH_7[16] = "CATCH  7      ";
const s8 str_CATCH_8[16] = "CATCH  8      ";
const s8 str_CATCH_9[16] = "CATCH  9      ";
const s8 str_CATCH_10[16] = "CATCH  10     ";
const s8 str_CATCH_11[16] = "CATCH  11     ";
const s8 str_CATCH_12[16] = "CATCH  12     ";
const s8 str_CATCH_13[16] = "CATCH  13     ";
const s8 str_CATCH_14[16] = "CATCH  14     ";
const s8 str_CATCH_15[16] = "CATCH  15     ";
const s8 str_CATCH_16[16] = "CATCH  16     ";
const s8 str_CATCH_17[16] = "CATCH  17     ";
const s8 str_CATCH_18[16] = "CATCH  18     ";
const s8 str_CATCH_19[16] = "CATCH  19     ";
const s8 str_CATCH_20[16] = "CATCH  20     ";
const s8 str_CATCH_21[16] = "CATCH  21     ";
const s8 str_CATCH_22[16] = "CATCH  22     ";
const s8 str_CATCH_23[16] = "CATCH  23     ";
const s8 str_CATCH_24[16] = "CATCH  24     ";
const s8 str_CATCH_25[16] = "CATCH  25     ";
const s8 str_CATCH_26[16] = "CATCH  26     ";
const s8 str_CATCH_27[16] = "CATCH  27     ";
const s8 str_CATCH_28[16] = "CATCH  28     ";
const s8 str_CATCH_29[16] = "CATCH  29     ";
const s8 str_CATCH_30[16] = "CATCH  30     ";
const s8 str_CATCH_31[16] = "CATCH  31     ";
const s8 str_CATCH_32[16] = "CATCH  32     ";
const s8 str_CATCH_33[16] = "CATCH  33     ";
const s8 str_CATCH_34[16] = "CATCH  34     ";
const s8 str_CATCH_35[16] = "CATCH  35     ";
const s8 str_CATCH_36[16] = "CATCH  36     ";
const s8 str_CATCH_37[16] = "CATCH  37     ";
const s8 str_CATCH_38[16] = "CATCH  38     ";
const s8 str_CATCH_39[16] = "CATCH  39     ";
const s8 str_CATCH_40[16] = "CATCH  40     ";
const s8 str_ALEX_ZUTUKI[16] = "ALEX ZUTUKI   ";
const s8 str_ALEX_BODY_S[16] = "ALEX BODY S   ";
const s8 str_ALEX_BACK_D[16] = "ALEX BACK D   ";
const s8 str_ALEX_POWER_B[16] = "ALEX POWER B  ";
const s8 str_ALEX_SLEEPER[16] = "ALEX SLEEPER  ";
const s8 str_RYU_SEOINAGE[16] = "RYU SEOINAGE  ";
const s8 str_IBUKI_2[16] = "IBUKI         ";
const s8 str_DADLEY_L_B[16] = "DADLEY  L B   ";
const s8 str_IBUKI_KUBIORI[16] = "IBUKI KUBIORI ";
const s8 str_NECRO_S_T[16] = "NECRO S T     ";
const s8 str_RYU_TOMOENAGE[16] = "RYU TOMOENAGE ";
const s8 str_YUN_HIZAGERI[16] = "YUN HIZAGERI  ";
const s8 str_ORO_KUBISIME[16] = "ORO KUBISIME  ";
const s8 str_NECRO_G_S[16] = "NECRO G S     ";
const s8 str_DUDDLEY_D_S[16] = "DUDDLEY D S   ";
const s8 str_YUN_MONKEY_F[16] = "YUN MONKEY F  ";
const s8 str_ORO_TOMOENAGE[16] = "ORO TOMOENAGE ";
const s8 str_ORO_NIOURIKI[16] = "ORO NIOURIKI  ";
const s8 str_ORO_GIGOKU_G[16] = "ORO GIGOKU G  ";
const s8 str_YUN_2[16] = "YUN           ";
const s8 str_NECRO_SNAKE_F[16] = "NECRO SNAKE F ";
const s8 str_NECRO_F_S[16] = "NECRO F S     ";
const s8 str_IBUKI_HARAIG[16] = "IBUKI HARAIG  ";
const s8 str_GILL_SPLASH_M[16] = "GILL SPLASH M ";
const s8 str_KEN_HIZAGERI[16] = "KEN HIZAGERI  ";
const s8 str_ORO_KISINRIKI[16] = "ORO KISINRIKI ";
const s8 str_SEAN_TACKLE[16] = "SEAN TACKLE   ";
const s8 str_ALEX_HYPER_B[16] = "ALEX HYPER B  ";
const s8 str_NECRO_SLAM_D[16] = "NECRO SLAM D  ";
const s8 str_ELENA_ASINAGE[16] = "ELENA ASINAGE ";
const s8 str_GILL_IMPACT_C[16] = "GILL IMPACT C ";
const s8 str_ALEX_S_H_B[16] = "ALEX  S H B   ";
const s8 str_ALEX_F_N_D[16] = "ALEX  F N D   ";
const s8 str_IBUKI_YOROI_D[16] = "IBUKI YOROI D ";
const s8 str_MAWARIKOMI_M_F[16] = "MAWARIKOMI M F";
const s8 str_HUGO_BODY_S[16] = "HUGO BODY S   ";
const s8 str_HUGO_N_G_T[16] = "HUGO N G T    ";
const s8 str_HUGO_M_S_P[16] = "HUGO M S P    ";
const s8 str_HUGO_S_D_B_B[16] = "HUGO S D B B  ";
const s8 str_S_PUNCH_A[16] = "S PUNCH  A    ";
const s8 str_S_PUNCH_B[16] = "S PUNCH  B    ";
const s8 str_S_PUNCH_C[16] = "S PUNCH  C    ";
const s8 str_M_PUNCH_A[16] = "M PUNCH  A    ";
const s8 str_M_PUNCH_B[16] = "M PUNCH  B    ";
const s8 str_M_PUNCH_C[16] = "M PUNCH  C    ";
const s8 str_L_PUNCH_A[16] = "L PUNCH  A    ";
const s8 str_L_PUNCH_B[16] = "L PUNCH  B    ";
const s8 str_L_PUNCH_C[16] = "L PUNCH  C    ";
const s8 str_S_KICK_A[16] = "S KICK   A    ";
const s8 str_S_KICK_B[16] = "S KICK   B    ";
const s8 str_S_KICK_C[16] = "S KICK   C    ";
const s8 str_M_KICK_A[16] = "M KICK   A    ";
const s8 str_M_KICK_B[16] = "M KICK   B    ";
const s8 str_M_KICK_C[16] = "M KICK   C    ";
const s8 str_L_KICK_A[16] = "L KICK   A    ";
const s8 str_L_KICK_B[16] = "L KICK   B    ";
const s8 str_L_KICK_C[16] = "L KICK   C    ";
const s8 str_KAGAMI_P_A[16] = "KAGAMI P  A   ";
const s8 str_KAGAMI_P_B[16] = "KAGAMI P  B   ";
const s8 str_KAGAMI_P_C[16] = "KAGAMI P  C   ";
const s8 str_KAGAMI_K_A[16] = "KAGAMI K  A   ";
const s8 str_KAGAMI_K_B[16] = "KAGAMI K  B   ";
const s8 str_KAGAMI_K_C[16] = "KAGAMI K  C   ";
const s8 str_V_JUMP_P_S_A[16] = "V JUMP P S  A ";
const s8 str_V_JUMP_P_S_B[16] = "V JUMP P S  B ";
const s8 str_V_JUMP_P_M_A[16] = "V JUMP P M  A ";
const s8 str_V_JUMP_P_M_B[16] = "V JUMP P M  B ";
const s8 str_V_JUMP_P_L_A[16] = "V JUMP P L  A ";
const s8 str_V_JUMP_P_L_B[16] = "V JUMP P L  B ";
const s8 str_V_JUMP_K_S_A[16] = "V JUMP K S  A ";
const s8 str_V_JUMP_K_S_B[16] = "V JUMP K S  B ";
const s8 str_V_JUMP_K_M_A[16] = "V JUMP K M  A ";
const s8 str_V_JUMP_K_M_B[16] = "V JUMP K M  B ";
const s8 str_V_JUMP_K_L_A[16] = "V JUMP K L  A ";
const s8 str_V_JUMP_K_L_B[16] = "V JUMP K L  B ";
const s8 str_F_JUMP_P_S_A[16] = "F JUMP P S  A ";
const s8 str_F_JUMP_P_S_B[16] = "F JUMP P S  B ";
const s8 str_F_JUMP_P_M_A[16] = "F JUMP P M  A ";
const s8 str_F_JUMP_P_M_B[16] = "F JUMP P M  B ";
const s8 str_F_JUMP_P_L_A[16] = "F JUMP P L  A ";
const s8 str_F_JUMP_P_L_B[16] = "F JUMP P L  B ";
const s8 str_F_JUMP_K_S_A[16] = "F JUMP K S  A ";
const s8 str_F_JUMP_K_S_B[16] = "F JUMP K S  B ";
const s8 str_F_JUMP_K_M_A[16] = "F JUMP K M  A ";
const s8 str_F_JUMP_K_M_B[16] = "F JUMP K M  B ";
const s8 str_F_JUMP_K_L_A[16] = "F JUMP K L  A ";
const s8 str_F_JUMP_K_L_B[16] = "F JUMP K L  B ";
const s8 str_B_JUMP_P_S_A[16] = "B JUMP P S  A ";
const s8 str_B_JUMP_P_S_B[16] = "B JUMP P S  B ";
const s8 str_B_JUMP_P_M_A[16] = "B JUMP P M  A ";
const s8 str_B_JUMP_P_M_B[16] = "B JUMP P M  B ";
const s8 str_B_JUMP_P_L_A[16] = "B JUMP P L  A ";
const s8 str_B_JUMP_P_L_B[16] = "B JUMP P L  B ";
const s8 str_B_JUMP_K_S_A[16] = "B JUMP K S  A ";
const s8 str_B_JUMP_K_S_B[16] = "B JUMP K S  B ";
const s8 str_B_JUMP_K_M_A[16] = "B JUMP K M  A ";
const s8 str_B_JUMP_K_M_B[16] = "B JUMP K M  B ";
const s8 str_B_JUMP_K_L_A[16] = "B JUMP K L  A ";
const s8 str_B_JUMP_K_L_B[16] = "B JUMP K L  B ";
const s8 str_SP_V_JP_S_P_A[16] = "SP V JP S P  A";
const s8 str_SP_V_JP_S_P_B[16] = "SP V JP S P  B";
const s8 str_SP_V_JP_M_P_A[16] = "SP V JP M P  A";
const s8 str_SP_V_JP_M_P_B[16] = "SP V JP M P  B";
const s8 str_SP_V_JP_L_P_A[16] = "SP V JP L P  A";
const s8 str_SP_V_JP_L_P_B[16] = "SP V JP L P  B";
const s8 str_SP_V_JP_S_K_A[16] = "SP V JP S K  A";
const s8 str_SP_V_JP_S_K_B[16] = "SP V JP S K  B";
const s8 str_SP_V_JP_M_K_A[16] = "SP V JP M K  A";
const s8 str_SP_V_JP_M_K_B[16] = "SP V JP M K  B";
const s8 str_SP_V_JP_L_K_A[16] = "SP V JP L K  A";
const s8 str_SP_V_JP_L_K_B[16] = "SP V JP L K  B";
const s8 str_SP_F_JP_S_P_A[16] = "SP F JP S P  A";
const s8 str_SP_F_JP_S_P_B[16] = "SP F JP S P  B";
const s8 str_SP_F_JP_M_P_A[16] = "SP F JP M P  A";
const s8 str_SP_F_JP_M_P_B[16] = "SP F JP M P  B";
const s8 str_SP_F_JP_L_P_A[16] = "SP F JP L P  A";
const s8 str_SP_F_JP_L_P_B[16] = "SP F JP L P  B";
const s8 str_SP_F_JP_S_K_A[16] = "SP F JP S K  A";
const s8 str_SP_F_JP_S_K_B[16] = "SP F JP S K  B";
const s8 str_SP_F_JP_M_K_A[16] = "SP F JP M K  A";
const s8 str_SP_F_JP_M_K_B[16] = "SP F JP M K  B";
const s8 str_SP_F_JP_L_K_A[16] = "SP F JP L K  A";
const s8 str_SP_F_JP_L_K_B[16] = "SP F JP L K  B";
const s8 str_SP_B_JP_S_P_A[16] = "SP B JP S P  A";
const s8 str_SP_B_JP_S_P_B[16] = "SP B JP S P  B";
const s8 str_SP_B_JP_M_P_A[16] = "SP B JP M P  A";
const s8 str_SP_B_JP_M_P_B[16] = "SP B JP M P  B";
const s8 str_SP_B_JP_L_P_A[16] = "SP B JP L P  A";
const s8 str_SP_B_JP_L_P_B[16] = "SP B JP L P  B";
const s8 str_SP_B_JP_S_K_A[16] = "SP B JP S K  A";
const s8 str_SP_B_JP_S_K_B[16] = "SP B JP S K  B";
const s8 str_SP_B_JP_M_K_A[16] = "SP B JP M K  A";
const s8 str_SP_B_JP_M_K_B[16] = "SP B JP M K  B";
const s8 str_SP_B_JP_L_K_A[16] = "SP B JP L K  A";
const s8 str_SP_B_JP_L_K_B[16] = "SP B JP L K  B";
const s8 str_S_V_JP_S_P_A[16] = "S  V JP S P  A";
const s8 str_S_V_JP_S_P_B[16] = "S  V JP S P  B";
const s8 str_S_V_JP_M_P_A[16] = "S  V JP M P  A";
const s8 str_S_V_JP_M_P_B[16] = "S  V JP M P  B";
const s8 str_S_V_JP_L_P_A[16] = "S  V JP L P  A";
const s8 str_S_V_JP_L_P_B[16] = "S  V JP L P  B";
const s8 str_S_V_JP_S_K_A[16] = "S  V JP S K  A";
const s8 str_S_V_JP_S_K_B[16] = "S  V JP S K  B";
const s8 str_S_V_JP_M_K_A[16] = "S  V JP M K  A";
const s8 str_S_V_JP_M_K_B[16] = "S  V JP M K  B";
const s8 str_S_V_JP_L_K_A[16] = "S  V JP L K  A";
const s8 str_S_V_JP_L_K_B[16] = "S  V JP L K  B";
const s8 str_S_F_JP_S_P_A[16] = "S  F JP S P  A";
const s8 str_S_F_JP_S_P_B[16] = "S  F JP S P  B";
const s8 str_S_F_JP_M_P_A[16] = "S  F JP M P  A";
const s8 str_S_F_JP_M_P_B[16] = "S  F JP M P  B";
const s8 str_S_F_JP_L_P_A[16] = "S  F JP L P  A";
const s8 str_S_F_JP_L_P_B[16] = "S  F JP L P  B";
const s8 str_S_F_JP_S_K_A[16] = "S  F JP S K  A";
const s8 str_S_F_JP_S_K_B[16] = "S  F JP S K  B";
const s8 str_S_F_JP_M_K_A[16] = "S  F JP M K  A";
const s8 str_S_F_JP_M_K_B[16] = "S  F JP M K  B";
const s8 str_S_F_JP_L_K_A[16] = "S  F JP L K  A";
const s8 str_S_F_JP_L_K_B[16] = "S  F JP L K  B";
const s8 str_S_B_JP_S_P_A[16] = "S  B JP S P  A";
const s8 str_S_B_JP_S_P_B[16] = "S  B JP S P  B";
const s8 str_S_B_JP_M_P_A[16] = "S  B JP M P  A";
const s8 str_S_B_JP_M_P_B[16] = "S  B JP M P  B";
const s8 str_S_B_JP_L_P_A[16] = "S  B JP L P  A";
const s8 str_S_B_JP_L_P_B[16] = "S  B JP L P  B";
const s8 str_S_B_JP_S_K_A[16] = "S  B JP S K  A";
const s8 str_S_B_JP_S_K_B[16] = "S  B JP S K  B";
const s8 str_S_B_JP_M_K_A[16] = "S  B JP M K  A";
const s8 str_S_B_JP_M_K_B[16] = "S  B JP M K  B";
const s8 str_S_B_JP_L_K_A[16] = "S  B JP L K  A";
const s8 str_S_B_JP_L_K_B[16] = "S  B JP L K  B";
const s8 str_TUKAMIKAKARI_A[16] = "TUKAMIKAKARI A";
const s8 str_TUKAMIKAKARI_B[16] = "TUKAMIKAKARI B";
const s8 str_TUKAMIKAKARI_C[16] = "TUKAMIKAKARI C";
const s8 str_TUKAMIKAKARI_D[16] = "TUKAMIKAKARI D";
const s8 str_TUKAMIKAKARI_E[16] = "TUKAMIKAKARI E";
const s8 str_TUKAMIKAKARI_F[16] = "TUKAMIKAKARI F";
const s8 str_TUKAMI_AIR_A[16] = "TUKAMI  AIR  A";
const s8 str_TUKAMI_AIR_B[16] = "TUKAMI  AIR  B";
const s8 str_TUKAMI_AIR_C[16] = "TUKAMI  AIR  C";
const s8 str_TUKAMI_AIR_D[16] = "TUKAMI  AIR  D";
const s8 str_TUKAMI_AIR_E[16] = "TUKAMI  AIR  E";
const s8 str_TUKAMI_AIR_F[16] = "TUKAMI  AIR  F";
const s8 str_UP_P_GUARD_P_S[16] = "UP P GUARD P S";
const s8 str_UP_P_GUARD_P_M[16] = "UP P GUARD P M";
const s8 str_UP_P_GUARD_P_L[16] = "UP P GUARD P L";
const s8 str_UP_P_GUARD_K_S[16] = "UP P GUARD K S";
const s8 str_UP_P_GUARD_K_M[16] = "UP P GUARD K M";
const s8 str_UP_P_GUARD_K_L[16] = "UP P GUARD K L";
const s8 str_D_P_GUARD_P_S[16] = "D  P GUARD P S";
const s8 str_D_P_GUARD_P_M[16] = "D  P GUARD P M";
const s8 str_D_P_GUARD_P_L[16] = "D  P GUARD P L";
const s8 str_D_P_GUARD_K_S[16] = "D  P GUARD K S";
const s8 str_D_P_GUARD_K_M[16] = "D  P GUARD K M";
const s8 str_D_P_GUARD_K_L[16] = "D  P GUARD K L";
const s8 str_FUSHIN_P_S[16] = "FUSHIN     P S";
const s8 str_FUSHIN_P_M[16] = "FUSHIN     P M";
const s8 str_FUSHIN_P_L[16] = "FUSHIN     P L";
const s8 str_FUSHIN_K_S[16] = "FUSHIN     K S";
const s8 str_FUSHIN_K_M[16] = "FUSHIN     K M";
const s8 str_FUSHIN_K_L[16] = "FUSHIN     K L";
const s8 str_OKIAGARI_P_S[16] = "OKIAGARI   P S";
const s8 str_OKIAGARI_P_M[16] = "OKIAGARI   P M";
const s8 str_OKIAGARI_P_L[16] = "OKIAGARI   P L";
const s8 str_OKIAGARI_K_S[16] = "OKIAGARI   K S";
const s8 str_OKIAGARI_K_M[16] = "OKIAGARI   K M";
const s8 str_OKIAGARI_K_L[16] = "OKIAGARI   K L";
const s8 str_ATTACK_1_S[16] = "ATTACK 1   S  ";
const s8 str_ATTACK_1_M[16] = "ATTACK 1   M  ";
const s8 str_ATTACK_1_L[16] = "ATTACK 1   L  ";
const s8 str_ATTACK_1_SP[16] = "ATTACK 1   SP ";
const s8 str_ATTACK_2_S[16] = "ATTACK 2   S  ";
const s8 str_ATTACK_2_M[16] = "ATTACK 2   M  ";
const s8 str_ATTACK_2_L[16] = "ATTACK 2   L  ";
const s8 str_ATTACK_2_SP[16] = "ATTACK 2   SP ";
const s8 str_ATTACK_3_S[16] = "ATTACK 3   S  ";
const s8 str_ATTACK_3_M[16] = "ATTACK 3   M  ";
const s8 str_ATTACK_3_L[16] = "ATTACK 3   L  ";
const s8 str_ATTACK_3_SP[16] = "ATTACK 3   SP ";
const s8 str_ATTACK_4_S[16] = "ATTACK 4   S  ";
const s8 str_ATTACK_4_M[16] = "ATTACK 4   M  ";
const s8 str_ATTACK_4_L[16] = "ATTACK 4   L  ";
const s8 str_ATTACK_4_SP[16] = "ATTACK 4   SP ";
const s8 str_ATTACK_5_S[16] = "ATTACK 5   S  ";
const s8 str_ATTACK_5_M[16] = "ATTACK 5   M  ";
const s8 str_ATTACK_5_L[16] = "ATTACK 5   L  ";
const s8 str_ATTACK_5_SP[16] = "ATTACK 5   SP ";
const s8 str_ATTACK_6_S[16] = "ATTACK 6   S  ";
const s8 str_ATTACK_6_M[16] = "ATTACK 6   M  ";
const s8 str_ATTACK_6_L[16] = "ATTACK 6   L  ";
const s8 str_ATTACK_6_SP[16] = "ATTACK 6   SP ";
const s8 str_ATTACK_7_S[16] = "ATTACK 7   S  ";
const s8 str_ATTACK_7_M[16] = "ATTACK 7   M  ";
const s8 str_ATTACK_7_L[16] = "ATTACK 7   L  ";
const s8 str_ATTACK_7_SP[16] = "ATTACK 7   SP ";
const s8 str_ATTACK_8_S[16] = "ATTACK 8   S  ";
const s8 str_ATTACK_8_M[16] = "ATTACK 8   M  ";
const s8 str_ATTACK_8_L[16] = "ATTACK 8   L  ";
const s8 str_ATTACK_8_SP[16] = "ATTACK 8   SP ";
const s8 str_ATTACK_9_S[16] = "ATTACK 9   S  ";
const s8 str_ATTACK_9_M[16] = "ATTACK 9   M  ";
const s8 str_ATTACK_9_L[16] = "ATTACK 9   L  ";
const s8 str_ATTACK_9_SP[16] = "ATTACK 9   SP ";
const s8 str_ATTACK_10_S[16] = "ATTACK 10  S  ";
const s8 str_ATTACK_10_M[16] = "ATTACK 10  M  ";
const s8 str_ATTACK_10_L[16] = "ATTACK 10  L  ";
const s8 str_ATTACK_10_SP[16] = "ATTACK 10  SP ";
const s8 str_ATTACK_11_S[16] = "ATTACK 11  S  ";
const s8 str_ATTACK_11_M[16] = "ATTACK 11  M  ";
const s8 str_ATTACK_11_L[16] = "ATTACK 11  L  ";
const s8 str_ATTACK_11_SP[16] = "ATTACK 11  SP ";
const s8 str_ATTACK_12_S[16] = "ATTACK 12  S  ";
const s8 str_ATTACK_12_M[16] = "ATTACK 12  M  ";
const s8 str_ATTACK_12_L[16] = "ATTACK 12  L  ";
const s8 str_ATTACK_12_SP[16] = "ATTACK 12  SP ";
const s8 str_ATTACK_13_S[16] = "ATTACK 13  S  ";
const s8 str_ATTACK_13_M[16] = "ATTACK 13  M  ";
const s8 str_ATTACK_13_L[16] = "ATTACK 13  L  ";
const s8 str_ATTACK_13_SP[16] = "ATTACK 13  SP ";
const s8 str_HANASARE[16] = "HANASARE      ";
const s8 str_EFF01_CHAR[16] = "EFF01 CHAR    ";
const s8 str_EFF13_CHAR[16] = "EFF13 CHAR    ";
const s8 str_BONUS_CHAR[16] = "BONUS CHAR    ";
const s8 str_JUDGEMENT_GAL[16] = "JUDGEMENT GAL ";
const s8 str_EXTRA[16] = "EXTRA         ";
const s8 str_PLEF[16] = "PLEF          ";
const s8 str_SELECT[16] = "SELECT        ";
const s8 str_ETC_1[16] = "ETC 1         ";
const s8 str_ETC_2[16] = "ETC 2         ";
const s8 str_ETC_3[16] = "ETC 3         ";
const s8 str_RUCCIA[16] = "RUCCIA        ";
const s8 str_AFRICA_2[16] = "AFRICA        ";
const s8 str_N_Y[16] = "N.Y           ";
const s8 str_HONGKONG[16] = "HONGKONG      ";
const s8 str_JAPAN2[16] = "JAPAN2        ";
const s8 str_GERMANY_2[16] = "GERMANY       ";
const s8 str_BRAZIL_2[16] = "BRAZIL        ";
const s8 str_ORUMEKA[16] = "ORUMEKA       ";
const s8 str_ENGLAND_2[16] = "ENGLAND       ";
const s8 str_JAPAN_3[16] = "JAPAN 3       ";
const s8 str_GILL_STAGE[16] = "GILL STAGE    ";
const s8 str_JAPAN_11[16] = "JAPAN 11      ";
const s8 str_BONUS[16] = "BONUS         ";
const s8 str_FRANCE_2[16] = "FRANCE        ";
const s8 str_CHAINA_2[16] = "CHAINA        ";
const s8 str_BRAZIL_1_2[16] = "BRAZIL 1      ";
const s8 str_JAPAN_10[16] = "JAPAN 10      ";
const s8 str_ENDING[16] = "ENDING        ";
const s8 str_APPEAR_JUNBI_1[16] = "APPEAR JUNBI 1";
const s8 str_APPEAR_JUNBI_2[16] = "APPEAR JUNBI 2";
const s8 str_APPEAR_JUNBI_3[16] = "APPEAR JUNBI 3";
const s8 str_APPEAR_JUNBI_4[16] = "APPEAR JUNBI 4";
const s8 str_APPEAR_JUNBI_5[16] = "APPEAR JUNBI 5";
const s8 str_APPEAR_JUNBI_6[16] = "APPEAR JUNBI 6";
const s8 str_APPEAR_JUNBI_7[16] = "APPEAR JUNBI 7";
const s8 str_APPEAR_JUNBI_8[16] = "APPEAR JUNBI 8";
const s8 str_APPEAR_1[16] = "APPEAR   1    ";
const s8 str_APPEAR_2[16] = "APPEAR   2    ";
const s8 str_APPEAR_3[16] = "APPEAR   3    ";
const s8 str_APPEAR_4[16] = "APPEAR   4    ";
const s8 str_APPEAR_5[16] = "APPEAR   5    ";
const s8 str_APPEAR_6[16] = "APPEAR   6    ";
const s8 str_APPEAR_7[16] = "APPEAR   7    ";
const s8 str_APPEAR_8[16] = "APPEAR   8    ";
const s8 str_SP_APPEAR_1[16] = "SP  APPEAR  1 ";
const s8 str_SP_APPEAR_2[16] = "SP  APPEAR  2 ";
const s8 str_SP_APPEAR_3[16] = "SP  APPEAR  3 ";
const s8 str_SP_APPEAR_4[16] = "SP  APPEAR  4 ";
const s8 str_SP_APPEAR_5[16] = "SP  APPEAR  5 ";
const s8 str_SP_APPEAR_6[16] = "SP  APPEAR  6 ";
const s8 str_SP_APPEAR_7[16] = "SP  APPEAR  7 ";
const s8 str_SP_APPEAR_8[16] = "SP  APPEAR  8 ";
const s8 str_ZANNEN_1[16] = "ZANNEN  1     ";
const s8 str_ZANNEN_2[16] = "ZANNEN  2     ";
const s8 str_ZANNEN_3[16] = "ZANNEN  3     ";
const s8 str_ZANNEN_4[16] = "ZANNEN  4     ";
const s8 str_ZANNEN_5[16] = "ZANNEN  5     ";
const s8 str_ZANNEN_6[16] = "ZANNEN  6     ";
const s8 str_ZANNEN_7[16] = "ZANNEN  7     ";
const s8 str_ZANNEN_8[16] = "ZANNEN  8     ";
const s8 str_WIN_1[16] = "WIN  1        ";
const s8 str_WIN_2[16] = "WIN  2        ";
const s8 str_WIN_3[16] = "WIN  3        ";
const s8 str_WIN_4[16] = "WIN  4        ";
const s8 str_WIN_5[16] = "WIN  5        ";
const s8 str_WIN_6[16] = "WIN  6        ";
const s8 str_WIN_7[16] = "WIN  7        ";
const s8 str_WIN_8[16] = "WIN  8        ";
const s8 str_SP_WIN_1[16] = "SP WIN  1     ";
const s8 str_SP_WIN_2[16] = "SP WIN  2     ";
const s8 str_SP_WIN_3[16] = "SP WIN  3     ";
const s8 str_SP_WIN_4[16] = "SP WIN  4     ";
const s8 str_SP_WIN_5[16] = "SP WIN  5     ";
const s8 str_SP_WIN_6[16] = "SP WIN  6     ";
const s8 str_SP_WIN_7[16] = "SP WIN  7     ";
const s8 str_SP_WIN_8[16] = "SP WIN  8     ";
const s8 str_JUDGMENT_WAIT[16] = "JUDGMENT WAIT ";
const s8 str_JUDGMENT_WIN[16] = "JUDGMENT WIN  ";
const s8 str_JUDGMENT_LOSE[16] = "JUDGMENT LOSE ";
const s8 str_WAIT[16] = "WAIT          ";
const s8 str_AFRICA_JUMP[16] = "AFRICA  JUMP  ";
const s8 str_AFRICA_LAND[16] = "AFRICA  LAND  ";
const s8 str_SEAN_BALL_HIT[16] = "SEAN BALL HIT ";
const s8 str_BONUS_WIN_1[16] = "BONUS WIN 1   ";
const s8 str_BONUS_WIN_2[16] = "BONUS WIN 2   ";
const s8 str_BONUS_WIN_3[16] = "BONUS WIN 3   ";
const s8 str_APPEAR_USE[16] = "APPEAR USE    ";


/* provisional name */
const char hit_kind_none_str[4] = "__";

/* provisional name */
const char hit_kind_uu_str[4] = "uu";

/* provisional name */
const char hit_kind_ua_str[4] = "ua";

/* provisional name */
const char hit_kind_ud_str[4] = "ud";

/* provisional name */
const char hit_kind_au_str[4] = "au";

/* provisional name */
const char hit_kind_aa_str[4] = "aa";

/* provisional name */
const char hit_kind_ad_str[4] = "ad";

/* provisional name */
const char hit_kind_du_str[4] = "du";

/* provisional name */
const char hit_kind_da_str[4] = "da";

/* provisional name */
const char hit_kind_dd_str[4] = "dd";

const u16 chk22_tbl[8] = {
    1, 9, 8, 10, 2, 6, 4, 5,
};

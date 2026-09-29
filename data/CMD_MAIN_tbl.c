/*
 * CMD_MAIN_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

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

extern void debug_bg_select_dispatch();
extern void debug_bg_select_init();
extern void debug_bg_select_navigate_updown();
extern void debug_object_look_dispatch();
extern void debug_catch_judgment_init();
extern void debug_catch_judgment_run();
extern void debug_char_preview_dispatch();
extern void debug_char_preview_init();
extern void debug_char_preview_run();
extern void debug_hit_a_judgement_init();
extern void debug_hit_a_judgement_run();
extern void debug_hit_judgment_redraw();
extern void debug_hit_a_exit_confirm();
extern void debug_hit_judgment_dispatch();
extern void debug_hit_judgment_init();
extern void debug_hit_judgment_move();
extern void debug_menu_select_init();
extern void debug_menu_select_run();
extern void debug_object_edit_all_char_init();
extern void debug_object_edit_all_char_move();
extern void debug_object_edit_dispatch();
extern void debug_object_edit_init();
extern void debug_object_edit_move();
extern void debug_object_look_init();
extern void debug_object_look_run();
extern void debug_parts_dispatch();
extern void debug_parts_init();
extern void debug_parts_run();
extern void debug_play07();
extern void debug_play08();
extern void debug_play09();
extern void debug_play10();
extern void debug_play11();
extern void debug_play12();
extern void debug_play13();
extern void game_config_1p_round_item_en();
extern void game_config_2p_round_item_en();
extern void game_config_bonus_item_en();
extern void game_config_damage_item_en();
extern void game_config_event_item_en();
extern void game_config_exit_item_en();
extern void game_config_init_en();
extern void game_config_level_item_en();
extern void game_config_timer_item_en();
extern void game_config_move_en();
extern const u8 debug_object_edit_all_char_dispatch[];
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

const TM_STRING config_title_str_tbl[10] = {
    { 3, 1, 2, (void*)gcfg_line_title_en },
    { 5, 4, 2, (void*)gcfg_line_level_en },
    { 0x5, 6, 2, (void*)gcfg_line_damage_en },
    { 0x5, 8, 2, (void*)gcfg_line_timer_en },
    { 0x5, 10, 2, (void*)gcfg_line_1p_round_en },
    { 0x5, 12, 2, (void*)gcfg_line_2p_round_en },
    { 0x5, 14, 2, (void*)gcfg_line_event_en },
    { 0x5, 16, 2, (void*)gcfg_line_bonus_en },
    { 0x5, 18, 2, (void*)gcfg_line_exit_en },
    { 0x9, 25, 2, (void*)gcfg_help_select_en },
};

const SETTINGS_STRING config_help_modify_str_tbl[2] = {
    { 9, 26, 2, (void*)gcfg_help_modify_en },
    { 9, 27, 2, (void*)gcfg_help_shots_en },
};

const SETTINGS_STRING config_help_return_str_tbl[3] = {
    { 9, 25, 2, (void*)gcfg_help_select2_en },
    { 9, 26, 2, (void*)gcfg_help_return_en },
    { 0x9, 27, 2, (void*)gcfg_help_shot1_en },
};

const s16 gcfg_gauge_clr_chr_en[1] = {
    42,
};

const s16 gcfg_gauge_chr_en[8] = {
    49, 50, 51, 52, 53, 54, 55, 56,
};

const SETTING_TBL_T Game_Config_Jmp_Data[5] = {
    { { game_config_init_en, game_config_move_en } },
    { { game_config_level_item_en, game_config_damage_item_en } },
    { { game_config_timer_item_en, game_config_1p_round_item_en } },
    { { game_config_2p_round_item_en, game_config_event_item_en } },
    { { game_config_bonus_item_en, game_config_exit_item_en } },
};

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

const STAGE_TBL_T debug_select_jmp_data[1] = {
    { { debug_menu_select_init, debug_menu_select_run } },
};

const char debug_cursor_msg[4] = "T";

const char debug_space_msg[4] = " ";

/* The initial values of Debug_Tbl (debug_main_dispatch), BG_Tbl (debug_bg_select_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 CMD_MAIN_local_init[16] = {
    (u32)debug_bg_select_dispatch,
    (u32)debug_object_look_dispatch,
    (u32)debug_object_edit_dispatch,
    (u32)debug_object_edit_all_char_dispatch,
    (u32)debug_hit_judgment_dispatch,
    (u32)debug_char_preview_dispatch,
    (u32)debug_parts_dispatch,
    (u32)debug_play07,
    (u32)debug_play08,
    (u32)debug_play09,
    (u32)debug_play10,
    (u32)debug_play11,
    (u32)debug_play12,
    (u32)debug_play13,
    (u32)debug_bg_select_init,
    (u32)debug_bg_select_navigate_updown,
};

const char bg_select_msg[12] = "BG SELECT";

/* The initial values of Look_Tbl (debug_object_look_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Look_Tbl_init[2] = {
    (u32)debug_object_look_init,
    (u32)debug_object_look_run,
};

const char object_look_msg[12] = "OBJECT LOOK";

const ROUTINES2 object_edit_jmp_data[1] = {
    { { debug_object_edit_init, debug_object_edit_move } },
};

const char object_edit_msg[12] = "OBJECT EDIT";

const char no_edit_erase_msg[8] = "       ";

const char no_edit_msg[8] = "NO EDIT";

/* The initial values of All_Tbl (debug_object_edit_all_char_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 All_Tbl_init[2] = {
    (u32)debug_object_edit_all_char_init,
    (u32)debug_object_edit_all_char_move,
};

const char object_edit_all_msg[32] = "OBJECT EDIT  -ALL CHAR VERSION-";

/* The initial values of Hit_Tbl (debug_hit_judgment_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Hit_Tbl_init[6] = {
    (u32)debug_hit_judgment_init,
    (u32)debug_hit_judgment_move,
    (u32)debug_hit_a_judgement_init,
    (u32)debug_hit_a_judgement_run,
    (u32)debug_hit_a_exit_confirm,
    (u32)debug_hit_judgment_redraw,
};

const char hit_judgment_msg[16] = "HIT JUDGMENT";

const char hit_a_judgement_msg[20] = "HIT -A- JUDGEMENT";

const char hit_tbl_label_msg[12] = "HIT TBL:";

const char pattern_label_msg[16] = "PATTERN:  /  ";

const s8 debug_blank6_msg[8] = "      ";

const s8 debug_blank18_msg[20] = "                  ";

const char debug_zero2_msg[4] = "00";

const char grid_empty_row_msg[8] = "---,--";

const char grid_row_frame_msg[8] = "   ,  ";

const char debug_blank3_msg[4] = "   ";

const char grid9_empty_box_msg[8] = "[--]";

const char dbg_hit_row_empty_str[20] = " --,--,M__B__,--";

const char dbg_hit_row_ix_str[8] = "[  ]";

const char dbg_hit_row_blank_str[20] = "   ,  ,      ,  ";

const char dbg_hit_row_mb_str[8] = "M__B__";

const char dbg_space2_str[4] = "  ";

const char dbg_hitbox_row_str[20] = " 000,000, 000,000";

const char dbg_minus_str[4] = "-";

/* The initial values of Catch_Tbl (debug_catch_judgment_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Catch_Tbl_init[2] = {
    (u32)debug_catch_judgment_init,
    (u32)debug_catch_judgment_run,
};

const char dbg_catch_judge_title[16] = "CATCH JUDJEMENT";

const JMP_TBL2 preview_jmp_tbl[1] = {
    { { debug_char_preview_init, debug_char_preview_run } },
};

const char dbg_tikuji_str[8] = "TIKUJI";

const char dbg_ikkatu_str[8] = "IKKATU";

/* The initial values of Parts_Tbl (debug_parts_dispatch) in CMD_MAIN.c,
   where the arcade build placed them. The routine copies its table from the compiler's
   own image, so nothing reads this one; it keeps the tables after it at their addresses. */
const u32 Parts_Tbl_init[2] = {
    (u32)debug_parts_init,
    (u32)debug_parts_run,
};

const char dbg_parts_title[8] = "PARTS";

const char dbg_slot_1p_s1_str[12] = "1P S1 UJA ";

const char dbg_slot_1p_s2_str[12] = "   S2 UJA2";

const char dbg_slot_1p_s3_str[12] = "   S3 UJA3";

const char dbg_slot_1p_s4_str[12] = "   S4 UJA4";

const char dbg_slot_s5_str[12] = "   S5  -  ";

const char dbg_slot_s6_str[12] = "   S6  -  ";

const char dbg_slot_2p_s1_str[12] = "2P S1 ROA ";

const char dbg_slot_2p_s2_str[12] = "   S2 WCA ";

const char dbg_slot_2p_s3_str[12] = "   S3 UMJA";

const char dbg_slot_2p_s4_str[12] = "   S4  -  ";

const char dbg_space10_str[12] = "          ";

const char dbg_no_wca_str[8] = "NO WCA ";

const char dbg_no_cmja_str[8] = "NO CMJA";

const u16 dbg_pl_color_tbl[24] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0, 0, 0,
};

const char dbg_bcp_str[8] = "BCP  ";

const char dbg_bce_str[8] = "BCE  ";

const char dbg_bcb_str[8] = "BCB  ";

const char dbg_plus_str[4] = "+";

const char dbg_flip_no_str[4] = "NO";

const char dbg_flip_h_str[4] = "H ";

const char dbg_flip_v_str[4] = "V ";

const char dbg_flip_hv_str[4] = "HV";

const char dbg_flag_on_str[4] = "[1]";

const char dbg_flag_off_str[4] = "[0]";

const char dbg_kakusyuku_off_str[16] = "KAKUSYUKU  OFF";

const char dbg_frame_off_str[16] = "FRAME      OFF";

const char dbg_frame_on_str[16] = "FRAME      ON ";

const char dbg_kakusyuku_on_str[16] = "KAKUSYUKU  ON ";

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

const char dbg_wca_str[44] = {
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
    5, 42, 6, 6, 9, -26784, 1, -26784,
    1, -8992, 1, -26912, 1, -26912, 1, -26912,
    1, -26912, 1, -26912, 1, -26912, 1, -26912,
    1, -26912, 1, -26912, 1, -25176, 1, -28672,
    1, -28576, 1, -28672, 1, -28672, 1, -28672,
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
    8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xE,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
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
    { 16, 26, 16, 16, (void*)hit_kind_none_str },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 17, 0, 20, 17, (void*)hit_kind_uu_str },
    { 18, 16, 21, 18, (void*)hit_kind_ua_str },
    { 20, 17, 22, 16, (void*)hit_kind_ud_str },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 21, 18, 24, 21, (void*)hit_kind_au_str },
    { 22, 20, 25, 22, (void*)hit_kind_aa_str },
    { 24, 21, 26, 20, (void*)hit_kind_ad_str },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 25, 22, 16, 25, (void*)hit_kind_du_str },
    { 26, 24, 17, 26, (void*)hit_kind_da_str },
    { 0, 25, 18, 24, (void*)hit_kind_dd_str },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
    { 0, 0, 0, 0, (void*)str_empty_8 },
};

/* the debug screens' text: menu lines, move and object names */
const char str_OBJECT_TEST[16] = "OBJECT TEST\n";
const char str_BG_SELECT[16] = "BG SELECT  \n";
const char str_OBJECT_LOOK[16] = "OBJECT LOOK\n";
const char str_OBJECT_EDIT[16] = "OBJECT EDIT\n";
const char str_OBJECT_EDIT_2[16] = "OBJECT EDIT 2\n";
const char str_HIT[8] = "HIT\n";
const char str_ALL_CHARACTER[16] = "ALL CHARACTER\n";
const char str_PARTS[8] = "PARTS\n";
const char str_YOKOYAMA[12] = "YOKOYAMA\n";
const char str_NAKAI[8] = "NAKAI\n";
const char str_YOSHIZUMI[12] = "YOSHIZUMI\n";
const char str_YU[4] = "YU\n";
const char str_RAOH[8] = "RAOH\n";
const char str_INE[8] = "INE\n";
const char str_OHYA[8] = "OHYA";
const char str_SELECT_UP_DOWN[20] = "SELECT  UP DOWN\n";
const char str_EXIT_1P_2P_START[24] = "EXIT    1P & 2P START";
const char str_PLAYER[12] = "PLAYER  :\n";
const char str_ALL[16] = "ALL     :   /\n";
const char str_MOTION[16] = "MOTION  :   /\n";
const char str_PATTERN[16] = "PATTERN :   /\n";
const char str_INTERRUT[16] = "INTERRUT:   /\n";
const char str_CODE_H[20] = "CODE    :     H\n";
const char str_FLIP[12] = "FLIP    :\n";
const char str_FLIP_ED[12] = "FLIP ED :\n";
const char str_POS_X_H[20] = "POS X   :     H\n";
const char str_POS_Y_H[16] = "POS Y   :     H";
const char str_REL_X_H[20] = "REL X   :     H\n";
const char str_REL_Y_H[20] = "REL Y   :     H\n";
const char str_CURRENT[12] = "CURRENT :";
const char str_H_n[16] = "             H\n";
const char str_GROUP[16] = "GROUP         \n";
const char str_R_n[16] = "R             \n";
const char str_G[16] = "G             \n";
const char str_B[20] = "B               ";
const char str_EDIT_NUM[12] = "EDIT NUM:\n";
const char str_NUM_END[12] = " NUM END:\n";
const char str_EDIT_INT[12] = "EDIT INT:\n";
const char str_INT_END[12] = " INT END:";
const char str_CURRENT_n[12] = "CURRENT :\n";
const char str_PARTS_X_H[20] = "PARTS X :     H\n";
const char str_PARTS_Y_H[20] = "PARTS Y :     H\n";
const char str_PARTS_FL[12] = "PARTS FL:\n";
const char str_OLC_IX[12] = "OLC IX  :\n";
const char str_IX_1[12] = "    IX 1:\n";
const char str_IX_2[12] = "    IX 2:\n";
const char str_IX_3[12] = "    IX 3:\n";
const char str_IX_4[12] = "    IX 4:";
const char str_DELETE_ALL_SH4[20] = "DELETE ALL    SH4\n";
const char str_1DATA_SH5[20] = "       1DATA  SH5\n";
const char str_CANCEL_SH6[20] = "       CANCEL SH6";
const char str_n[20] = "                  \n";
const char str_empty[20] = "                  ";
const char str_NO_EDIT[24] = "NO EDIT             \n";
const char str_DATA_NOTHING[24] = "   DATA  NOTHING    ";
const char str_REVISE_X_H[20] = "REVISE X:     H\n";
const char str_SIZE_X_H[20] = "SIZE   X:     H\n";
const char str_REVISE_Y_H[20] = "REVISE Y:     H\n";
const char str_SIZE_Y_H[20] = "SIZE   Y:     H\n";
const char str_IX_000[20] = "IX 000         \n";
const char str_CR_1P[20] = "CR  1P         \n";
const char str_MF[20] = "MF             \n";
const char str_M_B[20] = "M__B__         \n";
const char str_BOD_000[12] = "BOD 000\n";
const char str_BHA_000[12] = "BHA 000\n";
const char str_HAN_000[12] = "HAN 000\n";
const char str_CAT_000[12] = "CAT 000\n";
const char str_CAU_000[12] = "CAU 000\n";
const char str_ATT_000[12] = "ATT 000\n";
const char str_HOS_000[8] = "HOS 000";
const char str_KOC_IX_PT_Nix_n[32] = "        KOC     IX      PT Nix\n";
const char str_KOC_IX_PT_Nix[32] = "        KOC     IX      PT Nix";
const char str_HEAD[8] = "HEAD  \n";
const char str_BREAST[8] = "BREAST\n";
const char str_TRUNK[8] = "TRUNK \n";
const char str_LEG[8] = "LEG   \n";
const char str_HAND[8] = "HAND  \n";
const char str_CATCH_n[8] = "CATCH \n";
const char str_CAUGHT_n[8] = "CAUGHT\n";
const char str_ATT[8] = "ATT+  \n";
const char str_ATT_2[8] = "ATT-  \n";
const char str_HOSEI[8] = "HOSEI ";
const char str_WORK_EMPTY[16] = "WORK EMPTY !!\n";
const char str_PRESS_ANY_SHOT[16] = "PRESS ANY SHOT";
const char str_n_2[20] = "                 \n";
const char str_empty_2[20] = "                 ";
const char str_EXIT_OK[16] = " EXIT OK ? \n";
const char str_YES_2P_SHOT6[20] = " YES : 2P-SHOT6 \n";
const char str_NO_1P_SHOT6[20] = " NO  : 1P-SHOT6 ";
const char str_CG_CTR[24] = "CG CTR        (    )\n";
const char str_CG_TYPE[12] = "CG TYPE  \n";
const char str_CG_SE[24] = "CG SE         (    )\n";
const char str_CG_FLIP[24] = "CG FLIP       (    )\n";
const char str_CG_OLC_IX[24] = "CG OLC IX     (    )\n";
const char str_CG_NUMBER[12] = "CG NUMBER";
const char str_CG_ATT_IX[24] = "CG ATT IX     (    )\n";
const char str_CG_HIT_IX[24] = "CG HIT IX     (    )\n";
const char str_CG_EXTDAT[12] = "CG EXTDAT\n";
const char str_CG_CANCEL[12] = "CG CANCEL\n";
const char str_CG_EFFECT[12] = "CG EFFECT\n";
const char str_CG_EFTYPE[12] = "CG EFTYPE  ";
const char str_CG_RIVAL[24] = "CG RIVAL      (    )\n";
const char str_CG_ADD_XY[24] = "CG ADD XY     (    )\n";
const char str_CG_NIX[8] = "CG NIX\n";
const char str_CG_STATUS[12] = "CG STATUS";
const char str_CGD_TYPE[12] = "CGD TYPE \n";
const char str_PAT_ST[12] = "PAT ST   \n";
const char str_KIND_WAZA[12] = "KIND WAZA\n";
const char str_HIT_RANGE[12] = "HIT RANGE\n";
const char str_YOKE_TYPE[12] = "YOKE TYPE\n";
const char str_YOKE_PAT[12] = "YOKE PAT \n";
const char str_SP_TECH[12] = "SP TECH\n";
const char str_WCA_IX[8] = "WCA IX";
const char str_ATT_IX[8] = "ATT IX\n";
const char str_REACTION[24] = "REACTION      (    )\n";
const char str_MKH_IX[24] = "MKH IX        (    )\n";
const char str_DIP[24] = "DIP           (    )\n";
const char str_HISS[24] = "HISS          (    )\n";
const char str_DIR[24] = "DIR           (    )\n";
const char str_GUARD[24] = "GUARD         (    )\n";
const char str_POW[24] = "POW           (    )\n";
const char str_IMPACT[24] = "IMPACT        (    )\n";
const char str_PIYO_n[24] = "PIYO          (    )\n";
const char str_NG_TYPE[24] = "NG TYPE       (    )\n";
const char str_HS_ME[24] = "HS ME         (    )\n";
const char str_HS_YOU[24] = "HS YOU        (    )\n";
const char str_ZU_FLAG[24] = "ZU FLAG       (    )\n";
const char str_ZOKUSEI[24] = "ZOKUSEI       (    )\n";
const char str_AT_LEVEL[24] = "AT LEVEL      (    )\n";
const char str_ADD_ARTS[24] = "ADD ARTS      (    )\n";
const char str_BUTT_TYPE[24] = "BUTT TYPE     (    )\n";
const char str_BUTT_PAT[24] = "BUTT PAT      (    )\n";
const char str_DIR_ATT[24] = "DIR ATT       (    )\n";
const char str_VS_ID[24] = "VS ID         (    )";
const char str_n_3[32] = "                            \n";
const char str_empty_3[32] = "                            ";
const char str_n_4[40] = "                                     \n";
const char str_empty_4[40] = "                                     ";
const char str_CMOA[8] = "CMOA\n";
const char str_CMSW[8] = "CMSW\n";
const char str_CMLP[8] = "CMLP\n";
const char str_CML2[8] = "CML2\n";
const char str_CMJA[8] = "CMJA\n";
const char str_CMJ2[8] = "CMJ2\n";
const char str_CMJ3[8] = "CMJ3\n";
const char str_CMJ4[8] = "CMJ4\n";
const char str_CMMS[8] = "CMMS\n";
const char str_CMMD[8] = "CMMD\n";
const char str_CMYD[8] = "CMYD\n";
const char str_CMCF[8] = "CMCF\n";
const char str_CMCR[8] = "CMCR";
const char str_WCA[8] = "WCA ";
const char str_CGD1[8] = "CGD1";
const char str_CGD2[8] = "CGD2";
const char str_CGD3[8] = "CGD3";
const char str_empty_5[8] = "    ";
const char str_sl_00[8] = "sl_00";
const char str_sl_10[8] = "sl_10";
const char str_sl_12[8] = "sl_12";
const char str_sl_20[8] = "sl_20";
const char str_sl_22[8] = "sl_22";
const char str_sl_30[8] = "sl_30";
const char str_sl_32[8] = "sl_32";
const char str_sl_40[8] = "sl_40";
const char str_sl_42[8] = "sl_42";
const char str_sl_44[8] = "sl_44";
const char str_sl_50[8] = "sl_50";
const char str_sl_52[8] = "sl_52";
const char str_sl_54[8] = "sl_54";
const char str_sl_60[8] = "sl_60";
const char str_sl_62[8] = "sl_62";
const char str_sl_64[8] = "sl_64";
const char str_sl_70[8] = "sl_70";
const char str_sl_80[8] = "sl_80";
const char str_sl_82[8] = "sl_82";
const char str_sl_90[8] = "sl_90";
const char str_empty_6[8] = "     ";
const char str_Pa[4] = "Pa";
const char str_PA[4] = "PA";
const char str_PB[4] = "PB";
const char str_MLN[4] = "MLN";
const char str_MLU[4] = "MLU";
const char str_MLD[4] = "MLD";
const char str_MLF[4] = "MLF";
const char str_MLR[4] = "MLR";
const char str_M[4] = "M__";
const char str_S1[4] = "S1";
const char str_S2[4] = "S2";
const char str_S3[4] = "S3";
const char str_S4[4] = "S4";
const char str_S5[4] = "S5";
const char str_S6[4] = "S6";
const char str_empty_7[8] = "      ";
const char str_USEMJ[8] = "+USEMJ";
const char str_BASE[8] = "BASE  ";
const char str_BEFORE[8] = "BEFORE";
const char str_BACK[8] = "BACK  ";
const char str_H[4] = "H";
const char str_D[4] = "D";
const char str_A[4] = "A";
const char str_M_2[4] = "M";
const char str_R[4] = "R";
const char str_C[4] = "C";
const char str_S[4] = "S";
const char str_h[4] = "h";
const char str_d[4] = "d";
const char str_a[4] = "a";
const char str_m[4] = "m";
const char str_r[4] = "r";
const char str_c[4] = "c";
const char str_s[4] = "s";
const char str_h_2[4] = "h ";
const char str_d_2[4] = "d ";
const char str_a_2[4] = "a ";
const char str_m_2[4] = "m ";
const char str_r_2[4] = "r ";
const char str_c_2[4] = "c ";
const char str_s_2[4] = "s ";
const char str_NM[4] = "NM";
const char str_DM[4] = "DM";
const char str_CA[4] = "CA";
const char str_CU[4] = "CU";
const char str_AT[4] = "AT";
const char str_BT[4] = "BT";
const char str_EX[4] = "EX";
const char str_SA[4] = "SA";
const char str_CB[4] = "CB";
const char str_empty_8[4] = "  ";
const char str_nmA[4] = "nmA";
const char str_hsA[4] = "hsA";
const char str_nmC[4] = "nmC";
const char str_hsC[4] = "hsC";
const char str_saA[4] = "saA";
const char str_saC[4] = "saC";
const char str_paA[4] = "paA";
const char str_huA[4] = "huA";
const char str_BLANK[16] = "BLANK        ";
const char str_FLASH[16] = "FLASH        ";
const char str_GILL[16] = "GILL         ";
const char str_N_Y_0[16] = "N.Y 0        ";
const char str_JAPAN_0[16] = "JAPAN 0      ";
const char str_HONGKONG_0[16] = "HONGKONG 0   ";
const char str_ENGLAND[16] = "ENGLAND      ";
const char str_RUSSIA_0[16] = "RUSSIA 0     ";
const char str_GERMANY[16] = "GERMANY      ";
const char str_JAPAN_1[16] = "JAPAN 1      ";
const char str_AFRICA[16] = "AFRICA       ";
const char str_BRAZIL[16] = "BRAZIL       ";
const char str_HONGKONG_1[16] = "HONGKONG 1   ";
const char str_N_Y_1[16] = "N.Y 1        ";
const char str_BRAZIL_1[16] = "BRAZIL 1     ";
const char str_OROMEKA[16] = "OROMEKA      ";
const char str_JAPAN_20[16] = "JAPAN 20     ";
const char str_JAPAN_21[16] = "JAPAN 21     ";
const char str_CHAINA[16] = "CHAINA       ";
const char str_JAPAN_30[16] = "JAPAN 30     ";
const char str_RUSSIA_1[16] = "RUSSIA 1     ";
const char str_RUSSIA_2[16] = "RUSSIA 2     ";
const char str_FRANCE[16] = "FRANCE       ";
const char str_BONUS_1[16] = "BONUS 1      ";
const char str_BONUS_2[16] = "BONUS 2      ";
const char str_GILL_2[8] = "GILL   ";
const char str_ALEX[8] = "ALEX   ";
const char str_RYU[8] = "RYU    ";
const char str_YUN[8] = "YUN    ";
const char str_DUDLEY[8] = "DUDLEY ";
const char str_NECRO[8] = "NECRO  ";
const char str_HUGO[8] = "HUGO   ";
const char str_IBUKI[8] = "IBUKI  ";
const char str_ELENA[8] = "ELENA  ";
const char str_ORO[8] = "ORO    ";
const char str_YANG[8] = "YANG   ";
const char str_KEN[8] = "KEN    ";
const char str_SEAN[8] = "SEAN   ";
const char str_URIEN[8] = "URIEN  ";
const char str_GOUKI_1[8] = "GOUKI 1";
const char str_GOUKI_2[8] = "GOUKI 2";
const char str_CHUN_LI[8] = "CHUN-LI";
const char str_KARATE[8] = "KARATE ";
const char str_Q[8] = "Q      ";
const char str_No_12[8] = "No.12  ";
const char str_BIKEI[8] = "BIKEI  ";
const char str_empty_9[8] = "       ";
const char str_ETC[8] = "ETC    ";
const char str_NORMAL[8] = "NORMAL ";
const char str_DAMAGE[8] = "DAMAGE ";
const char str_CATCH[8] = "CATCH  ";
const char str_CAUGHT[8] = "CAUGHT ";
const char str_ATTACK[8] = "ATTACK ";
const char str_SP_AT[8] = "SP AT  ";
const char str_BUTTOBI[8] = "BUTTOBI";
const char str_UNION[8] = "UNION  ";
const char str_EFFECT[8] = "EFFECT ";
const char str_KAMAE[16] = "KAMAE         ";
const char str_HURIMUKI[16] = "HURIMUKI      ";
const char str_FRONT_WALK[16] = "FRONT WALK    ";
const char str_BACK_WALK[16] = "BACK  WALK    ";
const char str_DASH_HUMIKOMI[16] = "DASH  HUMIKOMI";
const char str_DASH_TOBINOKI[16] = "DASH  TOBINOKI";
const char str_KAGAMU[16] = "KAGAMU        ";
const char str_KAGAMI_KAMAE[16] = "KAGAMI KAMAE  ";
const char str_KAGAMI_TURN[16] = "KAGAMI TURN   ";
const char str_KAGAMI_F_WALK[16] = "KAGAMI F WALK ";
const char str_KAGAMI_B_WALK[16] = "KAGAMI B WALK ";
const char str_STAND_UP[16] = "STAND UP      ";
const char str_JUMP_JUNBI[16] = "JUMP     JUNBI";
const char str_SP_JUMP_JUNBI[16] = "SP JUMP  JUNBI";
const char str_JUMP_FRONT[16] = "JUMP FRONT    ";
const char str_JUMP_VERTICAL[16] = "JUMP VERTICAL ";
const char str_JUMP_BACK[16] = "JUMP BACK     ";
const char str_S_JUMP_FRONT[16] = "S JUMP FRONT  ";
const char str_S_JUMP_V[16] = "S JUMP V      ";
const char str_S_JUMP_BACK[16] = "S JUMP BACK   ";
const char str_SP_JUMP_FRONT[16] = "SP JUMP FRONT ";
const char str_SP_JUMP_V[16] = "SP JUMP V     ";
const char str_SP_JUMP_BACK[16] = "SP JUMP BACK  ";
const char str_WALK_END[16] = "WALK END      ";
const char str_PARING_HEAD[16] = "PARING  HEAD  ";
const char str_PARING_UP[16] = "PARING  UP    ";
const char str_PARING_DOWN[16] = "PARING  DOWN  ";
const char str_PARING_AIR_F[16] = "PARING  AIR F ";
const char str_PARING_AIR_B[16] = "PARING  AIR B ";
const char str_GUARD_HEAD[16] = "GUARD  HEAD   ";
const char str_GUARD_UP[16] = "GUARD  UP     ";
const char str_GUARD_DOWN[16] = "GUARD  DOWN   ";
const char str_GUARD_AIR[16] = "GUARD  AIR    ";
const char str_empty_10[16] = "              ";
const char str_P_BREAK_ZUJOU[16] = "P BREAK  ZUJOU";
const char str_P_BREAK_UP[16] = "P BREAK  UP   ";
const char str_P_BREAK_DOWN[16] = "P BREAK  DOWN ";
const char str_P_BREAK_AIR_F[16] = "P BREAK  AIR F";
const char str_P_BREAK_AIR_R[16] = "P BREAK  AIR R";
const char str_TUKAMIHAZUSI[16] = "TUKAMIHAZUSI  ";
const char str_TUKAMIHAZUSARE[16] = "TUKAMIHAZUSARE";
const char str_GUARD_HEAD_2[16] = "GUARD HEAD    ";
const char str_GUARD_UP_2[16] = "GUARD UP      ";
const char str_GUARD_DOWN_2[16] = "GUARD DOWN    ";
const char str_GUARD_AIR_2[16] = "GUARD AIR     ";
const char str_HUSHIN_HEAD[16] = "HUSHIN  HEAD  ";
const char str_HUSHIN_UP[16] = "HUSHIN  UP    ";
const char str_HUSHIN_DOWN[16] = "HUSHIN  DOWN  ";
const char str_HUSHIN_AIR[16] = "HUSHIN  AIR   ";
const char str_FACE_S[16] = "FACE  S       ";
const char str_FACE_M[16] = "FACE  M       ";
const char str_FACE_L[16] = "FACE  L       ";
const char str_FACE_SP[16] = "FACE  SP      ";
const char str_FOOK_OKU_S[16] = "FOOK OKU  S   ";
const char str_FOOK_OKU_M[16] = "FOOK OKU  M   ";
const char str_FOOK_OKU_L[16] = "FOOK OKU  L   ";
const char str_FOOK_OKU_SP[16] = "FOOK OKU  SP  ";
const char str_FOOK_TEMAE_S[16] = "FOOK TEMAE  S ";
const char str_FOOK_TEMAE_M[16] = "FOOK TEMAE  M ";
const char str_FOOK_TEMAE_L[16] = "FOOK TEMAE  L ";
const char str_FOOK_TEMAE_SP[16] = "FOOK TEMAE  SP";
const char str_UPPER_S[16] = "UPPER  S      ";
const char str_UPPER_M[16] = "UPPER  M      ";
const char str_UPPER_L[16] = "UPPER  L      ";
const char str_UPPER_SP[16] = "UPPER  SP     ";
const char str_NOUTEN_S[16] = "NOUTEN  S     ";
const char str_NOUTEN_M[16] = "NOUTEN  M     ";
const char str_NOUTEN_L[16] = "NOUTEN  L     ";
const char str_NOUTEN_SP[16] = "NOUTEN  SP    ";
const char str_BODY_BROW_S[16] = "BODY BROW   S ";
const char str_BODY_BROW_M[16] = "BODY BROW   M ";
const char str_BODY_BROW_L[16] = "BODY BROW   L ";
const char str_BODY_BROW_SP[16] = "BODY BROW   SP";
const char str_BODY_UPPER_S[16] = "BODY UPPER  S ";
const char str_BODY_UPPER_M[16] = "BODY UPPER  M ";
const char str_BODY_UPPER_L[16] = "BODY UPPER  L ";
const char str_BODY_UPPER_SP[16] = "BODY UPPER  SP";
const char str_TATAKI_S[16] = "TATAKI  S     ";
const char str_TATAKI_M[16] = "TATAKI  M     ";
const char str_TATAKI_L[16] = "TATAKI  L     ";
const char str_TATAKI_SP[16] = "TATAKI  SP    ";
const char str_TATAKI_V_S[16] = "TATAKI V. S   ";
const char str_TATAKI_V_M[16] = "TATAKI V. M   ";
const char str_TATAKI_V_L[16] = "TATAKI V. L   ";
const char str_TATAKI_V_SP[16] = "TATAKI V. SP  ";
const char str_NOBASITA_TE_S[16] = "NOBASITA TE  S";
const char str_NOBASITA_TE_M[16] = "NOBASITA TE  M";
const char str_NOBASITA_TE_L[16] = "NOBASITA TE  L";
const char str_NOBASITA_TE_SP[16] = "NOBASITA TE SP";
const char str_KAGAMI_S[16] = "KAGAMI  S     ";
const char str_KAGAMI_M[16] = "KAGAMI  M     ";
const char str_KAGAMI_L[16] = "KAGAMI  L     ";
const char str_KAGAMI_SP[16] = "KAGAMI  SP    ";
const char str_KGM_TATAKI_S[16] = "KGM TATAKI S  ";
const char str_KGM_TATAKI_M[16] = "KGM TATAKI M  ";
const char str_KGM_TATAKI_L[16] = "KGM TATAKI L  ";
const char str_KGM_TATAKI_SP[16] = "KGM TATAKI SP ";
const char str_KGM_TTKI_V_S[16] = "KGM TTKI V.S  ";
const char str_KGM_TTKI_V_M[16] = "KGM TTKI V.M  ";
const char str_KGM_TTKI_V_L[16] = "KGM TTKI V.L  ";
const char str_KGM_TTKI_V_SP[16] = "KGM TTKI V.SP ";
const char str_NEKOROBI_S[16] = "NEKOROBI  S   ";
const char str_NEKOROBI_M[16] = "NEKOROBI  M   ";
const char str_NEKOROBI_L[16] = "NEKOROBI  L   ";
const char str_NEKOROBI_SP[16] = "NEKOROBI  SP  ";
const char str_OKIAGARI[16] = "OKIAGARI      ";
const char str_OKIAGARI_F[16] = "OKIAGARI  F   ";
const char str_OKIAGARI_B[16] = "OKIAGARI  B   ";
const char str_LOSE_NO_STAND[16] = "LOSE  NO STAND";
const char str_LOSE_SONABA[16] = "LOSE  SONABA  ";
const char str_LOSE_KAGAMI[16] = "LOSE  KAGAMI  ";
const char str_PIYO[16] = "PIYO          ";
const char str_UKEMI_MOVE_F[16] = "UKEMI MOVE F  ";
const char str_UKEMI_MOVE_R[16] = "UKEMI MOVE R  ";
const char str_SHIMEOTASARE[16] = "SHIMEOTASARE  ";
const char str_TATI_TOUKETU_S[16] = "TATI TOUKETU S";
const char str_TATI_TOUKETU_M[16] = "TATI TOUKETU M";
const char str_TATI_TOUKETU_L[16] = "TATI TOUKETU L";
const char str_TATI_TOUKETU_P[16] = "TATI TOUKETU P";
const char str_KGM_TOUKETU_S[16] = "KGM  TOUKETU S";
const char str_KGM_TOUKETU_M[16] = "KGM  TOUKETU M";
const char str_KGM_TOUKETU_L[16] = "KGM  TOUKETU L";
const char str_KGM_TOUKETU_P[16] = "KGM  TOUKETU P";
const char str_TATI_DENGEKI_S[16] = "TATI DENGEKI S";
const char str_TATI_DENGEKI_M[16] = "TATI DENGEKI M";
const char str_TATI_DENGEKI_L[16] = "TATI DENGEKI L";
const char str_TATI_DENGEKI_P[16] = "TATI DENGEKI P";
const char str_KGM_DENGEKI_S[16] = "KGM  DENGEKI S";
const char str_KGM_DENGEKI_M[16] = "KGM  DENGEKI M";
const char str_KGM_DENGEKI_L[16] = "KGM  DENGEKI L";
const char str_KGM_DENGEKI_P[16] = "KGM  DENGEKI P";
const char str_OKIAGARI_FRONT[16] = "OKIAGARI FRONT";
const char str_OKIAGARI_REAR[16] = "OKIAGARI REAR ";
const char str_TATI_MOE_S[16] = "TATI MOE  S   ";
const char str_TATI_MOE_M[16] = "TATI MOE  M   ";
const char str_TATI_MOE_L[16] = "TATI MOE  L   ";
const char str_TATI_MOE_SP[16] = "TATI MOE  SP  ";
const char str_AIR_NORMAL[16] = "AIR  NORMAL   ";
const char str_ASIBARAI_SIRI[16] = "ASIBARAI SIRI ";
const char str_ASIB_TUNNOMERI[16] = "ASIB TUNNOMERI";
const char str_NOKEZORI[16] = "NOKEZORI      ";
const char str_KUNOJI[16] = "KUNOJI        ";
const char str_KIRIMOMI[16] = "KIRIMOMI      ";
const char str_UPPER[16] = "UPPER         ";
const char str_BODY_UPPER[16] = "BODY UPPER    ";
const char str_HARAYARARE[16] = "HARAYARARE    ";
const char str_TATAKI_AIR[16] = "TATAKI  AIR   ";
const char str_TTKI_V_AIR[16] = "TTKI V. AIR   ";
const char str_HUMI_ASIB[16] = "HUMI ASIB     ";
const char str_FACE[16] = "FACE          ";
const char str_ASIB_SIRI_LOSE[16] = "ASIB SIRI LOSE";
const char str_ASIB_TUN_LOSE[16] = "ASIB TUN  LOSE";
const char str_DENKI[16] = "DENKI         ";
const char str_KUNOJI_NOKE[16] = "KUNOJI NOKE   ";
const char str_BODY_UPPER_SP_2[16] = "BODY UPPER SP ";
const char str_HANEAGARI[16] = "HANEAGARI     ";
const char str_TOUKETSU_A[16] = "TOUKETSU  A   ";
const char str_BODY_SLAM[16] = "BODY SLAM     ";
const char str_IPPONZEOI[16] = "IPPONZEOI     ";
const char str_TOMOE_RYU[16] = "TOMOE  RYU    ";
const char str_MONKEY_FLIP[16] = "MONKEY FLIP   ";
const char str_TOMOE_ORO[16] = "TOMOE ORO     ";
const char str_SNAKE_FANG[16] = "SNAKE FANG    ";
const char str_FLANKEN_S[16] = "FLANKEN.S     ";
const char str_KISHINRIKI[16] = "KISHINRIKI    ";
const char str_SPLASH_M[16] = "SPLASH.M      ";
const char str_HARAIGOSHI[16] = "HARAIGOSHI    ";
const char str_ALEX_B_D[16] = "ALEX B.D      ";
const char str_GILL_3[16] = "GILL          ";
const char str_HANEKAERI_HARA[16] = "HANEKAERI HARA";
const char str_S_HANEAGARI[16] = "S HANEAGARI   ";
const char str_TATUMAKIZANKU[16] = "TATUMAKIZANKU ";
const char str_CATCH_1[16] = "CATCH  1      ";
const char str_CATCH_2[16] = "CATCH  2      ";
const char str_CATCH_3[16] = "CATCH  3      ";
const char str_CATCH_4[16] = "CATCH  4      ";
const char str_CATCH_5[16] = "CATCH  5      ";
const char str_CATCH_6[16] = "CATCH  6      ";
const char str_CATCH_7[16] = "CATCH  7      ";
const char str_CATCH_8[16] = "CATCH  8      ";
const char str_CATCH_9[16] = "CATCH  9      ";
const char str_CATCH_10[16] = "CATCH  10     ";
const char str_CATCH_11[16] = "CATCH  11     ";
const char str_CATCH_12[16] = "CATCH  12     ";
const char str_CATCH_13[16] = "CATCH  13     ";
const char str_CATCH_14[16] = "CATCH  14     ";
const char str_CATCH_15[16] = "CATCH  15     ";
const char str_CATCH_16[16] = "CATCH  16     ";
const char str_CATCH_17[16] = "CATCH  17     ";
const char str_CATCH_18[16] = "CATCH  18     ";
const char str_CATCH_19[16] = "CATCH  19     ";
const char str_CATCH_20[16] = "CATCH  20     ";
const char str_CATCH_21[16] = "CATCH  21     ";
const char str_CATCH_22[16] = "CATCH  22     ";
const char str_CATCH_23[16] = "CATCH  23     ";
const char str_CATCH_24[16] = "CATCH  24     ";
const char str_CATCH_25[16] = "CATCH  25     ";
const char str_CATCH_26[16] = "CATCH  26     ";
const char str_CATCH_27[16] = "CATCH  27     ";
const char str_CATCH_28[16] = "CATCH  28     ";
const char str_CATCH_29[16] = "CATCH  29     ";
const char str_CATCH_30[16] = "CATCH  30     ";
const char str_CATCH_31[16] = "CATCH  31     ";
const char str_CATCH_32[16] = "CATCH  32     ";
const char str_CATCH_33[16] = "CATCH  33     ";
const char str_CATCH_34[16] = "CATCH  34     ";
const char str_CATCH_35[16] = "CATCH  35     ";
const char str_CATCH_36[16] = "CATCH  36     ";
const char str_CATCH_37[16] = "CATCH  37     ";
const char str_CATCH_38[16] = "CATCH  38     ";
const char str_CATCH_39[16] = "CATCH  39     ";
const char str_CATCH_40[16] = "CATCH  40     ";
const char str_ALEX_ZUTUKI[16] = "ALEX ZUTUKI   ";
const char str_ALEX_BODY_S[16] = "ALEX BODY S   ";
const char str_ALEX_BACK_D[16] = "ALEX BACK D   ";
const char str_ALEX_POWER_B[16] = "ALEX POWER B  ";
const char str_ALEX_SLEEPER[16] = "ALEX SLEEPER  ";
const char str_RYU_SEOINAGE[16] = "RYU SEOINAGE  ";
const char str_IBUKI_2[16] = "IBUKI         ";
const char str_DADLEY_L_B[16] = "DADLEY  L B   ";
const char str_IBUKI_KUBIORI[16] = "IBUKI KUBIORI ";
const char str_NECRO_S_T[16] = "NECRO S T     ";
const char str_RYU_TOMOENAGE[16] = "RYU TOMOENAGE ";
const char str_YUN_HIZAGERI[16] = "YUN HIZAGERI  ";
const char str_ORO_KUBISIME[16] = "ORO KUBISIME  ";
const char str_NECRO_G_S[16] = "NECRO G S     ";
const char str_DUDDLEY_D_S[16] = "DUDDLEY D S   ";
const char str_YUN_MONKEY_F[16] = "YUN MONKEY F  ";
const char str_ORO_TOMOENAGE[16] = "ORO TOMOENAGE ";
const char str_ORO_NIOURIKI[16] = "ORO NIOURIKI  ";
const char str_ORO_GIGOKU_G[16] = "ORO GIGOKU G  ";
const char str_YUN_2[16] = "YUN           ";
const char str_NECRO_SNAKE_F[16] = "NECRO SNAKE F ";
const char str_NECRO_F_S[16] = "NECRO F S     ";
const char str_IBUKI_HARAIG[16] = "IBUKI HARAIG  ";
const char str_GILL_SPLASH_M[16] = "GILL SPLASH M ";
const char str_KEN_HIZAGERI[16] = "KEN HIZAGERI  ";
const char str_ORO_KISINRIKI[16] = "ORO KISINRIKI ";
const char str_SEAN_TACKLE[16] = "SEAN TACKLE   ";
const char str_ALEX_HYPER_B[16] = "ALEX HYPER B  ";
const char str_NECRO_SLAM_D[16] = "NECRO SLAM D  ";
const char str_ELENA_ASINAGE[16] = "ELENA ASINAGE ";
const char str_GILL_IMPACT_C[16] = "GILL IMPACT C ";
const char str_ALEX_S_H_B[16] = "ALEX  S H B   ";
const char str_ALEX_F_N_D[16] = "ALEX  F N D   ";
const char str_IBUKI_YOROI_D[16] = "IBUKI YOROI D ";
const char str_MAWARIKOMI_M_F[16] = "MAWARIKOMI M F";
const char str_HUGO_BODY_S[16] = "HUGO BODY S   ";
const char str_HUGO_N_G_T[16] = "HUGO N G T    ";
const char str_HUGO_M_S_P[16] = "HUGO M S P    ";
const char str_HUGO_S_D_B_B[16] = "HUGO S D B B  ";
const char str_S_PUNCH_A[16] = "S PUNCH  A    ";
const char str_S_PUNCH_B[16] = "S PUNCH  B    ";
const char str_S_PUNCH_C[16] = "S PUNCH  C    ";
const char str_M_PUNCH_A[16] = "M PUNCH  A    ";
const char str_M_PUNCH_B[16] = "M PUNCH  B    ";
const char str_M_PUNCH_C[16] = "M PUNCH  C    ";
const char str_L_PUNCH_A[16] = "L PUNCH  A    ";
const char str_L_PUNCH_B[16] = "L PUNCH  B    ";
const char str_L_PUNCH_C[16] = "L PUNCH  C    ";
const char str_S_KICK_A[16] = "S KICK   A    ";
const char str_S_KICK_B[16] = "S KICK   B    ";
const char str_S_KICK_C[16] = "S KICK   C    ";
const char str_M_KICK_A[16] = "M KICK   A    ";
const char str_M_KICK_B[16] = "M KICK   B    ";
const char str_M_KICK_C[16] = "M KICK   C    ";
const char str_L_KICK_A[16] = "L KICK   A    ";
const char str_L_KICK_B[16] = "L KICK   B    ";
const char str_L_KICK_C[16] = "L KICK   C    ";
const char str_KAGAMI_P_A[16] = "KAGAMI P  A   ";
const char str_KAGAMI_P_B[16] = "KAGAMI P  B   ";
const char str_KAGAMI_P_C[16] = "KAGAMI P  C   ";
const char str_KAGAMI_K_A[16] = "KAGAMI K  A   ";
const char str_KAGAMI_K_B[16] = "KAGAMI K  B   ";
const char str_KAGAMI_K_C[16] = "KAGAMI K  C   ";
const char str_V_JUMP_P_S_A[16] = "V JUMP P S  A ";
const char str_V_JUMP_P_S_B[16] = "V JUMP P S  B ";
const char str_V_JUMP_P_M_A[16] = "V JUMP P M  A ";
const char str_V_JUMP_P_M_B[16] = "V JUMP P M  B ";
const char str_V_JUMP_P_L_A[16] = "V JUMP P L  A ";
const char str_V_JUMP_P_L_B[16] = "V JUMP P L  B ";
const char str_V_JUMP_K_S_A[16] = "V JUMP K S  A ";
const char str_V_JUMP_K_S_B[16] = "V JUMP K S  B ";
const char str_V_JUMP_K_M_A[16] = "V JUMP K M  A ";
const char str_V_JUMP_K_M_B[16] = "V JUMP K M  B ";
const char str_V_JUMP_K_L_A[16] = "V JUMP K L  A ";
const char str_V_JUMP_K_L_B[16] = "V JUMP K L  B ";
const char str_F_JUMP_P_S_A[16] = "F JUMP P S  A ";
const char str_F_JUMP_P_S_B[16] = "F JUMP P S  B ";
const char str_F_JUMP_P_M_A[16] = "F JUMP P M  A ";
const char str_F_JUMP_P_M_B[16] = "F JUMP P M  B ";
const char str_F_JUMP_P_L_A[16] = "F JUMP P L  A ";
const char str_F_JUMP_P_L_B[16] = "F JUMP P L  B ";
const char str_F_JUMP_K_S_A[16] = "F JUMP K S  A ";
const char str_F_JUMP_K_S_B[16] = "F JUMP K S  B ";
const char str_F_JUMP_K_M_A[16] = "F JUMP K M  A ";
const char str_F_JUMP_K_M_B[16] = "F JUMP K M  B ";
const char str_F_JUMP_K_L_A[16] = "F JUMP K L  A ";
const char str_F_JUMP_K_L_B[16] = "F JUMP K L  B ";
const char str_B_JUMP_P_S_A[16] = "B JUMP P S  A ";
const char str_B_JUMP_P_S_B[16] = "B JUMP P S  B ";
const char str_B_JUMP_P_M_A[16] = "B JUMP P M  A ";
const char str_B_JUMP_P_M_B[16] = "B JUMP P M  B ";
const char str_B_JUMP_P_L_A[16] = "B JUMP P L  A ";
const char str_B_JUMP_P_L_B[16] = "B JUMP P L  B ";
const char str_B_JUMP_K_S_A[16] = "B JUMP K S  A ";
const char str_B_JUMP_K_S_B[16] = "B JUMP K S  B ";
const char str_B_JUMP_K_M_A[16] = "B JUMP K M  A ";
const char str_B_JUMP_K_M_B[16] = "B JUMP K M  B ";
const char str_B_JUMP_K_L_A[16] = "B JUMP K L  A ";
const char str_B_JUMP_K_L_B[16] = "B JUMP K L  B ";
const char str_SP_V_JP_S_P_A[16] = "SP V JP S P  A";
const char str_SP_V_JP_S_P_B[16] = "SP V JP S P  B";
const char str_SP_V_JP_M_P_A[16] = "SP V JP M P  A";
const char str_SP_V_JP_M_P_B[16] = "SP V JP M P  B";
const char str_SP_V_JP_L_P_A[16] = "SP V JP L P  A";
const char str_SP_V_JP_L_P_B[16] = "SP V JP L P  B";
const char str_SP_V_JP_S_K_A[16] = "SP V JP S K  A";
const char str_SP_V_JP_S_K_B[16] = "SP V JP S K  B";
const char str_SP_V_JP_M_K_A[16] = "SP V JP M K  A";
const char str_SP_V_JP_M_K_B[16] = "SP V JP M K  B";
const char str_SP_V_JP_L_K_A[16] = "SP V JP L K  A";
const char str_SP_V_JP_L_K_B[16] = "SP V JP L K  B";
const char str_SP_F_JP_S_P_A[16] = "SP F JP S P  A";
const char str_SP_F_JP_S_P_B[16] = "SP F JP S P  B";
const char str_SP_F_JP_M_P_A[16] = "SP F JP M P  A";
const char str_SP_F_JP_M_P_B[16] = "SP F JP M P  B";
const char str_SP_F_JP_L_P_A[16] = "SP F JP L P  A";
const char str_SP_F_JP_L_P_B[16] = "SP F JP L P  B";
const char str_SP_F_JP_S_K_A[16] = "SP F JP S K  A";
const char str_SP_F_JP_S_K_B[16] = "SP F JP S K  B";
const char str_SP_F_JP_M_K_A[16] = "SP F JP M K  A";
const char str_SP_F_JP_M_K_B[16] = "SP F JP M K  B";
const char str_SP_F_JP_L_K_A[16] = "SP F JP L K  A";
const char str_SP_F_JP_L_K_B[16] = "SP F JP L K  B";
const char str_SP_B_JP_S_P_A[16] = "SP B JP S P  A";
const char str_SP_B_JP_S_P_B[16] = "SP B JP S P  B";
const char str_SP_B_JP_M_P_A[16] = "SP B JP M P  A";
const char str_SP_B_JP_M_P_B[16] = "SP B JP M P  B";
const char str_SP_B_JP_L_P_A[16] = "SP B JP L P  A";
const char str_SP_B_JP_L_P_B[16] = "SP B JP L P  B";
const char str_SP_B_JP_S_K_A[16] = "SP B JP S K  A";
const char str_SP_B_JP_S_K_B[16] = "SP B JP S K  B";
const char str_SP_B_JP_M_K_A[16] = "SP B JP M K  A";
const char str_SP_B_JP_M_K_B[16] = "SP B JP M K  B";
const char str_SP_B_JP_L_K_A[16] = "SP B JP L K  A";
const char str_SP_B_JP_L_K_B[16] = "SP B JP L K  B";
const char str_S_V_JP_S_P_A[16] = "S  V JP S P  A";
const char str_S_V_JP_S_P_B[16] = "S  V JP S P  B";
const char str_S_V_JP_M_P_A[16] = "S  V JP M P  A";
const char str_S_V_JP_M_P_B[16] = "S  V JP M P  B";
const char str_S_V_JP_L_P_A[16] = "S  V JP L P  A";
const char str_S_V_JP_L_P_B[16] = "S  V JP L P  B";
const char str_S_V_JP_S_K_A[16] = "S  V JP S K  A";
const char str_S_V_JP_S_K_B[16] = "S  V JP S K  B";
const char str_S_V_JP_M_K_A[16] = "S  V JP M K  A";
const char str_S_V_JP_M_K_B[16] = "S  V JP M K  B";
const char str_S_V_JP_L_K_A[16] = "S  V JP L K  A";
const char str_S_V_JP_L_K_B[16] = "S  V JP L K  B";
const char str_S_F_JP_S_P_A[16] = "S  F JP S P  A";
const char str_S_F_JP_S_P_B[16] = "S  F JP S P  B";
const char str_S_F_JP_M_P_A[16] = "S  F JP M P  A";
const char str_S_F_JP_M_P_B[16] = "S  F JP M P  B";
const char str_S_F_JP_L_P_A[16] = "S  F JP L P  A";
const char str_S_F_JP_L_P_B[16] = "S  F JP L P  B";
const char str_S_F_JP_S_K_A[16] = "S  F JP S K  A";
const char str_S_F_JP_S_K_B[16] = "S  F JP S K  B";
const char str_S_F_JP_M_K_A[16] = "S  F JP M K  A";
const char str_S_F_JP_M_K_B[16] = "S  F JP M K  B";
const char str_S_F_JP_L_K_A[16] = "S  F JP L K  A";
const char str_S_F_JP_L_K_B[16] = "S  F JP L K  B";
const char str_S_B_JP_S_P_A[16] = "S  B JP S P  A";
const char str_S_B_JP_S_P_B[16] = "S  B JP S P  B";
const char str_S_B_JP_M_P_A[16] = "S  B JP M P  A";
const char str_S_B_JP_M_P_B[16] = "S  B JP M P  B";
const char str_S_B_JP_L_P_A[16] = "S  B JP L P  A";
const char str_S_B_JP_L_P_B[16] = "S  B JP L P  B";
const char str_S_B_JP_S_K_A[16] = "S  B JP S K  A";
const char str_S_B_JP_S_K_B[16] = "S  B JP S K  B";
const char str_S_B_JP_M_K_A[16] = "S  B JP M K  A";
const char str_S_B_JP_M_K_B[16] = "S  B JP M K  B";
const char str_S_B_JP_L_K_A[16] = "S  B JP L K  A";
const char str_S_B_JP_L_K_B[16] = "S  B JP L K  B";
const char str_TUKAMIKAKARI_A[16] = "TUKAMIKAKARI A";
const char str_TUKAMIKAKARI_B[16] = "TUKAMIKAKARI B";
const char str_TUKAMIKAKARI_C[16] = "TUKAMIKAKARI C";
const char str_TUKAMIKAKARI_D[16] = "TUKAMIKAKARI D";
const char str_TUKAMIKAKARI_E[16] = "TUKAMIKAKARI E";
const char str_TUKAMIKAKARI_F[16] = "TUKAMIKAKARI F";
const char str_TUKAMI_AIR_A[16] = "TUKAMI  AIR  A";
const char str_TUKAMI_AIR_B[16] = "TUKAMI  AIR  B";
const char str_TUKAMI_AIR_C[16] = "TUKAMI  AIR  C";
const char str_TUKAMI_AIR_D[16] = "TUKAMI  AIR  D";
const char str_TUKAMI_AIR_E[16] = "TUKAMI  AIR  E";
const char str_TUKAMI_AIR_F[16] = "TUKAMI  AIR  F";
const char str_UP_P_GUARD_P_S[16] = "UP P GUARD P S";
const char str_UP_P_GUARD_P_M[16] = "UP P GUARD P M";
const char str_UP_P_GUARD_P_L[16] = "UP P GUARD P L";
const char str_UP_P_GUARD_K_S[16] = "UP P GUARD K S";
const char str_UP_P_GUARD_K_M[16] = "UP P GUARD K M";
const char str_UP_P_GUARD_K_L[16] = "UP P GUARD K L";
const char str_D_P_GUARD_P_S[16] = "D  P GUARD P S";
const char str_D_P_GUARD_P_M[16] = "D  P GUARD P M";
const char str_D_P_GUARD_P_L[16] = "D  P GUARD P L";
const char str_D_P_GUARD_K_S[16] = "D  P GUARD K S";
const char str_D_P_GUARD_K_M[16] = "D  P GUARD K M";
const char str_D_P_GUARD_K_L[16] = "D  P GUARD K L";
const char str_FUSHIN_P_S[16] = "FUSHIN     P S";
const char str_FUSHIN_P_M[16] = "FUSHIN     P M";
const char str_FUSHIN_P_L[16] = "FUSHIN     P L";
const char str_FUSHIN_K_S[16] = "FUSHIN     K S";
const char str_FUSHIN_K_M[16] = "FUSHIN     K M";
const char str_FUSHIN_K_L[16] = "FUSHIN     K L";
const char str_OKIAGARI_P_S[16] = "OKIAGARI   P S";
const char str_OKIAGARI_P_M[16] = "OKIAGARI   P M";
const char str_OKIAGARI_P_L[16] = "OKIAGARI   P L";
const char str_OKIAGARI_K_S[16] = "OKIAGARI   K S";
const char str_OKIAGARI_K_M[16] = "OKIAGARI   K M";
const char str_OKIAGARI_K_L[16] = "OKIAGARI   K L";
const char str_ATTACK_1_S[16] = "ATTACK 1   S  ";
const char str_ATTACK_1_M[16] = "ATTACK 1   M  ";
const char str_ATTACK_1_L[16] = "ATTACK 1   L  ";
const char str_ATTACK_1_SP[16] = "ATTACK 1   SP ";
const char str_ATTACK_2_S[16] = "ATTACK 2   S  ";
const char str_ATTACK_2_M[16] = "ATTACK 2   M  ";
const char str_ATTACK_2_L[16] = "ATTACK 2   L  ";
const char str_ATTACK_2_SP[16] = "ATTACK 2   SP ";
const char str_ATTACK_3_S[16] = "ATTACK 3   S  ";
const char str_ATTACK_3_M[16] = "ATTACK 3   M  ";
const char str_ATTACK_3_L[16] = "ATTACK 3   L  ";
const char str_ATTACK_3_SP[16] = "ATTACK 3   SP ";
const char str_ATTACK_4_S[16] = "ATTACK 4   S  ";
const char str_ATTACK_4_M[16] = "ATTACK 4   M  ";
const char str_ATTACK_4_L[16] = "ATTACK 4   L  ";
const char str_ATTACK_4_SP[16] = "ATTACK 4   SP ";
const char str_ATTACK_5_S[16] = "ATTACK 5   S  ";
const char str_ATTACK_5_M[16] = "ATTACK 5   M  ";
const char str_ATTACK_5_L[16] = "ATTACK 5   L  ";
const char str_ATTACK_5_SP[16] = "ATTACK 5   SP ";
const char str_ATTACK_6_S[16] = "ATTACK 6   S  ";
const char str_ATTACK_6_M[16] = "ATTACK 6   M  ";
const char str_ATTACK_6_L[16] = "ATTACK 6   L  ";
const char str_ATTACK_6_SP[16] = "ATTACK 6   SP ";
const char str_ATTACK_7_S[16] = "ATTACK 7   S  ";
const char str_ATTACK_7_M[16] = "ATTACK 7   M  ";
const char str_ATTACK_7_L[16] = "ATTACK 7   L  ";
const char str_ATTACK_7_SP[16] = "ATTACK 7   SP ";
const char str_ATTACK_8_S[16] = "ATTACK 8   S  ";
const char str_ATTACK_8_M[16] = "ATTACK 8   M  ";
const char str_ATTACK_8_L[16] = "ATTACK 8   L  ";
const char str_ATTACK_8_SP[16] = "ATTACK 8   SP ";
const char str_ATTACK_9_S[16] = "ATTACK 9   S  ";
const char str_ATTACK_9_M[16] = "ATTACK 9   M  ";
const char str_ATTACK_9_L[16] = "ATTACK 9   L  ";
const char str_ATTACK_9_SP[16] = "ATTACK 9   SP ";
const char str_ATTACK_10_S[16] = "ATTACK 10  S  ";
const char str_ATTACK_10_M[16] = "ATTACK 10  M  ";
const char str_ATTACK_10_L[16] = "ATTACK 10  L  ";
const char str_ATTACK_10_SP[16] = "ATTACK 10  SP ";
const char str_ATTACK_11_S[16] = "ATTACK 11  S  ";
const char str_ATTACK_11_M[16] = "ATTACK 11  M  ";
const char str_ATTACK_11_L[16] = "ATTACK 11  L  ";
const char str_ATTACK_11_SP[16] = "ATTACK 11  SP ";
const char str_ATTACK_12_S[16] = "ATTACK 12  S  ";
const char str_ATTACK_12_M[16] = "ATTACK 12  M  ";
const char str_ATTACK_12_L[16] = "ATTACK 12  L  ";
const char str_ATTACK_12_SP[16] = "ATTACK 12  SP ";
const char str_ATTACK_13_S[16] = "ATTACK 13  S  ";
const char str_ATTACK_13_M[16] = "ATTACK 13  M  ";
const char str_ATTACK_13_L[16] = "ATTACK 13  L  ";
const char str_ATTACK_13_SP[16] = "ATTACK 13  SP ";
const char str_HANASARE[16] = "HANASARE      ";
const char str_EFF01_CHAR[16] = "EFF01 CHAR    ";
const char str_EFF13_CHAR[16] = "EFF13 CHAR    ";
const char str_BONUS_CHAR[16] = "BONUS CHAR    ";
const char str_JUDGEMENT_GAL[16] = "JUDGEMENT GAL ";
const char str_EXTRA[16] = "EXTRA         ";
const char str_PLEF[16] = "PLEF          ";
const char str_SELECT[16] = "SELECT        ";
const char str_ETC_1[16] = "ETC 1         ";
const char str_ETC_2[16] = "ETC 2         ";
const char str_ETC_3[16] = "ETC 3         ";
const char str_RUCCIA[16] = "RUCCIA        ";
const char str_AFRICA_2[16] = "AFRICA        ";
const char str_N_Y[16] = "N.Y           ";
const char str_HONGKONG[16] = "HONGKONG      ";
const char str_JAPAN2[16] = "JAPAN2        ";
const char str_GERMANY_2[16] = "GERMANY       ";
const char str_BRAZIL_2[16] = "BRAZIL        ";
const char str_ORUMEKA[16] = "ORUMEKA       ";
const char str_ENGLAND_2[16] = "ENGLAND       ";
const char str_JAPAN_3[16] = "JAPAN 3       ";
const char str_GILL_STAGE[16] = "GILL STAGE    ";
const char str_JAPAN_11[16] = "JAPAN 11      ";
const char str_BONUS[16] = "BONUS         ";
const char str_FRANCE_2[16] = "FRANCE        ";
const char str_CHAINA_2[16] = "CHAINA        ";
const char str_BRAZIL_1_2[16] = "BRAZIL 1      ";
const char str_JAPAN_10[16] = "JAPAN 10      ";
const char str_ENDING[16] = "ENDING        ";
const char str_APPEAR_JUNBI_1[16] = "APPEAR JUNBI 1";
const char str_APPEAR_JUNBI_2[16] = "APPEAR JUNBI 2";
const char str_APPEAR_JUNBI_3[16] = "APPEAR JUNBI 3";
const char str_APPEAR_JUNBI_4[16] = "APPEAR JUNBI 4";
const char str_APPEAR_JUNBI_5[16] = "APPEAR JUNBI 5";
const char str_APPEAR_JUNBI_6[16] = "APPEAR JUNBI 6";
const char str_APPEAR_JUNBI_7[16] = "APPEAR JUNBI 7";
const char str_APPEAR_JUNBI_8[16] = "APPEAR JUNBI 8";
const char str_APPEAR_1[16] = "APPEAR   1    ";
const char str_APPEAR_2[16] = "APPEAR   2    ";
const char str_APPEAR_3[16] = "APPEAR   3    ";
const char str_APPEAR_4[16] = "APPEAR   4    ";
const char str_APPEAR_5[16] = "APPEAR   5    ";
const char str_APPEAR_6[16] = "APPEAR   6    ";
const char str_APPEAR_7[16] = "APPEAR   7    ";
const char str_APPEAR_8[16] = "APPEAR   8    ";
const char str_SP_APPEAR_1[16] = "SP  APPEAR  1 ";
const char str_SP_APPEAR_2[16] = "SP  APPEAR  2 ";
const char str_SP_APPEAR_3[16] = "SP  APPEAR  3 ";
const char str_SP_APPEAR_4[16] = "SP  APPEAR  4 ";
const char str_SP_APPEAR_5[16] = "SP  APPEAR  5 ";
const char str_SP_APPEAR_6[16] = "SP  APPEAR  6 ";
const char str_SP_APPEAR_7[16] = "SP  APPEAR  7 ";
const char str_SP_APPEAR_8[16] = "SP  APPEAR  8 ";
const char str_ZANNEN_1[16] = "ZANNEN  1     ";
const char str_ZANNEN_2[16] = "ZANNEN  2     ";
const char str_ZANNEN_3[16] = "ZANNEN  3     ";
const char str_ZANNEN_4[16] = "ZANNEN  4     ";
const char str_ZANNEN_5[16] = "ZANNEN  5     ";
const char str_ZANNEN_6[16] = "ZANNEN  6     ";
const char str_ZANNEN_7[16] = "ZANNEN  7     ";
const char str_ZANNEN_8[16] = "ZANNEN  8     ";
const char str_WIN_1[16] = "WIN  1        ";
const char str_WIN_2[16] = "WIN  2        ";
const char str_WIN_3[16] = "WIN  3        ";
const char str_WIN_4[16] = "WIN  4        ";
const char str_WIN_5[16] = "WIN  5        ";
const char str_WIN_6[16] = "WIN  6        ";
const char str_WIN_7[16] = "WIN  7        ";
const char str_WIN_8[16] = "WIN  8        ";
const char str_SP_WIN_1[16] = "SP WIN  1     ";
const char str_SP_WIN_2[16] = "SP WIN  2     ";
const char str_SP_WIN_3[16] = "SP WIN  3     ";
const char str_SP_WIN_4[16] = "SP WIN  4     ";
const char str_SP_WIN_5[16] = "SP WIN  5     ";
const char str_SP_WIN_6[16] = "SP WIN  6     ";
const char str_SP_WIN_7[16] = "SP WIN  7     ";
const char str_SP_WIN_8[16] = "SP WIN  8     ";
const char str_JUDGMENT_WAIT[16] = "JUDGMENT WAIT ";
const char str_JUDGMENT_WIN[16] = "JUDGMENT WIN  ";
const char str_JUDGMENT_LOSE[16] = "JUDGMENT LOSE ";
const char str_WAIT[16] = "WAIT          ";
const char str_AFRICA_JUMP[16] = "AFRICA  JUMP  ";
const char str_AFRICA_LAND[16] = "AFRICA  LAND  ";
const char str_SEAN_BALL_HIT[16] = "SEAN BALL HIT ";
const char str_BONUS_WIN_1[16] = "BONUS WIN 1   ";
const char str_BONUS_WIN_2[16] = "BONUS WIN 2   ";
const char str_BONUS_WIN_3[16] = "BONUS WIN 3   ";
const char str_APPEAR_USE[16] = "APPEAR USE    ";


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

const u16 kaiten_lever_tbl[8] = {
    1, 9, 8, 0xA, 2, 6, 4, 5,
};

/*
 * CMD_MAIN.C  Debug menu and command input
 *
 * The debug_* screens - OBJECT LOOK/EDIT, HIT and CATCH JUDGMENT box editors, the HIT -A- JUDGEMENT
 * grid, PARTS, BG select, player snapshots, a move recorder and on-screen dumps of player state and
 * cg data.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "Com_Pl.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "CALDIR.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF00.h"
#include "EFF02.h"
#include "EFFK5.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "PLS01.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "fifo.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "bg000.h"
#include "HITCHECK.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "cmd_main_2.h"
#include "CMD_MAIN.h"
#include "cps3.h"
#include "eff05.h"
#include "EFFC9.h"

/* Debug_R_No: the debug menu routine (debug_scene_outer_dispatch) */
#define DBG_INIT        0       /* debug_menu_work_init */
#define DBG_GFX         1       /* debug_menu_gfx_load */
#define DBG_PLAYER      2       /* debug_menu_player_setup */
#define DBG_SELECT      3       /* debug_menu_select_dispatch */
#define DBG_RUN         4       /* the debug scene, until exit */

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
extern const u32 afc_char_table[];
extern const u32 alex_atca[];
extern const u32 alex_btca[];
extern const u32 alex_caca[];
extern const u32 alex_cuca[];
extern const u32 alex_dmca[];
extern const u32 alex_exca[];
extern const u32 alex_nmca[];
extern const u32 alex_saca[];
extern const u32 alex_yuca[];
extern const u32 chun_atca[];
extern const u32 chun_btca[];
extern const u32 chun_caca[];
extern const u32 chun_cuca[];
extern const u32 chun_dmca[];
extern const u32 chun_exca[];
extern const u32 chun_nmca[];
extern const u32 chun_saca[];
extern const u32 chun_yuca[];
extern const u32 dudley_atca[];
extern const u32 dudley_btca[];
extern const u32 dudley_caca[];
extern const u32 dudley_cuca[];
extern const u32 dudley_dmca[];
extern const u32 dudley_exca[];
extern const u32 dudley_nmca[];
extern const u32 dudley_saca[];
extern const u32 dudley_yuca[];
extern const u32 elena_atca[];
extern const u32 elena_btca[];
extern const u32 elena_caca[];
extern const u32 elena_cuca[];
extern const u32 elena_dmca[];
extern const u32 elena_exca[];
extern const u32 elena_nmca[];
extern const u32 elena_saca[];
extern const u32 elena_yuca[];
extern const u32 fnl_char_table[];
extern const u32 gill_atca[];
extern const u32 gill_btca[];
extern const u32 gill_caca[];
extern const u32 gill_cuca[];
extern const u32 gill_dmca[];
extern const u32 gill_exca[];
extern const u32 gill_nmca[];
extern const u32 gill_saca[];
extern const u32 gill_yuca[];
extern const u32 gouki1_atca[];
extern const u32 gouki1_btca[];
extern const u32 gouki1_caca[];
extern const u32 gouki1_cuca[];
extern const u32 gouki1_dmca[];
extern const u32 gouki1_exca[];
extern const u32 gouki1_nmca[];
extern const u32 gouki1_saca[];
extern const u32 gouki1_yuca[];
extern const u32 gouki2_atca[];
extern const u32 gouki2_btca[];
extern const u32 gouki2_caca[];
extern const u32 gouki2_cuca[];
extern const u32 gouki2_dmca[];
extern const u32 gouki2_exca[];
extern const u32 gouki2_nmca[];
extern const u32 gouki2_saca[];
extern const u32 gouki2_yuca[];
extern const u32 hugo_atca[];
extern const u32 hugo_btca[];
extern const u32 hugo_caca[];
extern const u32 hugo_cuca[];
extern const u32 hugo_dmca[];
extern const u32 hugo_exca[];
extern const u32 hugo_nmca[];
extern const u32 hugo_saca[];
extern const u32 hugo_yuca[];
extern const u32 ibuki_atca[];
extern const u32 ibuki_btca[];
extern const u32 ibuki_caca[];
extern const u32 ibuki_cuca[];
extern const u32 ibuki_dmca[];
extern const u32 ibuki_exca[];
extern const u32 ibuki_nmca[];
extern const u32 ibuki_saca[];
extern const u32 ibuki_yuca[];
extern const u32 j11_char_table[];
extern const u32 ken_atca[];
extern const u32 ken_btca[];
extern const u32 ken_caca[];
extern const u32 ken_cuca[];
extern const u32 ken_dmca[];
extern const u32 ken_exca[];
extern const u32 ken_nmca[];
extern const u32 ken_saca[];
extern const u32 ken_yuca[];
extern const u32 makoto_atca[];
extern const u32 makoto_btca[];
extern const u32 makoto_caca[];
extern const u32 makoto_cuca[];
extern const u32 makoto_dmca[];
extern const u32 makoto_exca[];
extern const u32 makoto_nmca[];
extern const u32 makoto_saca[];
extern const u32 makoto_yuca[];
extern const u32 necro_atca[];
extern const u32 necro_btca[];
extern const u32 necro_caca[];
extern const u32 necro_cuca[];
extern const u32 necro_dmca[];
extern const u32 necro_exca[];
extern const u32 necro_nmca[];
extern const u32 necro_saca[];
extern const u32 necro_yuca[];
extern const u32 no12_atca[];
extern const u32 no12_btca[];
extern const u32 no12_caca[];
extern const u32 no12_cuca[];
extern const u32 no12_dmca[];
extern const u32 no12_exca[];
extern const u32 no12_nmca[];
extern const u32 no12_saca[];
extern const u32 no12_yuca[];
extern const u32 orm_char_table[];
extern const u32 oro_atca[];
extern const u32 oro_btca[];
extern const u32 oro_caca[];
extern const u32 oro_cuca[];
extern const u32 oro_dmca[];
extern const u32 oro_exca[];
extern const u32 oro_nmca[];
extern const u32 oro_saca[];
extern const u32 oro_yuca[];
extern const u32 q_atca[];
extern const u32 q_btca[];
extern const u32 q_caca[];
extern const u32 q_cuca[];
extern const u32 q_dmca[];
extern const u32 q_exca[];
extern const u32 q_nmca[];
extern const u32 q_saca[];
extern const u32 q_yuca[];
extern const u32 remy_atca[];
extern const u32 remy_btca[];
extern const u32 remy_caca[];
extern const u32 remy_cuca[];
extern const u32 remy_dmca[];
extern const u32 remy_exca[];
extern const u32 remy_nmca[];
extern const u32 remy_saca[];
extern const u32 remy_yuca[];
extern const u32 ryu_atca[];
extern const u32 ryu_btca[];
extern const u32 ryu_caca[];
extern const u32 ryu_cuca[];
extern const u32 ryu_dmca[];
extern const u32 ryu_exca[];
extern const u32 ryu_nmca[];
extern const u32 ryu_saca[];
extern const u32 ryu_yuca[];
extern const u32 sean_atca[];
extern const u32 sean_btca[];
extern const u32 sean_caca[];
extern const u32 sean_cuca[];
extern const u32 sean_dmca[];
extern const u32 sean_exca[];
extern const u32 sean_nmca[];
extern const u32 sean_saca[];
extern const u32 sean_yuca[];
extern const u32 urien_atca[];
extern const u32 urien_btca[];
extern const u32 urien_caca[];
extern const u32 urien_cuca[];
extern const u32 urien_dmca[];
extern const u32 urien_exca[];
extern const u32 urien_nmca[];
extern const u32 urien_saca[];
extern const u32 urien_yuca[];
extern const u32 yang_atca[];
extern const u32 yang_btca[];
extern const u32 yang_caca[];
extern const u32 yang_cuca[];
extern const u32 yang_dmca[];
extern const u32 yang_exca[];
extern const u32 yang_nmca[];
extern const u32 yang_saca[];
extern const u32 yang_yuca[];
extern const u32 yun_atca[];
extern const u32 yun_btca[];
extern const u32 yun_caca[];
extern const u32 yun_cuca[];
extern const u32 yun_dmca[];
extern const u32 yun_exca[];
extern const u32 yun_nmca[];
extern const u32 yun_saca[];
extern const u32 yun_yuca[];



s8 Debug_R_No;  /* 0201706C */
s8 Debug_Select_No;  /* 0201706D */
s8 Debug_Menu_No;  /* 0201706E */
s8 Debug_Tool_No;  /* 0201706F */
s16 Debug_Rep_Timer[21];  /* 02017070 */
s8 Debug_Rep_Count[21];  /* 0201709A */
s16 Debug_RGB[4];  /* 020170B0 */
s8 Debug_RL_Flag[2];  /* 020170B8 */
s8 Debug_CG_Flip[2];  /* 020170BA */
s8 Debug_Flip_Work[2];  /* 020170BC */
s8 Debug_Flip_Mask[2];  /* 020170BE */
s8 Debug_Play_Flag;  /* 020170C0 */
s8 Debug_Snap_Disp;  /* 020170C1 */
s8 Debug_Dec_Disp;  /* 020170C2 */
s16 Debug_Rec_Frame;  /* 020170C4 */
s16 Debug_Rec_Count;  /* 020170C6 */
s8 Debug_PL_id;  /* 020170C8 */
s8 Debug_Command;  /* 020170C9 */
s8 Debug_Edit_Sub;  /* 020170CA */
s8 Debug_Hit_Sub;  /* 020170CB */
s8 Debug_Box_Edit;  /* 020170CC */
s8 dbg_copy_done;  /* 020170CD */
s8 dbg_snap_req;  /* 020170CE */
s8 dbg_hud_mode;  /* 020170CF */
s8 dbg_rec_menu;  /* 020170D0 */
s8 dbg_save_mode;  /* 020170D1 */
s8 dbg_look_mode;  /* 020170D2 */
s8 dbg_kakusyuku_mode;  /* 020170D3 */
s8 dbg_rec_exist;  /* 020170D4 */
s8 dbg_cmd_panel;  /* 020170D5 */
s8 dbg_col_ix[2];  /* 020170D6 */
s8 dbg_stage_sel;  /* 020170D8 */
s8 dbg_stage_sub;  /* 020170D9 */
s16 dbg_judge_eff_ix;  /* 020170DA */
s16 dbg_zoom_x;  /* 020170DC */
s16 dbg_zoom_y;  /* 020170DE */
s16 dbg_old_cgd_type;  /* 020170E0 */
s16 dbg_hud_x;  /* 020170E2 */
s16 dbg_copy_pat;  /* 020170E4 */
s16 dbg_copy_char;  /* 020170E6 */
u8 dbg_copy_char_tail[2];  /* after dbg_copy_char; nothing refers to it by name or address */
u16 dbg_p1sw_0;  /* 020170EA */
u16 dbg_p1sw_1;  /* 020170EC */
u16 dbg_p2sw_0;  /* 020170EE */
u16 dbg_p2sw_1;  /* 020170F0 */
s16 dbg_dipsw_0;  /* 020170F2 */
s16 dbg_dipsw_1;  /* 020170F4 */
s16 * dbg_edit_box;  /* 020170F8 */
s16 dbg_col_char;  /* 020170FC */
PLW * dbg_pl;  /* 02017100 */
DBG_SLOT * dbg_slot;  /* 02017104 */
s16 dbg_slot_w[2][9];  /* 02017108 */
SNAPSHOT* dbg_snap_ptr;  /* 0201712C */
SNAPSHOT dbg_snap_w[2][128];  /* 02017130 */
WORK_Other * dbg_ghost_ewk[2][3];  /* 02018B30 */
s16 dbg_col_no;  /* 02018B48 */
s16 dbg_bgcol_ix;  /* 02018B4A */
PATTERN_BUF dbg_look_buf;  /* 02018B4C */
u8 dbg_look_buf_tail[20];  /* after dbg_look_buf; nothing refers to it by name or address */
PATTERN_BUF dbg_copy_buf;  /* 020194EC */
u8 dbg_copy_buf_tail[20];  /* after dbg_copy_buf; nothing refers to it by name or address */
PATTERN_BUF dbg_edit_buf;  /* 02019E8C */
u8 dbg_edit_buf_tail[20];  /* after dbg_edit_buf; nothing refers to it by name or address */
WORK_Other_JUDGE * dbg_judge_ewk;  /* 0201A82C */
u8 dbg_look_judge[1584];  /* 0201A830 */
HITA_BOX dbg_look_body[99];  /* 0201AE60 */
HITA_BOX dbg_look_hand[198];  /* 0201BAC0 */
CATCH_BOX dbg_look_catch[99];  /* 0201D380 */
CAUGHT_BOX dbg_look_caught[99];  /* 0201D698 */
HITA_BOX dbg_look_attack[198];  /* 0201D9B0 */
HOSEI_BOX dbg_look_hosei[99];  /* 0201F270 */
u8 dbg_edit_judge[1584];  /* 0201F588 */
BODY_BOX dbg_edit_body[99];  /* 0201FBB8 */
HAND_BOX dbg_edit_hand[198];  /* 02020818 */
CATCH_BOX dbg_edit_catch[99];  /* 020220D8 */
CAUGHT_BOX dbg_edit_caught[99];  /* 020223F0 */
ATTACK_BOX dbg_edit_attack[198];  /* 02022708 */
HOSEI_BOX dbg_edit_hosei[99];  /* 02023FC8 */
u8 dbg_copy_judge[16];  /* 020242E0 */
BODY_BOX dbg_copy_body[1];  /* 020242F0 */
HAND_BOX dbg_copy_hand[2];  /* 02024310 */
CATCH_BOX dbg_copy_catch[1];  /* 02024350 */
CAUGHT_BOX dbg_copy_caught[1];  /* 02024358 */
ATTACK_BOX dbg_copy_attack[2];  /* 02024360 */
HOSEI_BOX dbg_copy_hosei[1];  /* 020243A0 */
WORK_Other * dbg_hita_ewk[7];  /* 020243A8 */
u8 dbg_hita_ewk_tail[4];  /* after dbg_hita_ewk; nothing refers to it by name or address */
s16 dbg_hita_num;  /* 020243C8 */
s16 dbg_hita_grid_sw;  /* 020243CA */
s16 dbg_parts_olc_ix[4];  /* 020243CC */
s8 dbg_parts_sel;  /* 020243D4 */
PLW dbg_parts_plw[4];  /* 020243D8 */
u8 ixbfw_cut;  /* 02025638 */


void bg_cell_write(s16 bg, s32 ofs, s32 cell, u32 src, u32 u5, s16 attr);

#pragma inline(debug_menu_select_dispatch)

/* provisional name */
s32 debug_scene_outer_dispatch(void) {
    dbg_p1sw_1 = dbg_p1sw_0;
    dbg_p1sw_0 = p1sw_0;
    dbg_p2sw_1 = dbg_p2sw_0;
    dbg_p2sw_0 = p2sw_0;
    dbg_dipsw_1 = dbg_dipsw_0;
    dbg_dipsw_0 = exsw_1;
    plw[0].wu.old_rno[0] = plw[0].wu.cg_number;
    plw[1].wu.old_rno[0] = plw[1].wu.cg_number;
    switch (Debug_R_No) {
    case DBG_INIT:
        debug_menu_work_init();
        break;
    case DBG_GFX:
        debug_menu_gfx_load();
        break;
    case DBG_PLAYER:
        debug_menu_player_setup();
        break;
    case DBG_SELECT:
        debug_menu_select_dispatch();
        break;
    case DBG_RUN:
        if (!debug_menu_exit_check()) {
            debug_main_dispatch();
            debug_effect_move_all();
        }
        break;
    }
    if ((dbg_p2sw_0 & 0xF0) == 0xF0) {
        return 1;
    }
    return 0;
}

/* provisional name */
void debug_effect_move_all(void)
{
    color_trans_dummy();
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(6);
    move_effect_work(5);
}



/* provisional name */
void debug_menu_work_init(void) {
    s16 i;
    s16 j;
    s16* p;
    Debug_R_No++;
    palette_bank_set(0x3FC00);
    palette_write(0, sys_palette, 0x100);
    dbg_stage_sel = dbg_stage_sub = 0;
    debug_edit_slots_reset();
    for (i = 0; i < 2; i++) {
        p = (s16*)(dbg_slot_w + i);
        for (j = 0; j < 16; j++) {
            *p++ = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        ((DBG_SLOT*)(dbg_slot_w + i))->sel[1] = 1;
        ((DBG_SLOT*)(dbg_slot_w + i))->sel[2] = 0;
        p = (s16*)(dbg_snap_w + i);
        for (j = 0; j < 12; j++) {
            *p++ = 0;
        }
    }
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    Game_pause = 0;
    G_No0 = 0;
    G_No1 = 0;
    G_No2 = 0;
    G_No3 = 0;
    plw[0].zuru_timer = plw[1].zuru_timer = 0;
}

/* provisional name */
void debug_menu_gfx_load(void)
{
    Debug_R_No++;
    tilemap_fill_all(0, 0x20);
    init_char_gfx_tables();
    effect_work_quick_init();
    load_char_gfx(0x9000, 1);
    setup_kage_cells();
    Game_pause = 0;
}



/* provisional name */
void debug_menu_player_setup(void) {
    s16 i;
    s16 j;
    s16 ix;
    WORK_Other* ewk;
    Debug_R_No++;
    tilemap_fill_all(0, 32);
    work_init_zero((s32*)&plw[0], sizeof(PLW));
    work_init_zero((s32*)&plw[1], sizeof(PLW));
    debug_pattern_edit_init_counts();
    debug_edit_slots_reset();
    debug_both_players_reset();
    plw[0].wu.hit_adrs = (u32*)&plw[1];
    plw[1].wu.hit_adrs = (u32*)&plw[0];
    plw[0].wu.dmg_adrs = (u32*)&plw[1];
    plw[1].wu.dmg_adrs = (u32*)&plw[0];
    init_color_trans_req();
    load_any_color(0);
    load_player_color(plw[0].player_number, 0, 0);
    load_player_color(plw[1].player_number, 1, 0);
    effect_00_init(&plw[0].wu);
    effect_00_init(&plw[1].wu);
    effect_01_init(&plw[0].wu, 0);
    effect_01_init(&plw[0].wu, 1);
    effect_01_init(&plw[0].wu, 2);
    effect_01_init(&plw[0].wu, 3);
    effect_01_init(&plw[1].wu, 0);
    effect_01_init(&plw[1].wu, 1);
    effect_01_init(&plw[1].wu, 2);
    effect_01_init(&plw[1].wu, 3);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if ((ix = pull_effect_work(7)) == -1) {
                return;
            }
            ewk = (WORK_Other*)frw[ix];
            ewk->wu.cgromtype = 1;
            ewk->wu.my_family = 1;
            if (i == 0) {
                ewk->wu.my_col_code = 0x2000;
            } else {
                ewk->wu.my_col_code = 0x2010;
            }
            ewk->wu.my_col_mode = 0x4200;
            ewk->wu.id = i;
            dbg_ghost_ewk[i][j] = ewk;
        }
    }
    dbg_judge_eff_ix = search_effect_index(0, 0, 0);
    Debug_Rec_Frame = 0;
    Debug_Rec_Count = 0;
    Debug_PL_id = 0;
    Debug_Dec_Disp = 0;
    dbg_cmd_panel = 0;
    dbg_hud_mode = 0;
    ixbfw_cut = 0;
    Game_pause = 0;
    if (Game_setting.mode) {
        dbg_hud_x = 8;
    } else {
        dbg_hud_x = 0;
    }
}



/* provisional name */
void debug_menu_select_dispatch(void) {
    void (*Select_Tbl[2])() = { debug_menu_select_init, debug_menu_select_run };
    Select_Tbl[Debug_Select_No]();
}

/* provisional name */
void debug_menu_select_init(void)
{
    Debug_Select_No++;
    tilemap_fill_all(0, 0x20);
    Debug_Menu_No += 4;
    tilemap_print_string(0, 0, 0xFFFF, dbg_menu_str);
    tilemap_print_string_attr(8, Debug_Menu_No, 6, "T");
    Game_pause = 0;
}



/* provisional name */
void debug_menu_select_run(void) {
    u16 sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & BUTTON_LP) {
        Debug_Menu_No -= 4;
        Debug_R_No++;
        Debug_Tool_No = 0;
        debug_bg_stage_load();
        return;
    }
    if (sw & LEVER_UP) {
        tilemap_print_string_attr(8, Debug_Menu_No, 6, " ");
        Debug_Menu_No--;
        if (Debug_Menu_No < 4) {
            Debug_Menu_No = 17;
        }
    } else if (sw & LEVER_DOWN) {
        tilemap_print_string_attr(8, Debug_Menu_No, 6, " ");
        Debug_Menu_No++;
        if (Debug_Menu_No > 17) {
            Debug_Menu_No = 4;
        }
    }
    tilemap_print_string_attr(8, Debug_Menu_No, 6, "T");
}



/* provisional name */
void debug_main_dispatch(void) {
    void (*Debug_Tbl[14])() = { debug_bg_select_dispatch, debug_object_look_dispatch, debug_object_edit_dispatch, debug_object_edit_all_char_dispatch, debug_hit_judgment_dispatch, debug_char_preview_dispatch, debug_parts_dispatch, debug_play07, debug_play08, debug_play09, debug_play10, debug_play11, debug_play12, debug_play13 };
    dbg_old_cgd_type = plw[0].wu.cgd_type;
    Debug_Tbl[Debug_Menu_No]();
}



/* provisional name */
void debug_bg_select_dispatch(void) {
    void (*BG_Tbl[2])() = { debug_bg_select_init, debug_bg_select_navigate_updown };
    BG_Tbl[Debug_Tool_No]();
    tilemap_print_string(0, 0, 0xFFFF, &dbg_bg_name_str[dbg_stage_sel]);
}

/* provisional name */
void debug_bg_select_init(void)
{
    Debug_Tool_No++;
    tilemap_fill_all(0, 0x20);
    tilemap_print_string_attr(0xF, 1, 0xE, bg_select_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_select_exit_str);
    debug_bg_stage_load();
}



/* provisional name */
void debug_bg_select_navigate_updown(void) {
    s16 moved = 0;
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_stage_sel--;
        moved = 1;
        if (dbg_stage_sel < 0) {
            dbg_stage_sel = 23;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_stage_sel++;
        moved = 1;
        if (dbg_stage_sel > 23) {
            dbg_stage_sel = 0;
        }
    }
    bg_w.stage = dbg_bg_select_tbl[dbg_stage_sel][0];
    bg_w.area = dbg_bg_select_tbl[dbg_stage_sel][1];
    if (moved) {
        Scr_all_clear_Wait();
        Debug_Tool_No = 0;
    }
}



const char bg_select_msg[12] = "BG SELECT";


/* provisional name */
void debug_object_look_dispatch(void) {
    void (*Look_Tbl[2])() = { debug_object_look_init, debug_object_look_run };
    dbg_pl = plw;
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    Look_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_kakusyuku_frame_flags();
    debug_hud_mode_dispatch();
}



/* provisional name */
void debug_object_look_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, object_look_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    dbg_kakusyuku_mode = 0;
    dbg_look_mode = 0;
    dbg_zoom_x = 19;
    dbg_zoom_y = 19;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    Debug_Snap_Disp = 0;
    Debug_PL_id = 0;
    debug_both_players_reset();
    plw[1].wu.disp_flag = 0;
    plw[1].wu.be_flag = 0;
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
}



/* provisional name */
void debug_object_look_run(void) {
    Debug_Command = 0;
    debug_object_look_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        dbg_pl->wu.meoshi_hit_flag = 1;
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 2:
        dbg_pl->wu.meoshi_hit_flag = 1;
        if (dbg_slot->sel[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 4:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot->sel[2] == dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            break;
        } else {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        break;
    case 5:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    case 6:
        dbg_pl->wu.meoshi_hit_flag = 1;
        char_move_cmoa(&dbg_pl->wu);
        debug_pattern_timer_update();
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
    }
    dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos;
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos;
    dbg_pl->wu.position_z = dbg_pl->wu.my_priority;
    sort_push_request(&dbg_pl->wu);
}



const char object_look_msg[12] = "OBJECT LOOK";


/* provisional name */
void debug_object_edit_dispatch(void) {
    void (*Edit_Tbl[2])() = { debug_object_edit_init, debug_object_edit_move };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = (DBG_SLOT*)(dbg_slot_w + Debug_PL_id);
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    Edit_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_record_info();
}



/* provisional name */
void debug_object_edit_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, object_edit_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_edit_num_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_both_players_reset();
    dbg_save_mode = 2;
    dbg_rec_menu = 0;
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Edit_Sub = 0;
    dbg_rec_exist = 0;
    Debug_Snap_Disp = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    Debug_Dec_Disp = 0;
    for (i = 0; i < 2; i++) {
        dbg_pl = &plw[i];
        dbg_slot = (DBG_SLOT*)(dbg_slot_w + i);
        debug_slot_char_load();
        debug_motion_list_count();
        debug_pattern_count();
        debug_pattern_timer_update();
    }
}



/* provisional name */
void debug_object_edit_move(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_object_edit_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 2:
        if (dbg_slot->sel[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot->sel[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        Debug_Play_Flag = 0;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot->sel[2]++;
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        Debug_Play_Flag = 0;
        break;
    case 6:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
            break;
        }
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
        dbg_rec_exist = 1;
        dbg_snap_ptr->used++;
        if (dbg_snap_ptr->used > dbg_snap_ptr->cg_ctr) {
            dbg_snap_ptr->used = 1;
            Debug_Rec_Frame++;
            if (Debug_Rec_Frame > Debug_Rec_Count) {
                Debug_Rec_Frame = 1;
            }
        }
        break;
    case 7:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, (char *)&no_edit_erase_msg);
        } else {
            tilemap_print_string_attr(30, 1, 6, (char *)&no_edit_msg);
            break;
        }
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
        dbg_rec_exist = 1;
        dbg_snap_ptr->used = 1;
        Debug_Rec_Frame++;
        if (Debug_Rec_Frame > Debug_Rec_Count) {
            Debug_Rec_Frame = 1;
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 8:
        debug_record_frame_save();
        Debug_Play_Flag = 1;
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    debug_object_edit_snapshot_restore();
    debug_draw_record_ghosts();
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
}



/* provisional name */
void debug_record_frame_save(void) {
    s16 i;
    s16 j;
    switch (dbg_save_mode) {
    case 0:
        dbg_snap_req = 1;
        debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
        debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        if (Debug_Rec_Frame < Debug_Rec_Count) {
            Debug_Rec_Frame++;
        }
        break;
    case 1:
        if (dbg_rec_exist == 0) {
            break;
        } else {
            if (Debug_Rec_Count > 128) {
                i = 127;
            } else {
                i = Debug_Rec_Count;
            }
            for (; i > Debug_Rec_Frame - 1; i--) {
                j = i + 1;
                debug_copy_player_snapshot(&dbg_snap_w[0][i], &dbg_snap_w[0][j]);
                debug_copy_player_snapshot(&dbg_snap_w[1][i], &dbg_snap_w[1][j]);
            }
            debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
            debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            if (Debug_Rec_Count + 1 <= 128) {
                Debug_Rec_Count++;
            }
        }
        break;
    case 2:
        if (dbg_rec_exist == 0) {
            if (Debug_Rec_Frame + 1 > 128) {
                break;
            }
            Debug_Rec_Frame++;
            if (Debug_Rec_Count + 1 > 128) {
                break;
            } else {
                Debug_Rec_Count++;
                debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
                debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            }
        } else {
            if (Debug_Rec_Frame + 1 > 128) {
                break;
            }
            if (Debug_Rec_Count > 128) {
                i = 127;
            } else {
                i = Debug_Rec_Count;
            }
            for (; i > Debug_Rec_Frame; i--) {
                j = i + 1;
                debug_copy_player_snapshot(&dbg_snap_w[0][i], &dbg_snap_w[0][j]);
                debug_copy_player_snapshot(&dbg_snap_w[1][i], &dbg_snap_w[1][j]);
            }
            Debug_Rec_Frame++;
            debug_save_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], &plw[0].wu);
            debug_save_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            if (Debug_Rec_Count + 1 <= 128) {
                Debug_Rec_Count++;
            }
        }
        break;
    }
}



/* provisional name */
void debug_object_edit_snapshot_restore(void) {
    WORK* wk;
    if (Debug_Play_Flag) {
        debug_restore_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], (WORK*)&plw[0]);
        debug_restore_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
        plw[0].wu.old_cgnum = 0;
        debug_char_disp(&plw[0].wu);
        plw[1].wu.old_cgnum = 0;
        debug_char_disp(&plw[1].wu);
        Debug_Snap_Disp = 1;
    } else if (dbg_snap_req) {
        if (Debug_Rec_Count) {
            debug_restore_player_snapshot(&dbg_snap_w[0][Debug_Rec_Frame], (WORK*)&plw[0]);
            debug_restore_player_snapshot(&dbg_snap_w[1][Debug_Rec_Frame], &plw[1].wu);
            plw[0].wu.old_cgnum = 0;
            debug_char_disp(&plw[0].wu);
            plw[1].wu.old_cgnum = 0;
            debug_char_disp(&plw[1].wu);
            Debug_Snap_Disp = 1;
        } else {
            plw[0].wu.old_cgnum = 0;
            debug_char_disp(&plw[0].wu);
            wk = &plw[1].wu;
            wk->old_cgnum = 0;
            debug_char_disp(wk);
            Debug_Snap_Disp = 1;
        }
    } else {
        plw[0].wu.old_cgnum = 0;
        debug_char_disp(&plw[0].wu);
        wk = &plw[1].wu;
        wk->old_cgnum = 0;
        debug_char_disp(wk);
        Debug_Snap_Disp = 0;
    }
}



const char object_edit_msg[12] = "OBJECT EDIT";


const char no_edit_erase_msg[8] = "       ";


const char no_edit_msg[8] = "NO EDIT";


/* provisional name */
void debug_object_edit_all_char_dispatch(void) {
    void (*All_Tbl[2])() = { debug_object_edit_all_char_init, debug_object_edit_all_char_move };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = (DBG_SLOT*)(dbg_slot_w + Debug_PL_id);
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    All_Tbl[Debug_Tool_No]();
    debug_draw_object_info();
    debug_draw_record_info();
}



/* provisional name */
void debug_object_edit_all_char_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(9, 1, 14, object_edit_all_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_edit_num_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_char_slot_init(1);
    debug_both_players_reset();
    dbg_save_mode = 2;
    dbg_rec_menu = 0;
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Edit_Sub = 0;
    Debug_Dec_Disp = 0;
    Debug_Snap_Disp = 0;
    dbg_rec_exist = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    plw[1].wu.old_cgnum = 0;
    plw[1].wu.cg_number = 1;
}



/* provisional name */
void debug_object_edit_all_char_move(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_edit_all_char_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 2:
        if (dbg_slot->sel[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (!dbg_pl->wu.disp_flag) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        debug_pattern_count();
        Debug_Play_Flag = 0;
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        debug_pattern_timer_update();
        if (dbg_slot->sel[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        Debug_Play_Flag = 0;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot->sel[2]++;
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
        dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
        Debug_Play_Flag = 0;
        break;
    case 6:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, no_edit_erase_msg);
        } else {
            tilemap_print_string_attr(30, 1, 6, no_edit_msg);
            break;
        }
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
        dbg_rec_exist = 1;
        dbg_snap_ptr->used++;
        if (dbg_snap_ptr->used > dbg_snap_ptr->cg_ctr) {
            dbg_snap_ptr->used = 1;
            Debug_Rec_Frame++;
            if (Debug_Rec_Frame > Debug_Rec_Count) {
                Debug_Rec_Frame = 1;
            }
        }
        break;
    case 7:
        if (Debug_Rec_Count) {
            tilemap_print_string_attr(30, 1, 14, (char *)&no_edit_erase_msg);
        } else {
            tilemap_print_string_attr(30, 1, 6, (char *)&no_edit_msg);
            break;
        }
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
        dbg_rec_exist = 1;
        dbg_snap_ptr->used = 1;
        Debug_Rec_Frame++;
        if (Debug_Rec_Frame > Debug_Rec_Count) {
            Debug_Rec_Frame = 1;
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 8:
        debug_record_frame_save();
        Debug_Play_Flag = 1;
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    debug_object_edit_snapshot_restore();
    debug_draw_record_ghosts();
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
}



/* provisional name */
void debug_zoom_out_by_dipsw(void) {
    u16 sw = ~dbg_dipsw_1;
    sw &= dbg_dipsw_0;
    sw &= 0xC0;
    switch (sw) {
    case 0x40:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 8, 8);
        break;
    case 0x80:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 16, 16);
        break;
    case 0xC0:
        Zoomf_Init();
        Frame_Down(0xC0, 0xE0, 24, 24);
        break;
    }
    sw = dbg_dipsw_0;
    sw &= 0xC0;
    if (sw == 0) {
        Zoomf_Init();
    }
}



/* provisional name */
void debug_player_color_next(void) {
    u16 sw;
    if (exsw_0 & 0x100) {
        sw = ~dbg_p1sw_1 & dbg_p1sw_0;
        if (sw & BUTTON_START) {
            dbg_col_ix[dbg_pl->wu.id] += 1;
            if (dbg_col_ix[dbg_pl->wu.id] > 12) {
                dbg_col_ix[dbg_pl->wu.id] = 12;
            }
            dbg_pl->wu.my_col_code = dbg_col_code_tbl[dbg_col_ix[dbg_pl->wu.id]];
            load_any_color(dbg_col_no_tbl[dbg_col_ix[dbg_pl->wu.id]]);
        }
    }
}



/* provisional name */
void debug_ghost_shift_left(WORK* wk) {
    u16 sw = exsw_1 & 3;
    switch (sw) {
    case 0:
        wk->position_x -= 104;
        wk->position_y += 96;
        break;
    case 1:
        wk->position_x -= 136;
        wk->position_y += 112;
        break;
    case 2:
        wk->position_x -= 168;
        wk->position_y += 128;
        break;
    case 3:
        wk->position_x -= 200;
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_ghost_shift_right(WORK* wk) {
    u16 sw = exsw_1 & 3;
    switch (sw) {
    case 0:
        wk->position_x += 104;
        wk->position_y += 96;
        break;
    case 1:
        wk->position_x += 136;
        wk->position_y += 112;
        break;
    case 2:
        wk->position_x += 168;
        wk->position_y += 128;
        break;
    case 3:
        wk->position_x += 200;
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_ghost_shift_up(WORK* wk) {
    u16 sw = exsw_1 & 6;
    switch (sw) {
    case 0:
        wk->position_y += 96;
        break;
    case 2:
        wk->position_y += 112;
        break;
    case 4:
        wk->position_y += 128;
        break;
    case 6:
        wk->position_y += 136;
        break;
    }
}



/* provisional name */
void debug_draw_record_ghosts(void) {
    u16 sw = exsw_1 & 1;
    s16 i;
    WORK_Other* ewk;
    if (sw == 0) {
        return;
    }
    if (!Debug_Rec_Count) {
        return;
    } else {
        if (dbg_save_mode) {
            if (Debug_Rec_Frame > 0) {
                for (i = 0; i < 2; i++) {
                    ewk = dbg_ghost_ewk[i][0];
                    debug_snapshot_to_ghost((WORK*)ewk, &dbg_snap_w[i][Debug_Rec_Frame]);
                    ewk->wu.my_priority += 4;
                    ewk->wu.position_z = ewk->wu.my_priority;
                    debug_ghost_shift_left(&ewk->wu);
                    ewk->wu.old_cgnum = 0;
                    debug_char_disp_once(&ewk->wu);
                }
            }
            if (Debug_Rec_Frame < Debug_Rec_Count) {
                for (i = 0; i < 2; i++) {
                    ewk = dbg_ghost_ewk[i][2];
                    debug_snapshot_to_ghost((WORK*)ewk, &dbg_snap_w[i][Debug_Rec_Frame + 1]);
                    ewk->wu.my_priority += 4;
                    ewk->wu.position_z = ewk->wu.my_priority;
                    debug_ghost_shift_right(&ewk->wu);
                    ewk->wu.old_cgnum = 0;
                    debug_char_disp_once(&ewk->wu);
                }
            }
        } else {
            if (Debug_Rec_Frame > 1) {
                for (i = 0; i < 2; i++) {
                    ewk = dbg_ghost_ewk[i][0];
                    debug_snapshot_to_ghost((WORK*)ewk, &dbg_snap_w[i][Debug_Rec_Frame - 1]);
                    ewk->wu.my_priority += 4;
                    ewk->wu.position_z = ewk->wu.my_priority;
                    debug_ghost_shift_left(&ewk->wu);
                    ewk->wu.old_cgnum = 0;
                    debug_char_disp_once(&ewk->wu);
                }
            }
            for (i = 0; i < 2; i++) {
                ewk = dbg_ghost_ewk[i][1];
                debug_snapshot_to_ghost((WORK*)ewk, &dbg_snap_w[i][Debug_Rec_Frame]);
                ewk->wu.my_priority += 2;
                ewk->wu.position_z = ewk->wu.my_priority;
                debug_ghost_shift_up(&ewk->wu);
                ewk->wu.old_cgnum = 0;
                debug_char_disp_once(&ewk->wu);
            }
            if (Debug_Rec_Frame < Debug_Rec_Count) {
                for (i = 0; i < 2; i++) {
                    ewk = dbg_ghost_ewk[i][2];
                    debug_snapshot_to_ghost((WORK*)ewk, &dbg_snap_w[i][Debug_Rec_Frame + 1]);
                    ewk->wu.my_priority += 4;
                    ewk->wu.position_z = ewk->wu.my_priority;
                    debug_ghost_shift_right(&ewk->wu);
                    ewk->wu.old_cgnum = 0;
                    debug_char_disp_once(&ewk->wu);
                }
            }
        }
    }
}



const char object_edit_all_msg[32] = "OBJECT EDIT  -ALL CHAR VERSION-";


/* provisional name */
void debug_hit_judgment_dispatch(void) {
    void (*Hit_Tbl[6])() = { debug_hit_judgment_init, debug_hit_judgment_move, debug_hit_a_judgement_init, debug_hit_a_judgement_run, debug_hit_a_exit_confirm, debug_hit_judgment_redraw };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = (DBG_SLOT*)(dbg_slot_w + Debug_PL_id);
    dbg_judge_ewk = (WORK_Other_JUDGE*)&frw[dbg_judge_eff_ix][0];
    Hit_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_hit_judgment_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, hit_judgment_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_hit_size_str);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hit_part_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_clear_rgb_triplet_table();
    Debug_PL_id = 0;
    Debug_Hit_Sub = 0;
    Debug_Box_Edit = 0;
    dbg_copy_done = 0;
    Debug_Snap_Disp = 0;
    dbg_cmd_panel = 0;
    Debug_Dec_Disp = 0;
    debug_both_players_reset();
    debug_slot_char_load();
    debug_motion_list_count();
    plw[1].wu.rl_flag = 1;
    dbg_look_buf.judge = dbg_look_judge;
    dbg_look_buf.body_adrs = dbg_look_buf.h_bod = (BODY_BOX*)dbg_look_body;
    dbg_look_buf.hand_adrs = dbg_look_buf.h_han = (HAND_BOX*)dbg_look_hand;
    dbg_look_buf.catch_adrs = dbg_look_buf.h_cat = dbg_look_catch;
    dbg_look_buf.caught_adrs = dbg_look_buf.h_cau = dbg_look_caught;
    dbg_look_buf.attack_adrs = dbg_look_buf.h_att = (ATTACK_BOX*)dbg_look_attack;
    dbg_look_buf.hosei_adrs = dbg_look_buf.h_hos = dbg_look_hosei;
    dbg_copy_buf.judge = dbg_copy_judge;
    dbg_copy_buf.body_adrs = dbg_copy_buf.h_bod = dbg_copy_body;
    dbg_copy_buf.hand_adrs = dbg_copy_buf.h_han = dbg_copy_hand;
    dbg_copy_buf.catch_adrs = dbg_copy_buf.h_cat = dbg_copy_catch;
    dbg_copy_buf.caught_adrs = dbg_copy_buf.h_cau = dbg_copy_caught;
    dbg_copy_buf.attack_adrs = dbg_copy_buf.h_att = dbg_copy_attack;
    dbg_copy_buf.hosei_adrs = dbg_copy_buf.h_hos = dbg_copy_hosei;
    dbg_edit_buf.judge = dbg_edit_judge;
    dbg_edit_buf.body_adrs = dbg_edit_buf.h_bod = dbg_edit_body;
    dbg_edit_buf.hand_adrs = dbg_edit_buf.h_han = dbg_edit_hand;
    dbg_edit_buf.catch_adrs = dbg_edit_buf.h_cat = dbg_edit_catch;
    dbg_edit_buf.caught_adrs = dbg_edit_buf.h_cau = dbg_edit_caught;
    dbg_edit_buf.attack_adrs = dbg_edit_buf.h_att = dbg_edit_attack;
    dbg_edit_buf.hosei_adrs = dbg_edit_buf.h_hos = dbg_edit_hosei;
    dbg_pl = &plw[1];
    dbg_slot = (DBG_SLOT*)&dbg_slot_w[1];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)&dbg_slot_w[0];
    debug_set_all_boxes(0);
    debug_pattern_list_build();
    debug_edit_pattern_timer_update();
    dbg_judge_ewk->curr_ja = 0;
    dbg_judge_ewk->look_up_flag = 0;
    dbg_edit_box = (s16*)dbg_look_buf.h_bod;
    dbg_col_no = 0;
    dbg_bgcol_ix = 0;
}



/* provisional name */
void debug_hit_judgment_move(void) {
    WORK* wk;
    Debug_Command = 0;
    debug_hit_judgment_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load_keep_col();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        if (Debug_PL_id) {
            debug_pattern_timer_update();
            debug_pattern_count();
        } else {
            debug_pattern_list_build();
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(1);
        }
        break;
    case 2:
        if (dbg_slot->sel[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        if (Debug_PL_id) {
            debug_pattern_count();
            debug_pattern_timer_update();
        } else {
            debug_pattern_list_build();
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(1);
        }
        break;
    case 4:
        if (Debug_PL_id) {
            char_move(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
        } else {
            debug_pattern_preview_step(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(dbg_slot->sel[2]);
        }
        break;
    case 5:
        if (Debug_PL_id) {
            char_move_z(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
        } else {
            wk = &dbg_pl->wu;
            dbg_pl->wu.cg_ctr = 1;
            debug_pattern_preview_step(wk);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_edit_pattern_timer_update();
            debug_set_all_boxes(dbg_slot->sel[2]);
        }
        break;
    }
    wk = &plw[0].wu;
    goto disp;
disp:
    debug_char_disp(wk);
    debug_char_disp(&plw[1].wu);
    debug_bg_color_preset_next();
    debug_rgb_editor_print(0);
    debug_draw_object_info();
    debug_draw_hit_edit_info();
    if (~dbg_p1sw_1 & dbg_p1sw_0 & BUTTON_HK) {
        if (dbg_slot->sel[0] <= 0xD8) {
            Debug_Tool_No = 2;
        }
    }
}



/* provisional name */
void debug_hit_a_judgement_init(void) {
    s16 i;
    Debug_Tool_No = 3;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 2, hit_a_judgement_msg);
    tilemap_print_string_attr(2, 1, 10, hit_tbl_label_msg);
    tilemap_print_string_attr(2, 3, 10, pattern_label_msg);
    dbg_hita_num = 0;
    for (i = 0; i < 7; i++) {
        if (debug_hit_a_judgement_alloc_slot(&dbg_hita_ewk[i]) == -1) {
            goto fail;
        }
        dbg_hita_num++;
    }
    debug_hit_a_judgement_build_table();
    debug_clear_rgb_triplet_table();
    return;
fail:
    Debug_Tool_No = 4;
}



/* provisional name */
void debug_hit_a_judgement_build_table(void) {
    WORK_Other** ewk;
    WORK* wk;
    u32 work_base;
    WORK_Other* slot;
    u32* dst;
    u32* src;
    HITA_PAT* pat;
    HITA_BOX* body;
    HITA_BOX* hand;
    HITA_BOX* att;
    HITA_KEY* keys;
    u32* ixkey;
    HITA_IX* ixtbl;
    HITA_KEY t;
    s16 i;
    s16 j;
    s16 n;
    ewk = dbg_hita_ewk;
    work_base = (u32)ewk;
    wk = &((WORK_Other**)work_base)[0]->wu;
    plw[0].wu.before = wk->before;
    plw[0].wu.myself = wk->myself;
    plw[0].wu.behind = wk->behind;
    plw[0].wu.listix = wk->listix;
    plw[0].wu.dead_f = wk->dead_f;
    plw[0].wu.timing = wk->timing;
    src = (u32*)&plw[0];
    (void)&((WORK*)src)->disp_flag;
    dst = (u32*)((WORK_Other**)work_base)[0];
    for (i = 0; i < 512; i++) {
        *dst++ = *src++;
    }
    plw[0].wu.xyz[0].disp.pos += 0x180;
    plw[0].wu.position_x += 0x180;
    plw[1].wu.xyz[0].disp.pos += 0x180;
    plw[1].wu.position_x += 0x180;
    wk->hit_adrs = plw[0].wu.set_char_ad;
    wk->dmg_adrs = (u32*)plw[0].wu.hit_ix_table;
    slot = ewk[1];
    slot->wu.routine_no[4] = 4;
    pat = (HITA_PAT*)slot->wu.old_rno;
    wk->set_char_ad = (u32*)pat;
    wk->cg_ix = 0;
    wk->cgd_type = 4;
    wk->dmcal_m = dbg_slot->rec_count;
    for (i = 0; i < wk->dmcal_m; i = i + 1) {
        pat[i].frames = dbg_look_buf.rec[i + 1].u.frames;
        pat[i].param = dbg_look_buf.rec[i + 1].param;
    }
    pat[i].frames = 0;
    pat[i].kind = 2;
    pat[i].param = 1;
    wk->cg_ctr = pat[0].frames;
    body = (HITA_BOX*)ewk[3]->wu.old_rno;
    wk->body_adrs = (BODY_BOX*)body;
    hand = (HITA_BOX*)((u8*)(ewk[4]) + 0x34);
    wk->hand_adrs = (HAND_BOX*)hand;
    wk->catch_adrs = (CATCH_BOX*)hand;
    wk->caught_adrs = (CAUGHT_BOX*)hand;
    wk->hosei_adrs = (HOSEI_BOX*)hand;
    att = (HITA_BOX*)((u8*)(ewk[5]) + 0x34);
    wk->attack_adrs = (ATTACK_BOX*)att;
    slot = ewk[6];
    keys = (HITA_KEY*)slot->wu.old_rno;
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (debug_memcmp_u32((u32*)&body[j], (u32*)&dbg_look_body[i], 8)) {
                keys[i].ix[0] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            body[n] = dbg_look_body[i];
            keys[i].ix[0] = n;
        }
    }
    wk->vitality = n;
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i++) {
        for (j = n; j >= 0; j--) {
            if (debug_memcmp_u32((u32*)&hand[j], (u32*)&dbg_look_hand[i], 8)) {
                keys[i].ix[1] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            hand[n] = dbg_look_hand[i];
            keys[i].ix[1] = n;
        }
    }
    wk->vital_new = n;
    n = 0;
    for (i = 1; i <= wk->dmcal_m; i = i + 1) {
        for (j = n; j >= 0; j = j - 1) {
            if (debug_memcmp_u32((u32*)&att[j], (u32*)&dbg_look_attack[i], 8)) {
                keys[i].ix[2] = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            att[n] = dbg_look_attack[i];
            keys[i].ix[2] = n;
        }
    }
    wk->vital_old = n;
    n = 0;
    slot = ewk[2];
    ixkey = (u32*)slot->wu.old_rno;
    for (i = 1; i <= wk->dmcal_m; i = i + 1) {
        for (j = n; j >= 0; j--) {
            if (keys[i].key == ixkey[j * 4]) {
                pat[i - 1].bits = j;
                break;
            }
        }
        if (j == -1) {
            n++;
            ((HITA_KEY*)&ixkey[n * 4])->key = keys[i].key;
            pat[i - 1].bits = n;
        }
    }
    for (i = 0; i < wk->dmcal_m; i = i + 1) {
        pat[i].bits <<= 13;
    }
    ixtbl = (HITA_IX*)ixkey;
    wk->hit_ix_table = (HIT_IX*)ixtbl;
    for (i = 1; i <= n; i++) {
        t.key = ((HITA_KEY*)ixkey)[i * 4].key;
        ixtbl[i].body = t.ix[0];
        ixtbl[i].hand = t.ix[1];
        ixtbl[i].attack = t.ix[2];
        ixtbl[i].w2 = 0;
        ixtbl[i].w8 = 0;
        ixtbl[i].w10 = 0;
        ixtbl[i].w14 = 0;
        ixtbl[i].k.both = 0;
    }
    wk->dmcal_d = n;
    wk->old_cgnum = 0;
    wk->spr.gfx_ofs = 0;
    wk->spr.gfx_cells = 0;
    for (i = 0; i < 4; i = i + 1) {
        wk->spr.gfx_blk10[i] = 0;
        wk->spr.gfx_blk40[i] = 0;
        wk->spr.gfx_blk_ex[i] = 0;
    }
    effect_K5_init((PLW*)wk);
    effect_00_init(wk);
    wk->cg_ix = -wk->cgd_type;
    wk->cg_ctr = 1;
    wk->cg_next_ix = 0;
    wk->old_cgnum = 0;
    wk->cg_wca_ix = 0;
    wk->K5_init_flag = 1;
    char_move(wk);
    wk->dir_timer = 0;
    wk->dir_step = 0;
    dbg_hita_grid_sw = 0;
    if (DEBUG_EDIT) {
        effect_K5_init((PLW*)wk);
    }
    if (DEBUG_EDIT) {
        wk->cg_ctr = 1;
    }
}



/* provisional name */
s32 debug_memcmp_u32(u32* a, u32* b, s16 n) {
    s16 i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            break;
        }
    }
    return i == n;
}

/* provisional name */
u32 debug_hit_a_judgement_alloc_slot(WORK_Other **slot)
{
    s16 ix;
    u8 *ewk;

    if ((ix = pull_effect_work(7)) == -1) {
        return 0xFFFFFFFF;
    }
    ewk = (u8 *)&frw[ix];
    *(u8 *)&frw[ix] = 1;
    *slot = (WORK_Other *)ewk;
    return 0;
}



/* provisional name */
void debug_hit_a_judgement_cleanup(void) {
    s16 i;
    plw[0].wu.dead_f = plw[0].wu.timing = plw[0].wu.behind = plw[0].wu.listix = plw[0].wu.before = plw[0].wu.myself = 0;
    for (i = 0; i < dbg_hita_num; i++) {
        if (i == 0) {
            all_cgps_put_back(dbg_hita_ewk[i]);
        }
        push_effect_work(&dbg_hita_ewk[i]->wu);
    }
}



/* provisional name */
void debug_hit_a_judgement_run(void) {
    WORK* wk = &dbg_hita_ewk[0]->wu;
    u16 sw1;
    u16 sw2;
    s16 group;
    wk->dir_timer++;
    sw1 = ~dbg_p1sw_1 & dbg_p1sw_0;
    sw2 = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw1 & BUTTON_MP) {
        char_move_z(wk);
    } else {
        switch (dbg_p1sw_0 & BUTTON_PUNCHES) {
        case 0x10:
            char_move(wk);
            break;
        case 0x30:
            if (!(wk->dir_timer & 1)) {
                char_move(wk);
            }
            break;
        case 0x20:
            if (!(wk->dir_timer & 3)) {
                char_move(wk);
            }
            break;
        case 0x60:
            if (!(wk->dir_timer & 7)) {
                char_move(wk);
            }
            break;
        case 0x40:
            if (!(wk->dir_timer & 0xF)) {
                char_move(wk);
            }
            break;
        }
    }
    if (sw2 & BUTTON_LK) {
        dbg_hita_grid_sw = (dbg_hita_grid_sw + 1) & 1;
    }
    debug_hit_a_judgement_navigate_xy(wk);
    if (debug_hit_a_judgement_column_nav(wk)) {
        wk->cg_ix -= wk->cgd_type;
        char_move_z(wk);
        debug_hit_a_judgement_print_footer();
    } else if (debug_hit_a_judgement_edit_grid(wk)) {
        wk->cg_ix -= wk->cgd_type;
        char_move_z(wk);
    }
    debug_hit_a_draw_cursor(wk->dir_step, wk->dir_timer);
    debug_hit_a_print_pattern_rows(wk, (GRID_REC*)(HITA_PAT*)wk->set_char_ad);
    debug_hit_a_print_hit_ix_rows(wk, (GRID9_REC*)(HITA_IX*)wk->hit_ix_table);
    debug_hit_a_print_counts(wk);
    debug_hit_a_print_box_values(wk);
    group = debug_cg_group_index(wk->cg_number);
    debug_draw_cg_group(wk->cg_number, group, 2, 25, 4);
    debug_draw_cg_group_offset(wk->cg_number, group, 8, 25, 4);
    if (sw1 & BUTTON_HK) {
        Debug_Tool_No = 4;
        tilemap_print_string(0, 0, 0xFFFF, dbg_blank4_str);
        tilemap_print_string(0, 0, 0xFFFF, dbg_exit_ok_str);
    }
    debug_rgb_editor_navigate(2);
    debug_rgb_editor_print(0);
    debug_char_disp(wk);
}



/* provisional name */
void debug_hit_a_judgement_navigate_xy(WORK* wk) {
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        wk->xyz[1].disp.pos++;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        wk->xyz[1].disp.pos--;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        wk->xyz[0].disp.pos--;
    }
    if (debug_held_pad_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        wk->xyz[0].disp.pos++;
    }
}



/* provisional name */
s32 debug_hit_a_judgement_edit_grid(WORK* wk) {
    HITA_IX* ixtbl = (HITA_IX*)wk->hit_ix_table;
    HITA_PAT* pat = (HITA_PAT*)wk->set_char_ad;
    s16 ix = wk->cg_ix / wk->cgd_type;
    s16 page = pat[ix].bits >> 13;
    s16 min = 0;
    s16 hit = page;
    HITA_IX* h = &ixtbl[hit];
    s16 step;
    s16 i;
    s32 sw;
    if ((step = debug_hit_a_judgement_held_step()) != 0) {
        switch (judge_column_tbl[wk->dir_step].rest[0]) {
        case 0:
            step += pat[ix].frames;
            if (step < 1) {
                step = 1;
            }
            if (step > 250) {
                step = 250;
            }
            pat[ix].frames = step;
            break;
        case 1:
            step += pat[ix].bits >> 13;
            if (step < min) {
                step = min;
            }
            if (step > wk->dmcal_d) {
                step = wk->dmcal_d;
            }
            pat[ix].bits = step << 13;
            break;
        case 2:
            step += h->body;
            if (step < min) {
                step = min;
            }
            if (step > wk->vitality) {
                step = wk->vitality;
            }
            h->body = step;
            break;
        case 3:
            step += h->hand;
            if (step < min) {
                step = min;
            }
            if (step > wk->vital_new) {
                step = wk->vital_new;
            }
            h->hand = step;
            break;
        case 4:
            if (step > 0) {
                h->k.kind[0] = hit_kind_tbl[h->k.kind[0]].held_up;
            } else {
                h->k.kind[0] = hit_kind_tbl[h->k.kind[0]].held_down;
            }
            break;
        case 5:
            if (step > 0) {
                h->k.kind[1] = hit_kind_tbl[h->k.kind[1]].held_up;
            } else {
                h->k.kind[1] = hit_kind_tbl[h->k.kind[1]].held_down;
            }
            break;
        case 6:
            step += h->attack;
            if (step < min) {
                step = min;
            }
            if (step > wk->vital_old) {
                step = wk->vital_old;
            }
            h->attack = step;
            break;
        }
        return 1;
    }
    if ((step = debug_hit_a_judgement_edit_step()) != 0) {
        switch (judge_column_tbl[wk->dir_step].rest[0]) {
        case 0:
            step = step + pat[ix].frames;
            if (step < 1) {
                step = 1;
            }
            if (step > 250) {
                step = 250;
            }
            pat[ix].frames = step;
            break;
        case 1:
            step = step + (pat[ix].bits >> 13);
            if (step < min) {
                step = min;
            }
            if (step > wk->dmcal_d) {
                step = wk->dmcal_d;
            }
            pat[ix].bits = step << 13;
            break;
        case 2:
            step = step + h->body;
            if (step < min) {
                step = min;
            }
            if (step > wk->vitality) {
                step = wk->vitality;
            }
            h->body = step;
            break;
        case 3:
            step = step + h->hand;
            if (step < min) {
                step = min;
            }
            if (step > wk->vital_new) {
                step = wk->vital_new;
            }
            h->hand = step;
            break;
        case 4:
            if (step > 0) {
                h->k.kind[0] = hit_kind_tbl[h->k.kind[0]].up;
            } else {
                h->k.kind[0] = hit_kind_tbl[h->k.kind[0]].down;
            }
            break;
        case 5:
            if (step > 0) {
                h->k.kind[1] = hit_kind_tbl[h->k.kind[1]].up;
            } else {
                h->k.kind[1] = hit_kind_tbl[h->k.kind[1]].down;
            }
            break;
        case 6:
            step = step + h->attack;
            if (step < min) {
                step = min;
            }
            if (step > wk->vital_old) {
                step = wk->vital_old;
            }
            h->attack = step;
            break;
        }
        return 1;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & BUTTON_LK) {
        goto add;
    add:
        if (wk->dir_step < 2) {
            if (wk->dmcal_m > 95) {
                goto none;
            }
            wk->dmcal_m++;
            for (i = wk->dmcal_m + 1; i > ix; i--) {
                pat[i] = pat[i - 1];
            }
        } else {
            if (wk->dmcal_d > 95) {
                goto none;
            }
            wk->dmcal_d++;
            ixtbl[wk->dmcal_d] = *h;
        }
        return 1;
    }
    if (!(sw & BUTTON_MK)) {
        goto none;
    }
    if (wk->dir_step < 2) {
        if (wk->dmcal_m < 2) {
            goto none;
        }
        for (i = ix; i < wk->dmcal_m; i++) {
            pat[i] = pat[i + 1];
        }
        wk->dmcal_m--;
    } else {
        *h = ixtbl[0];
    }
    return 1;
none:
    return 0;
}



/* provisional name */
s32 debug_hit_a_judgement_held_step(void) {
    if (!(dbg_p2sw_0 & BUTTON_LP)) {
        return 0;
    }
    if (debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        return -1;
    }
    if (debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 debug_hit_a_judgement_edit_step(void) {
    u16 sw;
    if (dbg_p2sw_0 & BUTTON_LP) {
        return 0;
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw & BUTTON_MP) {
        return 1;
    }
    if (sw & BUTTON_HP) {
        return -1;
    }
    return 0;
}



/* Hit-box editor: moves through the judgement columns; returns 1 when the selection changed. */
/* provisional name */
s32 debug_hit_a_judgement_column_nav(WORK* wk) {
    u32* tbl = wk->set_char_ad;
    s16 ix = wk->cg_ix / wk->cgd_type;
    s16 page = tbl[ix * 4 + 2] >> 13;
    s16 dir;
    s16 i;
    u32 target;
    s16 ret;
    const JUDGE_COLUMN (*col)[7];
    if (dbg_p2sw_0 & BUTTON_PUNCHES) {
        return 0;
    }
    dir = debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4) + debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5) * 2 + debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6) * 4 + debug_held_pad_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7) * 8;
    col = &judge_column_tbl;
    ret = 0;
    if (DEBUG_EDIT) {
        ret = 1;
        wk->dir_step = (*col)[wk->dir_step].rest[4];
    }
    switch (dir) {
    case 1:
        if (wk->dir_step < 2) {
            if (ix == 0) {
                wk->cg_ix = (wk->dmcal_m - 1) * wk->cgd_type;
            } else {
                wk->cg_ix -= wk->cgd_type;
            }
        } else {
            if (page == 0) {
                break;
            }
            for (target = (page - 1) << 13, i = 0; i < wk->dmcal_m; i++) {
                if (tbl[i * 4 + 2] == target) {
                    break;
                }
            }
            if (i != wk->dmcal_m) {
                wk->cg_ix = i * wk->cgd_type;
            }
        }
        ret = 1;
        break;
    case 2:
        if (wk->dir_step < 2) {
            wk->cg_ix += wk->cgd_type;
        } else {
            if (page == wk->dmcal_d) {
                break;
            }
            for (target = (page + 1) << 13, i = 0; i < wk->dmcal_m; i++) {
                if (DEBUG_EDIT) {
                    return 0;
                }
                if (tbl[i * 4 + 2] == target) {
                    break;
                }
            }
            if (i != wk->dmcal_m) {
                wk->cg_ix = i * wk->cgd_type;
            }
        }
        ret = 1;
        break;
    case 4:
        wk->dir_step = (*col)[wk->dir_step].rest[3];
        ret = 1;
        break;
    case 8:
        ret = 1;
        wk->dir_step = (*col)[wk->dir_step].rest[4];
        break;
    }
    return ret;
}



/* provisional name */
void debug_hit_a_judgement_print_footer(void) {
    tilemap_print_string_attr(3, 15, 0, debug_blank6_msg);
    tilemap_print_string_attr(29, 15, 0, debug_blank18_msg);
}



/* provisional name */
void debug_hit_a_draw_cursor(s16 col, s16 flags) {
    tilemap_print_string_attr(judge_column_tbl[col].x, judge_column_tbl[col].y, 4, dbg_sign_str[(flags & 0x20) == 0]);
}



/* provisional name */
void debug_hit_a_print_counts(WORK* wk) {
    tilemap_print_string_attr(10, 1, 10, debug_zero2_msg);
    tilemap_print_hex(10, 1, 10, remake_2_10(wk->dmcal_d, 2), 2, 2);
    tilemap_print_string_attr(10, 3, 10, debug_zero2_msg);
    tilemap_print_hex(10, 3, 10, remake_2_10(wk->dmcal_m, 2), 2, 2);
    tilemap_print_string_attr(13, 3, 10, debug_zero2_msg);
    tilemap_print_hex(13, 3, 10, remake_2_10(wk->cg_ix / wk->cgd_type + 1, 2), 2, 2);
}



/* provisional name */
void debug_hit_a_print_pattern_rows(WORK* wk, GRID_REC* recs) {
    s16 i;
    s16 ix;
    s16 attr;
    s16 v;
    const GRID_POS* hit;
    ix = wk->cg_ix / wk->cgd_type - 4;
    goto rows;
    if (DEBUG_DISP) {
        tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_empty_row_msg);
        tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_row_frame_msg);
        tilemap_print_string_attr(hit_grid5_pos_tbl[i].x, hit_grid5_pos_tbl[i].y, attr, debug_blank3_msg);
    }
rows:;
    if (DEBUG_DISP) {
        attr = 14;
    }
    for (i = 0; i < 9; ix = ix + 1, i++) {
        if (ix < 0 || ix >= wk->dmcal_m) {
            tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_empty_row_msg);
        } else {
            attr = 14;
            if (i == 4) {
                attr = 4;
            }
            tilemap_print_string_attr(2, hit_grid5_pos_tbl[i].y, 0, grid_row_frame_msg);
            v = recs[ix].frames;
            tilemap_print_string_attr(hit_grid5_pos_tbl[i].x, hit_grid5_pos_tbl[i].y, attr, debug_blank3_msg);
            tilemap_print_hex(hit_grid5_pos_tbl[i].x, hit_grid5_pos_tbl[i].y, attr, remake_2_10(v, 3), 3, 2);
            v = recs[ix].bits >> 13;
            tilemap_print_string_attr(hit_grid5_pos_tbl[i].hit->x,
                                      (hit = hit_grid5_pos_tbl[i].hit)->y, attr, debug_zero2_msg);
            tilemap_print_hex(hit->x, hit->y, attr, remake_2_10(v, 2), 2, 2);
        }
    }
    if (DEBUG_DISP) {
        attr = 4;
    }
}



/* provisional name */
void debug_hit_a_print_hit_ix_rows(WORK* wk, GRID9_REC* recs) {
    s16 i;
    s16 ix;
    u16 attr;
    ix = wk->cg_hit_ix;
    ix -= 3;
    for (i = 0; i < 7; ix++, i++) {
        if (ix < 0 || ix > wk->dmcal_d) {
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y + 0xFFFF, 0, grid9_empty_box_msg);
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y, 0, dbg_hit_row_empty_str);
        } else {
            attr = 14;
            if (i == 3) {
                attr = 4;
            }
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y + 0xFFFF, 0, dbg_hit_row_ix_str);
            tilemap_print_string_attr(31, hit_grid9_pos_tbl[i].y, 0, dbg_hit_row_blank_str);
            tilemap_print_string_attr(38, hit_grid9_pos_tbl[i].y, attr, dbg_hit_row_mb_str);
            tilemap_print_string_attr(32, hit_grid9_pos_tbl[i].y + 0xFFFF, attr, debug_zero2_msg);
            tilemap_print_hex(32, hit_grid9_pos_tbl[i].y + 0xFFFF, attr, remake_2_10(ix, 2), 2, 2);
            tilemap_print_string_attr(32, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(32, hit_grid9_pos_tbl[i].y, attr, remake_2_10(recs[ix].w0, 2), 2, 2);
            tilemap_print_string_attr(35, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(35, hit_grid9_pos_tbl[i].y, attr, remake_2_10(recs[ix].w4, 2), 2, 2);
            tilemap_print_string_attr(39, hit_grid9_pos_tbl[i].y, attr, hit_kind_tbl[recs[ix].kind6].name);
            tilemap_print_string_attr(42, hit_grid9_pos_tbl[i].y, attr, hit_kind_tbl[recs[ix].kind7].name);
            tilemap_print_string_attr(45, hit_grid9_pos_tbl[i].y, attr, dbg_space2_str);
            tilemap_print_hex(45, hit_grid9_pos_tbl[i].y, attr, remake_2_10(recs[ix].w12, 2), 2, 2);
        }
    }
}



/* provisional name */
void debug_hit_a_print_box_values(WORK* wk) {
    BODY_BOX* box;
    s16 i;
    s16 v;
    if (dbg_hita_grid_sw != 0 && wk->dir_step >= 2 && wk->dir_step != 4 && wk->dir_step != 5) {
        switch (wk->dir_step) {
        case 2:
            box = wk->h_bod;
            break;
        case 3:
            box = (BODY_BOX*)wk->h_han;
            break;
        default:
            box = (BODY_BOX*)wk->h_att;
            break;
        }
        for (i = 0; i < 4; i++) {
            tilemap_print_string_attr(11, i + 5, 2, dbg_hitbox_row_str);
            if ((v = box->body_dm[i][0]) < 0) {
                tilemap_print_string_attr(11, i + 5, 2, dbg_minus_str);
                v = -v;
            }
            tilemap_print_hex(12, i + 5, 2, v, 3, 0);
            tilemap_print_hex(16, i + 5, 2, box->body_dm[i][1], 3, 0);
            if ((v = box->body_dm[i][2]) < 0) {
                tilemap_print_string_attr(20, i + 5, 2, dbg_minus_str);
                v = -v;
            }
            tilemap_print_hex(21, i + 5, 2, v, 3, 0);
            tilemap_print_hex(25, i + 5, 2, box->body_dm[i][3], 3, 0);
        }
        return;
    }
    tilemap_print_string(0, 0, 0xFFFF, dbg_blank4_str);
}



/* provisional name */
void debug_hit_a_exit_confirm(void) {
    s16 sw1 = ~dbg_p1sw_1 & dbg_p1sw_0 & BUTTON_SHOTS;
    s16 sw2 = ~dbg_p2sw_1 & dbg_p2sw_0 & BUTTON_SHOTS;
    if (dbg_hita_num < 7) {
        tilemap_print_string(0, 0, 0xFFFF, dbg_work_empty_str);
        if (sw1 + sw2) {
            if (dbg_hita_num) {
                debug_hit_a_judgement_cleanup();
            }
            Debug_Tool_No = 5;
        }
        return;
    } else {
        if (sw2 & BUTTON_HK) {
            plw[0].wu.xyz[0].disp.pos -= 0x180;
            plw[0].wu.position_x -= 0x180;
            plw[1].wu.xyz[0].disp.pos -= 0x180;
            plw[1].wu.position_x -= 0x180;
            debug_hit_a_judgement_cleanup();
            Debug_Tool_No = 5;
            return;
        }
        if (sw1 & BUTTON_HK) {
            Debug_Tool_No = 3;
            tilemap_print_string(0, 0, 0xFFFF, dbg_blank4_str);
        }
        debug_char_disp(&dbg_hita_ewk[0]->wu);
    }
}



/* provisional name */
void debug_hit_judgment_redraw(void) {
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, hit_judgment_msg);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_hit_size_str);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hit_part_str);
    Debug_Tool_No = 1;
}



/* provisional name */
void debug_clear_rgb_triplet_table(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        Debug_RGB[i] = 0;
    }
}



/* provisional name */
void debug_rgb_editor_navigate(s16 mode) {
    u16 sw;
    s16 i;
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (mode != 1) {
        if (mode == 2) {
            if (dbg_p2sw_0 & BUTTON_HK) {
                for (i = 0; i < 3; i++) {
                    Debug_RGB[i]++;
                }
            }
            if (sw & BUTTON_HK) {
                for (i = 0; i < 3; i++) {
                    Debug_RGB[i] += 3;
                }
            }
            goto mask;
        }
        if (dbg_p2sw_0 & BUTTON_LP) {
            Debug_RGB[0]--;
            if (sw & BUTTON_LP) {
                Debug_RGB[0] -= 3;
            }
        }
        if (dbg_p2sw_0 & BUTTON_MP) {
            Debug_RGB[1]--;
            if (sw & BUTTON_MP) {
                Debug_RGB[1] -= 3;
            }
        }
        if (dbg_p2sw_0 & BUTTON_HP) {
            Debug_RGB[2]--;
            if (sw & BUTTON_HP) {
                Debug_RGB[2] -= 3;
            }
        }
    }
    if (dbg_p2sw_0 & BUTTON_LK) {
        Debug_RGB[0]++;
        if (sw & BUTTON_LK) {
            Debug_RGB[0] += 3;
        }
    }
    if (dbg_p2sw_0 & BUTTON_MK) {
        Debug_RGB[1]++;
        if (sw & BUTTON_MK) {
            Debug_RGB[1] += 3;
        }
    }
    if (dbg_p2sw_0 & BUTTON_HK) {
        Debug_RGB[2]++;
        if (sw & BUTTON_HK) {
            Debug_RGB[2] += 3;
        }
    }
mask:
    Debug_RGB[0] &= 0x7F;
    Debug_RGB[1] &= 0x7F;
    Debug_RGB[2] &= 0x7F;
}



/* provisional name */
void debug_bg_color_preset_next(void) {
    u16 sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & BUTTON_HP) {
        dbg_bgcol_ix++;
        dbg_bgcol_ix &= 7;
    }
    Debug_RGB[0] = dbg_rgb_preset_tbl[dbg_bgcol_ix][0];
    Debug_RGB[1] = dbg_rgb_preset_tbl[dbg_bgcol_ix][1];
    Debug_RGB[2] = dbg_rgb_preset_tbl[dbg_bgcol_ix][2];
}



/* provisional name */
void debug_rgb_editor_print(s16 print) {
    u16 r, g, b;
    s32 green, blue;
    s32 word;
    s32 part;
    (void)plw[print && print && print && print && print && print && print && 0].wu.id;
    r = Debug_RGB[0] >> 2;
    g = Debug_RGB[1] >> 2;
    b = Debug_RGB[2] >> 2;
    r &= 0x1F;
    g &= 0x1F;
    b &= 0x1F;
    green = g;
    blue = b;
    if (print) {
        tilemap_print_hex(13, 12, 2, r, 2, 0);
        tilemap_print_hex(13, 13, 2, green, 2, 0);
        tilemap_print_hex(13, 14, 2, blue, 2, 0);
    }
    part = green << 5;
    word = blue << 10;
    *(u16*)COLOR_RAM = (word | part | r) & 0x7FFF;
}



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


/* provisional name */
void debug_catch_judgment_dispatch(void) {
    void (*Catch_Tbl[2])() = { debug_catch_judgment_init, debug_catch_judgment_run };
    dbg_pl = &plw[Debug_PL_id];
    dbg_slot = (DBG_SLOT*)(dbg_slot_w + Debug_PL_id);
    Catch_Tbl[Debug_Tool_No]();
    if (!Debug_PL_id) {
        dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    }
    debug_draw_object_info();
    debug_draw_position_delta();
    debug_draw_edit_side();
    debug_draw_cm_summary();
}



/* provisional name */
void debug_catch_judgment_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(15, 1, 14, dbg_catch_judge_title);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_info_str);
    tilemap_print_string(0, 0, 0xFFFF, dbg_obj_rel_str);
    debug_both_players_reset();
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    Debug_PL_id = 0;
    dbg_cmd_panel = 0;
    Debug_Snap_Disp = 0;
    Debug_Dec_Disp = 0;
    for (i = 0; i < 2; i++) {
        dbg_pl = &plw[i];
        dbg_slot = (DBG_SLOT*)(dbg_slot_w + i);
        debug_slot_char_load();
        debug_motion_list_count();
        debug_pattern_count();
        debug_pattern_timer_update();
    }
}



/* provisional name */
void debug_catch_judgment_run(void) {
    Debug_Command = 0;
    debug_catch_judgment_input();
    switch (Debug_Command) {
    case 1:
        debug_slot_char_load();
        debug_motion_list_count();
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 2:
        if (dbg_slot->sel[0] > 0xD8) {
            set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
        } else {
            set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
        }
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        debug_pattern_count();
        break;
    case 4:
        char_move(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        if (dbg_slot->sel[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        }
        debug_pattern_timer_update();
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    case 5:
        char_move_z(&dbg_pl->wu);
        dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
        if (dbg_pl->wu.disp_flag == 0) {
            dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
        }
        Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
        dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
        Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
        debug_pattern_timer_update();
        dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
        break;
    }
    debug_char_disp((WORK*)&plw[0]);
    debug_char_disp((WORK*)&plw[1]);
}



const char dbg_catch_judge_title[16] = "CATCH JUDJEMENT";


/* provisional name */
void debug_char_preview_dispatch(void) {
    void (*Preview_Tbl[2])() = { debug_char_preview_init, debug_char_preview_run };
    dbg_pl = plw;
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    Preview_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_char_preview_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string(0, 0, 0xFFFF, dbg_all_char_str);
    debug_char_slot_init(0);
    debug_char_slot_init(1);
    dbg_pl->wu.be_flag = 1;
    dbg_pl->wu.disp_flag = 1;
    dbg_pl->wu.cgromtype = 1;
    dbg_pl->wu.my_family = 1;
    dbg_pl->wu.my_col_code = 0x2000;
    dbg_pl->wu.my_col_mode = 0x4200;
    dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos = 0x220;
    dbg_pl->wu.my_priority = 62;
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos = 0;
    dbg_pl->wu.xyz[2].disp.pos = dbg_pl->wu.my_priority;
    dbg_pl->wu.xyz[0].disp.low = 0;
    dbg_pl->wu.xyz[1].disp.low = 0;
    dbg_pl->wu.xyz[2].disp.low = 0;
    dbg_pl->wu.charset_id = debug_charset_tbl[0];
    plw[0].wu.cg_number = plw[1].wu.cg_number = 0;
    plw[0].wu.old_cgnum = 1;
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    Debug_PL_id = 0;
    Debug_Snap_Disp = 0;
    Debug_Dec_Disp = 0;
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    Debug_Flip_Mask[0] = Debug_Flip_Work[0] = Debug_CG_Flip[0] = Debug_RL_Flag[0] = 0;
    Debug_RL_Flag[1] = 0;
    Debug_CG_Flip[1] = 0;
    Debug_Flip_Work[1] = 0;
    Debug_Flip_Mask[1] = 0;
    debug_clear_rgb_triplet_table();
    dbg_col_no = 0;
}

/* provisional name */
void debug_char_preview_run(void) {
    u16 kind;
    u16 group;
    u16 code;
    u16 cells;
    s16 pal;
    u16 shown;
    CharGfxSet* set;
    debug_position_by_pad();
    kind = debug_cg_bank_kind(dbg_pl->wu.cg_number);
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_pl->wu.cg_number -= 1;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0xE5B7;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number < 0x9000) {
                dbg_pl->wu.cg_number = 0x77FF;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number < 0xD800) {
                dbg_pl->wu.cg_number = 0xBDE7;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_pl->wu.cg_number += 1;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0x77FF) {
                dbg_pl->wu.cg_number = 0x9000;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number > 0xBDE8) {
                dbg_pl->wu.cg_number = 0xD800;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        dbg_pl->wu.cg_number -= 0x80;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0xE5B7;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number < 0x9000) {
                dbg_pl->wu.cg_number = 0x77FF;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number < 0xD800) {
                dbg_pl->wu.cg_number = 0xBDE7;
            }
            break;
        }
    }
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        dbg_pl->wu.cg_number += 0x80;
        switch (kind) {
        case 0:
            if (dbg_pl->wu.cg_number > 0x77FF) {
                dbg_pl->wu.cg_number = 0x9000;
            }
            break;
        case 1:
            if (dbg_pl->wu.cg_number > 0xBDE8) {
                dbg_pl->wu.cg_number = 0xD800;
            }
            break;
        case 2:
            if (dbg_pl->wu.cg_number > 0xE5B8) {
                dbg_pl->wu.cg_number = 0;
            }
            break;
        }
    }
    if (~dbg_p1sw_1 & dbg_p1sw_0 & BUTTON_MK) {
        dbg_col_no++;
        if (((u16)dbg_col_no) > 14) {
            dbg_col_no = 0;
        }
        if (((u16)dbg_col_no) >= 7) {
            load_player_color(dbg_col_char, 1, ((u16)dbg_col_no) - 7);
            dbg_pl->wu.my_col_code = 0x2010;
        } else {
            load_player_color(dbg_col_char, 0, ((u16)dbg_col_no));
            dbg_pl->wu.my_col_code = 0x2000;
        }
    }
    if (dbg_pl->wu.cg_number < 0x8A00) {
        pal = dbg_pl->wu.cg_number / 0x600;
        if (dbg_pl->wu.cg_number >= 0x5A00) {
            pal++;
        }
        if (pal != dbg_col_char) {
            dbg_col_char = pal;
            if (((u16)dbg_col_no) >= 7) {
                load_player_color(dbg_col_char, 1, ((u16)dbg_col_no) - 7);
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                load_player_color(dbg_col_char, 0, ((u16)dbg_col_no));
                dbg_pl->wu.my_col_code = 0x2000;
            }
        }
    } else {
        if (dbg_pl->wu.cg_number > 0x9000 && dbg_pl->wu.cg_number < 0x9020) {
            dbg_col_char = 20;
        }
        if (dbg_pl->wu.cg_number > 0x9020 && dbg_pl->wu.cg_number < 0x9060) {
            if (dbg_col_char != 21) {
                dbg_col_char = 21;
            }
        }
        if (dbg_pl->wu.cg_number >= 0xABF8 && dbg_pl->wu.cg_number <= 0xADF8) {
            load_player_color(17, 0, ((u16)dbg_col_no));
        }
        if (dbg_pl->wu.cg_number >= 0xB478 && dbg_pl->wu.cg_number <= 0xB498) {
            load_any_color(9);
            dbg_pl->wu.my_col_code = 0x2140;
        }
    }
    tilemap_print_hex(10, 7, 2, dbg_pl->wu.cg_number, 4, 0);
    group = debug_cg_group_index(plw[0].wu.cg_number);
    debug_draw_cg_group(plw[0].wu.cg_number, group, 4, 5, 2);
    debug_draw_cg_group_offset(plw[0].wu.cg_number, group, 10, 5, 2);
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    shown = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (dbg_pl->zuru_timer != shown) {
        switch (debug_cg_bank_kind((u16)(dbg_pl->zuru_timer & 0x7FFF) / 4)) {
        case 0:
            code = bcp_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            purge_char_gfx(code);
            break;
        case 1:
            code = bce_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            if (code != 0x9000 && code != 0x9020) {
                purge_char_gfx(code);
            }
            break;
        case 2:
            code = bcb_group_top_tbl[(dbg_pl->zuru_timer & 0x7FFF) / 4];
            purge_char_gfx(code);
            break;
        }
        dbg_pl->zuru_timer = shown;
    }
    dbg_pl->wu.cg_olc_ix = dbg_pl->wu.cg_olc_ix = 0;
    debug_char_disp(&dbg_pl->wu);
    set = cg_data_list[dbg_pl->wu.cg_number].set;
    if (set->slot & 0x8000) {
        tilemap_print_string_attr(4, 10, 2, dbg_tikuji_str);
    } else {
        tilemap_print_string_attr(4, 10, 2, dbg_ikkatu_str);
    }
    cells = set->slot & 0x7FFF;
    tilemap_print_hex(11, 11, 2, cells, 4, 0);
    debug_rgb_editor_navigate(0);
    debug_rgb_editor_print(1);
}



const char dbg_tikuji_str[8] = "TIKUJI";


const char dbg_ikkatu_str[8] = "IKKATU";


/* provisional name */
void debug_parts_dispatch(void) {
    void (*Parts_Tbl[2])(void) = { debug_parts_init, debug_parts_run };

    if (Debug_PL_id) {
        dbg_pl = &dbg_parts_plw[dbg_parts_sel & 3];
    } else {
        dbg_pl = &plw[0];
    }
    dbg_slot = (DBG_SLOT*)(dbg_slot_w + Debug_PL_id);
    dbg_snap_ptr = &dbg_snap_w[0][Debug_Rec_Frame];
    Parts_Tbl[Debug_Tool_No]();
}



/* provisional name */
void debug_parts_init(void) {
    s16 i;
    Debug_Tool_No++;
    tilemap_fill_all(0, 32);
    tilemap_print_string_attr(9, 1, 14, dbg_parts_title);
    tilemap_print_string(0, 0, 0xFFFF, dbg_parts_info_str);
    for (i = 0; i < 21; i++) {
        Debug_Rep_Timer[i] = 0;
        Debug_Rep_Count[i] = 0;
    }
    debug_char_slot_init(1);
    debug_p1_reset();
    Debug_Play_Flag = 0;
    Debug_PL_id = 0;
    Debug_Snap_Disp = 0;
    dbg_rec_exist = 0;
    dbg_col_ix[0] = 0;
    dbg_col_ix[1] = 0;
    dbg_cmd_panel = 0;
    dbg_parts_sel = 0;
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    debug_slot_char_load();
    debug_motion_list_count();
    debug_pattern_count();
    debug_pattern_timer_update();
    dbg_col_char = 0;
    dbg_cmd_panel = 0;
    for (i = 0; i < 4; i++) {
        dbg_parts_plw[i].wu.be_flag = 1;
        dbg_parts_plw[i].wu.disp_flag = 1;
        dbg_parts_plw[i].wu.cgromtype = 1;
        dbg_parts_plw[i].wu.my_family = 1;
        dbg_parts_plw[i].wu.my_col_mode = 0x4200;
        dbg_parts_plw[i].wu.work_id = 1;
        dbg_parts_plw[i].wu.xyz[0].disp.low = 0;
        dbg_parts_plw[i].wu.xyz[1].disp.low = 0;
        dbg_parts_plw[i].wu.xyz[2].disp.low = 0;
        dbg_parts_plw[i].wu.my_col_code = 0x2000;
    }
    debug_parts_copy_overlap();
    for (i = 0; i < 4; i++) {
        Debug_RGB[i] = 0;
    }
}



/* provisional name */
void debug_parts_run(void) {
    u16 group;
    Debug_Command = 0;
    dbg_snap_req = 0;
    debug_parts_input();
    switch (Debug_Command) {
    case 1:
        if (!Debug_PL_id) {
            debug_slot_char_load();
            debug_motion_list_count();
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
            dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
            debug_pattern_count();
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 2:
        if (!Debug_PL_id) {
            if (dbg_slot->sel[0] > 0xD8) {
                set_char_move_init(&dbg_pl->wu, 0, dbg_slot->sel[1] - 1);
            } else {
                set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
            }
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
            dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
            debug_pattern_count();
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 3:
        Debug_Play_Flag = 0;
        break;
    case 4:
        if (!Debug_PL_id) {
            char_move(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            debug_pattern_timer_update();
            if (dbg_slot->sel[2] != dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type) {
                Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
                dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
                Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
                dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
            }
            dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
            dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    case 5:
        if (!Debug_PL_id) {
            char_move_z(&dbg_pl->wu);
            dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
            if (dbg_pl->wu.disp_flag == 0) {
                dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
            }
            Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
            dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
            Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
            debug_pattern_timer_update();
            dbg_slot->sel[2]++;
            dbg_slot->sel[2] = dbg_pl->wu.cg_ix / dbg_pl->wu.cgd_type;
            dbg_snap_ptr->dbg_val[1] = dbg_slot->frames;
            dbg_snap_ptr->dbg_val[0] = dbg_slot->rest;
            Debug_Play_Flag = 0;
            debug_parts_copy_overlap();
        }
        break;
    default:
        Debug_Play_Flag = 0;
        break;
    }
    group = debug_cg_group_index(dbg_pl->wu.cg_number);
    debug_draw_cg_group(dbg_pl->wu.cg_number, group, 1, 25, 2);
    debug_draw_cg_group_offset(dbg_pl->wu.cg_number, group, 7, 25, 2);
    debug_parts_flip_apply();
    debug_char_disp((WORK*)&plw[0]);
    debug_draw_parts_info();
    debug_parts_disp();
    if (!Debug_PL_id) {
        debug_rgb_editor_navigate(0);
        debug_rgb_editor_print(0);
    }
}



/* provisional name */
void debug_parts_copy_overlap(void) {
    s16 i;
    OVERLAP_PARTS* oct;
    for (i = 0; i < 4; i++) {
        oct = &plw[0].wu.overlap_char_tbl[plw[0].wu.cg_olc.olc_ix[i]];
        dbg_parts_plw[i].wu.cg_olc.olc_ix[i] = plw[0].wu.cg_olc.olc_ix[i];
        dbg_parts_plw[i].wu.cg_olc_ix = plw[0].wu.cg_olc_ix;
        dbg_parts_plw[i].wu.dir_step = oct->parts_hos_x;
        dbg_parts_plw[i].wu.dir_timer = oct->parts_hos_y;
        dbg_parts_plw[i].wu.xyz[0].disp.pos = plw[0].wu.xyz[0].disp.pos;
        dbg_parts_plw[i].wu.xyz[1].disp.pos = plw[0].wu.xyz[1].disp.pos;
        dbg_parts_plw[i].wu.xyz[0].disp.low = dbg_parts_plw[i].wu.xyz[1].disp.low = 0;
        dbg_parts_plw[i].wu.dir_old = oct->parts_flip;
        dbg_parts_plw[i].wu.cg_flip = dbg_parts_plw[i].wu.dir_old & 3;
        dbg_parts_plw[i].wu.cg_number = oct->parts_char;
        dbg_parts_plw[i].wu.old_rno[1] = oct->parts_prio;
    }
    for (i = 0; i < 4; i++) {
        (&dbg_parts_olc_ix[0])[i] = plw[0].wu.cg_olc.olc_ix[i];
        plw[0].wu.cg_olc.olc_ix[i] = 0;
    }
}



/* provisional name */
void debug_parts_flip_apply(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        if (dbg_parts_plw[i].wu.dir_old & 4) {
            dbg_parts_plw[i].wu.cg_flip = dbg_parts_plw[i].wu.dir_old ^ plw[0].wu.cg_flip;
        }
        plw[0].wu.cg_olc.olc_ix[i] = 0;
    }
}



/* provisional name */
/* The first loop writes slot 0 eight times. */
void debug_char_slot_init(id)
s16 id;
{
    PLW* save_wk;
    s16* save_sp;
    PLW* wk;
    s16* sp;
    s16 i;
    s16* p = dbg_slot_w[id];

    for (i = 0; i < 8; i++) {
        p[0] = 1;
    }
    sp = dbg_slot_w[id];
    sp[8] = 0;
    wk = &plw[id];
    wk->player_number = 0;
    wk->wu.charset_id = debug_charset_tbl[0];
    wk->zuru_timer = 0;
    save_wk = dbg_pl;
    dbg_pl = wk;
    save_sp = (s16*)dbg_slot;
    dbg_slot = (DBG_SLOT*)sp;
    dbg_pl->wu.id = id;
    debug_char_init();
    dbg_pl->wu.disp_flag = 0;
    dbg_pl = save_wk;
    dbg_slot = (DBG_SLOT*)save_sp;
}



/* provisional name */
void debug_edit_slots_reset(void) {
    s16 i;
    s16* sp = dbg_slot_w[0];

    for (i = 0; i < 2; i++) {
        s16* p = sp;
        sp[0] = 1;
        p[1] = 1;
        p[2] = 0;
        p[3] = 1;
        p[8] = 0;
        sp += 9;
    }
}



/* provisional name */
s32 debug_slot_all_select(u16 sw)
{
    s16 moved;
    s16 row;
    if (!(dbg_p1sw_0 & BUTTON_START)) {
        return 0;
    }
    if (!(dbg_p1sw_0 & (LEVER_UP | LEVER_DOWN))) {
        return 0;
    }
    moved = 0;
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
        dbg_slot->sel[0]--;
        if (dbg_slot->sel[0] < 1) {
            dbg_slot->sel[0] = dbg_slot->sel0_max;
        }
        moved = 1;
    } else if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
        dbg_slot->sel[0]++;
        moved = 1;
        if (dbg_slot->sel[0] > dbg_slot->sel0_max) {
            dbg_slot->sel[0] = 1;
        }
    }
    if (dbg_slot->sel[0] <= 216) {
        if (dbg_slot->sel[0] < 10) {
            row = dbg_slot->sel[0] - 1;
        } else {
            row = (dbg_slot->sel[0] - 1) % 9;
        }
        if (row >= 8) {
            row++;
        }
        dbg_slot->row = row;
    } else {
        dbg_slot->row = 0;
    }
    if (moved) {
        return 1;
    }
    return 0;
}



/* provisional name */
s32 debug_slot_motion_select(void) {
    if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
        dbg_slot->sel[1]++;
        if (dbg_slot->sel[1] > dbg_slot->sel1_max) {
            dbg_slot->sel[1] = 1;
        }
        return 2;
    } else if (debug_lever_repeat(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
        dbg_slot->sel[1]--;
        if (dbg_slot->sel[1] < 1) {
            dbg_slot->sel[1] = dbg_slot->sel1_max;
        }
        return 2;
    }
    return 0;
}



#pragma inline(debug_check_step, debug_check_rec_step, debug_check_step_z, debug_check_rec_frame)
#pragma inline(debug_pl_id_input, debug_record_sw_check, debug_dec_disp_input)

/* provisional name: command 4 (step one frame) on P1 button 1, unreferenced */
s32 debug_check_step(void) {
    if (dbg_p1sw_0 & BUTTON_LP) {
        return 4;
    }
    return 0;
}



/* provisional name: command 6 (next recorded frame) on P2 button 1, unreferenced */
s32 debug_check_rec_step(void) {
    if (Debug_Rec_Count != 0) {
        if (dbg_p2sw_0 & BUTTON_LP) {
            return 6;
        }
    }
    return 0;
}



/* provisional name: command 5 on button 2, unreferenced */
s32 debug_check_step_z(u16 sw) {
    if (sw & 0x20) {
        return 5;
    }
    return 0;
}



/* provisional name: command 7 (restart recorded frame) on button 2, unreferenced */
s32 debug_check_rec_frame(u16 sw) {
    if (Debug_Rec_Count != 0 && (sw & 0x20) != 0) {
        return 7;
    }
    return 0;
}



/* provisional name */
s32 debug_flip_cycle(u16 sw) {
    s8 keep;
    if (sw & 0x80) {
        keep = dbg_pl->wu.cg_flip;
        keep &= 4;
        dbg_pl->wu.cg_flip++;
        dbg_pl->wu.cg_flip &= 3;
        dbg_pl->wu.cg_flip |= keep;
        keep = Debug_Flip_Mask[dbg_pl->wu.id];
        keep &= 4;
        Debug_Flip_Mask[dbg_pl->wu.id]++;
        Debug_Flip_Mask[dbg_pl->wu.id] &= 3;
        Debug_Flip_Mask[dbg_pl->wu.id] |= keep;
        return 3;
    }
    return 0;
}



/* provisional name */
s32 debug_parts_flip_cycle(u16 sw) {
    s8 keep;
    if (sw & 0x80) {
        keep = dbg_pl->wu.cg_flip;
        keep &= 4;
        dbg_pl->wu.cg_flip++;
        dbg_pl->wu.cg_flip &= 3;
        dbg_pl->wu.cg_flip |= keep;
        if (!Debug_PL_id) {
            keep = Debug_Flip_Mask[dbg_pl->wu.id];
        keep &= 4;
            Debug_Flip_Mask[dbg_pl->wu.id]++;
            Debug_Flip_Mask[dbg_pl->wu.id] &= 3;
            Debug_Flip_Mask[dbg_pl->wu.id] |= keep;
        }
        return 3;
    }
    return 0;
}



/* provisional name */
s32 debug_priority_swap(u16 sw) {
    if (sw & 0x40) {
        if (plw[0].wu.my_priority == 50) {
            plw[0].wu.my_priority = 51;
            plw[1].wu.my_priority = 50;
        } else {
            plw[0].wu.my_priority = 50;
            plw[1].wu.my_priority = 51;
        }
        return 3;
    }
    if ((plw[0].wu.my_priority == 50 && plw[1].wu.my_priority == 51)
        || (plw[1].wu.my_priority == 50 && plw[0].wu.my_priority == 51)) {
        return 0;
    }
    if (plw[0].wu.my_priority <= plw[1].wu.my_priority) {
        plw[0].wu.my_priority = 50;
        plw[1].wu.my_priority = 51;
    } else {
        plw[0].wu.my_priority = 51;
        plw[1].wu.my_priority = 50;
    }
    return 0;
}



/* provisional name */
void debug_move_record_start(u16 sw) {
    s16 n;
    if (sw & 0x100) {
        if (Debug_Rec_Count != 0) {
            dbg_rec_menu = 15;
        } else {
            dbg_rec_menu = 0;
            n = debug_catch_move_record(dbg_snap_w[0], dbg_snap_w[1]);
            if (n != 0) {
                dbg_rec_exist = 1;
                Debug_Rec_Frame = 1;
            } else {
                Debug_Rec_Count = 0;
                Debug_Rec_Frame = 0;
            }
            dbg_snap_req = 1;
            Debug_Play_Flag = 1;
        }
    }
}


/* provisional name */
void debug_pl_id_input(u16 sw) {
    if (sw & 0x40) {
        Debug_PL_id ^= 1;
    }
}


/* provisional name */
s32 debug_record_sw_check(u16 sw) {
    if (sw & 0x80) {
        return 8;
    }
    return 0;
}



/* provisional name */
void debug_record_frame_adjust(u16 sw) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x100, 19)) {
        dbg_snap_ptr->cg_ctr++;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x200, 20)) {
        dbg_snap_ptr->cg_ctr--;
        if (dbg_snap_ptr->cg_ctr < 0) {
            dbg_snap_ptr->cg_ctr = 0;
        }
    }
}

/* provisional name */
void debug_move_record_menu(void)
{
    u16 sw;
    s16 i;
    s16 next;

    if (Debug_Rec_Count) {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_menu_str);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_nodata_str);
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & BUTTON_LK) {
        /* clear all recorded frames */
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        Debug_Rec_Frame = 0;
        Debug_Rec_Count = 0;
        dbg_save_mode = 2;
        dbg_snap_req = 0;
        dbg_rec_menu = 0;
        dbg_rec_exist = 0;
        Debug_Play_Flag = 0;
    }
    if (sw & BUTTON_MK) {
        /* delete the current frame: pull the following snapshots down one slot */
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        for (i = Debug_Rec_Frame; i < Debug_Rec_Count; i++) {
            next = i + 1;
            debug_copy_player_snapshot(&dbg_snap_w[0][next], &dbg_snap_w[0][i]);
            debug_copy_player_snapshot(&dbg_snap_w[1][next], &dbg_snap_w[1][i]);
        }
        Debug_Rec_Count--;
        dbg_rec_menu = 0;
        dbg_snap_req = 1;
        Debug_Play_Flag = 1;
    }
    if (sw & BUTTON_HK) {
        tilemap_print_string(0, 0, 0xFFFF, dbg_rec_clear_str);
        dbg_rec_menu = 0;
    }
}

/* provisional name */
void debug_playback_mode_cycle(u16 sw) {
    if ((sw & 0x200) != 0) {
        if (Debug_Rec_Count != 0) {
            dbg_rec_exist = 1;
            dbg_save_mode = dbg_save_mode + 1;
            if (2 < dbg_save_mode) {
                dbg_save_mode = 0;
            }
        }
    }
}



/* provisional name */
void debug_position_by_pad(void) {
    if (!(dbg_p1sw_0 & BUTTON_START)) {
        if (dbg_p1sw_0 & LEVER_DOWN) {
            debug_bg_scroll_by_pad();
            return;
        }
        if ((dbg_p1sw_0 & LEVER_UP) && (dbg_p2sw_0 & LEVER_ALL)) {
            debug_bg_position_reset();
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        dbg_pl->wu.xyz[1].disp.pos++;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        dbg_pl->wu.xyz[1].disp.pos--;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
        dbg_pl->wu.xyz[0].disp.pos--;
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
        dbg_pl->wu.xyz[0].disp.pos++;
    }
}



/* provisional name: debug_bg_scroll_by_pad for BG layer 0 only, unreferenced */
void debug_bg0_scroll_by_pad(void) {
    if (p2sw_0 & LEVER_LEFT) {
        bg_w.bgw[0].position_x--;
        bg_w.bgw[0].xy[0].disp.pos--;
    }
    if (p2sw_0 & LEVER_RIGHT) {
        bg_w.bgw[0].position_x++;
        bg_w.bgw[0].xy[0].disp.pos++;
    }
    if (p2sw_0 & LEVER_UP) {
        bg_w.bgw[0].position_y++;
        bg_w.bgw[0].xy[1].disp.pos++;
    }
    if (p2sw_0 & LEVER_DOWN) {
        bg_w.bgw[0].position_y--;
        bg_w.bgw[0].xy[1].disp.pos--;
    }
    Bg_Family_Set();
}



/* provisional name */
void debug_bg_position_reset(void) {
    s16 i;
    i = 0;
    while (i < bg_w.scno) {
        bg_w.bgw[i].xy[0].disp.pos = 0x100;
        bg_w.bgw[i].xy[1].disp.pos = 0;
        bg_w.bgw[i].xy[0].disp.low = 0;
        bg_w.bgw[i].xy[1].disp.low = 0;
        bg_w.bgw[i].position_x = 0x100;
        bg_w.bgw[i].position_y = 0;
        i++;
    }
    Bg_Family_Set();
}



#pragma inline(bg_pos_disp)
static void bg_pos_disp(s16 pos, s16 position) {}

/* provisional name */
void debug_bg_scroll_by_pad(void) {
    s16 i;
    if (p2sw_0 & LEVER_LEFT) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_x--;
            bg_w.bgw[i].xy[0].disp.pos--;
        }
    }
    if (p2sw_0 & LEVER_RIGHT) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_x++;
            bg_w.bgw[i].xy[0].disp.pos++;
        }
    }
    if (p2sw_0 & LEVER_UP) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_y++;
            bg_w.bgw[i].xy[1].disp.pos++;
        }
    }
    if (p2sw_0 & LEVER_DOWN) {
        for (i = 0; i < bg_w.scno; i++) {
            bg_w.bgw[i].position_y--;
            bg_w.bgw[i].xy[1].disp.pos--;
        }
    }
    if (!bg_w.stage) {
        bg_w.bgw[4].hos_xy[0].cal = bg_w.bgw[4].xy[0].cal = bg_w.bgw[0].xy[0].cal;
        bg_w.bgw[4].hos_xy[0].cal = bg_w.bgw[4].xy[1].cal = bg_w.bgw[0].xy[1].cal;
        bg_pos_disp(bg_w.bgw[4].xy[0].disp.pos, bg_w.bgw[4].position_x);
    }
    Bg_Family_Set();
}



/* provisional name */
void debug_hit_box_edit(void) {
    BODY_BOX* body;
    HAND_BOX* hand;
    ATTACK_BOX* attack;
    s16* box;
    u16 pad;
    if (Debug_PL_id) {
        return;
    }
    pad = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (pad & BUTTON_MP) {
        dbg_judge_ewk->look_up_flag ^= 1;
    }
    if (Debug_Box_Edit) {
        body = dbg_copy_buf.h_bod;
        hand = dbg_copy_buf.h_han;
        attack = dbg_copy_buf.h_att;
        (void)&((WORK*)attack)->id;
        switch (dbg_judge_ewk->curr_ja) {
        case 0:
            box = body->body_dm[0];
            break;
        case 1:
            box = body->body_dm[1];
            break;
        case 2:
            box = body->body_dm[2];
            break;
        case 3:
            box = body->body_dm[3];
            break;
        case 4:
            box = hand->hand_dm[0];
            break;
        case 5:
            box = hand->hand_dm[1];
            break;
        case 6:
            box = hand->hand_dm[2];
            break;
        case 7:
            box = hand->hand_dm[3];
            break;
        case 8:
            box = dbg_copy_buf.h_cat->cat_box;
            break;
        case 9:
            box = dbg_copy_buf.h_cau->cau_box;
            break;
        case 10:
            box = attack->att_box[0];
            break;
        case 11:
            box = attack->att_box[1];
            break;
        case 12:
            box = attack->att_box[2];
            break;
        case 13:
            box = attack->att_box[3];
            break;
        case 14:
            box = dbg_copy_buf.h_hos->hos_box;
        default:
            break;
        }
        dbg_edit_box = box;
    } else if (dbg_judge_ewk->look_up_flag) {
        pad = dbg_p2sw_0;
        body = dbg_look_buf.h_bod;
        hand = dbg_look_buf.h_han;
        attack = dbg_look_buf.h_att;
        if (DEBUG_EDIT) {
            dbg_judge_ewk->look_up_flag ^= 1;
        }
        switch (dbg_judge_ewk->curr_ja) {
        case 0:
            box = body->body_dm[0];
            break;
        case 1:
            box = body->body_dm[1];
            break;
        case 2:
            box = body->body_dm[2];
            break;
        case 3:
            box = body->body_dm[3];
            break;
        case 4:
            box = hand->hand_dm[0];
            break;
        case 5:
            box = hand->hand_dm[1];
            break;
        case 6:
            box = hand->hand_dm[2];
            break;
        case 7:
            box = hand->hand_dm[3];
            break;
        case 8:
            box = dbg_look_buf.h_cat->cat_box;
            break;
        case 9:
            box = dbg_look_buf.h_cau->cau_box;
            break;
        case 10:
            box = attack->att_box[0];
            break;
        case 11:
            box = attack->att_box[1];
            break;
        case 12:
            box = attack->att_box[2];
            break;
        case 13:
            box = attack->att_box[3];
            break;
        case 14:
            box = dbg_look_buf.h_hos->hos_box;
        default:
            break;
        }
        dbg_edit_box = box;
        if (!Debug_Box_Edit) {
            if (pad & BUTTON_LP) {
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
                    box[3]++;
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
                    box[3]--;
                    if (box[3] < 0) {
                        box[3] = 0;
                    }
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
                    box[1]++;
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
                    box[1]--;
                    if (box[1] < 0) {
                        box[1] = 0;
                    }
                }
            } else {
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
                    box[2]++;
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
                    box[2]--;
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
                    box[0]--;
                }
                if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
                    box[0]++;
                }
            }
        }
    } else {
        body = dbg_edit_buf.h_bod;
        hand = dbg_edit_buf.h_han;
        attack = dbg_edit_buf.h_att;
        (void)&((WORK*)attack)->id;
        switch (dbg_judge_ewk->curr_ja) {
        case 0:
            box = body->body_dm[0];
            break;
        case 1:
            box = body->body_dm[1];
            break;
        case 2:
            box = body->body_dm[2];
            break;
        case 3:
            box = body->body_dm[3];
            break;
        case 4:
            box = hand->hand_dm[0];
            break;
        case 5:
            box = hand->hand_dm[1];
            break;
        case 6:
            box = hand->hand_dm[2];
            break;
        case 7:
            box = hand->hand_dm[3];
            break;
        case 8:
            box = dbg_edit_buf.h_cat->cat_box;
            break;
        case 9:
            box = dbg_edit_buf.h_cau->cau_box;
            break;
        case 10:
            box = attack->att_box[0];
            break;
        case 11:
            box = attack->att_box[1];
            break;
        case 12:
            box = attack->att_box[2];
            break;
        case 13:
            box = attack->att_box[3];
            break;
        case 14:
            box = dbg_edit_buf.h_hos->hos_box;
        default:
            break;
        }
        dbg_edit_box = box;
    }
}



/* provisional name */
void debug_set_dummy_box(void) {
}



void debug_set_body_box(s16 n) {
    dbg_look_buf.h_bod = dbg_look_buf.body_adrs + n;
    dbg_edit_buf.h_bod = dbg_edit_buf.body_adrs + n;
}



/* provisional name */
void debug_set_hand_box(s16 n) {
    dbg_look_buf.h_han = dbg_look_buf.hand_adrs + n;
    dbg_edit_buf.h_han = dbg_edit_buf.hand_adrs + n;
}



/* provisional name */
void debug_set_catch_box(s16 n) {
    dbg_look_buf.h_cat = dbg_look_buf.catch_adrs + n;
    dbg_edit_buf.h_cat = dbg_edit_buf.catch_adrs + n;
}



/* provisional name */
void debug_set_caught_box(s16 n) {
    dbg_look_buf.h_cau = dbg_look_buf.caught_adrs + n;
    dbg_edit_buf.h_cau = dbg_edit_buf.caught_adrs + n;
}



/* provisional name */
void debug_set_attack_box(s16 n) {
    dbg_look_buf.h_att = dbg_look_buf.attack_adrs + n;
    dbg_edit_buf.h_att = dbg_edit_buf.attack_adrs + n;
}



/* provisional name */
void debug_set_hosei_box(s16 n) {
    dbg_look_buf.h_hos = dbg_look_buf.hosei_adrs + n;
    dbg_edit_buf.h_hos = dbg_edit_buf.hosei_adrs + n;
}

/* Point every hit-box cursor of the look and edit buffers at box number n. */
/* provisional name */
void debug_set_all_boxes(n)
s16 n;
{
    debug_set_dummy_box();
    debug_set_body_box(n);
    debug_set_hand_box(n);
    debug_set_catch_box(n);
    debug_set_caught_box(n);
    debug_set_attack_box(n);
    debug_set_hosei_box(n);
}



/* provisional name */
void debug_hit_box_cursor(void) {
    u16 now;
    u16 sw;
    u16 *input = &now;
    if (Debug_PL_id) {
        return;
    }
    now = dbg_p2sw_0;
held:;
    sw = ~dbg_p2sw_1 & now;
    if (now & 0x240) {
        tilemap_rect_fill(dbg_hud_x + 40, (s8)((WORK_Other*)dbg_judge_ewk)->refrected + 12, 8, 1, 2, 0xFFFF);
        if (sw & BUTTON_HP) {
            ((WORK_Other*)dbg_judge_ewk)->refrected--;
            if ((s8)((WORK_Other*)dbg_judge_ewk)->refrected < 0) {
                ((WORK_Other*)dbg_judge_ewk)->refrected = 14;
            }
        }
        if (sw & BUTTON_HK) {
            ((WORK_Other*)dbg_judge_ewk)->refrected++;
            if ((s8)((WORK_Other*)dbg_judge_ewk)->refrected > 14) {
                ((WORK_Other*)dbg_judge_ewk)->refrected = 0;
            }
        }
    }
}



/* provisional name */
void debug_memcpy_u16(u16* src, u16* dst, s16 n) {
    s16 i;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
}



/* provisional name */
void debug_hit_box_copy(void) {
    u16 sw;
    if (Debug_PL_id) {
        return;
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw & BUTTON_MK) {
        Debug_Box_Edit ^= 1;
        if (Debug_Box_Edit) {
            if (dbg_judge_ewk->look_up_flag) {
                debug_memcpy_u16((u16*)dbg_look_buf.h_bod, (u16*)dbg_copy_buf.h_bod, 16);
                debug_memcpy_u16((u16*)dbg_look_buf.h_han, (u16*)dbg_copy_buf.h_han, 16);
                debug_memcpy_u16((u16*)dbg_look_buf.h_att, (u16*)dbg_copy_buf.h_att, 16);
                debug_memcpy_u16((u16*)dbg_look_buf.h_cat, (u16*)dbg_copy_buf.h_cat, 4);
                debug_memcpy_u16((u16*)dbg_look_buf.h_cau, (u16*)dbg_copy_buf.h_cau, 4);
                debug_memcpy_u16((u16*)dbg_look_buf.h_hos, (u16*)dbg_copy_buf.h_hos, 4);
            } else {
                debug_memcpy_u16((u16*)dbg_pl->wu.h_bod, (u16*)dbg_copy_buf.h_bod, 16);
                debug_memcpy_u16((u16*)dbg_pl->wu.h_han, (u16*)dbg_copy_buf.h_han, 16);
                debug_memcpy_u16((u16*)dbg_pl->wu.h_att, (u16*)dbg_copy_buf.h_att, 16);
                debug_memcpy_u16((u16*)dbg_pl->wu.h_cat, (u16*)dbg_copy_buf.h_cat, 4);
                debug_memcpy_u16((u16*)dbg_pl->wu.h_cau, (u16*)dbg_copy_buf.h_cau, 4);
                debug_memcpy_u16((u16*)dbg_pl->wu.h_hos, (u16*)dbg_copy_buf.h_hos, 4);
            }
        } else {
            dbg_copy_done = 0;
        }
    }
    if (sw & BUTTON_LK) {
        if (Debug_Box_Edit) {
        dbg_copy_done = 1;
        dbg_copy_pat = dbg_slot->sel[2];
        dbg_copy_char = dbg_pl->wu.char_index;
        debug_set_body_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_bod, (u16*)dbg_look_buf.h_bod, 16);
        debug_set_hand_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_han, (u16*)dbg_look_buf.h_han, 16);
        debug_set_attack_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_att, (u16*)dbg_look_buf.h_att, 16);
        debug_set_catch_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_cat, (u16*)dbg_look_buf.h_cat, 4);
        debug_set_caught_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_cau, (u16*)dbg_look_buf.h_cau, 4);
        debug_set_hosei_box(dbg_slot->sel[2]);
        debug_memcpy_u16((u16*)dbg_copy_buf.h_hos, (u16*)dbg_look_buf.h_hos, 4);
        }
    }
}

/* provisional name */
void debug_hit_box_show_select(void) {
    u16 sw = exsw_1;
    dbg_judge_ewk->ja_disp_bit = 0;
    dbg_judge_ewk->wu.spr.gfx_cells = 0;
    if (sw & 0x100) {
        dbg_judge_ewk->ja_disp_bit |= 0x120;
        dbg_judge_ewk->wu.spr.gfx_cells += 8;
    }
    if (sw & 0x200) {
        dbg_judge_ewk->ja_disp_bit |= 0x200;
        dbg_judge_ewk->wu.spr.gfx_cells += 4;
    }
    if (sw & 0x400) {
        dbg_judge_ewk->ja_disp_bit |= 0xC0;
        dbg_judge_ewk->wu.spr.gfx_cells += 8;
    }
    if (sw & 0x800) {
        dbg_judge_ewk->ja_disp_bit |= 0x1F;
        dbg_judge_ewk->wu.spr.gfx_cells += 20;
    }
    if (sw & 0x1000) {
        dbg_judge_ewk->ja_disp_bit |= 0x400;
        dbg_judge_ewk->wu.spr.gfx_cells += 2;
    }
}



/* provisional name */
void debug_edit_common_input(void)
{
    u16 sw;
    u16 i;

    if (Debug_Menu_No != 4) {
        debug_position_by_pad();
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if ((Debug_Command = debug_slot_all_select(sw)) != 0) {
        return;
    }
    if ((Debug_Command = debug_slot_motion_select()) != 0) {
        return;
    }
    if ((Debug_Command = debug_check_step_z(sw)) != 0) {
        return;
    }
    if ((Debug_Command = debug_check_step()) != 0) {
        return;
    }
    Debug_Command = debug_flip_cycle(sw);
    if (sw & 0x800) {
        dbg_cmd_panel ^= 1;
        if (dbg_cmd_panel) {
            tilemap_print_string_attr(0x14, 3, 2, dbg_slot_1p_s1_str);
            tilemap_print_string_attr(0x14, 4, 2, dbg_slot_1p_s2_str);
            tilemap_print_string_attr(0x14, 5, 2, dbg_slot_1p_s3_str);
            tilemap_print_string_attr(0x14, 6, 2, dbg_slot_1p_s4_str);
            tilemap_print_string_attr(0x14, 7, 2, dbg_slot_s5_str);
            tilemap_print_string_attr(0x14, 8, 2, dbg_slot_s6_str);
            tilemap_print_string_attr(0x21, 3, 2, dbg_slot_2p_s1_str);
            tilemap_print_string_attr(0x21, 4, 2, dbg_slot_2p_s2_str);
            tilemap_print_string_attr(0x21, 5, 2, dbg_slot_2p_s3_str);
            tilemap_print_string_attr(0x21, 6, 2, dbg_slot_2p_s4_str);
            tilemap_print_string_attr(0x21, 7, 2, dbg_slot_s5_str);
            tilemap_print_string_attr(0x21, 8, 2, dbg_slot_s6_str);
        } else {
            for (i = 0; i < 6; i++) {
                tilemap_print_string_attr(0x14, i + 3, 2, dbg_space10_str);
                tilemap_print_string_attr(0x21, i + 3, 2, dbg_space10_str);
            }
        }
    }
}



/* provisional name */
void debug_kakusyuku_mode_cycle(u16 sw) {
    if (sw & 0x200) {
        dbg_kakusyuku_mode++;
        dbg_kakusyuku_mode &= 3;
        switch (dbg_kakusyuku_mode) {
        case 0:
            dbg_pl->wu.my_mr_flag = 0;
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            Zoomf_Init();
            break;
        case 1:
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            dbg_pl->wu.my_mr_flag = 0;
            break;
        case 2:
            dbg_pl->wu.my_mr_flag = 1;
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            Zoomf_Init();
            break;
        case 3:
            Zoomf_Init();
            dbg_pl->wu.my_mr.size.x = 63;
            dbg_pl->wu.my_mr.size.y = 63;
            dbg_zoom_x = 19;
            dbg_zoom_y = 19;
            dbg_pl->wu.my_mr_flag = 1;
            break;
        }
    }
}



/* provisional name */
void debug_screen_zoom_by_pad(void) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 64, 16)) {
        dbg_zoom_x--;
        dbg_zoom_y--;
        if (dbg_zoom_x > 0) {
            Frame_Down(0xc0, 0xe0, 1, 1);
        } else {
            dbg_zoom_x = 0;
            dbg_zoom_y = 0;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x200, 19)) {
        dbg_zoom_x++;
        dbg_zoom_y++;
        if (dbg_zoom_x < 38) {
            Frame_Up(0xc0, 0xe0, 1, 1);
        } else {
            dbg_zoom_x = 38;
            dbg_zoom_y = 38;
        }
    }
}



/* provisional name */
void debug_char_scale_by_pad(void) {
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 16, 14)) {
        if (dbg_pl->wu.my_mr.size.x != 0) {
            dbg_pl->wu.my_mr.size.x--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 32, 15)) {
        if (dbg_pl->wu.my_mr.size.y != 0) {
            dbg_pl->wu.my_mr.size.y--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 128, 17)) {
        dbg_pl->wu.my_mr.size.x++;
        if (dbg_pl->wu.my_mr.size.x > 127) {
            dbg_pl->wu.my_mr.size.x = 127;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 0x100, 18)) {
        dbg_pl->wu.my_mr.size.y++;
        if (dbg_pl->wu.my_mr.size.y > 127) {
            dbg_pl->wu.my_mr.size.y = 127;
        }
    }
}



/* provisional name */
void debug_kakusyuku_input(void) {
    switch (dbg_kakusyuku_mode) {
    case 1:
        debug_screen_zoom_by_pad();
        break;
    case 2:
        debug_char_scale_by_pad();
        break;
    case 3:
        debug_screen_zoom_by_pad();
        debug_char_scale_by_pad();
        break;
    }
}


/* provisional name */
void debug_dec_disp_input(u16 sw) {
    if (sw & 0x1000) {
        Debug_Dec_Disp ^= 1;
    }
}



/* provisional name */
void debug_cmd_panel_run(void) {
    WORK* wk;
    u16 trg = ~dbg_p1sw_1 & dbg_p1sw_0;
    u16 sel = ~dbg_p2sw_1 & dbg_p2sw_0 & BUTTON_SHOTS;
    u16 i;
    sel = sel * 16 + (0x3f0 & trg) / 16;
    if (dbg_cmd_panel != 0) {
        wk = &dbg_pl->wu;
        switch (sel) {
        case 1:
            char_move_cmja(wk);
            break;
        case 2:
            char_move_cmj2(wk);
            break;
        case 4:
            char_move_cmj3(wk);
            break;
        case 8:
            char_move_cmj4(wk);
            break;
        case 0x100:
            char_move_cmoa(wk);
            break;
        case 0x200:
            if (wk->cg_wca_ix != -1) {
                char_move_wca(wk);
            } else {
                tilemap_print_string_attr(20, 2, 2, dbg_no_wca_str);
            }
            break;
        case 0x400:
            if (wk->cmja.pat) {
                char_move_cmja(wk);
            } else {
                tilemap_print_string_attr(20, 2, 2, dbg_no_cmja_str);
            }
            break;
        default:
            if (trg & 0x800) {
                dbg_cmd_panel ^= 1;
            }
            goto draw;
            break;
        }
    }
    dbg_cmd_panel = 0;
    task_sleep(4);
draw:
    if (dbg_cmd_panel) {
        tilemap_print_string_attr(20, 3, 2, dbg_slot_1p_s1_str);
        tilemap_print_string_attr(20, 4, 2, dbg_slot_1p_s2_str);
        tilemap_print_string_attr(20, 5, 2, dbg_slot_1p_s3_str);
        tilemap_print_string_attr(20, 6, 2, dbg_slot_1p_s4_str);
        tilemap_print_string_attr(20, 7, 2, dbg_slot_s5_str);
        tilemap_print_string_attr(20, 8, 2, dbg_slot_s6_str);
        tilemap_print_string_attr(33, 3, 2, dbg_slot_2p_s1_str);
        tilemap_print_string_attr(33, 4, 2, dbg_slot_2p_s2_str);
        tilemap_print_string_attr(33, 5, 2, dbg_slot_2p_s3_str);
        tilemap_print_string_attr(33, 6, 2, dbg_slot_2p_s4_str);
        tilemap_print_string_attr(33, 7, 2, dbg_slot_s5_str);
        tilemap_print_string_attr(33, 8, 2, dbg_slot_s6_str);
    } else {
        tilemap_print_string_attr(20, 2, 2, dbg_space10_str);
        for (i = 0; i < 6; i++) {
            tilemap_print_string_attr(20, i + 3, 2, dbg_space10_str);
            tilemap_print_string_attr(33, i + 3, 2, dbg_space10_str);
        }
    }
}



/* provisional name */
void debug_cg_number_browse(void) {
    u16 kind;
    s16 moved;
    s16 ix;
    long code;
    u16 group;
    debug_position_by_pad();
    debug_flip_cycle(dbg_p1sw_0 & ~dbg_p1sw_1);
    kind = debug_cg_bank_kind((s16)dbg_pl->wu.cg_number);
    moved = 0;
    if (dbg_p1sw_0 & BUTTON_START) {
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 1, 0)) {
            dbg_pl->wu.cg_number--;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0xe5b7;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number < 0x9000) {
                    dbg_pl->wu.cg_number = 0x77ff;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number < 0xd800) {
                    dbg_pl->wu.cg_number = 0xbde7;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 2, 1)) {
            dbg_pl->wu.cg_number++;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0x77ff) {
                    dbg_pl->wu.cg_number = 0x9000;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number > 0xbde8) {
                    dbg_pl->wu.cg_number = 0xd800;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 4, 2)) {
            dbg_pl->wu.cg_number -= 0x80;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0xe5b7;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number < 0x9000) {
                    dbg_pl->wu.cg_number = 0x77ff;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number < 0xd800) {
                    dbg_pl->wu.cg_number = 0xbde7;
                }
                break;
            }
        }
        if (debug_lever_repeat_fast(dbg_p1sw_0, dbg_p1sw_1, 8, 3)) {
            dbg_pl->wu.cg_number += 0x80;
            moved = 1;
            switch (kind) {
            case 0:
                if (dbg_pl->wu.cg_number > 0x77ff) {
                    dbg_pl->wu.cg_number = 0x9000;
                }
                break;
            case 1:
                if (dbg_pl->wu.cg_number > 0xbde8) {
                    dbg_pl->wu.cg_number = 0xd800;
                }
                break;
            case 2:
                if (dbg_pl->wu.cg_number > 0xe5b8) {
                    dbg_pl->wu.cg_number = 0;
                }
                break;
            }
        }
        if (moved == 0) {
            return;
        }
        if (dbg_pl->wu.cg_number < 0x8a00) {
            code = dbg_pl->wu.cg_number;
            ix = code / 0x600;
            if (code >= 0x5a00) {
                ix++;
            }
            if (ix != dbg_col_char) {
                dbg_col_char = ix;
                load_player_color(dbg_col_char, 1, 0);
                dbg_pl->wu.charset_id = debug_charset_tbl[dbg_col_char];
                dbg_pl->wu.my_col_mode = 0x4200;
                debug_char_table_load();
                set_char_base_data_init(&dbg_pl->wu);
                dbg_pl->wu.my_col_code = 0x2010;
            }
            dbg_pl->player_number = ix;
        } else {
            if (dbg_pl->wu.cg_number > 0x9000 && dbg_pl->wu.cg_number < 0x9020) {
                dbg_col_char = 20;
            }
            if (dbg_pl->wu.cg_number > 0x9020 && dbg_pl->wu.cg_number < 0x9060) {
                if (dbg_col_char != 21) {
                    dbg_col_char = 21;
                }
            }
            if (dbg_pl->wu.cg_number >= 0xb478 && dbg_pl->wu.cg_number <= 0xb498) {
                load_any_color(9);
                dbg_pl->wu.my_col_code = 0x2140;
            }
        }
    }
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (dbg_pl->zuru_timer != group) {
        purge_char_gfx((u16)bcp_group_top_tbl[(dbg_pl->zuru_timer & 0x7fff) / 4]);
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_object_look_input(void) {
    u16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (sw & BUTTON_HP) {
        Debug_Command = 6;
        return;
    }
    debug_kakusyuku_mode_cycle(sw);
    debug_kakusyuku_input();
}

/* provisional name */
void debug_object_edit_input(void)
{
    u16 sw;

    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    if (dbg_rec_menu) {
        debug_move_record_menu();
        return;
    }
    debug_edit_common_input();
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if ((Debug_Command = debug_priority_swap(sw)) != 0) {
        return;
    }
    debug_move_record_start(sw);
    debug_playback_mode_cycle(sw);
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if ((Debug_Command = debug_check_rec_frame(sw)) != 0) {
        return;
    }
    if ((Debug_Command = debug_check_rec_step()) != 0) {
        return;
    }
    if ((Debug_Command = debug_record_sw_check(sw)) != 0) {
        return;
    }
    debug_dec_disp_input(sw);
    debug_record_frame_adjust(sw);
    debug_pl_id_input(sw);
    debug_zoom_out_by_dipsw();
    debug_player_color_next();
}



/* provisional name */
void debug_edit_all_char_input(void) {
    u16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    if (dbg_rec_menu) {
        debug_move_record_menu();
        return;
    }
    if (!dbg_pl->wu.id) {
        debug_edit_common_input();
    } else {
        debug_cg_number_browse();
    }
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if ((Debug_Command = debug_priority_swap(sw))) {
        return;
    }
    debug_move_record_start(sw);
    debug_playback_mode_cycle(sw);
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if ((Debug_Command = debug_check_rec_frame(sw))) {
        return;
    }
    if ((Debug_Command = debug_check_rec_step())) {
        return;
    }
    if ((Debug_Command = debug_record_sw_check(sw))) {
        return;
    }
    debug_record_frame_adjust(sw);
    debug_pl_id_input(sw);
    debug_dec_disp_input(sw);
    debug_zoom_out_by_dipsw();
    debug_player_color_next();
}



/* provisional name */
void debug_hit_judgment_input(void) {
    s16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    debug_hit_box_edit();
    debug_hit_box_cursor();
    debug_hit_box_copy();
    if (!((WORK_Other*)dbg_judge_ewk)->dm_refrect) {
        debug_position_by_pad();
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (sw & BUTTON_START) {
        Debug_PL_id = Debug_PL_id ^ 1;
    }
    if (Debug_PL_id) {
        if (sw & BUTTON_LP) {
            plw[1].wu.disp_flag ^= 1;
        }
    }
    if ((~dbg_p1sw_1 & dbg_p1sw_0) & BUTTON_MK) {
        dbg_col_no++;
        if ((u16)dbg_col_no > 7) {
            dbg_col_no = 0;
        }
        load_player_color(dbg_pl->player_number, dbg_pl->wu.id, (u16)dbg_col_no);
    }
}



/* provisional name */
void debug_catch_judgment_input(void) {
    s16 sw;
    if (dbg_cmd_panel) {
        debug_cmd_panel_run();
        return;
    }
    debug_edit_common_input();
    if (Debug_Command) {
        return;
    }
    sw = ~dbg_p2sw_1 & dbg_p2sw_0;
    debug_pl_id_input(sw);
    debug_dec_disp_input(sw);
}



/* provisional name */
void debug_parts_input(void) {
    u16 sw;
    s16 i;

    sw = ~dbg_p1sw_1 & dbg_p1sw_0;
    if (!Debug_PL_id) {
        if ((Debug_Command = debug_slot_all_select(sw))) {
            return;
        }
        if ((Debug_Command = debug_slot_motion_select())) {
            return;
        }
    } else {
        if (sw & BUTTON_MK) {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step = -dbg_parts_plw[dbg_parts_sel].wu.dir_step;
        }
        if (sw & BUTTON_HK) {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer = -dbg_parts_plw[dbg_parts_sel].wu.dir_timer;
        }
    }
    if ((Debug_Command = debug_check_step_z(sw))) {
        return;
    }
    if ((Debug_Command = debug_check_step())) {
        return;
    }
    Debug_Command = debug_parts_flip_cycle(sw);
    if (Debug_Command) {
        return;
    }
    if ((Debug_Command = debug_priority_swap(~dbg_p1sw_1 & dbg_p1sw_0))) {
        return;
    }
    sw = dbg_p2sw_0 & ~dbg_p2sw_1;
    if (sw & BUTTON_LP) {
        dbg_parts_sel++;
        dbg_parts_sel &= 3;
    }
    debug_dec_disp_input(sw);
    debug_pl_id_input(sw);
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 1, 4)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[1].disp.pos++;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[1].disp.pos++;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 2, 5)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[1].disp.pos--;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[1].disp.pos--;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_timer++;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 4, 6)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[0].disp.pos--;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[0].disp.pos--;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step--;
        }
    }
    if (debug_lever_repeat(dbg_p2sw_0, dbg_p2sw_1, 8, 7)) {
        if (!Debug_PL_id) {
            plw[0].wu.xyz[0].disp.pos++;
            for (i = 0; i < 4; i++) {
                dbg_parts_plw[i].wu.xyz[0].disp.pos++;
            }
        } else {
            dbg_parts_plw[dbg_parts_sel].wu.dir_step++;
        }
    }
    if (DEBUG_EDIT) {
        if (dbg_p2sw_0 & BUTTON_MP) {
            plw[0].wu.xyz[1].disp.pos = 0;
        }
    }
}



/* provisional name */
s32 debug_lever_repeat(sw, old, mask, ix)
    u16 sw;
    u16 old;
    u16 mask;
    s16 ix;
{
    if (sw & mask) {
        if (Debug_Menu_No == 5 && (sw & 0x10)) {
            return 1;
        }
        Debug_Rep_Timer[ix]++;
        if (~old & sw & mask) {
            Debug_Rep_Timer[ix] = 0;
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
        if (ix > 3) {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                return 1;
            }
            return 0;
        } else {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                if (Debug_Rep_Count[ix] > 4) {
                    Debug_Rep_Count[ix] = 0;
                    return 1;
                }
            }
            return 0;
        }
    }
    Debug_Rep_Timer[ix] = 0;
    Debug_Rep_Count[ix] = 0;
    return 0;
}



/* provisional name */
s32 debug_lever_repeat_fast(sw, old, mask, ix)
u16 sw;
u16 old;
u16 mask;
s16 ix;
{
    if (sw & mask) {
        if (sw & 0x10) {
            return 1;
        }
        Debug_Rep_Timer[ix]++;
        if (~old & sw & mask) {
            Debug_Rep_Timer[ix] = 0;
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
        if (ix > 3) {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                return 1;
            }
            return 0;
        } else {
            if (Debug_Rep_Timer[ix] > 10) {
                Debug_Rep_Count[ix]++;
                if (Debug_Rep_Count[ix] > 4) {
                    Debug_Rep_Count[ix] = 0;
                    return 1;
                }
            }
            return 0;
        }
    }
    Debug_Rep_Timer[ix] = 0;
    Debug_Rep_Count[ix] = 0;
    return 0;
}

/* provisional name */
u32 debug_held_pad_repeat(sw_now, sw_old, mask, ix)
u16 sw_now;
u16 sw_old;
u16 mask;
u16 ix;
{
    if (sw_now & mask) {
        if (~sw_old & sw_now & mask) {
            Debug_Rep_Timer[ix] = 0;
            Debug_Rep_Count[ix] = 0;
            return 1;
        }
        Debug_Rep_Timer[ix]++;
        if (ix < 4) {
            if (Debug_Rep_Timer[ix] > 12) {
                Debug_Rep_Timer[ix] = 12;
                return 1;
            }
        } else if (Debug_Rep_Timer[ix] > 16) {
            if (++Debug_Rep_Count[ix] > 4) {
                Debug_Rep_Count[ix] = 0;
                return 1;
            }
        }
    } else {
        Debug_Rep_Timer[ix] = 0;
        Debug_Rep_Count[ix] = 0;
    }
    return 0;
}



/* provisional name */
void debug_pattern_timer_update(void) {
    u32* p = dbg_pl->wu.set_char_ad + dbg_pl->wu.cg_ix;

    dbg_slot->frames = *(s8*)p;
    dbg_slot->rest = dbg_slot->frames - dbg_pl->wu.cg_ctr + 1;
}



/* provisional name */
void debug_edit_pattern_timer_update(void) {
    dbg_slot->frames = dbg_edit_buf.rec[dbg_slot->sel[2]].u.frames;
    dbg_slot->rest = dbg_slot->frames + 1 - dbg_pl->wu.cg_ctr;
}



/* provisional name */
void debug_char_table_load(void) {
    dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[dbg_pl->player_number][0];
    dbg_pl->wu.char_table[1] = dbg_pl_char_tbl[dbg_pl->player_number][1];
    dbg_pl->wu.char_table[2] = dbg_pl_char_tbl[dbg_pl->player_number][2];
    dbg_pl->wu.char_table[3] = dbg_pl_char_tbl[dbg_pl->player_number][3];
    dbg_pl->wu.char_table[4] = dbg_pl_char_tbl[dbg_pl->player_number][4];
    dbg_pl->wu.char_table[5] = dbg_pl_char_tbl[dbg_pl->player_number][5];
    dbg_pl->wu.char_table[6] = dbg_pl_char_tbl[dbg_pl->player_number][6];
    dbg_pl->wu.char_table[7] = dbg_pl_char_tbl[dbg_pl->player_number][7];
    dbg_pl->wu.char_table[8] = dbg_pl_char_tbl[dbg_pl->player_number][8];
    dbg_pl->wu.char_table[9] = dbg_pl_char_tbl[dbg_pl->player_number][8];
}



/* provisional name */
void debug_slot_char_load(void) {
    s16 ix;
    s16 n;
    s16 row;
    s16 col;
    u16 group;
    if (dbg_slot->sel[0] <= 0xd8) {
        dbg_pl->wu.operator = 0;
        if (dbg_slot->sel[0] < 10) {
            ix = 0;
        } else {
            ix = (dbg_slot->sel[0] - 1) / 9;
        }
        if (dbg_pl->player_number != ix) {
            dbg_pl->player_number = ix;
            dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
            dbg_pl->wu.my_col_mode = 0x4200;
            debug_char_table_load();
            set_char_base_data_init(&dbg_pl->wu);
            if (dbg_pl->wu.id) {
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                dbg_pl->wu.my_col_code = 0x2000;
            }
            load_player_color(dbg_pl_color_tbl[dbg_pl->player_number], dbg_pl->wu.id, 0);
            set_player_shadow(dbg_pl);
        }
        set_char_move_init(&dbg_pl->wu, dbg_slot->row, 0);
    } else {
        switch (dbg_slot->sel[0]) {
        case 0xd9:
            load_player_color(1, 0, 0);
            dbg_pl->wu.my_col_code = 0x4007;
            break;
        case 0xda:
            dbg_pl->wu.hit_ix_table = (HIT_IX*)&ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = (BODY_BOX*)&ef13_body_box;
            dbg_pl->wu.hand_adrs = (HAND_BOX*)&ef13_hand_box;
            dbg_pl->wu.attack_adrs = (ATTACK_BOX*)&ef13_att_box;
            dbg_pl->wu.catch_adrs = (CATCH_BOX*)&ef13_cat_box;
            dbg_pl->wu.caught_adrs = (CAUGHT_BOX*)&ef13_cau_box;
            dbg_pl->wu.hosei_adrs = (HOSEI_BOX*)&ef13_hos_box;
            dbg_pl->wu.att_ix_table = (ATTACK_ATTR*)&ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[dbg_slot->sel[0] - 0xd7]);
            dbg_pl->wu.my_col_code = 0x4020;
            break;
        case 0xdb:
            dbg_pl->wu.hit_ix_table = (HIT_IX*)&ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = (BODY_BOX*)&ef13_body_box;
            dbg_pl->wu.hand_adrs = (HAND_BOX*)&ef13_hand_box;
            dbg_pl->wu.attack_adrs = (ATTACK_BOX*)&ef13_att_box;
            dbg_pl->wu.catch_adrs = (CATCH_BOX*)&ef13_cat_box;
            dbg_pl->wu.caught_adrs = (CAUGHT_BOX*)&ef13_cau_box;
            dbg_pl->wu.hosei_adrs = (HOSEI_BOX*)&ef13_hos_box;
            dbg_pl->wu.att_ix_table = (ATTACK_ATTR*)&ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[dbg_slot->sel[0] - 0xd7]);
            break;
        case 0xfb:
            dbg_pl->wu.my_col_code = 0x4140;
            load_any_color(dbg_obj_color_tbl[dbg_slot->sel[0] - 0xd7]);
            break;
        default:
            dbg_pl->wu.my_col_mode = 0x4200;
            dbg_pl->wu.my_col_code = 0x4080;
            break;
        }
        dbg_pl->player_number = 0x99;
        dbg_pl->wu.operator = 1;
        n = dbg_slot->sel[0] - 0xd8;
        if (n < 10) {
            col = n - 1;
            row = 0;
        } else {
            col = (n - 1) % 9;
            row = (n - 1) / 9;
        }
        row += 24;
        dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[row][col];
        set_char_move_init(&dbg_pl->wu, 0, 0);
    }
    Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
    dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
    Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (group & 0x8000) {
        if (!(dbg_pl->zuru_timer & 0)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
            dbg_pl->zuru_timer = group;
        }
    } else if (!get_cg_slot_addr(group)) {
        if (!(dbg_pl->zuru_timer & 0x8000)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
        }
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_slot_char_load_keep_col(void) {
    s16 ix;
    s16 n;
    s16 row;
    s16 col;
    u16 group;
    if (dbg_slot->sel[0] <= 0xd8) {
        dbg_pl->wu.operator = 0;
        if (dbg_slot->sel[0] < 10) {
            ix = 0;
        } else {
            ix = (dbg_slot->sel[0] - 1) / 9;
        }
        if (dbg_pl->player_number != ix) {
            dbg_pl->player_number = ix;
            dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
            dbg_pl->wu.my_col_mode = 0x4200;
            debug_char_table_load();
            set_char_base_data_init(&dbg_pl->wu);
            if (dbg_pl->wu.id) {
                dbg_pl->wu.my_col_code = 0x2010;
            } else {
                dbg_pl->wu.my_col_code = 0x2000;
            }
            load_player_color(dbg_pl_color_tbl[dbg_pl->player_number], 0, dbg_pl->wu.id, (u16)dbg_col_no);
            set_player_shadow(dbg_pl);
        }
        set_char_move_init(&dbg_pl->wu, dbg_slot->row, 0);
    } else {
        dbg_pl->wu.my_col_mode = 0x4200;
        dbg_pl->wu.my_col_code = 0x4080;
        if (dbg_slot->sel[0] == 0xd9) {
            load_player_color(1, 0, 0);
            dbg_pl->wu.my_col_code = 0x4007;
        }
        if (dbg_slot->sel[0] == 0xda) {
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[dbg_slot->sel[0] - 0xda]);
            dbg_pl->wu.my_col_code = 0x4020;
        }
        if (dbg_slot->sel[0] == 0xdb) {
            dbg_pl->wu.hit_ix_table = ef13_hit_ix_table;
            dbg_pl->wu.body_adrs = ef13_body_box;
            dbg_pl->wu.hand_adrs = ef13_hand_box;
            dbg_pl->wu.attack_adrs = ef13_att_box;
            dbg_pl->wu.catch_adrs = ef13_cat_box;
            dbg_pl->wu.caught_adrs = ef13_cau_box;
            dbg_pl->wu.hosei_adrs = ef13_hos_box;
            dbg_pl->wu.att_ix_table = ef13_catt_table;
            load_any_color(dbg_obj_color_tbl[dbg_slot->sel[0] - 0xdb]);
            dbg_pl->wu.my_col_code = 0x4040;
        }
        dbg_pl->player_number = 0x99;
        dbg_pl->wu.operator = 1;
        n = dbg_slot->sel[0] - 0xd8;
        if (n < 10) {
            col = n - 1;
            row = 0;
        } else {
            col = (n - 1) % 9;
            row = (n - 1) / 9;
        }
        row += 24;
        dbg_pl->wu.char_table[0] = dbg_pl_char_tbl[row][col];
        set_char_move_init(&dbg_pl->wu, 0, 0);
    }
    Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip;
    dbg_pl->wu.cg_flip ^= Debug_Flip_Mask[dbg_pl->wu.id];
    Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag;
    dbg_pl->wu.disp_flag = check_cg_data(dbg_pl->wu.cg_number);
    if (dbg_pl->wu.disp_flag == 0) {
        dbg_pl->wu.old_cgnum = dbg_pl->wu.cg_number;
    }
    group = get_cg_slot_no(dbg_pl->wu.cg_number);
    if (group & 0x8000) {
        if (!(dbg_pl->zuru_timer & 0)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
            dbg_pl->zuru_timer = group;
        }
    } else if (!get_cg_slot_addr(group)) {
        if (!(dbg_pl->zuru_timer & 0x8000)) {
            purge_char_gfx(dbg_pl->wu.old_rno[0]);
        }
        dbg_pl->zuru_timer = group;
    }
}



/* provisional name */
void debug_char_disp(WORK* wk) {
    wk->position_x = wk->xyz[0].disp.pos;
    wk->position_y = wk->xyz[1].disp.pos;
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
}


/* provisional name */
void debug_char_disp_sort(WORK* wk) {
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
}



/* provisional name */
void debug_char_disp_once(WORK* wk) {
    wk->be_flag = 1;
    wk->disp_flag = 1;
    wk->position_z = wk->my_priority;
    sort_push_request(wk);
    wk->be_flag = 0;
    wk->disp_flag = 0;
}



/* provisional name */
void debug_parts_disp(void) {
    s16 i;
    for (i = 0; i < 4; i++) {
        dbg_parts_plw[i].wu.position_x = plw[0].wu.position_x;
        dbg_parts_plw[i].wu.position_y = plw[0].wu.position_y;
        dbg_parts_plw[i].wu.position_z = plw[0].wu.position_z;
        dbg_parts_plw[i].wu.rl_flag = plw[0].wu.rl_flag;
        if (dbg_parts_plw[i].wu.dir_old & 4) {
            dbg_parts_plw[i].wu.cg_flip = dbg_parts_plw[i].wu.dir_old ^= plw[0].wu.cg_flip;
            if (plw[0].wu.cg_flip & 1) {
                dbg_parts_plw[i].wu.rl_flag = (dbg_parts_plw[i].wu.rl_flag + 1) & 1;
            }
        }
        if (dbg_parts_plw[i].wu.rl_flag) {
            dbg_parts_plw[i].wu.position_x -= dbg_parts_plw[i].wu.dir_step;
        } else {
            dbg_parts_plw[i].wu.position_x += dbg_parts_plw[i].wu.dir_step;
        }
        dbg_parts_plw[i].wu.position_y += dbg_parts_plw[i].wu.dir_timer;
        if (dbg_parts_plw[i].wu.dir_old & 4) {
            if (plw[0].wu.cg_flip & 2) {
                dbg_parts_plw[i].wu.position_y -= dbg_parts_plw[i].wu.dir_timer * 2;
            }
        }
        if (dbg_parts_plw[i].wu.old_rno[1] == 2) {
            dbg_parts_plw[i].wu.position_z -= (i + 1) * 2;
        } else {
            dbg_parts_plw[i].wu.position_z += (i + 1) * 2;
        }
        sort_push_request(&dbg_parts_plw[i].wu);
    }
}



/* provisional name */
void debug_pattern_edit_init_counts(void) {
    u32** pat;
    ((DBG_SLOT*)&dbg_slot_w[0])->sel[0] = 1;
    ((DBG_SLOT*)&dbg_slot_w[1])->sel[0] = 1;
    ((DBG_SLOT*)&dbg_slot_w[0])->sel0_max = 0;
    ((DBG_SLOT*)&dbg_slot_w[1])->sel0_max = 0;
    for (pat = dbg_pl_char_tbl[0]; *pat; pat++) {
        ((DBG_SLOT*)&dbg_slot_w[0])->sel0_max++;
        ((DBG_SLOT*)&dbg_slot_w[1])->sel0_max++;
    }
}



/* provisional name */
void debug_motion_list_count(void) {
    u32* p;
    dbg_slot->sel[1] = 1;
    if (dbg_slot->sel[0] > 0xD8) {
        p = dbg_pl->wu.char_table[0];
    } else {
        switch (dbg_slot->row) {
        case 0:
            p = dbg_pl->wu.char_table[0];
            break;
        case 1:
            p = dbg_pl->wu.char_table[1];
            break;
        case 2:
            p = dbg_pl->wu.char_table[2];
            break;
        case 3:
            p = dbg_pl->wu.char_table[3];
            break;
        case 4:
            p = dbg_pl->wu.char_table[4];
            break;
        case 5:
            p = dbg_pl->wu.char_table[5];
            break;
        case 6:
            p = dbg_pl->wu.char_table[6];
            break;
        case 7:
            p = dbg_pl->wu.char_table[7];
            break;
        case 8:
        case 9:
            p = dbg_pl->wu.char_table[9];
            break;
        default:
            break;
        }
    }
    dbg_slot->sel1_max = 0;
    while (*p) {
        p++;
        dbg_slot->sel1_max++;
    }
}



/* provisional name */
void debug_pattern_count(void) {
    u32* p;
    dbg_slot->sel[2] = 0;
    p = dbg_pl->wu.set_char_ad;
    dbg_slot->rec_count = 0;
    while (1) {
        u32* q = p;
        if (*(u16*)q == 1) {
            break;
        }
        if (*(u16*)q >= 0x100) {
            dbg_slot->rec_count++;
        }
        p += dbg_pl->wu.cgd_type;
    }
}



/* provisional name */
void debug_pattern_entry_copy_dual(s16 n, s16 box) {
    u16* src;
    u16* a;
    u16* b;
    s16 i;
    HIT_IX* ix;
    src = (u16*)&dbg_pl->wu.hit_ix_table[box];
    a = dbg_look_buf.hit_ix[n];
    b = dbg_edit_buf.hit_ix[n];
    for (i = 0; i < 8; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    ix = &dbg_pl->wu.hit_ix_table[box];
    src = (u16*)&dbg_pl->wu.body_adrs[ix->boix];
    a = (u16*)&dbg_look_buf.body_adrs[n];
    b = (u16*)&dbg_edit_buf.body_adrs[n];
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.hand_adrs[ix->bhix + ix->haix];
    a = (u16*)&dbg_look_buf.hand_adrs[n];
    b = (u16*)&dbg_edit_buf.hand_adrs[n];
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.attack_adrs[ix->atix];
    a = (u16*)&dbg_look_buf.attack_adrs[n];
    b = (u16*)&dbg_edit_buf.attack_adrs[n];
    for (i = 0; i < 16; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.catch_adrs[ix->caix];
    a = (u16*)&dbg_look_buf.catch_adrs[n];
    b = (u16*)&dbg_edit_buf.catch_adrs[n];
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.caught_adrs[ix->cuix];
    a = (u16*)&dbg_look_buf.caught_adrs[n];
    b = (u16*)&dbg_edit_buf.caught_adrs[n];
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
    src = (u16*)&dbg_pl->wu.hosei_adrs[ix->hoix];
    a = (u16*)&dbg_look_buf.hosei_adrs[n];
    b = (u16*)&dbg_edit_buf.hosei_adrs[n];
    for (i = 0; i < 4; i++) {
        *a++ = *src;
        *b++ = *src++;
    }
}



/* provisional name */
void debug_pattern_list_build(void) {
    union {
        u32 l;
        struct {
            s16 hi;
            s16 lo;
        } w;
        s16 s[2];
    } v;
    s16 n;
    u32* p;
    u16* q;
    PATTERN_REC* r;
    dbg_slot->sel[2] = 1;
    dbg_slot->rec_count = 0;
    n = 0;
    p = dbg_pl->wu.set_char_ad;
    while (1) {
        q = (u16*)p;
        if (*q == 1) {
            break;
        }
        if (*q >= 0x100) {
            n++;
            dbg_slot->rec_count++;
            q = (u16*)p;
            r = &dbg_look_buf.rec[dbg_slot->rec_count];
            r->u.code = q[0];
            r = &dbg_edit_buf.rec[dbg_slot->rec_count];
            r->u.code = q[0];
            dbg_look_buf.rec[dbg_slot->rec_count].type = dbg_pl->wu.cgd_type;
            dbg_look_buf.rec[dbg_slot->rec_count].param = q[3];
            if (dbg_pl->wu.cgd_type != 2) {
                v.s[0] = q[4];
                v.w.lo = q[5];
            } else {
                v.s[0] = 0;
                v.w.lo = 0;
            }
            v.l <<= 3;
            dbg_look_buf.rec[dbg_slot->rec_count].box = v.w.hi & 0x1FF;
            dbg_edit_buf.rec[dbg_slot->rec_count].type = dbg_pl->wu.cgd_type;
            dbg_edit_buf.rec[dbg_slot->rec_count].param = q[3];
            if (dbg_pl->wu.cgd_type != 2) {
                v.w.hi = q[4];
                v.w.lo = q[5];
            } else {
                v.w.hi = 0;
                v.w.lo = 0;
            }
            v.l <<= 3;
            dbg_edit_buf.rec[dbg_slot->rec_count].box = v.w.hi & 0x1FF;
            debug_pattern_entry_copy_dual(n, dbg_look_buf.rec[n].box);
        }
        p += dbg_pl->wu.cgd_type;
    }
}

/* provisional name */
void debug_pattern_preview_restart(WORK* wk) {
    dbg_pl->wu.cg_ctr = 1;
    debug_pattern_preview_step(wk);
}

/* provisional name */
void debug_pattern_preview_step(WORK* wk)
{
    if (--dbg_pl->wu.cg_ctr != 0) {
        return;
    }
    dbg_slot->sel[2]++;
    if (dbg_slot->sel[2] > dbg_slot->rec_count) {
        dbg_slot->sel[2] = 1;
    }
    wk->cg_olc = wk->olc_ix_table[wk->cg_olc_ix];
    if (((WORK_Other_JUDGE *)dbg_judge_ewk)->look_up_flag) {
        wk->cgd_type = dbg_look_buf.rec[dbg_slot->sel[2]].type;
        wk->cg_ctr = dbg_look_buf.rec[dbg_slot->sel[2]].u.frames;
        wk->cg_number = dbg_look_buf.rec[dbg_slot->sel[2]].param;
        wk->cg_hit_ix = dbg_look_buf.rec[dbg_slot->sel[2]].box;
        if (wk->cg_att_ix) {
            set_new_attnum(wk);
        }
        wk->cg_ja = wk->hit_ix_table[wk->cg_hit_ix];
        wk->h_bod = wk->body_adrs + dbg_look_buf.hit_ix[dbg_slot->sel[2]][0];
        wk->h_han = wk->hand_adrs + (dbg_look_buf.hit_ix[dbg_slot->sel[2]][2] + dbg_look_buf.hit_ix[dbg_slot->sel[2]][1]);
        wk->h_cat = wk->catch_adrs + dbg_look_buf.hit_ix[dbg_slot->sel[2]][4];
        wk->h_cau = wk->caught_adrs + dbg_look_buf.hit_ix[dbg_slot->sel[2]][5];
        wk->h_att = wk->attack_adrs + dbg_look_buf.hit_ix[dbg_slot->sel[2]][6];
        wk->h_hos = wk->hosei_adrs + dbg_look_buf.hit_ix[dbg_slot->sel[2]][7];
    } else {
        wk->cgd_type = dbg_edit_buf.rec[dbg_slot->sel[2]].type;
        wk->cg_ctr = dbg_edit_buf.rec[dbg_slot->sel[2]].u.frames;
        wk->cg_number = dbg_edit_buf.rec[dbg_slot->sel[2]].param;
        wk->cg_hit_ix = dbg_edit_buf.rec[dbg_slot->sel[2]].box;
        wk->h_bod = wk->body_adrs + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][0];
        wk->h_han = wk->hand_adrs + (dbg_edit_buf.hit_ix[dbg_slot->sel[2]][2] + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][1]);
        wk->h_cat = wk->catch_adrs + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][4];
        wk->h_cau = wk->caught_adrs + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][5];
        wk->h_att = wk->attack_adrs + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][6];
        wk->h_hos = wk->hosei_adrs + dbg_edit_buf.hit_ix[dbg_slot->sel[2]][7];
    }
    if (wk->cg_type == 0xFF) {
        return;
    }
    if (!(wk->cg_type & 0x80)) {
        return;
    }
    wk->cg_wca_ix = wk->cg_type & 0x7F;
    wk->cg_type = 0;
}



/* provisional name */
void debug_save_player_snapshot(SNAPSHOT* rec, WORK* wk) {
    rec->pos_x = wk->xyz[0].disp.pos;
    rec->pos_y = wk->xyz[1].disp.pos;
    rec->priority = wk->my_priority;
    rec->cg_number = wk->cg_number;
    rec->dbg_rl_flag = Debug_RL_Flag[wk->id];
    rec->dbg_cg_flip = Debug_CG_Flip[wk->id];
    rec->used = 1;
    rec->col_mode = wk->my_col_mode;
    rec->col_code = wk->my_col_code;
    rec->olc_ix = wk->cg_olc_ix;
    rec->rl_flag = wk->rl_flag;
    rec->cg_flip = wk->cg_flip;
    if (dbg_save_mode) {
        rec->cg_ctr = wk->cg_ctr;
    }
}



/* provisional name */
void debug_copy_player_snapshot(SNAPSHOT* src, SNAPSHOT* dst) {
    dst->pos_x = src->pos_x;
    dst->pos_y = src->pos_y;
    dst->priority = src->priority;
    dst->cg_number = src->cg_number;
    dst->dbg_rl_flag = src->dbg_rl_flag;
    dst->dbg_cg_flip = src->dbg_cg_flip;
    dst->used = 1;
    dst->cg_ctr = src->cg_ctr;
    dst->col_mode = src->col_mode;
    dst->col_code = src->col_code;
    dst->olc_ix = src->olc_ix;
    dst->rl_flag = src->rl_flag;
    dst->cg_flip = src->cg_flip;
}



/* provisional name */
void debug_restore_player_snapshot(SNAPSHOT* rec, WORK* wk) {
    wk->xyz[0].disp.pos = rec->pos_x;
    wk->xyz[1].disp.pos = rec->pos_y;
    wk->my_priority = rec->priority;
    wk->cg_number = rec->cg_number;
    wk->my_col_mode = rec->col_mode;
    wk->my_col_code = rec->col_code;
    wk->cg_olc_ix = rec->olc_ix;
    wk->rl_flag = rec->rl_flag;
    wk->cg_flip = rec->cg_flip;
    set_char_olc_data(wk);
}



/* provisional name */
void debug_snapshot_to_ghost(WORK* wk, SNAPSHOT* rec) {
    wk->position_x = rec->pos_x;
    wk->position_y = rec->pos_y;
    wk->my_priority = rec->priority;
    wk->cg_number = rec->cg_number;
    wk->my_col_mode = rec->col_mode;
    wk->my_col_code = rec->col_code;
    wk->cg_olc_ix = rec->olc_ix;
    wk->rl_flag = rec->rl_flag;
    wk->cg_flip = rec->cg_flip;
}



/* provisional name */
s32 debug_hex4_to_bcd(s16 x) {
    s16 digit[4];
    s16 i;
    s32 n;
    s16 div = 1000;
    s32 a;
    s32 b;
    s32 c;
    for (i = 0; i < 4; i++) {
        n = 0;
        while (1) {
            x -= div;
            if (x < 0) {
                break;
            }
            n++;
        }
        digit[i] = n;
        x = x + div;
        div /= 10;
    }
    a = digit[0] << 12;
    a &= 0xF000;
    b = digit[1] << 8;
    b &= 0xF00;
    c = digit[2] << 4;
    c &= 0xF0;
    a |= b;
    a |= c;
    a |= digit[3];
    return (s16)a;
}



/* provisional name */
s16 debug_cg_bank_kind(u16 code) {
    if (code >= 0xD800) {
        return 2;
    } else if (code >= 0x9000) {
        return 1;
    } else {
        return 0;
    }
}

/* provisional name */
void debug_draw_cg_group(code, n, x, y, attr)
    u16 code;
    s16 n;
    s32 x;
    s32 y;
    s16 attr;
{
    switch (debug_cg_bank_kind(code)) {
    case 0:
        tilemap_print_string_attr(x, y, attr, dbg_bcp_str);
        break;
    case 1:
        tilemap_print_string_attr(x, y, attr, dbg_bce_str);
        break;
    case 2:
        tilemap_print_string_attr(x, y, attr, dbg_bcb_str);
        break;
    }
    n = debug_hex4_to_bcd(n);
    tilemap_print_hex(x + 3, y, attr, n, 2, 0);
}

/* provisional name */
void debug_draw_cg_group_offset(code, ix, x, y, attr)
    u16 code;
    s16 ix;
    s16 x;
    s16 y;
    s16 attr;
{
    s16 base;
    switch (debug_cg_bank_kind(code)) {
    case 0:
        base = bcp_group_top_tbl[ix];
        break;
    case 1:
        base = bce_group_top_tbl[ix];
        break;
    case 2:
        base = bcb_group_top_tbl[ix];
        break;
    }
    tilemap_print_string_attr(x - 1, y, attr, dbg_plus_str);
    base = code - base;
    tilemap_print_hex(x, y, attr, base, 4, 0);
}



/* provisional name */
void debug_draw_object_info(void) {
    s16 num;
    s16 pat;
    const TM_STRING* p;
    num = debug_hex4_to_bcd(dbg_slot->sel[0]);
    tilemap_print_hex(10, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel0_max);
    tilemap_print_hex(14, 4, 2, num, 3, 0);
    if (DEBUG_DISP) {
        num = debug_hex4_to_bcd(dbg_slot->rec_count);
        tilemap_print_hex(18, 4, 2, num, 3, 0);
    }
    num = debug_hex4_to_bcd(dbg_slot->sel[1]);
    tilemap_print_hex(10, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel1_max);
    tilemap_print_hex(14, 6, 2, num, 3, 0);
    if (Debug_Menu_No == 4) {
        pat = debug_hex4_to_bcd(dbg_slot->sel[2]);
    } else {
        pat = debug_hex4_to_bcd(dbg_slot->sel[2] + 1);
    }
    tilemap_print_hex(11, 8, 2, pat, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->rec_count);
    tilemap_print_hex(14, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->rest);
    tilemap_print_hex(11, 9, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->frames);
    tilemap_print_hex(14, 9, 2, num, 2, 0);
    tilemap_print_hex(11, 10, 2, dbg_pl->wu.cg_number, 4, 0);
    switch (Debug_CG_Flip[dbg_pl->wu.id]) {
    case 0:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_hv_str);
        break;
    }
    if (Debug_RL_Flag[dbg_pl->wu.id]) {
        tilemap_print_string_attr(13, 11, 2, dbg_flag_on_str);
    } else {
        tilemap_print_string_attr(13, 11, 2, dbg_flag_off_str);
    }
    switch (dbg_pl->wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_hv_str);
        break;
    }
    if (dbg_pl->wu.rl_flag) {
        tilemap_print_string_attr(13, 12, 2, dbg_flag_on_str);
    } else {
        tilemap_print_string_attr(13, 12, 2, dbg_flag_off_str);
    }
    tilemap_print_hex(11, 13, 2, dbg_pl->wu.position_x, 4, 0);
    tilemap_print_hex(11, 14, 2, dbg_pl->wu.position_y, 4, 0);
    if (dbg_slot->sel[0] <= 216) {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[dbg_slot->row]);
        tilemap_print_string(0, 0, 0xFFFF, &(*(dbg_slot->row + dbg_act_name_tbl))[dbg_slot->sel[1] - 1]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[dbg_pl->player_number]);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[10]);
        p = dbg_act_name_tbl[10];
        p = &p[dbg_slot->sel[0] - 217];
        tilemap_print_string(0, 0, 0xFFFF, p);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[16]);
    }
}



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


/* provisional name */
void debug_draw_kakusyuku_frame_flags(void) {
    switch (dbg_kakusyuku_mode) {
    case 0:
        tilemap_print_string_attr(1, 16, 2, "KAKUSYUKU  OFF");
        tilemap_print_string_attr(1, 17, 2, "FRAME      OFF");
        break;
    case 1:
        tilemap_print_string_attr(1, 17, 2, "FRAME      ON ");
        break;
    case 2:
        tilemap_print_string_attr(1, 16, 2, "KAKUSYUKU  ON ");
        tilemap_print_string_attr(1, 17, 2, "FRAME      OFF");
        break;
    case 3:
        tilemap_print_string_attr(1, 17, 2, "FRAME      ON ");
        break;
    }
}



/* provisional name */
void debug_draw_position_delta(void) {
    s16 d;
    s16 bcd;
    d = plw[1].wu.xyz[0].disp.pos;
    d -= plw[0].wu.xyz[0].disp.pos;
    if (d < 0) {
        tilemap_print_string_attr(10, 15, 2, dbg_minus_str);
        d = -d;
    } else {
        tilemap_print_string_attr(10, 15, 2, " ");
    }
    if (Debug_Dec_Disp) {
        bcd = debug_hex4_to_bcd(d);
        tilemap_print_hex(11, 15, 2, bcd, 4, 0);
        tilemap_print_string_attr(15, 15, 2, dbg_space2_str);
    } else {
        tilemap_print_hex(11, 15, 2, d, 4, 0);
        tilemap_print_string_attr(15, 15, 2, dbg_hex_mark_str);
    }
    d = plw[1].wu.xyz[1].disp.pos;
    d -= plw[0].wu.xyz[1].disp.pos;
    if (d < 0) {
        tilemap_print_string_attr(10, 16, 2, dbg_minus_str);
        d = -d;
    } else {
        tilemap_print_string_attr(10, 16, 2, " ");
    }
    if (Debug_Dec_Disp) {
        bcd = debug_hex4_to_bcd(d);
        tilemap_print_hex(11, 16, 2, bcd, 4, 0);
        tilemap_print_string_attr(15, 16, 2, dbg_space2_str);
    } else {
        tilemap_print_hex(11, 16, 2, d, 4, 0);
        tilemap_print_string_attr(15, 16, 2, dbg_hex_mark_str);
    }
}

/* provisional name */
void debug_draw_edit_side(void) {
    if (Debug_PL_id) {
        tilemap_print_string_attr(11, 17, 2, dbg_2p_str);
    } else {
        tilemap_print_string_attr(11, 17, 2, dbg_1p_str);
    }
}

/* provisional name */
void debug_draw_hit_edit_info(void)
{
    s16 i;
    s16 num;
    HIT_IX *hit;
    u16 x;

    tilemap_rect_fill(dbg_hud_x + 40, ((WORK_Other_JUDGE *)dbg_judge_ewk)->curr_ja + 12, 8, 1, 14, 0xFFFF);
    if (Debug_Box_Edit) {
        tilemap_print_string_attr(dbg_hud_x + 40, 8, 6, dbg_hold_str);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 40, 8, 14, dbg_free_str);
    }
    if (DEBUG_DISP) {
        tilemap_print_string_attr(dbg_hud_x + 40, 9, 6, dbg_copy_str);
    }
    if (dbg_copy_done) {
        if (dbg_copy_pat == dbg_slot->sel[2] && dbg_pl->wu.char_index == dbg_copy_char) {
            tilemap_print_string_attr(dbg_hud_x + 40, 9, 6, dbg_copy_str);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 40, 9, 14, dbg_copy_str);
        }
    } else {
        tilemap_print_string_attr(dbg_hud_x + 40, 9, 14, dbg_copy_str);
    }
    if (((WORK_Other_JUDGE *)dbg_judge_ewk)->look_up_flag) {
        tilemap_print_string_attr(dbg_hud_x + 40, 10, 2, dbg_user_str);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 40, 10, 2, dbg_define_str);
    }

    /* the four edit-box values, signed */
    for (i = 0; i < 4; i++) {
        num = dbg_edit_box[i];
        if (num < 0) {
            tilemap_print_string_attr(10, i + 15, 2, dbg_minus_str);
            num = -num;
        } else {
            tilemap_print_string_attr(10, i + 15, 2, " ");
        }
        tilemap_print_hex(11, i + 15, 2, num, 4, 0);
    }

    /* hit-index row of the current pattern */
    num = remake_2_10((u16)dbg_edit_buf.rec[dbg_slot->sel[2]].box, 3);
    tilemap_print_hex(4, 20, 2, num, 3, 0);
    hit = &dbg_pl->wu.hit_ix_table[(u16)dbg_edit_buf.rec[dbg_slot->sel[2]].box];
    tilemap_print_hex(12, 20, 2, remake_2_10(hit->boix, 3), 3, 0);
    tilemap_print_hex(12, 21, 2, remake_2_10(hit->bhix, 3), 3, 0);
    tilemap_print_hex(12, 22, 2, remake_2_10(hit->haix, 3), 3, 0);
    tilemap_print_hex(12, 23, 2, remake_2_10(hit->caix, 3), 3, 0);
    tilemap_print_hex(12, 24, 2, remake_2_10(hit->cuix, 3), 3, 0);
    tilemap_print_hex(12, 25, 2, remake_2_10(hit->atix, 3), 3, 0);
    tilemap_print_hex(12, 26, 2, remake_2_10(hit->hoix, 3), 3, 0);
    tilemap_print_string_attr(2, 24, 2, hit_kind_tbl[hit->mf.half.bx].name);
    tilemap_print_string_attr(5, 24, 2, hit_kind_tbl[hit->mf.half.mv].name);

    x = dbg_hud_x + 5;
    tilemap_print_string_attr(x, 21, 2, Debug_PL_id ? dbg_2p_str : dbg_1p_str);
}



/* provisional name */
void debug_draw_cm_summary(void) {
    s16 num;
    tilemap_print_string_attr(5, 25, 10, dbg_lp_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.code);
    tilemap_print_hex(8, 25, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmlp_str[dbg_pl->wu.cmlp.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.ix);
    tilemap_print_hex(15, 25, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmlp.pat);
    tilemap_print_string_attr(19, 25, 10, dbg_nix_str);
    tilemap_print_hex(22, 25, 10, num, 2, 0);
    tilemap_print_string_attr(5, 26, 10, dbg_l2_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.code);
    tilemap_print_hex(8, 26, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cml2_str[dbg_pl->wu.cml2.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.ix);
    tilemap_print_hex(15, 26, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cml2.pat);
    tilemap_print_string_attr(19, 26, 10, dbg_nix_str);
    tilemap_print_hex(22, 26, 10, num, 2, 0);
    tilemap_print_string_attr(5, 27, 10, dbg_sw_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.code);
    tilemap_print_hex(8, 27, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmsw_str[dbg_pl->wu.cmsw.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.ix);
    tilemap_print_hex(15, 27, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmsw.pat);
    tilemap_print_string_attr(19, 27, 10, dbg_nix_str);
    tilemap_print_hex(22, 27, 10, num, 2, 0);
    tilemap_print_string_attr(25, 25, 10, dbg_ja_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.code);
    tilemap_print_hex(28, 25, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmja_str[dbg_pl->wu.cmja.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.ix);
    tilemap_print_hex(35, 25, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmja.pat);
    tilemap_print_string_attr(39, 25, 10, dbg_nix_str);
    tilemap_print_hex(42, 25, 10, num, 2, 0);
    tilemap_print_string_attr(25, 26, 10, dbg_j2_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.code);
    tilemap_print_hex(28, 26, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmja_str[dbg_pl->wu.cmj2.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.ix);
    tilemap_print_hex(35, 26, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmj2.pat);
    tilemap_print_string_attr(39, 26, 10, dbg_nix_str);
    tilemap_print_hex(42, 26, 10, num, 2, 0);
    tilemap_print_string_attr(25, 27, 10, dbg_oa_str);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.code);
    tilemap_print_hex(28, 27, 10, num, 3, 0);
    tilemap_print_string(0, 0, 0xFFFF, &dbg_koc_cmoa_str[dbg_pl->wu.cmoa.koc]);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.ix);
    tilemap_print_hex(35, 27, 10, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_pl->wu.cmoa.pat);
    tilemap_print_string_attr(39, 27, 10, dbg_nix_str);
    tilemap_print_hex(42, 27, 10, num, 2, 0);
}

/* provisional name */
void debug_draw_cm_data(void)
{
    s16 bcd;

    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmoa.koc]);
    tilemap_print_string(dbg_hud_x, 1, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmsw.koc]);
    tilemap_print_string(dbg_hud_x, 2, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmlp.koc]);
    tilemap_print_string(dbg_hud_x, 3, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cml2.koc]);
    tilemap_print_string(dbg_hud_x, 4, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmja.koc]);
    tilemap_print_string(dbg_hud_x, 5, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmj2.koc]);
    tilemap_print_string(dbg_hud_x, 6, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmj3.koc]);
    tilemap_print_string(dbg_hud_x, 7, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmj4.koc]);
    tilemap_print_string(dbg_hud_x, 8, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmms.koc]);
    tilemap_print_hex(dbg_hud_x + 32, 11, 10, dbg_pl->wu.cmmd.koc, 2, 0);
    tilemap_print_hex(dbg_hud_x + 32, 12, 10, dbg_pl->wu.cmyd.koc, 2, 0);
    tilemap_print_string(dbg_hud_x, 11, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmcf.koc]);
    tilemap_print_string(dbg_hud_x, 12, 0xFFFF, &dbg_koc_str[dbg_pl->wu.cmcr.koc]);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmoa.ix);
    tilemap_print_hex(dbg_hud_x + 35, 2, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmoa.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 2, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 2, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmsw.ix);
    tilemap_print_hex(dbg_hud_x + 35, 3, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmsw.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 3, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 3, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmlp.ix);
    tilemap_print_hex(dbg_hud_x + 35, 4, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmlp.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 4, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 4, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cml2.ix);
    tilemap_print_hex(dbg_hud_x + 35, 5, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cml2.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 5, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 5, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmja.ix);
    tilemap_print_hex(dbg_hud_x + 35, 6, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmja.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 6, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 6, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj2.ix);
    tilemap_print_hex(dbg_hud_x + 35, 7, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj2.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 7, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 7, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj3.ix);
    tilemap_print_hex(dbg_hud_x + 35, 8, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj3.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 8, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 8, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj4.ix);
    tilemap_print_hex(dbg_hud_x + 35, 9, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmj4.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 9, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 9, 10, bcd, 2, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmms.ix);
    tilemap_print_hex(dbg_hud_x + 35, 10, 10, bcd, 3, 0);
    bcd = debug_hex4_to_bcd(dbg_pl->wu.cmms.pat);
    tilemap_print_string_attr(dbg_hud_x + 39, 10, 10, dbg_nix_str);
    tilemap_print_hex(dbg_hud_x + 42, 10, 10, bcd, 2, 0);
    tilemap_print_hex(dbg_hud_x + 35, 11, 10, dbg_pl->wu.cmmd.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 11, 10, dbg_pl->wu.cmmd.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 12, 10, dbg_pl->wu.cmyd.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 12, 10, dbg_pl->wu.cmyd.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 13, 10, dbg_pl->wu.cmcf.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 13, 10, dbg_pl->wu.cmcf.pat, 3, 0);
    tilemap_print_hex(dbg_hud_x + 35, 14, 10, dbg_pl->wu.cmcr.ix, 3, 0);
    tilemap_print_hex(dbg_hud_x + 41, 14, 10, dbg_pl->wu.cmcr.pat, 3, 0);
}



/* provisional name */
void debug_draw_delta_and_side(void)
{
  debug_draw_position_delta();
  debug_draw_edit_side();
  return;
}



/* provisional name */
void debug_draw_record_info(void) {
    s16 bcd;
    debug_draw_position_delta();
    debug_draw_edit_side();
    bcd = ((s16)debug_hex4_to_bcd(Debug_Rec_Count));
    tilemap_print_hex(11, 19, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(Debug_Rec_Frame));
    tilemap_print_hex(11, 18, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(dbg_snap_ptr->used));
    tilemap_print_hex(11, 20, 2, bcd, 4, 0);
    bcd = ((s16)debug_hex4_to_bcd(dbg_snap_ptr->cg_ctr));
    tilemap_print_hex(11, 21, 2, bcd, 4, 0);
    switch (dbg_save_mode) {
    case 0:
        tilemap_print_string_attr(1, 23, 6, dbg_over_write_str);
        break;
    case 1:
        tilemap_print_string_attr(1, 23, 6, dbg_insert_str);
        break;
    case 2:
        tilemap_print_string_attr(1, 23, 6, dbg_addition_str);
        break;
    }
}

/* provisional name */
void debug_draw_parts_info(void)
{
    const char *str;
    s16 num;

    num = debug_hex4_to_bcd(dbg_slot->sel[0]);
    tilemap_print_hex(10, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel0_max);
    tilemap_print_hex(14, 4, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel[1]);
    tilemap_print_hex(10, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel1_max);
    tilemap_print_hex(14, 6, 2, num, 3, 0);
    num = debug_hex4_to_bcd(dbg_slot->sel[2] + 1);
    tilemap_print_hex(11, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->rec_count);
    tilemap_print_hex(14, 8, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->rest);
    tilemap_print_hex(11, 9, 2, num, 2, 0);
    num = debug_hex4_to_bcd(dbg_slot->frames);
    tilemap_print_hex(14, 9, 2, num, 2, 0);
    tilemap_print_hex(11, 10, 2, dbg_pl->wu.cg_number, 4, 0);

    switch (Debug_CG_Flip[dbg_pl->wu.id]) {
    case 0:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 11, 2, dbg_flip_hv_str);
        break;
    }
    if (Debug_RL_Flag[dbg_pl->wu.id]) {
        str = dbg_flag_on_str;
    } else {
        str = dbg_flag_off_str;
    }
    tilemap_print_string_attr(13, 11, 2, str);

    switch (dbg_pl->wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 12, 2, dbg_flip_hv_str);
        break;
    }
    if (dbg_pl->wu.rl_flag) {
        str = dbg_flag_on_str;
    } else {
        str = dbg_flag_off_str;
    }
    tilemap_print_string_attr(13, 12, 2, str);

    if (dbg_slot->sel[0] <= 216) {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[dbg_slot->row]);
        tilemap_print_string(0, 0, 0xFFFF, &(*(dbg_slot->row + dbg_act_name_tbl))[dbg_slot->sel[1] - 1]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[dbg_pl->player_number]);
    } else {
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_kind_str[10]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_act_name_tbl[10][dbg_slot->sel[0] - 217]);
        tilemap_print_string(0, 0, 0xFFFF, &dbg_char_name_str[26]);
    }

    if (Debug_PL_id) {
        str = dbg_2p_str;
    } else {
        str = dbg_1p_str;
    }
    tilemap_print_string_attr(11, 13, 2, str);

    /* the selected part */
    num = dbg_parts_plw[dbg_parts_sel].wu.dir_step;
    if (num < 0) {
        tilemap_print_string_attr(10, 14, 10, dbg_minus_str);
        num = -num;
    } else {
        tilemap_print_string_attr(10, 14, 10, " ");
    }
    tilemap_print_hex(11, 14, 2, num, 4, 0);
    num = dbg_parts_plw[dbg_parts_sel].wu.dir_timer;
    if (num < 0) {
        tilemap_print_string_attr(10, 15, 10, dbg_minus_str);
        num = -num;
    } else {
        tilemap_print_string_attr(10, 15, 10, " ");
    }
    tilemap_print_hex(11, 15, 2, num, 4, 0);
    switch (dbg_parts_plw[dbg_parts_sel].wu.cg_flip) {
    case 0:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_no_str);
        break;
    case 1:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_h_str);
        break;
    case 2:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_v_str);
        break;
    case 3:
        tilemap_print_string_attr(11, 16, 2, dbg_flip_hv_str);
        break;
    }

    str = dbg_nothing_str;
    switch (dbg_parts_sel) {
    case 0:
        tilemap_print_string_attr(1, 23, 6, dbg_parts1_str);
        if (dbg_parts_olc_ix[0]) {
            tilemap_print_string_attr(8, 23, 6, dbg_blank8_str);
        } else {
            tilemap_print_string_attr(8, 23, 6, str);
        }
        break;
    case 1:
        tilemap_print_string_attr(1, 23, 6, dbg_parts2_str);
        if (dbg_parts_olc_ix[1]) {
            tilemap_print_string_attr(8, 23, 6, dbg_blank8_str);
        } else {
            tilemap_print_string_attr(8, 23, 6, str);
        }
        break;
    case 2:
        tilemap_print_string_attr(1, 23, 6, dbg_parts3_str);
        if (dbg_parts_olc_ix[2]) {
            tilemap_print_string_attr(8, 23, 6, dbg_blank8_str);
        } else {
            tilemap_print_string_attr(8, 23, 6, str);
        }
        break;
    case 3:
        tilemap_print_string_attr(1, 23, 6, dbg_parts4_str);
        if (dbg_parts_olc_ix[3]) {
            tilemap_print_string_attr(8, 23, 6, dbg_blank8_str);
        } else {
            tilemap_print_string_attr(8, 23, 6, str);
        }
        break;
    }

    num = debug_hex4_to_bcd(dbg_parts_plw[0].wu.cg_olc_ix);
    tilemap_print_hex(11, 17, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[0].wu.cg_olc.olc_ix[0]);
    tilemap_print_hex(11, 18, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[1].wu.cg_olc.olc_ix[1]);
    tilemap_print_hex(11, 19, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[2].wu.cg_olc.olc_ix[2]);
    tilemap_print_hex(11, 20, 2, num, 4, 0);
    num = debug_hex4_to_bcd(dbg_parts_plw[3].wu.cg_olc.olc_ix[3]);
    tilemap_print_hex(11, 21, 2, num, 4, 0);
}



/* provisional name */
void debug_char_init(void) {
    s16 x;
    if (Game_setting.mode) {
        x = 32;
    } else {
        x = 0;
    }
    dbg_pl->wu.be_flag = 1;
    dbg_pl->wu.disp_flag = 1;
    dbg_pl->wu.cgromtype = 1;
    dbg_pl->wu.my_family = 1;
    dbg_pl->wu.my_col_mode = 0x4200;
    dbg_pl->wu.work_id = 1;
    if (dbg_pl->wu.id) {
        dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos = x + 0x270;
        dbg_pl->wu.my_priority = 64;
        dbg_pl->wu.target_adrs = (u32*)&plw[0];
    } else {
        dbg_pl->wu.position_x = dbg_pl->wu.xyz[0].disp.pos = x + 0x200;
        dbg_pl->wu.my_priority = 62;
        dbg_pl->wu.target_adrs = (u32*)&plw[1];
    }
    dbg_pl->wu.position_y = dbg_pl->wu.xyz[1].disp.pos = 0;
    dbg_pl->wu.xyz[2].disp.pos = dbg_pl->wu.my_priority;
    dbg_pl->wu.xyz[0].disp.low = 0;
    dbg_pl->wu.xyz[1].disp.low = 0;
    dbg_pl->wu.xyz[2].disp.low = 0;
    dbg_pl->wu.charset_id = debug_charset_tbl[dbg_pl->player_number];
    debug_char_table_load();
    set_char_base_data_init(&dbg_pl->wu);
    set_char_move_init(&dbg_pl->wu, dbg_slot->row, dbg_slot->sel[1] - 1);
    Debug_Flip_Work[dbg_pl->wu.id] = Debug_RL_Flag[dbg_pl->wu.id] = dbg_pl->wu.rl_flag = 0;
    Debug_Flip_Mask[dbg_pl->wu.id] = Debug_CG_Flip[dbg_pl->wu.id] = dbg_pl->wu.cg_flip = 0;
    if (dbg_pl->wu.id) {
        dbg_pl->wu.my_col_code = 0x2010;
    } else {
        dbg_pl->wu.my_col_code = 0x2000;
    }
}



/* provisional name */
void debug_p1_reset(void) {
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    dbg_pl->wu.id = 0;
    debug_char_init();
}



/* provisional name */
void debug_both_players_reset(void) {
    dbg_pl = &plw[0];
    dbg_slot = (DBG_SLOT*)dbg_slot_w[0];
    dbg_pl->wu.id = 0;
    debug_char_init();
    dbg_pl->wu.id = 0;
    dbg_pl = &plw[1];
    dbg_pl->wu.id = 1;
    debug_char_init();
    dbg_pl->wu.id = 1;
}



/* provisional name */
s32 debug_menu_exit_check(void) {
    if ((dbg_p1sw_0 & BUTTON_START) && (dbg_p2sw_0 & BUTTON_START)) {
        if (Debug_Menu_No >= 7) {
            Debug_R_No = DBG_INIT;
        } else {
            Debug_R_No = DBG_PLAYER;
        }
        Debug_Select_No = 0;
        Debug_Tool_No = 0;
        Scr_all_clear_Wait();
        dbg_hud_mode = 0;
        tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_str);
        return 1;
    }
    return 0;
}

/* provisional name */
void debug_bg_stage_load(void)
{
    s16 i;

    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();

    switch (dbg_stage_sel) {
    case 0:
        debug_bg_alloc_scene_init();
        bg_w.scno = 3;
        break;

    case 1:
        debug_bg_alloc_init();
        bg_w.scno = 3;
        break;

    case 21:
        scr_cg_c_no = simmram_block_alloc_10(31, 1);
        bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
        load_any_color(0x16);
        load_any_color(0x17);
        polygon2d_submit_line(0x020B0000, 0, 0, 3);
        polygon2d_submit_line(0x020B0080, bg_w.scroll_cg_adr, 0x1E5F, 1);
        if (Game_setting.mode) {
            bg_w.pos_offset = 248;
        } else {
            bg_w.pos_offset = 192;
        }
        for (i = 0; i < 7; i++) {
            bg_w.bgw[i].pos_x_work = bg_w.bgw[i].pos_y_work = 512;
            bg_w.bgw[i].zuubun = 0;
            bg_w.bgw[i].xy[0].cal = WORK_RAM;        /* pos 512, low 0 */
            bg_w.bgw[i].xy[1].cal = 0;
            bg_w.bgw[i].wxy[0].cal = WORK_RAM;
            bg_w.bgw[i].wxy[1].cal = 0;
            bg_w.bgw[i].hos_xy[0].cal = 0;
            bg_w.bgw[i].hos_xy[1].cal = 0;
            bg_w.bgw[i].speed_x = 0;
            bg_w.bgw[i].speed_y = 0;
            bg_w.bgw[i].rewrite_flag = 0;
            bg_w.bgw[i].fam_no = i;
            bg_w.bgw[i].r_no_1 = bg_w.bgw[i].r_no_2 = 0;
            bg_w.bgw[i].speed_x = 0;
        }
        bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
        bg_w.bgw[0].bg_address = (u16 *)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
        scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
        scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
        sprite_list_setup(0, 1, bg_scr_record_data);
        bg_cell_write(0, 0x2000, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x2040, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x2080, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x20C0, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3000, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3040, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x3080, 0, (u32)russia2_scrn_data, 0, 0x340);
        bg_cell_write(0, 0x30C0, 1, (u32)russia2_scrn_data, 0, 0x340);
        bg_zoom_x_pos = 192;
        Bg_On_R(1);
        Bg_Off_R(16);
        scrn_attr_set(0, 0, 24);
        scrn_reg_w[0].ctrl &= 0xFE7F;
        bg_w.bgw[0].speed_x = 0x10000;
        bg_w.bgw[0].speed_y = 0x10000;
        bg_w.bgw[0].rewrite_flag = 0;
        bg_w.bgw[0].xy[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos = bg_w.bgw[0].pos_y_work = 0;
        base_y_pos = 40;
        bg_pos_hosei2();
        Bg_Family_Set();
        break;

    default:
        bg_initialize();
        if (bg_w.stage == 10) {
            bg_cell_write(0, 0x2000, 0x11, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x2040, 0x12, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x2080, 0x13, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x20C0, 0x14, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3000, 0x15, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3040, 0x16, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x3080, 0x17, (u32)eff23_scrn_data, 0, 0x280);
            bg_cell_write(0, 0x30C0, 0x18, (u32)eff23_scrn_data, 0, 0x280);
        }
        break;
    }

    if (Game_setting.mode) {
        bg_w.pos_offset = 248;
    } else {
        bg_w.pos_offset = 192;
    }
    for (i = 0; i < 3; i++) {
        bg_w.bgw[i].xy[0].disp.pos = 512;
        bg_w.bgw[i].xy[1].disp.pos = 0;
        bg_w.bgw[i].wxy[0].disp.pos = 512;
        bg_w.bgw[i].wxy[1].disp.pos = 0;
        bg_w.bgw[i].xy[0].disp.low = 0;
        bg_w.bgw[i].xy[1].disp.low = 0;
        bg_w.bgw[i].wxy[0].disp.low = 0;
        bg_w.bgw[i].wxy[1].disp.low = 0;
        bg_w.bgw[i].position_x = 512;
        bg_w.bgw[i].position_y = 0;
    }
    if (bg_w.stage != 8) {
        base_y_pos = 40;
    } else {
        base_y_pos = 48;
    }
    bg_pos_hosei2();
    Bg_Family_Set();
}



/* provisional name */
s32 debug_cg_group_index(code)
    u16 code;
{
    u16 i;
    if (code >= 0xD800) {
        for (i = 0; i < 47; i++) {
            if (code < bcb_group_top_tbl[i + 1]) {
                break;
            }
        }
    } else if (code >= 0x9000) {
        for (i = 0; i < 58; i++) {
            if (code < bce_group_top_tbl[i + 1]) {
                break;
            }
        }
    } else {
        for (i = 0; i < 24; i++) {
            if (code < bcp_group_top_tbl[i + 1]) {
                i = bcp_group_no_tbl[i];
                break;
            }
        }
    }
    return i;
}

/* provisional name */
void debug_draw_att_data(void)
{
    s16 bcd;

    if (plw[0].wu.meoshi_hit_flag != 1) {
        tilemap_print_string_attr(dbg_hud_x + 36, 2, 10, dbg_minus_str);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 36, 2, 14, " ");
    }
    bcd = debug_hex4_to_bcd(plw[0].wu.cg_att_ix);
    tilemap_print_hex(dbg_hud_x + 37, 2, 10, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 3, 10, plw[0].wu.att.reaction, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.reaction);
    tilemap_print_hex(dbg_hud_x + 42, 3, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 4, 10, plw[0].wu.att.mkh_ix, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.mkh_ix);
    tilemap_print_hex(dbg_hud_x + 42, 4, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 5, 10, plw[0].wu.att.dipsw, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dipsw);
    tilemap_print_hex(dbg_hud_x + 42, 5, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.att.dir, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dir);
    tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.att.dir, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.dir);
    tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 8, 10, plw[0].wu.att.guard, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.guard);
    tilemap_print_hex(dbg_hud_x + 42, 8, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 9, 10, plw[0].wu.att.pow, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.pow);
    tilemap_print_hex(dbg_hud_x + 42, 9, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 10, 10, plw[0].wu.att.impact, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.impact);
    tilemap_print_hex(dbg_hud_x + 42, 10, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 11, 10, plw[0].wu.att.piyo, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.piyo);
    tilemap_print_hex(dbg_hud_x + 42, 11, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 12, 10, plw[0].wu.att.ng_type, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.ng_type);
    tilemap_print_hex(dbg_hud_x + 42, 12, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 13, 10, plw[0].wu.att.hs_me, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.hs_me);
    tilemap_print_hex(dbg_hud_x + 42, 13, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 14, 10, plw[0].wu.att.hs_you, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.hs_you);
    tilemap_print_hex(dbg_hud_x + 42, 14, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 15, 10, plw[0].wu.zu_flag, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.zu_flag);
    tilemap_print_hex(dbg_hud_x + 42, 15, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 16, 10, plw[0].wu.at_attribute, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.at_attribute);
    tilemap_print_hex(dbg_hud_x + 42, 16, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 17, 10, plw[0].wu.att.level, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.level);
    tilemap_print_hex(dbg_hud_x + 42, 17, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 18, 10, plw[0].wu.add_arts_point, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.add_arts_point);
    tilemap_print_hex(dbg_hud_x + 42, 18, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 19, 10, plw[0].wu.att.but_ix, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.att.but_ix);
    tilemap_print_hex(dbg_hud_x + 42, 19, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 21, 10, plw[0].wu.dir_atthit, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.dir_atthit);
    tilemap_print_hex(dbg_hud_x + 42, 21, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 22, 10, plw[0].wu.vs_id, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.vs_id);
    tilemap_print_hex(dbg_hud_x + 42, 22, 2, bcd, 4, 0);
}



/* provisional name */
void debug_draw_cg_data(void) {
    const TM_STRING* off;
    const TM_STRING* on;
    s16 bcd;
    s16 n;
    s16 i;
    s16 bit;
    s32 group;
    if (dbg_old_cgd_type != plw[0].wu.cgd_type) {
        switch (plw[0].wu.cgd_type) {
        case 2:
            tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_mid_str);
        case 4:
            tilemap_print_string(0, 0, 0xFFFF, dbg_hud_clr_low_str);
            break;
        }
    }
    switch (plw[0].wu.cgd_type) {
    case 6:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_rival_str);
        tilemap_print_hex(dbg_hud_x + 37, 16, 10, plw[0].wu.cg_rival, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_rival);
        tilemap_print_hex(dbg_hud_x + 42, 16, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 17, 10, plw[0].wu.cg_add_xy, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_add_xy);
        tilemap_print_hex(dbg_hud_x + 42, 17, 2, bcd, 4, 0);
        tilemap_print_string_attr(dbg_hud_x + 37, 18, 10, dbg_nix_str);
        tilemap_print_hex(dbg_hud_x + 40, 18, 10, plw[0].wu.cg_next_ix, 2, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_status);
        tilemap_print_hex(dbg_hud_x + 37, 19, 10, bcd, 4, 0);
    case 4:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_att_str);
        if (plw[0].wu.cg_att_ix < 0) {
            tilemap_print_string_attr(dbg_hud_x + 37, 14, 2, dbg_minus_str);
            n = -plw[0].wu.cg_att_ix;
            tilemap_print_string_attr(dbg_hud_x + 42, 14, 2, dbg_minus_str);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 14, 2, " ");
            tilemap_print_string_attr(dbg_hud_x + 42, 14, 2, " ");
            n = plw[0].wu.cg_att_ix;
        }
        tilemap_print_hex(dbg_hud_x + 38, 10, 10, plw[0].wu.cg_att_ix, 3, 0);
        bcd = debug_hex4_to_bcd(n);
        tilemap_print_hex(dbg_hud_x + 43, 10, 2, bcd, 3, 0);
        tilemap_print_hex(dbg_hud_x + 37, 11, 10, plw[0].wu.cg_hit_ix, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_hit_ix);
        tilemap_print_hex(dbg_hud_x + 42, 11, 2, bcd, 4, 0);
        if (plw[0].wu.cg_extdat) {
            bcd = plw[0].wu.cg_extdat & 0xC0;
            bcd = bcd >> 6;
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_extdat_str[bcd]);
            bcd = debug_hex4_to_bcd(plw[0].wu.cg_extdat & 0x3F);
            tilemap_print_hex(dbg_hud_x + 39, 12, 10, bcd, 2, 0);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 12, 10, dbg_no_extdat_str);
        }
        if (DEBUG_DISP) {
            bcd = debug_hex4_to_bcd(plw[0].wu.cg_type);
        }
        bit = 1;
        i = 0;
        off = dbg_cancel_off_str;
        on = dbg_cancel_on_str;
        for (; i < 8; i++, off++, on++) {
            if (plw[0].wu.cg_cancel & bit) {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, on);
            } else {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, off);
            }
            bit = bit << 1;
        }
        if (plw[0].wu.cg_cancel & 8) {
            n = plw[0].wu.cg_eftype & 0xF;
            if (n > 8) {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_names[8]);
            } else {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_names[n]);
            }
            n = plw[0].wu.cg_eftype >> 8;
            n &= 7;
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_s_str[n]);
            if (plw[0].wu.cg_eftype & 0x80) {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_usemj_str[1]);
            } else {
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_eftype_usemj_str[0]);
            }
        } else if (plw[0].wu.cg_eftype) {
            tilemap_print_string_attr(dbg_hud_x + 37, 15, 10, dbg_eftype_str);
            bcd = debug_hex4_to_bcd(plw[0].wu.cg_eftype);
            tilemap_print_hex(dbg_hud_x + 40, 15, 10, bcd, 2, 0);
        } else {
            tilemap_print_string_attr(dbg_hud_x + 37, 15, 10, debug_blank6_msg);
        }
        tilemap_print_hex(dbg_hud_x + 37, 14, 10, plw[0].wu.cg_effect, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_effect);
        tilemap_print_hex(dbg_hud_x + 42, 14, 2, bcd, 4, 0);
    case 2:
        tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_cgd_type_str[plw[0].wu.cgd_type / 2]);
        tilemap_print_hex(dbg_hud_x + 37, 3, 10, plw[0].wu.cg_ctr, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_ctr);
        tilemap_print_hex(dbg_hud_x + 42, 3, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 4, 10, plw[0].wu.cg_type, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_type);
        tilemap_print_hex(dbg_hud_x + 42, 4, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 5, 10, (s16)plw[0].wu.cg_se, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_se);
        tilemap_print_hex(dbg_hud_x + 42, 5, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.cg_flip, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_flip);
        tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
        tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.cg_olc_ix, 4, 0);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_olc_ix);
        tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
        group = debug_cg_group_index((s16)dbg_pl->wu.cg_number);
        debug_draw_cg_group((s16)plw[0].wu.cg_number, group, dbg_hud_x + 37, 8, 2);
        debug_draw_cg_group_offset((s16)plw[0].wu.cg_number, group, dbg_hud_x + 43, 8, 2);
        break;
    }
}



/* provisional name */
void debug_draw_cgd_info(void) {
    s16 bcd;
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_pat_status_str[plw[0].wu.pat_status / 2]);
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_cgd_type_str[plw[0].wu.cgd_type / 2]);
    bcd = plw[0].wu.kind_of_waza;
    bcd = bcd >> 4;
    tilemap_print_string(dbg_hud_x, 0, 0xFFFF, &dbg_waza_kind_str[bcd]);
    if (plw[0].wu.kind_of_waza & 1) {
        tilemap_print_string_attr(dbg_hud_x + 40, 4, 10, dbg_waza_k_str);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 40, 4, 10, dbg_waza_p_str);
    }
    if (plw[0].wu.kind_of_waza & 2) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit0_str);
    }
    if (plw[0].wu.kind_of_waza & 4) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit1_str);
    }
    if (plw[0].wu.kind_of_waza & 6) {
        tilemap_print_string_attr(dbg_hud_x + 41, 4, 10, dbg_digit2_str);
    }
    tilemap_print_hex(dbg_hud_x + 37, 5, 10, plw[0].wu.hit_range, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 6, 10, plw[0].wu.total_paring, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.total_paring);
    tilemap_print_hex(dbg_hud_x + 42, 6, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 7, 10, plw[0].wu.total_att_set, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.total_att_set);
    tilemap_print_hex(dbg_hud_x + 42, 7, 2, bcd, 4, 0);
    tilemap_print_hex(dbg_hud_x + 37, 8, 10, plw[0].wu.sp_tech_id, 4, 0);
    bcd = debug_hex4_to_bcd(plw[0].wu.sp_tech_id);
    tilemap_print_hex(dbg_hud_x + 42, 8, 2, bcd, 4, 0);
    if (plw[0].wu.cg_wca_ix) {
        tilemap_print_string_attr(dbg_hud_x + 37, 9, 10, dbg_wca_str);
        bcd = debug_hex4_to_bcd(plw[0].wu.cg_wca_ix);
        tilemap_print_hex(dbg_hud_x + 40, 9, 10, bcd, 2, 0);
    } else {
        tilemap_print_string_attr(dbg_hud_x + 37, 9, 10, debug_blank6_msg);
    }
}



/* provisional name */
void debug_hud_mode_dispatch(void) {
    u16 trg = ~dbg_p2sw_1 & dbg_p2sw_0;
    if (trg & BUTTON_START) {
        dbg_hud_mode++;
        if (dbg_hud_mode > 4) {
            dbg_hud_mode = 0;
        }
        switch (dbg_hud_mode) {
        case 0:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            break;
        case 1:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cg_head_str);
            break;
        case 2:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_bottom_str);
            switch (plw[0].wu.cgd_type) {
            case 6:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_low_str);
            case 4:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_mid_str);
            case 2:
                tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
                break;
            }
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_att_data_str);
            break;
        case 3:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cm_label_str);
            break;
        case 4:
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_hud_clr_str);
            tilemap_print_string(dbg_hud_x, 0, 0xFFFF, dbg_cgd_info_str);
            break;
        }
    }
    switch (dbg_hud_mode) {
    case 1:
        debug_draw_cg_data();
        break;
    case 2:
        debug_draw_att_data();
        break;
    case 3:
        debug_draw_cm_data();
        break;
    case 4:
        debug_draw_cgd_info();
        break;
    }
}



/* provisional name */
s16 debug_catch_move_record(SNAPSHOT* p1, SNAPSHOT* p2) {
    SNAPSHOT* s1;
    SNAPSHOT* s2;
    if (plw[0].wu.now_koc != 2) {
        return 0;
    }
    plw[0].tsukami_num = plw[1].player_number;
    set_char_move_init(&plw[0].wu, 2, ((DBG_SLOT*)dbg_slot_w[0])->sel[1] - 1);
    set_char_move_init(&plw[1].wu, 3, plw[0].wu.cmyd.ix);
    if (plw[0].wu.cmyd.pat == 0) {
        return 0;
    }
    Debug_CG_Flip[0] = plw[0].wu.cg_flip;
    Debug_Flip_Mask[0] = 0;
    Debug_RL_Flag[0] = plw[0].wu.rl_flag;
    Debug_CG_Flip[1] = plw[1].wu.cg_flip;
    Debug_Flip_Mask[1] = 0;
    Debug_RL_Flag[1] = plw[1].wu.rl_flag;
    Debug_Rec_Count = 0;
    ixbfw_cut = 1;
    if (p1sw_0 & BUTTON_HK) {
        ixbfw_cut += 4;
    }
    if (plw[0].wu.cmyd.pat == 1) {
        for (;;) {
            Debug_Rec_Count++;
            s1 = &p1[Debug_Rec_Count];
            s2 = &p2[Debug_Rec_Count];
            if (plw[0].wu.cg_rival) {
                char_move_index(&plw[1].wu, plw[0].wu.curr_rca->catch_nix);
                plw[1].wu.rl_flag = plw[0].wu.rl_flag ^ plw[0].wu.curr_rca->catch_flip;
                if (plw[0].wu.rl_flag) {
                    plw[1].wu.xyz[0].disp.pos = plw[0].wu.xyz[0].disp.pos - plw[0].wu.curr_rca->catch_hos_x;
                } else {
                    plw[1].wu.xyz[0].disp.pos = plw[0].wu.xyz[0].disp.pos + plw[0].wu.curr_rca->catch_hos_x;
                }
                plw[1].wu.xyz[1].disp.pos = plw[0].wu.xyz[1].disp.pos + plw[0].wu.curr_rca->catch_hos_y;
                if (plw[0].wu.curr_rca->catch_prio == 2) {
                    plw[1].wu.next_z = plw[0].wu.xyz[2].disp.pos - 1;
                } else {
                    plw[1].wu.next_z = plw[0].wu.xyz[2].disp.pos + 1;
                }
            }
            debug_move_snapshot_frame(s1, &plw[0].wu, plw[0].wu.xyz[2].disp.pos);
            debug_move_snapshot_frame(s2, &plw[1].wu, plw[1].wu.next_z);
            char_move_z(&plw[0].wu);
            Debug_CG_Flip[0] = plw[0].wu.cg_flip;
            Debug_Flip_Mask[0] = 0;
            Debug_RL_Flag[0] = plw[0].wu.rl_flag;
            if (plw[0].wu.cg_type == 0xFF) {
                break;
            }
            if (ixbfw_cut & 4) {
                if (plw[0].wu.cg_rival == 0) {
                    break;
                }
            }
        }
    } else {
        for (;;) {
            Debug_Rec_Count++;
            s1 = &p1[Debug_Rec_Count];
            s2 = &p2[Debug_Rec_Count];
            if (plw[0].wu.cg_rival) {
                char_move_index(&plw[1].wu, plw[0].wu.curr_rca->catch_nix);
                plw[1].wu.rl_flag = plw[0].wu.rl_flag ^ plw[0].wu.curr_rca->catch_flip;
                if (plw[0].wu.rl_flag) {
                    plw[0].wu.xyz[0].disp.pos = plw[1].wu.xyz[0].disp.pos + plw[0].wu.curr_rca->catch_hos_x;
                } else {
                    plw[0].wu.xyz[0].disp.pos = plw[1].wu.xyz[0].disp.pos - plw[0].wu.curr_rca->catch_hos_x;
                }
                plw[0].wu.xyz[1].disp.pos = plw[1].wu.xyz[1].disp.pos - plw[0].wu.curr_rca->catch_hos_y;
                if (plw[0].wu.curr_rca->catch_prio == 2) {
                    plw[1].wu.next_z = plw[0].wu.xyz[2].disp.pos - 1;
                } else {
                    plw[1].wu.next_z = plw[0].wu.xyz[2].disp.pos + 1;
                }
            }
            debug_move_snapshot_frame(s1, &plw[0].wu, plw[0].wu.xyz[2].disp.pos);
            debug_move_snapshot_frame(s2, &plw[1].wu, plw[1].wu.next_z);
            char_move_z(&plw[0].wu);
            Debug_CG_Flip[0] = plw[0].wu.cg_flip;
            Debug_Flip_Mask[0] = 0;
            Debug_RL_Flag[0] = plw[0].wu.rl_flag;
            if (plw[0].wu.cg_type == 0xFF) {
                break;
            }
            if (ixbfw_cut & 4) {
                if (plw[0].wu.cg_rival == 0) {
                    break;
                }
            }
        }
    }
    ixbfw_cut = 0;
    return 1;
}



/* provisional name */
void debug_move_snapshot_frame(SNAPSHOT* rec, WORK* wk, s16 priority) {
    rec->pos_x = wk->xyz[0].disp.pos;
    rec->pos_y = wk->xyz[1].disp.pos;
    rec->priority = priority;
    rec->cg_number = wk->cg_number;
    rec->dbg_rl_flag = wk->rl_flag;
    rec->dbg_cg_flip = wk->cg_flip;
    rec->used = 1;
    rec->cg_ctr = wk->cg_ctr;
    rec->col_mode = wk->my_col_mode;
    rec->col_code = wk->my_col_code;
    rec->olc_ix = wk->cg_olc_ix;
    rec->rl_flag = wk->rl_flag;
    rec->cg_flip = wk->cg_flip;
}

/* provisional name */
void debug_bg_tile_put(s16 bg, s32 ofs, s32 page, s32 src) {
    u16* dst;
    u16* sp;
    s32 x;
    s32 adr;

    adr = (s32)bg_w.bgw[bg].bg_address;
    ofs += adr;
    dst = (u16*)ofs;
    x = 0;
    x += bg_w.ake_cg_adr >> 7;
    page = (page << 10) + src;
    sp = (u16*)page;
    blit_16x16_tile(sp, (u16)x, dst, 0x2C0);
}



/* provisional name */
void debug_bg_alloc_init(void) {
    scr_cg_c_no = ((s16)simmram_block_alloc_10(104, 1));
    bg_w.ake_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    load_any_color(0x8C);
    load_any_color(0x8F);
    polygon2d_submit_line(0x020F0000, 0, 0, 3);
    polygon2d_submit_line(0x020F0080, bg_w.ake_cg_adr, 0x14FF, 1);
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, (s16*)bg_map_tbl[0][0]);
    bg_w.bgw[0].r_no_1 = bg_w.bgw[0].r_no_2 = 0;
    bg_w.bgw[0].fam_no = 0;
    debug_bg_tile_put(0, 0x3000, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x3040, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x3080, 3, (s32)ake_scrn_data);
    debug_bg_tile_put(0, 0x30C0, 3, (s32)ake_scrn_data);
    Bg_On_R(1);
    Bg_Off_R(16);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
}



/* provisional name */
void debug_bg_alloc_scene_init(void) {
    s32 n = (bg_gfx_tbl[1].size * 16 + 0xFFF) / 0x1000;
    u32 blocks = n;
    scr_cg_c_no = ((s16)simmram_block_alloc_10(blocks, 1));
    bg_w.scroll_cg_adr = simmram_slot_to_offset(scr_cg_c_no);
    load_bg_color(1);
    load_bg_color(16);
    polygon2d_submit_line(bg_gfx_tbl[1].prep, 0, 0, 3);
    polygon2d_submit_line(bg_gfx_tbl[1].src, bg_w.scroll_cg_adr, bg_gfx_tbl[1].size, 1);
    bg_w.bgw[0].bg_adrs_c_no = simmram_big_page_alloc_40(1);
    bg_w.bgw[0].bg_address = (u16*)simmram_slot_addr(bg_w.bgw[0].bg_adrs_c_no);
    scrn_map_set_now(0, (u32)bg_w.bgw[0].bg_address);
    scrn_map_set(0, (u32)bg_w.bgw[0].bg_address);
    sprite_list_setup(0, 1, (s16*)bg_map_tbl[1][0]);
    bg_w.bgw[0].r_no_1 = bg_w.bgw[0].r_no_2 = 0;
    bg_w.bgw[0].fam_no = 0;
    bg_cell_write(0, 0x2000, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x2040, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x2080, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x20C0, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3000, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3040, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x3080, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    bg_cell_write(0, 0x30C0, 0, (u32)debug_scene_scrn_data, 0, 0x280);
    Bg_On_R(1);
    Bg_Off_R(16);
    scrn_attr_set(0, 0, 31);
    scrn_reg_w[0].ctrl &= 0xFE7F;
}

/* provisional name */
void screen_work_clear_all(void)
{
    Family_Init();
    clear_scroll_layer_state_and_mask();
    scrn_pos_clear();
    Zoomf_Init();
}

/* 02000924 */
const char* dbg_sign_str[2] = {
    &dbg_wca_str[4],
    &dbg_wca_str[8],
};
/* 0200092C */
s16 dbg_rgb_preset_tbl[8][3] = {
    { 0, 0, 0 }, { 127, 0, 0 }, { 127, 127, 127 }, { 127, 127, 0 }, { 127, 0, 127 }, { 0, 127, 0 }, { 0, 0, 127 }, { 112, 112, 112 },
};
/* 0200095C */
TM_STRING dbg_menu_str[15] = {
    { 13, 2, 2, str_OBJECT_TEST },
    { 10, 4, 2, str_BG_SELECT },
    { 10, 5, 2, str_OBJECT_LOOK },
    { 10, 6, 2, str_OBJECT_EDIT },
    { 10, 7, 2, str_OBJECT_EDIT_2 },
    { 10, 8, 2, str_HIT },
    { 10, 9, 2, str_ALL_CHARACTER },
    { 10, 10, 2, str_PARTS },
    { 10, 11, 2, str_YOKOYAMA },
    { 10, 12, 2, str_NAKAI },
    { 10, 13, 2, str_YOSHIZUMI },
    { 10, 14, 2, str_YU },
    { 10, 15, 2, str_RAOH },
    { 10, 16, 2, str_INE },
    { 10, 17, 2, str_OHYA },
};
/* 02000A10 */
TM_STRING dbg_select_exit_str[2] = {
    { 17, 3, 2, str_SELECT_UP_DOWN },
    { 17, 4, 2, str_EXIT_1P_2P_START },
};
/* 02000A28 */
TM_STRING dbg_obj_info_str[10] = {
    { 1, 3, 2, str_PLAYER },
    { 1, 4, 2, str_ALL },
    { 1, 6, 2, str_MOTION },
    { 1, 8, 2, str_PATTERN },
    { 1, 9, 2, str_INTERRUT },
    { 1, 10, 2, str_CODE_H },
    { 1, 11, 2, str_FLIP },
    { 1, 12, 2, str_FLIP_ED },
    { 1, 13, 2, str_POS_X_H },
    { 1, 14, 2, str_POS_Y_H },
};
/* 02000AA0 */
TM_STRING dbg_obj_rel_str[3] = {
    { 1, 15, 2, str_REL_X_H },
    { 1, 16, 2, str_REL_Y_H },
    { 1, 17, 2, str_CURRENT },
};
/* 02000AC4 */
TM_STRING dbg_all_char_str[7] = {
    { 15, 1, 2, str_ALL_CHARACTER },
    { 1, 5, 2, str_H_n },
    { 1, 7, 2, str_H_n },
    { 4, 11, 2, str_GROUP },
    { 4, 12, 2, str_R_n },
    { 4, 13, 2, str_G },
    { 4, 14, 2, str_B },
};
/* 02000B18 */
TM_STRING dbg_edit_num_str[4] = {
    { 1, 18, 2, str_EDIT_NUM },
    { 1, 19, 2, str_NUM_END },
    { 1, 20, 2, str_EDIT_INT },
    { 1, 21, 2, str_INT_END },
};
/* 02000B48 */
TM_STRING dbg_parts_info_str[17] = {
    { 1, 3, 2, str_PLAYER },
    { 1, 4, 2, str_ALL },
    { 1, 6, 2, str_MOTION },
    { 1, 8, 2, str_PATTERN },
    { 1, 9, 2, str_INTERRUT },
    { 1, 10, 2, str_CODE_H },
    { 1, 11, 2, str_FLIP },
    { 1, 12, 2, str_FLIP_ED },
    { 1, 13, 2, str_CURRENT_n },
    { 1, 14, 2, str_PARTS_X_H },
    { 1, 15, 2, str_PARTS_Y_H },
    { 1, 16, 2, str_PARTS_FL },
    { 1, 17, 2, str_OLC_IX },
    { 1, 18, 2, str_IX_1 },
    { 1, 19, 2, str_IX_2 },
    { 1, 20, 2, str_IX_3 },
    { 1, 21, 2, str_IX_4 },
};
/* 02000C14 */
TM_STRING dbg_rec_menu_str[3] = {
    { 27, 3, 6, str_DELETE_ALL_SH4 },
    { 27, 4, 6, str_1DATA_SH5 },
    { 27, 5, 6, str_CANCEL_SH6 },
};
/* 02000C38 */
TM_STRING dbg_rec_clear_str[3] = {
    { 27, 3, 6, str_n },
    { 27, 4, 6, str_n },
    { 27, 5, 6, str_empty },
};
/* 02000C5C */
TM_STRING dbg_rec_nodata_str[2] = {
    { 27, 3, 6, str_NO_EDIT },
    { 27, 4, 6, str_DATA_NOTHING },
};
/* 02000C74 */
TM_STRING dbg_hit_size_str[18] = {
    { 1, 15, 2, str_REVISE_X_H },
    { 1, 16, 2, str_SIZE_X_H },
    { 1, 17, 2, str_REVISE_Y_H },
    { 1, 18, 2, str_SIZE_Y_H },
    { 1, 20, 2, str_IX_000 },
    { 1, 21, 2, str_CR_1P },
    { 1, 23, 2, str_MF },
    { 1, 24, 2, str_M_B },
    { 8, 20, 2, str_BOD_000 },
    { 8, 21, 2, str_BHA_000 },
    { 8, 22, 2, str_HAN_000 },
    { 8, 23, 2, str_CAT_000 },
    { 8, 24, 2, str_CAU_000 },
    { 8, 25, 2, str_ATT_000 },
    { 8, 26, 2, str_HOS_000 },
    { 15, 25, 2, str_KOC_IX_PT_Nix_n },
    { 15, 26, 2, str_KOC_IX_PT_Nix_n },
    { 15, 27, 2, str_KOC_IX_PT_Nix },
};
/* 02000D4C */
TM_STRING dbg_hit_part_str[15] = {
    { 40, 12, 2, str_HEAD },
    { 40, 13, 2, str_BREAST },
    { 40, 14, 2, str_TRUNK },
    { 40, 15, 2, str_LEG },
    { 40, 16, 2, str_HAND },
    { 40, 17, 2, str_HAND },
    { 40, 18, 2, str_HAND },
    { 40, 19, 2, str_HAND },
    { 40, 20, 2, str_CATCH_n },
    { 40, 21, 2, str_CAUGHT_n },
    { 40, 22, 2, str_ATT },
    { 40, 23, 2, str_ATT },
    { 40, 24, 2, str_ATT_2 },
    { 40, 25, 2, str_ATT_2 },
    { 40, 26, 2, str_HOSEI },
};
/* 02000E00 */
TM_STRING dbg_work_empty_str[2] = {
    { 15, 5, 8, str_WORK_EMPTY },
    { 15, 7, 8, str_PRESS_ANY_SHOT },
};
/* 02000E18 */
TM_STRING dbg_blank4_str[4] = {
    { 11, 5, 2, str_n_2 },
    { 11, 6, 2, str_n_2 },
    { 11, 7, 2, str_n_2 },
    { 11, 8, 2, str_empty_2 },
};
/* 02000E48 */
TM_STRING dbg_exit_ok_str[3] = {
    { 14, 5, 2, str_EXIT_OK },
    { 11, 7, 2, str_YES_2P_SHOT6 },
    { 11, 8, 2, str_NO_1P_SHOT6 },
};
/* 02000E6C */
TM_STRING dbg_cg_head_str[6] = {
    { 27, 3, 2, str_CG_CTR },
    { 27, 4, 2, str_CG_TYPE },
    { 27, 5, 2, str_CG_SE },
    { 27, 6, 2, str_CG_FLIP },
    { 27, 7, 2, str_CG_OLC_IX },
    { 27, 8, 2, str_CG_NUMBER },
};
/* 02000EB4 */
TM_STRING dbg_cg_att_str[6] = {
    { 27, 10, 2, str_CG_ATT_IX },
    { 27, 11, 2, str_CG_HIT_IX },
    { 27, 12, 2, str_CG_EXTDAT },
    { 27, 13, 2, str_CG_CANCEL },
    { 27, 14, 2, str_CG_EFFECT },
    { 27, 15, 2, str_CG_EFTYPE },
};
/* 02000EFC */
TM_STRING dbg_cg_rival_str[4] = {
    { 27, 16, 2, str_CG_RIVAL },
    { 27, 17, 2, str_CG_ADD_XY },
    { 27, 18, 2, str_CG_NIX },
    { 27, 19, 2, str_CG_STATUS },
};
/* 02000F2C */
TM_STRING dbg_cgd_info_str[8] = {
    { 27, 2, 2, str_CGD_TYPE },
    { 27, 3, 2, str_PAT_ST },
    { 27, 4, 2, str_KIND_WAZA },
    { 27, 5, 2, str_HIT_RANGE },
    { 27, 6, 2, str_YOKE_TYPE },
    { 27, 7, 2, str_YOKE_PAT },
    { 27, 8, 2, str_SP_TECH },
    { 27, 9, 2, str_WCA_IX },
};
/* 02000F8C */
TM_STRING dbg_att_data_str[21] = {
    { 27, 2, 2, str_ATT_IX },
    { 27, 3, 2, str_REACTION },
    { 27, 4, 2, str_MKH_IX },
    { 27, 5, 2, str_DIP },
    { 27, 6, 2, str_HISS },
    { 27, 7, 2, str_DIR },
    { 27, 8, 2, str_GUARD },
    { 27, 9, 2, str_POW },
    { 27, 10, 2, str_IMPACT },
    { 27, 11, 2, str_PIYO_n },
    { 27, 12, 2, str_NG_TYPE },
    { 27, 13, 2, str_HS_ME },
    { 27, 14, 2, str_HS_YOU },
    { 27, 15, 2, str_ZU_FLAG },
    { 27, 16, 2, str_ZOKUSEI },
    { 27, 17, 2, str_AT_LEVEL },
    { 27, 18, 2, str_ADD_ARTS },
    { 27, 19, 2, str_BUTT_TYPE },
    { 27, 20, 2, str_BUTT_PAT },
    { 27, 21, 2, str_DIR_ATT },
    { 27, 22, 2, str_VS_ID },
};
/* 02001088 */
TM_STRING dbg_hud_clr_str[26] = {
    { 27, 2, 2, str_n_3 },
    { 27, 3, 2, str_n_3 },
    { 27, 4, 2, str_n_3 },
    { 27, 5, 2, str_n_3 },
    { 27, 6, 2, str_n_3 },
    { 27, 7, 2, str_n_3 },
    { 27, 8, 2, str_n_3 },
    { 27, 9, 2, str_n_3 },
    { 27, 10, 2, str_n_3 },
    { 27, 11, 2, str_n_3 },
    { 27, 12, 2, str_n_3 },
    { 27, 13, 2, str_n_3 },
    { 27, 14, 2, str_n_3 },
    { 27, 15, 2, str_n_3 },
    { 27, 16, 2, str_n_3 },
    { 27, 17, 2, str_n_3 },
    { 27, 18, 2, str_n_3 },
    { 27, 19, 2, str_n_3 },
    { 27, 20, 2, str_n_3 },
    { 27, 21, 2, str_n_3 },
    { 27, 22, 2, str_n_3 },
    { 27, 23, 2, str_n_3 },
    { 27, 24, 2, str_n_3 },
    { 27, 25, 2, str_n_3 },
    { 27, 26, 2, str_n_3 },
    { 27, 27, 2, str_empty_3 },
};
/* 020011C0 */
TM_STRING dbg_hud_clr_mid_str[6] = {
    { 27, 14, 2, str_n_3 },
    { 27, 15, 2, str_n_3 },
    { 27, 16, 2, str_n_3 },
    { 27, 17, 2, str_n_3 },
    { 27, 18, 2, str_n_3 },
    { 27, 19, 2, str_n_3 },
};
/* 02001208 */
TM_STRING dbg_hud_clr_low_str[9] = {
    { 27, 20, 2, str_n_3 },
    { 27, 21, 2, str_n_3 },
    { 27, 22, 2, str_n_3 },
    { 27, 23, 2, str_n_3 },
    { 27, 24, 2, str_n_3 },
    { 27, 25, 2, str_n_3 },
    { 27, 26, 2, str_n_3 },
    { 27, 27, 2, str_empty_3 },
    { 27, 28, 2, str_empty_3 },
};
/* 02001274 */
TM_STRING dbg_hud_clr_bottom_str[3] = {
    { 5, 25, 2, str_n_4 },
    { 5, 26, 2, str_n_4 },
    { 5, 27, 2, str_empty_4 },
};
/* 02001298 */
TM_STRING dbg_cm_label_str[13] = {
    { 27, 2, 2, str_CMOA },
    { 27, 3, 2, str_CMSW },
    { 27, 4, 2, str_CMLP },
    { 27, 5, 2, str_CML2 },
    { 27, 6, 2, str_CMJA },
    { 27, 7, 2, str_CMJ2 },
    { 27, 8, 2, str_CMJ3 },
    { 27, 9, 2, str_CMJ4 },
    { 27, 10, 2, str_CMMS },
    { 27, 11, 2, str_CMMD },
    { 27, 12, 2, str_CMYD },
    { 27, 13, 2, str_CMCF },
    { 27, 14, 2, str_CMCR },
};
/* 02001334 */
TM_STRING dbg_cgd_type_str[5] = {
    { 37, 1, 0xA, str_WCA },
    { 37, 2, 0xA, str_CGD1 },
    { 37, 2, 0xA, str_CGD2 },
    { 37, 2, 0xA, str_CGD3 },
    { 37, 2, 0xA, str_empty_5 },
};
/* 02001370 */
TM_STRING dbg_pat_status_str[23] = {
    { 37, 3, 0xA, str_sl_00 },
    { 37, 3, 0xA, str_sl_10 },
    { 37, 3, 0xA, str_sl_12 },
    { 37, 3, 0xA, str_sl_20 },
    { 37, 3, 0xA, str_sl_22 },
    { 37, 3, 0xA, str_sl_30 },
    { 37, 3, 0xA, str_sl_32 },
    { 37, 3, 0xA, str_sl_40 },
    { 37, 3, 0xA, str_sl_42 },
    { 37, 3, 0xA, str_sl_44 },
    { 37, 3, 0xA, str_sl_50 },
    { 37, 3, 0xA, str_sl_52 },
    { 37, 3, 0xA, str_sl_54 },
    { 37, 3, 0xA, str_sl_60 },
    { 37, 3, 0xA, str_sl_62 },
    { 37, 3, 0xA, str_sl_64 },
    { 37, 3, 0xA, str_sl_70 },
    { 37, 3, 0xA, str_sl_80 },
    { 37, 3, 0xA, str_sl_82 },
    { 37, 3, 0xA, str_sl_90 },
    { 37, 3, 0xA, str_empty_6 },
    { 37, 3, 0xA, str_empty_6 },
    { 37, 3, 0xA, str_empty_6 },
};
/* 02001484 */
TM_STRING dbg_extdat_str[3] = {
    { 37, 12, 0xA, str_Pa },
    { 37, 12, 0xA, str_PA },
    { 37, 12, 0xA, str_PB },
};
/* 020014A8 */
TM_STRING dbg_eftype_names[9] = {
    { 37, 15, 0xA, str_MLN },
    { 37, 15, 0xA, str_MLU },
    { 37, 15, 0xA, str_MLD },
    { 37, 15, 0xA, str_MLF },
    { 37, 15, 0xA, str_MLF },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_MLR },
    { 37, 15, 0xA, str_M },
};
/* 02001514 */
TM_STRING dbg_eftype_s_str[6] = {
    { 40, 15, 0xA, str_S1 },
    { 40, 15, 0xA, str_S2 },
    { 40, 15, 0xA, str_S3 },
    { 40, 15, 0xA, str_S4 },
    { 40, 15, 0xA, str_S5 },
    { 40, 15, 0xA, str_S6 },
};
/* 0200155C */
TM_STRING dbg_eftype_usemj_str[8] = {
    { 42, 15, 0xA, str_empty_7 },
    { 42, 15, 0xA, str_USEMJ },
    { 37, 24, 0xA, str_BASE },
    { 37, 24, 0xA, str_BEFORE },
    { 37, 24, 0xA, str_BACK },
    { 37, 24, 0xA, str_empty_7 },
    { 37, 24, 0xA, str_empty_7 },
    { 37, 24, 0xA, str_empty_7 },
};
/* 020015BC */
TM_STRING dbg_cancel_on_str[8] = {
    { 44, 13, 0xA, str_H },
    { 43, 13, 0xA, str_D },
    { 42, 13, 0xA, str_A },
    { 41, 13, 0xA, str_M_2 },
    { 40, 13, 0xA, str_R },
    { 39, 13, 0xA, str_C },
    { 38, 13, 0xA, str_S },
    { 37, 13, 0xA, str_S },
};
/* 0200161C */
TM_STRING dbg_cancel_off_str[24] = {
    { 44, 13, 0xA, str_h },
    { 43, 13, 0xA, str_d },
    { 42, 13, 0xA, str_a },
    { 41, 13, 0xA, str_m },
    { 40, 13, 0xA, str_r },
    { 39, 13, 0xA, str_c },
    { 38, 13, 0xA, str_s },
    { 37, 13, 0xA, str_s },
    { 37, 17, 0xA, str_H },
    { 38, 17, 0xA, str_D },
    { 39, 17, 0xA, str_A },
    { 40, 17, 0xA, str_M_2 },
    { 41, 17, 0xA, str_R },
    { 42, 17, 0xA, str_C },
    { 43, 17, 0xA, str_S },
    { 44, 17, 0xA, str_S },
    { 37, 17, 0xA, str_h_2 },
    { 38, 17, 0xA, str_d_2 },
    { 39, 17, 0xA, str_a_2 },
    { 40, 17, 0xA, str_m_2 },
    { 41, 17, 0xA, str_r_2 },
    { 42, 17, 0xA, str_c_2 },
    { 43, 17, 0xA, str_s_2 },
    { 44, 17, 0xA, str_s_2 },
};
/* 0200173C */
TM_STRING dbg_koc_cmlp_str[11] = {
    { 12, 25, 0xA, str_NM },
    { 12, 25, 0xA, str_DM },
    { 12, 25, 0xA, str_CA },
    { 12, 25, 0xA, str_CU },
    { 12, 25, 0xA, str_AT },
    { 12, 25, 0xA, str_BT },
    { 12, 25, 0xA, str_EX },
    { 12, 25, 0xA, str_SA },
    { 32, 25, 0xA, str_CB },
    { 32, 25, 0xA, (void*)str_empty_8 },
    { 32, 25, 0xA, (void*)str_empty_8 },
};
/* 020017C0 */
TM_STRING dbg_koc_cml2_str[11] = {
    { 12, 26, 0xA, str_NM },
    { 12, 26, 0xA, str_DM },
    { 12, 26, 0xA, str_CA },
    { 12, 26, 0xA, str_CU },
    { 12, 26, 0xA, str_AT },
    { 12, 26, 0xA, str_BT },
    { 12, 26, 0xA, str_EX },
    { 12, 26, 0xA, str_SA },
    { 32, 26, 0xA, str_CB },
    { 32, 26, 0xA, (void*)str_empty_8 },
    { 32, 26, 0xA, (void*)str_empty_8 },
};
/* 02001844 */
TM_STRING dbg_koc_cmsw_str[11] = {
    { 32, 25, 0xA, str_NM },
    { 32, 25, 0xA, str_DM },
    { 32, 25, 0xA, str_CA },
    { 32, 25, 0xA, str_CU },
    { 32, 25, 0xA, str_AT },
    { 32, 25, 0xA, str_SA },
    { 32, 25, 0xA, str_BT },
    { 32, 25, 0xA, str_EX },
    { 32, 25, 0xA, str_CB },
    { 32, 25, 0xA, (void*)str_empty_8 },
    { 32, 25, 0xA, (void*)str_empty_8 },
};
/* 020018C8 */
TM_STRING dbg_koc_cmja_str[11] = {
    { 32, 26, 0xA, str_NM },
    { 32, 26, 0xA, str_DM },
    { 32, 26, 0xA, str_CA },
    { 32, 26, 0xA, str_CU },
    { 32, 26, 0xA, str_AT },
    { 32, 26, 0xA, str_SA },
    { 32, 26, 0xA, str_BT },
    { 32, 26, 0xA, str_EX },
    { 32, 26, 0xA, str_CB },
    { 32, 26, 0xA, (void*)str_empty_8 },
    { 32, 26, 0xA, (void*)str_empty_8 },
};
/* 0200194C */
TM_STRING dbg_koc_cmoa_str[9] = {
    { 32, 27, 0xA, str_NM },
    { 32, 27, 0xA, str_DM },
    { 32, 27, 0xA, str_CA },
    { 32, 27, 0xA, str_CU },
    { 32, 27, 0xA, str_AT },
    { 32, 27, 0xA, str_SA },
    { 32, 27, 0xA, str_BT },
    { 32, 27, 0xA, str_EX },
    { 32, 27, 0xA, str_CB },
};
/* 020019B8: provisional name */
TM_STRING dbg_koc_str[9] = {
    { 32, 2, 2, str_NM },
    { 32, 2, 2, str_DM },
    { 32, 2, 2, str_CA },
    { 32, 2, 2, str_CU },
    { 32, 2, 2, str_AT },
    { 32, 2, 2, str_SA },
    { 32, 2, 2, str_BT },
    { 32, 2, 2, str_EX },
    { 32, 2, 2, str_CB },
};
/* 02001A24 */
TM_STRING dbg_waza_kind_str[8] = {
    { 37, 4, 0xA, str_nmA },
    { 37, 4, 0xA, str_hsA },
    { 37, 4, 0xA, str_nmC },
    { 37, 4, 0xA, str_hsC },
    { 37, 4, 0xA, str_saA },
    { 37, 4, 0xA, str_saC },
    { 37, 4, 0xA, str_paA },
    { 37, 4, 0xA, str_huA },
};
/* 02001A84 */
TM_STRING dbg_bg_name_str[25] = {
    { 2, 3, 2, str_BLANK },
    { 2, 3, 2, str_FLASH },
    { 2, 3, 2, str_GILL },
    { 2, 3, 2, str_N_Y_0 },
    { 2, 3, 2, str_JAPAN_0 },
    { 2, 3, 2, str_HONGKONG_0 },
    { 2, 3, 2, str_ENGLAND },
    { 2, 3, 2, str_RUSSIA_0 },
    { 2, 3, 2, str_GERMANY },
    { 2, 3, 2, str_JAPAN_1 },
    { 2, 3, 2, str_AFRICA },
    { 2, 3, 2, str_BRAZIL },
    { 2, 3, 2, str_HONGKONG_1 },
    { 2, 3, 2, str_N_Y_1 },
    { 2, 3, 2, str_BRAZIL_1 },
    { 2, 3, 2, str_OROMEKA },
    { 2, 3, 2, str_JAPAN_20 },
    { 2, 3, 2, str_JAPAN_21 },
    { 2, 3, 2, str_CHAINA },
    { 2, 3, 2, str_JAPAN_30 },
    { 2, 3, 2, str_RUSSIA_1 },
    { 2, 3, 2, str_RUSSIA_2 },
    { 2, 3, 2, str_FRANCE },
    { 2, 3, 2, str_BONUS_1 },
    { 2, 3, 2, str_BONUS_2 },
};
/* 02001BB0 */
TM_STRING dbg_char_name_str[25] = {
    { 11, 3, 2, str_GILL_2 },
    { 11, 3, 2, str_ALEX },
    { 11, 3, 2, str_RYU },
    { 11, 3, 2, str_YUN },
    { 11, 3, 2, str_DUDLEY },
    { 11, 3, 2, str_NECRO },
    { 11, 3, 2, str_HUGO },
    { 11, 3, 2, str_IBUKI },
    { 11, 3, 2, str_ELENA },
    { 11, 3, 2, str_ORO },
    { 11, 3, 2, str_YANG },
    { 11, 3, 2, str_KEN },
    { 11, 3, 2, str_SEAN },
    { 11, 3, 2, str_URIEN },
    { 11, 3, 2, str_GOUKI_1 },
    { 11, 3, 2, str_GOUKI_2 },
    { 11, 3, 2, str_CHUN_LI },
    { 11, 3, 2, str_KARATE },
    { 11, 3, 2, str_Q },
    { 11, 3, 2, str_No_12 },
    { 11, 3, 2, str_BIKEI },
    { 11, 3, 2, str_empty_9 },
    { 11, 3, 2, str_empty_9 },
    { 11, 3, 2, str_empty_9 },
    { 11, 3, 2, str_ETC },
};
/* 02001CDC */
TM_STRING dbg_act_kind_str[994] = {
    { 3, 5, 4, str_NORMAL },
    { 3, 5, 4, str_DAMAGE },
    { 3, 5, 4, str_CATCH },
    { 3, 5, 4, str_CAUGHT },
    { 3, 5, 4, str_ATTACK },
    { 3, 5, 4, str_SP_AT },
    { 3, 5, 4, str_BUTTOBI },
    { 3, 5, 4, str_UNION },
    { 3, 5, 4, str_ETC },
    { 3, 5, 4, str_ETC },
    { 3, 5, 4, str_EFFECT },
    { 3, 5, 4, str_empty_9 },
    { 3, 7, 4, str_KAMAE },
    { 3, 7, 4, str_HURIMUKI },
    { 3, 7, 4, str_FRONT_WALK },
    { 3, 7, 4, str_BACK_WALK },
    { 3, 7, 4, str_DASH_HUMIKOMI },
    { 3, 7, 4, str_DASH_TOBINOKI },
    { 3, 7, 4, str_KAGAMU },
    { 3, 7, 4, str_KAGAMI_KAMAE },
    { 3, 7, 4, str_KAGAMI_TURN },
    { 3, 7, 4, str_KAGAMI_F_WALK },
    { 3, 7, 4, str_KAGAMI_B_WALK },
    { 3, 7, 4, str_STAND_UP },
    { 3, 7, 4, str_JUMP_JUNBI },
    { 3, 7, 4, str_SP_JUMP_JUNBI },
    { 3, 7, 4, str_JUMP_FRONT },
    { 3, 7, 4, str_JUMP_VERTICAL },
    { 3, 7, 4, str_JUMP_BACK },
    { 3, 7, 4, str_S_JUMP_FRONT },
    { 3, 7, 4, str_S_JUMP_V },
    { 3, 7, 4, str_S_JUMP_BACK },
    { 3, 7, 4, str_SP_JUMP_FRONT },
    { 3, 7, 4, str_SP_JUMP_V },
    { 3, 7, 4, str_SP_JUMP_BACK },
    { 3, 7, 4, str_WALK_END },
    { 3, 7, 4, str_PARING_HEAD },
    { 3, 7, 4, str_PARING_UP },
    { 3, 7, 4, str_PARING_DOWN },
    { 3, 7, 4, str_PARING_AIR_F },
    { 3, 7, 4, str_PARING_AIR_B },
    { 3, 7, 4, str_GUARD_HEAD },
    { 3, 7, 4, str_GUARD_UP },
    { 3, 7, 4, str_GUARD_DOWN },
    { 3, 7, 4, str_GUARD_AIR },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_P_BREAK_ZUJOU },
    { 3, 7, 4, str_P_BREAK_UP },
    { 3, 7, 4, str_P_BREAK_DOWN },
    { 3, 7, 4, str_P_BREAK_AIR_F },
    { 3, 7, 4, str_P_BREAK_AIR_R },
    { 3, 7, 4, str_TUKAMIHAZUSI },
    { 3, 7, 4, str_TUKAMIHAZUSARE },
    { 3, 7, 4, str_TUKAMIHAZUSI },
    { 3, 7, 4, str_TUKAMIHAZUSARE },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_GUARD_HEAD_2 },
    { 3, 7, 4, str_GUARD_UP_2 },
    { 3, 7, 4, str_GUARD_DOWN_2 },
    { 3, 7, 4, str_GUARD_AIR_2 },
    { 3, 7, 4, str_HUSHIN_HEAD },
    { 3, 7, 4, str_HUSHIN_UP },
    { 3, 7, 4, str_HUSHIN_DOWN },
    { 3, 7, 4, str_HUSHIN_AIR },
    { 3, 7, 4, str_FACE_S },
    { 3, 7, 4, str_FACE_M },
    { 3, 7, 4, str_FACE_L },
    { 3, 7, 4, str_FACE_SP },
    { 3, 7, 4, str_FOOK_OKU_S },
    { 3, 7, 4, str_FOOK_OKU_M },
    { 3, 7, 4, str_FOOK_OKU_L },
    { 3, 7, 4, str_FOOK_OKU_SP },
    { 3, 7, 4, str_FOOK_TEMAE_S },
    { 3, 7, 4, str_FOOK_TEMAE_M },
    { 3, 7, 4, str_FOOK_TEMAE_L },
    { 3, 7, 4, str_FOOK_TEMAE_SP },
    { 3, 7, 4, str_UPPER_S },
    { 3, 7, 4, str_UPPER_M },
    { 3, 7, 4, str_UPPER_L },
    { 3, 7, 4, str_UPPER_SP },
    { 3, 7, 4, str_NOUTEN_S },
    { 3, 7, 4, str_NOUTEN_M },
    { 3, 7, 4, str_NOUTEN_L },
    { 3, 7, 4, str_NOUTEN_SP },
    { 3, 7, 4, str_BODY_BROW_S },
    { 3, 7, 4, str_BODY_BROW_M },
    { 3, 7, 4, str_BODY_BROW_L },
    { 3, 7, 4, str_BODY_BROW_SP },
    { 3, 7, 4, str_BODY_UPPER_S },
    { 3, 7, 4, str_BODY_UPPER_M },
    { 3, 7, 4, str_BODY_UPPER_L },
    { 3, 7, 4, str_BODY_UPPER_SP },
    { 3, 7, 4, str_TATAKI_S },
    { 3, 7, 4, str_TATAKI_M },
    { 3, 7, 4, str_TATAKI_L },
    { 3, 7, 4, str_TATAKI_SP },
    { 3, 7, 4, str_TATAKI_V_S },
    { 3, 7, 4, str_TATAKI_V_M },
    { 3, 7, 4, str_TATAKI_V_L },
    { 3, 7, 4, str_TATAKI_V_SP },
    { 3, 7, 4, str_NOBASITA_TE_S },
    { 3, 7, 4, str_NOBASITA_TE_M },
    { 3, 7, 4, str_NOBASITA_TE_L },
    { 3, 7, 4, str_NOBASITA_TE_SP },
    { 3, 7, 4, str_KAGAMI_S },
    { 3, 7, 4, str_KAGAMI_M },
    { 3, 7, 4, str_KAGAMI_L },
    { 3, 7, 4, str_KAGAMI_SP },
    { 3, 7, 4, str_KGM_TATAKI_S },
    { 3, 7, 4, str_KGM_TATAKI_M },
    { 3, 7, 4, str_KGM_TATAKI_L },
    { 3, 7, 4, str_KGM_TATAKI_SP },
    { 3, 7, 4, str_KGM_TTKI_V_S },
    { 3, 7, 4, str_KGM_TTKI_V_M },
    { 3, 7, 4, str_KGM_TTKI_V_L },
    { 3, 7, 4, str_KGM_TTKI_V_SP },
    { 3, 7, 4, str_NEKOROBI_S },
    { 3, 7, 4, str_NEKOROBI_M },
    { 3, 7, 4, str_NEKOROBI_L },
    { 3, 7, 4, str_NEKOROBI_SP },
    { 3, 7, 4, str_OKIAGARI },
    { 3, 7, 4, str_OKIAGARI_F },
    { 3, 7, 4, str_OKIAGARI_B },
    { 3, 7, 4, str_LOSE_NO_STAND },
    { 3, 7, 4, str_LOSE_SONABA },
    { 3, 7, 4, str_LOSE_KAGAMI },
    { 3, 7, 4, str_PIYO },
    { 3, 7, 4, str_UKEMI_MOVE_F },
    { 3, 7, 4, str_UKEMI_MOVE_R },
    { 3, 7, 4, str_SHIMEOTASARE },
    { 3, 7, 4, str_TATI_TOUKETU_S },
    { 3, 7, 4, str_TATI_TOUKETU_M },
    { 3, 7, 4, str_TATI_TOUKETU_L },
    { 3, 7, 4, str_TATI_TOUKETU_P },
    { 3, 7, 4, str_KGM_TOUKETU_S },
    { 3, 7, 4, str_KGM_TOUKETU_M },
    { 3, 7, 4, str_KGM_TOUKETU_L },
    { 3, 7, 4, str_KGM_TOUKETU_P },
    { 3, 7, 4, str_TATI_DENGEKI_S },
    { 3, 7, 4, str_TATI_DENGEKI_M },
    { 3, 7, 4, str_TATI_DENGEKI_L },
    { 3, 7, 4, str_TATI_DENGEKI_P },
    { 3, 7, 4, str_KGM_DENGEKI_S },
    { 3, 7, 4, str_KGM_DENGEKI_M },
    { 3, 7, 4, str_KGM_DENGEKI_L },
    { 3, 7, 4, str_KGM_DENGEKI_P },
    { 3, 7, 4, str_OKIAGARI_FRONT },
    { 3, 7, 4, str_OKIAGARI_REAR },
    { 3, 7, 4, str_TATI_MOE_S },
    { 3, 7, 4, str_TATI_MOE_M },
    { 3, 7, 4, str_TATI_MOE_L },
    { 3, 7, 4, str_TATI_MOE_SP },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_AIR_NORMAL },
    { 3, 7, 4, str_ASIBARAI_SIRI },
    { 3, 7, 4, str_ASIB_TUNNOMERI },
    { 3, 7, 4, str_NOKEZORI },
    { 3, 7, 4, str_KUNOJI },
    { 3, 7, 4, str_KIRIMOMI },
    { 3, 7, 4, str_UPPER },
    { 3, 7, 4, str_BODY_UPPER },
    { 3, 7, 4, str_HARAYARARE },
    { 3, 7, 4, str_TATAKI_AIR },
    { 3, 7, 4, str_TTKI_V_AIR },
    { 3, 7, 4, str_HUMI_ASIB },
    { 3, 7, 4, str_FACE },
    { 3, 7, 4, str_ASIB_SIRI_LOSE },
    { 3, 7, 4, str_ASIB_TUN_LOSE },
    { 3, 7, 4, str_DENKI },
    { 3, 7, 4, str_KUNOJI_NOKE },
    { 3, 7, 4, str_BODY_UPPER_SP_2 },
    { 3, 7, 4, str_HANEAGARI },
    { 3, 7, 4, str_TOUKETSU_A },
    { 3, 7, 4, str_BODY_SLAM },
    { 3, 7, 4, str_IPPONZEOI },
    { 3, 7, 4, str_TOMOE_RYU },
    { 3, 7, 4, str_MONKEY_FLIP },
    { 3, 7, 4, str_TOMOE_ORO },
    { 3, 7, 4, str_SNAKE_FANG },
    { 3, 7, 4, str_FLANKEN_S },
    { 3, 7, 4, str_KISHINRIKI },
    { 3, 7, 4, str_SPLASH_M },
    { 3, 7, 4, str_HARAIGOSHI },
    { 3, 7, 4, str_ALEX_B_D },
    { 3, 7, 4, str_GILL_3 },
    { 3, 7, 4, str_HANEKAERI_HARA },
    { 3, 7, 4, str_S_HANEAGARI },
    { 3, 7, 4, str_TATUMAKIZANKU },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_CATCH_1 },
    { 3, 7, 4, str_CATCH_2 },
    { 3, 7, 4, str_CATCH_3 },
    { 3, 7, 4, str_CATCH_4 },
    { 3, 7, 4, str_CATCH_5 },
    { 3, 7, 4, str_CATCH_6 },
    { 3, 7, 4, str_CATCH_7 },
    { 3, 7, 4, str_CATCH_8 },
    { 3, 7, 4, str_CATCH_9 },
    { 3, 7, 4, str_CATCH_10 },
    { 3, 7, 4, str_CATCH_11 },
    { 3, 7, 4, str_CATCH_12 },
    { 3, 7, 4, str_CATCH_13 },
    { 3, 7, 4, str_CATCH_14 },
    { 3, 7, 4, str_CATCH_15 },
    { 3, 7, 4, str_CATCH_16 },
    { 3, 7, 4, str_CATCH_17 },
    { 3, 7, 4, str_CATCH_18 },
    { 3, 7, 4, str_CATCH_19 },
    { 3, 7, 4, str_CATCH_20 },
    { 3, 7, 4, str_CATCH_21 },
    { 3, 7, 4, str_CATCH_22 },
    { 3, 7, 4, str_CATCH_23 },
    { 3, 7, 4, str_CATCH_24 },
    { 3, 7, 4, str_CATCH_25 },
    { 3, 7, 4, str_CATCH_26 },
    { 3, 7, 4, str_CATCH_27 },
    { 3, 7, 4, str_CATCH_28 },
    { 3, 7, 4, str_CATCH_29 },
    { 3, 7, 4, str_CATCH_30 },
    { 3, 7, 4, str_CATCH_31 },
    { 3, 7, 4, str_CATCH_32 },
    { 3, 7, 4, str_CATCH_33 },
    { 3, 7, 4, str_CATCH_34 },
    { 3, 7, 4, str_CATCH_35 },
    { 3, 7, 4, str_CATCH_36 },
    { 3, 7, 4, str_CATCH_37 },
    { 3, 7, 4, str_CATCH_38 },
    { 3, 7, 4, str_CATCH_39 },
    { 3, 7, 4, str_CATCH_40 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_ALEX_ZUTUKI },
    { 3, 7, 4, str_ALEX_BODY_S },
    { 3, 7, 4, str_ALEX_BACK_D },
    { 3, 7, 4, str_ALEX_POWER_B },
    { 3, 7, 4, str_ALEX_SLEEPER },
    { 3, 7, 4, str_RYU_SEOINAGE },
    { 3, 7, 4, str_IBUKI_2 },
    { 3, 7, 4, str_DADLEY_L_B },
    { 3, 7, 4, str_IBUKI_KUBIORI },
    { 3, 7, 4, str_NECRO_S_T },
    { 3, 7, 4, str_RYU_TOMOENAGE },
    { 3, 7, 4, str_YUN_HIZAGERI },
    { 3, 7, 4, str_ORO_KUBISIME },
    { 3, 7, 4, str_NECRO_G_S },
    { 3, 7, 4, str_DUDDLEY_D_S },
    { 3, 7, 4, str_YUN_MONKEY_F },
    { 3, 7, 4, str_ORO_TOMOENAGE },
    { 3, 7, 4, str_ORO_NIOURIKI },
    { 3, 7, 4, str_ORO_GIGOKU_G },
    { 3, 7, 4, str_YUN_2 },
    { 3, 7, 4, str_NECRO_SNAKE_F },
    { 3, 7, 4, str_NECRO_F_S },
    { 3, 7, 4, str_IBUKI_HARAIG },
    { 3, 7, 4, str_GILL_SPLASH_M },
    { 3, 7, 4, str_KEN_HIZAGERI },
    { 3, 7, 4, str_ORO_KISINRIKI },
    { 3, 7, 4, str_SEAN_TACKLE },
    { 3, 7, 4, str_ALEX_HYPER_B },
    { 3, 7, 4, str_NECRO_SLAM_D },
    { 3, 7, 4, str_ELENA_ASINAGE },
    { 3, 7, 4, str_GILL_IMPACT_C },
    { 3, 7, 4, str_ALEX_S_H_B },
    { 3, 7, 4, str_ALEX_F_N_D },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_IBUKI_2 },
    { 3, 7, 4, str_IBUKI_YOROI_D },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_MAWARIKOMI_M_F },
    { 3, 7, 4, str_HUGO_BODY_S },
    { 3, 7, 4, str_HUGO_N_G_T },
    { 3, 7, 4, str_HUGO_M_S_P },
    { 3, 7, 4, str_HUGO_S_D_B_B },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_S_PUNCH_A },
    { 3, 7, 4, str_S_PUNCH_B },
    { 3, 7, 4, str_S_PUNCH_C },
    { 3, 7, 4, str_M_PUNCH_A },
    { 3, 7, 4, str_M_PUNCH_B },
    { 3, 7, 4, str_M_PUNCH_C },
    { 3, 7, 4, str_L_PUNCH_A },
    { 3, 7, 4, str_L_PUNCH_B },
    { 3, 7, 4, str_L_PUNCH_C },
    { 3, 7, 4, str_S_KICK_A },
    { 3, 7, 4, str_S_KICK_B },
    { 3, 7, 4, str_S_KICK_C },
    { 3, 7, 4, str_M_KICK_A },
    { 3, 7, 4, str_M_KICK_B },
    { 3, 7, 4, str_M_KICK_C },
    { 3, 7, 4, str_L_KICK_A },
    { 3, 7, 4, str_L_KICK_B },
    { 3, 7, 4, str_L_KICK_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_P_A },
    { 3, 7, 4, str_KAGAMI_P_B },
    { 3, 7, 4, str_KAGAMI_P_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_KAGAMI_K_A },
    { 3, 7, 4, str_KAGAMI_K_B },
    { 3, 7, 4, str_KAGAMI_K_C },
    { 3, 7, 4, str_V_JUMP_P_S_A },
    { 3, 7, 4, str_V_JUMP_P_S_B },
    { 3, 7, 4, str_V_JUMP_P_M_A },
    { 3, 7, 4, str_V_JUMP_P_M_B },
    { 3, 7, 4, str_V_JUMP_P_L_A },
    { 3, 7, 4, str_V_JUMP_P_L_B },
    { 3, 7, 4, str_V_JUMP_K_S_A },
    { 3, 7, 4, str_V_JUMP_K_S_B },
    { 3, 7, 4, str_V_JUMP_K_M_A },
    { 3, 7, 4, str_V_JUMP_K_M_B },
    { 3, 7, 4, str_V_JUMP_K_L_A },
    { 3, 7, 4, str_V_JUMP_K_L_B },
    { 3, 7, 4, str_F_JUMP_P_S_A },
    { 3, 7, 4, str_F_JUMP_P_S_B },
    { 3, 7, 4, str_F_JUMP_P_M_A },
    { 3, 7, 4, str_F_JUMP_P_M_B },
    { 3, 7, 4, str_F_JUMP_P_L_A },
    { 3, 7, 4, str_F_JUMP_P_L_B },
    { 3, 7, 4, str_F_JUMP_K_S_A },
    { 3, 7, 4, str_F_JUMP_K_S_B },
    { 3, 7, 4, str_F_JUMP_K_M_A },
    { 3, 7, 4, str_F_JUMP_K_M_B },
    { 3, 7, 4, str_F_JUMP_K_L_A },
    { 3, 7, 4, str_F_JUMP_K_L_B },
    { 3, 7, 4, str_B_JUMP_P_S_A },
    { 3, 7, 4, str_B_JUMP_P_S_B },
    { 3, 7, 4, str_B_JUMP_P_M_A },
    { 3, 7, 4, str_B_JUMP_P_M_B },
    { 3, 7, 4, str_B_JUMP_P_L_A },
    { 3, 7, 4, str_B_JUMP_P_L_B },
    { 3, 7, 4, str_B_JUMP_K_S_A },
    { 3, 7, 4, str_B_JUMP_K_S_B },
    { 3, 7, 4, str_B_JUMP_K_M_A },
    { 3, 7, 4, str_B_JUMP_K_M_B },
    { 3, 7, 4, str_B_JUMP_K_L_A },
    { 3, 7, 4, str_B_JUMP_K_L_B },
    { 3, 7, 4, str_SP_V_JP_S_P_A },
    { 3, 7, 4, str_SP_V_JP_S_P_B },
    { 3, 7, 4, str_SP_V_JP_M_P_A },
    { 3, 7, 4, str_SP_V_JP_M_P_B },
    { 3, 7, 4, str_SP_V_JP_L_P_A },
    { 3, 7, 4, str_SP_V_JP_L_P_B },
    { 3, 7, 4, str_SP_V_JP_S_K_A },
    { 3, 7, 4, str_SP_V_JP_S_K_B },
    { 3, 7, 4, str_SP_V_JP_M_K_A },
    { 3, 7, 4, str_SP_V_JP_M_K_B },
    { 3, 7, 4, str_SP_V_JP_L_K_A },
    { 3, 7, 4, str_SP_V_JP_L_K_B },
    { 3, 7, 4, str_SP_F_JP_S_P_A },
    { 3, 7, 4, str_SP_F_JP_S_P_B },
    { 3, 7, 4, str_SP_F_JP_M_P_A },
    { 3, 7, 4, str_SP_F_JP_M_P_B },
    { 3, 7, 4, str_SP_F_JP_L_P_A },
    { 3, 7, 4, str_SP_F_JP_L_P_B },
    { 3, 7, 4, str_SP_F_JP_S_K_A },
    { 3, 7, 4, str_SP_F_JP_S_K_B },
    { 3, 7, 4, str_SP_F_JP_M_K_A },
    { 3, 7, 4, str_SP_F_JP_M_K_B },
    { 3, 7, 4, str_SP_F_JP_L_K_A },
    { 3, 7, 4, str_SP_F_JP_L_K_B },
    { 3, 7, 4, str_SP_B_JP_S_P_A },
    { 3, 7, 4, str_SP_B_JP_S_P_B },
    { 3, 7, 4, str_SP_B_JP_M_P_A },
    { 3, 7, 4, str_SP_B_JP_M_P_B },
    { 3, 7, 4, str_SP_B_JP_L_P_A },
    { 3, 7, 4, str_SP_B_JP_L_P_B },
    { 3, 7, 4, str_SP_B_JP_S_K_A },
    { 3, 7, 4, str_SP_B_JP_S_K_B },
    { 3, 7, 4, str_SP_B_JP_M_K_A },
    { 3, 7, 4, str_SP_B_JP_M_K_B },
    { 3, 7, 4, str_SP_B_JP_L_K_A },
    { 3, 7, 4, str_SP_B_JP_L_K_B },
    { 3, 7, 4, str_S_V_JP_S_P_A },
    { 3, 7, 4, str_S_V_JP_S_P_B },
    { 3, 7, 4, str_S_V_JP_M_P_A },
    { 3, 7, 4, str_S_V_JP_M_P_B },
    { 3, 7, 4, str_S_V_JP_L_P_A },
    { 3, 7, 4, str_S_V_JP_L_P_B },
    { 3, 7, 4, str_S_V_JP_S_K_A },
    { 3, 7, 4, str_S_V_JP_S_K_B },
    { 3, 7, 4, str_S_V_JP_M_K_A },
    { 3, 7, 4, str_S_V_JP_M_K_B },
    { 3, 7, 4, str_S_V_JP_L_K_A },
    { 3, 7, 4, str_S_V_JP_L_K_B },
    { 3, 7, 4, str_S_F_JP_S_P_A },
    { 3, 7, 4, str_S_F_JP_S_P_B },
    { 3, 7, 4, str_S_F_JP_M_P_A },
    { 3, 7, 4, str_S_F_JP_M_P_B },
    { 3, 7, 4, str_S_F_JP_L_P_A },
    { 3, 7, 4, str_S_F_JP_L_P_B },
    { 3, 7, 4, str_S_F_JP_S_K_A },
    { 3, 7, 4, str_S_F_JP_S_K_B },
    { 3, 7, 4, str_S_F_JP_M_K_A },
    { 3, 7, 4, str_S_F_JP_M_K_B },
    { 3, 7, 4, str_S_F_JP_L_K_A },
    { 3, 7, 4, str_S_F_JP_L_K_B },
    { 3, 7, 4, str_S_B_JP_S_P_A },
    { 3, 7, 4, str_S_B_JP_S_P_B },
    { 3, 7, 4, str_S_B_JP_M_P_A },
    { 3, 7, 4, str_S_B_JP_M_P_B },
    { 3, 7, 4, str_S_B_JP_L_P_A },
    { 3, 7, 4, str_S_B_JP_L_P_B },
    { 3, 7, 4, str_S_B_JP_S_K_A },
    { 3, 7, 4, str_S_B_JP_S_K_B },
    { 3, 7, 4, str_S_B_JP_M_K_A },
    { 3, 7, 4, str_S_B_JP_M_K_B },
    { 3, 7, 4, str_S_B_JP_L_K_A },
    { 3, 7, 4, str_S_B_JP_L_K_B },
    { 3, 7, 4, str_TUKAMIKAKARI_A },
    { 3, 7, 4, str_TUKAMIKAKARI_B },
    { 3, 7, 4, str_TUKAMIKAKARI_C },
    { 3, 7, 4, str_TUKAMIKAKARI_D },
    { 3, 7, 4, str_TUKAMIKAKARI_E },
    { 3, 7, 4, str_TUKAMIKAKARI_F },
    { 3, 7, 4, str_TUKAMI_AIR_A },
    { 3, 7, 4, str_TUKAMI_AIR_B },
    { 3, 7, 4, str_TUKAMI_AIR_C },
    { 3, 7, 4, str_TUKAMI_AIR_D },
    { 3, 7, 4, str_TUKAMI_AIR_E },
    { 3, 7, 4, str_TUKAMI_AIR_F },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_UP_P_GUARD_P_S },
    { 3, 7, 4, str_UP_P_GUARD_P_M },
    { 3, 7, 4, str_UP_P_GUARD_P_L },
    { 3, 7, 4, str_UP_P_GUARD_K_S },
    { 3, 7, 4, str_UP_P_GUARD_K_M },
    { 3, 7, 4, str_UP_P_GUARD_K_L },
    { 3, 7, 4, str_D_P_GUARD_P_S },
    { 3, 7, 4, str_D_P_GUARD_P_M },
    { 3, 7, 4, str_D_P_GUARD_P_L },
    { 3, 7, 4, str_D_P_GUARD_K_S },
    { 3, 7, 4, str_D_P_GUARD_K_M },
    { 3, 7, 4, str_D_P_GUARD_K_L },
    { 3, 7, 4, str_FUSHIN_P_S },
    { 3, 7, 4, str_FUSHIN_P_M },
    { 3, 7, 4, str_FUSHIN_P_L },
    { 3, 7, 4, str_FUSHIN_K_S },
    { 3, 7, 4, str_FUSHIN_K_M },
    { 3, 7, 4, str_FUSHIN_K_L },
    { 3, 7, 4, str_OKIAGARI_P_S },
    { 3, 7, 4, str_OKIAGARI_P_M },
    { 3, 7, 4, str_OKIAGARI_P_L },
    { 3, 7, 4, str_OKIAGARI_K_S },
    { 3, 7, 4, str_OKIAGARI_K_M },
    { 3, 7, 4, str_OKIAGARI_K_L },
    { 3, 7, 4, str_ATTACK_1_S },
    { 3, 7, 4, str_ATTACK_1_M },
    { 3, 7, 4, str_ATTACK_1_L },
    { 3, 7, 4, str_ATTACK_1_SP },
    { 3, 7, 4, str_ATTACK_2_S },
    { 3, 7, 4, str_ATTACK_2_M },
    { 3, 7, 4, str_ATTACK_2_L },
    { 3, 7, 4, str_ATTACK_2_SP },
    { 3, 7, 4, str_ATTACK_3_S },
    { 3, 7, 4, str_ATTACK_3_M },
    { 3, 7, 4, str_ATTACK_3_L },
    { 3, 7, 4, str_ATTACK_3_SP },
    { 3, 7, 4, str_ATTACK_4_S },
    { 3, 7, 4, str_ATTACK_4_M },
    { 3, 7, 4, str_ATTACK_4_L },
    { 3, 7, 4, str_ATTACK_4_SP },
    { 3, 7, 4, str_ATTACK_5_S },
    { 3, 7, 4, str_ATTACK_5_M },
    { 3, 7, 4, str_ATTACK_5_L },
    { 3, 7, 4, str_ATTACK_5_SP },
    { 3, 7, 4, str_ATTACK_6_S },
    { 3, 7, 4, str_ATTACK_6_M },
    { 3, 7, 4, str_ATTACK_6_L },
    { 3, 7, 4, str_ATTACK_6_SP },
    { 3, 7, 4, str_ATTACK_7_S },
    { 3, 7, 4, str_ATTACK_7_M },
    { 3, 7, 4, str_ATTACK_7_L },
    { 3, 7, 4, str_ATTACK_7_SP },
    { 3, 7, 4, str_ATTACK_8_S },
    { 3, 7, 4, str_ATTACK_8_M },
    { 3, 7, 4, str_ATTACK_8_L },
    { 3, 7, 4, str_ATTACK_8_SP },
    { 3, 7, 4, str_ATTACK_9_S },
    { 3, 7, 4, str_ATTACK_9_M },
    { 3, 7, 4, str_ATTACK_9_L },
    { 3, 7, 4, str_ATTACK_9_SP },
    { 3, 7, 4, str_ATTACK_10_S },
    { 3, 7, 4, str_ATTACK_10_M },
    { 3, 7, 4, str_ATTACK_10_L },
    { 3, 7, 4, str_ATTACK_10_SP },
    { 3, 7, 4, str_ATTACK_11_S },
    { 3, 7, 4, str_ATTACK_11_M },
    { 3, 7, 4, str_ATTACK_11_L },
    { 3, 7, 4, str_ATTACK_11_SP },
    { 3, 7, 4, str_ATTACK_12_S },
    { 3, 7, 4, str_ATTACK_12_M },
    { 3, 7, 4, str_ATTACK_12_L },
    { 3, 7, 4, str_ATTACK_12_SP },
    { 3, 7, 4, str_ATTACK_13_S },
    { 3, 7, 4, str_ATTACK_13_M },
    { 3, 7, 4, str_ATTACK_13_L },
    { 3, 7, 4, str_ATTACK_13_SP },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_HANASARE },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_EFF01_CHAR },
    { 3, 7, 4, str_EFF13_CHAR },
    { 3, 7, 4, str_BONUS_CHAR },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_JUDGEMENT_GAL },
    { 3, 7, 4, str_EXTRA },
    { 3, 7, 4, str_PLEF },
    { 3, 7, 4, str_SELECT },
    { 3, 7, 4, str_ETC_1 },
    { 3, 7, 4, str_ETC_2 },
    { 3, 7, 4, str_ETC_3 },
    { 3, 7, 4, str_RUCCIA },
    { 3, 7, 4, str_AFRICA_2 },
    { 3, 7, 4, str_N_Y },
    { 3, 7, 4, str_HONGKONG },
    { 3, 7, 4, str_JAPAN2 },
    { 3, 7, 4, str_GERMANY_2 },
    { 3, 7, 4, str_BRAZIL_2 },
    { 3, 7, 4, str_ORUMEKA },
    { 3, 7, 4, str_ENGLAND_2 },
    { 3, 7, 4, str_JAPAN_3 },
    { 3, 7, 4, str_GILL_STAGE },
    { 3, 7, 4, str_JAPAN_11 },
    { 3, 7, 4, str_BONUS },
    { 3, 7, 4, str_FRANCE_2 },
    { 3, 7, 4, str_CHAINA_2 },
    { 3, 7, 4, str_BRAZIL_1_2 },
    { 3, 7, 4, str_JAPAN_10 },
    { 3, 7, 4, str_ENDING },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_APPEAR_JUNBI_1 },
    { 3, 7, 4, str_APPEAR_JUNBI_2 },
    { 3, 7, 4, str_APPEAR_JUNBI_3 },
    { 3, 7, 4, str_APPEAR_JUNBI_4 },
    { 3, 7, 4, str_APPEAR_JUNBI_5 },
    { 3, 7, 4, str_APPEAR_JUNBI_6 },
    { 3, 7, 4, str_APPEAR_JUNBI_7 },
    { 3, 7, 4, str_APPEAR_JUNBI_8 },
    { 3, 7, 4, str_APPEAR_1 },
    { 3, 7, 4, str_APPEAR_2 },
    { 3, 7, 4, str_APPEAR_3 },
    { 3, 7, 4, str_APPEAR_4 },
    { 3, 7, 4, str_APPEAR_5 },
    { 3, 7, 4, str_APPEAR_6 },
    { 3, 7, 4, str_APPEAR_7 },
    { 3, 7, 4, str_APPEAR_8 },
    { 3, 7, 4, str_SP_APPEAR_1 },
    { 3, 7, 4, str_SP_APPEAR_2 },
    { 3, 7, 4, str_SP_APPEAR_3 },
    { 3, 7, 4, str_SP_APPEAR_4 },
    { 3, 7, 4, str_SP_APPEAR_5 },
    { 3, 7, 4, str_SP_APPEAR_6 },
    { 3, 7, 4, str_SP_APPEAR_7 },
    { 3, 7, 4, str_SP_APPEAR_8 },
    { 3, 7, 4, str_ZANNEN_1 },
    { 3, 7, 4, str_ZANNEN_2 },
    { 3, 7, 4, str_ZANNEN_3 },
    { 3, 7, 4, str_ZANNEN_4 },
    { 3, 7, 4, str_ZANNEN_5 },
    { 3, 7, 4, str_ZANNEN_6 },
    { 3, 7, 4, str_ZANNEN_7 },
    { 3, 7, 4, str_ZANNEN_8 },
    { 3, 7, 4, str_WIN_1 },
    { 3, 7, 4, str_WIN_2 },
    { 3, 7, 4, str_WIN_3 },
    { 3, 7, 4, str_WIN_4 },
    { 3, 7, 4, str_WIN_5 },
    { 3, 7, 4, str_WIN_6 },
    { 3, 7, 4, str_WIN_7 },
    { 3, 7, 4, str_WIN_8 },
    { 3, 7, 4, str_SP_WIN_1 },
    { 3, 7, 4, str_SP_WIN_2 },
    { 3, 7, 4, str_SP_WIN_3 },
    { 3, 7, 4, str_SP_WIN_4 },
    { 3, 7, 4, str_SP_WIN_5 },
    { 3, 7, 4, str_SP_WIN_6 },
    { 3, 7, 4, str_SP_WIN_7 },
    { 3, 7, 4, str_SP_WIN_8 },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WAIT },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_WIN },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_JUDGMENT_LOSE },
    { 3, 7, 4, str_WAIT },
    { 3, 7, 4, str_AFRICA_JUMP },
    { 3, 7, 4, str_AFRICA_LAND },
    { 3, 7, 4, str_SEAN_BALL_HIT },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_BONUS_WIN_1 },
    { 3, 7, 4, str_BONUS_WIN_2 },
    { 3, 7, 4, str_BONUS_WIN_3 },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_APPEAR_USE },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
    { 3, 7, 4, str_empty_10 },
};
/* 02004B74 */
const TM_STRING* dbg_act_name_tbl[11] = {
    &dbg_act_kind_str[12],
    &dbg_act_kind_str[77],
    &dbg_act_kind_str[231],
    &dbg_act_kind_str[279],
    &dbg_act_kind_str[329],
    &dbg_act_kind_str[610],
    &dbg_act_kind_str[181],
    &dbg_act_kind_str[722],
    &dbg_act_kind_str[895],
    &dbg_act_kind_str[895],
    &dbg_act_kind_str[853],
};
/* 02004BA0 */
u32* dbg_pl_char_tbl[29][9] = {
    { gill_nmca, gill_dmca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_btca, gill_exca, gill_yuca },
    { alex_nmca, alex_dmca, alex_caca, alex_cuca, alex_atca, alex_saca, alex_btca, alex_exca, alex_yuca },
    { ryu_nmca, ryu_dmca, ryu_caca, ryu_cuca, ryu_atca, ryu_saca, ryu_btca, ryu_exca, ryu_yuca },
    { yun_nmca, yun_dmca, yun_caca, yun_cuca, yun_atca, yun_saca, yun_btca, yun_exca, yun_yuca },
    { dudley_nmca, dudley_dmca, dudley_caca, dudley_cuca, dudley_atca, dudley_saca, dudley_btca, dudley_exca, dudley_yuca },
    { necro_nmca, necro_dmca, necro_caca, necro_cuca, necro_atca, necro_saca, necro_btca, necro_exca, necro_yuca },
    { hugo_nmca, hugo_dmca, hugo_caca, hugo_cuca, hugo_atca, hugo_saca, hugo_btca, hugo_exca, hugo_yuca },
    { ibuki_nmca, ibuki_dmca, ibuki_caca, ibuki_cuca, ibuki_atca, ibuki_saca, ibuki_btca, ibuki_exca, ibuki_yuca },
    { elena_nmca, elena_dmca, elena_caca, elena_cuca, elena_atca, elena_saca, elena_btca, elena_exca, elena_yuca },
    { oro_nmca, oro_dmca, oro_caca, oro_cuca, oro_atca, oro_saca, oro_btca, oro_exca, oro_yuca },
    { yang_nmca, yang_dmca, yang_caca, yang_cuca, yang_atca, yang_saca, yang_btca, yang_exca, yang_yuca },
    { ken_nmca, ken_dmca, ken_caca, ken_cuca, ken_atca, ken_saca, ken_btca, ken_exca, ken_yuca },
    { sean_nmca, sean_dmca, sean_caca, sean_cuca, sean_atca, sean_saca, sean_btca, sean_exca, sean_yuca },
    { urien_nmca, urien_dmca, urien_caca, urien_cuca, urien_atca, urien_saca, urien_btca, urien_exca, urien_yuca },
    { gouki1_nmca, gouki1_dmca, gouki1_caca, gouki1_cuca, gouki1_atca, gouki1_saca, gouki1_btca, gouki1_exca, gouki1_yuca },
    { gouki2_nmca, gouki2_dmca, gouki2_caca, gouki2_cuca, gouki2_atca, gouki2_saca, gouki2_btca, gouki2_exca, gouki2_yuca },
    { chun_nmca, chun_dmca, chun_caca, chun_cuca, chun_atca, chun_saca, chun_btca, chun_exca, chun_yuca },
    { makoto_nmca, makoto_dmca, makoto_caca, makoto_cuca, makoto_atca, makoto_saca, makoto_btca, makoto_exca, makoto_yuca },
    { q_nmca, q_dmca, q_caca, q_cuca, q_atca, q_saca, q_btca, q_exca, q_yuca },
    { no12_nmca, no12_dmca, no12_caca, no12_cuca, no12_atca, no12_saca, no12_btca, no12_exca, no12_yuca },
    { remy_nmca, remy_dmca, remy_caca, remy_cuca, remy_atca, remy_saca, remy_btca, remy_exca, remy_yuca },
    { gill_nmca, gill_dmca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_btca, gill_exca, gill_yuca },
    { gill_nmca, gill_dmca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_btca, gill_exca, gill_yuca },
    { gill_nmca, gill_dmca, gill_caca, gill_cuca, gill_atca, gill_saca, gill_btca, gill_exca, gill_yuca },
    { ef01_char_table, ef13_char_table, bonus_char_table, (u32*)&ef13_char_table_225[108], (u32*)&ef13_char_table_225[116], (u32*)&ef13_char_table_225[124], (u32*)&ef13_char_table_225[132], (u32*)&ef13_char_table_225[140], (u32*)&ef13_char_table_225[148] },
    { (u32*)&ef13_char_table_225[156], (u32*)&ef13_char_table_225[164], ag_face_panel_table, plef_char_table, sel_pl_char_table, etc_char_table, etc2_char_table, etc3_char_table, rca_char_table },
    { afc_char_table, usa_char_table, hkg_char_table, (u32*)&rca_char_table_023[36], grm_char_table, brz_char_table, orm_char_table, eng_char_table, jp3_char_table },
    { fnl_char_table, j11_char_table, bns_char_table, frc_char_table, chn_char_table, brz_char_table, j10_char_table, end_char_table, op_char_table },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

/*
 * EFFECT_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void clear_caution_flag();
extern void effect_00_move();
extern void effect_01_move();
extern void effect_02_move();
extern void effect_03_init();
extern void effect_03_move();
extern void effect_04_move();
extern void effect_05_move();
extern void effect_06_move();
extern void effect_07_move();
extern void effect_08_move();
extern void effect_09_init();
extern void effect_09_init2();
extern void effect_09_move();
extern void effect_10_move();
extern void effect_11_move();
extern void effect_12_move();
extern void effect_13_init();
extern void effect_13_move();
extern void effect_14_move();
extern void effect_15_move();
extern void effect_16_move();
extern void effect_17_move();
extern void effect_18_move();
extern void effect_19_move();
extern void effect_20_move();
extern void effect_21_move();
extern void effect_22_move();
extern void effect_23_move();
extern void effect_24_move();
extern void effect_25_move();
extern void effect_26_move();
extern void effect_27_move();
extern void effect_28_move();
extern void effect_29_move();
extern void effect_30_move();
extern void effect_31_move();
extern void effect_32_move();
extern void effect_33_move();
extern void effect_34_init();
extern void effect_34_move();
extern void effect_35_move();
extern void effect_36_move();
extern void effect_37_init();
extern void effect_37_move();
extern void effect_38_move();
extern void effect_39_move();
extern void effect_40_move();
extern void effect_41_init();
extern void effect_41_move();
extern void effect_42_move();
extern void effect_43_move();
extern void effect_44_move();
extern void effect_45_move();
extern void effect_46_move();
extern void effect_47_init();
extern void effect_47_move();
extern void effect_48_move();
extern void effect_49_move();
extern void effect_50_move();
extern void effect_51_move();
extern void effect_52_move();
extern void effect_53_move();
extern void effect_54_move();
extern void effect_55_move();
extern void effect_56_move();
extern void effect_57_move();
extern void effect_58_move();
extern void effect_59_move();
extern void effect_60_move();
extern void effect_61_move();
extern void effect_62_move();
extern void effect_63_move();
extern void effect_64_move();
extern void effect_65_move();
extern void effect_66_move();
extern void effect_67_move();
extern void effect_68_move();
extern void effect_69_move();
extern void effect_70_move();
extern void effect_71_move();
extern void effect_72_move();
extern void effect_73_init();
extern void effect_73_move();
extern void effect_74_move();
extern void effect_75_move();
extern void effect_76_move();
extern void effect_77_init();
extern void effect_77_move();
extern void effect_78_move();
extern void effect_79_move();
extern void effect_80_move();
extern void effect_81_move();
extern void effect_82_move();
extern void effect_83_move();
extern void effect_84_move();
extern void effect_85_move();
extern void effect_86_move();
extern void effect_87_move();
extern void effect_88_move();
extern void effect_89_move();
extern void effect_90_move();
extern void effect_91_move();
extern void effect_92_move();
extern void effect_93_move();
extern void effect_94_move();
extern void effect_95_move();
extern void effect_96_move();
extern void effect_97_move();
extern void effect_98_move();
extern void effect_99_move();
extern void effect_A0_move();
extern void effect_A1_move();
extern void effect_A2_move();
extern void effect_A3_move();
extern void effect_A4_move();
extern void effect_A5_move();
extern void effect_A6_move();
extern void effect_A7_move();
extern void effect_A8_move();
extern void effect_A9_move();
extern void effect_B0_move();
extern void effect_B1_move();
extern void effect_B2_move();
extern void effect_B3_move();
extern void effect_B4_move();
extern void effect_B5_move();
extern void effect_B6_move();
extern void effect_B7_move();
extern void effect_B8_move();
extern void effect_B9_move();
extern void effect_C0_init();
extern void effect_C0_move();
extern void effect_C1_move();
extern void effect_C2_move();
extern void effect_C3_move();
extern void effect_C4_move();
extern void effect_C5_move();
extern void effect_C6_move();
extern void effect_C7_init();
extern void effect_C7_move();
extern void effect_C8_move();
extern void effect_C9_move();
extern void effect_D0_init();
extern void effect_D0_move();
extern void effect_D1_init();
extern void effect_D1_move();
extern void effect_D2_move();
extern void effect_D3_move();
extern void effect_D4_init();
extern void effect_D4_move();
extern void effect_D5_init();
extern void effect_D5_move();
extern void effect_D6_init();
extern void effect_D6_move();
extern void effect_D7_move();
extern void effect_D8_move();
extern void effect_D9_init();
extern void effect_D9_move();
extern void effect_E0_move();
extern void effect_E1_move();
extern void effect_E2_move();
extern void effect_E3_move();
extern void effect_E4_move();
extern void effect_E5_move();
extern void effect_E6_move();
extern void effect_E7_move();
extern void effect_E8_move();
extern void effect_E9_move();
extern void effect_F0_move();
extern void effect_F1_init();
extern void effect_F1_move();
extern void effect_F2_move();
extern void effect_F3_move();
extern void effect_F4_init();
extern void effect_F4_move();
extern void effect_F5_move();
extern void effect_F6_move();
extern void effect_F7_move();
extern void effect_F8_init();
extern void effect_F8_move();
extern void effect_F9_move();
extern void effect_G0_move();
extern void effect_G1_move();
extern void effect_G2_move();
extern void effect_G3_init();
extern void effect_G3_move();
extern void effect_G4_init();
extern void effect_G4_move();
extern void effect_G5_move();
extern void effect_G6_init();
extern void effect_G6_move();
extern void effect_G7_init();
extern void effect_G7_move();
extern void effect_G8_move();
extern void effect_G9_move();
extern void effect_H0_move();
extern void effect_H1_move();
extern void effect_H2_move();
extern void effect_H3_move();
extern void effect_H4_move();
extern void effect_H5_move();
extern void effect_H6_move();
extern void effect_H7_init();
extern void effect_H7_move();
extern void effect_H8_init();
extern void effect_H8_move();
extern void effect_H9_init();
extern void effect_H9_move();
extern void effect_I0_init();
extern void effect_I0_move();
extern void effect_I1_move();
extern void effect_I2_move();
extern void effect_I3_move();
extern void effect_I4_move();
extern void effect_I5_move();
extern void effect_I6_move();
extern void effect_I7_init();
extern void effect_I7_move();
extern void effect_I8_move();
extern void effect_I9_move();
extern void effect_J0_move();
extern void effect_J1_move();
extern void effect_J2_move();
extern void effect_J3_init();
extern void effect_J3_move();
extern void effect_J4_init();
extern void effect_J4_move();
extern void effect_J5_move();
extern void effect_J6_move();
extern void effect_J7_move();
extern void effect_J8_move();
extern void effect_J9_move();
extern void effect_K0_move();
extern void effect_K1_move();
extern void effect_K2_move();
extern void effect_K3_move();
extern void effect_K4_move();
extern void effect_K5_move();
extern void effect_K6_move();
extern void effect_K7_move();
extern void effect_K8_init();
extern void effect_K8_move();
extern void effect_K9_init();
extern void effect_K9_move();
extern void effect_L0_move();
extern void effect_L1_move();
extern void effect_L2_move();
extern void effect_L3_move();
extern void effect_L4_move();
extern void effect_L5_move();
extern void effect_L6_move();
extern void effect_L7_init();
extern void effect_L7_move();
extern void effect_L8_move();
extern void effect_L9_move();
extern void effect_M0_move();
extern void effect_M1_move();
extern void effect_M2_init();
extern void effect_M2_move();
extern void effect_M3_move();
extern void effect_M4_move();
extern void effect_M5_move();
extern void effect_M6_move();
extern void effect_M7_move();
extern void effect_M8_init();
extern void effect_M8_move();
extern void erase_after_images();
extern void exec_char_asxy();
extern void flip_my_rl_flag();
extern void reset_extra_bg_flag();
extern void set_caution_flag();
extern void set_tenguiwa();
extern void setup_accessories();
extern void setup_after_images();
extern void setup_ase_extra();
extern void setup_bg_quake_x();
extern void setup_bg_quake_y();
extern void setup_command_number();
extern void setup_disp_flag();
extern void setup_dmv_use_flag();
extern void setup_exdm_ix();
extern void setup_free_program();
extern void setup_meoshi_hit_flag();
extern void setup_status_flag();

void (*const effmovejptbl[229])() = {
    effect_00_move,  effect_01_move,  effect_02_move,  effect_03_move,  /* 0 */
    effect_04_move,  effect_05_move,  effect_06_move,  effect_07_move,  /* 4 */
    effect_08_move,  effect_09_move,  effect_10_move,  effect_11_move,  /* 8 */
    effect_12_move,  effect_13_move,  effect_14_move,  effect_15_move,  /* 12 */
    effect_16_move,  effect_17_move,  effect_18_move,  effect_19_move,  /* 16 */
    effect_20_move,  effect_21_move,  effect_22_move,  effect_23_move,  /* 20 */
    effect_24_move,  effect_25_move,  effect_26_move,  effect_27_move,  /* 24 */
    effect_28_move,  effect_29_move,  effect_30_move,  effect_31_move,  /* 28 */
    effect_32_move,  effect_33_move,  effect_34_move,  effect_35_move,  /* 32 */
    effect_36_move,  effect_37_move,  effect_38_move,  effect_39_move,  /* 36 */
    effect_40_move,  effect_41_move,  effect_42_move,  effect_43_move,  /* 40 */
    effect_44_move,  effect_45_move,  effect_46_move,  effect_47_move,  /* 44 */
    effect_48_move,  effect_49_move,  effect_50_move,  effect_51_move,  /* 48 */
    effect_52_move,  effect_53_move,  effect_54_move,  effect_55_move,  /* 52 */
    effect_56_move,  effect_57_move,  effect_58_move,  effect_59_move,  /* 56 */
    effect_60_move,  effect_61_move,  effect_62_move,  effect_63_move,  /* 60 */
    effect_64_move,  effect_65_move,  effect_66_move,  effect_67_move,  /* 64 */
    effect_68_move,  effect_69_move,  effect_70_move,  effect_71_move,  /* 68 */
    effect_72_move,  effect_73_move,  effect_74_move,  effect_75_move,  /* 72 */
    effect_76_move,  effect_77_move,  effect_78_move,  effect_79_move,  /* 76 */
    effect_80_move,  effect_81_move,  effect_82_move,  effect_83_move,  /* 80 */
    effect_84_move,  effect_85_move,  effect_86_move,  effect_87_move,  /* 84 */
    effect_88_move,  effect_89_move,  effect_90_move,  effect_91_move,  /* 88 */
    effect_92_move,  effect_93_move,  effect_94_move,  effect_95_move,  /* 92 */
    effect_96_move,  effect_97_move,  effect_98_move,  effect_99_move,  /* 96 */
    effect_A0_move,  effect_A1_move,  effect_A2_move,  effect_A3_move,  /* 100 */
    effect_A4_move,  effect_A5_move,  effect_A6_move,  effect_A7_move,  /* 104 */
    effect_A8_move,  effect_A9_move,  effect_B0_move,  effect_B1_move,  /* 108 */
    effect_B2_move,  effect_B3_move,  effect_B4_move,  effect_B5_move,  /* 112 */
    effect_B6_move,  effect_B7_move,  effect_B8_move,  effect_B9_move,  /* 116 */
    effect_C0_move,  effect_C1_move,  effect_C2_move,  effect_C3_move,  /* 120 */
    effect_C4_move,  effect_C5_move,  effect_C6_move,  effect_C7_move,  /* 124 */
    effect_C8_move,  effect_C9_move,  effect_D0_move,  effect_D1_move,  /* 128 */
    effect_D2_move,  effect_D3_move,  effect_D4_move,  effect_D5_move,  /* 132 */
    effect_D6_move,  effect_D7_move,  effect_D8_move,  effect_D9_move,  /* 136 */
    effect_E0_move,  effect_E1_move,  effect_E2_move,  effect_E3_move,  /* 140 */
    effect_E4_move,  effect_E5_move,  effect_E6_move,  effect_E7_move,  /* 144 */
    effect_E8_move,  effect_E9_move,  effect_F0_move,  effect_F1_move,  /* 148 */
    effect_F2_move,  effect_F3_move,  effect_F4_move,  effect_F5_move,  /* 152 */
    effect_F6_move,  effect_F7_move,  effect_F8_move,  effect_F9_move,  /* 156 */
    effect_G0_move,  effect_G1_move,  effect_G2_move,  effect_G3_move,  /* 160 */
    effect_G4_move,  effect_G5_move,  effect_G6_move,  effect_G7_move,  /* 164 */
    effect_G8_move,  effect_G9_move,  effect_H0_move,  effect_H1_move,  /* 168 */
    effect_H2_move,  effect_H3_move,  effect_H4_move,  effect_H5_move,  /* 172 */
    effect_H6_move,  effect_H7_move,  effect_H8_move,  effect_H9_move,  /* 176 */
    effect_I0_move,  effect_I1_move,  effect_I2_move,  effect_I3_move,  /* 180 */
    effect_I4_move,  effect_I5_move,  effect_I6_move,  effect_I7_move,  /* 184 */
    effect_I8_move,  effect_I9_move,  effect_J0_move,  effect_J1_move,  /* 188 */
    effect_J2_move,  effect_J3_move,  effect_J4_move,  effect_J5_move,  /* 192 */
    effect_J6_move,  effect_J7_move,  effect_J8_move,  effect_J9_move,  /* 196 */
    effect_K0_move,  effect_K1_move,  effect_K2_move,  effect_K3_move,  /* 200 */
    effect_K4_move,  effect_K5_move,  effect_K6_move,  effect_K7_move,  /* 204 */
    effect_K8_move,  effect_K9_move,  effect_L0_move,  effect_L1_move,  /* 208 */
    effect_L2_move,  effect_L3_move,  effect_L4_move,  effect_L5_move,  /* 212 */
    effect_L6_move,  effect_L7_move,  effect_L8_move,  effect_L9_move,  /* 216 */
    effect_M0_move,  effect_M1_move,  effect_M2_move,  effect_M3_move,  /* 220 */
    effect_M4_move,  effect_M5_move,  effect_M6_move,  effect_M7_move,  /* 224 */
    effect_M8_move,  /* 228 */
};

void (*const effinitjptbl[39])() = {
    0, effect_03_init, effect_13_init, effect_09_init, effect_G7_init, effect_C0_init, effect_C7_init, effect_D0_init,
    effect_D1_init, effect_F4_init, effect_34_init, effect_37_init, effect_09_init2, effect_41_init, effect_D4_init, set_tenguiwa,
    effect_D9_init, setup_accessories, setup_after_images, erase_after_images, effect_F1_init, clear_caution_flag, setup_status_flag, reset_extra_bg_flag,
    flip_my_rl_flag, effect_F8_init, clear_caution_flag, effect_G3_init, effect_G4_init, setup_ase_extra, effect_G6_init, setup_meoshi_hit_flag,
    exec_char_asxy, set_caution_flag, effect_H7_init, effect_H8_init, effect_H9_init, setup_free_program, setup_bg_quake_x,
};

void (*const effinitjp_quake_y[19])() = {
    setup_bg_quake_y,      effect_47_init,        effect_I0_init,        effect_77_init,  /* 0 */
    setup_exdm_ix,         setup_dmv_use_flag,    effect_D5_init,        effect_D6_init,  /* 4 */
    setup_disp_flag,       setup_command_number,  effect_I7_init,        effect_J3_init,  /* 8 */
    effect_J4_init,        effect_73_init,        effect_K8_init,        effect_K9_init,  /* 12 */
    effect_L7_init,        effect_M2_init,        effect_M8_init,  /* 16 */
};

/*
 * ENTRY_TBL_B.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Entry_00();
extern void Entry_02();
extern void Entry_03();
extern void Entry_04();
extern void Entry_06();
extern void Entry_07();
extern void Entry_08();
extern void Entry_10();
extern void Entry_01();
extern const char sh_str_monitor_entry[];
extern const char sh_str_illegal_inst[];
extern const char sh_str_regs_r9_r11[];
extern const char sh_mn_sub_rm_rn[];
extern const char sh_mn_subc_rm_rn[];
extern const char sh_mn_subv_rm_rn[];
extern const char sh_mn_add_rm_rn[];
extern const char sh_mn_dmulsl_rm_rn[];
extern const char sh_mn_addc_rm_rn[];
extern const char sh_mn_addv_rm_rn[];
extern const char sh_mn_macw_rminc_rninc[];
extern const char sh_mn_movb_atrm_rn[];
extern const char sh_mn_movw_atrm_rn[];
extern const char sh_str_regs_r12_r14[];
extern const char sh_mn_movl_atrm_rn[];
extern const char sh_mn_mov_rm_rn[];
extern const char sh_mn_movb_rminc_rn[];
extern const char sh_mn_movw_rminc_rn[];
extern const char sh_mn_movl_rminc_rn[];
extern const char sh_mn_not_rm_rn[];
extern const char sh_mn_swapb_rm_rn[];
extern const char sh_mn_swapw_rm_rn[];
extern const char sh_mn_negc_rm_rn[];
extern const char sh_mn_neg_rm_rn[];
extern const char sh_str_regs_sp_pc[];
extern const char sh_mn_extub_rm_rn[];
extern const char sh_mn_extuw_rm_rn[];
extern const char sh_mn_extsb_rm_rn[];
extern const char sh_mn_extsw_rm_rn[];
extern const char sh_mn_movb_disprm_r0[];
extern const char sh_mn_movw_disprm_r0[];
extern const char sh_mn_movb_r0_disprn[];
extern const char sh_mn_movw_r0_disprn[];
extern const char sh_mn_bt_label[];
extern const char sh_mn_bf_label[];
extern const char sh_str_regs_pr_gbr[];
extern const char sh_mn_bt_s_label[];
extern const char sh_mn_bf_s_label[];
extern const char sh_mn_movb_r0_dispgbr[];
extern const char sh_mn_movw_r0_dispgbr[];
extern const char sh_mn_movl_r0_dispgbr[];
extern const char sh_mn_movb_dispgbr_r0[];
extern const char sh_mn_movw_dispgbr_r0[];
extern const char sh_mn_movl_dispgbr_r0[];
extern const char sh_mn_mova_disppc_r0[];
extern const char sh_mn_cmp_eq_imm_r0[];
extern const char sh_str_dump_header[];
extern const char sh_mn_trapa_imm[];
extern const char sh_mn_tst_imm_r0[];
extern const char sh_mn_and_imm_r0[];
extern const char sh_mn_xor_imm_r0[];
extern const char sh_mn_or_imm_r0[];
extern const char sh_mn_tstb_imm_r0gbr[];
extern const char sh_mn_andb_imm_r0gbr[];
extern const char sh_mn_xorb_imm_r0gbr[];
extern const char sh_mn_orb_imm_r0gbr[];
extern const char sh_mn_movl_rm_disprn[];
extern const char sh_str_disasm_header[];
extern const char sh_mn_movl_disprm_rn[];
extern const char sh_mn_bra_label[];
extern const char sh_mn_bsr_label[];
extern const char sh_mn_movw_disppc_rn[];
extern const char sh_mn_movl_disppc_rn[];
extern const char sh_mn_add_imm_rn[];
extern const char sh_mn_mov_imm_rn[];
extern const char sh_mn_clrt[];
extern const char sh_mn_nop[];
extern const char sh_mn_rts[];
extern const char sh_mn_sett[];
extern const char sh_str_slot_illegal_inst[];
extern const char sh_mn_div0u[];
extern const char sh_mn_sleep[];
extern const char sh_mn_clrmac[];
extern const char sh_mn_rte[];
extern const char sh_mn_ldsl_rminc_mach[];
extern const char sh_mn_ldcl_rminc_sr[];
extern const char sh_mn_lds_rm_mach[];
extern const char sh_mn_ldc_rm_sr[];
extern const char sh_mn_ldsl_rminc_macl[];
extern const char sh_mn_ldcl_rminc_gbr[];
extern const char sh_str_cpu_addr_error[];
extern const char sh_mn_lds_rm_macl[];
extern const char sh_mn_ldc_rm_gbr[];
extern const char sh_mn_ldsl_rminc_pr[];
extern const char sh_mn_ldcl_rminc_vbr[];
extern const char sh_mn_lds_rm_pr[];
extern const char sh_mn_ldc_rm_vbr[];
extern const char sh_mn_stc_sr_rn[];
extern const char sh_mn_bsrf_rn[];
extern const char sh_mn_sts_mach_rn[];
extern const char sh_mn_stc_gbr_rn[];
extern const char sh_str_dma_addr_error[];
extern const char sh_mn_sts_macl_rn[];
extern const char sh_mn_stc_vbr_rn[];
extern const char sh_mn_braf_rn[];
extern const char sh_mn_movt_rn[];
extern const char sh_mn_sts_pr_rn[];
extern const char sh_mn_cmp_pl_rn[];
extern const char sh_mn_cmp_pz_rn[];
extern const char sh_mn_dt_rn[];
extern const char sh_mn_tasb_atrn[];
extern const char sh_mn_rotl_rn[];
extern const char sh_str_unknown_exception[];
extern const char sh_mn_rotr_rn[];
extern const char sh_mn_rotcl_rn[];
extern const char sh_mn_rotcr_rn[];
extern const char sh_mn_shal_rn[];
extern const char sh_mn_shar_rn[];
extern const char sh_mn_shll_rn[];
extern const char sh_mn_shlr_rn[];
extern const char sh_mn_shll2_rn[];
extern const char sh_mn_shlr2_rn[];
extern const char sh_mn_shll8_rn[];
extern const char sh_str_monitor_title[];
extern const char sh_mn_shlr8_rn[];
extern const char sh_mn_shll16_rn[];
extern const char sh_mn_shlr16_rn[];
extern const char sh_mn_jmp_atrn[];
extern const char sh_mn_jsr_atrn[];
extern const char sh_mn_stcl_sr_decrn[];
extern const char sh_mn_stcl_gbr_decrn[];
extern const char sh_mn_stcl_vbr_decrn[];
extern const char sh_mn_stsl_mach_decrn[];
extern const char sh_mn_stsl_macl_decrn[];
extern const char sh_str_regs_r0_r2[];
extern const char sh_mn_stsl_pr_decrn[];
extern const char sh_mn_movb_rm_r0rn[];
extern const char sh_mn_movw_rm_r0rn[];
extern const char sh_mn_movl_rm_r0rn[];
extern const char sh_mn_mull_rm_rn[];
extern const char sh_mn_movb_r0rm_rn[];
extern const char sh_mn_movw_r0rm_rn[];
extern const char sh_mn_movl_r0rm_rn[];
extern const char sh_mn_macl_rminc_rninc[];
extern const char sh_mn_movb_rm_atrn[];
extern const char sh_str_regs_r3_r5[];
extern const char sh_mn_movw_rm_atrn[];
extern const char sh_mn_movl_rm_atrn[];
extern const char sh_mn_movb_rm_decrn[];
extern const char sh_mn_movw_rm_decrn[];
extern const char sh_mn_movl_rm_decrn[];
extern const char sh_mn_div0s_rm_rn[];
extern const char sh_mn_tst_rm_rn[];
extern const char sh_mn_and_rm_rn[];
extern const char sh_mn_xor_rm_rn[];
extern const char sh_mn_or_rm_rn[];
extern const char sh_str_regs_r6_r8[];
extern const char sh_mn_cmp_str_rm_rn[];
extern const char sh_mn_xtrct_rm_rn[];
extern const char sh_mn_muluw_rm_rn[];
extern const char sh_mn_mulsw_rm_rn[];
extern const char sh_mn_cmp_eq_rm_rn[];
extern const char sh_mn_cmp_hs_rm_rn[];
extern const char sh_mn_cmp_ge_rm_rn[];
extern const char sh_mn_div1_rm_rn[];
extern const char sh_mn_dmulul_rm_rn[];
extern const char sh_mn_cmp_hi_rm_rn[];

const s8 msg_free_play[20] = "     FREE PLAY     ";

const s8 msg_blank[20] = "                   ";

const s8 msg_blank18[20] = "                  ";

const s8 msg_continue[20] = "     CONTINUE_     ";

const s8 msg_continue_cnt[20] = "     CONTINUE_\t    ";

const u8 msg_game_over[20] = "     GAME OVER     ";

const u8 msg_insert_2coins[24] = {
    32, 32, 32, 73, 78, 83, 69, 82,
    84, 32, 2, 32, 67, 79, 73, 78,
    83, 32, 32, 32, 0, 0, 0, 0,
};

const u8 msg_insert_coin[20] = "    INSERT COIN    ";

const u8 msg_insert_coins[20] = "   INSERT   COINS  ";

const u8 msg_join_in[20] = "      JOIN IN      ";

const s8 msg_press_2p_start[20] = "   PRESS \002P START  ";

const s8 msg_press_1p_start[20] = "   PRESS \001P START  ";

const s8 msg_please_wait[20] = "    PLEASE WAIT    ";

const u8 msg_insert_more_coin[20] = "INSERT   MORE COIN ";

const u8 msg_insert_more_coins[20] = "INSERT   MORE COINS";

const s8 msg_coins[8] = "COINS:";

const s8 msg_credit[12] = "CREDIT :";

const s8 msg_plural_s[4] = "S";

const s8 msg_credits[12] = "CREDITS:";

const s8 msg_space[4] = " ";

const s8 msg_blank6[8] = "      ";

const s8 msg_coin_frac[8] = "( / )";

const s8 msg_blank25[28] = "                         ";

const s8 msg_insert_1_more[20] = "INSERT 1 MORE COIN";

const s8 msg_press_1or2_start[28] = "PRESS \001 OR \002 START BUTTON";

const s8 msg_insert_2_more[20] = "INSERT 2 MORE COINS";

const s8 msg_press_1p_button[24] = "PRESS \001P START BUTTON";

const s8 msg_press_2p_button[24] = "PRESS \002P START BUTTON";
const s8 str_INSERT_COIN[20] = "     INSERT COIN   ";
const s8 str_INSERT_COINS[20] = "   INSERT \002 COINS  ";
const s8 str_INSERT_COINS_2[20] = "   INSERT \003 COINS  ";
const s8 str_INSERT_COINS_3[20] = "   INSERT \004 COINS  ";
const s8 str_INSERT_COINS_4[20] = "   INSERT \005 COINS  ";
const s8 str_INSERT_COINS_5[20] = "   INSERT \006 COINS  ";
const s8 str_INSERT_COINS_6[20] = "   INSERT \007 COINS  ";
const s8 str_INSERT_COINS_7[20] = "   INSERT \010 COINS  ";
const s8 str_INSERT_COINS_8[20] = "   INSERT \t COINS  ";

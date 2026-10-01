/*
 * ENTRY_TBL.C  game tables
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

/* provisional name: opcode records ahead of the disassembler's tables; nothing reads them */
const u32 monitor_msg_tbl[42] = {
    0x10016, 0xE0000, (u32)sh_str_monitor_entry, 0x10016, 0xE0000, (u32)sh_str_illegal_inst, 0x10016, 0xE0000,
    (u32)sh_str_slot_illegal_inst, 0x10016, 0xE0000, (u32)sh_str_cpu_addr_error, 0x10016, 0xE0000, (u32)sh_str_dma_addr_error, 0x10016,
    0xE0000, (u32)sh_str_unknown_exception, 0xC0000, 0xE0000, (u32)sh_str_monitor_title, 2, 0xE0000, (u32)sh_str_regs_r0_r2,
    3, 0xE0000, (u32)sh_str_regs_r3_r5, 4, 0xE0000, (u32)sh_str_regs_r6_r8, 5, 0xE0000,
    (u32)sh_str_regs_r9_r11, 6, 0xE0000, (u32)sh_str_regs_r12_r14, 7, 0xE0000, (u32)sh_str_regs_sp_pc, 8,
    0xE0000, (u32)sh_str_regs_pr_gbr,
};

const TM_STRING dbg_dump_title[1] = {
    { 0, 10, 14, (void*)sh_str_dump_header },
};

const TM_STRING dbg_disasm_title[1] = {
    { 0, 10, 14, (void*)sh_str_disasm_header },
};

const MoveName sh_op_none_tbl[9] = {
    { 8, (void*)sh_mn_clrt },
    { 9, (void*)sh_mn_nop },
    { 0xB, (void*)sh_mn_rts },
    { 0x18, (void*)sh_mn_sett },
    { 0x19, (void*)sh_mn_div0u },
    { 0x1B, (void*)sh_mn_sleep },
    { 0x28, (void*)sh_mn_clrmac },
    { 0x2B, (void*)sh_mn_rte },
    { 0xFFFF, 0 },
};

const MoveName sh_op_ldm_tbl[13] = {
    { 0x4006, (void*)sh_mn_ldsl_rminc_mach },
    { 0x4007, (void*)sh_mn_ldcl_rminc_sr },
    { 0x400A, (void*)sh_mn_lds_rm_mach },
    { 0x400E, (void*)sh_mn_ldc_rm_sr },
    { 0x4016, (void*)sh_mn_ldsl_rminc_macl },
    { 0x4017, (void*)sh_mn_ldcl_rminc_gbr },
    { 0x401A, (void*)sh_mn_lds_rm_macl },
    { 0x401E, (void*)sh_mn_ldc_rm_gbr },
    { 0x4026, (void*)sh_mn_ldsl_rminc_pr },
    { 0x4027, (void*)sh_mn_ldcl_rminc_vbr },
    { 0x402A, (void*)sh_mn_lds_rm_pr },
    { 0x402E, (void*)sh_mn_ldc_rm_vbr },
    { 0xFFFF, 0 },
};

const MoveName sh_op_n_tbl[36] = {
    { 2, (void*)sh_mn_stc_sr_rn },
    { 3, (void*)sh_mn_bsrf_rn },
    { 0xA, (void*)sh_mn_sts_mach_rn },
    { 0x12, (void*)sh_mn_stc_gbr_rn },
    { 0x1A, (void*)sh_mn_sts_macl_rn },
    { 0x22, (void*)sh_mn_stc_vbr_rn },
    { 0x23, (void*)sh_mn_braf_rn },
    { 0x29, (void*)sh_mn_movt_rn },
    { 0x2A, (void*)sh_mn_sts_pr_rn },
    { 0x4015, (void*)sh_mn_cmp_pl_rn },
    { 0x4011, (void*)sh_mn_cmp_pz_rn },
    { 0x4010, (void*)sh_mn_dt_rn },
    { 0x401B, (void*)sh_mn_tasb_atrn },
    { 0x4004, (void*)sh_mn_rotl_rn },
    { 0x4005, (void*)sh_mn_rotr_rn },
    { 0x4024, (void*)sh_mn_rotcl_rn },
    { 0x4025, (void*)sh_mn_rotcr_rn },
    { 0x4020, (void*)sh_mn_shal_rn },
    { 0x4021, (void*)sh_mn_shar_rn },
    { 0x4000, (void*)sh_mn_shll_rn },
    { 0x4001, (void*)sh_mn_shlr_rn },
    { 0x4008, (void*)sh_mn_shll2_rn },
    { 0x4009, (void*)sh_mn_shlr2_rn },
    { 0x4018, (void*)sh_mn_shll8_rn },
    { 0x4019, (void*)sh_mn_shlr8_rn },
    { 0x4028, (void*)sh_mn_shll16_rn },
    { 0x4029, (void*)sh_mn_shlr16_rn },
    { 0x402B, (void*)sh_mn_jmp_atrn },
    { 0x400B, (void*)sh_mn_jsr_atrn },
    { 0x4003, (void*)sh_mn_stcl_sr_decrn },
    { 0x4013, (void*)sh_mn_stcl_gbr_decrn },
    { 0x4023, (void*)sh_mn_stcl_vbr_decrn },
    { 0x4002, (void*)sh_mn_stsl_mach_decrn },
    { 0x4012, (void*)sh_mn_stsl_macl_decrn },
    { 0x4022, (void*)sh_mn_stsl_pr_decrn },
    { 0xFFFF, 0 },
};

const MoveName sh_op_nm_tbl[54] = {
    { 4, (void*)sh_mn_movb_rm_r0rn },
    { 5, (void*)sh_mn_movw_rm_r0rn },
    { 6, (void*)sh_mn_movl_rm_r0rn },
    { 7, (void*)sh_mn_mull_rm_rn },
    { 0xC, (void*)sh_mn_movb_r0rm_rn },
    { 0xD, (void*)sh_mn_movw_r0rm_rn },
    { 0xE, (void*)sh_mn_movl_r0rm_rn },
    { 0xF, (void*)sh_mn_macl_rminc_rninc },
    { 0x2000, (void*)sh_mn_movb_rm_atrn },
    { 0x2001, (void*)sh_mn_movw_rm_atrn },
    { 0x2002, (void*)sh_mn_movl_rm_atrn },
    { 0x2004, (void*)sh_mn_movb_rm_decrn },
    { 0x2005, (void*)sh_mn_movw_rm_decrn },
    { 0x2006, (void*)sh_mn_movl_rm_decrn },
    { 0x2007, (void*)sh_mn_div0s_rm_rn },
    { 0x2008, (void*)sh_mn_tst_rm_rn },
    { 0x2009, (void*)sh_mn_and_rm_rn },
    { 0x200A, (void*)sh_mn_xor_rm_rn },
    { 0x200B, (void*)sh_mn_or_rm_rn },
    { 0x200C, (void*)sh_mn_cmp_str_rm_rn },
    { 0x200D, (void*)sh_mn_xtrct_rm_rn },
    { 0x200E, (void*)sh_mn_muluw_rm_rn },
    { 0x200F, (void*)sh_mn_mulsw_rm_rn },
    { 0x3000, (void*)sh_mn_cmp_eq_rm_rn },
    { 0x3002, (void*)sh_mn_cmp_hs_rm_rn },
    { 0x3003, (void*)sh_mn_cmp_ge_rm_rn },
    { 0x3004, (void*)sh_mn_div1_rm_rn },
    { 0x3005, (void*)sh_mn_dmulul_rm_rn },
    { 0x3006, (void*)sh_mn_cmp_hi_rm_rn },
    { 0x3008, (void*)sh_mn_sub_rm_rn },
    { 0x300A, (void*)sh_mn_subc_rm_rn },
    { 0x300B, (void*)sh_mn_subv_rm_rn },
    { 0x300C, (void*)sh_mn_add_rm_rn },
    { 0x300D, (void*)sh_mn_dmulsl_rm_rn },
    { 0x300E, (void*)sh_mn_addc_rm_rn },
    { 0x300F, (void*)sh_mn_addv_rm_rn },
    { 0x400F, (void*)sh_mn_macw_rminc_rninc },
    { 0x6000, (void*)sh_mn_movb_atrm_rn },
    { 0x6001, (void*)sh_mn_movw_atrm_rn },
    { 0x6002, (void*)sh_mn_movl_atrm_rn },
    { 0x6003, (void*)sh_mn_mov_rm_rn },
    { 0x6004, (void*)sh_mn_movb_rminc_rn },
    { 0x6005, (void*)sh_mn_movw_rminc_rn },
    { 0x6006, (void*)sh_mn_movl_rminc_rn },
    { 0x6007, (void*)sh_mn_not_rm_rn },
    { 0x6008, (void*)sh_mn_swapb_rm_rn },
    { 0x6009, (void*)sh_mn_swapw_rm_rn },
    { 0x600A, (void*)sh_mn_negc_rm_rn },
    { 0x600B, (void*)sh_mn_neg_rm_rn },
    { 0x600C, (void*)sh_mn_extub_rm_rn },
    { 0x600D, (void*)sh_mn_extuw_rm_rn },
    { 0x600E, (void*)sh_mn_extsb_rm_rn },
    { 0x600F, (void*)sh_mn_extsw_rm_rn },
    { 0xFFFF, 0 },
};

const MoveName sh_op_disp_m_tbl[3] = {
    { 0x8400, (void*)sh_mn_movb_disprm_r0 },
    { 0x8500, (void*)sh_mn_movw_disprm_r0 },
    { 0xFFFF, 0 },
};

const MoveName sh_op_disp_n_tbl[3] = {
    { 0x8000, (void*)sh_mn_movb_r0_disprn },
    { 0x8100, (void*)sh_mn_movw_r0_disprn },
    { 0xFFFF, 0 },
};

const MoveName sh_op_d8_tbl[12] = {
    { 0x8900, (void*)sh_mn_bt_label },
    { 0x8B00, (void*)sh_mn_bf_label },
    { 0x8D00, (void*)sh_mn_bt_s_label },
    { 0x8F00, (void*)sh_mn_bf_s_label },
    { 0xC000, (void*)sh_mn_movb_r0_dispgbr },
    { 0xC100, (void*)sh_mn_movw_r0_dispgbr },
    { 0xC200, (void*)sh_mn_movl_r0_dispgbr },
    { 0xC400, (void*)sh_mn_movb_dispgbr_r0 },
    { 0xC500, (void*)sh_mn_movw_dispgbr_r0 },
    { 0xC600, (void*)sh_mn_movl_dispgbr_r0 },
    { 0xC700, (void*)sh_mn_mova_disppc_r0 },
    { 0xFFFF, 0 },
};

const MoveName sh_op_imm_tbl[11] = {
    { 0x8800, (void*)sh_mn_cmp_eq_imm_r0 },
    { 0xC300, (void*)sh_mn_trapa_imm },
    { 0xC800, (void*)sh_mn_tst_imm_r0 },
    { 0xC900, (void*)sh_mn_and_imm_r0 },
    { 0xCA00, (void*)sh_mn_xor_imm_r0 },
    { 0xCB00, (void*)sh_mn_or_imm_r0 },
    { 0xCC00, (void*)sh_mn_tstb_imm_r0gbr },
    { 0xCD00, (void*)sh_mn_andb_imm_r0gbr },
    { 0xCE00, (void*)sh_mn_xorb_imm_r0gbr },
    { 0xCF00, (void*)sh_mn_orb_imm_r0gbr },
    { 0xFFFF, 0 },
};

const MoveName sh_op_disp4_tbl[3] = {
    { 0x1000, (void*)sh_mn_movl_rm_disprn },
    { 0x5000, (void*)sh_mn_movl_disprm_rn },
    { 0xFFFF, 0 },
};

const MoveName sh_op_d12_tbl[3] = {
    { 0xA000, (void*)sh_mn_bra_label },
    { 0xB000, (void*)sh_mn_bsr_label },
    { 0xFFFF, 0 },
};

const MoveName sh_op_pcrel_tbl[3] = {
    { 0x9000, (void*)sh_mn_movw_disppc_rn },
    { 0xD000, (void*)sh_mn_movl_disppc_rn },
    { 0xFFFF, 0 },
};

const MoveName sh_op_imm_n_tbl[3] = {
    { 0x7000, (void*)sh_mn_add_imm_rn },
    { 0xE000, (void*)sh_mn_mov_imm_rn },
    { 0xFFFF, 0 },
};

/* provisional name */
const char sh_str_break[8] = "Break:";

const char sh_str_rm[4] = "Rm";

const char sh_str_rn[4] = "Rn";

const char sh_str_undef[4] = "???";

/* provisional name */
const char sh_str_monitor_entry[16] = "Monitor Entry";

/* provisional name */
const char sh_str_illegal_inst[28] = "Common Illigal Instruction";

/* provisional name */
const char sh_str_slot_illegal_inst[28] = "Slot Illigal Instruction";

/* provisional name */
const char sh_str_cpu_addr_error[20] = "CPU Address Error";

/* provisional name */
const char sh_str_dma_addr_error[20] = "DMA Address Error";

/* provisional name */
const char sh_str_unknown_exception[20] = "Unknown Exception";

/* provisional name */
const char sh_str_monitor_title[16] = "M O N I T O R\n";

/* provisional name */
const char sh_str_regs_r0_r2[48] = "R0  = 00000000 R1  = 00000000 R2  = 00000000\n";

/* provisional name */
const char sh_str_regs_r3_r5[48] = "R3  = 00000000 R4  = 00000000 R5  = 00000000\n";

/* provisional name */
const char sh_str_regs_r6_r8[48] = "R6  = 00000000 R7  = 00000000 R8  = 00000000\n";

/* provisional name */
const char sh_str_regs_r9_r11[48] = "R9  = 00000000 R10 = 00000000 R11 = 00000000\n";

/* provisional name */
const char sh_str_regs_r12_r14[48] = "R12 = 00000000 R13 = 00000000 R14 = 00000000\n";

/* provisional name */
const char sh_str_regs_sp_pc[32] = "SP  = 00000000 PC  = 00000000\n";

/* provisional name */
const char sh_str_regs_pr_gbr[32] = "PR  = 00000000 GBR = 00000000";

/* provisional name */
const char sh_str_dump_header[48] = "Address   +0   +2   +4   +6   +8   +A   +C   +E";

/* provisional name */
const char sh_str_disasm_header[48] = "Address  Code Nemonic                          ";

/* provisional name */
const char sh_mn_clrt[28] = "CLRT                    ";

/* provisional name */
const char sh_mn_nop[28] = "NOP                     ";

/* provisional name */
const char sh_mn_rts[28] = "RTS                     ";

/* provisional name */
const char sh_mn_sett[28] = "SETT                    ";

/* provisional name */
const char sh_mn_div0u[28] = "DIV0U                   ";

/* provisional name */
const char sh_mn_sleep[28] = "SLEEP                   ";

/* provisional name */
const char sh_mn_clrmac[28] = "CLRMAC                  ";

/* provisional name */
const char sh_mn_rte[28] = "RTE                     ";

/* provisional name */
const char sh_mn_ldsl_rminc_mach[28] = "LDS.L   @Rm+,MACH       ";

/* provisional name */
const char sh_mn_ldcl_rminc_sr[28] = "LDC.L   @Rm+,SR         ";

/* provisional name */
const char sh_mn_lds_rm_mach[28] = "LDS     Rm,MACH         ";

/* provisional name */
const char sh_mn_ldc_rm_sr[28] = "LDC     Rm,SR           ";

/* provisional name */
const char sh_mn_ldsl_rminc_macl[28] = "LDS.L   @Rm+,MACL       ";

/* provisional name */
const char sh_mn_ldcl_rminc_gbr[28] = "LDC.L   @Rm+,GBR        ";

/* provisional name */
const char sh_mn_lds_rm_macl[28] = "LDS     Rm,MACL         ";

/* provisional name */
const char sh_mn_ldc_rm_gbr[28] = "LDC     Rm,GBR          ";

/* provisional name */
const char sh_mn_ldsl_rminc_pr[28] = "LDS.L   @Rm+,PR         ";

/* provisional name */
const char sh_mn_ldcl_rminc_vbr[28] = "LDC.L   @Rm+,VBR        ";

/* provisional name */
const char sh_mn_lds_rm_pr[28] = "LDS     Rm,PR           ";

/* provisional name */
const char sh_mn_ldc_rm_vbr[28] = "LDC     Rm,VBR          ";

/* provisional name */
const char sh_mn_stc_sr_rn[28] = "STC     SR,Rn           ";

/* provisional name */
const char sh_mn_bsrf_rn[28] = "BSRF    Rn              ";

/* provisional name */
const char sh_mn_sts_mach_rn[28] = "STS     MACH,Rn         ";

/* provisional name */
const char sh_mn_stc_gbr_rn[28] = "STC     GBR,Rn          ";

/* provisional name */
const char sh_mn_sts_macl_rn[28] = "STS     MACL,Rn         ";

/* provisional name */
const char sh_mn_stc_vbr_rn[28] = "STC     VBR,Rn          ";

/* provisional name */
const char sh_mn_braf_rn[28] = "BRAF    Rn              ";

/* provisional name */
const char sh_mn_movt_rn[28] = "MOVT    Rn              ";

/* provisional name */
const char sh_mn_sts_pr_rn[28] = "STS     PR,Rn           ";

/* provisional name */
const char sh_mn_cmp_pl_rn[28] = "CMP/PL  Rn              ";

/* provisional name */
const char sh_mn_cmp_pz_rn[28] = "CMP/PZ  Rn              ";

/* provisional name */
const char sh_mn_dt_rn[28] = "DT      Rn              ";

/* provisional name */
const char sh_mn_tasb_atrn[28] = "TAS.B   @Rn             ";

/* provisional name */
const char sh_mn_rotl_rn[28] = "ROTL    Rn              ";

/* provisional name */
const char sh_mn_rotr_rn[28] = "ROTR    Rn              ";

/* provisional name */
const char sh_mn_rotcl_rn[28] = "ROTCL   Rn              ";

/* provisional name */
const char sh_mn_rotcr_rn[28] = "ROTCR   Rn              ";

/* provisional name */
const char sh_mn_shal_rn[28] = "SHAL    Rn              ";

/* provisional name */
const char sh_mn_shar_rn[28] = "SHAR    Rn              ";

/* provisional name */
const char sh_mn_shll_rn[28] = "SHLL    Rn              ";

/* provisional name */
const char sh_mn_shlr_rn[28] = "SHLR    Rn              ";

/* provisional name */
const char sh_mn_shll2_rn[28] = "SHLL2   Rn              ";

/* provisional name */
const char sh_mn_shlr2_rn[28] = "SHLR2   Rn              ";

/* provisional name */
const char sh_mn_shll8_rn[28] = "SHLL8   Rn              ";

/* provisional name */
const char sh_mn_shlr8_rn[28] = "SHLR8   Rn              ";

/* provisional name */
const char sh_mn_shll16_rn[28] = "SHLL16  Rn              ";

/* provisional name */
const char sh_mn_shlr16_rn[28] = "SHLR16  Rn              ";

/* provisional name */
const char sh_mn_jmp_atrn[28] = "JMP     @Rn             ";

/* provisional name */
const char sh_mn_jsr_atrn[28] = "JSR     @Rn             ";

/* provisional name */
const char sh_mn_stcl_sr_decrn[28] = "STC.L   SR,@-Rn         ";

/* provisional name */
const char sh_mn_stcl_gbr_decrn[28] = "STC.L   GBR,@-Rn        ";

/* provisional name */
const char sh_mn_stcl_vbr_decrn[28] = "STC.L   VBR,@-Rn        ";

/* provisional name */
const char sh_mn_stsl_mach_decrn[28] = "STS.L   MACH,@-Rn       ";

/* provisional name */
const char sh_mn_stsl_macl_decrn[28] = "STS.L   MACL,@-Rn       ";

/* provisional name */
const char sh_mn_stsl_pr_decrn[28] = "STS.L   PR,@-Rn         ";

/* provisional name */
const char sh_mn_movb_rm_r0rn[28] = "MOV.B   Rm,@(R0,Rn)     ";

/* provisional name */
const char sh_mn_movw_rm_r0rn[28] = "MOV.W   Rm,@(R0,Rn)     ";

/* provisional name */
const char sh_mn_movl_rm_r0rn[28] = "MOV.L   Rm,@(R0,Rn)     ";

/* provisional name */
const char sh_mn_mull_rm_rn[28] = "MUL.L   Rm,Rn           ";

/* provisional name */
const char sh_mn_movb_r0rm_rn[28] = "MOV.B   @(R0,Rm),Rn     ";

/* provisional name */
const char sh_mn_movw_r0rm_rn[28] = "MOV.W   @(R0,Rm),Rn     ";

/* provisional name */
const char sh_mn_movl_r0rm_rn[28] = "MOV.L   @(R0,Rm),Rn     ";

/* provisional name */
const char sh_mn_macl_rminc_rninc[28] = "MAC.L   @Rm+,@Rn+       ";

/* provisional name */
const char sh_mn_movb_rm_atrn[28] = "MOV.B   Rm,@Rn          ";

/* provisional name */
const char sh_mn_movw_rm_atrn[28] = "MOV.W   Rm,@Rn          ";

/* provisional name */
const char sh_mn_movl_rm_atrn[28] = "MOV.L   Rm,@Rn          ";

/* provisional name */
const char sh_mn_movb_rm_decrn[28] = "MOV.B   Rm,@-Rn         ";

/* provisional name */
const char sh_mn_movw_rm_decrn[28] = "MOV.W   Rm,@-Rn         ";

/* provisional name */
const char sh_mn_movl_rm_decrn[28] = "MOV.L   Rm,@-Rn         ";

/* provisional name */
const char sh_mn_div0s_rm_rn[28] = "DIV0S   Rm,Rn           ";

/* provisional name */
const char sh_mn_tst_rm_rn[28] = "TST     Rm,Rn           ";

/* provisional name */
const char sh_mn_and_rm_rn[28] = "AND     Rm,Rn           ";

/* provisional name */
const char sh_mn_xor_rm_rn[28] = "XOR     Rm,Rn           ";

/* provisional name */
const char sh_mn_or_rm_rn[28] = "OR      Rm,Rn           ";

/* provisional name */
const char sh_mn_cmp_str_rm_rn[28] = "CMP/STR Rm,Rn           ";

/* provisional name */
const char sh_mn_xtrct_rm_rn[28] = "XTRCT   Rm,Rn           ";

/* provisional name */
const char sh_mn_muluw_rm_rn[28] = "MULU.W  Rm,Rn           ";

/* provisional name */
const char sh_mn_mulsw_rm_rn[28] = "MULS.W  Rm,Rn           ";

/* provisional name */
const char sh_mn_cmp_eq_rm_rn[28] = "CMP/EQ  Rm,Rn           ";

/* provisional name */
const char sh_mn_cmp_hs_rm_rn[28] = "CMP/HS  Rm,Rn           ";

/* provisional name */
const char sh_mn_cmp_ge_rm_rn[28] = "CMP/GE  Rm,Rn           ";

/* provisional name */
const char sh_mn_div1_rm_rn[28] = "DIV1    Rm,Rn           ";

/* provisional name */
const char sh_mn_dmulul_rm_rn[28] = "DMULU.L Rm,Rn           ";

/* provisional name */
const char sh_mn_cmp_hi_rm_rn[28] = "CMP/HI  Rm,Rn           ";

/* provisional name */
const char sh_mn_sub_rm_rn[28] = "SUB     Rm,Rn           ";

/* provisional name */
const char sh_mn_subc_rm_rn[28] = "SUBC    Rm,Rn           ";

/* provisional name */
const char sh_mn_subv_rm_rn[28] = "SUBV    Rm,Rn           ";

/* provisional name */
const char sh_mn_add_rm_rn[28] = "ADD     Rm,Rn           ";

/* provisional name */
const char sh_mn_dmulsl_rm_rn[28] = "DMULS.L Rm,Rn           ";

/* provisional name */
const char sh_mn_addc_rm_rn[28] = "ADDC    Rm,Rn           ";

/* provisional name */
const char sh_mn_addv_rm_rn[28] = "ADDV    Rm,Rn           ";

/* provisional name */
const char sh_mn_macw_rminc_rninc[28] = "MAC.W   @Rm+,@Rn+       ";

/* provisional name */
const char sh_mn_movb_atrm_rn[28] = "MOV.B   @Rm,Rn          ";

/* provisional name */
const char sh_mn_movw_atrm_rn[28] = "MOV.W   @Rm,Rn          ";

/* provisional name */
const char sh_mn_movl_atrm_rn[28] = "MOV.L   @Rm,Rn          ";

/* provisional name */
const char sh_mn_mov_rm_rn[28] = "MOV     Rm,Rn           ";

/* provisional name */
const char sh_mn_movb_rminc_rn[28] = "MOV.B   @Rm+,Rn         ";

/* provisional name */
const char sh_mn_movw_rminc_rn[28] = "MOV.W   @Rm+,Rn         ";

/* provisional name */
const char sh_mn_movl_rminc_rn[28] = "MOV.L   @Rm+,Rn         ";

/* provisional name */
const char sh_mn_not_rm_rn[28] = "NOT     Rm,Rn           ";

/* provisional name */
const char sh_mn_swapb_rm_rn[28] = "SWAP.B  Rm,Rn           ";

/* provisional name */
const char sh_mn_swapw_rm_rn[28] = "SWAP.W  Rm,Rn           ";

/* provisional name */
const char sh_mn_negc_rm_rn[28] = "NEGC    Rm,Rn           ";

/* provisional name */
const char sh_mn_neg_rm_rn[28] = "NEG     Rm,Rn           ";

/* provisional name */
const char sh_mn_extub_rm_rn[28] = "EXTU.B  Rm,Rn           ";

/* provisional name */
const char sh_mn_extuw_rm_rn[28] = "EXTU.W  Rm,Rn           ";

/* provisional name */
const char sh_mn_extsb_rm_rn[28] = "EXTS.B  Rm,Rn           ";

/* provisional name */
const char sh_mn_extsw_rm_rn[28] = "EXTS.W  Rm,Rn           ";

/* provisional name */
const char sh_mn_movb_disprm_r0[28] = "MOV.B   @(disp,Rm),R0   ";

/* provisional name */
const char sh_mn_movw_disprm_r0[28] = "MOV.W   @(disp,Rm),R0   ";

/* provisional name */
const char sh_mn_movb_r0_disprn[28] = "MOV.B   R0,@(disp,Rn)   ";

/* provisional name */
const char sh_mn_movw_r0_disprn[28] = "MOV.W   R0,@(disp,Rn)   ";

/* provisional name */
const char sh_mn_bt_label[28] = "BT      label           ";

/* provisional name */
const char sh_mn_bf_label[28] = "BF      label           ";

/* provisional name */
const char sh_mn_bt_s_label[28] = "BT/S    label           ";

/* provisional name */
const char sh_mn_bf_s_label[28] = "BF/S    label           ";

/* provisional name */
const char sh_mn_movb_r0_dispgbr[28] = "MOV.B   R0,@(disp,GBR)  ";

/* provisional name */
const char sh_mn_movw_r0_dispgbr[28] = "MOV.W   R0,@(disp,GBR)  ";

/* provisional name */
const char sh_mn_movl_r0_dispgbr[28] = "MOV.L   R0,@(disp,GBR)  ";

/* provisional name */
const char sh_mn_movb_dispgbr_r0[28] = "MOV.B   @(disp,GBR),R0  ";

/* provisional name */
const char sh_mn_movw_dispgbr_r0[28] = "MOV.W   @(disp,GBR),R0  ";

/* provisional name */
const char sh_mn_movl_dispgbr_r0[28] = "MOV.L   @(disp,GBR),R0  ";

/* provisional name */
const char sh_mn_mova_disppc_r0[28] = "MOVA    @(disp,PC),R0   ";

/* provisional name */
const char sh_mn_cmp_eq_imm_r0[28] = "CMP/EQ  #imm,R0         ";

/* provisional name */
const char sh_mn_trapa_imm[28] = "TRAPA   #imm            ";

/* provisional name */
const char sh_mn_tst_imm_r0[28] = "TST     #imm,R0         ";

/* provisional name */
const char sh_mn_and_imm_r0[28] = "AND     #imm,R0         ";

/* provisional name */
const char sh_mn_xor_imm_r0[28] = "XOR     #imm,R0         ";

/* provisional name */
const char sh_mn_or_imm_r0[28] = "OR      #imm,R0         ";

/* provisional name */
const char sh_mn_tstb_imm_r0gbr[28] = "TST.B   #imm,@(R0,GBR)  ";

/* provisional name */
const char sh_mn_andb_imm_r0gbr[28] = "AND.B   #imm,@(R0,GBR)  ";

/* provisional name */
const char sh_mn_xorb_imm_r0gbr[28] = "XOR.B   #imm,@(R0,GBR)  ";

/* provisional name */
const char sh_mn_orb_imm_r0gbr[28] = "OR.B    #imm,@(R0,GBR)  ";

/* provisional name */
const char sh_mn_movl_rm_disprn[28] = "MOV.L   Rm,@(disp,Rn)   ";

/* provisional name */
const char sh_mn_movl_disprm_rn[28] = "MOV.L   @(disp,Rm),Rn   ";

/* provisional name */
const char sh_mn_bra_label[28] = "BRA     label           ";

/* provisional name */
const char sh_mn_bsr_label[28] = "BSR     label           ";

/* provisional name */
const char sh_mn_movw_disppc_rn[28] = "MOV.W   @(disp,PC),Rn   ";

/* provisional name */
const char sh_mn_movl_disppc_rn[28] = "MOV.L   @(disp,PC),Rn   ";

/* provisional name */
const char sh_mn_add_imm_rn[28] = "ADD     #imm,Rn         ";

/* provisional name */
const char sh_mn_mov_imm_rn[28] = "MOV     #imm,Rn         ";
const char str_R0[4] = "R0";
const char str_R1[4] = "R1";
const char str_R2[4] = "R2";
const char str_R3[4] = "R3";
const char str_R4[4] = "R4";
const char str_R5[4] = "R5";
const char str_R6[4] = "R6";
const char str_R7[4] = "R7";
const char str_R8[4] = "R8";
const char str_R9[4] = "R9";
const char str_R10[4] = "R10";
const char str_R11[4] = "R11";
const char str_R12[4] = "R12";
const char str_R13[4] = "R13";
const char str_R14[4] = "R14";
const char str_SP[4] = "SP";

/* Initial values of Main_Jmp_Tbl (entry_main) in Entry.c. */
const u32 Main_Jmp_Tbl_init[11] = {
    (u32)Entry_00,
    (u32)Entry_01,
    (u32)Entry_02,
    (u32)Entry_03,
    (u32)Entry_04,
    (u32)Entry_03,
    (u32)Entry_06,
    (u32)Entry_07,
    (u32)Entry_08,
    (u32)Entry_03,
    (u32)Entry_10,
};

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

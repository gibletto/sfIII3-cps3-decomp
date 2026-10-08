/*
 * WORK_B.C  work RAM cleared at boot
 *
 * 02007EEC-02079C97, right after the initialised variables of work.c: reset_entry clears it (B_BGN,
 * B_END in sections.src). Section B, placed after section R by the linker. A <name>_tail table holds the
 * bytes between <name> and the next named variable: unnamed variables, or more of <name> reached
 * through an index past its end.
 */

#include "types.h"
#include "structs.h"
#include "aboutspr.h"
#include "ACTIVE00.h"
#include "active01.h"
#include "active02.h"
#include "active03.h"
#include "active04.h"
#include "active05.h"
#include "active06.h"
#include "active07.h"
#include "active08.h"
#include "active09.h"
#include "active10.h"
#include "active11.h"
#include "active12.h"
#include "active13.h"
#include "active14.h"
#include "active15.h"
#include "active16.h"
#include "active17.h"
#include "active18.h"
#include "active19.h"
#include "appear.h"
#include "BBBSCOM.h"
#include "BBBSCOM2.h"
#include "bg000.h"
#include "bg0001.h"
#include "bg040.h"
#include "BG050.h"
#include "bg090.h"
#include "BG100.h"
#include "bg120.h"
#include "bg130.h"
#include "bg140.h"
#include "bg150.h"
#include "bg160.h"
#include "bg190.h"
#include "bonus_bg.h"
#include "bns_bg2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "CALDIR.h"
#include "cgdata.h"
#include "CHARID.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "charscr.h"
#include "cmb_cont.h"
#include "cmb_win.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "coin_cont.h"
#include "Com_Pl.h"
#include "Com_Sub.h"
#include "cram_bank.h"
#include "demo00.h"
#include "demo01.h"
#include "demo02_code.h"
#include "eeprom.h"
#include "EFF00.h"
#include "EFF02.h"
#include "EFF03.h"
#include "EFF04.h"
#include "eff05.h"
#include "eff06.h"
#include "EFF07.h"
#include "eff08.h"
#include "EFF09.h"
#include "EFF10.h"
#include "EFF11.h"
#include "eff12.h"
#include "EFF13.h"
#include "EFF13_KOTP.h"
#include "eff14.h"
#include "EFF15.h"
#include "EFF16.h"
#include "EFF18.h"
#include "EFF19.h"
#include "eff20.h"
#include "EFF21.h"
#include "EFF22.h"
#include "EFF23.h"
#include "EFF24.h"
#include "EFF25.h"
#include "EFF26.h"
#include "EFF27.h"
#include "eff28.h"
#include "eff29.h"
#include "EFF30.h"
#include "EFF31.h"
#include "EFF32.h"
#include "EFF33.h"
#include "EFF34.h"
#include "eff35.h"
#include "eff36.h"
#include "EFF37.h"
#include "EFF38.h"
#include "Eff39.h"
#include "EFF41.h"
#include "EFF42.h"
#include "EFF44.h"
#include "EFF45.h"
#include "EFF46.h"
#include "EFF47.h"
#include "EFF48.h"
#include "EFF49.h"
#include "Eff50.h"
#include "Eff51.h"
#include "Eff52.h"
#include "EFF53.h"
#include "EFF54.h"
#include "eff56.h"
#include "eff57.h"
#include "eff58.h"
#include "Eff59.h"
#include "EFF61.h"
#include "EFF62.h"
#include "EFF63.h"
#include "eff64.h"
#include "eff65.h"
#include "eff66.h"
#include "EFF68.h"
#include "EFF69.h"
#include "EFF70.h"
#include "EFF71.h"
#include "EFF72.h"
#include "eff73.h"
#include "EFF74.h"
#include "EFF75_ORDER.h"
#include "Eff76.h"
#include "EFF77.h"
#include "EFF78.h"
#include "Eff79.h"
#include "Eff80.h"
#include "Eff81.h"
#include "EFF82.h"
#include "EFF83.h"
#include "EFF84.h"
#include "EFF85.h"
#include "EFF86.h"
#include "eff87.h"
#include "eff88.h"
#include "eff89.h"
#include "eff90.h"
#include "eff91.h"
#include "eff92_code.h"
#include "eff93.h"
#include "eff94.h"
#include "Eff95.h"
#include "EFF96.h"
#include "eff97.h"
#include "EFF98.h"
#include "EFF99.h"
#include "effa0.h"
#include "EFFA1.h"
#include "EffA2.h"
#include "EFFA2_MAIN.h"
#include "EFFA3.h"
#include "effa5.h"
#include "effa5_input.h"
#include "EFFA6.h"
#include "EFFA7.h"
#include "effa8.h"
#include "effa9.h"
#include "EFFB0.h"
#include "EFFB1.h"
#include "EFFB1_INIT.h"
#include "effb2.h"
#include "effb3.h"
#include "effb4.h"
#include "EFFB5.h"
#include "EFFB6.h"
#include "EFFB8.h"
#include "effb9.h"
#include "EFFC0.h"
#include "EFFC1.h"
#include "EFFC2.h"
#include "EFFC3.h"
#include "EFFC4.h"
#include "EFFC5.h"
#include "EFFC6.h"
#include "EFFC7.h"
#include "EFFC8.h"
#include "EFFC9.h"
#include "EFFD0.h"
#include "EFFD1.h"
#include "effd2.h"
#include "effd3.h"
#include "EFFD4.h"
#include "EFFD5.h"
#include "effd6_code.h"
#include "effd7.h"
#include "EffD8.h"
#include "EFFD9.h"
#include "EffE0.h"
#include "EFFE1.h"
#include "EFFE2.h"
#include "effe3.h"
#include "EFFE5.h"
#include "effe6.h"
#include "EFFE7.h"
#include "EFFE8.h"
#include "effe9.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "effect_L9_move.h"
#include "efff0.h"
#include "EFFF1.h"
#include "EFFF2_code.h"
#include "EFFF4.h"
#include "efff5.h"
#include "efff6.h"
#include "efff7.h"
#include "efff8_code.h"
#include "efff9.h"
#include "EffG0.h"
#include "EFFG3.h"
#include "EFFG4.h"
#include "EFFG5.h"
#include "EFFG6.h"
#include "EFFG7.h"
#include "effg8.h"
#include "EFFG9.h"
#include "EFFH0.h"
#include "EFFH1.h"
#include "EFFH2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
#include "EFFH9.h"
#include "EFFI0.h"
#include "EFFI3.h"
#include "EFFI4.h"
#include "EFFI4MV.h"
#include "EFFI5.h"
#include "effi6.h"
#include "EFFI7.h"
#include "EFFI8.h"
#include "EFFI9.h"
#include "EFFJ0.h"
#include "effj1.h"
#include "effj2_code.h"
#include "effj4.h"
#include "effj5.h"
#include "effj6.h"
#include "EFFJ7.h"
#include "EFFJ8.h"
#include "EFFJ9.h"
#include "EFFK0.h"
#include "EFFK2.h"
#include "EFFK3.h"
#include "EFFK4.h"
#include "EFFK5.h"
#include "EffK6.h"
#include "EFFK7.h"
#include "EFFK8.h"
#include "EFFK9.h"
#include "EFFL0.h"
#include "EFFL1.h"
#include "effL2.h"
#include "effL3.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "effL7.h"
#include "effl8.h"
#include "effM0.h"
#include "EFFM1.h"
#include "EFFM2.h"
#include "EffM3.h"
#include "effM5.h"
#include "effM6.h"
#include "EFFM7.h"
#include "EM_Cand.h"
#include "end_1.h"
#include "end_10.h"
#include "end_11.h"
#include "end_12.h"
#include "end_13.h"
#include "end_14.h"
#include "end_16.h"
#include "end_17.h"
#include "end_18.h"
#include "end_19.h"
#include "end_2.h"
#include "end_20.h"
#include "end_3.h"
#include "end_4.h"
#include "end_5.h"
#include "end_6.h"
#include "end_7.h"
#include "end_8.h"
#include "end_9.h"
#include "end_main.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "Entry.h"
#include "entry_2.h"
#include "fifo.h"
#include "active20.h"
#include "FOLLOW01.h"
#include "FOLLOW02.h"
#include "Game.h"
#include "game_config_main.h"
#include "Game_Main.h"
#include "Grade.h"
#include "HITCHECK.h"
#include "HITEFEF.h"
#include "HITEFPL.h"
#include "HITPLEF.h"
#include "HITPLPL.h"
#include "lose_pl.h"
#include "Manage.h"
#include "manage_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "n_input.h"
#include "next_cpu.h"
#include "pass00.h"
#include "PASS01.h"
#include "PASS02.h"
#include "PASS03.h"
#include "PASS04.h"
#include "PASS05.h"
#include "PASS06.h"
#include "PASS07.h"
#include "PASS08.h"
#include "PASS09.h"
#include "pass10.h"
#include "PASS11.h"
#include "PASS12.h"
#include "pass13.h"
#include "pass14.h"
#include "pass15.h"
#include "pass16.h"
#include "pass17.h"
#include "pass18.h"
#include "pass19.h"
#include "Passive20.h"
#include "PLCNT2.h"
#include "PLCNT3.h"
#include "PLCNTDAT.h"
#include "plcntdat_2.h"
#include "PLCNTSET.h"
#include "plcntset_2.h"
#include "PLMAIN.h"
#include "PLMAIN2.h"
#include "PLNORMAL.h"
#include "PLPAT.h"
#include "PLPAT00.h"
#include "PLPAT01.h"
#include "PLPAT02.h"
#include "PLPAT03.h"
#include "PLPAT04.h"
#include "PLPAT05.h"
#include "PLPAT06.h"
#include "PLPAT07.h"
#include "PLPAT08.h"
#include "PLPAT09.h"
#include "plpat10.h"
#include "PLPAT11.h"
#include "PLPAT12.h"
#include "PLPAT13.h"
#include "plpat14.h"
#include "plpat16.h"
#include "plpat17.h"
#include "plpat18.h"
#include "plpat19.h"
#include "plpat20.h"
#include "PLPATUNI.h"
#include "PLPCA.h"
#include "PLPCU.h"
#include "PLPDM.h"
#include "PLPNM.h"
#include "PLS00.h"
#include "PLS01.h"
#include "PLS02.h"
#include "PLS03.h"
#include "PLS03ATT.h"
#include "PLSGAUGE.h"
#include "RANKING.h"
#include "sc_logo.h"
#include "sc_sub.h"
#include "sc_sub_2.h"
#include "sc_trans.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "sel_pl.h"
#include "SHELL00.h"
#include "SHELL01.h"
#include "SHELL03.h"
#include "SHELL04.h"
#include "SHELL05.h"
#include "SHELL07.h"
#include "SHELL11.h"
#include "SHELL12.h"
#include "SHELL13.h"
#include "SHELL14.h"
#include "SLOWF.h"
#include "sound_voice.h"
#include "sound_voice_2.h"
#include "spgauge.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "SYS_sub.h"
#include "SYS_sub2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "ta_sub.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "vbl_hook.h"
#include "VITAL.h"
#include "count.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "win_pl.h"

TCB * current_task;  /* 02007EEC */
s32 task_sys_w1;  /* 02007EF0 */
s32 task_sys_w2;  /* 02007EF4 */
s32 task_sys_w3;  /* 02007EF8 */
s32 task_free_count;  /* 02007EFC */
u32 system_timer;  /* 02007F00 */
u32 task_tick_mask;  /* 02007F04 */
s8 system_ctrl_flag;  /* 02007F08 */
s8 task_tick_mode;  /* 02007F09 */
s8 vsync_flag;  /* 02007F0A */
u32 frame_pass_count;  /* 02007F0C */
s8 task_ran_flag;  /* 02007F10 */
u32 task_sched_context[3];  /* 02007F14 */
SETTINGS game_config_work;  /* 02007F20 */
u32 exception_regs[23];  /* 02007F30 */
u32 exception_code;  /* 02007F8C */
u8 boot_stack[4100];  /* the stack r15 starts on: vector 1 points at its end (task_stack); provisional name */
u8 task_stack[18][1024];  /* 02008F94 */
TCB task_tbl[8];  /* 0200D794 */
u8 task_tbl_tail[32];  /* after task_tbl; nothing refers to it by name or address */
TASK_QUEUE task_req_queue;  /* 0200D9B4 */
u8 task_req_buff[716];  /* 0200D9C8 */
s16 test_rno;  /* 0200DC94 */
s16 test_menu_no;  /* 0200DC96 */
s16 test_cursor;  /* 0200DC98 */
s16 test_cursor_on;  /* 0200DC9A */
s16 test_cursor_off;  /* 0200DC9C */
s16 test_font_type;  /* 0200DC9E */
s16 test_cursor_max;  /* 0200DCA0 */
u8 test_cursor_max_tail[2];  /* after test_cursor_max; nothing refers to it by name or address */
s16 screen_window[2][4];  /* 0200DCA4 */
SCROLL_WINDOW zoom_frame[2];  /* 0200DCB4 */
s16 screen_disp_ctrl;  /* 0200DCC4 */
s16 screen_base_x;  /* 0200DCC6 */
s16 screen_base_y;  /* 0200DCC8 */
s32 screen_mode;  /* 0200DCCC */
u8 zoom_req_flag;  /* 0200DCD0 */
u8 window_req_flag;  /* 0200DCD1 */
s16 zoom_adj_x;  /* 0200DCD2 */
s16 zoom_adj_y;  /* 0200DCD4 */
s16 flip_obj_ofs_x;  /* 0200DCD6 */
s16 flip_obj_ofs_y;  /* 0200DCD8 */
s16 flip_crt_ofs_x;  /* 0200DCDA */
s16 flip_crt_ofs_y;  /* 0200DCDC */
s16 flip_scr_ofs_x;  /* 0200DCDE */
s16 flip_scr_ofs_y;  /* 0200DCE0 */
s16 flip_zoom_ofs_x;  /* 0200DCE2 */
s16 flip_zoom_ofs_y;  /* 0200DCE4 */
u8 flip_zoom_ofs_y_tail[14];  /* after flip_zoom_ofs_y; nothing refers to it by name or address */
s8 Lv;  /* 0200DCF4 */
s8 Rnd;  /* 0200DCF5 */
u8 Rnd_tail[2];  /* after Rnd; nothing refers to it by name or address */
s8 PASSIVE_X;  /* 0200DCF8 */
u8 PASSIVE_X_tail[1731];  /* after PASSIVE_X; nothing refers to it by name or address */
CharGfxSlot cg_slot_tbl[512];  /* 0200E3BC */
CharGfxEntry * cg_data_list;  /* 0200EBBC */
u8 att_req[4];  /* 0200EBC0 */
WORK * q_hit_push[32];  /* 0200EBC4 */
HS hs[32];  /* 0200EC44 */
s8 ca_check_flag;  /* 0200EE44 */
s16 * dmdat_adrs[16];  /* 0200EE48 */
s16 mkm_wk[32];  /* 0200EE88 */
s16 hpq_in;  /* 0200EEC8 */
u8 hpq_in_tail[2];  /* after hpq_in; nothing refers to it by name or address */
s16 EXE_flag;  /* 0200EECC */
s16 SLOW_flag;  /* 0200EECE */
s16 SLOW_timer;  /* 0200EED0 */
u16 * wipe_dst_ptr;  /* 0200EED4 */
u8 * wipe_back_ptr;  /* 0200EED8 */
u8 * wipe_pat_top;  /* 0200EEDC */
u8 * wipe_pat_ptr;  /* 0200EEE0 */
u8 wipe_pat_ptr_tail[7510];  /* after wipe_pat_ptr; nothing refers to it by name or address */
u8 Candidate_Buff[16];  /* 02010C3A */
u8 Candidate_Buff_tail[2];  /* after Candidate_Buff; nothing refers to it by name or address */
GradeData judge_item[2][2];  /* 02010C4C */
GradeFinalData judge_final[2][2];  /* 02010D7C */
JudgeGals judge_gals[2];  /* 0201102C */
JudgeCom judge_com[2];  /* 02011040 */
u8 ji_sat[2][384];  /* 02011058 */
u8 ji_sat_tail[20];  /* after ji_sat; nothing refers to it by name or address */
u16 Game_timer;  /* 0201136C */
s16 Game_pause;  /* 0201136E */
s16 Game_difficulty;  /* 02011370 */
s16 Control_Time;  /* 02011372 */
s16 Time_in_Time;  /* 02011374 */
s16 Counter_hi;  /* 02011376 */
s16 Counter_low;  /* 02011378 */
s16 Round_Level;  /* 0201137A */
u16 Round_Result;  /* 0201137C */
s8 request_message;  /* 0201137E */
s8 Winner_id;  /* 0201137F */
s8 Loser_id;  /* 02011380 */
s16 PL_Wins[2];  /* 02011382 */
s8 Break_Into;  /* 02011386 */
u8 My_char[2];  /* 02011387 */
u8 Allow_a_battle_f;  /* 02011389 */
u8 Round_num;  /* 0201138A */
s8 Super_Arts[2];  /* 0201138B */
s8 Fade_Flag;  /* 0201138D */
s8 Forbid_Break;  /* 0201138E */
s8 Request_Break[2];  /* 0201138F */
s16 Fade_R_No0;  /* 02011392 */
s16 Fade_R_No1;  /* 02011394 */
u16 Fade_Number;  /* 02011396 */
u8 Fade_Mode;  /* 02011398 */
u32 Score[2][3];  /* 0201139C */
/* Play_Type: declared 2 bytes; the code reads it on into the variables after it */
u8 Play_Type[1];  /* 020113B4 */
u8 Play_Type_tail[1];  /* after Play_Type; nothing refers to it by name or address */
s8 Continue_Count[2];  /* 020113B6 */
s8 Personal_Continue_Flag[2];  /* 020113B8 */
s8 Personal_Disp_Flag;  /* 020113BA */
u8 Personal_Disp_Flag_tail[1];  /* after Personal_Disp_Flag; nothing refers to it by name or address */
s8 WINNER;  /* 020113BC */
s8 LOSER;  /* 020113BD */
u8 LOSER_tail[2];  /* after LOSER; nothing refers to it by name or address */
s16 Conclusion_Type;  /* 020113C0 */
s8 Judge_Round_Flag;  /* 020113C2 */
s16 win_type[2][4];  /* 020113C4 */
s8 win_pause_go;  /* 020113D4 */
s16 message_index;  /* 020113D6 */
s16 Conclusion_Flag;  /* 020113D8 */
s8 New_Challenger;  /* 020113DA */
s8 Champion;  /* 020113DB */
s8 Complete_Judgement;  /* 020113DC */
s8 Reserve_Cut;  /* 020113DD */
s8 Perfect_Flag;  /* 020113DE */
s16 DE_X[19];  /* 020113E0 */
u8 DE_X_tail[2];  /* after DE_X; nothing refers to it by name or address */
s16 Fade_Gap_Timer;  /* 02011408 */
s8 Fade_Half_Flag;  /* 0201140A */
u32 Vital_Bonus[2];  /* 0201140C */
u32 Time_Bonus[2];  /* 02011414 */
u8 Time_Bonus_tail[4];  /* after Time_Bonus; nothing refers to it by name or address */
s16 win_mark_new[2];  /* 02011420 */
s8 Next_Step;  /* 02011424 */
s8 judge_flag;  /* 02011425 */
s8 Wipe_Count;  /* 02011426 */
u8 Wipe_Limit;  /* 02011427 */
u8 Wipe_Mode;  /* 02011428 */
u8 Wipe_Kind;  /* 02011429 */
u8 sc_chr_ram[7360];  /* 0201142A */
u8 bcount_mark_chr_w[9024];  /* 020130EA */
s8 Cover_Timer;  /* 0201542A */
s16 Text_Page_Y;  /* 0201542C */
s8 E_07_Flag[2];  /* 0201542E */
s8 Personal_Timer[2];  /* 02015430 */
s8 Request_E_No;  /* 02015432 */
s8 Request_G_No;  /* 02015433 */
s16 G_Timer;  /* 02015434 */
s16 G_No0;  /* 02015436 */
s16 G_No1;
s16 G_No2;
s16 G_No3;
s16 D_Timer;  /* 0201543E */
s16 D_No0;  /* 02015440 */
s16 D_No1;
s16 D_No2;
s16 D_No3;
u8 Present_Rank[2];  /* 02015448 */
s8 Rank_In[2][4];  /* 0201544A */
s8 Request_Disp_Rank[2][4];  /* 02015452 */
s8 Rank_Demo_Loop;  /* 0201545A */
s8 Rank_Type;  /* 0201545B */
s8 Flash_Sign[2];  /* 0201545C */
s8 Flash_Rank_Time;  /* 0201545E */
s8 Flash_Rank_Interval;  /* 0201545F */
s8 Ranking_X;  /* 02015460 */
s8 Rank;  /* 02015461 */
s8 Rank_X;  /* 02015462 */
s16 Rank_Pos_X;  /* 02015464 */
s16 Rank_Pos_Y;  /* 02015466 */
s16 E_Timer;  /* 02015468 */
s16 E_No0;  /* 0201546A */
s16 E_No1;
s16 E_No2;
s16 E_No3;
s16 F_No0[2];  /* 02015472 */
s16 F_No1[2];  /* 02015476 */
s16 F_No2[2];  /* 0201547A */
s16 F_No3[2];  /* 0201547E */
s16 F_Timer[2];  /* 02015482 */
u8 F_Timer_tail[12];  /* after F_Timer; nothing refers to it by name or address */
s16 E_Number[2][4];  /* 02015492 */
s16 ENTRY_X;  /* 020154A2 */
s16 C_Timer;  /* 020154A4 */
s16 C_No0;  /* 020154A6 */
s16 C_No1;
s16 C_No2;
s16 C_No3;
s8 Complete_Victory;  /* 020154AE */
s8 Demo_Flag;  /* 020154AF */
s8 Next_Demo;  /* 020154B0 */
s8 Demo_PL_Index;  /* 020154B1 */
s8 Demo_Stage_Index;  /* 020154B2 */
s16 S_Timer;  /* 020154B4 */
s16 S_No;  /* 020154B6 */
s16 S_Sub_No;  /* 020154B8 */
s16 S_Sub2_No;  /* 020154BA */
s16 S_Sub3_No;  /* 020154BC */
s16 Flash_Complete[2];  /* 020154BE */
s16 Sel_PL_Complete[2];  /* 020154C2 */
s16 Sel_Arts_Complete[2];  /* 020154C6 */
s16 Select_Start[2];  /* 020154CA */
s16 Cursor_X[2];  /* 020154CE */
s16 Arts_Y[2];  /* 020154D2 */
u8 Arts_Y_tail[4];  /* after Arts_Y; nothing refers to it by name or address */
s16 Cursor_Y_Pos[2][3];  /* 020154DA */
s16 Stop_Cursor[2];  /* 020154E6 */
s16 Move_Super_Arts[2];  /* 020154EA */
u8 Move_Super_Arts_tail[6];  /* after Move_Super_Arts; nothing refers to it by name or address */
s16 Battle_Country;  /* 020154F4 */
s16 Face_Status;  /* 020154F6 */
s8 Face_MV_Request;  /* 020154F8 */
s8 Face_Move;  /* 020154F9 */
s8 Appear_Cursor;  /* 020154FA */
s8 Select_Timer;  /* 020154FB */
s8 Time_Stop;  /* 020154FC */
s8 Time_Over;  /* 020154FD */
s16 Unit_Of_Timer;  /* 020154FE */
s8 Player_id;  /* 02015500 */
s8 Last_Player_id;  /* 02015501 */
s8 Player_Number;  /* 02015502 */
s8 COM_id;  /* 02015503 */
s8 EM_id;  /* 02015504 */
s16 VS_Index[2];  /* 02015506 */
u8 VS_Index_tail[2];  /* after VS_Index; nothing refers to it by name or address */
s16 Plate_X[2][3];  /* 0201550C */
s16 Plate_Y[2][3];  /* 02015518 */
u8 Plate_Y_tail[24];  /* after Plate_Y; nothing refers to it by name or address */
s16 SP_No[2][4];  /* 0201553C */
s16 ID;  /* 0201554C */
s16 Face_No[2];  /* 0201554E */
s16 Sel_Sub_No[2];  /* 02015552 */
s16 Arts_Cursor_No[2];  /* 02015556 */
s16 Arts_Cursor_Timer[2];  /* 0201555A */
s16 Exit_No;  /* 0201555E */
u8 Exit_No_tail[4];  /* after Exit_No; nothing refers to it by name or address */
s16 Select_Arts[2];  /* 02015564 */
u8 Select_Arts_tail[4];  /* after Select_Arts; nothing refers to it by name or address */
s8 Select_Status[2];  /* 0201556C */
s8 Select_Demo_Index;  /* 0201556E */
u8 Country;  /* 0201556F */
s16 mes_already;  /* 02015570 */
s16 CP_No[2][4];  /* 02015572 */
s16 CP_Index[2][8];  /* 02015582 */
s16 Pattern_Index[2];  /* 020155A2 */
s16 Timer_00[2];  /* 020155A6 */
s16 Timer_01[2];  /* 020155AA */
s8 Combo_Speed[2];  /* 020155AE */
u8 Combo_Speed_tail[2];  /* after Combo_Speed; nothing refers to it by name or address */
s16 PL_Distance[2];  /* 020155B2 */
s16 Area_Number[2];  /* 020155B6 */
u16 Lever_Buff[2];  /* 020155BA */
u16 Lever_Pool[2];  /* 020155BE */
const_s16_arr Tech_Address[2];  /* 020155C4 */
s16 Tech_Index[2];  /* 020155CC */
u8 Tech_Index_tail[24];  /* after Tech_Index; nothing refers to it by name or address */
s16 Random_ix16_com;  /* 020155E8 */
s16 Random_ix32_com;  /* 020155EA */
s16 M_Timer;  /* 020155EC */
s16 M_No0;  /* 020155EE */
s16 M_No1;  /* 020155F0 */
s16 M_No2;  /* 020155F2 */
s16 M_No3;  /* 020155F4 */
s8 Demo_Step_Flag;  /* 020155F6 */
s16 VS_Tech[2];  /* 020155F8 */
s8 Exec_Wipe;  /* 020155FC */
u16 Guard_Type[2];  /* 020155FE */
s16 Separate_Area[2][3];  /* 02015602 */
u32 * Shell_Address[2];  /* 02015610 */
u16 Free_Lever[2];  /* 02015618 */
s8 Passive_Flag[2];  /* 0201561C */
s8 Flip_Flag[2];  /* 0201561E */
u8 Flip_Flag_tail[4];  /* after Flip_Flag; nothing refers to it by name or address */
s8 Lie_Flag[2];  /* 02015624 */
s16 Term_No[2];  /* 02015626 */
s8 Attack_Flag[2];  /* 0201562A */
s8 Passive_Mode;  /* 0201562C */
s8 Limited_Flag[2];  /* 0201562D */
s8 Shell_Ignore_Timer[2];  /* 0201562F */
s16 Com_Width_Data[2];  /* 02015632 */
s8 Event_Judge_Gals;  /* 02015636 */
u8 EJG_Index[4];  /* 02015637 */
s8 Guard_Flag[2];  /* 0201563B */
u16 Lever_Squat[2];  /* 0201563E */
u16 M_Lv[2];  /* 02015642 */
s8 Pierce_Menu[2];  /* 02015646 */
s8 Counter_Attack[2];  /* 02015648 */
s16 zuubun_base_x;  /* 0201564A */
s8 Face_MV_Time;  /* 0201564C */
s8 Before_Jump[2];  /* 0201564D */
u8 Before_Jump_tail[17];  /* after Before_Jump; nothing refers to it by name or address */
s8 Stop_Combo;  /* 02015660 */
u8 Stock_Hit_Flag[2];  /* 02015661 */
s8 Rolling_Flag[2];  /* 02015663 */
u8 Continue_Coin[2];  /* 02015665 */
s8 Ignore_Entry[2];  /* 02015667 */
u8 Ignore_Entry_tail[1];  /* after Ignore_Entry; nothing refers to it by name or address */
/* Cursor_Y: declared 4 bytes; the code reads it on into the variables after it */
u8 Cursor_Y[1];  /* 0201566A */
u8 Cursor_Y_tail[15];  /* after Cursor_Y; nothing refers to it by name or address */
s8 Last_Arts_PL;  /* 0201567A */
s8 Moving_Plate[2];  /* 0201567B */
s8 Naming_Cut[2];  /* 0201567D */
s8 Moving_Plate_Counter[2];  /* 0201567F */
s8 OK_Priority[2];  /* 02015681 */
s8 Player_Color[2];  /* 02015683 */
s8 PP_Priority[2][3];  /* 02015685 */
u8 PP_Priority_tail[31];  /* after PP_Priority; nothing refers to it by name or address */
u8 Stock_My_char[2];  /* 020156AA */
s8 Stock_Player_Color[2];  /* 020156AC */
s16 Insert_Y;  /* 020156AE */
u8 Insert_Y_tail[2];  /* after Insert_Y; nothing refers to it by name or address */
u8 Version_Type;  /* 020156B2 */
u8 Version_Type_tail[1];  /* after Version_Type; nothing refers to it by name or address */
s8 BGM_Fade_Out_Flag;  /* 020156B4 */
s16 zoom_request_flag;  /* 020156B6 */
s16 zoom_req_flag_old;  /* 020156B8 */
s16 zoom_request_level;  /* 020156BA */
s16 Stock_Com_Color[2];  /* 020156BC */
s8 Stock_Com_Arts[2];  /* 020156C0 */
u8 Stock_Com_Arts_tail[16];  /* after Stock_Com_Arts; nothing refers to it by name or address */
s8 Stop_SG;  /* 020156D2 */
s16 Last_Selected_ID;  /* 020156D4 */
s16 Last_Called_SE;  /* 020156D6 */
s16 scr_req_x;  /* 020156D8 */
s16 scr_req_y;  /* 020156DA */
u8 scr_req_y_tail[6];  /* after scr_req_y; nothing refers to it by name or address */
s8 Operator_Status[2];  /* 020156E2 */
s8 Round_Operator[2];  /* 020156E4 */
u32 Stock_Score[2];  /* 020156E8 */
s8 another_bg[2];  /* 020156F0 */
s8 another_bg_old[2];  /* 020156F2 */
s8 judge_disp_all;  /* 020156F4 */
u8 judge_disp_all_tail[49];  /* after judge_disp_all; nothing refers to it by name or address */
s8 unused_flag_b;  /* 02015726 */
s8 bg_test_flag;  /* 02015727 */
s8 Last_Super_Arts[2];  /* 02015728 */
s8 Last_My_char[2];  /* 0201572A */
u8 Last_My_char_tail[4];  /* after Last_My_char; nothing refers to it by name or address */
s8 Continue_Menu[2];  /* 02015730 */
s8 Timer_Freeze;  /* 02015732 */
s8 Rapid_No[2][4];  /* 02015733 */
s16 Rapid_Index[2];  /* 0201573C */
s8 Standing_Timer[2];  /* 02015740 */
s8 Before_Look[2];  /* 02015742 */
s16 Shell_Separate_Area[2][3];  /* 02015744 */
s16 Attack_Counter[2];  /* 02015750 */
s16 Last_Attack_Counter[2];  /* 02015754 */
s8 Attack_Count_No0[2];  /* 02015758 */
s16 Com_Color_Shot;  /* 0201575A */
s8 Standing_Master_Timer[2];  /* 0201575C */
s8 unused_flag_c;  /* 0201575E */
s8 test_sw_lock;  /* 0201575F */
s8 Keep_BGM_Flag;  /* 02015760 */
s8 No_Death;  /* 02015761 */
s8 Flash_MT[2];  /* 02015762 */
s8 Squat_Timer[2];  /* 02015764 */
s8 Squat_Master_Timer[2];  /* 02015766 */
s8 Turn_Over[2];  /* 02015768 */
s16 Distance_XX_Index[2];  /* 0201576A */
u16 Resume_Lever[2][20];  /* 0201576E */
s8 Turn_Over_Timer[2];  /* 020157BE */
s8 Jump_Pass_Timer[2][4];  /* 020157C0 */
s8 sa_gauge_flash[2];  /* 020157C8 */
s8 Receive_Flag[2];  /* 020157CA */
s8 Disposal_Again[2];  /* 020157CC */
u16 pcon_timer;  /* 020157CE */
s8 unused_flag_a;  /* 020157D0 */
volatile s8 BGM_Fade_Level;  /* 020157D1 */
u8 Decided_My_char[2];  /* 020157D2 */
s8 Break_Com[2][24];  /* 020157D4 */
s8 Sel_Exit_Flag;  /* 02015804 */
u16 Lever_Store[2][3];  /* 02015806 */
s16 Return_CP_No[2];  /* 02015812 */
s16 Return_CP_Index[2];  /* 02015816 */
s16 Return_Pattern_Index[2];  /* 0201581A */
s8 aiuchi_flag;  /* 0201581E */
u8 paring_counter[2];  /* 0201581F */
u8 paring_bonus_r[2];  /* 02015821 */
u8 paring_ctr_vs[2][2];  /* 02015823 */
u8 paring_ctr_ori[2];  /* 02015827 */
u8 Type_of_Attack[2];  /* 02015829 */
u16 Lever_LR[2];  /* 0201582C */
s16 Last_Eftype[2];  /* 02015830 */
u16 DENJIN_No[2];  /* 02015834 */
u8 DENJIN_Term[2];  /* 02015838 */
u16 SC_Personal_Time[2];  /* 0201583A */
u8 Attack_Count_Buff[2][4];  /* 0201583E */
u8 Attack_Count_Index[2];  /* 02015846 */
s16 Guard_Counter[2];  /* 02015848 */
u8 CC_Type;  /* 0201584C */
u8 CC_Value[2];  /* 0201584D */
u8 CC_Value_tail[2];  /* after CC_Value; nothing refers to it by name or address */
u8 Continue_Coin2[2];  /* 02015851 */
s16 kage_gfx_ofs[64];  /* 02015854 */
s16 kage_gfx_cells[64];  /* 020158D4 */
s16 car_gfx_ofs[288];  /* 02015954 */
s16 car_gfx_cells[288];  /* 02015B94 */
s16 hitmark_gfx_ofs[2][512];  /* 02015DD4 */
s16 hitmark_gfx_cells[512];  /* 020165D4 */
s16 seraph_gfx_ofs[64];  /* 020169D4 */
s16 seraph_gfx_cells[64];  /* 02016A54 */
s16 Limit_Time;  /* 02016AD4 */
u8 Weak_PL;  /* 02016AD6 */
s16 Last_Pattern_Index[2];  /* 02016AD8 */
u8 Bullet_No[2];  /* 02016ADC */
u8 Bullet_Counter[2];  /* 02016ADE */
s16 Random_ix16_ex_com;  /* 02016AE0 */
u16 Random_ix32_ex_com;  /* 02016AE2 */
s16 Entry_Mes_X[2];  /* 02016AE4 */
s16 Entry_Mes_Wide[2];  /* 02016AE8 */
s8 Disp_Win_Name;  /* 02016AEC */
u8 Perfect_Counter[2];  /* 02016AED */
u8 Straight_Counter[2];  /* 02016AEF */
u32 Complete_Bonus;  /* 02016AF4 */
u8 Complete_Bonus_tail[8];  /* after Complete_Bonus; nothing refers to it by name or address */
s8 Break_Into_CPU;  /* 02016B00 */
s8 ID_of_Face[3][7];  /* 02016B01 */
s8 Cursor_Move[2];  /* 02016B16 */
s8 Auto_Cursor[2];  /* 02016B18 */
s8 Auto_No[2];  /* 02016B1A */
s8 Auto_Index[2];  /* 02016B1C */
s8 Auto_Timer[2];  /* 02016B1E */
s8 ID2;  /* 02016B20 */
u8 Explosion;  /* 02016B21 */
s16 Exit_Timer;  /* 02016B22 */
s8 Introduce_Break_Into[2];  /* 02016B24 */
u32 Stage_Stock_Score[2];  /* 02016B28 */
s16 Max_vitality;  /* 02016B30 */
s8 gouki_wins;  /* 02016B32 */
s8 EM_Rank;  /* 02016B33 */
s8 Disp_PERFECT;  /* 02016B34 */
u8 Escape_SS;  /* 02016B35 */
s8 Deley_Shot_No[2];  /* 02016B36 */
s8 Deley_Shot_Timer[2];  /* 02016B38 */
s16 Bonus_Game_Flag;  /* 02016B3A */
s16 Bonus_Game_Work;  /* 02016B3C */
s16 Bonus_Game_result;  /* 02016B3E */
s16 Bonus_Game_ex_result;  /* 02016B40 */
s8 Lost_Round[2];  /* 02016B42 */
s8 Super_Arts_Finish[2];  /* 02016B44 */
s8 Stage_SA_Finish[2];  /* 02016B46 */
s8 Perfect_Finish[2];  /* 02016B48 */
s8 Cheap_Finish[2];  /* 02016B4A */
s8 Last_My_char2[2];  /* 02016B4C */
u8 gouki_app;  /* 02016B4E */
s8 Bonus_Game_Complete;  /* 02016B4F */
s16 Stock_Bonus_Game_Result;  /* 02016B50 */
s16 Gill_Pos_X;  /* 02016B52 */
s16 bs_scrrrl[2][2];  /* 02016B54 */
u32 Bonus_Score;  /* 02016B5C */
u32 Final_Bonus_Score;  /* 02016B60 */
s16 Bonus_Stage_RNO[4];  /* 02016B64 */
u8 Demo_Lever_Play;  /* 02016B6C */
s16 Bonus_Stage_Level;  /* 02016B6E */
s16 Bonus_Stage_Tix;  /* 02016B70 */
s8 Get_Demo_Index;  /* 02016B72 */
u8 Combo_Demo_Flag;  /* 02016B73 */
u8 Stage_Continue[2];  /* 02016B74 */
u8 Pause_Hit_Marks;  /* 02016B76 */
u8 Special_Settle;  /* 02016B77 */
u8 Extra_Break;  /* 02016B78 */
u8 Shin_Gouki_BGM;  /* 02016B79 */
s8 Stage_Lost_Round[2];  /* 02016B7A */
s8 Stage_Perfect_Finish[2];  /* 02016B7C */
s8 Stage_Cheap_Finish[2];  /* 02016B7E */
s8 EXE_obroll;  /* 02016B80 */
u8 End_PL;  /* 02016B81 */
s8 Stage_Judge_Finish[2];  /* 02016B82 */
u8 PB_Status;  /* 02016B84 */
u8 Flip_Counter[2];  /* 02016B85 */
s8 Stage_Time_Finish[2];  /* 02016B87 */
u8 Bonus_Type;  /* 02016B89 */
s8 Completion_Bonus[2][2];  /* 02016B8A */
s8 ichikannkei;  /* 02016B8E */
s16 bs2_floor[3];  /* 02016B90 */
s16 bs2_hosei[3];  /* 02016B96 */
s16 bs2_current_damage;  /* 02016B9C */
u8 WIN_X;  /* 02016B9E */
s8 Complete_Face;  /* 02016B9F */
u8 Plate_Disposal_No[2][3];  /* 02016BA0 */
u8 SO_No[2];  /* 02016BA6 */
u8 Order[100];  /* 02016BA8 */
u8 Order_Dir[100];  /* 02016C0C */
u8 Order_Timer[100];  /* 02016C70 */
u16 Win_Record[2];  /* 02016CD4 */
u16 Stock_Win_Record[2];  /* 02016CD8 */
u8 Disp_Command_Name[2][3];  /* 02016CDC */
u32 * Synchro_Address[2][2];  /* 02016CE4 */
u8 SC_No[4];  /* 02016CF4 */
u8 EM_List[2][2];  /* 02016CF8 */
s8 Sel_EM_Complete[2];  /* 02016CFC */
s8 Temporary_EM[2];  /* 02016CFE */
s8 Suicide[8];  /* 02016D00 */
const u8 * Free_Ptr[2];  /* 02016D08 */
u8 BGM_No[2];  /* 02016D10 */
u8 BGM_Timer[2];  /* 02016D12 */
u16 WGJ_Win;  /* 02016D14 */
u32 WGJ_Score;  /* 02016D18 */
u8 EM_History[2][10];  /* 02016D1C */
u8 Scene_Cut;  /* 02016D30 */
u8 GO_No[2];  /* 02016D31 */
u8 GO_No_tail[2];  /* after GO_No; nothing refers to it by name or address */
u8 Aborigine;  /* 02016D35 */
s16 Target_BG_X[6];  /* 02016D36 */
s16 Offset_BG_X[6];  /* 02016D42 */
u8 Continue_Count_Down[2];  /* 02016D4E */
u8 WGJ_Target;  /* 02016D50 */
u8 Final_Result_id;  /* 02016D51 */
u8 EM_Candidate[2][2][10];  /* 02016D52 */
u8 Wipe_Panel_Count;  /* 02016D7A */
s8 Last_Selected_EM[2];  /* 02016D7B */
u8 Battle_Round[2];  /* 02016D7D */
u8 Battle_Q[2];  /* 02016D7F */
u8 Q_Country;  /* 02016D81 */
u8 Continue_Cut[2];  /* 02016D82 */
u8 Introduce_Boss[2][2];  /* 02016D84 */
u8 Stage_Intro_Flag;  /* 02016D88 */
u8 Appear_Q;  /* 02016D89 */
u32 Bonus_Score_Plus;  /* 02016D8C */
s8 Cut_Scroll;  /* 02016D90 */
u32 Perfect_Bonus[2];  /* 02016D94 */
s8 OK_Moving_SA_Plate[2];  /* 02016D9C */
u8 Final_Play_Type[2];  /* 02016D9E */
s8 Best_Grade[2];  /* 02016DA0 */
s8 Cursor_Timer[2];  /* 02016DA2 */
s16 Result_Disp_Timer[2];  /* 02016DA4 */
u8 Reset_Timer[2];  /* 02016DA8 */
s16 scrl;  /* 02016DAA */
s16 scrr;  /* 02016DAC */
u8 bbbs_type;  /* 02016DAE */
u8 Straight_Flag[2];  /* 02016DAF */
u8 kakushi_on;  /* 02016DB1 */
u8 kakushi_ix;  /* 02016DB2 */
u8 kakushi_op;  /* 02016DB3 */
u8 RO_backup[2];  /* 02016DB4 */
u8 PT_backup;  /* 02016DB6 */
u8 dm17_to_nm23_flag;  /* 02016DB7 */
u8 dm17_to_nm23_flag_tail[148];  /* after dm17_to_nm23_flag; nothing refers to it by name or address */
RANK_DATA Ranking_Data[20];  /* 02016E4C */
RANK_DATA Present_Data[2];  /* 02016FDC */
u8 Debug_w[4];  /* 02017004 */
s8 MANAGE_X;  /* 02017008 */
u8 MANAGE_X_tail[3];  /* after MANAGE_X; nothing refers to it by name or address */
s16 Cont_No;  /* 0201700C */
s16 Cont_Sub_No;  /* 0201700E */
s16 Cont_Sub2_No;  /* 02017010 */
s16 Cont_Sub3_No;  /* 02017012 */
s16 Cont_Timer;  /* 02017014 */
u8 Cont_Timer_tail[2];  /* after Cont_Timer; nothing refers to it by name or address */
s16 CONTINUE_X;  /* 02017018 */
u8 CONTINUE_X_tail[2];  /* after CONTINUE_X; nothing refers to it by name or address */
u8 SEL_PL_X;  /* 0201701C */
s16 Play_Type_1st;  /* 0201701E */
u16 * Demo_Ptr[2];  /* 02017020 */
u8 Demo_Ptr_tail[10];  /* after Demo_Ptr; nothing refers to it by name or address */
u16 Color7[2];  /* 02017032 */
u8 Color7_tail[2];  /* after Color7; nothing refers to it by name or address */
u8 SEL_CPU_X;  /* 02017038 */
s16 Start_X;  /* 0201703A */
s8 Config_Item_jp;  /* 0201703C */
s8 Config_Exit_jp;  /* 0201703D */
s8 Config_Move_jp;  /* 0201703E */
s8 Config_Keep_Bits_jp;  /* 0201703F */
s8 Config_Old_jp;  /* 02017040 */
s8 Config_New_jp;  /* 02017041 */
s8 Config_Org_jp;  /* 02017042 */
s16 Config_Attr_jp;  /* 02017044 */
s16 Config_Rep_Timer_jp[4];  /* 02017046 */
s8 Config_Rep_Count_jp[4];  /* 0201704E */
u8 Config_Rep_Count_jp_tail[2];  /* after Config_Rep_Count_jp; nothing refers to it by name or address */
s8 Config_Item_en;  /* 02017054 */
s8 Config_Exit_en;  /* 02017055 */
s8 Config_Move_en;  /* 02017056 */
s8 Config_Keep_Bits_en;  /* 02017057 */
s8 Config_Old_en;  /* 02017058 */
s8 Config_New_en;  /* 02017059 */
s8 Config_Org_en;  /* 0201705A */
s16 Config_Attr_en;  /* 0201705C */
s16 Config_Rep_Timer_en[4];  /* 0201705E */
s8 Config_Rep_Count_en[4];  /* 02017066 */
u8 Config_Rep_Count_en_tail[2];  /* after Config_Rep_Count_en; nothing refers to it by name or address */
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
u8 dbg_look_catch[792];  /* 0201D380 */
u8 dbg_look_caught[792];  /* 0201D698 */
HITA_BOX dbg_look_attack[198];  /* 0201D9B0 */
u8 dbg_look_hosei[792];  /* 0201F270 */
u8 dbg_edit_judge[1584];  /* 0201F588 */
u8 dbg_edit_body[3168];  /* 0201FBB8 */
u8 dbg_edit_hand[6336];  /* 02020818 */
u8 dbg_edit_catch[792];  /* 020220D8 */
u8 dbg_edit_caught[792];  /* 020223F0 */
u8 dbg_edit_attack[6336];  /* 02022708 */
u8 dbg_edit_hosei[792];  /* 02023FC8 */
u8 dbg_copy_judge[16];  /* 020242E0 */
u8 dbg_copy_body[32];  /* 020242F0 */
u8 dbg_copy_hand[64];  /* 02024310 */
u8 dbg_copy_catch[8];  /* 02024350 */
u8 dbg_copy_caught[8];  /* 02024358 */
u8 dbg_copy_attack[64];  /* 02024360 */
u8 dbg_copy_hosei[8];  /* 020243A0 */
WORK_Other * dbg_hita_ewk[7];  /* 020243A8 */
u8 dbg_hita_ewk_tail[4];  /* after dbg_hita_ewk; nothing refers to it by name or address */
s16 dbg_hita_num;  /* 020243C8 */
s16 dbg_hita_grid_sw;  /* 020243CA */
s16 dbg_parts_olc_ix[4];  /* 020243CC */
s8 dbg_parts_sel;  /* 020243D4 */
PLW dbg_parts_plw[4];  /* 020243D8 */
u8 ixbfw_cut;  /* 02025638 */
u8 ixbfw_cut_tail[3];  /* after ixbfw_cut; nothing refers to it by name or address */
T_PL_LVR t_pl_lvr[2];  /* 0202563C */
WAZA_WORK waza_work[2][56];  /* 020256C4 */
u8 waza_work_tail[2];  /* after waza_work; nothing refers to it by name or address */
u16 sw_work;  /* 02026306 */
s16 * cmd_tbl_ptr;  /* 02026308 */
s16 waza_type[2];  /* 0202630C */
T_PL_LVR * chk_pl;  /* 02026310 */
WAZA_WORK * waza_ptr;  /* 02026314 */
WORK_CP wcp[2];  /* 02026318 */
s16 cmd_id;  /* 02026B24 */
PLW * cmd_pl;  /* 02026B28 */
u8 cmd_pl_tail[4];  /* after cmd_pl; nothing refers to it by name or address */
s16 eff_hit_flag[11];  /* 02026B30 */
AKE_SCRL ake_scrl_w[5];  /* 02026B48 */
BG bg_w;  /* 02026BAC */
s16 scr_cg_c_no;  /* 02026FF0 */
s16 ake_cg_c_no;  /* 02026FF2 */
BGW * bgw_ptr;  /* 02026FF4 */
s32 suzi_calc_w[2];  /* 02026FF8 */
u8 suzi_calc_w_tail[8];  /* after suzi_calc_w; nothing refers to it by name or address */
Ideal_W ideal_w;  /* 02027008 */
u16 suzi_line_buf[2048];  /* 02027010 */
MVXY bg_mvxy;  /* 02028010 */
s16 bg_stop;  /* 02028028 */
s8 bg_app_stop;  /* 0202802A */
s16 base_y_pos;  /* 0202802C */
u8 base_y_pos_tail[12];  /* after base_y_pos; nothing refers to it by name or address */
s16 bg_ofs_work[3];  /* 0202803A */
s16 bg_zoom_x_pos;  /* 02028040 */
s16 bg_sp_work;  /* 02028042 */
u8 bg_sp_work_tail[2];  /* after bg_sp_work; nothing refers to it by name or address */
s16 bg_land_flag;  /* 02028046 */
s8 demo_car_flag[2];  /* 02028048 */
s16 bg_etc_flag;  /* 0202804A */
s16 bg_stop2;  /* 0202804C */
s16 chase_x;  /* 0202804E */
s16 chase_y;  /* 02028050 */
s16 chase_time_x;  /* 02028052 */
s16 chase_time_y;  /* 02028054 */
s8 akebono_flag;  /* 02028056 */
s8 seraph_flag;  /* 02028057 */
s8 aku_flag;  /* 02028058 */
s8 bg_select_no;  /* 02028059 */
s8 sa_pa_flag;  /* 0202805A */
s8 bg_app;  /* 0202805B */
s8 bg_vbl_trans_flag;  /* 0202805C */
u8 bg_vbl_trans_flag_tail[3];  /* after bg_vbl_trans_flag; nothing refers to it by name or address */
s16 ls_cnt1;  /* 02028060 */
BG_ADRS eff_bg_adrs[3];  /* 02028064 */
u8 eff_bg_adrs_tail[56];  /* after eff_bg_adrs; nothing refers to it by name or address */
s16 bg1403_wait;  /* 020280B4 */
u8 bg1403_wait_tail[2];  /* after bg1403_wait; nothing refers to it by name or address */
s16 Name_00[2];  /* 020280B8 */
NAME_WK name_wk[2];  /* 020280BC */
NAME_WK * name_ptr;  /* 02028128 */
SC_NAME_WK sc_name_wk[2][4];  /* 0202812C */
SC_NAME_WK * nsc_ptr;  /* 0202817C */
RANK_NAME_W rank_name_w[2];  /* 02028180 */
s16 Name_Input_f;  /* 02028188 */
s16 naming_cnt[2];  /* 0202818A */
s16 n_disp_flag;  /* 0202818E */
s16 name_limit_timer[2];  /* 02028190 */
s16 Appear_end;  /* 02028194 */
s16 appear_work[2];  /* 02028196 */
s8 Appear_flag[2];  /* 0202819A */
s8 Appear_free[2];  /* 0202819C */
s8 Appear_hv[2];  /* 0202819E */
s8 Appear_car_stop[2];  /* 020281A0 */
s16 app_counter[2];  /* 020281A2 */
u8 app_counter_tail[2];  /* after app_counter; nothing refers to it by name or address */
s16 poison_flag[2];  /* 020281A8 */
s16 win_rno[2];  /* 020281AC */
s16 a_rno;  /* 020281B0 */
s16 win_free[2];  /* 020281B2 */
u8 win_free_tail[2];  /* after win_free; nothing refers to it by name or address */
s16 lose_rno[3];  /* 020281B8 */
s16 lose_free[2];  /* 020281BE */
u8 lose_free_tail[2];  /* after lose_free; nothing refers to it by name or address */
OP_W op_w;  /* 020281C4 */
s16 op_end_flag;  /* 020281E0 */
s16 op_obj_disp;  /* 020281E2 */
u8 op_obj_disp_tail[2];  /* after op_obj_disp; nothing refers to it by name or address */
s8 op_scrn_end;  /* 020281E6 */
s16 op_sound_status;  /* 020281E8 */
OPBW * opw_ptr;  /* 020281EC */
u8 opw_ptr_tail[2];  /* after opw_ptr; nothing refers to it by name or address */
s16 op_plmove_timer;  /* 020281F2 */
s16 op_demo_index;  /* 020281F4 */
MVXY op_bg_mvxy[3];  /* 020281F8 */
END_W end_w;  /* 02028240 */
s16 ls_rate1;  /* 0202824C */
s8 end_etc_flag;  /* 0202824E */
s8 ending_all_end;  /* 0202824F */
s8 end_fade_flag;  /* 02028250 */
s8 end_no_cut;  /* 02028251 */
s16 end_fade_timer;  /* 02028252 */
u8 end_fade_timer_tail[2];  /* after end_fade_timer; nothing refers to it by name or address */
s8 end_name_cut[2];  /* 02028256 */
s8 end_staff_flag;  /* 02028258 */
u8 end_cont_coin;  /* 02028259 */
u8 end_obj_sync;  /* 0202825A */
s16 staff_roll_timer;  /* 0202825C */
s32 staff_r_no;  /* 02028260 */
s8 end5_col_ix;  /* 02028264 */
s8 end5_pal_ix;  /* 02028265 */
s16 end5_bg1_pos;  /* 02028266 */
SELPL card_pl_w[2];  /* 02028268 */
s16 card_msg_cnt;  /* 02028280 */
u8 card_msg_cnt_tail[2];  /* after card_msg_cnt; nothing refers to it by name or address */
s16 cd_ready_flag;  /* 02028284 */
s16 cd_spin_timer;  /* 02028286 */
s16 roll_rate2;  /* 02028288 */
s16 roll_rate_t2;  /* 0202828A */
s16 roll_stop;  /* 0202828C */
s16 name_timer;  /* 0202828E */
s8 dbg_play12_w[4];  /* 02028290 */
u8 col_trans_req_tbl[256];  /* 02028294 */
s16 col_trans_req_cnt0;  /* 02028394 */
s16 col_trans_req_cnt1;  /* 02028396 */
s16 col_trans_req_cnt2;  /* 02028398 */
s32 col_trans_result;  /* 0202839C */
u16 * sc_trans_dst;  /* 020283A0 */
u8 * sc_bak_ptr;  /* 020283A4 */
u8 * sc_trans_src;  /* 020283A8 */
u8 sc_trans_src_tail[6];  /* after sc_trans_src; nothing refers to it by name or address */
u16 sc_trans_word;  /* 020283B2 */
u8 sc_chr_bak_1p[320];  /* 020283B4 */
u8 sc_chr_bak_2p[324];  /* 020284F4 */
s16 vital_col_ix;  /* 02028638 */
s16 vital_dot_pos;  /* 0202863A */
s16 vital_red_ofs;  /* 0202863C */
s16 vital_yel_ofs;  /* 0202863E */
u16 vital_stop_flag[2];  /* 02028640 */
u16 gauge_stop_flag[2];  /* 02028644 */
/* vit_bar: declared 48 bytes; the code reads it on into the variables after it */
u8 vit_bar[24];  /* 02028648 */
u8 vit_bar_2p[24];  /* 02028660 */
ROUND_TIMER round_timer;  /* 02028678 */
u8 round_timer_tail[4];  /* after round_timer; nothing refers to it by name or address */
s16 flash_timer;  /* 02028680 */
s8 flash_r_num;  /* 02028682 */
s8 flash_col;  /* 02028683 */
COUNT_WORK count_work;  /* 02028684 */
u8 count_work_tail[2];  /* after count_work; nothing refers to it by name or address */
s8 Old_Stop_SG;  /* 0202868C */
s8 Exec_Wipe_F;  /* 0202868D */
s8 time_clear[2];  /* 0202868E */
s16 spg_number;  /* 02028690 */
s16 spg_work;  /* 02028692 */
s16 spg_offset;  /* 02028694 */
s8 time_num;  /* 02028696 */
s8 time_timer;  /* 02028697 */
s8 time_flag[2];  /* 02028698 */
s16 spg_col;  /* 0202869A */
SPG_DAT spg_dat[2];  /* 0202869C */
/* win_mark_rno: declared 4 bytes; the code reads it on into the variables after it */
u8 win_mark_rno[2];  /* 02028704 */
u8 win_mark_rno_2p[2];  /* 02028706 */
s16 win_mark_timer[2];  /* 02028708 */
s16 win_mark_phase[2];  /* 0202870C */
s16 win_mark_num[2];  /* 02028710 */
s16 win_mark_pos[2];  /* 02028714 */
s8 fade_layer_num;  /* 02028718 */
s16 fade_cont_rno;  /* 0202871A */
s8 fade_end_timer;  /* 0202871C */
FADE_LAYER fade_layer[7];  /* 02028720 */
s16 stn_number;  /* 02028800 */
s16 stn_work;  /* 02028802 */
s16 stn_offset;  /* 02028804 */
STN_DAT sdat[2];  /* 02028808 */
s16 old_cmb_flag[2];  /* 02028838 */
s8 cmb_stock[2];  /* 0202883C */
s8 first_attack;  /* 0202883E */
s8 rever_attack[2];  /* 0202883F */
s8 paring_attack[2];  /* 02028841 */
s8 bonus_pts[2];  /* 02028843 */
s16 hit_num;  /* 02028846 */
u8 sa_kind;  /* 02028848 */
u8 end_flag[2];  /* 02028849 */
s16 calc_hit[2][10];  /* 0202884C */
s16 score_calc[2][12];  /* 02028874 */
s8 cmb_all_stock;  /* 020288A4 */
s8 sarts_finish_flag[2];  /* 020288A5 */
s8 last_hit_time;  /* 020288A7 */
s8 cmb_calc_now[2];  /* 020288A8 */
u8 cst_read[2];  /* 020288AA */
u8 cst_write[2];  /* 020288AC */
CMST_WIN cmst_buff[2][4];  /* 020288B0 */
u32 frw[128][512];  /* 02028990 */
u8 frw_tail[4];  /* after frw; nothing refers to it by name or address */
s16 frwque[128];  /* 02068994 */
s16 frwctr;  /* 02068A94 */
s16 head_ix[8];  /* 02068A96 */
s16 tail_ix[8];  /* 02068AA6 */
s16 exec_tm[8];  /* 02068AB6 */
u8 exec_tm_tail[2];  /* after exec_tm; nothing refers to it by name or address */
/* eff14_work: declared 400 bytes; the code reads it on into the variables after it */
u8 eff14_work[320];  /* 02068AC8 */
s16 chk77_flag;  /* 02068C08 */
u8 chk77_flag_tail[2];  /* after chk77_flag; nothing refers to it by name or address */
u8 OK_Appear79[2];  /* 02068C0C */
u8 Extra_Counter[2];  /* 02068C0E */
s16 RND_95;  /* 02068C10 */
s16 END_OF_95;  /* 02068C12 */
s16 effa6_pos_x_1p;  /* 02068C14 */
s16 effa6_pos_y_1p;  /* 02068C16 */
s16 effa6_pos_z_1p;  /* 02068C18 */
s16 effa6_pos_x_2p;  /* 02068C1A */
s16 effa6_pos_y_2p;  /* 02068C1C */
u8 effa6_pos_y_2p_tail[2];  /* after effa6_pos_y_2p; nothing refers to it by name or address */
s16 mmes_already;  /* 02068C20 */
u8 mmes_already_tail[2];  /* after mmes_already; nothing refers to it by name or address */
s16 rf_b2_flag;  /* 02068C24 */
s16 b2_curr_no;  /* 02068C26 */
WORK_Other * effb3_oya;  /* 02068C28 */
s16 test_pl_no;  /* 02068C2C */
s16 test_mes_no;  /* 02068C2E */
s16 test_in;  /* 02068C30 */
s16 old_mes_no2;  /* 02068C32 */
s16 old_mes_no3;  /* 02068C34 */
s16 old_mes_no_pl;  /* 02068C36 */
s16 mes_timer;  /* 02068C38 */
WORK_Other * oya_p;  /* 02068C3C */
s16 efff9_suicide;  /* 02068C40 */
s32 * efff9_txt_no_adrs;  /* 02068C44 */
u16 * efff9_txt_scene_adrs;  /* 02068C48 */
s16 efff9_PL_NO;  /* 02068C4C */
s16 efff9_txt_point;  /* 02068C4E */
s16 efff9_message;  /* 02068C50 */
s16 keep_mes_no;  /* 02068C52 */
s16 roll_rate;  /* 02068C54 */
s16 roll_rate_t;  /* 02068C56 */
u32 spmv_ng_save;  /* 02068C58 */
s16 pcon_rno[4];  /* 02068C5C */
s16 appear_type;  /* 02068C64 */
u8 round_slow_flag;  /* 02068C66 */
u8 pcon_dp_flag;  /* 02068C67 */
u8 pl_eff_disp_stop;  /* 02068C68 */
u8 pl_eff_disp_stop_tail[1];  /* after pl_eff_disp_stop; nothing refers to it by name or address */
u8 win_sp_flag;  /* 02068C6A */
char dead_voice_flag;  /* 02068C6B */
PLW plw[2];  /* 02068C6C */
SA_WORK super_arts[2];  /* 0206959C */
PiyoriType piyori_type[2];  /* 020695F4 */
ComboType combo_type[2];  /* 0206961C */
ComboType remake_power[2];  /* 0206976C */
ZanzouTableEntry zanzou_table[2][48];  /* 020698BC */
u8 zanzou_table_tail[64];  /* after zanzou_table; nothing refers to it by name or address */
RAMBOD rambod[2];  /* 02069EFC */
RAMHAN ramhan[2];  /* 02069F3C */
s8 stop_count[2];  /* 02069F7C */
u8 stop_count_tail[2];  /* after stop_count; nothing refers to it by name or address */
u16 metamor_original[64];  /* 02069F80 */
u16 metamor_original2[64];  /* 0206A000 */
s16 bcdext;  /* 0206A080 */
SCRLPOS fm_pos[8];  /* 0206A084 */
SCRLPOS scrn_pos[5];  /* 0206A104 */
SCROLL_CTRL scrn_reg_w[4];  /* 0206A154 */
SPRPTR scrn_map_ptr[4];  /* 0206A17C */
u16 scrn_line_prm[4][2];  /* 0206A1BC */
SCRN_MODE scrn_mode_prm[4];  /* 0206A1CC */
u16 Screen_Switch;  /* 0206A1DC */
u16 Screen_Switch_Buffer;  /* 0206A1DE */
u8 Screen_Switch_Req;  /* 0206A1E0 */
u8 Screen_Switch_Req_tail[3];  /* after Screen_Switch_Req; nothing refers to it by name or address */
s16 iotest_out1_flag;  /* 0206A1E4 */
s16 iotest_out2_flag;  /* 0206A1E6 */
s32 iotest_hold_flag;  /* 0206A1E8 */
/* iotest_save_flip: declared 2 bytes; the code reads it on into the variables after it */
u8 iotest_save_flip[1];  /* 0206A1EC */
u8 iotest_save_flip_tail[1];  /* after iotest_save_flip; nothing refers to it by name or address */
u32 scsi_sense_key;  /* 0206A1F0 */
u32 scsi_sense_asc;  /* 0206A1F4 */
s8 scsi_sense_buf[22];  /* 0206A1F8 */
SCSI_INQUIRY scsi_inquiry_data;  /* 0206A20E */
SCSI_CAPACITY scsi_capacity;  /* 0206A234 */
s8 scsi_toc_buf[40];  /* 0206A23C */
s8 cd_sector_buf[2048];  /* 0206A264 */
s32 scsi_error;  /* 0206AA64 */
s16 scsi_cdb_len;  /* 0206AA68 */
u8 scsi_cdb_len_tail[2];  /* after scsi_cdb_len; nothing refers to it by name or address */
COINCHUTE coin_chute1_w;  /* 0206AA6C */
COINCHUTE coin_chute2_w;  /* 0206AA74 */
/* Coin chutes 3 and 4 have the same 8-byte work as chutes 1 and 2 (coin_chute_tbl points at each; the
 * coin test reads them byte by byte); some of their bytes are also named on their own. */
s8 coin_chute3_w[2];  /* 0206AA7C: bytes 0-1 of chute 3 */
u8 coin3_coin_rate;  /* 0206AA7E */
u8 coin3_credit_rate;  /* 0206AA7F */
u8 coin3_credit_rate_tail[2];  /* bytes 4-5 of chute 3 */
u8 coin3_in_flag;  /* 0206AA82 */
u8 coin3_in_flag_tail[1];  /* byte 7 of chute 3 */
s8 coin_chute4_w[2];  /* 0206AA84: bytes 0-1 of chute 4 */
u8 coin4_coin_rate;  /* 0206AA86 */
u8 coin4_credit_rate;  /* 0206AA87 */
u8 coin4_credit_rate_tail[2];  /* bytes 4-5 of chute 4 */
u8 coin4_in_flag;  /* 0206AA8A */
u16 p1sw_0;  /* 0206AA8C */
u16 p1sw_1;  /* 0206AA8E */
u16 p2sw_0;  /* 0206AA90 */
u16 p2sw_1;  /* 0206AA92 */
u16 p3sw_0;  /* 0206AA94 */
u16 p3sw_1;  /* 0206AA96 */
u16 p4sw_0;  /* 0206AA98 */
u16 p4sw_1;  /* 0206AA9A */
u8 syssw_0;  /* 0206AA9C */
u8 syssw_1;  /* 0206AA9D */
u16 exsw_0;  /* 0206AA9E */
u16 exsw_1;  /* 0206AAA0 */
u16 exsw_2;  /* 0206AAA2 */
u16 exsw_3;  /* 0206AAA4 */
u16 exsw_4;  /* 0206AAA6 */
u16 exsw_5;  /* 0206AAA8 */
u16 exsw_6;  /* 0206AAAA */
u16 exsw_7;  /* 0206AAAC */
u16 card_sw_0;  /* 0206AAAE */
u16 card_sw_1;  /* 0206AAB0 */
u16 coin_sw_hist[4];  /* 0206AAB2 */
u16 coin_sw_now[4];  /* 0206AABA */
u8 coin_sw_now_tail[2];  /* after coin_sw_now; nothing refers to it by name or address */
s16 card_out_req;  /* 0206AAC4 */
u16 card_out_busy;  /* 0206AAC6 */
u8 card_out_busy_tail[128];  /* after card_out_busy; nothing refers to it by name or address */
u32 book_coin_count;  /* 0206AB48 */
u32 book_service_count;  /* 0206AB4C */
u32 book_free_count;  /* 0206AB50 */
u32 book_card_count;  /* 0206AB54 */
u16 eep_dummy;  /* 0206AB58 */
u16 eep_strobe_0;  /* 0206AB5A */
u16 eep_strobe_1;  /* 0206AB5C */
u16 eep_strobe_2;  /* 0206AB5E */
u16 eeprom_test_save[64];  /* 0206AB60 */
/* eeprom_w: declared 128 bytes; the code reads it on into the variables after it */
u8 eeprom_w[6];  /* 0206ABE0 */
u8 eeprom_saved_flip;  /* 0206ABE6 */
u8 eeprom_saved_flip_tail[25];  /* after eeprom_saved_flip; nothing refers to it by name or address */
u8 eeprom_game_cfg[16];  /* 0206AC00 */
u8 eeprom_backup_cfg[80];  /* 0206AC10 */
s16 eeprom_retry;  /* 0206AC60 */
SETTINGS Game_setting;  /* 0206AC62 */
u8 Game_setting_tail[2];  /* after Game_setting; nothing refers to it by name or address */
s8 cfg_top_cursor;  /* 0206AC74 */
s8 cfg_coin;  /* 0206AC75 */
s8 cfg_continue;  /* 0206AC76 */
s8 cfg_chute;  /* 0206AC77 */
s8 cfg_sound_mode;  /* 0206AC78 */
s8 cfg_demo_sound;  /* 0206AC79 */
s8 cfg_flip_old;  /* 0206AC7A */
s8 cfg_free_play;  /* 0206AC7B */
s8 cfg_coin_special;  /* 0206AC7C */
s8 cfg_cont_forced;  /* 0206AC7D */
s8 cfg_changed;  /* 0206AC7E */
s8 cfg_voice;  /* 0206AC7F */
s8 cfg_dispenser;  /* 0206AC80 */
s8 cfg_win_point;  /* 0206AC81 */
s8 cfg_win_point_vs;  /* 0206AC82 */
s8 cfg_extra;  /* 0206AC83 */
u8 cfg_extra_tail[1];  /* after cfg_extra; nothing refers to it by name or address */
s8 cfg_cursor;  /* 0206AC85 */
s8 cfg_cursor_old;  /* 0206AC86 */
s8 cfg_coin_step;  /* 0206AC87 */
s8 cfg_coin_sel;  /* 0206AC88 */
s8 cfg_reserve;  /* 0206AC89 */
s32 cfg_item_max;  /* 0206AC8C */
s32 frame_ready;  /* 0206AC90 */
SPRITE_ENTRY spr_entry_a[512];  /* 0206AC94 */
SPRITE_ENTRY spr_entry_b[512];  /* 0206D494 */
SPRITE_ENTRY * spr_prio_a[0x80];  /* 0206FC94 */
SPRITE_ENTRY * spr_prio_b[0x80];  /* 0206FE94 */
u16 spr_cnt0_a;  /* 02070094 */
u16 spr_cnt0_b;  /* 02070096 */
u16 spr_cnt1_a;  /* 02070098 */
u16 spr_cnt1_b;  /* 0207009A */
u16 spr_cnt2_a;  /* 0207009C */
u16 spr_cnt2_b;  /* 0207009E */
u16 spr_cnt3_a;  /* 020700A0 */
u16 spr_cnt3_b;  /* 020700A2 */
u16 spr_cnt4_a;  /* 020700A4 */
u16 spr_cnt4_b;  /* 020700A6 */
u8 spr_bank;  /* 020700A8 */
s8 spr_list_ready;  /* 020700A9 */
u8 spr_list_ready_tail[2];  /* after spr_list_ready; nothing refers to it by name or address */
s16 simm40_owner[3970];  /* 020700AC */
s16 simm40_link[1986];  /* 02071FB0 */
s16 simm40_used[64];  /* 02072F34 */
s16 simm10_owner[4098];  /* 02072FB4 */
s16 simm10_link[2050];  /* 02074FB8 */
s16 simm10_used[64];  /* 02075FBC */
s32 poly_dma_state;  /* 0207603C */
s16 poly_reserve0;  /* 02076040 */
s16 poly_reserve1;  /* 02076042 */
POLY_LINE poly_line_buf[2][0x155];  /* 02076044 */
u32 poly_line_cnt[2];  /* 0207803C */
u32 poly_line_rd[2];  /* 02078044 */
POLYCMD poly_quad_buf[2][32];  /* 0207804C */
u32 poly_quad_cnt[2];  /* 0207844C */
u32 poly_quad_rd[2];  /* 02078454 */
u32 poly_order_pos[2];  /* 0207845C */
u16 poly_order_kind[2][0x175];  /* 02078464 */
s32 poly_wr_bank;  /* 02078A38 */
s32 poly_rd_bank;  /* 02078A3C */
SPRITE_LIST sprite_list_w[4];  /* 02078A40 */
u16 num_font_code;  /* 02078CE0 */
u32 palette_base;  /* 02078CE4 */
const u16 * snd_attack_ptr;  /* 02078CE8 */
const u16 * snd_decay_ptr;  /* 02078CEC */
const u16 * snd_lfo_rate_ptr;  /* 02078CF0 */
const u16 * snd_pitch_lfo_ptr;  /* 02078CF4 */
const u16 * snd_vol_lfo_ptr;  /* 02078CF8 */
SNDSAMPLE * snd_sample_tbl;  /* 02078CFC */
u8 ** snd_bank_tbl;  /* 02078D00 */
u32 snd_fade_level;  /* 02078D04 */
u32 snd_fade_speed;  /* 02078D08 */
SNDVOICE bgm_voice[16];  /* 02078D0C */
SNDVOICE se_voice[16];  /* 0207944C */
SNDRAMP se_pan_ramp[16];  /* 02079B8C */
s16 voice_state_init_pair_work;  /* 02079C0C */
u16 snd_wave_bias;  /* 02079C0E */
SOUND_CTRL snd_ctrl;  /* 02079C10 */
u32 bgm_tick_step;  /* 02079C14 */
u32 se_tick_step[16];  /* 02079C18 */
s8 sound_sample_submit_work4;  /* 02079C58 */
u8 bgm_master_vol;  /* 02079C59 */
u8 snd_master_vol;  /* 02079C5A */
u8 snd_stereo;  /* 02079C5B */
u8 gSeqStatus[1];  /* 02079C5C */
u8 gSeqStatus_tail[15];  /* after gSeqStatus; nothing refers to it by name or address */
u32 * snd_seq_data;  /* 02079C6C */
SNDRAMP se_ramp_req;  /* 02079C70 */
u16 snd_reg_save;  /* 02079C78 */
u16 snd_seq_max;  /* 02079C7A */
u8 bgm_status_save[16];  /* 02079C7C */
u8 sound_sample_submit_work7;  /* 02079C8C */
u8 sound_sample_submit_work7_tail[1];  /* after sound_sample_submit_work7; nothing refers to it by name or address */
u8 bgm_master_vol_init;  /* 02079C8E */
s32 errno;  /* 02079C90 */
s16 cram_bank_old;  /* 02079C94 */
s16 cram_bank_now;  /* 02079C96 */

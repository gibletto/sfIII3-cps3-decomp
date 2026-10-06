/*
 * END_SUB_6.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads (part 6)
 *
 * Routines: debug_play10, debug_play10_init, debug_play10_move.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Com_Pl.h"
#include "SYS_sub.h"
#include "VITAL.h"
#include "count.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFFH3.h"
#include "effh4.h"
#include "effh5.h"
#include "effh6_code.h"
#include "plcntdat_2.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Manage.h"
#include "manage_2.h"
#include "EFFM7.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "HITCHECK.h"
#include "cmb_cont.h"
#include "SLOWF.h"
#include "Entry.h"
#include "entry_2.h"
#include "meta_col.h"
#include "meta_col_mem.h"
#include "meta_col_strcpy.h"
#include "meta_col_lib.h"
#include "meta_col_bcd.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "fifo.h"
#include "ta_sub2.h"
#include "tate00.h"
#include "ta_sub.h"
#include "end_sub.h"
#include "end_sub_6.h"
#include "cps3.h"

#pragma inline(card_pl_work_clear)



/* provisional name */
void debug_play10(void) {
    void (*jmp_tbl[2])() = { debug_play10_init, debug_play10_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play10_init(void) {
    tilemap_fill_all(0, 0x20);
    G_No2++;
    System_all_clear_Wait();
    Play_Type = 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    My_char[0] = 2;
    My_char[1] = 2;
    vital_cont_init();
    combo_cont_init();
    count_cont_init(0);
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);
    C_No0 = 0;
    Game_timer = 0;
    Game_pause = 0;
    Round_num = 0;
    Allow_a_battle_f = 0;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    appear_type = 0;
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    bg_w.stage = 13;
    bg_w.area = 0;
    TATE00();
}

/* provisional name */
void debug_play10_move(void)
{
    round_timer.timer = 0x990000;
    Game_timer++;
    set_EXE_flag();
    Player_control();
    TATE00();
    Game_Management();
    hit_check_main_process();
}

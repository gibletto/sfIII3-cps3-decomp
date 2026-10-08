/*
 * END_SUB_7B.C  Ending support: prize cards, CD checks, staff roll, debug fights and colour loads (part 7b)
 *
 * Routines: debug_play12, debug_play12_init, debug_play12_move, debug_play12_dummy.
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
#include "color3rd.h"
#include "cps3.h"

/* provisional name */
void debug_play12(void) {
    void (*jmp_tbl[2])() = { debug_play12_init, debug_play12_move };
    jmp_tbl[G_No2]();
}



/* provisional name */
void debug_play12_init(void) {
    G_No2++;
    dbg_play12_w[0] = dbg_play12_w[1] = dbg_play12_w[2] = dbg_play12_w[3] = 0;
    effect_work_quick_init();
    bg_work_clear();
}



/* provisional name */
void debug_play12_move(void) { hit_check_main_process(); }


/* provisional name */
void debug_play12_dummy(void) {}

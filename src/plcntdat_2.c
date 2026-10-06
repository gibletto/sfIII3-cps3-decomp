/*
 * PLCNTDAT_2.C  Player base data, stun and super-art setup, round resets (part 2)
 *
 * Routines: clear_super_arts_point, check_combo_end, set_scrrrl.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub.h"
#include "end_sub.h"
#include "end_sub_2.h"
#include "end_sub_3.h"
#include "end_sub_4.h"
#include "end_sub_5.h"
#include "end_sub_6.h"
#include "end_sub_7.h"
#include "color3rd.h"
#include "end_sub_8.h"
#include "sc_trans.h"
#include "VITAL.h"
#include "count.h"
#include "spgauge.h"
#include "EFF02.h"
#include "EFF00.h"
#include "EFFK5.h"
#include "effM5.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "EFFE5.h"
#include "EFFJ7.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "CHARID.h"
#include "plcntdat_2.h"
#include "fighter.h"



void clear_super_arts_point(PLW* wk) {
    wk->sa->gauge.s.h = 0;
    wk->sa->gauge.s.l = -1;
    wk->sa->mp_rno = 0;
    wk->sa->sa_rno = 0;
    wk->sa->ex_rno = 0;
    wk->sa->mp = 0;
    wk->sa->ok = 0;
    wk->sa->ex = 0;
}



s32 check_combo_end(s16 ix) {
    s16 rnum;
    if (plw[ix].py->flag) {
        return 1;
    }
    if (plw[ix].tsukamare_f) {
        return 1;
    }
    if (pcon_rno[0] == 2 && pcon_rno[1] == 0 && pcon_rno[2] == 2) {
        return 0;
    }
    if (plw[ix].wu.cg_ja.boix == 0 && plw[ix].wu.cg_ja.cuix == 0 && plw[ix].wu.pat_status == 38) {
        return 0;
    }
    if (plw[ix].zuru_flag) {
        return 0;
    }
    if (plw[ix].wu.routine_no[1] != 1 && plw[ix].wu.routine_no[1] != 3) {
        return 0;
    }
    if (plw[ix].old_gdflag != plw[ix].guard_flag) {
        if (plw[ix].guard_flag == 0) {
            rnum = 0;
        } else {
            rnum = 1;
        }
    } else if (plw[ix].guard_flag == 0) {
        rnum = 0;
    } else {
        rnum = 1;
    }
    return rnum;
}

void set_scrrrl(void)
{
    s16 center;
    center = get_center_position();
    scrr = center + 192;
    scrl = center - 192;
}

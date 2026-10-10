/*
 * SC_SUB_3.C  Stun gauge control and drawing
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
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
#include "sc_sub_2.h"
#include "cps3.h"

void stun_mark_put(s8 pl);



void stngauge_cont_init(void) {
    sdat[0].cstn = 0;
    sdat[0].ostn = 0;
    sdat[0].stncol_number = 20;
    sdat[0].stntbl_ptr = stngauge_puttbl[0];
    sdat[0].sflag = 0;
    sdat[0].osflag = 0;
    sdat[0].g_or_s = 0;
    sdat[0].stimer = 2;
    sdat[0].slen = piyori_type[0].genkai / 8;
    sdat[0].dotlen = piyori_type[0].genkai;
    sdat[0].proccess_dead = 0;
    sdat[1].cstn = 0;
    sdat[1].ostn = 0;
    sdat[1].stncol_number = 0x94;
    sdat[1].stntbl_ptr = stngauge_puttbl[0];
    sdat[1].sflag = 0;
    sdat[1].osflag = 0;
    sdat[1].g_or_s = 0;
    sdat[1].stimer = 2;
    sdat[1].slen = piyori_type[1].genkai / 8;
    sdat[1].dotlen = piyori_type[1].genkai;
    sdat[1].proccess_dead = 0;
    sdat[0].stnptbl_ptr = stngauge_postbl[0];
    sdat[1].stnptbl_ptr = stngauge_postbl[1];
    stun_gauge_waku_write(0);
    stun_gauge_waku_write(1);
    stun_mark_write(0, 0);
    stun_mark_write(1, 1);
}



void stngauge_cont_main(void) {
    if (!EXE_flag) {
        if (((s16)gauge_stop_flag[0]) == 0) {
            stngauge_control(0);
        }
        if (((s16)gauge_stop_flag[1]) == 0) {
            stngauge_control(1);
        }
    }
}



void stngauge_control(s32 player) {
    s8 pl = player;
    STN_DAT* g = &sdat[pl];
    PLW* wk = &plw[pl];
    if (Exec_Wipe) {
        g->cstn = wk->py->now.quantity.h;
        return;
    }
    if (g->proccess_dead) {
        return;
    }
    if (wk->dead_flag) {
        g->proccess_dead = 1;
        g->cstn = 0;
        stun_put(pl);
        return;
    }
    if ((wk->wu.routine_no[1] == 1 && wk->wu.routine_no[2] == 25 && wk->wu.routine_no[3] != 0) ||
        wk->py->flag == 1) {
        g->sflag = 1;
        if (g->osflag == 0) {
            sdat[pl].cstn = stun_genkai_tbl[My_char[pl] & 0x7F];
        }
        sdat[pl].stimer--;
        if (sdat[pl].g_or_s == 0) {
            if (sdat[pl].stimer == 0) {
                stun_mark_put(pl);
                sdat[pl].g_or_s = 1;
                sdat[pl].stimer = 2;
            }
        } else if (sdat[pl].stimer == 0) {
            stun_put(pl);
            sdat[pl].g_or_s = 0;
            sdat[pl].stimer = 2;
        }
        sdat[pl].osflag = sdat[pl].sflag;
        return;
    }
    g->sflag = 0;
    if (g->osflag == 1) {
        sdat[pl].osflag = sdat[pl].sflag;
        sdat[pl].g_or_s = 0;
        sdat[pl].stimer = 2;
        sdat[pl].cstn = wk->py->now.quantity.h;
        sdat[pl].osflag = sdat[pl].sflag;
        stun_put(pl);
        return;
    }
    if (sdat[pl].cstn != plw[pl].py->now.quantity.h) {
        sdat[pl].cstn = plw[pl].py->now.quantity.h;
        stun_put(pl);
    }
}



void stun_put(pl)
s8 pl;
{
    s8 i;
    stn_work = 0;
    stn_number = 0;
    for (i = 0; i < sdat[pl].slen; i++) {
        stn_work += 8;
        if (stn_work >= sdat[pl].cstn) {
            if (sdat[pl].cstn >= stn_work - 8) {
                stn_offset = sdat[pl].cstn - i * 8;
                tilemap_put_cell(sdat[pl].stnptbl_ptr[stn_number], 3, sdat[pl].stncol_number, sdat[pl].stntbl_ptr[stn_offset]);
            } else {
                tilemap_put_cell(sdat[pl].stnptbl_ptr[stn_number], 3, sdat[pl].stncol_number, sdat[pl].stntbl_ptr[0]);
            }
        } else {
            tilemap_put_cell(sdat[pl].stnptbl_ptr[stn_number], 3, sdat[pl].stncol_number, sdat[pl].stntbl_ptr[8]);
        }
        stn_number++;
    }
}



void stun_mark_write(s8 pl, s8 kind) {
    const u16* cells;
    s16 attr;
    PiyoriType* pt;
    STN_DAT* g;
    s8 i;
    stn_work = 0;
    stn_number = 0;
    if (pl == 1 && kind == 0) {
        ToneDown(7);
    }
    attr = 20;
    if (kind == 2) {
        cells = stngauge_puttbl[1];
    } else {
        cells = stngauge_puttbl[pl - kind];
    }
    if (kind == 1 && pl == 1) {
        attr = 148;
    }
    pt = &piyori_type[pl];
    g = &sdat[pl];
    for (i = 0; i < pt->genkai / 8; i++) {
        stn_work += 8;
        if (stn_work >= g->cstn) {
            if (g->cstn >= stn_work - 8) {
                stn_offset = g->cstn - i * 8;
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[stn_offset]);
            } else {
                tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[0]);
            }
        } else {
            tilemap_put_cell(g->stnptbl_ptr[stn_number], 3, attr, cells[8]);
        }
        stn_number++;
    }
}



void stun_gauge_waku_write(s8 pl) {
    s8 i;
    if (pl == 0) {
        for (i = 0; i < 9 - sdat[0].slen; i++) {
            tilemap_put_cell(i + 11, 3, 2, 63);
        }
        tilemap_put_cell(i + 11, 3, 2, 110);
    } else {
        for (i = 0; i < 9 - sdat[1].slen; i++) {
            tilemap_put_cell(36 - i, 3, 2, 63);
        }
        tilemap_put_cell(36 - i, 3, 130, 110);
    }
}



void stngauge_work_clear(void) {
    sdat[0].cstn = 0;
    sdat[0].ostn = 0;
    sdat[0].sflag = 0;
    sdat[0].osflag = 0;
    sdat[0].g_or_s = 0;
    sdat[0].stimer = 2;
    sdat[0].proccess_dead = 0;
    stun_mark_write(0, 0);
    sdat[1].cstn = 0;
    sdat[1].ostn = 0;
    sdat[1].sflag = 0;
    sdat[1].osflag = 0;
    sdat[1].g_or_s = 0;
    sdat[1].stimer = 2;
    sdat[1].proccess_dead = 0;
    stun_mark_write(1, 1);
}

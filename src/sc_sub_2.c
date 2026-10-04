/*
 * SC_SUB_2.C  HUD win marks, palette fade control and stun gauge (part 2)
 *
 * Routines: fade_cont_init, fade_cont_main, stngauge_cont_init, stngauge_cont_main,
 * stngauge_control, stun_put, stun_mark_write, stun_gauge_waku_write, stngauge_work_clear.
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



void fade_cont_init(void) {
    const s16* tbl;
    const s16* dat;
    FADE_LAYER* fw;
    s32 i;
    s8 num;
    s32 no;
    fade_layer_num = 0;
    fade_cont_rno = 0;
    fade_end_timer = 1;
    no = Fade_Number;
    tbl = fade_data_tbl[no];
    fade_layer_num = num = *tbl++;
    for (i = 0; i < num; i++) {
        fw = &fade_layer[i];
        fw->adrs = fade_adrs_tbl[tbl[0]];
        fw->cur = fw->adrs;
        dat = fade_param_tbl[tbl[1]];
        fw->v8 = dat[0];
        fw->v10 = dat[1];
        fw->v12 = fw->v10;
        fw->v14 = fw->v10;
        fw->v16 = dat[2];
        fw->kind = dat[3];
        fw->v20 = dat[4];
        fw->v22 = fw->v20;
        fw->v24 = dat[5];
        fw->on = 1;
        switch (fw->kind) {
        case 0:
        case 1:
            fade_layer[i].step = 64;
            break;
        case 2:
        case 3:
            fade_layer[i].step = 96;
            break;
        }
        tbl += 2;
    }
}

s32 fade_cont_main(void)
{
    FADE_LAYER *fl;
    s32 rv;
    u16 j;
    s32 i;
    s8 done;

    rv = fade_cont_rno;
    if (rv == 0) {
        for (i = 0; i < fade_layer_num; i++) {
            fl = &fade_layer[i];
            if (fl->on == 0) {
                continue;
            }
            if (--fl->v20 != 0) {
                continue;
            }
            fl->v20 = fl->v22;
            for (j = 0; j < fl->v8; j++) {
                load_any_color_req(*(u32 *)fl->adrs, fl->v10 + fl->step, fl->v12 + fl->step, fl->v14 + fl->step);
                fl->adrs += 4;
            }
            if (fl->v10 == fl->v16) {
                fl->on = 0;
                continue;
            }
            fl->adrs = fl->cur;
            fl->v10 += fl->v24;
            fl->v12 = fl->v10;
            fl->v14 = fl->v10;
            switch (fl->kind) {
            case 0:
            case 2:
                if (fl->v10 < fl->v16) {
                    fl->v10 = fl->v16;
                    fl->v12 = fl->v10;
                    fl->v14 = fl->v10;
                }
                break;
            case 1:
            case 3:
                if (fl->v16 < fl->v10) {
                    fl->v10 = fl->v16;
                    fl->v12 = fl->v10;
                    fl->v14 = fl->v10;
                }
                break;
            }
            continue;
        }
        done = 0;
        for (i = 0; i < fade_layer_num; i++) {
            rv = 26; /* the value returned when no layer is fading: offset of .on in the layer record */
            if (fade_layer[i].on == 0) {
                done++;
            }
        }
        if (done == (u8)fade_layer_num) {
            fade_cont_rno = 1;
        }
    } else if (rv == 1) {
        if (--fade_end_timer == 0) {
            Fade_Flag = 0;
            Fade_Mode = 0;
        }
    }
    return rv;
}



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
    STN_DAT* sd = &sdat[pl];
    PLW* wk = &plw[pl];
    if (Exec_Wipe) {
        sd->cstn = wk->py->now.quantity.h;
        return;
    }
    if (sd->proccess_dead) {
        return;
    }
    if (wk->dead_flag) {
        sd->proccess_dead = 1;
        sd->cstn = 0;
        stun_put(pl);
        return;
    }
    if ((wk->wu.routine_no[1] == 1 && wk->wu.routine_no[2] == 25 && wk->wu.routine_no[3] != 0) ||
        wk->py->flag == 1) {
        sd->sflag = 1;
        if (sd->osflag == 0) {
            sd->cstn = stun_genkai_tbl[My_char[pl] & 0x7F];
        }
        sd->stimer--;
        if (sd->g_or_s == 0) {
            if (sd->stimer == 0) {
                stun_mark_put(pl);
                sd->g_or_s = 1;
                sd->stimer = 2;
            }
        } else if (sd->stimer == 0) {
            stun_put(pl);
            sd->g_or_s = 0;
            sd->stimer = 2;
        }
        sd->osflag = sd->sflag;
        return;
    }
    sd->sflag = 0;
    if (sd->osflag == 1) {
        sd->osflag = sd->sflag;
        sd->g_or_s = 0;
        sd->stimer = 2;
        sd->cstn = wk->py->now.quantity.h;
        sd->osflag = sd->sflag;
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

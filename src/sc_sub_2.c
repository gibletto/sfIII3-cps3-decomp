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

void stun_mark_put(s8 pl);



void fade_cont_init(void) {
    const s16* tbl;
    const s16* dat;
    s8 i;
    s8 num;
    fade_layer_num = 0;
    fade_cont_rno = 0;
    fade_end_timer = 1;
    tbl = fade_data_tbl[Fade_Number];
    fade_layer_num = num = *tbl++;
    for (i = 0; i < num; i++) {
        fade_layer[i].adrs = fade_adrs_tbl[tbl[0]];
        fade_layer[i].cur = fade_layer[i].adrs;
        dat = fade_param_tbl[tbl[1]];
        fade_layer[i].v8 = dat[0];
        fade_layer[i].v10 = dat[1];
        fade_layer[i].v12 = fade_layer[i].v10;
        fade_layer[i].v14 = fade_layer[i].v10;
        fade_layer[i].v16 = dat[2];
        fade_layer[i].kind = dat[3];
        fade_layer[i].v20 = dat[4];
        fade_layer[i].v22 = fade_layer[i].v20;
        fade_layer[i].v24 = dat[5];
        fade_layer[i].on = 1;
        switch (fade_layer[i].kind) {
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
    u16 j;
    s8 i;
    s8 done;
    FADE_LAYER* fl;

    switch (fade_cont_rno) {
    case 0:
        for (i = 0; i < fade_layer_num; i++) {
            if (fade_layer[i].on) {
                fade_layer[i].v20--;
                if (fade_layer[i].v20 == 0) {
                    fade_layer[i].v20 = fade_layer[i].v22;
                    fl = &fade_layer[i];
                    for (j = 0; j < fl->v8; j++) {
                        load_any_color_req(*(u32 *)fl->adrs, fl->v10 + fl->step, fl->v12 + fl->step, fl->v14 + fl->step);
                        fl->adrs += 4;
                    }
                    (void)fl->on;
                    if (fade_layer[i].v10 == fade_layer[i].v16) {
                        fade_layer[i].on = 0;
                    } else {
                        fade_layer[i].adrs = fade_layer[i].cur;
                        fade_layer[i].v10 += fade_layer[i].v24;
                        fade_layer[i].v12 = fade_layer[i].v10;
                        fade_layer[i].v14 = fade_layer[i].v10;
                        switch (fade_layer[i].kind) {
                        case 0:
                        case 2:
                            if (fade_layer[i].v10 < fade_layer[i].v16) {
                                (void)fl->on;
                                fl = &fade_layer[i];
                                fl->v10 = fl->v16;
                                fl->v12 = fl->v10;
                                fl->v14 = fl->v10;
                            }
                            break;
                        case 1:
                        case 3:
                            fl = &fade_layer[i];
                            if (fl->v10 > fl->v16) {
                                fl = &fade_layer[i];
                                fl->v10 = fl->v16;
                                fl->v12 = fl->v10;
                                fl->v14 = fl->v10;
                            }
                            break;
                        }
                    }
                }
            }
        }
        done = 0;
        for (i = 0; i < fade_layer_num; i++) {
            if (fade_layer[i].on == 0) {
                done++;
            }
        }
        if (done == fade_layer_num) {
            fade_cont_rno = 1;
        }
        break;
    case 1:
        fade_end_timer--;
        if (fade_end_timer == 0) {
            Fade_Flag = 0;
            Fade_Mode = 0;
        }
        break;
    }
}

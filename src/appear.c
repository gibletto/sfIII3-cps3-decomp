/*
 * APPEAR.C  Fighter entrance (appearance) sequences
 *
 * Runs each fighter's entrance at the start of a match.
 * appear_data_init_set chooses the entrance type from app_type_tbl (or app_type_tbl2
 * for a home/visitor rematch decided by home_visitor_check) by fighter, opponent and stage,
 * and loads its APPEAR_DATA. appear_player then dispatches on routine_no[4] to one of about
 * forty routines Appear_00000-Appear_39000: walk-ins, jumps and drops, poses, vehicles
 * (effect M5), props (effects 97, 09, 15, 46, 86, C5, C8, M1) and stage animals
 * (animal_decide / effect_M0_init). Special match-ups have their own checks (Yun/Yang, Sean,
 * Gill, don_appear_check). Appear_flag, Appear_free and Appear_end signal the stage and the
 * game flow; appear_work_clear resets them. Driven from the player routines (PLMAIN, PLPNM)
 * and Manage.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "win_pl.h"
#include "EFF86.h"
#include "EFFC8.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "PLS02.h"
#include "ta_sub.h"
#include "CALDIR.h"
#include "charmove_2.h"
#include "EFF09.h"
#include "EFF15.h"
#include "EFF46.h"
#include "eff97.h"
#include "EFFC5.h"
#include "EFFM1.h"
#include "effM5.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "EFFM7.h"
#include "EFF30.h"
#include "EFF31.h"
#include "EFF32.h"
#include "EFF82.h"
#include "EFF83.h"
#include "effL3.h"
#include "EFFL4.h"
#include "effl5.h"
#include "effl6.h"
#include "EFFM2.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "lose_pl.h"
#include "sys_test.h"
#include "sys_test_2.h"
#include "sys_test_2b.h"
#include "sys_test_2c.h"
#include "sys_test_3.h"
#include "sys_test_4.h"
#include "sys_test_5.h"
#include "aboutspr.h"
#include "SYS_sub.h"
#include "sc_trans.h"
#include "fifo.h"
#include "eff36.h"
#include "EFF48.h"
#include "EFFC1.h"
#include "efff6.h"
#include "end_main.h"
#include "sys_config.h"
#include "sys_config_2.h"
#include "sys_config_3.h"
#include "Com_Pl.h"
#include "appear.h"
#include "fighter.h"

/* routine_no[3], Appear_01000 */
#define AP01_WAIT       1       /* until Appear_flag */
#define AP01_NEXT       2       /* start the next animation */
#define AP01_END        3       /* run the animation to its end */

/* routine_no[3], Appear_03000 */
#define AP03_END        1       /* run the animation to its end */

/* routine_no[3], Appear_04000 */
#define AP04_CUE        1       /* run the animation to cue 9 */
#define AP04_NEXT       2       /* start the next animation */
#define AP04_END        3       /* run the animation to its end */

/* routine_no[3], Appear_05000 */
#define AP05_WAIT       1       /* count down appear_work */
#define AP05_NEXT       2       /* start the next animation */
#define AP05_CUE        3       /* run the animation to cue 9 */
#define AP05_END        4       /* run the animation to its end */

/* routine_no[3], Appear_06000 */
#define AP06_WAIT       1       /* until demo_car_flag */
#define AP06_NEXT       2       /* start the next animation */
#define AP06_NEXT2      3       /* start the next animation */
#define AP06_END        4       /* run the animation to its end */

/* routine_no[3], Appear_07000 */
#define AP07_WAIT       1       /* until Appear_flag != 0 */
#define AP07_CUE        2       /* run the animation to cue 9 */
#define AP07_AIR        3       /* in the air until it lands (falls through) */
#define AP07_AIR2       4       /* in the air until it lands */
#define AP07_END        5       /* run the animation to its end */

/* routine_no[3], Appear_08000 */
#define AP08_END        1       /* run the animation to its end */

/* routine_no[3], Appear_09000 */
#define AP09_END        1       /* run the animation to its end */
#define AP09_NEXT       2       /* start the next animation */
#define AP09_NEXT2      3       /* start the next animation */
#define AP09_END2       4       /* run the animation to its end */

/* routine_no[3], Appear_10000 */
#define AP10_NEXT       1       /* start the next animation */
#define AP10_END        2       /* run the animation to its end */

/* routine_no[3], Appear_11000 */
#define AP11_WAIT       1       /* count down app_counter */

/* routine_no[3], Appear_12000 */
#define AP12_NEXT       1       /* start the next animation */
#define AP12_END        2       /* run the animation to its end */

/* routine_no[3], Appear_13000 */
#define AP13_WAIT       1       /* until bg_land_flag */
#define AP13_NEXT       2       /* start the next animation */
#define AP13_END        3       /* run the animation to its end */

/* routine_no[3], Appear_14000 */
#define AP14_END        1       /* run the animation to its end */

/* routine_no[3], Appear_15000 */
#define AP15_END        1       /* run the animation to its end, with sounds at cues 2 and 3 */

/* routine_no[3], Appear_16000 */
#define AP16_END        1       /* run the animation to its end */

/* routine_no[3], Appear_17000 */
#define AP17_WAIT       1       /* until bg_app */
#define AP17_CUE        2       /* run the animation to cue 2 */
#define AP17_END        3       /* run the animation to its end */

/* routine_no[3], Appear_18000 */
#define AP18_CUE        1       /* run the animation to cue 9 */
#define AP18_WAIT       2       /* count down appear_work */
#define AP18_END        3       /* run the animation to its end */

/* routine_no[3], Appear_19000 */
#define AP19_NEXT       1       /* start the next animation */
#define AP19_NEXT2      2       /* start the next animation */
#define AP19_END        3       /* run the animation to its end */

/* routine_no[3], Appear_20000 */
#define AP20_END        1       /* run the animation to its end */

/* routine_no[3], Appear_21000 */
#define AP21_END        1       /* run the animation to its end */

/* routine_no[3], Appear_22000 */
#define AP22_NEXT       1       /* start the next animation */
#define AP22_END        2       /* run the animation to its end */

/* routine_no[3], Appear_23000 */
#define AP23_NEXT       1       /* start the next animation */
#define AP23_END        2       /* run the animation to its end */

/* routine_no[3], Appear_26000 */
#define AP26_WAIT       1       /* count down appear_work */
#define AP26_AIR        2       /* in the air until it lands */
#define AP26_RUN        3       /* run the animation */
#define AP26_NEXT       4       /* start the next animation */
#define AP26_CUE        5       /* run the animation to cue 9 */
#define AP26_END        6       /* run the animation to its end */

/* routine_no[3], Appear_28000 */
#define AP28_WAIT       1       /* until Appear_car_stop[id_w] */
#define AP28_CUE        2       /* run the animation to cue 9 */
#define AP28_WAIT2      3       /* until plw[id_w].wu.routine_no[3] >= 3 */
#define AP28_NEXT       4       /* start the next animation */
#define AP28_END        5       /* run the animation to its end */

/* routine_no[3], Appear_29000 */
#define AP29_WAIT       1       /* wait for cmwk[1], then start the entry cmwk[2] chose */
#define AP29_MOVE       2       /* move and run the animation */
#define AP29_END        3       /* run the animation to its end */
#define AP29_NEXT       4       /* start the next animation */
#define AP29_END2       5       /* run the animation to its end */

/* routine_no[3], Appear_30000 */
#define AP30_END        1       /* run the animation to its end */

/* routine_no[3], Appear_31000 */
#define AP31_END        1       /* run the animation to its end */

/* routine_no[3], Appear_32000 */
#define AP32_END        1       /* run the animation to its end */

/* routine_no[3], Appear_33000 */
#define AP33_NEXT       1       /* start the next animation */
#define AP33_END        2       /* run the animation to its end */

/* routine_no[3], Appear_36000 */
#define AP36_NEXT       1       /* start the next animation */
#define AP36_WAIT       2       /* count down app_counter */
#define AP36_NEXT2      3       /* start the next animation */
#define AP36_END        4       /* run the animation to its end */

/* routine_no[3], Appear_37000 */
#define AP37_END        1       /* run the animation to its end */
#define AP37_NEXT       2       /* start the next animation */
#define AP37_NEXT2      3       /* start the next animation */
#define AP37_CUE        4       /* run the animation to cue 9 */
#define AP37_NEXT3      5       /* start the next animation */
#define AP37_WAIT       6       /* count down app_counter */

/* routine_no[3], Appear_38000 */
#define AP38_END        1       /* run the animation to its end */

/* routine_no[3], Appear_39000 */
#define AP39_MOVE       1       /* move and run the animation */
#define AP39_DONE       2       /* the entry is over: stand */

/* routine_no[3], Appear_41000 */
#define AP41_WAIT       1       /* count down app_counter */




s16 Appear_end;  /* 02028194 */
s16 appear_work[2];  /* 02028196 */
s8 Appear_flag[2];  /* 0202819A */
s8 Appear_free[2];  /* 0202819C */
s8 Appear_hv[2];  /* 0202819E */
s8 Appear_car_stop[2];  /* 020281A0 */
s16 app_counter[2];  /* 020281A2 */


void appear_work_clear(void) {
    Appear_end = 0;
    Appear_flag[0] = 0;
    Appear_flag[1] = 0;
    Appear_free[0] = 0;
    Appear_free[1] = 0;
    bg_stop = 0;
    bg_app_stop = 0;
}



s32 home_visitor_check(PLW* wk) {
    s32 hv_type;
    s32 pl_num;
    s16 num;
    hv_type = 0;
    if (wk->wu.id) {
        num = plw[0].player_number;
    } else {
        num = plw[1].player_number;
    }
    if (pl_num = num, Play_Type) {
        if (Champion == wk->wu.id && wk->player_number == pl_num && pl_num != PL_ELENA) {
            hv_type = 1;
        }
    } else {
        if (wk->wu.operator && wk->player_number == pl_num && pl_num != PL_ELENA) {
            hv_type = 1;
        }
    }
    return hv_type;
}

void appear_data_set(PLW* wk, const APPEAR_DATA* dtbl) {
    if (wk->wu.id) {
        if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - dtbl->whx;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - dtbl->hx;
        }
        wk->wu.xyz[1].disp.pos = dtbl->hy;
        wk->wu.rl_flag = (dtbl->rl + 1) & 1;
        wk->wu.routine_no[4] = dtbl->rno;
        Appear_flag[0] = dtbl->ixod;
        wk->wu.char_index = dtbl->char_index;
    } else {
        if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + dtbl->whx;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + dtbl->hx;
        }
        wk->wu.xyz[1].disp.pos = dtbl->hy;
        wk->wu.rl_flag = dtbl->rl;
        wk->wu.routine_no[4] = dtbl->rno;
        Appear_flag[1] = dtbl->ixod;
        wk->wu.char_index = dtbl->char_index;
    }
}



void appear_data_init_set(PLW* wk) {
    const APPEAR_DATA* dtbl;
    s8 ap_work;
    s16 id_work;
    Appear_hv[wk->wu.id] = home_visitor_check(wk);
    id_work = wk->wu.id ^ 1;
    if (bg_w.area) {
        ap_work = 0;
    } else if (Appear_hv[wk->wu.id]) {
        ap_work = app_type_tbl2[wk->player_number][plw[id_work].player_number][bg_w.stage];
    } else {
        ap_work = app_type_tbl[wk->player_number][plw[id_work].player_number][bg_w.stage];
    }
    dtbl = &appear_data[ap_work];
    appear_data_set(wk, dtbl);
}



void appear_player(PLW* wk) {
    void (*appear_jmp_tbl[42])(
        PLW* wk) = { Appear_00000, Appear_01000, Appear_01000, Appear_03000, Appear_04000, Appear_05000, Appear_06000, Appear_07000, Appear_08000, Appear_09000, Appear_10000, Appear_11000, Appear_12000, Appear_13000, Appear_14000, Appear_15000, Appear_16000, Appear_17000, Appear_18000, Appear_19000, Appear_20000, Appear_21000, Appear_22000, Appear_23000, Appear_24000, Appear_25000, Appear_26000, Appear_06000, Appear_28000, Appear_29000, Appear_30000, Appear_31000, Appear_32000, Appear_33000, Appear_34000, Appear_01000, Appear_36000, Appear_37000, Appear_38000, Appear_39000, Appear_06000, Appear_41000 };
    appear_jmp_tbl[wk->wu.routine_no[4]](wk);
}



void Appear_00000(PLW* wk) {
    Appear_end++;
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
}



void Appear_01000(PLW* wk) {
    s16 work;
    s16 id_w;
    id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        work = random_16_com();
        switch (wk->wu.routine_no[4]) {
        case 1:
            work &= 3;
            set_char_move_init(&wk->wu, 9, work);
            break;
        case 2:
            work &= 3;
            set_char_move_init(&wk->wu, 9, work + 4);
            break;
        case 35:
            work &= 7;
            set_char_move_init(&wk->wu, 9, work);
            break;
        }
        break;
    case AP01_WAIT:
        if (Appear_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            char_move(&wk->wu);
        } else {
            wk->wu.routine_no[3] = AP01_END;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
        }
        break;
    case AP01_NEXT:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            if (Appear_flag[wk->wu.id] == 0) {
                wk->wu.routine_no[3]++;
                set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
            }
        }
        break;
    case AP01_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_03000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, wk->wu.char_index);
        bg_app_stop = 1;
        break;
    case AP03_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



/* provisional name */
s32 yun_yang_appear_check(PLW* wk) {
    s16 kind;
    if ((plw[0].player_number == PL_YUN && plw[1].player_number == PL_YANG) ||
        (plw[0].player_number == PL_YANG && plw[1].player_number == PL_YUN)) {
        kind = 2;
    } else {
        kind = 1;
    }
    switch (kind) {
    case 1:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[2]);
        wk->wu.routine_no[4] = 1;
        Appear_01000(wk);
        return 1;
    case 2:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[24]);
        wk->wu.routine_no[4] = 20;
        Appear_20000(wk);
        return 1;
    }
    return 0;
}



void Appear_04000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_app_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        break;
    case AP04_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            app_counter[wk->wu.id] = 0x1C;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
            } else {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
            }
        }
        break;
    case AP04_NEXT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x11);
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x58;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x58;
            }
            wk->wu.xyz[0].disp.low = 0;
            wk->wu.xyz[1].cal = 0;
            break;
        }
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        break;
    case AP04_END:
        char_move(&wk->wu);
        if ((wk->wu.cg_type) == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



/* provisional name */
s32 yang_yun_appear_check(PLW* wk) {
    s16 kind;
    if ((plw[0].player_number == PL_YUN && plw[1].player_number == PL_YANG) ||
        (plw[0].player_number == PL_YANG && plw[1].player_number == PL_YUN)) {
        kind = 2;
    } else {
        kind = 1;
    }
    switch (kind) {
    case 1:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[2]);
        wk->wu.routine_no[4] = 1;
        Appear_01000(wk);
        return 1;
    case 2:
        if (wk->wu.id) {
            Appear_flag[0] = 0;
        } else {
            Appear_flag[1] = 0;
        }
        appear_data_set(wk, &appear_data[24]);
        wk->wu.routine_no[4] = 20;
        Appear_20000(wk);
        return 1;
    }
    return 0;
}



void Appear_05000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x17);
        bg_app_stop = 1;
        appear_work[wk->wu.id] = 0x1C;
        break;
    case AP05_WAIT:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 0x1B;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x60, 0, 2, 0);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x60, 0, 2, 0);
            }
        }
        break;
    case AP05_NEXT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0x17, 9, 0);
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x58;
                break;
            }
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x58;
            return;
        }
        add_x_sub((WORK_Other*)&wk->wu);
        break;
    case AP05_CUE:
        char_move(&wk->wu);
        if ((wk->wu.cg_type) == 9) {
            wk->wu.routine_no[3]++;
            wk->wu.rl_flag ^= 1;
            return;
        }
        break;
    case AP05_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_06000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        switch (wk->wu.routine_no[4]) {
        case 6:
            effect_C5_init(wk, 0);
            break;
        case 27:
            effect_C5_init(wk, 1);
            break;
        case 40:
            effect_M5_init(wk);
            break;
        }
        wk->wu.disp_flag = 0;
        bg_app_stop = 1;
        break;
    case AP06_WAIT:
        if (demo_car_flag[wk->wu.id]) {
            wk->wu.routine_no[3]++;
            wk->wu.disp_flag = 1;
            wk->wu.my_mr_flag = 0;
            set_char_move_init(&wk->wu, 9, 0x13);
            wk->wu.position_z = wk->wu.next_z = 0x6E;
            wk->wu.mvxy.d[0].sp = 0;
            wk->wu.mvxy.d[1].sp = -0x8000;
            if (wk->wu.routine_no[4] == 0x1B) {
                appear_work[wk->wu.id] = 0x34;
            } else {
                appear_work[wk->wu.id] = 0x2A;
            }
            if (wk->wu.id) {
                cal_initial_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 88, 0);
            } else {
                cal_initial_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 88, 0);
            }
        }
        break;
    case AP06_NEXT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x10);
            Appear_end++;
        } else {
            add_x_sub((WORK_Other*)&wk->wu);
            add_y_sub((WORK_Other*)&wk->wu);
        }
        break;
    case AP06_NEXT2:
        char_move(&wk->wu);
        if (wk->wu.cg_type) {
            wk->wu.routine_no[3]++;
            if (wk->wu.routine_no[4] == 0x1B) {
                wk->wu.rl_flag ^= 1;
                set_char_move_init(&wk->wu, 0, 1);
            } else {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
            }
        }
        break;
    case AP06_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
    wk->wu.position_x = wk->wu.xyz[0].disp.pos;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos;
}



void Appear_07000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        if (plw[wk->wu.id ^ 1].player_number == PL_SEAN && bg_w.stage == 12 && bg_w.area == 0) {
            wk->wu.routine_no[4] = 1;
            set_char_move_init(&wk->wu, 9, 17);
            wk->wu.routine_no[3] = AP07_AIR;
        } else {
            set_char_move_init(&wk->wu, 9, 8);
            effect_C8_init(wk);
            if (Appear_flag[wk->wu.id]) {
                wk->wu.routine_no[3]++;
                break;
            }
            wk->wu.routine_no[3] = AP07_CUE;
        }
        break;
    case AP07_WAIT:
        if (Appear_flag[wk->wu.id] != 0) {
            break;
        }
        wk->wu.routine_no[3] += 1;
    case AP07_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            wk->wu.cg_type = 0;
        }
        break;
    case AP07_AIR:
    case AP07_AIR2:
        switch (wk->wu.cg_type) {
        case 1:
            wk->wu.mvxy.a[1].sp = 0x30000;
            wk->wu.mvxy.d[1].sp = 0xffffa000;
            wk->wu.cg_type = 0;
            char_move_z(&wk->wu);
            break;
        case 2:
        case 3:
            char_move(&wk->wu);
            add_y_sub((WORK_Other*)wk);
            if (wk->wu.xyz[1].disp.pos < 0) {
                wk->wu.xyz[1].disp.pos = wk->wu.position_y = 0;
                wk->wu.xyz[1].disp.low = 0;
                char_move_z(&wk->wu);
            }
            break;
        case 4:
            wk->wu.cg_type = 0;
            char_move_z(&wk->wu);
            wk->wu.routine_no[3]++;
            break;
        default:
            char_move(&wk->wu);
            break;
        }
        break;
    case AP07_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
    wk->wu.position_x = wk->wu.xyz[0].disp.pos;
    wk->wu.position_y = wk->wu.xyz[1].disp.pos;
}



void Appear_08000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (sean_appear_check(wk, wk->wu.id)) {
            set_char_move_init(&wk->wu, 9, 0x11);
            Appear_free[wk->wu.id] = 0;
            bg_app_stop = 1;
            break;
        }
        appear_data_set(wk, appear_data);
        wk->wu.routine_no[4] = 2;
        break;
    case AP08_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



s32 sean_appear_check(PLW* wk, s16 id) {
    if (plw[id].player_number == PL_SEAN && bg_w.stage == 12) {
        return 1;
    }
    return 0;
}



void Appear_09000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        bg_app_stop = 1;
        break;
    case AP09_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            Appear_free[wk->wu.id] = 1;
            app_counter[wk->wu.id] = 0x20;
            return;
        }
        break;
    case AP09_NEXT:
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x11);
            wk->wu.mvxy.a[1].sp = -0xB0000;
            wk->wu.mvxy.d[1].sp = -0x6000;
            return;
        }
        break;
    case AP09_NEXT2:
        char_move(&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        if (wk->wu.xyz[1].disp.pos <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init(&wk->wu, 9, 0x12);
            Appear_end++;
            return;
        }
        break;
    case AP09_END2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_10000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x13);
        bg_app_stop = 1;
        wk->wu.mvxy.d[0].sp = 0;
        if (wk->wu.id) {
            wk->wu.mvxy.a[0].sp = -0x18000;
        } else {
            wk->wu.mvxy.a[0].sp = 0x18000;
        }
        break;
    case AP10_NEXT:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)&wk->wu);
        if (wk->wu.id) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 0x58) {
                break;
            }
        } else {
            if (wk->wu.xyz[0].disp.pos < bg_w.bgw[1].pos_x_work - 0x58) {
                break;
            }
        }
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 0x14);
        Appear_end++;
        break;
    case AP10_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_11000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_app_stop = 1;
        app_counter[wk->wu.id] = 0x50;
        set_char_move_init(&wk->wu, 0, 0);
        break;
    case AP11_WAIT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP11_WAIT;
            Appear_end++;
            if (Demo_Sound != 0 || Demo_Flag != 0) {
                sound_request_pan(0x2A9, 0x40, 0x40, 0, 2);
            }
        }
    }
}



void Appear_12000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        set_char_move_init(&wk->wu, 9, 12);
        effect_46_init(&wk->wu, 0);
        work = 88;
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.mvxy.d[1].sp = -0x8000;
        app_counter[wk->wu.id] = 0x30;
        if (wk->wu.id) {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + work, 0);
        } else {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - work, 0);
        }
        break;
    case AP12_NEXT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            set_char_move_init2(&wk->wu, 9, 12, 19, 0);
            Appear_end++;
            break;
        }
        add_x_sub((WORK_Other*)&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        break;
    case AP12_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.cg_type = 0;
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
    }
}



void Appear_13000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        set_char_move_init2(&wk->wu, 9, 0x3D, 4, 0);
        wk->wu.mvxy.a[1].sp = 0x78000;
        wk->wu.mvxy.d[1].sp = -0x3000;
        wk->wu.kage_flag = 0;
        break;
    case AP13_WAIT:
        if (bg_land_flag) {
            wk->wu.kage_flag = 1;
            wk->wu.routine_no[3]++;
        }
    case AP13_NEXT:
        char_move(&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        if (wk->wu.xyz[1].disp.pos < 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x3E);
            wk->wu.xyz[1].cal = 0;
            Appear_end++;
            return;
        }
        break;
    case AP13_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
        }
        break;
    }
}



void Appear_14000(PLW* wk) {
    s16 work;
    s16 id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        if (sean_appear_check(wk, id_w)) {
            set_char_move_init(&wk->wu, 9, 0x3C);
            return;
        }
        wk->wu.routine_no[2] = NORMAL_STAND;
        wk->wu.routine_no[3] = RN3_START;
        Appear_end++;
        break;
    case AP14_END:
        switch (Appear_free[id_w]) {
        case 0:
            char_move(&wk->wu);
            break;
        case 1:
            work = wk->wu.cg_ix / wk->wu.cgd_type;
            set_char_move_init2(&wk->wu, 0, 0, work + 1, 0);
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = AP14_END;
            Appear_end += 1;
            break;
        case 2:
            char_move(&wk->wu);
            if (wk->wu.cg_type == 0xFF) {
                wk->wu.routine_no[2] = NORMAL_STAND;
                wk->wu.routine_no[3] = RN3_START;
                Appear_end += 1;
            }
        }
    }
}



void Appear_15000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_app_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 8);
        effect_97_init(wk);
        break;
    case AP15_END:
        char_move(&wk->wu);
        switch (wk->wu.cg_type) {
        case 0x2:
            wk->wu.cg_type = 0;
            Sound_SE(0x10A);
            break;
        case 0x3:
            wk->wu.cg_type = 0;
            Sound_SE(0x10B);
            break;
        case 0xFF:
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
            break;
        }
    }
}



void Appear_16000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        if (smoke_check[bg_w.bg_index]) {
            set_char_move_init(&wk->wu, 9, 0xE);
        } else {
            set_char_move_init(&wk->wu, 9, 0xC);
        }
        break;
    case AP16_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



s16 gill_appear_check(void) {
    s16 id_w;
    if (bg_w.stage && bg_w.area) {
        return 1;
    }
    id_w = -1;
    if (plw[0].player_number == PL_GILL) {
        id_w = 1;
    }
    if (plw[1].player_number == PL_GILL) {
        id_w = 0;
    }
    if (id_w < 0) {
        return 1;
    }
    if (Introduce_Boss[Player_id][1] & 0x80) {
        return 1;
    }
    return 0;
}



void Appear_17000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (gill_appear_check()) {
            appear_data_set(wk, appear_data);
            Appear_00000(wk);
            break;
        }
        set_char_move_init(&wk->wu, 9, 0);
        bg_app_stop = 1;
        gSeqStatus[0] = 0;
        sound_request(49);
        set_char_move_init(&wk->wu, 9, 8);
        break;
    case AP17_WAIT:
        if (bg_app) {
            break;
        }
        wk->wu.routine_no[3]++;
        break;
    case AP17_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 2) {
            wk->wu.routine_no[3]++;
            wk->gill_ccch_go = 1;
            return;
        }
        break;
    case AP17_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
            bgm_fade_out(0x8C);
        }
        break;
    }
}



void Appear_18000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (plw[0].player_number == PL_ELENA && plw[1].player_number == PL_ELENA) {
            Appear_free[wk->wu.id] = 0;
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x3B;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x3B;
            }
            set_char_move_init(&wk->wu, 9, 0x10);
        } else {
            Appear_free[wk->wu.id] = 1;
            work = random_16_com();
            work &= 3;
            set_char_move_init(&wk->wu, 9, work + 8);
            wk->wu.mvxy.a[0].sp = 0;
            wk->wu.mvxy.a[1].sp = 0x80000;
            appear_work[wk->wu.id] = 0x1F;
            if (wk->wu.id) {
                cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
            } else {
                cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
            }
        }
        bg_app_stop = 1;
        break;
    case AP18_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            if (!Appear_free[wk->wu.id]) {
                wk->wu.mvxy.a[0].sp = 0;
                wk->wu.mvxy.a[1].sp = 0x80000;
                appear_work[wk->wu.id] = 0x1F;
                if (wk->wu.id) {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 1);
                } else {
                    cal_delta_speed(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 1);
                }
            }
            wk->wu.cg_type = 0;
            wk->wu.routine_no[3]++;
        }
        break;
    case AP18_WAIT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            wk->wu.xyz[1].cal = 0;
            break;
        }
        add_x_sub((WORK_Other*)&wk->wu);
        add_y_sub((WORK_Other*)&wk->wu);
        break;
    case AP18_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
    return;
}



void Appear_19000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_app_stop = 1;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0);
        wk->wu.rl_flag = 0;
        wk->wu.xyz[0].disp.pos = 0x275;
        wk->wu.xyz[1].disp.pos = 0x154;
        wk->wu.next_z = 0x56;
        wk->wu.my_mr_flag = 1;
        wk->wu.my_mr.size.x = 0x35;
        wk->wu.my_mr.size.y = 0x35;
        appear_work[wk->wu.id] = 0x82;
        break;
    case AP19_NEXT:
        appear_work[wk->wu.id]--;
        wk->wu.next_z = 0x56;
        if (appear_work[wk->wu.id] < 0) {
            wk->wu.routine_no[3]++;
            wk->wu.my_mr_flag = 0;
            wk->wu.my_mr.size.x = 0x3F;
            wk->wu.my_mr.size.y = 0x3F;
            set_char_move_init2(&wk->wu, 9, 0x3D, 4, 0);
            appear_work[wk->wu.id] = 0x20;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 1, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 1, 1);
            }
            if (wk->wu.id == 0) {
                wk->wu.rl_flag = 1;
            }
            wk->wu.next_z = wk->wu.my_priority;
            effect_15_init(&wk->wu, 0);
            effect_15_init(&wk->wu, 1);
            effect_15_init(&wk->wu, 2);
        }
        break;
    case AP19_NEXT2:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x3E);
            wk->wu.xyz[1].cal = 0;
            if (wk->wu.id) {
                Appear_flag[0] = 0;
            } else {
                Appear_flag[1] = 0;
            }
        } else {
            add_x_sub((WORK_Other*)&wk->wu);
            add_y_sub((WORK_Other*)&wk->wu);
        }
        break;
    case AP19_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_20000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x15);
        bg_app_stop = 1;
        break;
    case AP20_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



void Appear_21000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 7;
        if (work == 6 || work == 7) {
            appear_data_set(wk, &appear_data[24]);
            set_char_move_init(&wk->wu, 9, 0xE);
        } else {
            set_char_move_init(&wk->wu, 9, work + 8);
        }
        bg_app_stop = 1;
        break;
    case AP21_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end += 1;
        }
    }
}



void Appear_22000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        wk->wu.cmwk[1] = 0;
        set_char_move_init(&wk->wu, 9, 0);
        bg_app_stop = 1;
        break;
    case AP22_NEXT:
        char_move(&wk->wu);
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 8);
        break;
    case AP22_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



void Appear_23000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 3;
        wk->wu.cmwk[1] = 0;
        set_char_move_init(&wk->wu, 9, work + 4);
        bg_app_stop = 1;
        break;
    case AP23_NEXT:
        char_move(&wk->wu);
        if ((wk->wu.cmwk[1]) && wk->wu.cg_type == 9) {
            wk->wu.routine_no[3] += 1;
            set_char_move_init(&wk->wu, 9, wk->wu.char_index + 8);
            return;
        } else {
            return;
        }
    case AP23_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end += 1;
        }
        break;
    }
}



void Appear_24000(PLW* wk) {
    if (wk->wu.operator == 0) {
        if (wk->wu.id) {
            if (Game_setting.Screen_Mode) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 200;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 168;
            }
        } else if (Game_setting.Screen_Mode) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 200;
        } else {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 144;
        }
    }
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
}



void Appear_25000(PLW* wk) {
    if (!wk->wu.operator) {
        wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work;
    }
    wk->wu.routine_no[2] = NORMAL_STAND;
    wk->wu.routine_no[3] = RN3_START;
}



void Appear_26000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        bg_app_stop = 1;
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        appear_work[wk->wu.id] = 0x14;
        Appear_free[wk->wu.id] = 0;
        break;
    case AP26_WAIT:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 0x14;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work + 88, 0, 0, 1);
            } else {
                cal_all_speed_data(&wk->wu, appear_work[wk->wu.id], bg_w.bgw[1].pos_x_work - 88, 0, 0, 1);
            }
        }
        break;
    case AP26_AIR:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        if (wk->wu.xyz[1].disp.pos <= 0x40) {
            wk->wu.routine_no[3]++;
            wk->wu.hit_quake = 0x18;
            if (wk->wu.id == 0) {
                effect_86_init(0);
            }
            Sound_SE(0x109);
        }
        break;
    case AP26_RUN:
        char_move(&wk->wu);
        if (wk->wu.hit_quake <= 0) {
            wk->wu.routine_no[3]++;
            Appear_free[wk->wu.id] = 1;
        }
        break;
    case AP26_NEXT:
        char_move(&wk->wu);
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0x10, 3, 0);
            wk->wu.xyz[1].cal = 0;
        } else {
            add_x_sub((WORK_Other*)wk);
            add_y_sub((WORK_Other*)wk);
        }
        break;
    case AP26_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.rl_flag ^= 1;
            wk->wu.routine_no[3]++;
        }
        break;
    case AP26_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_28000(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        Appear_car_stop[id_w] = 0;
        set_char_move_init(&wk->wu, 9, 17);
        bg_app_stop = 1;
        break;
    case AP28_WAIT:
        if (Appear_car_stop[id_w]) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 17, 2, 0);
        }
        break;
    case AP28_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
        }
        break;
    case AP28_WAIT2:
        if (plw[id_w].wu.routine_no[3] >= 3) {
            wk->wu.routine_no[3]++;
            appear_work[wk->wu.id] = 20;
        }
        break;
    case AP28_NEXT:
        appear_work[wk->wu.id]--;
        if (appear_work[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 17, 15, 0);
        }
        break;
    case AP28_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_29000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = bg_app_stop = 1;
        wk->wu.cmwk[1] = 0;
        wk->wu.cmwk[2] = 0;
        work = random_16_com();
        wk->wu.cmwk[2] = work & 3;
        set_char_move_init(&wk->wu, 9, 0);
        work = random_16_com();
        if (work & 1) {
            effect_09_init2(&wk->wu, 0x19);
        }
        if (8 < work) {
            effect_09_init2(&wk->wu, 0x1b);
        }
        animal_decide(wk);
        break;
    case AP29_WAIT:
        if (wk->wu.cmwk[1]) {
            switch (wk->wu.cmwk[2]) {
            case 0:
            case 1:
                wk->wu.routine_no[3] = AP29_MOVE;
                if (wk->wu.id) {
                    wk->wu.mvxy.a[0].sp = -0x10000;
                } else {
                    wk->wu.mvxy.a[0].sp = 0x10000;
                }
                set_char_move_init(&wk->wu, 9, 8);
                break;
            case 2:
                wk->wu.routine_no[3] = AP29_END;
                if (wk->wu.id) {
                    wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0xd8;
                } else {
                    wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0xd8;
                }
                set_char_move_init(&wk->wu, 9, 10);
                break;
            case 3:
                wk->wu.routine_no[3] = AP29_NEXT;
                set_char_move_init(&wk->wu, 9, 0xb);
                wk->wu.mvxy.d[0].sp = 0;
                wk->wu.mvxy.d[1].sp = -0x8000;
                wk->wu.xyz[1].disp.pos = 0xb0;
                app_counter[wk->wu.id] = 0x20;
                if (wk->wu.id) {
                    cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0);
                } else {
                    cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0);
                }
                break;
            }
        }
        break;
    case AP29_MOVE:
        char_move(&wk->wu);
        add_x_sub((WORK_Other*)&wk->wu);
        if (wk->wu.id) {
            if (wk->wu.xyz[0].disp.pos > bg_w.bgw[1].pos_x_work + 0x58) {
                break;
            }
        } else if (wk->wu.xyz[0].disp.pos < (bg_w.bgw[1].pos_x_work - 0x58)) {
            break;
        }
        wk->wu.routine_no[2] = NORMAL_STAND;
        wk->wu.routine_no[3] = RN3_START;
        Appear_end++;
        break;
    case AP29_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    case AP29_NEXT:
        app_counter[wk->wu.id] -= 1;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0xb, 5, 0);
            wk->wu.xyz[1].disp.pos = 0;
        } else {
            add_x_sub((WORK_Other*)&wk->wu);
            add_y_sub((WORK_Other*)&wk->wu);
        }
        break;
    case AP29_END2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void animal_decide(PLW* wk) {
    u8 work2;
    s16 work = random_16_com();
    work2 = animal_decide_tbl[work];
    don_appear_check(wk);
    switch (work2) {
    case 0:
        break;
    case 1:
        effect_M0_init(wk->wu.rl_flag, 0);
        effect_M0_init(wk->wu.rl_flag, 1);
        break;
    default:
        effect_M0_init(wk->wu.rl_flag, work2);
        break;
    }
}



void don_appear_check(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;
    if (plw[id_w].player_number == PL_IBUKI) {
        effect_M0_init(wk->wu.rl_flag, 6);
    }
}



void Appear_30000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        work = random_16_com();
        work &= 3;
        appear_data_set(wk, &appear_data[24]);
        set_char_move_init(&wk->wu, 9, 0xE);
        break;
    case AP30_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end += 1;
        }
    }
}


void Appear_31000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (Appear_flag[wk->wu.id]) {
            appear_data_set(wk, appear_data);
            Appear_00000(wk);
        } else {
            set_char_move_init(&wk->wu, 9, 8);
        }
        bg_app_stop = 1;
        break;
    case AP31_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_32000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work + 8);
        bg_app_stop = 1;
        break;
    case AP32_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end += 1;
        }
    }
}



void Appear_33000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        set_char_move_init(&wk->wu, 9, 0xC);
        wk->wu.mvxy.d[0].sp = 0;
        wk->wu.mvxy.d[1].sp = -0x8000;
        wk->wu.xyz[1].disp.pos = 0x50;
        app_counter[wk->wu.id] = 0x2A;
        if (wk->wu.id) {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0);
        } else {
            cal_initial_speed(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0);
        }
        bg_app_stop = 1;
        don_appear_check(wk);
        break;
    case AP33_NEXT:
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0xC, 2, 0);
            wk->wu.xyz[1].disp.pos = 0;
            break;
        }
        add_x_sub((WORK_Other*)wk);
        add_y_sub((WORK_Other*)wk);
        break;
    case AP33_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



void Appear_34000(PLW* wk) {
    s16 work;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3] += 1;
        wk->wu.disp_flag = 1;
        work = random_16_com();
        work &= 7;
        set_char_move_init(&wk->wu, 9, work);
        switch (work) {
        case 0:
        case 2:
        case 6:
        case 7:
            if (wk->wu.id) {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x71;
            } else {
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work - 0x71;
            }
            break;
        }
        bg_app_stop = 1;
        break;
    default:
        Appear_01000(wk);
    }
}



void Appear_36000(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x10);
        bg_app_stop = 1;
        break;
    case AP36_NEXT:
        char_move(&wk->wu);
        if (plw[id_w].wu.cmwk[0] == 3) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x11);
            app_counter[wk->wu.id] = 0x10;
            wk->wu.next_z = plw[id_w].wu.my_priority;
        }
        break;
    case AP36_WAIT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            app_counter[wk->wu.id] = 0x16;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 2, 0);
            } else {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 2, 0);
            }
        }
        wk->wu.next_z = plw[id_w].wu.my_priority;
        break;
    case AP36_NEXT2:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[3]++;
            set_char_move_init2(&wk->wu, 9, 0x11, 0x0A, 0);
            wk->wu.next_z = wk->wu.my_priority;
        } else {
            add_x_sub((WORK_Other*)wk);
        }
        break;
    case AP36_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void Appear_37000(PLW* wk) {
    s16 id_w = wk->wu.id ^ 1;
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        set_char_move_init(&wk->wu, 9, 0x11);
        bg_app_stop = 1;
        wk->wu.cmwk[0] = 0;
        effect_M1_init(&wk->wu);
        break;
    case AP37_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            wk->wu.cmwk[0] = 1;
        }
        break;
    case AP37_NEXT:
        char_move(&wk->wu);
        if (wk->wu.cmwk[0] == 2) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x12);
        }
        break;
    case AP37_NEXT2:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 9, 0x13);
        }
        break;
    case AP37_CUE:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 9) {
            wk->wu.routine_no[3]++;
            wk->wu.cmwk[0] = 3;
            wk->wu.next_z = plw[id_w].wu.my_priority;
        }
        break;
    case AP37_NEXT3:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[3]++;
            set_char_move_init(&wk->wu, 0, 3);
            app_counter[wk->wu.id] = 0x2a;
            if (wk->wu.id) {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work + 0x58, 0, 0, 0);
            } else {
                cal_all_speed_data(&wk->wu, app_counter[wk->wu.id], bg_w.bgw[1].pos_x_work - 0x58, 0, 0, 0);
            }
            wk->wu.next_z = wk->wu.my_priority;
        } else {
            wk->wu.next_z = plw[id_w].wu.my_priority;
        }
        break;
    case AP37_WAIT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] <= 0) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        } else {
            add_x_sub((WORK_Other*)&wk->wu);
        }
        break;
    }
}



void Appear_38000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        bg_app_stop = 1;
        wk->wu.disp_flag = 1;
        if (wk->wu.id) {
            set_char_move_init(&wk->wu, 9, 0x14);
        } else {
            set_char_move_init(&wk->wu, 9, 0x13);
        }
        break;
    case AP38_END:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
    }
}



void Appear_39000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        if (gill_appear_check()) {
            appear_data_set(wk, appear_data);
            Appear_00000(wk);
            break;
        }
        bg_app_stop = 1;
        set_char_move_init(&wk->wu, 0, 2);
        if (wk->wu.id) {
            wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 0x200;
        }
        setup_mvxy_data(&wk->wu, 0);
        wk->wu.mvxy.a[0].sp >>= 1;
        add_mvxy_speed(&wk->wu);
        wk->wu.mvxy.a[0].sp *= 2;
        break;
    case AP39_MOVE:
        cal_mvxy_speed(&wk->wu);
        add_mvxy_speed(&wk->wu);
        char_move(&wk->wu);
        if (wk->wu.id) {
            if (wk->wu.xyz[0].disp.pos < (bg_w.bgw[1].pos_x_work + 88)) {
                wk->wu.routine_no[3]++;
                wk->wu.xyz[0].disp.pos = bg_w.bgw[1].pos_x_work + 88;
                return;
            }
        } else {
            if (wk->wu.xyz[0].disp.pos > (bg_w.bgw[1].pos_x_work - 88)) {
                wk->wu.routine_no[3] += 1;
                wk->wu.xyz[0].disp.pos = (bg_w.bgw[1].pos_x_work - 88);
                return;
            }
        }
        break;
    case AP39_DONE:
        wk->wu.routine_no[2] = NORMAL_STAND;
        wk->wu.routine_no[3] = RN3_START;
        Appear_end += 1;
        break;
    }
}


void Appear_41000(PLW* wk) {
    switch (wk->wu.routine_no[3]) {
    case RN3_START:
        wk->wu.routine_no[3]++;
        wk->wu.disp_flag = 1;
        bg_app_stop = 1;
        set_char_move_init(&wk->wu, 0, 0);
        app_counter[wk->wu.id] = 0x78;
        effect_M7_init(wk);
        break;
    case AP41_WAIT:
        char_move(&wk->wu);
        app_counter[wk->wu.id]--;
        if (app_counter[wk->wu.id] < 0) {
            wk->wu.routine_no[2] = NORMAL_STAND;
            wk->wu.routine_no[3] = RN3_START;
            Appear_end++;
        }
        break;
    }
}



void jijii_nebukuro(wk)
PLW* wk;
{
    if (!wk->wu.cmwk[0]) {
        char_move(&wk->wu);
        return;
    }
    switch (wk->wu.routine_no[6]) {
    case 0:
        wk->wu.routine_no[6]++;
        set_char_move_init(&wk->wu, 1, 60);
        char_move_z(&wk->wu);
        wk->wu.xyz[1].disp.pos = -6;
        break;
    case 1:
        char_move(&wk->wu);
        if (wk->wu.cg_type == 0xFF) {
            wk->wu.routine_no[6]++;
        }
    case 2:
        if (wk->player_number == PL_GILL) {
            Gill_Pos_X = wk->wu.xyz[0].disp.pos;
        }
        break;
    }
}

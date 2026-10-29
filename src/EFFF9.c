/*
 * EFFF9.C  Effect F9: ending message window
 *
 * Effect F9 is the ending message window. effect_F9_move picks the message by Country and
 * Language (effF9_mes_jp / _en / _es / _pt), loads its graphics, types it out a few characters
 * every three frames and calls Next_Talk_Message when its display time runs out. The ending
 * scripts (end_*.c) drive it through Rewrite_End_Message, Rewrite_Talk_Message,
 * Set_Direct_Message and Next_Talk_Message, which read the per-character scene lists in
 * txt_no_tbl (message + time pairs); effF9_talk_init opens the window on BG3.
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
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "CMD_MAIN.h"
#include "cmd_main_2.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "EFFF9.h"

/* routine_no[0] */
#define R0_INIT         0       /* load the message */
#define R0_WAIT1        1       /* wait a frame before showing */
#define R0_WAIT2        2       /* wait a frame before showing */
#define R0_WAIT3        3       /* wait a frame before showing */
#define R0_WAIT4        4       /* wait a frame before showing */
#define R0_MOVE         5       /* type the message out until its time */
#define R0_END          6       /* hidden for a frame */
#define R0_KILL         7       /* (default) put the work back */



extern const u16 efff9_no_scene[];
extern const EFFF9_MESSAGE effF9_mes_en_0[];
extern const EFFF9_MESSAGE effF9_mes_en_10[];
extern const EFFF9_MESSAGE effF9_mes_en_11[];
extern const EFFF9_MESSAGE effF9_mes_en_12[];
extern const EFFF9_MESSAGE effF9_mes_en_13[];
extern const EFFF9_MESSAGE effF9_mes_en_14[];
extern const EFFF9_MESSAGE effF9_mes_en_16[];
extern const EFFF9_MESSAGE effF9_mes_en_17[];
extern const EFFF9_MESSAGE effF9_mes_en_18[];
extern const EFFF9_MESSAGE effF9_mes_en_19[];
extern const EFFF9_MESSAGE effF9_mes_en_2[];
extern const EFFF9_MESSAGE effF9_mes_en_20[];
extern const EFFF9_MESSAGE effF9_mes_en_3[];
extern const EFFF9_MESSAGE effF9_mes_en_4[];
extern const EFFF9_MESSAGE effF9_mes_en_5[];
extern const EFFF9_MESSAGE effF9_mes_en_6[];
extern const EFFF9_MESSAGE effF9_mes_en_7[];
extern const EFFF9_MESSAGE effF9_mes_en_8[];
extern const EFFF9_MESSAGE effF9_mes_en_9[];
extern const EFFF9_MESSAGE effF9_mes_jp_0[];
extern const EFFF9_MESSAGE effF9_mes_jp_10[];
extern const EFFF9_MESSAGE effF9_mes_jp_11[];
extern const EFFF9_MESSAGE effF9_mes_jp_12[];
extern const EFFF9_MESSAGE effF9_mes_jp_13[];
extern const EFFF9_MESSAGE effF9_mes_jp_14[];
extern const EFFF9_MESSAGE effF9_mes_jp_16[];
extern const EFFF9_MESSAGE effF9_mes_jp_17[];
extern const EFFF9_MESSAGE effF9_mes_jp_18[];
extern const EFFF9_MESSAGE effF9_mes_jp_19[];
extern const EFFF9_MESSAGE effF9_mes_jp_2[];
extern const EFFF9_MESSAGE effF9_mes_jp_20[];
extern const EFFF9_MESSAGE effF9_mes_jp_3[];
extern const EFFF9_MESSAGE effF9_mes_jp_4[];
extern const EFFF9_MESSAGE effF9_mes_jp_5[];
extern const EFFF9_MESSAGE effF9_mes_jp_6[];
extern const EFFF9_MESSAGE effF9_mes_jp_7[];
extern const EFFF9_MESSAGE effF9_mes_jp_8[];
extern const EFFF9_MESSAGE effF9_mes_jp_9[];
extern const u16 pl01txt1[40];
extern const u16 pl02txt1[20];
extern const u16 pl02txt5[];
extern const u16 pl03txt1[];
extern const u16 pl03txt2[14];
extern const u16 pl03txt4[18];
extern const u16 pl03txt6[];
extern const u16 pl04txt1[24];
extern const u16 pl05txt1[];
extern const u16 pl05txt2[20];
extern const u16 pl05txt5[];
extern const u16 pl05txt6[12];
extern const u16 pl06txt2[];
extern const u16 pl06txt3[];
extern const u16 pl06txt4[];
extern const u16 pl06txt5[];
extern const u16 pl07txt1[];
extern const u16 pl07txt2[];
extern const u16 pl07txt3[20];
extern const u16 pl08txt1[];
extern const u16 pl08txt2[];
extern const u16 pl08txt3[18];
extern const u16 pl09txt2[10];
extern const u16 pl09txt4[];
extern const u16 pl09txt5[];
extern const u16 pl09txt6[];
extern const u16 pl10txt1[];
extern const u16 pl10txt2[16];
extern const u16 pl10txt4[16];
extern const u16 pl10txt6[12];
extern const u16 pl11txt2[40];
extern const u16 pl12txt2[14];
extern const u16 pl12txt4[];
extern const u16 pl12txt5[10];
extern const u16 pl13txt1[];
extern const u16 pl13txt2[22];
extern const u16 pl14txt1[];
extern const u16 pl14txt2[24];
extern const u16 pl15txt1[14];
extern const u16 pl15txt3[];
extern const u16 pl15txt4[12];
extern const u16 pl16txt1[];
extern const u16 pl16txt2[];
extern const u16 pl16txt3[8];
extern const u16 pl16txt5[];
extern const u16 pl16txt6[];
extern const u16 pl16txt7[];
extern const u16 pl17txt1[];
extern const u16 pl17txt2[];
extern const u16 pl17txt3[];
extern const u16 pl17txt5[54];
extern const u16 pl17txt6[14];
extern const u16 pl19txt2[];
extern const u16 pl19txt3[];
extern const u16 pl19txt4[14];
extern const u16 pl19txt6[10];

s16 efff9_suicide;  /* 02068C40 */
const u16** efff9_txt_no_adrs;  /* 02068C44 */
u16 * efff9_txt_scene_adrs;  /* 02068C48 */
s16 efff9_PL_NO;  /* 02068C4C */
s16 efff9_txt_point;  /* 02068C4E */
s16 efff9_message;  /* 02068C50 */
s16 keep_mes_no;  /* 02068C52 */


/* 0200706C */
const EFFF9_MESSAGE* effF9_mes_jp[28] = {
    effF9_mes_jp_0,
    effF9_mes_jp_0,
    effF9_mes_jp_2,
    effF9_mes_jp_3,
    effF9_mes_jp_4,
    effF9_mes_jp_5,
    effF9_mes_jp_6,
    effF9_mes_jp_7,
    effF9_mes_jp_8,
    effF9_mes_jp_9,
    effF9_mes_jp_10,
    effF9_mes_jp_11,
    effF9_mes_jp_12,
    effF9_mes_jp_13,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_16,
    effF9_mes_jp_17,
    effF9_mes_jp_18,
    effF9_mes_jp_19,
    effF9_mes_jp_20,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
};
/* 020070DC */
const EFFF9_MESSAGE* effF9_mes_en[21] = {
    effF9_mes_en_0,
    effF9_mes_en_0,
    effF9_mes_en_2,
    effF9_mes_en_3,
    effF9_mes_en_4,
    effF9_mes_en_5,
    effF9_mes_en_6,
    effF9_mes_en_7,
    effF9_mes_en_8,
    effF9_mes_en_9,
    effF9_mes_en_10,
    effF9_mes_en_11,
    effF9_mes_en_12,
    effF9_mes_en_13,
    effF9_mes_en_14,
    effF9_mes_en_14,
    effF9_mes_en_16,
    effF9_mes_en_17,
    effF9_mes_en_18,
    effF9_mes_en_19,
    effF9_mes_en_20,
};
/* 02007130 */
const EFFF9_MESSAGE* effF9_mes_es[21] = {
    effF9_mes_jp_0,
    effF9_mes_jp_0,
    effF9_mes_jp_2,
    effF9_mes_jp_3,
    effF9_mes_jp_4,
    effF9_mes_jp_5,
    effF9_mes_jp_6,
    effF9_mes_jp_7,
    effF9_mes_jp_8,
    effF9_mes_jp_9,
    effF9_mes_jp_10,
    effF9_mes_jp_11,
    effF9_mes_jp_12,
    effF9_mes_jp_13,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
};
/* 02007184 */
const EFFF9_MESSAGE* effF9_mes_pt[21] = {
    effF9_mes_jp_0,
    effF9_mes_jp_0,
    effF9_mes_jp_2,
    effF9_mes_jp_3,
    effF9_mes_jp_4,
    effF9_mes_jp_5,
    effF9_mes_jp_6,
    effF9_mes_jp_7,
    effF9_mes_jp_8,
    effF9_mes_jp_9,
    effF9_mes_jp_10,
    effF9_mes_jp_11,
    effF9_mes_jp_12,
    effF9_mes_jp_13,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
    effF9_mes_jp_14,
};
/* provisional name */
const u16* txt_no_00[6] = {
    efff9_no_scene, pl01txt1,
    &pl01txt1[6], &pl01txt1[16],
    &pl01txt1[30], &pl01txt1[34],
};
/* provisional name */
const u16* txt_no_02[6] = {
    efff9_no_scene, pl02txt1,
    &pl02txt1[6], &pl02txt1[14],
    &pl02txt1[18], pl02txt5,
};
/* provisional name */
const u16* txt_no_03[7] = {
    efff9_no_scene, pl03txt1,
    pl03txt2, &pl03txt2[6],
    pl03txt4, &pl03txt4[10],
    pl03txt6,
};
/* provisional name */
const u16* txt_no_04[3] = {
    efff9_no_scene, pl04txt1,
    &pl04txt1[10],
};
/* provisional name */
const u16* txt_no_05[7] = {
    efff9_no_scene, pl05txt1,
    pl05txt2, &pl05txt2[10],
    &pl05txt2[16], pl05txt5,
    pl05txt6,
};
/* provisional name */
const u16* txt_no_06[6] = {
    efff9_no_scene, &pl05txt6[6],
    pl06txt2, pl06txt3,
    pl06txt4, pl06txt5,
};
/* provisional name */
const u16* txt_no_07[5] = {
    efff9_no_scene, pl07txt1,
    pl07txt2, pl07txt3,
    &pl07txt3[8],
};
/* provisional name */
const u16* txt_no_08[5] = {
    efff9_no_scene, pl08txt1,
    pl08txt2, pl08txt3,
    &pl08txt3[10],
};
/* provisional name */
const u16* txt_no_09[7] = {
    efff9_no_scene, &pl08txt3[14],
    pl09txt2, &pl09txt2[6],
    pl09txt4, pl09txt5,
    pl09txt6,
};
/* provisional name */
const u16* txt_no_10[7] = {
    efff9_no_scene, pl10txt1,
    pl10txt2, &pl10txt2[10],
    pl10txt4, &pl10txt4[10],
    pl10txt6,
};
/* provisional name */
const u16* txt_no_11[6] = {
    efff9_no_scene, &pl10txt6[8],
    pl11txt2, &pl11txt2[6],
    &pl11txt2[14], &pl11txt2[26],
};
/* provisional name */
const u16* txt_no_12[7] = {
    efff9_no_scene, &pl11txt2[34],
    pl12txt2, &pl12txt2[8],
    pl12txt4, pl12txt5,
    &pl12txt5[6],
};
/* provisional name */
const u16* txt_no_13[5] = {
    efff9_no_scene, pl13txt1,
    pl13txt2, &pl13txt2[8],
    &pl13txt2[14],
};
/* provisional name */
const u16* txt_no_14[6] = {
    efff9_no_scene, pl14txt1,
    pl14txt2, &pl14txt2[10],
    &pl14txt2[16], &pl14txt2[18],
};
/* provisional name */
const u16* txt_no_16[6] = {
    efff9_no_scene, pl15txt1,
    &pl15txt1[10], pl15txt3,
    pl15txt4, &pl15txt4[8],
};
/* provisional name */
const u16* txt_no_17[8] = {
    efff9_no_scene, pl16txt1,
    pl16txt2, pl16txt3,
    &pl16txt3[6], pl16txt5,
    pl16txt6, pl16txt7,
};
/* provisional name */
const u16* txt_no_18[7] = {
    efff9_no_scene, pl17txt1,
    pl17txt2, pl17txt3,
    &pl17txt6[10], pl17txt5,
    pl17txt6,
};
/* provisional name */
const u16* txt_no_19[6] = {
    efff9_no_scene, &pl17txt5[6],
    &pl17txt5[12], &pl17txt5[22],
    &pl17txt5[30], &pl17txt5[40],
};
/* provisional name */
const u16* txt_no_20[8] = {
    efff9_no_scene, &pl17txt5[48],
    pl19txt2, pl19txt3,
    pl19txt4, &pl19txt4[10],
    pl19txt6, &pl19txt6[8],
};
/* provisional name */
const u16* txt_no_26[2] = {
    efff9_no_scene, pl15txt1,
};
/* 020073B8 */
const u16** txt_no_tbl[28] = {
    txt_no_00, txt_no_00, txt_no_02, txt_no_03,
    txt_no_04, txt_no_05, txt_no_06, txt_no_07,
    txt_no_08, txt_no_09, txt_no_10, txt_no_11,
    txt_no_12, txt_no_13, txt_no_14, txt_no_14,
    txt_no_16, txt_no_17, txt_no_18, txt_no_19,
    txt_no_20, txt_no_14, txt_no_14, txt_no_14,
    txt_no_14, txt_no_14, txt_no_26, txt_no_26,
};


void effect_F9_move(WORK_Other_CONN* ewk) {
    const u16* chr_data;
    const CONN* conn_data;
    s16 i;
    switch (ewk->wu.routine_no[0]) {
    case R0_INIT:
        ewk->wu.routine_no[0]++;
        switch (Country) {
        case 1:
            conn_data = effF9_mes_jp[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_jp[ewk->master_player][mes_already].chr;
            break;
        case 2:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        case 3:
            switch (Language) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        case 4:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        case 5:
            conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
            break;
        case 6:
            conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
            break;
        case 7:
            switch (Language) {
            case 0:
                conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
                break;
            case 1:
                conn_data = effF9_mes_es[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_es[ewk->master_player][mes_already].chr;
                break;
            case 2:
                conn_data = effF9_mes_pt[ewk->master_player][mes_already].conn;
                chr_data = effF9_mes_pt[ewk->master_player][mes_already].chr;
                break;
            }
            break;
        default:
            conn_data = effF9_mes_en[ewk->master_player][mes_already].conn;
            chr_data = effF9_mes_en[ewk->master_player][mes_already].chr;
            break;
        }
        for (i = 0; i < chr_data[0]; i++) {
            load_char_gfx(chr_data[i + 1], 1);
        }
        ewk->num_of_conn = chr_data[i + 1];
        ewk->wu.old_rno[4] = chr_data[i + 1];
        if (ewk->wu.old_rno[4] == 0) {
            ewk->wu.old_rno[5] = 0;
        } else {
            ewk->wu.old_rno[5] = 1;
        }
        ewk->wu.old_rno[6] = 1;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = ewk->wu.cg_number = 0;
        for (i = 0; i < ewk->num_of_conn; i++) {
            ewk->conn[i].nx = conn_data[i].nx;
            ewk->conn[i].ny = conn_data[i].ny;
            ewk->conn[i].col = conn_data[i].col;
            ewk->conn[i].chr = conn_data[i].chr;
        }
        efff9_suicide = 0;
        ewk->wu.vitality = 240;
        ewk->num_of_conn = ewk->wu.old_rno[5];
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        break;
    case R0_WAIT1:
    case R0_WAIT2:
    case R0_WAIT3:
    case R0_WAIT4:
        ewk->wu.routine_no[0]++;
        break;
    case R0_MOVE:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.type = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        }
        ewk->wu.old_rno[6]--;
        if (ewk->wu.old_rno[6] == 0) {
            ewk->wu.old_rno[6] = 3;
            if (ewk->wu.old_rno[4] == ewk->wu.old_rno[5]) {
                ewk->wu.old_rno[6] = 3;
            } else {
                ewk->wu.old_rno[5]++;
                if (Country != 1) {
                    ewk->wu.old_rno[5]++;
                    if (ewk->wu.old_rno[4] < ewk->wu.old_rno[5]) {
                        ewk->wu.old_rno[5] = ewk->wu.old_rno[4];
                    }
                }
                ewk->num_of_conn = ewk->wu.old_rno[5];
            }
        }
        if (ewk->wu.old_rno[3] == 0) {
            Next_Talk_Message();
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            break;
        } else {
        }
        ewk->wu.old_rno[3]--;
        if (efff9_suicide == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = R0_END;
            ewk->wu.disp_flag = 0;
            break;
        }
        ewk->wu.cg_number++;
        ewk->wu.cg_number &= 0x7FFF;
        sort_push_request3(&ewk->wu);
        break;
    case R0_END:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}

/* Start the ending text effect for character pl_no. */
s32 effect_F9_init(s16 pl_no)
{
    WORK_Other* ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    keep_mes_no = 0;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_PL_NO = pl_no;
    ewk->master_player = efff9_PL_NO;
    return 0;
}



void efff9_wk_set(WORK_Other_CONN* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 159;
    ewk->wu.work_id = 16;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 4;
    ewk->wu.my_priority = 5;
    ewk->wu.position_x = 312;
    ewk->wu.position_y = 24;
    ewk->wu.position_z = 5;
}



/* provisional name */
s32 effF9_talk_init(s16 pl) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    mes_already = 0;
    efff9_suicide = 0;
    efff9_txt_point = 0;
    effF9_talk_wk_set(ewk);
    efff9_PL_NO = pl;
    ewk->master_player = efff9_PL_NO;
    load_any_color(0x8D);
    return 0;
}



/* provisional name */
void effF9_talk_wk_set(WORK_Other* ewk) {
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0x9F;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = 0;
    ewk->wu.cgromtype = 1;
    ewk->wu.sync_suzi = 0;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0;
    ewk->wu.my_family = 3;
    ewk->wu.my_priority = 5;
    if (Game_setting.mode == 0) {
        ewk->wu.position_x = 0x280;
    } else {
        ewk->wu.position_x = 0x2E8;
    }
    ewk->wu.position_y = 0x18;
    ewk->wu.position_z = 5;
}



s32 Rewrite_End_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    ix = pull_effect_work(4);
    if (ix == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    keep_mes_no = mes_no;
    ewk->wu.routine_no[0] = R0_INIT;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    ewk->wu.old_rno[3] = *(s16*)(efff9_txt_scene_adrs + 1);
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
s32 Rewrite_Talk_Message(u16 mes_no) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    keep_mes_no = mes_no;
    ewk->wu.routine_no[0] = R0_INIT;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    effF9_talk_wk_set(ewk);
    efff9_txt_point = 2;
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[mes_no];
    efff9_message = efff9_txt_scene_adrs[0];
    ewk->wu.old_rno[3] = *(s16*)(efff9_txt_scene_adrs + 1);
    mes_already = efff9_message;
    return 0;
}



/* provisional name */
s32 Set_Direct_Message(s16 mes) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    efff9_suicide = 0;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    mes_already = mes;
    return 0;
}



/* provisional name */
s32 Next_Talk_Message(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.routine_no[0] = R0_INIT;
    efff9_suicide = 1;
    ewk->master_player = efff9_PL_NO;
    efff9_wk_set((WORK_Other_CONN*)ewk);
    efff9_txt_no_adrs = txt_no_tbl[efff9_PL_NO];
    efff9_txt_scene_adrs = (u16*)efff9_txt_no_adrs[keep_mes_no];
    efff9_message = efff9_txt_scene_adrs[efff9_txt_point];
    ewk->wu.old_rno[3] = efff9_txt_scene_adrs[efff9_txt_point + 1];
    efff9_txt_point += 2;
    mes_already = efff9_message;
    return 0;
}

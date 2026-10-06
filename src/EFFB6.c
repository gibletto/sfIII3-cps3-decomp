/*
 * EFFB6.C  Effect B5 init, effect B6 (another-BG overlay parts) and effect B7 move
 *
 * effect_B5_init creates the three name-entry letter works (B5) for a player, 24 dots apart on
 * BG1 (called from n_input.c).
 * Effect B6 draws a set of background overlay cells for the another-BG switch: effect_B6_init is
 * called twice (types 0 and 1) from efff0.c. effect_B6_move copies the cell positions from
 * effB6_pos_tbl_0 / _1 and, while another_bg[] is set, shows the parts of its type and slides
 * them by the offsets for the switch direction (1-4), drawing with disp_car_parts_cells.
 * Effect B7 shows a rank-in number (pattern old_rno[0] + 1) for name entry until it is killed;
 * its init is in EFFB8.C.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "ta_sub.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "CHARMOVE.h"
#include "charmove_2.h"
#include "bg_sub.h"
#include "bg_sub_2.h"
#include "bg_sub_3.h"
#include "bg_sub_4.h"
#include "bg_sub_5.h"
#include "PLS02.h"
#include "EFFB6.h"



s32 effect_B5_init(s16 PL_id) {
    WORK_Other* ewk;
    s16 ix;
    s16 i;
    s16 x = bg_w.bgw[0].xy[0].disp.pos - 20;
    NAME_WK* np = &name_wk[PL_id];
    for (i = 0; i < 3; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->my_master = (u32*)np;
        ewk->wu.be_flag = 1;
        ewk->wu.id = 115;
        ewk->wu.work_id = 16;
        ewk->wu.old_rno[2] = i;
        ewk->wu.type = i;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x180;
        ewk->wu.my_priority = ewk->wu.position_z = 10;
        ewk->wu.position_y = 80;
        ewk->wu.xyz[1].cal = 0x500000;
        ewk->wu.position_x = ewk->wu.xyz[0].disp.pos = x;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.char_index = 6;
        ewk->wu.char_table[0] = etc_char_table;
        x = x + 24;
    }
    return 0;
}



void effect_B6_move(WORK_Other_CONN* ewk_conn) {
    WORK_B6* ewk = (WORK_B6*)ewk_conn;
    WORK* oya = ewk->my_master;
    s32 i;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 0;
        ewk->num = effB6_num_tbl[ewk->wu.type];
        if (ewk->wu.type) {
            effB6_pos_data_set(ewk, effB6_pos_tbl_1, ewk->num);
        } else {
            effB6_pos_data_set(ewk, effB6_pos_tbl_0, ewk->num);
        }
        return;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        if (akebono_flag) {
            return;
        }
        switch (ewk->wu.routine_no[1]) {
        case 0:
            if (another_bg[0] | another_bg[1]) {
                ewk->wu.routine_no[1]++;
            }
            break;
        case 1:
            if (another_bg[0] | another_bg[1]) {
                ewk->wu.disp_flag = 0;
                switch (another_bg[oya->type]) {
                case 1:
                    if (ewk->wu.type != 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][1] += ewk->src[i][3];
                        ewk->pos[i][2] = ewk->src[i][4];
                        continue;
                    }
                    ewk->wu.disp_flag = 1;
                    break;
                case 2:
                    if (ewk->wu.type == 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][0] += ewk->src[i][1];
                        ewk->pos[i][2] = ewk->src[i][5];
                        continue;
                    }
                    ewk->wu.disp_flag = 1;
                    break;
                case 3:
                    if (ewk->wu.type == 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][0] -= ewk->src[i][1];
                        ewk->pos[i][2] = ewk->src[i][4];
                        continue;
                    }
                    ewk->wu.disp_flag = 1;
                    break;
                case 4:
                    if (ewk->wu.type != 0) {
                        break;
                    }
                    for (i = 0; i < ewk->num; i++) {
                        ewk->pos[i][1] -= ewk->src[i][3];
                        ewk->pos[i][2] = ewk->src[i][5];
                        continue;
                    }
                    ewk->wu.disp_flag = 1;
                    break;
                }
            } else {
                ewk->wu.disp_flag = 0;
                ewk->wu.routine_no[1] = 0;
            }
            break;
        }
        disp_car_parts_cells(&ewk->wu);
        return;
    case 2:
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}

/* provisional name */
void effB6_pos_data_set(ewk, tbl, num)
WORK_B6* ewk;
const s16 (*tbl)[6];
s16 num;
{
    s16 i;
    s16* d;
    const s16* t;
    for (i = 0; i < num; i++) {
        d = ewk->src[i];
        t = tbl[i];
        d[0] = t[0];
        d[1] = t[1];
        d[2] = t[2];
        d[3] = t[3];
        d[4] = t[4];
        d[5] = t[5];
        ewk->pos[i][0] = ewk->src[i][0];
        ewk->pos[i][1] = ewk->src[i][2];
        ewk->pos[i][2] = ewk->src[i][4];
        ewk->pos[i][0] += bg_w.bgw[1].pos_x_work;
    }
}



s32 effect_B6_init(WORK_Other* oya, u8 type) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(5)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 116;
    ewk->wu.work_id = 16;
    ewk->wu.type = type;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x21C5;
    ewk->wu.my_family = 2;
    ewk->wu.my_priority = ewk->wu.position_z = 69;
    ewk->my_master = (u32*)oya;
    ewk->wu.sync_suzi = 0;
    suzi_offset_set(ewk);
    return 0;
}


void effect_B7_move(WORK_Other* ewk) {
    NAME_WK* np = (NAME_WK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.disp_flag = 1;
        set_char_move_init2(&ewk->wu, 0, 7, ewk->wu.old_rno[0] + 1, 0);
        break;
    case 1:
        disp_pos_trans_entry(ewk);
        break;
    case 2:
        ewk->wu.routine_no[0]++;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}


s32 effect_B7_init(s8 pl) {
    WORK_Other* ewk;
    NAME_WK* np = &name_wk[pl];
    s16 ix;
    s16 i;
    s16 x;
    for (i = 0; i < 2; i++) {
        if ((ix = pull_effect_work(3)) == -1) {
            return -1;
        }
        ewk = (WORK_Other*)frw[ix];
        ewk->my_master = (u32*)np;
        ewk->wu.be_flag = 1;
        ewk->wu.id = 117;
        ewk->wu.work_id = 16;
        ewk->wu.type = i;
        ewk->wu.cgromtype = 1;
        ewk->wu.disp_flag = 0;
        ewk->wu.rl_flag = 0;
        ewk->wu.my_family = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = 0x180;
        ewk->wu.position_z = 10;
        ewk->wu.my_priority = 10;
        ewk->wu.position_y = 104;
        ewk->wu.xyz[1].cal = 104 << 16;
        ewk->wu.xyz[0].disp.low = 0;
        ewk->wu.char_index = 7;
        *ewk->wu.char_table = etc_char_table;
        if (i) {
            ewk->wu.old_rno[0] = np->rank_in * 2 + 1;
            x = bg_w.bgw[0].xy[0].disp.pos + 8;
        } else {
            ewk->wu.old_rno[0] = np->rank_in * 2;
            x = bg_w.bgw[0].xy[0].disp.pos - 8;
        }
        ewk->wu.xyz[0].disp.pos = x;
        ewk->wu.position_x = x;
    }
    return 0;
}

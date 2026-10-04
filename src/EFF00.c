/*
 * EFF00.C  Effect 00 (judgement box display) and effect 01 move
 *
 * Effect 00 draws a character's judgement boxes (body, hand, catch, caught, attack, hosei)
 * over it. Which boxes are shown is chosen by the extra DIP switches or judge_disp_all; in
 * the debug editors it shows the edited or looked-up box set instead. effect_00_init is
 * called from the debug screens in CMD_MAIN.
 * effect_01_move runs the overlay-parts work that follows its master's motion, flip and
 * display flag (set_parts_disp_flag); effect_01_init creates it for one of a character's parts
 * slots and records it in the master's olc_work_ix.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "effect_2.h"
#include "EFF00.h"
#include "fighter.h"
void effect_00_move(WORK_Other_JUDGE* judge) {
    WORK_Other_JUDGE* ewk = (WORK_Other_JUDGE*)judge;
    s32 dip;
    ewk->fade_cja.l = ewk->fade_cja.l + 0x2000;
    ewk->fade_cja.w = ewk->fade_cja.w & 3;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        renewal_table_address(ewk, ewk->my_master);
        ewk->wu.cgromtype = 1;
        ewk->wu.my_col_mode = 0x4200;
        ewk->wu.my_col_code = ewk->wu.spr.disp_colcd = 0x203F;
        ewk->wu.my_priority = ewk->wu.position_z = 16;
        ewk->wu.cg_number = 0x9000;
        ewk->curr_ja = ewk->look_up_flag = 0;
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || ewk->my_master->waku_work_index != ewk->wu.myself) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            break;
        }
        dip = exsw_1 & 0x3F00;
        (*(u16*)((u8*)&(ewk)->wu + 0x242)) = 0;
        ewk->ja_disp_bit = 0;
        if (judge_disp_all) {
            ewk->ja_disp_bit = jdb[15];
            (*(u16*)((u8*)&(ewk)->wu + 0x242)) = jdb2[15];
        } else if ((ewk->master_work_id == 1) ? (dip & 0x1000) : (dip & 0x2000)) {
            dip = (dip >> 8) & 0xF;
            ewk->ja_disp_bit = jdb[dip];
            (*(u16*)((u8*)&(ewk)->wu + 0x242)) = jdb2[dip];
        }
        renewal_table_address(ewk, ewk->my_master);
        renewal_table_data(ewk);
        sort_push_request2((WORK_Other*)ewk);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back((WORK_Other*)ewk);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void renewal_table_address(WORK_Other_JUDGE* ewk, WORK* twk) {
    ewk->wu.rl_flag = twk->rl_flag;
    if (judge_disp_all == 0) {
        if (twk->disp_flag) {
            ewk->wu.disp_flag = 1;
        } else {
            ewk->wu.disp_flag = 0;
        }
    }
    if (Debug_Box_Edit) {
        ewk->wu.h_bod = dbg_copy_buf.h_bod;
        ewk->wu.h_han = dbg_copy_buf.h_han;
        ewk->wu.h_att = dbg_copy_buf.h_att;
        ewk->wu.h_cat = dbg_copy_buf.h_cat;
        ewk->wu.h_cau = dbg_copy_buf.h_cau;
        ewk->wu.h_hos = dbg_copy_buf.h_hos;
    } else if (ewk->look_up_flag) {
        ewk->wu.h_bod = dbg_look_buf.h_bod;
        ewk->wu.h_han = dbg_look_buf.h_han;
        ewk->wu.h_att = dbg_look_buf.h_att;
        ewk->wu.h_cat = dbg_look_buf.h_cat;
        ewk->wu.h_cau = dbg_look_buf.h_cau;
        ewk->wu.h_hos = dbg_look_buf.h_hos;
    } else {
        ewk->wu.h_bod = twk->h_bod;
        ewk->wu.h_han = twk->h_han;
        ewk->wu.h_cat = twk->h_cat;
        ewk->wu.h_cau = twk->h_cau;
        ewk->wu.h_att = twk->h_att;
        ewk->wu.h_hos = twk->h_hos;
    }
    if (test_flag) {
        ewk->wu.position_x = twk->position_x;
        ewk->wu.position_y = twk->position_y;
    } else {
        ewk->wu.position_x = twk->xyz[0].disp.pos;
        ewk->wu.position_y = twk->xyz[1].disp.pos;
    }
}



/* provisional name */
void renewal_table_data(WORK_Other_JUDGE* ewk) {
    u16* mm;
    s16 i;
    s16 j;
    for (mm = (u16*)ewk->wu.h_bod, i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_han, i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i + 4][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_cat, j = 0; j < 4; j++) {
        ewk->jx[8][j] = *mm++;
    }
    for (mm = (u16*)ewk->wu.h_cau, j = 0; j < 4; j++) {
        ewk->jx[9][j] = *mm++;
    }
    for (mm = (u16*)ewk->wu.h_att, i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            ewk->jx[i + 10][j] = *mm++;
        }
    }
    for (mm = (u16*)ewk->wu.h_hos, j = 0; j < 4; j++) {
        ewk->jx[14][j] = *mm++;
    }
    for (i = 0; i < 15; i++) {
        ewk->ja[i * 4 + 2][0] = ewk->ja[i * 4][0] = ewk->jx[i][0];
        ewk->ja[i * 4 + 3][0] = ewk->ja[i * 4 + 1][0] = ewk->jx[i][0] + ewk->jx[i][1];
        ewk->ja[i * 4 + 3][1] = ewk->ja[i * 4 + 2][1] = ewk->jx[i][2];
        ewk->ja[i * 4 + 1][1] = ewk->ja[i * 4][1] = ewk->jx[i][2] + ewk->jx[i][3];
    }
    ewk->ja[60][1] = ewk->ja[60][0] = 0;
    ewk->ja[61][0] = 0;
    ewk->ja[61][1] = -ewk->wu.position_y;
}



s32 effect_00_init(WORK* wk) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0;
    ewk->wu.work_id = 128;
    ewk->wu.charset_id = wk->charset_id;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.my_ext_pri = wk->my_ext_pri;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    wk->waku_work_index = ewk->wu.myself;
    return 0;
}



void effect_01_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cgromtype = mwk->cgromtype;
        ewk->wu.cg_number = ewk->wu.old_cgnum = 0;
        ewk->wu.blink_timing = mwk->blink_timing;
        ewk->wu.cg_olc.olc_ix[ewk->wu.type] = 0;
        return;
    case 1:
        if (ewk->wu.dead_f == 1 || mwk->olc_work_ix[ewk->wu.type] != ewk->wu.myself) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0]++;
            return;
        }
        if (mwk->cg_olc.olc_ix[ewk->wu.type] == 0) {
            ewk->wu.cg_olc.olc_ix[ewk->wu.type] = 0;
            return;
        }
        if (!Game_pause && !EXE_flag) {
            if (ewk->wu.cg_olc.olc_ix[ewk->wu.type] != mwk->cg_olc.olc_ix[ewk->wu.type]) {
                ewk->wu.cg_olc.olc_ix[ewk->wu.type] = ewk->wu.cg_ix = mwk->cg_olc.olc_ix[ewk->wu.type];
                ewk->wu.now_koc = ewk->wu.cg_ix;
                if (ewk->wu.type == 0 && ((PLW*)mwk)->player_number == PL_GILL && mwk->rl_flag) {
                    ewk->wu.now_koc++;
                }
                get_new_parts_data(ewk, (PLW*)mwk);
            } else if (((PLW*)mwk)->sa_stop_flag == 0) {
                if (--ewk->wu.cg_ctr == 0) {
                    if (ewk->wu.overlap_char_tbl->parts_nix) {
                        ewk->wu.cg_ix = ewk->wu.overlap_char_tbl->parts_nix;
                    } else {
                        ewk->wu.cg_ix++;
                    }
                    ewk->wu.now_koc = ewk->wu.cg_ix;
                    get_new_parts_data(ewk, (PLW*)mwk);
                }
            }
            if (ewk->wu.cg_number == 0) {
                break;
            }
            ewk->wu.position_x = mwk->position_x;
            ewk->wu.position_y = mwk->position_y;
            ewk->wu.position_z = mwk->position_z;
            ewk->wu.rl_flag = mwk->rl_flag;
            ewk->wu.cg_flip = ewk->wu.overlap_char_tbl->parts_flip & 3;
            if (ewk->wu.overlap_char_tbl->parts_flip & 4) {
                ewk->wu.cg_flip ^= mwk->cg_flip;
                if (mwk->cg_flip & 1) {
                    ewk->wu.rl_flag = (ewk->wu.rl_flag + 1) & 1;
                }
            }
            if (ewk->wu.rl_flag) {
                ewk->wu.position_x -= ewk->wu.overlap_char_tbl->parts_hos_x;
            } else {
                ewk->wu.position_x += ewk->wu.overlap_char_tbl->parts_hos_x;
            }
            ewk->wu.position_y += ewk->wu.overlap_char_tbl->parts_hos_y;
            if (ewk->wu.overlap_char_tbl->parts_flip & 4 && mwk->cg_flip & 2) {
                ewk->wu.position_y -= ewk->wu.overlap_char_tbl->parts_hos_y * 2;
            }
            if (ewk->wu.overlap_char_tbl->parts_prio == 2) {
                ewk->wu.position_z -= (ewk->wu.type + 1) * 2;
            } else {
                ewk->wu.position_z += (ewk->wu.type + 1) * 2;
            }
        }
        if (ewk->wu.cg_number == 0) {
            break;
        }
        set_parts_disp_flag(ewk, (PLW*)mwk);
        if (ewk->wu.overlap_char_tbl->parts_colcd == 0) {
            ewk->wu.my_col_code = mwk->my_col_code;
            ewk->wu.extra_col = mwk->extra_col;
            ewk->wu.extra_col_2 = mwk->extra_col_2;
        }
        sort_push_request(&ewk->wu);
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        break;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        break;
    }
}



/* provisional name */
void get_new_parts_data(WORK_Other* ewk, PLW* mwk) {
    ewk->wu.overlap_char_tbl = mwk->wu.overlap_char_tbl + ewk->wu.now_koc;
    ewk->wu.cg_ctr = ewk->wu.overlap_char_tbl->parts_timer;
    if (ewk->wu.overlap_char_tbl->parts_colmd) {
        if (ewk->wu.overlap_char_tbl->parts_colmd == 1) {
            ewk->wu.my_col_mode = ((WORK*)mwk->wu.target_adrs)->my_col_mode;
        } else {
            ewk->wu.my_col_mode = parts_colmd_table[ewk->wu.overlap_char_tbl->parts_colmd];
        }
    } else {
        ewk->wu.my_col_mode = mwk->wu.my_col_mode;
    }
    if (ewk->wu.overlap_char_tbl->parts_colcd) {
        ewk->wu.my_col_code = parts_colcd_table[ewk->wu.overlap_char_tbl->parts_colcd];
        if (!(parts_colcd_table[ewk->wu.overlap_char_tbl->parts_colcd] & 0x2000)) {
            ewk->wu.my_col_code += mwk->wu.my_col_code;
        }
    } else {
        ewk->wu.my_col_code = mwk->wu.my_col_code;
        ewk->wu.extra_col = mwk->wu.extra_col;
        ewk->wu.extra_col_2 = mwk->wu.extra_col_2;
    }
    ewk->wu.cg_number = ewk->wu.overlap_char_tbl->parts_char;
}



void set_parts_disp_flag(WORK_Other* ewk, PLW* mwk) {
    switch (ewk->wu.overlap_char_tbl->parts_disp) {
    case 1:
        if (mwk->wu.disp_flag) {
            ewk->wu.disp_flag = 1;
        } else {
            ewk->wu.disp_flag = 0;
        }
        break;
    case 2:
        if (mwk->wu.disp_flag) {
            ewk->wu.disp_flag = 2;
        } else {
            ewk->wu.disp_flag = 0;
        }
        break;
    case 11:
        ewk->wu.disp_flag = 1;
        break;
    case 12:
        ewk->wu.disp_flag = 2;
        break;
    default:
        ewk->wu.disp_flag = mwk->wu.disp_flag;
        break;
    }
}


s32 effect_01_init(WORK* wk, u8 koolc) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(1)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 1;
    ewk->wu.work_id = 32;
    ewk->wu.type = koolc;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.blink_timing = wk->blink_timing;
    ewk->my_master = (u32*)wk;
    ewk->master_work_id = wk->work_id;
    ewk->master_id = wk->id;
    wk->olc_work_ix[koolc] = ewk->wu.myself;
    return 0;
}

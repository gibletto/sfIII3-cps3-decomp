/*
 * EFFJ0.C  Effects J0 (shell after-image), J1 (empty) and J2 (bonus-stage level plate)
 *
 * Effect J0 is one image of a shell's after-image trail. effect_J0_init is called by effect I9
 * (EFFI9.C) with the image's delay in the trail; effect_J0_move draws the shell's current frame,
 * flip and graphics at the position the shell had that many frames ago (read from I9's image
 * buffer), and ends with its timer or when the shell starts to finish.
 * effect_J1_move is an empty routine.
 * Effect J2 is the bonus-stage level plate: effect_J2_init (from Game_Main.c) builds a two-part
 * connected sprite (id 192) from bbbs_nando_large; after its delay it shows its connected sprites with the digit for
 * Bonus_Stage_Level fixed to the BG1 screen position (effJ2_trans) for 60 frames, and
 * disappears early on a break-in (Break_Into).
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "EFFECT.h"
#include "EFFJ0.h"




void effect_J0_move(WORK_Other* ewk) {
    WORK_Other* mwk = (WORK_Other*)ewk->my_master;
    WORK_Other* cwk = (WORK_Other*)ewk->wu.target_adrs;
    WORK* sub_w = (WORK*)cwk->wu.target_adrs;
    ImageBuff* image_buff = (ImageBuff*)sub_w + 9;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        ewk->wu.cg_att_ix = 0;
        ewk->wu.cg_hit_ix = 0;
        break;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
            return;
        }
        if (mwk->wu.routine_no[0] >= 2 || mwk->wu.routine_no[1] >= 2) {
            ewk->wu.routine_no[0] = 2;
            ewk->wu.disp_flag = 0;
            return;
        }
        if (!EXE_flag && !Game_pause && mwk->wu.hit_stop <= 0) {
            if (--ewk->wu.dir_timer == 0) {
                ewk->wu.routine_no[0] = 2;
                return;
            }
            ewk->wu.position_x = image_buff[ewk->wu.dir_step].pos_x;
            ewk->wu.position_y = image_buff[ewk->wu.dir_step].pos_y;
        }
        ewk->wu.old_cgnum = ewk->wu.cg_number = mwk->wu.cg_number;
        ewk->wu.rl_flag = mwk->wu.rl_flag;
        ewk->wu.spr.gfx_ofs = mwk->wu.spr.gfx_ofs;
        ewk->wu.spr.gfx_cells = mwk->wu.spr.gfx_cells;
        ewk->wu.spr.sprite_flip = mwk->wu.spr.sprite_flip;
        ewk->wu.cg_flip = mwk->wu.cg_flip;
        ewk->wu.spr.done_rl = mwk->wu.spr.done_rl;
        break;
    case 2:
        ewk->wu.routine_no[0] = 3;
        return;
    default:
        all_cgps_put_back(&ewk->wu);
        push_effect_work(&ewk->wu);
        return;
    }
    sort_push_request(&ewk->wu);
}



s32 effect_J0_init(WORK_Other* ek, WORK_Other* mk, s16 data) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.disp_flag = 2;
    ewk->wu.id = 190;
    ewk->wu.old_cgnum = ek->wu.cg_number = mk->wu.cg_number;
    ewk->wu.dir_step = data;
    ewk->wu.position_x = ewk->wu.old_pos[0] = mk->wu.position_x;
    ewk->wu.position_y = ewk->wu.old_pos[1] = mk->wu.position_y;
    ewk->wu.rl_flag = mk->wu.rl_flag;
    ewk->wu.cg_flip = mk->wu.cg_flip;
    ewk->wu.blink_timing = mk->wu.blink_timing;
    ewk->wu.spr.gfx_ofs = mk->wu.spr.gfx_ofs;
    ewk->wu.spr.gfx_cells = mk->wu.spr.gfx_cells;
    ewk->wu.spr.sprite_flip = mk->wu.spr.sprite_flip;
    ewk->wu.spr.done_rl = mk->wu.spr.done_rl;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = mk->wu.my_family;
    ewk->wu.cgromtype = mk->wu.cgromtype;
    ewk->wu.my_col_mode = mk->wu.my_col_mode;
    ewk->wu.my_col_code = mk->wu.my_col_code;
    ewk->wu.extra_col = mk->wu.current_colcd;
    ewk->my_master = (u32*)mk;
    ewk->wu.target_adrs = (u32*)ek;
    ewk->master_id = mk->wu.id;
    ewk->master_player = mk->master_player;
    ewk->wu.dir_timer = ek->wu.dir_timer;
    return 0;
}



void effect_J1_move(void)
{
  return;
}



void effect_J2_move(WORK_Other_CONN* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        switch (ewk->wu.routine_no[1]) {
        case 0:
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
            ewk->wu.old_cgnum = 0;
            break;
        default:
            break;
        }
        if (--ewk->wu.dir_timer > 0) {
            break;
        }
        ewk->wu.routine_no[0] = 1;
        ewk->wu.routine_no[1] = 0;
        ewk->wu.disp_flag = 1;
        ewk->wu.old_cgnum = 0;
        ewk->wu.dir_timer = 60;
        ewk->wu.position_z = ewk->wu.my_priority = 27;
        ewk->conn[0].chr += Bonus_Stage_Level % 10;
        break;
    case 1:
        if (ewk->wu.dead_f == 1 || Break_Into || --ewk->wu.dir_timer <= 0) {
            ewk->wu.disp_flag = 0;
            ewk->wu.routine_no[0] = 2;
        } else {
            effJ2_trans(&ewk->wu);
        }
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
void effJ2_trans(WORK* ewk) {
    ewk->cg_number = (ewk->cg_number + 1) & 0x7FFF;
    if (ewk->cg_number == 0) {
        ewk->cg_number = 1;
    }
    ewk->position_x = bg_w.bgw[1].wxy[0].disp.pos;
    ewk->position_y = bg_w.bgw[1].wxy[1].disp.pos;
    sort_push_request3(ewk);
}


s32 effect_J2_init(s16 delay) {
    WORK_Other_CONN* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other_CONN*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 192;
    ewk->wu.work_id = 16;
    ewk->wu.my_family = 2;
    ewk->wu.cgromtype = 1;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 92;
    ewk->wu.dir_timer = delay;
    ewk->num_of_conn = 2;
    ewk->conn[0] = bbbs_nando_large[0];
    ewk->conn[1] = bbbs_nando_large[1];
    return 0;
}

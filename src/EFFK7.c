/*
 * EFFK7.C  Effect K7: metamorphosis super art controller (character 19)
 *
 * Effect K7 is created by Att_METAMORPHOSE (plpat19) and supervises the player while the
 * metamorphosis super art runs.
 * Type 0 (K7_move_type_0) turns the player into the opponent: at the marked animation frame it
 * takes the opponent's character number and charset, reloads base data (set_base_data_metamor)
 * and the attack/defence ratings and borrows the opponent's colours; when the art expires or a
 * rebirth check fires it plays the return animation and restores the original character.
 * Type 1 (K7_move_type_1) blinks the player from K7_blink_tbl while the art is active and
 * switches to K7_last_tbl when the gauge is nearly spent.
 * On exit the routine restores colour, display and the default attack/defence values.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "PLCNTDAT.h"
#include "meta_col.h"
#include "Com_Pl.h"
#include "EFFECT.h"
#include "end_sub.h"
#include "CHARMOVE.h"
#include "EFFK7.h"
void effect_K7_move(WORK_Other* ewk) {
    PLW* mwk = (PLW*)ewk->my_master;

    switch (ewk->wu.routine_no[0]) {
    case 0:
        if (ewk->wu.type) {
            ewk->wu.routine_no[0] = 1;
            break;
        }
        ewk->wu.routine_no[0] = 1;
        metamor_color_store(mwk->wu.id);
        return;
    case 1:
        if (ewk->wu.dead_f == 1) {
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (mwk->metamor_index != ewk->wu.myself) {
            ewk->wu.routine_no[0] = 2;
            break;
        }
        if (EXE_flag != 0) {
            break;
        }
        if (Game_pause != 0) {
            break;
        }
        if (ewk->wu.type) {
            K7_move_type_1(ewk, mwk);
            return;
        }
        K7_move_type_0(ewk, mwk);
        return;
    case 2:
        mwk->metamorphose = 0;
        mwk->metamor_over = 0;
        mwk->att_plus = 8;
        mwk->def_plus = 8;
        mwk->wu.my_col_mode = ewk->wu.my_col_mode;
        mwk->wu.my_col_code = ewk->wu.my_col_code;
        mwk->wu.disp_flag = 1;
    default:
        push_effect_work(&ewk->wu);
        return;
    }
}



/* provisional name */
void K7_move_type_1(WORK_Other* ewk, PLW* mwk) {
    const s16(*blink)[4] = K7_blink_tbl;
    const s16(*last)[4] = K7_last_tbl;
    SA_WORK* sa;
    if (mwk->sa->ok != -1 || mwk->dead_flag) {
        ewk->wu.routine_no[0] = 2;
        return;
    }
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (mwk->wu.cg_type != 20) {
            return;
        }
        ewk->wu.routine_no[1] = 1;
        ewk->wu.dir_step = 0;
        ewk->wu.dir_old = blink[ewk->wu.dir_step][3];
        ewk->wu.dir_timer = blink[ewk->wu.dir_step][0];
        mwk->wu.disp_flag = blink[ewk->wu.dir_step][1];
        mwk->wu.my_col_mode = blink[ewk->wu.dir_step][2];
    case 1:
        if (ewk->wu.dir_step > 2) {
            sa = mwk->sa;
            if ((sa->gauge.i - 0x10000) / (sa->dtm * sa->dtm_mul) <= 45) {
                ewk->wu.routine_no[1] = 2;
                ewk->wu.dir_step = 0;
                ewk->wu.dir_old = last[ewk->wu.dir_step][3];
                ewk->wu.dir_timer = last[ewk->wu.dir_step][0];
                mwk->wu.disp_flag = last[ewk->wu.dir_step][1];
                mwk->wu.my_col_mode = last[ewk->wu.dir_step][2];
                if (ewk->wu.dir_old) {
                    K7_col_mode_flip(&mwk->wu);
                }
                break;
            }
        }
        if (--ewk->wu.dir_timer < 0) {
            do {
                ewk->wu.dir_step++;
            } while (blink[ewk->wu.dir_step][0] == 0);
            if (blink[ewk->wu.dir_step][0] == -1) {
                ewk->wu.dir_step = blink[ewk->wu.dir_step][1];
            }
            ewk->wu.dir_old = blink[ewk->wu.dir_step][3];
            ewk->wu.dir_timer = blink[ewk->wu.dir_step][0];
            mwk->wu.disp_flag = blink[ewk->wu.dir_step][1];
            mwk->wu.my_col_mode = blink[ewk->wu.dir_step][2];
        }
        if (ewk->wu.dir_old) {
            K7_col_mode_flip(&mwk->wu);
        }
        break;
    case 2:
        if (--ewk->wu.dir_timer < 0) {
            do {
                ewk->wu.dir_step++;
            } while (blink[ewk->wu.dir_step][0] == 0);
            if (last[ewk->wu.dir_step][0] == -1) {
                ewk->wu.routine_no[0] = 2;
                break;
            }
            ewk->wu.dir_old = last[ewk->wu.dir_step][3];
            ewk->wu.dir_timer = last[ewk->wu.dir_step][0];
            mwk->wu.disp_flag = last[ewk->wu.dir_step][1];
            mwk->wu.my_col_mode = last[ewk->wu.dir_step][2];
        }
        if (ewk->wu.dir_old) {
            K7_col_mode_flip(&mwk->wu);
        }
        break;
    }
}



/* provisional name */
void K7_col_mode_flip(WORK* wk) {
    if (wk->my_col_mode == 0x4400) {
        wk->my_col_mode = 0x4200;
    } else {
        wk->my_col_mode = 0x4400;
    }
}



void K7_move_type_0(WORK_Other* ewk, PLW* mwk) {
    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (mwk->wu.cg_type != 20) {
            break;
        }
        ewk->wu.routine_no[1] = 1;
        ewk->wu.direction = mwk->player_number;
        ewk->wu.charset_id = mwk->wu.charset_id;
        mwk->player_number = ((PLW*)mwk->wu.target_adrs)->player_number;
        mwk->wu.charset_id = ((PLW*)mwk->wu.target_adrs)->wu.charset_id;
        set_base_data_metamor(mwk);
        mwk->att_plus = 10;
        mwk->def_plus = 6;
        if (mwk->wu.operator == 0) {
            Next_Be_Free(mwk);
        }
        break;
    case 1:
        if (mwk->wu.cg_type != 30) {
            break;
        }
        ewk->wu.routine_no[1] = 2;
        metamor_color_trans(mwk->wu.id, mwk->player_number);
        metamor_color_copy(mwk->wu.id);
        mwk->metamorphose = 1;
    case 2:
        if (mwk->dead_flag != 0) {
            ewk->wu.routine_no[1] = 9;
            break;
        }
        if (mwk->sa->ok == -1) {
            break;
        }
        ewk->wu.routine_no[1] = 3;
        mwk->metamor_over = 1;
    case 3:
        if (K7_mt0_rebirth_check(mwk) == 0) {
            break;
        }
        ewk->wu.routine_no[1] = 4;
        mwk->wu.routine_no[1] = 4;
        mwk->wu.routine_no[2] = 33;
        mwk->wu.routine_no[3] = 0;
        mwk->metamor_over = 0;
        mwk->wu.cg_type = 0;
        mwk->wu.cg_hit_ix = 0;
        mwk->wu.cg_ja = mwk->wu.hit_ix_table[mwk->wu.cg_hit_ix];
        set_jugde_area(&mwk->wu);
        break;
    case 4:
        if (mwk->wu.cg_type != 30) {
            break;
        }
        ewk->wu.routine_no[1] = 5;
        mwk->player_number = ewk->wu.direction;
        mwk->wu.charset_id = ewk->wu.charset_id;
        set_base_data_metamor(mwk);
        metamor_color_restore(mwk->wu.id);
        metamor_color_reset(mwk->wu.id);
        if (mwk->wu.operator == 0) {
            Next_Be_Free(mwk);
        }
        break;
    case 5:
        ewk->wu.routine_no[0] = 2;
        break;
    }
}



s32 K7_mt0_rebirth_check(PLW* mwk) {
    s16 num = 0;

    switch (mwk->wu.routine_no[1]) {
    case 0:
        if (pcon_dp_flag) {
            if (mwk->wu.routine_no[2] == 1 && mwk->wu.routine_no[3] != 0) {
                num = 1;
            }
        } else {
            if ((u8)mwk->guard_flag != 3 && !mwk->wu.hit_stop) {
                num = 1;
            }
        }
        break;
    default:
        break;
    }
    return num;
}



s32 effect_K7_init(PLW* wk) {
    WORK_Other* ewk;
    s16 ix;
    if (test_flag) {
        return -1;
    }
    if ((ix = pull_effect_work(0)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 207;
    ewk->wu.work_id = 16;
    ewk->wu.type = 0;
    ewk->my_master = (u32*)wk;
    wk->metamor_index = ewk->wu.myself;
    ewk->wu.my_col_mode = 0x4200;
    ewk->wu.my_col_code = 0x2000;
    if (wk->wu.id) {
        ewk->wu.my_col_code += 16;
    }
    return 0;
}

/*
 * EFFI3.C  Effect I0 spawner, effect I2 (palette cycle), effect I3 (BG stop) and empty I1
 *
 * effect_I0_init scatters num_of_koishi[] stone pieces around a work: a random layout from
 * koishi_app_area picks each piece's offset (koishi_area_hosei) and speeds (koishi_speed_x /
 * _y), and effI0_piece_set creates the I0 work with gravity and a landing height.
 * Effect I2 cycles a palette: every time its timer from effI2_timer_tbl runs out it moves to the
 * next of ten steps and loads the palette in effI2_col_tbl. It is freed on Suicide[0].
 * Effect I3 (effect_I3_init, called from player move code) sets bg_stop to hold the background
 * scroll while an action plays; its i3_data entry gives the duration (fixed, the owner's hit
 * stop or frame type) and whether it also ends when the owner's pattern changes.
 * effect_I1_move is an empty routine.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "EFFECT.h"
#include "PLS02.h"
#include "aboutspr.h"
#include "EFFI3.h"



/* provisional name */
s32 effI0_piece_set(WORK* wk, s16 hsx, s16 hsy, s16 spx, s16 spy, s16 nxy) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 0xB4;
    ewk->wu.work_id = 0x10;
    ewk->wu.rl_flag = wk->rl_flag;
    ewk->wu.my_family = wk->my_family;
    ewk->wu.cgromtype = 1;
    ewk->wu.next_y = nxy;
    ewk->wu.mvxy.a[0].sp = spx << 8;
    ewk->wu.mvxy.d[0].sp = 0;
    ewk->wu.mvxy.a[1].sp = spy << 8;
    ewk->wu.mvxy.d[1].sp = -0x8000U;
    if (ewk->wu.rl_flag) {
        ewk->wu.xyz[0].disp.pos = wk->position_x - hsx;
    } else {
        ewk->wu.xyz[0].disp.pos = wk->position_x + hsx;
    }
    ewk->wu.xyz[1].disp.pos = wk->position_y + hsy;
    ewk->wu.position_z = wk->position_z + 1;
    ewk->wu.char_table[0] = plef_char_table;
    return 0;
}



void effect_I0_init(WORK* wk, u8 num) {
    s16* dix;
    s16 i;
    s16 hsx;
    s16 hsy;
    s16 spx;
    s16 spy;
    s16 nxy;
    dix = (s16*)koishi_app_area[random_16_com() & 7];
    for (i = 0; i < num_of_koishi[num]; i++) {
        hsx = (koishi_area_hosei[dix[i]] + (random_16_com() - 7));
        hsy = -(random_16_com() & 3);
        nxy = (hsy - (random_16_com() & 3));
        spx = koishi_speed_x[dix[i]][random_16_com() & 7];
        spy = koishi_speed_y[dix[i]][random_16_com() & 7];
        effI0_piece_set(wk, hsx, hsy, spx, spy, nxy);
    }
}



void effect_I1_move(void)
{
  return;
}



s32 effect_I2_init(void) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 182;
    ewk->wu.operator = 0;
    ewk->wu.type = effI2_timer_tbl[0];
    return 0;
}



void effect_I2_move(WORK_Other* ewk) {
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
    case 1:
        if (Suicide[0]) {
            all_cgps_put_back(ewk);
            push_effect_work((WORK*)ewk);
            break;
        }
        ewk->wu.type--;
        if (ewk->wu.type == 0) {
            ewk->wu.operator++;
            if (ewk->wu.operator > 9) {
                ewk->wu.operator = 0;
            }
            ewk->wu.type = effI2_timer_tbl[ewk->wu.operator];
            load_any_color(effI2_col_tbl[ewk->wu.operator]);
        }
        break;
    case 2:
    default:
        push_effect_work((WORK*)ewk);
        break;
    }
}



void effect_I3_move(WORK_Other* ewk) {
    WORK* mwk = (WORK*)ewk->my_master;
    switch (ewk->wu.routine_no[0]) {
    case 0:
        ewk->wu.routine_no[0]++;
        bg_stop = 1;
        switch (i3_data[ewk->wu.type].sour) {
        case 1:
            if ((ewk->wu.dir_timer = ewk->wu.hit_stop) < 0) {
                ewk->wu.dir_timer = -ewk->wu.dir_timer;
            }
            break;
        case 2:
            ewk->wu.dir_timer = ewk->wu.cg_type;
            break;
        default:
            ewk->wu.dir_timer = i3_data[ewk->wu.type].tm;
            break;
        }
    case 1:
        if (ewk->wu.dead_f == 1 || Suicide[0] != 0) {
            ewk->wu.routine_no[0]++;
            break;
        }
        if (EXE_flag != 0 || Game_pause != 0) {
            break;
        }
        if ((i3_data[ewk->wu.type].flag & 1 && --ewk->wu.dir_timer < 0) ||
            (i3_data[ewk->wu.type].flag & 2 &&
             (ewk->wu.now_koc != mwk->now_koc || ewk->wu.char_index != mwk->char_index))) {
            ewk->wu.routine_no[0] = 2;
        }
        break;
    case 2:
    default:
        bg_stop = 0;
        push_effect_work(&ewk->wu);
        break;
    }
}



s32 effect_I3_init(WORK* wk, u8 tix) {
    WORK_Other* ewk;
    s16 ix;
    if ((ix = pull_effect_work(3)) == -1) {
        return -1;
    }
    ewk = (WORK_Other*)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 183;
    ewk->wu.work_id = 16;
    ewk->my_master = (u32*)wk;
    ewk->wu.type = tix;
    ewk->wu.cg_type = wk->cg_type;
    ewk->wu.hit_stop = wk->hit_stop;
    ewk->wu.now_koc = wk->now_koc;
    ewk->wu.char_index = wk->char_index;
    return 0;
}

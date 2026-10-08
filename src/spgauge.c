/*
 * spgauge.c  Super art gauge display
 *
 * Draws and animates the super art gauge for both players on the text layer.
 * spgauge_cont_init (and spgauge_cont_demo_init for attract mode) set each player's gauge work
 * from the chosen super art: stock count, gauge length and colour. spgauge_cont_main runs every
 * frame and calls spgauge_control per player, which follows the player's gauge value, plays the
 * gauge sounds, and reacts to the gauge flash requests: super art activation, EX move use and
 * reaching full stock start the "SA"/"EX"/"MAX" lettering (samoji_control, sast_control) and the
 * gauge colour changes (sagauge_color_chenge, sa_gauge_color_set).
 * wipe_check restores the gauge after a screen wipe, and the *_trans routines write the gauge
 * cells, frame, stock digits and lettering.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLMAIN.h"
#include "SE.h"
#include "se_2.h"
#include "se_3.h"
#include "spgauge.h"
#include "fighter.h"



void spgauge_cont_init(void) {
    s8 lpy;
    spg_dat[0].current_spg = 0;
    spg_dat[0].old_spg = 0;
    spg_dat[0].spgcol_number = 34;
    spg_dat[0].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[0].spg_level = 0;
    spg_dat[0].spg_maxlevel = super_arts[0].store_max;
    spg_dat[0].spg_len = super_arts[0].gauge_len / 8;
    spg_dat[0].spg_dotlen = super_arts[0].gauge_len;
    spg_dat[0].flag = 0;
    spg_dat[0].flag2 = 0;
    spg_dat[0].timer = 60;
    spg_dat[0].timer2 = 2;
    spg_dat[0].kind = 0;
    spg_dat[0].max = 0;
    spg_dat[0].max_old = 0;
    spg_dat[0].max_rno = 0;
    spg_dat[0].time_rno = 0;
    spg_dat[0].gauge_flash_time = 2;
    spg_dat[0].gauge_flash_col = 0;
    spg_dat[0].sa_flag = 0;
    spg_dat[0].ex_flag = 0;
    spg_dat[0].no_chgcol = 0;
    spg_dat[0].time_no_clear = 0;
    sa_gauge_flash[0] = spg_dat[0].sa_mukou = 0;
    if (super_arts[0].gauge_type == 1) {
        spg_dat[0].time = 1;
        time_flag[0] = 1;
    } else {
        spg_dat[0].time = 0;
        time_flag[0] = 0;
    }
    spg_dat[1].current_spg = 0;
    spg_dat[1].old_spg = 0;
    spg_dat[1].spgcol_number = 162;
    spg_dat[1].spgtbl_ptr = spgauge_puttbl[0];
    spg_dat[1].spg_level = 0;
    spg_dat[1].spg_maxlevel = super_arts[1].store_max;
    spg_dat[1].spg_len = super_arts[1].gauge_len / 8;
    spg_dat[1].spg_dotlen = super_arts[1].gauge_len;
    spg_dat[1].flag = 0;
    spg_dat[1].flag2 = 0;
    spg_dat[1].timer = 60;
    spg_dat[1].timer2 = 2;
    spg_dat[1].kind = 0;
    spg_dat[1].max = 0;
    spg_dat[1].max_old = 0;
    spg_dat[1].max_rno = 0;
    spg_dat[1].time_rno = 0;
    spg_dat[1].gauge_flash_time = 2;
    spg_dat[1].gauge_flash_col = 0;
    spg_dat[1].sa_flag = 0;
    spg_dat[1].ex_flag = 0;
    spg_dat[1].no_chgcol = 0;
    spg_dat[1].time_no_clear = 0;
    spg_dat[1].sa_mukou = 0;
    sa_gauge_flash[1] = 0;
    if (super_arts[1].gauge_type == 1) {
        spg_dat[1].time = 1;
        time_flag[1] = 1;
    } else {
        spg_dat[1].time = 0;
        time_flag[1] = 0;
    }
    spg_dat[0].spgptbl_ptr = spgauge_postbl[0];
    spg_dat[1].spgptbl_ptr = spgauge_postbl[1];
    for (lpy = 0; lpy < 2; lpy++) {
        spg_dat[lpy].mass_len = spg_dat[lpy].spg_len - 5;
        if (spg_dat[lpy].spg_len & 1) {
            spg_dat[lpy].mchar = 5;
            spg_dat[lpy].mass_odd = 1;
        } else {
            spg_dat[lpy].mass_len = spg_dat[lpy].mass_len - 1;
            spg_dat[lpy].mchar = 6;
            spg_dat[lpy].mass_odd = 0;
        }
        spg_dat[lpy].mass_len /= 2;
    }
    sa_stock_trans(0, 0, 0);
    sa_stock_trans(0, 0, 1);
    sa_max_level_trans(0, spg_dat[0].spg_maxlevel);
    sa_max_level_trans(1, spg_dat[1].spg_maxlevel);
    sa_number_trans();
    sa_gauge_trans(0, 0);
    sa_gauge_trans(1, 0);
    sa_waku_trans(0, 0);
    sa_waku_trans(1, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    spg_col = 0;
}



void spgauge_cont_demo_init(void) {
    u8 lpy;
    do { SPG_DAT* spg = &spg_dat[0]; demo_set_sa_full(&super_arts[0]); spg->current_spg = super_arts[0].gauge_len; spg->old_spg = super_arts[0].gauge_len; spg->spgcol_number = 34; spg->spgtbl_ptr = spgauge_puttbl[0]; spg->spg_level = super_arts[0].store; spg->spg_maxlevel = super_arts[0].store_max; spg->spg_len = super_arts[0].gauge_len / 8; spg->spg_dotlen = super_arts[0].gauge_len; spg->flag = 0; spg->flag2 = 0; spg->timer = 60; spg->timer2 = 2; spg->kind = 1; spg->max = 1; spg->max_old = 0; spg->max_rno = 2; spg->time_rno = 0; spg->gauge_flash_time = 2; spg->gauge_flash_col = 0; spg->sa_flag = 0; spg->ex_flag = 0; spg->no_chgcol = 0; spg->time_no_clear = 0; spg->sa_mukou = 0; sa_gauge_flash[0] = 0; if (super_arts[0].gauge_type == 1) { spg->time = 1; time_flag[0] = 1; } else { spg->time = 0; time_flag[0] = 0; } } while (0);
    do { SPG_DAT* spg = &spg_dat[1]; demo_set_sa_full(&super_arts[1]); spg->current_spg = super_arts[1].gauge_len; spg->old_spg = super_arts[1].gauge_len; spg->spgcol_number = 162; spg->spgtbl_ptr = spgauge_puttbl[0]; spg->spg_level = super_arts[1].store; spg->spg_maxlevel = super_arts[1].store_max; spg->spg_len = super_arts[1].gauge_len / 8; spg->spg_dotlen = super_arts[1].gauge_len; spg->flag = 0; spg->flag2 = 0; spg->timer = 60; spg->timer2 = 2; spg->kind = 1; spg->max = 1; spg->max_old = 0; spg->max_rno = 2; spg->time_rno = 0; spg->gauge_flash_time = 2; spg->gauge_flash_col = 0; spg->sa_flag = 0; spg->ex_flag = 0; spg->no_chgcol = 0; spg->time_no_clear = 0; spg->sa_mukou = 0; sa_gauge_flash[1] = 0; if (super_arts[1].gauge_type == 1) { spg->time = 1; time_flag[1] = 1; } else { spg->time = 0; time_flag[1] = 0; } } while (0);
    spg_dat[0].spgptbl_ptr = spgauge_postbl[0];
    spg_dat[1].spgptbl_ptr = spgauge_postbl[1];
    for (lpy = 0; lpy < 2; lpy++) {
        SPG_DAT* spg = &spg_dat[lpy];
        spg->mass_len = spg->spg_len - 5;
        if (spg->spg_len & 1) {
            spg->mchar = 5;
            spg->mass_odd = 1;
        } else {
            spg->mass_len = spg->mass_len - 1;
            spg->mchar = 6;
            spg->mass_odd = 0;
        }
        spg->mass_len /= 2;
    }
    sa_stock_trans(spg_dat[0].spg_maxlevel, 1, 0);
    sa_stock_trans(spg_dat[1].spg_maxlevel, 1, 1);
    sa_max_level_trans(0, spg_dat[0].spg_maxlevel);
    sa_max_level_trans(1, spg_dat[1].spg_maxlevel);
    sa_number_trans();
    sa_gauge_trans(0, 1);
    sa_gauge_trans(1, 1);
    sa_waku_trans(0, 0);
    sa_waku_trans(1, 1);
    sa_moji_trans(0, 0, 1);
    sa_moji_trans(1, 0, 1);
    Old_Stop_SG = 0;
    Exec_Wipe_F = 0;
    time_clear[0] = 0;
    time_clear[1] = 0;
    spg_offset = 0;
    time_num = 0;
    time_timer = 3;
    spg_col = 1;
}



void spgauge_cont_main(void) {
    if (Stop_SG) {
        wipe_check();
        Old_Stop_SG = Stop_SG;
        return;
    } else {
        if (Old_Stop_SG) {
            Old_Stop_SG = 0;
            Exec_Wipe_F = 0;
            time_clear[0] = 0;
            time_clear[1] = 0;
        }
        sa_time_moji_send();
        if (gauge_stop_flag[0] == 0) {
            spgauge_control(0);
        }
        if (gauge_stop_flag[1] == 0) {
            spgauge_control(1);
        }
    }
}



void spgauge_control(s8 Spg_Num) {
    if (sa_gauge_flash[Spg_Num]) {
        spgauge_sound_request(Spg_Num);
        if (plw[Spg_Num].sa->store == plw[Spg_Num].sa->store_max && spg_dat[Spg_Num].max_old == 0 && spg_dat[Spg_Num].max == 0) {
            spg_dat[Spg_Num].max = 1;
        } else {
            spg_dat[Spg_Num].max = 0;
        }
        spg_dat[Spg_Num].flag = 1;
        spg_dat[Spg_Num].max_rno = 0;
        spg_dat[Spg_Num].time_rno = 0;
        spg_dat[Spg_Num].timer2 = 2;
        spg_dat[Spg_Num].kind = 0;
        spg_dat[Spg_Num].no_chgcol = 0;
        if (plw[Spg_Num].sa->ok == -1 || plw[Spg_Num].sa->mp == -1) {
            spg_dat[Spg_Num].sa_flag = 1;
            spg_dat[Spg_Num].timer = 60;
            if (Conclusion_Flag != 0) {
                spg_dat[Spg_Num].time_no_clear = 1;
                if (My_char[Spg_Num] == PL_GILL && plw[Spg_Num].sa->ok == -1) {
                    spg_dat[Spg_Num].sa_mukou = 0;
                } else {
                    spg_dat[Spg_Num].sa_mukou = 1;
                }
            }
            sa_gauge_flash[Spg_Num] &= ~4;
        } else if (plw[Spg_Num].sa->ex == -1) {
            if (Conclusion_Flag != 0) {
                spg_dat[Spg_Num].sa_mukou = 1;
            }
            spg_dat[Spg_Num].ex_flag = 1;
            spg_dat[Spg_Num].timer = 20;
            sa_gauge_flash[Spg_Num] &= ~2;
        } else {
            spg_dat[Spg_Num].timer = 35;
            sa_gauge_flash[Spg_Num] &= ~1;
        }
    }
    if (spg_dat[Spg_Num].max != 0) {
        sast_control(Spg_Num);
    } else if (spg_dat[Spg_Num].flag != 0) {
        samoji_control(Spg_Num);
    }
    if (plw[Spg_Num].sa->ex != 0 || spg_dat[Spg_Num].ex_flag == 1 || spg_dat[Spg_Num].sa_flag == 1) {
        sagauge_color_chenge(Spg_Num);
    }
    if (spg_dat[Spg_Num].current_spg != plw[Spg_Num].sa->gauge.s.h || spg_dat[Spg_Num].max != 0) {
        if (spg_dat[Spg_Num].max != 0) {
            spg_dat[Spg_Num].current_spg = spg_dat[Spg_Num].spg_dotlen;
        } else {
            spg_dat[Spg_Num].current_spg = plw[Spg_Num].sa->gauge.s.h;
        }
        if (spg_dat[Spg_Num].max == 0 && spg_dat[Spg_Num].flag == 0) {
            if (spg_dat[Spg_Num].max_old == 0) {
                sa_waku_trans(Spg_Num, Spg_Num);
            }
        }
    }
}



void wipe_check(void) {
    PLW* pl;
    if (Old_Stop_SG) {
        if (Exec_Wipe != 0) {
            return;
        }
        if (Exec_Wipe_F != 0) {
            return;
        }
        Exec_Wipe_F = 1;
        if (spg_dat[0].time == 1 && time_clear[0] == 1) {
            if (spg_dat[0].time_no_clear == 0) {
                spgauge_work_clear(0);
                tilemap_clear_rect(1, 25, 4, 26);
                spgauge_wipe_write(0);
            } else {
                satime_ko_after_clear(0);
            }
        }
        if (spg_dat[1].time == 1 && time_clear[1] == 1) {
            if (spg_dat[1].time_no_clear == 0) {
                spgauge_work_clear(1);
                tilemap_clear_rect(43, 25, 46, 26);
                spgauge_wipe_write(1);
            } else {
                satime_ko_after_clear(1);
            }
        }
        return;
    }
    pl = &plw[0];
    if (pl->sa->ok == -1) {
        pl->sa->ok = 0;
        time_clear[0] = 1;
        pl->sa->gauge.i = 0;
        spg_dat[0].current_spg = 0;
        spg_dat[0].spg_level = 0;
    }
    pl = &plw[1];
    if (pl->sa->ok == -1) {
        pl->sa->ok = 0;
        time_clear[1] = 1;
        pl->sa->gauge.i = 0;
        spg_dat[1].current_spg = 0;
        spg_dat[1].spg_level = 0;
    }
}



void satime_ko_after_clear(s8 pl) {
    spg_dat[pl].max = 0;
    spg_dat[pl].max_old = 1;
    spg_dat[pl].kind = 1;
    spg_dat[pl].timer2 = 2;
    spg_dat[pl].max_rno = 2;
    spg_dat[pl].time_rno = 5;
}



void sa_time_moji_send(void) {
    if (time_flag[0] != 0 || time_flag[1] != 0) {
        time_timer--;
        if (time_timer == 0) {
            if (time_flag[0]) {
                sc_chr_block_trans((u16)sa_time_data_tbl[time_num][0], 0x100, 8, 1);
            }
            if (time_flag[1]) {
                sc_chr_block_trans((u16)sa_time_data_tbl[time_num][1], 0x108, 8, 1);
            }
            time_timer = 3;
            if (time_num == 5) {
                time_num = 0;
            } else {
                time_num++;
            }
        }
    }
}



void sast_control(s8 Stpl_Num) {
    switch (spg_dat[Stpl_Num].max_rno) {
    case 0:
        sa_moji_trans(Stpl_Num, 0, 1);
        spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
        sa_gauge_trans(Stpl_Num, 1);
        sagauge_color_chenge(Stpl_Num);
        spg_dat[Stpl_Num].max_rno = 1;
        break;
    case 1:
        spg_dat[Stpl_Num].timer--;
        if (spg_dat[Stpl_Num].timer) {
            spg_dat[Stpl_Num].timer2--;
            if (spg_dat[Stpl_Num].timer2 != 0) {
                break;
            }
            spg_dat[Stpl_Num].kind++;
            if (spg_dat[Stpl_Num].kind == 3) {
                spg_dat[Stpl_Num].kind = 0;
            }
            sa_gauge_trans(Stpl_Num, spg_dat[Stpl_Num].kind);
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_dat[Stpl_Num].kind, Stpl_Num);
            spg_dat[Stpl_Num].timer2 = 1;
        } else {
            sa_gauge_trans(Stpl_Num, 1);
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num);
            spg_dat[Stpl_Num].max = 0;
            spg_dat[Stpl_Num].max_old = 1;
            spg_dat[Stpl_Num].kind = 1;
            spg_dat[Stpl_Num].timer2 = 2;
            spg_dat[Stpl_Num].max_rno = 2;
            spg_dat[Stpl_Num].time_rno = 5;
        }
        break;
    case 2:
        break;
    }
}



void samoji_control(s8 Stpl_Num) {
    if (spg_dat[Stpl_Num].time) {
        switch (spg_dat[Stpl_Num].time_rno) {
        case 0:
            if (plw[Stpl_Num].sa->ok != -1) {
                spg_dat[Stpl_Num].time_rno = 3;
                goto case_3;
            }
            spg_dat[Stpl_Num].time_rno = 1;
        case 1:
            spg_dat[Stpl_Num].timer--;
            if ((!spg_dat[Stpl_Num].sa_mukou || spg_dat[Stpl_Num].timer != 0) && spg_dat[Stpl_Num].spg_level == plw[Stpl_Num].sa->store) {
                do { spg_dat[Stpl_Num].timer2--; if (spg_dat[Stpl_Num].kind == 0) { if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num); sa_gauge_trans(Stpl_Num, 0); spg_dat[Stpl_Num].kind = 1; spg_dat[Stpl_Num].timer2 = 2; } } else if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num); sa_gauge_trans(Stpl_Num, 1); spg_dat[Stpl_Num].kind = 0; spg_dat[Stpl_Num].timer2 = 2; } } while (0);
                return;
            }
            if (spg_dat[Stpl_Num].sa_flag == 0 || spg_dat[Stpl_Num].sa_mukou != 0) {
                goto jump;
            }
            sa_gauge_trans(Stpl_Num, 1);
            sa_moji_trans(Stpl_Num, 1, 1);
            sa_gauge_color_set(Stpl_Num);
            spg_dat[Stpl_Num].time_rno = 2;
            spg_dat[Stpl_Num].no_chgcol = 1;
        case 2:
            if (spg_dat[Stpl_Num].current_spg > 0 && plw[Stpl_Num].sa->ok == -1) {
                if (spg_dat[Stpl_Num].current_spg != spg_dat[Stpl_Num].old_spg) {
                    sa_waku_trans(Stpl_Num, Stpl_Num);
                }
                spg_dat[Stpl_Num].old_spg = spg_dat[Stpl_Num].current_spg;
                return;
            }
            spg_dat[Stpl_Num].time_rno = 4;
            return;
        case 3:
        case_3:
            spg_dat[Stpl_Num].timer--;
            if (spg_dat[Stpl_Num].timer != 0) {
                do { spg_dat[Stpl_Num].timer2--; if (spg_dat[Stpl_Num].kind == 0) { if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num); sa_gauge_trans(Stpl_Num, 0); spg_dat[Stpl_Num].kind = 1; spg_dat[Stpl_Num].timer2 = 2; } } else if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num); sa_gauge_trans(Stpl_Num, 1); spg_dat[Stpl_Num].kind = 0; spg_dat[Stpl_Num].timer2 = 2; } } while (0);
                return;
            }
            spg_dat[Stpl_Num].time_rno = 4;
        case 4:
            if (spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_moji_trans(Stpl_Num, 1, 0);
                spg_dat[Stpl_Num].max_old = 0;
            }
        jump:
            sa_gauge_color_set(Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_col, Stpl_Num);
            sa_gauge_trans(Stpl_Num, spg_col);
            if (spg_dat[Stpl_Num].sa_mukou == 0) {
                sa_waku_trans(Stpl_Num, Stpl_Num);
            }
            spg_dat[Stpl_Num].flag = 0;
            spg_dat[Stpl_Num].time_rno = 5;
            spg_dat[Stpl_Num].max_rno = 0;
            spg_dat[Stpl_Num].sa_flag = 0;
            spg_dat[Stpl_Num].ex_flag = 0;
            spg_dat[Stpl_Num].no_chgcol = 0;
            spg_dat[Stpl_Num].sa_mukou = 0;
            return;
        default:
            return;
        }
    }
    switch (spg_dat[Stpl_Num].max_rno) {
    case 0:
        if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
            spg_dat[Stpl_Num].current_spg = spg_dat[Stpl_Num].spg_dotlen;
            sa_waku_trans(Stpl_Num, Stpl_Num);
            spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
            sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_col, Stpl_Num);
        }
        spg_dat[Stpl_Num].max_rno = 1;
    case 1:
        spg_dat[Stpl_Num].timer--;
        if (spg_dat[Stpl_Num].timer != 0) {
            do { spg_dat[Stpl_Num].timer2--; if (spg_dat[Stpl_Num].kind == 0) { if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 0, Stpl_Num); sa_gauge_trans(Stpl_Num, 0); spg_dat[Stpl_Num].kind = 1; spg_dat[Stpl_Num].timer2 = 2; } } else if (spg_dat[Stpl_Num].timer2 == 0) { sa_stock_trans(spg_dat[Stpl_Num].spg_level, 1, Stpl_Num); sa_gauge_trans(Stpl_Num, 1); spg_dat[Stpl_Num].kind = 0; spg_dat[Stpl_Num].timer2 = 2; } } while (0);
            return;
        }
        if (spg_dat[Stpl_Num].max_old != 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
            sa_moji_trans(Stpl_Num, 0, 0);
            spg_dat[Stpl_Num].max_old = 0;
        }
        sa_gauge_color_set(Stpl_Num);
        spg_dat[Stpl_Num].spg_level = plw[Stpl_Num].sa->store;
        sa_stock_trans(spg_dat[Stpl_Num].spg_level, spg_col, Stpl_Num);
        sa_gauge_trans(Stpl_Num, spg_col);
        if (spg_dat[Stpl_Num].max_old == 0 && spg_dat[Stpl_Num].sa_mukou == 0) {
            sa_waku_trans(Stpl_Num, Stpl_Num);
        }
        spg_dat[Stpl_Num].flag = 0;
        spg_dat[Stpl_Num].max_rno = 2;
        spg_dat[Stpl_Num].sa_flag = 0;
        spg_dat[Stpl_Num].ex_flag = 0;
        spg_dat[Stpl_Num].sa_mukou = 0;
        break;
    }
}




/* provisional name */
void sa_gauge_color_set(s8 pl) {
    if (plw[pl].sa->gauge_type == 1 && plw[pl].sa->ok == -1) {
        spg_col = 1;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 28;
        } else {
            spg_dat[1].spgcol_number = 156;
        }
        return;
    } else if (plw[pl].sa->store != 0) {
        spg_col = 1;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 36;
        } else {
            spg_dat[1].spgcol_number = 164;
        }
    } else {
        spg_col = 0;
        if (pl == 0) {
            spg_dat[0].spgcol_number = 34;
        } else {
            spg_dat[1].spgcol_number = 162;
        }
    }
}



void sa_color_chenge(pl, step)
s8 pl;
s8 step;
{
    SPG_DAT* p0 = &spg_dat[0];
    SPG_DAT* p1 = &spg_dat[1];
    if (spg_dat[pl].kind) {
        if (pl == 0) {
            p0->spgcol_number = step * 2 + 34;
        } else {
            p1->spgcol_number = step * 2 + 162;
        }
    } else {
        if (pl == 0) {
            p0->spgcol_number = 36 - step * 2;
        } else {
            p1->spgcol_number = 164 - step * 2;
        }
    }
}



void sagauge_color_chenge(s8 Stpl_Num) {
    if (spg_dat[Stpl_Num].no_chgcol) {
        return;
    }
    spg_dat[Stpl_Num].gauge_flash_time--;
    if (spg_dat[Stpl_Num].gauge_flash_time != 0) {
        return;
    }
    spg_dat[Stpl_Num].gauge_flash_time = 2;
    if (Stpl_Num == 0) {
        sq_paint_chenge(6, 26, spg_dat[0].spg_len, 1, sagauge_colchg_tbl[spg_dat[0].gauge_flash_col][0]);
    } else if (spg_dat[1].max == 1 || spg_dat[1].max_old == 1 || spg_dat[1].spg_level == spg_dat[1].spg_maxlevel) {
        sq_paint_chenge(42 - spg_dat[1].spg_len, 26, spg_dat[1].mass_len, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
        sq_paint_chenge(42 - spg_dat[1].spg_len + spg_dat[1].mass_len, 26, spg_dat[1].mchar, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][0]);
        sq_paint_chenge(42 - spg_dat[1].spg_len + spg_dat[1].mass_len + spg_dat[1].mchar,
                     26,
                     spg_dat[1].mass_len,
                     1,
                     sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
    } else {
        sq_paint_chenge(42 - spg_dat[1].spg_len, 26, spg_dat[1].spg_len, 1, sagauge_colchg_tbl[spg_dat[1].gauge_flash_col][1]);
    }
    if (spg_dat[Stpl_Num].gauge_flash_col == 3) {
        spg_dat[Stpl_Num].gauge_flash_col = 0;
    } else {
        spg_dat[Stpl_Num].gauge_flash_col++;
    }
}



void sa_moji_trans(Stpl_Num, Kind, OnOff)
    s32 Stpl_Num;
    s8 Kind;
    s8 OnOff;
{
    SPG_DAT* spg;
    switch (Kind) {
    case 0:
        if (OnOff) {
            spg = &spg_dat[Stpl_Num];
            spg->current_spg = spg->spg_dotlen;
            sa_waku_trans(Stpl_Num, Stpl_Num);
            max_mark_write(Stpl_Num, spg->spg_len, (s16)spg->mchar, (s16)spg->mass_len, spg->mass_odd);
        } else {
            sa_waku_trans(Stpl_Num, Stpl_Num);
        }
        break;
    case 1:
    default:
        if ((s8)Stpl_Num == 0) {
            if (OnOff) {
                scfont_lnput(1, 0x19, 4, 2, 0x16, 0x100);
                scfont_lnput(1, 0x1B, 2, 1, 0x16, 0xCD);
            } else {
                tilemap_clear_rect(1, 0x19, 4, 0x1A);
                tilemap_clear_rect(1, 0x1B, 2, 0x1B);
            }
        } else {
            if (OnOff) {
                scfont_lnput(0x2B, 0x19, 4, 2, 0x16, 0x108);
                scfont_lnput_rev(0x2D, 0x1B, 2, 1, 0x16, 0xCD);
            } else {
                tilemap_clear_rect(0x2B, 0x19, 0x2E, 0x1A);
                tilemap_clear_rect(0x2D, 0x1B, 0x2E, 0x1B);
            }
        }
        break;
    }
}



void sa_waku_trans(pl_kind)
s8 pl_kind;
{
    s8 i;
    s32 len;
    const u16* sa_char_ptr;
    SPG_DAT* spg;
    spg_work = 0;
    spg_number = 0;
    sa_char_ptr = spgauge_puttbl[0];
    len = super_arts[pl_kind].gauge_len / 8;
    spg = &spg_dat[pl_kind];
    for (i = 0; i < len; i++) {
        spg_work += 8;
        if (spg_work >= spg->current_spg) {
            if (spg->current_spg >= (spg_work - 8)) {
                spg_offset = spg->current_spg - (i * 8);
                tilemap_put_cell((&spg->spgptbl_ptr[spg_number])[16 - len],
                                 26,
                                 spg->spgcol_number,
                                 sa_char_ptr[spg_offset]);
            } else {
                tilemap_put_cell(
                    (&spg->spgptbl_ptr[spg_number])[16 - len], 26, spg->spgcol_number, sa_char_ptr[0]);
            }
        } else {
            tilemap_put_cell((&spg->spgptbl_ptr[spg_number])[16 - len], 26, spg->spgcol_number, sa_char_ptr[8]);
        }
        spg_number++;
    }
}



void spgauge_sound_request(s8 Stpl_Num) {
    if (plw[Stpl_Num].sa->store > spg_dat[Stpl_Num].spg_level) {
        Sound_SE(Stpl_Num + 107);
    }
}



void spgauge_work_clear(s8 Stpl_Num) {
    SPG_DAT* spg;
    plw[Stpl_Num].sa->gauge.i = 0;
    spg = &spg_dat[Stpl_Num];
    spg->current_spg = 0;
    spg->old_spg = 0;
    spg->spgcol_number = 18;
    spg->spg_level = 0;
    spg->flag = 0;
    spg->flag2 = 0;
    spg->timer = 60;
    spg->timer2 = 2;
    spg->kind = 0;
    spg->max = 0;
    spg->max_old = 0;
    spg->max_rno = 0;
    spg->time_rno = 0;
    spg->gauge_flash_time = 2;
    spg->gauge_flash_col = 0;
    spg->sa_flag = 0;
    spg->ex_flag = 0;
    spg->no_chgcol = 0;
    spg->time_no_clear = 0;
    spg->sa_mukou = 0;
    sa_gauge_flash[Stpl_Num] = 0;
    sa_color_chenge(Stpl_Num, 1);
}



/* provisional name */
void satime_stock_clear(void) {
    if (spg_dat[0].time == 1 && plw[0].sa->ok == -1 && spg_dat[0].time_no_clear == 0) {
        sa_stock_chr_trans(0, 0);
    }
    if (spg_dat[1].time == 1 && plw[1].sa->ok == -1 && spg_dat[1].time_no_clear == 0) {
        sa_stock_chr_trans(1, 0);
    }
}



void spgauge_wipe_write(s32 Stpl_Num) {
    s32 s = (s8)Stpl_Num;
    if (s == 0) {
        tilemap_put_cell(3, 25, 26, 0xD1);
        tilemap_put_cell(3, 26, 26, 0xD2);
    } else {
        tilemap_put_cell(44, 25, 26, 0xD4);
        tilemap_put_cell(44, 26, 26, 0xD5);
    }
    sa_waku_trans(Stpl_Num, Stpl_Num);
    sa_gauge_trans(s, 0);
    return;
}



void sa_gauge_trans(s8 Stpl_Num, s16 Spg_Col) {
    s8 lpy;
    sc_ram_to_vram(Stpl_Num + (Spg_Col * 2) + 6, 0, 0);
    if (!Stpl_Num) {
        for (lpy = 0; lpy < spg_dat[0].spg_len; lpy++) {
            tilemap_put_cell(lpy + 6, 27, sa_color_data2_tbl[Spg_Col][0], 0xCF);
        }
        tilemap_put_cell(lpy + 6, 26, 28, 0xD8);
        tilemap_put_cell(lpy + 6, 27, 28, 0xDA);
        tilemap_put_cell(lpy + 7, 26, 28, 0xD9);
        tilemap_put_cell(lpy + 7, 27, 28, 0xDB);
        sa_fullstock_trans(0, Spg_Col);
        return;
    }
    for (lpy = 0; lpy < spg_dat[1].spg_len; lpy++) {
        tilemap_put_cell(41 - lpy, 27, sa_color_data2_tbl[Spg_Col][1], 0xCF);
    }
    tilemap_put_cell(41 - lpy, 26, 0x9C, 0xDC);
    tilemap_put_cell(41 - lpy, 27, 0x9C, 0xDE);
    tilemap_put_cell(40 - lpy, 26, 0x9C, 0xDD);
    tilemap_put_cell(40 - lpy, 27, 0x9C, 0xDF);
    sa_fullstock_trans(1, Spg_Col);
}

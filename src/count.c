/*
 * COUNT.C  Vitality bars and round timers (part 3)
 *
 * Routines: count_cont_init, count_cont_reset, count_cont_main, counter_control, counter_flash,
 * counter_color_clear, bcount_cont_init, bcount_cont_reset, bcount_cont_main, bcounter_control,
 * bcounter_down.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "PLS01.h"
#include "count.h"
#include "cps3.h"



void count_cont_init(pl)
s8 pl;
{
    count_work.hoji_counter = hoji_counter_tbl[Game_setting.set3];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[Game_setting.set3];
    round_timer.half.h = Counter_hi;
    count_digit_trans(pl, 9, 9);
    if (!pl) {
        sc_ram_to_vram(2, 0, 0);
        sc_ram_to_vram(3, 0, 0);
    }
    round_timer.timer = 0x630000;
    Timer_Freeze = 0;
    flash_r_num = 0;
    flash_col = 0;
}



/* provisional name */
void count_cont_reset(void) {
    count_work.hoji_counter = hoji_counter_tbl[(*&Game_setting).set3];
    Counter_hi = 99;
    Counter_low = hoji_counter_tbl[(*&Game_setting).set3];
    round_timer.half.h = Counter_hi;
    flash_r_num = 0;
    flash_col = 0;
    count_digit_trans(0, 9, 9);
    sc_ram_to_vram(2, 0, 0);
    sc_ram_to_vram(3, 0, 0);
}



void count_cont_main(void) {
    if (!Break_Into && !sa_stop_check() && !EXE_flag && !Game_pause) {
        counter_control();
    }
}



void counter_control(void) {
    s32 hi;
    const COUNT_WORK* cw = &count_work;
    if (Counter_hi == 0) {
        return;
    }
    if (flash_r_num) {
        if (Counter_hi == 10 && Counter_low == cw->hoji_counter) {
            flash_timer = 0;
            counter_flash(1);
        } else if (Counter_hi <= 10) {
            counter_flash(1);
        } else {
            counter_flash(0);
        }
    } else if (Counter_hi == 30 && Counter_low == cw->hoji_counter) {
        flash_r_num = 1;
        flash_timer = 0;
        counter_flash(0);
    }
    if (Counter_low) {
        Counter_low -= 1;
        return;
    }
    Counter_low = cw->hoji_counter;
    Counter_hi -= 1;
    if (Counter_hi == 0) {
        sq_paint_chenge(22, 0, 4, 5, 8);
    }
    round_timer.half.h = Counter_hi;
    hi = (u16)Counter_hi / 10;
    if (Counter_hi) {
        count_digit_trans(0, hi, Counter_hi - hi * 10);
    } else {
        count_digit_trans(0, 0, 0);
    }
}



void counter_flash(s8 ix) {
    flash_timer--;
    if (flash_timer >= 0) {
        return;
    }
    flash_timer = flash_timer_tbl[ix];
    sq_paint_chenge(22, 0, 4, 5, flash_color_tbl[flash_col]);
    flash_col++;
    if (flash_col == 4) {
        flash_col = 0;
    }
}

/* provisional name */
void counter_color_clear(void) {
    sq_paint_chenge(0x16, 0, 4, 5, 8);
}



/* Counter_hi goes to the high half of round_timer. */
void bcount_cont_init(u8 pl) {
    count_work.hoji_counter = 60;
    Counter_hi = 50;
    Counter_low = count_work.hoji_counter;
    *(s16*)&round_timer = Counter_hi;
    bcount_digit_trans(pl, 5, 0);
    bcount_mark_trans(pl);
    sc_ram_to_vram(29, 0, 0);
    round_timer.timer = 0x320000;
    Time_Stop = 0;
}



/* provisional name */
void bcount_cont_reset(void) {
    count_work.hoji_counter = 60;
    Counter_hi = 50;
    Counter_low = count_work.hoji_counter;
    round_timer.half.h = Counter_hi;
    bcount_digit_trans(0, 5, 0);
    bcount_mark_trans(0);
    sc_ram_to_vram(29, 0, 0);
}



void bcount_cont_main(void) {
    if (Break_Into) {
        return;
    }
    if (sa_stop_check()) {
        return;
    }
    if (Time_Stop) {
        return;
    }
    if (EXE_flag || Game_pause) {
        return;
    }
    bcounter_control();
}



void bcounter_control(void) {
    u16 hi;
    u16 lo;
    const COUNT_WORK* cw;
    if (Counter_hi == 0) {
        return;
    }
    if (Counter_low != 0) {
        Counter_low -= 1;
        return;
    }
    cw = &count_work;
    Counter_low = cw->hoji_counter;
    Counter_hi -= 1;
    round_timer.half.h = Counter_hi;
    hi = (u16)Counter_hi / 10;
    lo = Counter_hi - hi * 10;
    if (Counter_hi) {
        bcount_digit_trans(0, hi, lo);
        return;
    }
    hi = lo = 0;
    bcount_digit_trans(0, hi, lo);
    Time_Over = 1;
}



s16 bcounter_down(u8 stop) {
    u16 hi;
    u16 lo;
    if (Counter_hi == 0) {
        return 0;
    }
    Counter_hi--;
    if (stop) {
        Counter_hi = 0;
    }
    hi = (u16)Counter_hi / 10;
    lo = Counter_hi - hi * 10;
    if (Counter_hi) {
        bcount_digit_trans(0, hi, lo);
    } else {
        hi = lo = 0;
        bcount_digit_trans(0, hi, lo);
    }
    return Counter_hi;
}

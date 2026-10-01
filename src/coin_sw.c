/*
 * coin_sw.c  Coins, credits and switches
 *
 * Coin chute detection, credit add and credit_use, the coin counter and lockout coils,
 * the player switch reads (normal and six-button panels, extended inputs), coin switch sampling and
 * the card dispenser.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "meta_col.h"
#include "eeprom.h"
#include "sys_config.h"
#include "textsound.h"
#include "sys_test.h"
#include "cps3.h"



/* provisional name */
u8 coin_chute_check(s8 n, s32 keep) {
    COINCHUTE* cc;
    void* unused0;
    void* unused1;
    u8 rc;
    rc = 0;
    cc = coin_chute_tbl[n];
    if (keep == 0) {
        cc->dropped = 0;
    }
    unused0 = coin_sw_tbl[n][0];
    unused1 = coin_sw_tbl[n][1];
    if (cc->state == 0) {
        if ((coin_sw_hist[n] & 15) == 3) {
            cc->state = 1;
            cc->timer = 50;
        }
    } else if ((coin_sw_hist[n] & 15) == 12) {
        cc->state = 0;
        cc->dropped = 1;
        rc = 1;
        bookkeep_coin_count();
        coin_in_flag++;
    } else {
        cc->timer--;
        if (cc->timer == 0) {
            cc->state = 0;
        }
    }
    return rc;
}



/* provisional name */
void coin_credit_add(s8 n, s8 m) {
    COINCHUTE* cc;
    s8* credits;
    s8* coins;
    cc = coin_chute_tbl[n];
    credits = credit_ptr_tbl[n];
    coins = coin_count_ptr_tbl[m];
    (*coins)++;
    if (*credits < 9) {
        cc->count++;
    } else {
        cc->count = 0;
    }
    switch (Two_Coin_Start) {
    case 0:
        if (cc->count < cc->per_credit) {
            break;
        }
    default:
        bcdext = 0;
        *credits = abcd(*credits, cc->credits);
        if (*credits > 9) {
            *credits = 9;
        }
        cc->count = 0;
        break;
    }
}



/* provisional name */
void coin_counter_drive(s8 n) {
    COINCHUTE* cc;
    s8* coins;
    cc = coin_chute_tbl[n];
    coins = coin_count_ptr_tbl[n];
    if (cc->lockout) {
        cc->lockout = cc->lockout - 1;
        if (cc->lockout == 32) {
            coin_out_latch &= (u8)coin_counter_off_mask;
        }
    } else if (*coins) {
        *coins = *coins - 1;
        cc->lockout = 64;
        coin_out_latch |= coin_counter_on_bit;
    }
}



/* provisional name */
void coin_lock_release(s8 chute) {
    switch (chute) {
    case 0:
        coin_out_latch |= 1;
        break;
    case 1:
        coin_out_latch |= 2;
        break;
    case 2:
        coin_out_latch |= 4;
        break;
    case 3:
        coin_out_latch |= 8;
        break;
    default:
        coin_out_latch |= 15;
        break;
    }
}



/* provisional name */
void coin_lock_set(chute)
s8 chute;
{
    switch (chute) {
    case 0:
        coin_out_latch &= ~1;
        break;
    case 1:
        coin_out_latch &= ~2;
        break;
    case 2:
        coin_out_latch &= ~4;
        break;
    case 3:
        coin_out_latch &= ~8;
        break;
    default:
        coin_out_latch &= ~15;
        break;
    }
}



/* provisional name */
void coin_lock_check(s8 n, s8 coil) {
    COINCHUTE* cc;
    s8* credits;
    cc = coin_chute_tbl[n];
    credits = credit_ptr_tbl[n];
    if (*credits + cc->credits <= 9) {
        coin_lock_release(coil);
    } else {
        coin_lock_set(coil);
    }
}



/* provisional name */
s32 credit_use(s8 n) {
    s8* credits;
    switch (Chute_Mode) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 10:
        if (credit_1p) {
            credits = &credit_1p;
        } else {
            return 0;
        }
        break;
    case 2:
        if (n) {
            if (credit_2p) {
                credits = &credit_2p;
            } else {
                return 0;
            }
        } else {
            if (credit_1p) {
                credits = &credit_1p;
            } else {
                return 0;
            }
        }
        break;
    case 6:
        switch (n) {
        case 0:
            if (credit_1p) {
                credits = &credit_1p;
            } else {
                return 0;
            }
            break;
        case 1:
            if (credit_2p) {
                credits = &credit_2p;
            } else {
                return 0;
            }
            break;
        case 2:
            if (credit_3p) {
                credits = &credit_3p;
            } else {
                return 0;
            }
            break;
        }
        break;
    case 9:
        switch (n) {
        case 0:
        case 1:
            if (credit_1p) {
                credits = &credit_1p;
            } else {
                return 0;
            }
            break;
        case 2:
        case 3:
            if (credit_3p) {
                credits = &credit_3p;
            } else {
                return 0;
            }
            break;
        }
        break;
    case 11:
        switch (n) {
        case 0:
            if (credit_1p) {
                credits = &credit_1p;
            } else {
                return 0;
            }
            break;
        case 1:
            if (credit_2p) {
                credits = &credit_2p;
            } else {
                return 0;
            }
            break;
        case 2:
            if (credit_3p) {
                credits = &credit_3p;
            } else {
                return 0;
            }
            break;
        case 3:
            if (credit_4p) {
                credits = &credit_4p;
            } else {
                return 0;
            }
            break;
        }
        break;
    }
    (*credits)--;
    return 1;
}

/* provisional name */
u16 * switch_work_clear(char level)
{
    switch (level) {
    case 2:
        p4sw_0 = 0;
        p4sw_1 = 0;
        /* fall through */
    case 1:
        p3sw_0 = 0;
        p3sw_1 = 0;
        /* fall through */
    case 0:
        p2sw_0 = 0;
        p2sw_1 = 0;
        p1sw_0 = 0;
        p1sw_1 = 0;
        break;
    }
    syssw_0 = 0;
    syssw_1 = 0;
    coin_sw_now[0] = 0;
    coin_sw_hist[0] = 0;
    coin_sw_now[1] = 0;
    coin_sw_hist[1] = 0;
    coin_sw_now[2] = 0;
    coin_sw_hist[2] = 0;
    coin_sw_now[3] = 0;
    coin_sw_hist[3] = 0;
    card_sw_1 = 0;
    card_sw_0 = 0;
    return &coin_sw_hist[3];
}



/* provisional name */
void switch_read(s8 mode) {
    register s32 lo;
    register s32 hi;
    ext_switch_read();
    switch (mode) {
    case 2:
        p4sw_1 = p4sw_0;
        p4sw_0 = (~(*(volatile u16*)(IO_REG + 0x4)) >> 8) % 256U;
        lo = ~(s16)(*(volatile u16*)IO_REG) & 0x800;
        hi = (~(*(volatile u16*)IO_REG) & 0x8000) >> 3;
        p4sw_0 |= lo | hi;
    case 1:
        p3sw_1 = p3sw_0;
        p3sw_0 = ~(s16)(*(volatile u16*)(IO_REG + 0x4)) % 256U;
        lo = (~(*(volatile u16*)IO_REG) & 0x400) << 1;
        hi = (~(*(volatile u16*)IO_REG) & 0x4000) >> 2;
        p3sw_0 |= lo | hi;
    case 0:
        p2sw_1 = p2sw_0;
        p2sw_0 = (~(*(volatile u16*)(IO_REG + 0x2)) >> 8) % 256U;
        lo = (~(*(volatile u16*)IO_REG) & 0x200) << 2;
        hi = (~(*(volatile u16*)IO_REG) & 0x2000) >> 1;
        p2sw_0 |= lo | hi;
        p1sw_1 = p1sw_0;
        p1sw_0 = ~(s16)(*(volatile u16*)(IO_REG + 0x2)) % 256U;
        lo = (~(*(volatile u16*)IO_REG) & 0x100) << 3;
        hi = ~(s16)(*(volatile u16*)IO_REG) & 0x1000;
        p1sw_0 |= lo | hi;
        break;
    }
    syssw_1 = syssw_0;
    syssw_0 = ~(*(volatile u16*)IO_REG);
    return;
}



/* provisional name */
void switch_read_six_button(void) {
    register u16 lo;
    register u16 hi;
    ext_switch_read();
    p1sw_1 = p1sw_0;
    p1sw_0 = ~(s16)(*(volatile u16*)(IO_REG + 0x2)) % 256U;
    lo = p1sw_0;
    p1sw_0 = ((lo & 0x80) << 3) | (p1sw_0 & 0x7F);
    lo = (~(*(volatile u16*)(IO_REG + 0x4)) << 4) & 0x80;
    lo |= (~(*(volatile u16*)(IO_REG + 0x4)) << 6) & 0x100;
    lo |= (~(*(volatile u16*)(IO_REG + 0x4)) << 8) & 0x200;
    p1sw_0 |= lo;
    lo = (~(*(volatile u16*)IO_REG) & 0x100) << 3;
    hi = ~(s16)(*(volatile u16*)IO_REG) & 0x1000;
    p1sw_0 |= lo | hi;
    p2sw_1 = p2sw_0;
    p2sw_0 = (~(*(volatile u16*)(IO_REG + 0x2)) >> 8) % 256U;
    lo = p2sw_0;
    p2sw_0 = ((lo & 0x80) << 3) | (p2sw_0 & 0x7F);
    lo = (~(*(volatile u16*)(IO_REG + 0x4)) << 3) & 0x180;
    lo |= (~(*(volatile u16*)IO_REG) >> 1) & 0x200;
    p2sw_0 |= lo;
    lo = (~(*(volatile u16*)IO_REG) & 0x200) << 2;
    hi = (~(*(volatile u16*)IO_REG) & 0x2000) >> 1;
    p2sw_0 |= lo | hi;
    syssw_1 = syssw_0;
    syssw_0 = ~(*(volatile u16*)IO_REG);
}



/* provisional name */
void ext_switch_read(void) {
    exsw_0 = ~((volatile u16*)EXT_SW)[0];
    exsw_1 = ~((volatile u16*)EXT_SW)[1];
    exsw_2 = ~((volatile u16*)EXT_SW)[2];
    exsw_3 = ~((volatile u16*)EXT_SW)[3];
    exsw_4 = ~((volatile u16*)EXT_SW)[4];
    exsw_5 = ~((volatile u16*)EXT_SW)[5];
    exsw_6 = ~((volatile u16*)EXT_SW)[6];
    exsw_7 = ~((volatile u16*)EXT_SW)[7];
    exsw_0 |= ~((volatile u16*)EXT_SW)[8];
    exsw_1 |= ~((volatile u16*)EXT_SW)[9];
    exsw_2 |= ~((volatile u16*)EXT_SW)[10];
    exsw_3 |= ~((volatile u16*)EXT_SW)[11];
    exsw_4 |= ~((volatile u16*)EXT_SW)[12];
    exsw_5 |= ~((volatile u16*)EXT_SW)[13];
    exsw_6 |= ~((volatile u16*)EXT_SW)[14];
    exsw_7 |= ~((volatile u16*)EXT_SW)[15];
}



/* provisional name */
void coin_sw_shift(void) {
    coin_sw_hist[0] <<= 1;
    coin_sw_hist[1] <<= 1;
    coin_sw_hist[2] <<= 1;
    coin_sw_hist[3] <<= 1;
    coin_sw_hist[0] |= coin_sw_now[0];
    coin_sw_hist[1] |= coin_sw_now[1];
    coin_sw_hist[2] |= coin_sw_now[2];
    coin_sw_hist[3] |= coin_sw_now[3];
}



/* provisional name */
void coin_sw_sample(void) {
    coin_sw_now[0] = (~(*(volatile u16*)IO_REG) & 0x100) >> 8;
    coin_sw_now[1] = (~(*(volatile u16*)IO_REG) & 0x200) >> 9;
    coin_sw_now[2] = (~(*(volatile u16*)IO_REG) & 0x400) >> 10;
    coin_sw_now[3] = (~(*(volatile u16*)IO_REG) & 0x800) >> 11;
}



/* provisional name */
void dispenser_sw_read(void) {
    card_sw_1 = card_sw_0;
    card_sw_0 = (~(*(volatile u16*)(IO_REG + 0x4)) >> 8) % 256U;
}

/* provisional name */
char * dispenser_init(void)
{
    char *ret;
    s32 sw;
    s32 latch;
    card_out_req = 0;
    ret = (char *)&Card_Dispenser;
    if (Card_Dispenser != 0) {
        card_out_busy = 0;
        coin_out_latch &= ~4;
        sw = card_sw_0;
        ret = (char *)(u32)sw;
        if (sw & 4) {
            card_out_busy = 4;
            latch = (s8)coin_out_latch | 4;
            coin_out_latch = latch;
            ret = (char *)latch;
        }
    }
    return ret;
}



/* provisional name */
void dispenser_control(void) {
    if (Card_Dispenser == 0) {
        return;
    }
    if ((card_sw_0 & 0x20) == 0) {
        card_empty_flag = -1;
    } else {
        card_empty_flag = 0;
    }
    if (card_out_busy == 4) {
        if (~card_sw_1 & card_sw_0 & 0x40) {
            if (test_flag == 0) {
                bookkeep_card_count();
            }
            card_out_busy = 0;
            coin_out_latch &= ~4;
        }
    } else {
        if (card_empty_flag == -1) {
            return;
        }
        if (card_out_req == 0) {
            return;
        }
        if (card_sw_0 & 1) {
            return;
        }
        card_out_req--;
        card_out_busy = 4;
        coin_out_latch |= 4;
    }
}

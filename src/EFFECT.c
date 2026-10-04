/*
 * EFFECT.C  Effect work manager
 *
 * All effect objects live in 128 work blocks (frw) taken from a free queue and linked into one of
 * eight execution lists. effect_work_init builds the queue; pull_effect_work (or
 * effect_work_pull_link, to insert beside a given work) takes a block for a list, and
 * push_effect_work unlinks, clears and returns it. move_effect_work runs one list per call, calling
 * each work's move routine through effmovejptbl by id; a timing stamp stops a work pulled during the
 * pass from running twice. effect_work_quick_init / _quick_clear and the list walkers free whole
 * lists, effect_work_kill marks works dead and search_effect_index finds a work by id. Also here:
 * work_init_zero, the per-player shell list helpers (effect_shell_ix_* , get_vs_shell_adrs,
 * setup_shell_hit_stop, shell_live_check) and small setters called from character move data (status,
 * caution, extra-BG, BG quake, extra-damage index, step move), and setup_dmv_use_flag,
 * setup_disp_flag and setup_command_number, used when effects and players are initialised.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "effect_2.h"
#include "EFFECT.h"

void move_effect_work(s16 index) {
    s16 curr_ix;
    s16 next_ix;
    WORK* c_addr;
    exec_tm[index]++;
    curr_ix = (&head_ix[0])[index];
    while (curr_ix != -1) {
        c_addr = (WORK*)frw[curr_ix];
        next_ix = c_addr->behind;
        if (c_addr->timing != (s16)exec_tm[index]) {
            c_addr->timing = exec_tm[index];
            effmovejptbl[c_addr->id](c_addr);
        }
        curr_ix = next_ix;
    }
}



void effect_work_init(void) {
    WORK* c_addr;
    s16 i;
    work_init_zero((s32*)frw, sizeof(frw));
    for (i = 0; i < 128; i++) {
        frwctr = (128 - 1) - i;
        c_addr = (WORK*)frw[frwctr];
        frwque[i] = c_addr->myself = frwctr;
        c_addr->before = c_addr->behind = -1;
    }
    frwctr = 128;
    for (i = 0; i < 8; i++) {
        s16* t = &tail_ix[i];
        head_ix[i] = -1;
        *t = -1;
        exec_tm[i] = 0;
    }
}



void effect_work_quick_init(void) {

    s16 i;
    for (i = 0; i < 8; i += 1) {
        effect_work_list_release(i, -1);
    }
}



/* provisional name */
void effect_work_quick_clear(void) {
    s16 i;
    for (i = 0; i < 8; i += 1) {
        effect_work_list_init(i, -1);
    }
}



/* provisional name */
void effect_work_list_release(lix, iid)
    s16 lix;
    s16 iid;
{
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;
    curr_ix = head_ix[lix];
    if (iid == -1) {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            all_cgps_put_back((WORK_Other*)c_addr);
            push_effect_work(c_addr);
            curr_ix = next_ix;
        }
        exec_tm[lix] = 0;
    } else {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            if (c_addr->id == iid) {
                all_cgps_put_back((WORK_Other*)c_addr);
                push_effect_work(c_addr);
            }
            curr_ix = next_ix;
        }
    }
}



void effect_work_list_init(lix, iid)
s16 lix;
s16 iid;
{
    WORK* c_addr;
    s16 curr_ix;
    s16 next_ix;

    curr_ix = head_ix[lix];
    if (iid == -1) {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            push_effect_work(c_addr);
            curr_ix = next_ix;
        }
        (&exec_tm[0])[lix] = 0;
    } else {
        while (curr_ix != -1) {
            c_addr = (WORK*)frw[curr_ix];
            next_ix = c_addr->behind;
            if (c_addr->id == iid) {
                push_effect_work(c_addr);
            }
            curr_ix = next_ix;
        }
    }
}



/* Takes an effect work from the free queue and links it into list `index`; returns its slot index, -1 when none is free. */
/* provisional name */
s32 pull_effect_work(s16 index) {
    s16 qix;
    WORK* tadr;
    WORK* wrk;
    if (frwctr < 1) {
        return -1;
    }
    qix = frwque[(frwctr -= 1)];
    tadr = (WORK*)frw[qix];
    if (head_ix[index] == -1) {
        tail_ix[index] = qix;
        head_ix[index] = qix;
    } else {
        wrk = (WORK*)frw[tail_ix[index]];
        wrk->behind = qix;
        tadr->before = tail_ix[index];
        tail_ix[index] = qix;
    }
    tadr->timing = exec_tm[index];
    tadr->listix = index;
    return qix;
}



/* provisional name */
s32 effect_work_pull_link(s16 index, s16 before, s16 aix) {
    s16 qix;
    WORK* tadr;
    WORK* wrk;
    if (aix == -1) {
        return pull_effect_work(index);
    }
    if (frwctr < 1) {
        return -1;
    }
    qix = frwque[--frwctr];
    tadr = (WORK*)frw[qix];
    wrk = (WORK*)frw[aix];
    if (before != 0) {
        if ((tadr->before = wrk->before) == -1) {
            head_ix[index] = qix;
        }
        tadr->behind = aix;
        wrk->before = qix;
    } else {
        if ((tadr->behind = wrk->behind) == -1) {
            tail_ix[index] = qix;
        }
        tadr->before = aix;
        wrk->behind = qix;
    }
    tadr->timing = exec_tm[index];
    tadr->listix = index;
    return qix;
}



s32 search_effect_index(s16 index, s16 flag, s16 tid) {
    WORK* c_addr;
    s16 aix;
    if (flag) {
        aix = tail_ix[index];
        while (aix != -1) {
            c_addr = (WORK*)frw[aix];
            if (c_addr->id != tid) {
                aix = c_addr->before;
            } else {
                break;
            }
        }
    } else {
        aix = head_ix[index];
        while (aix != -1) {
            c_addr = (WORK*)frw[aix];
            if (c_addr->id != tid) {
                aix = c_addr->behind;
            } else {
                break;
            }
        }
    }
    return aix;
}



/* Unlinks an effect work and returns it to the free queue; returns its slot index. */
s32 push_effect_work(WORK* wkhd) {
    WORK* c_addr;
    WORK* c_addr2;
    s16 qix;
    s16 lix;
    lix = wkhd->listix;
    qix = wkhd->myself;
    c_addr = (WORK*)frw[qix];
    switch ((qix == head_ix[lix]) + (qix == tail_ix[lix]) * 2) {
    case 0:
        c_addr2 = (WORK*)frw[c_addr->before];
        c_addr2->behind = c_addr->behind;
        c_addr2 = (WORK*)frw[c_addr->behind];
        c_addr2->before = c_addr->before;
        break;
    case 1:
        head_ix[lix] = c_addr->behind;
        c_addr2 = (WORK*)frw[c_addr->behind];
        c_addr2->before = -1;
        break;
    case 2:
        c_addr2 = (WORK*)frw[c_addr->before];
        c_addr2->behind = -1;
        tail_ix[lix] = c_addr->before;
        break;
    default:
        head_ix[lix] = tail_ix[lix] = -1;
        break;
    }
    work_init_zero((s32*)frw[qix], sizeof(frw[0]));
    c_addr->before = c_addr->behind = -1;
    frwque[frwctr++] = qix;
    return c_addr->myself = qix;
}



void effect_work_kill(s16 index, s16 kill_id) {
    s16 aix;
    WORK* c_addr;
    aix = head_ix[index];
    if (kill_id == -1) {
        for (; aix != -1; aix = c_addr->behind) {
            c_addr = (WORK*)frw[aix];
            c_addr->dead_f = 1;
        }
    } else {
        for (; aix != -1; aix = c_addr->behind) {
            c_addr = (WORK*)frw[aix];
            if (c_addr->id == kill_id) {
                c_addr->dead_f = 1;
            }
        }
    }
}


/* provisional name */
s16 get_frwctr(void) {
    return frwctr;
}



void work_init_zero(s32* adrs_int, s32 xx) {
    s32 i;
    s32 surr;
    s8* adrs_char;
    surr = (u32)xx % 4;
    xx /= 4;
    for (i = 0; i < xx; i++) {
        *adrs_int++ = 0;
    }
    if (surr != 0) {
        adrs_char = (s8*)adrs_int;
        for (i = 0; i < surr; i++) {
            *adrs_char++ = 0;
        }
    }
}

/* provisional name */
void work_init_copy(s32* src, s32* dst, s16 size) {
    s16 i;
    s16 j;
    s16 words;
    s32 surr;
    surr = (u32)size % 4;
    words = size;
    words /= 4;
    for (i = 0; i < words; i++) {
        *dst++ = *src++;
    }
    if (surr != 0) {
        for (j = 0; j < surr; j++) {
            *(s8*)dst = *(s8*)src;
            src++;
            dst++;
        }
    }
}

void write_my_shell_ix(WORK* wk, s16 ix) {
    s32 i;
    for (i = 7; i >= 1; i -= 1) {
        wk->shell_ix[i] = wk->shell_ix[i - 1];
    }
    wk->shell_ix[0] = ix;
}



s32 erase_my_shell_ix(WORK* wk, s16 ix) {
    s32 i;
    s32 j;
    for (i = 0; i < 8; i++) {
        if (wk->shell_ix[i] != ix) {
            continue;
        }
        goto ok;
    }
    return 0;
ok:
    for (j = i; j < 7; j++) {
        s16* p = &wk->shell_ix[j];
        p[0] = p[1];
    }
    wk->shell_ix[7] = -1;
    return 1;
}



s32 get_my_shell_ix(WORK* wk, s16 ix, WORK** tmw) {
    if (wk->shell_ix[ix] == -1) {
        return 0;
    }
    *tmw = (WORK*)frw[wk->shell_ix[ix]];
    if ((*tmw)->be_flag) {
        return 1;
    }
    return 0;
}



s32 get_vs_shell_adrs(WORK* wk, s16 id, s16 ix, WORK_Other** tmw) {
    if (wk->shell_ix[ix] == -1) {
        return 0;
    }
    *tmw = (WORK_Other*)frw[wk->shell_ix[ix]];
    if ((*tmw)->master_id == id) {
        return 1;
    }
    return 0;
}



void clear_my_shell_ix(WORK* wk) {
    s32 i;
    for (i = 0; i < 8; i++) {
        wk->shell_ix[i] = -1;
    }
}



void setup_shell_hit_stop(WORK* wk, s16 tm, s16 fl) {
    WORK* tmw;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (get_my_shell_ix(wk, i, &tmw) != 0) {
            if (fl == 0 || tmw->id != 0x29) {
                tmw->hit_stop = tm;
            }
        }
    }
}



s32 shell_live_check(PLW* wk, s16 wix) {
    WORK_Other* tmw;
    s16 i;
    if (wk->player_number != 0xE) {
        for (i = 0; i < 8; i++) {
            if (wk->wu.shell_ix[i] == -1) {
                break;
            }
            tmw = (WORK_Other*)frw[wk->wu.shell_ix[i]];
            if ((!tmw->refrected) && (tmw->wu.original_vitality == wix)) {
                return 1;
            }
        }
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (wk->wu.shell_ix[i] == -1) {
            break;
        }
        tmw = (WORK_Other*)frw[wk->wu.shell_ix[i]];
        if (tmw->refrected) {
            continue;
        }
        if ((tmw->wu.original_vitality == 31) || (tmw->wu.original_vitality == 33) ||
            (tmw->wu.original_vitality == 46)) {
            return 1;
        }
    }
    return 0;
}

/* Clear the player's caution (guard-warning) flag. */
void clear_caution_flag(PLW* wk)
{
    wk->caution_flag = 0;
}

/* Set the player's caution (guard-warning) flag. */
void set_caution_flag(PLW* wk)
{
    wk->caution_flag = 1;
}



void setup_status_flag(WORK* wk, u8 status) {
    wk->pat_status = status;
}



void reset_extra_bg_flag(WORK* wk) {
    another_bg[wk->id] = 0;
}

void flip_my_rl_flag(WORK* wk)
{

    wk->rl_flag = ((u8)wk->rl_flag + 1U) & 1;
}



void setup_meoshi_hit_flag(WORK* wk, u8 flag) {
    wk->meoshi_hit_flag = flag;
}




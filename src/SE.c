/*
 * SE.C  Screen wipe patterns and sound request routines
 *
 * Two groups of routines. The wipe routines (wipe_pattern_*, wipe_mask_*, mix_or/mix_put/
 * mix_copy) OR or AND one step of a wipe-out or wipe-in pattern into the fix-layer character
 * graphics, column by column; Switch_Screen and Switch_Screen_Revival in SYS_sub call them.
 * The sound routines start stage BGM (Stage_BGM, bgm_fade_in_stage), initialise sound
 * (sound_system_init) and play effects for objects: the Se_ table handlers (Se_Myself, Se_Let,
 * Se_Let_SP, ...) and Se_Shock play a code in the character's own sound bank, panned
 * by screen position (Get_Position), with voice replacement from Check_Voice_SE.
 * Call_Se plays a fixed code; Finish_SE plays the winner's finishing voice.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "textsound.h"
#include "bg_sub.h"
#include "SE.h"
#include "cps3.h"

void mix_or_128(void);

void mix_put_128(void);



/* provisional name */
void wipe_pattern_or_cols(s16 kind, s16 row) {
    u8* src;
    u8* map;
    u16* dst;
    u16* p;
    u32 code;
    s16 ofs;
    s16 x;
    s16 y;
    s16 width;
    width = wipe_column_tbl[kind].w;
    src = wipe_column_tbl[kind].adr + width * row;
    map = wipe_set_pattern_tbl[kind].adr + row * 32;
    dst = (u16*)(SS_RAM + 0x8000);
    y = 0;
    do {
        for (x = 0; x < wipe_column_tbl[kind].w; x++) {
            code = src[x];
            ofs = code * 2;
            p = (u16*)((u8*)dst + ofs);
            *p |= map[code];
            continue;
        }
        dst += 32;
    } while (++y < 464);
}



/* provisional name */
void wipe_pattern_restore_cols(s16 kind, s16 row) {
    s32 ofs;
    u8* src;
    u8* map;
    u8* cell;
    u16* dst;
    s16 x;
    s16 y;
    ofs = wipe_column_tbl[kind].w;
    ofs *= row;
    src = wipe_column_tbl[kind].adr + ofs;
    map = wipe_clear_pattern_tbl[kind].adr + row * 32;
    cell = sc_chr_ram;
    dst = (u16*)(SS_RAM + 0x8000);
    for (y = 0; y < 464; y++) {
        for (x = 0; x < wipe_column_tbl[kind].w; x++) {
            dst[src[x]] = cell[src[x]] | map[src[x]];
            continue;
        }
        dst += 32;
        cell += 32;
    }
}



/* provisional name */
void mix_or_512(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 512; i++) {
        wipe_pat_ptr = wipe_pat_top;
        for (j = 0; j < 32; j++) {
            *wipe_dst_ptr = *wipe_pat_ptr | *wipe_dst_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
        }
    }
}



/* provisional name */
void mix_put_512(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 512; i++) {
        wipe_pat_ptr = wipe_pat_top;
        for (j = 0; j < 32; j++) {
            *wipe_dst_ptr = *wipe_back_ptr | *wipe_pat_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
            wipe_back_ptr++;
        }
    }
}



/* provisional name */
void wipe_pattern_set(s16 kind, s16 row, s16 mix) {
    wipe_pat_top = wipe_set_pattern_tbl[kind].adr;
    if (mix) {
        wipe_pat_top = wipe_clear_pattern_tbl[kind].adr;
    }
    wipe_pat_top += row * 32;
    wipe_dst_ptr = (u16*)(SS_RAM + 0x8000);
    if (!mix) {
        mix_or_128();
    } else {
        wipe_back_ptr = sc_chr_ram;
        mix_put_128();
    }
}



/* provisional name */
void mix_or_128(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 128; i++) {
        wipe_pat_ptr = wipe_pat_top;
        for (j = 0; j < 32; j++) {
            *wipe_dst_ptr = *wipe_pat_ptr | *wipe_dst_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
        }
    }
}



/* provisional name */
void mix_put_128(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 128; i++) {
        wipe_pat_ptr = wipe_pat_top;
        for (j = 0; j < 32; j++) {
            *wipe_dst_ptr = *wipe_back_ptr | *wipe_pat_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
            wipe_back_ptr++;
        }
    }
}



/* provisional name */
void wipe_pattern_and_low(s16 kind, s16 row) {
    s16 x;
    s16 y;
    wipe_pat_top = wipe_clear_pattern_tbl[kind].adr + row * 32;
    wipe_dst_ptr = (u16*)(SS_RAM + 0xD000);
    for (y = 0; y < 144; y++) {
        wipe_pat_ptr = wipe_pat_top;
        for (x = 0; x < 32; x++) {
            *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
            wipe_dst_ptr++;
            wipe_pat_ptr++;
        }
    }
}



/* provisional name */
void wipe_and_row(void) {
    s32 j;
    wipe_pat_ptr = wipe_pat_top;
    for (j = 0; j < 32; j++) {
        *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
        wipe_dst_ptr++;
        wipe_pat_ptr++;
    }
}



/* provisional name */
void wipe_and_dot(void) {
    *wipe_dst_ptr = *wipe_pat_ptr & *wipe_dst_ptr;
    wipe_dst_ptr++;
    wipe_pat_ptr++;
}



/* provisional name */
void wipe_mask_set_cols(s16 kind, s16 row) {
    u8* src;
    u8* map;
    u8* mask;
    u16* dst;
    s16 x;
    s16 y;
    s16 i;
    s16 width;
    width = wipe_column_tbl[kind].w;
    src = wipe_column_tbl[kind].adr + width * row;
    map = wipe_set_pattern_tbl[kind].adr + row * 32;
    dst = (u16*)(SS_RAM + 0xE000);
    mask = wipe_mask_chr;
    for (i = 0; i < 6; i++) {
        for (y = 0; y < 16; y++) {
            for (x = 0; x < wipe_column_tbl[kind].w; x++) {
                dst[src[x]] = mask[src[x]] & map[src[x]];
            }
            dst += 32;
            mask += 32;
        }
    }
}



/* provisional name */
void wipe_mask_and_cols(s16 kind, s16 row) {
    s16 x;
    s16 y;
    s16 i;
    u8* src;
    u8* map;
    u16* dst;

    src = wipe_column_tbl[kind].adr;
    src += wipe_column_tbl[kind].w * row;
    map = wipe_clear_pattern_tbl[kind].adr;
    map += row * 32;
    dst = (u16*)(SS_RAM + 0xE000);
    for (i = 0; i < 6; i++) {
        for (y = 0; y < 16; y++, dst += 32) {
            for (x = 0; x < wipe_column_tbl[kind].w; x++) {
                dst[src[x]] &= map[src[x]];
            }
        }
    }
}



void Stage_BGM(u16 Stage_Number, s32 Round_Number) {
    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Keep_BGM_Flag) {
        return;
    }
    gSeqStatus[0] = 0;
    sound_request(stage_bgm_tbl[Stage_Number] + (Round_Number & 1));
}



/* provisional name */
void bgm_fade_in_stage(s16 x) {
    if (!Keep_BGM_Flag) {
        sound_fade_in_submit(stage_bgm_tbl[bg_w.stage], 0x8000 / x);
    }
}

void Sound_SE(Code)
    s16 Code;
{
    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        sound_request(Code);
    }
}


/* provisional name */
void sound_bgm_fade_out(s16 speed) {
    bgm_fade_out(speed);
}

/* provisional name */
void bgm_request(bgm_code)
s16 bgm_code;
{
    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Keep_BGM_Flag) {
        return;
    }
    sound_reg_level_set(0, 0);
    sound_request(bgm_code);
}



/* provisional name */
void voice_all_off(void) { bgm_stop(); }



/* provisional name */
void sound_system_init(void) {
    s16 i;
    sound_request_pan(0x78, 0x40, 0x40, 0, 2);
    for (i = 0; i < 14; i++) {
        se_voice_stop(init_fade_voice_tbl[i]);
    }
}



void Se_Dummy(WORK_Other* ewk, u16 Code) {
}



void Se_Shock(WORK_Other* ewk, u16 Code) {
    u16 se;
    s16 pos;
    PLW* em;
    s32 uid;
    s16 xx;
    s32 zz;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        se = Check_Bonus_SE(Code);
        if (ewk->wu.work_id == 1) {
            em = (PLW*)ewk->wu.target_adrs;
            uid = ewk->wu.id;
        } else {
            em = (PLW*)((PLW*)ewk->my_master)->wu.target_adrs;
            uid = ewk->master_id;
        }
        if (em->wu.work_id == 1 && em->wu.vital_new < 0) {
            xx = 0;
            zz = 0x27;
            for (; xx < 7; xx++) {
                if (se == SE_Shock_Data[xx]) {
                    zz = 0;
                    break;
                }
            }
            se += zz;
        }
        if (se) {
            se += uid * 0x300;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(se, pos, pos, 0, 2);
    }
}



void Se_Myself(WORK_Other* ewk, u16 Code) {
    s32 se;
    s16 pos;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        se = Check_Voice_SE(Code);
        if ((u16)se) {
            se += ewk->wu.id * 0x300;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(se, pos, pos, 0, 2);
    }
}



void Se_Myself_Die(WORK_Other* ewk, u16 Code) {
    s32 se;
    s16 pos;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    if (ewk->wu.vital_new < 0) {
        return;
    }
    se = Check_Voice_SE(Code);
    if ((u16)se) {
        se += ewk->wu.id * 0x300;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}



void Se_Let(WORK_Other* ewk, u16 Code) {
    s32 se;
    s32 uid;
    s16 pos;
    volatile s16 code = Code;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    code = Check_Voice_SE((u16)code);
    se = Check_Bonus_SE((u16)code);
    if (ewk->wu.work_id == 1) {
        uid = ewk->wu.id;
    } else {
        uid = ewk->master_id;
    }
    if ((u16)se) {
        se += uid * 0x300;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}



void Se_Let_SP(WORK_Other* ewk, u16 Code) {
    s32 uid;
    PLW* em;
    s16 pos;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        em = (PLW*)ewk->wu.target_adrs;
        if (ewk->wu.work_id == 1) {
            uid = ewk->wu.id;
        } else {
            uid = ewk->master_id;
        }
        if (em->wu.work_id == 1 && em->wu.vital_new < 0) {
            if (Code == 0x14B) {
                Code = 0x158;
            }
            if (Code == 0x13A) {
                Code = 0x15A;
            }
        }
        if (Code) {
            Code += uid * 0x300;
        }
        pos = Get_Position((PLW*)ewk);
        sound_request_pan(Code, pos, pos, 0, 2);
    }
}



void Call_Se(WORK_Other* ewk, u16 Code) {
    s16 code = Code;
    s16 pos;
    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        pos = Get_Position((PLW*)&code);
        sound_request_pan(code, pos, pos, 0, 2);
    }
}

/* Sound handler: plays Code (with the character's voice replacement) at the
   object's screen position, but stays silent while the object is dropping
   at a height of 64 or less. */
s32 Se_Term(WORK_Other* ewk, u16 Code) {
    s32 se;
    s16 pos;

    if (Demo_Sound == 0 && Demo_Flag == 0) {
        return;
    }
    if (Combo_Demo_Flag & 0x80) {
        return;
    }
    if (ewk->wu.mvxy.a[1].sp < 0 && ewk->wu.xyz[1].disp.pos <= 64) {
        return 0;
    }
    se = Check_Voice_SE(Code);
    if ((u16)se) {
        se += ewk->wu.id * 0x300;
    }
    pos = Get_Position((PLW*)ewk);
    sound_request_pan(se, pos, pos, 0, 2);
}



void Finish_SE(void) {
    s32 se;
    s16 pos;
    PLW* wk;

    if ((Demo_Sound != 0 || Demo_Flag != 0) && (Combo_Demo_Flag & 0x80) == 0) {
        se = Check_Finish_SE();
        if ((s16)se != -1) {
            wk = &plw[Winner_id];
            if ((s16)se) {
                se += wk->wu.id * 0x300;
            }
            pos = Get_Position(wk);
            sound_request_pan(se, pos, pos, 0, 2);
        }
    }
}



s32 Check_Finish_SE(void) {
    s16 xx;
    for (xx = 0; xx < 7; xx++) {
        if (Finish_SE_Data[0][xx] == Last_Called_SE) {
        } else {
            continue;
        }
        return Finish_SE_Data[1][xx];
    }
    return -1;
}



u16 Get_Position(PLW* wk) {
    u16 xx;
    u16 yy;
    xx = get_center_position();
    xx -= 0xF8;
    xx = wk->wu.position_x - xx;
    xx /= 4;
    if (xx < 0x80) {
        return xx;
    }
    yy = get_center_position();
    if (yy > wk->wu.xyz[0].disp.pos) {
        return 1;
    }
    return 0x7E;
}



/* provisional name */
s32 Check_Voice_SE(code)
s16 code;
{
    if (code < 0x140 || Voice_Type == 0) {
        return code;
    }
    return Voice_SE_Data[code - 0x140];
}

s32 Check_Bonus_SE(Code)
s16 Code;
{
    if (Bonus_Game_Flag == 0 || Bonus_Type != 21) {
        return Code;
    }
    if (Code < 0x100) {
        return Code;
    }
    if (Code >= 0x760) {
        return Code;
    }
    {
        s32 ofs = (Code - 0x100) * 2;
        if (Voice_Type == 0) {
            return *(u16*)((s32)Bonus_SE_Data + ofs);
        }
        return *(u16*)((s32)Bonus_SE_Voice_Data + ofs);
    }
}

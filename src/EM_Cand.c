/*
 * EM_CAND.C  Combo demo setup and CPU opponent candidate lists
 *
 * Combo_Demo_Init prepares a combo-demo round (allows the battle, clears player-control steps and
 * Suicide, points both demo input streams at the current demo's data) and Setup_Combo_Demo_PL
 * (called from PLCNTAPP) loads both players' character, super art and colour from the combo demo
 * table.
 * Initialize_EM_Candidate (from sel_pl) builds a player's candidate buffer and fills the two CPU
 * opponent candidate lists for stages 1-8, sets the rival for stage 9 and clears stage 10.
 * Check_EM_Buff and Check_Same_CPU are the helpers that avoid repeated or duplicate opponents.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "VITAL.h"
#include "PLCNTDAT.h"
#include "HITCHECK.h"
#include "PLS02.h"
#include "EM_Cand.h"



/* provisional name */
void Combo_Demo_Init(void) {
    Demo_Lever_Play = 255;
    Allow_a_battle_f = 1;
    Game_pause = 0;
    Suicide[0] = 0;
    round_timer.timer = 1;
    pcon_rno[0] = 0;
    pcon_rno[1] = 0;
    pcon_rno[2] = 0;
    pcon_rno[3] = 0;
    appear_type = 0;
    Demo_Ptr[0] = Combo_Demo_Lever_Data[(u8)Get_Demo_Index][0];
    Demo_Ptr[1] = Combo_Demo_Lever_Data[(u8)Get_Demo_Index][1];
    clear_hit_queue();
    vital_cont_init();
    set_kizetsu_status(0);
    set_kizetsu_status(1);
}



/* provisional name */
void Setup_Combo_Demo_PL(void) {
    s8* p = combo_demo_pl_tbl[Get_Demo_Index];
    My_char[0] = *p++;
    Super_Arts[0] = *p++;
    Player_Color[0] = *p++;
    My_char[1] = *p++;
    Super_Arts[1] = *p++;
    Player_Color[1] = *p;
}



void Initialize_EM_Candidate(s16 PL_id) {
    s16 ix;
    s16 ok_urien = ((s16)random_16_com());
    for (ix = 0; ix < 16; ix++) {
        Candidate_Buff[ix] = 0xFF;
    }
    Setup_Candidate_Buff(PL_id);
    for (ix = 0; ix < 8; ix++) {
        EM_Candidate[PL_id][0][ix] = Check_EM_Buff(ix, ok_urien);
        EM_Candidate[PL_id][1][ix] = Check_EM_Buff(ix, ok_urien);
    }
    EM_Candidate[PL_id][0][8] = Rival_Char_Data[My_char[PL_id] - 1];
    EM_Candidate[PL_id][1][8] = Rival_Char_Data[My_char[PL_id] - 1];
    EM_Candidate[PL_id][0][9] = 0;
    EM_Candidate[PL_id][1][9] = 0;
}

void Setup_Candidate_Buff(PL_id)
s16 PL_id;
{
    s16 em = 0;
    s16 ix;
    for (ix = 1; ix <= 20; ix++) {
        if (ix == My_char[PL_id]) {
            continue;
        }
        if (ix == 18) {
            continue;
        }
        if (ix == 15) {
            continue;
        }
        if (ix == Rival_Char_Data[My_char[PL_id] - 1]) {
            continue;
        }
        if (Break_Com[PL_id][ix]) {
            continue;
        }
        Candidate_Buff[em] = ix;
        em++;
    }
}



s16 Check_EM_Buff(grade, flag)
s16 grade;
s16 flag;
{
    s16 ix = random_16_com();
    s16 step;
    u8 chr;
    if (Check_EM_Sub(grade, flag, ix)) {
        chr = Candidate_Buff[ix];
        Candidate_Buff[ix] = 0xFF;
        return chr;
    }
    step = random_16_com() & 1;
    if (step == 0) {
        step = -1;
    }
    while (1) {
        if (Check_EM_Sub(grade, flag, ix)) {
            chr = Candidate_Buff[ix];
            Candidate_Buff[ix] = 0xFF;
            return chr;
        }
        ix += step;
        if (ix < 0) {
            ix = 15;
        }
        if (ix > 15) {
            ix = 0;
        }
    }
}

s32 Check_EM_Sub(grade, flag, ix)
s16 grade;
s16 flag;
s16 ix;
{
    if (Candidate_Buff[ix] == 0xFF) {
        return 0;
    }
    switch (Candidate_Buff[ix]) {
    case 2:
    case 6:
    case 8:
    case 11:
        if (grade < 4) {
            return 0;
        }
        return 1;
    case 14:
        if (grade < 6) {
            return 0;
        }
        return 1;
    case 13:
        if (flag != 0 && grade < 4) {
            return 0;
        }
        return 1;
    default:
        return 1;
    }
}



void Check_Same_CPU(s16 PL_id) {
    s32 ix;
    s32 ok_urien;
    if (VS_Index[PL_id] >= 9) {
        return;
    }
    if (Last_My_char[PL_id] == My_char[PL_id]) {
        return;
    }
    ok_urien = random_16_com();
    for (ix = 0; ix < 16; ix++) {
        Candidate_Buff[ix] = 0xFF;
    }
    Setup_Candidate_Buff(PL_id);
    for (ix = VS_Index[PL_id]; ix < 8; ix++) {
        EM_Candidate[PL_id][0][ix] = Check_EM_Buff(ix, ok_urien);
        EM_Candidate[PL_id][1][ix] = Check_EM_Buff(ix, ok_urien);
    }
    EM_Candidate[PL_id][0][8] = Rival_Char_Data[My_char[PL_id] - 1];
    EM_Candidate[PL_id][1][8] = Rival_Char_Data[My_char[PL_id] - 1];
}

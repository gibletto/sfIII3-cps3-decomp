/*
 * n_input.c  Ranking name entry
 *
 * Name_Input is the per-player entry for entering initials after a ranked game: it works out
 * which ranking the player reached (ranking_state_check), sets up the name work and a time
 * limit, then runs the Name_Jmp_scs states (init, lever/button input, wait, finish).
 * Name_Input_comm and Name_Scs_Input_comm move the cursor through the character set and
 * commit letters, with a timeout that ends entry automatically. When the name is left blank or
 * matches an entry in slang_tbl (name_slang_check), define_name_input substitutes one of two
 * fixed names at random; ranking_name_entry then copies the letters into the ranking record.
 * The rest of the file draws the entered names and scores on the text layer and shows the
 * "thank you for playing" message.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "end_sub.h"
#include "sc_trans.h"
#include "Eff93.h"
#include "EFFB6.h"
#include "EFFB8.h"
#include "sc_face.h"
#include "PLS02.h"
#include "SE.h"
#include "textsound.h"
#include "n_input.h"



s16 Name_Input(s16 pl_id) {
    end_no_cut = 1;
    Name_Input_f = 0;
    name_ptr = &name_wk[pl_id];
    name_ptr->id = pl_id;
    start_cut_check(pl_id);
    switch (Name_00[pl_id]) {
    case 0:
        Name_00[pl_id]++;
        name_ptr->type = 0;
        name_work_init(pl_id);
        name_limit_timer[name_ptr->id] = 1800;
        ranking_state_check();
        all_name_display();
        break;
    default:
        Name_Jmp_scs[name_ptr->r_no_0]();
        break;
    }
    return Name_Input_f;
}



/* provisional name */
void Name_Input_init(void) {
    name_ptr->r_no_0++;
    load_any_color(4);
    if (end_name_cut[name_ptr->id] == 0) {
        name_ptr->timer = 1200;
    }
    name_ptr->index = 0;
    effect_B7_init(name_ptr->id);
    effect_B5_init(name_ptr->id);
}

/* provisional name */
void Name_Input_comm(void) {
    s16 cmd;
    s16 i;
    name_ptr->timer--;
    name_limit_timer[name_ptr->id]--;
    if (name_limit_timer[name_ptr->id] < 0 || name_ptr->timer < 0) {
        name_ptr->r_no_0 = 6;
        for (i = name_ptr->index; i < 4; i++) {
            name_ptr->code[i] = 0x2C;
        }
        return;
    }
    cmd = Name_Input_sub();
    switch (cmd) {
    case 1:
        name_ptr->r_no_0++;
        name_ptr->timer += 420;
        name_ptr->end_flag[name_ptr->index] = 1;
        name_ptr->index++;
        name_ptr->index &= 3;
        name_ptr->wait_cnt = 10;
        name_ptr->code[name_ptr->index] = name_ptr->code[name_ptr->index - 1];
        break;
    case 2:
        name_ptr->timer += 420;
        name_ptr->index--;
        name_ptr->r_no_0 -= 2;
        if (name_ptr->index < 0) {
            name_ptr->index = 0;
            name_ptr->r_no_0 = 0;
        } else {
            name_ptr->code[name_ptr->index + 1] = 0x2F;
        }
        name_ptr->end_flag[name_ptr->index] = 0;
        break;
    case 3:
        name_ptr->r_no_0 = 6;
        for (i = name_ptr->index; i < 4; i++) {
            name_ptr->code[i] = 0x2C;
        }
        break;
    }
}



void Name_Input_wait(void) {
    name_ptr->wait_cnt--;
    if (name_ptr->wait_cnt < 0) {
        name_ptr->r_no_0++;
    }
}



/* provisional name */
void Name_Input_end(void) {
    s16 i;
    name_ptr->r_no_0++;
    if (name_ptr->index > 0) {
        if (name_slang_check() != 0) {
            define_name_input();
        }
    } else {
        define_name_input();
    }
    ranking_name_entry();
    for (i = 0; i < 4; i++) {
        name_ptr->end_flag[i] = 1;
    }
    name_ptr->index = 3;
}

/* provisional name */
void Name_Finish(void)
{
    Sound_SE(0x62);
    end_no_cut = 0;
    Name_Input_f = 1;
}



/* provisional name */
void show_thank_you_for_playing(void) {
    tilemap_print_string_attr(20, 22, 18, thank_you_str);
    tilemap_print_string_attr(19, 23, 18, for_playing_str);
}



/* provisional name */
void Name_Scs_Input_init(void) {
    name_ptr->r_no_0++;
    if (end_name_cut[name_ptr->id] == 0) {
        name_ptr->timer = 1200;
    }
    name_ptr->index = 0;
    name_entry_commit_row(name_ptr->id, Text_Page_Y);
    Scs_char_move();
}



void Name_Scs_Input_comm(void) {
    s16 work;
    s16 i;
    name_ptr->timer--;
    name_limit_timer[name_ptr->id]--;
    if (name_limit_timer[name_ptr->id] < 0 || name_ptr->timer < 0) {
        name_ptr->r_no_0 = 6;
        for (i = name_ptr->index; i < 4; i++) {
            name_ptr->code[i] = 44;
        }
    } else {
        work = Name_Input_sub();
        switch (work) {
        case 1:
            name_ptr->r_no_0 += 1;
            name_ptr->timer += 420;
            name_ptr->end_flag[name_ptr->index] = 1;
            naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            name_ptr->index += 1;
            name_ptr->index &= 3;
            name_ptr->wait_cnt = 10;
            if (name_ptr->index != 3) {
                name_ptr->code[name_ptr->index] = name_ptr->code[name_ptr->index - 1];
            } else {
                name_ptr->code[name_ptr->index] = 46;
            }
            (*&sc_name_wk)[name_ptr->id][name_ptr->index].n_disp_flag = 0;
            (*&sc_name_wk)[name_ptr->id][name_ptr->index].f_cnt = 0;
            break;
        case 2:
            name_ptr->timer += 420;
            (*&sc_name_wk)[name_ptr->id][name_ptr->index].n_disp_flag = 0;
            (*&sc_name_wk)[name_ptr->id][name_ptr->index].f_cnt = 0;
            name_ptr->index--;
            name_ptr->r_no_0 -= 2;
            if (name_ptr->index < 0) {
                name_ptr->index = 0;
                name_ptr->r_no_0 = 0;
            } else {
                name_ptr->code[name_ptr->index + 1] = 47;
                naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            }
            name_ptr->end_flag[name_ptr->index] = 0;
            break;
        case 3:
            name_ptr->r_no_0 = 6;
            naming_set(name_ptr->id, name_ptr->index, name_ptr->code[name_ptr->index]);
            for (i = name_ptr->index; i < 4; i++) {
                name_ptr->code[i] = 44;
            }
            break;
        }
    }
    Scs_char_move();
}



/* provisional name */
void Name_Scs_Input_end(void) {
    s16 i;
    name_ptr->r_no_0++;
    naming_cnt[name_ptr->id] = 120;
    n_disp_flag = 0;
    if (name_ptr->index != 0) {
        if (name_slang_check() != 0) {
            define_name_input();
        }
    } else {
        define_name_input();
    }
    for (i = 0; i < 4; i++) {
        name_ptr->end_flag[i] = 1;
    }
    ranking_name_entry();
    name_ptr->index = 3;
    if (name_ptr->id) {
        effect_89_init(8, DE_X[0] + 40, Text_Page_Y, 3, 1);
    } else {
        effect_89_init(8, (*&DE_X)[6] + 13, Text_Page_Y, 3, 1);
    }
}



void Name_Scs_Finish(void) {
    naming_cnt[name_ptr->id]--;
    if (naming_cnt[name_ptr->id] < 0) {
        Name_Input_f = 1;
        end_no_cut = 0;
    }
    Scs_char_move();
}



s32 Name_Input_sub(void) {
    u16 sw_up_w;
    u16 sw_data;
    name_ptr->old_code[name_ptr->index] = name_ptr->code[name_ptr->index];
    if (name_ptr->id) {
        sw_data = p2sw_0;
        sw_up_w = ~p2sw_1 & p2sw_0;
    } else {
        sw_data = p1sw_0;
        sw_up_w = ~p1sw_1 & p1sw_0;
    }
    if (sw_up_w & 0x3F0) {
        switch (name_ptr->code[name_ptr->index]) {
        case 45:
            return 2;
        case 46:
            return 3;
        default:
            return 1;
        }
    } else {
        if (sw_data & 0xC) {
            if (auto_n_check(4, 0, sw_data, sw_up_w)) {
                name_ptr->code[name_ptr->index]--;
                if (name_ptr->code[name_ptr->index] < 0) {
                    name_ptr->code[name_ptr->index] = 46;
                }
            }
            if (auto_n_check(8, 1, sw_data, sw_up_w)) {
                name_ptr->code[name_ptr->index]++;
                if (name_ptr->code[name_ptr->index] > 46) {
                    name_ptr->code[name_ptr->index] = 0;
                }
            }
        }
        return 0;
    }
}



s32 auto_n_check(chk_lvr, index, sw_data, sw_up_w)
u16 chk_lvr;
s16 index;
u16 sw_data;
u16 sw_up_w;
{
    if (sw_up_w & chk_lvr) {
        name_ptr->count1[index] = 0;
        name_ptr->count2[index] = 0;
        return 1;
    }
    if (sw_data & chk_lvr) {
        if (name_ptr->count1[index] > 12) {
            name_ptr->count2[index]++;
            if (name_ptr->count2[index] > 4) {
                name_ptr->count2[index] = 0;
                return 1;
            }
        } else {
            name_ptr->count1[index]++;
            name_ptr->count2[index] = 0;
        }
    } else {
        name_ptr->count1[index] = 0;
        name_ptr->count2[index] = 0;
    }
    return 0;
}



s32 name_slang_check(void) {
    const s16* slang_ptr = &slang_tbl[0][0];
    s16 i;
    s16 j;
    s16 slang_cnt;
    for (i = 0; i < 17; i++) {
        slang_cnt = 0;
        for (j = 0; j < 3; j++) {
            if (*slang_ptr == name_ptr->code[j]) {
                slang_cnt++;
            }
            slang_ptr++;
        }
        if (slang_cnt == 3) {
            return 1;
        }
    }
    return 0;
}



void define_name_input(void) {
    s16 work = random_16_com();
    if (work & 1) {
        name_ptr->code[0] = 2;
        name_ptr->code[1] = 0;
        name_ptr->code[2] = 15;
    } else {
        name_ptr->code[0] = 2;
        name_ptr->code[1] = 14;
        name_ptr->code[2] = 12;
    }
}



void ranking_state_check(void) {
    s16 joui;
    s16 j;
    s8* rank_in;
    NAME_WK* name;
    (*(NAME_WK * volatile *)&name_ptr)->rank = -1;
    (*(NAME_WK * volatile *)&name_ptr)->rank_sub = -1;
    for (joui = 0; joui < 4; joui++) {
        if (Rank_In[(*(NAME_WK * volatile *)&name_ptr)->id][joui] >= 0) {
            break;
        }
    }
    for (j = joui + 1; j < 4; j++) {
        if (Rank_In[(*(NAME_WK * volatile *)&name_ptr)->id][j] >= 0) {
            rank_in = Rank_In[(*(NAME_WK * volatile *)&name_ptr)->id];
            if (rank_in[joui] > rank_in[j]) {
                joui = j;
            }
        }
    }
    name = (*(NAME_WK * volatile *)&name_ptr);
    name->rank_in = name->rank = Rank_In[name->id][joui];
    name = (*(NAME_WK * volatile *)&name_ptr);
    name->rank_status = name->status = rank_stage_tbl[joui];
}



void ranking_name_entry(void) {
    RANK_NAME_W* ptr = &rank_name_w[name_ptr->id];
    ptr->code[0] = name_code_tbl[name_ptr->code[0]];
    ptr->code[1] = name_code_tbl[name_ptr->code[1]];
    ptr->code[2] = name_code_tbl[name_ptr->code[2]];
    ptr->code[3] = name_code_tbl[name_ptr->code[3]];
}



void name_work_init(pl_id)
s16 pl_id;
{
    s16 j;
    (*&name_wk)[pl_id].r_no_0 = 0;
    (*&name_wk)[pl_id].r_no_1 = 0;
    (*&name_wk)[pl_id].dmm = 0;
    (*&name_wk)[pl_id].end_flag[0] = 0;
    (*&name_wk)[pl_id].code[0] = 46;
    (*&name_wk)[pl_id].old_code[0] = 46;
    (*&name_wk)[pl_id].end_flag[3] = 0;
    (*&name_wk)[pl_id].old_code[3] = (*&name_wk)[pl_id].code[3] = 44;
    (*&sc_name_wk)[pl_id][0].c_cnt = 0;
    (*&sc_name_wk)[pl_id][0].type = 0;
    (*&sc_name_wk)[pl_id][0].r_no_0 = 0;
    (*&sc_name_wk)[pl_id][0].r_no_1 = 0;
    for (j = 1; j < 3; j++) {
        (*&name_wk)[pl_id].end_flag[j] = 0;
        (*&name_wk)[pl_id].code[j] = 0x2F;
        (*&name_wk)[pl_id].old_code[j] = 0x2F;
        (*&sc_name_wk)[pl_id][j].c_cnt = j;
        (*&sc_name_wk)[pl_id][j].type = j;
        (*&sc_name_wk)[pl_id][j].r_no_0 = 0;
        (*&sc_name_wk)[pl_id][j].r_no_1 = 0;
    }
}



/* provisional name */
void name_entry_commit_row(s16 pl_id, s16 pos_y) {
    s16 pos_x;
    s8 rank;
    if (pl_id) {
        pos_x = DE_X[0] + 37;
    } else {
        pos_x = (*&DE_X)[6] + 10;
    }
    switch (name_ptr->rank_in) {
    case 0:
        rank = 0;
        break;
    case 1:
        rank = 1;
        break;
    case 2:
        rank = 2;
        break;
    default:
        rank = 3;
        break;
    }
    rank_mark_set(pl_id, rank);
    tilemap_put_cell(pos_x - 1, pos_y, 16, name_ptr->rank_in + 1);
    tilemap_put_cell(pos_x, pos_y, 16, pl_id * 2 + 106);
    tilemap_put_cell(pos_x + 1, pos_y, 16, pl_id * 2 + 107);
    if (pl_id) {
        sc_ram_to_vram_opc(25, Game_setting.mode << 3, pos_y, 16);
    } else {
        sc_ram_to_vram_opc(24, Game_setting.mode << 2, pos_y, 16);
    }
}



void Scs_char_move(void) {
    s16 i;
    s8 ofs;
    ofs = 0;
    for (i = 0; i < 4; i++) {
        nsc_ptr = &sc_name_wk[name_ptr->id][ofs];
        Scs_move_sub();
        ofs++;
    }
}



s32 Scs_move_sub(void) {
    switch (nsc_ptr->r_no_0) {
    case 0:
    case_0:
        if (name_ptr->end_flag[nsc_ptr->type]) {
            nsc_ptr->r_no_0++;
            naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
        } else {
            current_sc_move2();
        }
        break;
    case 1:
        if (name_ptr->r_no_0 == 7) {
            nsc_ptr->r_no_0 = 2;
        }
        if (name_ptr->end_flag[nsc_ptr->type] == 0) {
            nsc_ptr->r_no_0 = 1;
            goto case_0;
        }
        break;
    case 2:
        break;
    }
    if (name_ptr->old_code[nsc_ptr->type] != name_ptr->code[nsc_ptr->type]) {
        s8 type;
        s32 id;
        nsc_ptr->n_disp_flag = 0;
        nsc_ptr->f_cnt = 0;
        type = nsc_ptr->type;
        id = name_ptr->id;
        naming_set(id, type, name_ptr->code[type]);
        return;
    }
    return (s32)name_ptr;
}



void current_sc_move2(void) {
    if (name_ptr->index != nsc_ptr->c_cnt) {
        return;
    }
    switch (nsc_ptr->r_no_1) {
    case 0:
        nsc_ptr->r_no_1++;
        nsc_ptr->f_cnt = 0;
        nsc_ptr->n_disp_flag = 0;
        naming_set(name_ptr->id, nsc_ptr->type, name_ptr->code[nsc_ptr->type]);
        break;
    case 1:
        if (name_ptr->r_no_0 > 5) {
            nsc_ptr->r_no_0++;
            break;
        }
        nsc_ptr->f_cnt++;
        if (nsc_ptr->f_cnt > 16) {
            nsc_ptr->f_cnt = 0;
            nsc_ptr->n_disp_flag++;
            if (nsc_ptr->n_disp_flag > 2) {
                nsc_ptr->n_disp_flag = 0;
            }
            naming_set(name_ptr->id, nsc_ptr->type, (nsc_ptr->n_disp_flag != 2) ? name_ptr->code[nsc_ptr->type] : 47);
        }
        break;
    }
}



void all_name_display(void) {
    s16 i;
    for (i = 0; i < 3; i++) {
        naming_set(name_ptr->id, (s8)i, name_ptr->code[i]);
    }
    naming_set(name_ptr->id, 3, 44);
    name_ptr->dmm = 1;
}



void start_cut_check(pl_id)
s16 pl_id;
{
    s16 i;
    if (Naming_Cut[pl_id]) {
        if (name_ptr->r_no_0 < 6) {
            name_ptr->r_no_0 = 6;
        }
        i = 0;
        do {
            if (name_ptr->end_flag[i] == 0) {
                name_ptr->code[i] = 44;
            }
        } while (++i < 3);
    }
}

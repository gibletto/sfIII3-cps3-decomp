/*
 * EFFECT_2.C  Effect work manager (part 2)
 *
 * Routines: exec_char_asxy, setup_free_program, setup_bg_quake_x, setup_bg_quake_y, setup_exdm_ix,
 * setup_dmv_use_flag, setup_disp_flag, setup_command_number.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "aboutspr.h"
#include "effect_2.h"



s32 exec_char_asxy(WORK* wk, u8 data) {
    s16* from_rom2;
    s32 st;
    s16 ix = data;
    ix *= 2;
    from_rom2 = &wk->step_xy_table[ix];
    st = *from_rom2++;
    st *= 256;
    if (wk->rl_flag) {
        wk->xyz[0].cal += st;
    } else {
        wk->xyz[0].cal -= st;
    }
    st = *from_rom2;
    st *= 256;
    wk->xyz[1].cal += st;
}



void setup_free_program(WORK* wk, u8 arg) {}/* Start a horizontal background quake using quake pattern ix. */
void setup_bg_quake_x(WORK* wk, u8 ix)
{
    bg_w.quake_x_index = ix;
}

/* Start a vertical background quake using quake pattern ix. */
void setup_bg_quake_y(WORK* wk, u8 ix)
{
    bg_w.quake_y_index = ix;
}



void setup_exdm_ix(PLW* wk, u8 ix) {
    wk->exdm_ix = ix;
}


void setup_dmv_use_flag(PLW* wk, u8 use) {
    wk->dm_vital_use = use;
}



void setup_disp_flag(WORK* wk, s8 flag) {
    wk->disp_flag = flag;
}

/* Queue a special command number for the player to perform. */
void setup_command_number(PLW* wk, u8 cmd_no)
{
    wk->cmd_request = cmd_no;
}

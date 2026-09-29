#ifndef EFF00_H
#define EFF00_H

#include "structs.h"

s32 effect_00_init(WORK* wk);
void setup_dmv_use_flag(PLW* wk, u8 use);
void setup_disp_flag(WORK* wk, s8 flag);
void setup_command_number(PLW* wk, u8 cmd_no);
void renewal_table_data(WORK_Other_JUDGE* ewk);
void renewal_table_address(WORK_Other_JUDGE* ewk, WORK* twk);
void effect_00_move(WORK_Other_JUDGE* ewk);
void get_new_parts_data(WORK_Other* ewk, PLW* mwk);
void effect_01_move(WORK_Other* ewk);
void set_parts_disp_flag(WORK_Other* ewk, PLW* mwk);

#endif

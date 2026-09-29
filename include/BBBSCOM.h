#ifndef BBBSCOM_H
#define BBBSCOM_H

#include "structs.h"

s32 set_bonus_game_nando(u16 swdat);
void bbbs_com_execute(PLW* wk);
void bbbs_com_initialize(void);
s32 katteni_bonus_nando(u16 swdat);
void makeup_bonus_game_level(s16 ix);
s32 set_bonus_game_difficulty(s16 emid);

#endif

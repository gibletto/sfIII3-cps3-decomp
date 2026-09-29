#ifndef EFFH3_H
#define EFFH3_H

#include "structs.h"

s32 effect_H3_init(void);
void effH5_0000(WORK_Other* ewk);
void effH5_0001(WORK_Other* ewk);
void effH5_0002(WORK_Other* ewk);
void effH5_0003(WORK_Other* ewk);
void effH5_0004(WORK_Other* ewk);
void effH5_init_common(WORK_Other* ewk);
s32 effect_H6_init();
void effect_H3_move(WORK_Other* ewk);
void effect_H4_move(WORK_Other* ewk);
s32 effect_H5_init(u8 type);
void effect_H5_move(WORK_Other* ewk);
void effect_H6_move(WORK_Other* ewk);

#endif

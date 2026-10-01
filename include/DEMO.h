#ifndef DEMO_H
#define DEMO_H

#include "structs.h"

void Set_Mode_Pos(s16* x, s16 add, s16 base);
s32 CAPCOM_Logo(void);
s32 Title(void);
void Setup_Demo_PL(void);
void Setup_Demo_Arts(void);
void Setup_Demo_Stage(void);
void Setup_Select_Demo_PL(void);
void Demo00(void);
s32 Play_Demo(void);
void Demo01(void);
s32 Title_At_a_Dash(void);
void Logo_Capcom(void);
void Logo_Etc(void);
void Logo_Warning(void);
void draw_operator_info(s32 y);

#endif

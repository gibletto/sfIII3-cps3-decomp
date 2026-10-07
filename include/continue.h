#ifndef CONTINUE_H
#define CONTINUE_H

#include "structs.h"

void Additinal_Score_DM(WORK_Other* wk, u32 ix);
s16 Check_Count_Cut(s16 PL_id, s16 Limit);
void GameOver_2nd(void);
void GameOver_3rd(void);
s32 Short_Ending_Scene(void);
void Continue_1st(void);
void Continue_2nd(void);
s32 Continue_3rd(void);
void Continue_4th(void);
void Continue_5th(void);
void Setup_Continue_OBJ(void);
s32 Check_Exit_Continue(void);
void Disp_Personal_Count(s16 id, char count);
void Clear_Win_Type(void);
s32 Check_Coin_In(s16 pl);
void Setup_Result_OBJ(void);
void cal_damage_vitality(PLW* as, PLW* ds);
void cal_damage_vitality_eff(WORK_Other* as, PLW* ds);
s32 Continue_Scene(void);
void Score_Sub(void);
s32 Clear_Personal_Data(s16 PL_id);
void Disp_Player_Score();

#endif

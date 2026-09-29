#ifndef WIN_H
#define WIN_H

#include "structs.h"

void Additinal_Score_DM(WORK_Other* wk, u32 ix);
s16 Check_Count_Cut(s16 PL_id, s16 Limit);
s32 Check_Short_Ending(void);
s32 Winner_Scene(void);
s32 Loser_Scene(void);
void Setup_Virtual_BG(s16 bg, s16 x, s16 y);
void Setup_Wins_OBJ(void);
s32 Game_Over(void);
s32 GameOver_1st(void);
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
u32 Disp_Personal_Count(s16 id, char count);
void Clear_Win_Type(void);
s32 Check_Coin_In(s16 pl);
void Setup_Result_OBJ(void);
void cal_damage_vitality(PLW* as, PLW* ds);
void cal_damage_vitality_eff(WORK_Other* as, PLW* ds);
s16 Continue_Scene(void);
s32 Win_1st(void);
void Win_2nd(void);
void Win_3rd(void);
void Win_4th(void);
void Win_5th(void);
void Win_6th(void);
void Lose_2nd(void);
void Lose_3rd(void);
void Lose_4th(void);
void Lose_5th(void);
void Lose_6th(void);
void Lose_1st(void);
void Score_Sub(void);
s32 Clear_Personal_Data(s16 PL_id);
void Disp_Player_Score(s16 id);

#endif

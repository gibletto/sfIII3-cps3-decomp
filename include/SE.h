#ifndef SE_H
#define SE_H

#include "structs.h"

void Call_Se(WORK_Other* ewk, u16 Code);
s32 Check_Bonus_SE();
s32 Check_Finish_SE(void);
void wipe_pattern_or_cols(s16 kind, s16 row);
void wipe_pattern_restore_cols(s16 kind, s16 row);
void mix_or_512(void);
void mix_put_512(void);
void wipe_pattern_set(s16 kind, s16 row, s16 mix);
void wipe_pattern_and_low(s16 kind, s16 row);
void wipe_mask_set_cols(s16 kind, s16 row);
void wipe_mask_and_cols(s16 kind, s16 row);
void bgm_fade_in_stage(s16 x);
void Se_Myself(WORK_Other* ewk, u16 Code);
void Se_Myself_Die(WORK_Other* ewk, u16 Code);
void Se_Let_SP(WORK_Other* ewk, u16 Code);
s32 Se_Term(WORK_Other* ewk, u16 Code);
s32 Check_Voice_SE();
void Finish_SE(void);
u16 Get_Position(PLW* wk);
void Se_Let(WORK_Other* ewk, u16 Code);
void Stage_BGM(u16 Stage_Number, s32 Round_Number);
void bgm_request();
void Se_Shock(WORK_Other* ewk, u16 Code);
void Sound_SE();
void sound_system_init(void);
void Se_Dummy(WORK_Other* ewk, u16 Code);
void voice_all_off(void);

#endif

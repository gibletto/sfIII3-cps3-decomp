#ifndef EXTERN_H
#define EXTERN_H

#include "structs.h"

void task_exit_to_system(void);
void effB1_trans(WORK* ewk);
void Bonus_bg();
s32 Check_Shell_Another_in_Flip(PLW* wk);
void bios_vector_restart(s32 mode, s32 arg);
void Meltw(u16* s, u16* d, s32 file_ptr);
void Push_LDREQ_Queue_Player(s16 id, s16 ix);
s32 Ranking();
s32 Setup_Directory_Record_Data();
s32 Setup_Target_PL();
char * _builtin_strcpy(char* dst, const char* src);
void cpRevivalTask();
void cpu_hang_forever(void);
void damage_atemi_setup(PLW* wk, PLW* ek);
s32 emGetMaxBlocking();
s32 emLevelRemake(s32 now, s32 max, s32 exd);
void get_message_conn_data(WORK_Other_CONN* ewk, s16 kind, s16 pl, s16 msg);
void njWaitVSync_with_N();
void op_bg1_0003(s16 r_index);
void op_bg2_0000(void);
void op_bg2_0001(void);
void op_bg2_0002(void);
void op_bg2_0003(void);
void set_base_data_metamorphose(PLW* wk, s16 dmid);
void task_sleep(s32 frames);
void task_wait(void);
void task_dispatch(TCB* task);

#endif

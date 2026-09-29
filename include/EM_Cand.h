#ifndef EM_CAND_H
#define EM_CAND_H

#include "structs.h"

s16 Check_EM_Buff();
void Check_Same_CPU(s16 PL_id);
void Combo_Demo_Init(void);
void Setup_Combo_Demo_PL(void);
void Setup_Candidate_Buff();
s32 Check_EM_Sub();
void Initialize_EM_Candidate(s16 PL_id);

#endif

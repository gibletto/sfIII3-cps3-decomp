/*
 * SYS_SUB2.C  Small system subroutines
 *
 * Switch_Priority_76 queues order 7 for object slot 56 on the next frame.
 * Clear_Disp_Ranking clears a player's four rank-display requests and rank-in entries.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "SYS_sub2.h"



void Switch_Priority_76(void) {
    Order[56] = 7;
    Order_Timer[56] = 1;
}



void Clear_Disp_Ranking(s16 PL_id) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        Request_Disp_Rank[PL_id][i] = -1;
        Rank_In[PL_id][i] = -1;
    }
}

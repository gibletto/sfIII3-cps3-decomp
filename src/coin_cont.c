/*
 * COIN_CONT.C  Coin sound and continue count redraw
 *
 * coin_in_sound_request requests the coin sound when a coin has just dropped in either chute
 * and Demo_Flag is 1: sound 115 when E_No0 is 1, otherwise sound 106.
 * Redisp_Continue_Count redraws the CONTINUE message and the remaining count for a player
 * whose entry state shows the continue prompt.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "Win.h"
#include "win_2.h"
#include "gameover.h"
#include "continue.h"
#include "pow_pow.h"
#include "textsound.h"
#include "textsound_2.h"
#include "textsound_3.h"
#include "coin_cont.h"



/* provisional name */
void coin_in_sound_request(void) {
    if (coin_chute1_w.dropped | coin_chute2_w.dropped) {
        if (Demo_Flag == 1) {
            sound_request(E_No0 == 1 ? 115 : 106);
        }
    }
}

/* provisional name */
void Redisp_Continue_Count(s16 pl_id) {
    if (E_Number[pl_id][0] == 1) {
        tilemap_print_string_attr(DE_X[Entry_Mes_Wide[pl_id]] + (&Entry_Mes_X[0])[pl_id], Text_Page_Y, 0x12, msg_continue);
        ((void (*)(s32, s32))Disp_Personal_Count)(pl_id, Continue_Count[pl_id]);
    }
}

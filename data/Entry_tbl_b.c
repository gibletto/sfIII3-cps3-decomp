/*
 * ENTRY_TBL_B.C  player entry and credit messages
 *
 * The fixed-width messages of the entry / credit task: FREE PLAY, INSERT COIN(S), CONTINUE and
 * its count, GAME OVER, JOIN IN, PRESS START, PLEASE WAIT, the INSERT MORE COIN(S) prompts and
 * the CREDIT and COINS displays; a control character in a string stands for a player number or
 * coin count. Read by ENTRY_2.C; msg_continue is also read by COIN_CONT.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s8 msg_free_play[20] = "     FREE PLAY     ";

const s8 msg_blank[20] = "                   ";

const s8 msg_blank18[20] = "                  ";

const s8 msg_continue[20] = "     CONTINUE_     ";

const s8 msg_continue_cnt[20] = "     CONTINUE_\t    ";

const s8 msg_game_over[20] = "     GAME OVER     ";

/* Messages whose digits are the font's glyph numbers 0-9 (not ASCII) are written as numbers; the comment
   after each name is the text it shows. */
const s8 msg_insert_2coins[24] = {  /* "   INSERT 2 COINS   " */
    32, 32, 32, 73, 78, 83, 69, 82,
    84, 32, 2, 32, 67, 79, 73, 78,
    83, 32, 32, 32, 0, 0, 0, 0,
};

const s8 msg_insert_coin[20] = "    INSERT COIN    ";

const s8 msg_insert_coins[20] = "   INSERT   COINS  ";

const s8 msg_join_in[20] = "      JOIN IN      ";

const s8 msg_press_2p_start[20] = "   PRESS \002P START  ";

const s8 msg_press_1p_start[20] = "   PRESS \001P START  ";

const s8 msg_please_wait[20] = "    PLEASE WAIT    ";

const s8 msg_insert_more_coin[20] = "INSERT   MORE COIN ";

const s8 msg_insert_more_coins[20] = "INSERT   MORE COINS";

const s8 msg_coins[8] = "COINS:";

const s8 msg_credit[12] = "CREDIT :";

const s8 msg_plural_s[4] = "S";

const s8 msg_credits[12] = "CREDITS:";

const s8 msg_space[4] = " ";

const s8 msg_blank6[8] = "      ";

const s8 msg_coin_frac[8] = "( / )";

const s8 msg_blank25[28] = "                         ";

const s8 msg_insert_1_more[20] = "INSERT 1 MORE COIN";

const s8 msg_press_1or2_start[28] = "PRESS \001 OR \002 START BUTTON";

const s8 msg_insert_2_more[20] = "INSERT 2 MORE COINS";

const s8 msg_press_1p_button[24] = "PRESS \001P START BUTTON";

const s8 msg_press_2p_button[24] = "PRESS \002P START BUTTON";
const s8 str_INSERT_COIN[20] = "     INSERT COIN   ";
const s8 str_INSERT_COINS[20] = "   INSERT \002 COINS  ";
const s8 str_INSERT_COINS_2[20] = "   INSERT \003 COINS  ";
const s8 str_INSERT_COINS_3[20] = "   INSERT \004 COINS  ";
const s8 str_INSERT_COINS_4[20] = "   INSERT \005 COINS  ";
const s8 str_INSERT_COINS_5[20] = "   INSERT \006 COINS  ";
const s8 str_INSERT_COINS_6[20] = "   INSERT \007 COINS  ";
const s8 str_INSERT_COINS_7[20] = "   INSERT \010 COINS  ";
const s8 str_INSERT_COINS_8[20] = "   INSERT \t COINS  ";

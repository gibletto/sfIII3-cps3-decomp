/*
 * EFFF9_TBL.C  object viewer labels
 *
 * The four labels "BLK", "OBJ", "MR " and "POS" that the effect F7 debug object viewer prints
 * on the text layer. Read by EFFF7.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s8 effF7_blk_msg[4] = "BLK";

const s8 effF7_obj_msg[4] = "OBJ";

const s8 effF7_mr_msg[4] = "MR ";

const s8 effF7_pos_msg[4] = "POS";

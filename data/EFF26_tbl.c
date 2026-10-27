/*
 * EFF26_TBL.C  breakable object part counts
 *
 * eff26_num gives the number of effect 26 parts created for each type; the word after the
 * count starts the part list reached through scr_obj_data26. Read by EFF26.C, the parts of
 * breakable stage objects.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s16 eff26_num[2] = {
    1, 0,
};

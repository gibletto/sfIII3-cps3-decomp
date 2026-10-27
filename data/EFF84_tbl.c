/*
 * EFF84_TBL.C  centre-screen message display times
 *
 * Time_Data gives how long each kind of centre-screen message stays up. Read by EFF84.C, the
 * centre-screen message controller.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


const s8 Time_Data[5] = {
    80, 90, 50, 50, 50,
};


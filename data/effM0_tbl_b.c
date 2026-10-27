/*
 * EFFM0_TBL_B.C  stage animal running times
 *
 * animal_0005_tbl is the random running time of an animal using behaviour animal_0005 before
 * it stops, stands and runs off. Read by EFFM0.C.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

const s16 animal_0005_tbl[16] = {
    40, 50, 160, 70, 80, 100, 30, 200,
    340, 10, 110, 18, 40, 60, 30, 150,
};

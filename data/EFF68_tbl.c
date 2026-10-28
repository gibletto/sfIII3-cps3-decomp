/*
 * EFF68_TBL.C  bg090 waypoint flying objects
 *
 * eff68_data_tbl gives, for each of the three objects, its points to fly through, the timing
 * and the animation numbers of each leg. Read by EFF68.C, which holds effects 67 and 68.
 */

#include "types.h"
#include "structs.h"

#pragma section TBL


/* one row per object: { my_family, x, y, old_rno[2] .. old_rno[7], char_index, routine_no[6], priority, routine_no[4] } */
const s16 eff68_data_tbl[4][13] = {
    { 2, 432, 192, 504, 180, 576, 172, 522, 160, 8, 9, 73, 0 },
    { 2, 592, 208, 664, 196, 736, 188, 682, 176, 8, 9, 73, 20 },
    { 3, 736, 160, 808, 148, 880, 140, 826, 128, 10, 11, 83, 50 },
    { 3, 624, 192, 696, 180, 768, 172, 714, 160, 10, 11, 83, 40 },
};

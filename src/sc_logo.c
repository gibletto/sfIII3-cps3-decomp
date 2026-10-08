/*
 * sc_logo.c  SF3 logo on the text layer
 *
 * SF3_logo clears a block of the text (fix) layer character area and then puts the
 * "SF3" logo as a 16 x 6 cell block with scfont_sqput, at the column taken from the DE_X
 * table and the row passed in. Called by effect 59.
 */

#include "structs.h"
#include "work.h"
#include "romdata.h"
#include "extern.h"
#include "sc_trans.h"
#include "sc_logo.h"
u32 SF3_logo(s16 y)
{
    sc_chr_clear(384, 128);
    scfont_sqput(DE_X[3] + 16, y + 10, 16, 6, 58, 384);
}

/*
 * SND_BANK.C  instrument banks (section SNDBANK, 06788000)
 *
 * snd_bank_rom_tbl points at 16 banks. A bank starts with one offset per program, from the bank's start,
 * to that program's key splits (0: no program); a program is a list of SNDPATCH, one per key range up to
 * note_ceiling, ending with note_ceiling -1. Each SNDPATCH names the sample it plays (snd_sample_rom_tbl)
 * with its pan, volume, pitch and envelope curves. Banks 9-15 are empty.
 */

#include "types.h"
#include "structs.h"

#pragma section SNDBANK

extern const u16 snd_bank_00[], snd_bank_01[], snd_bank_02[], snd_bank_03[], snd_bank_04[], snd_bank_05[], snd_bank_06[], snd_bank_07[], snd_bank_08[], snd_bank_09[], snd_bank_10[], snd_bank_11[], snd_bank_12[], snd_bank_13[], snd_bank_14[], snd_bank_15[];

u8* const snd_bank_rom_tbl[16] = {
    (u8*)snd_bank_00,
    (u8*)snd_bank_01,
    (u8*)snd_bank_02,
    (u8*)snd_bank_03,
    (u8*)snd_bank_04,
    (u8*)snd_bank_05,
    (u8*)snd_bank_06,
    (u8*)snd_bank_07,
    (u8*)snd_bank_08,
    (u8*)snd_bank_09,
    (u8*)snd_bank_10,
    (u8*)snd_bank_11,
    (u8*)snd_bank_12,
    (u8*)snd_bank_13,
    (u8*)snd_bank_14,
    (u8*)snd_bank_15,
};

const u16 snd_bank_00[128] = {  /* program -> offset of its key splits */
    256, 342, 428, 502, 588, 674, 866, 1058, 1180, 1266, 1280, 1318,
    1404, 1454, 0, 0, 0, 0, 1646, 1660, 1674, 1688, 1702, 1752,
    1766, 1780, 1794, 1808, 1822, 1836, 1850, 1864, 1878, 1892, 1906, 1920,
    1934, 1948, 1962, 1976, 1990, 2004, 2042, 2056, 2070, 2084, 2098, 2136,
    2150, 2164, 2178, 2192, 2206, 2220, 2234, 2248, 2262, 2276, 2290, 2304,
    2318, 2332, 2394, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_00_prog_000[7] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   16,   80,   86,    0,   63,   63,  127,    1,   63 },
    {   42,  255,   16,   62,   87,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,   88,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,   89,    0,   63,   63,  127,    1,   63 },
    {   46,  255,   16,   66,   90,    0,   63,   63,  127,    1,   63 },
    {   47,  255,   16,   67,   91,    0,   63,   63,  127,    1,   63 },
    {   48,  255,   16,   68,   92,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_001[7] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,   93,    0,   63,   63,  127,    1,   63 },
    {   42,  255,   16,   62,   94,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,   95,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,   96,    0,   63,   63,  127,    1,   63 },
    {   47,  255,   16,   67,   97,    0,   63,   63,  127,    1,   63 },
    {   48,  255,   16,   68,   98,    0,   63,   63,  127,    1,   63 },
    {   49,  255,   16,   69,   99,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_002[6] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,  108,    0,   63,   63,  127,    1,   63 },
    {   43,  255,   16,   63,  109,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,  110,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,  111,    0,   63,   63,  127,    1,   63 },
    {   46,  255,   16,   66,  112,    0,   63,   63,  127,    1,   63 },
    {   48,  255,   16,   68,  113,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_003[7] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,  126,    0,   63,   63,  127,    1,   63 },
    {   42,  255,   16,   62,  127,    0,   63,   63,  127,    1,   63 },
    {   43,  255,   16,   63,  128,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,  129,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,  130,    0,   63,   63,  127,    1,   63 },
    {   46,  255,   16,   66,  131,    0,   63,   63,  127,    1,   63 },
    {   47,  255,   16,   67,  132,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_004[7] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,  133,    0,   63,   63,  127,    1,   63 },
    {   42,  255,   16,   62,  134,    0,   63,   63,  127,    1,   63 },
    {   43,  255,   16,   63,  135,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,  136,    0,   63,   63,  127,    1,   63 },
    {   46,  255,   16,   66,  137,    0,   63,   63,  127,    1,   63 },
    {   47,  255,   16,   67,  138,    0,   63,   63,  127,    1,   63 },
    {   49,  255,   16,   69,  139,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_005[16] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   36,  255,   16,   56,  165,    0,   63,   63,  122,   36,   36 },
    {   39,  255,   16,   59,  167,    0,   63,   63,  122,   36,   36 },
    {   40,  255,   16,   40,  170,    0,   63,   63,  112,   32,   56 },
    {   42,  255,    0,   42,  166,    0,   63,   63,  122,   36,   36 },
    {   45,  255,    5,   65,  114,    0,   63,   53,  122,   36,   36 },
    {   46,  255,  -24,   46,  169,    0,   63,   63,  122,   36,   36 },
    {   49,  255,   -8,   49,  168,    0,   63,   63,  122,   32,   32 },
    {   51,  255,  -20,   51,  172,    0,   63,   63,  122,   32,   32 },
    {   52,  255,    0,   72,  159,    0,   63,   58,  122,    1,   50 },
    {   53,  255,    0,   73,  149,    0,   63,   48,  122,   41,   41 },
    {   54,  255,    8,   54,  171,    0,   63,   63,  122,   36,   36 },
    {   55,  255,    0,   75,  150,    0,   63,   48,  122,   41,   41 },
    {   56,  255,   -8,   76,  151,    0,   63,   48,  122,   41,   41 },
    {   57,  255,   -8,   77,  152,    0,   63,   48,  122,   41,   41 },
    {   59,  255,    0,   59,  160,    0,   63,   58,  122,    1,   50 },
    {  127,  255,    0,   83,  157,    0,   63,   63,  122,    1,   56 },
};
const SNDPATCH snd_bank_00_prog_006[16] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   36,  255,   16,   56,  165,    0,   63,   63,  122,   36,   36 },
    {   39,  255,   16,   59,  167,    0,   63,   63,  122,   36,   36 },
    {   40,  255,   16,   40,  170,    0,   63,   63,  112,   32,   56 },
    {   42,  255,   20,   54,  692,    0,   63,   63,  122,   40,   40 },
    {   45,  255,    5,   65,  114,    0,   63,   53,  122,   36,   36 },
    {   46,  255,    0,   58,  693,    0,   63,   63,  122,   36,   36 },
    {   49,  255,   -8,   49,  168,    0,   63,   63,  122,   32,   32 },
    {   51,  255,  -20,   51,  172,    0,   63,   63,  122,   32,   32 },
    {   52,  255,    0,   72,  159,    0,   63,   58,  122,    1,   50 },
    {   53,  255,    0,   73,  149,    0,   63,   48,  122,   41,   41 },
    {   54,  255,    8,   54,  171,    0,   63,   63,  122,   36,   36 },
    {   55,  255,    0,   75,  150,    0,   63,   48,  122,   41,   41 },
    {   56,  255,   -8,   76,  151,    0,   63,   48,  122,   41,   41 },
    {   57,  255,   -8,   77,  152,    0,   63,   48,  122,   41,   41 },
    {   59,  255,    0,   59,  160,    0,   63,   58,  122,    1,   50 },
    {   72,  255,  -24,   92,  115,    0,   63,   63,  127,    1,   63 },
};
const SNDPATCH snd_bank_00_prog_007[10] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   60,  255,   28,   80,  588,    0,   63,   63,  127,    1,   48 },
    {   61,  255,   28,   81,  589,    0,   63,   63,  127,    1,   48 },
    {   62,  255,   28,   82,  590,    0,   63,   63,  127,    1,   48 },
    {   63,  255,   28,   83,  591,    0,   63,   63,  127,    1,   48 },
    {   64,  255,    0,   84,  592,    0,   63,   63,  127,    1,   48 },
    {   65,  255,   28,   85,  593,    0,   63,   63,  127,    1,   48 },
    {   66,  255,   28,   86,  594,    0,   63,   63,  127,    1,   48 },
    {   67,  255,   28,   87,  595,    0,   63,   63,  127,    1,   48 },
    {   68,  255,   28,   88,  596,    0,   63,   63,  127,    1,   48 },
    {   69,  255,    0,   89,  597,    0,   63,   63,  127,    1,   48 },
};
const u16 snd_bank_00_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_008[7] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   60,  255,    0,   80,  598,    0,   63,   63,  127,    1,   48 },
    {   61,  255,   24,   81,  599,    0,   63,   63,  127,    1,   48 },
    {   62,  255,   24,   82,  600,    0,   63,   63,  127,    1,   48 },
    {   63,  255,   24,   83,  601,    0,   63,   63,  127,    1,   48 },
    {   64,  255,   24,   84,  602,    0,   63,   63,  127,    1,   48 },
    {   67,  255,   16,   87,  603,    0,   63,   63,  127,    1,   48 },
    {   68,  255,   16,   88,  604,    0,   63,   63,  127,    1,   48 },
};
const u16 snd_bank_00_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  231,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_010[3] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   72,  255,   36,   92,  642,    0,   63,   48,  112,   36,   36 },
    {   74,  255,   20,   94,  643,    0,   63,   63,  127,    1,   63 },
    {  127,  255,    8,   99,  644,    0,   63,   63,  122,   38,   38 },
};
const u16 snd_bank_00_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_011[7] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,  645,    0,   63,   63,  127,    1,   63 },
    {   43,  255,   16,   63,  646,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,  647,    0,   63,   63,  127,    1,   63 },
    {   45,  255,   16,   65,  648,    0,   63,   63,  127,    1,   63 },
    {   46,  255,   16,   66,  649,    0,   63,   63,  127,    1,   63 },
    {   47,  255,   16,   67,  650,    0,   63,   63,  127,    1,   63 },
    {   48,  255,   16,   68,  651,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_012[4] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   16,   61,  664,    0,   63,   63,  127,    1,   63 },
    {   42,  255,   16,   62,  665,    0,   63,   63,  127,    1,   63 },
    {   43,  255,   16,   63,  666,    0,   63,   63,  127,    1,   63 },
    {   44,  255,   16,   64,  667,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_013[16] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   41,  255,   24,   61,  676,    0,   63,   63,  127,    1,   54 },
    {   42,  255,   16,   62,  677,    0,   63,   63,  127,    1,   54 },
    {   43,  255,   16,   63,  678,    0,   63,   63,  127,    1,   54 },
    {   44,  255,   16,   64,  679,    0,   63,   63,  127,    1,   54 },
    {   45,  255,   16,   65,  680,    0,   63,   63,  127,    1,   54 },
    {   48,  255,   16,   68,  681,    0,   63,   63,  127,    1,   54 },
    {   53,  255,   24,   73,  682,    0,   63,   63,  127,    1,   54 },
    {   54,  255,   16,   74,  683,    0,   63,   63,  127,    1,   54 },
    {   55,  255,   16,   75,  684,    0,   63,   63,  127,    1,   54 },
    {   56,  255,   16,   76,  685,    0,   63,   63,  127,    1,   54 },
    {   65,  255,   32,   85,  686,    0,   63,   63,  127,    1,   54 },
    {   67,  255,   24,   87,  687,    0,   63,   63,  127,    1,   54 },
    {   68,  255,   24,   88,  688,    0,   63,   63,  127,    1,   54 },
    {   69,  255,   24,   89,  689,    0,   63,   63,  127,    1,   54 },
    {   70,  255,   24,   90,  690,    0,   63,   63,  127,    1,   54 },
    {   71,  255,   24,   91,  691,    0,   63,   63,  127,    1,   54 },
};
const SNDPATCH snd_bank_00_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   24,   68,  675,    0,   63,    1,    1,    1,   51 },
};
const u16 snd_bank_00_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   68,  652,    0,   63,   63,  122,    1,   56 },
};
const u16 snd_bank_00_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   65,  102,    0,   63,   53,  122,    1,   56 },
};
const u16 snd_bank_00_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_021[1] = {  /* program 21 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   63,  154,    0,   63,   57,   80,   26,   56 },
};
const u16 snd_bank_00_prog_021_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_022[4] = {  /* program 22 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   52,  255,    8,   65,  123,    0,   63,   56,   80,    1,   53 },
    {   64,  255,    0,   77,  124,    0,   63,   56,  116,   37,   48 },
    {   69,  255,  -16,   89,  125,    0,   63,   63,  127,    1,   32 },
    {   72,  255,  -24,   92,  148,    0,   63,   63,  127,    1,   32 },
};
const u16 snd_bank_00_prog_022_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_023[1] = {  /* program 23 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  155,    0,   63,   63,  127,   34,   34 },
};
const u16 snd_bank_00_prog_023_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_024[1] = {  /* program 24 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   16,   77,  117,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_024_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_025[1] = {  /* program 25 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   12,   77,  118,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_025_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_026[1] = {  /* program 26 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -8,   77,  119,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_026_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_027[1] = {  /* program 27 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -8,   77,  120,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_027_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_028[1] = {  /* program 28 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -12,   77,  121,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_028_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_029[1] = {  /* program 29 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -12,   77,  122,    0,   63,   48,  116,   32,   37 },
};
const u16 snd_bank_00_prog_029_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    4,   75,  141,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   75,  142,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   75,  143,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   75,  144,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -6,   75,  145,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    4,   75,  146,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   75,  147,    0,   63,   48,  122,    1,   47 },
};
const u16 snd_bank_00_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   84,  100,    0,   63,   48,  122,    1,   56 },
};
const u16 snd_bank_00_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   92,  101,    0,   63,   48,  122,    1,   56 },
};
const u16 snd_bank_00_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   63,  103,    0,   63,   63,  127,   32,   53 },
};
const u16 snd_bank_00_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    8,   88,  153,    0,   63,   63,  122,   36,   56 },
};
const u16 snd_bank_00_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_041[3] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   59,  255,    0,   68,  161,    0,   63,   63,  112,    1,   51 },
    {   71,  255,    0,   84,  162,    0,   63,   63,  112,    1,   51 },
    {  127,  255,  -28,   96,  163,    0,   63,   63,  112,    1,   51 },
};
const u16 snd_bank_00_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   99,  104,    0,   63,   48,  122,    1,   56 },
};
const u16 snd_bank_00_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -16,   92,  164,    0,   63,   58,  122,    1,   56 },
};
const u16 snd_bank_00_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_044[1] = {  /* program 44 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   77,  116,    0,   63,   48,  122,    1,   56 },
};
const u16 snd_bank_00_prog_044_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   84,  140,    0,   63,   48,  122,    1,   50 },
};
const u16 snd_bank_00_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_046[3] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   65,  255,  -16,   80,  105,    0,   63,   48,  122,    1,   53 },
    {   77,  255,    0,   92,  106,    0,   63,   48,  122,    1,   53 },
    {  127,  255,   16,  104,  107,    0,   63,   48,  122,    1,   53 },
};
const u16 snd_bank_00_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   82,  156,    0,   63,   63,  127,    1,   51 },
};
const u16 snd_bank_00_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   79,  158,    0,   63,   58,   96,   37,   37 },
};
const u16 snd_bank_00_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_049[1] = {  /* program 49 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   77,  653,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_049_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_050[1] = {  /* program 50 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -14,   77,  654,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_050_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_051[1] = {  /* program 51 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -12,   77,  655,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_051_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_052[1] = {  /* program 52 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -12,   77,  656,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_052_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_053[1] = {  /* program 53 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -12,   77,  657,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_053_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_054[1] = {  /* program 54 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -8,   77,  658,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_054_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_055[1] = {  /* program 55 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   28,   77,  659,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_055_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_056[1] = {  /* program 56 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,   77,  660,    0,   63,   63,  122,   32,   48 },
};
const u16 snd_bank_00_prog_056_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_057[1] = {  /* program 57 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  661,    0,   63,   63,  127,    1,   51 },
};
const u16 snd_bank_00_prog_057_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_058[1] = {  /* program 58 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  662,    0,   63,   48,  112,   38,   38 },
};
const u16 snd_bank_00_prog_058_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_059[1] = {  /* program 59 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  663,    0,   63,   63,  122,    1,   51 },
};
const u16 snd_bank_00_prog_059_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,   80,  668,    0,   63,   48,  122,   39,   48 },
};
const u16 snd_bank_00_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_061[5] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   36,  255,   36,   56,  669,    0,   63,   63,  127,    1,   51 },
    {   37,  255,   24,   57,  670,    0,   63,   63,  127,    1,   51 },
    {   38,  255,   16,   58,  671,    0,   63,   63,  127,    1,   51 },
    {   76,  255,    0,   89,  672,    0,   63,   63,  127,    1,   63 },
    {  127,  255,    0,  101,  673,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_00_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_00_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   24,   77,  674,    0,   63,   48,  122,   36,   54 },
};
const u16 snd_bank_00_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_01[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 508, 522, 536, 550, 564, 0,
    578, 592, 606, 620, 634, 648, 662, 676, 690, 0, 704, 718,
    732, 746, 0, 0, 760, 774, 788, 0, 0, 0, 802, 816,
    830, 844, 858, 872, 886, 900, 914, 928, 942, 956, 970, 984,
    0, 0, 998, 1012, 0, 1026, 1040, 1054, 1068, 0, 1082, 1096,
    1110, 1124, 1138, 1152, 1166, 1180, 1194, 1208, 0, 0, 0, 1222,
    1236, 1250, 1264, 1278, 0, 1292, 0, 1306, 1320, 1334, 1348, 1362,
    1376, 1390, 1404, 1418, 1432, 1446, 1460, 1474, 1488, 1502, 1516, 1530,
    1544, 1558, 1572, 1586, 1600, 1614, 1628, 1642, 1656, 1670, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_01_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   56,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   55,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   54,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   62,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   61,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   60,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   59,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   58,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   57,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   63,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   64,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   65,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   66,    0,   63,   63,  127,   41,   51 },
};
const u16 snd_bank_01_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   67,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   68,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   69,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   32,    0,   70,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   71,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    0,    0,   63,   63,  127,   42,   51 },
};
const u16 snd_bank_01_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    1,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    2,    0,   63,   63,  127,    1,   51 },
};
const u16 snd_bank_01_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_021[1] = {  /* program 21 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    3,    0,   63,   63,  127,   33,   51 },
};
const u16 snd_bank_01_prog_021_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_022[1] = {  /* program 22 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    4,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_022_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_024[1] = {  /* program 24 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    5,    0,   63,   63,  127,    1,   51 },
};
const u16 snd_bank_01_prog_024_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_025[1] = {  /* program 25 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    6,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_025_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_026[1] = {  /* program 26 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    7,    0,   63,   63,  127,   37,   51 },
};
const u16 snd_bank_01_prog_026_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_027[1] = {  /* program 27 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    8,    0,   63,   63,  127,   37,   51 },
};
const u16 snd_bank_01_prog_027_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_028[1] = {  /* program 28 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,    9,    0,   63,   63,  127,   37,   51 },
};
const u16 snd_bank_01_prog_028_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_029[1] = {  /* program 29 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   10,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_029_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   11,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   12,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   13,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   14,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   15,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   16,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   17,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   18,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   19,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   20,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_046[1] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   21,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   22,    0,   63,   63,  127,   36,   51 },
};
const u16 snd_bank_01_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   23,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_049[1] = {  /* program 49 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   24,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_049_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_050[1] = {  /* program 50 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   25,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_050_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_051[1] = {  /* program 51 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   26,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_051_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_052[1] = {  /* program 52 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   27,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_052_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_053[1] = {  /* program 53 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   28,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_053_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_054[1] = {  /* program 54 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   29,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_054_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_055[1] = {  /* program 55 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   30,    0,   63,   63,  127,   30,   26 },
};
const u16 snd_bank_01_prog_055_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_056[1] = {  /* program 56 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   31,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_056_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_057[1] = {  /* program 57 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   32,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_057_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_058[1] = {  /* program 58 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   33,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_058_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_059[1] = {  /* program 59 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   34,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_059_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   35,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   36,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   37,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   38,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,   39,    0,   63,   63,  127,   21,   51 },
};
const u16 snd_bank_01_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   40,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   41,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   42,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   43,    0,   63,   63,  127,   16,   51 },
};
const u16 snd_bank_01_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,   44,    0,   63,   63,  127,   28,   51 },
};
const u16 snd_bank_01_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   45,    0,   63,   63,  127,   26,   51 },
};
const u16 snd_bank_01_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   46,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   47,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   48,    0,   63,   63,  127,   16,    1 },
};
const u16 snd_bank_01_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   49,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_079[1] = {  /* program 79 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   50,    0,   63,   63,  127,   30,   51 },
};
const u16 snd_bank_01_prog_079_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_083[1] = {  /* program 83 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,   51,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_083_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_084[1] = {  /* program 84 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   52,    0,   63,   63,  127,   30,   51 },
};
const u16 snd_bank_01_prog_084_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_085[1] = {  /* program 85 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   53,    0,   63,   63,  127,   32,   51 },
};
const u16 snd_bank_01_prog_085_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_086[1] = {  /* program 86 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  219,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_086_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_087[1] = {  /* program 87 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  220,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_087_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_089[1] = {  /* program 89 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  221,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_089_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  248,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  249,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -30,    0,  250,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -25,    0,  251,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   50,    0,  704,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  705,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  706,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  707,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  713,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  714,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  715,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  716,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  717,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  718,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  720,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  721,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_107[1] = {  /* program 107 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  722,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_107_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_108[1] = {  /* program 108 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  723,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_108_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_109[1] = {  /* program 109 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  724,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_109_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_110[1] = {  /* program 110 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  725,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_110_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_111[1] = {  /* program 111 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  726,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_111_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_112[1] = {  /* program 112 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  727,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_112_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_113[1] = {  /* program 113 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  728,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_113_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_114[1] = {  /* program 114 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  729,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_114_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_115[1] = {  /* program 115 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  730,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_115_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_116[1] = {  /* program 116 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  731,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_116_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_01_prog_117[1] = {  /* program 117 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  732,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_01_prog_117_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_02[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 0, 0, 0, 298, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 324, 338, 388, 402, 416, 430,
    0, 0, 0, 0, 0, 0, 444, 458, 472, 486, 500, 514,
    528, 542, 556, 570, 584, 598, 612, 626, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_02_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   83,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -25,    0,   84,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   85,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_006[2] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   66,  255,    0,    0,   72,    0,   63,   63,  127,    1,   63 },
    {   67,  255,   -5,    0,   73,    0,   63,   18,  126,   31,   51 },
};
const u16 snd_bank_02_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   74,    0,   38,   60,  127,   30,   56 },
};
const u16 snd_bank_02_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_019[4] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {   60,  255,  -15,    0,   75,    0,   63,   63,  127,    1,   63 },
    {   61,  255,    0,    0,   76,    0,   63,   63,  127,    1,   63 },
    {   62,  255,  -15,    0,   77,    0,   63,   63,  127,    1,   63 },
    {   63,  255,  -15,    0,   78,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   79,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_021[1] = {  /* program 21 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   80,    0,   63,   63,  127,    1,   56 },
};
const u16 snd_bank_02_prog_021_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_022[1] = {  /* program 22 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   81,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_022_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_023[1] = {  /* program 23 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,   82,    0,   48,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_023_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  624,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  625,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  626,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  627,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  628,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  629,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  630,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  631,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  632,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  633,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  634,    0,   63,   63,  127,   37,   26 },
};
const u16 snd_bank_02_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  635,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  636,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_02_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  719,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_02_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_03[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 508, 522, 536, 550, 0, 0,
    0, 0, 0, 0, 0, 0, 564, 578, 592, 606, 620, 634,
    648, 662, 676, 690, 704, 718, 732, 746, 760, 774, 788, 802,
    816, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    830, 844, 858, 872, 886, 900, 914, 928, 942, 956, 970, 984,
    998, 1012, 1026, 1040, 1054, 1068, 1082, 1096, 1110, 1124, 1138, 1152,
    1166, 0, 0, 0, 0, 0, 1180, 1194, 1208, 1222, 1236, 1250,
    1264, 1278, 1292, 1306, 1320, 1334, 1348, 1362, 1376, 1390, 1404, 1418,
    1432, 1446, 1460, 1474, 1488, 1502, 1516, 1530, 1544, 1558, 1572, 1586,
    1600, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_03_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  173,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  174,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  175,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  176,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  177,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  178,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  179,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  180,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  181,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  182,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  183,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  184,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  185,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  186,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  187,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  188,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  189,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  190,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  191,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  252,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  253,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_021[1] = {  /* program 21 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  254,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_021_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  192,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  193,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  194,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  195,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  196,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  197,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  198,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  199,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  200,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  201,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  203,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  202,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  204,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  205,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_044[1] = {  /* program 44 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  255,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_044_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  256,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_046[1] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  258,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  259,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  257,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  206,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_061[1] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  207,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  208,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  209,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_064[1] = {  /* program 64 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  210,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_064_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  211,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  212,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  213,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   25,    0,  214,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_069[1] = {  /* program 69 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  216,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_069_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  217,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  218,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  215,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  610,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  638,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  639,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  640,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  641,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  698,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_079[1] = {  /* program 79 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  699,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_079_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_080[1] = {  /* program 80 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  700,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_080_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_081[1] = {  /* program 81 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  701,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_081_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_082[1] = {  /* program 82 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  702,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_082_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_083[1] = {  /* program 83 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  703,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_083_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_084[1] = {  /* program 84 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  712,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_084_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_090[1] = {  /* program 90 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  260,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_090_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  261,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  262,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  263,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  264,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  265,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  266,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  267,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  268,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  269,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  270,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  271,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  272,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  273,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  274,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  275,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   63,    0,  276,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_107[1] = {  /* program 107 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  277,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_107_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_108[1] = {  /* program 108 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  278,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_108_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_109[1] = {  /* program 109 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  279,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_109_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_110[1] = {  /* program 110 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  280,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_110_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_111[1] = {  /* program 111 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  281,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_111_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_112[1] = {  /* program 112 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  605,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_112_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_113[1] = {  /* program 113 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  606,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_113_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_114[1] = {  /* program 114 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  607,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_114_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_115[1] = {  /* program 115 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  608,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_115_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_116[1] = {  /* program 116 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  609,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_116_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_117[1] = {  /* program 117 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  694,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_117_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_118[1] = {  /* program 118 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  695,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_118_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_119[1] = {  /* program 119 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  696,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_119_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_03_prog_120[1] = {  /* program 120 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  697,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_03_prog_120_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_04[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 508, 522, 536, 550, 564, 578,
    592, 0, 0, 0, 0, 0, 606, 620, 634, 648, 662, 676,
    690, 704, 718, 732, 746, 0, 760, 774, 788, 802, 816, 830,
    844, 858, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    872, 886, 900, 914, 928, 942, 956, 970, 984, 998, 1012, 1026,
    1040, 1054, 1068, 1082, 1096, 1110, 1124, 1138, 1152, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1166, 1180, 1194, 1208, 1222, 1236,
    1250, 1264, 1278, 1292, 1306, 1320, 1334, 1348, 1362, 1376, 1390, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_04_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  282,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  283,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  284,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  285,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  286,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  287,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  288,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  289,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  290,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  291,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  292,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  293,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  294,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  295,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  296,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  297,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  298,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  299,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  300,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  301,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  302,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_021[1] = {  /* program 21 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  303,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_021_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_022[1] = {  /* program 22 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  304,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_022_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_023[1] = {  /* program 23 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  305,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_023_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_024[1] = {  /* program 24 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  306,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_024_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  307,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  308,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  309,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  310,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  311,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  312,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  313,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  314,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  315,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  316,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  317,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  318,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  319,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_044[1] = {  /* program 44 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  320,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_044_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  321,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_046[1] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  322,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  323,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  324,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_049[1] = {  /* program 49 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  325,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_049_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  326,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_061[1] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  327,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  328,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  329,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_064[1] = {  /* program 64 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  330,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_064_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  331,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  332,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  333,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  334,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_069[1] = {  /* program 69 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  335,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_069_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  336,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  337,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  338,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  339,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  340,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  341,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  342,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  708,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  709,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_079[1] = {  /* program 79 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  710,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_079_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_080[1] = {  /* program 80 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  711,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_080_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_090[1] = {  /* program 90 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  343,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_090_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  344,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  345,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -25,    0,  346,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  347,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  348,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  349,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  350,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  351,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  352,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  353,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  354,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   50,    0,  355,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  356,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  357,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  358,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_04_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  359,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_04_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_05[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 508, 522, 536, 550, 564, 578,
    592, 606, 620, 634, 648, 662, 676, 690, 704, 718, 732, 746,
    760, 774, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    788, 802, 816, 830, 844, 858, 872, 886, 900, 914, 928, 942,
    956, 970, 984, 998, 1012, 1026, 1040, 1054, 1068, 1082, 1096, 1110,
    1124, 1138, 1152, 0, 0, 0, 1166, 1180, 1194, 1208, 1222, 1236,
    1250, 1264, 1278, 1292, 1306, 1320, 1334, 1348, 1362, 1376, 1390, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_05_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  360,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  361,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  362,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  363,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  364,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  365,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  366,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  367,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  368,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  369,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  370,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  371,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  372,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  373,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  374,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  375,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  376,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   60,    0,  377,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  378,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  379,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  380,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  381,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  382,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  383,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  384,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  385,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  386,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  387,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  388,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   38,    0,  389,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  390,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  391,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_044[1] = {  /* program 44 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  392,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_044_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -5,    0,  393,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_046[1] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  394,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  395,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  396,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_049[1] = {  /* program 49 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  397,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_049_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  398,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_061[1] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  399,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  400,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  401,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_064[1] = {  /* program 64 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  402,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_064_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  403,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  404,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  405,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  406,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_069[1] = {  /* program 69 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  407,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_069_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  408,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  409,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  410,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  411,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  412,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  413,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  414,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   25,    0,  415,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  416,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_079[1] = {  /* program 79 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -25,    0,  417,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_079_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_080[1] = {  /* program 80 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  418,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_080_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_081[1] = {  /* program 81 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  419,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_081_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_082[1] = {  /* program 82 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  611,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_082_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_083[1] = {  /* program 83 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  612,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_083_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_084[1] = {  /* program 84 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  613,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_084_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_085[1] = {  /* program 85 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  614,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_085_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_086[1] = {  /* program 86 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  615,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_086_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_090[1] = {  /* program 90 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  420,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_090_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  421,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  422,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  423,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  424,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  425,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  426,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  427,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  428,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  429,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  430,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  431,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  432,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  433,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  434,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  435,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_05_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  637,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_05_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_06[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 508, 522, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 536, 550, 564, 578, 592, 606,
    620, 634, 648, 662, 676, 690, 704, 718, 0, 732, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    746, 760, 774, 788, 802, 816, 830, 844, 858, 872, 886, 900,
    914, 928, 942, 956, 970, 984, 998, 1012, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1026, 1040, 1054, 1068, 1082, 1096,
    1110, 1124, 1138, 1152, 1166, 1180, 1194, 1208, 1222, 1236, 1250, 1264,
    1278, 1292, 1306, 1320, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_06_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  436,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  437,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  438,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  439,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  440,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  441,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  442,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  443,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  444,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  445,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  446,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   25,    0,  447,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  448,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  449,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  450,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  451,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   30,    0,  452,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  453,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   40,    0,  454,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  455,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  456,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  457,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  458,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  459,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  460,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  461,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  462,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  463,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  464,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  465,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  466,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  467,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  468,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -40,    0,  469,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -40,    0,  470,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  471,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_061[1] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  472,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  473,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  474,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_064[1] = {  /* program 64 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  475,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_064_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  476,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  477,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  478,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  479,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_069[1] = {  /* program 69 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  480,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_069_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  481,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  482,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  483,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  484,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  485,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  486,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  487,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  488,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  489,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_079[1] = {  /* program 79 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  490,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_079_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_090[1] = {  /* program 90 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  491,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_090_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  492,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  493,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  494,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  495,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  496,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  497,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  498,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  499,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  500,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  501,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  502,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  503,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  504,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  505,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  506,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  507,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_107[1] = {  /* program 107 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  508,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_107_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_108[1] = {  /* program 108 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  509,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_108_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_109[1] = {  /* program 109 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  510,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_109_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_110[1] = {  /* program 110 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  511,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_110_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_06_prog_111[1] = {  /* program 111 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  512,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_06_prog_111_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_07[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 452, 466, 480, 494, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 508, 522, 536, 550, 564, 578,
    592, 606, 620, 634, 648, 662, 676, 690, 704, 718, 732, 746,
    760, 774, 788, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    802, 816, 830, 844, 858, 872, 886, 900, 914, 928, 942, 956,
    970, 984, 998, 1012, 1026, 1040, 1054, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1068, 1082, 1096, 1110, 1124, 1138,
    1152, 1166, 1180, 1194, 1208, 1222, 1236, 1250, 1264, 1278, 1292, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_07_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  513,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  514,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  515,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  516,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  517,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  518,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  519,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  520,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  521,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  522,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  523,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  524,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  525,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  526,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_014[1] = {  /* program 14 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  527,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_014_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  528,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_016[1] = {  /* program 16 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  529,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_016_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  530,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  531,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -5,    0,  532,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  533,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -5,    0,  534,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  535,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  536,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  537,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_037[1] = {  /* program 37 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  538,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_037_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_038[1] = {  /* program 38 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  539,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_038_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_039[1] = {  /* program 39 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  540,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_039_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_040[1] = {  /* program 40 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  541,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_040_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_041[1] = {  /* program 41 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  542,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_041_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_042[1] = {  /* program 42 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  543,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_042_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_043[1] = {  /* program 43 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  544,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_043_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_044[1] = {  /* program 44 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  545,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_044_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_045[1] = {  /* program 45 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  546,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_045_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_046[1] = {  /* program 46 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  547,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_046_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_047[1] = {  /* program 47 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  548,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_047_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_048[1] = {  /* program 48 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  549,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_048_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_049[1] = {  /* program 49 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  550,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_049_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_050[1] = {  /* program 50 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   50,    0,  551,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_050_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_060[1] = {  /* program 60 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -5,    0,  552,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_060_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_061[1] = {  /* program 61 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  553,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_061_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_062[1] = {  /* program 62 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  554,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_062_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_063[1] = {  /* program 63 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  555,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_063_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_064[1] = {  /* program 64 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  556,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_064_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_065[1] = {  /* program 65 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  557,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_065_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_066[1] = {  /* program 66 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  558,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_066_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_067[1] = {  /* program 67 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  559,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_067_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_068[1] = {  /* program 68 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  560,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_068_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_069[1] = {  /* program 69 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  561,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_069_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_070[1] = {  /* program 70 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   50,    0,  562,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_070_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_071[1] = {  /* program 71 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   50,    0,  563,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_071_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_072[1] = {  /* program 72 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  564,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_072_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_073[1] = {  /* program 73 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  565,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_073_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_074[1] = {  /* program 74 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  566,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_074_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_075[1] = {  /* program 75 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   55,    0,  567,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_075_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_076[1] = {  /* program 76 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   20,    0,  568,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_076_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_077[1] = {  /* program 77 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  569,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_077_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_078[1] = {  /* program 78 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  570,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_078_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_090[1] = {  /* program 90 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  571,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_090_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_091[1] = {  /* program 91 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  572,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_091_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_092[1] = {  /* program 92 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  573,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_092_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_093[1] = {  /* program 93 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -15,    0,  574,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_093_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_094[1] = {  /* program 94 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  575,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_094_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_095[1] = {  /* program 95 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  576,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_095_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_096[1] = {  /* program 96 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  577,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_096_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_097[1] = {  /* program 97 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  578,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_097_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_098[1] = {  /* program 98 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  579,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_098_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_099[1] = {  /* program 99 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  580,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_099_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_100[1] = {  /* program 100 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    5,    0,  581,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_100_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_101[1] = {  /* program 101 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  582,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_101_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_102[1] = {  /* program 102 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  583,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_102_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_103[1] = {  /* program 103 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  584,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_103_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_104[1] = {  /* program 104 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  585,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_104_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_105[1] = {  /* program 105 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  586,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_105_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_07_prog_106[1] = {  /* program 106 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  587,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_07_prog_106_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

const u16 snd_bank_08[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_09[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_10[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_11[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_12[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_13[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_14[128] = {  /* program -> offset of its key splits */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

const u16 snd_bank_15[128] = {  /* program -> offset of its key splits */
    256, 270, 284, 298, 312, 326, 340, 354, 368, 382, 396, 410,
    424, 438, 0, 452, 0, 466, 480, 494, 508, 0, 522, 536,
    550, 564, 578, 592, 606, 620, 634, 648, 662, 676, 690, 704,
    718, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
const SNDPATCH snd_bank_15_prog_000[1] = {  /* program 0 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  222,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_000_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_001[1] = {  /* program 1 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  223,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_001_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_002[1] = {  /* program 2 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  224,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_002_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_003[1] = {  /* program 3 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  225,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_003_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_004[1] = {  /* program 4 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   -5,    0,  226,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_004_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_005[1] = {  /* program 5 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  227,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_005_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_006[1] = {  /* program 6 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  228,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_006_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_007[1] = {  /* program 7 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  229,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_007_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_008[1] = {  /* program 8 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  230,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_008_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_009[1] = {  /* program 9 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  231,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_009_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_010[1] = {  /* program 10 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  232,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_010_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_011[1] = {  /* program 11 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  233,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_011_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_012[1] = {  /* program 12 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  234,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_012_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_013[1] = {  /* program 13 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  235,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_013_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_015[1] = {  /* program 15 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  236,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_015_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_017[1] = {  /* program 17 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  237,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_017_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_018[1] = {  /* program 18 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  238,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_018_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_019[1] = {  /* program 19 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  239,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_019_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_020[1] = {  /* program 20 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,    0,    0,  240,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_020_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_022[1] = {  /* program 22 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  241,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_022_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_023[1] = {  /* program 23 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  242,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_023_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_024[1] = {  /* program 24 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  243,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_024_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_025[1] = {  /* program 25 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  244,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_025_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_026[1] = {  /* program 26 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  245,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_026_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_027[1] = {  /* program 27 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  246,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_027_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_028[1] = {  /* program 28 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -20,    0,  247,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_028_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_029[1] = {  /* program 29 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   15,    0,  616,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_029_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_030[1] = {  /* program 30 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  617,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_030_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_031[1] = {  /* program 31 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  618,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_031_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_032[1] = {  /* program 32 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,  -10,    0,  619,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_032_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_033[1] = {  /* program 33 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   45,    0,  620,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_033_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_034[1] = {  /* program 34 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   25,    0,  621,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_034_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_035[1] = {  /* program 35 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   10,    0,  622,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_035_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */
const SNDPATCH snd_bank_15_prog_036[1] = {  /* program 36 */
    /* ceil  pan  vol  res  sample  pitch  att  dec  vel  rel  frel */
    {  127,  255,   35,    0,  623,    0,   63,   63,  127,    1,   63 },
};
const u16 snd_bank_15_prog_036_end = 0xFFFF;  /* note_ceiling -1: the end of the key splits */

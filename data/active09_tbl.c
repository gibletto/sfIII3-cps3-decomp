/*
 * ACTIVE09_TBL.C  game tables
 */

#include "types.h"
#include "structs.h"

#pragma section TBL

extern void Pattern09_0000();
extern void Pattern09_0001();
extern void Pattern09_0002();
extern void Pattern09_0003();
extern void Pattern09_0004();
extern void Pattern09_0005();
extern void Pattern09_0006();
extern void Pattern09_0007();
extern void Pattern09_0008();
extern void Pattern09_0009();
extern void Pattern09_0010();
extern void Pattern09_0011();
extern void Pattern09_0012();
extern void Pattern09_0013();
extern void Pattern09_0014();
extern void Pattern09_0015();
extern void Pattern09_0016();
extern void Pattern09_0017();
extern void Pattern09_0018();
extern void Pattern09_0019();
extern void Pattern09_0020();
extern void Pattern09_0021();
extern void Pattern09_0022();
extern void Pattern09_0023();
extern void Pattern09_0024();
extern void Pattern09_0025();
extern void Pattern09_0026();
extern void Pattern09_0027();
extern void Pattern09_0028();
extern void Pattern09_0029();
extern void Pattern09_0030();
extern void Pattern09_0031();
extern void Pattern09_0032();
extern void Pattern09_0033();
extern void Pattern09_0034();
extern void Pattern09_0035();
extern void Pattern09_0036();
extern void Pattern09_0037();
extern void Pattern09_0038();
extern void Pattern09_0039();
extern void Pattern09_0040();
extern void Pattern09_0041();
extern void Pattern09_0042();
extern void Pattern09_0043();
extern void Pattern09_0044();
extern void Pattern09_0045();
extern void Pattern09_0046();
extern void Pattern09_0047();
extern void Pattern09_0048();
extern void Pattern09_0049();
extern void Pattern09_0050();
extern void Pattern09_0051();
extern void Pattern09_0052();
extern void Pattern09_0053();
extern void Pattern09_0054();
extern void Pattern09_0055();
extern void Pattern09_0056();
extern void Pattern09_0057();
extern void Pattern09_0058();
extern void Pattern09_0059();
extern void Pattern09_0060();
extern void Pattern09_0061();
extern void Pattern09_0062();
extern void Pattern09_0063();
extern void Pattern09_0064();
extern void Pattern09_0065();
extern void Pattern09_0066();
extern void Pattern09_0067();
extern void Pattern09_0068();
extern void Pattern09_0069();
extern void Pattern09_0070();
extern void Pattern09_0071();
extern void Pattern09_0072();
extern void Pattern09_0073();
extern void Pattern09_0074();
extern void Pattern09_0075();
extern void Pattern09_0076();
extern void Pattern09_0077();
extern void Pattern09_0078();
extern void Pattern09_0079();
extern void Pattern09_0080();
extern void Pattern09_0081();
extern void Pattern09_0082();
extern void Pattern09_0083();
extern void Pattern09_0084();
extern void Pattern09_0085();
extern void Pattern09_0086();
extern void Pattern09_0087();
extern void Pattern09_0088();
extern void Pattern09_0089();
extern void Pattern09_0090();
extern void Pattern09_0091();
extern void Pattern09_0092();
extern void Pattern09_0093();
extern void Pattern09_0094();
extern void Pattern09_0095();
extern void Pattern09_0096();
extern void Pattern09_0097();
extern void Pattern09_0098();
extern void Pattern09_0099();
extern void Pattern09_0100();
extern void Pattern10_0000();
extern void Pattern10_0001();
extern void Pattern10_0002();
extern void Pattern10_0003();
extern void Pattern10_0004();
extern void Pattern10_0005();
extern void Pattern10_0006();
extern void Pattern10_0007();
extern void Pattern10_0008();
extern void Pattern10_0009();
extern void Pattern10_0010();
extern void Pattern10_0011();
extern void Pattern10_0012();
extern void Pattern10_0013();
extern void Pattern10_0014();
extern void Pattern10_0015();
extern void Pattern10_0016();
extern void Pattern10_0017();
extern void Pattern10_0018();
extern void Pattern10_0019();
extern void Pattern10_0020();
extern void Pattern10_0021();
extern void Pattern10_0022();
extern void Pattern10_0023();
extern void Pattern10_0024();
extern void Pattern10_0025();
extern void Pattern10_0026();
extern void Pattern10_0027();
extern void Pattern10_0028();
extern void Pattern10_0029();
extern void Pattern10_0030();
extern void Pattern10_0031();
extern void Pattern10_0032();
extern void Pattern10_0033();
extern void Pattern10_0034();
extern void Pattern10_0035();
extern void Pattern10_0036();
extern void Pattern10_0037();
extern void Pattern10_0038();
extern void Pattern10_0039();
extern void Pattern10_0040();
extern void Pattern10_0041();
extern void Pattern10_0042();
extern void Pattern10_0043();
extern void Pattern10_0044();
extern void Pattern10_0045();
extern void Pattern10_0046();
extern void Pattern10_0047();
extern void Pattern10_0048();
extern void Pattern10_0049();
extern void Pattern10_0050();
extern void Pattern10_0051();
extern void Pattern10_0052();
extern void Pattern10_0053();
extern void Pattern10_0054();
extern void Pattern10_0055();
extern void Pattern10_0056();
extern void Pattern10_0057();
extern void Pattern10_0058();
extern void Pattern10_0059();
extern void Pattern10_0060();
extern void Pattern10_0061();
extern void Pattern10_0062();
extern void Pattern10_0063();
extern void Pattern10_0064();
extern void Pattern10_0065();
extern void Pattern10_0066();
extern void Pattern10_0067();
extern void Pattern10_0068();
extern void Pattern10_0069();
extern void Pattern11_0000();
extern void Pattern11_0001();
extern void Pattern11_0002();
extern void Pattern11_0003();
extern void Pattern11_0004();
extern void Pattern11_0005();
extern void Pattern11_0006();
extern void Pattern11_0007();
extern void Pattern11_0008();
extern void Pattern11_0009();
extern void Pattern11_0010();
extern void Pattern11_0011();
extern void Pattern11_0012();
extern void Pattern11_0013();
extern void Pattern11_0014();
extern void Pattern11_0015();
extern void Pattern11_0016();
extern void Pattern11_0017();
extern void Pattern11_0018();
extern void Pattern11_0019();
extern void Pattern11_0020();
extern void Pattern11_0021();
extern void Pattern11_0022();
extern void Pattern11_0023();
extern void Pattern11_0024();
extern void Pattern11_0025();
extern void Pattern11_0026();
extern void Pattern11_0027();
extern void Pattern11_0028();
extern void Pattern11_0029();
extern void Pattern11_0030();
extern void Pattern11_0031();
extern void Pattern11_0032();
extern void Pattern11_0033();
extern void Pattern11_0034();
extern void Pattern11_0035();
extern void Pattern11_0036();
extern void Pattern11_0037();
extern void Pattern11_0038();
extern void Pattern11_0039();
extern void Pattern11_0040();
extern void Pattern11_0041();
extern void Pattern11_0042();
extern void Pattern11_0043();
extern void Pattern11_0044();
extern void Pattern11_0045();
extern void Pattern11_0046();
extern void Pattern11_0047();
extern void Pattern11_0048();
extern void Pattern11_0049();
extern void Pattern11_0050();
extern void Pattern11_0051();
extern void Pattern11_0052();
extern void Pattern11_0053();
extern void Pattern11_0054();
extern void Pattern11_0055();
extern void Pattern11_0056();
extern void Pattern11_0057();
extern void Pattern11_0058();
extern void Pattern11_0059();
extern void Pattern11_0060();
extern void Pattern11_0061();
extern void Pattern11_0062();
extern void Pattern11_0063();
extern void Pattern11_0064();
extern void Pattern11_0065();
extern void Pattern11_0066();
extern void Pattern11_0067();
extern void Pattern11_0068();
extern void Pattern11_0069();
extern void Pattern11_0070();
extern void Pattern11_0071();
extern void Pattern11_0072();
extern void Pattern11_0073();
extern void Pattern11_0074();
extern void Pattern11_0075();
extern void Pattern11_0076();
extern void Pattern11_0077();
extern void Pattern11_0078();
extern void Pattern11_0079();
extern void Pattern11_0080();
extern void Pattern11_0081();
extern void Pattern11_0082();
extern void Pattern11_0083();
extern void Pattern11_0084();
extern void Pattern11_0085();
extern void Pattern11_0086();
extern void Pattern11_0087();
extern void Pattern11_0088();
extern void Pattern11_0089();
extern void Pattern12_0000();
extern void Pattern12_0001();
extern void Pattern12_0002();
extern void Pattern12_0003();
extern void Pattern12_0004();
extern void Pattern12_0005();
extern void Pattern12_0006();
extern void Pattern12_0007();
extern void Pattern12_0008();
extern void Pattern12_0009();
extern void Pattern12_0010();
extern void Pattern12_0011();
extern void Pattern12_0012();
extern void Pattern12_0013();
extern void Pattern12_0014();
extern void Pattern12_0015();
extern void Pattern12_0016();
extern void Pattern12_0017();
extern void Pattern12_0018();
extern void Pattern12_0019();
extern void Pattern12_0020();
extern void Pattern12_0021();
extern void Pattern12_0022();
extern void Pattern12_0023();
extern void Pattern12_0024();
extern void Pattern12_0025();
extern void Pattern12_0026();
extern void Pattern12_0027();
extern void Pattern12_0028();
extern void Pattern12_0029();
extern void Pattern12_0030();
extern void Pattern12_0031();
extern void Pattern12_0032();
extern void Pattern12_0033();
extern void Pattern12_0034();
extern void Pattern12_0035();
extern void Pattern12_0036();
extern void Pattern12_0037();
extern void Pattern12_0038();
extern void Pattern12_0039();
extern void Pattern12_0040();
extern void Pattern12_0041();
extern void Pattern12_0042();
extern void Pattern12_0043();
extern void Pattern12_0044();
extern void Pattern12_0045();
extern void Pattern12_0046();
extern void Pattern12_0047();
extern void Pattern12_0048();
extern void Pattern12_0049();
extern void Pattern12_0050();
extern void Pattern12_0051();
extern void Pattern12_0052();
extern void Pattern12_0053();
extern void Pattern12_0054();
extern void Pattern12_0055();
extern void Pattern12_0056();
extern void Pattern12_0057();
extern void Pattern12_0058();
extern void Pattern12_0059();
extern void Pattern12_0060();
extern void Pattern12_0061();
extern void Pattern12_0062();
extern void Pattern12_0063();
extern void Pattern12_0064();
extern void Pattern12_0065();
extern void Pattern12_0066();
extern void Pattern12_0067();
extern void Pattern12_0068();
extern void Pattern12_0069();
extern void Pattern12_0070();
extern void Pattern12_0071();
extern void Pattern12_0072();
extern void Pattern12_0073();
extern void Pattern12_0074();
extern void Pattern12_0075();
extern void Pattern12_0076();
extern void Pattern12_0077();
extern void Pattern12_0078();
extern void Pattern12_0079();
extern void Pattern12_0080();
extern void Pattern12_0081();
extern void Pattern12_0082();
extern void Pattern12_0083();
extern void Pattern12_0084();
extern void Pattern12_0085();
extern void Pattern13_0000();
extern void Pattern13_0001();
extern void Pattern13_0002();
extern void Pattern13_0003();
extern void Pattern13_0004();
extern void Pattern13_0005();
extern void Pattern13_0006();
extern void Pattern13_0007();
extern void Pattern13_0008();
extern void Pattern13_0009();
extern void Pattern13_0010();
extern void Pattern13_0011();
extern void Pattern13_0012();
extern void Pattern13_0013();
extern void Pattern13_0014();
extern void Pattern13_0015();
extern void Pattern13_0016();
extern void Pattern13_0017();
extern void Pattern13_0018();
extern void Pattern13_0019();
extern void Pattern13_0020();
extern void Pattern13_0021();
extern void Pattern13_0022();
extern void Pattern13_0023();
extern void Pattern13_0024();
extern void Pattern13_0025();
extern void Pattern13_0026();
extern void Pattern13_0027();
extern void Pattern13_0028();
extern void Pattern13_0029();
extern void Pattern13_0030();
extern void Pattern13_0031();
extern void Pattern13_0032();
extern void Pattern13_0033();
extern void Pattern13_0034();
extern void Pattern13_0035();
extern void Pattern13_0036();
extern void Pattern13_0037();
extern void Pattern13_0038();
extern void Pattern13_0039();
extern void Pattern13_0040();
extern void Pattern13_0041();
extern void Pattern13_0042();
extern void Pattern13_0043();
extern void Pattern13_0044();
extern void Pattern13_0045();
extern void Pattern13_0046();
extern void Pattern13_0047();
extern void Pattern13_0048();
extern void Pattern13_0049();
extern void Pattern13_0050();
extern void Pattern13_0051();
extern void Pattern13_0052();
extern void Pattern13_0053();
extern void Pattern13_0054();
extern void Pattern13_0055();
extern void Pattern13_0056();
extern void Pattern13_0057();
extern void Pattern13_0058();
extern void Pattern13_0059();
extern void Pattern13_0060();
extern void Pattern13_0061();
extern void Pattern13_0062();
extern void Pattern13_0063();
extern void Pattern13_0064();
extern void Pattern13_0065();
extern void Pattern13_0066();
extern void Pattern13_0067();
extern void Pattern13_0068();
extern void Pattern13_0069();
extern void Pattern13_0070();
extern void Pattern13_0071();
extern void Pattern13_0072();
extern void Pattern13_0073();
extern void Pattern13_0074();
extern void Pattern13_0075();
extern void Pattern13_0076();
extern void Pattern13_0077();
extern void Pattern13_0078();
extern void Pattern13_0079();
extern void Pattern13_0080();
extern void Pattern14_0000();
extern void Pattern14_0001();
extern void Pattern14_0002();
extern void Pattern14_0003();
extern void Pattern14_0004();
extern void Pattern14_0005();
extern void Pattern14_0006();
extern void Pattern14_0007();
extern void Pattern14_0008();
extern void Pattern14_0009();
extern void Pattern14_0010();
extern void Pattern14_0011();
extern void Pattern14_0012();
extern void Pattern14_0013();
extern void Pattern14_0014();
extern void Pattern14_0015();
extern void Pattern14_0016();
extern void Pattern14_0017();
extern void Pattern14_0018();
extern void Pattern14_0019();
extern void Pattern14_0020();
extern void Pattern14_0021();
extern void Pattern14_0022();
extern void Pattern14_0023();
extern void Pattern14_0024();
extern void Pattern14_0025();
extern void Pattern14_0026();
extern void Pattern14_0027();
extern void Pattern14_0028();
extern void Pattern14_0029();
extern void Pattern14_0030();
extern void Pattern14_0031();
extern void Pattern14_0032();
extern void Pattern14_0033();
extern void Pattern14_0034();
extern void Pattern14_0035();
extern void Pattern14_0036();
extern void Pattern14_0037();
extern void Pattern14_0038();
extern void Pattern14_0039();
extern void Pattern14_0040();
extern void Pattern14_0041();
extern void Pattern14_0042();
extern void Pattern14_0043();
extern void Pattern14_0044();
extern void Pattern14_0045();
extern void Pattern14_0046();
extern void Pattern14_0047();
extern void Pattern14_0048();
extern void Pattern14_0049();
extern void Pattern14_0050();
extern void Pattern14_0051();
extern void Pattern14_0052();
extern void Pattern14_0053();
extern void Pattern14_0054();
extern void Pattern14_0055();
extern void Pattern14_0056();
extern void Pattern14_0057();
extern void Pattern14_0058();
extern void Pattern14_0059();
extern void Pattern14_0060();
extern void Pattern14_0061();
extern void Pattern14_0062();
extern void Pattern14_0063();
extern void Pattern14_0064();
extern void Pattern14_0065();
extern void Pattern14_0066();
extern void Pattern14_0067();
extern void Pattern14_0068();
extern void Pattern14_0069();
extern void Pattern14_0070();
extern void Pattern14_0071();
extern void Pattern14_0072();
extern void Pattern14_0073();
extern void Pattern14_0074();
extern void Pattern14_0075();
extern void Pattern14_0076();
extern void Pattern14_0077();
extern void Pattern14_0078();
extern void Pattern14_0079();
extern void Pattern14_0080();
extern void Pattern14_0081();
extern void Pattern14_0082();
extern void Pattern14_0083();
extern void Pattern14_0084();
extern void Pattern14_0085();
extern void Pattern14_0086();
extern void Pattern14_0087();
extern void Pattern14_0088();
extern void Pattern14_0089();
extern void Pattern14_0090();
extern void Pattern14_0091();
extern void Pattern14_0092();
extern void Pattern14_0093();
extern void Pattern14_0094();
extern void Pattern14_0095();
extern void Pattern14_0096();
extern void Pattern14_0097();
extern void Pattern14_0098();
extern void Pattern14_0099();
extern void Pattern14_0100();
extern void Pattern14_0101();
extern void Pattern14_0102();
extern void Pattern14_0103();
extern void Pattern14_0104();
extern void Pattern14_0105();
extern void Pattern14_0106();
extern void Pattern14_0107();
extern void Pattern14_0108();
extern void Pattern14_0109();
extern void Pattern14_0110();
extern void Pattern14_0111();
extern void Pattern14_0112();
extern void Pattern14_0113();
extern void Pattern14_0114();
extern void Pattern14_0115();
extern void Pattern14_0116();
extern void Pattern14_0117();
extern void Pattern14_0118();
extern void Pattern14_0119();
extern void Pattern14_0120();
extern void Pattern14_0121();
extern void Pattern14_0122();
extern void Pattern14_0123();
extern void Pattern14_0124();
extern void Pattern14_0125();
extern void Pattern14_0126();
extern void Pattern14_0127();
extern void Pattern14_0128();
extern void Pattern14_0129();
extern void Pattern14_0130();
extern void Pattern14_0131();
extern void Pattern14_0132();
extern void Pattern14_0133();
extern void Pattern14_0134();
extern void Pattern14_0135();
extern void Pattern14_0136();
extern void Pattern14_0137();
extern void Pattern14_0138();
extern void Pattern14_0139();
extern void Pattern14_0140();
extern void Pattern14_0141();
extern void Pattern14_0142();
extern void Pattern14_0143();
extern void Pattern14_0144();
extern void Pattern14_0145();
extern void Pattern14_0146();
extern void Pattern14_0147();
extern void Pattern14_0148();
extern void Pattern14_0149();
extern void Pattern14_0150();
extern void Pattern15_0000();
extern void Pattern15_0001();
extern void Pattern15_0002();
extern void Pattern15_0003();
extern void Pattern15_0004();
extern void Pattern15_0005();
extern void Pattern15_0006();
extern void Pattern15_0007();
extern void Pattern15_0008();
extern void Pattern15_0009();
extern void Pattern15_0010();
extern void Pattern15_0011();
extern void Pattern15_0012();
extern void Pattern15_0013();
extern void Pattern15_0014();
extern void Pattern15_0015();
extern void Pattern15_0016();
extern void Pattern15_0017();
extern void Pattern15_0018();
extern void Pattern15_0019();
extern void Pattern15_0020();
extern void Pattern15_0021();
extern void Pattern15_0022();
extern void Pattern15_0023();
extern void Pattern15_0024();
extern void Pattern15_0025();
extern void Pattern15_0026();
extern void Pattern15_0027();
extern void Pattern15_0028();
extern void Pattern15_0029();
extern void Pattern15_0030();
extern void Pattern15_0031();
extern void Pattern15_0032();
extern void Pattern15_0033();
extern void Pattern15_0034();
extern void Pattern15_0035();
extern void Pattern15_0036();
extern void Pattern15_0037();
extern void Pattern15_0038();
extern void Pattern15_0039();
extern void Pattern15_0040();
extern void Pattern15_0041();
extern void Pattern15_0042();
extern void Pattern15_0043();
extern void Pattern15_0044();
extern void Pattern15_0045();
extern void Pattern15_0046();
extern void Pattern15_0047();
extern void Pattern15_0048();
extern void Pattern15_0049();
extern void Pattern15_0050();
extern void Pattern15_0051();
extern void Pattern15_0052();
extern void Pattern15_0053();
extern void Pattern15_0054();
extern void Pattern15_0055();
extern void Pattern15_0056();
extern void Pattern15_0057();
extern void Pattern15_0058();
extern void Pattern15_0059();
extern void Pattern15_0060();
extern void Pattern15_0061();
extern void Pattern15_0062();
extern void Pattern15_0063();
extern void Pattern15_0064();
extern void Pattern15_0065();
extern void Pattern15_0066();
extern void Pattern15_0067();
extern void Pattern15_0068();
extern void Pattern15_0069();
extern void Pattern15_0070();
extern void Pattern15_0071();
extern void Pattern15_0072();
extern void Pattern15_0073();
extern void Pattern15_0074();
extern void Pattern15_0075();
extern void Pattern15_0076();
extern void Pattern15_0077();
extern void Pattern15_0078();
extern void Pattern15_0079();
extern void Pattern15_0080();
extern void Pattern15_0081();
extern void Pattern15_0082();
extern void Pattern15_0083();
extern void Pattern15_0084();
extern void Pattern15_0085();
extern void Pattern15_0086();
extern void Pattern15_0087();
extern void Pattern15_0088();
extern void Pattern15_0089();
extern void Pattern15_0090();
extern void Pattern15_0091();
extern void Pattern15_0092();
extern void Pattern15_0093();
extern void Pattern15_0094();
extern void Pattern15_0095();
extern void Pattern15_0096();
extern void Pattern15_0097();
extern void Pattern15_0098();
extern void Pattern15_0099();
extern void Pattern15_0100();
extern void Pattern15_0101();
extern void Pattern15_0102();
extern void Pattern15_0103();
extern void Pattern15_0104();
extern void Pattern15_0105();
extern void Pattern15_0106();
extern void Pattern15_0107();
extern void Pattern15_0108();
extern void Pattern15_0109();
extern void Pattern15_0110();
extern void Pattern15_0111();
extern void Pattern15_0112();
extern void Pattern15_0113();
extern void Pattern15_0114();
extern void Pattern15_0115();
extern void Pattern15_0116();
extern void Pattern15_0117();
extern void Pattern15_0118();
extern void Pattern15_0119();
extern void Pattern15_0120();
extern void Pattern15_0121();
extern void Pattern15_0122();
extern void Pattern15_0123();
extern void Pattern15_0124();
extern void Pattern15_0125();
extern void Pattern15_0126();
extern void Pattern15_0127();
extern void Pattern15_0128();
extern void Pattern15_0129();
extern void Pattern15_0130();
extern void Pattern15_0131();
extern void Pattern15_0132();
extern void Pattern15_0133();
extern void Pattern15_0134();
extern void Pattern15_0135();
extern void Pattern15_0136();
extern void Pattern15_0137();
extern void Pattern15_0138();
extern void Pattern15_0139();
extern void Pattern15_0140();
extern void Pattern15_0141();
extern void Pattern15_0142();
extern void Pattern15_0143();
extern void Pattern15_0144();
extern void Pattern15_0145();
extern void Pattern15_0146();
extern void Pattern15_0147();
extern void Pattern15_0148();

void (*const Pattern09_Tbl[101])() = {
    Pattern09_0000,  Pattern09_0001,  Pattern09_0002,  Pattern09_0003,  /* 0 */
    Pattern09_0004,  Pattern09_0005,  Pattern09_0006,  Pattern09_0007,  /* 4 */
    Pattern09_0008,  Pattern09_0009,  Pattern09_0010,  Pattern09_0011,  /* 8 */
    Pattern09_0012,  Pattern09_0013,  Pattern09_0014,  Pattern09_0015,  /* 12 */
    Pattern09_0016,  Pattern09_0017,  Pattern09_0018,  Pattern09_0019,  /* 16 */
    Pattern09_0020,  Pattern09_0021,  Pattern09_0022,  Pattern09_0023,  /* 20 */
    Pattern09_0024,  Pattern09_0025,  Pattern09_0026,  Pattern09_0027,  /* 24 */
    Pattern09_0028,  Pattern09_0029,  Pattern09_0030,  Pattern09_0031,  /* 28 */
    Pattern09_0032,  Pattern09_0033,  Pattern09_0034,  Pattern09_0035,  /* 32 */
    Pattern09_0036,  Pattern09_0037,  Pattern09_0038,  Pattern09_0039,  /* 36 */
    Pattern09_0040,  Pattern09_0041,  Pattern09_0042,  Pattern09_0043,  /* 40 */
    Pattern09_0044,  Pattern09_0045,  Pattern09_0046,  Pattern09_0047,  /* 44 */
    Pattern09_0048,  Pattern09_0049,  Pattern09_0050,  Pattern09_0051,  /* 48 */
    Pattern09_0052,  Pattern09_0053,  Pattern09_0054,  Pattern09_0055,  /* 52 */
    Pattern09_0056,  Pattern09_0057,  Pattern09_0058,  Pattern09_0059,  /* 56 */
    Pattern09_0060,  Pattern09_0061,  Pattern09_0062,  Pattern09_0063,  /* 60 */
    Pattern09_0064,  Pattern09_0065,  Pattern09_0066,  Pattern09_0067,  /* 64 */
    Pattern09_0068,  Pattern09_0069,  Pattern09_0070,  Pattern09_0071,  /* 68 */
    Pattern09_0072,  Pattern09_0073,  Pattern09_0074,  Pattern09_0075,  /* 72 */
    Pattern09_0076,  Pattern09_0077,  Pattern09_0078,  Pattern09_0079,  /* 76 */
    Pattern09_0080,  Pattern09_0081,  Pattern09_0082,  Pattern09_0083,  /* 80 */
    Pattern09_0084,  Pattern09_0085,  Pattern09_0086,  Pattern09_0087,  /* 84 */
    Pattern09_0088,  Pattern09_0089,  Pattern09_0090,  Pattern09_0091,  /* 88 */
    Pattern09_0092,  Pattern09_0093,  Pattern09_0094,  Pattern09_0095,  /* 92 */
    Pattern09_0096,  Pattern09_0097,  Pattern09_0098,  Pattern09_0099,  /* 96 */
    Pattern09_0100,  /* 100 */
};

void (*const Pattern10_Tbl[70])() = {
    Pattern10_0000,  Pattern10_0001,  Pattern10_0002,  Pattern10_0003,  /* 0 */
    Pattern10_0004,  Pattern10_0005,  Pattern10_0006,  Pattern10_0007,  /* 4 */
    Pattern10_0008,  Pattern10_0009,  Pattern10_0010,  Pattern10_0011,  /* 8 */
    Pattern10_0012,  Pattern10_0013,  Pattern10_0014,  Pattern10_0015,  /* 12 */
    Pattern10_0016,  Pattern10_0017,  Pattern10_0018,  Pattern10_0019,  /* 16 */
    Pattern10_0020,  Pattern10_0021,  Pattern10_0022,  Pattern10_0023,  /* 20 */
    Pattern10_0024,  Pattern10_0025,  Pattern10_0026,  Pattern10_0027,  /* 24 */
    Pattern10_0028,  Pattern10_0029,  Pattern10_0030,  Pattern10_0031,  /* 28 */
    Pattern10_0032,  Pattern10_0033,  Pattern10_0034,  Pattern10_0035,  /* 32 */
    Pattern10_0036,  Pattern10_0037,  Pattern10_0038,  Pattern10_0039,  /* 36 */
    Pattern10_0040,  Pattern10_0041,  Pattern10_0042,  Pattern10_0043,  /* 40 */
    Pattern10_0044,  Pattern10_0045,  Pattern10_0046,  Pattern10_0047,  /* 44 */
    Pattern10_0048,  Pattern10_0049,  Pattern10_0050,  Pattern10_0051,  /* 48 */
    Pattern10_0052,  Pattern10_0053,  Pattern10_0054,  Pattern10_0055,  /* 52 */
    Pattern10_0056,  Pattern10_0057,  Pattern10_0058,  Pattern10_0059,  /* 56 */
    Pattern10_0060,  Pattern10_0061,  Pattern10_0062,  Pattern10_0063,  /* 60 */
    Pattern10_0064,  Pattern10_0065,  Pattern10_0066,  Pattern10_0067,  /* 64 */
    Pattern10_0068,  Pattern10_0069,  /* 68 */
};

void (*const Pattern11_Tbl[90])() = {
    Pattern11_0000,  Pattern11_0001,  Pattern11_0002,  Pattern11_0003,  /* 0 */
    Pattern11_0004,  Pattern11_0005,  Pattern11_0006,  Pattern11_0007,  /* 4 */
    Pattern11_0008,  Pattern11_0009,  Pattern11_0010,  Pattern11_0011,  /* 8 */
    Pattern11_0012,  Pattern11_0013,  Pattern11_0014,  Pattern11_0015,  /* 12 */
    Pattern11_0016,  Pattern11_0017,  Pattern11_0018,  Pattern11_0019,  /* 16 */
    Pattern11_0020,  Pattern11_0021,  Pattern11_0022,  Pattern11_0023,  /* 20 */
    Pattern11_0024,  Pattern11_0025,  Pattern11_0026,  Pattern11_0027,  /* 24 */
    Pattern11_0028,  Pattern11_0029,  Pattern11_0030,  Pattern11_0031,  /* 28 */
    Pattern11_0032,  Pattern11_0033,  Pattern11_0034,  Pattern11_0035,  /* 32 */
    Pattern11_0036,  Pattern11_0037,  Pattern11_0038,  Pattern11_0039,  /* 36 */
    Pattern11_0040,  Pattern11_0041,  Pattern11_0042,  Pattern11_0043,  /* 40 */
    Pattern11_0044,  Pattern11_0045,  Pattern11_0046,  Pattern11_0047,  /* 44 */
    Pattern11_0048,  Pattern11_0049,  Pattern11_0050,  Pattern11_0051,  /* 48 */
    Pattern11_0052,  Pattern11_0053,  Pattern11_0054,  Pattern11_0055,  /* 52 */
    Pattern11_0056,  Pattern11_0057,  Pattern11_0058,  Pattern11_0059,  /* 56 */
    Pattern11_0060,  Pattern11_0061,  Pattern11_0062,  Pattern11_0063,  /* 60 */
    Pattern11_0064,  Pattern11_0065,  Pattern11_0066,  Pattern11_0067,  /* 64 */
    Pattern11_0068,  Pattern11_0069,  Pattern11_0070,  Pattern11_0071,  /* 68 */
    Pattern11_0072,  Pattern11_0073,  Pattern11_0074,  Pattern11_0075,  /* 72 */
    Pattern11_0076,  Pattern11_0077,  Pattern11_0078,  Pattern11_0079,  /* 76 */
    Pattern11_0080,  Pattern11_0081,  Pattern11_0082,  Pattern11_0083,  /* 80 */
    Pattern11_0084,  Pattern11_0085,  Pattern11_0086,  Pattern11_0087,  /* 84 */
    Pattern11_0088,  Pattern11_0089,  /* 88 */
};

void (*const Pattern12_Tbl[86])() = {
    Pattern12_0000,  Pattern12_0001,  Pattern12_0002,  Pattern12_0003,  /* 0 */
    Pattern12_0004,  Pattern12_0005,  Pattern12_0006,  Pattern12_0007,  /* 4 */
    Pattern12_0008,  Pattern12_0009,  Pattern12_0010,  Pattern12_0011,  /* 8 */
    Pattern12_0012,  Pattern12_0013,  Pattern12_0014,  Pattern12_0015,  /* 12 */
    Pattern12_0016,  Pattern12_0017,  Pattern12_0018,  Pattern12_0019,  /* 16 */
    Pattern12_0020,  Pattern12_0021,  Pattern12_0022,  Pattern12_0023,  /* 20 */
    Pattern12_0024,  Pattern12_0025,  Pattern12_0026,  Pattern12_0027,  /* 24 */
    Pattern12_0028,  Pattern12_0029,  Pattern12_0030,  Pattern12_0031,  /* 28 */
    Pattern12_0032,  Pattern12_0033,  Pattern12_0034,  Pattern12_0035,  /* 32 */
    Pattern12_0036,  Pattern12_0037,  Pattern12_0038,  Pattern12_0039,  /* 36 */
    Pattern12_0040,  Pattern12_0041,  Pattern12_0042,  Pattern12_0043,  /* 40 */
    Pattern12_0044,  Pattern12_0045,  Pattern12_0046,  Pattern12_0047,  /* 44 */
    Pattern12_0048,  Pattern12_0049,  Pattern12_0050,  Pattern12_0051,  /* 48 */
    Pattern12_0052,  Pattern12_0053,  Pattern12_0054,  Pattern12_0055,  /* 52 */
    Pattern12_0056,  Pattern12_0057,  Pattern12_0058,  Pattern12_0059,  /* 56 */
    Pattern12_0060,  Pattern12_0061,  Pattern12_0062,  Pattern12_0063,  /* 60 */
    Pattern12_0064,  Pattern12_0065,  Pattern12_0066,  Pattern12_0067,  /* 64 */
    Pattern12_0068,  Pattern12_0069,  Pattern12_0070,  Pattern12_0071,  /* 68 */
    Pattern12_0072,  Pattern12_0073,  Pattern12_0074,  Pattern12_0075,  /* 72 */
    Pattern12_0076,  Pattern12_0077,  Pattern12_0078,  Pattern12_0079,  /* 76 */
    Pattern12_0080,  Pattern12_0081,  Pattern12_0082,  Pattern12_0083,  /* 80 */
    Pattern12_0084,  Pattern12_0085,  /* 84 */
};

void (*const Pattern13_Tbl[81])() = {
    Pattern13_0000,  Pattern13_0001,  Pattern13_0002,  Pattern13_0003,  /* 0 */
    Pattern13_0004,  Pattern13_0005,  Pattern13_0006,  Pattern13_0007,  /* 4 */
    Pattern13_0008,  Pattern13_0009,  Pattern13_0010,  Pattern13_0011,  /* 8 */
    Pattern13_0012,  Pattern13_0013,  Pattern13_0014,  Pattern13_0015,  /* 12 */
    Pattern13_0016,  Pattern13_0017,  Pattern13_0018,  Pattern13_0019,  /* 16 */
    Pattern13_0020,  Pattern13_0021,  Pattern13_0022,  Pattern13_0023,  /* 20 */
    Pattern13_0024,  Pattern13_0025,  Pattern13_0026,  Pattern13_0027,  /* 24 */
    Pattern13_0028,  Pattern13_0029,  Pattern13_0030,  Pattern13_0031,  /* 28 */
    Pattern13_0032,  Pattern13_0033,  Pattern13_0034,  Pattern13_0035,  /* 32 */
    Pattern13_0036,  Pattern13_0037,  Pattern13_0038,  Pattern13_0039,  /* 36 */
    Pattern13_0040,  Pattern13_0041,  Pattern13_0042,  Pattern13_0043,  /* 40 */
    Pattern13_0044,  Pattern13_0045,  Pattern13_0046,  Pattern13_0047,  /* 44 */
    Pattern13_0048,  Pattern13_0049,  Pattern13_0050,  Pattern13_0051,  /* 48 */
    Pattern13_0052,  Pattern13_0053,  Pattern13_0054,  Pattern13_0055,  /* 52 */
    Pattern13_0056,  Pattern13_0057,  Pattern13_0058,  Pattern13_0059,  /* 56 */
    Pattern13_0060,  Pattern13_0061,  Pattern13_0062,  Pattern13_0063,  /* 60 */
    Pattern13_0064,  Pattern13_0065,  Pattern13_0066,  Pattern13_0067,  /* 64 */
    Pattern13_0068,  Pattern13_0069,  Pattern13_0070,  Pattern13_0071,  /* 68 */
    Pattern13_0072,  Pattern13_0073,  Pattern13_0074,  Pattern13_0075,  /* 72 */
    Pattern13_0076,  Pattern13_0077,  Pattern13_0078,  Pattern13_0079,  /* 76 */
    Pattern13_0080,  /* 80 */
};

void (*const Pattern14_Tbl[151])() = {
    Pattern14_0000,  Pattern14_0001,  Pattern14_0002,  Pattern14_0003,  /* 0 */
    Pattern14_0004,  Pattern14_0005,  Pattern14_0006,  Pattern14_0007,  /* 4 */
    Pattern14_0008,  Pattern14_0009,  Pattern14_0010,  Pattern14_0011,  /* 8 */
    Pattern14_0012,  Pattern14_0013,  Pattern14_0014,  Pattern14_0015,  /* 12 */
    Pattern14_0016,  Pattern14_0017,  Pattern14_0018,  Pattern14_0019,  /* 16 */
    Pattern14_0020,  Pattern14_0021,  Pattern14_0022,  Pattern14_0023,  /* 20 */
    Pattern14_0024,  Pattern14_0025,  Pattern14_0026,  Pattern14_0027,  /* 24 */
    Pattern14_0028,  Pattern14_0029,  Pattern14_0030,  Pattern14_0031,  /* 28 */
    Pattern14_0032,  Pattern14_0033,  Pattern14_0034,  Pattern14_0035,  /* 32 */
    Pattern14_0036,  Pattern14_0037,  Pattern14_0038,  Pattern14_0039,  /* 36 */
    Pattern14_0040,  Pattern14_0041,  Pattern14_0042,  Pattern14_0043,  /* 40 */
    Pattern14_0044,  Pattern14_0045,  Pattern14_0046,  Pattern14_0047,  /* 44 */
    Pattern14_0048,  Pattern14_0049,  Pattern14_0050,  Pattern14_0051,  /* 48 */
    Pattern14_0052,  Pattern14_0053,  Pattern14_0054,  Pattern14_0055,  /* 52 */
    Pattern14_0056,  Pattern14_0057,  Pattern14_0058,  Pattern14_0059,  /* 56 */
    Pattern14_0060,  Pattern14_0061,  Pattern14_0062,  Pattern14_0063,  /* 60 */
    Pattern14_0064,  Pattern14_0065,  Pattern14_0066,  Pattern14_0067,  /* 64 */
    Pattern14_0068,  Pattern14_0069,  Pattern14_0070,  Pattern14_0071,  /* 68 */
    Pattern14_0072,  Pattern14_0073,  Pattern14_0074,  Pattern14_0075,  /* 72 */
    Pattern14_0076,  Pattern14_0077,  Pattern14_0078,  Pattern14_0079,  /* 76 */
    Pattern14_0080,  Pattern14_0081,  Pattern14_0082,  Pattern14_0083,  /* 80 */
    Pattern14_0084,  Pattern14_0085,  Pattern14_0086,  Pattern14_0087,  /* 84 */
    Pattern14_0088,  Pattern14_0089,  Pattern14_0090,  Pattern14_0091,  /* 88 */
    Pattern14_0092,  Pattern14_0093,  Pattern14_0094,  Pattern14_0095,  /* 92 */
    Pattern14_0096,  Pattern14_0097,  Pattern14_0098,  Pattern14_0099,  /* 96 */
    Pattern14_0100,  Pattern14_0101,  Pattern14_0102,  Pattern14_0103,  /* 100 */
    Pattern14_0104,  Pattern14_0105,  Pattern14_0106,  Pattern14_0107,  /* 104 */
    Pattern14_0108,  Pattern14_0109,  Pattern14_0110,  Pattern14_0111,  /* 108 */
    Pattern14_0112,  Pattern14_0113,  Pattern14_0114,  Pattern14_0115,  /* 112 */
    Pattern14_0116,  Pattern14_0117,  Pattern14_0118,  Pattern14_0119,  /* 116 */
    Pattern14_0120,  Pattern14_0121,  Pattern14_0122,  Pattern14_0123,  /* 120 */
    Pattern14_0124,  Pattern14_0125,  Pattern14_0126,  Pattern14_0127,  /* 124 */
    Pattern14_0128,  Pattern14_0129,  Pattern14_0130,  Pattern14_0131,  /* 128 */
    Pattern14_0132,  Pattern14_0133,  Pattern14_0134,  Pattern14_0135,  /* 132 */
    Pattern14_0136,  Pattern14_0137,  Pattern14_0138,  Pattern14_0139,  /* 136 */
    Pattern14_0140,  Pattern14_0141,  Pattern14_0142,  Pattern14_0143,  /* 140 */
    Pattern14_0144,  Pattern14_0145,  Pattern14_0146,  Pattern14_0147,  /* 144 */
    Pattern14_0148,  Pattern14_0149,  Pattern14_0150,  /* 148 */
};

void (*const Pattern15_Tbl[149])() = {
    Pattern15_0000,  Pattern15_0001,  Pattern15_0002,  Pattern15_0003,  /* 0 */
    Pattern15_0004,  Pattern15_0005,  Pattern15_0006,  Pattern15_0007,  /* 4 */
    Pattern15_0008,  Pattern15_0009,  Pattern15_0010,  Pattern15_0011,  /* 8 */
    Pattern15_0012,  Pattern15_0013,  Pattern15_0014,  Pattern15_0015,  /* 12 */
    Pattern15_0016,  Pattern15_0017,  Pattern15_0018,  Pattern15_0019,  /* 16 */
    Pattern15_0020,  Pattern15_0021,  Pattern15_0022,  Pattern15_0023,  /* 20 */
    Pattern15_0024,  Pattern15_0025,  Pattern15_0026,  Pattern15_0027,  /* 24 */
    Pattern15_0028,  Pattern15_0029,  Pattern15_0030,  Pattern15_0031,  /* 28 */
    Pattern15_0032,  Pattern15_0033,  Pattern15_0034,  Pattern15_0035,  /* 32 */
    Pattern15_0036,  Pattern15_0037,  Pattern15_0038,  Pattern15_0039,  /* 36 */
    Pattern15_0040,  Pattern15_0041,  Pattern15_0042,  Pattern15_0043,  /* 40 */
    Pattern15_0044,  Pattern15_0045,  Pattern15_0046,  Pattern15_0047,  /* 44 */
    Pattern15_0048,  Pattern15_0049,  Pattern15_0050,  Pattern15_0051,  /* 48 */
    Pattern15_0052,  Pattern15_0053,  Pattern15_0054,  Pattern15_0055,  /* 52 */
    Pattern15_0056,  Pattern15_0057,  Pattern15_0058,  Pattern15_0059,  /* 56 */
    Pattern15_0060,  Pattern15_0061,  Pattern15_0062,  Pattern15_0063,  /* 60 */
    Pattern15_0064,  Pattern15_0065,  Pattern15_0066,  Pattern15_0067,  /* 64 */
    Pattern15_0068,  Pattern15_0069,  Pattern15_0070,  Pattern15_0071,  /* 68 */
    Pattern15_0072,  Pattern15_0073,  Pattern15_0074,  Pattern15_0075,  /* 72 */
    Pattern15_0076,  Pattern15_0077,  Pattern15_0078,  Pattern15_0079,  /* 76 */
    Pattern15_0080,  Pattern15_0081,  Pattern15_0082,  Pattern15_0083,  /* 80 */
    Pattern15_0084,  Pattern15_0085,  Pattern15_0086,  Pattern15_0087,  /* 84 */
    Pattern15_0088,  Pattern15_0089,  Pattern15_0090,  Pattern15_0091,  /* 88 */
    Pattern15_0092,  Pattern15_0093,  Pattern15_0094,  Pattern15_0095,  /* 92 */
    Pattern15_0096,  Pattern15_0097,  Pattern15_0098,  Pattern15_0099,  /* 96 */
    Pattern15_0100,  Pattern15_0101,  Pattern15_0102,  Pattern15_0103,  /* 100 */
    Pattern15_0104,  Pattern15_0105,  Pattern15_0106,  Pattern15_0107,  /* 104 */
    Pattern15_0108,  Pattern15_0109,  Pattern15_0110,  Pattern15_0111,  /* 108 */
    Pattern15_0112,  Pattern15_0113,  Pattern15_0114,  Pattern15_0115,  /* 112 */
    Pattern15_0116,  Pattern15_0117,  Pattern15_0118,  Pattern15_0119,  /* 116 */
    Pattern15_0120,  Pattern15_0121,  Pattern15_0122,  Pattern15_0123,  /* 120 */
    Pattern15_0124,  Pattern15_0125,  Pattern15_0126,  Pattern15_0127,  /* 124 */
    Pattern15_0128,  Pattern15_0129,  Pattern15_0130,  Pattern15_0131,  /* 128 */
    Pattern15_0132,  Pattern15_0133,  Pattern15_0134,  Pattern15_0135,  /* 132 */
    Pattern15_0136,  Pattern15_0137,  Pattern15_0138,  Pattern15_0139,  /* 136 */
    Pattern15_0140,  Pattern15_0141,  Pattern15_0142,  Pattern15_0143,  /* 140 */
    Pattern15_0144,  Pattern15_0145,  Pattern15_0146,  Pattern15_0147,  /* 144 */
    Pattern15_0148,  /* 148 */
};


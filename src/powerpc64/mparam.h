/* Generated by MPFR's tuneup.c, 2010-10-18, gcc 4.4.4 */
/* ps3gccfarm.fsffrance.org (Cell Broadband Engine, altivec supported) with gmp 5.0.1 */


#define MPFR_TUNE_CASE "src/powerpc64/mparam.h"
#define MPFR_MULHIGH_TAB  \
 -1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,14,14,14,14,14,16,16,18,18,18,18, \
 18,22,22,22,22,28,28,28,28,28,28,28,28,28,32,32, \
 32,32,32,36,36,36,36,36,36,36,36,36,44,44,44,44, \
 44,44,44,44,44,44,56,56,56,56,56,56,56,56,56,56, \
 56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56, \
 56,56,64,64,72,72,72,72,72,72,72,64,72,72,72,72, \
 72,72,72,72,72,93,93,93,93,93,93,93,96,93,93,96, \
 93,99,96,93,80,93,95,93,93,105,105,105,117,102,126,93, \
 105,105,105,111,96,105,105,105,105,120,105,117,105,88,117,87, \
 105,117,105,105,129,117,105,158,129,129,136,129,129,129,129,129, \
 129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129, \
 129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129, \
 129,129,129,129,129,129,129,140,140,140,140,140,140,140,172,172, \
 172,172,172,172,172,172,172,172,172,172,172,172,172,172,172,172, \
 172,172,172,172,172,172,172,172,172,172,172,172,172,172,172,172, \
 172,172,220,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220, \
 220,220,220,220,220,220,220,220,220,252,220,252,252,252,252,252, \
 252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252, \
 252,252,252,252,252,284,284,284,284,284,284,284,284,284,284,284, \
 284,284,284,284,284,284,284,284,284,284,284,284,284,284,284,283, \
 284,284,284,284,284,284,284,284,284,284,284,284,284,284,284,284, \
 284,284,284,284,284,284,284,284,283,284,284,283,284,284,283,284, \
 283,284,283,284,284,284,284,284,283,284,282,283,284,284,284,281, \
 283,284,284,284,284,283,284,283,284,316,316,315,316,348,378,316, \
 378,316,378,378,378,378,378,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,377,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,378,378,378,378,378,378,378,378,378,378, \
 377,378,378,378,378,378,377,378,378,377,378,376,377,378,377,378, \
 377,378,378,378,378,378,426,378,377,378,378,378,378,426,426,378, \
 426,378,426,426,426,425,426,426,426,426,426,426,426,426,426,426, \
 425,426,426,426,426,426,425,426,426,425,426,424,425,426,425,426, \
 425,426,426,426,426,426,425,426,424,425,426,426,426,424,425,426, \
 426,426,426,425,426,425,426,425,426,425,426,426,426,426,426,426, \
 426,425,426,426,425,426,426,426,426,426,426,426,426,426,426,504, \
 426,504,504,504,504,504,504,504,504,504,504,503,504,504,503,504, \
 504,503,504,504,503,504,504,503,504,502,503,504,503,504,503,504, \
 504,504,504,504,503,504,503,504,504,504,504,502,503,504,504,504, \
 504,503,504,503,504,503,504,503,504,504,504,504,503,504,504,503, \
 504,502,503,504,504,504,504,568,504,568,567,568,568,504,568,568, \
 568,568,568,568,567,568,568,567,568,566,567,566,567,568,567,568, \
 568,568,568,568,567,568,566,568,567,568,568,566,567,568,568,568, \
 568,567,568,568,568,567,566,567,568,568,568,568,567,568,568,566, \
 568,568,567,567,568,568,568,568,568,568,568,568,568,568,568,568, \
 568,567,568,568,568,568,568,568,597,568,568,568,568,568,568,568, \
 568,568,568,568,568,568,568,568,568,568,568,568,631,632,632,632, \
 632,631,632,631,632,631,632,631,632,631,632,632,631,632,632,631, \
 632,632,630,632,632,632,632,632,632,632,632,632,632,632,735,632, \
 632,632,632,632,736,736,735,736,632,735,736,736,736,736,735,736, \
 736,735,736,736,736,736,736,736,736,736,736,736,694,736,736,735, \
 736,736,736,736,735,736,735,736,736,736,735,734,734,736,736,735, \
 736,736,736,736,733,736,735,735,736,734,736,736,731,734,735,735, \
 736,735,732,734,734,734,735,735,734,736,735,735,736,760,736,760, \
 736,736,736,758,736,760,759,759,760,760,760,736,760,760,735,734, \
 760,734,734,736,760,734,735,759,760,760,735,736,760,735,735,758, \
 760,760,758,759,758,760,760,784,784,831,832,760,760,760,831,832, \
 832,831,831,831,831,832,832,823,824,832,832,829,831,824,830,824, \
 831,823,831,822,828,832,831,832,832,823,831,822,831,832,831,829, \
 832,831,832,829,829,832,832,832,824,831,832,831,832,828,832,831, \
 832,832,832,824,831,826,830,831,824,832,831,832,831,830,832,832, \
 832,824,832,829,831,830,832,832,832,830,832,830,832,831,831,832 \
  
#define MPFR_SQRHIGH_TAB  \
 -1,0,0,0,0,0,0,0,0,0,6,6,7,7,8,9, \
 9,9,10,10,12,11,12,13,13,13,14,14,15,16,16,16, \
 17,17,18,19,19,19,20,20,21,22,22,22,23,23,24,24, \
 32,32,26,32,34,32,32,32,32,34,32,32,34,32,34,34, \
 34,34,34,38,38,36,36,38,38,38,40,38,40,39,40,40, \
 41,42,42,42,44,44,44,44,46,46,46,48,48,64,64,64, \
 64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64, \
 64,64,64,64,64,64,64,64,64,64,64,68,68,68,68,68, \
 72,72,72,68,67,68,68,68,72,72,96,96,96,96,96,96, \
 96,96,96,96,96,96,96,96,96,96,96,96,99,99,99,99, \
 96,96,96,96,99,99,99,96,99,96,114,111,152,96,96,129, \
 95,96,134,114,99,98,158,105,112,117,147,105,108,123,132,105, \
 129,122,99,99,111,111,111,111,105,111,117,108,108,110,111,111, \
 111,108,108,111,111,117,111,111,111,111,117,123,117,111,117,117, \
 123,120,123,126,123,129,129,129,129,129,123,123,123,123,128,129, \
 129,129,122,123,123,123,135,128,129,129,129,129,129,128,129,129, \
 135,129,132,134,132,135,134,135,133,134,135,134,135,136,148,140, \
 139,140,139,140,140,140,140,148,147,148,147,148,148,148,148,148, \
 155,156,146,147,148,148,148,156,152,164,152,155,156,156,156,164, \
 155,156,156,156,163,164,164,162,163,164,164,171,172,172,172,170, \
 171,172,172,172,172,171,172,171,172,171,172,171,172,188,172,172, \
 176,188,188,188,172,172,188,172,188,196,196,187,188,176,176,195, \
 196,204,204,195,196,188,187,188,252,188,252,252,252,252,252,252, \
 252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252, \
 251,252,252,252,252,252,252,252,256,256,256,252,252,252,252,250, \
 256,252,252,252,252,260,252,256,252,260,260,267,252,268,268,252, \
 267,268,268,268,268,265,268,267,268,265,268,267,268,268,252,268, \
 252,252,252,252,268,268,267,268,268,268,268,267,267,268,268,268, \
 268,268,268,268,268,268,268,268,267,268,268,268,268,268,268,268, \
 268,268,268,268,268,268,268,268,268,268,268,268,268,268,268,268, \
 284,268,268,284,284,284,284,284,284,284,284,284,284,284,284,268, \
 268,268,268,268,268,267,268,268,268,268,268,268,268,268,268,268, \
 268,268,268,268,284,268,268,268,268,268,268,284,268,284,268,268, \
 268,267,268,268,268,268,268,268,284,284,378,284,378,378,378,378, \
 284,377,378,378,284,378,378,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,378,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,378,378,378,378,378,378,378,402,378,378, \
 378,378,378,402,402,402,401,402,402,402,402,402,402,402,402,402, \
 402,402,401,378,402,378,378,378,378,378,378,378,378,378,378,378, \
 378,377,378,378,378,378,378,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,378,378,378,378,378,378,378,378,378,378, \
 378,378,378,378,378,378,378,378,377,378,378,378,378,378,377,378, \
 378,378,378,378,378,378,378,378,378,378,378,377,378,402,402,378, \
 378,378,402,402,401,402,402,402,402,402,402,402,402,402,402,402, \
 402,402,402,402,502,402,402,402,402,402,402,402,402,402,402,402, \
 426,426,426,426,426,426,426,426,426,426,426,426,426,426,426,426, \
 426,426,426,426,426,426,426,426,426,426,426,426,426,426,426,504, \
 504,504,504,426,504,504,426,426,426,504,504,504,504,504,504,504, \
 504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504, \
 504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504, \
 504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504, \
 504,504,504,536,504,536,536,535,536,536,536,536,536,536,536,536, \
 536,536,536,536,536,536,536,536,536,536,536,536,536,536,536,536, \
 536,536,536,536,536,536,536,536,536,536,534,536,536,536,536,536, \
 536,536,568,536,536,536,536,536,535,536,536,568,536,536,536,536, \
 536,568,536,536,568,568,536,536,536,536,536,536,535,536,536,536, \
 535,536,536,535,536,536,536,536,536,536,536,536,536,536,536,536, \
 536,536,536,536,536,536,536,536,536,536,536,536,536,536,536,535, \
 536,536,536,536,536,536,536,568,568,568,567,568,568,568,568,536, \
 568,568,536,568,568,568,565,568,568,568,568,568,568,568,568,568, \
 568,568,760,568,568,760,568,568,760,568,568,568,568,568,760,568, \
 760,760,760,760,760,760,760,760,759,759,760,760,760,760,760,760, \
 760,760,760,760,760,760,760,760,760,760,760,760,760,760,760,760, \
 760,760,760,760,760,760,760,760,760,760,760,760,760,760,760,760 \
  
#define MPFR_DIVHIGH_TAB  \
 0,1,2,2,2,5,6,5,6,7,8,7,8,9,10,11, \
 9,9,9,10,13,12,13,12,13,14,14,14,15,16,17,18, \
 19,20,21,19,20,21,19,23,22,23,21,22,23,23,24,24, \
 24,26,26,27,27,28,28,28,28,29,30,30,30,33,31,33, \
 32,33,34,35,35,36,36,37,36,37,37,38,38,40,40,40, \
 40,41,41,50,53,51,51,52,51,54,53,51,53,53,55,56, \
 55,56,56,56,56,56,56,56,56,56,55,56,56,56,56,56, \
 56,63,64,63,64,64,64,64,64,64,64,71,64,71,72,71, \
 71,71,71,72,71,71,71,72,72,72,71,71,72,72,72,72, \
 72,73,75,79,80,76,76,79,80,80,80,79,79,80,79,80, \
 80,88,88,112,112,112,112,112,112,112,112,112,112,112,112,112, \
 112,112,112,112,112,112,112,112,112,112,112,112,112,112,112,112, \
 112,112,112,112,112,112,112,112,112,112,112,112,112,112,112,112, \
 128,128,112,128,112,128,112,128,136,143,144,110,112,112,112,112, \
 112,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128, \
 128,128,128,128,128,128,128,128,128,128,128,128,144,128,144,144, \
 144,144,144,144,144,144,144,144,144,144,144,144,143,144,144,144, \
 144,144,144,144,143,144,142,144,144,144,144,144,143,144,143,144, \
 144,152,160,152,148,160,159,160,160,160,160,160,159,160,158,159, \
 160,160,160,158,159,160,160,160,176,159,160,176,158,176,174,176, \
 176,176,176,204,175,176,208,176,208,208,208,208,208,208,208,208, \
 208,208,208,208,209,208,207,208,208,208,224,208,209,210,206,216, \
 208,216,210,216,210,216,208,224,224,224,224,224,208,216,216,224, \
 224,224,224,222,224,224,224,224,224,222,224,224,224,208,224,208, \
 224,216,224,216,208,216,216,208,224,224,216,224,224,224,224,224, \
 224,224,224,224,216,224,224,224,224,224,224,224,224,224,224,224, \
 224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224, \
 222,223,224,223,224,256,224,256,256,256,256,256,224,224,256,256, \
 256,256,256,256,256,256,256,256,256,256,256,256,256,256,256,256, \
 254,255,256,255,256,256,256,256,252,253,254,255,256,256,256,256, \
 256,256,256,256,256,256,256,256,256,256,256,256,256,256,256,256, \
 256,256,256,256,256,256,256,256,255,256,256,256,256,256,256,256, \
 256,257,257,280,280,287,280,280,279,288,280,280,288,280,288,288, \
 288,288,280,279,288,280,287,288,280,288,288,288,280,288,288,278, \
 279,288,288,288,280,279,280,288,280,280,280,280,287,288,280,288, \
 288,288,288,286,288,288,288,288,287,286,288,287,287,288,288,288, \
 288,295,296,312,311,304,304,319,320,305,312,312,312,310,304,318, \
 312,319,318,320,312,318,312,320,320,320,304,312,312,320,312,319, \
 312,311,320,311,344,320,320,317,320,344,320,336,344,320,344,344, \
 319,344,320,344,343,320,344,343,351,351,320,351,344,352,344,341, \
 336,343,344,344,343,343,350,352,352,349,344,439,352,350,352,352, \
 352,344,352,350,343,352,440,352,440,432,440,416,439,440,440,432, \
 440,432,440,440,429,432,440,440,439,440,439,432,437,440,432,439, \
 432,417,440,439,432,432,432,420,432,432,432,440,431,440,440,440, \
 432,433,440,440,439,433,440,440,432,440,439,440,432,432,440,440, \
 440,439,440,438,439,448,439,440,440,440,432,440,440,439,440,439, \
 440,440,440,440,440,439,438,440,440,439,439,440,440,439,440,440, \
 440,440,448,440,439,439,440,440,439,440,448,440,439,432,440,432, \
 440,439,440,439,439,440,432,439,439,440,440,438,440,440,440,440, \
 440,440,448,440,440,440,440,436,439,440,432,432,432,440,440,440, \
 440,440,439,448,439,439,440,439,440,439,436,448,440,440,440,440, \
 448,439,440,440,440,440,440,439,440,440,438,448,432,440,440,440, \
 440,440,440,438,440,439,432,448,437,448,440,432,440,440,440,440, \
 438,448,448,440,440,448,440,440,440,439,440,440,440,440,448,448, \
 448,440,437,440,440,440,440,440,440,448,440,448,448,448,448,448, \
 440,448,448,447,448,448,448,448,448,448,446,448,511,504,480,448, \
 504,504,512,502,512,503,512,504,504,512,501,504,504,512,512,512, \
 504,503,500,504,512,511,512,512,512,511,512,512,512,504,512,512, \
 512,512,512,504,504,512,503,510,512,504,512,512,511,511,512,512, \
 512,512,512,512,512,511,512,501,512,512,504,502,504,504,504,512, \
 512,512,504,504,504,511,504,512,512,511,504,512,504,512,512,510, \
 504,504,512,512,512,504,504,512,504,511,512,511,510,512,508,512, \
 512,504,512,512,504,512,511,512,512,512,512,504,512,512,504,512, \
 512,512,559,510,512,512,512,512,510,512,512,512,510,512,512,512 \
  
#define MPFR_MUL_THRESHOLD 7 /* limbs */
#define MPFR_SQR_THRESHOLD 17 /* limbs */
#define MPFR_EXP_2_THRESHOLD 780 /* bits */
#define MPFR_EXP_THRESHOLD 12598 /* bits */
#define MPFR_SINCOS_THRESHOLD 21485 /* bits */
#define MPFR_AI_THRESHOLD1 -20040 /* threshold for negative input of mpfr_ai */
#define MPFR_AI_THRESHOLD2 1813
#define MPFR_AI_THRESHOLD3 31265
/* Tuneup completed successfully, took 6533 seconds */

/* Generated by MPFR's tuneup.c, 2009-02-10, gcc 4.3 */
/* gcc50.fsffrance.org (armv5tel-unknown-linux-gnueabi) with gmp-4.2.4 */

#define MPFR_TUNE_CASE "ARM"
#define MPFR_MULHIGH_TAB  \
 -1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,0,0,0,0,80,0,0,72,72, \
 80,77,72,72,76,76,80,77,84,84,76,76,77,77,84,84, \
 76,76,80,80,84,84,76,76,80,80,84,84,79,79,80,80, \
 81,81,82,82,83,83,84,84,103,103,104,104,96,111,103,112, \
 104,104,111,111,112,112,128,128,120,120,127,127,119,119,111,111, \
 113,113,114,126,127,127,128,128,129,129,118,134,123,135,128,136, \
 137,137,134,134,127,127,128,128,141,137,142,142,143,143,144,144, \
 145,145,142,142,143,143,144,144,145,145,150,150,151,151,152,144, \
 149,149,158,150,159,159,160,160,161,153,158,154,159,159,160,160, \
 159,159,160,160,166,166,152,167,168,168,159,159,160,160,161,161, \
 167,167,163,163,164,159,150,160,161,166,167,162,168,158,159,159, \
 160,155,156,156,162,157,158,158,159,159,160,160,166,161,162,167, \
 168,168,159,159,160,160,206,206,207,167,168,168,224,224,210,205, \
 167,167,168,168,223,223,224,224,219,225,226,208,221,239,240,240, \
 223,205,224,224,225,207,208,256,239,209,222,222,253,223,224,224, \
 225,255,256,256,221,221,222,222,223,223,224,224,255,255,232,256, \
 233,233,234,234,223,253,254,254,243,249,250,250,239,233,240,288, \
 256,242,243,271,272,251,252,287,288,288,240,240,241,255,256,256, \
 257,257,258,272,252,252,253,253,254,254,255,255,256,256,271,257, \
 272,272,266,273,288,274,268,268,290,269,284,284,271,271,272,272, \
 280,280,288,281,282,282,290,304,333,298,271,299,307,286,287,287, \
 305,305,298,306,315,299,300,300,301,309,326,286,287,303,304,288, \
 289,305,330,330,331,331,332,324,333,333,286,286,287,335,336,336, \
 353,329,330,330,331,331,332,332,333,357,302,342,359,351,352,328, \
 353,345,354,330,331,331,332,332,333,357,358,358,359,367,368,368, \
 329,356,357,330,331,331,332,377,378,378,379,379,380,380,372,381, \
 355,382,383,356,357,384,367,403,404,404,405,405,379,352,353,362, \
 363,363,373,382,383,374,402,384,403,403,404,404,405,378,379,352, \
 353,362,381,381,427,427,428,428,429,429,367,376,377,431,405,432, \
 429,379,380,380,381,381,402,402,403,453,404,384,405,375,406,406, \
 407,377,378,378,379,379,380,380,381,381,432,432,383,383,384,384, \
 385,425,426,396,407,477,408,408,419,399,400,380,381,401,402,392, \
 393,403,404,404,405,405,476,426,427,417,428,428,429,429,430,430, \
 409,420,421,476,477,477,401,401,402,402,403,403,426,426,427,405, \
 417,428,429,429,430,430,431,431,432,421,477,422,423,423,424,424, \
 425,425,426,459,471,449,428,428,429,429,430,452,453,475,465,454, \
 455,455,456,456,468,468,469,458,470,492,438,471,472,450,473,473, \
 449,449,450,450,451,451,452,452,453,453,454,478,479,467,468,456, \
 481,469,470,458,459,471,496,472,473,461,462,462,463,475,476,476, \
 477,477,478,466,467,467,468,468,469,469,470,482,483,483,484,496, \
 497,485,486,474,475,475,476,500,501,477,490,490,491,491,492,492, \
 463,476,477,477,478,478,479,492,480,493,494,481,495,495,483,483, \
 497,497,498,498,499,473,474,474,475,488,489,463,464,464,465,465, \
 466,453,467,467,468,494,495,482,483,470,471,497,498,498,499,499, \
 500,474,475,475,476,463,464,490,491,491,492,492,493,480,481,572, \
 501,473,474,474,475,475,476,476,477,477,478,478,479,479,620,480, \
 481,495,496,496,497,595,596,498,499,499,612,486,613,669,614,600, \
 489,615,616,672,477,477,618,618,619,619,620,620,607,621,664,622, \
 623,623,624,624,625,611,612,668,669,669,614,614,615,671,672,616, \
 614,644,645,645,616,616,647,617,618,618,619,664,650,665,666,651, \
 667,667,668,668,669,654,655,655,656,656,657,657,658,658,659,659, \
 660,645,646,661,662,617,648,648,619,649,650,665,666,711,712,667, \
 668,668,714,669,715,715,716,671,672,672,673,658,674,704,690,675, \
 657,657,658,658,659,691,708,708,693,709,710,710,711,711,712,712, \
 713,713,714,666,667,667,668,716,765,717,718,718,719,719,720,720, \
 737,705,690,722,723,755,756,740,725,757,758,710,759,759,712,712, \
 761,713,714,714,715,715,764,764,765,717,766,766,767,767,768,768 \

#define MPFR_SQRHIGH_TAB  \
 -1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,12,13,13,14,14,15,15,16,16, \
 17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24, \
 25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32, \
 33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40, \
 41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48, \
 49,49,50,50,51,51,52,52,53,53,54,54,55,55,56,56, \
 57,57,58,58,59,59,60,60,61,61,62,62,63,63,64,64, \
 65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72, \
 73,73,74,74,75,75,76,76,77,77,78,78,79,79,80,80, \
 81,81,82,82,83,83,84,84,85,85,86,86,87,87,88,88, \
 89,89,90,90,91,91,92,92,93,93,94,94,95,95,96,96, \
 97,97,98,98,99,99,100,100,101,101,102,102,103,103,104,104, \
 105,105,106,106,107,107,108,108,109,109,110,110,111,111,112,112, \
 113,113,114,114,115,115,116,116,117,117,118,118,119,119,120,120, \
 121,121,122,122,123,123,124,124,125,125,126,126,127,127,128,128, \
 129,129,130,130,131,131,132,132,133,133,134,134,135,135,136,136, \
 137,137,138,138,139,139,140,140,141,141,142,142,143,143,144,144, \
 145,145,146,146,147,147,148,148,149,149,150,150,151,151,152,152, \
 168,153,154,154,155,155,156,156,157,177,168,168,174,159,160,160, \
 161,173,174,168,175,163,164,164,165,183,184,184,167,167,168,168, \
 169,169,170,170,171,171,172,172,173,173,174,174,175,175,176,176, \
 177,177,178,178,179,179,180,180,181,181,182,182,183,183,184,184, \
 185,185,186,186,187,187,188,188,189,189,190,190,191,191,192,192, \
 193,193,194,194,195,195,196,196,197,197,198,198,199,199,200,200, \
 201,201,202,202,203,224,204,204,205,205,206,206,207,207,208,208, \
 209,209,210,210,211,211,212,212,213,213,214,214,215,215,216,216, \
 217,217,218,218,219,219,220,220,221,221,222,222,223,223,224,224, \
 225,225,226,226,227,227,228,228,229,229,230,230,231,231,232,232, \
 233,233,234,234,235,235,236,236,237,237,238,238,239,239,240,240, \
 241,241,242,242,243,243,244,244,245,245,246,246,247,247,248,248, \
 249,249,250,250,251,251,252,252,253,253,254,254,255,255,256,256, \
 257,257,258,258,259,259,260,260,261,261,262,262,263,263,264,264, \
 265,265,266,266,267,267,268,268,269,269,270,270,271,271,272,272, \
 273,273,274,274,275,302,303,276,304,277,278,296,279,288,316,280, \
 281,308,309,282,283,319,320,302,303,285,286,313,314,287,288,288, \
 329,289,320,310,311,321,312,312,313,313,334,324,325,325,326,326, \
 327,337,328,328,329,329,330,330,331,301,302,332,333,333,334,304, \
 305,305,306,306,357,337,338,328,349,349,350,350,351,351,352,352, \
 343,343,344,354,355,365,366,366,367,387,388,388,319,349,370,370, \
 365,354,355,355,356,378,379,368,369,380,381,392,393,393,328,328, \
 329,373,374,396,386,386,387,387,388,399,378,400,412,423,336,424, \
 403,403,393,371,372,405,406,406,396,407,408,397,398,409,410,432, \
 345,422,423,401,402,413,414,392,393,415,416,427,428,417,429,440, \
 437,401,402,438,439,451,452,452,453,417,418,430,431,431,432,432, \
 433,421,422,446,447,459,460,424,425,365,366,366,367,451,452,368, \
 369,429,430,454,455,443,444,456,457,445,446,482,483,375,376,376, \
 377,437,438,450,451,475,476,488,501,465,478,430,431,383,384,384, \
 385,385,386,503,504,491,440,388,389,389,390,507,391,391,392,392, \
 393,393,394,394,395,434,396,487,449,449,450,398,399,399,400,400, \
 401,401,402,402,403,403,404,404,405,405,445,458,459,446,460,408, \
 461,409,410,410,411,411,412,412,413,413,414,492,415,415,416,416, \
 417,417,418,418,419,489,420,420,421,421,422,422,423,423,424,480, \
 425,425,426,468,497,427,428,428,429,429,430,430,431,431,432,432, \
 433,433,434,434,435,435,436,436,437,437,438,438,439,439,440,440, \
 441,441,442,442,443,443,444,444,445,445,446,446,447,447,448,448, \
 449,449,450,450,451,451,452,452,453,453,454,454,455,455,456,456, \
 457,457,458,458,459,459,460,520,521,461,462,462,463,463,464,464, \
 465,465,466,511,512,467,468,468,469,469,470,470,471,471,472,472, \
 473,473,474,474,475,535,536,551,477,477,478,478,479,479,480,480, \
 481,481,482,482,483,483,484,484,485,485,486,486,487,487,488,488, \
 489,489,490,490,491,491,492,492,493,493,494,494,495,495,496,496, \
 497,497,498,498,499,499,500,500,501,501,502,502,503,503,504,504, \
 505,505,506,506,507,507,508,508,509,509,510,510,511,511,512,512 \

#define MPFR_MUL_THRESHOLD 7 /* limbs */
#define MPFR_EXP_2_THRESHOLD 407 /* bits */
#define MPFR_EXP_THRESHOLD 4030 /* bits */

/*1652191 卓弋然 计算机1*/
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄
#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
using namespace std;

typedef struct tagRS_BLOCKINFO
{
	int ncRSBlock;		// ＲＳブロック数
	int ncAllCodeWord;	// ブロック内コードワード数
	int ncDataCodeWord;	// データコードワード数(コードワード数 - ＲＳコードワード数)

} RS_BLOCKINFO, *LPRS_BLOCKINFO;

typedef struct tagQR_VERSIONINFO
{
	int nVersionNo;	   
	int ncAllCodeWord; 
		
	int ncDataCodeWord[4];	

	int ncAlignPoint;	
	int nAlignPoint[6];	

	RS_BLOCKINFO RS_BlockInfo1[4]; 
	RS_BLOCKINFO RS_BlockInfo2[4];

} QR_VERSIONINFO, *LPQR_VERSIONINFO;

static QR_VERSIONINFO QR_VersonInfo[] = { { 0 }, // (ダミー:Ver.0)
{ 1, // Ver.1
26,   19,   16,   13,    9,
0,   0,   0,   0,   0,   0,   0,
1,  26,  19,
1,  26,  16,
1,  26,  13,
1,  26,   9,
0,   0,   0,
0,   0,   0,
0,   0,   0,
0,   0,   0 },
{ 2, // Ver.2
44,   34,   28,   22,   16,
1,  18,   0,   0,   0,   0,   0,
1,  44,  34,
1,  44,  28,
1,  44,  22,
1,  44,  16,
0,   0,   0,
0,   0,   0,
0,   0,   0,
0,   0,   0 },
{ 3, // Ver.3
70,   55,   44,   34,   26,
1,  22,   0,   0,   0,   0,   0,
1,  70,  55,
1,  70,  44,
2,  35,  17,
2,  35,  13,
0,   0,   0,
0,   0,   0,
0,   0,   0,
0,   0,   0 },
{ 4, // Ver.4
100,   80,   64,   48,   36,
1,  26,   0,   0,   0,   0,   0,
1, 100,  80,
2,  50,  32,
2,  50,  24,
4,  25,   9,
0,   0,   0,
0,   0,   0,
0,   0,   0,
0,   0,   0 },
{ 5, // Ver.5
134,  108,   86,   62,   46,
1,  30,   0,   0,   0,   0,   0,
1, 134, 108,
2,  67,  43,
2,  33,  15,
2,  33,  11,
0,   0,   0,
0,   0,   0,
2,  34,  16,
2,  34,  12 },
{ 6, // Ver.6
172,  136,  108,   76,   60,
1,  34,   0,   0,   0,   0,   0,
2,  86,  68,
4,  43,  27,
4,  43,  19,
4,  43,  15,
0,   0,   0,
0,   0,   0,
0,   0,   0,
0,   0,   0 },
{ 7, // Ver.7
196,  156,  124,   88,   66,
2,  22,  38,   0,   0,   0,   0,
2,  98,  78,
4,  49,  31,
2,  32,  14,
4,  39,  13,
0,   0,   0,
0,   0,   0,
4,  33,  15,
1,  40,  14 },
{ 8, // Ver.8
242,  194,  154,  110,   86,
2,  24,  42,   0,   0,   0,   0,
2, 121,  97,
2,  60,  38,
4,  40,  18,
4,  40,  14,
0,   0,   0,
2,  61,  39,
2,  41,  19,
2,  41,  15 },
{ 9, // Ver.9
292,  232,  182,  132,  100,
2,  26,  46,   0,   0,   0,   0,
2, 146, 116,
3,  58,  36,
4,  36,  16,
4,  36,  12,
0,   0,   0,
2,  59,  37,
4,  37,  17,
4,  37,  13 },
{ 10, // Ver.10
346,  274,  216,  154,  122,
2,  28,  50,   0,   0,   0,   0,
2,  86,  68,
4,  69,  43,
6,  43,  19,
6,  43,  15,
2,  87,  69,
1,  70,  44,
2,  44,  20,
2,  44,  16 },
{ 11, // Ver.11
404,  324,  254,  180,  140,
2,  30,  54,   0,   0,   0,   0,
4, 101,  81,
1,  80,  50,
4,  50,  22,
3,  36,  12,
0,   0,   0,
4,  81,  51,
4,  51,  23,
8,  37,  13 },
{ 12, // Ver.12
466,  370,  290,  206,  158,
2,  32,  58,   0,   0,   0,   0,
2, 116,  92,
6,  58,  36,
4,  46,  20,
7,  42,  14,
2, 117,  93,
2,  59,  37,
6,  47,  21,
4,  43,  15 },
{ 13, // Ver.13
532,  428,  334,  244,  180,
2,  34,  62,   0,   0,   0,   0,
4, 133, 107,
8,  59,  37,
8,  44,  20,
12,  33,  11,
0,   0,   0,
1,  60,  38,
4,  45,  21,
4,  34,  12 },
{ 14, // Ver.14
581,  461,  365,  261,  197,
3,  26,  46,  66,   0,   0,   0,
3, 145, 115,
4,  64,  40,
11,  36,  16,
11,  36,  12,
1, 146, 116,
5,  65,  41,
5,  37,  17,
5,  37,  13 },
{ 15, // Ver.15
655,  523,  415,  295,  223,
3,  26,  48,  70,   0,   0,   0,
5, 109,  87,
5,  65,  41,
5,  54,  24,
11,  36,  12,
1, 110,  88,
5,  66,  42,
7,  55,  25,
7,  37,  13 },
{ 16, // Ver.16
733,  589,  453,  325,  253,
3,  26,  50,  74,   0,   0,   0,
5, 122,  98,
7,  73,  45,
15,  43,  19,
3,  45,  15,
1, 123,  99,
3,  74,  46,
2,  44,  20,
13,  46,  16 },
{ 17, // Ver.17
815,  647,  507,  367,  283,
3,  30,  54,  78,   0,   0,   0,
1, 135, 107,
10,  74,  46,
1,  50,  22,
2,  42,  14,
5, 136, 108,
1,  75,  47,
15,  51,  23,
17,  43,  15 },
{ 18, // Ver.18
901,  721,  563,  397,  313,
3,  30,  56,  82,   0,   0,   0,
5, 150, 120,
9,  69,  43,
17,  50,  22,
2,  42,  14,
1, 151, 121,
4,  70,  44,
1,  51,  23,
19,  43,  15 },
{ 19, // Ver.19
991,  795,  627,  445,  341,
3,  30,  58,  86,   0,   0,   0,
3, 141, 113,
3,  70,  44,
17,  47,  21,
9,  39,  13,
4, 142, 114,
11,  71,  45,
4,  48,  22,
16,  40,  14 },
{ 20, // Ver.20
1085,  861,  669,  485,  385,
3,  34,  62,  90,   0,   0,   0,
3, 135, 107,
3,  67,  41,
15,  54,  24,
15,  43,  15,
5, 136, 108,
13,  68,  42,
5,  55,  25,
10,  44,  16 },
{ 21, // Ver.21
1156,  932,  714,  512,  406,
4,  28,  50,  72,  94,   0,   0,
4, 144, 116,
17,  68,  42,
17,  50,  22,
19,  46,  16,
4, 145, 117,
0,   0,   0,
6,  51,  23,
6,  47,  17 },
{ 22, // Ver.22
1258, 1006,  782,  568,  442,
4,  26,  50,  74,  98,   0,   0,
2, 139, 111,
17,  74,  46,
7,  54,  24,
34,  37,  13,
7, 140, 112,
0,   0,   0,
16,  55,  25,
0,   0,   0 },
{ 23, // Ver.23
1364, 1094,  860,  614,  464,
4,  30,  54,  78, 102,   0,   0,
4, 151, 121,
4,  75,  47,
11,  54,  24,
16,  45,  15,
5, 152, 122,
14,  76,  48,
14,  55,  25,
14,  46,  16 },
{ 24, // Ver.24
1474, 1174,  914,  664,  514,
4,  28,  54,  80, 106,   0,   0,
6, 147, 117,
6,  73,  45,
11,  54,  24,
30,  46,  16,
4, 148, 118,
14,  74,  46,
16,  55,  25,
2,  47,  17 },
{ 25, // Ver.25
1588, 1276, 1000,  718,  538,
4,  32,  58,  84, 110,   0,   0,
8, 132, 106,
8,  75,  47,
7,  54,  24,
22,  45,  15,
4, 133, 107,
13,  76,  48,
22,  55,  25,
13,  46,  16 },
{ 26, // Ver.26
1706, 1370, 1062,  754,  596,
4,  30,  58,  86, 114,   0,   0,
10, 142, 114,
19,  74,  46,
28,  50,  22,
33,  46,  16,
2, 143, 115,
4,  75,  47,
6,  51,  23,
4,  47,  17 },
{ 27, // Ver.27
1828, 1468, 1128,  808,  628,
4,  34,  62,  90, 118,   0,   0,
8, 152, 122,
22,  73,  45,
8,  53,  23,
12,  45,  15,
4, 153, 123,
3,  74,  46,
26,  54,  24,
28,  46,  16 },
{ 28, // Ver.28
1921, 1531, 1193,  871,  661,
5,  26,  50,  74,  98, 122,   0,
3, 147, 117,
3,  73,  45,
4,  54,  24,
11,  45,  15,
10, 148, 118,
23,  74,  46,
31,  55,  25,
31,  46,  16 },
{ 29, // Ver.29
2051, 1631, 1267,  911,  701,
5,  30,  54,  78, 102, 126,   0,
7, 146, 116,
21,  73,  45,
1,  53,  23,
19,  45,  15,
7, 147, 117,
7,  74,  46,
37,  54,  24,
26,  46,  16 },
{ 30, // Ver.30
2185, 1735, 1373,  985,  745,
5,  26,  52,  78, 104, 130,   0,
5, 145, 115,
19,  75,  47,
15,  54,  24,
23,  45,  15,
10, 146, 116,
10,  76,  48,
25,  55,  25,
25,  46,  16 },
{ 31, // Ver.31
2323, 1843, 1455, 1033,  793,
5,  30,  56,  82, 108, 134,   0,
13, 145, 115,
2,  74,  46,
42,  54,  24,
23,  45,  15,
3, 146, 116,
29,  75,  47,
1,  55,  25,
28,  46,  16 },
{ 32, // Ver.32
2465, 1955, 1541, 1115,  845,
5,  34,  60,  86, 112, 138,   0,
17, 145, 115,
10,  74,  46,
10,  54,  24,
19,  45,  15,
0,   0,   0,
23,  75,  47,
35,  55,  25,
35,  46,  16 },
{ 33, // Ver.33
2611, 2071, 1631, 1171,  901,
5,  30,  58,  86, 114, 142,   0,
17, 145, 115,
14,  74,  46,
29,  54,  24,
11,  45,  15,
1, 146, 116,
21,  75,  47,
19,  55,  25,
46,  46,  16 },
{ 34, // Ver.34
2761, 2191, 1725, 1231,  961,
5,  34,  62,  90, 118, 146,   0,
13, 145, 115,
14,  74,  46,
44,  54,  24,
59,  46,  16,
6, 146, 116,
23,  75,  47,
7,  55,  25,
1,  47,  17 },
{ 35, // Ver.35
2876, 2306, 1812, 1286,  986,
6,  30,  54,  78, 102, 126, 150,
12, 151, 121,
12,  75,  47,
39,  54,  24,
22,  45,  15,
7, 152, 122,
26,  76,  48,
14,  55,  25,
41,  46,  16 },
{ 36, // Ver.36
3034, 2434, 1914, 1354, 1054,
6,  24,  50,  76, 102, 128, 154,
6, 151, 121,
6,  75,  47,
46,  54,  24,
2,  45,  15,
14, 152, 122,
34,  76,  48,
10,  55,  25,
64,  46,  16 },
{ 37, // Ver.37
3196, 2566, 1992, 1426, 1096,
6,  28,  54,  80, 106, 132, 158,
17, 152, 122,
29,  74,  46,
49,  54,  24,
24,  45,  15,
4, 153, 123,
14,  75,  47,
10,  55,  25,
46,  46,  16 },
{ 38, // Ver.38
3362, 2702, 2102, 1502, 1142,
6,  32,  58,  84, 110, 136, 162,
4, 152, 122,
13,  74,  46,
48,  54,  24,
42,  45,  15,
18, 153, 123,
32,  75,  47,
14,  55,  25,
32,  46,  16 },
{ 39, // Ver.39
3532, 2812, 2216, 1582, 1222,
6,  26,  54,  82, 110, 138, 166,
20, 147, 117,
40,  75,  47,
43,  54,  24,
10,  45,  15,
4, 148, 118,
7,  76,  48,
22,  55,  25,
67,  46,  16 },
{ 40, // Ver.40
3706, 2956, 2334, 1666, 1276,
6,  30,  58,  86, 114, 142, 170,
19, 148, 118,
18,  75,  47,
34,  54,  24,
20,  45,  15,
6, 149, 119,
31,  76,  48,
34,  55,  25,
61,  46,  16 }
};

static unsigned char byExpToInt[] = { 1,   2,   4,   8,  16,  32,  64, 128,  29,  58, 116, 232, 205, 135,  19,  38,
76, 152,  45,  90, 180, 117, 234, 201, 143,   3,   6,  12,  24,  48,  96, 192,
157,  39,  78, 156,  37,  74, 148,  53, 106, 212, 181, 119, 238, 193, 159,  35,
70, 140,   5,  10,  20,  40,  80, 160,  93, 186, 105, 210, 185, 111, 222, 161,
95, 190,  97, 194, 153,  47,  94, 188, 101, 202, 137,  15,  30,  60, 120, 240,
253, 231, 211, 187, 107, 214, 177, 127, 254, 225, 223, 163,  91, 182, 113, 226,
217, 175,  67, 134,  17,  34,  68, 136,  13,  26,  52, 104, 208, 189, 103, 206,
129,  31,  62, 124, 248, 237, 199, 147,  59, 118, 236, 197, 151,  51, 102, 204,
133,  23,  46,  92, 184, 109, 218, 169,  79, 158,  33,  66, 132,  21,  42,  84,
168,  77, 154,  41,  82, 164,  85, 170,  73, 146,  57, 114, 228, 213, 183, 115,
230, 209, 191,  99, 198, 145,  63, 126, 252, 229, 215, 179, 123, 246, 241, 255,
227, 219, 171,  75, 150,  49,  98, 196, 149,  55, 110, 220, 165,  87, 174,  65,
130,  25,  50, 100, 200, 141,   7,  14,  28,  56, 112, 224, 221, 167,  83, 166,
81, 162,  89, 178, 121, 242, 249, 239, 195, 155,  43,  86, 172,  69, 138,   9,
18,  36,  72, 144,  61, 122, 244, 245, 247, 243, 251, 235, 203, 139,  11,  22,
44,  88, 176, 125, 250, 233, 207, 131,  27,  54, 108, 216, 173,  71, 142,   1 };

static unsigned char byIntToExp[] = { 0,   0,   1,  25,   2,  50,  26, 198,   3, 223,  51, 238,  27, 104, 199,  75,
4, 100, 224,  14,  52, 141, 239, 129,  28, 193, 105, 248, 200,   8,  76, 113,
5, 138, 101,  47, 225,  36,  15,  33,  53, 147, 142, 218, 240,  18, 130,  69,
29, 181, 194, 125, 106,  39, 249, 185, 201, 154,   9, 120,  77, 228, 114, 166,
6, 191, 139,  98, 102, 221,  48, 253, 226, 152,  37, 179,  16, 145,  34, 136,
54, 208, 148, 206, 143, 150, 219, 189, 241, 210,  19,  92, 131,  56,  70,  64,
30,  66, 182, 163, 195,  72, 126, 110, 107,  58,  40,  84, 250, 133, 186,  61,
202,  94, 155, 159,  10,  21, 121,  43,  78, 212, 229, 172, 115, 243, 167,  87,
7, 112, 192, 247, 140, 128,  99,  13, 103,  74, 222, 237,  49, 197, 254,  24,
227, 165, 153, 119,  38, 184, 180, 124,  17,  68, 146, 217,  35,  32, 137,  46,
55,  63, 209,  91, 149, 188, 207, 205, 144, 135, 151, 178, 220, 252, 190,  97,
242,  86, 211, 171,  20,  42,  93, 158, 132,  60,  57,  83,  71, 109,  65, 162,
31,  45,  67, 216, 183, 123, 164, 118, 196,  23,  73, 236, 127,  12, 111, 246,
108, 161,  59,  82,  41, 157,  85, 170, 251,  96, 134, 177, 187, 204,  62,  90,
203,  89,  95, 176, 156, 169, 160,  81,  11, 245,  22, 235, 122, 117,  44, 215,
79, 174, 213, 233, 230, 231, 173, 232, 116, 214, 244, 234, 168,  80,  88, 175 };

static unsigned char byRSExp7[] = { 87, 229, 146, 149, 238, 102,  21 };
static unsigned char byRSExp10[] = { 251,  67,  46,  61, 118,  70,  64,  94,  32,  45 };
static unsigned char byRSExp13[] = { 74, 152, 176, 100,  86, 100, 106, 104, 130, 218, 206, 140,  78 };
static unsigned char byRSExp15[] = { 8, 183,  61,  91, 202,  37,  51,  58,  58, 237, 140, 124,   5,  99, 105 };
static unsigned char byRSExp16[] = { 120, 104, 107, 109, 102, 161,  76,   3,  91, 191, 147, 169, 182, 194, 225, 120 };
static unsigned char byRSExp17[] = { 43, 139, 206,  78,  43, 239, 123, 206, 214, 147,  24,  99, 150,  39, 243, 163, 136 };
static unsigned char byRSExp18[] = { 215, 234, 158,  94, 184,  97, 118, 170,  79, 187, 152, 148, 252, 179,   5,  98,  96, 153 };
static unsigned char byRSExp20[] = { 17,  60,  79,  50,  61, 163,  26, 187, 202, 180, 221, 225,  83, 239, 156, 164, 212, 212, 188, 190 };
static unsigned char byRSExp22[] = { 210, 171, 247, 242,  93, 230,  14, 109, 221,  53, 200,  74,   8, 172,  98,  80, 219, 134, 160, 105,
165, 231 };
static unsigned char byRSExp24[] = { 229, 121, 135,  48, 211, 117, 251, 126, 159, 180, 169, 152, 192, 226, 228, 218, 111,   0, 117, 232,
87,  96, 227,  21 };
static unsigned char byRSExp26[] = { 173, 125, 158,   2, 103, 182, 118,  17, 145, 201, 111,  28, 165,  53, 161,  21, 245, 142,  13, 102,
48, 227, 153, 145, 218,  70 };
static unsigned char byRSExp28[] = { 168, 223, 200, 104, 224, 234, 108, 180, 110, 190, 195, 147, 205,  27, 232, 201,  21,  43, 245,  87,
42, 195, 212, 119, 242,  37,   9, 123 };
static unsigned char byRSExp30[] = { 41, 173, 145, 152, 216,  31, 179, 182,  50,  48, 110,  86, 239,  96, 222, 125,  42, 173, 226, 193,
224, 130, 156,  37, 251, 216, 238,  40, 192, 180 };
static unsigned char byRSExp32[] = { 10,   6, 106, 190, 249, 167,   4,  67, 209, 138, 138,  32, 242, 123,  89,  27, 120, 185,  80, 156,
38,  69, 171,  60,  28, 222,  80,  52, 254, 185, 220, 241 };
static unsigned char byRSExp34[] = { 111,  77, 146,  94,  26,  21, 108,  19, 105,  94, 113, 193,  86, 140, 163, 125,  58, 158, 229, 239,
218, 103,  56,  70, 114,  61, 183, 129, 167,  13,  98,  62, 129,  51 };
static unsigned char byRSExp36[] = { 200, 183,  98,  16, 172,  31, 246, 234,  60, 152, 115,   0, 167, 152, 113, 248, 238, 107,  18,  63,
218,  37,  87, 210, 105, 177, 120,  74, 121, 196, 117, 251, 113, 233,  30, 120 };
static unsigned char byRSExp38[] = { 159,  34,  38, 228, 230,  59, 243,  95,  49, 218, 176, 164,  20,  65,  45, 111,  39,  81,  49, 118,
113, 222, 193, 250, 242, 168, 217,  41, 164, 247, 177,  30, 238,  18, 120, 153,  60, 193 };
static unsigned char byRSExp40[] = { 59, 116,  79, 161, 252,  98, 128, 205, 128, 161, 247,  57, 163,  56, 235, 106,  53,  26, 187, 174,
226, 104, 170,   7, 175,  35, 181, 114,  88,  41,  47, 163, 125, 134,  72,  20, 232,  53,  35,  15 };
static unsigned char byRSExp42[] = { 250, 103, 221, 230,  25,  18, 137, 231,   0,   3,  58, 242, 221, 191, 110,  84, 230,   8, 188, 106,
96, 147,  15, 131, 139,  34, 101, 223,  39, 101, 213, 199, 237, 254, 201, 123, 171, 162, 194, 117,
50,  96 };
static unsigned char byRSExp44[] = { 190,   7,  61, 121,  71, 246,  69,  55, 168, 188,  89, 243, 191,  25,  72, 123,   9, 145,  14, 247,
1, 238,  44,  78, 143,  62, 224, 126, 118, 114,  68, 163,  52, 194, 217, 147, 204, 169,  37, 130,
113, 102,  73, 181 };
static unsigned char byRSExp46[] = { 112,  94,  88, 112, 253, 224, 202, 115, 187,  99,  89,   5,  54, 113, 129,  44,  58,  16, 135, 216,
169, 211,  36,   1,   4,  96,  60, 241,  73, 104, 234,   8, 249, 245, 119, 174,  52,  25, 157, 224,
43, 202, 223,  19,  82,  15 };
static unsigned char byRSExp48[] = { 228,  25, 196, 130, 211, 146,  60,  24, 251,  90,  39, 102, 240,  61, 178,  63,  46, 123, 115,  18,
221, 111, 135, 160, 182, 205, 107, 206,  95, 150, 120, 184,  91,  21, 247, 156, 140, 238, 191,  11,
94, 227,  84,  50, 163,  39,  34, 108 };
static unsigned char byRSExp50[] = { 232, 125, 157, 161, 164,   9, 118,  46, 209,  99, 203, 193,  35,   3, 209, 111, 195, 242, 203, 225,
46,  13,  32, 160, 126, 209, 130, 160, 242, 215, 242,  75,  77,  42, 189,  32, 113,  65, 124,  69,
228, 114, 235, 175, 124, 170, 215, 232, 133, 205 };
static unsigned char byRSExp52[] = { 116,  50,  86, 186,  50, 220, 251,  89, 192,  46,  86, 127, 124,  19, 184, 233, 151, 215,  22,  14,
59, 145,  37, 242, 203, 134, 254,  89, 190,  94,  59,  65, 124, 113, 100, 233, 235, 121,  22,  76,
86,  97,  39, 242, 200, 220, 101,  33, 239, 254, 116,  51 };
static unsigned char byRSExp54[] = { 183,  26, 201,  87, 210, 221, 113,  21,  46,  65,  45,  50, 238, 184, 249, 225, 102,  58, 209, 218,
109, 165,  26,  95, 184, 192,  52, 245,  35, 254, 238, 175, 172,  79, 123,  25, 122,  43, 120, 108,
215,  80, 128, 201, 235,   8, 153,  59, 101,  31, 198,  76,  31, 156 };
static unsigned char byRSExp56[] = { 106, 120, 107, 157, 164, 216, 112, 116,   2,  91, 248, 163,  36, 201, 202, 229,   6, 144, 254, 155,
135, 208, 170, 209,  12, 139, 127, 142, 182, 249, 177, 174, 190,  28,  10,  85, 239, 184, 101, 124,
152, 206,  96,  23, 163,  61,  27, 196, 247, 151, 154, 202, 207,  20,  61,  10 };
static unsigned char byRSExp58[] = { 82, 116,  26, 247,  66,  27,  62, 107, 252, 182, 200, 185, 235,  55, 251, 242, 210, 144, 154, 237,
176, 141, 192, 248, 152, 249, 206,  85, 253, 142,  65, 165, 125,  23,  24,  30, 122, 240, 214,   6,
129, 218,  29, 145, 127, 134, 206, 245, 117,  29,  41,  63, 159, 142, 233, 125, 148, 123 };
static unsigned char byRSExp60[] = { 107, 140,  26,  12,   9, 141, 243, 197, 226, 197, 219,  45, 211, 101, 219, 120,  28, 181, 127,   6,
100, 247,   2, 205, 198,  57, 115, 219, 101, 109, 160,  82,  37,  38, 238,  49, 160, 209, 121,  86,
11, 124,  30, 181,  84,  25, 194,  87,  65, 102, 190, 220,  70,  27, 209,  16,  89,   7,  33, 240 };
static unsigned char byRSExp62[] = { 65, 202, 113,  98,  71, 223, 248, 118, 214,  94,   0, 122,  37,  23,   2, 228,  58, 121,   7, 105,
135,  78, 243, 118,  70,  76, 223,  89,  72,  50,  70, 111, 194,  17, 212, 126, 181,  35, 221, 117,
235,  11, 229, 149, 147, 123, 213,  40, 115,   6, 200, 100,  26, 246, 182, 218, 127, 215,  36, 186,
110, 106 };
static unsigned char byRSExp64[] = { 45,  51, 175,   9,   7, 158, 159,  49,  68, 119,  92, 123, 177, 204, 187, 254, 200,  78, 141, 149,
119,  26, 127,  53, 160,  93, 199, 212,  29,  24, 145, 156, 208, 150, 218, 209,   4, 216,  91,  47,
184, 146,  47, 140, 195, 195, 125, 242, 238,  63,  99, 108, 140, 230, 242,  31, 204,  11, 178, 243,
217, 156, 213, 231 };
static unsigned char byRSExp66[] = { 5, 118, 222, 180, 136, 136, 162,  51,  46, 117,  13, 215,  81,  17, 139, 247, 197, 171,  95, 173,
65, 137, 178,  68, 111,  95, 101,  41,  72, 214, 169, 197,  95,   7,  44, 154,  77, 111, 236,  40,
121, 143,  63,  87,  80, 253, 240, 126, 217,  77,  34, 232, 106,  50, 168,  82,  76, 146,  67, 106,
171,  25, 132,  93,  45, 105 };
static unsigned char byRSExp68[] = { 247, 159, 223,  33, 224,  93,  77,  70,  90, 160,  32, 254,  43, 150,  84, 101, 190, 205, 133,  52,
60, 202, 165, 220, 203, 151,  93,  84,  15,  84, 253, 173, 160,  89, 227,  52, 199,  97,  95, 231,
52, 177,  41, 125, 137, 241, 166, 225, 118,   2,  54,  32,  82, 215, 175, 198,  43, 238, 235,  27,
101, 184, 127,   3,   5,   8, 163, 238 };

static unsigned char*  byRSExp[] = { NULL,      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,      byRSExp7,  NULL,      NULL,
byRSExp10, NULL,      NULL,      byRSExp13, NULL,      byRSExp15, byRSExp16, byRSExp17, byRSExp18, NULL,
byRSExp20, NULL,      byRSExp22, NULL,      byRSExp24, NULL,      byRSExp26, NULL,      byRSExp28, NULL,
byRSExp30, NULL,      byRSExp32, NULL,      byRSExp34, NULL,      byRSExp36, NULL,      byRSExp38, NULL,
byRSExp40, NULL,      byRSExp42, NULL,      byRSExp44, NULL,      byRSExp46, NULL,      byRSExp48, NULL,
byRSExp50, NULL,      byRSExp52, NULL,      byRSExp54, NULL,      byRSExp56, NULL,      byRSExp58, NULL,
byRSExp60, NULL,      byRSExp62, NULL,      byRSExp64, NULL,      byRSExp66, NULL,      byRSExp68 };

static int nIndicatorLenNumeral[] = { 10, 12, 14 };
static int nIndicatorLenAlphabet[] = { 9, 11, 13 };
static int nIndicatorLen8Bit[] = { 8, 16, 16 };
static int nIndicatorLenKanji[] = { 8, 10, 12 };

unsigned int calalign_n(int ver) //计算校正图形数，同时为校正图形坐标赋值
{
	if (ver == 1) return 0;
	if (ver>1 && ver <= 6) return 1;
	if (ver>6 && ver <= 13) return 6;
	if (ver>13 && ver <= 20) return 13;
	if (ver>20 && ver <= 27) return 22;
	if (ver>27 && ver <= 34) return 33;
	if (ver>34 && ver <= 40) return 46;
	else return -1;
}

int str_analysis(char* text)  //返回0表示全是数字，返回0表示存在非数字内容
{
	int num = 1;
	for (; *text != 0; text++) {
		if (!((*text)>='0' && (*text) <= '9'))
			num = 0;
	    }
	if (num == 1) 
		return 0;
	else return 1;
}

int numdigit(int n) //由数字个数计算所需的二进制数据位数
{
	int m, l, digit;
	m = n / 3;
	l = n % 3;
	if (l == 0) 
		digit = m * 10;
	if (l == 1) 
		digit = m * 10 + 4;
	if (l == 2) 
		digit = m * 10 + 7;
	if (n <= 235) 
		digit += 14; 
	else if (n <= 1425) 
		digit += 16;         //从版本10开始，字符计数指示符的位数是12而不是10
	else 
		digit += 18;
	return digit;
}
int asciidigit(int n)//由ascii码个数计算所需的二进制数据位数
{
	int digit = 8 * n;
	if (n <= 98) 
		digit += 12;
	else 
		digit += 50;
	return digit;
}

unsigned int getmsgn(unsigned int ver)
{
	unsigned int funcn, formatn, datan, msgn;
	formatn = ver <= 6 ? 31 : 67;
	if (ver == 1) 
		funcn = 202;
	else 
		funcn = (unsigned int)(180 + 25 * calalign_n(ver) + 2 * (17 + 4 * ver) - 10 * sqrt(3 + calalign_n(ver)));
	datan = (17 + 4 * ver)*(17 + 4 * ver) - funcn - formatn;
	msgn = (datan - (QR_VersonInfo[ver].ncAllCodeWord - QR_VersonInfo[ver].ncDataCodeWord[3]) * 8) / 8 * 8; //按照标准，信息位数（不含纠错）应为8的倍数
	return msgn;
}

int getver(char* text, int mode) //确定版本
{
	unsigned int ver, len = strlen(text);
	unsigned int num, msgn;
	if (mode == 0) 
		num = numdigit(len);
	else if (mode == 1) 
		num = asciidigit(len);
	for (ver = 1; ver <= 40; ver++)
	{
		msgn = getmsgn(ver);
		if (msgn<num)
		{
			if (ver == 40) 
				return -1;
			msgn = getmsgn(ver + 1);
			if (msgn >= num)
				return (ver + 1);
		}
		else if (ver == 1) 
			return 1;
	}
	return -2;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool IsNumeralData(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return true;

	return false;
}

bool IsAlphabetData(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return true;

	if (c >= 'A' && c <= 'Z')
		return true;

	if (c == ' ' || c == '$' || c == '%' || c == '*' || c == '+' || c == '-' || c == '.' || c == '/' || c == ':')
		return true;

	return false;
}

bool IsKanjiData(unsigned char c1, unsigned char c2)
{
	if (((c1 >= 0x81 && c1 <= 0x9f) || (c1 >= 0xe0 && c1 <= 0xeb)) && (c2 >= 0x40))
	{
		if ((c1 == 0x9f && c2 > 0xfc) || (c1 == 0xeb && c2 > 0xbf))
			return false;

		return true;
	}

	return false;
}

int SetBitStream(int nIndex, unsigned short wData, int ncData, unsigned char *m_byDataCodeWord)
{
	int i;

	if (nIndex == -1 || nIndex + ncData > 2000 * 8)
		return -1;

	for (i = 0; i < ncData; ++i)
	{
		if (wData & (1 << (ncData - i - 1)))
		{
			m_byDataCodeWord[(nIndex + i) / 8] |= 1 << (7 - ((nIndex + i) % 8));
		}
	}

	return nIndex + ncData;
}

unsigned short AlphabetToBinaly(unsigned char c)
{
	if (c >= '0' && c <= '9') return (unsigned char)(c - '0');

	if (c >= 'A' && c <= 'Z') return (unsigned char)(c - 'A' + 10);

	if (c == ' ') return 36;

	if (c == '$') return 37;

	if (c == '%') return 38;

	if (c == '*') return 39;

	if (c == '+') return 40;

	if (c == '-') return 41;

	if (c == '.') return 42;

	if (c == '/') return 43;

	return 44; // c == ':'
}

unsigned short KanjiToBinaly(unsigned short wc)
{
	if (wc >= 0x8140 && wc <= 0x9ffc)
		wc -= 0x8140;
	else // (wc >= 0xe040 && wc <= 0xebbf)
		wc -= 0xc140;

	return (unsigned short)(((wc >> 8) * 0xc0) + (wc & 0x00ff));
}

int GetBitLength(BYTE nMode, int ncData, int nVerGroup)
{
	int ncBits = 0;

	switch (nMode)
	{
	case 0:
		ncBits = 4 + nIndicatorLenNumeral[nVerGroup] + (10 * (ncData / 3));
		switch (ncData % 3)
		{
		case 1:
			ncBits += 4;
			break;
		case 2:
			ncBits += 7;
			break;
		default: // case 0:
			break;
		}

		break;

	case 1:
		ncBits = 4 + nIndicatorLenAlphabet[nVerGroup] + (11 * (ncData / 2)) + (6 * (ncData % 2));
		break;

	case 2:
		ncBits = 4 + nIndicatorLen8Bit[nVerGroup] + (8 * ncData);
		break;

	default: // case QR_MODE_KANJI:
		ncBits = 4 + nIndicatorLenKanji[nVerGroup] + (13 * (ncData / 2));
		break;
	}

	return ncBits;
}

bool EncodeSourceData(const char *lpsSource, int ncLength, int nVerGroup, unsigned char *m_byDataCodeWord, int &m_ncDataCodeWordBit)
{
	int m_nBlockLength[2000];
	int m_ncDataBlock;
	unsigned char m_byBlockMode[2000];
	memset(m_nBlockLength, 0, sizeof(m_nBlockLength));

	int i, j;

	// どのモードが何文字(バイト)継続しているかを調査
	for (m_ncDataBlock = i = 0; i < ncLength; ++i)
	{
		BYTE byMode;

		if (i < ncLength - 1 && IsKanjiData(lpsSource[i], lpsSource[i + 1]))
			byMode = 3;
		else if (IsNumeralData(lpsSource[i]))
			byMode = 0;
		else if (IsAlphabetData(lpsSource[i]))
			byMode = 1;
		else
			byMode = 2;

		if (i == 0)
			m_byBlockMode[0] = byMode;

		if (m_byBlockMode[m_ncDataBlock] != byMode)
			m_byBlockMode[++m_ncDataBlock] = byMode;

		++m_nBlockLength[m_ncDataBlock];

		if (byMode == 3)
		{
			// 漢字は文字数ではなく	数で記録
			++m_nBlockLength[m_ncDataBlock];
			++i;
		}
	}

	++m_ncDataBlock;

	/////////////////////////////////////////////////////////////////////////
	// 隣接する英数字モードブロックと数字モードブロックの並びをを条件により結合

	int ncSrcBits, ncDstBits; // 元のビット長と単一の英数字モードブロック化した場合のビット長

	int nBlock = 0;

	while (nBlock < m_ncDataBlock - 1)
	{
		int ncJoinFront, ncJoinBehind; // 前後８ビットバイトモードブロックと結合した場合のビット長
		int nJoinPosition = 0; // ８ビットバイトモードブロックとの結合：-1=前と結合、0=結合しない、1=後ろと結合

							   // 「数字－英数字」または「英数字－数字」の並び
		if ((m_byBlockMode[nBlock] == 0  && m_byBlockMode[nBlock + 1] == 1) ||
			(m_byBlockMode[nBlock] == 1 && m_byBlockMode[nBlock + 1] == 0))
		{
			// 元のビット長と単一の英数字モードブロック化した場合のビット長を比較
			ncSrcBits = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup) +
				GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

			ncDstBits = GetBitLength(1, m_nBlockLength[nBlock] + m_nBlockLength[nBlock + 1], nVerGroup);

			if (ncSrcBits > ncDstBits)
			{
				// 前後に８ビットバイトモードブロックがある場合、それらとの結合が有利かどうかをチェック
				if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
				{
					// 前に８ビットバイトモードブロックあり
					ncJoinFront = GetBitLength(2, m_nBlockLength[nBlock - 1] + m_nBlockLength[nBlock], nVerGroup) +
						GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

					if (ncJoinFront > ncDstBits + GetBitLength(2, m_nBlockLength[nBlock - 1], nVerGroup))
						ncJoinFront = 0; // ８ビットバイトモードブロックとは結合しない
				}
				else
					ncJoinFront = 0;

				if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
				{
					// 後ろに８ビットバイトモードブロックあり
					ncJoinBehind = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup) +
						GetBitLength(2, m_nBlockLength[nBlock + 1] + m_nBlockLength[nBlock + 2], nVerGroup);

					if (ncJoinBehind > ncDstBits + GetBitLength(2, m_nBlockLength[nBlock + 2], nVerGroup))
						ncJoinBehind = 0; // ８ビットバイトモードブロックとは結合しない
				}
				else
					ncJoinBehind = 0;

				if (ncJoinFront != 0 && ncJoinBehind != 0)
				{
					// 前後両方に８ビットバイトモードブロックがある場合はデータ長が短くなる方を優先
					nJoinPosition = (ncJoinFront < ncJoinBehind) ? -1 : 1;
				}
				else
				{
					nJoinPosition = (ncJoinFront != 0) ? -1 : ((ncJoinBehind != 0) ? 1 : 0);
				}

				if (nJoinPosition != 0)
				{
					// ８ビットバイトモードブロックとの結合
					if (nJoinPosition == -1)
					{
						m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

						// 後続をシフト
						for (i = nBlock; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}
					}
					else
					{
						m_byBlockMode[nBlock + 1] = 2;
						m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

						// 後続をシフト
						for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}
					}

					--m_ncDataBlock;
				}
				else
				{
					// 英数字と数字の並びを単一の英数字モードブロックに統合

					if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 1)
					{
						// 結合しようとするブロックの後ろに続く英数字モードブロックを結合
						m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

						// 後続をシフト
						for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}

						--m_ncDataBlock;
					}

					m_byBlockMode[nBlock] = 1;
					m_nBlockLength[nBlock] += m_nBlockLength[nBlock + 1];

					// 後続をシフト
					for (i = nBlock + 1; i < m_ncDataBlock - 1; ++i)
					{
						m_byBlockMode[i] = m_byBlockMode[i + 1];
						m_nBlockLength[i] = m_nBlockLength[i + 1];
					}

					--m_ncDataBlock;

					if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 1)
					{
						// 結合したブロックの前の英数字モードブロックを結合
						m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

						// 後続をシフト
						for (i = nBlock; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}

						--m_ncDataBlock;
					}
				}

				continue; // 現在位置のブロックを再調査
			}
		}

		++nBlock; // 次ブロックを調査
	}

	/////////////////////////////////////////////////////////////////////////
	// 連続する短いモードブロックを８ビットバイトモードブロック化

	nBlock = 0;

	while (nBlock < m_ncDataBlock - 1)
	{
		ncSrcBits = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup)
			+ GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

		ncDstBits = GetBitLength(2, m_nBlockLength[nBlock] + m_nBlockLength[nBlock + 1], nVerGroup);

		// 前に８ビットバイトモードブロックがある場合、重複するインジケータ分を減算
		if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
			ncDstBits -= (4 + nIndicatorLen8Bit[nVerGroup]);

		// 後ろに８ビットバイトモードブロックがある場合、重複するインジケータ分を減算
		if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
			ncDstBits -= (4 + nIndicatorLen8Bit[nVerGroup]);

		if (ncSrcBits > ncDstBits)
		{
			if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
			{
				// 結合するブロックの前にある８ビットバイトモードブロックを結合
				m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

				// 後続をシフト
				for (i = nBlock; i < m_ncDataBlock - 1; ++i)
				{
					m_byBlockMode[i] = m_byBlockMode[i + 1];
					m_nBlockLength[i] = m_nBlockLength[i + 1];
				}

				--m_ncDataBlock;
				--nBlock;
			}

			if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
			{
				// 結合するブロックの後ろにある８ビットバイトモードブロックを結合
				m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

				// 後続をシフト
				for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
				{
					m_byBlockMode[i] = m_byBlockMode[i + 1];
					m_nBlockLength[i] = m_nBlockLength[i + 1];
				}

				--m_ncDataBlock;
			}

			m_byBlockMode[nBlock] = 2;
			m_nBlockLength[nBlock] += m_nBlockLength[nBlock + 1];

			// 後続をシフト
			for (i = nBlock + 1; i < m_ncDataBlock - 1; ++i)
			{
				m_byBlockMode[i] = m_byBlockMode[i + 1];
				m_nBlockLength[i] = m_nBlockLength[i + 1];
			}

			--m_ncDataBlock;

			// 結合したブロックの前から再調査
			if (nBlock >= 1)
				--nBlock;

			continue;
		}

		++nBlock; // 次ブロックを調査
	}

	/////////////////////////////////////////////////////////////////////////
	// ビット配列化
	int ncComplete = 0; // 処理済データカウンタ
	WORD wBinCode;

	m_ncDataCodeWordBit = 0; // ビット単位処理カウンタ

	memset(m_byDataCodeWord, 0, 2000);

	for (i = 0; i < m_ncDataBlock && m_ncDataCodeWordBit != -1; ++i)
	{
		if (m_byBlockMode[i] == 0)
		{
			/////////////////////////////////////////////////////////////////
			// 数字モード

			// インジケータ(0001b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 1, 4, m_byDataCodeWord);

			// 文字数セット
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLenNumeral[nVerGroup], m_byDataCodeWord);

			// ビット列保存
			for (j = 0; j < m_nBlockLength[i]; j += 3)
			{
				if (j < m_nBlockLength[i] - 2)
				{
					wBinCode = (WORD)(((lpsSource[ncComplete + j] - '0') * 100) +
						((lpsSource[ncComplete + j + 1] - '0') * 10) +
						(lpsSource[ncComplete + j + 2] - '0'));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 10, m_byDataCodeWord);
				}
				else if (j == m_nBlockLength[i] - 2)
				{
					// 端数２バイト
					wBinCode = (WORD)(((lpsSource[ncComplete + j] - '0') * 10) +
						(lpsSource[ncComplete + j + 1] - '0'));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 7, m_byDataCodeWord);
				}
				else if (j == m_nBlockLength[i] - 1)
				{
					// 端数１バイト
					wBinCode = (WORD)(lpsSource[ncComplete + j] - '0');

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 4, m_byDataCodeWord);
				}
			}

			ncComplete += m_nBlockLength[i];
		}

		else if (m_byBlockMode[i] == 1)
		{
			/////////////////////////////////////////////////////////////////
			// 英数字モード

			// モードインジケータ(0010b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 2, 4, m_byDataCodeWord);

			// 文字数セット
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLenAlphabet[nVerGroup], m_byDataCodeWord);

			// ビット列保存
			for (j = 0; j < m_nBlockLength[i]; j += 2)
			{
				if (j < m_nBlockLength[i] - 1)
				{
					wBinCode = (WORD)((AlphabetToBinaly(lpsSource[ncComplete + j]) * 45) +
						AlphabetToBinaly(lpsSource[ncComplete + j + 1]));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 11, m_byDataCodeWord);
				}
				else
				{
					// 端数１バイト
					wBinCode = (WORD)AlphabetToBinaly(lpsSource[ncComplete + j]);

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 6, m_byDataCodeWord);
				}
			}

			ncComplete += m_nBlockLength[i];
		}

		else if (m_byBlockMode[i] == 2)
		{
			/////////////////////////////////////////////////////////////////
			// ８ビットバイトモード

			// モードインジケータ(0100b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 4, 4, m_byDataCodeWord);

			// 文字数セット
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLen8Bit[nVerGroup], m_byDataCodeWord);

			// ビット列保存
			for (j = 0; j < m_nBlockLength[i]; ++j)
			{
				m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)lpsSource[ncComplete + j], 8, m_byDataCodeWord);
			}

			ncComplete += m_nBlockLength[i];
		}
		else // m_byBlockMode[i] == 3
		{
			/////////////////////////////////////////////////////////////////
			// 漢字モード

			// モードインジケータ(1000b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 8, 4, m_byDataCodeWord);

			// 文字数セット
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)(m_nBlockLength[i] / 2), nIndicatorLenKanji[nVerGroup], m_byDataCodeWord);

			// 漢字モードでビット列保存
			for (j = 0; j < m_nBlockLength[i] / 2; ++j)
			{
				WORD wBinCode = KanjiToBinaly((WORD)(((BYTE)lpsSource[ncComplete + (j * 2)] << 8) + (BYTE)lpsSource[ncComplete + (j * 2) + 1]));

				m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 13, m_byDataCodeWord);
			}

			ncComplete += m_nBlockLength[i];
		}
	}

	return (m_ncDataCodeWordBit != -1);
}

void EncodeText(char* lpsSource, int ncLength, unsigned char *m_byDataCodeWord,int &m_ncDataCodeWordBit, int nVersion = 1)
{
	int nVerGroup = nVersion >= 27 ? 2 : (nVersion >= 10 ? 1 : 0);
	int i, j;

	for (i = nVerGroup; i <= 2; ++i)
	{
		if (EncodeSourceData(lpsSource, ncLength, i, m_byDataCodeWord, m_ncDataCodeWordBit))    //m_byDataCodeWord：过程数据块，此处初始化(似乎没加版本信息和大小信息)
		{
			if (i == 0)
			{
				for (j = 1; j <= 9; ++j)
				{
					if ((m_ncDataCodeWordBit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[3])
						return;
				}
			}
			else if (i == 1)
			{
				for (j = 10; j <= 26; ++j)
				{
					if ((m_ncDataCodeWordBit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[3])
						return;
				}
			}
			else if (i == 2)
			{
				for (j = 27; j <= 40; ++j)
				{
					if ((m_ncDataCodeWordBit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[3])
						return;
				}
			}
		}
	}

}

void SetVersionPattern(int ver, unsigned char qr[][177])
{
	int i, j;
	int graph_size = ver * 4 + 17;

	if (ver <= 6)
		return;

	int nVerData = ver << 12;

	for (i = 0; i < 6; ++i)
	{
		if (nVerData & (1 << (17 - i)))
		{
			nVerData ^= (0x1f25 << (5 - i));
		}
	}

	nVerData += ver << 12;

	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			qr[graph_size - 11 + j][i] = qr[i][graph_size - 11 + j] =
				(nVerData & (1 << (i * 3 + j))) ? 11 : 10;
		}
	}
}

void SetFormatInfoPattern(int ver, int nPatternNo, unsigned char data[][177])
{
	int nFormatInfo;
	int i;
	int graph_size = ver * 4 + 17;

	nFormatInfo = 0x10;
	nFormatInfo += nPatternNo;

	int nFormatData = nFormatInfo << 10;

	for (i = 0; i < 5; ++i)
	{
		if (nFormatData & (1 << (14 - i)))
		{
			nFormatData ^= (0x0537 << (4 - i)); // 10100110111b
		}
	}

	nFormatData += nFormatInfo << 10;

	nFormatData ^= 0x5412; // 101010000010010b

	for (i = 0; i <= 5; ++i)
		data[8][i] = (nFormatData & (1 << i)) ? 11 : 10;

	data[8][7] = (nFormatData & (1 << 6)) ? 11 : 10;
	data[8][8] = (nFormatData & (1 << 7)) ? 11 : 10;
	data[7][8] = (nFormatData & (1 << 8)) ? 11 : 10;

	for (i = 9; i <= 14; ++i)
		data[14 - i][8] = (nFormatData & (1 << i)) ? 11 : 10;

	for (i = 0; i <= 7; ++i)
		data[graph_size - 1 - i][8] = (nFormatData & (1 << i)) ? 11 : 10;

	data[8][graph_size - 8] = 11; 

	for (i = 8; i <= 14; ++i)
		data[8][graph_size - 15 + i] = (nFormatData & (1 << i)) ? 11 : 10;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void cross_the_data(unsigned char *bytext,unsigned char *byalltext, int ver)
{
	int byalln = QR_VersonInfo[ver].ncAllCodeWord;
	memset(byalltext, 0, byalln);

	int nDataCwIndex = 0;

	int ncBlock1 = QR_VersonInfo[ver].RS_BlockInfo1[3].ncRSBlock;
	int ncBlock2 = QR_VersonInfo[ver].RS_BlockInfo2[3].ncRSBlock;
	int ncBlockSum = ncBlock1 + ncBlock2;

	int nBlockNo = 0; 

	int ncDataCw1 = QR_VersonInfo[ver].RS_BlockInfo1[3].ncDataCodeWord;
	int ncDataCw2 = QR_VersonInfo[ver].RS_BlockInfo2[3].ncDataCodeWord;

	for (int i = 0; i < ncBlock1; i++){
		for (int j = 0; j < ncDataCw1; j++){
			byalltext[(ncBlockSum * j) + nBlockNo] = bytext[nDataCwIndex++];
		    }
		++nBlockNo;
	    }

	for (int i = 0; i < ncBlock2; i++){
		for (int j = 0; j < ncDataCw2; j++){
			if (j < ncDataCw1){
				byalltext[(ncBlockSum * j) + nBlockNo] = bytext[nDataCwIndex++];
			    }
			else{
				byalltext[(ncBlockSum * ncDataCw1) + i] = bytext[nDataCwIndex++];
			    }
		    }
		++nBlockNo;
	    }
}

void get_ec_code(unsigned char message_poly[],int &pointer, int message_num, int generator_num)
{
	int* generator_poly = new int[generator_num];
	for (int i = 0; i < generator_num; i++)
		generator_poly[i] = byRSExp[generator_num][i];

	for (int i = 0; i < message_num; i++) {
		if (message_poly[pointer] == 0)
			pointer++;
		else {
			unsigned char mes_first_exp = byIntToExp[message_poly[pointer]];
			int end_mark = pointer;

			for (int j = end_mark + 1; j < generator_num + end_mark + 1; j++) {
				int by_exp = (int)(generator_poly[j - end_mark - 1] + mes_first_exp);
				while (1) {
					if (by_exp >= 255)
						by_exp %= 255;
					else
						break;
				    }
				unsigned char exp_1 = (unsigned char)(by_exp);

				message_poly[j] = unsigned char(message_poly[j] ^ byExpToInt[exp_1]);
			    }
			pointer++;
		    }
	    }

	delete generator_poly;
}

void add_ec_code(unsigned char *bytext, unsigned char *byalltext, int ver)
{
	int nDataCwIndex = 0;
	int ncDataCodeWord = QR_VersonInfo[ver].ncDataCodeWord[3];

	int ncBlock1 = QR_VersonInfo[ver].RS_BlockInfo1[3].ncRSBlock;
	int ncBlock2 = QR_VersonInfo[ver].RS_BlockInfo2[3].ncRSBlock;
	int ncBlockSum = ncBlock1 + ncBlock2;

	int nBlockNo = 0;

	int ncDataCw1 = QR_VersonInfo[ver].RS_BlockInfo1[3].ncDataCodeWord;   //信息多项式项数1
	int ncDataCw2 = QR_VersonInfo[ver].RS_BlockInfo2[3].ncDataCodeWord;   //信息多项式项数2

	int ncRSCw1 = QR_VersonInfo[ver].RS_BlockInfo1[3].ncAllCodeWord - ncDataCw1;   //生成多项式项数1
	int ncRSCw2 = QR_VersonInfo[ver].RS_BlockInfo2[3].ncAllCodeWord - ncDataCw2;   //生成多项式项数2

	for (int i = 0; i < ncBlock1; i++) {
		int pointer = 0;
		unsigned char ectext[300];
		memset(ectext, 0, 300);

		memcpy(ectext, bytext + nDataCwIndex, ncDataCw1);

		get_ec_code(ectext, pointer, ncDataCw1, ncRSCw1);

		for (int j = 0; j < ncRSCw1; j++)
			byalltext[ncDataCodeWord + (ncBlockSum * j) + nBlockNo] = ectext[pointer + j];
		    
		nDataCwIndex += ncDataCw1;
		++nBlockNo;
	    }

	for (int i = 0; i < ncBlock2; i++) {
		int pointer = 0;
		unsigned char ectext[300];
		memset(ectext, 0, 300);

		memcpy(ectext, bytext + nDataCwIndex, ncDataCw2);

		get_ec_code(ectext, pointer, ncDataCw2, ncRSCw2);

		for (int j = 0; j < ncRSCw2; j++)
			byalltext[ncDataCodeWord + (ncBlockSum * j) + nBlockNo] = ectext[pointer + j];
		    
		nDataCwIndex += ncDataCw2;
		++nBlockNo;
	    }
		
}

void set_finder_patterns(int ver,unsigned char qr[][177])
{
	int graph_size = ver * 4 + 17;

	unsigned int fpattern[] = {
		1111111,
		1000001,
		1011101,
		1011101,
		1011101,
		1000001,
		1111111
	    };

	for (int i = 0; i < 7; ++i){
		for (int j = 0; j < 7; ++j){

			int flag = ((fpattern[i] / (int)pow(10, j) % 10) == 1);
			if (flag) {
				qr[j][i] = 11;
				qr[j][graph_size - 7 + i] = 11;
				qr[graph_size - 7 + j][i] = 11;
			    }
			else {
				qr[j][i] = 10;
				qr[j][graph_size - 7 + i] = 10;  //用来区分已经填过的空格和尚未填的空格
				qr[graph_size - 7 + j][i] = 10;
			    }
		    }
	    }
}

void set_seperator(int ver, unsigned char qr[][177])
{
	int graph_size = ver * 4 + 17;

	for (int i = 0; i < 8; ++i) {
		qr[i][7] = 10;
		qr[7][i] = 10;
		qr[graph_size - 8][i] = 10;
		qr[graph_size - 8 + i][7] = 10;
		qr[i][graph_size - 8] = 10; 
		qr[7][graph_size - 8 + i] = 10;
		qr[graph_size - 8 + i][8] = 10;
		qr[8][graph_size - 8 + i] = 10;
	    }
	    
	for (int i = 0; i < 9; ++i) {
		qr[i][8] = 10;
		qr[8][i] = 10;
	    }
}

void set_one_alignment_pattern(int x,int y, unsigned char qr[][177])
{
	int alignment[] = { 
		11111,
		10001,
		10101,
		10001,
		11111,
		}; 

	if (qr[x][y] == 11 || qr[x][y] == 10)
		return;

	x -= 2; y -= 2;

	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			int flag = ((alignment[i] / (int)pow(10, j) % 10) == 1);
			if (flag)
				qr[x + j][y + i] = 11;
			else 
				qr[x + j][y + i] = 10;
		    }
	    }
}

void set_alignment_patterns(int ver, unsigned char qr[][177])
{
	
	set_one_alignment_pattern(QR_VersonInfo[ver].nAlignPoint[0], QR_VersonInfo[ver].nAlignPoint[0], qr);
	if (ver >= 7) {
		for (int i = 0; i < QR_VersonInfo[ver].ncAlignPoint; i++)
			for (int j = 0; j < QR_VersonInfo[ver].ncAlignPoint; j++)
				set_one_alignment_pattern(QR_VersonInfo[ver].nAlignPoint[i], QR_VersonInfo[ver].nAlignPoint[j], qr);

		for (int i = 0; i < QR_VersonInfo[ver].ncAlignPoint; i++) {
			set_one_alignment_pattern(QR_VersonInfo[ver].nAlignPoint[i], 6, qr);
			set_one_alignment_pattern(6, QR_VersonInfo[ver].nAlignPoint[i], qr);
		    }
	    }

}

void set_timing_patterns(int ver, unsigned char qr[][177])
{
	int graph_size = ver * 4 + 17;

	for (int i = 8; i <= graph_size - 9; ++i){
		if (i % 2 == 0) {
			qr[i][6] = 11;
			qr[6][i] = 11;
		    }
		else {
			qr[i][6] = 10;
			qr[6][i] = 10;
		    }
	    }
}

void full_data(int ver, unsigned char qr[][177],unsigned char byalltext[])
{
	int x = ver * 4 + 17;
	int y = ver * 4 + 16;

	int rx = 1, ry = 1;
	int sum_code_num = QR_VersonInfo[ver].ncAllCodeWord;

	for (int i = 0; i < sum_code_num; ++i){
		for (int j = 0; j < 8; ++j){
			//if (qr[x][y] == 11 || qr[x][y] == 10)
			//	cout << x << "   " << y << endl;
			do{
				x += rx;
				rx *= -1;
				if (rx < 0){
					y += ry;
					if (y < 0 || y == ver * 4 + 17){
						if (y < 0)
							y = 0;
						else
							y = ver * 4 + 16;
						ry *= -1;
						x -= 2;
						if (x == 6)
							--x;
					    }
				     }
				//if (qr[x][y] == 11 || qr[x][y] == 10)
				//	cout<<(int)qr[x][y]<<"    " << x << "   " << y << endl;
			    } while (qr[x][y] == 11 || qr[x][y] == 10);
				
				qr[x][y] = (byalltext[i] & (1 << (7 - j))) ? 21 : 20;
				//if (qr[x][y] == 21)
				//	cout << "    " << i << "    " << j << "    " << x << "    " << y << endl;
		    }
	    }
}

void set_mask(unsigned char data[][177], int mode,int ver)    //////////////////////////////////
{
	int graph_size = ver * 4 + 17;
	for (int row = 0; row < graph_size; row++){
		for (int column = 0; column < graph_size; column++){
			if (data[column][row] / 10 == 2) {
				bool flag = 0;

				if (mode == 0)
					flag = ((column + row) % 2 == 0);
				else if (mode == 1)
					flag = (row % 2 == 0);
				else if (mode == 2)
					flag = (column % 3 == 0);
				else if (mode == 3)
					flag = ((column + row) % 3 == 0);
				else if (mode == 4)
					flag = (((row / 2) + (column / 3)) % 2 == 0);
				else if (mode == 5)
					flag = (((row * column) % 2) + ((row * column) % 3) == 0);
				else if (mode == 6)
					flag = ((((column * row) % 2) + ((column * row) % 3)) % 2 == 0);
				else
					flag = ((((column + row) % 2) + ((column * row) % 3)) % 2 == 0);

				if (flag == 1) {
					if (data[column][row] % 10 == 1)
						data[column][row] = 20;
					else
						data[column][row] = 21;
				    }
			    }
			}
		}
	
}

int count_penalty(int ver, unsigned char data[][177])
{
	int num = 0;
	int graph_size = ver * 4 + 17;

	for (int i = 0; i < graph_size; i++){
		for (int j = 0; j < graph_size - 4;){
			int cnt = 1;
			int k;
			for (k = j + 1; k < graph_size; k++) {
				if (data[i][j] % 10 == data[i][k] % 10)
					cnt++;
				else
					break;
			    }

			if (cnt >= 5)
				num += 3 + cnt - 5;

			j = k;
		    }
	    }

	for (int i = 0; i < graph_size; i++){
		for (int j = 0; j < graph_size - 4;){
			int cnt = 1;
			int k;
			for (k = j + 1; k < graph_size; k++) {
				if (data[j][i] % 10 == data[k][i] % 10)
					cnt++;
				else
					break;
			    }

			if (cnt >= 5)
				num += 3 + cnt - 5;

			j = k;
		    }
	    }

	for (int i = 0; i < graph_size - 1; ++i){
		for (int j = 0; j < graph_size - 1; ++j){
			if ((data[i][j] % 10 == data[i + 1][j] % 10) &&
				(data[i][j] % 10 == data[i][j + 1] % 10) &&
				(data[i][j] % 10 == data[i + 1][j + 1] % 10))
				num += 3; 
		    }
	    }

	for (int i = 0; i < graph_size; i++)
		for (int j = 0; j < graph_size - 10; j++) {
			if (((data[i][j] % 10 == 0) && (data[i][j + 1] % 10 == 0) && (data[i][j + 2] % 10 == 0) && (data[i][j + 3] % 10 == 0) &&
				(data[i][j + 4] % 10 == 1) &&
				(data[i][j + 5] % 10 == 0) &&
				(data[i][j + 6] % 10 == 1) && (data[i][j + 7] % 10 == 1) && (data[i][j + 8] % 10 == 1) &&
				(data[i][j + 9] % 10 == 0) &&
				(data[i][j + 10] % 10 == 1)) ||
				((data[i][j + 7] % 10 == 0) && (data[i][j + 8] % 10 == 0) && (data[i][j + 9] % 10 == 0) && (data[i][j + 10] % 10 == 0) &&
				(data[i][j] % 10 == 1) &&
					(data[i][j + 1] % 10 == 0) &&
					(data[i][j + 2] % 10 == 1) && (data[i][j + 3] % 10 == 1) && (data[i][j + 4] % 10 == 1) &&
					(data[i][j + 5] % 10 == 0) &&
					(data[i][j + 6] % 10 == 1)))
				num += 40;
		    }

	for (int i = 0; i < graph_size; i++)
		for (int j = 0; j < graph_size - 10; j++) {
			if (((data[j][i] % 10 == 0) && (data[j + 1][i] % 10 == 0) && (data[j + 2][i] % 10 == 0) && (data[j + 3][i] % 10 == 0) &&
				(data[j + 4][i] % 10 == 1) &&
				(data[j + 5][i] % 10 == 0) &&
				(data[j + 6][i] % 10 == 1) && (data[j + 7][i] % 10 == 1) && (data[j + 8][i] % 10 == 1) &&
				(data[j + 9][i] % 10 == 0) &&
				(data[j + 10][i] % 10 == 1)) ||
				((data[j + 7][i] % 10 == 0) && (data[j + 8][i] % 10 == 0) && (data[j + 9][i] % 10 == 0) && (data[j + 10][i] % 10 == 0) &&
				(data[j][i] % 10 == 1) &&
					(data[j + 1][i] % 10 == 0) &&
					(data[j + 2][i] % 10 == 1) && (data[j + 3][i] % 10 == 1) && (data[j + 4][i] % 10 == 1) &&
					(data[j + 5][i] % 10 == 0) &&
					(data[j + 6][i] % 10 == 1)))
				num += 40;
		    }

	int cnt = 0;

	for (int i = 0; i < graph_size; ++i){
		for (int j = 0; j < graph_size; ++j){
			if (data[i][j] % 10 == 1)
				cnt++;
		    }
	    }

	num += (abs(50 - ((cnt * 100) / (graph_size * graph_size))) / 5) * 10;

	return num;
}

int encode(char *text,unsigned char result[][177])
{
	int mode = str_analysis(text);
	int ver = getver(text, mode);
//	if (ver == 1)
//		ver++;
	unsigned char bytext[2000];
	int databits;
	//cout << ver;
	//getchar();
	//getchar();
	EncodeText(text, strlen(text), bytext, databits, ver);
	//memcpy(bytext, text, sizeof(text));
	//databits = sizeof(text);

	//加0000
	int datacode = QR_VersonInfo[ver].ncDataCodeWord[3];
	int zeron;
	zeron = 4 >= datacode * 8 - databits ? datacode - databits : 4;
	if (zeron > 0)
		databits = zeron + databits;
	
	//加11101100, 00010001
	int flag = 0;
	unsigned char one_zero = 0xec;
	for (int i = (databits + 7) / 8; i < datacode; ++i){
		bytext[i] = one_zero;
		if (flag == 0) {
			one_zero = 0x11;
			flag = 1;
		    }
		else {
			one_zero = 0xec;
			flag = 0;
		    }
	    }
	unsigned char byalltext[2000];
	cross_the_data(bytext, byalltext, ver);
	add_ec_code(bytext, byalltext, ver);
	

	unsigned char qrgraph[177][177];
	memset(qrgraph, 0, sizeof(qrgraph));
	
	//功能内容填充
	set_finder_patterns(ver, qrgraph);

	set_seperator(ver, qrgraph);
	SetVersionPattern(ver, qrgraph);
	set_alignment_patterns(ver, qrgraph);
	set_timing_patterns(ver, qrgraph);
	
	//文本内容填充
	full_data(ver, qrgraph, byalltext);
	
	//还剩掩码未写
	unsigned char data_for_mask[177][177];
	int min_penalty = 2000;
	int mask_no = 0;
	for (int i = 0; i < 8; i++) {
		memcpy(data_for_mask, qrgraph, sizeof(qrgraph));
		const int N = 4 * ver + 17;
		
		set_mask(data_for_mask, i, ver);

		SetFormatInfoPattern(ver, i, data_for_mask);
		int num = count_penalty(ver, data_for_mask);
		printf("score:%d\n", num);
		if (num < min_penalty) {
			min_penalty = num;
			mask_no = i;
		    }
	    }
	printf("best::%d\n", mask_no);
	set_mask(qrgraph, mask_no, ver);
	SetFormatInfoPattern(ver, mask_no, qrgraph);
	
	for (int i = 0; i < 177; i++) {
		for (int j = 0; j < 177; j++) {
			if (qrgraph[i][j] % 10 == 1)
				result[i][j] = 1;
			else
				result[i][j] = 0;
		    }
	    }
		
	return ver;
}

int main()
{
	char text[2000];
	unsigned char result[177][177];
	cout << "请输入要生成的内容：";
	gets_s(text);
	getchar();
	system("cls");
	int size = encode(text, result) * 4 + 17;
	SetConsoleTextAttribute(hout, 0 * 16 + 7);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (result[i][j]) {  
				SetConsoleTextAttribute(hout, 0 * 16 + 7);
				cout << "  ";
			    }
			else {
				SetConsoleTextAttribute(hout, 7 * 16 + 7);
				cout << "  ";
			    }
		    }
		SetConsoleTextAttribute(hout, 7 * 16 + 7);
		cout << "  " << endl;
	    }
	for (int i = 0; i < size; i++)
		cout << "  ";
	cout << "  " << endl;
	getchar();
	getchar();
	getchar();
	system("pause");
	return 0;
}
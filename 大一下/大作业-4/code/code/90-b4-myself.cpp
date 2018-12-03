/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include "cmd_console_tools.h"
#include "90-b4.h"

using namespace std;

int encode(const char *const s, const int len, bool(*QRcode)[MAX_MODULESIZE])
{
	bool is_digit = check_str(s, len);
	int ver = get_encode_version(len, is_digit);
	if (ver == -1)
		return -1;

	unsigned char data[MAX_DATACODEWORD];
	int databit;
	encode_data(ver, s, len, data, databit);
	extend_data(ver, data, databit);

	unsigned char code[MAX_ALLCODEWORD];
	recode(ver, data, code);
	ECcode_append(ver, data, code);

	unsigned char Orgin_QR[MAX_MODULESIZE][MAX_MODULESIZE];
	memset(Orgin_QR, 0, sizeof(Orgin_QR));
	Function_Part(ver, Orgin_QR); Version_Info(ver, Orgin_QR);
	Data_Part(ver, code, Orgin_QR);
	Msk_Part(ver, Orgin_QR);
	Version_Info(ver, Orgin_QR);

	const int margin = ver * 4 + 17;
	sFor(i, 0, margin) sFor(j, 0, margin)
		QRcode[i][j] = Orgin_QR[i][j] & 1;
		
	return ver;
}

bool check_str(const char *const s, const int len)
{
	For(i, 1, len)
		if (!(s[i] >= '0' && s[i] <= '9'))
			return 0;
	return 1;
}

int get_encode_version(const int len,const bool is_digit)
{
	int Nbit = is_digit ? calc_digit(len) : calc_ascii(len);
	int l = 1, r = 40;
	while (l != r)
	{
		int mid = (l + r) >> 1;
		int Maxbit = calc_bit(mid);
		Maxbit < Nbit ? l = mid + 1 : r = mid;
	}
	return l > 40 ? -1 : l;
}
int calc_digit(const int len)
{
	int Div = len / 3, Mod = len % 3;
	int res = Div * 10 + 3 * Mod + (Mod != 0);
	return res + (len <= 1425 ? (len <= 235 ? 14 : 16) : 18);
}
int calc_ascii(const int len)
{
	return 8 * len + (len <= 98 ? 12 : 50);
}
int calc_bit(const int ver)
{
	int formbit = ver <= 6 ? 31 : 67;
	int funbit = ver == 1 ? 202 : (int)(180 + 25 * pos_bit(ver) + 2 * (4 * ver + 17) - 10 * sqrt(3 + pos_bit(ver)));
	int databit = (4 * ver + 17)*(4 * ver + 17) - formbit - funbit;
	return (databit - (QR_VersonInfo[ver].ncAllCodeWord - QR_VersonInfo[ver].ncDataCodeWord[3]) * 8) / 8 * 8;
}
int pos_bit(const int ver)
{
	if (ver == 1) 
		return 0;
	if (ver>1 && ver <= 6) 
		return 1;
	if (ver>6 && ver <= 13) 
		return 6;
	if (ver>13 && ver <= 20) 
		return 13;
	if (ver>20 && ver <= 27) 
		return 22;
	if (ver>27 && ver <= 34) 
		return 33;
	// ver>34 && ver <= 40
	return 46;
}

void encode_data(const int ver, const char *const s, const int len, unsigned char *data, int &databit)
{
	int Group = ver >= 27 ? 2 : (ver >= 10 ? 1 : 0);
	For(i, Group, 2)
	{
		if (!EncodeSourceData(s + 1, len, i, data, databit)) /////s+1 !!! std下标从0开始
			continue;
		if (!i)
		{
			For(j, 1, 9)
				if ((databit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[QR_LEVEL_H])
					return;
		}
		else if (i == 1)
		{
			For(j, 10, 26)
				if ((databit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[QR_LEVEL_H])
					return;
		}
		else //i == 2
		{
			For(j, 27, 40)
				if ((databit + 7) / 8 <= QR_VersonInfo[j].ncDataCodeWord[QR_LEVEL_H])
					return;
		}
		/////////else if 位置注意！！！大括号不可省！！！r
	}
}
void extend_data(const int ver, unsigned char *data, int &databit)
{
	int infobit = QR_VersonInfo[ver].ncDataCodeWord[QR_LEVEL_H];
	int zerobit=8*infobit-databit>4?4:infobit-databit;
	if (zerobit > 0)
		databit += zerobit;

	const unsigned char extendbit[2] = { 0xec,0x11 };
	int pre = 0;
	sFor(i, (databit + 7) / 8, infobit)
		data[i] = extendbit[pre],pre ^= 1;
}

void recode(const int ver, const unsigned char *const data, unsigned char *code)
{
	int codebit= QR_VersonInfo[ver].ncAllCodeWord;
	memset(code, 0, codebit);

	int Block1bit = QR_VersonInfo[ver].RS_BlockInfo1[QR_LEVEL_H].ncRSBlock;
	int Block2bit = QR_VersonInfo[ver].RS_BlockInfo2[QR_LEVEL_H].ncRSBlock;
	int Blockbit = Block1bit + Block2bit;

	int data1bit = QR_VersonInfo[ver].RS_BlockInfo1[QR_LEVEL_H].ncDataCodeWord;
	int data2bit = QR_VersonInfo[ver].RS_BlockInfo2[QR_LEVEL_H].ncDataCodeWord;

	int pdata = 0, pcode = 0;
	sFor(i, 0, Block1bit)
	{
		sFor(j, 0, data1bit)
			code[j*Blockbit + pcode] = data[pdata++];
		++pcode;
	}
	sFor(i, 0, Block2bit)
	{
		sFor(j, 0, data2bit)
		{
			unsigned char &tcode = code[j < data1bit ? j*Blockbit + pcode : data1bit*Blockbit + i];
			tcode = data[pdata++];
		}
		++pcode;
	}
}

void ECcode_append(const int ver, const unsigned char *const data, unsigned char *code)
{
	int Block1bit = QR_VersonInfo[ver].RS_BlockInfo1[QR_LEVEL_H].ncRSBlock;
	int Block2bit = QR_VersonInfo[ver].RS_BlockInfo2[QR_LEVEL_H].ncRSBlock;
	int Blockbit = Block1bit + Block2bit;

	int databit = QR_VersonInfo[ver].ncDataCodeWord[QR_LEVEL_H];
	int data1bit = QR_VersonInfo[ver].RS_BlockInfo1[QR_LEVEL_H].ncDataCodeWord;
	int poly1bit = QR_VersonInfo[ver].RS_BlockInfo1[QR_LEVEL_H].ncAllCodeWord - data1bit;
	int data2bit = QR_VersonInfo[ver].RS_BlockInfo2[QR_LEVEL_H].ncDataCodeWord;
	int poly2bit = QR_VersonInfo[ver].RS_BlockInfo2[QR_LEVEL_H].ncAllCodeWord - data2bit;

	int pdata = 0, pcode = 0;
	sFor(i, 0, Block1bit)
	{
		int tail = 0;
		unsigned char MsgPoly[2 * MAX_CODEBLOCK];
		memset(MsgPoly, 0, sizeof(MsgPoly));
		memcpy(MsgPoly, data + pdata, data1bit);
		encode_ECcode(MsgPoly, tail, data1bit, poly1bit);

		sFor(j, 0, poly1bit)
			code[j*Blockbit + databit + pcode] = MsgPoly[tail + j];
		pdata += data1bit;
		++pcode;
	}
	sFor(i, 0, Block2bit)
	{
		int tail = 0;
		unsigned char MsgPoly[2 * MAX_CODEBLOCK];
		memset(MsgPoly, 0, sizeof(MsgPoly));
		memcpy(MsgPoly, data + pdata, data2bit);
		encode_ECcode(MsgPoly, tail, data2bit, poly2bit);

		sFor(j, 0, poly2bit)
			code[j*Blockbit + databit + pcode] = MsgPoly[tail + j];
		pdata += data2bit;
		++pcode;
	}
}
void encode_ECcode(unsigned char*Msg, int &tail, const int Msgbit, const int polybit)
{
	int *poly = new(nothrow) int[polybit];
	if (poly == NULL)
	{
		printf("No Free Memory\n");
		exit(-1);
	}
	sFor(i, 0, polybit)
		poly[i] = byRSExp[polybit][i];
	sFor(i, 0, Msgbit)
	{
		int cur = tail++;
		if (!Msg[cur])
			continue;
		unsigned char cur_exp = byIntToExp[Msg[cur]];
		For(j, cur + 1, polybit + cur)
		{
			unsigned char texp = (unsigned char)((poly[j - cur - 1] + cur_exp)%255);
			Msg[j] ^= byExpToInt[texp];
		}
	}
	delete[]poly;
}

void Function_Part(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	Finder_Patterns(ver, QR);
	Seperator(ver, QR);
	Alignment_Patterns(ver, QR);
	Timing_Patterns(ver, QR);
	Dark_Module_And_Retain(ver, QR);
}
void Finder_Patterns(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	const bool base_pattern[Finder_MARGIN][Finder_MARGIN] =
	{
		{ 1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,1 },
		{ 1,0,1,1,1,0,1 },
		{ 1,0,1,1,1,0,1 },
		{ 1,0,1,1,1,0,1 },
		{ 1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1 }
	};

	sFor(i, 0, Finder_MARGIN) sFor(j, 0, Finder_MARGIN)
		QR[i][j] = QR[i][margin - 7 + j] = QR[margin - 7 + i][j] = base_pattern[i][j] ? fun_Black : fun_White;
}
void Seperator(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	For(j, 0, 7)
		QR[7][j] = QR[7][margin - 8 + j] = QR[margin - 8][j] = fun_White;
	For(i, 0, 7)
		QR[i][7] = QR[i][margin - 8] = QR[margin - 8 + i][7] = fun_White;
	QR[7][7] = QR[margin - 7][7] = QR[7][margin - 7] = fun_White;
}
void Alignment_Patterns(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	int cnt = QR_VersonInfo[ver].ncAlignPoint;
	sFor(i, 0, cnt)
	{
		sFor(j, 0, cnt)
			add_AlPattern(QR, QR_VersonInfo[ver].nAlignPoint[i], QR_VersonInfo[ver].nAlignPoint[j]);
		add_AlPattern(QR, QR_VersonInfo[ver].nAlignPoint[i], Alignment_Common);
		add_AlPattern(QR, Alignment_Common, QR_VersonInfo[ver].nAlignPoint[i]);
	}
}
void add_AlPattern(unsigned char(*QR)[MAX_MODULESIZE], const int x, const int y)
{
	const bool base_pattern[Alignment_MARGIN][Alignment_MARGIN] =
	{
		{ 1,1,1,1,1 },
		{ 1,0,0,0,1 },
		{ 1,0,1,0,1 },
		{ 1,0,0,0,1 },
		{ 1,1,1,1,1 }
	};
	if (QR[x][y])
		return;
	For(i, -2, 2) For(j, -2, 2)
		QR[x + i][y + j] = base_pattern[i + 2][j + 2] ? fun_Black : fun_White;
}
void Timing_Patterns(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	For(k, 8, margin - 9)
		QR[k][6] = QR[6][k] = k & 1 ? fun_White : fun_Black;
}
void Dark_Module_And_Retain(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	QR[margin - 8][8] = fun_Black;
	QR[8][8] = Retain;
	For(j, 0, 7)
		QR[8][j] = QR[8][margin - 8 + j] = Retain;
	For(i, 0, 7)
		QR[i][8] = QR[margin - 8 + i][8] = Retain;
	QR[6][8] = QR[8][6] = fun_Black; //Timing Pattern
	if (ver <= 6)
		return;
	For(i, margin - 11, margin - 9) For(j, 0, 5)
		QR[i][j] = Retain;
	For(i, 0, 5) For(j, margin - 11, margin - 9)
		QR[i][j] = Retain;
}

void Data_Part(const int ver, const unsigned char *const code, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	int x = margin, y = margin - 1;
	int deltax = 1, deltay = 1;
	int totbit = QR_VersonInfo[ver].ncAllCodeWord;
	sFor(i, 0, totbit) opFor(j, 7, 0)
	{
		do
		{
			x += deltax;
			deltax = -deltax;
			if (deltax < 0)
			{
				y += deltay;
				if (y < 0 || y == margin)
				{
					y = y < 0 ? 0 : margin - 1;
					deltay = -deltay;
					x -= 2;

					if (x == 6) //*****Timing Pattern
						--x;
				}
			}
		} while (QR[x][y]);
		
		//printf("%d %d %d\n", x, y, code[i] & (1 << j));
		QR[x][y] = (code[i] & (1 << j)) ? data_Black : data_White;
	}
}

void Msk_Part(const int ver, unsigned char(*QR)[MAX_MODULESIZE])
{
	unsigned char mskcode[MAX_MODULESIZE][MAX_MODULESIZE];
	unsigned char best[MAX_MODULESIZE][MAX_MODULESIZE];
	int lowest_score = 19980413;
	int tmp = 0;

	For(i, 0, 7)
	{
		memcpy(mskcode, QR, sizeof(mskcode)); //QR是指针啊！！！！！！！！

		add_msk(ver, i, mskcode);
		Format_Info(ver, i, mskcode);

		int cur_score = Evaluate_Msk(ver, mskcode);
		if (cur_score >= lowest_score)
			continue;
		lowest_score = cur_score;
		tmp = i;
		memcpy(best, mskcode, sizeof(mskcode));//QR不能直接修改 原版还要用
	}
	memcpy(QR, best, sizeof(best));
}
void add_msk(const int ver, const int msk_id, unsigned char(*QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	sFor(i, 0, margin) sFor(j, 0, margin)
	{
		if (!(QR[i][j] >> 3))
			continue;
		if (trans_msk(msk_id, j, i))
			continue;
		QR[i][j] ^= 1;
	}
}
int trans_msk(const int msk_id, const int x, const int y)
{
	switch (msk_id)
	{
	case 0:
		return (x + y) & 1;
	case 1:
		return x & 1;
	case 2:
		return y % 3;
	case 3:
		return (x + y) % 3;
	case 4:
		return (x / 2 + y / 3) & 1;
	case 5:
		return (x*y & 1) + (x*y % 3);
	case 6:
		return ((x*y & 1) + (x*y % 3)) & 1; //先计算运算再位运算！！
	default: //case 7:
		return ((x + y & 1) + (x*y % 3)) & 1;
	}
}
int Evaluate_Msk(const int ver, const unsigned char (*const QR)[MAX_MODULESIZE])
{
	int margin = ver * 4 + 17;
	int score = 0;
	//Condition 1
	sFor(i, 0, margin) for (int j = 0; j < margin - 4;)
	{
		int same = 1,k;
		for (k = j + 1; k < margin; ++k)
			if ((QR[i][j] & 1) == (QR[i][k] & 1))
				++same;
			else
				break;
		if (same >= 5)
			score += same - 2;
		j = k;
	}
	sFor(j, 0, margin) for (int i = 0; i < margin - 4;)
	{
		int cnt = 1, k;
		for (k = i + 1; k < margin; ++k)
			if ((QR[i][j] & 1) == (QR[k][j] & 1))
				++cnt;
			else
				break;
		if (cnt >= 5)
			score += cnt - 2;
		i = k;
	}
	//Condition 2
	sFor(i, 0, margin - 1) sFor(j, 0, margin - 1)
		if (((QR[i][j] & 1) == (QR[i][j + 1] & 1)) 
			&& ((QR[i][j] & 1) == (QR[i + 1][j] & 1)) 
			&& ((QR[i][j] & 1) == (QR[i + 1][j + 1] & 1)))
			score += 3;
	//Condition 3
	const int cond[2][11] = { {1,0,1,1,1,0,1,0,0,0,0},{0,0,0,0,1,0,1,1,1,0,1} };
	sFor(i, 0, margin) sFor(j, 0, margin - 10)
	{
		bool succ = 1;
		For(op, 0, 1) For(k, 0, 10)
			if ((QR[i][j + k] & 1) != cond[op][k])
			{
				succ = 0;
				break;
			}
		score += 40 * succ;
	}
	sFor(i, 0, margin - 10) sFor(j, 0, margin)
	{
		bool succ = 1;
		For(op, 0, 1) For(k, 0, 10)
			if ((QR[i + k][j] & 1) != cond[op][k])
			{
				succ = 0;
				break;
			}
		score += 40 * succ;
	}
	//Condition 4
	int cnt = 0;
	sFor(i, 0, margin) sFor(j, 0, margin)
		cnt += QR[i][j] & 1;
	int per = int(100.0*cnt / (margin*margin));
	int A = (per / 5) * 5;
	int B = (per / 5 + 1) * 5;
	int dA = abs(A - 50) / 5;
	int dB = abs(B - 50) / 5;
	score += Min(dA, dB) * 10;

	return score;
}

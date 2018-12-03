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
#include<io.h>
#include<Windows.h>
#include "cmd_console_tools.h"
#include "90-b3.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

using namespace std;

void setfont()
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = 1;
	info.dwFontSize.Y = 1;
	info.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hout, NULL, &info);
	setconsoleborder(hout, 600, 180);
}

void get_alarm_ini(Alarm *&head)
{
	fstream ini(iniFile, ios::in);
	if (!ini.is_open())
	{
		ini.open(iniFile, ios::out | ios::_Noreplace | ios::binary);
		ini.close();
	}
	ini.open(iniFile, ios::in | ios::binary);

	head = new(nothrow) Alarm;
	if (head == NULL)
	{
		printf("Alarm setting Error\n");
		exit(-1);
	}
	head->pre = head->nxt = head;
	head->h = head->m = head->mode = 0;
	ini.clear();
	ini.seekg(0, ios::beg);
	while (1)
	{
		ini.peek();
		if (ini.eof())
			break;
		Alarm *New = new(nothrow) Alarm;
		if (New == NULL)
		{
			printf("Alarm setting Error\n");
			exit(-1);
		}
		ini.read((char*)&New->h, IntSize)
			.read((char*)&New->m, IntSize)
			.read((char*)&New->mode, IntSize);
		head->nxt->pre = New;
		New->nxt = head->nxt;
		New->pre = head;
		head->nxt = New;
	}
	ini.close();
}
void refresh_ini(Alarm *head)
{
	ofstream ini(iniFile, ios::out | ios::trunc | ios::binary);
	Alarm *cur = head;
	while ((cur = cur->nxt) != head)
		ini.write((char*)&cur->h, IntSize)
		.write((char*)&cur->m, IntSize)
		.write((char*)&cur->mode, IntSize);

	ini.close();
}

int get_key(const HANDLE hin, int time_limit)
{
	INPUT_RECORD    mouseRec;
	DWORD           res;
	DWORD			bg = GetTickCount();

	while (1)
	{
		while (!_kbhit())
		{
			if (GetTickCount() - bg < (unsigned)time_limit)
				continue;
			return TLE;
		}
		ReadConsoleInput(hin, &mouseRec, 1, &res);
		if (mouseRec.EventType != MOUSE_EVENT)
			if (mouseRec.EventType == KEY_EVENT && mouseRec.Event.KeyEvent.bKeyDown
				&& (mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_BACK
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_DELETE
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_RETURN
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_UP
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_DOWN
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_LEFT
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_F1
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_F2))
				return mouseRec.Event.KeyEvent.wVirtualKeyCode;
	}
	return MOUSE_NO_ACTION;
}

bool check_time(Alarm *const al, const int w, const int h, const int m)
{
	bool f[8] = { 0 };
	if (!al->mode || al->mode == 8)
		f[1] = f[2] = f[3] = f[4] = f[5] = f[6] = f[7] = 1;
	else if (al->mode == 9)
		f[1] = f[2] = f[3] = f[4] = f[5] = 1;
	else if (al->mode == 10)
		f[6] = f[7] = 1;
	else
		f[al->mode] = 1;

	return f[w] == 1 && al->h == h && al->m == m;
}
void Alarm_Clock_Rang()
{
	system("cls");
	gotoxy(hout, 190, 25);
	output_str((unsigned char *)"闹钟设定时间到", Normal);
	gotoxy(hout, 10, 70);
	output_str((unsigned char *)"按回车键关闭闹钟", LED);

	bool Music_Playing = 0;
	long Handle;
	_finddata_t MusicFile;
	if ((Handle = _findfirst(".\\1652228\\*.wav", &MusicFile)) == -1L)
	{
		gotoxy(hout, 10, 130);
		output_str((unsigned char *)"没有找到音频文件", Abnormal);
	}
	else
	{
		Music_Playing = 1;
		char addr[100] = { ".\\1652228\\" };
		strcat(addr, MusicFile.name);
		WCHAR MusicAddress[MAX_PATH] = { 0 };
		MultiByteToWideChar(CP_ACP, 0, addr, -1, MusicAddress, sizeof(MusicAddress));
		PlaySound(MusicAddress, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	while (_getch() != '\r');
	if (Music_Playing)
		PlaySound(NULL, NULL, NULL);
}

void output_str(const unsigned char *str,const int mode)
{
	if (str[0] == '\0')
		return;
	for (int i = 0; str[i] != '\0'; i += 2) 
	{
		unsigned char word[3] = { str[i] ,str[i + 1],'\0' };
		output_ch(word, mode);
	}
}
void output_dig(int d, const int mode)
{
	int d1 = d / 10, d2 = d % 10;
	output_ch((unsigned char *)Dig[d1], mode);
	output_ch((unsigned char *)Dig[d2], mode);
}
int output_ch(const unsigned char word[],const int mode)
{
	ifstream GB_file("hzk16", ios::in);
	if (!GB_file.is_open()) 
	{
		printf("缺少汉字库文件\n");
		exit(-1);
	}

	const unsigned char base[8] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };
	int st = (94 * (unsigned int)(word[0] - 0xa0 - 1) + (word[1] - 0xa0 - 1)) * 32;
	GB_file.seekg(st, ios::beg);
	unsigned char  character[32] = { 0 };
	GB_file.read((char*)character, 32);

	int x, y;
	setcolor(hout, 0, 7);
	sFor(k, 0, 16)
	{
		sFor(j, 0, 2) sFor(i, 0, 8)
		{
			int dot = base[i] & character[2 * k + j];
			if (mode == Normal)
			{
				setcolor(hout, dot ? 7 : 0, 0);
				printf("  ");
				setcolor(hout, 0, 7);
			}
			else if (mode == LED)
				printf(dot ? "* " : "  ");
			else 
			{
				setcolor(hout, dot ? 0 : 7, 0);
				printf("  ");
				setcolor(hout, 0, 7);
			}
		}
		getxy(hout, x, y);
		gotoxy(hout, x - 32, y + 1);
	}
	getxy(hout, x, y);
	gotoxy(hout, x + 32, y - 16);

	GB_file.close();
	return 0;
}

void Draw_Circle(const Point O)
{
	const int R = 40;
	const int R2 = R*R;
	const int low = O.x - 2 * R, high = O.x + 2 * R;
	const int _low = O.y - R, _high = O.y + R;

	setcolor(hout, 7, 0);

	For(x, low, high)
	{
		int min_dis = R2, dis;
		For(y, _low - 1, _high + 1)
			if ((dis = abs((x - O.x)*(x - O.x) / 4 + (y - O.y)*(y - O.y) - R2)) < min_dis)
				min_dis = dis;
		For(y, _low - 1, _high + 1)
			if (abs((x - O.x)*(x - O.x) / 4 + (y - O.y)*(y - O.y) - R2) == min_dis)
			{
				gotoxy(hout, x, y);
				printf(" ");
			}
	}
	For(y, _low, _high)
	{
		int min_dis = R2, dis;
		For(x, low - 1, high + 1)
			if ((dis = abs((x - O.x)*(x - O.x) / 4 + (y - O.y)*(y - O.y) - R2)) < min_dis)
				min_dis = dis;
		For(x, low - 1, high + 1)
			if (abs((x - O.x)*(x - O.x) / 4 + (y - O.y)*(y - O.y) - R2) == min_dis)
			{
				gotoxy(hout, x, y);
				printf(" ");
			}
	}

	setcolor(hout, 0, 7);
	gotoxy(hout, O.x, O.y);
}
void Draw_Hand(const Point O, Point last[3][N], double ang, int op)
{
	int len = op ? (op == 2 ? Second : Minute) : Hour;
	setcolor(hout, 0, 7);
	sFor(i, 0, N)
	{
		if (!last[op][i].x && !last[op][i].y)
			break;
		gotoxy(hout, last[op][i].x, last[op][i].y);
		printf(" ");
		last[op][i].x = last[op][i].y = 0;
	}

	int dx = (ang >= -pi / 2 && ang <= pi / 2) ? 1 : -1;
	int dy = ang > 0 ? -1 : 1;
	int cnt = 0;
	setcolor(hout, 7, 0);
	if (fabs(ang - pi / 2) < eps || fabs(ang + pi / 2) < eps)
	{
		for (int y = O.y; abs(y - O.y) <= len; y += dy)
		{
			gotoxy(hout, O.x, y);
			printf(" ");
			last[op][cnt++] = { O.x,y };
		}
	}
	else
	{
		double k = tan(ang);
		int preY = O.y; // avoid draw up and down
		double limit_x = fabs(2 * len*cos(ang))+1;
		for (int x = O.x; 1.0*abs(x - O.x) < limit_x; x += dx)
		{
			int minY;
			double min_delta = len;
			double limit_y = fabs(k*(x - O.x)) + 4;
			for (int y = O.y; 1.0*abs(y - O.y) < limit_y; y += dy)
			{
				double delta;
				if ((delta = fabs(fabs(k*(x - O.x) / 2) - fabs(y - O.y))) < min_delta)
					min_delta = delta, minY = y;
			}

			bool overflow = 0;
			if ((x - O.x)*(x - O.x) / 4 + (minY - O.y)*(minY - O.y) >= len*len)
				minY = O.y + (int)sqrt(len*len - (x - O.x)*(x - O.x) / 4)*dy, overflow = 1;
			if ((minY - preY)*dy < 0)
				break;

			gotoxy(hout, x, minY);
			printf(" ");
			last[op][cnt++] = { x,minY };
			if(abs(minY-preY)>1)
				for (int y = preY; abs(y - preY) <= abs(minY - preY); y += dy)
				{
					gotoxy(hout, x, y);
					printf(" ");
					last[op][cnt++] = { x,y };
				}

			if (overflow)
				break;
			preY = minY;
		}
	}
	setcolor(hout, 0, 7);
	gotoxy(hout, O.x, O.y);
}

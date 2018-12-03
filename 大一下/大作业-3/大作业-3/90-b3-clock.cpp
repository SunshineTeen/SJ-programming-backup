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
#include "90-b3.h"

using namespace std;

void clock_work(Alarm *head, int &option, int &mode)
{
	system("cls");

	int time_zone = 8;
	Point last_P[3][N] = { { 0,0 } };
	const Point O = { 100,50 };
	static DWORD pre_time = 0;

	bool fst = 1;
	bool setting_change = 0;
	bool day_change = 0;
	while (1)
	{
		mode == Mechanical ?
			output_mechanical_clock(O, last_P, time_zone, day_change) :
			output_digital_clock(time_zone, day_change);
		if (fst || setting_change)
		{
			mode == Mechanical ?
				output_help(Mechanical_Y) :
				output_help(Digital_Y);

			int Y = mode == Mechanical ? Mechanical_zone_Y : Digital_zone_Y;
			output_time_zone(Y, time_zone);
			int X = mode == Mechanical ? 200 : 10;
			Y = mode == Mechanical ? 10 : 3;
			output_day_info(mode, time_zone, X, Y);
			fst = setting_change = day_change = 0;
		}
		else if (day_change)
		{
			int X = mode == Mechanical ? 200 : 10;
			int Y = mode == Mechanical ? 10 : 3;
			output_day_info(mode, time_zone, X, Y);
			day_change = 0;
		}

		if (GetTickCount()-pre_time>60000 && check_alarm(head, time_zone))
		{
			pre_time = GetTickCount();
			setting_change = 1;
			continue;
		}

		int key = get_key(hin);
		if (key == TLE || key == MOUSE_NO_ACTION)
			continue;
		if (key == VK_F1)
		{
			setting_change = 1;
			mode ^= 1;
			system("cls");
			continue;
		}
		if (key == VK_F2)
		{
			option ^= 1;
			return;
		}
		if (key == VK_UP || key == VK_DOWN)
		{
			setting_change = 1;
			time_zone += key == VK_UP ? -1 : 1;
			if (time_zone < 0)
				time_zone = 23;
			if (time_zone > 23)
				time_zone = 0;
			system("cls");
			continue;
		}
	}
}

bool check_alarm(Alarm *head, const int time_zone)
{
	int delta = time_zone - base_zone;
	time_t cur_sec = int(time(0)) + delta * 3600;
	if (time_zone > 12)
		cur_sec -= 24 * 3600;
	tm *cur_time = localtime(&cur_sec);
	int w = cur_time->tm_wday;
	int h = int(cur_time->tm_hour);
	int m = int(cur_time->tm_min);
	if (!w)
		w = 7;

	Alarm *cur = head;
	while ((cur = cur->nxt) != head)
	{
		if (check_time(cur, w, h, m))
		{
			if (!cur->mode)
			{
				cur->pre->nxt = cur->nxt;
				cur->nxt->pre = cur->pre;
				delete cur;
				refresh_ini(head);
			}
			Alarm_Clock_Rang();
			system("cls");
			return 1;
		}
	}
	return 0;
}

void output_mechanical_clock(const Point O, Point last[3][N], const int time_zone, bool &day_change)
{
	int delta = time_zone - base_zone;
	time_t cur_sec = int(time(0)) + delta * 3600;
	tm *cur_time = localtime(&cur_sec);
	int h = int(cur_time->tm_hour);
	if (h >= 12)
		h -= 12;
	int m = int(cur_time->tm_min);
	int s = int(cur_time->tm_sec);
	static int pre_day = 0;
	if (!pre_day)
		pre_day = cur_time->tm_yday;
	else if (pre_day != (cur_time->tm_yday))
		day_change = 1, pre_day = cur_time->tm_yday;

	double sec_ang = 2 * pi*1.0*s / 60;
	double min_ang = 2 * pi*1.0*m / 60;
	double hour_ang = 2 * pi*1.0*h / 12 + min_ang / 12;
	sec_ang = pi / 2 - sec_ang;
	min_ang = pi / 2 - min_ang;
	hour_ang = pi / 2 - hour_ang;
	if (sec_ang <= -pi)
		sec_ang += 2 * pi;
	if (min_ang <= -pi)
		min_ang += 2 * pi;
	if (hour_ang <= -pi)
		hour_ang += 2 * pi;

	Draw_Circle(O);
	Draw_Hand(O, last, sec_ang, 2);
	Draw_Hand(O, last, min_ang, 1);
	Draw_Hand(O, last, hour_ang, 0);
}
void output_digital_clock(const int time_zone, bool &day_change)
{
	int delta = time_zone - base_zone;
	time_t cur_sec = int(time(0)) + delta * 3600;
	tm *cur_time = localtime(&cur_sec);
	int h = int(cur_time->tm_hour);
	int m = int(cur_time->tm_min);
	int s = int(cur_time->tm_sec);
	static int pre_day = 0;
	if (!pre_day)
		pre_day = cur_time->tm_yday;
	else if (pre_day != (cur_time->tm_yday))
		day_change = 1, pre_day = cur_time->tm_yday;

	const int X = 0;
	const int Y = 65;
	gotoxy(hout, X, Y);

	output_dig(h, Normal);
	output_ch((unsigned char *)"：", Normal);
	output_dig(m, Normal);
	output_ch((unsigned char *)"：", Normal);
	output_dig(s, Normal);
}
void output_help(const int Y)
{
	gotoxy(hout, 0, Y + 1);
	output_str((unsigned char *)"按↑↓键改变时区", LED);
	gotoxy(hout, 0, Y + 17);
	output_str((unsigned char *)"按Ｆ１键切换至数字式", LED);
	gotoxy(hout, 0, Y + 33);
	output_str((unsigned char *)"按Ｆ２切换至闹钟设定", LED);
}
void output_time_zone(const int Y, const int zone)
{
	const int X = 3;
	setcolor(hout, 0, 0);
	For(j, 0, 16)
	{
		gotoxy(hout, X, Y + j);
		For(i, 1, 16 * 12)
			printf(" ");
	}
	gotoxy(hout, X, Y);

	output_str((unsigned char *)Zone[zone], Normal);
	setcolor(hout, 0, 7);
}
void output_day_info(const int mode, const int time_zone, const int X, const int Y)
{
	int delta = time_zone - base_zone;
	time_t cur_sec = int(time(0)) + delta * 3600;
	if (time_zone > 12)
		cur_sec -= 24 * 3600;
	tm *cur_time = localtime(&cur_sec);
	int y = 1900 + cur_time->tm_year;
	int m = 1 + cur_time->tm_mon;
	int d = cur_time->tm_mday;
	int w = cur_time->tm_wday;

	gotoxy(hout, X, Y);
	output_dig(y / 100, Normal), output_dig(y % 100, Normal), output_str((unsigned char*)"年", Normal);
	gotoxy(hout, X, Y + 20);
	output_dig(m, Normal), output_str((unsigned char*)"月", Normal), output_dig(d, Normal), output_str((unsigned char *)"日", Normal);
	gotoxy(hout, X, Y + 40);
	output_str((unsigned char*)Week[w], Normal);
}

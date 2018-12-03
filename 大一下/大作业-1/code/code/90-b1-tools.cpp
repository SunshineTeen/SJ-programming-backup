/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include "cmd_console_tools.h"
#include "90-b1.h"

using namespace std;


bool init_mode(int &mode)
{
	printf("[请选择0-9]:");
	if (!scanf(" %d", &mode))
		mode = -1;
	FFLUSH;
	if (mode < 0 || mode>9)
		return 0;
	return 1;
}
void init(int &n, int &m)
{
	setconsoleborder(hout, 80, 50);
	while (1)
	{
		printf("请输入行数(5-9):");
		if (!scanf(" %d", &n))
			n = 4;
		FFLUSH;
		if (n < 5 || n>9)
		{
			gotoxy(hout, 0, 0);
			For(i, 1, 80)
				printf(" ");
			gotoxy(hout, 0, 0);
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入列数(5-9):");
		if (!scanf(" %d", &m))
			m = 4;
		FFLUSH;
		if (m < 5 || m>9)
		{
			gotoxy(hout, 0, 1);
			For(i, 1, 80)
				printf(" ");
			gotoxy(hout, 0, 1);
			continue;
		}
		break;
	}
}

char alpha_upper(const char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 32;
	return ch;
}
void End()
{
	char op[1024] = "LoveTaihouForever";
	setcolor(hout, 0, 7);
	printf("本小题结束，请输入End继续...\n");
	while (1)
	{
		int p = 0;
		while ((op[++p] = getchar()) != '\n');
		if (alpha_upper(op[1]) != 'E' || alpha_upper(op[2]) != 'N' || alpha_upper(op[3]) != 'D')
		{
			printf("输入错误\n");
			continue;
		}
		return;
	}
}

void reset(int(*map)[Maxm], const int n, const int m)
{
	For(i, 1, n)
		For(j, 1, m)
		map[i][j] = 0;
	For(i, 0, n + 1)
		map[i][0] = map[i][m + 1] = -1;
	For(j, 0, m + 1)
		map[0][j] = map[n + 1][j] = -1;
}
void reset_map(int(*map)[Maxm], const int n, const int m)
{
	For(i, 1, n) For(j, 1, m)
		map[i][j] = rand() % Maxc + 1;
}

//check if somewhere can be eliminate
bool check(int(*map)[Maxm], const int n, const int m, bool(*del)[Maxm])
{
	bool res = 0;
	For(i, 1, n) For(j, 1, m)
		del[i][j] = 0;
	For(i, 1, n) For(j, 1, m)
	{
		if (map[i][j] == map[i][j + 1] && map[i][j + 1] == map[i][j + 2])
		{
			res = 1;
			del[i][j] = del[i][j + 1] = del[i][j + 2] = 1;
			int tj = j + 3;
			while (map[i][tj] == map[i][j])
			{
				del[i][tj] = 1;
				++tj;
			}
		}
		if (map[i][j] == map[i + 1][j] && map[i + 1][j] == map[i + 2][j])
		{
			res = 1;
			del[i][j] = del[i + 1][j] = del[i + 2][j] = 1;
			int ti = i + 3;
			while (map[ti][j] == map[i][j])
			{
				del[ti][j] = 1;
				++ti;
			}
		}
	}
	return res;
}

void fill_map(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	For(i, 1, n) For(j, 1, m)
	{
		if (!flag[i][j])
			continue;
		map[i][j] = rand() % Maxc + 1;
	}
}

//find somewhere can be swap
bool find(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	For(i, 1, n) For(j, 1, m)
		flag[i][j] = 0;
	For(i, 1, n) For(j, 1, m)
	{
		if (j <= m - 1)
		{
			exchange(map, n, m, { i,j }, { i,j + 2 }, { i,j + 1 }, { i - 1,j + 1 }, { i + 1,j + 1 }, { 0,0 }, flag);
			exchange(map, n, m, { i,j }, { i,j + 1 }, { i,j + 2 }, { i - 1,j + 2 }, { i + 1,j + 2 }, { i,j + 3 }, flag);
			exchange(map, n, m, { i,j }, { i,j + 1 }, { i,j - 1 }, { i - 1,j - 1 }, { i + 1,j - 1 }, { i,j - 2 }, flag);
		}
		if (i <= n - 1)
		{
			exchange(map, n, m, { i,j }, { i + 2,j }, { i + 1,j }, { i + 1,j - 1 }, { i + 1,j + 1 }, { 0,0 }, flag);
			exchange(map, n, m, { i,j }, { i + 1,j }, { i + 2,j }, { i + 2,j - 1 }, { i + 2,j + 1 }, { i + 3,j }, flag);
			exchange(map, n, m, { i,j }, { i + 1,j }, { i - 1,j }, { i - 1,j - 1 }, { i - 1,j + 1 }, { i - 2,j }, flag);
		}
	}
	For(i, 1, n) For(j, 1, n)
		if (flag[i][j])
			return 1;
	return 0;
}
void exchange(int(*map)[Maxm], int n, int m, Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, bool(*flag)[Maxm])
{
	if (map[p1.x][p1.y] != map[p2.x][p2.y])
		return;
	if (p4.x > 0 && p4.x <= n && p4.y > 0 && p4.y <= m && map[p1.x][p1.y] == map[p4.x][p4.y])
		flag[p3.x][p3.y] = flag[p4.x][p4.y] = 1;
	if (p5.x > 0 && p5.x <= n && p5.y > 0 && p5.y <= m && map[p1.x][p1.y] == map[p5.x][p5.y])
		flag[p3.x][p3.y] = flag[p5.x][p5.y] = 1;
	if (p6.x > 0 && p6.x <= n && p6.y > 0 && p6.y <= m && map[p1.x][p1.y] == map[p6.x][p6.y])
		flag[p3.x][p3.y] = flag[p6.x][p6.y] = 1;
}

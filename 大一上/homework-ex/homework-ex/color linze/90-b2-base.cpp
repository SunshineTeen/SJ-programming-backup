/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

void work_1(int(*map)[Maxm], const int n, const int m, int &last)
{
	reset_map(5, map, n, m, last);
	output_array(map, n, m, 0);
}
void work_2(int(*map)[Maxm], const int n, const int m, int &last)
{
	reset_map(n*m * 3 / 5, map, n, m, last);
	output_array(map, n, m, 1);

	int col[4];
	For(i, 1, 3)
		col[i] = rand() % Maxc + 1;
	printf("�������������ɫ�ֱ���%d %d %d\n", col[1], col[2], col[3]);

	int sx, sy, ex, ey;
	init_st(map, n, m, sx, sy);
	init_ed(map, n, m, ex, ey);

	int tox[Maxn][Maxn] = { 0 };
	int toy[Maxn][Maxn] = { 0 };
	if (!bfs(map, sx, sy, ex, ey, tox, toy))
	{
		printf("�޷��ҵ��ƶ�·��\n");
		printf("\n");
		return;
	}
	output_route(map, n, m, sx, sy, ex, ey, tox, toy);
}
void work_3(int(*map)[Maxm], const int n, const int m, int &last)
{
	reset_map(5, map, n, m, last);

	bool flag = 1;
	int col[4], tot = 0;
	int sum_del[8] = { 0 };
	do
	{
		output_array(map, n, m, 1);
		if (flag)
		{
			For(i, 1, 3)
				col[i] = rand() % Maxc + 1;
		}
		printf("�������������ɫ�ֱ���%d %d %d\n", col[1], col[2], col[3]);

		int sx, sy, ex, ey;
		init_st(map, n, m, sx, sy);
		init_ed(map, n, m, ex, ey);

		int tox[Maxn][Maxn] = { 0 };
		int toy[Maxn][Maxn] = { 0 };
		if (!bfs(map, sx, sy, ex, ey, tox, toy))
		{
			printf("�޷��ҵ��ƶ�·��\n\n");
			flag = 0;
			continue;
		}

		map[ex][ey] = map[sx][sy];
		map[sx][sy] = 0;
		int score = check(map, ex, ey, last, sum_del);
		if (score)
			flag = 0;
		else
		{
			flag = 1;
			int lim = Min(3, last), cnt = 1;
			while (cnt <= lim)
			{
				if (rand_ball(map, n, m, col[cnt], last))
				{
					col[cnt] = rand() % Maxc + 1;
					continue;
				}
				++cnt;
			}
		}
		output_array(map, n, m, 1);
		printf("���ε÷֣�%d �ܵ÷֣�%d\n\n\n", tot += score, score);
	} while (last > 0);
	printf("��Ϸ�������������յ÷�Ϊ��%d\n\n", tot);
}

void output_array(const int(*map)[Maxm], const int n, const int m, const int mode)
{
	printf("\n");
	if (!mode)
		printf("��ʼ����:\n");
	else
		printf("��ǰ����:\n");

	printf("  | ");
	For(j, 1, m)
		printf(" %d ", j);
	printf("\n");
	printf("--+-");
	For(j, 1, m)
		printf("---");
	printf("\n");
	For(i, 1, n)
	{
		printf("%c | ", 'A' + i - 1);
		For(j, 1, m)
		{
			setcolor(hout, 0, 7);
			printf(" ");
			setcolor(hout, map[i][j] ? 14 : 0, fgc[map[i][j]]);
			printf("%d", map[i][j]);
			setcolor(hout, 0, 7);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}
void output_route(int(*map)[Maxm], const int n, const int m, const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm])
{
	bool f[Maxn][Maxm] = { 0 };
	f[sx][sy] = 1;
	int curx = sx, cury = sy;
	while (curx != ex || cury != ey)
	{
		int nxtx = tox[curx][cury], nxty = toy[curx][cury];
		f[nxtx][nxty] = 1;
		curx = nxtx, cury = nxty;
	}
	setconsoleborder(hout, 80, 25);
	output_route_array(n, m, f);
	output_route_col(map, n, m, f);
}
void output_route_array(const int n, const int m, const bool(*f)[Maxm])
{
	printf("����������:\n");
	printf("  | ");
	For(j, 1, m)
		printf(" %d ", j);
	printf("\n");
	printf("--+-");
	For(j, 1, m)
		printf("---");
	printf("\n");
	For(i, 1, n)
	{
		printf("%c | ", 'A' + i - 1);
		For(j, 1, m)
			if (f[i][j])
				printf(" * ");
			else
				printf(" 0 ");
		printf("\n");
	}
	printf("\n\n");
}
void output_route_col(int(*map)[Maxm], const int n, const int m, const bool(*f)[Maxm])
{
	printf("�ƶ�·��(��ͬ��ɫ��ʶ):\n");
	printf("  | ");
	For(j, 1, m)
		printf(" %d ", j);
	printf("\n");
	printf("--+-");
	For(j, 1, m)
		printf("---");
	printf("\n");
	For(i, 1, n)
	{
		printf("%c | ", 'A' + i - 1);
		For(j, 1, m)
		{
			setcolor(hout, 0, 7);
			printf(" ");
			setcolor(hout, f[i][j] ? 14 : 0, f[i][j] ? 9 : 7);
			printf("%d", map[i][j]);
			setcolor(hout, 0, 7);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n\n");
}

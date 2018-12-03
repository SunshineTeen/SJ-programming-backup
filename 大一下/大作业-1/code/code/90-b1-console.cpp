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

void output_cmd_base(int(*map)[Maxm], const int n, const int m)
{
	const int cols = 35;
	const int lines = 20 + 2 * (n - 5);
	const int size = 36 - 4 * (n - 5);
	setconsoleborder(hout, cols, lines);
	setfontsize(hout, L"新宋体", size);
	setcolor(hout, 15, 0);

	printf("╔");
	For(i, 1, m)
		printf("═");
	printf("╗\n");
	For(i, 1, n)
	{
		printf("║");
		For(j, 1, m)
		{
			if (!map[i][j])
			{
				printf("  ");
				continue;
			}
			setcolor(hout, col[map[i][j]], 0);
			cout << "○";
			setcolor(hout, 15, 0);
		}
		printf("║\n");
	}
	printf("╚");
	For(i, 1, m)
		printf("═");
	printf("╝\n");
}

void output_cmd_change(int step, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	char fig[3];
	if (!step)
		strcpy(fig, "  ");
	else if (step == 1)
		strcpy(fig, "★");
	else if (step == 2 || step == 4)
		strcpy(fig, "○");
	else //step==3
		strcpy(fig, "◎");
	For(i, 1, n) For(j, 1, m)
	{
		if (!flag[i][j])
			continue;
		gotoxy(hout, 4 * j - 2, 2 * i);
		setcolor(hout, step ? col[map[i][j]] : 15, step ? 0 : 15);
		printf("%s", fig);
		Sleep(step == 4 ? 0 : 200);
	}
	setcolor(hout, 0, 7);
}
void output_cmd_reset(int(*map)[Maxm], const int n, const int m, const int mode)
{
	const int cols = 35 + 2 * (m - 2);
	const int lines = 20 + 2 * (n - 5);
	const int size = 36 - 4 * (n - 5);
	setconsoleborder(hout, cols, lines);
	setfontsize(hout, L"新宋体", size);

	setcolor(hout, 0, 7);
	gotoxy(hout, 0, 0);
	if (mode == 8)
		printf("(右键-退出)当前总分: 0\n");
	else
		printf("\n");

	setcolor(hout, 15, 0);
	printf("╔");
	For(i, 1, m - 1)
		printf("═╤");
	printf("═╗\n");

	For(i, 1, n - 1)
	{
		printf("║");
		For(j, 1, m - 1)
		{
			if (!map[i][j])
			{
				printf("  │");
				continue;
			}
			setcolor(hout, col[map[i][j]], 0);
			printf("○");
			setcolor(hout, 15, 0);
			printf("│");
		}
		if (!map[i][m])
			printf("  ");
		else
		{
			setcolor(hout, col[map[i][m]], 0);
			printf("○");
			setcolor(hout, 15, 0);
		}
		printf("║\n");

		printf("║");
		For(j, 1, m - 1)
			printf("─┼");
		printf("─╢\n");
	}
	printf("║");
	For(j, 1, m - 1)
	{
		if (!map[n][j])
		{
			printf("  │");
			continue;
		}
		setcolor(hout, col[map[n][j]], 0);
		printf("○");
		setcolor(hout, 15, 0);
		printf("│");
	}
	if (!map[n][m])
		printf("  ");
	else
	{
		setcolor(hout, col[map[n][m]], 0);
		printf("○");
		setcolor(hout, 15, 0);
	}
	printf("║\n");

	printf("╚");
	For(i, 1, m - 1)
		printf("═╧");
	printf("═╝\n");
}
//fall down
void output_cmd_alter(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	opFor(i, n, 1) For(j, 1, m)
	{
		if (!flag[i][j])
			continue;
		int prei = i, curi = i - 1;
		while (curi)
		{
			while (flag[curi][j] && curi)
				--curi;
			if (!curi)
				break;
			int tc = col[map[curi][j]];
			map[prei][j] = map[curi][j];
			flag[prei][j] = 0;
			map[curi][j] = 0;
			flag[curi][j] = 1;
			For(k, curi + 1, prei)
			{
				gotoxy(hout, 4 * j - 2, 2 * (k - 1));
				setcolor(hout, 15, 0);
				printf("  ");
				gotoxy(hout, 4 * j - 2, 2 * (k - 1) + 1);
				setcolor(hout, tc, 0);
				printf("○");
				Sleep(50);
				gotoxy(hout, 4 * j - 2, 2 * (k - 1) + 1);
				setcolor(hout, 15, 0);
				printf("─");
				gotoxy(hout, 4 * j - 2, 2 * k);
				setcolor(hout, tc, 0);
				printf("○");
				Sleep(50);
			}
			--prei;
			--curi;
		}
	}
	setcolor(hout, 0, 7);
}
void output_score(int &tot, const int n, const int m, bool(*flag)[Maxm])
{
	For(i, 1, n) For(j, 1, m)
		if (flag[i][j])
			++tot;
	setcolor(hout, 0, 7);
	gotoxy(hout, 21, 0);
	printf("%d", tot);
}

void cmd_reset(int(*map)[Maxm], const int n, const int m, const int mode)
{
	bool flag[Maxn][Maxm];

	reset_map(map, n, m);
	printf("\n初始数组:\n");
	output_array(0, map, n, m, flag);

	printf("\n按回车键显示图形界面...");
	while (_getch() != '\r');

	if (mode == 4)
		output_cmd_base(map, n, m);
	else
		output_cmd_reset(map, n, m, mode);
}
void work_cmd(int(*map)[Maxm], const int n, const int m, const int mode)
{
	bool flag[Maxn][Maxm];

	reset_map(map, n, m);
	output_cmd_reset(map, n, m, mode);

	setcolor(hout, 0, 7);
	while (1)
	{
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("按回车键进行寻找可消除项...");
		while (_getch() != '\r');
		printf("\n");
		if (!check(map, n, m, flag))
		{
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("无可消除项\n");
			break;
		}
		output_cmd_change(1, map, n, m, flag);
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("\n");
		if (mode == 6)
			return;

		Sleep(200);
		output_cmd_change(0, map, n, m, flag);
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));

		printf("按回车键进行下落操作...");
		while (_getch() != '\r');
		output_cmd_alter(map, n, m, flag);

		fill_map(map, n, m, flag);
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("按回车键进行填充操作...");
		while (_getch() != '\r');
		output_cmd_change(2, map, n, m, flag);
	}

	if (mode == 6)
		return;
	Sleep(1000);
	find(map, n, m, flag);
	gotoxy(hout, 0, 13 + 2 * (n - 5));
	printf("                              ");
	gotoxy(hout, 0, 13 + 2 * (n - 5));
	printf("按回车键查询可行交换...");
	while (_getch() != '\r');
	output_cmd_change(3, map, n, m, flag);
	gotoxy(hout, 0, 13 + 2 * (n - 5));
	printf("                              ");
	gotoxy(hout, 0, 13 + 2 * (n - 5));
}

void work_game(int(*map)[Maxm], const int n, const int m)
{
	bool flag[Maxn][Maxm];
	int tot = 0;
	reset_map(map, n, m);
	output_cmd_reset(map, n, m, 8);

	bool lock = 1;
	setcolor(hout, 0, 7);
	while (1)
	{
		while (1)
		{
			setcolor(hout, 0, 7);
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("正在寻找可消除项...");
			if (!check(map, n, m, flag))
			{
				gotoxy(hout, 0, 13 + 2 * (n - 5));
				printf("                              ");
				gotoxy(hout, 0, 13 + 2 * (n - 5));
				printf("无可消除项\n");
				break;
			}
			output_cmd_change(1, map, n, m, flag);

			if (!lock)
				output_score(tot, n, m, flag);

			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("\n");
			Sleep(200);
			output_cmd_change(0, map, n, m, flag);
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));

			printf("正在进行下落操作...");
			output_cmd_alter(map, n, m, flag);

			fill_map(map, n, m, flag);
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("正在进行填充操作...");
			output_cmd_change(2, map, n, m, flag);
		}

		Sleep(1000);
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("正在查询可行交换...");
		if (!find(map, n, m, flag))
		{
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("无可行交换");
			Sleep(500);
			break;
		}
		output_cmd_change(3, map, n, m, flag);
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		printf("                              ");
		gotoxy(hout, 0, 13 + 2 * (n - 5));
		if (lock)
			lock = 0;

		if (!mouse_work(map, n, m, flag))
			break;
	}

	gotoxy(hout, 0, 13 + 2 * (n - 5));
	printf("                              ");
	gotoxy(hout, 0, 13 + 2 * (n - 5));
	printf("游戏结束!!!!\n");
}

bool mouse_init(Point &mouse, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	Point pos;
	pos.x = pos.y = 0;
	enable_mouse(hin);
	setcursor(hout, CURSOR_INVISIBLE);
	while (1)
	{
		int mouse_action = read_mouse(hin, pos.x, pos.y);
		gotoxy(hout, 0, 16 + 2 * (n - 7));
		setcolor(hout, 0, 7);
		if ((pos.x >= 2 && pos.x <= 4 * m - 1 && ((pos.x % 4 == 2) || (pos.x % 4) == 3))
			&& (pos.y >= 2 && pos.y <= 2 * n && !(pos.y % 2)))
		{
			printf("[当前光标位置] : %c行%d列", pos.y / 2 + 'A' - 1, (pos.x + 2) / 4);
			if (mouse_action == MOUSE_RIGHT_BUTTON_CLICK)
				return 0;
			if (mouse_action == MOUSE_LEFT_BUTTON_CLICK)
			{
				mouse = { pos.y / 2,(pos.x + 2) / 4 };
				return 1;
			}
		}
	}
}
bool mouse_work(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	bool select = 0;
	Point mouse, pre;
	while (1)
	{
		if (!mouse_init(mouse, map, n, m, flag))
			return 0;
		if (!map[mouse.x][mouse.y] && !select)
			continue;
		if (!flag[mouse.x][mouse.y])
		{
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("                              ");
			gotoxy(hout, 0, 13 + 2 * (n - 5));
			printf("不能选择这个位置");
			continue;
		}
		if (!select)
		{
			select = 1;
			gotoxy(hout, 4 * mouse.y - 2, 2 * mouse.x);
			setcolor(hout, col[map[mouse.x][mouse.y]], 0);
			printf("¤");
			pre = mouse;
			setcolor(hout, 0, 7);
			continue;
		}
		//select == 1
		if ((mouse.x == pre.x && abs(mouse.y - pre.y) == 1) ||
			(mouse.y == pre.y && abs(mouse.x - pre.x) == 1))
		{
			if (check_swap(map, n, m, pre, mouse))
			{
				if (mouse.x < pre.x || mouse.y < pre.y)
					Swap(mouse, pre);
				int deltax = mouse.x - pre.x, deltay = 2 * (mouse.y - pre.y);
				output_cmd_change(4, map, n, m, flag);

				setcolor(hout, 15, 0);
				gotoxy(hout, 4 * pre.y - 2, 2 * pre.x);
				printf("  ");
				gotoxy(hout, 4 * mouse.y - 2, 2 * mouse.x);
				printf("  ");
				setcolor(hout, 15, 0);
				gotoxy(hout, 4 * pre.y - 2 + deltay, 2 * pre.x + deltax);
				printf("○");
				Sleep(200);

				setcolor(hout, col[map[pre.x][pre.y]], 0);
				gotoxy(hout, 4 * pre.y - 2, 2 * pre.x);
				printf("○");
				setcolor(hout, col[map[mouse.x][mouse.y]], 0);
				gotoxy(hout, 4 * mouse.y - 2, 2 * mouse.x);
				printf("○");
				setcolor(hout, 15, 0);
				gotoxy(hout, 4 * pre.y - 2 + deltay, 2 * pre.x + deltax);
				printf(deltax ? "─" : "│");
				Sleep(50);

				break;
			}
			else
			{
				gotoxy(hout, 0, 13 + 2 * (n - 5));
				printf("                              ");
				gotoxy(hout, 0, 13 + 2 * (n - 5));
				printf("无法进行交换");
				continue;
			}
		}
		else
		{
			setcolor(hout, col[map[pre.x][pre.y]], 0);
			gotoxy(hout, 4 * pre.y - 2, 2 * pre.x);
			printf("◎");
			setcolor(hout, col[map[mouse.x][mouse.y]], 0);
			gotoxy(hout, 4 * mouse.y - 2, 2 * mouse.x);
			printf("¤");
			pre = mouse;
			setcolor(hout, 0, 7);
			continue;
		}
	}
	return 1;
}

template <typename T>
void Swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}
bool try_swap(int(*map)[Maxm], int n, int m, int tc, const int X, const int Y)
{
	int cnt = 0;

	int curX = X - 1;
	while (curX && cnt<2)
	{
		if (col[map[curX][Y]] != tc)
			break;
		cnt++;
		--curX;
	}
	curX = X + 1;
	while (curX <= n && cnt < 2)
	{
		if (col[map[curX][Y]] != tc)
			break;
		cnt++;
		++curX;
	}
	if (cnt >= 2)
		return 1;

	cnt = 0;
	int curY = Y - 1;
	while (curY && cnt < 2)
	{
		if (col[map[X][curY]] != tc)
			break;
		cnt++;
		--curY;
	}
	curY = Y + 1;
	while (curY <= m && cnt < 2)
	{
		if (col[map[X][curY]] != tc)
			break;
		cnt++;
		++curY;
	}
	if (cnt >= 2)
		return 1;

	return 0;
}
bool check_swap(int(*map)[Maxm], int n, int m, Point A, Point B)
{
	int cA = col[map[A.x][A.y]], cB = col[map[B.x][B.y]];
	Swap(map[A.x][A.y], map[B.x][B.y]);
	if (!try_swap(map, n, m, cA, B.x, B.y) && !try_swap(map, n, m, cB, A.x, A.y))
	{
		Swap(map[A.x][A.y], map[B.x][B.y]);
		return 0;
	}
	return 1;
}

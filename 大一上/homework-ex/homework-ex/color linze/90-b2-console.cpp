/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

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

void work_4(int(*map)[Maxm], const int n, const int m, int &last)
{
	work_1(map, n, m, last);
	printf("按回车显示图形...");
	while (_getch() != '\r');
	reset_pic_base(map, n, m);
}
void work_5(int(*map)[Maxm], const int n, const int m, int &last)
{
	work_1(map, n, m, last);
	printf("按回车显示图形...");
	while (_getch() != '\r');
	reset_pic(5, map, n, m);
}
void work_6(int(*map)[Maxm], const int n, const int m, int &last)
{
	bool setting[2] = { 1,1 };
	int tmp[8] = { 0 };
	reset_map(n*m * 3 / 5, map, n, m, last);
	reset_pic(6, map, n, m);
	int score = 0;
	mouse_work(6, map, n, m, last, score, tmp, setting);
	system("cls");
	reset_pic(6, map, n, m);
}
int work_7(const int mode, int(*map)[Maxm], const int n, const int m, int &last)
{
	const int Clear = n*m;

	bool setting[2] = { 1,1 };
	reset_map(5, map, n, m, last);

	bool flag = 1;
	int col[4], tot = 0;
	int sum_del[8] = { 0 };

	For(i, 1, 3)
		col[i] = rand() % Maxc + 1;
	reset_pic(mode, map, n, m);
	reset_menu(tot, col, map, n, m, sum_del, setting);

	do
	{
		int pretot = tot, res;
		if (res = mouse_work(mode, map, n, m, last, tot, sum_del, setting))
		{
			if (res == 1)
				break;
			else if (res == 2)
				return 1;
			else
			{
				reset_pic(mode, map, n, m);
				reset_menu(tot, col, map, n, m, sum_del, setting);
				continue;
			}
		}
		reset_menu(tot, col, map, n, m, sum_del, setting);
		if (!(tot - pretot))
		{
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
			For(i, 1, 3)
				col[i] = rand() % Maxc + 1;
		}
		reset_pic(mode, map, n, m);
		reset_menu(tot, col, map, n, m, sum_del, setting);
	} while (last > 0 && last != Clear);
	gotoxy(hout, 0, 16 + 2 * (n - 7));
	setcolor(hout, 0, 7);
	printf("                            ");
	gotoxy(hout, 0, 16 + 2 * (n - 7));
	printf("游戏结束！！！！！\n");
	return 0;
}
void work_8(int(*map)[Maxm], const int n, const int m, int &last)
{
	while (1)
	{
		if (!work_7(8, map, n, m, last))
			return;
		reset(map, n, m, last);
	}
}
void work_9(int(*map)[Maxm], const int n, const int m, int &last)
{
	while (1)
	{
		if (!work_7(9, map, n, m, last))
			return;
		reset(map, n, m, last);
	}
}

int mouse_work(const int mode, int(*map)[Maxm], const int n, const int m, int &last, int &score, int *sum_del, bool*setting)
{
	const int size = 28 - 4 * (n - 7);
	bool select = 0;
	int mouse[2] = { 0 }, prex, prey;

	while (1)
	{
		int mouse_init_f = mouse_init(mode, map, n, m, mouse, setting);
		if (mouse_init_f)
			return mouse_init_f;
		int x = mouse[0], y = mouse[1];
		if (!map[x][y] && !select)
			continue;
		if (map[x][y] && !select)
		{
			select = 1;
			gotoxy(hout, 4 * y - 2, 2 * x);
			setfontsize(hout, L"新宋体", size);
			setcolor(hout, 7 + map[x][y], 0);
			printf("◎");
			prex = x, prey = y;
			setcolor(hout, 0, 7);
			continue;
		}
		if (map[x][y] && select)
		{
			setfontsize(hout, L"新宋体", size);
			setcolor(hout, 7 + map[prex][prey], 0);
			gotoxy(hout, 4 * prey - 2, 2 * prex);
			printf("○");
			setcolor(hout, 7 + map[x][y], 0);
			gotoxy(hout, 4 * y - 2, 2 * x);
			printf("◎");
			prex = x, prey = y;
			setcolor(hout, 0, 7);
			continue;
		}

		bool bfs(int(*map)[Maxm], const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm]);
		int tox[Maxn][Maxn] = { 0 };
		int toy[Maxn][Maxn] = { 0 };
		if (!bfs(map, prex, prey, x, y, tox, toy))
			continue;
		map[x][y] = map[prex][prey];
		map[prex][prey] = 0;
		ball_moving(map, n, m, prex, prey, x, y, tox, toy, 7 + map[x][y]);
		score += check(map, x, y, last, sum_del);

		return 0;
	}
}
/***************************************************************************
the clarification of the return-value
0 - a mouse action
1 - the right button click
2 - a new game
3 - a setting command
***************************************************************************/
int mouse_init(const int mode, int(*map)[Maxm], const int n, const int m, int *mouse, bool*setting)
{
	int X = 0, Y = 0;
	enable_mouse(hin);
	setcursor(hout, CURSOR_INVISIBLE);
	while (1)
	{
		int mouse_action;
		if (mode <= 7)
			mouse_action = read_mouse(hin, X, Y);
		else
		{
			mouse_action = read_mouse_and_key(hin, mode, X, Y);
			if (mouse_action == VK_F3)
			{
				setting[0] ^= 1;
				return 3;
			}
			else if (mouse_action == VK_F5)
			{
				setting[1] ^= 1;
				return 3;
			}
			else if (mouse_action == VK_F4)
				return 2;
		}
		/***************************************************************************
		just for testing
		***************************************************************************/
		if (mode == 9)
		{
			if (mouse_action != 6)
			{
				gotoxy(hout, 0, 17 + 2 * (n - 7));
				printf("                                      ");
				gotoxy(hout, 0, 17 + 2 * (n - 7));
				printf("(200ms for clicking) mouse_action = %d", mouse_action);
			}
		}

		gotoxy(hout, 0, 16 + 2 * (n - 7));
		setcolor(hout, 0, 7);
		if ((X >= 2 && X <= 4 * m - 1 && ((X % 4 == 2) || (X % 4) == 3)) && (Y >= 2 && Y <= 2 * n && (Y % 2) == 0))
		{
			printf("[当前光标位置] : %c行%d列", Y / 2 + 'A' - 1, (X + 2) / 4);
			if (mouse_action == MOUSE_RIGHT_BUTTON_CLICK)
				return 1;
			if (mouse_action == MOUSE_LEFT_BUTTON_CLICK)
			{
				mouse[0] = Y / 2, mouse[1] = (X + 2) / 4;
				return 0;
			}
		}
	}
}

void reset_pic_base(int(*map)[Maxm], const int n, const int m)
{
	const int cols = 35;
	const int lines = 20 + 2 * (n - 7);
	const int size = 28 - 4 * (n - 7);
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
			setcolor(hout, 7 + map[i][j], 0);
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
void reset_pic(const int mode, int(*map)[Maxm], const int n, const int m)
{
	const int cols = (35 + 2 * (m - 2)) * ((mode >= 7) + 1);
	const int lines = 22 + 2 * (n - 7);
	const int size = 28 - 4 * (n - 7);
	setconsoleborder(hout, cols, lines);
	setfontsize(hout, L"新宋体", size);

	setcolor(hout, 0, 7);
	gotoxy(hout, 0, 0);
	printf("(右键-退出");
	if (mode >= 8)
		printf(" F3-开启/关闭彩球预告 F4-重新开始 F5-开启/关闭统计信息");
	printf(")\n");
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
			setcolor(hout, 7 + map[i][j], 0);
			printf("○");
			setcolor(hout, 15, 0);
			printf("│");
		}
		if (!map[i][m])
			printf("  ");
		else
		{
			setcolor(hout, 7 + map[i][m], 0);
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
		setcolor(hout, 7 + map[n][j], 0);
		printf("○");
		setcolor(hout, 15, 0);
		printf("│");
	}
	if (!map[n][m])
		printf("  ");
	else
	{
		setcolor(hout, 7 + map[n][m], 0);
		printf("○");
		setcolor(hout, 15, 0);
	}
	printf("║\n");

	printf("╚");
	For(i, 1, m - 1)
		printf("═╧");
	printf("═╝\n");
}
void reset_menu(const int tot, const int *col, const int(*map)[Maxm], const int n, const int m, const int *sum_del, bool*setting)
{
	const int size = 28 - 4 * (n - 7);
	setfontsize(hout, L"新宋体", size);
	setcolor(hout, 15, 0);

	gotoxy(hout, 43, 1);
	printf("╔══════╗");
	gotoxy(hout, 43, 2);
	printf("║得分");
	cout << setw(8) << tot << "║";
	gotoxy(hout, 43, 3);
	printf("╚══════╝");

	if (setting[0])
	{
		gotoxy(hout, 43, 5);
		setcolor(hout, 15, 0);
		printf("╔═╤═╤═╗");
		gotoxy(hout, 43, 6);
		printf("║");
		setcolor(hout, col[1] + 7, 0);
		printf("○");
		setcolor(hout, 15, 0);
		printf("│");
		setcolor(hout, col[2] + 7, 0);
		printf("○");
		setcolor(hout, 15, 0);
		printf("│");
		setcolor(hout, col[3] + 7, 0);
		printf("○");
		setcolor(hout, 15, 0);
		printf("║");
		gotoxy(hout, 43, 7);
		printf("╚═╧═╧═╝");
	}

	if (setting[1])
	{
		int sum = n*m, cnt[8] = { 0 };
		For(i, 1, n)
			For(j, 1, m)
			++cnt[map[i][j]];

		gotoxy(hout, 43, 9);
		setcolor(hout, 15, 0);
		printf("╔════════════╗");

		gotoxy(hout, 43, 10);
		printf("║");
		cout << "  " << setw(2) << setiosflags(ios::right) << setfill('0') << cnt[0];
		printf(":/(");
		cout << setw(5) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << 1.0*cnt[0] / sum * 100;
		printf("%%)  ");
		printf("del-");
		cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << setfill(' ') << sum_del[0];
		printf("║");

		For(i, 1, 7)
		{
			gotoxy(hout, 43, 10 + i);
			printf("║");
			setcolor(hout, 7 + i, 0);
			cout << "○";
			setcolor(hout, 15, 0);
			cout << setw(2) << setiosflags(ios::right) << setfill('0') << cnt[i];
			printf(":/(");
			cout << setw(5) << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << 1.0*cnt[i] / sum * 100;
			printf("%%)  ");
			printf("del-");
			cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << setfill(' ') << sum_del[i];
			printf("║");
		}

		gotoxy(hout, 43, 18);
		cout << "╚════════════╝";
		setcolor(hout, 0, 7);
	}
}
void ball_moving(int(*map)[Maxm], const int n, const int m, const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm], int col)
{
	int ux = sx, uy = sy;
	do
	{
		int vx = tox[ux][uy], vy = toy[ux][uy];
		if (ux == vx)
		{
			int fy = vy > uy ? 2 : -2;
			For(i, 1, 2)
			{
				Sleep(200);
				showch(hout, 4 * uy - 2 + fy*(i - 1), 2 * ux, ' ', 15, 0, 2);
				gotoxy(hout, 4 * uy - 2 + fy*i, 2 * ux);
				setcolor(hout, col, 0);
				printf("◎");
			}
			gotoxy(hout, 4 * uy - 2 + fy, 2 * ux);
			setcolor(hout, 15, 0);
			printf("│");
		}
		else //uy==vy
		{
			int fx = vx > ux ? 1 : -1;
			For(i, 1, 2)
			{
				Sleep(200);
				showch(hout, 4 * uy - 2, 2 * ux + fx*(i - 1), ' ', 15, 0, 2);
				gotoxy(hout, 4 * uy - 2, 2 * ux + fx*i);
				setcolor(hout, col, 0);
				printf("◎");
			}
			gotoxy(hout, 4 * uy - 2, 2 * ux + fx);
			setcolor(hout, 15, 0);
			printf("─");
		}
		ux = vx, uy = vy;
	} while (ux != ex || uy != ey);
}

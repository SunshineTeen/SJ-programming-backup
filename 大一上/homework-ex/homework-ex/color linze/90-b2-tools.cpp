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

//reset
void reset(int(*map)[Maxm], const int n, const int m, int &last)
{
	For(i, 1, n)
		For(j, 1, m)
		map[i][j] = 0;
	For(i, 0, n + 1)
		map[i][0] = map[i][m + 1] = -1;
	For(j, 0, m + 1)
		map[0][j] = map[n + 1][j] = -1;
	last = n*m;
}

//input
bool init_mode(int &mode)
{
	printf("[��ѡ��0-9]:");
	if (!scanf(" %d", &mode))
		mode = -1;
	FFLUSH;
	if (mode < 0 || mode>9)
		return 0;
	return 1;
}
void init(int &n, int &m)
{
	setconsoleborder(hout, 80, 25);
	while (1)
	{
		printf("����������(7-9):");
		if (!scanf(" %d", &n))
			n = 6;
		FFLUSH;
		if (n < 7 || n>9)
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
		printf("����������(7-9):");
		if (!scanf(" %d", &m))
			m = 6;
		FFLUSH;
		if (m < 7 || m>9)
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
void init_st(int(*map)[Maxm], const int n, const int m, int &sx, int &sy)
{
	while (1)
	{
		printf("������ĸ+������ʽ[��:c2]����Ҫ�ƶ���ľ������꣺");
		sx = alpha_upper(getchar()) - 'A' + 1;
		sy = getchar() - '0';
		FFLUSH;
		if (!map[sx][sy])
		{
			printf("����������Ϊ��\n");
			continue;
		}
		if (sx<1 || sx>n || sy<1 || sy>m)
			continue;
		break;
	}
	printf("����Ϊ%c��%d��\n", sx + 'A' - 1, sy);
}
void init_ed(int(*map)[Maxm], const int n, const int m, int &ex, int &ey)
{
	while (1)
	{
		printf("������ĸ+������ʽ[��:c2]����Ҫ�ƶ����Ŀ�����꣺");
		ex = alpha_upper(getchar()) - 'A' + 1;
		ey = getchar() - '0';
		FFLUSH;
		if (map[ex][ey])
		{
			printf("����������ǿ�\n");
			continue;
		}
		if (ex<1 || ex>n || ey<1 || ey>m)
			continue;
		break;
	}
	printf("����Ϊ%c��%d��\n", ex + 'A' - 1, ey);
}

//change the Alphabet
char alpha_upper(const char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 32;
	return ch;
}

//prework
void reset_map(int x, int(*map)[Maxm], const int n, const int m, int &last)
{
	int tmp[8] = { 0 };
	while (x)
	{
		int col = rand() % Maxc + 1, tlast = last;
		if (rand_ball(map, n, m, col, last))
		{
			x += last - tlast;
			continue;
		}
		--x;
	}
}

//bfs to find the route
bool bfs(int(*map)[Maxm], const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm])
{
	int l = 1, r = 2;
	int Qx[Maxx] = { 0 }, Qy[Maxx] = { 0 };
	int frox[Maxn][Maxm] = { 0 }, froy[Maxn][Maxm] = { 0 };
	bool f[Maxn][Maxm] = { 0 };
	Qx[l] = sx, Qy[l] = sy;
	f[sx][sy] = 1;
	while (l < r)
	{
		int ux = Qx[l], uy = Qy[l];
		if (ux == ex && uy == ey)
		{
			f[ex][ey] = 1;
			break;
		}
		For(i, 0, 3)
		{
			int vx = ux + fx[i], vy = uy + fy[i];
			if (map[vx][vy] || f[vx][vy])
				continue;
			frox[vx][vy] = ux;
			froy[vx][vy] = uy;
			Qx[r] = vx, Qy[r] = vy;
			f[vx][vy] = 1;
			++r;
		}
		++l;
	}
	if (!f[ex][ey])
		return 0;
	get_route(sx, sy, ex, ey, frox, froy, tox, toy);
	return 1;
}
void get_route(const int sx, const int sy, const int ex, const int ey, int(*frox)[Maxm], int(*froy)[Maxm], int(*tox)[Maxm], int(*toy)[Maxm])
{
	int curx = ex, cury = ey;
	while (curx != sx || cury != sy)
	{
		int prex = frox[curx][cury], prey = froy[curx][cury];
		tox[prex][prey] = curx;
		toy[prex][prey] = cury;
		curx = prex, cury = prey;
	}
}

int rand_ball(int(*map)[Maxm], const int n, const int m, const int col, int &last)
{
	int tmp[8] = { 0 };
	while (1)
	{
		int i = rand() % n + 1;
		int j = rand() % m + 1;
		if (map[i][j])
			continue;

		map[i][j] = col;
		--last;
		return check(map, i, j, last, tmp);
	}
}
int check(int(*map)[Maxm], const int x, const int y, int &last, int *sum_del)
{
	int A = 1, B = 0;
	For(i, 0, 3)
	{
		int tmp = Calc(map, x, y, map[x][y], gx[2 * i], gy[2 * i])
			+ Calc(map, x, y, map[x][y], gx[2 * i + 1], gy[2 * i + 1]);
		if (tmp >= 4)
		{
			Delete(map, x, y, map[x][y], gx[2 * i], gy[2 * i]);
			Delete(map, x, y, map[x][y], gx[2 * i + 1], gy[2 * i + 1]);
			A += tmp;
			++B;
		}
	}
	if (A == 1)
		return 0;
	int res = 10 + 2 * (A + B - 6)*(A + B - 6);
	last += A;
	sum_del[map[x][y]] += A;
	map[x][y] = 0;
	return res;
}
int Calc(int(*map)[Maxm], int x, int y, const int col, const int fx, const int fy)
{
	int res = 0;
	x += fx, y += fy;
	while (map[x][y] == col)
		++res, x += fx, y += fy;
	return res;
}
void Delete(int(*map)[Maxm], int x, int y, const int col, const int fx, const int fy)
{
	x += fx, y += fy;
	while (map[x][y] == col)
		map[x][y] = 0, x += fx, y += fy;
}

int read_mouse_and_key(const HANDLE hin,const int mode, int &X, int &Y, const int enable_read_mouse_moved)
{
	INPUT_RECORD    mouseRec;
	DWORD           res;
	COORD           crPos;

	while (1)
	{
		static int mouse_pre_event = MOUSE_MOVED;
		ReadConsoleInput(hin, &mouseRec, 1, &res);

		if (mouseRec.EventType != MOUSE_EVENT)
			if (mouseRec.EventType == KEY_EVENT && mouseRec.Event.KeyEvent.bKeyDown //avoid the twice of input
				&& (mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_F3
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_F4
					|| mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_F5))
				return mouseRec.Event.KeyEvent.wVirtualKeyCode;
			else
				continue;

		crPos = mouseRec.Event.MouseEvent.dwMousePosition;
		X = crPos.X;
		Y = crPos.Y;

		if (mode==9 && mouse_pre_event == (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED))
		{
			if (mouseRec.Event.MouseEvent.dwButtonState)
				return MOUSE_ONLY_MOVED;
			mouse_pre_event = MOUSE_MOVED;
		}
		if (enable_read_mouse_moved && mouseRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
			return MOUSE_ONLY_MOVED;

		int Double_Click_Res;
		if (mouseRec.Event.MouseEvent.dwButtonState == (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED))
		{
			mouse_pre_event = (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED);
			return MOUSE_LEFTRIGHT_BUTTON_CLICK;
		}
		else if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_LEFT_BUTTON_DOUBLE_CLICK;
			else if (mode == 9 && (Double_Click_Res = Check_Double_Click(FROM_LEFT_1ST_BUTTON_PRESSED)))
			{
				if (Double_Click_Res == RIGHTMOST_BUTTON_PRESSED)
				{
					mouse_pre_event = (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED);
					return MOUSE_LEFTRIGHT_BUTTON_CLICK;
				}
				else
					return MOUSE_LEFT_BUTTON_DOUBLE_CLICK;
			}
			else
				return MOUSE_LEFT_BUTTON_CLICK;
		}
		else if (mouseRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_RIGHT_BUTTON_DOUBLE_CLICK;
			else if (mode == 9 && (Double_Click_Res = Check_Double_Click(RIGHTMOST_BUTTON_PRESSED)))
			{
				if (Double_Click_Res == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					mouse_pre_event = (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED);
					return MOUSE_LEFTRIGHT_BUTTON_CLICK;
				}
				else
					return MOUSE_RIGHT_BUTTON_DOUBLE_CLICK;
			}
			else
				return MOUSE_RIGHT_BUTTON_CLICK;
		}
		else
			;
	}
	return MOUSE_NO_ACTION;
}
int Check_Double_Click(int pre_mouse_event, const int enable_read_mouse_moved)
{
	const int Time_Limit = 200;
	long time = clock();

	INPUT_RECORD    mouseRec;
	DWORD           res;

	bool release = 1;
	while(clock()-time<Time_Limit)
	{
		PeekConsoleInput(hin, &mouseRec, 1, &res);
		if (res > 0)
		{
			ReadConsoleInput(hin, &mouseRec, 1, &res);
			if (mouseRec.EventType != MOUSE_EVENT)
				continue;
			if (enable_read_mouse_moved && mouseRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
				continue;
			if (mouseRec.Event.MouseEvent.dwButtonState == (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED))
			{
				if (pre_mouse_event == FROM_LEFT_1ST_BUTTON_PRESSED)
					return RIGHTMOST_BUTTON_PRESSED;
				return FROM_LEFT_1ST_BUTTON_PRESSED;
			}
			if (!mouseRec.Event.MouseEvent.dwEventFlags)
			{
				release ^= 1;
				if (!release)
					continue;
			}
			return mouseRec.Event.MouseEvent.dwButtonState;
		}
	}
	return 0;
}

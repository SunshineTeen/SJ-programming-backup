/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include "cmd_console_tools.h"

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')

using namespace std;

const int Maxh = 10;
const int Maxn = Maxh + 10;
const int X[3] = { 12,44,76 };
const int Y = 15;
const int width = 100;

int cnt;
int stack[3][Maxn];
int top[3];

//img part
void reset_xy(const int mode)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mode <= 4)
		return;
	else if (mode >= 5 && mode <= 7)
		gotoxy(hout, 0, 28);
	else if (mode == 8)
		gotoxy(hout, 0, 34);
	else //mode==9
		gotoxy(hout, 0, 38);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
}
void put_disk(const int i, const int x, const int y, const int len, const int last)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const int fg_color = COLOR_BLACK;
	const int bg_color = i;
	showch(hout, x, y, ' ', bg_color, fg_color, len);
	Sleep(last);
}
void move_disk(const int i, const char from, const int n, const char to, const int m, const int last)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const int sti = from - 'A';
	const int edi = to - 'A';
	const int stx = X[sti] - i;
	const int edx = X[edi] - i;
	const int len = 2 * i + 1;

	opFor(j, Y - n, 2)
	{
		showch(hout, stx, j, ' ', COLOR_BLACK, COLOR_WHITE, len);
		if (j >= 3)
			showch(hout, X[sti], j, ' ', COLOR_HYELLOW, COLOR_BLACK, 1);
		put_disk(i, stx, j - 1, len, last);
	}

	int ii = stx > edx ? -1 : 1;
	int p = stx;
	while (p != edx)
	{
		showch(hout, p, 1, ' ', COLOR_BLACK, COLOR_WHITE, len);
		put_disk(i, (p += ii), 1, len, last);
	}

	For(j, 1, Y - m - 1)
	{
		showch(hout, edx, j, ' ', COLOR_BLACK, COLOR_WHITE, len);
		if (j >= 3)
			showch(hout, X[edi], j, ' ', COLOR_HYELLOW, COLOR_BLACK, 1);
		put_disk(i, edx, j + 1, len, last);
	}
}
void put_pillar(const int last)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	const int fg_color = COLOR_BLACK;
	const int bg_color = COLOR_HYELLOW;
	const int width = 23;
	const int height = 12;

	showch(hout, 1, Y, ' ', bg_color, fg_color, width);
	showch(hout, 33, Y, ' ', bg_color, fg_color, width);
	showch(hout, 65, Y, ' ', bg_color, fg_color, width);
	opFor(i, 3 + height, 3)
	{
		showch(hout, X[0], i, ' ', bg_color, fg_color, 1);
		Sleep(last);
		showch(hout, X[1], i, ' ', bg_color, fg_color, 1);
		Sleep(last);
		showch(hout, X[2], i, ' ', bg_color, fg_color, 1);
		Sleep(last);
	}
}
void img_reset(const int n, const char st, const char ed, const int last)
{
	printf("从 %c 移动到 %c,共 %d 层", st, ed, n);
	put_pillar(last);
	int k = st - 'A';
	For(i, 1, n)
	{
		int x = X[k] - i, y = Y - (n - i + 1), len = 2 * i + 1;
		put_disk(i, x, y, len, last);
	}

}

//output part
void clear_screen(const int mode)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, 0);
	int sx, sy = 0, ex, ey = width-1;
	if (mode == 4)
		sx = 1, ex = 28;
	else
	{
		sx = Y + 1;
		ex = 32;
	}
	For(i, sx, ex)
	{
		For(j, sy, ey)
		{
			gotoxy(hout, j, i);
			printf(" ");
		}
	}

	if (mode == 4)
		gotoxy(hout, 0, 1);
	else
		gotoxy(hout, 0, Y + 1);
}
void print_array()
{
	printf("A:");
	For(i, 1, top[0])
		cout << setw(2) << stack[0][i];
	For(i, 1, 10 - top[0])
		printf("  ");
	printf(" ");

	printf("B:");
	For(i, 1, top[1])
		cout << setw(2) << stack[1][i];
	For(i, 1, 10 - top[1])
		printf("  ");
	printf(" ");

	printf("C:");
	For(i, 1, top[2])
		cout << setw(2) << stack[2][i];
	For(i, 1, 10 - top[2])
		printf("  ");

	printf("\n");
}
inline void put_pic()
{
	printf("\n");
	opFor(i, Maxh, 1)
	{
		if (stack[0][i])
			cout << setw(12) << stack[0][i];
		else
			printf("            ");
		if (stack[1][i])
			cout << setw(10) << stack[1][i];
		else
			printf("          ");
		if (stack[2][i])
			cout << setw(10) << stack[2][i];
		else
			printf("          ");
		printf("\n");
	}
	printf("         =========================\n");
	printf("           A         B         C\n");
	printf("\n\n\n");
}
inline void output(const int mode, const int n, const char st, const char ed, const int num, const char from, const char to, const int last)
{
	if (mode == 4 || mode == 8 || mode == 9)
	{
		clear_screen(mode);
		put_pic();
	}

	++cnt;
	if (mode == 1)
		printf("%d#", num);
	else
	{
		printf("第");
		cout << setw(4) << cnt;
		cout << "步(";
		cout << setw(2) << num;
		cout << "):";
	}
	printf(" %c---->%c ", from, to);

	if (mode == 3 || mode == 4 || mode == 8 || mode == 9)
		print_array();
	else
		printf("\n");

	if (mode == 8 || mode == 9)
		move_disk(num, from, top[from - 'A'] + 1, to, top[to - 'A'], (last ? last / 10 : 30));
		
	reset_xy(mode);
}

//stack operate
int pop(int i)
{
	int res = stack[i][top[i]];
	stack[i][top[i]--] = 0;
	return res;
}
void push(int x, int i)
{
	stack[i][++top[i]] = x;
}

//work part
void wait(const int last)
{
	if (!last)
	{
		char ch;
		while (1)
		{
			ch = _getch();
			if (ch == '\n' || ch == '\r')
				break;
		}
	}
	else
		Sleep(last);
}
inline void move(const int mode, const int n, const char st, const char ed, const int num, const char from, const char to, const char tmp, const int last)
{
	if (!num)
		return;
	move(mode, n, st, ed, num - 1, from, tmp, to, last);
	int x = pop(from - 'A');
	push(x, to - 'A');

	if (mode == 4 || mode == 8)
		wait(last);
	output(mode, n, st, ed, num, from, to, last);
	move(mode, n, st, ed, num - 1, tmp, to, from, last);
}
inline void clear_stack(const int n)
{
	top[0] = top[1] = top[2] = 0;
	stack[0][0] = stack[1][0] = stack[2][0] = n + 1;
	For(i, 1, Maxh)
		stack[0][i] = stack[1][i] = stack[2][i] = 0;
}
void reset(const int mode, const int n, const char st, const char ed, const int speed, const int last)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	clear_stack(n);
	int Id = st - 'A';
	opFor(i, n, 1)
		push(i, Id);

	if (mode != 1 && mode != 2)
		system("cls");
	if (mode == 4 || mode == 8)
		printf("从 %c 移动到 %c , 共 %d 层 , 延时设置为 %d ", st, ed, n, speed);
	else if (mode == 9)
		printf("从 %c 移动到 %c , 共 %d 层 ", st, ed, n);

	if (mode == 8 || mode == 9)
	{
		img_reset(n, st, ed, (speed ? last / 20 : 30));
		gotoxy(hout, 0, Y + 1);
		setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	}

	if (mode == 4 || mode == 8 || mode == 9)
		put_pic();

	if (mode == 4 || mode == 8 || mode == 9)
	{
		printf("初始：                ");
		print_array();
	}
}
void work(const int mode, const int n, const char st, const char ed, const char tmp, const int speed, const int last)
{
	reset(mode, n, st, ed, speed, last);
	move(mode, n, st, ed, n, st, ed, tmp, last);
}

//game part
void move_operate(const int n, const int i, const int j)
{
	if (!top[i])
	{
		printf("源柱为空!!!!");
		Sleep(750);
		return;
	}
	int top_i = stack[i][top[i]], top_j = stack[j][top[j]];
	if (top_i > top_j)
	{
		printf("大盘压小盘，非法移动");
		Sleep(750);
		return;
	}

	int tmp = pop(i);
	push(tmp,j);
	output(9, n, 0, 0, tmp, i + 'A', j + 'A', 1);
}
inline bool check(const int n, const char i)
{
	if (top[i - 'A'] == n)
		return 1;
	return 0;
}
inline void clear()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, 34);
	For(i, 1, width - 1)
		printf(" ");
	printf("\n");
	For(i, 1, width)
		printf(" ");
	gotoxy(hout, 0, 34);
}
void game_ver(const int n, const char st, const char ed)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	char from, to;

	reset(9, n, st, ed, 0, 0);
	while (1)
	{
		if (check(n, ed))
		{
			gotoxy(hout, 0, 35);
			printf("游戏结束!!!!");
			return;
		}
		clear();
		printf("请输入移动的柱号(命令形式:AC=A顶端的盘子移动到C) : ");
		if (scanf(" %c%c", &from, &to) != 2)
			from = to = 'D';
		if (from >= 'a' && from <= 'z')
			from -= 32;
		if (to >= 'a' && to <= 'z')
			to -= 32;
		if (from<'A' || from>'C' || to<'A' || to>'C' || from == to)
		{
			FFLUSH;
			continue;
		}
		FFLUSH;

		move_operate(n, from - 'A', to - 'A');
	}
}

//input part
void pre_work(char *st, char *ed, char *tmp)
{
	bool f[3] = { 0 };
	if (*st >= 'a' && *st <= 'c')
		st -= 32;
	if (*ed >= 'a' && *ed <= 'c')
		ed -= 32;
	f[*st - 'A'] = 1;
	f[*ed - 'A'] = 1;
	if (!f[0])
		*tmp = 'A';
	else if (!f[1])
		*tmp = 'B';
	else
		*tmp = 'C';
}
void init_speed(int *speed, int *last)
{
	while (1)
	{
		printf("请输入移动速度（0-5 : 0-按回车单步演示 1-延时最长 5-延时最短）：");
		if (!scanf(" %d", speed))
			*speed = 6;
		if (*speed < 0 || *speed>5)
		{
			FFLUSH;
			continue;
		}
		break;
	}

	if (*speed == 1)
		*last = 1000;
	else if (*speed == 2)
		*last = 500;
	else if (*speed == 3)
		*last = 200;
	else if (*speed == 4)
		*last = 50;
	else if (*speed == 5)
		*last = 1;
	else
		*last = 0;
}
void init_ed(const char st, char *ed)
{
	while (1)
	{
		printf("请输入目标圆柱名（A,B,C）：");
		if (!scanf(" %c", ed))
			*ed = 'D';
		if (!((*ed >= 'A' && *ed <= 'C') || (*ed >= 'a' && *ed <= 'c')))
		{
			FFLUSH;
			continue;
		}
		if (st == *ed)
		{
			printf("起始柱(%c)和目标柱(%c)不能为同一个柱子\n", st, *ed);
			FFLUSH;
			continue;
		}
		return;
	}
}
void init_st(char *st)
{
	while (1)
	{
		printf("请输入起始圆柱名（A,B,C）：");
		if (!scanf(" %c", st))
			*st = 'D';
		if (!((*st >= 'A' && *st <= 'C') || (*st >= 'a' && *st <= 'c')))
		{
			FFLUSH;
			continue;
		}
		return;
	}
}
void init_n(int *n)
{
	while (1)
	{
		printf("请输入盘子的个数（1-10）：");
		if (!scanf(" %d", n))
			*n = 11;
		if (n <= 0 || *n >= 11)
		{
			FFLUSH;
			continue;
		}
		return;
	}
}
bool init_mode(int *mode)
{
	printf("[请选择0-9] ");
	if (!scanf(" %d", mode))
	{
		FFLUSH;
		return 0;
	}
	if (*mode < 0 || *mode>9)
		return 0;
	return 1;
}
int init(int *mode, int *n, char *st, char *ed, int *speed, int *last)
{
	if (!init_mode(mode))
		return 0;
	if (!(*mode))
		return 1;
	FFLUSH;

	if (*mode != 5)
	{
		init_n(n);
		FFLUSH;
		init_st(st);
		FFLUSH;
		init_ed(*st, ed);
		FFLUSH;
	}
	if (*mode == 4 || *mode == 8)
	{
		init_speed(speed, last);
		FFLUSH;
	}

	return 2;
}

//screen operate
void change_screen(const int mode)
{
	if (mode == 1 || mode == 2)
		return;
	if (mode >= 3 && mode <= 7)
		system("mode con cols=100 lines=30");
	else if (mode == 8)
		system("mode con cols=100 lines=36");
	else
		system("mode con cols=100 lines=40");
}
void output_system()
{
	For(i, 1, 35)
		printf("-");
	printf("\n");

	printf("1.基本解\n");
	printf("2.基本解<步数记录>\n");
	printf("3.内部数组显示<横向>\n");
	printf("4.内部数组显示<纵向+横向>\n");
	printf("5.图形解-预备-画三个圆柱\n");
	printf("6.图形解-预备-在起始柱子上画n个盘子\n");
	printf("7.图形解-预备-第一次移动\n");
	printf("8.图形解-自动移动版本\n");
	printf("9.图形解-游戏版\n");
	printf("0.退出\n");

	For(i, 1, 35)
		printf("-");
	printf("\n");
}

int main()
{
	int mode, n, speed, last;
	char st, ed, tmp;

	while (1)
	{
		system("cls");
		system("mode con cols=80 lines=30");

		cnt = mode = n = speed = st = ed = tmp = last = 0;

		output_system();

		int res = init(&mode, &n, &st, &ed, &speed, &last);
		if (!res) // mode select wrong
			continue;
		else if (res == 1) // mode==0
			break;
		change_screen(mode);

		if (mode != 5)
			pre_work(&st, &ed, &tmp);

		if (mode == 1 || mode == 2 || mode == 3 || mode == 4 || mode == 8)
			work(mode, n, st, ed, tmp, speed, last);
		else if (mode == 5)
			put_pillar(30);
		else if (mode == 6)
			img_reset(n, st, ed, 30);
		else if (mode == 7)
		{
			img_reset(n, st, ed, 30);
			Sleep(500);
			if (n == 1)
				move_disk(1, st, n, ed, 1, 30);
			else
				move_disk(1, st, n, tmp, 1, 30);
		}
		else //mode==9
			game_ver(n, st, ed);

		reset_xy(mode);
		printf("按回车继续");
		while (1)
		{
			char op;
			op = _getch();
			if (op == '\n' || op == '\r')
				break;
		}
	}

	return 0;
}

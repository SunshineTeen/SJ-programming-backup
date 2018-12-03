/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<conio.h>
#include<io.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

void clear_img(int line)
{
	gotoxy(hout, 0, line);
	For(i, 1, 100)
		cout << " ";
	gotoxy(hout, 0, line);
}

void select_img(int(*map)[N + 1], File *head, const int lim)
{
	gotoxy(hout, menu_X, menu_Y);
	setcolor(hout, 7, 0);
	File *cur = head;
	int k = 1;
	cout << setiosflags(ios::left) << setw(20) << cur->name;

	int op;
	while ((op = _getch()) != 13)
	{
		if (op != 224)
			continue;
		op = _getch();
		if (op != 72 && op != 80)
			continue;
		if (op == 72)//up
			if (k == 1)
			{
				cur = cur->pre;
				File *p = cur;
				setcolor(hout, 0, 7);
				For(i, 1, lim)
				{
					gotoxy(hout, menu_X, menu_Y + i - 1);
					cout << "                    ";
					gotoxy(hout, menu_X, menu_Y + i - 1);
					cout << setiosflags(ios::left) << setw(20) << p->name;
					p = p->nxt;
				}
			}
			else
			{
				gotoxy(hout, menu_X, menu_Y + k - 1);
				setcolor(hout, 0, 7);
				cout << setiosflags(ios::left) << setw(20) << cur->name;
				--k;
				cur = cur->pre;
			}
		if (op == 80)//down
			if (k == lim)
			{
				cur = cur->nxt;
				File *p = cur;
				setcolor(hout, 0, 7);
				opFor(i, lim, 1)
				{
					gotoxy(hout, menu_X, menu_Y + i - 1);
					cout << "                    ";
					gotoxy(hout, menu_X, menu_Y + i - 1);
					cout << setiosflags(ios::left) << setw(20) << p->name;
					p = p->pre;
				}
			}
			else
			{
				gotoxy(hout, menu_X, menu_Y + k - 1);
				setcolor(hout, 0, 7);
				cout << setiosflags(ios::left) << setw(20) << cur->name;
				++k;
				cur = cur->nxt;
			}
		gotoxy(hout, menu_X, menu_Y + k - 1);
		setcolor(hout, 7, 0);
		cout << setiosflags(ios::left) << setw(20) << cur->name;
	}
	setcolor(hout, 0, 7);

	ifstream infile;
	infile.open(cur->name, ios::in);
	For(i, 1, N) For(j, 1, N)
		infile >> map[i][j];
	infile.close();
}

int input_keyboard(Point &P, int &x, bool const(*fix)[N + 1], int const(*map)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9])
{
	while (1)
	{
		char op = _getch();
		if (op == -32)
		{
			clear_img(high_Y + 3);
			op = _getch();
			Point fp = { 0,0 };
			if (op == 72)
				fp.x = -1;
			else if (op == 80)
				fp.x = 1;
			else if (op == 75)
				fp.y = -1;
			else if (op == 77)
				fp.y = 1;
			Point Q = P;
			P.x += fp.x, P.y += fp.y;
			if (P.x<1 || P.x>N || P.y<1 || P.y>N)
			{
				P = Q;
				continue;
			}
			output_ex(0, Q, fix, map[Q.x][Q.y], f, fx, fy, fz);
			output_ex(1, P, fix, map[P.x][P.y], f, fx, fy, fz);
		}
		else if (op == 8)
			return 2;
		else if (op == 27)
			return -1;
		else
		{
			if (fix[P.x][P.y])
			{
				clear_img(high_Y + 3);
				cout << "You cannot change this value" << endl;
				continue;
			}
			else if (op<'0' || op>'9')
				continue;
			x = op - '0';
			return 1;
		}
	}
	return 1;
}
int input_mouse(Point &P, int &x, bool const(*fix)[N + 1], int const(*map)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9])
{
	Point Q;
	while (1)
	{
		Point pos;
		pos.x = pos.y = 0;
		enable_mouse(hin);
		setcursor(hout, CURSOR_INVISIBLE);
		while (1)
		{
			int mouse_action = read_mouse_and_key(hin, pos.x, pos.y);
			if (mouse_action == MOUSE_RIGHT_BUTTON_CLICK)
				return -1;
			if (mouse_action == VK_BACK)
				return 2;
			if (mouse_action == MOUSE_LEFT_BUTTON_CLICK)
			{
				Q = P;
				if (pos.x > low_X + 1 && pos.x <= high_X && pos.y > low_Y && pos.y <= high_Y)
					P.x = (pos.y - low_Y - 1) / 3 + 1, P.y = (pos.x - low_X - 2) / 6 + 1;
				else
					P.x = 0, P.y = 0;
				break;
			}
		}

		if (Q.x && Q.y)
			output_ex(0, Q, fix, map[Q.x][Q.y], f, fx, fy, fz);
		if (!P.x && !P.y)
			continue;
		if (fix[P.x][P.y])
		{
			clear_img(high_Y + 3);
			cout << "You cannot select this lattice" << endl;
			continue;
		}
		if (P.x && P.y)
			output_ex(1, P, fix, map[P.x][P.y], f, fx, fy, fz);
		char op;
		for (op = _getch(); (op<'0' || op>'9') && op != 27; op = _getch());
		if (op == 27)
		{
			output_ex(0, P, fix, map[P.x][P.y], f, fx, fy, fz);
			P.x = 0, P.y = 0;
			continue;
		}
		x = op - '0';
		break;
	}
	return 1;
}

void menu_output_img(File *f_head, const int limit)
{
	File *p = f_head;
	int i = 1;
	setconsoleborder(hout, 100, 40);
	gotoxy(hout, menu_X - 2, menu_Y - 2);
	cout << "数独样本文件：";
	gotoxy(hout, menu_X - 2, menu_Y - 1);
	cout << "╔══════════╗";
	do
	{
		gotoxy(hout, menu_X - 2, menu_Y + i - 1);
		cout << "║";
		cout << setiosflags(ios::left) << setw(20) << p->name;
		cout << "║" << endl;
		++i;
		p = p->nxt;
	} while (i <= limit);
	gotoxy(hout, menu_X - 2, menu_Y + limit);
	cout << "╚══════════╝";
}
void output_img(int(*map)[N + 1], bool const(*fix)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9], Point P)
{
	For(i, 1, 9) For(j, 1, 9)
	{
		int x = map[i][j] - 1;
		setcolor(hout, f[0][i] | f[1][j] | f[2][rotate(i, j)] ? 7 : 0,
			(i == P.x && j == P.y) ? 10 : ((fx[i][x] > 1) | (fy[j][x] > 1) | (fz[rotate(i, j)][x] > 1) ? 12 : (fix[i][j] ? 11 : 14)));
		int tX = low_X + 2 + 6 * (j - 1);
		gotoxy(hout, tX, low_Y + 3 * (i - 1) + 1);
		cout << "╔═╗";
		gotoxy(hout, tX, low_Y + 3 * (i - 1) + 2);
		cout << "║" << map[i][j] << " ║";
		gotoxy(hout, tX, low_Y + 3 * (i - 1) + 3);
		cout << "╚═╝";
	}
	setcolor(hout, 0, 7);
}
void output_ex(const int mode, Point &P, bool const(*fix)[N + 1], int const x, bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9])
{
	setcolor(hout, mode ? 8 : (f[0][P.x] | f[1][P.y] | f[2][rotate(P.x, P.y)] ? 7 : 0),
		(fx[P.x][x - 1] > 1) | (fy[P.y][x - 1] > 1) | (fz[rotate(P.x, P.y)][x - 1] > 1) ? 12 : (fix[P.x][P.y] ? 11 : 14));

	int tX = low_X + 6 * P.y - 4;
	gotoxy(hout, tX, low_Y + 3 * P.x - 2);
	cout << "╔═╗";
	gotoxy(hout, tX, low_Y + 3 * P.x - 1);
	cout << "║" << x << " ║";
	gotoxy(hout, tX, low_Y + 3 * P.x);
	cout << "╚═╝";
	setcolor(hout, 0, 7);
}

void game_img(const int mode, int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9])
{
	gotoxy(hout, low_X + 2, low_Y);
	For(j, 1, 9)
		cout << "  " << char('a' + j - 1) << "   ";
	For(i, 1, 9)
	{
		gotoxy(hout, low_X, low_Y + 3 * (i - 1) + 2);
		cout << i << ' ';
	}
	Operation *p = NULL;
	bool wrong[3][N + 1] = { 0 };
	int res = check(map, wrong, fx, fy, fz);
	if (res)
	{
		output_img(map, fix, wrong, fx, fy, fz, { 0,0 });
		gotoxy(hout, 0, high_Y + 2);
		if (res == -1)
		{
			cout << "The origin data has been completed." << endl;
			return;
		}
		cout << "There" << (res == 1 ? " is " : " are ") << res << " collision" << (res == 1 ? " " : "s ")
			<< "in the origin data, please check it again !!" << endl;
		return;
	}
	Point P = { 0,0 };
	Point cur = { 1,1 };
	int x;
	while (1)
	{
		output_img(map, fix, wrong, fx, fy, fz, P);

		int f = 0;
		clear_img(high_Y + 2);
		if (mode == 2)
		{
			cout << "请按行/列/值的顺序输入[例:5c6=第5行第c列填入6],输入bk表示退回一次,输入end退出游戏: ";

			char Enter[256] = { "" };
			f = input(P, x, fix, Enter);
			clear_img(high_Y + 4);
			cout << "Your enter: " << Enter;
		}
		else if (mode == 4)
		{
			cout << "请通过上下左右键控制光标,数字键进行填值,Backspace表示回退一次,ESC退出游戏";
			f = input_keyboard(cur, x, fix, map, wrong, fx, fy, fz);
			P = cur;
		}
		else
		{
			cout << "请通过鼠标左键选择格子,数字键进行填值ESC表示撤销选择,Backspace表示回退一次,鼠标右键退出游戏";
			f = input_mouse(P, x, fix, map, wrong, fx, fy, fz);
		}

		if (!f)
			continue;
		if (f == -1)
		{
			clear_img(high_Y + 3);
			cout << "You End the game" << endl;
			return;
		}
		if (f == 2)
		{
			if (p == NULL)
			{
				clear_img(high_Y + 3);
				cout << "This is the beginning" << endl;
				continue;
			}
			cur = P = p->pos;
			x = p->past;
			Operation *tmp = p;
			p = p->pre;
			delete tmp;
		}
		else
		{
			Operation *tmp = new(nothrow) Operation;
			if (tmp == NULL)
			{
				clear_img(high_Y + 3);
				cout << "It's so bad that you've run out of all memory, Game Over" << endl;
				Free_Operation(p);
				return;
			}
			if (p == NULL)
				tmp->pre = NULL;
			else
				tmp->pre = p;
			p = tmp;
			p->pos = P;
			p->past = map[P.x][P.y];
		}
		if (map[P.x][P.y])
			--fx[P.x][map[P.x][P.y] - 1], --fy[P.y][map[P.x][P.y] - 1], --fz[rotate(P.x, P.y)][map[P.x][P.y] - 1];
		map[P.x][P.y] = x;
		if (x)
			++fx[P.x][x - 1], ++fy[P.y][x - 1], ++fz[rotate(P.x, P.y)][x - 1];
		res = check(map, wrong, fx, fy, fz);
		clear_img(high_Y + 3);
		if (res > 0)
			cout << "There" << (res == 1 ? " is " : " are ") << res << " collision" << (res == 1 ? " " : "s ") << "inside" << endl;
		else if (!res)
			cout << "It's a legal operation" << endl;
		else
		{
			output_img(map, fix, wrong, fx, fy, fz, P);
			gotoxy(hout, 0, high_Y + 3);
			cout << "Congratulations! You finish the sudoku" << endl;
			Free_Operation(p);
			break;
		}
	}
	clear_img(high_Y + 5);
}
void work_auto(int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9])
{
	bool wrong[3][N + 1] = { 0 };
	int res = check(map, wrong, fx, fy, fz);

	gotoxy(hout, low_X + 2, low_Y);
	For(j, 1, 9)
		cout << "  " << char('a' + j - 1) << "   ";
	For(i, 1, 9)
	{
		gotoxy(hout, low_X, low_Y + 3 * (i - 1) + 2);
		cout << i << ' ';
	}
	output_img(map, fix, wrong, fx, fy, fz, { 0,0 });

	if (res)
	{
		gotoxy(hout, 0, high_Y + 2);
		if (res == -1)
		{
			cout << "The origin data has been completed." << endl;
			return;
		}
		cout << "There" << (res == 1 ? " is " : " are ") << res << " collision" << (res == 1 ? " " : "s ")
			<< "in the origin data, please check it again !!" << endl;
		return;
	}

	clear_img(high_Y + 1);
	cout << "当前搜索次数: ";
	int ans = dfs(1, 1, map, fix, fx, fy, fz);
	clear_img(high_Y + 2);
	if (ans)
		cout << "The sudoku has been completed";
	else
		cout << "The sudoku is unsolvable";
	clear_img(high_Y + 4);
}

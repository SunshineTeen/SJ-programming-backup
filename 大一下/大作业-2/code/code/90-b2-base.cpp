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

void menu_output_base(File *f_head)
{
	cout << "当前目录下符合sudoku*.txt的文件有" << endl;
	File *p = f_head;
	do
	{
		cout << p->name << "  ";
		p = p->nxt;
	} while (p != f_head);
	cout << endl;
}
int select_base(int(*map)[N + 1])
{
	cout << "请输入数独题目文件名(直接回车默认为sudoku.txt): ";
	char file_name[256] = "";
	cin.getline(file_name, 256);
	if (!strlen(file_name))
		strcpy(file_name, "sudoku.txt");
	ifstream infile;
	infile.open(file_name, ios::in);
	if (!infile.is_open())
	{
		cout << "No Such File" << endl;
		return 0;
	}

	For(i, 1, N) For(j, 1, N)
		infile >> map[i][j];
	infile.close();
	return 1;
}
void game_base(int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9])
{
	Operation *p = NULL;
	bool wrong[3][N + 1] = { 0 };
	int res = check(map, wrong, fx, fy, fz);
	if (res)
	{
		if (res == -1)
		{
			output_base(map, fix, wrong, fx, fy, fz);
			cout << "The origin data has been completed." << endl;
			return;
		}
		cout << "There" << (res == 1 ? " is " : " are ") << res << " collision" << (res == 1 ? " " : "s ") << "inside" << endl;
		output_base(map, fix, wrong, fx, fy, fz);
		cout << endl;
		cout << "The origin data is wrong, please check it again !!" << endl;
		return;
	}
	while (1)
	{
		output_base(map, fix, wrong, fx, fy, fz);
		cout << "请按行/列/值的顺序输入[例:5c6=第5行第c列填入6],输入bk表示退回一次,输入end退出游戏: ";
		Point P;
		int x;
		char Enter[256] = { "" };
		int f = input(P, x, fix, Enter);
		if (!f)
			continue;
		if (f == -1)
		{
			cout << "You End the game" << endl;
			return;
		}
		if (f == 2)
		{
			if (p == NULL)
			{
				cout << "This is the beginning" << endl;
				continue;
			}
			P = p->pos;
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
		if (res > 0)
			cout << "There" << (res == 1 ? " is " : " are ") << res << " collision" << (res == 1 ? " " : "s ") << "inside" << endl;
		else if (!res)
			cout << "It's a legal operation" << endl;
		else
		{
			output_base(map, fix, wrong, fx, fy, fz);
			cout << "Congratulations! You finish the sudoku" << endl;
			Free_Operation(p);
			return;
		}
	}
}
void output_base(int(*map)[N + 1], bool const(*fix)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9])
{
	cout << "-+-a-b-c-+-d-e-f-+-g-h-i-" << endl;
	For(i, 1, N)
	{
		cout << i << "| ";
		For(j, 1, N)
		{
			int x = map[i][j] - 1;
			setcolor(hout, f[0][i] | f[1][j] | f[2][rotate(i, j)] ? 7 : 0,
				(fx[i][x] > 1) | (fy[j][x] > 1) | (fz[rotate(i, j)][x] > 1) ? 12 : (fix[i][j] ? 11 : 14));
			cout << map[i][j];
			setcolor(hout, 0, 7);
			cout << " ";
			if (j == 3 || j == 6)
				cout << "| ";
		}
		cout << endl;
		if (i == 3 || i == 6)
			cout << "-+-------+-------+-------" << endl;
	}
}

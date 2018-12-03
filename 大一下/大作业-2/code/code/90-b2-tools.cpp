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

int get_file(File *&head, int &cnt)
{
	File *tail = NULL;
	long fst_file;
	struct _finddata_t file_info;
	if ((fst_file = _findfirst(".\\sudoku*.txt", &file_info)) == -1L)
	{
		cout << "No Files" << endl;
		return 0;
	}
	do
	{
		++cnt;
		File *p = new(nothrow) File;
		if (p == NULL)
		{
			cout << "No Free Memory" << endl;
			return -1;
		}
		if (head == NULL)
			head = tail = p;
		else
			tail->nxt = p, p->pre = tail, tail = p;
		p->name = new(nothrow) char[strlen(file_info.name) + 1];
		if (p->name == NULL)
		{
			cout << "No Free Memory" << endl;
			return -1;
		}
		strcpy(p->name, file_info.name);
		p->nxt = NULL;
	} while (!_findnext(fst_file, &file_info));
	_findclose(fst_file);

	if (head != tail)
		head->pre = tail, tail->nxt = head;
	else
		head->pre = tail->nxt = head;
	return 1;
}
void Free_file(File *&head)
{
	File *p = head;
	do
	{
		File *tmp = p;
		p = p->nxt;
		delete[] tmp->name;
		delete tmp;
	} while (p != head);
}
void Free_Operation(Operation *p)
{
	while (p != NULL)
	{
		Operation *tmp = p;
		p = p->pre;
		delete tmp;
	}
}

char alpha_upper(const char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 32;
	return ch;
}

int rotate(const int x, const int y)
{
	return (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
}

int input(Point &P, int &x, bool const(*fix)[N + 1], char *res)
{
	P = { 0,0 };
	char op[256] = { "TaihouDaisuki" };
	cin.getline(op, 256);
	strcpy(res, op);
	if (strlen(op) == 2 && alpha_upper(op[0]) == 'B' && alpha_upper(op[1]) == 'K')
		return 2;
	if (strlen(op) != 3)
	{
		cout << "Input Error" << endl;
		return 0;
	}
	if (alpha_upper(op[0]) == 'E' && alpha_upper(op[1]) == 'N' && alpha_upper(op[2]) == 'D')
		return -1;
	if (op[0]<'1' || op[0]>'9')
	{
		cout << "line" << op[0] << "does not fall in [1,9]" << endl;
		return 0;
	}
	if (alpha_upper(op[1]) < 'A' || alpha_upper(op[1]) > 'I')
	{
		cout << "column" << op[1] << "does not fall in [a,i]" << endl;
		return 0;
	}
	if (op[2]<'0' || op[2]>'9')
	{
		cout << "value" << op[2] << "does not fall in [0,9]" << endl;
		return 0;
	}
	P.x = op[0] - '0';
	P.y = alpha_upper(op[1]) - 'A' + 1;
	if (fix[P.x][P.y])
	{
		cout << "You cannot change this value" << endl;
		return 0;
	}
	x = op[2] - '0';
	return 1;
}
void pre_work(int(*map)[N + 1], bool(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9])
{
	For(i, 1, N) For(j, 1, N)
		if (map[i][j])
		{
			++fx[i][map[i][j] - 1];
			++fy[j][map[i][j] - 1];
			++fz[rotate(i, j)][map[i][j] - 1];
			fix[i][j] = 1;
		}

}
int check(int(*map)[N + 1], bool(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9])
{
	For(i, 1, N)
		f[0][i] = f[1][i] = f[2][i] = 0;

	For(i, 1, 9) For(k, 0, 8)
	{
		if (fx[i][k] > 1)
			f[0][i] = 1;
		if (fy[i][k] > 1)
			f[1][i] = 1;
		if (fz[i][k] > 1)
			f[2][i] = 1;
	}
	int cnt_error = 0;
	For(i, 1, N)
		cnt_error += f[0][i] + f[1][i] + f[2][i];
	if (cnt_error > 0)
		return cnt_error;
	For(i, 1, N) For(j, 1, N)
		if (!map[i][j])
			return 0;
	return -1;
}

bool dfs(int x, int y, int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9])
{
	static int step = 0;
	if (y > 9)
		y -= 9, ++x;
	if (x == 10)
		return 1;
	if (fix[x][y])
		return dfs(x, y + 1, map, fix, fx, fy, fz);
	int z = rotate(x, y);
	For(i, 1, 9)
	{
		int num = i - 1;
		if (fx[x][num] | fy[y][num] | fz[z][num])
			continue;
		++fx[x][num];
		++fy[y][num];
		++fz[z][num];
		map[x][y] = i;
		++step;
		gotoxy(hout, 14, high_Y + 1);
		cout << step;
		
		output_img(map, fix, zeros, fx, fy, fz, { x,y });
		if (dfs(x, y + 1, map, fix, fx, fy, fz))
			return 1;
		map[x][y] = 0;
		--fx[x][num];
		--fy[y][num];
		--fz[z][num];
	}
	output_img(map, fix, zeros, fx, fy, fz, { 0,0 });
	return 0;
}

void work(const int mode)
{
	File *file_head = NULL;
	int cnt_file = 0;
	int f = get_file(file_head, cnt_file);
	if (!f)
		return;
	if (f == -1)
	{
		Free_file(file_head);
		return;
	}

	system("cls");
	int limit = Min(cnt_file, 8);
	int map[N + 1][N + 1] = { 0 };
	bool fix[N + 1][N + 1] = { 0 };
	int fx[N + 1][9] = { 0 }, fy[N + 1][9] = { 0 }, fz[N + 1][9] = { 0 };/////////f[][num] => num+1 has been used
	if (mode == 1)
	{
		menu_output_base(file_head);
		if (select_base(map))
		{
			pre_work(map, fix, fx, fy, fz);
			game_base(map, fix, fx, fy, fz);
		}
	}
	else
	{
		menu_output_img(file_head, limit);
		select_img(map, file_head, limit);
		pre_work(map, fix, fx, fy, fz);
		if (mode == 3)
			work_auto(map, fix, fx, fy, fz);
		else
			game_img(mode, map, fix, fx, fy, fz);
	}

	Free_file(file_head);
}

void init(int &mode)
{
	cin >> mode;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		mode = -1;
	}
	FFLUSH;
}
void End()
{
	char op[1024] = "LoveTaihouForever";
	setcolor(hout, 0, 7);
	cout << "本小题结束，请输入End继续..." << endl;
	while (1)
	{
		int p = 0;
		while ((op[++p] = getchar()) != '\n');
		if (alpha_upper(op[1]) != 'E' || alpha_upper(op[2]) != 'N' || alpha_upper(op[3]) != 'D')
		{
			cout << "输入错误" << endl;
			continue;
		}
		return;
	}
}

int read_mouse_and_key(const HANDLE hin, int &X, int &Y, const int enable_read_mouse_moved)
{
	INPUT_RECORD    mouseRec;
	DWORD           res;
	COORD           crPos;

	while (1)
	{
		ReadConsoleInput(hin, &mouseRec, 1, &res);
		if (mouseRec.EventType != MOUSE_EVENT)
			if (mouseRec.EventType == KEY_EVENT && mouseRec.Event.KeyEvent.bKeyDown
				&& mouseRec.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
				return mouseRec.Event.KeyEvent.wVirtualKeyCode;
			else
				continue;

		crPos = mouseRec.Event.MouseEvent.dwMousePosition;
		X = crPos.X;
		Y = crPos.Y;

		if (enable_read_mouse_moved && mouseRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
			return MOUSE_ONLY_MOVED;

		if (mouseRec.Event.MouseEvent.dwButtonState == (FROM_LEFT_1ST_BUTTON_PRESSED | RIGHTMOST_BUTTON_PRESSED))
			return MOUSE_LEFTRIGHT_BUTTON_CLICK;
		else if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_LEFT_BUTTON_DOUBLE_CLICK;
			else
				return MOUSE_LEFT_BUTTON_CLICK;
		}
		else if (mouseRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				return MOUSE_RIGHT_BUTTON_DOUBLE_CLICK;
			else
				return MOUSE_RIGHT_BUTTON_CLICK;
		}
		else
			;
	}
	return MOUSE_NO_ACTION;
}

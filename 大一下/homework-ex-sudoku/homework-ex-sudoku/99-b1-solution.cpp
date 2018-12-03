//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<limits.h>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N = 9;
const int n = N*N * 4;
const int m = N*N*N * 4;
const int Maxp = n + 4 * m + 20;

struct calc
{
	int n;
	int ok[N + 1];
	int i, j;
}cnt[N+3][N+3];
struct DLX
{
	int l, r,up,down;
	int col;
	int i, j, x;

	void clear(int _id)
	{
		l = r = up = down = col = _id;
		i = j = x = 0;
	}
}p[Maxp]; int cnt_p;

int head;
int tot[n + 10];
int pos[N + 3][N + 3][N + 3];

void Delete(int col)
{
	p[p[col].l].r = p[col].r;
	p[p[col].r].l = p[col].l;
	for (int k = p[col].down; k != col; k = p[k].down)
		for (int i = p[k].r; i != k; i = p[i].r)
			p[p[i].up].down = p[i].down, p[p[i].down].up = p[i].up, --tot[p[i].col];
}
void Recover(int col)
{
	for (int k = p[col].up; k != col; k = p[k].up)
		for (int i = p[k].l; i != k; i = p[i].l)
			p[p[i].up].down = p[p[i].down].up = i, ++tot[p[i].col];
	p[p[col].l].r = p[p[col].r].l = col;
}

bool dfs(int sudoku[10][10])
{
	if (p[head].r == head) return 1;
	int mincol = 0, mintot = INT_MAX;
	for (int i = p[head].r; i != head; i = p[i].r)
	{
		if (!tot[i]) return 0;
		if (tot[i] >= mintot) continue;
		mintot = tot[i], mincol = i;
	}
	Delete(mincol);
	for (int i = p[mincol].down; i != mincol; i = p[i].down)
	{
		int _i = p[i].i, _j = p[i].j, _x = p[i].x;
		for (int j = p[i].r; j != i; j = p[j].r) Delete(p[j].col);
		sudoku[_i][_j] = _x; 
		if (dfs(sudoku)) return 1;
		sudoku[_i][_j] = 0;
		for (int j = p[i].l; j != i; j = p[j].l) Recover(p[j].col);
	}
	Recover(mincol);
	return 0;
}
bool work(int sudoku[10][10])
{
	For(i, 1, N) For(j, 1, N) if (sudoku[i][j])
	{
		Delete(p[pos[i][j][sudoku[i][j]]].col);
		for (int k = p[pos[i][j][sudoku[i][j]]].r; k != pos[i][j][sudoku[i][j]]; k = p[k].r)
			Delete(p[k].col);
	}
	return dfs(sudoku);
}

int get_id(int i, int j)
{
	return (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
}
void add(int col, int cnt)
{
	p[p[col].up].down = cnt; p[cnt].up = p[col].up;
	p[cnt].down = col; p[col].up = cnt;
	p[cnt].col = col;
	++tot[col];
}
void insert(int x, int i, int j, int &cnt_p)
{
	For(k, 1, 4)
	{
		p[cnt_p + k].clear(cnt_p + k);
		p[cnt_p + k].l = cnt_p + k - 1;
		p[cnt_p + k].r = cnt_p + k + 1;
		p[cnt_p + k].i = i; p[cnt_p + k].j = j; p[cnt_p + k].x = x;
	}
	p[cnt_p + 1].l = cnt_p + 4; p[cnt_p + 4].r = cnt_p + 1;
	

	add(9 * (i - 1) + j, cnt_p + 1);
	add(81 + 9 * (i - 1) + x, cnt_p + 2);
	add(81 * 2 + 9 * (j - 1) + x, cnt_p + 3);
	add(81 * 3 + 9 * (get_id(i, j) - 1) + x, cnt_p + 4);
	cnt_p += 4;
}
void build_DLX(int sudoku[10][10])
{
	head = 0; cnt_p = 0;

	p[head].clear(cnt_p); p[head].l = p[head].r = head;
	p[++cnt_p].clear(cnt_p); p[cnt_p].l = head; p[head].r = cnt_p;
	p[cnt_p].up = p[cnt_p].down = p[cnt_p].col = cnt_p;
	For(i, 2, n)
		p[++cnt_p].clear(cnt_p), p[cnt_p].l = cnt_p - 1, p[cnt_p - 1].r = cnt_p,
		p[cnt_p].up = p[cnt_p].down = p[cnt_p].col = cnt_p;
	p[cnt_p].r = head, p[head].l = cnt_p;

	For(i, 1, n) tot[i] = 0;
	For(i, 1, N) For(j, 1, N) 
		if (sudoku[i][j])
			pos[i][j][sudoku[i][j]] = cnt_p + 1, insert(sudoku[i][j], i, j, cnt_p);
		else
			For(_i, 1, cnt[i][j].n)
				insert(cnt[i][j].ok[_i], i, j, cnt_p);
}

bool pre_work(int sudoku[10][10])
{
	bool used[N + 1];
	For(i, 1, N) For(j, 1, N)
	{
		if (sudoku[i][j])
			continue;

		cnt[i][j].n = 0;
		For(k, 1, N) used[k] = 0;

		For(k, 1, N)
		{
			if (k == j) continue;
			used[sudoku[i][k]] = 1;
		}
		For(k, 1, N)
		{
			if (k == i) continue;
			used[sudoku[k][j]] = 1;
		}
		int Id = get_id(i, j);
		int basei = (Id - 1) / 3 * 3 + 1;
		int basej = (Id - 1) % 3 * 3 + 1;
		For(k, 1, N)
		{
			int _i = basei + (k - 1) / 3, _j = basej + (k - 1) % 3;
			if (i == _i && j == _j) continue;
			used[sudoku[_i][_j]] = 1;
		}
		
		int &n = cnt[i][j].n;
		For(k, 1, N) if (!used[k])
			cnt[i][j].ok[++n] = k;
		if (!n)	return 0;
	}
	return 1;
}
bool check(int sudoku[10][10])
{
	bool f[N + 1];
	For(i, 1, N)
	{
		For(k, 1, N) f[k] = 0;
		For(j, 1, N) if (sudoku[i][j])
		{
			if (f[sudoku[i][j]]) return 0;
			f[sudoku[i][j]] = 1;
		}
	}
	For(j, 1, N)
	{
		For(k, 1, N) f[k] = 0;
		For(i, 1, N) if (sudoku[i][j])
		{
			if (f[sudoku[i][j]]) return 0;
			f[sudoku[i][j]] = 1;
		}
	}
	For(Id, 1, N)
	{
		For(k, 1, N) f[k] = 0;
		int basei = (Id - 1) / 3 * 3 + 1;
		int basej = (Id - 1) % 3 * 3 + 1;
		For(k, 1, N)
		{
			int i = basei + (k - 1) / 3, j = basej + (k - 1) % 3;
			if (sudoku[i][j])
			{
				if (f[sudoku[i][j]]) return 0;
				f[sudoku[i][j]] = 1;
			}
		}
	}
	return 1;
}

int solving_sudoku(int sudoku[9][9])
{
	int _sudoku[10][10] = {0};
	For(i, 0, 8) For(j, 0, 8)
	{
		if (sudoku[i][j] < 0 || sudoku[i][j]>9)	return -1;
		_sudoku[i + 1][j + 1] = sudoku[i][j];
	}

	if (!check(_sudoku)) return -2;
	if (!pre_work(_sudoku)) return -3;
	build_DLX(_sudoku);

	bool f = work(_sudoku);
	if (f)
	{
		For(i, 0, 8) For(j, 0, 8)
			sudoku[i][j] = _sudoku[i + 1][j + 1];
	}
	return f ? 0 : -3;
}

/* 返回值：0  ：有解
-1 : 原始数据有0-9之外的非法值
-2 ：原始值行/列/九宫有冲突
-3 ：无解
-4 : 其它错误（无内存等）
*/

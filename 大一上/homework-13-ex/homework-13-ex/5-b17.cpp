/* 学号:1652228 姓名:王哲源 班级:计算机一班 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<ctime>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

void output(int map[][31], const int n, const int m)
{
	For(i, 1, n)
	{
		For(j, 1, m - 1)
			if (map[i][j] == -1)
				printf("* ");
			else
				printf("%d ", map[i][j]);
		if (map[i][m] == -1)
			printf("*\n");
		else
			printf("%d\n", map[i][m]);
	}
}

void cnt_mine(int map[][31], const int n, const int m)
{
	const int fx[8] = { 0,-1,-1,-1,0,1,1,1 };
	const int fy[8] = { -1,-1,0,1,1,1,0,-1 };
	For(i,1,n)
		For(j, 1, m)
		{
			if (map[i][j] == -1) continue;
			For(k, 0, 7)
				if (map[i + fx[k]][j + fy[k]] == -1)
					++map[i][j];
		}
}

inline bool sur(int map[][31], const int x, const int y, const int n, const int m)
{
	if (!x || x == n + 1 || !y || y == m + 1)
		return 0;
	return (map[x - 1][y] < 0 && map[x + 1][y] < 0 && map[x][y - 1] < 0 && map[x][y + 1] < 0);
}
inline bool check(int map[][31], const int x, const int y, const int n, const int m)
{
	if (sur(map, x - 1, y, n, m) || sur(map, x + 1, y, n, m)
		|| sur(map, x, y - 1, n, m) || sur(map, x, y + 1, n, m))
		return 0;
	return 1;
}
void set_mine(int map[][31], const int n, const int m)
{
	int cnt = 50;
	srand((unsigned)time(0));
	while (cnt)
	{
		int x = rand() % n + 1;
		int y = rand() % m + 1;
		if (map[x][y] == -1 || !check(map, x, y, n, m))
			continue;
		map[x][y] = -1;
		--cnt;
	}
}

void reset(int map[][31], const int n, const int m)
{
	const int inf = -999495;

	For(i, 1, n)
		For(j, 1, m)
			map[i][j] = 0;
	For(i, 0, n + 1)
		map[i][0] = map[i][m + 1] = inf;
	For(j, 0, m + 1)
		map[0][j] = map[n + 1][j] = inf;
}

int main()
{
	const int inf = 99999999 + 413;
	const int n = 10;
	const int m = 26;
	int map[n + 5][m + 5];

	reset(map, n, m);
	set_mine(map, n, m);
	cnt_mine(map, n, m);
	output(map, n, m);

	return 0;
}
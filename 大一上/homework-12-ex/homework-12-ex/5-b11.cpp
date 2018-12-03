/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;

inline void output(int base, int lim, int cal[][30])
{
	cout << setw(13) << 3 * base + 1;
	printf("月            ");
	printf("     ");

	cout << setw(13) << 3 * base + 2;
	printf("月            ");
	printf("     ");

	cout << setw(13) << 3 * base + 3;
	printf("月            ");
	printf("     \n");

	printf("Sun Mon Tue Wed Thu Fri Sat     ");
	printf("Sun Mon Tue Wed Thu Fri Sat     ");
	printf("Sun Mon Tue Wed Thu Fri Sat     ");
	printf("\n");
	For(i, 1, lim)
	{
		For(j, 0, 20)
		{
			if (cal[i][j])
			{
				cout << setw(3) << cal[i][j];
				printf(" ");
			}
			else
				printf("    ");
			if (j % 7 == 6)
				printf("    ");
		}
		printf("\n");
	}
	printf("\n");

}
inline int calc(int m, bool leapyear)
{
	int tot;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		tot = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		tot = 30;
	else
		tot = 28 + leapyear;
	return tot;
}
void work(int y,int d)
{
	bool leapyear;
	if ((!(y % 4) && (y % 100)) || !(y % 400))
		leapyear = 1;
	else
		leapyear = 0;

	const int Maxn = 10;
	const int Maxm = 30;
	int cal[Maxn][Maxm];

	For(i, 0, 3)
	{
		For(_i, 0, Maxn - 1)
			For(_j, 0, Maxm - 1)
				cal[_i][_j] = 0;

		int line = 0;
		For(j, 1, 3)
		{
			int tot = calc(3 * i + j, leapyear);
			int x = 1, y = 7 * (j - 1) + d % 7;
			int lim = 7 * j;
			For(k, 1, tot)
			{
				if (y >= lim)
				{
					y -= 7;
					++x;
				}
				cal[x][y] = k;
				++y;
				++d;
			}
			line = Max(line, x);
			d %= 7;
			if (!d)
				d = 7;
		}

		output(i, line, cal);
	}
}

int zeller(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		--year;
	}
	int c = year / 100;
	year %= 100;
	int w = year + year / 4 + c / 4 - 2 * c + (13 * (month + 1) / 5) + day - 1;
	while (w < 0)
		w += 7;
	return w;
}
int main()
{
	system("mode con cols=100 lines=40");

	int y;
	printf("请输入年份(1900-2100) : ");
	scanf(" %d", &y);

	int d = (zeller(y, 1, 1) + 7) % 7;

	work(y,d);

	//system("pause");/////////////////////////
	return 0;
}

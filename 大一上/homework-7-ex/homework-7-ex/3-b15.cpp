//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include <windows.h> //取系统时间

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{	
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&fc_begin);	//获得初始硬件定时器计数

										/* 此处是你的程序开始 */
	const int STD = 1953;
	int cnt = 0;
	For(i, 100, 997)
	{
		int a = i / 100, b = i % 100 / 10, c=i % 10;
		if (!a || !b || !c || a == b || a == c || b == c)
			continue;
		For(j, i + 1, 998)
		{
			int d = j / 100, e = j % 100 / 10, f = j % 10;
			if (!d || !e || !f || d == e || d == f || e == f
				|| d == a || d == b || d == c
				|| e == a || e == b || e == c
				|| f == a || f == b || f == c)
				continue;
			For(k, j + 1, 998)
			{
				int x = k / 100, y = k % 100 / 10, z = k % 10;
				if (!x || !y || !z || x == y || x == z || y == z
					|| x == a || x == b || x == c || x == d || x == e || x == f
					|| y == a || y == b || y == c || y == d || y == e || y == f
					|| z == a || z == b || z == c || z == d || z == e || z == f)
					continue;
				if (i + k + j == STD)
				{
					++cnt;
					printf("No.");
					cout << setw(3) << cnt;
					printf(" : %d+%d+%d=1953\n", i, j, k);
				}
			}
		}
	}

	printf("total=%d\n", cnt);
										/* 此处是你的程序结束 */

	QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "时钟频率：" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "时钟计数：" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;

	return 0;
}

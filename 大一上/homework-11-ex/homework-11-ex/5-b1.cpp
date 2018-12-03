/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{
	const int n = 10;
	const int Maxn = n + 10;
	int a[Maxn][Maxn];

	a[1][1] = 1;
	For(i, 2, n)
	{
		a[i][1] = a[i][i] = 1;
		For(j, 2, i - 1)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
	For(i, 1, n)
	{
		For(j, 1, n - i)
			printf("   ");
		For(j, 1, i)
		{
			cout << setw(5) << a[i][j];
			printf(" ");
		}
		printf("\n");
	}

	return 0;
}
/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{
	const int Maxn = 15;
	int a[Maxn][Maxn];

	a[1][1] = 1;
	For(i, 2, 10)
	{
		a[i][1] = a[i][i] = 1;
		For(j, 2, i - 1)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
	For(i, 1, 10)
	{
		cout << a[i][1];
		For(j, 2, i)
		{
			cout << ' ';
			cout << setw(4) << a[i][j] ;
		}
		printf("\n");
	}

	return 0;
}
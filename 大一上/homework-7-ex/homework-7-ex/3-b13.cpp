//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)

using namespace std;

int main()
{
	For(i, 1, 9)
	{
		sFor(j, 1, i)
		{
			int ans = i*j;
			printf("%dx%d=", j, i);
			cout << setw(2) << i*j;
			printf("  ");
		}
		printf("%dx%d=", i, i);
		cout << setw(2) << i*i << endl;
	}

	return 0;
}
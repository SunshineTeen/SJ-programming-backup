/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')

using namespace std;

const int Maxl = 35;

void work(const int n, char *bin)
{
	int sum = 0, BIN = 1;
	opFor(i, n, 1)
	{
		sum += (*(bin + i) == '1')*BIN;
		BIN *= 2;
	}
	printf("十进制数为: %d\n", sum);
}

void init(int *n, char *bin)
{
	while (1)
	{
		printf("请输入一个长度不超过32的二进制数\n");
		scanf(" %s", bin + 1);
		int len = strlen(bin + 1);
		bool fail = 0;
		For(i, 1, len)
			if ((*(bin + i) != '0') && (*(bin + i) != '1'))
			{
				fail = 1;
				FFLUSH;
				break;
			}
		if (!fail)
		{
			*n = len;
			return;
		}
	}
}

int main()
{
	int n;
	char bin[Maxl];
	init(&n, bin);
	work(n, bin);

	return 0;
}

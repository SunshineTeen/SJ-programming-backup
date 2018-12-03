/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')

using namespace std;

const int Maxn = 30;

void output(const int n, int *A)
{
	printf("移动后的数组为\n");
	For(i, 1, n)
		printf("%d ", *(A + i));
	printf("\n");
}

inline void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void work(const int n, const int m, int *A)
{
	int tmp[Maxn] = { 0 };
	int *t = tmp;
	For(i, 1, n - m)
		*(t + i) = *(A + i);
	For(i, 1, m)
		*(A + i) = *(A + n - m + i);
	For(i, 1 + m, n)
		*(A + i) = *(t + i - m);

}

void init_A(const int n, int *A)
{
	while (1)
	{
		bool init_fail = 0;
		printf("请输入n个整数\n");
		For(i, 1, n)
			if (!scanf(" %d", A+i))
			{
				init_fail = 1;
				break;
			}
		FFLUSH;
		if (!init_fail)
			break;
	}
}
void init_m(const int n,int *m)
{
	while (1)
	{
		printf("请输入后移的位置个数m(0-20) ");
		if (!scanf(" %d", m))
			*m = n;
		FFLUSH;
		if ((*m) >= n)
		{
			printf("输入不合法\n");
			continue;
		}
		if ((*m) >= 0)
			break;
	}
}
void init_n(int *n)
{
	while (1)
	{
		printf("请输入数列的长度n(1-20) ");
		if (!scanf(" %d", n))
			*n = 0;
		FFLUSH;
		if (*n >= 1 && *n<=20)
			break;
	}
}
void init(int *n, int *m, int *A)
{
	init_n(n);
	init_m(*n,m);
	init_A(*n, A);
}

int main()
{
	int n, m;
	int A[Maxn];
	
	init(&n, &m, A);
	work(n, m, A);
	output(n, A);

	return 0;
}

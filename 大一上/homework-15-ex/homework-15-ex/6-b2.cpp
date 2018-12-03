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

const int Maxl = 50;

void output(int *pc)
{
	while (*pc != -1)
		printf("%d ", *(pc++));
	printf("\n");
}

void merge(int *la, int *lb, int *lc)
{
	while (*la != -1 || *lb != -1)
	{
		int ta = *la, tb = *lb;
		if (ta == -1)
		{
			*(lc++) = *(lb++);
			continue;
		}
		if (tb == -1)
		{
			*(lc++) = *(la++);
			continue;
		}
		if (ta < tb)
			*(lc++) = *(la++);
		else
			*(lc++) = *(lb++);
	}
	*lc = -1;
}

int main()
{
	int a[] = { 1,2,5,9,10,16,-1 };
	int b[] = { 3,4,6,7,8,-1 };
	int c[Maxl] = { 0 };

	merge(a, b, c);
	output(c);

	return 0;
}

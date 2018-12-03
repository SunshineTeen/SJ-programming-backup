//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)

using namespace std;

int main()
{
	For(i, 2, 1000)
	{
		int sum = 0;
		sFor(j, 1, i - 1)
			if (!(i%j))
				sum += j;
		if (i != sum)
			continue;

		printf("%d,its factors are ",i);
		int tmp = 1;
		For(j, 2, i - 1)
			if (!(i%j))
			{
				printf("%d,", tmp);
				tmp = j;
			}
		printf("%d\n", tmp);
	}

	return 0;
}
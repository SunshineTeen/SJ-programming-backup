//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入两个正整数m和n\n");

	int n, m;
	scanf(" %d %d", &n, &m);

	int a,b,r;
	a = n;
	b = m;

	while (1)
	{
		r = a % b;
		if (!r)
			break;
		a = b;
		b = r;
	}
	a = n*m / b;

	printf("两个数的最小公约数为:%d\n", b);
	printf("两个数的最大公倍数为:%d\n", a);

	return 0;
}
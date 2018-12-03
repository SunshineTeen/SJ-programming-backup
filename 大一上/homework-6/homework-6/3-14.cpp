//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("请输入四个int范围内的整数\n");

	int a, b, c, d,tmp;
	scanf(" %d %d %d %d", &a, &b, &c, &d);

	if (a > b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}
	if (a > c)
	{
		tmp = c;
		c = a;
		a = tmp;
	}
	if (a > d)
	{
		tmp = d;
		d = a;
		a = tmp;
	}
	if (b > c)
	{
		tmp = c;
		c = b;
		b = tmp;
	}
	if (b > d)
	{
		tmp = d;
		d = b;
		b = tmp;
	}
	if (c > d)
	{
		tmp = d;
		d = c;
		c = tmp;
	}
	printf("四个数的从小到大排序为:%d %d %d %d\n", a, b, c, d);

	return 0;
}
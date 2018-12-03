//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入一个介于[0.01,100)的浮点数表示找的零钱\n");

	double x;
	scanf(" %lf", &x);
	x += 0.001;

	int a, b, c, d, e, f, g, h, i, j;//分别为50元到1分的个数

	a = int(x / 50);
	x -= 50 * a;

	b = int(x / 20);
	x -= 20 * b;

	c = int(x / 10);
	x -= 10 * c;

	d = int(x / 5);
	x -= 5 * d;

	e = int(x / 1);
	x -= 1 * e;

	f = int(x / 0.5);
	x -= 0.5*f;

	g = int(x / 0.1);
	x -= 0.1*g;

	h = int(x / 0.05);
	x -= 0.05*h;

	i = int(x / 0.02);
	x -= 0.02*i;

	j = int(x / 0.01);
	x -= 0.01*j;

	int sum = a + b + c + d + e + f + g + h + i + j;
	printf("总数量为%d\n", sum);
	printf("具体为:\n");
	if (a)
		printf("50元 * %d\n", a);
	if (b)
		printf("20元 * %d\n", b);
	if (c)
		printf("10元 * %d\n", c);
	if (d)
		printf("5元 * %d\n", d);
	if (e)
		printf("1元 * %d\n", e);
	if (f)
		printf("5角 * %d\n", f);
	if (g)
		printf("1角 * %d\n", g);
	if (h)
		printf("5分 * %d\n", h);
	if (i)
		printf("2分 * %d\n", i);
	if (j)
		printf("1分 * %d\n", j);

	return 0;
}
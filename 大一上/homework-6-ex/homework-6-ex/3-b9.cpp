//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("������һ������[0.01,100)�ĸ�������ʾ�ҵ���Ǯ\n");

	double x;
	scanf(" %lf", &x);
	x += 0.001;

	int a, b, c, d, e, f, g, h, i, j;//�ֱ�Ϊ50Ԫ��1�ֵĸ���

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
	printf("������Ϊ%d\n", sum);
	printf("����Ϊ:\n");
	if (a)
		printf("50Ԫ * %d\n", a);
	if (b)
		printf("20Ԫ * %d\n", b);
	if (c)
		printf("10Ԫ * %d\n", c);
	if (d)
		printf("5Ԫ * %d\n", d);
	if (e)
		printf("1Ԫ * %d\n", e);
	if (f)
		printf("5�� * %d\n", f);
	if (g)
		printf("1�� * %d\n", g);
	if (h)
		printf("5�� * %d\n", h);
	if (i)
		printf("2�� * %d\n", i);
	if (j)
		printf("1�� * %d\n", j);

	return 0;
}
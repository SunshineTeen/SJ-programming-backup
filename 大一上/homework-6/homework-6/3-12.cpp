//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("请输入一个不多于5位的正整数\n");

	int x;
	scanf(" %d", &x);

	int a, b, c, d, e;//提取各位数字
	a = x / 10000;
	x -= 10000 * a;

	b = x / 1000;
	x -= 1000 * b;

	c = x / 100;
	x -= 100 * c;

	d = x / 10;
	x -= 10 * d;

	e = x;

	printf("这个数是");
	if (a)//万位非0，以下相同
		printf("五位数");
	else if(b)
		printf("四位数");
	else if(c)
		printf("三位数");
	else if (d)
		printf("二位数");
	else 
		printf("一位数");
	printf("\n");

	printf("正序：%d %d %d %d %d\n", a, b, c, d, e);
	printf("逆序：%d %d %d %d %d\n", e, d, c, b, a);

	return 0;
}
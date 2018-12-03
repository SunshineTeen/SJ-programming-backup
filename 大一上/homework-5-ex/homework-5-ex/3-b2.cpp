/* 学号:1652228 班级:计算机一班 姓名:王哲源 */
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main()
{
	printf("请输入一个[1,30000]的整数\n");
	int x, a, b, c, d, e;
	scanf(" %d", &x);

	a = x / 10000;            //提取万位(下同)
	x -= 10000 * a;           //去除万位(下同)

	b = x / 1000;
	x -= 1000 * b;

	c = x / 100;
	x -= 100 * c;

	d = x / 10;
	x -= 10 * d;

	e = x;

	printf("万位：%d\n", a);
	printf("千位：%d\n", b);
	printf("百位：%d\n", c);
	printf("十位：%d\n", d);
	printf("个位：%d\n", e);

	return 0;
}
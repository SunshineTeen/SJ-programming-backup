//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入三个实数表示三角形的三条边长\n");

	double a, b, c,tmp;
	scanf(" %lf %lf %lf", &a, &b, &c);
	
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a > c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b > c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}//三边从小到大排序

	if (a + b > c)
	{
		double p = (a + b + c) / 2;
		double S = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("三角形的面积为:%lf\n", S);
	}
	else
		printf("您输入的数据有误，无法构成三角形\n");

	return 0;
}
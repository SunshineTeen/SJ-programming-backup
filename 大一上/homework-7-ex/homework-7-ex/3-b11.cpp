//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入e^x中指数x的数值\n");

	double x;
	scanf(" %lf", &x);

	const double eps = 1e-6;
	double a = 1, b = 1, sum = 0, tmp=1;
	int i=1;

	do
	{
		sum += tmp;
		a *= x;
		b *= i;
		++i;
		tmp = a / b;
	} while (tmp >= eps);

	printf("e^x的近似值为 %.6lf\n", sum);

	return 0;
}
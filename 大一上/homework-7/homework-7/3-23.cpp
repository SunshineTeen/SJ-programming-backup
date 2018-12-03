//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;

int main()
{
	printf("请输入要求平方根的整数\n");

	double a;
	scanf(" %lf", &a);

	const double eps = 1e-5;
	double x1=0, x2=a;

	do
	{
		x1 = x2;
		x2 = 0.5*(x1 + a / x1);
	} while (fabs(x1 - x2) >= eps);

	printf("迭代法求出的平方根为%.5lf\n", x2);

	return 0;
}
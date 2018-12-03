/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double F_(double f,double a, double b, double c, double x)
{
	double k = 3 * a*x*x + 2 * b*x + c;
	return -f / k + x;
}

double F(double a, double b, double c, double d,double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

int main()
{
	double a, b, c, d;

	printf("请顺序输入一元三次方程的四个系数 1 , 2 , 3 , 4 : ");
	scanf(" %lf %lf %lf %lf", &a, &b, &c, &d);
	printf("\n");

	const double eps = 1e-6;
	double x0 = 1,tmp;

	while (fabs(tmp=F(a, b, c, d, x0)) >= eps)
		x0 = F_(tmp,a, b, c,x0);

	printf("该一元三次方程在x=1附近的实根为 x = %.6lf\n", x0);

	return 0;
}
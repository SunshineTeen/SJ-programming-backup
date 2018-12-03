/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work_0(double b, double c)
{
	printf("该方程的根为 : x=");
	cout << (-c / b) << endl;
}

void work_1(double a, double b)
{
	const double eps = 1e-6;
	double tmp = -b / (2 * a);
	if (fabs(tmp) < eps)
		tmp = 0;

	printf("方程有两个相等实根\n");
	cout << "x1 = x2 = " << tmp << endl;
}

void work_2(double a, double b, double delta)
{
	const double eps = 1e-6;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < eps)
		x1 = 0;
	if (fabs(x2) < eps)
		x2 = 0;

	printf("方程有两个不相等实根\n");
	cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
}

void work_3(double a, double b, double delta)
{
	const double eps = 1e-6;
	double common = -b / (2 * a);
	double tmp = sqrt(fabs(delta)) / (2 * a);

	printf("方程有两个不相等虚根\n");
	if (fabs(common) < eps)
	{
		cout << "x1 = " << tmp << 'i' << endl;
		cout << "x2 = " << "-" << tmp << 'i' << endl;
	}
	else
	{
		cout << "x1 = " << common << "+" << tmp << 'i' << " , ";
		cout << "x2 = " << common << "-" << tmp << 'i' << endl;
	}
}
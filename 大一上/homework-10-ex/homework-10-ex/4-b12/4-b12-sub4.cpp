/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

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
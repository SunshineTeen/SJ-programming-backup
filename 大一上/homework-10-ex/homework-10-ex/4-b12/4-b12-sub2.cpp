/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work_1(double a, double b)
{
	const double eps = 1e-6;
	double tmp = -b / (2 * a);
	if (fabs(tmp) < eps)
		tmp = 0;

	printf("方程有两个相等实根\n");
	cout << "x1 = x2 = " << tmp << endl;
}
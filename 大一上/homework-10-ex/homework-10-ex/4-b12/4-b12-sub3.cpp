/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work_2(double a, double b, double delta)
{
	const double eps = 1e-6;
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < eps)
		x1 = 0;
	if (fabs(x2) < eps)
		x2 = 0;

	printf("���������������ʵ��\n");
	cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
}
/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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

	printf("�������������ʵ��\n");
	cout << "x1 = x2 = " << tmp << endl;
}
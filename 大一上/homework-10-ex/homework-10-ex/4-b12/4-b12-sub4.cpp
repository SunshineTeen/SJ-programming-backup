/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work_3(double a, double b, double delta)
{
	const double eps = 1e-6;
	double common = -b / (2 * a);
	double tmp = sqrt(fabs(delta)) / (2 * a);

	printf("������������������\n");
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
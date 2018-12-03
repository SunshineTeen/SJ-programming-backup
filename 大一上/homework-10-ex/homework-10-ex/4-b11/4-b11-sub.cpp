/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void work_0(double b, double c)
{
	printf("�÷��̵ĸ�Ϊ : x=");
	cout << (-c / b) << endl;
}

void work_1(double a, double b)
{
	const double eps = 1e-6;
	double tmp = -b / (2 * a);
	if (fabs(tmp) < eps)
		tmp = 0;

	printf("�������������ʵ��\n");
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

	printf("���������������ʵ��\n");
	cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
}

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
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("��˳������һԪ���η��̵�����ϵ��\n");

	double a, b, c;
	scanf(" %lf %lf %lf", &a, &b, &c);

	const double eps = 1e-6;
	if (fabs(a) < eps)
		printf("����һԪ���η���\n");
	else
	{
		double delta = b * b - 4 * a * c;
		if (fabs(delta) < eps)
		{
			double tmp = -b / (2 * a);
			if (fabs(tmp) < eps)
				tmp = 0;

			printf("�������������ʵ��\n");
			cout << "x1 = x2 = " << tmp << endl;
		}
		else if (delta > 0)
		{
			double x1 = (-b + sqrt(delta)) / (2 * a);
			double x2 = (-b - sqrt(delta)) / (2 * a);
			if (fabs(x1) < eps)
				x1 = 0;
			if (fabs(x2) < eps)
				x2 = 0;

			printf("���������������ʵ��\n");
			cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
		}
		else //delta<0
		{
			double common = -b / (2 * a);
			double tmp = sqrt(fabs(delta))/ (2 * a);
			
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
	}
	
	return 0;
}

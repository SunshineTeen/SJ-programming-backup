//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("������e^x��ָ��x����ֵ\n");

	double x;
	scanf(" %lf", &x);

	const double eps = 1e-6;
	double a = 1, b = 1, sum = 0, tmp=1;
	int i=1;

	do
	{
		sum += tmp;
		a *= x;
		b *= i;
		++i;
		tmp = a / b;
	} while (tmp >= eps);

	printf("e^x�Ľ���ֵΪ %.6lf\n", sum);

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;

int main()
{
	printf("������Ҫ��ƽ����������\n");

	double a;
	scanf(" %lf", &a);

	const double eps = 1e-5;
	double x1=0, x2=a;

	do
	{
		x1 = x2;
		x2 = 0.5*(x1 + a / x1);
	} while (fabs(x1 - x2) >= eps);

	printf("�����������ƽ����Ϊ%.5lf\n", x2);

	return 0;
}
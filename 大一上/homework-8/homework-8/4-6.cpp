/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double F_(double f,double a, double b, double c, double x)
{
	double k = 3 * a*x*x + 2 * b*x + c;
	return -f / k + x;
}

double F(double a, double b, double c, double d,double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

int main()
{
	double a, b, c, d;

	printf("��˳������һԪ���η��̵��ĸ�ϵ�� 1 , 2 , 3 , 4 : ");
	scanf(" %lf %lf %lf %lf", &a, &b, &c, &d);
	printf("\n");

	const double eps = 1e-6;
	double x0 = 1,tmp;

	while (fabs(tmp=F(a, b, c, d, x0)) >= eps)
		x0 = F_(tmp,a, b, c,x0);

	printf("��һԪ���η�����x=1������ʵ��Ϊ x = %.6lf\n", x0);

	return 0;
}
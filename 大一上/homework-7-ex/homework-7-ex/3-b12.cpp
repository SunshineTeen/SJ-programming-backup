//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	double l = 0, r = 1;
	const double eps = 1e-6;

	while (fabs(l - r) >= eps)
	{
		double mid = (l + r) / 2;
		double F = 2 * mid*mid*mid - 9 * mid*mid + 12 * mid - 3;
		F < 0 ? l = mid : r = mid;
	}
	printf("����2*x^3-9*x^2+12*x-3=0��(0,1)��ĸ�����ֵΪx=%.6lf\n", l);

	return 0;
}
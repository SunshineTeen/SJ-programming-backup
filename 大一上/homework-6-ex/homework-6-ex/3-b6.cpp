//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("�������������ֱ�������ʾ�����ε���������\n");

	double ax, ay, bx, by, cx, cy;
	scanf(" %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);

	double ux = bx - ax, uy = by - ay;
	double vx = cx - ax, vy = cy - ay;
	double S = fabs(ux*vy - uy*vx)/2;
	const double eps = 1e-6;
	
	if (S < eps)
		printf("����������������޷�����������\n");
	else
		printf("�����ε����Ϊ:%lf\n", S);

	return 0;
}
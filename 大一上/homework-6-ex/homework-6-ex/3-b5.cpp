//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("����������ʵ����ʾ�����ε������߳�\n");

	double a, b, c,tmp;
	scanf(" %lf %lf %lf", &a, &b, &c);
	
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a > c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}
	if (b > c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}//���ߴ�С��������

	if (a + b > c)
	{
		double p = (a + b + c) / 2;
		double S = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("�����ε����Ϊ:%lf\n", S);
	}
	else
		printf("����������������޷�����������\n");

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("���������ƽ��ֱ������ϵ�ϵ�����\n");

	const double eps = 1e-6;
	double x, y;
	scanf(" %lf %lf", &x, &y);
	
	printf("������λ�õĸ߶�Ϊ:");
	if (fabs(x) < eps || fabs(y) < eps || fabs(x) > 3 || fabs(y) > 3)
		printf("0\n");
	else if (y > 0)
	{
		if (x > 0)//��һ����
		{
			if (x + y <= 3)
				printf("1\n");
			else
				printf("0\n");
		}
		else //�ڶ�����
		{
			if (y - x <= 3)
				printf("2\n");
			else
				printf("0\n");
		}
	}
	else
	{
		if (x < 0)//��������
		{
			if (x + y >= -3)
				printf("3\n");
			else
				printf("0\n");
		}
		else //��������
		{
			if (y - x >= -3)
				printf("4\n");
			else
				printf("0\n");
		}
	}

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("���������������ֱ��ʾ������\n");

	int x, y, z;
	scanf(" %d %d %d", &x, &y, &z);
	if (y <= 0 || z <= 0)
	{
		printf("�������\n");
		return 0;
	}
	
	bool LeapYear;
	if ((!(x % 4) && (x % 100)) || !(x % 400))
		LeapYear = 1;
	else 
		LeapYear = 0;

	int sum;
	switch (y)
	{
		case 1:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 2:
			if ((!LeapYear && (z>28)) || (LeapYear && (z>29)))
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 3:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 4:
			if (z > 30)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31+z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 5:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 6:
			if (z > 30)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 7:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 8:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 9:
			if (z > 30)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 10:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 11:
			if (z > 30)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		case 12:
			if (z > 31)
			{
				printf("�������\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + z;
				printf("���Ǹ���ĵ�%d��\n", sum);
				break;
			}
		default:
			printf("�������\n");
	}

	return 0;
}
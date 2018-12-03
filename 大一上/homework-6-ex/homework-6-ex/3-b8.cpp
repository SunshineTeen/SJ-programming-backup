//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入三个整数分别表示年月日\n");

	int x, y, z;
	scanf(" %d %d %d", &x, &y, &z);
	if (y <= 0 || z <= 0)
	{
		printf("输入错误\n");
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
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 2:
			if ((!LeapYear && (z>28)) || (LeapYear && (z>29)))
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 3:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 4:
			if (z > 30)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31+z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 5:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 6:
			if (z > 30)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 7:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 8:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 9:
			if (z > 30)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 10:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 11:
			if (z > 30)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		case 12:
			if (z > 31)
			{
				printf("输入错误\n");
				break;
			}
			else
			{
				sum = 31 + 28 + LeapYear + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + z;
				printf("这是该年的第%d天\n", sum);
				break;
			}
		default:
			printf("输入错误\n");
	}

	return 0;
}
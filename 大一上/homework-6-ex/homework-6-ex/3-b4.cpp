//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入点在平面直角坐标系上的坐标\n");

	const double eps = 1e-6;
	double x, y;
	scanf(" %lf %lf", &x, &y);
	
	printf("点所在位置的高度为:");
	if (fabs(x) < eps || fabs(y) < eps || fabs(x) > 3 || fabs(y) > 3)
		printf("0\n");
	else if (y > 0)
	{
		if (x > 0)//第一象限
		{
			if (x + y <= 3)
				printf("1\n");
			else
				printf("0\n");
		}
		else //第二象限
		{
			if (y - x <= 3)
				printf("2\n");
			else
				printf("0\n");
		}
	}
	else
	{
		if (x < 0)//第三象限
		{
			if (x + y >= -3)
				printf("3\n");
			else
				printf("0\n");
		}
		else //第四象限
		{
			if (y - x >= -3)
				printf("4\n");
			else
				printf("0\n");
		}
	}

	return 0;
}
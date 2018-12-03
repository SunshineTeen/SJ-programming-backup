//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("请输入三个点的直角坐标表示三角形的三个定点\n");

	double ax, ay, bx, by, cx, cy;
	scanf(" %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);

	double ux = bx - ax, uy = by - ay;
	double vx = cx - ax, vy = cy - ay;
	double S = fabs(ux*vy - uy*vx)/2;
	const double eps = 1e-6;
	
	if (S < eps)
		printf("您输入的数据有误，无法构成三角形\n");
	else
		printf("三角形的面积为:%lf\n", S);

	return 0;
}
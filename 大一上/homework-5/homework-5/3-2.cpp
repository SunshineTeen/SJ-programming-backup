//姓名：王哲源 班级：计算机1班 学号：1652228
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double r = 1.5, h = 3;
	double pi = acos(-1.0);
	printf("圆周长=%.2f\n", 2*pi*r);
	printf("圆面积=%.2f\n", pi*r*r);
	printf("圆球表面积=%.2f\n", 4*pi*r*r);
	printf("圆球体积=%.2f\n", 4.0/3*pi*r*r*r);
	printf("圆柱体积=%.2f\n", pi*r*r*h);
	return 0;
}
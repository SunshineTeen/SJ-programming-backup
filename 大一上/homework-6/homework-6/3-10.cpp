//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("请输入一个实数\n");

	double x;
	scanf(" %lf", &x);

	printf("对应的y值为:");
	if (x < 1)
		cout << x << endl;
	else if (x >= 1 && x < 10)
		cout << 2 * x - 1 << endl;
	else
		cout << 3 * x - 11 << endl;     //x>10
	
	return 0;
}
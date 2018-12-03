//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("请输入当月利润\n");

	int i;
	scanf(" %d", &i);

	double sum = 0;
	int tmp = i / 100000;

	switch(tmp)
	{
		case 0:
			sum = i*0.1;
			break;
		case 1:
			sum = 10000 + (i - 100000)*0.075;
			break;
		case 2:
		case 3:
			sum = 10000 + 15000 + (i - 200000)*0.05;
			break;
		case 4:
		case 5:
			sum = 10000 + 15000 + 10000 + (i - 400000)*0.03;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			sum = 10000 + 15000 + 10000 + 6000 + (i - 600000)*0.015;
			break;
		default:
			sum = 10000 + 15000 + 10000 + 6000 + 6000 + (i - 1000000)*0.01;
			break;
	}
	printf("应发奖金%.2lf元\n", sum);

	return 0;
}
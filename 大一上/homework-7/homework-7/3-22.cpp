//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

int main()
{
	int sum = 1;
	opFor(i, 9, 1)
		sum = (sum + 1) * 2;
	printf("猴子第1天共摘了%d个桃子\n", sum);

	return 0;
}
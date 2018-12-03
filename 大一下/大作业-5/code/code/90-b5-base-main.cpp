// 班级:计算机一班 学号:1652228 姓名:王哲源

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<Windows.h>
#include<conio.h>
#include "90-b5-base.h"

using namespace std;

void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

int main()
{
	bigint a, b;
	printf("请输入两个大数字 a , b : ");
	cin >> a >> b;

	if (1)
	{
		printf("两数 + / - / * / / / %% 运算 :\n");
		cout << "a + b =" << a + b << endl;
		cout << "a - b =" << a - b << endl;
		cout << "a * b =" << a * b << endl;
		cout << "a / b =" << a / b << endl;
		cout << "a % b =" << a % b << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("运算符 += / -= / *= / /= / %%= 运算(每次结束后a都会复原) :\n");
		bigint c(a);
		cout << "a += b =" << (c += b) << endl;
		c = a;
		cout << "a -= b =" << (c -= b) << endl;
		c = a;
		cout << "a *= b =" << (c *= b) << endl;
		c = a;
		cout << "a /= b =" << (c /= b) << endl;
		c = a;
		cout << "a %= b =" << (c %= b) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("判断运算符 :\n");
		cout << "a > b " << (a > b) << endl;
		cout << "a < b =" << (a < b) << endl;
		cout << "a >= b =" << (a >= b) << endl;
		cout << "a <= b =" << (a <= b) << endl;
		cout << "a == b =" << (a == b) << endl;
		cout << "a != b =" << (a != b) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("自增/自减运算(运算后a不复原) :\n");
		cout << "a++ =" << (a++) << endl;
		cout << "++a =" << (++a) << endl;
		cout << "a-- =" << (a--) << endl;
		cout << "--a =" << (--a) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("复合运算 :\n");
		bigint c = (a + a%b)*(a - b) / b;
		cout << "( a + a % b ) * ( a - b ) / b =" << c << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("数组测试(A[0]=a,A[1]=b) :\n");
		bigint A[2];
		A[0] = a;
		A[1] = b;
		cout << "A[0] = " << A[0] << endl;
		cout << "A[1] = " << A[1] << endl;
		wait_for_enter();
	}

	return 0;
}

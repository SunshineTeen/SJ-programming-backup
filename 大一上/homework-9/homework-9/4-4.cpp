/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int fac(int x)
{
	if (!x || x == 1) 
		return 1;
	return fac(x - 1)*x;
}

int main()
{
	int a, b, c;

	while (1)
	{
		printf("请输入三个非负整数a,b,c : ");
		cin >> a >> b >> c;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> a >> b >> c;
			printf("\n");
		}

		if (a<0 || b<0 || c<0)
		{
			printf("输入的三个整数不能为负数，请重新输入\n");
			continue;
		}
		break;
	}
	printf("%d! + %d! + %d! = %d\n", a,b,c,fac(a) + fac(b) + fac(c));

	return 0;
}

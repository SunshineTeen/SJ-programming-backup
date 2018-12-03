/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int Fibonacci(int i)
{
	if (i == 1)
		return 1;
	if (i == 2)
		return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}

int main()
{
	int n;

	while (1)
	{
		printf("请输入要求的斐波那契数列项数n (建议不要作死超过40) : ");
		cin >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> n;
			printf("\n");
		}
		if (n <= 0)
		{
			printf("输入的项数应为正整数，请重新输入\n");
			continue;
		}
		break;
	}
	printf("Fibonacci[%d] = %d\n",n,Fibonacci(n));

	return 0;
}

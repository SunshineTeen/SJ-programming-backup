/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int sigema(int i)
{
	if (i == 1)
		return 1;
	return sigema(i - 1) + i*i;
}

int main()
{
	int n;

	while (1)
	{
		printf("请输入一个正整数n : ");
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
			printf("输入的n应当为正整数，请重新输入\n");
			continue;
		}
		break;
	}
	printf("∑(1,%d) i^2 = %d\n", n , sigema(n));

	return 0;
}

/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int is_power(int num, int base)
{
	if (num==1)
		return 1;
	int tmp = num%base;
	if (tmp)
		return 0;
	else
		return is_power(num / base, base);
}

int main()
{
	int num, base;

	while (1)
	{
		printf("请分别一个十进制正整数以及一个想判断是否为基数的2以上正整数 : ");
		cin >> num >> base;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> num >> base;
			printf("\n");
		}
		if (num <= 0)
		{
			printf("输入的十进制数应当为正整数，请重新输入\n");
			continue;
		}
		if (base <= 1)
		{
			printf("输入的基数应当为大于等于2的整数，请重新输入\n");
			continue;
		}
		break;
	}
	printf("%d\n", is_power(num, base));

	return 0;
}
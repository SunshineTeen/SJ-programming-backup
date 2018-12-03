/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline void output(int num, char from, char to)
{
	printf("%d# %c->%c\n", num, from, to);
}
inline void move(int num, char from, char to, char tmp)
{
	if (!num)
		return;
	move(num - 1, from, tmp, to);
	output(num, from, to);
	move(num - 1, tmp, to, from);
}

int main()
{
	int n;

	while (1)
	{
		printf("请输入盘子的个数n (1-64) : ");
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

		if (n <= 0 || n >= 65)
		{
			printf("盘子的个数应当介于1-64之间，请重新输入\n");
			continue;
		}
		break;
	}

	move(n, 'A', 'C', 'B');

	return 0;
}
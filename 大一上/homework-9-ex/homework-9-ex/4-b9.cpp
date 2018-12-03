/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int Min(int a, int b, int c=2147483647, int d = 2147483647)
{
	int tmp_1 = a < b ? a : b;
	int tmp_2 = c < d ? c : d;
	return tmp_1 < tmp_2 ? tmp_1 : tmp_2;
}

int main()
{
	int n;
	int a = 1, b = 1, c = 1, d = 1;

	while (1)
	{
		printf("请一次性输入需要求最小值的正整数的个数(介于2到4之间)及数 : ");
		cin >> n;
		if (n == 2)
			cin >> a >> b;
		else if (n == 3)
			cin >> a >> b >> c;
		else
			cin >> a >> b >> c >> d;

		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> n;
			if (n < 2 || n>4)
				return 0;
			if (n == 2)
				cin >> a >> b;
			else if (n == 3)
				cin >> a >> b >> c;
			else
				cin >> a >> b >> c >> d;
			printf("\n");
		}
		if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
		{
			printf("输入的数应当为正整数，请重新输入\n");
			continue;
		}
		break;
	}
	printf("这%d个数中最小的为 : ", n);
	if (n == 2)
		printf("%d\n", Min(a, b));
	else if (n == 3)
		printf("%d\n", Min(a, b, c));
	else
		printf("%d\n", Min(a, b, c, d));

	return 0;
}
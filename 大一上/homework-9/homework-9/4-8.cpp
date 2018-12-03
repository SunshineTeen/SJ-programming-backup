/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline double P(double x, int n)
{
	if (!n)
		return 1;
	if (n == 1) 
		return x;
	return ((2 * n - 1)*x*P(x, n - 1) - (n - 1)*P(x, n - 2)) / n;
}

int main()
{
	int n;
	double x;

	while (1)
	{
		printf("请分别输入浮点数x和阶数n，其中n为非负整数 : ");
		cin >> x >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> x >> n;
			printf("\n");
		}

		if (n < 0)
		{
			printf("输入阶数n不能为负数，请重新输入\n");
			continue;
		}
		break;
	}
	cout <<"P("<<x<<","<<n<<") = " << P(x, n) << endl;

	return 0;
}

/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	double a, b, c;

	printf("请顺序输入一元二次方程的三个系数 : ");
	const double eps = 1e-6;
	while (1)
	{
		cin >> a >> b >> c;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。输三个实数 : ";
			cin >> a >> b >> c;
			printf("\n");
		}
		if (fabs(a) < eps && fabs(b) < eps)
		{
			printf("输入错误，无法构成方程，请重新输入 : ");
			continue;
		}
		break;
	}

	void work_0(double b, double c);
	void work_1(double a, double b);
	void work_2(double a, double b, double delta);
	void work_3(double a, double b, double delta);

	if (fabs(a) < eps)
	{
		work_0(b, c);
		return 0;
	}

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < eps)
		work_1(a, b);
	else if (delta > 0)
		work_2(a, b, delta);
	else
		work_3(a, b, delta);

	return 0;
}
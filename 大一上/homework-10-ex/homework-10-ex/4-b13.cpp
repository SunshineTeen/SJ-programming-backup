/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const double eps = 1e-6;

double a, b, c,delta;

void work_3()
{
	double common = -b / (2 * a);
	double tmp = sqrt(fabs(delta)) / (2 * a);

	printf("方程有两个不相等虚根\n");
	if (fabs(common) < eps)
	{
		cout << "x1 = " << tmp << 'i' << endl;
		cout << "x2 = " << "-" << tmp << 'i' << endl;
	}
	else
	{
		cout << "x1 = " << common << "+" << tmp << 'i' << " , ";
		cout << "x2 = " << common << "-" << tmp << 'i' << endl;
	}
}

void work_2()
{
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < eps)
		x1 = 0;
	if (fabs(x2) < eps)
		x2 = 0;

	printf("方程有两个不相等实根\n");
	cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
}

void work_1()
{
	double tmp = -b / (2 * a);
	if (fabs(tmp) < eps)
		tmp = 0;

	printf("方程有两个相等实根\n");
	cout << "x1 = x2 = " << tmp << endl;
}

void work_0()
{
	printf("该方程的根为 : x=");
	cout << (-c / b) << endl;
}

int main()
{
	printf("请顺序输入一元二次方程的三个系数 : ");
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

	if (fabs(a) < eps)
	{
		work_0();
		return 0;
	}

	delta = b * b - 4 * a * c;
	if (fabs(delta) < eps)
		work_1();
	else if (delta > 0)
		work_2();
	else
		work_3();

	return 0;
}
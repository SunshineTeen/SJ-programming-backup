/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

inline void trans(int n)
{
	if (n == 4)
	{
		printf("四");
		return;
	}
	if (n == 5)
	{
		printf("五");
		return;
	}
	if (n == 6)
	{
		printf("六");
		return;
	}
	printf("七");
}
inline double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2 - y1*x2;
}
void work(int n, double x[], double y[])
{
	const double eps = 1e-6;
	bool f;

	double v1x = x[1] - x[n], v1y = y[1] - y[n];
	double v2x = x[2] - x[1], v2y = y[2] - y[1];
	double tc = cross(v1x, v1y, v2x, v2y);
	if (fabs(tc) < eps)
	{
		printf("不是");
		trans(n);
		printf("边形\n");
		return;
	}
	if (tc > 0)
		f = 1;
	else 
		f = 0;

	For(i, 3, n)
	{
		v1x = v2x;
		v1y = v2y;
		v2x = x[i] - x[i - 1];
		v2y = y[i] - y[i - 1];
		tc = cross(v1x, v1y, v2x, v2y);
		if (fabs(tc) < eps)
		{
			printf("不是");
			trans(n);
			printf("边形\n");
			return;
		}
		if ((tc > 0 && f) || (tc < 0 && !f))
			continue;
		printf("不是");
		trans(n);
		printf("边形\n");
		return;
	}

	printf("是");
	trans(n);
	printf("边形");
	double S = cross(x[n],y[n],x[1],y[1]);
	For(i, 1, n - 1)
		S += cross(x[i], y[i], x[i + 1], y[i + 1]);
	S *= 0.5;
	printf(" , 面积为 %.6lf\n", fabs(S));
}

int main()
{
	const int Maxn = 10;
	double x[Maxn], y[Maxn];
	int n;

	while (1)
	{
		printf("请输入点对的个数n (4-7) : ");
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> n;
		}
		if (n <4 || n >7)
		{
			printf("点对的个数应当介于4-7之间，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请按顺时针/逆时针顺序依次输入%d个点的横纵坐标\n",n);
		For(i, 1, n)
			cin >> x[i] >> y[i];
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			For(i, 1, n)
				cin >> x[i] >> y[i];
		}
		break;
	}

	work(n, x, y);

	//system("pause");/////////////////////////
	return 0;
}

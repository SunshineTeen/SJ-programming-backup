/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath> 
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

inline char getch(int s)
{
	if (s == 1)
		return '+';
	if (s == 2)
		return '-';
	if (s == 3)
		return '*';
	//s==4
	return '/';
}
inline void output(double a, double b, double c, double d ,int s1,int s2,int s3,int p1,int p2,int q1,int p3,int q2,int q3)
{
	For(i, 1, p1)
		printf("(");
	printf("%.0lf", a);
	printf("%c", getch(s1));
	For(i, 1, p2)
		printf("(");
	printf("%.0lf", b);
	For(i, 1, q1)
		printf(")");
	printf("%c", getch(s2));
	For(i, 1, p3)
		printf("(");
	printf("%.0lf", c);
	For(i, 1, q2)
		printf(")");
	printf("%c", getch(s3));
	printf("%.0lf", d);
	For(i, 1, q3)
		printf(")");

	printf("=24\n");
}
inline double calc(double x, double y,int op)
{
	const double eps = 1e-6;

	if (op == 1)
		return x + y;
	if (op == 2)
		return x - y;
	if (op == 3)
		return x * y;
	//op==4
	if (fabs(y) < eps)
		return 1e10;
	return x / y;
}
void work(double a,double b,double c,double d)
{
	const double eps = 1e-6;
	bool getans = 0;
	For(s1, 1, 4)
		For(s2, 1, 4)
			For(s3, 1, 4)
			{
				if (fabs(calc(calc(calc(a, b, s1), c, s2), d, s3) - 24)<eps) //ab c d
					getans = 1, output(a, b, c, d, s1, s2, s3, 2, 0, 1, 0, 1, 0);
				if (fabs(calc(calc(a, calc(b, c, s2), s1), d, s3) - 24)<eps) //bc a d
					getans = 1, output(a, b, c, d, s1, s2, s3, 1, 1, 0, 0, 2, 0);
				if (fabs(calc(a, calc(b, calc(c, d, s3), s2), s1) - 24)<eps) //cd b a
					getans = 1, output(a, b, c, d, s1, s2, s3, 0, 1, 0, 1, 0, 2);
				if (fabs(calc(a, calc(calc(b, c, s2), d, s3), s1) - 24)<eps) //bc d a
					getans = 1, output(a, b, c, d, s1, s2, s3, 0, 2, 0, 0, 1, 1);
				if (fabs(calc(calc(a, b, s1), calc(c, d, s3), s2) - 24)<eps) //ab cd
					getans = 1, output(a, b, c, d, s1, s2, s3, 1, 0, 1, 1, 0, 1);
			}

	if (!getans)
		printf("无解\n");
}

inline bool pd(double x)
{
	return (x >= 1 && x <= 10);
}

int main()
{
	double a, b, c, d;
	while (1)
	{
		printf("请输入24点的4个介于[0,10]整数 : ");
		cin >> a >> b >> c >> d;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> a >> b >> c >> d;
			printf("\n");
		}

		if (!pd(a) || !pd(b) || !pd(c) || !pd(d))
		{
			printf("输入的4个数应当介于[0,10]，请重新输入\n");
			continue;
		}
		break;
	}

	work(a,b,c,d);

	return 0;
}

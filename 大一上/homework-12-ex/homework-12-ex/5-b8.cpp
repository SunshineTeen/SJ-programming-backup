/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
		printf("��");
		return;
	}
	if (n == 5)
	{
		printf("��");
		return;
	}
	if (n == 6)
	{
		printf("��");
		return;
	}
	printf("��");
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
		printf("����");
		trans(n);
		printf("����\n");
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
			printf("����");
			trans(n);
			printf("����\n");
			return;
		}
		if ((tc > 0 && f) || (tc < 0 && !f))
			continue;
		printf("����");
		trans(n);
		printf("����\n");
		return;
	}

	printf("��");
	trans(n);
	printf("����");
	double S = cross(x[n],y[n],x[1],y[1]);
	For(i, 1, n - 1)
		S += cross(x[i], y[i], x[i + 1], y[i + 1]);
	S *= 0.5;
	printf(" , ���Ϊ %.6lf\n", fabs(S));
}

int main()
{
	const int Maxn = 10;
	double x[Maxn], y[Maxn];
	int n;

	while (1)
	{
		printf("�������Եĸ���n (4-7) : ");
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> n;
		}
		if (n <4 || n >7)
		{
			printf("��Եĸ���Ӧ������4-7֮�䣬����������\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("�밴˳ʱ��/��ʱ��˳����������%d����ĺ�������\n",n);
		For(i, 1, n)
			cin >> x[i] >> y[i];
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			For(i, 1, n)
				cin >> x[i] >> y[i];
		}
		break;
	}

	work(n, x, y);

	//system("pause");/////////////////////////
	return 0;
}

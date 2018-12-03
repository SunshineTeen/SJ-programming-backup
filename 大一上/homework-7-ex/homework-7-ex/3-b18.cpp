//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)

using namespace std;

int main()
{
	int n;
	printf("请输入抢红包的总人数[1,50] : ");
	scanf(" %d", &n);

	double init;
	printf("请输入红包总额[0.01,200] : ");
	scanf(" %lf", &init);
	printf("\n");

	int tot = int((init + 0.009) * 100);
	if (n>tot)
	{
		printf("输入错误，单个红包的金额必须大于0.01元\n");
		return 0;
	}

	srand((unsigned int)time(0));
	tot -= n;

	printf("每个人获得的红包金额如下:\n");

	sFor(i, 1, n)
	{
		if (!tot)
		{
			printf("第");
			cout << setw(2) << i;
			printf("个人获得的红包金额为 0.01元\n");
			continue;
		}

		int plus = 0;
		double ans;

		int j = tot;
		while (j)
		{
			int f1 = rand() % 9;
			if (j >= 100 && !f1)
			{
				int f = rand() % (n - i + 1);
				if (!f)
					plus += 100;
				j -= 100;
			}
			else if (j >= 10 && (f1 == 1 || f1 == 2 || f1 == 3))
			{
				int f = rand() % (n - i + 1);
				if (!f)
					plus += 10;
				j -= 10;
			}
			else
			{
				int f = rand() % (n - i + 1);
				if (!f)
					++plus;
				--j;
			}
		}

		ans = 0.01*(plus + 1);
		tot -= plus;

		printf("第");
		cout << setw(2) << i;
		printf("个人获得的红包金额为 ");
		printf("%.2lf", ans);
		printf("元\n");
	}

	printf("第");
	cout << setw(2) << n;
	printf("个人获得的红包金额为 ");
	printf("%.2lf", 0.01*(tot + 1));
	printf("元\n");

	return 0;
}

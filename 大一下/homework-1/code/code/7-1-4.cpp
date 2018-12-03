//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

struct Day
{
	int x, y, z;
};

int days(int *day, Day &D)
{
	if (D.z > day[D.y])
	{
		printf("输入的天数有误，无法计算\n");
		return -1;
	}

	int sum = 0;
	For(i, 1, D.y - 1)
		sum += day[i];
	sum += D.z;
	return sum;
}

int main()
{
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	Day D;
	while (1)
	{
		printf("请输入三个整数分别表示年月日\n");
		cin >> D.x >> D.y >> D.z;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。输三个整数 : ";
			cin >> D.x >> D.y >> D.z;
			printf("\n");
		}
		if (D.y <= 0 || D.y >= 13)
		{
			printf("输入错误，请重新输入\n");
			return 0;
		}
		break;
	}

	if ((!(D.x % 4) && (D.x % 100)) || !(D.x % 400))
		++day[2];

	int ans = days(day, D);
	if (ans != -1)
		printf("这是该年的第%d天\n", ans);

	return 0;
}
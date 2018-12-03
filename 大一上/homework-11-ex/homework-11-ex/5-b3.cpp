//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

void work(int day[], int y, int z)
{
	if (z > day[y])
	{
		printf("输入的天数有误，无法计算\n");
		return;
	}
	int sum = 0;
	For(i, 1, y - 1)
		sum += day[i];
	sum += z;
	printf("这是该年的第%d天\n", sum);
}

int pdly(int x)
{
	if ((!(x % 4) && (x % 100)) || !(x % 400))
		return 1;
	return 0;
}

int main()
{
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int x, y, z;
	while (1)
	{
		printf("请输入三个整数分别表示年月日\n");
		cin >> x >> y >> z;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。输三个整数 : ";
			cin >> x >> y >> z;
			printf("\n");
		}
		if (y <= 0 || y>=13)
		{
			printf("输入错误，请重新输入\n");
			return 0;
		}
		break;
	}

	day[2]+=pdly(x);
	work(day,y,z);

	return 0;
}
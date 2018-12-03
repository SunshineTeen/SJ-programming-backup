/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int zeller(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		--year;
	}
	int c = year / 100;
	year %= 100;
	int w = year + year / 4 + c / 4 - 2 * c + (13 * (month + 1) / 5) + day - 1;
	while (w < 0)
		w += 7;
	return w;
}

int main()
{
	int y, m, d;
	//char dot;

	while (1)
	{
		printf("请输入年月日(年份介于1900-2100之间)，两两之间以空格隔开 : ");
		cin >> y >> m >> d;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> y >> m >> d;
			printf("\n");
		}

		if (y < 1900 || y>2100)
		{
			printf("输入的年份应当介于1900-2100之间，请重新输入\n");
			continue;
		}
		break;
	}

	if (m < 0 || m>12 || d < 0 || d>31)
	{
		printf("非法\n");
		return 0;
	}
	bool leapyear;
	if ((!(y % 4) && (y % 100)) || !(y % 400))
		leapyear = 1;
	else
		leapyear = 0;
	int lim;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		lim = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		lim = 30;
	else
		lim = 28 + leapyear;
	if (d > lim)
	{
		printf("非法\n");
		return 0;
	}

	int ans = (zeller(y, m, d) + 7) % 7;
	switch (ans)
	{
	case 1:
		printf("一\n");
		break;
	case 2:
		printf("二\n");
		break;
	case 3:
		printf("三\n");
		break;
	case 4:
		printf("四\n");
		break;
	case 5:
		printf("五\n");
		break;
	case 6:
		printf("六\n");
		break;
	default:
		printf("日\n");
		break;
	}

	return 0;
}
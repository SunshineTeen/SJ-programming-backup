/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
		printf("������������(��ݽ���1900-2100֮��)������֮���Կո���� : ");
		cin >> y >> m >> d;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> y >> m >> d;
			printf("\n");
		}

		if (y < 1900 || y>2100)
		{
			printf("��������Ӧ������1900-2100֮�䣬����������\n");
			continue;
		}
		break;
	}

	if (m < 0 || m>12 || d < 0 || d>31)
	{
		printf("�Ƿ�\n");
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
		printf("�Ƿ�\n");
		return 0;
	}

	int ans = (zeller(y, m, d) + 7) % 7;
	switch (ans)
	{
	case 1:
		printf("һ\n");
		break;
	case 2:
		printf("��\n");
		break;
	case 3:
		printf("��\n");
		break;
	case 4:
		printf("��\n");
		break;
	case 5:
		printf("��\n");
		break;
	case 6:
		printf("��\n");
		break;
	default:
		printf("��\n");
		break;
	}

	return 0;
}
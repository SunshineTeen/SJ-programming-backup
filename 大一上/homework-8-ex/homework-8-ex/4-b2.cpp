/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

void calendar(int a, int b, int c)
{
	bool leapyear;
	if ((!(a % 4) && (a % 100)) || !(a % 400))
		leapyear = 1;
	else
		leapyear = 0;
	int tot;
	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
		tot = 31;
	else if (b == 4 || b == 6 || b == 9 || b == 11)
		tot = 30;
	else
		tot = 28 + leapyear;

	printf("\n");
	printf("%d��%d�µ�����Ϊ\n", a, b);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	For(i, 1, c)
		printf("        ");

	int p = c;
	For(i, 1, tot)
	{
		cout << setw(4) << i;
		printf("    ");
		if (c == 6)
		{
			c = 0;
			printf("\n");
		}
		else
			++c;
	}
	printf("\n");
}

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
	int y, m;

	while (1)
	{
		printf("�������꼰��(��ݽ���1900-2100֮��)������֮���Կո���� : ");
		cin >> y >> m;
		printf("\n");

		if (y < 1900 || y>2100)
		{
			printf("��������Ӧ������1900-2100֮�䣬����������\n");
			continue;
		}
		if (m < 0 || m>12)
		{
			printf("������·�Ӧ������1-12֮�䣬����������\n");
			continue;
		}
		break;
	}

	int d = (zeller(y, m, 1) + 7) % 7;
	calendar(y, m, d);

	return 0;
}
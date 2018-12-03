//����������Դ �༶�������1�� ѧ�ţ�1652228

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

int days(int *day, Day D)
{
	if (D.z > day[D.y])
	{
		printf("��������������޷�����\n");
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
		printf("���������������ֱ��ʾ������\n");
		cin >> D.x >> D.y >> D.z;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ������������� : ";
			cin >> D.x >> D.y >> D.z;
			printf("\n");
		}
		if (D.y <= 0 || D.y >= 13)
		{
			printf("�����������������\n");
			return 0;
		}
		break;
	}

	if ((!(D.x % 4) && (D.x % 100)) || !(D.x % 400))
		++day[2];

	int ans = days(day, D);
	if (ans != -1)
		printf("���Ǹ���ĵ�%d��\n", ans);

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

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
		printf("��������������޷�����\n");
		return;
	}
	int sum = 0;
	For(i, 1, y - 1)
		sum += day[i];
	sum += z;
	printf("���Ǹ���ĵ�%d��\n", sum);
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
		printf("���������������ֱ��ʾ������\n");
		cin >> x >> y >> z;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ������������� : ";
			cin >> x >> y >> z;
			printf("\n");
		}
		if (y <= 0 || y>=13)
		{
			printf("�����������������\n");
			return 0;
		}
		break;
	}

	day[2]+=pdly(x);
	work(day,y,z);

	return 0;
}
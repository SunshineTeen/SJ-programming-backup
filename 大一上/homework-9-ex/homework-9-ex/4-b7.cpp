/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int is_power(int num, int base)
{
	if (num==1)
		return 1;
	int tmp = num%base;
	if (tmp)
		return 0;
	else
		return is_power(num / base, base);
}

int main()
{
	int num, base;

	while (1)
	{
		printf("��ֱ�һ��ʮ�����������Լ�һ�����ж��Ƿ�Ϊ������2���������� : ");
		cin >> num >> base;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> num >> base;
			printf("\n");
		}
		if (num <= 0)
		{
			printf("�����ʮ������Ӧ��Ϊ������������������\n");
			continue;
		}
		if (base <= 1)
		{
			printf("����Ļ���Ӧ��Ϊ���ڵ���2������������������\n");
			continue;
		}
		break;
	}
	printf("%d\n", is_power(num, base));

	return 0;
}
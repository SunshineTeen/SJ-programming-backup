/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int sigema(int i)
{
	if (i == 1)
		return 1;
	return sigema(i - 1) + i*i;
}

int main()
{
	int n;

	while (1)
	{
		printf("������һ��������n : ");
		cin >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> n;
			printf("\n");
		}
		if (n <= 0)
		{
			printf("�����nӦ��Ϊ������������������\n");
			continue;
		}
		break;
	}
	printf("��(1,%d) i^2 = %d\n", n , sigema(n));

	return 0;
}

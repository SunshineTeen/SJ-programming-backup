/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int Max(int a, int b,int c,int d)
{
	int tmp_1 = a > b ? a : b;
	int tmp_2 = c > d ? c : d;
	return tmp_1 > tmp_2 ? tmp_1 : tmp_2;
}
inline int Max(int a, int b,int c)
{
	int tmp = a > b ? a : b;
	return tmp > c ? tmp : c;
}
inline int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	int a = 1, b = 1, c = 1, d = 1;

	while (1)
	{
		printf("��һ����������Ҫ�����ֵ���������ĸ���(����2��4֮��)���� : ");
		cin >> n;
		if (n == 2)
			cin >> a >> b;
		else if (n == 3)
			cin >> a >> b >> c;
		else
			cin >> a >> b >> c >> d;

		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> n;
			if (n < 2 || n>4)
				return 0;
			if (n == 2)
				cin >> a >> b;
			else if (n == 3)
				cin >> a >> b >> c;
			else
				cin >> a >> b >> c >> d;
			printf("\n");
		}
		if (a <= 0 || b <= 0 || c <= 0 || d <= 0)
		{
			printf("�������Ӧ��Ϊ������������������\n");
			continue;
		}
		break;
	}
	printf("��%d����������Ϊ : ", n);
	if (n == 2)
		printf("%d\n", Max(a, b));
	else if (n == 3)
		printf("%d\n", Max(a, b, c));
	else
		printf("%d\n", Max(a, b, c, d));

	return 0;
}
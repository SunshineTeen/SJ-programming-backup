/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int fac(int x)
{
	if (!x || x == 1) 
		return 1;
	return fac(x - 1)*x;
}

int main()
{
	int a, b, c;

	while (1)
	{
		printf("�����������Ǹ�����a,b,c : ");
		cin >> a >> b >> c;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> a >> b >> c;
			printf("\n");
		}

		if (a<0 || b<0 || c<0)
		{
			printf("�����������������Ϊ����������������\n");
			continue;
		}
		break;
	}
	printf("%d! + %d! + %d! = %d\n", a,b,c,fac(a) + fac(b) + fac(c));

	return 0;
}

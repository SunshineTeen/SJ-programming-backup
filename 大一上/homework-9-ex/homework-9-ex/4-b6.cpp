/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline int Fibonacci(int i)
{
	if (i == 1)
		return 1;
	if (i == 2)
		return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}

int main()
{
	int n;

	while (1)
	{
		printf("������Ҫ���쳲�������������n (���鲻Ҫ��������40) : ");
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
			printf("���������ӦΪ������������������\n");
			continue;
		}
		break;
	}
	printf("Fibonacci[%d] = %d\n",n,Fibonacci(n));

	return 0;
}

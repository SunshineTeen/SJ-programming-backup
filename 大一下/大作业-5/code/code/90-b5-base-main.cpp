// �༶:�����һ�� ѧ��:1652228 ����:����Դ

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<Windows.h>
#include<conio.h>
#include "90-b5-base.h"

using namespace std;

void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

int main()
{
	bigint a, b;
	printf("���������������� a , b : ");
	cin >> a >> b;

	if (1)
	{
		printf("���� + / - / * / / / %% ���� :\n");
		cout << "a + b =" << a + b << endl;
		cout << "a - b =" << a - b << endl;
		cout << "a * b =" << a * b << endl;
		cout << "a / b =" << a / b << endl;
		cout << "a % b =" << a % b << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("����� += / -= / *= / /= / %%= ����(ÿ�ν�����a���Ḵԭ) :\n");
		bigint c(a);
		cout << "a += b =" << (c += b) << endl;
		c = a;
		cout << "a -= b =" << (c -= b) << endl;
		c = a;
		cout << "a *= b =" << (c *= b) << endl;
		c = a;
		cout << "a /= b =" << (c /= b) << endl;
		c = a;
		cout << "a %= b =" << (c %= b) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("�ж������ :\n");
		cout << "a > b " << (a > b) << endl;
		cout << "a < b =" << (a < b) << endl;
		cout << "a >= b =" << (a >= b) << endl;
		cout << "a <= b =" << (a <= b) << endl;
		cout << "a == b =" << (a == b) << endl;
		cout << "a != b =" << (a != b) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("����/�Լ�����(�����a����ԭ) :\n");
		cout << "a++ =" << (a++) << endl;
		cout << "++a =" << (++a) << endl;
		cout << "a-- =" << (a--) << endl;
		cout << "--a =" << (--a) << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("�������� :\n");
		bigint c = (a + a%b)*(a - b) / b;
		cout << "( a + a % b ) * ( a - b ) / b =" << c << endl;
		wait_for_enter();
	}

	if (1)
	{
		printf("�������(A[0]=a,A[1]=b) :\n");
		bigint A[2];
		A[0] = a;
		A[1] = b;
		cout << "A[0] = " << A[0] << endl;
		cout << "A[1] = " << A[1] << endl;
		wait_for_enter();
	}

	return 0;
}

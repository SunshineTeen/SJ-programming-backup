//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("����������������m��n\n");

	int n, m;
	scanf(" %d %d", &n, &m);

	int a,b,r;
	a = n;
	b = m;

	while (1)
	{
		r = a % b;
		if (!r)
			break;
		a = b;
		b = r;
	}
	a = n*m / b;

	printf("����������С��Լ��Ϊ:%d\n", b);
	printf("����������󹫱���Ϊ:%d\n", a);

	return 0;
}
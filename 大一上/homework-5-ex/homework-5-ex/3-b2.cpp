/* ѧ��:1652228 �༶:�����һ�� ����:����Դ */
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main()
{
	printf("������һ��[1,30000]������\n");
	int x, a, b, c, d, e;
	scanf(" %d", &x);

	a = x / 10000;            //��ȡ��λ(��ͬ)
	x -= 10000 * a;           //ȥ����λ(��ͬ)

	b = x / 1000;
	x -= 1000 * b;

	c = x / 100;
	x -= 100 * c;

	d = x / 10;
	x -= 10 * d;

	e = x;

	printf("��λ��%d\n", a);
	printf("ǧλ��%d\n", b);
	printf("��λ��%d\n", c);
	printf("ʮλ��%d\n", d);
	printf("��λ��%d\n", e);

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("������һ��������5λ��������\n");

	int x;
	scanf(" %d", &x);

	int a, b, c, d, e;//��ȡ��λ����
	a = x / 10000;
	x -= 10000 * a;

	b = x / 1000;
	x -= 1000 * b;

	c = x / 100;
	x -= 100 * c;

	d = x / 10;
	x -= 10 * d;

	e = x;

	printf("�������");
	if (a)//��λ��0��������ͬ
		printf("��λ��");
	else if(b)
		printf("��λ��");
	else if(c)
		printf("��λ��");
	else if (d)
		printf("��λ��");
	else 
		printf("һλ��");
	printf("\n");

	printf("����%d %d %d %d %d\n", a, b, c, d, e);
	printf("����%d %d %d %d %d\n", e, d, c, b, a);

	return 0;
}
//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("������һ������[0,100��)֮��ĸ�������ʾ����Ҽ۸�\n");

	double x;
	scanf(" %lf", &x);
	x += 0.001;

	int a, b, c, d, e, f, g, h, i, j, k, l;
	a = int(x / 1000000000);
	x -= 1.0 * a * 1000000000; 

	b = int(x / 100000000);
	x -= 1.0 * b * 100000000;

	c = int(x / 10000000);
	x -= 1.0 * c * 10000000;

	d = int(x / 1000000);
	x -= 1.0 * d * 1000000;

	e = int(x / 100000);
	x -= 1.0 * e * 100000;

	f = int(x / 10000);
	x -= 1.0 * f * 10000;

	g = int(x / 1000);
	x -= 1.0 * g * 1000;

	h = int(x / 100);
	x -= 1.0 * h * 100;

	i = int(x / 10);
	x -= 1.0 * i * 10;

	j = int(x);
	x -= 1.0 * j;

	k = int(x / 0.1);
	x -= 0.1 * k;

	l = int(x / 0.01);

	bool flag = 0;
	if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l)
		printf("��Բ");

	switch (a)
	{
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		default:
			break;
	}
	switch (b)
	{
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		default:
			break;
	}
	if (a || b)
		printf("��");

	switch (c)
	{
		case 1:
			printf("ҼǪ");
			flag = 1;
			break;
		case 2:
			printf("��Ǫ");
			flag = 1;
			break;
		case 3:
			printf("��Ǫ");
			flag = 1;
			break;
		case 4:
			printf("��Ǫ");
			flag = 1;
			break;
		case 5:
			printf("��Ǫ");
			flag = 1;
			break;
		case 6:
			printf("½Ǫ");
			flag = 1;
			break;
		case 7:
			printf("��Ǫ");
			flag = 1;
			break;
		case 8:
			printf("��Ǫ");
			flag = 1;
			break;
		case 9:
			printf("��Ǫ");
			flag = 1;
			break;
		default:
			if (a || b)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && d)
		printf("��");
	switch (d)
	{
		case 1:
			printf("Ҽ��");
			flag = 1;
			break;
		case 2:
			printf("����");
			flag = 1;
			break;
		case 3:
			printf("����");
			flag = 1;
			break;
		case 4:
			printf("����");
			flag = 1;
			break;
		case 5:
			printf("���");
			flag = 1;
			break;
		case 6:
			printf("½��");
			flag = 1;
			break;
		case 7:
			printf("���");
			flag = 1;
			break;
		case 8:
			printf("�ư�");
			flag = 1;
			break;
		case 9:
			printf("����");
			flag = 1;
			break;
		default:
			if (a || b || c)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && e)
		printf("��");
	switch (e)
	{
		case 1:
			printf("Ҽʰ");
			flag = 1;
			break;
		case 2:
			printf("��ʰ");
			flag = 1;
			break;
		case 3:
			printf("��ʰ");
			flag = 1;
			break;
		case 4:
			printf("��ʰ");
			flag = 1;
			break;
		case 5:
			printf("��ʰ");
			flag = 1;
			break;
		case 6:
			printf("½ʰ");
			flag = 1;
			break;
		case 7:
			printf("��ʰ");
			flag = 1;
			break;
		case 8:
			printf("��ʰ");
			flag = 1;
			break;
		case 9:
			printf("��ʰ");
			flag = 1;
			break;
		default:
			if (a || b || c || d)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && f)
		printf("��");
	switch (f)
	{
		case 1:
			printf("Ҽ");
			flag = 1;
			break;
		case 2:
			printf("��");
			flag = 1;
			break;
		case 3:
			printf("��");
			flag = 1;
			break;
		case 4:
			printf("��");
			flag = 1;
			break;
		case 5:
			printf("��");
			flag = 1;
			break;
		case 6:
			printf("½");
			flag = 1;
			break;
		case 7:
			printf("��");
			flag = 1;
			break;
		case 8:
			printf("��");
			flag = 1;
			break;
		case 9:
			printf("��");
			flag = 1;
			break;
		default:
			flag = 0;
			break;
	}
	if (c || d || e || f)
		printf("��");

	switch (g)
	{
		case 1:
			printf("ҼǪ");
			flag = 1;
			break;
		case 2:
			printf("��Ǫ");
			flag = 1;
			break;
		case 3:
			printf("��Ǫ");
			flag = 1;
			break;
		case 4:
			printf("��Ǫ");
			flag = 1;
			break;
		case 5:
			printf("��Ǫ");
			flag = 1;
			break;
		case 6:
			printf("½Ǫ");
			flag = 1;
			break;
		case 7:
			printf("��Ǫ");
			flag = 1;
			break;
		case 8:
			printf("��Ǫ");
			flag = 1;
			break;
		case 9:
			printf("��Ǫ");
			flag = 1;
			break;
		default:
			if (a || b || c || d || e || f)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && h)
		printf("��");
	switch (h)
	{
		case 1:
			printf("Ҽ��");
			flag = 1;
			break;
		case 2:
			printf("����");
			flag = 1;
			break;
		case 3:
			printf("����");
			flag = 1;
			break;
		case 4:
			printf("����");
			flag = 1;
			break;
		case 5:
			printf("���");
			flag = 1;
			break;
		case 6:
			printf("½��");
			flag = 1;
			break;
		case 7:
			printf("���");
			flag = 1;
			break;
		case 8:
			printf("�ư�");
			flag = 1;
			break;
		case 9:
			printf("����");
			flag = 1;
			break;
		default:
			if (a || b || c || d || e || f || g)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && i)
		printf("��");
	switch (i)
	{
		case 1:
			printf("Ҽʰ");
			flag = 1;
			break;
		case 2:
			printf("��ʰ");
			flag = 1;
			break;
		case 3:
			printf("��ʰ");
			flag = 1;
			break;
		case 4:
			printf("��ʰ");
			flag = 1;
			break;
		case 5:
			printf("��ʰ");
			flag = 1;
			break;
		case 6:
			printf("½ʰ");
			flag = 1;
			break;
		case 7:
			printf("��ʰ");
			flag = 1;
			break;
		case 8:
			printf("��ʰ");
			flag = 1;
			break;
		case 9:
			printf("��ʰ");
			flag = 1;
			break;
		default:
			if (a || b || c || d || e || f || g || h)
				flag = 0;
			else
				flag = 1;
			break;
	}
	if (!flag && j)
		printf("��");
	switch (j)
	{
		case 1:
			printf("Ҽ");
			flag = 1;
			break;
		case 2:
			printf("��");
			flag = 1;
			break;
		case 3:
			printf("��");
			flag = 1;
			break;
		case 4:
			printf("��");
			flag = 1;
			break;
		case 5:
			printf("��");
			flag = 1;
			break;
		case 6:
			printf("½");
			flag = 1;
			break;
		case 7:
			printf("��");
			flag = 1;
			break;
		case 8:
			printf("��");
			flag = 1;
			break;
		case 9:
			printf("��");
			flag = 1;
			break;
		default:
			flag = 0;
			break;
	}
	if (a || b || c || d || e || f || g || h || i || j)
		printf("Բ");

	switch (k)
	{
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
		default:
			break;
	}
	if (!l) printf("��");

	if (l && (a || b || c || d || e || f || g || h || i || j) && !k)
		printf("��");
	switch (l)
	{
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 9:
			printf("����");
			break;
		default:
			break;
	}

	printf("\n");

	return 0;
}
/* ѧ��:1652228 ����:����Դ �༶:�����һ�� */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/* ������Ա��������κ��޸�
���������⣬�������κκ�����������㡱-������!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ����������� */


/* ������Ҫ���main���� */
int main()
{
	double x;
	
	while (1)
	{
		printf("������һ������[0,100��)֮��ĸ�������ʾ����Ҽ۸�:");
		cin >> x;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> x;
			printf("\n");
		}

		if (x<0 || x>=1e10)
		{
			printf("����Ľ��Ӧ����[0,100��)֮�䣬����������\n");
			continue;
		}
		break;
	}

	x += 0.009;

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

	if(!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l)
	{
		daxie(0, 1);
		printf("Բ��\n");
		return 0;
	}

	bool flag;

	daxie(a, 0);
	if (a)
		printf("ʰ");

	daxie(b, 0);
	if (a || b) printf("��");

	if ((a || b) && d)
		flag = 1;
	else
		flag = 0;
	daxie(c, flag);
	if (c)
		printf("Ǫ");

	if ((a || b || c) && e)
		flag = 1;
	else
		flag = 0;
	daxie(d, flag);
	if (d)
		printf("��");

	if ((a || b || c || d) && f)
		flag = 1;
	else
		flag = 0;
	daxie(e, flag);
	if (e)
		printf("ʰ");

	daxie(f, 0);
	if (c || d || e || f)
		printf("��");

	if ((a || b || c || d || e || f) && h)
		flag = 1;
	else
		flag = 0;
	daxie(g, flag);
	if (g)
		printf("Ǫ");

	if ((a || b || c || d || e || f || g) && i)
		flag = 1;
	else
		flag = 0;
	daxie(h, flag);
	if (h)
		printf("��");

	if ((a || b || c || d || e || f || g || h) && j)
		flag = 1;
	else
		flag = 0;
	daxie(i, flag);
	if (i)
		printf("ʰ");

	daxie(j, flag);
	if (a || b || c || d || e || f || g || h || i || j)
		printf("Բ");

	if ((a || b || c || d || e || f || g || h || i || j) && l)
		flag = 1;
	else
		flag = 0;
	daxie(k, flag);
	if(k)
		printf("��");

	if (!l)
		printf("��");
	else
	{
		daxie(l, 0);
		printf("��");
	}

	printf("\n");

	return 0;
}
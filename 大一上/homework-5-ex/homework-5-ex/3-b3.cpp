/* ѧ��:1652228 �༶:�����һ�� ����:����Դ */
#include<iostream>

using namespace std;

int main()
{
	double x;
	int a, b, c, d, e, f, g, h, i, j, k, l;

	printf("������һ��[0,100��)֮�������С�����������λ\n");
	cin >> x;
	x += 0.001; //��ֹ��ٷ�λʱ��Ϊ�����Ƴ����������ȶ�ʧ

	a = int(x / 1000000000);  //��ȡʮ��λ(��ͬ)
	x -= 1.0 * a * 1000000000;  //ȥ��ʮ��λ(��ͬ)
	
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

	printf("ʮ��λ��%d\n", a);
	printf("��λ��%d\n", b);
	printf("ǧ��λ��%d\n", c);
	printf("����λ��%d\n", d);
	printf("ʮ��λ��%d\n", e);
	printf("��λ��%d\n", f);
	printf("ǧλ��%d\n", g);
	printf("��λ��%d\n", h);
	printf("ʮλ��%d\n", i);
	printf("��λ��%d\n", j);
	printf("ʮ��λ��%d\n", k);
	printf("�ٷ�λ��%d\n", l);

	return 0;
}
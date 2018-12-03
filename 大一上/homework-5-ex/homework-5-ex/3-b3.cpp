/* 学号:1652228 班级:计算机一班 姓名:王哲源 */
#include<iostream>

using namespace std;

int main()
{
	double x;
	int a, b, c, d, e, f, g, h, i, j, k, l;

	printf("请输入一个[0,100亿)之间的数，小数点后至多两位\n");
	cin >> x;
	x += 0.001; //防止求百分位时因为二进制除不尽而精度丢失

	a = int(x / 1000000000);  //提取十亿位(下同)
	x -= 1.0 * a * 1000000000;  //去除十亿位(下同)
	
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

	printf("十亿位：%d\n", a);
	printf("亿位：%d\n", b);
	printf("千万位：%d\n", c);
	printf("百万位：%d\n", d);
	printf("十万位：%d\n", e);
	printf("万位：%d\n", f);
	printf("千位：%d\n", g);
	printf("百位：%d\n", h);
	printf("十位：%d\n", i);
	printf("个位：%d\n", j);
	printf("十分位：%d\n", k);
	printf("百分位：%d\n", l);

	return 0;
}
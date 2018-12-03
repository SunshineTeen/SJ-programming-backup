/* 学号:1652228 姓名:王哲源 班级:计算机一班 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const char chistr[] = "零壹贰叁肆伍陆柒捌玖";

char result[256];

void daxie(int num, int flag_of_zero)
{
	char tmp[5] = {0};
	strncpy(tmp, chistr + 2 * num, 2);
	if (!num && !flag_of_zero)
		return;
	strcat(result, tmp);
}

int main()
{
	double x;

	while (1)
	{ 
		printf("请输入一个介于[0,100亿)之间的浮点数表示人民币价格:");
		cin >> x;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> x;
			printf("\n");
		}

		if (x < 0 || x >= 1e10)
		{
			printf("输入的金额应当在[0,100亿)之间，请重新输入\n");
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

	if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l)
	{
		daxie(0, 1);
		strcat(result, "圆整");

		cout << result << endl;

		return 0;
	}

	bool flag;

	daxie(a, 0);
	if (a)
		strcat(result, "圆拾");

	daxie(b, 0);
	if (a || b)
		strcat(result, "亿");

	if ((a || b) && d)
		flag = 1;
	else
		flag = 0;
	daxie(c, flag);
	if (c)
		strcat(result, "仟");

	if ((a || b || c) && e)
		flag = 1;
	else
		flag = 0;
	daxie(d, flag);
	if (d)
		strcat(result, "佰");

	if ((a || b || c || d) && f)
		flag = 1;
	else
		flag = 0;
	daxie(e, flag);
	if (e)
		strcat(result, "拾");

	daxie(f, 0);
	if (c || d || e || f)
		strcat(result, "万");

	if ((a || b || c || d || e || f) && h)
		flag = 1;
	else
		flag = 0;
	daxie(g, flag);
	if (g)
		strcat(result, "仟");

	if ((a || b || c || d || e || f || g) && i)
		flag = 1;
	else
		flag = 0;
	daxie(h, flag);
	if (h)
		strcat(result, "佰");

	if ((a || b || c || d || e || f || g || h) && j)
		flag = 1;
	else
		flag = 0;
	daxie(i, flag);
	if (i)
		strcat(result, "拾");

	daxie(j, flag);
	if (a || b || c || d || e || f || g || h || i || j)
		strcat(result, "圆");

	if ((a || b || c || d || e || f || g || h || i || j) && l)
		flag = 1;
	else
		flag = 0;
	daxie(k, flag);
	if (k)
		strcat(result, "角");

	if (!l)
		strcat(result, "整");
	else
	{
		daxie(l, 0);
		strcat(result, "分");
	}

	cout << result << endl;

	return 0;
}
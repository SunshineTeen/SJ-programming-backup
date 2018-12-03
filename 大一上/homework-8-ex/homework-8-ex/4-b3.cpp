/* 学号:1652228 姓名:王哲源 班级:计算机一班 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

/* 可根据需要添加相应的内容 */

/* 不允许对本函数做任何修改
除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数 */


/* 根据需要完成main函数 */
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

		if (x<0 || x>=1e10)
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

	if(!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !k && !l)
	{
		daxie(0, 1);
		printf("圆整\n");
		return 0;
	}

	bool flag;

	daxie(a, 0);
	if (a)
		printf("拾");

	daxie(b, 0);
	if (a || b) printf("亿");

	if ((a || b) && d)
		flag = 1;
	else
		flag = 0;
	daxie(c, flag);
	if (c)
		printf("仟");

	if ((a || b || c) && e)
		flag = 1;
	else
		flag = 0;
	daxie(d, flag);
	if (d)
		printf("佰");

	if ((a || b || c || d) && f)
		flag = 1;
	else
		flag = 0;
	daxie(e, flag);
	if (e)
		printf("拾");

	daxie(f, 0);
	if (c || d || e || f)
		printf("万");

	if ((a || b || c || d || e || f) && h)
		flag = 1;
	else
		flag = 0;
	daxie(g, flag);
	if (g)
		printf("仟");

	if ((a || b || c || d || e || f || g) && i)
		flag = 1;
	else
		flag = 0;
	daxie(h, flag);
	if (h)
		printf("佰");

	if ((a || b || c || d || e || f || g || h) && j)
		flag = 1;
	else
		flag = 0;
	daxie(i, flag);
	if (i)
		printf("拾");

	daxie(j, flag);
	if (a || b || c || d || e || f || g || h || i || j)
		printf("圆");

	if ((a || b || c || d || e || f || g || h || i || j) && l)
		flag = 1;
	else
		flag = 0;
	daxie(k, flag);
	if(k)
		printf("角");

	if (!l)
		printf("整");
	else
	{
		daxie(l, 0);
		printf("分");
	}

	printf("\n");

	return 0;
}
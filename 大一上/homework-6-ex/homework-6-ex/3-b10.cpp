//ĞÕÃû£ºÍõÕÜÔ´ °à¼¶£º¼ÆËã»ú1°à Ñ§ºÅ£º1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	printf("ÇëÊäÈëÒ»¸ö½éÓÚ[0,100ÒÚ)Ö®¼äµÄ¸¡µãÊı±íÊ¾ÈËÃñ±Ò¼Û¸ñ\n");

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
		printf("ÁãÔ²");

	switch (a)
	{
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		default:
			break;
	}
	switch (b)
	{
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		default:
			break;
	}
	if (a || b)
		printf("ÒÚ");

	switch (c)
	{
		case 1:
			printf("Ò¼Çª");
			flag = 1;
			break;
		case 2:
			printf("·¡Çª");
			flag = 1;
			break;
		case 3:
			printf("ÈşÇª");
			flag = 1;
			break;
		case 4:
			printf("ËÁÇª");
			flag = 1;
			break;
		case 5:
			printf("ÎéÇª");
			flag = 1;
			break;
		case 6:
			printf("Â½Çª");
			flag = 1;
			break;
		case 7:
			printf("ÆâÇª");
			flag = 1;
			break;
		case 8:
			printf("°ÆÇª");
			flag = 1;
			break;
		case 9:
			printf("¾ÁÇª");
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
		printf("Áã");
	switch (d)
	{
		case 1:
			printf("Ò¼°Û");
			flag = 1;
			break;
		case 2:
			printf("·¡°Û");
			flag = 1;
			break;
		case 3:
			printf("Èş°Û");
			flag = 1;
			break;
		case 4:
			printf("ËÁ°Û");
			flag = 1;
			break;
		case 5:
			printf("Îé°Û");
			flag = 1;
			break;
		case 6:
			printf("Â½°Û");
			flag = 1;
			break;
		case 7:
			printf("Æâ°Û");
			flag = 1;
			break;
		case 8:
			printf("°Æ°Û");
			flag = 1;
			break;
		case 9:
			printf("¾Á°Û");
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
		printf("Áã");
	switch (e)
	{
		case 1:
			printf("Ò¼Ê°");
			flag = 1;
			break;
		case 2:
			printf("·¡Ê°");
			flag = 1;
			break;
		case 3:
			printf("ÈşÊ°");
			flag = 1;
			break;
		case 4:
			printf("ËÁÊ°");
			flag = 1;
			break;
		case 5:
			printf("ÎéÊ°");
			flag = 1;
			break;
		case 6:
			printf("Â½Ê°");
			flag = 1;
			break;
		case 7:
			printf("ÆâÊ°");
			flag = 1;
			break;
		case 8:
			printf("°ÆÊ°");
			flag = 1;
			break;
		case 9:
			printf("¾ÁÊ°");
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
		printf("Áã");
	switch (f)
	{
		case 1:
			printf("Ò¼");
			flag = 1;
			break;
		case 2:
			printf("·¡");
			flag = 1;
			break;
		case 3:
			printf("Èş");
			flag = 1;
			break;
		case 4:
			printf("ËÁ");
			flag = 1;
			break;
		case 5:
			printf("Îé");
			flag = 1;
			break;
		case 6:
			printf("Â½");
			flag = 1;
			break;
		case 7:
			printf("Æâ");
			flag = 1;
			break;
		case 8:
			printf("°Æ");
			flag = 1;
			break;
		case 9:
			printf("¾Á");
			flag = 1;
			break;
		default:
			flag = 0;
			break;
	}
	if (c || d || e || f)
		printf("Íò");

	switch (g)
	{
		case 1:
			printf("Ò¼Çª");
			flag = 1;
			break;
		case 2:
			printf("·¡Çª");
			flag = 1;
			break;
		case 3:
			printf("ÈşÇª");
			flag = 1;
			break;
		case 4:
			printf("ËÁÇª");
			flag = 1;
			break;
		case 5:
			printf("ÎéÇª");
			flag = 1;
			break;
		case 6:
			printf("Â½Çª");
			flag = 1;
			break;
		case 7:
			printf("ÆâÇª");
			flag = 1;
			break;
		case 8:
			printf("°ÆÇª");
			flag = 1;
			break;
		case 9:
			printf("¾ÁÇª");
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
		printf("Áã");
	switch (h)
	{
		case 1:
			printf("Ò¼°Û");
			flag = 1;
			break;
		case 2:
			printf("·¡°Û");
			flag = 1;
			break;
		case 3:
			printf("Èş°Û");
			flag = 1;
			break;
		case 4:
			printf("ËÁ°Û");
			flag = 1;
			break;
		case 5:
			printf("Îé°Û");
			flag = 1;
			break;
		case 6:
			printf("Â½°Û");
			flag = 1;
			break;
		case 7:
			printf("Æâ°Û");
			flag = 1;
			break;
		case 8:
			printf("°Æ°Û");
			flag = 1;
			break;
		case 9:
			printf("¾Á°Û");
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
		printf("Áã");
	switch (i)
	{
		case 1:
			printf("Ò¼Ê°");
			flag = 1;
			break;
		case 2:
			printf("·¡Ê°");
			flag = 1;
			break;
		case 3:
			printf("ÈşÊ°");
			flag = 1;
			break;
		case 4:
			printf("ËÁÊ°");
			flag = 1;
			break;
		case 5:
			printf("ÎéÊ°");
			flag = 1;
			break;
		case 6:
			printf("Â½Ê°");
			flag = 1;
			break;
		case 7:
			printf("ÆâÊ°");
			flag = 1;
			break;
		case 8:
			printf("°ÆÊ°");
			flag = 1;
			break;
		case 9:
			printf("¾ÁÊ°");
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
		printf("Áã");
	switch (j)
	{
		case 1:
			printf("Ò¼");
			flag = 1;
			break;
		case 2:
			printf("·¡");
			flag = 1;
			break;
		case 3:
			printf("Èş");
			flag = 1;
			break;
		case 4:
			printf("ËÁ");
			flag = 1;
			break;
		case 5:
			printf("Îé");
			flag = 1;
			break;
		case 6:
			printf("Â½");
			flag = 1;
			break;
		case 7:
			printf("Æâ");
			flag = 1;
			break;
		case 8:
			printf("°Æ");
			flag = 1;
			break;
		case 9:
			printf("¾Á");
			flag = 1;
			break;
		default:
			flag = 0;
			break;
	}
	if (a || b || c || d || e || f || g || h || i || j)
		printf("Ô²");

	switch (k)
	{
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èş½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;
		default:
			break;
	}
	if (!l) printf("Õû");

	if (l && (a || b || c || d || e || f || g || h || i || j) && !k)
		printf("Áã");
	switch (l)
	{
		case 1:
			printf("Ò¼·Ö");
			break;
		case 2:
			printf("·¡·Ö");
			break;
		case 3:
			printf("Èş·Ö");
			break;
		case 4:
			printf("ËÁ·Ö");
			break;
		case 5:
			printf("Îé·Ö");
			break;
		case 6:
			printf("Â½·Ö");
			break;
		case 7:
			printf("Æâ·Ö");
			break;
		case 8:
			printf("°Æ·Ö");
			break;
		case 9:
			printf("¾Á·Ö");
			break;
		default:
			break;
	}

	printf("\n");

	return 0;
}
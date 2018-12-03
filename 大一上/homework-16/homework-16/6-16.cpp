/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int Maxn = 15;
const int Maxl = 10010;

int main()
{
	char num[Maxn][Maxl];
	char s[Maxl];
	int n = 0, cnt = 0;

	printf("请输入一个字符串\n");
	char tmp;
	while ((tmp = getchar()) != '\n')
		*(s + (++n)) = tmp;
	*(s + (++n)) = 0;

	For(i, 1, n)
	{
		if (*(s+i)<'0' || *(s + i)>'9')
			continue;
		int j = i, p = 0;
		++cnt;
		while (*(s + j) >= '0' && *(s + j) <= '9')
			*(*(num+cnt)+(++p))= *(s + (j++));
		*(*(num + cnt) + (++p)) = '\0';
		i = j;
	}

	if (!cnt)
		printf("该字符串中不存在数字\n");
	else
	{
		printf("一共有%d个整数,如下\n", cnt);
		For(i, 1, cnt)
			printf("%s\n", *(num+i) + 1);
	}
	return 0;
}

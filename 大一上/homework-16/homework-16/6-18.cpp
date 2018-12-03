/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int Maxn = 13;
const int Maxl = 25;

int main()
{
	int n;
	char s[Maxn][Maxl] = { "invalid","January","February","March","April","May","June"
						,"July","August","September","October","November","December" };
	printf("请输入月份号：\n");
	if (!scanf(" %d", &n))
		n = 0;
	char(*p)[Maxl] = s + n;
	printf("该月份的英文月名为：%s\n", p);

	return 0;
}

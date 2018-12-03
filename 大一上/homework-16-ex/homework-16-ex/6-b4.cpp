/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int Maxl = 100000;

int main()
{
	char s[Maxl];
	int n = 0;

	printf("请输入一个字符串\n");
	char tmp;
	while ((tmp = getchar()) != '\n')
		*(s + (++n)) = tmp;

	if (!n)
	{
		printf("yes\n");
		system("pause");
		return 0;
	}

	int l = 1, r = n;
	bool getans = 1;
	while (r > l)
	{
		if (*(s + l) != *(s + r))
		{
			getans = 0;
			break;
		}
		++l, --r;
	}

	printf(getans ? "yes" : "no");
	printf("\n");

	//system("pause");
	return 0;
}

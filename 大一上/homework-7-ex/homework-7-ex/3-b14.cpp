//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)

using namespace std;

int main()
{
	int a, b, c;

	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");

		scanf(" %d %d", &a, &b);
		if (a >= 2000 && a <= 2030 && b >= 1 && b <= 12)
			break;
		printf("输入错误，请重新输入\n");
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",a,b);

		scanf(" %d", &c);
		if (c>=0 && c<=6)
			break;
		printf("输入错误，请重新输入\n");
	}

	bool leapyear;
	if ((!(a % 4) && (a % 100)) || !(a % 400))
		leapyear = 1;
	else
		leapyear = 0;

	int tot;
	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
		tot = 31;
	else if (b == 4 || b == 6 || b == 9 || b == 11)
		tot = 30;
	else 
		tot = 28 + leapyear;

	printf("\n");
	printf("%d年%d月的月历为\n", a, b);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	For(i, 1, c)
		printf("        ");
	
	int p = c;
	For(i, 1, tot)
	{
		cout << setw(4) << i;
		printf("    ");
		if (c == 6)
		{
			c = 0;
			printf("\n");
		}
		else
			++c;
	}
	printf("\n");

	return 0;
}
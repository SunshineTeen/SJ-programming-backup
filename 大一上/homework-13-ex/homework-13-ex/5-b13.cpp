/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

void Sort(char Name[][15], char Id[][15], int low, int high)
{
	if (low >= high)
		return;

	const int Maxl = 15;
	char tmp[Maxl], _tmp[Maxl];
	int l = low, r = high;

	strcpy(tmp, Name[l]);
	strcpy(_tmp, Id[l]);
	while (l < r)
	{
		while (l < r && strcmp(tmp, Name[r]) < 0)
			--r;
		if (l < r)
		{
			strcpy(Name[l], Name[r]);
			strcpy(Id[l], Id[r]);
		}
		while (l < r && strcmp(tmp, Name[l])>0)
			++l;
		if (l < r)
		{
			strcpy(Name[r], Name[l]);
			strcpy(Id[r], Id[l]);
		}
	}
	strcpy(Name[l], tmp);
	strcpy(Id[l], _tmp);
	Sort(Name, Id, low, l - 1);
	Sort(Name, Id, r + 1, high);
}

int init()
{
	int res;
	while (1)
	{
		cin >> res;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了，请重新输入  :";
			cin >> res;
		}
		if (res <= 0)
		{
			printf("人数应该为正整数，请重新输入\n");
			continue;
		}
		return res;
	}
}

int main()
{
	const int Maxn = 200;
	const int Maxl = 15;

	int n;
	char Name[Maxn][Maxl], Id[Maxn][Maxl];
	char aim[Maxl];

	printf("请输入学生人数 :");
	n = init();

	For(i, 1, n)
	{
		printf("请输入第%d个学生的姓名和学号 : ",i);
		scanf(" %s %s", Name[i] + 1, Id[i] + 1);
	}
	Sort(Name, Id, 1, n);

	printf("请输入要查找的学生姓名 : ");
	scanf(" %s", aim + 1);
	int p = 1;
	while (p <= n)
	{
		int cmp = strcmp(aim, Name[p]);
		if (cmp < 0)
		{
			p = n + 1;
			break;
		}
		if (!cmp)
			break;
		++p;
	}
	if (p == n + 1)
		printf("未查找到该同学\n");
	else
		printf("查找到该同学，其学号为%s\n", Id[p]+1);

	return 0;
}

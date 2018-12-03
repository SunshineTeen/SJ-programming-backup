/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

void init(int score[], int i)
{
	cin >> score[i];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "求你别乱打字符了。。请按标准输入成绩 : ";
		cin >> score[i];
	}
}

int main()
{
	const int n = 10;
	const int Maxl = 100;
	char Name[n + 5][Maxl], Id[n + 5][Maxl];
	int score[n + 5];
	int cnt = 0;

	printf("请依次输入10个学生的姓名、学号和成绩\n");
	For(i, 1, n)
	{
		cin >> Name[i] >> Id[i];
		init(score, i);
		if (score[i] < 60) ++cnt;
	}

	if (!cnt)
		printf("没有不及格的人\n");
	else
	{
		printf("不及格的人为\n");
		For(i, 1, n)
			if (score[i] < 60)
				printf("姓名：%s      学号：%s\n", Name[i], Id[i]);
	}

	//system("pause");/////////////////////////
	return 0;
}

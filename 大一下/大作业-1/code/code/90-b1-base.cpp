/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include "cmd_console_tools.h"
#include "90-b1.h"

using namespace std;

bool file_input(char *file_name, int(*map)[Maxm], int &n, int &m)
{
	setconsoleborder(hout, 80, 50);
	printf("请输入学号(输入 1651234 对应会打开 test\1651234.dat 文件)\n\n");

	scanf(" %s", file_name);
	char file_root[200] = ".\\test\\"; /*  .\文件所在目录下文件 ..\文件所在上一级目录下目录*/
	strcat(file_root, file_name);
	strcat(file_root, ".dat");
	if (freopen(file_root, "r", stdin) == NULL)
	{
		printf("打开文件%s失败\n", file_root);
		freopen("CON", "r", stdin);//重定义输入流回控制台
		return 0;
	}
	scanf(" %d %d", &n, &m);
	reset(map, n, m);
	For(i, 1, n) For(j, 1, m)
		scanf(" %d", &map[i][j]);
	freopen("CON", "r", stdin);//重定义输入流回控制台
	return 1;
}
void output_file_ans(char *file_name, const int n, const int m)
{
	char file_root[200] = ".\\test\\"; /*  .\文件所在目录下文件 ..\文件所在上一级目录下目录*/
	bool tmp[Maxn][Maxm];
	strcat(file_root, file_name);
	strcat(file_root, ".ans");
	freopen(file_root, "r", stdin);

	int ans[Maxn][Maxm];
	For(i, 1, n) For(j, 1, m)
		scanf(" %d", &ans[i][j]);
	printf("\n\n答案文件内容:\n");
	output_array(9, ans, n, m, tmp);
	printf("\n");
	freopen("CON", "r", stdin);//重定义输入流回控制台
}

void work_array(int(*map)[Maxm], const int n, const int m, const int mode)
{
	bool flag[Maxn][Maxm];

	if (mode != 9)
		reset_map(map, n, m);

	printf("\n初始数组:\n");
	output_array(0, map, n, m, flag);

	while (1)
	{
		if (mode == 9)
			break;
		printf("\n按回车键进行寻找可消除项...");
		while (_getch() != '\r');
		printf("\n");
		if (!check(map, n, m, flag))
		{
			printf("无可消除项\n");
			break;
		}
		printf("当前可消除项目:\n");
		output_array(1, map, n, m, flag);
		printf("\n");
		if (mode == 1)
			return;

		alter_map(map, n, m, flag);
		printf("\n按回车键进行下落操作...");
		while (_getch() != '\r');
		printf("\n");
		output_array(2, map, n, m, flag);
		printf("\n");

		fill_map(map, n, m, flag);
		printf("\n按回车键进行填充操作...");
		while (_getch() != '\r');
		printf("\n");
		output_array(3, map, n, m, flag);
		printf("\n");
	}

	if (mode == 2)
		return;
	find(map, n, m, flag);

	if (mode != 9)
	{
		printf("\n按回车键查询可行交换(可行交换将用不同底色显示)...");
		while (_getch() != '\r');
	}
	else
		printf("\n\n可行交换如下不同底色显示:");
	printf("\n");
	output_array(4, map, n, m, flag);
}

void output_array(const int step, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm])
{
	printf("  |");
	For(i, 1, m)
		printf("  %d", i);
	printf(" \n");
	printf("--+");
	For(i, 1, m)
		printf("---");
	printf("-\n");

	For(i, 1, n)
	{
		printf("%c |", 'A' + i - 1);
		For(j, 1, m)
		{
			printf("  ");
			int bgc = 0, fgc = 7;
			if ((step == 1 && flag[i][j]) || (step == 2 && !map[i][j])
				|| (step == 3 && flag[i][j]) || (step == 4 && flag[i][j]))
				bgc = 14, fgc = 1;
			if (step == 9 && map[i][j] >= 90)
				bgc = 14, fgc = 1, map[i][j] -= 90;
			setcolor(hout, bgc, fgc);
			printf("%d", map[i][j]);
			setcolor(hout, 0, 7);
		}
		printf(" \n");
	}
}

//array fall down
void alter_map(int(*map)[Maxm], const int n, const int m, bool(*del)[Maxm])
{
	For(i, 1, n) For(j, 1, m)
		if (del[i][j])
			map[i][j] = 0;
	opFor(i, n, 1) For(j, 1, m)
	{
		if (map[i][j])
			continue;
		int prei = i, curi = i - 1;
		while (curi)
		{
			while (!map[curi][j])
				--curi;
			if (!curi)
				break;
			map[prei][j] = map[curi][j];
			del[prei][j] = 0;
			map[curi][j] = 0;
			del[curi][j] = 1;
			--prei;
			--curi;
		}
	}
}

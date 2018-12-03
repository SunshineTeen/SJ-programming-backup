/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

int main()
{
	srand((unsigned)time(0));
	int map[Maxn][Maxm];
	while (1)
	{
		output_menu();
		int mode, n, m, last;
		if (!init_mode(mode))
			continue;
		if (!mode)
			break;
		init(n, m);
		reset(map, n, m, last);

		if (mode == 1)
			work_1(map, n, m, last);
		else if (mode == 2)
			work_2(map, n, m, last);
		else if (mode == 3)
			work_3(map, n, m, last);
		else if (mode == 4)
			work_4(map, n, m, last);
		else if (mode == 5)
			work_5(map, n, m, last);
		else if (mode == 6)
			work_6(map, n, m, last);
		else if (mode == 7)
			work_7(7, map, n, m, last);
		else if (mode == 8)
			work_8(map, n, m, last);
		else // mode==9
			work_9(map, n, m, last);

		End();
	}

	return 0;
}

void output_menu()
{
	setfontsize(hout, L"点阵字体", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);
	For(i, 1, 45)
		printf("-");
	printf("\n");

	printf("1.内部数组，随机生成初始5个球\n");
	printf("2.内部数组，随机生成60%%的球，寻找移动路径\n");
	printf("3.内部数组，完整版\n");
	printf("4.画出n*n的框架（无分割线），随机显示5个球\n");
	printf("5.画出n*n的框架（有分割线），随机显示5个球\n");
	printf("6.n*n的框架，60%%的球，支持鼠标，完成一次移动\n");
	printf("7.cmd图形界面完整版\n");
	printf("8.cmd图形界面完整版-支持同时读键\n");
	printf("9.双击及左右键同时按下操作屏蔽单击\n");
	printf("0.退出\n");

	For(i, 1, 45)
		printf("-");
	printf("\n");


}

void End()
{
	char op[1024] = "LoveTaihouForever";
	setcolor(hout, 0, 7);
	printf("本小题结束，请输入End继续...\n");
	while (1)
	{
		int p = 0;
		while ((op[++p] = getchar()) != '\n');
		if (alpha_upper(op[1]) != 'E' || alpha_upper(op[2]) != 'N' || alpha_upper(op[3]) != 'D')
		{
			printf("输入错误\n");
			continue;
		}
		return;
	}

}

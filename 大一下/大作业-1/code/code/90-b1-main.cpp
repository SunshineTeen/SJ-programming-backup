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

int main()
{
	srand((unsigned)time(0));
	int map[Maxn][Maxm];
	while (1)
	{
		output_menu();
		int mode, n, m;
		char file_name[100];
		if (!init_mode(mode))
			continue;
		if (!mode)
			break;

		if (mode != 9)
		{
			init(n, m);
			reset(map, n, m);
		}
		if (mode >= 1 && mode <= 3)
			work_array(map, n, m, mode);
		else if (mode == 4 || mode == 5)
			cmd_reset(map, n, m, mode);
		else if (mode == 6 || mode == 7)
			work_cmd(map, n, m, mode);
		else if (mode == 8)
			work_game(map, n, m);
		else if (file_input(file_name, map, n, m)) // mode == 9
		{
			work_array(map, n, m, 9);
			output_file_ans(file_name, n, m);
		}

		End();
	}

	return 0;
}
void output_menu()
{
	setfontsize(hout, L"点阵字体", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);
	For(i, 1, 55)
		printf("-");
	printf("\n");

	printf("1.内部数组，生成初始状态，寻找是否有初始可消除项\n");
	printf("2.内部数组，消除初始可消除项后非0项下落并用0填充\n");
	printf("3.内部数组，消除初始可消除项后查找消除提示\n");
	printf("4.n*n的框架(无分隔线)，显示初始状态\n");
	printf("5.n*n的框架(有分隔线)，显示初始状态\n");
	printf("6.n*n的框架(有分隔线)，显示初始状态及初始可消除项\n");
	printf("7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示\n");
	printf("8.cmd图形界面完整版\n");
	printf("9.从文件中读取数据以验证查找消除提示的算法的正确性\n");
	printf("0.退出\n");

	For(i, 1, 55)
		printf("-");
	printf("\n");
}

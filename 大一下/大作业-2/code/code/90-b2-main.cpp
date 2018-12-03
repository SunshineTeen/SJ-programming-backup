/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<conio.h>
#include<io.h>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;

int main()
{
	srand((unsigned)time(0));
	while (1)
	{
		output_menu();

		int mode;
		init(mode);
		if (!mode)
			break;
		if (mode < 0 || mode>5)
			continue;

		work(mode);
		End();
	}

	return 0;
}

void output_menu()
{
	setfontsize(hout, L"点阵字体", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);

	cout << "-------------------------------" << endl;
	cout << "1.字符界面游戏" << endl;
	cout << "2.图形界面游戏" << endl;
	cout << "3.图形界面自动解" << endl;
	cout << "4.图形界面游戏(键盘方向键操作)" << endl;
	cout << "5.图形界面游戏(鼠标键盘操作)" << endl;
	cout << "0.退出" << endl;
	cout << "-------------------------------" << endl;
	cout << "请选择[0-5] ";
}

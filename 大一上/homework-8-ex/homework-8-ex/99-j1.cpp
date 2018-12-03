/* 学号:1652228 姓名:王哲源 班级:计算机一班 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

						/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 在指定位置处打印一个指定的字符 */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int    i;

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand(unsigned int(time(0)));

	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	rand()函数的功能：随机生成一个在 0-32767 之间的整数
	注意：程序有bug，如果两次循环生成的XY坐标恰好完全相同，则字母数量会不足20个（仅说明，不需要解决此bug） */
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	/* 在此处添加需要的代码-begin */
	//_getch();
	gotoxy(hout, 35, 9);
	int x = 35, y = 9;
	while (1)
	{
		char op = _getch();
		if (op == 'q' || op == 'Q')
			break;
		if (op == -32)//上下左右均为功能键，有两个键值，且第一个均为-32，防止ascii和HPKM冲突
		{
			op = _getch();
			if (op == 72)//Up
			{
				if (y == 1)
					continue;
				gotoxy(hout, x, --y);
			}
			if (op == 75)//Left
			{
				if (x == 1)
					continue;
				gotoxy(hout, --x, y);
			}
			if (op == 80)//Down
			{
				if (y == MAX_Y)
					continue;
				gotoxy(hout, x, ++y);
			}
			if (op == 77)//Right
			{
				if (x == MAX_X)
					continue;
				gotoxy(hout, ++x, y);
			}
		}
		if (op == 32)
			cout << " \b";
	}

	/* 在此处添加需要的代码-end */

	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	getchar();
	return 0;
}
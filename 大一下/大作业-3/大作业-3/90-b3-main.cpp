/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include "cmd_console_tools.h"
#include "90-b3.h"

using namespace std;

int main()
{
	setfont();
	Alarm *head;
	get_alarm_ini(head);

	int option = CLOCK;
	int mode = Mechanical;
	while (1)
	{
		if (option == CLOCK)
			clock_work(head, option, mode);
		else if (option == ALARM)
			alarm_work(head, option);
	}

	return 0;
}

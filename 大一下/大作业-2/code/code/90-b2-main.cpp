/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
	setfontsize(hout, L"��������", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);

	cout << "-------------------------------" << endl;
	cout << "1.�ַ�������Ϸ" << endl;
	cout << "2.ͼ�ν�����Ϸ" << endl;
	cout << "3.ͼ�ν����Զ���" << endl;
	cout << "4.ͼ�ν�����Ϸ(���̷��������)" << endl;
	cout << "5.ͼ�ν�����Ϸ(�����̲���)" << endl;
	cout << "0.�˳�" << endl;
	cout << "-------------------------------" << endl;
	cout << "��ѡ��[0-5] ";
}

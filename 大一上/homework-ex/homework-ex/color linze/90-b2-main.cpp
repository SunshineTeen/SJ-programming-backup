/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
	setfontsize(hout, L"��������", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);
	For(i, 1, 45)
		printf("-");
	printf("\n");

	printf("1.�ڲ����飬������ɳ�ʼ5����\n");
	printf("2.�ڲ����飬�������60%%����Ѱ���ƶ�·��\n");
	printf("3.�ڲ����飬������\n");
	printf("4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����\n");
	printf("5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����\n");
	printf("6.n*n�Ŀ�ܣ�60%%����֧����꣬���һ���ƶ�\n");
	printf("7.cmdͼ�ν���������\n");
	printf("8.cmdͼ�ν���������-֧��ͬʱ����\n");
	printf("9.˫�������Ҽ�ͬʱ���²������ε���\n");
	printf("0.�˳�\n");

	For(i, 1, 45)
		printf("-");
	printf("\n");


}

void End()
{
	char op[1024] = "LoveTaihouForever";
	setcolor(hout, 0, 7);
	printf("��С�������������End����...\n");
	while (1)
	{
		int p = 0;
		while ((op[++p] = getchar()) != '\n');
		if (alpha_upper(op[1]) != 'E' || alpha_upper(op[2]) != 'N' || alpha_upper(op[3]) != 'D')
		{
			printf("�������\n");
			continue;
		}
		return;
	}

}

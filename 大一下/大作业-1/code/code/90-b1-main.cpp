/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
	setfontsize(hout, L"��������", 16);
	setcolor(hout, 0, 7);
	setconsoleborder(hout, 80, 25);
	For(i, 1, 55)
		printf("-");
	printf("\n");

	printf("1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������\n");
	printf("2.�ڲ����飬������ʼ����������0�����䲢��0���\n");
	printf("3.�ڲ����飬������ʼ������������������ʾ\n");
	printf("4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬\n");
	printf("5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬\n");
	printf("6.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬����ʼ��������\n");
	printf("7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ\n");
	printf("8.cmdͼ�ν���������\n");
	printf("9.���ļ��ж�ȡ��������֤����������ʾ���㷨����ȷ��\n");
	printf("0.�˳�\n");

	For(i, 1, 55)
		printf("-");
	printf("\n");
}

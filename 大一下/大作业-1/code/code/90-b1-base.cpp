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

bool file_input(char *file_name, int(*map)[Maxm], int &n, int &m)
{
	setconsoleborder(hout, 80, 50);
	printf("������ѧ��(���� 1651234 ��Ӧ��� test\1651234.dat �ļ�)\n\n");

	scanf(" %s", file_name);
	char file_root[200] = ".\\test\\"; /*  .\�ļ�����Ŀ¼���ļ� ..\�ļ�������һ��Ŀ¼��Ŀ¼*/
	strcat(file_root, file_name);
	strcat(file_root, ".dat");
	if (freopen(file_root, "r", stdin) == NULL)
	{
		printf("���ļ�%sʧ��\n", file_root);
		freopen("CON", "r", stdin);//�ض����������ؿ���̨
		return 0;
	}
	scanf(" %d %d", &n, &m);
	reset(map, n, m);
	For(i, 1, n) For(j, 1, m)
		scanf(" %d", &map[i][j]);
	freopen("CON", "r", stdin);//�ض����������ؿ���̨
	return 1;
}
void output_file_ans(char *file_name, const int n, const int m)
{
	char file_root[200] = ".\\test\\"; /*  .\�ļ�����Ŀ¼���ļ� ..\�ļ�������һ��Ŀ¼��Ŀ¼*/
	bool tmp[Maxn][Maxm];
	strcat(file_root, file_name);
	strcat(file_root, ".ans");
	freopen(file_root, "r", stdin);

	int ans[Maxn][Maxm];
	For(i, 1, n) For(j, 1, m)
		scanf(" %d", &ans[i][j]);
	printf("\n\n���ļ�����:\n");
	output_array(9, ans, n, m, tmp);
	printf("\n");
	freopen("CON", "r", stdin);//�ض����������ؿ���̨
}

void work_array(int(*map)[Maxm], const int n, const int m, const int mode)
{
	bool flag[Maxn][Maxm];

	if (mode != 9)
		reset_map(map, n, m);

	printf("\n��ʼ����:\n");
	output_array(0, map, n, m, flag);

	while (1)
	{
		if (mode == 9)
			break;
		printf("\n���س�������Ѱ�ҿ�������...");
		while (_getch() != '\r');
		printf("\n");
		if (!check(map, n, m, flag))
		{
			printf("�޿�������\n");
			break;
		}
		printf("��ǰ��������Ŀ:\n");
		output_array(1, map, n, m, flag);
		printf("\n");
		if (mode == 1)
			return;

		alter_map(map, n, m, flag);
		printf("\n���س��������������...");
		while (_getch() != '\r');
		printf("\n");
		output_array(2, map, n, m, flag);
		printf("\n");

		fill_map(map, n, m, flag);
		printf("\n���س�������������...");
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
		printf("\n���س�����ѯ���н���(���н������ò�ͬ��ɫ��ʾ)...");
		while (_getch() != '\r');
	}
	else
		printf("\n\n���н������²�ͬ��ɫ��ʾ:");
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

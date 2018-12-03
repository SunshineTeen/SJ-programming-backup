/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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

void alarm_work(Alarm *head, int &option)
{
	Alarm *cur;
	
	cur = head->nxt;
	output_alarm_menu();
	output_alarm(cur, head);

	while (1)
	{
		refresh_ini(head);
		int op = get_key(hin, 0);
		while (op != VK_BACK && op != VK_DELETE && op != VK_F1 && op != VK_F2
			&& op != VK_UP && op != VK_DOWN)
			op = get_key(hin, 0);
		if (op == VK_BACK)
		{
			option ^= 1;
			return;
		}
		if (op == VK_DELETE)
		{
			if (cur != head)
			{
				Alarm *tmp = cur->nxt;
				cur->pre->nxt = cur->nxt;
				cur->nxt->pre = cur->pre;
				delete cur;
				cur = tmp;
				if (cur == head)
					cur = head->nxt;
			}
			output_alarm(cur, head);
			continue;
		}
		if (op == VK_UP || op == VK_DOWN)
		{
			cur = op == VK_UP ? cur->pre : cur->nxt;
			if (cur == head)
				cur = op == VK_DOWN ? head->nxt : head->pre;
			output_alarm(cur, head);
			continue;
		}
		if (op == VK_F1 && cur == head)
			continue;
		Alarm *tmp = op == VK_F1 ? tmp = cur : tmp = head;
		bool Cancle = alarm_set(head, tmp);
		if (!Cancle)
			cur = tmp;
		output_alarm_menu();
		output_alarm(cur, head);
	}
}
bool alarm_set(Alarm *const head, Alarm *&cur)
{
	if (cur == head)
	{
		Alarm *New = new(nothrow) Alarm;
		if (New == NULL)
		{
			printf("Alarm setting Error\n");
			exit(-1);
		}
		New->h = New->m = New->mode = 0;
		New->nxt = New->pre = New;
		cur = New;
	}
	int choose = 1;
	output_alarm_setting();
	while (1)
	{
		output_alarm(cur, choose);
		int op = get_key(hin, 0);
		while (op != VK_BACK && op != VK_F1	&& op != VK_UP && op != VK_DOWN && op != VK_RETURN)
			op = get_key(hin, 0);
		if (op == VK_BACK)
			return 1;
		if (op == VK_RETURN)
		{
			if (cur->nxt == cur)
			{
				cur->nxt = head->nxt;
				head->nxt->pre = cur;
				head->nxt = cur;
				cur->pre = head;
			}
			return 0;
		}
		if (op == VK_UP || op == VK_DOWN)
		{
			int delta = op == VK_UP ? 1 : -1;
			if (choose == 1)
			{
				cur->h += delta;
				if (cur->h > 23)
					cur->h -= 24;
				if (cur->h < 0)
					cur->h += 24;
			}
			else if (choose == 2)
			{
				cur->m += delta;
				if (cur->m > 59)
					cur->m -= 60;
				if (cur->m < 0)
					cur->m += 60;
			}
			else
			{
				cur->mode += delta;
				if (cur->mode > 10)
					cur->mode -= 11;
				if (cur->mode < 0)
					cur->mode += 11;
			}
			continue;
		}
		if (op == VK_F1)
		{
			++choose;
			if (choose > 3)
				choose -= 3;
			continue;
		}
	}
}

void output_alarm(Alarm *cur, const Alarm *head)
{
	const int X = 0;
	const int Y = 3;
	gotoxy(hout, X, Y);

	if (cur == head)
		output_str((unsigned char *)"��ǰ������", Abnormal);
	else
	{
		output_dig(cur->h, Abnormal);
		output_ch((unsigned char *)"��", Abnormal);
		output_dig(cur->m, Abnormal);
	}
	gotoxy(hout, X, Y + 18);
	output_str(cur == head ? (unsigned char*)"���ޡ�" : (unsigned char*)Mode[cur->mode], Abnormal);
}
void output_alarm(Alarm *cur, const int choose)
{
	const int X = 0;
	const int Y = 3;

	gotoxy(hout, X, Y);
	output_dig(cur->h, choose == 1 ? Abnormal : Normal);
	output_ch((unsigned char *)"��", Normal);
	output_dig(cur->m, choose == 2 ? Abnormal : Normal);
	gotoxy(hout, X, Y + 18);
	output_str((unsigned char *)Mode[cur->mode], choose == 3 ? Abnormal : Normal);

}
void output_alarm_menu()
{
	system("cls");
	const int X = 0;
	const int Y = 3;

	gotoxy(hout, 0, Y + 38);
	output_str((unsigned char *)"�������鿴��������", LED);
	gotoxy(hout, 0, Y + 56);
	output_str((unsigned char *)"���ƣ����޸ĵ�ǰ����", LED);
	gotoxy(hout, 0, Y + 74);
	output_str((unsigned char *)"���ƣ��½�����", LED);
	gotoxy(hout, 0, Y + 92);
	output_str((unsigned char *)"���ģ������ɾ��", LED);
	gotoxy(hout, 0, Y + 110);
	output_str((unsigned char *)"���£���������˻�", LED);
}
void output_alarm_setting()
{
	system("cls");
	const int X = 0;
	const int Y = 3;

	gotoxy(hout, 0, Y + 38);
	output_str((unsigned char *)"���������ڵ�ǰ��ѡ��ֵ", LED);
	gotoxy(hout, 0, Y + 56);
	output_str((unsigned char *)"���ƣ����л��޸���", LED);
	gotoxy(hout, 0, Y + 74);
	output_str((unsigned char *)"���س���ȷ���޸�", LED);
	gotoxy(hout, 0, Y + 92);
	output_str((unsigned char *)"���£��������ȡ��", LED);
}

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
#include "90-b4.h"

using namespace std;

int main()
{
	char s[120];
	int len = 0;
	init(s,len);
	output(s, len);

	setcolor(hout, 0, 7);
	printf("\n\n\n");
	printf("二维码生成完成，请按回车继续");
	while (_getch() != '\r');

	return 0;
}

void init(char *s, int &len)
{
	printf("请输入要生成二维码的文本(100字节以内)： ");
	while ((s[++len] = getchar()) != '\n');
	s[len--] = '\0';
}

void output(const char *const s, const int len)
{
	setconsoleborder(hout, 180, 180, 999);
	system("cls");

	bool QRcode[MAX_MODULESIZE][MAX_MODULESIZE];

	int size = encode(s, len, QRcode) * 4 + 17;
	if (size == -1)
	{ 
		printf("文本过大，无法编码\n");
		return;
	}
	SetConsoleTextAttribute(hout, WHITE_BLOCK);
	For(i, 0, size)
		printf("  ");
	printf("  \n");
	sFor(i, 0, size)
	{
		SetConsoleTextAttribute(hout, WHITE_BLOCK);
		printf("  ");
		sFor(j, 0, size)
		{
			SetConsoleTextAttribute(hout, QRcode[i][j] ? BLACK_BLOCK : WHITE_BLOCK);
			printf("  ");
		}
		SetConsoleTextAttribute(hout, WHITE_BLOCK);
		printf("  \n");
	}
	SetConsoleTextAttribute(hout, WHITE_BLOCK);
	For(i,0,size)
		printf("  ");
	printf("  \n");
}

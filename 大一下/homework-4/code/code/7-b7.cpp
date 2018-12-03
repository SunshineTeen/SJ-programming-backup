//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define FFLUSH while(getchar()!='\n')

using namespace std;

const int N = 10;
const short bin[N] = { 1,2,4,8,16,32,64,128,256,512 };

void output(const short Switch)
{
	For(i, 0, N-1)
		printf("%c   ", 'A' + i);
	printf("\n");
	For(i, 0, N - 1)
		if (Switch&bin[i])
			printf("ON  ");
		else
			printf("OFF ");
	printf("\n");
}

void alpha_upper(char &ch)
{
	if (ch >= 'a' && ch <= 'z')
		ch -= 32;
}

bool work(const int i, short &Switch)
{
	char op[65535] = "TaihouDaisuki";
	scanf(" %s", op);
	alpha_upper(op[0]);
	alpha_upper(op[1]);
	alpha_upper(op[2]);
	if (op[0] == 'O' && op[1] == 'N' && op[2]=='\0')
		Switch |= bin[i];
	else if (op[0] == 'O' && op[1] == 'F' && op[2] == 'F' && op[3]=='\0')
	{
		Switch = ~Switch;
		Switch |= bin[i];
		Switch = ~Switch;
	}
	else
	{
		printf("输入错误，请重新输入\n");
		FFLUSH;
		return 0;
	}

	return 1;
}

int init()
{
	printf("请输入操作[例:A ON 或 H OFF],退出请输入END : ");
	char op[65535] = "TaihouDaisuki";
	scanf(" %s", op);
	For(i, 0, 2)
		alpha_upper(op[i]);
	if (op[0] == 'E' && op[1] == 'N' && op[2] == 'D' && op[3] == '\0')
		return -1;
	if (op[0]<'A' || op[0]>'J' || op[1]!='\0')
	{
		printf("输入错误，请重新输入\n");
		FFLUSH;
		return -2;
	}
	return op[0] - 'A';
}

int main()
{
	short Switch = 0x0000;
	while (1)
	{
		int alpha = init();
		if (alpha == -2)
			continue;
		if (alpha == -1)
			break;
		if (!work(alpha,Switch))
			continue;
		output(Switch);
	}

	return 0;
}
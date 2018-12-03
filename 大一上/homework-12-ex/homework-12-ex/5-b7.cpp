/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>
#include<conio.h>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

const int Maxh = 10;
const int Maxn = Maxh+10;

int n,cnt,mode;
int stack[3][Maxn];
int top[3];
char st, ed, tmp;
int show;
int last;

void print()
{
	printf("A:");
	For(i, 1, top[0] - 1)
		cout << setw(2) << stack[0][i];
	For(i, 1, 10 - top[0] + 1)
		printf("  ");
	printf(" ");

	printf("B:");
	For(i, 1, top[1] - 1)
		cout << setw(2) << stack[1][i];
	For(i, 1, 10 - top[1] + 1)
		printf("  ");
	printf(" ");

	printf("C:");
	For(i, 1, top[2] - 1)
		cout << setw(2) << stack[2][i];
	For(i, 1, 10 - top[2] + 1)
		printf("  ");

	printf("\n");
}

int pop(int i)
{
	int res = stack[i][top[i]-1];
	stack[i][--top[i]] = 0;
	return res;
}
void push(int x, int i)
{
	stack[i][top[i]++] = x;
}

inline void put_pic()
{
	printf("\n");
	opFor(i, Maxh,1)
	{
		if (stack[0][i])
			cout << setw(12) << stack[0][i];
		else
			printf("            ");
		if (stack[1][i])
			cout << setw(10) << stack[1][i];
		else
			printf("          ");
		if (stack[2][i])
			cout << setw(10) << stack[2][i];
		else
			printf("          ");
		printf("\n");
	}
	printf("         =========================\n");
	printf("           A         B         C\n");
	printf("\n\n\n");
}
inline void output(int num, char from, char to)
{
	system("cls");
	printf("从 %c 移动到 %c , 共 %d 层 , 延时设置为 %d , ", st, ed, n, mode);
	if (!show)
		printf("不");
	printf("显示内部数组数值\n");

	put_pic();

	++cnt;
	printf("第");
	cout << setw(4) << cnt;
	cout << setw(4) << "步(" << num << "):";
	printf(" %c---->%c ", from, to);
	if(show)
		print();
}

inline void move(int num, char from, char to, char tmp)
{
	if (!num)
		return;
	move(num - 1, from, tmp, to);
	int x = pop(from - 'A');
	push(x, to - 'A');

	if (!mode)
	{
		char ch;
		while (1)
		{
			ch = _getch();
			if (ch == '\n' || ch=='\r')
				break;
		}
	}
	else
		Sleep(last);

	output(num, from, to);
	move(num - 1, tmp, to, from);
}

void reset(int n, char x)
{

	top[0] = top[1] = top[2] = 1;
	int Id = x - 'A';
	opFor(i, n, 1)
		push(i, Id);

	system("cls");
	printf("从 %c 移动到 %c , 共 %d 层 , 延时设置为 %d , ", st, ed, n, mode);
	if (!show) 
		printf("不");
	printf("显示内部数组数值\n");

	put_pic();
	printf("初始：                ");
	if(show)
		print();
}

void work()
{
	reset(n, st);
	move(n, st, ed, tmp);
}

void pre_work()
{
	bool f[3] = { 0 };
	if (st >= 'a' && st <= 'c')
		st -= 32;
	if (ed >= 'a' && ed <= 'c')
		ed -= 32;
	f[st - 'A'] = 1;
	f[ed - 'A'] = 1;
	if (!f[0])
		tmp = 'A';
	else if (!f[1])
		tmp = 'B';
	else
		tmp = 'C';
	
	if (mode == 1)
		last = 1000;
	else if (mode == 2)
		last = 800;
	else if (mode == 3)
		last = 600;
	else if (mode == 4)
		last = 400;
	else if (mode == 5)
		last = 200;
}

void init()
{
	while (1)
	{
		printf("请输入盘子的个数n (1-10) : ");
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> n;
		}
		if (n <= 0 || n >= 11)
		{
			printf("盘子的个数应当介于1-16之间，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入起始圆柱名（A,B,C）：");
		cin >> st;
		if (!((st >= 'A' && st <= 'C') || (st >= 'a' && st <= 'c')))
		{
			printf("圆盘编号应当为A,B,C，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入结束圆柱名（A,B,C）：");
		cin >> ed;
		if (!((ed >= 'A' && ed <= 'C') || (ed >= 'a' && ed <= 'c')))
		{
			printf("圆盘编号应当为A,B,C，请重新输入\n");
			continue;
		}
		if (st == ed)
		{
			printf("起始和目标盘不能为同一个，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入移动速度(0-5 : 0-按回车单步演示 1-延时最长 5-延时最短)：");
		cin >> mode;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> mode;
		}
		if (mode < 0 || mode>5)
		{
			printf("移动速度模式为0-5 请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入是否显示内部数组数值(0-不显示 1-显示)：");
		cin >> show;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			cin >> show;
		}
		if (show < 0 || show>1)
		{
			printf("请输入0或1，请重新输入\n");
			continue;
		}
		break;
	}
	cin.ignore(1024, '\n');
}

int main()
{
	system("cls");
	system("mode con cols=100 lines=30");

	init();
	pre_work();
	work();

	//system("pause");/////////////////////////
	return 0;
}
//清屏 system("cls");
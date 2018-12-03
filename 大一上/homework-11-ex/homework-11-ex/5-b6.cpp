/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

const int Maxn = 15;

int cnt;
int stack[3][Maxn];
int top[3];

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
	return stack[i][--top[i]];
}
void push(int x, int i)
{
	stack[i][top[i]++] = x;
}

inline void output(int num, char from, char to)
{
	++cnt;
	printf("第");
	cout << setw(4) << cnt;
	cout << setw(4) << "步(" << num << "):";
	printf(" %c---->%c ", from, to);
	print();
}
inline void move(int num, char from, char to, char tmp)
{
	if (!num)
		return;
	move(num - 1, from, tmp, to);
	int x = pop(from - 'A');
	push(x,to - 'A');
	output(num, from, to);
	move(num - 1, tmp, to, from);
}

void reset(int n,char x)
{
	top[0] = top[1] = top[2] = 1;
	int Id = x - 'A';
	opFor(i, n, 1)
		push(i, Id);

	printf("初始：                ");
	print();
}

int main()
{
	system("cls");
	system("mode con cols=100 lines=30");

	int n;
	char st, ed, tmp;
	bool f[3] = {0};

	while (1)
	{
		printf("请输入盘子的个数n (1-10) : ");
		cin >> n;
		printf("\n");
		printf("请输入起始圆柱名（A,B,C）：");
		cin >> st;
		printf("\n");
		printf("请输入目标圆柱名（A,B,C）：");
		cin >> ed;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "求你别乱打字符了。。请按标准输入 : ";
			printf("请输入盘子的个数n (1-10) : ");
			cin >> n;
			printf("\n");
			printf("请输入起始圆柱名（A,B,C）：");
			cin >> st;
			printf("\n");
			printf("请输入目标圆柱名（A,B,C）：");
			cin >> ed;
			printf("\n");
		}

		if (n <= 0 || n >= 11)
		{
			printf("盘子的个数应当介于1-16之间，请重新输入\n");
			continue;
		}
		if (st == ed)
		{
			printf("起始和目标盘不能为同一个，请重新输入\n");
			continue;
		}
		if (!((st>='A' && st<='C')||(st>='a' && st<='c')) || !((ed>='A' && ed<='C')||(ed>='a' && ed<='c')))
		{
			printf("圆盘编号应当为A,B,C，请重新输入\n");
			continue;
		}
		break;
	}
	if(st>='a' && st<='c')
		st-=32;
	if(ed>='a' && ed<='c')
		ed-=32;

	f[st - 'A'] = 1;
	f[ed - 'A'] = 1;
	if (!f[0])
		tmp = 'A';
	else if (!f[1])
		tmp = 'B';
	else
		tmp = 'C';

	reset(n,st);
	move(n, st, ed, tmp);

	return 0;
}

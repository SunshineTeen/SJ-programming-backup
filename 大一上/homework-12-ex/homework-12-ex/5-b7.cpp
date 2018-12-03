/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
	printf("�� %c �ƶ��� %c , �� %d �� , ��ʱ����Ϊ %d , ", st, ed, n, mode);
	if (!show)
		printf("��");
	printf("��ʾ�ڲ�������ֵ\n");

	put_pic();

	++cnt;
	printf("��");
	cout << setw(4) << cnt;
	cout << setw(4) << "��(" << num << "):";
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
	printf("�� %c �ƶ��� %c , �� %d �� , ��ʱ����Ϊ %d , ", st, ed, n, mode);
	if (!show) 
		printf("��");
	printf("��ʾ�ڲ�������ֵ\n");

	put_pic();
	printf("��ʼ��                ");
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
		printf("���������ӵĸ���n (1-10) : ");
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> n;
		}
		if (n <= 0 || n >= 11)
		{
			printf("���ӵĸ���Ӧ������1-16֮�䣬����������\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("��������ʼԲ������A,B,C����");
		cin >> st;
		if (!((st >= 'A' && st <= 'C') || (st >= 'a' && st <= 'c')))
		{
			printf("Բ�̱��Ӧ��ΪA,B,C������������\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("���������Բ������A,B,C����");
		cin >> ed;
		if (!((ed >= 'A' && ed <= 'C') || (ed >= 'a' && ed <= 'c')))
		{
			printf("Բ�̱��Ӧ��ΪA,B,C������������\n");
			continue;
		}
		if (st == ed)
		{
			printf("��ʼ��Ŀ���̲���Ϊͬһ��������������\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("�������ƶ��ٶ�(0-5 : 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)��");
		cin >> mode;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> mode;
		}
		if (mode < 0 || mode>5)
		{
			printf("�ƶ��ٶ�ģʽΪ0-5 ����������\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("�������Ƿ���ʾ�ڲ�������ֵ(0-����ʾ 1-��ʾ)��");
		cin >> show;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> show;
		}
		if (show < 0 || show>1)
		{
			printf("������0��1������������\n");
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
//���� system("cls");
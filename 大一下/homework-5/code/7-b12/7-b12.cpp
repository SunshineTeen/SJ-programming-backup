//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define FFLUSH while(getchar()!='\n')
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;

struct KFC
{
	char id;
	char *name;
	double cost;
};
struct SPECIAL
{
	char *iteam;
	char *name;
	double cost;
};

const struct KFC list[] = 
{
	{ 'A', "香辣鸡腿堡",         17.0 },
	{ 'B', "劲脆鸡腿堡",         17.0 },
	{ 'C', "新奥尔良烤鸡腿堡",   17.0 },
	{ 'D', "牛油果香辣鸡腿堡",   18.0 },
	{ 'E', "藤椒肯大大鸡排",     11.0 },
	{ 'F', "老北京鸡肉卷",       15.0 },
	{ 'G', "吮指原味鸡(一块)",   10.5 },
	{ 'H', "吮指原味鸡(二块)",   20.0 },
	{ 'I', "新奥尔良烤翅",       10.5 },
	{ 'J', "劲爆鸡米花",         10.5 },
	{ 'K', "香辣鸡翅",           9.5 },
	{ 'L', "黄金鸡块(五块)",     9.0 },
	{ 'M', "鲜蔬色拉",           12.0 },
	{ 'N', "薯条(小)",           8.5 },
	{ 'O', "薯条(中)",           10.0 },
	{ 'P', "薯条(大)",           12.0 },
	{ 'Q', "芙蓉蔬荟汤",         7.5 },
	{ 'R', "骨肉相连",           7.0 },
	{ 'S', "醇香土豆泥",         6.0 },
	{ 'T', "香甜粟米棒",         7.0 },
	{ 'U', "脆皮甜筒",           7.5 },
	{ 'V', "百事可乐(小)",       6.5 },
	{ 'W', "百事可乐(中)",       8.0 },
	{ 'X', "百事可乐(大)",       9.5 },
	{ 'Y', "九珍果汁饮料",       10.5 },
	{ 'Z', "纯纯玉米饮",         9.5 },
	{ '\0', NULL,                0 }
};
const struct SPECIAL special[] = 
{
	{ "ANV", "香辣汉堡工作日午餐",    20 },
	{ "GGGGGJJJSTWWW", "超值全家桶",  82 },
	{ "ZZ", "玉米饮第2件半价",        14.5 },
	{ "UUU","脆皮甜筒买2送1",         15 },
	{ NULL, NULL, 0 }
};
const int inf = 99999999 + 413;

char upper_alpha(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - 32;
	return ch;
}

char *get_name(char ch)
{
	int p = -1;
	while (list[++p].id != ch);
	return list[p].name;
}
void output(int cnt[])
{
	For(i, 0, 25)
	{
		if (!cnt[i])
			continue;
		cout << get_name(i + 'A');
		if (cnt[i] > 1)
			cout << '*' << cnt[i];
		cout << '+';
	}
	cout << "\b";
}

double get_cost(char ch)
{
	int p = -1;
	while (list[++p].id != ch);
	return list[p].cost;
}
double sum(int cnt[])
{
	int p = -1;
	double res = 0;
	while (special[++p].iteam != NULL)
	{
		char *cur = special[p].iteam;
		int n = strlen(cur), q = 0;
		int sel = inf;
		while (q < n)
		{
			int m = 1;
			while (cur[q] == cur[q + 1])
				++q, ++m;
			sel = Min(sel, cnt[upper_alpha(cur[q]) - 'A'] / m);
			++q;
		}
		res += special[p].cost*sel;
		if (!sel)
			continue;
		q = 0;
		while (q < n)
		{
			int m = 1;
			while (cur[q] == cur[q + 1])
				++q, ++m;
			cnt[upper_alpha(cur[q]) - 'A'] -= m*sel;
			++q;
		}
	}
	For(i, 0, 25)
		res += cnt[i] * get_cost(i + 'A');
	return res;
}

int init(int cnt[])
{
	char ch = getchar();
	if (ch == '0')
		if (getchar() == '\n')
			return 0;
		else
			return -1;
	do
	{
		ch = upper_alpha(ch);
		if (ch<'A' || ch>'Z')
			return -1;
		++cnt[ch-'A'];
	} while ((ch = getchar()) != '\n');
	return 1;
}

void setcolor(const HANDLE hout, const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
}
void setconsoleborder(const HANDLE hout, const int cols, const int lines, const int buffer_lines = -1)
{
	char cmd[80];
	setcolor(hout, 0, 7);
	system("cls");

	sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
	system(cmd);

	if (buffer_lines >= lines) 
	{
		COORD cr;
		cr.X = cols;
		cr.Y = buffer_lines;
		SetConsoleScreenBufferSize(hout, cr);
	}

	return;
}
char *get_iteam(char id)
{
	int p = -1;
	while (list[++p].id != id);
	return list[p].name;
}
void output_menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setconsoleborder(hout, 100, 35);

	int p = -1;
	while (list[++p].id != '\0')
	{
		cout << " " << list[p].id << " "
			<< setw(18) << setiosflags(ios::left) << list[p].name << "    "
			<< setw(6) << setiosflags(ios::fixed) << setprecision(1) << list[p].cost;
		cout << (p & 1 ? "\n" : " |  ");
	}

	cout << "\n【优惠信息】：\n";
	p = -1;
	while (special[++p].iteam != NULL)
	{
		cout << special[p].name << '=';
		int l = 0, r;
		while (special[p].iteam[l] != '\0')
		{
			r = l;
			while (special[p].iteam[++r] == special[p].iteam[l]);
			cout << get_iteam(special[p].iteam[l]);
			if (r - l > 1)
				cout << "*" << r - l;
			cout << "+";
			l = r;
		}
		cout << "\b=" << setiosflags(ios::fixed) << setprecision(1) << special[p].cost << endl;
	}

	cout << "\n【输入规则说明】\n";
	cout << "ANU=香辣鸡腿堡+薯条(小)+脆皮甜筒\\aakka=香辣鸡腿堡*3+香辣鸡翅*2\n";
	cout << "字母不区分大小写，不限顺序，单独输入0则退出程序\n";
	cout << "\n请点单：";
}

int main()
{
	while (1)
	{
		output_menu();
		int cnt[26] = { 0 };
		int res = init(cnt);
		if (res == -1)
		{
			FFLUSH;
			cout << "输入错误,按任意键继续\n";
			getchar();
			continue;
		}
		if (res == 2)
			continue;
		if (!res)
			break;

		output(cnt);
		double cost=sum(cnt);
		cout << "共计：" << setiosflags(ios::fixed) << setprecision(1) << cost << "元" << endl;

		cout << "点单完成,按任意键继续\n";
		getchar();
	}
	

	return 0;
}

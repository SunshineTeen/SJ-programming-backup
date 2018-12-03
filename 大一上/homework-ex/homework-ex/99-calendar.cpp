/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<Windows.h>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define pFor(i,l,r) for(int i=l;i+2<=r;i+=2)
#define Max(a,b) ((a)>(b)?(a):(b))
#define FFLUSH while(getchar()!='\n')
#define COLOR_BLACK		0	//黑
#define COLOR_BLUE		1	//蓝
#define COLOR_GREEN		2	//绿
#define COLOR_CYAN		3	//青
#define COLOR_RED		4	//红
#define COLOR_PINK		5	//粉
#define COLOR_YELLOW	6	//黄
#define COLOR_WHITE		7	//白
#define COLOR_HBLACK	8	//亮黑
#define COLOR_HBLUE		9	//亮蓝
#define COLOR_HGREEN	10	//亮绿
#define COLOR_HCYAN		11	//亮青
#define COLOR_HRED		12	//亮红
#define COLOR_HPINK		13	//亮粉
#define COLOR_HYELLOW	14	//亮黄
#define COLOR_HWHITE	15	//亮白

using namespace std;

const int Maxn = 10;
const int Maxm = 30;
const int mon_col[13] = { 0,15,15,10,10,10,6,6,6,12,12,12,15 };
const int day_col[8] = { 0,3,3,3,3,3,4,9 };
const int Y = 92;

int last[5] = { 1 };

class Cursor_Operate
{
public:
	void gotoxy(const HANDLE hout, const int X, const int Y)
	{
		COORD coord;
		coord.X = X;
		coord.Y = Y;
		SetConsoleCursorPosition(hout, coord);
	}
	void setcolor(const HANDLE hout, const int bg_color, const int fg_color)
	{
		SetConsoleTextAttribute(hout, bg_color * 16 + fg_color);
	}
}Cu_op;

void clear()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	For(i, 0, 4)
		For(j, 1, Y - 1)
		{
			int color = rand() % 14 + 1;
			Cu_op.gotoxy(hout, j, last[i]);
			printf(" ");
	}
	For(i, 1, last[4])
	{
		Cu_op.gotoxy(hout, 0, i);
		printf(" ");
		Cu_op.gotoxy(hout, Y, i);
		printf(" ");
	}
}
void decorate(const int mode)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned)time(0));
	For(i, 0, 4)
		pFor(j, 1, Y)
		{
			if (((j/2) & 1) == mode)
				continue;
			int color = rand() % 14 + 1;
			Cu_op.gotoxy(hout, j, last[i]);
			Cu_op.setcolor(hout, COLOR_BLACK, color);
			printf("☆");
		}
	For(i, 1, last[4])
	{
		if ((i & 1) == mode)
			continue;
		int color = rand() % 14 + 1;
		Cu_op.gotoxy(hout, 0, i);
		Cu_op.setcolor(hout, COLOR_BLACK, color);
		printf("☆");
		color = rand() % 14 + 1;
		Cu_op.gotoxy(hout, Y, i);
		Cu_op.setcolor(hout, COLOR_BLACK, color);
		printf("☆");
	}
}

//output part
void output_calendar(const int base, const int lim, int cal[Maxn][Maxm])
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	For(i, 1, lim)
	{
		printf(" ");
		For(j, 1, 21)
		{
			if (cal[i][j])
			{
				int day = j % 7;
				if (!day)
					day = 7;
				Cu_op.setcolor(hout, COLOR_BLACK, day_col[day]);
				cout << setw(3) << cal[i][j];
				printf(" ");
			}
			else
				printf("    ");
			if (!(j % 7))
				printf("    ");
		}
		printf("\n");
	}
	printf("\n");
}
void output_menu(const int base)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	For(i, 1, 3)
	{
		Cu_op.setcolor(hout, COLOR_BLACK, mon_col[3 * base + i]);
		printf(" ");
		cout << setw(13) << 3 * base + i;
		printf("月            ");
		printf("     ");
	}
	printf("\n");

	printf(" ");
	For(i, 1, 3)
	{
		Cu_op.setcolor(hout, COLOR_BLACK, day_col[1]);
		printf("Mon Tue Wed Thu Fri ");
		Cu_op.setcolor(hout, COLOR_BLACK, day_col[6]);
		printf("Sat ");
		Cu_op.setcolor(hout, COLOR_BLACK, day_col[7]);
		printf("Sun     ");
	}
	printf("\n");
}
void output(const int base,const int lim, int cal[Maxn][Maxm])
{
	output_menu(base);
	output_calendar(base, lim, cal);
}

inline int calc(const int m,const bool leapyear)
{
	int tot;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		tot = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		tot = 30;
	else
		tot = 28 + leapyear;
	return tot;
}
void work_part(const bool leapyear,int y,int d,int *suml)
{
	int cal[Maxn][Maxm];

	For(i, 0, 3)
	{
		For(_i, 1, Maxn-1)
			For(_j, 1, Maxm-1)
			cal[_i][_j] = 0;

		int line = 0;
		For(j, 1, 3)
		{
			int tot = calc(3 * i + j, leapyear);
			int x = 1, y = 7 * (j - 1) + d;
			int lim = 7 * j;
			For(k, 1, tot)
			{
				if (y > lim)
				{
					y -= 7;
					++x;
				}
				cal[x][y] = k;
				++y;
				++d;
			}
			line = Max(line, x);
			d %= 7;
			if (!d)
				d = 7;
		}
		(*suml) += line;
		last[i + 1] = last[i] + line + 3;
		output(i, line, cal);
	}
}

void PAUSE()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	Cu_op.gotoxy(hout, 29, last[4] + 1);
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_HBLUE);
	printf("Presented by ");
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_CYAN);
	printf("大鳳ちゃん世界一番可愛い　");
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_HRED);
	printf("鳳ちゃん僕の嫁 ");
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_HYELLOW);
	puts("的 永遠の波");
	      
	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	printf("\n输出完毕，请按Ctrl+C退出");
}
void work(const int y,const int d,const bool leapyear)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	Cu_op.setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	system("cls");
	For(i, 1, 41)
		printf(" ");
	printf("%d年 年历\n", y);
	printf("\n");

	int suml = 0;
	work_part(leapyear, y, d, &suml);

	PAUSE();
	while (1)
	{
		clear();
		decorate(0);
		Sleep(500);
		clear();
		decorate(1);
		Sleep(500);
	}
}

int zeller(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		--year;
	}
	int c = year / 100;
	year %= 100;
	int w = year + year / 4 + c / 4 - 2 * c + (13 * (month + 1) / 5) + day - 1;
	while (w < 0)
		w += 7;
	return w;
}

void init(int *y, bool *leapyear)
{
	printf("请输入年份(1900-2100) : ");
	scanf(" %d", y);
	FFLUSH;

	if ((!(*y % 4) && (*y % 100)) || !(*y % 400))
		*leapyear = 1;
	else
		*leapyear = 0;
}
int main()
{
	system("mode con cols=100 lines=40");

	int y;
	bool leapyear;

	init(&y, &leapyear);
	int d = (zeller(y, 1, 1) + 7) % 7;
	work(y,d, leapyear);
	
	return 0;
}
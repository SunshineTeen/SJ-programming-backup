/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')

using namespace std;

const int n = 4;
const int m = 5;
const double eps = 1e-6;

void work_3(int(*score)[m + 3], double *ave)
{
	int cnt = 0;
	int good[n + 3];
	int *p = good;
	For(i, 1, n)
	{
		if (*(ave + i) >= 90)
		{
			*(p + (++cnt)) = i;
			continue;
		}
		int tot = 0;
		For(j, 1, m)
			if (*(*(score + i) + j) >=85)
				++tot;
		if (tot ==m)
			*(p + (++cnt)) = i;
	}
	if (!cnt)
	{
		printf("没有平均成绩在90分以上或全部成绩在85分以上的学生\n");
		return;
	}
	printf("平均成绩在90分以上或全部成绩在85分以上的学生如下\n");
	For(k, 1, cnt)
	{
		int i = *(p + k);
		printf("学号 %d\n", i);
	}
}
void work_2(int(*score)[m + 3], double *ave)
{
	int cnt = 0;
	int fail[n + 3];
	int *p = fail;
	For(i, 1, n)
	{
		int tot = 0;
		For(j, 1, m)
			if (*(*(score + i) + j) < 60)
				++tot;
		if (tot > 2)
			*(p + (++cnt)) = i;
	}
	if (!cnt)
	{
		printf("没有两门以上课程不及格的学生\n");
		return;
	}
	printf("两门以上课程不及格的学生如下\n");
	For(k, 1, cnt)
	{
		int i = *(p + k);
		printf("学号 %d ", i);
		printf("全部成绩为 ");
		For(j, 1, m)
			printf("%d ", *(*(score + i) + j));
		printf("平均成绩为 %.2lf\n", *(ave + i));
	}
}
void work_1(int(*score)[m + 3])
{
	double sum = 0;
	For(i, 1, n)
		sum += *(*(score + i) + 1);
	printf("第1门课的平均分为: %.2lf\n", sum / n);
}
void work(int(*score)[m + 3], double *ave)
{
	work_1(score);
	printf("\n");
	work_2(score, ave);
	printf("\n");
	work_3(score, ave);
	printf("\n");
}

void reset(int(*score)[m + 3], double *ave)
{
	For(i, 1, n)
	{
		double sum = 0;
		For(j, 1, m)
			sum += *(*(score + i) + j);
		*(ave + i) = sum / m;
	}
}

void init_i(const int i, int *p)
{
	while (1)
	{
		bool init_fail = 0;
		printf("请输入第%d个同学的5门课成绩\n", i);
		For(j, 1, m)
		{
			if (!scanf(" %d", p + j))
			{
				init_fail = 1;
				break;
			}
			if (*(p + j) < 0 || *(p + j) > 100)
			{
				init_fail = 1;
				break;
			}
		}
		FFLUSH;
		if (!init_fail)
			break;
	}
}
void init(int(*p)[m + 3])
{
	For(i, 1, n)
		init_i(i, *(p + i));
	printf("\n");
}

int main()
{
	int score[n + 3][m + 3];
	double ave[n + 3];

	init(score);
	reset(score, ave);
	work(score, ave);

	return 0;
}

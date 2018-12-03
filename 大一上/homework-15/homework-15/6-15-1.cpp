/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

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
		printf("û��ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ��\n");
		return;
	}
	printf("ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ������\n");
	For(k, 1, cnt)
	{
		int i = *(p + k);
		printf("ѧ�� %d\n", i);
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
		printf("û���������Ͽγ̲������ѧ��\n");
		return;
	}
	printf("�������Ͽγ̲������ѧ������\n");
	For(k, 1, cnt)
	{
		int i = *(p + k);
		printf("ѧ�� %d ", i);
		printf("ȫ���ɼ�Ϊ ");
		For(j, 1, m)
			printf("%d ", *(*(score + i) + j));
		printf("ƽ���ɼ�Ϊ %.2lf\n", *(ave + i));
	}
}
void work_1(int(*score)[m + 3])
{
	double sum = 0;
	For(i, 1, n)
		sum += *(*(score + i) + 1);
	printf("��1�ſε�ƽ����Ϊ: %.2lf\n", sum / n);
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
		printf("�������%d��ͬѧ��5�ſγɼ�\n", i);
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

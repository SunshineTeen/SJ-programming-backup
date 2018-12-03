//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const char *name[] = { "���P","���L","����","����","����","Ϧ��","�r��","ɽ�L",
                       "���L","���L","����","��","������","����","��Ħ",
                       "���Q","���Q","����","ϼ","���","ѩ�L","�r���L","����L","���L" ,NULL };
const short room[] = { 0x00a9, 0x0092 , 0x0092 , 0x0092 , 0x0092 , 0x0082 ,0x0092,0x0092,0x0082,0x0092,0x0000 };

void output(const int n, int const* Id)
{
	int line = 0, row = 0;
	while (room[row++]);
	--row;
	sFor(i, 0, row)
	{
		int tl = 0;
		for (int tmp = room[i]; tmp; tmp >>= 1, ++tl);
		line = Max(line, tl);
	}

	int p = 0;
	sFor(i, 0, row)
	{
		printf("|    /   |");
		opFor(j, line - 1, 0)
		{
			if ((room[i] >> j) & 1)
			{
				if (Id[p] == -1)
					printf("    /   |");
				else
				{
					cout << setw(8) << setiosflags(ios::right) << name[Id[p]];
					printf("|");
				}
				++p;
				continue;
			}
			printf("    /   |");
		}
		printf("\n");
	}
}
void allocate(const int mode, const int n, const int m, bool *seat_f, bool *stu_f, int *Id)
{
	srand((unsigned)time(0));
	int last = n,j=-1;
	while (last)
	{
		int i = rand() % n;
		if (stu_f[i])
			continue;
		stu_f[i] = 1;

		if (mode == 1)
			++j;
		else
		{
			do
			{
				j = rand() % m;
			} while (seat_f[j]);
		}
		seat_f[j] = 1;

		Id[j] = i;
		--last;
	}
}
void init_mode(int &mode)
{
	printf("���������ַ��䷽ʽ[1/2]\n");
	printf("1.����λ˳�����\n");
	printf("2.�����������\n");
	printf("��ѡ����䷽ʽ:");
	while (1)
	{
		if (!scanf("%d", &mode))
			mode = 3;
		if (mode < 1 || mode>2)
		{
			printf("�������������ѡ��:");
			FFLUSH;
			continue;
		}
		return;
	}
}
void work(const int n,const int m)
{
	int mode;
	init_mode(mode);

	bool *seat_f = new(nothrow) bool[m] {0};
	bool *stu_f = new(nothrow) bool[n] {0};
	int *Id = new(nothrow) int[m];

	if (seat_f == NULL || stu_f == NULL || Id == NULL)
	{
		printf("No Free Memory\n");
		return;
	}

	sFor(i, 0, m)
		Id[i] = -1;

	allocate(mode, n, m, seat_f, stu_f, Id);
	output(n, Id);

	delete[]seat_f;
	delete[]stu_f;
	delete[]Id;

}

void pre_work(int &n, int &m)
{
	while (name[n++] != NULL);
	--n;

	int p = 0,tmp;
	while (tmp = room[p++])
		for (; tmp; m += tmp & 1, tmp >>= 1);
}

int main()
{
	int n = 0, m = 0;
	pre_work(n, m);
	printf("%d %d\n", n, m);
	if (n > m)
	{
		printf("��λ����\n");
		return 0;
	}
	work(n,m);
	return 0;
}
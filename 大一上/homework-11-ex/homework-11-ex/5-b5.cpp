//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<fstream>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

void work(int day[], int y, int z)
{
	if (z > day[y])
	{
		printf("输入的天数有误，无法计算\n");
		return;
	}
	int sum = 0;
	For(i, 1, y - 1)
		sum += day[i];
	sum += z;
	printf("这是该年的第%d天\n", sum);
}

void Sort(int score[], int low, int high)
{
	if (low >= high) 
		return;
	int l = low, r = high;
	int tmp = score[l];
	while (l<r)
	{
		while (l<r && score[r] <= tmp) 
			--r;
		if (l<r) 
			score[l] = score[r];
		while (l<r && score[l] >= tmp) 
			++l;
		if (l<r) 
			score[r] = score[l];
	}
	score[l] = tmp;
	Sort(score, low, l - 1); 
	Sort(score, r + 1, high);
}

int main()
{
	const int Maxn = 1010;
	int score[Maxn] = { 0 };

	ifstream file;
	file.open("score.dat", ios::in);
	if (!file.is_open())
	{
		printf("打开文件失败\n");
		return -1;
	}

	int N = 0;
	while (1)
	{
		int tmp;
		file >> tmp;
		if (tmp == -1)
			break;
		score[++N] = tmp;
	}
	score[N+1]=-1;

	Sort(score, 1, N);
	for (int i = 1; i <= N;)
	{
		int j = i + 1;
		while (score[i] == score[j]) ++j;
		--j;
		For(k, i, j)
		{
			cout << setw(3) << score[k];
			printf(" ");
			cout << setw(3) << i;
			printf("\n");
		}
		i = j + 1;
	}
	
	file.close();
	return 0;
}

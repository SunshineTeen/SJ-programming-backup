//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

void Sort(int score[],int low, int high)
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
	const int N = 50;
	const int Maxn = N + 10;
	int score[Maxn] = {0};

	srand((unsigned int)time(0));
	For(i, 1, N)
		score[i] = rand() % 101;
	score[N + 1] = -1;
	//For(i, 1, N) printf("%d ", score[i]);puts("");
	Sort(score, 1, N);
	for (int i = 1; i <= N;)
	{
		int j = i+1;
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

	return 0;
}

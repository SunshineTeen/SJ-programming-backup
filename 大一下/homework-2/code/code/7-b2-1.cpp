//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<fstream>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

struct Student
{
	int Id;
	int score;
	int rank = 0;
	char name[30];
};

void output(const int n, Student *const head)
{
	For(i, 0, n - 1)
	{
		Student *p = head + i;
		printf("%d %s %d %d\n", p->Id, p->name, p->score, p->rank);
	}
	delete[]head;
}

void Swap(Student *X, Student *Y)
{
	Student tmp = *X;
	*X = *Y;
	*Y = tmp;
}
void Sort(const int n, Student *const head)
{
	For(i, 0, n-1)
	{
		int maxs = (head + i)->score,maxi=i;
		For(j, i, n - 1)
			if ((head + j)->score > maxs)
				maxs = (head + j)->score, maxi = j;
		Swap(head + i, head + maxi);
	}
	int p = 0, rank = 1;
	while (p < n)
	{
		int score = (head + p)->score, pre = p;
		while ((head + p)->score == score && p < n)
			(head + p)->rank = rank, ++p;
		rank += p - pre;
	}
	For(i, 0, n - 1)
	{
		int minid = (head + i)->Id, mini = i;
		For(j, i, n - 1)
			if ((head + j)->Id < minid)
				minid = (head + j)->Id, mini = j;
		Swap(head + i, head + mini);
	}
}

void init(int &n, Student *&head)
{
	scanf(" %d", &n);
	head = new(nothrow) Student[n];
	if (head == NULL)
	{
		printf("No Free Memory\n");
		return;
	}
	Student *p = head;
	For(i, 0, n-1)
	{
		scanf(" %d", &p->Id);
		scanf(" %s", p->name);
		scanf(" %d", &p->score);
		++p;
	}
}

int main()
{
	if (freopen("student.txt", "r", stdin) == NULL)
	{
		printf("Open File Error\n");
		return 0;
	}
	
	int n;
	Student *head=NULL;
	init(n, head);
	Sort(n, head);
	output(n, head);

	freopen("CON", "r", stdin);//重定义输入流回控制台
	return 0;
}
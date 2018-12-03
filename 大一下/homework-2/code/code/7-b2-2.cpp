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
void Sort_Id(Student *const head, const int l, const int r)
{
	For(i, l, r)
	{
		int minid = (head + i)->Id, mini = i;
		For(j, i, r)
			if ((head + j)->Id < minid)
				minid = (head + j)->score, mini = j;

		Swap(head + i, head + mini);
	}
}
void Sort(const int n, Student *const head)
{
	For(i, 0, n - 1)
	{
		int maxs = (head + i)->score, maxi = i;
		For(j, i, n - 1)
			if ((head + j)->score > maxs)
				maxs = (head + j)->score, maxi = j;
		Swap(head + i, head + maxi);
	}

	int r = 0, rank = 1;
	while (r < n)
	{
		int score = (head + r)->score;
		int l = r;
		while ((head + r)->score == score && r < n)
			(head + r)->rank = rank, ++r;
		Sort_Id(head, l, r - 1);
		rank += r - l;
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
	For(i, 0, n - 1)
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
	Student *head = NULL;
	init(n, head);
	Sort(n, head);
	output(n, head);

	freopen("CON", "r", stdin);//重定义输入流回控制台
	return 0;
}
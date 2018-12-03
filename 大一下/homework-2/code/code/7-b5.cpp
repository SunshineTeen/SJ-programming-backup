//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

struct Student
{
	char *no;
	char *name;
	char *school;
	Student *nxt;
};

void Free(Student *&head)
{
	while (head != NULL)
	{
		delete[]head->no;
		delete[]head->name;
		delete[]head->school;
		Student *tmp = head->nxt;
		delete head;
		head = tmp;
	}
}

void output(const int n, Student *head)
{
	printf("以下为选中学生名单\n");
	while (head != NULL)
	{
		printf("%s", head->no);
		cout << setw(15) << head->name;
		cout << setw(13) << head->school;
		printf("\n");
		head = head->nxt;
	}
}

void work(int n, Student *&head_all, int m, Student *&head)
{
	srand((unsigned)time(0));
	Student *cur = head;
	while (m--)
	{
		int num = rand() % n;
		Student *select = head_all;
		if (!num)
			head_all = head_all->nxt;
		else
		{
			while (--num)
				select = select->nxt;
			Student *tmp = select->nxt;
			select->nxt = tmp->nxt;
			select = tmp;
		}

		Student *p = new(nothrow) Student;
		if (p == NULL)
		{
			printf("No Free Memory");
			return;
		}
		if (head == NULL)
			head = p;
		else
			cur->nxt = p;
		cur = p;
		cur->nxt = NULL;

		cur->no = new(nothrow) char[sizeof(select->no)];
		cur->name = new(nothrow) char[sizeof(select->name)];
		cur->school = new(nothrow) char[sizeof(select->school)];
		if (cur->no == NULL || cur->name == NULL || cur->school == NULL)
		{
			printf("No Free Memory\n");
			return;
		}
		*cur = *select;
		cur->nxt = NULL;
		--n;
	}
}

void init(int &n, int &m, Student *&head_all)
{
	scanf(" %d", &n);
	scanf(" %d", &m);
	
	Student *cur = head_all;
	For(i, 1, m)
	{
		char no[20], name[50], school[50];
		scanf(" %s %s %s", no, name, school);
		
		Student *p = new(nothrow) Student;
		if (p == NULL)
		{
			printf("No Free Memory\n");
			return;
		}
		if (head_all == NULL)
			head_all = p;
		else
			cur->nxt = p;
		cur = p;
		cur->nxt = NULL;

		cur->no = new(nothrow) char[strlen(no)+1];
		cur->name = new(nothrow) char[strlen(name) + 1];
		cur->school = new(nothrow) char[strlen(school) + 1];
		if (cur->no == NULL || cur->name == NULL || cur->school == NULL)
		{
			printf("No Free Memory\n");
			return;
		}
		//printf("here\n");
		strcpy(cur->no, no);
		strcpy(cur->name, name);
		strcpy(cur->school, school);
	}
}

int main()
{
	if (freopen("stulist.txt", "r", stdin) == NULL)
	{
		printf("Open File Error\n");
		return 0;
	}
	freopen("result.txt", "w", stdout);

	int n, m;
	Student *head_all = NULL;
	init(n, m, head_all);
	Student *head = NULL;
	work(m, head_all, n, head);
	output(n, head);
	Free(head_all);
	Free(head);

	return 0;
}
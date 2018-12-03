//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

struct student
{
	int no;
	char name[9];
	int score;
	struct student *next;
};

void output(const int n, student *head)
{
	while (head != NULL)
	{
		printf("%d %s %d\n", head->no, head->name, head->score);
		student *tmp = head;
		head = head->next;
		delete tmp;
	}
}

void init(int &n, student *&head)
{
	int no;
	char name[9];
	int score;
	student *cur = head;
	while (1)
	{
		scanf(" %d", &no);
		scanf(" %s", name);
		scanf(" %d", &score);
		if (no == 9999999)
			break;

		student *tmp = new(nothrow) student;
		if (tmp == NULL)
		{
			printf("No Free Memory\n");
			return;
		}
		if (head == NULL)
			head = tmp;
		else
			cur->next = tmp;
		cur = tmp;
		*cur = { no,"name",score,NULL };
		strcpy(cur->name, name);
	}
}

int main()
{
	if (freopen("list.txt", "r", stdin) == NULL)
	{
		printf("Open File Error\n");
		return 0;
	}

	int n;
	student *head = NULL;
	init(n, head);
	output(n, head);

	freopen("CON", "r", stdin);//�ض����������ؿ���̨
	return 0;
}
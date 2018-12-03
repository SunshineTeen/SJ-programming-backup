//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		
#include <math.h>
#include <string.h>

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define TJOVERFLOW	-2
#define MAX_NUM_PER_LINE 	5

typedef int Status;
typedef int ElemType;

int line_count;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList pa = La->next, pb = Lb->next, pc = (*Lc);

	while (pa && pb)
	{
		LinkList tmp = (LNode *)malloc(sizeof(LNode));
		if (tmp == NULL)
			exit(TJOVERFLOW);
		pc->next = tmp;
		pc = tmp;
		if (pa->data <= pb->data)
		{
			pc->data = pa->data;
			pa = pa->next;
		}
		else
		{
			pc->data = pb->data;
			pb = pb->next;
		}
	}

	pa = pa ? pa : pb;
	while (pa)
	{
		LinkList tmp = (LNode *)malloc(sizeof(LNode));
		if (tmp == NULL)
			exit(TJOVERFLOW);
		pc->next = tmp;
		pc = tmp;
		pc->data = pa->data;
		pa = pa->next;
	}
	pc->next = NULL;
}

Status MyVisit(ElemType e)
{
	printf("%3d->", e);

	if ((++line_count) % MAX_NUM_PER_LINE == 0)
		printf("\n");

	return OK;
}
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	LinkList p = L->next;

	line_count = 0;
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;
	int      pos = 0;

	while (p && pos<i - 1)
	{
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return TJOVERFLOW;

	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

Status InitList(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(TJOVERFLOW);

	(*L)->next = NULL;
	return OK;
}
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	*L = NULL;
	return OK;
}

int main()
{
	LinkList  La, Lb, Lc;

	int INSERT_NUM = 25;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	printf("插入%d个元素：\n", INSERT_NUM);
	for (int i = INSERT_NUM * 2; i > 0; i -= 2)
		ListInsert(&La, 1, i);
	for (int i = INSERT_NUM; i > 0; i -= 3)
		ListInsert(&Lb, 1, i + 1), ListInsert(&Lb, 1, i);

	printf("\nA表为：\n");
	line_count = 0;
	ListTraverse(La, MyVisit);
	printf("\n\nB表为：\n");
	line_count = 0;
	ListTraverse(Lb, MyVisit);
	printf("\n\nC表为：\n");
	line_count = 0;
	ListTraverse(Lc, MyVisit);

	MergeList_L(La, Lb, &Lc);
	printf("\n归并后:\n");

	printf("\nA表为：\n");
	line_count = 0;
	ListTraverse(La, MyVisit);
	printf("\n\nB表为：\n");
	line_count = 0;
	ListTraverse(Lb, MyVisit);
	printf("\n\nC表为：\n");
	line_count = 0;
	ListTraverse(Lc, MyVisit);

	DestroyList(&La);
	DestroyList(&Lb);
	DestroyList(&Lc);
	
	return 0;
}

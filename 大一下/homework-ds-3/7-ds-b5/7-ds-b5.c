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

void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa, pb, pc;
	if ((*La)->data <= (*Lb)->data)
		pa = (*La), pb = (*Lb);
	else
		pa = (*Lb), pb = (*La);
	pc = (*Lc) = pa;
	pa = pa->next;

	while (pa && pb) 
	{
		if (pa->data <= pb->data) 
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else 
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;
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
	LinkList p = L;

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
	int      pos = 1;

	if (i != 1)
	{
		while (p && pos<i - 1)
		{
			p = p->next;
			pos++;
		}

		if (p == NULL || pos>i - 1)
			return ERROR;
	}

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return TJOVERFLOW;

	s->data = e;
	if (i != 1)
	{
		s->next = p->next;
		p->next = s;
	}
	else
	{
		s->next = p;
		*L = s;
	}

	return OK;
}

Status InitList(LinkList *L)
{
	*L = NULL;
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

	MergeList_L(&La, &Lb, &Lc);
	printf("\n归并后:\n");

	printf("\nC表为：\n");
	line_count = 0;
	ListTraverse(Lc, MyVisit);

	DestroyList(&Lc);
	
	return 0;
}
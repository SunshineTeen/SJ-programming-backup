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

void union_L(LinkList *La, LinkList *Lb)
{
	LinkList p, q, r;
	for (q = *Lb; q->next;)
	{
		for (p = *La; p->next; p = p->next)
			if (p->next->data == q->next->data)
				break;
		if (!p->next)
		{
			r = (LinkList)malloc(sizeof(LNode));
			if (!r)
				exit(TJOVERFLOW);
			r->data = q->next->data;
			r->next = (*La)->next;
			(*La)->next = r;
		}
		r = q->next->next;
		free(q->next);
		q->next = r;
	}
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
	LinkList  La, Lb;

	int INSERT_NUM = 25;
	InitList(&La);
	InitList(&Lb);

	printf("插入%d个元素：\n", INSERT_NUM);
	for (int i = INSERT_NUM * 2; i > 0; i -= 2)
		ListInsert(&La, 1, i);
	for (int i = INSERT_NUM; i > 0; i -= 3)
		ListInsert(&Lb, 1, i);
	for (int i = INSERT_NUM; i > 0; i -= 3)
		ListInsert(&Lb, 1, i + 1);

	printf("\nA表为：\n");
	line_count = 0;
	ListTraverse(La, MyVisit);
	printf("\n\nB表为：\n");
	line_count = 0;
	ListTraverse(Lb, MyVisit);

	union_L(&La, &Lb);
	printf("\n合并后:\n");

	printf("\nA表为：\n");
	line_count = 0;
	ListTraverse(La, MyVisit);
	printf("\n\nB表为：\n");
	line_count = 0;
	ListTraverse(Lb, MyVisit);

	DestroyList(&La);
	DestroyList(&Lb);

	return 0;
}

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

void difference(LinkList *S, const int Na, const ElemType A[], const int Nb, const ElemType B[])
{
	LinkList p = *S;
	for (int i = 0; i < Na; ++i)
	{
		LinkList tmp = (LNode *)malloc(sizeof(LNode));
		if (tmp == NULL)
			exit(TJOVERFLOW);
		p->next = tmp;
		p = tmp;
		p->data = A[i];
	}
	p->next = NULL;
	LinkList tail = p;

	for (int i = 0; i < Nb; ++i)
	{
		p = *S;
		while (p->next != tail->next)
		{
			if (p->next->data == B[i])
				break;
			p = p->next;
		}
		if (p->next == tail->next)
		{
			LinkList tmp = (LNode *)malloc(sizeof(LNode));
			if (tmp == NULL)
				exit(TJOVERFLOW);
			tmp->data = B[i];
			tmp->next = tail->next;
			tail->next = tmp;
			continue;
		}
		LinkList tmp = p->next;
		p->next = tmp->next;
		if (tmp == tail)
			tail = p;
		free(tmp);
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
	const int Na = 6;
	const int Nb = 5;
	const ElemType A[] = { 1,2,3,5,7,9 };
	const ElemType B[] = { 1,3,8,9,6 };
	LinkList  S;

	InitList(&S);

	printf("A表为：\n");
	for (int i = 0; i < Na; ++i)
		printf("%d ", A[i]);
	printf("\n\nB表为：\n");
	for (int i = 0; i < Nb; ++i)
		printf("%d ", B[i]);
	printf("\n");

	difference(&S, Na, A, Nb, B);
	printf("\n进行集合运算 (A-B)∪(B-A) 后:\n");

	printf("\n结果为：\n");
	line_count = 0;
	ListTraverse(S, MyVisit);

	DestroyList(&S);
	
	return 0;
}
